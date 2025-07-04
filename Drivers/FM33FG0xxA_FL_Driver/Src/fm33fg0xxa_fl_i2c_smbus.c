/**
  *******************************************************************************************************
  * @file    fm33fg0xxa_fl_i2c_smbus.c
  * @author  FMSH Application Team
  * @brief   Source file of I2C SMBUS FL Module
  *******************************************************************************************************
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

/** @addtogroup I2C
  * @{
  */

#ifdef FL_I2C_SMBUS_DRIVER_ENABLED

/* Private macros ------------------------------------------------------------*/
/** @addtogroup I2C_FL_Private_Macros
  * @{
  */

#define         IS_FL_I2C_SMBUS_INSTANCE(INSTANCE)                      (((INSTANCE) == I2CSMB0)||\
                                                                          ((INSTANCE) == I2CSMB1))

#define         IS_FL_I2C_SMBUS_BAUDRATE(__VALUE__)                     (((__VALUE__) > 0 )&&((__VALUE__) <= 1000000))

#define         IS_FL_I2C_SMBUS_CLOCKSRC(__VALUE__)                     (((__VALUE__) == FL_CMU_I2CSMB1_CLK_SOURCE_APBCLK )||\
                                                                         ((__VALUE__) == FL_CMU_I2CSMB1_CLK_SOURCE_RCHF)||\
                                                                         ((__VALUE__) == FL_CMU_I2CSMB1_CLK_SOURCE_SYSCLK ) ||\
                                                                         ((__VALUE__) == FL_CMU_I2CSMB0_CLK_SOURCE_APBCLK )||\
                                                                         ((__VALUE__) == FL_CMU_I2CSMB0_CLK_SOURCE_RCHF)||\
                                                                         ((__VALUE__) == FL_CMU_I2CSMB0_CLK_SOURCE_SYSCLK))

#define         IS_FL_I2C_SMBUS_MSATER_TIMEOUT(__VALUE__)               (((__VALUE__) == FL_IWDT_PERIOD_125MS)||\
                                                                         ((__VALUE__) == FL_IWDT_PERIOD_16000MS))


#define         IS_FL_I2C_SMBUS_ANGLOGFILTER(__VALUE__)                 (((__VALUE__) == FL_ENABLE)||\
                                                                         ((__VALUE__) == FL_DISABLE))

#define         IS_FL_I2C_SMBUS_ADDRSIZE10BIT(__VALUE__)                (((__VALUE__) == FL_ENABLE)||\
                                                                         ((__VALUE__) == FL_DISABLE))

#define         IS_FL_I2C_SMBUS_SLAVE_SCLSEN(__VALUE__)                 (((__VALUE__) == FL_ENABLE)||\
                                                                         ((__VALUE__) == FL_DISABLE))

/**
  * @}
  */

/** @addtogroup I2CSMBUS_FL_EF_Init
  * @{
  */

/**
  * @brief  复位I2CSMBUS外设.
  * @param  I2CSMBx 外设入口地址
  * @retval 错误状态，可能值：
  *         -FL_PASS 外设寄存器值恢复复位值
  *         -FL_FAIL 未成功执行
  */
FL_ErrorStatus FL_I2C_SMBUS_DeInit(I2CSMB_Type *I2CSMBx)
{
    assert_param(IS_FL_I2C_SMBUS_INSTANCE(I2CSMBx));
    /* 使能外设复位 */
    FL_RMU_EnablePeripheralReset(RMU);
    if(I2CSMBx == I2CSMB0)
    {
        /* 复位I2CSMB0外设寄存器 */
        FL_RMU_EnableResetAPBPeripheral(RMU, FL_RMU_RSTAPB_I2CSMB0);
        FL_RMU_DisableResetAPBPeripheral(RMU, FL_RMU_RSTAPB_I2CSMB0);
    }
    else if(I2CSMBx == I2CSMB1)
    {
        /* 复位I2CSMB1外设寄存器 */
        FL_RMU_EnableResetAPBPeripheral(RMU, FL_RMU_RSTAPB_I2C1);
        FL_RMU_DisableResetAPBPeripheral(RMU, FL_RMU_RSTAPB_I2C1);
    }
    else
    {
        FL_RMU_DisablePeripheralReset(RMU);
        return FL_FAIL;
    }
    return FL_PASS;
}

/**
  * @brief  配置I2CSMBUS主机模式.
  * @param  I2CSMBx 外设入口地址
  * @param  I2CSMB_InitStruct 指向 @ref FL_I2C_SMBUS_MasterMode_InitTypeDef 结构体的指针
  * @retval 错误状态，可能值：
  *         -FL_PASS 配置成功
  *         -FL_FAIL 配置过程发生错误
  */
FL_ErrorStatus FL_I2C_SMBUS_MasterMode_Init(I2CSMB_Type *I2CSMBx, FL_I2C_SMBUS_MasterMode_InitTypeDef *I2CSMB_InitStruct)
{
    uint32_t I2C_Clk_Freq = 0, BRG = 0;
    FL_ErrorStatus status = FL_FAIL;
    if(I2CSMB_InitStruct != NULL)
    {
        assert_param(IS_FL_I2C_SMBUS_INSTANCE(I2CSMBx));
        assert_param(IS_FL_I2C_SMBUS_CLOCKSRC(I2CSMB_InitStruct->clockSource));
        assert_param(IS_FL_I2C_SMBUS_BAUDRATE(I2CSMB_InitStruct->baudRate));
        /* 外设总线时钟和工作时钟开启 */
        if(I2CSMBx == I2CSMB0)
        {
            /* 外设总线始时钟 */
            FL_CMU_EnableGroup3BusClock(FL_CMU_GROUP3_BUSCLK_I2CSMB0);
            FL_CMU_SetI2CSMB0ClockSource(I2CSMB_InitStruct->clockSource);
            FL_CMU_EnableOperationClock(FL_CMU_OPCLK_I2CSMB0);
        }
        else if(I2CSMBx == I2CSMB1)
        {
            FL_CMU_EnableGroup3BusClock(FL_CMU_GROUP3_BUSCLK_I2CSMB1);
            FL_CMU_SetI2CSMB1ClockSource(I2CSMB_InitStruct->clockSource);
            FL_CMU_EnableOperationClock(FL_CMU_OPCLK_I2CSMB1);
        }
        else
        {
            return FL_FAIL;
        }
        /* 获取时钟源速度 */
        switch(I2CSMB_InitStruct->clockSource)
        {
            case FL_CMU_I2CSMB1_CLK_SOURCE_APBCLK:
            /*case FL_CMU_I2CSMB0_CLK_SOURCE_APBCLK:*/
                I2C_Clk_Freq = FL_CMU_GetAPB1ClockFreq();
                break;
            case FL_CMU_I2CSMB1_CLK_SOURCE_RCHF:
            case FL_CMU_I2CSMB0_CLK_SOURCE_RCHF:
                I2C_Clk_Freq = FL_CMU_GetRCHFClockFreq();
                break;
            case FL_CMU_I2CSMB1_CLK_SOURCE_SYSCLK:
            case FL_CMU_I2CSMB0_CLK_SOURCE_SYSCLK:
                I2C_Clk_Freq = FL_CMU_GetSystemClockFreq();
                break;
            default:
                I2C_Clk_Freq = FL_CMU_GetAPB1ClockFreq();
                break;
        }
        /* 根据不同的时钟源速度计算出配置速率需要的寄存器值并配置相关寄存器 */
        BRG = (uint32_t)(I2C_Clk_Freq / (2 * I2CSMB_InitStruct->baudRate)) - 1;
        FL_I2CSMB_WriteSCLHighWidth(I2CSMBx, BRG);
        FL_I2CSMB_WriteSCLLowWidth(I2CSMBx, BRG);
        FL_I2CSMB_WriteSDAHoldTime(I2CSMBx, (uint32_t)((BRG & 0x1FF) / 2));
        /* 使能外设 */
        FL_I2CSMB_Enable(I2CSMBx);
        status = FL_PASS;
    }
    return status;
}

/**
  * @brief  将 @ref FL_I2C_SMBUS_MasterMode_InitTypeDef 结构体初始化为默认配置
  * @param  I2CSMB_InitStruct 指向 @ref FL_I2C_SMBUS_MasterMode_InitTypeDef 结构体的指针
  *
  * @retval None
  */
void FL_I2C_SMBUS_MasterMode_StructInit(FL_I2C_SMBUS_MasterMode_InitTypeDef *I2CSMB_InitStruct)
{
    if(I2CSMB_InitStruct != NULL)
    {
        I2CSMB_InitStruct->clockSource = FL_CMU_I2CSMB1_CLK_SOURCE_APBCLK;
        I2CSMB_InitStruct->baudRate = 40000;
    }
}

/**
  * @brief  配置I2CSMBUS从机模式.
  * @param  I2CSMBx 外设入口地址
  * @param  I2CSMB_InitStruct 指向 @ref FL_I2C_SMBUS_SlaveMode_InitTypeDef 结构体的指针.
  * @note   作为从机时的从机地址应参考手册推荐具体设置
  * @retval 错误状态，可能值：
  *         -FL_PASS 配置成功
  *         -FL_FAIL 配置过程发生错误
  */
FL_ErrorStatus FL_I2C_SMBUS_SlaveMode_Init(I2CSMB_Type *I2CSMBx, FL_I2C_SMBUS_SlaveMode_InitTypeDef *I2CSMB_InitStruct)
{
    FL_ErrorStatus status = FL_FAIL;
    if(I2CSMB_InitStruct != NULL)
    {
        assert_param(IS_FL_I2C_SMBUS_INSTANCE(I2CSMBx));
        assert_param(IS_FL_I2C_SMBUS_CLOCKSRC(I2CSMB_InitStruct->clockSource));
        assert_param(IS_FL_I2C_SMBUS_ADDRSIZE10BIT(I2CSMB_InitStruct->ownAddrSize10bit));
        assert_param(IS_FL_I2C_SMBUS_SLAVE_SCLSEN(I2CSMB_InitStruct->SCLSEN));
        /* 外设总线时钟开启 注：不需要工作时钟*/
        if(I2CSMBx == I2CSMB0)
        {
            /* 外设总线始时钟和工作时钟 */
            FL_CMU_EnableGroup3BusClock(FL_CMU_GROUP3_BUSCLK_I2CSMB0);
            FL_CMU_SetI2CSMB0ClockSource(I2CSMB_InitStruct->clockSource);
            FL_CMU_EnableOperationClock(FL_CMU_OPCLK_I2CSMB0);
        }
        else if(I2CSMBx == I2CSMB1)
        {
            FL_CMU_EnableGroup3BusClock(FL_CMU_GROUP3_BUSCLK_I2CSMB1);
            FL_CMU_SetI2CSMB0ClockSource(I2CSMB_InitStruct->clockSource);
            FL_CMU_EnableOperationClock(FL_CMU_OPCLK_I2CSMB0);
        }
        else
        {
            return FL_FAIL;
        }
        /* 从机地址宽度  和地址配置 */
        if(I2CSMB_InitStruct->ownAddrSize10bit == FL_ENABLE)
        {
            FL_I2CSMB_Enable10BitAddress(I2CSMBx);
            FL_I2CSMB_WriteSlave10BitAddress(I2CSMBx, ((I2CSMB_InitStruct->ownAddr) & 0x000003FFU));
        }
        else
        {
            FL_I2CSMB_Disable10BitAddress(I2CSMBx);
            FL_I2CSMB_WriteSlave10BitAddress(I2CSMBx, ((I2CSMB_InitStruct->ownAddr) & 0x0000007FU));
        }
        /* 从机时钟延展使能 */
        if(I2CSMB_InitStruct->SCLSEN == FL_ENABLE)
        {
            FL_I2CSMB_EnableSlaveSCLStretching(I2CSMBx);
        }
        else
        {
            FL_I2CSMB_DisableSlaveSCLStretching(I2CSMBx);
        }
        /* 从机地址使能 */
        FL_I2CSMB_EnableSlaveAddressMatch(I2CSMBx);
        /* 使能外设 */
        FL_I2CSMB_Enable(I2CSMBx);
        status = FL_PASS;
    }
    return status;
}

/**
  * @brief  将 @ref FL_I2C_SMBUS_SlaveMode_InitTypeDef 结构体初始化为默认配置
  * @param  I2CSMB_InitStruct 指向 @ref FL_I2C_SMBUS_SlaveMode_InitTypeDef 结构体的指针
  *
  * @retval None
  */

void FL_I2C_SMBUS_SlaveMode_StructInit(FL_I2C_SMBUS_SlaveMode_InitTypeDef *I2CSMB_InitStruct)
{
    if(I2CSMB_InitStruct != NULL)
    {
        I2CSMB_InitStruct->ownAddr             = 0x55;
        I2CSMB_InitStruct->ownAddrSize10bit    = FL_DISABLE;
        I2CSMB_InitStruct->SCLSEN              = FL_ENABLE;
    }
}



/**
  * @}
  */

#endif /* FL_I2C_SMBUS_DRIVER_ENABLED */

/**
  * @}
  */

/**
  * @}
  */

/********************** (C) COPYRIGHT Fudan Microelectronics **** END OF FILE ***********************/
