 /**   
  *******************************************************************************************************
  * @file    fm33fg0xxa_fl_dac.h
  * @author  FMSH Application Team
  * @brief   Head file of DAC FL Module 
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
#ifndef __FM33FG0XXA_FL_DAC_H
#define __FM33FG0XXA_FL_DAC_H

#ifdef __cplusplus
extern "C" {
#endif
/* Includes -------------------------------------------------------------------------------------------*/
#include "fm33fg0xxa_fl_def.h"
/** @addtogroup FM33FG0XXA_FL_Driver
  * @{
  */
/* Exported types -------------------------------------------------------------------------------------*/
/** @defgroup DAC_FL_ES_INIT DAC Exported Init structures
  * @{
  */

/**
  * @brief FL DAC Init Sturcture definition
  */
typedef struct
{
    /* DAC触发使能配置 */
    uint32_t triggerMode;
    /* DAC触发源配置 */
    uint32_t triggerSource;
    /* DAC反馈开关配置 */
    uint32_t switchMode;
}FL_DAC_InitTypeDef;


/**
  * @}
  */
/* Exported constants ---------------------------------------------------------------------------------*/
/** @defgroup DAC_FL_Exported_Constants DAC Exported Constants
  * @{
  */

#define    DAC_CR1_EN_Pos                                         (0U)
#define    DAC_CR1_EN_Msk                                         (0x1U << DAC_CR1_EN_Pos)
#define    DAC_CR1_EN                                             DAC_CR1_EN_Msk

#define    DAC_CR2_DMAEN_Pos                                      (1U)
#define    DAC_CR2_DMAEN_Msk                                      (0x1U << DAC_CR2_DMAEN_Pos)
#define    DAC_CR2_DMAEN                                          DAC_CR2_DMAEN_Msk

#define    DAC_CR2_TRGEN_Pos                                      (0U)
#define    DAC_CR2_TRGEN_Msk                                      (0x1U << DAC_CR2_TRGEN_Pos)
#define    DAC_CR2_TRGEN                                          DAC_CR2_TRGEN_Msk

#define    DAC_CFGR_TRGSEL_Pos                                    (2U)
#define    DAC_CFGR_TRGSEL_Msk                                    (0xfU << DAC_CFGR_TRGSEL_Pos)
#define    DAC_CFGR_TRGSEL                                        DAC_CFGR_TRGSEL_Msk

#define    DAC_CFGR_SWIEN_Pos                                     (0U)
#define    DAC_CFGR_SWIEN_Msk                                     (0x1U << DAC_CFGR_SWIEN_Pos)
#define    DAC_CFGR_SWIEN                                         DAC_CFGR_SWIEN_Msk

#define    DAC_SWTRGR_SWTRIG_Pos                                  (0U)
#define    DAC_SWTRGR_SWTRIG_Msk                                  (0x1U << DAC_SWTRGR_SWTRIG_Pos)
#define    DAC_SWTRGR_SWTRIG                                      DAC_SWTRGR_SWTRIG_Msk

#define    DAC_DHR_DHR_Pos                                        (0U)
#define    DAC_DHR_DHR_Msk                                        (0x3ffU << DAC_DHR_DHR_Pos)
#define    DAC_DHR_DHR                                            DAC_DHR_DHR_Msk

#define    DAC_IER_DMAE_IE_Pos                                    (3U)
#define    DAC_IER_DMAE_IE_Msk                                    (0x1U << DAC_IER_DMAE_IE_Pos)
#define    DAC_IER_DMAE_IE                                        DAC_IER_DMAE_IE_Msk

#define    DAC_IER_DOU_IE_Pos                                     (0U)
#define    DAC_IER_DOU_IE_Msk                                     (0x1U << DAC_IER_DOU_IE_Pos)
#define    DAC_IER_DOU_IE                                         DAC_IER_DOU_IE_Msk

#define    DAC_ISR_DMAERR_Pos                                     (3U)
#define    DAC_ISR_DMAERR_Msk                                     (0x1U << DAC_ISR_DMAERR_Pos)
#define    DAC_ISR_DMAERR                                         DAC_ISR_DMAERR_Msk

#define    DAC_ISR_DOU_Pos                                        (0U)
#define    DAC_ISR_DOU_Msk                                        (0x1U << DAC_ISR_DOU_Pos)
#define    DAC_ISR_DOU                                            DAC_ISR_DOU_Msk


#define    FL_DAC_TRGI_SOFTWARE                                   (0x0U << DAC_CFGR_TRGSEL_Pos)
#define    FL_DAC_TRGI_ATIM                                       (0x1U << DAC_CFGR_TRGSEL_Pos)
#define    FL_DAC_TRGI_GPTIM1                                     (0x2U << DAC_CFGR_TRGSEL_Pos)
#define    FL_DAC_TRGI_GPTIM2                                     (0x3U << DAC_CFGR_TRGSEL_Pos)
#define    FL_DAC_TRGI_BSTIM                                      (0x4U << DAC_CFGR_TRGSEL_Pos)
#define    FL_DAC_TRGI_LPTIM                                      (0x5U << DAC_CFGR_TRGSEL_Pos)
#define    FL_DAC_TRGI_TAU00                                      (0x6U << DAC_CFGR_TRGSEL_Pos)
#define    FL_DAC_TRGI_TAU03                                      (0x7U << DAC_CFGR_TRGSEL_Pos)
#define    FL_DAC_TRGI_EXTIFAB13                                  (0xcU << DAC_CFGR_TRGSEL_Pos)
#define    FL_DAC_TRGI_EXTIFAB29                                  (0xdU << DAC_CFGR_TRGSEL_Pos)
#define    FL_DAC_TRGI_EXTIFCD4                                   (0xeU << DAC_CFGR_TRGSEL_Pos)
#define    FL_DAC_TRGI_EXTIFCD30                                  (0xfU << DAC_CFGR_TRGSEL_Pos)


/**
  * @}
  */
/* Exported functions ---------------------------------------------------------------------------------*/
/** @defgroup DAC_FL_Exported_Functions DAC Exported Functions
  * @{
  */

/**
  * @brief    Enable DAC
  * @rmtoll   CR1    EN    FL_DAC_Enable
  * @param    DACx DAC instance
  * @retval   None
  */
__STATIC_INLINE void FL_DAC_Enable(DAC_Type* DACx)
{
    SET_BIT(DACx->CR1, DAC_CR1_EN_Msk);
}

/**
  * @brief    Disable DAC
  * @rmtoll   CR1    EN    FL_DAC_Disable
  * @param    DACx DAC instance
  * @retval   None
  */
__STATIC_INLINE void FL_DAC_Disable(DAC_Type* DACx)
{
    CLEAR_BIT(DACx->CR1, DAC_CR1_EN_Msk);
}

/**
  * @brief    Get DAC Enable Status
  * @rmtoll   CR1    EN    FL_DAC_IsEnabled
  * @param    DACx DAC instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_DAC_IsEnabled(DAC_Type* DACx)
{
    return (uint32_t)(READ_BIT(DACx->CR1, DAC_CR1_EN_Msk) == DAC_CR1_EN_Msk);
}

/**
  * @brief    Enable DAC DMA
  * @rmtoll   CR2    DMAEN    FL_DAC_EnableDMAReq
  * @param    DACx DAC instance
  * @retval   None
  */
__STATIC_INLINE void FL_DAC_EnableDMAReq(DAC_Type* DACx)
{
    SET_BIT(DACx->CR2, DAC_CR2_DMAEN_Msk);
}

/**
  * @brief    Disable DAC DMA
  * @rmtoll   CR2    DMAEN    FL_DAC_DisableDMAReq
  * @param    DACx DAC instance
  * @retval   None
  */
__STATIC_INLINE void FL_DAC_DisableDMAReq(DAC_Type* DACx)
{
    CLEAR_BIT(DACx->CR2, DAC_CR2_DMAEN_Msk);
}

/**
  * @brief    Get DAC DMA Enable Status
  * @rmtoll   CR2    DMAEN    FL_DAC_IsEnabledDMAReq
  * @param    DACx DAC instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_DAC_IsEnabledDMAReq(DAC_Type* DACx)
{
    return (uint32_t)(READ_BIT(DACx->CR2, DAC_CR2_DMAEN_Msk) == DAC_CR2_DMAEN_Msk);
}

/**
  * @brief    Enable DAC Trigger
  * @rmtoll   CR2    TRGEN    FL_DAC_EnableTriggerMode
  * @param    DACx DAC instance
  * @retval   None
  */
__STATIC_INLINE void FL_DAC_EnableTriggerMode(DAC_Type* DACx)
{
    SET_BIT(DACx->CR2, DAC_CR2_TRGEN_Msk);
}

/**
  * @brief    Disable DAC Trigger 
  * @rmtoll   CR2    TRGEN    FL_DAC_DisableTriggerMode
  * @param    DACx DAC instance
  * @retval   None
  */
__STATIC_INLINE void FL_DAC_DisableTriggerMode(DAC_Type* DACx)
{
    CLEAR_BIT(DACx->CR2, DAC_CR2_TRGEN_Msk);
}

/**
  * @brief    Get DAC Trigger  Enable Status
  * @rmtoll   CR2    TRGEN    FL_DAC_IsEnabledTriggerMode
  * @param    DACx DAC instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_DAC_IsEnabledTriggerMode(DAC_Type* DACx)
{
    return (uint32_t)(READ_BIT(DACx->CR2, DAC_CR2_TRGEN_Msk) == DAC_CR2_TRGEN_Msk);
}

/**
  * @brief    Set DAC Trigger Source
  * @note     Can Only Be Modified When TRGEN=0
  * @rmtoll   CFGR    TRGSEL    FL_DAC_SetTriggerSource
  * @param    DACx DAC instance
  * @param    source This parameter can be one of the following values:
  *           @arg @ref FL_DAC_TRGI_SOFTWARE
  *           @arg @ref FL_DAC_TRGI_ATIM
  *           @arg @ref FL_DAC_TRGI_GPTIM1
  *           @arg @ref FL_DAC_TRGI_GPTIM2
  *           @arg @ref FL_DAC_TRGI_BSTIM
  *           @arg @ref FL_DAC_TRGI_LPTIM
  *           @arg @ref FL_DAC_TRGI_TAU00
  *           @arg @ref FL_DAC_TRGI_TAU03
  *           @arg @ref FL_DAC_TRGI_EXTIFAB13
  *           @arg @ref FL_DAC_TRGI_EXTIFAB29
  *           @arg @ref FL_DAC_TRGI_EXTIFCD4
  *           @arg @ref FL_DAC_TRGI_EXTIFCD30
  * @retval   None
  */
__STATIC_INLINE void FL_DAC_SetTriggerSource(DAC_Type* DACx, uint32_t source)
{
    MODIFY_REG(DACx->CFGR, DAC_CFGR_TRGSEL_Msk, source);
}

/**
  * @brief    Get DAC Trigger Source
  * @rmtoll   CFGR    TRGSEL    FL_DAC_GetTriggerSource
  * @param    DACx DAC instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_DAC_TRGI_SOFTWARE
  *           @arg @ref FL_DAC_TRGI_ATIM
  *           @arg @ref FL_DAC_TRGI_GPTIM1
  *           @arg @ref FL_DAC_TRGI_GPTIM2
  *           @arg @ref FL_DAC_TRGI_BSTIM
  *           @arg @ref FL_DAC_TRGI_LPTIM
  *           @arg @ref FL_DAC_TRGI_TAU00
  *           @arg @ref FL_DAC_TRGI_TAU03
  *           @arg @ref FL_DAC_TRGI_EXTIFAB13
  *           @arg @ref FL_DAC_TRGI_EXTIFAB29
  *           @arg @ref FL_DAC_TRGI_EXTIFCD4
  *           @arg @ref FL_DAC_TRGI_EXTIFCD30
  */
__STATIC_INLINE uint32_t FL_DAC_GetTriggerSource(DAC_Type* DACx)
{
    return (uint32_t)(READ_BIT(DACx->CFGR, DAC_CFGR_TRGSEL_Msk));
}

/**
  * @brief    Enable DAC DAC Feedback Switch
  * @rmtoll   CFGR    SWIEN    FL_DAC_EnableFeedbackSwitch
  * @param    DACx DAC instance
  * @retval   None
  */
__STATIC_INLINE void FL_DAC_EnableFeedbackSwitch(DAC_Type* DACx)
{
    SET_BIT(DACx->CFGR, DAC_CFGR_SWIEN_Msk);
}

/**
  * @brief    Disable DAC DAC Feedback Switch
  * @rmtoll   CFGR    SWIEN    FL_DAC_DisableFeedbackSwitch
  * @param    DACx DAC instance
  * @retval   None
  */
__STATIC_INLINE void FL_DAC_DisableFeedbackSwitch(DAC_Type* DACx)
{
    CLEAR_BIT(DACx->CFGR, DAC_CFGR_SWIEN_Msk);
}

/**
  * @brief    Get DAC Feedback Switch
  * @rmtoll   CFGR    SWIEN    FL_DAC_IsEnabledFeedbackSwitch
  * @param    DACx DAC instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_DAC_IsEnabledFeedbackSwitch(DAC_Type* DACx)
{
    return (uint32_t)(READ_BIT(DACx->CFGR, DAC_CFGR_SWIEN_Msk) == DAC_CFGR_SWIEN_Msk);
}

/**
  * @brief    Trigger DAC
  * @rmtoll   SWTRGR    SWTRIG    FL_DAC_EnableSoftwareTrigger
  * @param    DACx DAC instance
  * @retval   None
  */
__STATIC_INLINE void FL_DAC_EnableSoftwareTrigger(DAC_Type* DACx)
{
    SET_BIT(DACx->SWTRGR, DAC_SWTRGR_SWTRIG_Msk);
}

/**
  * @brief    Write DAC Data
  * @rmtoll   DHR    DHR    FL_DAC_WriteData
  * @param    DACx DAC instance
  * @param    data 
  * @retval   None
  */
__STATIC_INLINE void FL_DAC_WriteData(DAC_Type* DACx, uint32_t data)
{
    MODIFY_REG(DACx->DHR, DAC_DHR_DHR_Msk, (data << DAC_DHR_DHR_Pos));
}

/**
  * @brief    Read DAC Data
  * @rmtoll   DHR    DHR    FL_DAC_ReadData
  * @param    DACx DAC instance
  * @retval   
  */
__STATIC_INLINE uint32_t FL_DAC_ReadData(DAC_Type* DACx)
{
    return (uint32_t)(READ_BIT(DACx->DHR, DAC_DHR_DHR_Msk) >> DAC_DHR_DHR_Pos);
}

/**
  * @brief    Enable DAC DMA Error interrupt
  * @rmtoll   IER    DMAE_IE    FL_DAC_EnableIT_DMAError
  * @param    DACx DAC instance
  * @retval   None
  */
__STATIC_INLINE void FL_DAC_EnableIT_DMAError(DAC_Type* DACx)
{
    SET_BIT(DACx->IER, DAC_IER_DMAE_IE_Msk);
}

/**
  * @brief    Disable DAC DMA Error interrupt
  * @rmtoll   IER    DMAE_IE    FL_DAC_DisableIT_DMAError
  * @param    DACx DAC instance
  * @retval   None
  */
__STATIC_INLINE void FL_DAC_DisableIT_DMAError(DAC_Type* DACx)
{
    CLEAR_BIT(DACx->IER, DAC_IER_DMAE_IE_Msk);
}

/**
  * @brief    Get DAC DMA Error interrupt Enable Status
  * @rmtoll   IER    DMAE_IE    FL_DAC_IsEnabledIT_DMAError
  * @param    DACx DAC instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_DAC_IsEnabledIT_DMAError(DAC_Type* DACx)
{
    return (uint32_t)(READ_BIT(DACx->IER, DAC_IER_DMAE_IE_Msk) == DAC_IER_DMAE_IE_Msk);
}

/**
  * @brief    Enable DAC Data Output Updated Interrupt
  * @rmtoll   IER    DOU_IE    FL_DAC_EnableIT_DataOutputUpdate
  * @param    DACx DAC instance
  * @retval   None
  */
__STATIC_INLINE void FL_DAC_EnableIT_DataOutputUpdate(DAC_Type* DACx)
{
    SET_BIT(DACx->IER, DAC_IER_DOU_IE_Msk);
}

/**
  * @brief    Disable DAC Data Output Updated Interrupt
  * @rmtoll   IER    DOU_IE    FL_DAC_DisableIT_DataOutputUpdate
  * @param    DACx DAC instance
  * @retval   None
  */
__STATIC_INLINE void FL_DAC_DisableIT_DataOutputUpdate(DAC_Type* DACx)
{
    CLEAR_BIT(DACx->IER, DAC_IER_DOU_IE_Msk);
}

/**
  * @brief    Get DAC Data Output Updated Interrupt Enable Status
  * @rmtoll   IER    DOU_IE    FL_DAC_IsEnabledIT_DataOutputUpdate
  * @param    DACx DAC instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_DAC_IsEnabledIT_DataOutputUpdate(DAC_Type* DACx)
{
    return (uint32_t)(READ_BIT(DACx->IER, DAC_IER_DOU_IE_Msk) == DAC_IER_DOU_IE_Msk);
}

/**
  * @brief    Get DAC DMA Error Flag
  * @rmtoll   ISR    DMAERR    FL_DAC_IsActiveFlag_DMAError
  * @param    DACx DAC instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_DAC_IsActiveFlag_DMAError(DAC_Type* DACx)
{
    return (uint32_t)(READ_BIT(DACx->ISR, DAC_ISR_DMAERR_Msk) == (DAC_ISR_DMAERR_Msk));
}

/**
  * @brief    Clear DAC DMA Error Flag
  * @rmtoll   ISR    DMAERR    FL_DAC_ClearFlag_DMAError
  * @param    DACx DAC instance
  * @retval   None
  */
__STATIC_INLINE void FL_DAC_ClearFlag_DMAError(DAC_Type* DACx)
{
    WRITE_REG(DACx->ISR, DAC_ISR_DMAERR_Msk);
}

/**
  * @brief    Get DAC Data Output Updated Flag
  * @rmtoll   ISR    DOU    FL_DAC_IsActiveFlag_DataOutputUpdate
  * @param    DACx DAC instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_DAC_IsActiveFlag_DataOutputUpdate(DAC_Type* DACx)
{
    return (uint32_t)(READ_BIT(DACx->ISR, DAC_ISR_DOU_Msk) == (DAC_ISR_DOU_Msk));
}

/**
  * @brief    Clear DAC Data Output Updated Flag
  * @rmtoll   ISR    DOU    FL_DAC_ClearFlag_DataOutputUpdate
  * @param    DACx DAC instance
  * @retval   None
  */
__STATIC_INLINE void FL_DAC_ClearFlag_DataOutputUpdate(DAC_Type* DACx)
{
    WRITE_REG(DACx->ISR, DAC_ISR_DOU_Msk);
}

/**
  * @}
  */

/** @defgroup DAC_FL_EF_Init Initialization and de-initialization functions
  * @{
  */
extern FL_ErrorStatus FL_DAC_Init(DAC_Type *DACx, FL_DAC_InitTypeDef  *DAC_InitStruct);
extern FL_ErrorStatus FL_DAC_DeInit(DAC_Type *DACx);


/**
  * @}
  */


/**
  * @}
  */

#ifdef __cplusplus
}
#endif

#endif /* __FM33FG0XXA_FL_DAC_H*/

/*************************Py_Code_Generator Version: 0.1-0.14-0.1 @ 2023-05-17*************************/
/*************************(C) COPYRIGHT Fudan Microelectronics **** END OF FILE*************************/
