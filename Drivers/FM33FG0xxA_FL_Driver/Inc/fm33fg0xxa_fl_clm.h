 /**   
  *******************************************************************************************************
  * @file    fm33fg0xxa_fl_clm.h
  * @author  FMSH Application Team
  * @brief   Head file of CLM FL Module 
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
#ifndef __FM33FG0XXA_FL_CLM_H
#define __FM33FG0XXA_FL_CLM_H

#ifdef __cplusplus
extern "C" {
#endif
/* Includes -------------------------------------------------------------------------------------------*/
#include "fm33fg0xxa_fl_def.h"
/** @addtogroup FM33FG0XXA_FL_Driver
  * @{
  */
/* Exported types -------------------------------------------------------------------------------------*/
/**
  * @brief FL CLM Init Sturcture definition
  */
typedef struct
{
    /* CLM工作模式配置 */
    uint32_t mode;
    /* 超时复位使能配置 */
    FL_FunState timeoutReset;
    /* 参考周期配置 */
    uint32_t referenceclockCycle;
    /* 监控时钟选择 */
    uint32_t monitorclock;
    /* 时钟监控比较高阈值配置 */
    uint32_t CompareHighThreshold;
    /* 时钟监控比较低阈值配置 */
    uint32_t CompareLowThreshold;
}FL_CLM_InitTypeDef;


/**
  * @}
  */
/* Exported constants ---------------------------------------------------------------------------------*/
/** @defgroup CLM_FL_Exported_Constants CLM Exported Constants
  * @{
  */

#define    CLM_CR_TOREN_Pos                                       (31U)
#define    CLM_CR_TOREN_Msk                                       (0x1U << CLM_CR_TOREN_Pos)
#define    CLM_CR_TOREN                                           CLM_CR_TOREN_Msk

#define    CLM_CR_MODE_Pos                                        (6U)
#define    CLM_CR_MODE_Msk                                        (0x3U << CLM_CR_MODE_Pos)
#define    CLM_CR_MODE                                            CLM_CR_MODE_Msk

#define    CLM_CR_UDFIE_Pos                                       (3U)
#define    CLM_CR_UDFIE_Msk                                       (0x1U << CLM_CR_UDFIE_Pos)
#define    CLM_CR_UDFIE                                           CLM_CR_UDFIE_Msk

#define    CLM_CR_OVFIE_Pos                                       (2U)
#define    CLM_CR_OVFIE_Msk                                       (0x1U << CLM_CR_OVFIE_Pos)
#define    CLM_CR_OVFIE                                           CLM_CR_OVFIE_Msk

#define    CLM_CR_MONIE_Pos                                       (1U)
#define    CLM_CR_MONIE_Msk                                       (0x1U << CLM_CR_MONIE_Pos)
#define    CLM_CR_MONIE                                           CLM_CR_MONIE_Msk

#define    CLM_CR_EN_Pos                                          (0U)
#define    CLM_CR_EN_Msk                                          (0x1U << CLM_CR_EN_Pos)
#define    CLM_CR_EN                                              CLM_CR_EN_Msk

#define    CLM_CFGR_REF_CNT_Pos                                   (8U)
#define    CLM_CFGR_REF_CNT_Msk                                   (0xffU << CLM_CFGR_REF_CNT_Pos)
#define    CLM_CFGR_REF_CNT                                       CLM_CFGR_REF_CNT_Msk

#define    CLM_CFGR_MONSEL_Pos                                    (0U)
#define    CLM_CFGR_MONSEL_Msk                                    (0x3U << CLM_CFGR_MONSEL_Pos)
#define    CLM_CFGR_MONSEL                                        CLM_CFGR_MONSEL_Msk

#define    CLM_CNTR_CNT_Pos                                       (0U)
#define    CLM_CNTR_CNT_Msk                                       (0xffffffU << CLM_CNTR_CNT_Pos)
#define    CLM_CNTR_CNT                                           CLM_CNTR_CNT_Msk

#define    CLM_ISR_UDF_Pos                                        (2U)
#define    CLM_ISR_UDF_Msk                                        (0x1U << CLM_ISR_UDF_Pos)
#define    CLM_ISR_UDF                                            CLM_ISR_UDF_Msk

#define    CLM_ISR_OVF_Pos                                        (1U)
#define    CLM_ISR_OVF_Msk                                        (0x1U << CLM_ISR_OVF_Pos)
#define    CLM_ISR_OVF                                            CLM_ISR_OVF_Msk

#define    CLM_CMPH_CMPH_Pos                                      (0U)
#define    CLM_CMPH_CMPH_Msk                                      (0xffffffU << CLM_CMPH_CMPH_Pos)
#define    CLM_CMPH_CMPH                                          CLM_CMPH_CMPH_Msk

#define    CLM_CMPL_CMPL_Pos                                      (0U)
#define    CLM_CMPL_CMPL_Msk                                      (0xffffffU << CLM_CMPL_CMPL_Pos)
#define    CLM_CMPL_CMPL                                          CLM_CMPL_CMPL_Msk


#define    FL_CLM_WORKMODE_INTERRUPT                              (0x0U << CLM_CR_MODE_Pos)
#define    FL_CLM_WORKMODE_RESET                                  (0x2U << CLM_CR_MODE_Pos)


#define    FL_CLM_MONCLK_RCHF                                     (0x0U << CLM_CFGR_MONSEL_Pos)
#define    FL_CLM_MONCLK_PLL                                      (0x1U << CLM_CFGR_MONSEL_Pos)
#define    FL_CLM_MONCLK_XTHF                                     (0x2U << CLM_CFGR_MONSEL_Pos)


/**
  * @}
  */
/* Exported functions ---------------------------------------------------------------------------------*/
/** @defgroup CLM_FL_Exported_Functions CLM Exported Functions
  * @{
  */

/**
  * @brief    Enable CLM Timeout Reset
  * @rmtoll   CR    TOREN    FL_CLM_EnableTimeOutReset
  * @param    CLMx CLM instance
  * @retval   None
  */
__STATIC_INLINE void FL_CLM_EnableTimeOutReset(CLM_Type* CLMx)
{
    SET_BIT(CLMx->CR, CLM_CR_TOREN_Msk);
}

/**
  * @brief    Disable CLM Timeout Reset
  * @rmtoll   CR    TOREN    FL_CLM_DisableTimeOutReset
  * @param    CLMx CLM instance
  * @retval   None
  */
__STATIC_INLINE void FL_CLM_DisableTimeOutReset(CLM_Type* CLMx)
{
    CLEAR_BIT(CLMx->CR, CLM_CR_TOREN_Msk);
}

/**
  * @brief    Get CLM Timeout Reset Enable Status
  * @rmtoll   CR    TOREN    FL_CLM_IsEnabledTimeOutReset
  * @param    CLMx CLM instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_CLM_IsEnabledTimeOutReset(CLM_Type* CLMx)
{
    return (uint32_t)(READ_BIT(CLMx->CR, CLM_CR_TOREN_Msk) == CLM_CR_TOREN_Msk);
}

/**
  * @brief    Set CLM Working Mode
  * @rmtoll   CR    MODE    FL_CLM_SetWorkingMode
  * @param    CLMx CLM instance
  * @param    mode This parameter can be one of the following values:
  *           @arg @ref FL_CLM_WORKMODE_Interrupt
  *           @arg @ref FL_CLM_WORKMODE_Reset
  * @retval   None
  */
__STATIC_INLINE void FL_CLM_SetWorkingMode(CLM_Type* CLMx, uint32_t mode)
{
    MODIFY_REG(CLMx->CR, CLM_CR_MODE_Msk, mode);
}

/**
  * @brief    Get CLM Working Mode
  * @rmtoll   CR    MODE    FL_CLM_GetWorkingMode
  * @param    CLMx CLM instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_CLM_WORKMODE_Interrupt
  *           @arg @ref FL_CLM_WORKMODE_Reset
  */
__STATIC_INLINE uint32_t FL_CLM_GetWorkingMode(CLM_Type* CLMx)
{
    return (uint32_t)(READ_BIT(CLMx->CR, CLM_CR_MODE_Msk));
}

/**
  * @brief    Enable CLM Counter Underflow Interrupt
  * @rmtoll   CR    UDFIE    FL_CLM_EnableIT_CounterUnderflowInterrupt
  * @param    CLMx CLM instance
  * @retval   None
  */
__STATIC_INLINE void FL_CLM_EnableIT_CounterUnderflowInterrupt(CLM_Type* CLMx)
{
    SET_BIT(CLMx->CR, CLM_CR_UDFIE_Msk);
}

/**
  * @brief    Disable CLM Counter Underflow Interrupt
  * @rmtoll   CR    UDFIE    FL_CLM_DisableIT_CounterUnderflowInterrupt
  * @param    CLMx CLM instance
  * @retval   None
  */
__STATIC_INLINE void FL_CLM_DisableIT_CounterUnderflowInterrupt(CLM_Type* CLMx)
{
    CLEAR_BIT(CLMx->CR, CLM_CR_UDFIE_Msk);
}

/**
  * @brief    Get CLM Counter Underflow Interrupt Enable Status
  * @rmtoll   CR    UDFIE    FL_CLM_IsEnabledIT_CounterUnderflowInterrupt
  * @param    CLMx CLM instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_CLM_IsEnabledIT_CounterUnderflowInterrupt(CLM_Type* CLMx)
{
    return (uint32_t)(READ_BIT(CLMx->CR, CLM_CR_UDFIE_Msk) == CLM_CR_UDFIE_Msk);
}

/**
  * @brief    Enable CLM Counter Overflow Interrupt
  * @rmtoll   CR    OVFIE    FL_CLM_EnableIT_CounterOverflowInterrupt
  * @param    CLMx CLM instance
  * @retval   None
  */
__STATIC_INLINE void FL_CLM_EnableIT_CounterOverflowInterrupt(CLM_Type* CLMx)
{
    SET_BIT(CLMx->CR, CLM_CR_OVFIE_Msk);
}

/**
  * @brief    Disable CLM Counter Overflow Interrupt
  * @rmtoll   CR    OVFIE    FL_CLM_DisableIT_CounterOverflowInterrupt
  * @param    CLMx CLM instance
  * @retval   None
  */
__STATIC_INLINE void FL_CLM_DisableIT_CounterOverflowInterrupt(CLM_Type* CLMx)
{
    CLEAR_BIT(CLMx->CR, CLM_CR_OVFIE_Msk);
}

/**
  * @brief    Get CLM Counter Overflow Interrupt Enable Status
  * @rmtoll   CR    OVFIE    FL_CLM_IsEnabledIT_CounterOverflowInterrupt
  * @param    CLMx CLM instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_CLM_IsEnabledIT_CounterOverflowInterrupt(CLM_Type* CLMx)
{
    return (uint32_t)(READ_BIT(CLMx->CR, CLM_CR_OVFIE_Msk) == CLM_CR_OVFIE_Msk);
}

/**
  * @brief    Enable CLM Cycle Interrupt
  * @rmtoll   CR    MONIE    FL_CLM_EnableIT_CycleInterrupt
  * @param    CLMx CLM instance
  * @retval   None
  */
__STATIC_INLINE void FL_CLM_EnableIT_CycleInterrupt(CLM_Type* CLMx)
{
    SET_BIT(CLMx->CR, CLM_CR_MONIE_Msk);
}

/**
  * @brief    Disable CLM Cycle Interrupt
  * @rmtoll   CR    MONIE    FL_CLM_DisableIT_CycleInterrupt
  * @param    CLMx CLM instance
  * @retval   None
  */
__STATIC_INLINE void FL_CLM_DisableIT_CycleInterrupt(CLM_Type* CLMx)
{
    CLEAR_BIT(CLMx->CR, CLM_CR_MONIE_Msk);
}

/**
  * @brief    Get CLM Cycle Interrupt Enable Status
  * @rmtoll   CR    MONIE    FL_CLM_IsEnabledIT_CycleInterrupt
  * @param    CLMx CLM instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_CLM_IsEnabledIT_CycleInterrupt(CLM_Type* CLMx)
{
    return (uint32_t)(READ_BIT(CLMx->CR, CLM_CR_MONIE_Msk) == CLM_CR_MONIE_Msk);
}

/**
  * @brief    Enable CLM
  * @rmtoll   CR    EN    FL_CLM_Enable
  * @param    CLMx CLM instance
  * @retval   None
  */
__STATIC_INLINE void FL_CLM_Enable(CLM_Type* CLMx)
{
    SET_BIT(CLMx->CR, CLM_CR_EN_Msk);
}

/**
  * @brief    Disable CLM
  * @rmtoll   CR    EN    FL_CLM_Disable
  * @param    CLMx CLM instance
  * @retval   None
  */
__STATIC_INLINE void FL_CLM_Disable(CLM_Type* CLMx)
{
    CLEAR_BIT(CLMx->CR, CLM_CR_EN_Msk);
}

/**
  * @brief    Get CLM Enable Status
  * @rmtoll   CR    EN    FL_CLM_IsEnabled
  * @param    CLMx CLM instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_CLM_IsEnabled(CLM_Type* CLMx)
{
    return (uint32_t)(READ_BIT(CLMx->CR, CLM_CR_EN_Msk) == CLM_CR_EN_Msk);
}

/**
  * @brief    Set CLM Reference Clock Cycle
  * @rmtoll   CFGR    REF_CNT    FL_CLM_WriteReferenceClockCycle
  * @param    CLMx CLM instance
  * @param    cycle 
  * @retval   None
  */
__STATIC_INLINE void FL_CLM_WriteReferenceClockCycle(CLM_Type* CLMx, uint32_t cycle)
{
    MODIFY_REG(CLMx->CFGR, CLM_CFGR_REF_CNT_Msk, (cycle << CLM_CFGR_REF_CNT_Pos));
}

/**
  * @brief    Get CLM Reference Clock Cycle
  * @rmtoll   CFGR    REF_CNT    FL_CLM_ReadReferenceClockCycle
  * @param    CLMx CLM instance
  * @retval   
  */
__STATIC_INLINE uint32_t FL_CLM_ReadReferenceClockCycle(CLM_Type* CLMx)
{
    return (uint32_t)(READ_BIT(CLMx->CFGR, CLM_CFGR_REF_CNT_Msk) >> CLM_CFGR_REF_CNT_Pos);
}

/**
  * @brief    Set CLM Monitor Clock
  * @rmtoll   CFGR    MONSEL    FL_CLM_SetMonitorClock
  * @param    CLMx CLM instance
  * @param    clock This parameter can be one of the following values:
  *           @arg @ref FL_CLM_MONCLK_RCHF
  *           @arg @ref FL_CLM_MONCLK_PLL
  *           @arg @ref FL_CLM_MONCLK_XTHF
  * @retval   None
  */
__STATIC_INLINE void FL_CLM_SetMonitorClock(CLM_Type* CLMx, uint32_t clock)
{
    MODIFY_REG(CLMx->CFGR, CLM_CFGR_MONSEL_Msk, clock);
}

/**
  * @brief    Get CLM Monitor Clock
  * @rmtoll   CFGR    MONSEL    FL_CLM_GetMonitorClock
  * @param    CLMx CLM instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_CLM_MONCLK_RCHF
  *           @arg @ref FL_CLM_MONCLK_PLL
  *           @arg @ref FL_CLM_MONCLK_XTHF
  */
__STATIC_INLINE uint32_t FL_CLM_GetMonitorClock(CLM_Type* CLMx)
{
    return (uint32_t)(READ_BIT(CLMx->CFGR, CLM_CFGR_MONSEL_Msk));
}

/**
  * @brief    Get CLM Clock Calibration Counter
  * @rmtoll   CNTR    CNT    FL_CLM_ReadClockCalibrationCounter
  * @param    CLMx CLM instance
  * @retval   
  */
__STATIC_INLINE uint32_t FL_CLM_ReadClockCalibrationCounter(CLM_Type* CLMx)
{
    return (uint32_t)(READ_BIT(CLMx->CNTR, CLM_CNTR_CNT_Msk) >> CLM_CNTR_CNT_Pos);
}

/**
  * @brief    Get CLM Underflow Flag
  * @rmtoll   ISR    UDF    FL_CLM_IsActiveFlag_Underflow
  * @param    CLMx CLM instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_CLM_IsActiveFlag_Underflow(CLM_Type* CLMx)
{
    return (uint32_t)(READ_BIT(CLMx->ISR, CLM_ISR_UDF_Msk) == (CLM_ISR_UDF_Msk));
}

/**
  * @brief    Clear CLM Underflow Flag 
  * @rmtoll   ISR    UDF    FL_CLM_ClearFlag_Underflow
  * @param    CLMx CLM instance
  * @retval   None
  */
__STATIC_INLINE void FL_CLM_ClearFlag_Underflow(CLM_Type* CLMx)
{
    WRITE_REG(CLMx->ISR, CLM_ISR_UDF_Msk);
}

/**
  * @brief    Get CLM Overflow Flag
  * @rmtoll   ISR    OVF    FL_CLM_IsActiveFlag_Overflow
  * @param    CLMx CLM instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_CLM_IsActiveFlag_Overflow(CLM_Type* CLMx)
{
    return (uint32_t)(READ_BIT(CLMx->ISR, CLM_ISR_OVF_Msk) == (CLM_ISR_OVF_Msk));
}

/**
  * @brief    Clear CLM Overflow Flag
  * @rmtoll   ISR    OVF    FL_CLM_ClearFlag_Overflow
  * @param    CLMx CLM instance
  * @retval   None
  */
__STATIC_INLINE void FL_CLM_ClearFlag_Overflow(CLM_Type* CLMx)
{
    WRITE_REG(CLMx->ISR, CLM_ISR_OVF_Msk);
}

/**
  * @brief    Get CLM Clock Monitor Interrupt Flag
  * @rmtoll   ISR    OVF    FL_CLM_IsActiveFlag_ClockMonitor
  * @param    CLMx CLM instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_CLM_IsActiveFlag_ClockMonitor(CLM_Type* CLMx)
{
    return (uint32_t)(READ_BIT(CLMx->ISR, CLM_ISR_OVF_Msk) == (CLM_ISR_OVF_Msk));
}

/**
  * @brief    Clear CLM Clock Monitor Interrupt Flag
  * @rmtoll   ISR    OVF    FL_CLM_ClearFlag_ClockMonitor
  * @param    CLMx CLM instance
  * @retval   None
  */
__STATIC_INLINE void FL_CLM_ClearFlag_ClockMonitor(CLM_Type* CLMx)
{
    WRITE_REG(CLMx->ISR, CLM_ISR_OVF_Msk);
}

/**
  * @brief    Set CLM Compare Value High Threshold
  * @rmtoll   CMPH    CMPH    FL_CLM_WriteCompareHighThreshold
  * @param    CLMx CLM instance
  * @param    data 
  * @retval   None
  */
__STATIC_INLINE void FL_CLM_WriteCompareHighThreshold(CLM_Type* CLMx, uint32_t data)
{
    MODIFY_REG(CLMx->CMPH, CLM_CMPH_CMPH_Msk, (data << CLM_CMPH_CMPH_Pos));
}

/**
  * @brief    Get CLM Compare Value High Threshold
  * @rmtoll   CMPH    CMPH    FL_CLM_ReadCompareHighThreshold
  * @param    CLMx CLM instance
  * @retval   
  */
__STATIC_INLINE uint32_t FL_CLM_ReadCompareHighThreshold(CLM_Type* CLMx)
{
    return (uint32_t)(READ_BIT(CLMx->CMPH, CLM_CMPH_CMPH_Msk) >>CLM_CMPH_CMPH_Pos);
}

/**
  * @brief    Set CLM Compare Value Low Threshold
  * @rmtoll   CMPL    CMPL    FL_CLM_WriteCompareLowThreshold
  * @param    CLMx CLM instance
  * @param    data 
  * @retval   None
  */
__STATIC_INLINE void FL_CLM_WriteCompareLowThreshold(CLM_Type* CLMx, uint32_t data)
{
    MODIFY_REG(CLMx->CMPL, CLM_CMPL_CMPL_Msk, (data << CLM_CMPL_CMPL_Pos));
}

/**
  * @brief    Get CLM Compare Value Low Threshold
  * @rmtoll   CMPL    CMPL    FL_CLM_ReadCompareLowThreshold
  * @param    CLMx CLM instance
  * @retval   
  */
__STATIC_INLINE uint32_t FL_CLM_ReadCompareLowThreshold(CLM_Type* CLMx)
{
    return (uint32_t)(READ_BIT(CLMx->CMPL, CLM_CMPL_CMPL_Msk) >> CLM_CMPL_CMPL_Pos);
}

/**
  * @}
  */

/** @defgroup CLM_FL_EF_Init Initialization and de-initialization functions
  * @{
  */
extern FL_ErrorStatus FL_CLM_Init(CLM_Type *CLMx, FL_CLM_InitTypeDef  *CLM_InitStruct);
extern FL_ErrorStatus FL_CLM_DeInit(CLM_Type *CLMx);

/**
  * @}
  */


/**
  * @}
  */

#ifdef __cplusplus
}
#endif

#endif /* __FM33FG0XXA_FL_CLM_H*/

/*************************Py_Code_Generator Version: 0.1-0.14-0.1 @ 2023-05-16*************************/
/*************************(C) COPYRIGHT Fudan Microelectronics **** END OF FILE*************************/
