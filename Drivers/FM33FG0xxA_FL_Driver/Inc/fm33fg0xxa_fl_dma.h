 /**    
  *******************************************************************************************************
  * @file    fm33fg0xxa_fl_dma.h
  * @author  FMSH Application Team
  * @brief   Head file of DMA FL Module
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

/* Define to prevent recursive inclusion---------------------------------------------------------------*/
#ifndef __FM33FG0XXA_FL_DMA_H
#define __FM33FG0XXA_FL_DMA_H

#ifdef __cplusplus
extern "C" {
#endif
/* Includes -------------------------------------------------------------------------------------------*/
#include "fm33fg0xxa_fl_def.h"
/** @addtogroup FM33FG0XXA_FL_Driver
  * @{
  */
/* Exported types -------------------------------------------------------------------------------------*/
/** @defgroup DMA_FL_ES_INIT DMA Exported Init structures
  * @{
  */

/**
  * @brief FL DMA Init Sturcture definition
  */
typedef struct
{
    /*! DMA外设映射地址 */
    uint32_t periphAddress;
    /*! DMA传输方向 */
    uint32_t direction;
    /*! RAM地址增长方向 */
    uint32_t memoryAddressIncMode;
    /*! flash地址指针对象*/
    uint32_t flashPointObject;
    /*! flash地址增长方向 */
    uint32_t flashAddressIncMode;
    /*! DAM传输通道数据位宽 */
    uint32_t dataSize;
    /*! DMA通道优先级 */
    uint32_t priority;
    /*! 循环模式使能 */
    uint32_t circMode;

} FL_DMA_InitTypeDef;

/**
  * @brief FL DMA Config Sturcture definition
  */
typedef struct
{
    /*! RAM地址 */
    uint32_t memoryAddress;
    /*! DMA传输数据字节个数 */
    uint32_t transmissionCount;

} FL_DMA_ConfigTypeDef;

/**
  * @brief Configuration with temporary structure variable users will not be used directly
  */
typedef struct
{
    __IO uint32_t CHCR;
    __IO uint32_t CHMAD;
} CHANNEL;

/**
  * @brief Configuration with temporary structure variable users will not be used directly
  */
typedef struct
{
    __IO uint32_t RESV;
    __IO CHANNEL  Channel[7];
    __IO uint32_t CH7CR;
    __IO uint32_t CH7FLSAD;
    __IO uint32_t CH7RAMAD;
} DMA_ADDR;

/**
  * @}
  */
/* Exported constants ---------------------------------------------------------------------------------*/
/** @defgroup DMA_FL_Exported_Constants DMA Exported Constants
  * @{
  */

#define    DMA_GCR_ADDRERR_IE_Pos                                 (1U)
#define    DMA_GCR_ADDRERR_IE_Msk                                 (0x1U << DMA_GCR_ADDRERR_IE_Pos)
#define    DMA_GCR_ADDRERR_IE                                     DMA_GCR_ADDRERR_IE_Msk

#define    DMA_GCR_EN_Pos                                         (0U)
#define    DMA_GCR_EN_Msk                                         (0x1U << DMA_GCR_EN_Pos)
#define    DMA_GCR_EN                                             DMA_GCR_EN_Msk

#define    DMA_CHCR_TSIZE_Pos                                     (16U)
#define    DMA_CHCR_TSIZE_Msk                                     (0xffffU << DMA_CHCR_TSIZE_Pos)
#define    DMA_CHCR_TSIZE                                         DMA_CHCR_TSIZE_Msk

#define    DMA_CHCR_PRI_Pos                                       (12U)
#define    DMA_CHCR_PRI_Msk                                       (0x3U << DMA_CHCR_PRI_Pos)
#define    DMA_CHCR_PRI                                           DMA_CHCR_PRI_Msk

#define    DMA_CHCR_INC_Pos                                       (11U)
#define    DMA_CHCR_INC_Msk                                       (0x1U << DMA_CHCR_INC_Pos)
#define    DMA_CHCR_INC                                           DMA_CHCR_INC_Msk

#define    DMA_CH7CR_DIR_Pos                                      (10U)
#define    DMA_CH7CR_DIR_Msk                                      (0x1UL << DMA_CH7CR_DIR_Pos)
#define    DMA_CH7CR_DIR                                          DMA_CH7CR_DIR_Msk

#define    DMA_CH7CR_RAM_INC_Pos                                  (9U)
#define    DMA_CH7CR_RAM_INC_Msk                                  (0x1UL << DMA_CH7CR_RAM_INC_Pos)
#define    DMA_CH7CR_RAM_RI                                       DMA_CH7CR_RAM_INC_Msk

#define    DMA_CH7CR_FLASH_INC_Pos                                (8U)
#define    DMA_CH7CR_FLASH_INC_Msk                                (0x1UL << DMA_CH7CR_FLASH_INC_Pos)
#define    DMA_CH7CR_INC                                          DMA_CH7CR_FLASH_INC_Msk

#define    DMA_CHCR_SSEL_Pos                                      (8U)
#define    DMA_CHCR_SSEL_Msk                                      (0x7U << DMA_CHCR_SSEL_Pos)
#define    DMA_CHCR_SSEL                                          DMA_CHCR_SSEL_Msk

#define    DMA_CHCR_SUSP_Pos                                      (7U)
#define    DMA_CHCR_SUSP_Msk                                      (0x1U << DMA_CHCR_SUSP_Pos)
#define    DMA_CHCR_SUSP                                          DMA_CHCR_SUSP_Msk

#define    DMA_CHCR_DIR_Pos                                       (6U)
#define    DMA_CHCR_DIR_Msk                                       (0x1U << DMA_CHCR_DIR_Pos)
#define    DMA_CHCR_DIR                                           DMA_CHCR_DIR_Msk

#define    DMA_CHCR_BDW_Pos                                       (4U)
#define    DMA_CHCR_BDW_Msk                                       (0x3U << DMA_CHCR_BDW_Pos)
#define    DMA_CHCR_BDW                                           DMA_CHCR_BDW_Msk

#define    DMA_CHCR_CIRC_Pos                                      (3U)
#define    DMA_CHCR_CIRC_Msk                                      (0x1U << DMA_CHCR_CIRC_Pos)
#define    DMA_CHCR_CIRC                                          DMA_CHCR_CIRC_Msk

#define    DMA_CHCR_FTIE_Pos                                      (2U)
#define    DMA_CHCR_FTIE_Msk                                      (0x1U << DMA_CHCR_FTIE_Pos)
#define    DMA_CHCR_FTIE                                          DMA_CHCR_FTIE_Msk

#define    DMA_CHCR_HTIE_Pos                                      (1U)
#define    DMA_CHCR_HTIE_Msk                                      (0x1U << DMA_CHCR_HTIE_Pos)
#define    DMA_CHCR_HTIE                                          DMA_CHCR_HTIE_Msk

#define    DMA_CHCR_EN_Pos                                        (0U)
#define    DMA_CHCR_EN_Msk                                        (0x1U << DMA_CHCR_EN_Pos)
#define    DMA_CHCR_EN                                            DMA_CHCR_EN_Msk

#define    DMA_CH7FAR_FLSAD_Pos                                   (0U)
#define    DMA_CH7FAR_FLSAD_Msk                                   (0x1ffffU << DMA_CH7FAR_FLSAD_Pos)
#define    DMA_CH7FAR_FLSAD                                       DMA_CH7FAR_FLSAD_Msk

#define    DMA_ISR_ADDRERR_Pos                                    (16U)
#define    DMA_ISR_ADDRERR_Msk                                    (0x1U << DMA_ISR_ADDRERR_Pos)
#define    DMA_ISR_ADDRERR                                        DMA_ISR_ADDRERR_Msk

#define    DMA_ISR_CHFT_Pos                                       (8U)
#define    DMA_ISR_CHFT_Msk                                       (0x1U << DMA_ISR_CHFT_Pos)
#define    DMA_ISR_CHFT                                           DMA_ISR_CHFT_Msk

#define    DMA_ISR_CHHT_Pos                                       (0U)
#define    DMA_ISR_CHHT_Msk                                       (0x1U << DMA_ISR_CHHT_Pos)
#define    DMA_ISR_CHHT                                           DMA_ISR_CHHT_Msk


#define    FL_DMA_CHANNEL_0                                       (0x0U << 0U)
#define    FL_DMA_CHANNEL_1                                       (0x1U << 0U)
#define    FL_DMA_CHANNEL_2                                       (0x2U << 0U)
#define    FL_DMA_CHANNEL_3                                       (0x3U << 0U)
#define    FL_DMA_CHANNEL_4                                       (0x4U << 0U)
#define    FL_DMA_CHANNEL_5                                       (0x5U << 0U)
#define    FL_DMA_CHANNEL_6                                       (0x6U << 0U)
#define    FL_DMA_CHANNEL_7                                       (0x7U << 0U)

#define    FL_DMA_PRIORITY_LOW                                    (0x0U << DMA_CHCR_PRI_Pos)
#define    FL_DMA_PRIORITY_MEDIUM                                 (0x1U << DMA_CHCR_PRI_Pos)
#define    FL_DMA_PRIORITY_HIGH                                   (0x2U << DMA_CHCR_PRI_Pos)
#define    FL_DMA_PRIORITY_VERYHIGH                               (0x3U << DMA_CHCR_PRI_Pos)

#define    FL_DMA_MEMORY_INC_MODE_INCREASE                        (0x1U << DMA_CHCR_INC_Pos)
#define    FL_DMA_MEMORY_INC_MODE_DECREASE                        (0x0U << DMA_CHCR_INC_Pos)
#define    FL_DMA_CH7_RAM_INC_MODE_INCREASE                       (0x1U << DMA_CH7CR_RAM_INC_Pos)
#define    FL_DMA_CH7_RAM_INC_MODE_DECREASE                       (0x0U << DMA_CH7CR_RAM_INC_Pos)
#define    FL_DMA_CH7_FLASH_INC_MODE_INCREASE                     (0x1U << DMA_CH7CR_FLASH_INC_Pos)
#define    FL_DMA_CH7_FLASH_INC_MODE_DECREASE                     (0x0U << DMA_CH7CR_FLASH_INC_Pos)

#define    FL_DMA_PERIPHERAL_FUNCTION1                            (0x0U << DMA_CHCR_SSEL_Pos)
#define    FL_DMA_PERIPHERAL_FUNCTION2                            (0x1U << DMA_CHCR_SSEL_Pos)
#define    FL_DMA_PERIPHERAL_FUNCTION3                            (0x2U << DMA_CHCR_SSEL_Pos)
#define    FL_DMA_PERIPHERAL_FUNCTION4                            (0x3U << DMA_CHCR_SSEL_Pos)
#define    FL_DMA_PERIPHERAL_FUNCTION5                            (0x4U << DMA_CHCR_SSEL_Pos)
#define    FL_DMA_PERIPHERAL_FUNCTION6                            (0x5U << DMA_CHCR_SSEL_Pos)
#define    FL_DMA_PERIPHERAL_FUNCTION7                            (0x6U << DMA_CHCR_SSEL_Pos)
#define    FL_DMA_PERIPHERAL_FUNCTION8                            (0x7U << DMA_CHCR_SSEL_Pos)

#define    FL_DMA_DIR_PERIPHERAL_TO_RAM                           (0x0U << DMA_CHCR_DIR_Pos)
#define    FL_DMA_DIR_RAM_TO_PERIPHERAL                           (0x1U << DMA_CHCR_DIR_Pos)
#define    FL_DMA_DIR_FLASH_TO_RAM                                (0x1U << DMA_CH7CR_DIR_Pos)
#define    FL_DMA_DIR_RAM_TO_FLASH                                (0x0U << DMA_CH7CR_DIR_Pos)

#define    FL_DMA_BANDWIDTH_8B                                    (0x0U << DMA_CHCR_BDW_Pos)
#define    FL_DMA_BANDWIDTH_16B                                   (0x1U << DMA_CHCR_BDW_Pos)
#define    FL_DMA_BANDWIDTH_32B                                   (0x2U << DMA_CHCR_BDW_Pos)

#define    FL_DMA_FLASHDIRECT_CODE                                (0x0U << DMA_CH7FAR_DFLS_Pos)
#define    FL_DMA_FLASHDIRECT_DATA                                (0x1U << DMA_CH7FAR_DFLS_Pos)

/**
  * @}
  */
/* Exported functions ---------------------------------------------------------------------------------*/
/** @defgroup DMA_FL_Exported_Functions DMA Exported Functions
  * @{
  */

/**
  * @brief    DMA address error interrupt enable
  * @rmtoll   GCR    ADDRERR_IE    FL_DMA_EnableIT_AddressError
  * @param    DMAx DMA instance
  * @retval   None
  */
__STATIC_INLINE void FL_DMA_EnableIT_AddressError(DMA_Type* DMAx)
{
    SET_BIT(DMAx->GCR, DMA_GCR_ADDRERR_IE_Msk);
}

/**
  * @brief    Get DMA address error interrupt enable status
  * @rmtoll   GCR    ADDRERR_IE    FL_DMA_IsEnabledIT_AddressError
  * @param    DMAx DMA instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_DMA_IsEnabledIT_AddressError(DMA_Type* DMAx)
{
    return (uint32_t)(READ_BIT(DMAx->GCR, DMA_GCR_ADDRERR_IE_Msk) == DMA_GCR_ADDRERR_IE_Msk);
}

/**
  * @brief    DMA address error interrupt disable
  * @rmtoll   GCR    ADDRERR_IE    FL_DMA_DisableIT_AddressError
  * @param    DMAx DMA instance
  * @retval   None
  */
__STATIC_INLINE void FL_DMA_DisableIT_AddressError(DMA_Type* DMAx)
{
    CLEAR_BIT(DMAx->GCR, DMA_GCR_ADDRERR_IE_Msk);
}

/**
  * @brief    DMA enable
  * @rmtoll   GCR    EN    FL_DMA_Enable
  * @param    DMAx DMA instance
  * @retval   None
  */
__STATIC_INLINE void FL_DMA_Enable(DMA_Type* DMAx)
{
    SET_BIT(DMAx->GCR, DMA_GCR_EN_Msk);
}

/**
  * @brief    Get DMA enable status
  * @rmtoll   GCR    EN    FL_DMA_IsEnabled
  * @param    DMAx DMA instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_DMA_IsEnabled(DMA_Type* DMAx)
{
    return (uint32_t)(READ_BIT(DMAx->GCR, DMA_GCR_EN_Msk) == DMA_GCR_EN_Msk);
}

/**
  * @brief    DMA disable
  * @rmtoll   GCR    EN    FL_DMA_Disable
  * @param    DMAx DMA instance
  * @retval   None
  */
__STATIC_INLINE void FL_DMA_Disable(DMA_Type* DMAx)
{
    CLEAR_BIT(DMAx->GCR, DMA_GCR_EN_Msk);
}

/**
  * @brief    Set channelx transmission length
  * @rmtoll   CHCR    TSIZE    FL_DMA_WriteTransmissionSize
  * @param    DMAx DMA instance
  * @param    size 
  * @param    channel This parameter can be one of the following values:
  *           @arg @ref FL_DMA_CHANNEL_0
  *           @arg @ref FL_DMA_CHANNEL_1
  *           @arg @ref FL_DMA_CHANNEL_2
  *           @arg @ref FL_DMA_CHANNEL_3
  *           @arg @ref FL_DMA_CHANNEL_4
  *           @arg @ref FL_DMA_CHANNEL_5
  *           @arg @ref FL_DMA_CHANNEL_6
  *           @arg @ref FL_DMA_CHANNEL_7
  * @retval   None
  */
__STATIC_INLINE void FL_DMA_WriteTransmissionSize(DMA_Type* DMAx, uint32_t size, uint32_t channel)
{
    DMA_ADDR  *Temp = (DMA_ADDR *)DMAx;
    if(size != 0)
    {
        if(channel <= FL_DMA_CHANNEL_6)
        {
            MODIFY_REG(Temp->Channel[channel].CHCR, (0xffffU << 16U), (size << 16U));
        }
        else
        {
            MODIFY_REG(Temp->CH7CR, (0xfffU << 16U), (size << 16U));
        } 
    }
}

/**
  * @brief    Get channelx transmission length
  * @rmtoll   CHCR    TSIZE    FL_DMA_ReadTransmissionSize
  * @param    DMAx DMA instance
  * @param    channel This parameter can be one of the following values:
  *           @arg @ref FL_DMA_CHANNEL_0
  *           @arg @ref FL_DMA_CHANNEL_1
  *           @arg @ref FL_DMA_CHANNEL_2
  *           @arg @ref FL_DMA_CHANNEL_3
  *           @arg @ref FL_DMA_CHANNEL_4
  *           @arg @ref FL_DMA_CHANNEL_5
  *           @arg @ref FL_DMA_CHANNEL_6
  *           @arg @ref FL_DMA_CHANNEL_7
  * @retval   
  */
__STATIC_INLINE uint32_t FL_DMA_ReadTransmissionSize(DMA_Type* DMAx, uint32_t channel)
{
    DMA_ADDR  *Temp = (DMA_ADDR *)DMAx;
    if(channel <= FL_DMA_CHANNEL_6)
    {
        return (uint32_t)(READ_BIT(Temp->Channel[channel].CHCR, (0xffffU << 16)) >> 16U);
    }
    else
    {
        return (uint32_t)(READ_BIT(Temp->CH7CR, (0xfffU << 16)) >> 16U);
    }
}

/**
  * @brief    Set channelx priority
  * @rmtoll   CHCR    PRI    FL_DMA_SetPriority
  * @param    DMAx DMA instance
  * @param    priority This parameter can be one of the following values:
  *           @arg @ref FL_DMA_PRIORITY_LOW
  *           @arg @ref FL_DMA_PRIORITY_MEDIUM
  *           @arg @ref FL_DMA_PRIORITY_HIGH
  *           @arg @ref FL_DMA_PRIORITY_VERYHIGH
  * @param    channel This parameter can be one of the following values:
  *           @arg @ref FL_DMA_CHANNEL_0
  *           @arg @ref FL_DMA_CHANNEL_1
  *           @arg @ref FL_DMA_CHANNEL_2
  *           @arg @ref FL_DMA_CHANNEL_3
  *           @arg @ref FL_DMA_CHANNEL_4
  *           @arg @ref FL_DMA_CHANNEL_5
  *           @arg @ref FL_DMA_CHANNEL_6
  *           @arg @ref FL_DMA_CHANNEL_7
  * @retval   None
  */
__STATIC_INLINE void FL_DMA_SetPriority(DMA_Type* DMAx, uint32_t priority, uint32_t channel)
{
    DMA_ADDR  *Temp = (DMA_ADDR *)DMAx;
    if(channel <= FL_DMA_CHANNEL_6)
    {
        MODIFY_REG(Temp->Channel[channel].CHCR, DMA_CHCR_PRI_Msk, priority);
    }
    else if(channel == FL_DMA_CHANNEL_7)
    {
        MODIFY_REG(Temp->CH7CR, DMA_CHCR_PRI_Msk, priority);
    }
    else
    {
        /* MODIFY_REG(Temp->, DMA_CHCR_PRI_Msk, priority); */
    }
}

/**
  * @brief    Get channelx priority
  * @rmtoll   CHCR    PRI    FL_DMA_GetPriority
  * @param    DMAx DMA instance
  * @param    channel This parameter can be one of the following values:
  *           @arg @ref FL_DMA_CHANNEL_0
  *           @arg @ref FL_DMA_CHANNEL_1
  *           @arg @ref FL_DMA_CHANNEL_2
  *           @arg @ref FL_DMA_CHANNEL_3
  *           @arg @ref FL_DMA_CHANNEL_4
  *           @arg @ref FL_DMA_CHANNEL_5
  *           @arg @ref FL_DMA_CHANNEL_6
  *           @arg @ref FL_DMA_CHANNEL_7
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_DMA_PRIORITY_LOW
  *           @arg @ref FL_DMA_PRIORITY_MEDIUM
  *           @arg @ref FL_DMA_PRIORITY_HIGH
  *           @arg @ref FL_DMA_PRIORITY_VERYHIGH
  */
__STATIC_INLINE uint32_t FL_DMA_GetPriority(DMA_Type* DMAx, uint32_t channel)
{
    DMA_ADDR  *Temp = (DMA_ADDR *)DMAx;
    if(channel <= FL_DMA_CHANNEL_6)
    {
        return (uint32_t)(READ_BIT(Temp->Channel[channel].CHCR, DMA_CHCR_PRI_Msk) >> DMA_CHCR_PRI_Pos);
    }
    else
    {
        return (uint32_t)(READ_BIT(Temp->CH7CR, DMA_CHCR_PRI_Msk)>> DMA_CHCR_PRI_Pos);
    }
}

/**
  * @brief    Set channelx RAM address incremental
  * @rmtoll   CHCR    INC    FL_DMA_SetMemoryIncrementMode 

  * @param    DMAx DMA instance
  * @param    mode This parameter can be one of the following values:
  *           @arg @ref FL_DMA_MEMORY_INC_MODE_INCREASE
  *           @arg @ref FL_DMA_MEMORY_INC_MODE_DECREASE
  * @param    channel This parameter can be one of the following values:
  *           @arg @ref FL_DMA_CHANNEL_0
  *           @arg @ref FL_DMA_CHANNEL_1
  *           @arg @ref FL_DMA_CHANNEL_2
  *           @arg @ref FL_DMA_CHANNEL_3
  *           @arg @ref FL_DMA_CHANNEL_4
  *           @arg @ref FL_DMA_CHANNEL_5
  *           @arg @ref FL_DMA_CHANNEL_6
  *           @arg @ref FL_DMA_CHANNEL_7
  * @retval   None
  */
__STATIC_INLINE void FL_DMA_SetMemoryIncrementMode (DMA_Type* DMAx, uint32_t mode, uint32_t channel)
{
    DMA_ADDR  *Temp = (DMA_ADDR *)DMAx;
    if(channel <= FL_DMA_CHANNEL_6)
    {
        MODIFY_REG(Temp->Channel[channel].CHCR, DMA_CHCR_INC_Msk, mode);
    }
    else
    {
        MODIFY_REG(Temp->CH7CR, DMA_CH7CR_RAM_INC_Msk, mode);
    }
}

/**
  * @brief    Get channelx RAM address incremental status
  * @rmtoll   CHCR    INC    FL_DMA_GetMemoryIncrementMode 
  * @param    DMAx DMA instance
  * @param    channel This parameter can be one of the following values:
  *           @arg @ref FL_DMA_CHANNEL_0
  *           @arg @ref FL_DMA_CHANNEL_1
  *           @arg @ref FL_DMA_CHANNEL_2
  *           @arg @ref FL_DMA_CHANNEL_3
  *           @arg @ref FL_DMA_CHANNEL_4
  *           @arg @ref FL_DMA_CHANNEL_5
  *           @arg @ref FL_DMA_CHANNEL_6
  *           @arg @ref FL_DMA_CHANNEL_7
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_DMA_MEMORY_INC_MODE_INCREASE
  *           @arg @ref FL_DMA_MEMORY_INC_MODE_DECREASE
  */
__STATIC_INLINE uint32_t FL_DMA_GetMemoryIncrementMode (DMA_Type* DMAx, uint32_t channel)
{
    DMA_ADDR  *Temp = (DMA_ADDR *)DMAx;
    if(channel <= FL_DMA_CHANNEL_6)
    {
        return (uint32_t)(READ_BIT(Temp->Channel[channel].CHCR, DMA_CHCR_INC_Msk) >> DMA_CHCR_INC_Pos);
    }
    else
    {
        return (uint32_t)(READ_BIT(Temp->CH7CR, DMA_CH7CR_RAM_INC_Msk)>> DMA_CH7CR_RAM_INC_Pos);
    }
}

/**
  * @brief
  * @rmtoll   CH7CR    INC    FL_DMA_SetFlashAddrIncremental
  * @param    DMAx DMA instance
  * @param    Incremental This parameter can be one of the following values:
  *           @arg @ref FL_DMA_CH7_FLASH_INC_MODE_INCREASE
  *           @arg @ref FL_DMA_CH7_FLASH_INC_MODE_DECREASE
  * @retval   None
  */
__STATIC_INLINE void FL_DMA_SetFlashAddrIncremental(DMA_Type *DMAx, uint32_t Incremental)
{
    DMA_ADDR  *Temp = (DMA_ADDR *)DMAx;
    MODIFY_REG(Temp->CH7CR, DMA_CH7CR_FLASH_INC_Msk, Incremental);
}
 
/**
  * @brief
  * @rmtoll   CHCR    INC    FL_DMA_GetFlashAddrIncremental
  * @param    DMAx DMA instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_DMA_CH7_FLASH_INC_MODE_INCREASE
  *           @arg @ref FL_DMA_CH7_FLASH_INC_MODE_DECREASE
  */
__STATIC_INLINE uint32_t FL_DMA_GetFlashAddrIncremental(DMA_Type *DMAx)
{
    DMA_ADDR  *Temp = (DMA_ADDR *)DMAx;
    return (uint32_t)(READ_BIT(Temp->CH7CR, DMA_CH7CR_FLASH_INC_Msk) >> DMA_CH7CR_FLASH_INC_Pos);
}

/**
  * @brief    Channelx request source select
  * @rmtoll   CHCR    SSEL    FL_DMA_SetPeripheralMap
  * @param    DMAx DMA instance
  * @param    peripheral This parameter can be one of the following values:
  *           @arg @ref FL_DMA_PERIPHERAL_FUNCTION1
  *           @arg @ref FL_DMA_PERIPHERAL_FUNCTION2
  *           @arg @ref FL_DMA_PERIPHERAL_FUNCTION3
  *           @arg @ref FL_DMA_PERIPHERAL_FUNCTION4
  *           @arg @ref FL_DMA_PERIPHERAL_FUNCTION5
  *           @arg @ref FL_DMA_PERIPHERAL_FUNCTION6
  *           @arg @ref FL_DMA_PERIPHERAL_FUNCTION7
  *           @arg @ref FL_DMA_PERIPHERAL_FUNCTION8
  * @param    channel This parameter can be one of the following values:
  *           @arg @ref FL_DMA_CHANNEL_0
  *           @arg @ref FL_DMA_CHANNEL_1
  *           @arg @ref FL_DMA_CHANNEL_2
  *           @arg @ref FL_DMA_CHANNEL_3
  *           @arg @ref FL_DMA_CHANNEL_4
  *           @arg @ref FL_DMA_CHANNEL_5
  *           @arg @ref FL_DMA_CHANNEL_6
  *           @arg @ref FL_DMA_CHANNEL_7
  * @retval   None
  */
__STATIC_INLINE void FL_DMA_SetPeripheralMap(DMA_Type* DMAx, uint32_t peripheral, uint32_t channel)
{
    DMA_ADDR  *Temp = (DMA_ADDR *)DMAx;
    if(channel <= FL_DMA_CHANNEL_6)
    {
        MODIFY_REG(Temp->Channel[channel].CHCR, DMA_CHCR_SSEL_Msk, peripheral);
    }
}

/**
  * @brief    Get Channelx request source select status
  * @rmtoll   CHCR    SSEL    FL_DMA_GetPeripheralMap
  * @param    DMAx DMA instance
  * @param    channel This parameter can be one of the following values:
  *           @arg @ref FL_DMA_CHANNEL_0
  *           @arg @ref FL_DMA_CHANNEL_1
  *           @arg @ref FL_DMA_CHANNEL_2
  *           @arg @ref FL_DMA_CHANNEL_3
  *           @arg @ref FL_DMA_CHANNEL_4
  *           @arg @ref FL_DMA_CHANNEL_5
  *           @arg @ref FL_DMA_CHANNEL_6
  *           @arg @ref FL_DMA_CHANNEL_7
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_DMA_PERIPHERAL_FUNCTION1
  *           @arg @ref FL_DMA_PERIPHERAL_FUNCTION2
  *           @arg @ref FL_DMA_PERIPHERAL_FUNCTION3
  *           @arg @ref FL_DMA_PERIPHERAL_FUNCTION4
  *           @arg @ref FL_DMA_PERIPHERAL_FUNCTION5
  *           @arg @ref FL_DMA_PERIPHERAL_FUNCTION6
  *           @arg @ref FL_DMA_PERIPHERAL_FUNCTION7
  *           @arg @ref FL_DMA_PERIPHERAL_FUNCTION8
  */
__STATIC_INLINE uint32_t FL_DMA_GetPeripheralMap(DMA_Type* DMAx, uint32_t channel)
{
    DMA_ADDR  *Temp = (DMA_ADDR *)DMAx;
    if(channel <= FL_DMA_CHANNEL_6)
    {
        return (uint32_t)(READ_BIT(Temp->Channel[channel].CHCR, DMA_CHCR_SSEL_Msk) >> DMA_CHCR_SSEL_Pos);
    }
    return 0;
}

/**
  * @brief    DMA channel suspend enable
  * @rmtoll   CHCR    SUSP    FL_DMA_EnableChannelSuspend
  * @param    DMAx DMA instance
  * @param    channel This parameter can be one of the following values:
  *           @arg @ref FL_DMA_CHANNEL_0
  *           @arg @ref FL_DMA_CHANNEL_1
  *           @arg @ref FL_DMA_CHANNEL_2
  *           @arg @ref FL_DMA_CHANNEL_3
  *           @arg @ref FL_DMA_CHANNEL_4
  *           @arg @ref FL_DMA_CHANNEL_5
  *           @arg @ref FL_DMA_CHANNEL_6
  *           @arg @ref FL_DMA_CHANNEL_7
  * @retval   None
  */
__STATIC_INLINE void FL_DMA_EnableChannelSuspend(DMA_Type *DMAx, uint32_t channel)
{
    DMA_ADDR  *Temp = (DMA_ADDR *)DMAx;
    if(channel <= FL_DMA_CHANNEL_6)
    {
        SET_BIT(Temp->Channel[channel].CHCR, DMA_CHCR_SUSP_Msk);
    }
    else
    {
        SET_BIT(Temp->CH7CR, DMA_CHCR_SUSP_Msk);
    }
}

/**
  * @brief    Get DMA channel suspend enable status
  * @rmtoll   CHCR    SUSP    FL_DMA_IsEnabledChannelSuspend
  * @param    DMAx DMA instance
  * @param    channel This parameter can be one of the following values:
  *           @arg @ref FL_DMA_CHANNEL_0
  *           @arg @ref FL_DMA_CHANNEL_1
  *           @arg @ref FL_DMA_CHANNEL_2
  *           @arg @ref FL_DMA_CHANNEL_3
  *           @arg @ref FL_DMA_CHANNEL_4
  *           @arg @ref FL_DMA_CHANNEL_5
  *           @arg @ref FL_DMA_CHANNEL_6
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_DMA_IsEnabledChannelSuspend(DMA_Type *DMAx, uint32_t channel)
{
    DMA_ADDR  *Temp = (DMA_ADDR *)DMAx;
    if(channel <= FL_DMA_CHANNEL_6)
    {
        return (uint32_t)(READ_BIT(Temp->Channel[channel].CHCR, DMA_CHCR_SUSP_Msk) == DMA_CHCR_SUSP_Msk);
    }
    return 0;
}

/**
  * @brief    DMA channel resume transmission
  * @rmtoll   CHCR    SUSP    FL_DMA_DisableChannelSuspend
  * @param    DMAx DMA instance
  * @param    channel This parameter can be one of the following values:
  *           @arg @ref FL_DMA_CHANNEL_0
  *           @arg @ref FL_DMA_CHANNEL_1
  *           @arg @ref FL_DMA_CHANNEL_2
  *           @arg @ref FL_DMA_CHANNEL_3
  *           @arg @ref FL_DMA_CHANNEL_4
  *           @arg @ref FL_DMA_CHANNEL_5
  *           @arg @ref FL_DMA_CHANNEL_6
  * @retval   None
  */
__STATIC_INLINE void FL_DMA_DisableChannelSuspend(DMA_Type *DMAx, uint32_t channel)
{
    DMA_ADDR  *Temp = (DMA_ADDR *)DMAx;
    if(channel <= FL_DMA_CHANNEL_6)
    {
        CLEAR_BIT(Temp->Channel[channel].CHCR, DMA_CHCR_SUSP_Msk);
    }
}

/**
  * @brief    Set channelx transmit direction 
  * @rmtoll   CHCR    DIR    FL_DMA_SetTransmissionDirection
  * @param    DMAx DMA instance
  * @param    direction This parameter can be one of the following values:
  *           @arg @ref FL_DMA_DIR_PERIPHERAL_TO_RAM
  *           @arg @ref FL_DMA_DIR_RAM_TO_PERIPHERAL
  *           @arg @ref 
  *           @arg @ref FL_DMA_DIR_FLASH_TO_RAM
  *           @arg @ref FL_DMA_DIR_RAM_TO_FLASH
  * @param    channel This parameter can be one of the following values:
  *           @arg @ref FL_DMA_CHANNEL_0
  *           @arg @ref FL_DMA_CHANNEL_1
  *           @arg @ref FL_DMA_CHANNEL_2
  *           @arg @ref FL_DMA_CHANNEL_3
  *           @arg @ref FL_DMA_CHANNEL_4
  *           @arg @ref FL_DMA_CHANNEL_5
  *           @arg @ref FL_DMA_CHANNEL_6
  *           @arg @ref 
  *           @arg @ref FL_DMA_CHANNEL_7
  * @retval   None
  */
__STATIC_INLINE void FL_DMA_SetTransmissionDirection(DMA_Type *DMAx, uint32_t direction, uint32_t channel)
{
    DMA_ADDR  *Temp = (DMA_ADDR *)DMAx;
    if(channel <= FL_DMA_CHANNEL_6)
    {
        MODIFY_REG(Temp->Channel[channel].CHCR, DMA_CHCR_DIR_Msk, direction);
    }
    else
    {
        MODIFY_REG(Temp->CH7CR, DMA_CH7CR_DIR_Msk, direction);
    }
}

/**
  * @brief    Get channelx transmit direction
  * @rmtoll   CHCR    DIR    FL_DMA_GetTransmissionDirection
  * @param    DMAx DMA instance
  * @param    channel This parameter can be one of the following values:
  *           @arg @ref FL_DMA_CHANNEL_0
  *           @arg @ref FL_DMA_CHANNEL_1
  *           @arg @ref FL_DMA_CHANNEL_2
  *           @arg @ref FL_DMA_CHANNEL_3
  *           @arg @ref FL_DMA_CHANNEL_4
  *           @arg @ref FL_DMA_CHANNEL_5
  *           @arg @ref FL_DMA_CHANNEL_6
  *           @arg @ref 
  *           @arg @ref FL_DMA_CHANNEL_7
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_DMA_DIR_PERIPHERAL_TO_RAM
  *           @arg @ref FL_DMA_DIR_RAM_TO_PERIPHERAL
  *           @arg @ref 
  *           @arg @ref FL_DMA_DIR_FLASH_TO_RAM
  *           @arg @ref FL_DMA_DIR_RAM_TO_FLASH
  */
__STATIC_INLINE uint32_t FL_DMA_GetTransmissionDirection(DMA_Type *DMAx, uint32_t channel)
{
    DMA_ADDR  *Temp = (DMA_ADDR *)DMAx;
    if(channel <= FL_DMA_CHANNEL_6)
    {
        return (uint32_t)(READ_BIT(Temp->Channel[channel].CHCR, DMA_CHCR_DIR_Msk) >> DMA_CHCR_DIR_Pos);
    }
    else
    {
        return (uint32_t)(READ_BIT(Temp->CH7CR, DMA_CH7CR_DIR_Msk) >> DMA_CH7CR_DIR_Pos);
    }
}

/**
  * @brief    Set transmit bandwidth
  * @rmtoll   CHCR    BDW    FL_DMA_SetBandwidth
  * @param    DMAx DMA instance
  * @param    bandwidth This parameter can be one of the following values:
  *           @arg @ref FL_DMA_BANDWIDTH_8B
  *           @arg @ref FL_DMA_BANDWIDTH_16B
  *           @arg @ref FL_DMA_BANDWIDTH_32B
  * @param    channel This parameter can be one of the following values:
  *           @arg @ref FL_DMA_CHANNEL_0
  *           @arg @ref FL_DMA_CHANNEL_1
  *           @arg @ref FL_DMA_CHANNEL_2
  *           @arg @ref FL_DMA_CHANNEL_3
  *           @arg @ref FL_DMA_CHANNEL_4
  *           @arg @ref FL_DMA_CHANNEL_5
  *           @arg @ref FL_DMA_CHANNEL_6
  *           @arg @ref FL_DMA_CHANNEL_7
  * @retval   None
  */
__STATIC_INLINE void FL_DMA_SetBandwidth(DMA_Type* DMAx, uint32_t bandwidth, uint32_t channel)
{
    DMA_ADDR  *Temp = (DMA_ADDR *)DMAx;
    if(channel <= FL_DMA_CHANNEL_6)
    {
        MODIFY_REG(Temp->Channel[channel].CHCR, DMA_CHCR_BDW_Msk, bandwidth);
    }
}

/**
  * @brief    Get transmit bandwidth
  * @rmtoll   CHCR    BDW    FL_DMA_GetBandwidth
  * @param    DMAx DMA instance
  * @param    channel This parameter can be one of the following values:
  *           @arg @ref FL_DMA_CHANNEL_0
  *           @arg @ref FL_DMA_CHANNEL_1
  *           @arg @ref FL_DMA_CHANNEL_2
  *           @arg @ref FL_DMA_CHANNEL_3
  *           @arg @ref FL_DMA_CHANNEL_4
  *           @arg @ref FL_DMA_CHANNEL_5
  *           @arg @ref FL_DMA_CHANNEL_6
  *           @arg @ref FL_DMA_CHANNEL_7
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_DMA_BANDWIDTH_8B
  *           @arg @ref FL_DMA_BANDWIDTH_16B
  *           @arg @ref FL_DMA_BANDWIDTH_32B
  */
__STATIC_INLINE uint32_t FL_DMA_GetBandwidth(DMA_Type* DMAx, uint32_t channel)
{
    DMA_ADDR  *Temp = (DMA_ADDR *)DMAx;
    if(channel <= FL_DMA_CHANNEL_6)
    {
        return (uint32_t)(READ_BIT(Temp->Channel[channel].CHCR, DMA_CHCR_BDW_Msk) >> DMA_CHCR_BDW_Pos);
    }
    else
    {
        /* FLASH 通道 默认位宽32Bit */
        return FL_DMA_BANDWIDTH_32B;
    }
}

/**
  * @brief    Circular mode enable
  * @rmtoll   CHCR    CIRC    FL_DMA_EnableCircularMode
  * @param    DMAx DMA instance
  * @param    channel This parameter can be one of the following values:
  *           @arg @ref FL_DMA_CHANNEL_0
  *           @arg @ref FL_DMA_CHANNEL_1
  *           @arg @ref FL_DMA_CHANNEL_2
  *           @arg @ref FL_DMA_CHANNEL_3
  *           @arg @ref FL_DMA_CHANNEL_4
  *           @arg @ref FL_DMA_CHANNEL_5
  *           @arg @ref FL_DMA_CHANNEL_6
  * @retval   None
  */
__STATIC_INLINE void FL_DMA_EnableCircularMode(DMA_Type* DMAx, uint32_t channel)
{
    DMA_ADDR  *Temp = (DMA_ADDR *)DMAx;
    if(channel <= FL_DMA_CHANNEL_6)
    {
        SET_BIT(Temp->Channel[channel].CHCR, DMA_CHCR_CIRC_Msk);
    }
    else
    {
        SET_BIT(Temp->CH7CR, DMA_CHCR_CIRC_Msk);
    }
}

/**
  * @brief    Get circular mode enable status
  * @rmtoll   CHCR    CIRC    FL_DMA_IsEnabledCircularMode
  * @param    DMAx DMA instance
  * @param    channel This parameter can be one of the following values:
  *           @arg @ref FL_DMA_CHANNEL_0
  *           @arg @ref FL_DMA_CHANNEL_1
  *           @arg @ref FL_DMA_CHANNEL_2
  *           @arg @ref FL_DMA_CHANNEL_3
  *           @arg @ref FL_DMA_CHANNEL_4
  *           @arg @ref FL_DMA_CHANNEL_5
  *           @arg @ref FL_DMA_CHANNEL_6
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_DMA_IsEnabledCircularMode(DMA_Type* DMAx, uint32_t channel)
{
    DMA_ADDR  *Temp = (DMA_ADDR *)DMAx;
    if(channel <= FL_DMA_CHANNEL_6)
    {
        return (uint32_t)(READ_BIT(Temp->Channel[channel].CHCR, DMA_CHCR_CIRC_Msk) == DMA_CHCR_CIRC_Msk);
    }
    else
    {
        return (uint32_t)(READ_BIT(Temp->CH7CR, DMA_CHCR_CIRC_Msk) == DMA_CHCR_CIRC_Msk);
    }
}

/**
  * @brief    Circular mode disable
  * @rmtoll   CHCR    CIRC    FL_DMA_DisableCircularMode
  * @param    DMAx DMA instance
  * @param    channel This parameter can be one of the following values:
  *           @arg @ref FL_DMA_CHANNEL_0
  *           @arg @ref FL_DMA_CHANNEL_1
  *           @arg @ref FL_DMA_CHANNEL_2
  *           @arg @ref FL_DMA_CHANNEL_3
  *           @arg @ref FL_DMA_CHANNEL_4
  *           @arg @ref FL_DMA_CHANNEL_5
  *           @arg @ref FL_DMA_CHANNEL_6
  * @retval   None
  */
__STATIC_INLINE void FL_DMA_DisableCircularMode(DMA_Type* DMAx, uint32_t channel)
{
    DMA_ADDR  *Temp = (DMA_ADDR *)DMAx;
    if(channel <= FL_DMA_CHANNEL_6)
    {
        CLEAR_BIT(Temp->Channel[channel].CHCR, DMA_CHCR_CIRC_Msk);
    }
    else
    {
        CLEAR_BIT(Temp->CH7CR, DMA_CHCR_CIRC_Msk);
    }
}

/**
  * @brief    channelx transmit finished interrupt enable
  * @rmtoll   CHCR    FTIE    FL_DMA_EnableIT_TransferComplete
  * @param    DMAx DMA instance
  * @param    channel This parameter can be one of the following values:
  *           @arg @ref FL_DMA_CHANNEL_0
  *           @arg @ref FL_DMA_CHANNEL_1
  *           @arg @ref FL_DMA_CHANNEL_2
  *           @arg @ref FL_DMA_CHANNEL_3
  *           @arg @ref FL_DMA_CHANNEL_4
  *           @arg @ref FL_DMA_CHANNEL_5
  *           @arg @ref FL_DMA_CHANNEL_6
  *           @arg @ref FL_DMA_CHANNEL_7
  * @retval   None
  */
__STATIC_INLINE void FL_DMA_EnableIT_TransferComplete(DMA_Type* DMAx, uint32_t channel)
{
    DMA_ADDR  *Temp = (DMA_ADDR *)DMAx;
    if(channel <= FL_DMA_CHANNEL_6)
    {
        SET_BIT(Temp->Channel[channel].CHCR, DMA_CHCR_FTIE_Msk);
    }
    else
    {
        SET_BIT(Temp->CH7CR, DMA_CHCR_FTIE_Msk);
    }
}

/**
  * @brief    Get channelx transmit finished interrupt enable status
  * @rmtoll   CHCR    FTIE    FL_DMA_IsEnabledIT_TransferComplete
  * @param    DMAx DMA instance
  * @param    channel This parameter can be one of the following values:
  *           @arg @ref FL_DMA_CHANNEL_0
  *           @arg @ref FL_DMA_CHANNEL_1
  *           @arg @ref FL_DMA_CHANNEL_2
  *           @arg @ref FL_DMA_CHANNEL_3
  *           @arg @ref FL_DMA_CHANNEL_4
  *           @arg @ref FL_DMA_CHANNEL_5
  *           @arg @ref FL_DMA_CHANNEL_6
  *           @arg @ref FL_DMA_CHANNEL_7
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_DMA_IsEnabledIT_TransferComplete(DMA_Type* DMAx, uint32_t channel)
{
    DMA_ADDR  *Temp = (DMA_ADDR *)DMAx;
    if(channel <= FL_DMA_CHANNEL_6)
    {
        return (uint32_t)(READ_BIT(Temp->Channel[channel].CHCR, DMA_CHCR_FTIE_Msk) == DMA_CHCR_FTIE_Msk);
    }
    else
    {
        return (uint32_t)(READ_BIT(Temp->CH7CR, DMA_CHCR_FTIE_Msk) == DMA_CHCR_FTIE_Msk);
    }
}

/**
  * @brief    channelx transmit finished interrupt disable
  * @rmtoll   CHCR    FTIE    FL_DMA_DisableIT_TransferComplete
  * @param    DMAx DMA instance
  * @param    channel This parameter can be one of the following values:
  *           @arg @ref FL_DMA_CHANNEL_0
  *           @arg @ref FL_DMA_CHANNEL_1
  *           @arg @ref FL_DMA_CHANNEL_2
  *           @arg @ref FL_DMA_CHANNEL_3
  *           @arg @ref FL_DMA_CHANNEL_4
  *           @arg @ref FL_DMA_CHANNEL_5
  *           @arg @ref FL_DMA_CHANNEL_6
  *           @arg @ref FL_DMA_CHANNEL_7
  * @retval   None
  */
__STATIC_INLINE void FL_DMA_DisableIT_TransferComplete(DMA_Type* DMAx, uint32_t channel)
{
    DMA_ADDR  *Temp = (DMA_ADDR *)DMAx;
    if(channel <= FL_DMA_CHANNEL_6)
    {
        CLEAR_BIT(Temp->Channel[channel].CHCR, DMA_CHCR_FTIE_Msk);
    }
    else
    {
        CLEAR_BIT(Temp->CH7CR, DMA_CHCR_FTIE_Msk);
    }
}

/**
  * @brief    Channelx Half-transfer interrupt enable
  * @rmtoll   CHCR    HTIE    FL_DMA_EnableIT_TransferHalfComplete
  * @param    DMAx DMA instance
  * @param    channel This parameter can be one of the following values:
  *           @arg @ref FL_DMA_CHANNEL_0
  *           @arg @ref FL_DMA_CHANNEL_1
  *           @arg @ref FL_DMA_CHANNEL_2
  *           @arg @ref FL_DMA_CHANNEL_3
  *           @arg @ref FL_DMA_CHANNEL_4
  *           @arg @ref FL_DMA_CHANNEL_5
  *           @arg @ref FL_DMA_CHANNEL_6
  *           @arg @ref FL_DMA_CHANNEL_7
  * @retval   None
  */
__STATIC_INLINE void FL_DMA_EnableIT_TransferHalfComplete(DMA_Type* DMAx, uint32_t channel)
{
    DMA_ADDR  *Temp = (DMA_ADDR *)DMAx;
    if(channel <= FL_DMA_CHANNEL_6)
    {
        SET_BIT(Temp->Channel[channel].CHCR, DMA_CHCR_HTIE_Msk);
    }
    else
    {
        SET_BIT(Temp->CH7CR, DMA_CHCR_HTIE_Msk);
    } 
}

/**
  * @brief    Get Channelx Half-transfer interrupt enable status
  * @rmtoll   CHCR    HTIE    FL_DMA_IsEnabledIT_TransferHalfComplete
  * @param    DMAx DMA instance
  * @param    channel This parameter can be one of the following values:
  *           @arg @ref FL_DMA_CHANNEL_0
  *           @arg @ref FL_DMA_CHANNEL_1
  *           @arg @ref FL_DMA_CHANNEL_2
  *           @arg @ref FL_DMA_CHANNEL_3
  *           @arg @ref FL_DMA_CHANNEL_4
  *           @arg @ref FL_DMA_CHANNEL_5
  *           @arg @ref FL_DMA_CHANNEL_6
  *           @arg @ref FL_DMA_CHANNEL_7
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_DMA_IsEnabledIT_TransferHalfComplete(DMA_Type* DMAx, uint32_t channel)
{
    DMA_ADDR  *Temp = (DMA_ADDR *)DMAx;
    if(channel <= FL_DMA_CHANNEL_6)
    {
        return (uint32_t)(READ_BIT(Temp->Channel[channel].CHCR, DMA_CHCR_HTIE_Msk) == DMA_CHCR_HTIE_Msk);
    }
    else
    {
        return (uint32_t)(READ_BIT(Temp->CH7CR, DMA_CHCR_HTIE_Msk) == DMA_CHCR_HTIE_Msk);
    }
}

/**
  * @brief    Channelx Half-transfer interrupt disable
  * @rmtoll   CHCR    HTIE    FL_DMA_DisableIT_TransferHalfComplete
  * @param    DMAx DMA instance
  * @param    channel This parameter can be one of the following values:
  *           @arg @ref FL_DMA_CHANNEL_0
  *           @arg @ref FL_DMA_CHANNEL_1
  *           @arg @ref FL_DMA_CHANNEL_2
  *           @arg @ref FL_DMA_CHANNEL_3
  *           @arg @ref FL_DMA_CHANNEL_4
  *           @arg @ref FL_DMA_CHANNEL_5
  *           @arg @ref FL_DMA_CHANNEL_6
  *           @arg @ref FL_DMA_CHANNEL_7
  * @retval   None
  */
__STATIC_INLINE void FL_DMA_DisableIT_TransferHalfComplete(DMA_Type* DMAx, uint32_t channel)
{
    DMA_ADDR  *Temp = (DMA_ADDR *)DMAx;
    if(channel <= FL_DMA_CHANNEL_6)
    {
        CLEAR_BIT(Temp->Channel[channel].CHCR, DMA_CHCR_HTIE_Msk);
    }
    else
    {
        CLEAR_BIT(Temp->CH7CR, DMA_CHCR_HTIE_Msk);
    }
}

/**
  * @brief    Channelx enable
  * @rmtoll   CHCR    EN    FL_DMA_EnableChannel
  * @param    DMAx DMA instance
  * @param    channel This parameter can be one of the following values:
  *           @arg @ref FL_DMA_CHANNEL_0
  *           @arg @ref FL_DMA_CHANNEL_1
  *           @arg @ref FL_DMA_CHANNEL_2
  *           @arg @ref FL_DMA_CHANNEL_3
  *           @arg @ref FL_DMA_CHANNEL_4
  *           @arg @ref FL_DMA_CHANNEL_5
  *           @arg @ref FL_DMA_CHANNEL_6
  *           @arg @ref FL_DMA_CHANNEL_7
  * @retval   None
  */
__STATIC_INLINE void FL_DMA_EnableChannel(DMA_Type* DMAx, uint32_t channel)
{
    DMA_ADDR  *Temp = (DMA_ADDR *)DMAx;
    if(channel <= FL_DMA_CHANNEL_6)
    {
        SET_BIT(Temp->Channel[channel].CHCR, DMA_CHCR_EN_Msk);
    }
    else
    {
        SET_BIT(Temp->CH7CR, DMA_CHCR_EN_Msk);
    }
}

/**
  * @brief    Get channelx enable status
  * @rmtoll   CHCR    EN    FL_DMA_IsEnabledChannel
  * @param    DMAx DMA instance
  * @param    channel This parameter can be one of the following values:
  *           @arg @ref FL_DMA_CHANNEL_0
  *           @arg @ref FL_DMA_CHANNEL_1
  *           @arg @ref FL_DMA_CHANNEL_2
  *           @arg @ref FL_DMA_CHANNEL_3
  *           @arg @ref FL_DMA_CHANNEL_4
  *           @arg @ref FL_DMA_CHANNEL_5
  *           @arg @ref FL_DMA_CHANNEL_6
  *           @arg @ref FL_DMA_CHANNEL_7
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_DMA_IsEnabledChannel(DMA_Type* DMAx, uint32_t channel)
{
    DMA_ADDR  *Temp = (DMA_ADDR *)DMAx;
    if(channel <= FL_DMA_CHANNEL_6)
    {
        return (uint32_t)(READ_BIT(Temp->Channel[channel].CHCR, DMA_CHCR_EN_Msk) == DMA_CHCR_EN_Msk);
    }
    else
    {
        return (uint32_t)(READ_BIT(Temp->CH7CR, DMA_CHCR_CIRC_Msk) == DMA_CHCR_EN_Msk);
    }
}

/**
  * @brief    Channelx disable
  * @rmtoll   CHCR    EN    FL_DMA_DisableChannel
  * @param    DMAx DMA instance
  * @param    channel This parameter can be one of the following values:
  *           @arg @ref FL_DMA_CHANNEL_0
  *           @arg @ref FL_DMA_CHANNEL_1
  *           @arg @ref FL_DMA_CHANNEL_2
  *           @arg @ref FL_DMA_CHANNEL_3
  *           @arg @ref FL_DMA_CHANNEL_4
  *           @arg @ref FL_DMA_CHANNEL_5
  *           @arg @ref FL_DMA_CHANNEL_6
  *           @arg @ref FL_DMA_CHANNEL_7
  * @retval   None
  */
__STATIC_INLINE void FL_DMA_DisableChannel(DMA_Type* DMAx, uint32_t channel)
{
    DMA_ADDR  *Temp = (DMA_ADDR *)DMAx;
    if(channel <= FL_DMA_CHANNEL_6)
    {
        CLEAR_BIT(Temp->Channel[channel].CHCR, DMA_CHCR_EN_Msk);
    }
    else
    {
        CLEAR_BIT(Temp->CH7CR, DMA_CHCR_EN_Msk);
    }
}

/**
  * @brief    Set channelx memory pointer address 
  * @rmtoll   MEMAD        FL_DMA_WriteMemoryAddress
  * @param    DMAx DMA instance
  * @param    data 
  * @param    channel This parameter can be one of the following values:
  *           @arg @ref FL_DMA_CHANNEL_0
  *           @arg @ref FL_DMA_CHANNEL_1
  *           @arg @ref FL_DMA_CHANNEL_2
  *           @arg @ref FL_DMA_CHANNEL_3
  *           @arg @ref FL_DMA_CHANNEL_4
  *           @arg @ref FL_DMA_CHANNEL_5
  *           @arg @ref FL_DMA_CHANNEL_6
  *           @arg @ref FL_DMA_CHANNEL_7
  * @retval   None
  */
__STATIC_INLINE void FL_DMA_WriteMemoryAddress(DMA_Type* DMAx, uint32_t data, uint32_t channel)
{
    DMA_ADDR  *Temp = (DMA_ADDR *)DMAx;
    if(channel <= FL_DMA_CHANNEL_6)
    {
        MODIFY_REG(Temp->Channel[channel].CHMAD, (0xffffffffU), (data));
    }
    else
    {
        MODIFY_REG(Temp->CH7RAMAD, (0xfffU), (data));
    }
}

/**
  * @brief    Get channelx memory pointer address 
  * @rmtoll   MEMAD        FL_DMA_ReadMemoryAddress
  * @param    DMAx DMA instance
  * @param    channel This parameter can be one of the following values:
  *           @arg @ref FL_DMA_CHANNEL_0
  *           @arg @ref FL_DMA_CHANNEL_1
  *           @arg @ref FL_DMA_CHANNEL_2
  *           @arg @ref FL_DMA_CHANNEL_3
  *           @arg @ref FL_DMA_CHANNEL_4
  *           @arg @ref FL_DMA_CHANNEL_5
  *           @arg @ref FL_DMA_CHANNEL_6
  *           @arg @ref FL_DMA_CHANNEL_7
  * @retval   
  */
__STATIC_INLINE uint32_t FL_DMA_ReadMemoryAddress(DMA_Type* DMAx, uint32_t channel)
{
    DMA_ADDR  *Temp = (DMA_ADDR *)DMAx;
    if(channel <= FL_DMA_CHANNEL_6)
    {
        return (uint32_t)(READ_BIT(Temp->Channel[channel].CHMAD, (0xffffffffU)));
    }
    else
    {
        return (uint32_t)(READ_BIT(Temp->CH7RAMAD, (0xfffU)));
    }
}

/**
  * @brief    Set channel7 flash pointer address
  * @rmtoll   CH7FAR    FLSAD    FL_DMA_WriteFlashAddress
  * @param    DMAx DMA instance
  * @param    data 
  * @retval   None
  */
__STATIC_INLINE void FL_DMA_WriteFlashAddress(DMA_Type* DMAx, uint32_t data)
{
    MODIFY_REG(DMAx->CH7FLSAD, (0xffffU << 0U), (data << 0U));
}

/**
  * @brief    Get channel7 flash pointer address
  * @rmtoll   CH7FAR    FLSAD    FL_DMA_ReadFlashAddress
  * @param    DMAx DMA instance
  * @retval   
  */
__STATIC_INLINE uint32_t FL_DMA_ReadFlashAddress(DMA_Type* DMAx)
{
    return (uint32_t)(READ_BIT(DMAx->CH7FLSAD, (0xffffU << 0U)) >> 0U);
}

/**
  * @brief    Get DMA address error flag
  * @rmtoll   ISR    ADDRERR    FL_DMA_IsActiveFlag_AddressError
  * @param    DMAx DMA instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_DMA_IsActiveFlag_AddressError(DMA_Type* DMAx)
{
    return (uint32_t)(READ_BIT(DMAx->ISR, DMA_ISR_ADDRERR_Msk) == (DMA_ISR_ADDRERR_Msk));
}

/**
  * @brief    Clear DMA address error flag
  * @rmtoll   ISR    ADDRERR    FL_DMA_ClearFlag_AddressError
  * @param    DMAx DMA instance
  * @retval   None
  */
__STATIC_INLINE void FL_DMA_ClearFlag_AddressError(DMA_Type* DMAx)
{
    WRITE_REG(DMAx->ISR, DMA_ISR_ADDRERR_Msk);
}

/**
  * @brief    Get DMA channelx finished-transfer flag
  * @rmtoll   ISR    CHFT    FL_DMA_IsActiveFlag_TransferComplete
  * @param    DMAx DMA instance
  * @param    channel This parameter can be one of the following values:
  *           @arg @ref FL_DMA_CHANNEL_0
  *           @arg @ref FL_DMA_CHANNEL_1
  *           @arg @ref FL_DMA_CHANNEL_2
  *           @arg @ref FL_DMA_CHANNEL_3
  *           @arg @ref FL_DMA_CHANNEL_4
  *           @arg @ref FL_DMA_CHANNEL_5
  *           @arg @ref FL_DMA_CHANNEL_6
  *           @arg @ref FL_DMA_CHANNEL_7
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_DMA_IsActiveFlag_TransferComplete(DMA_Type* DMAx, uint32_t channel)
{
    return (uint32_t)(uint32_t)(READ_BIT(DMAx->ISR, (DMA_ISR_CHFT_Msk << channel))
                                == (DMA_ISR_CHFT_Msk << channel));
}

/**
  * @brief    Clear DMA channelx finished-transfer flag
  * @rmtoll   ISR    CHFT    FL_DMA_ClearFlag_TransferComplete
  * @param    DMAx DMA instance
  * @param    channel This parameter can be one of the following values:
  *           @arg @ref FL_DMA_CHANNEL_0
  *           @arg @ref FL_DMA_CHANNEL_1
  *           @arg @ref FL_DMA_CHANNEL_2
  *           @arg @ref FL_DMA_CHANNEL_3
  *           @arg @ref FL_DMA_CHANNEL_4
  *           @arg @ref FL_DMA_CHANNEL_5
  *           @arg @ref FL_DMA_CHANNEL_6
  *           @arg @ref FL_DMA_CHANNEL_7
  * @retval   None
  */
__STATIC_INLINE void FL_DMA_ClearFlag_TransferComplete(DMA_Type* DMAx, uint32_t channel)
{
    WRITE_REG(DMAx->ISR, (DMA_ISR_CHFT_Msk << channel));
}

/**
  * @brief    Get DMA channel half-transfer flag
  * @rmtoll   ISR    CHHT    FL_DMA_IsActiveFlag_TransferHalfComplete
  * @param    DMAx DMA instance
  * @param    channel This parameter can be one of the following values:
  *           @arg @ref FL_DMA_CHANNEL_0
  *           @arg @ref FL_DMA_CHANNEL_1
  *           @arg @ref FL_DMA_CHANNEL_2
  *           @arg @ref FL_DMA_CHANNEL_3
  *           @arg @ref FL_DMA_CHANNEL_4
  *           @arg @ref FL_DMA_CHANNEL_5
  *           @arg @ref FL_DMA_CHANNEL_6
  *           @arg @ref FL_DMA_CHANNEL_7
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_DMA_IsActiveFlag_TransferHalfComplete(DMA_Type* DMAx, uint32_t channel)
{
    return (uint32_t)(uint32_t)(READ_BIT(DMAx->ISR, (DMA_ISR_CHHT_Msk << channel))
                                == (DMA_ISR_CHHT_Msk << channel));
}


/**
  * @brief    Clear DMA channel half-transfer flag
  * @rmtoll   ISR    CHHT    FL_DMA_ClearFlag_TransferHalfComplete
  * @param    DMAx DMA instance
  * @param    channel This parameter can be one of the following values:
  *           @arg @ref FL_DMA_CHANNEL_0
  *           @arg @ref FL_DMA_CHANNEL_1
  *           @arg @ref FL_DMA_CHANNEL_2
  *           @arg @ref FL_DMA_CHANNEL_3
  *           @arg @ref FL_DMA_CHANNEL_4
  *           @arg @ref FL_DMA_CHANNEL_5
  *           @arg @ref FL_DMA_CHANNEL_6
  *           @arg @ref FL_DMA_CHANNEL_7
  * @retval   None
  */
__STATIC_INLINE void FL_DMA_ClearFlag_TransferHalfComplete(DMA_Type* DMAx, uint32_t channel)
{
   WRITE_REG(DMAx->ISR, (DMA_ISR_CHHT_Msk << channel));
}


/**
  * @}
  */

/** @defgroup DMA_FL_EF_Init Initialization and de-initialization functions
  * @{
  */
FL_ErrorStatus FL_DMA_DeInit(DMA_Type *DMAx);
FL_ErrorStatus FL_DMA_Init(DMA_Type *DMAx, FL_DMA_InitTypeDef *initStruct, uint32_t channel);
void FL_DMA_StructInit(FL_DMA_InitTypeDef *InitStruct);

FL_ErrorStatus FL_DMA_StartTransmission(DMA_Type *DMAx, FL_DMA_ConfigTypeDef *configStruct, uint32_t channel);


/**
  * @}
  */


/**
  * @}
  */

#ifdef __cplusplus
}
#endif

#endif /* __FM33FG0XXA_FL_DMA_H*/

/*************************Py_Code_Generator Version: 0.1-0.14-0.1 @ 2023-03-23*************************/
/*************************(C) COPYRIGHT Fudan Microelectronics **** END OF FILE*************************/
