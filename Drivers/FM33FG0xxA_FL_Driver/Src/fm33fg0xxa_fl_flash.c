 /**   
  *******************************************************************************************************
  * @file    fm33fg0xxa_fl_flash.c
  * @author  FMSH Application Team
  * @brief   Source file of FLASH FL Module 
  ******************************************************************************************************* 
  * @attention    
  * Copyright (c) 2023, SHANGHAI FUDAN MICROELECTRONICS GROUP CO., LTD.(FUDAN MICROELECTRONICS./ FUDAN MICRO.)    
  * All rights reserved.    
  *    
  * Processor:                   FM33FG0xxA    
  * http:                        http://www.fmdevelopers.com.cn/    
  *    
  * Redistribution and use in source and binary forms, with or without    
  * modification, are permitted provided that the following conditions are met    
  *    
  * 1. Redistributions of source code must retain the above copyright notice,    
  *    this list of conditions and the following disclaimer.    
  *    
  * 2. Redistributions in binary form must reproduce the above copyright notice,    
  *    this list of conditions and the following disclaimer in the documentation    
  *    and/or other materials provided with the distribution.    
  *    
  * 3. Neither the name of the copyright holder nor the names of its contributors    
  *    may be used to endorse or promote products derived from this software    
  *    without specific prior written permission.    
  *    
  * 4. To provide the most up-to-date information, the revision of our documents     
  *    on the World Wide Web will be the most Current. Your printed copy may be      
  *    an earlier revision. To verify you have the latest information avaliable,    
  *    refer to: http://www.fmdevelopers.com.cn/.    
  *    
  * THIS SOFTWARE IS PROVIDED BY FUDAN MICRO "AS IS" AND ANY EXPRESSED:     
  * ORIMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES     
  * OF MERCHANTABILITY NON-INFRINGEMENT AND FITNESS FOR A PARTICULAR PURPOSE    
  * ARE DISCLAIMED.IN NO EVENT SHALL FUDAN MICRO OR ITS CONTRIBUTORS BE LIABLE     
  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL     
  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS     
  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER    
  * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,     
  * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISINGIN ANY WAY OUT OF THE     
  * USE OF THIS SOFTWARE, EVEN IF ADVISED OFTHE POSSIBILITY OF SUCH DAMAGE.  
  *
  *******************************************************************************************************  
  */    

/* Includes ------------------------------------------------------------------*/
#include "fm33fg0xxa_fl.h"

/** @addtogroup FM33FG0XXA_FL_Driver
  * @{
  */

/** @addtogroup FLASH
  * @{
  */

/* Private macros ------------------------------------------------------------*/
/** @addtogroup FLASH_FL_Private_Macros
  * @{
  */

#define    IS_FLASH_ALL_INSTANCE(INTENCE)               ((INTENCE) == FLASH)

#define    IS_FL_FLASH_CODE_MAX_ADDR(__VALUE__)         ((uint32_t)(__VALUE__) <= (FL_FLASH_CODE_ADDR_MAXPROGRAM))
           
#define    IS_FL_FLASH_CODE_MAX_PAGE(__VALUE__)         ((uint32_t)(__VALUE__) < (FL_FLASH_CODE_MAX_PAGE_NUM))
           
#define    IS_FL_FLASH_CODE_MAX_SECTOR(__VALUE__)       ((uint32_t)(__VALUE__) < (FL_FLASH_CODE_MAX_SECTOR_NUM))


#define    IS_FL_FLASH_INFO_MAX_ADDR(__VALUE__)         ((((uint32_t)(FL_FLASH_INFO_ADDR_MINPROGRAM)) <= (__VALUE__)) &&\
                                                         ((__VALUE__) <= (FL_FLASH_INFO_ADDR_MAXPROGRAM)))
           
#define    IS_FL_FLASH_INFO_MAX_PAGE(__VALUE__)         ((uint32_t)(__VALUE__) < (FL_FLASH_INFO_MAX_PAGE_NUM))
           
#define    IS_FL_FLASH_INFO_MAX_SECTOR(__VALUE__)       ((uint32_t)(__VALUE__) < (FL_FLASH_IFFO_MAX_SECTOR_NUM))


#define    IS_FL_FLASH_DATA_MAX_ADDR(__VALUE__)         ((((uint32_t)(FL_FLASH_DATA_ADDR_MINPROGRAM)) <= (__VALUE__)) &&\
                                                         ((__VALUE__) <= (FL_FLASH_DATA_ADDR_MAXPROGRAM)))
                                                         
#define    IS_FL_FLASH_DATA_MAX_PAGE(__VALUE__)         ((__VALUE__) < (FL_FLASH_DATA_MAX_PAGE_NUM))
           
#define    IS_FL_FLASH_DATA_MAX_SECTOR(__VALUE__)       ((__VALUE__) < (FL_FLASH_DATA_MAX_SECTOR_NUM))
                                                     

/**
  * @}
  */


/* Private function prototypes -----------------------------------------------*/
/** @defgroup FLASH_FL_Private_Functions FLASH Private Functions
  * @{
  */



/** @addtogroup FLASH_FL_EF_Init
  * @{
  */

/**
  * @brief  Code Flash 页擦除函数，一个页为512byte.
  * @param  FLASHx FLASH Port
  * @param  address 为需要擦除的页内任意地址，推荐使用页开始的首地址（字对齐）

  *         .
  * @retval ErrorStatus枚举值

  *         -FL_FAIL 擦写发生错误
  *         -FL_PASS 擦写成功
  */
FL_ErrorStatus FL_FLASH_CodePageErase(FLASH_Type *FLASHx, uint32_t address)
{
    uint32_t timeout = 0;
    uint32_t primask = 0;
    uint32_t ClockError, KeyError, AuthenticationError;
    FL_ErrorStatus ret = FL_FAIL;
    /* 入口参数检查 */
    assert_param(IS_FLASH_ALL_INSTANCE(FLASHx));
    assert_param((IS_FL_FLASH_CODE_MAX_ADDR((uint32_t)address)) ||\
                 (IS_FL_FLASH_INFO_MAX_ADDR((uint32_t)address)));
    /*时钟使能*/
    FL_CMU_EnableGroup2BusClock(FL_CMU_GROUP2_BUSCLK_FLASH);
    /* 地址对齐检查 */
    if((address % FL_FLASH_WORD_ADDRS_ALIGN) != 0)
    {
        /*地址未对齐*/
        return FL_FAIL;
    }
    if(FL_FLASH_GetCodeLockStatus(FLASHx) == FL_FLASH_CODE_KEY_STATUS_ERROR)
    {
        /*Code Flash 已经锁定，复位前无法操作*/
        return FL_FAIL;
    }
    /* 擦写时钟使能*/
    FL_CMU_EnableOperationClock(FL_CMU_OPCLK_FLASH);
    /* 配置擦写类型*/
    FL_FLASH_SetCodeEraseType(FLASHx, FL_FLASH_CODE_ERASE_TYPE_PAGE);
    /* 开始擦除页*/
    FL_FLASH_EnableCodeErase(FLASHx);
    /* Key 序列*/
    primask = __get_PRIMASK();
    __disable_irq();
    FL_FLASH_CodeUnlock(FLASHx, FL_FLASH_ERASE_KEY);
    FL_FLASH_CodeUnlock(FLASHx, FL_FLASH_PGAE_ERASE_KEY);
    
    /* 清除中断标志*/
    FL_FLASH_ClearFlag_CodeEraseComplete(FLASHx);
    FL_FLASH_ClearFlag_CodeClockError(FLASHx);
    FL_FLASH_ClearFlag_CodeKeyError(FLASHx);
    FL_FLASH_ClearFlag_CodeAuthenticationError(FLASHx);
    /* 擦请求 */
    *((uint32_t *)address) = FL_FLASH_ERASE_REQUEST;
    while(1)
    {
        timeout++;
        ClockError = FL_FLASH_IsActiveFlag_CodeClockError(FLASHx);
        KeyError = FL_FLASH_IsActiveFlag_CodeKeyError(FLASHx);
        AuthenticationError = FL_FLASH_IsActiveFlag_CodeAuthenticationError(FLASHx);
        if((timeout > FL_FLASH_ERASE_TIMEOUT) || (ClockError == 0X01UL) || (KeyError == 0X01UL) || (AuthenticationError == 0X01UL))
        {
            /* 超时或出现错误 */
            ret = FL_FAIL;
            break;
        }
        else
        {
            if(FL_FLASH_IsActiveFlag_CodeEraseComplete(FLASHx) == 0X01U)
            {
                /*编程成功*/
                FL_FLASH_ClearFlag_CodeEraseComplete(FLASHx);
                ret =  FL_PASS;
                break;
            }
        }
    }
    FL_FLASH_CodeLock(FLASHx);
    FL_CMU_DisableOperationClock(FL_CMU_OPCLK_FLASH);
    FL_CMU_DisableGroup2BusClock(FL_CMU_GROUP2_BUSCLK_FLASH);
    __set_PRIMASK(primask);
    return ret;
}

/**
  * @brief  Code Flash 扇区擦除函数，一个扇区为2k byte.
  * @param  FLASHx FLASH Port
  * @param  address 为需要擦除的扇区内任意地址，推荐使用扇区开始的首地址（字对齐）

  *         .
  * @retval ErrorStatus枚举值

  *         -FL_FAIL 擦写发生错误
  *         -FL_PASS 擦写成功
  */
FL_ErrorStatus FL_FLASH_CodeSectorErase(FLASH_Type *FLASHx, uint32_t address)
{
    uint32_t timeout = 0;
    uint32_t primask = 0;
    FL_ErrorStatus ret = FL_FAIL;
    uint32_t ClockError, KeyError, AuthenticationError;
    /* 入口参数检查 */
    assert_param(IS_FLASH_ALL_INSTANCE(FLASHx));
    assert_param((IS_FL_FLASH_CODE_MAX_ADDR((uint32_t)address)) ||\
                 (IS_FL_FLASH_INFO_MAX_ADDR((uint32_t)address)));
    /* 时钟使能*/
    FL_CMU_EnableGroup2BusClock(FL_CMU_GROUP2_BUSCLK_FLASH);
    /* 地址对齐检查 */
    if((address % FL_FLASH_WORD_ADDRS_ALIGN) != 0)
    {
        /*地址未对齐*/
        return FL_FAIL;
    }
    if(FL_FLASH_GetCodeLockStatus(FLASHx) == FL_FLASH_CODE_KEY_STATUS_ERROR)
    {
        /*Code Flash 已经锁定，复位前无法操作*/
        return FL_FAIL;
    }
    /* 擦写时钟使能*/
    FL_CMU_EnableOperationClock(FL_CMU_OPCLK_FLASH);
    /* 配置擦写类型*/
    FL_FLASH_SetCodeEraseType(FLASHx, FL_FLASH_CODE_ERASE_TYPE_SECTOR);
    /* 开始擦除扇区*/
    FL_FLASH_EnableCodeErase(FLASHx);
    /* Key 序列*/
    primask = __get_PRIMASK();
    __disable_irq();
    FL_FLASH_CodeUnlock(FLASHx, FL_FLASH_ERASE_KEY);
    FL_FLASH_CodeUnlock(FLASHx, FL_FLASH_SECTOR_ERASE_KEY);
    
    /* 清除中断标志*/
    FL_FLASH_ClearFlag_CodeEraseComplete(FLASHx);
    FL_FLASH_ClearFlag_CodeClockError(FLASHx);
    FL_FLASH_ClearFlag_CodeKeyError(FLASHx);
    FL_FLASH_ClearFlag_CodeAuthenticationError(FLASHx);
    /* 擦请求 */
    *((uint32_t *)address) = FL_FLASH_ERASE_REQUEST;
    while(1)
    {
        timeout++;
        ClockError = FL_FLASH_IsActiveFlag_CodeClockError(FLASHx);
        KeyError = FL_FLASH_IsActiveFlag_CodeKeyError(FLASHx);
        AuthenticationError = FL_FLASH_IsActiveFlag_CodeAuthenticationError(FLASHx);
        if((timeout > FL_FLASH_ERASE_TIMEOUT) || (ClockError == 0X01U) || (KeyError == 0X01U) || (AuthenticationError == 0X01U))
        {
            /* 超时或出现错误 */
            ret = FL_FAIL;
            break;
        }
        else
        {
            if(FL_FLASH_IsActiveFlag_CodeEraseComplete(FLASHx) == 0X01U)
            {
                /*编程成功*/
                FL_FLASH_ClearFlag_CodeEraseComplete(FLASHx);
                ret =  FL_PASS;
                break;
            }
        }
    }
    FL_FLASH_CodeLock(FLASHx);
    FL_CMU_DisableOperationClock(FL_CMU_OPCLK_FLASH);
    FL_CMU_DisableGroup2BusClock(FL_CMU_GROUP2_BUSCLK_FLASH);
    __set_PRIMASK(primask);
    return ret;
}

/**
  * @brief  Code Flash 单次字编程函数，编程地址必须对齐到字边界.
  * @param  FLASHx FLASH Port
  * @param  address 为需要编程的已经擦除过的扇区内任意地址，非对齐地址编程将触发fault。

  *
  * @retval ErrorStatus枚举值

  *         -FL_FAIL 编程发生错误
  *         -FL_PASS 编程成功
  */
FL_ErrorStatus FL_FLASH_CodeProgram_Word(FLASH_Type *FLASHx, uint32_t address, uint32_t data)
{
    uint32_t timeout = 0;
    uint32_t primask = 0;
    uint32_t ClockError, KeyError, AuthenticationError;
    FL_ErrorStatus ret = FL_PASS;
    /* 入口参数检查 */
    assert_param(IS_FLASH_ALL_INSTANCE(FLASHx));
    assert_param((IS_FL_FLASH_CODE_MAX_ADDR((uint32_t)address)) ||\
                 (IS_FL_FLASH_INFO_MAX_ADDR((uint32_t)address)));
    /*时钟使能*/
    FL_CMU_EnableGroup2BusClock(FL_CMU_GROUP2_BUSCLK_FLASH);
    /* 地址对齐检查 */
    if((address % FL_FLASH_WORD_ADDRS_ALIGN) != 0)
    {
        /*地址未对齐*/
        return FL_FAIL;
    }
    if(FL_FLASH_GetCodeLockStatus(FLASHx) == FL_FLASH_CODE_KEY_STATUS_ERROR)
    {
        /*Code Flash 已经锁定，复位前无法操作*/
        return FL_FAIL;
    }
    /* FLASH擦写时钟使能*/
    FL_CMU_EnableOperationClock(FL_CMU_OPCLK_FLASH);
    /* 开始编程*/
    FL_FLASH_EnableCodeProgram(FLASHx);
    /* Key 序列*/
    primask = __get_PRIMASK();
    __disable_irq();
    FL_FLASH_CodeUnlock(FLASHx, FL_FLASH_PROGRAM_KEY1);
    FL_FLASH_CodeUnlock(FLASHx, FL_FLASH_PROGRAM_KEY2);
    
    /* 清除中断标志*/
    FL_FLASH_ClearFlag_CodeProgramComplete(FLASHx);
    FL_FLASH_ClearFlag_CodeClockError(FLASHx);
    FL_FLASH_ClearFlag_CodeKeyError(FLASHx);
    FL_FLASH_ClearFlag_CodeAuthenticationError(FLASHx);
    /* flash编程 Word*/
    *((uint32_t *)address) = data;
    while(1)
    {
        timeout++;
        ClockError = FL_FLASH_IsActiveFlag_CodeClockError(FLASHx);
        KeyError = FL_FLASH_IsActiveFlag_CodeKeyError(FLASHx);
        AuthenticationError = FL_FLASH_IsActiveFlag_CodeAuthenticationError(FLASHx);
        if((timeout > FL_FLASH_ERASE_TIMEOUT) || (ClockError == 0X01U) || (KeyError == 0X01U) || (AuthenticationError == 0X01U))
        {
            /* 超时或出现错误 */
            ret = FL_FAIL;
            break;
        }
        else
        {
            if(FL_FLASH_IsActiveFlag_CodeProgramComplete(FLASHx) == 0X01U)
            {
                /*编程成功*/
                FL_FLASH_ClearFlag_CodeProgramComplete(FLASHx);
                ret = FL_PASS;
                break;
            }
        }
    }
    FL_FLASH_CodeLock(FLASHx);
    FL_CMU_DisableOperationClock(FL_CMU_OPCLK_FLASH);
    FL_CMU_DisableGroup2BusClock(FL_CMU_GROUP2_BUSCLK_FLASH);
    __set_PRIMASK(primask);
    return ret;
}

/**
  * @brief  Code Flash 页编程函数，编程地址必须对齐到页边界.
  * @param  FLASHx FLASH Port
  * @param  PageNum 为需要编程的已经擦除过的页号，非对齐地址编程将触发fault。

  *
  * @retval ErrorStatus枚举值

  *         -FL_FAIL 编程发生错误
  *         -FL_PASS 编程成功
  */
FL_ErrorStatus FL_FLASH_CodeProgram_Page(FLASH_Type *FLASHx, uint32_t pageNum, uint32_t *data)
{
    uint32_t count;
    uint32_t primask;
    uint32_t address;
    uint32_t timeout;
    uint32_t ClockError, KeyError, AuthenticationError;
    FL_ErrorStatus status = FL_FAIL;
    if(data != NULL)
    {
        /* 入口参数检查 */
        assert_param(IS_FLASH_ALL_INSTANCE(FLASHx));
        assert_param(IS_FL_FLASH_CODE_MAX_PAGE((uint32_t)pageNum));
        address = pageNum * FL_FLASH_CODE_PGAE_SIZE_BYTE;
        /* 注意：不包含Information0~3 page */
        assert_param(IS_FL_FLASH_CODE_MAX_ADDR((uint32_t)address));
        /* 时钟使能*/
        FL_CMU_EnableGroup2BusClock(FL_CMU_GROUP2_BUSCLK_FLASH);
        /* 页地址对齐检查 */
        if((address % FL_FLASH_CODE_PGAE_SIZE_BYTE) != 0)
        {
            /*地址未对齐*/
            return FL_FAIL;
        }
        /* FLASH擦写时钟使能*/
        FL_CMU_EnableOperationClock(FL_CMU_OPCLK_FLASH);
        /* 开始编程*/
        FL_FLASH_EnableCodeProgram(FLASHx);
        /* Key 序列*/
        primask = __get_PRIMASK();
        __disable_irq();
        FL_FLASH_CodeUnlock(FLASHx, FL_FLASH_PROGRAM_KEY1);
        FL_FLASH_CodeUnlock(FLASHx, FL_FLASH_PROGRAM_KEY2);
        
        /* 清除中断标志*/
        FL_FLASH_ClearFlag_CodeProgramComplete(FLASHx);
        FL_FLASH_ClearFlag_CodeClockError(FLASHx);
        FL_FLASH_ClearFlag_CodeKeyError(FLASHx);
        FL_FLASH_ClearFlag_CodeAuthenticationError(FLASHx);
        for(count = 0; count < FL_FLASH_CODE_PGAE_SIZE_BYTE; count += 4)
        {
            timeout = 0;
            FL_FLASH_EnableCodeProgram(FLASHx);
            *((uint32_t *)address) = *data;
            address += 4;
            data++;
            while(1)
            {
                timeout++;
                ClockError = FL_FLASH_IsActiveFlag_CodeClockError(FLASHx);
                KeyError = FL_FLASH_IsActiveFlag_CodeKeyError(FLASHx);
                AuthenticationError = FL_FLASH_IsActiveFlag_CodeAuthenticationError(FLASHx);
                if((timeout > FL_FLASH_ERASE_TIMEOUT) || (ClockError == 0X01U) || (KeyError == 0X01U) || (AuthenticationError == 0X01U))
                {
                    /* 超时或出现错误 */
                    status = FL_FAIL;
                    break;
                }
                else
                {
                    if(FL_FLASH_IsActiveFlag_CodeProgramComplete(FLASHx) == 0X01U)
                    {
                        /*编程成功*/
                        FL_FLASH_ClearFlag_CodeProgramComplete(FLASHx);
                        status = FL_PASS;
                        break;
                    }
                }
            }
        }
        FL_FLASH_CodeLock(FLASHx);
        FL_CMU_DisableOperationClock(FL_CMU_OPCLK_FLASH);
        FL_CMU_DisableGroup2BusClock(FL_CMU_GROUP2_BUSCLK_FLASH);
        __set_PRIMASK(primask);
    }
    return status;
}

/**
  * @brief  Code Flash 扇区编程函数，编程地址必须对齐到扇区边界.
  * @param  FLASHx FLASH Port
  * @param  sectorNum 为需要编程的已经擦除过的扇区号，非对齐地址编程将触发fault。

  *
  * @retval ErrorStatus枚举值

  *         -FL_FAIL 编程发生错误
  *         -FL_PASS 编程成功
  */
FL_ErrorStatus FL_FLASH_CodeProgram_Sector(FLASH_Type *FLASHx, uint32_t sectorNum, uint32_t *data)
{
    uint32_t count;
    uint32_t primask;
    uint32_t address;
    uint32_t timeout;
    uint32_t ClockError, KeyError, AuthenticationError;
    FL_ErrorStatus status = FL_FAIL;
    if(data != NULL)
    {
        /* 入口参数检查 */
        assert_param(IS_FLASH_ALL_INSTANCE(FLASHx));
        assert_param(IS_FL_FLASH_CODE_MAX_SECTOR((uint32_t)sectorNum));
        address = sectorNum * FL_FLASH_CODE_SECTOR_SIZE_BYTE;
        /* 注意：不包含Information0~3 page */
        assert_param(IS_FL_FLASH_CODE_MAX_ADDR((uint32_t)address));
        /*时钟使能*/
        FL_CMU_EnableGroup2BusClock(FL_CMU_GROUP2_BUSCLK_FLASH);
        /* 页地址对齐检查 */
        if((address % FL_FLASH_CODE_SECTOR_SIZE_BYTE) != 0)
        {
            /*地址未对齐*/
            return FL_FAIL;
        }
        /*FLASH擦写时钟使能*/
        FL_CMU_EnableOperationClock(FL_CMU_OPCLK_FLASH);
        /* 开始编程*/
        FL_FLASH_EnableCodeProgram(FLASHx);
        /* Key 序列*/
        primask = __get_PRIMASK();
        __disable_irq();
        FL_FLASH_CodeUnlock(FLASHx, FL_FLASH_PROGRAM_KEY1);
        FL_FLASH_CodeUnlock(FLASHx, FL_FLASH_PROGRAM_KEY2);
        
        /* 清除中断标志*/
        FL_FLASH_ClearFlag_CodeProgramComplete(FLASHx);
        FL_FLASH_ClearFlag_CodeClockError(FLASHx);
        FL_FLASH_ClearFlag_CodeKeyError(FLASHx);
        FL_FLASH_ClearFlag_CodeAuthenticationError(FLASHx);
        for(count = 0; count < FL_FLASH_CODE_SECTOR_SIZE_BYTE; count += 4)
        {
            timeout = 0;
            FL_FLASH_EnableCodeProgram(FLASHx);
            *((uint32_t *)address) =  *data;
            address += 4;
            data++;
            while(1)
            {
                timeout++;
                ClockError = FL_FLASH_IsActiveFlag_CodeClockError(FLASHx);
                KeyError = FL_FLASH_IsActiveFlag_CodeKeyError(FLASHx);
                AuthenticationError = FL_FLASH_IsActiveFlag_CodeAuthenticationError(FLASHx);
                if((timeout > FL_FLASH_ERASE_TIMEOUT) || (ClockError == 0X01U) || (KeyError == 0X01U) || (AuthenticationError == 0X01U))
                {
                    /* 超时或出现错误 */
                    status = FL_FAIL;
                    break;
                }
                else
                {
                    if(FL_FLASH_IsActiveFlag_CodeProgramComplete(FLASHx) == 0x01U)
                    {
                        /*编程成功*/
                        FL_FLASH_ClearFlag_CodeProgramComplete(FLASHx);
                        status = FL_PASS;
                        break;
                    }
                }
            }
        }
        FL_FLASH_CodeLock(FLASHx);
        FL_CMU_DisableOperationClock(FL_CMU_OPCLK_FLASH);
        FL_CMU_DisableGroup2BusClock(FL_CMU_GROUP2_BUSCLK_FLASH);
        __set_PRIMASK(primask);
    }
    return status;
}


/**
  * @brief  Code Flash DMA编程函数，编程地址必须对齐到halt-page，长度固定为64字.
  * @param  FLASHx FLASH Port
  * @param  address 待编程Flash地址
  * @param  *data 待写入Flash数据
  *
  * @retval ErrorStatus枚举值

  *         -FL_FAIL 擦写发生错误
  *         -FL_PASS 擦写成功
  */
FL_ErrorStatus FL_FLASH_CodeWrite_Dma(FLASH_Type *FLASHx, uint32_t address, uint32_t *data)
{
    FL_ErrorStatus ret;
    uint32_t primask;
    uint32_t timeout;
    FL_DMA_InitTypeDef DMA_InitStruct = {0};
    /* 入口参数检查 */
    assert_param(IS_FLASH_ALL_INSTANCE(FLASHx));
    /* 注意：不包含Information0~3 page */
    assert_param(IS_FL_FLASH_CODE_MAX_ADDR((uint32_t)address));
    
    /* 半页对齐*/
    if((address % (FL_FLASH_CODE_PGAE_SIZE_BYTE / 2)) != 0)
    {
        /* 地址未对齐 */
        return FL_FAIL;
    }
    /* 总线时钟使能 */
    FL_CMU_EnableGroup2BusClock(FL_CMU_GROUP2_BUSCLK_FLASH);
    /* FLASH擦写时钟使能 */
    FL_CMU_EnableOperationClock(FL_CMU_OPCLK_FLASH);
    /* 开始编程*/
    FL_FLASH_EnableCodeProgram(FLASHx);
    /* Key 序列*/
    primask = __get_PRIMASK();
    __disable_irq();
    FL_FLASH_CodeUnlock(FLASHx, FL_FLASH_PROGRAM_KEY1);
    FL_FLASH_CodeUnlock(FLASHx, FL_FLASH_PROGRAM_KEY2);
    
    FL_FLASH_EnableCodeProgram(FLASHx);
    /* DMA通道配置*/
    DMA_InitStruct.circMode             = FL_DISABLE;
    DMA_InitStruct.direction            = FL_DMA_DIR_RAM_TO_FLASH;
    DMA_InitStruct.memoryAddressIncMode = FL_DMA_CH7_RAM_INC_MODE_INCREASE;
    DMA_InitStruct.flashAddressIncMode  = FL_DMA_CH7_FLASH_INC_MODE_INCREASE;
    DMA_InitStruct.priority             = FL_DMA_PRIORITY_HIGH;
    (void)FL_DMA_Init(DMA, &DMA_InitStruct, FL_DMA_CHANNEL_7);
    /* Channel7 Flash 指针地址为（word 地址） */
    FL_DMA_WriteFlashAddress(DMA, address >> 2);
    /* Channel7 RAM 指针地址为（word 地址）*/
    FL_DMA_WriteMemoryAddress(DMA, (uint32_t)data >> 2, FL_DMA_CHANNEL_7);  
    FL_DMA_WriteTransmissionSize(DMA, 64 - 1, FL_DMA_CHANNEL_7);
    FL_DMA_Enable(DMA);
    FL_DMA_ClearFlag_TransferComplete(DMA, FL_DMA_CHANNEL_7);
    FL_DMA_EnableChannel(DMA, FL_DMA_CHANNEL_7);
    timeout = 0;
    while(1)
    {
        timeout++;
        if(timeout > FL_FLASH_ERASE_TIMEOUT)
        {
            ret = FL_FAIL;
            break;
        }
        if(FL_DMA_IsActiveFlag_TransferComplete(DMA, FL_DMA_CHANNEL_7) == 0X01)
        {   /* 清除标志 */
            FL_DMA_ClearFlag_TransferComplete(DMA, FL_DMA_CHANNEL_7);
            FL_FLASH_ClearFlag_CodeProgramComplete(FLASHx);
            ret = FL_PASS;
            break;
        }
    }
    FL_FLASH_CodeLock(FLASHx);
    FL_CMU_DisableOperationClock(FL_CMU_OPCLK_FLASH);
    FL_CMU_DisableGroup2BusClock(FL_CMU_GROUP2_BUSCLK_FLASH);
    __set_PRIMASK(primask);
    FL_DMA_Disable(DMA);
    return ret;
}

/**
  * @brief  Code Flash DMA读取函数，编程地址字对齐.
  * @param  FLASHx FLASH Port
  * @param  address 读取数据Flash地址
  * @param  *data 读出数据存储区

  * @param  length 读出数据的字长度
  *
  * @retval ErrorStatus枚举值

  *         -FL_FAIL 擦写发生错误
  *         -FL_PASS 擦写成功
  */
FL_ErrorStatus FL_FLASH_CodeRead_Dma(FLASH_Type *FLASHx, uint32_t address, uint32_t *data, uint32_t length)
{
    FL_ErrorStatus ret = FL_PASS;
    uint32_t Timeout;
    FL_DMA_InitTypeDef DMA_InitStruct = {0};
    /* 入口参数检查 */
    assert_param(IS_FLASH_ALL_INSTANCE(FLASHx));
    /* 注意：不包含Information0~3 page */
    assert_param(IS_FL_FLASH_CODE_MAX_ADDR((uint32_t)address));
    assert_param(length > 0x00);
    
    /* 字对齐 */
    if((address % FL_FLASH_WORD_ADDRS_ALIGN) != 0)
    {
        /* 地址未对齐 */
        return FL_FAIL;
    }
    /* 总线时钟使能 */
    FL_CMU_EnableGroup2BusClock(FL_CMU_GROUP2_BUSCLK_FLASH);
    /* FLASH工作时钟使能 */
    FL_CMU_EnableOperationClock(FL_CMU_OPCLK_FLASH);
    /* DMA通道配置 */
    DMA_InitStruct.circMode             = FL_DISABLE;
    DMA_InitStruct.direction            = FL_DMA_DIR_FLASH_TO_RAM;
    DMA_InitStruct.memoryAddressIncMode = FL_DMA_CH7_RAM_INC_MODE_INCREASE;
    DMA_InitStruct.flashAddressIncMode  = FL_DMA_CH7_FLASH_INC_MODE_INCREASE;
    DMA_InitStruct.priority             = FL_DMA_PRIORITY_HIGH;
    (void)FL_DMA_Init(DMA, &DMA_InitStruct, FL_DMA_CHANNEL_7);
    /* Channel7 Flash 指针地址为（word 地址） */
    FL_DMA_WriteFlashAddress(DMA, address >> 2);
    /* Channel7 RAM 指针地址为（word 地址）*/
    FL_DMA_WriteMemoryAddress(DMA, (uint32_t)data >> 2, FL_DMA_CHANNEL_7);
    FL_DMA_WriteTransmissionSize(DMA, length - 1, FL_DMA_CHANNEL_7);
    FL_DMA_Enable(DMA);
    FL_DMA_ClearFlag_TransferComplete(DMA, FL_DMA_CHANNEL_7);
    FL_DMA_EnableChannel(DMA, FL_DMA_CHANNEL_7);
    Timeout = 0;
    while(1)
    {
        Timeout++;
        if(Timeout > FL_FLASH_ERASE_TIMEOUT)
        {
            ret = FL_FAIL;
            break;
        }
        if(FL_DMA_IsActiveFlag_TransferComplete(DMA, FL_DMA_CHANNEL_7) == 0X01)
        {   /* 清除标志 */
            FL_DMA_ClearFlag_TransferComplete(DMA, FL_DMA_CHANNEL_7);
            ret = FL_PASS;
            break;
        }
    }
    FL_DMA_Disable(DMA);
    return ret;
}


/**
  * @brief  Date Flash 页擦除函数，一个页为512byte.
  * @param  FLASHx FLASH Port
  * @param  address 为需要擦除的页内任意地址，推荐使用页开始的首地址（字对齐）

  *         .
  * @retval ErrorStatus枚举值

  *         -FL_FAIL 擦写发生错误
  *         -FL_PASS 擦写成功
  */
FL_ErrorStatus FL_FLASH_DataPageErase(FLASH_Type *FLASHx, uint32_t address)
{
    uint32_t timeout = 0;
    uint32_t primask = 0;
    uint32_t ClockError, KeyError, AuthenticationError;
    FL_ErrorStatus ret = FL_FAIL;
    /* 入口参数检查 */
    assert_param(IS_FLASH_ALL_INSTANCE(FLASHx));
    assert_param(IS_FL_FLASH_DATA_MAX_ADDR((uint32_t)address));
    /*时钟使能*/
    FL_CMU_EnableGroup2BusClock(FL_CMU_GROUP2_BUSCLK_FLASH);
    /* 地址对齐检查 */
    if((address % FL_FLASH_WORD_ADDRS_ALIGN) != 0)
    {
        /*地址未对齐*/
        return FL_FAIL;
    }
    if(FL_FLASH_GetDataLockStatus(FLASHx) == FL_FLASH_DATA_KEY_STATUS_ERROR)
    {
        /*Data Flash 已经锁定，复位前无法操作*/
        return FL_FAIL;
    }
    /*FLASH擦写时钟使能*/
    FL_CMU_EnableOperationClock(FL_CMU_OPCLK_FLASH);
    /*配置擦写类型*/
    FL_FLASH_SetDataEraseType(FLASHx, FL_FLASH_DATA_ERASE_TYPE_PAGE);
    /* 开始擦除页*/
    FL_FLASH_EnableDataErase(FLASHx);
    /* Key 序列*/
    primask = __get_PRIMASK();
    __disable_irq();
    FL_FLASH_DataUnlock(FLASHx, FL_FLASH_ERASE_KEY);
    FL_FLASH_DataUnlock(FLASHx, FL_FLASH_PGAE_ERASE_KEY);
    __set_PRIMASK(primask);
    /* 清除中断标志*/
    FL_FLASH_ClearFlag_DataEraseComplete(FLASHx);
    FL_FLASH_ClearFlag_DataClockError(FLASHx);
    FL_FLASH_ClearFlag_DataKeyError(FLASHx);
    FL_FLASH_ClearFlag_DataAuthenticationError(FLASHx);
    /* 擦请求 */
    *((uint32_t *)address) = FL_FLASH_ERASE_REQUEST;
    while(1)
    {
        timeout++;
        ClockError = FL_FLASH_IsActiveFlag_DataClockError(FLASHx);
        KeyError = FL_FLASH_IsActiveFlag_DataKeyError(FLASHx);
        AuthenticationError = FL_FLASH_IsActiveFlag_DataAuthenticationError(FLASHx);
        if((timeout > FL_FLASH_ERASE_TIMEOUT) || (ClockError == 0X01UL) || (KeyError == 0X01UL) || (AuthenticationError == 0X01UL))
        {
            /* 超时或出现错误 */
            ret = FL_FAIL;
            break;
        }
        else
        {
            if(FL_FLASH_IsActiveFlag_DataEraseComplete(FLASHx) == 0X01U)
            {
                /*编程成功*/
                FL_FLASH_ClearFlag_DataEraseComplete(FLASHx);
                ret =  FL_PASS;
                break;
            }
        }
    }
    FL_FLASH_DataLock(FLASHx);
    FL_CMU_DisableOperationClock(FL_CMU_OPCLK_FLASH);
    FL_CMU_DisableGroup2BusClock(FL_CMU_GROUP2_BUSCLK_FLASH);
    return ret;
}

/**
  * @brief  Data Flash 扇区擦除函数，一个扇区为2k byte.
  * @param  FLASHx FLASH Port
  * @param  address 为需要擦除的扇区内任意地址，推荐使用扇区开始的首地址（字对齐）

  *         .
  * @retval ErrorStatus枚举值

  *         -FL_FAIL 擦写发生错误
  *         -FL_PASS 擦写成功
  */
FL_ErrorStatus FL_FLASH_DataSectorErase(FLASH_Type *FLASHx, uint32_t address)
{
    uint32_t timeout = 0;
    uint32_t primask = 0;
    FL_ErrorStatus ret = FL_FAIL;
    uint32_t ClockError, KeyError, AuthenticationError;
    /* 入口参数检查 */
    assert_param(IS_FLASH_ALL_INSTANCE(FLASHx));
    assert_param(IS_FL_FLASH_DATA_MAX_ADDR((uint32_t)address));
    /*时钟使能*/
    FL_CMU_EnableGroup2BusClock(FL_CMU_GROUP2_BUSCLK_FLASH);
    /* 地址对齐检查 */
    if((address % FL_FLASH_WORD_ADDRS_ALIGN) != 0)
    {
        /*地址未对齐*/
        return FL_FAIL;
    }
    if(FL_FLASH_GetDataLockStatus(FLASHx) == FL_FLASH_DATA_KEY_STATUS_ERROR)
    {
        /*Data Flash 已经锁定，复位前无法操作*/
        return FL_FAIL;
    }
    /*FLASH擦写时钟使能*/
    FL_CMU_EnableOperationClock(FL_CMU_OPCLK_FLASH);
    /*配置擦写类型*/
    FL_FLASH_SetDataEraseType(FLASHx, FL_FLASH_DATA_ERASE_TYPE_SECTOR);
    /* 开始擦除扇区*/
    FL_FLASH_EnableDataErase(FLASHx);
    /* Key 序列*/
    primask = __get_PRIMASK();
    __disable_irq();
    FL_FLASH_DataUnlock(FLASHx, FL_FLASH_ERASE_KEY);
    FL_FLASH_DataUnlock(FLASHx, FL_FLASH_SECTOR_ERASE_KEY);
    __set_PRIMASK(primask);
    /* 清除中断标志*/
    FL_FLASH_ClearFlag_DataEraseComplete(FLASHx);
    FL_FLASH_ClearFlag_DataClockError(FLASHx);
    FL_FLASH_ClearFlag_DataKeyError(FLASHx);
    FL_FLASH_ClearFlag_DataAuthenticationError(FLASHx);
    /* 擦请求 */
    *((uint32_t *)address) = FL_FLASH_ERASE_REQUEST;
    while(1)
    {
        timeout++;
        ClockError = FL_FLASH_IsActiveFlag_DataClockError(FLASHx);
        KeyError = FL_FLASH_IsActiveFlag_DataKeyError(FLASHx);
        AuthenticationError = FL_FLASH_IsActiveFlag_DataAuthenticationError(FLASHx);
        if((timeout > FL_FLASH_ERASE_TIMEOUT) || (ClockError == 0X01U) || (KeyError == 0X01U) || (AuthenticationError == 0X01U))
        {
            /* 超时或出现错误 */
            ret = FL_FAIL;
            break;
        }
        else
        {
            if(FL_FLASH_IsActiveFlag_DataEraseComplete(FLASHx) == 0X01U)
            {
                /*编程成功*/
                FL_FLASH_ClearFlag_DataEraseComplete(FLASHx);
                ret =  FL_PASS;
                break;
            }
        }
    }
    FL_FLASH_DataLock(FLASHx);
    FL_CMU_DisableOperationClock(FL_CMU_OPCLK_FLASH);
    FL_CMU_DisableGroup2BusClock(FL_CMU_GROUP2_BUSCLK_FLASH);
    return ret;
}

/**
  * @brief  Data Flash 单次字编程函数，编程地址必须对齐到字边界.
  * @param  FLASHx FLASH Port
  * @param  address 为需要编程的已经擦除过的扇区内任意地址，非对齐地址编程将触发fault。

  *
  * @retval ErrorStatus枚举值

  *         -FL_FAIL 编程发生错误
  *         -FL_PASS 编程成功
  */
FL_ErrorStatus FL_FLASH_DataProgram_Word(FLASH_Type *FLASHx, uint32_t address, uint32_t data)
{
    uint32_t timeout = 0;
    uint32_t primask = 0;
    uint32_t ClockError, KeyError, AuthenticationError;
    FL_ErrorStatus ret = FL_PASS;
    /* 入口参数检查 */
    assert_param(IS_FLASH_ALL_INSTANCE(FLASHx));
    assert_param(IS_FL_FLASH_DATA_MAX_ADDR((uint32_t)address));
    /*时钟使能*/
    FL_CMU_EnableGroup2BusClock(FL_CMU_GROUP2_BUSCLK_FLASH);
    /* 地址对齐检查 */
    if((address % FL_FLASH_WORD_ADDRS_ALIGN) != 0)
    {
        /*地址未对齐*/
        return FL_FAIL;
    }
    if(FL_FLASH_GetDataLockStatus(FLASHx) == FL_FLASH_DATA_KEY_STATUS_ERROR)
    {
        /*Data Flash 已经锁定，复位前无法操作*/
        return FL_FAIL;
    }
    /*FLASH擦写时钟使能*/
    FL_CMU_EnableOperationClock(FL_CMU_OPCLK_FLASH);
    /* 开始编程*/
    FL_FLASH_EnableDataProgram(FLASHx);
    /* Key 序列*/
    primask = __get_PRIMASK();
    __disable_irq();
    FL_FLASH_DataUnlock(FLASHx, FL_FLASH_PROGRAM_KEY1);
    FL_FLASH_DataUnlock(FLASHx, FL_FLASH_PROGRAM_KEY2);
    __set_PRIMASK(primask);
    /* 清除中断标志*/
    FL_FLASH_ClearFlag_DataProgramComplete(FLASHx);
    FL_FLASH_ClearFlag_DataClockError(FLASHx);
    FL_FLASH_ClearFlag_DataKeyError(FLASHx);
    FL_FLASH_ClearFlag_DataAuthenticationError(FLASHx);
    /* flash编程 Word*/
    *((uint32_t *)address) = data;
    while(1)
    {
        timeout++;
        ClockError = FL_FLASH_IsActiveFlag_DataClockError(FLASHx);
        KeyError = FL_FLASH_IsActiveFlag_DataKeyError(FLASHx);
        AuthenticationError = FL_FLASH_IsActiveFlag_DataAuthenticationError(FLASHx);
        if((timeout > FL_FLASH_ERASE_TIMEOUT) || (ClockError == 0X01U) || (KeyError == 0X01U) || (AuthenticationError == 0X01U))
        {
            /* 超时或出现错误 */
            ret = FL_FAIL;
            break;
        }
        else
        {
            if(FL_FLASH_IsActiveFlag_DataProgramComplete(FLASHx) == 0X01U)
            {
                /*编程成功*/
                FL_FLASH_ClearFlag_DataProgramComplete(FLASHx);
                ret = FL_PASS;
                break;
            }
        }
    }
    FL_FLASH_DataLock(FLASHx);
    FL_CMU_DisableOperationClock(FL_CMU_OPCLK_FLASH);
    FL_CMU_DisableGroup2BusClock(FL_CMU_GROUP2_BUSCLK_FLASH);
    return ret;
}

/**
  * @brief  Data Flash 页编程函数，编程地址必须对齐到页边界.
  * @param  FLASHx FLASH Port
  * @param  PageNum 为需要编程的已经擦除过的页号，非对齐地址编程将触发fault。

  *
  * @retval ErrorStatus枚举值

  *         -FL_FAIL 编程发生错误
  *         -FL_PASS 编程成功
  */
FL_ErrorStatus FL_FLASH_DataProgram_Page(FLASH_Type *FLASHx, uint32_t pageNum, uint32_t *data)
{
    uint32_t count;
    uint32_t primask;
    uint32_t address;
    uint32_t timeout;
    uint32_t ClockError, KeyError, AuthenticationError;
    FL_ErrorStatus status = FL_FAIL;
    if(data != NULL)
    {
        /* 入口参数检查 */
        assert_param(IS_FLASH_ALL_INSTANCE(FLASHx));
        assert_param(IS_FL_FLASH_DATA_MAX_PAGE((uint32_t)pageNum));
        address = pageNum * FL_FLASH_DATA_PGAE_SIZE_BYTE + FL_FLASH_DATA_ADDR_MINPROGRAM;
        assert_param(IS_FL_FLASH_DATA_MAX_ADDR((uint32_t)address));
        /* 时钟使能*/
        FL_CMU_EnableGroup2BusClock(FL_CMU_GROUP2_BUSCLK_FLASH);
        /* 页地址对齐检查 */
        if((address % FL_FLASH_DATA_PGAE_SIZE_BYTE) != 0)
        {
            /*地址未对齐*/
            return FL_FAIL;
        }
        /* FLASH擦写时钟使能*/
        FL_CMU_EnableOperationClock(FL_CMU_OPCLK_FLASH);
        /* 开始编程*/
        FL_FLASH_EnableDataProgram(FLASHx);
        /* Key 序列*/
        primask = __get_PRIMASK();
        __disable_irq();
        FL_FLASH_DataUnlock(FLASHx, FL_FLASH_PROGRAM_KEY1);
        FL_FLASH_DataUnlock(FLASHx, FL_FLASH_PROGRAM_KEY2);
        __set_PRIMASK(primask);
        /* 清除中断标志*/
        FL_FLASH_ClearFlag_DataProgramComplete(FLASHx);
        FL_FLASH_ClearFlag_DataClockError(FLASHx);
        FL_FLASH_ClearFlag_DataKeyError(FLASHx);
        FL_FLASH_ClearFlag_DataAuthenticationError(FLASHx);
        for(count = 0; count < FL_FLASH_DATA_PGAE_SIZE_BYTE; count += 4)
        {
            timeout = 0;
            FL_FLASH_EnableDataProgram(FLASHx);
            *((uint32_t *)address) = *data;
            address += 4;
            data++;
            while(1)
            {
                timeout++;
                ClockError = FL_FLASH_IsActiveFlag_DataClockError(FLASHx);
                KeyError = FL_FLASH_IsActiveFlag_DataKeyError(FLASHx);
                AuthenticationError = FL_FLASH_IsActiveFlag_DataAuthenticationError(FLASHx);
                if((timeout > FL_FLASH_ERASE_TIMEOUT) || (ClockError == 0X01U) || (KeyError == 0X01U) || (AuthenticationError == 0X01U))
                {
                    /* 超时或出现错误 */
                    status = FL_FAIL;
                    break;
                }
                else
                {
                    if(FL_FLASH_IsActiveFlag_DataProgramComplete(FLASHx) == 0X01U)
                    {
                        /*编程成功*/
                        FL_FLASH_ClearFlag_DataProgramComplete(FLASHx);
                        status = FL_PASS;
                        break;
                    }
                }
            }
        }
        FL_FLASH_DataLock(FLASHx);
        FL_CMU_DisableOperationClock(FL_CMU_OPCLK_FLASH);
        FL_CMU_DisableGroup2BusClock(FL_CMU_GROUP2_BUSCLK_FLASH);
    }
    return status;
}

/**
  * @brief  Data Flash 扇区编程函数，编程地址必须对齐到扇区边界.
  * @param  FLASHx FLASH Port
  * @param  sectorNum 为需要编程的已经擦除过的扇区号，非对齐地址编程将触发fault。

  *
  * @retval ErrorStatus枚举值

  *         -FL_FAIL 编程发生错误
  *         -FL_PASS 编程成功
  */
FL_ErrorStatus FL_FLASH_DataProgram_Sector(FLASH_Type *FLASHx, uint32_t sectorNum, uint32_t *data)
{
    uint32_t count;
    uint32_t primask;
    uint32_t address;
    uint32_t timeout;
    uint32_t ClockError, KeyError, AuthenticationError;
    FL_ErrorStatus status = FL_FAIL;
    if(data != NULL)
    {
        /* 入口参数检查 */
        assert_param(IS_FLASH_ALL_INSTANCE(FLASHx));
        assert_param(IS_FL_FLASH_DATA_MAX_SECTOR((uint32_t)sectorNum));
        address = sectorNum * FL_FLASH_DATA_SECTOR_SIZE_BYTE + FL_FLASH_DATA_ADDR_MINPROGRAM;
        assert_param(IS_FL_FLASH_DATA_MAX_ADDR((uint32_t)address));
        /*时钟使能*/
        FL_CMU_EnableGroup2BusClock(FL_CMU_GROUP2_BUSCLK_FLASH);
        /* 页地址对齐检查 */
        if((address % FL_FLASH_DATA_SECTOR_SIZE_BYTE) != 0)
        {
            /*地址未对齐*/
            return FL_FAIL;
        }
        /* FLASH擦写时钟使能*/
        FL_CMU_EnableOperationClock(FL_CMU_OPCLK_FLASH);
        /* 开始编程*/
        FL_FLASH_EnableDataProgram(FLASHx);
        /* Key 序列*/
        primask = __get_PRIMASK();
        __disable_irq();
        FL_FLASH_DataUnlock(FLASHx, FL_FLASH_PROGRAM_KEY1);
        FL_FLASH_DataUnlock(FLASHx, FL_FLASH_PROGRAM_KEY2);
        __set_PRIMASK(primask);
        /* 清除中断标志*/
        FL_FLASH_ClearFlag_DataProgramComplete(FLASHx);
        FL_FLASH_ClearFlag_DataClockError(FLASHx);
        FL_FLASH_ClearFlag_DataKeyError(FLASHx);
        FL_FLASH_ClearFlag_DataAuthenticationError(FLASHx);
        for(count = 0; count < FL_FLASH_DATA_SECTOR_SIZE_BYTE; count += 4)
        {
            timeout = 0;
            FL_FLASH_EnableDataProgram(FLASHx);
            *((uint32_t *)address) = *data;
            address += 4;
            data++;
            while(1)
            {
                timeout++;
                ClockError = FL_FLASH_IsActiveFlag_DataClockError(FLASHx);
                KeyError = FL_FLASH_IsActiveFlag_DataKeyError(FLASHx);
                AuthenticationError = FL_FLASH_IsActiveFlag_DataAuthenticationError(FLASHx);
                if((timeout > FL_FLASH_ERASE_TIMEOUT) || (ClockError == 0X01U) || (KeyError == 0X01U) || (AuthenticationError == 0X01U))
                {
                    /* 超时或出现错误 */
                    status = FL_FAIL;
                    break;
                }
                else
                {
                    if(FL_FLASH_IsActiveFlag_DataProgramComplete(FLASHx) == 0x01U)
                    {
                        /*编程成功*/
                        FL_FLASH_ClearFlag_DataProgramComplete(FLASHx);
                        status = FL_PASS;
                        break;
                    }
                }
            }
        }
        FL_FLASH_DataLock(FLASHx);
        FL_CMU_DisableOperationClock(FL_CMU_OPCLK_FLASH);
        FL_CMU_DisableGroup2BusClock(FL_CMU_GROUP2_BUSCLK_FLASH);
    }
    return status;
}


/**
  * @}
  */

/* Private function ----------------------------------------------------------*/
/** @defgroup FLASH_FL_Private_Functions FLASH Private Functions
  * @{
  */



/**
  * @}
  */

/**
  * @}
  */

/**
  * @}
  */

/*************************(C) COPYRIGHT Fudan Microelectronics **** END OF FILE*************************/
