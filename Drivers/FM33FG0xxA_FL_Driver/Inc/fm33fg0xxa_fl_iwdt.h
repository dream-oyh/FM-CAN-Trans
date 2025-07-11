 /**    
  *******************************************************************************************************
  * @file    fm33fg0xxa_fl_iwdt.h
  * @author  FMSH Application Team
  * @brief   Head file of IWDT FL Module
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
#ifndef __FM33FG0XXA_FL_IWDT_H
#define __FM33FG0XXA_FL_IWDT_H

#ifdef __cplusplus
extern "C" {
#endif
/* Includes -------------------------------------------------------------------------------------------*/
#include "fm33fg0xxa_fl_def.h"
/** @addtogroup FM33FG0XXA_FL_Driver
  * @{
  */

/** @defgroup IWDT IWDT
  * @brief IWDT FL driver
  * @{
  */

/* Exported types -------------------------------------------------------------------------------------*/
/** @defgroup IWDT_FL_ES_INIT IWDT Exported Init structures
  * @{
  */

/**
  * @brief FL IWDT Init Sturcture definition
  */
typedef  struct
{
    /* 看门狗溢出时间 */
    uint32_t overflowPeriod;
    /* 清狗窗口 */
    uint32_t iwdtWindows;

} FL_IWDT_InitTypeDef;
/**
  * @}
  */
/* Exported constants ---------------------------------------------------------------------------------*/
/** @defgroup IWDT_FL_Exported_Constants IWDT Exported Constants
  * @{
  */

#define    IWDT_RELOAD_KEY                                        (0x12345A5AUL)

#define    IWDT_CR_FREEZE_Pos                                     (11U)
#define    IWDT_CR_FREEZE_Msk                                     (0x1U << IWDT_CR_FREEZE_Pos)
#define    IWDT_CR_FREEZE                                         IWDT_CR_FREEZE_Msk

#define    IWDT_CR_CFG_Pos                                        (0U)
#define    IWDT_CR_CFG_Msk                                        (0x7U << IWDT_CR_CFG_Pos)
#define    IWDT_CR_CFG                                            IWDT_CR_CFG_Msk

#define    IWDT_IER_IE_Pos                                        (0U)
#define    IWDT_IER_IE_Msk                                        (0x1U << IWDT_IER_IE_Pos)
#define    IWDT_IER_IE                                            IWDT_IER_IE_Msk

#define    IWDT_ISR_WINF_Pos                                      (0U)
#define    IWDT_ISR_WINF_Msk                                      (0x1U << IWDT_ISR_WINF_Pos)
#define    IWDT_ISR_WINF                                          IWDT_ISR_WINF_Msk






#define    FL_IWDT_PERIOD_125MS                                   (0x0U << IWDT_CR_CFG_Pos)
#define    FL_IWDT_PERIOD_250MS                                   (0x1U << IWDT_CR_CFG_Pos)
#define    FL_IWDT_PERIOD_500MS                                   (0x2U << IWDT_CR_CFG_Pos)
#define    FL_IWDT_PERIOD_1000MS                                  (0x3U << IWDT_CR_CFG_Pos)
#define    FL_IWDT_PERIOD_2000MS                                  (0x4U << IWDT_CR_CFG_Pos)
#define    FL_IWDT_PERIOD_4000MS                                  (0x5U << IWDT_CR_CFG_Pos)
#define    FL_IWDT_PERIOD_8000MS                                  (0x6U << IWDT_CR_CFG_Pos)
#define    FL_IWDT_PERIOD_16000MS                                 (0x7U << IWDT_CR_CFG_Pos)


/**
  * @}
  */
/* Exported functions ---------------------------------------------------------------------------------*/
/** @defgroup IWDT_FL_Exported_Functions IWDT Exported Functions
  * @{
  */

/**
  * @brief    Set IWDT service register
  * @rmtoll   SERV        FL_IWDT_ReloadCounter
  * @param    IWDTx IWDT instance
  * @retval   None
  */
__STATIC_INLINE void FL_IWDT_ReloadCounter(IWDT_Type *IWDTx)
{
    volatile uint32_t val = 0;
    IWDTx->SERV = IWDT_RELOAD_KEY;
    val = READ_REG(IWDTx->SERV);
}

/**
  * @brief    Set freeze in sleep enable
  * @rmtoll   CR    FREEZE    FL_IWDT_EnableFreezeWhileSleep
  * @param    IWDTx IWDT instance
  * @retval   None
  */
__STATIC_INLINE void FL_IWDT_EnableFreezeWhileSleep(IWDT_Type *IWDTx)
{
    volatile uint32_t val = 0;
    SET_BIT(IWDTx->CR, IWDT_CR_FREEZE_Msk);
    val = READ_REG(IWDTx->SERV);
}

/**
  * @brief    Set freeze in sleep disable
  * @rmtoll   CR    FREEZE    FL_IWDT_DisableFreezeWhileSleep
  * @param    IWDTx IWDT instance
  * @retval   None
  */
__STATIC_INLINE void FL_IWDT_DisableFreezeWhileSleep(IWDT_Type *IWDTx)
{
    volatile uint32_t val = 0;
    CLEAR_BIT(IWDTx->CR, IWDT_CR_FREEZE_Msk);
    val = READ_REG(IWDTx->SERV);
}

/**
  * @brief    Get freeze in sleep enable status
  * @rmtoll   CR    FREEZE    FL_IWDT_IsEnabledFreezeWhileSleep
  * @param    IWDTx IWDT instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_IWDT_IsEnabledFreezeWhileSleep(IWDT_Type *IWDTx)
{
    volatile uint32_t val = 0;
    uint32_t temp;
    temp = (uint32_t)(READ_BIT(IWDTx->CR, IWDT_CR_FREEZE_Msk) == IWDT_CR_FREEZE_Msk);
    val = READ_REG(IWDTx->SERV);
    return temp;
}

/**
  * @brief    Set IWDT overflow period
  * @rmtoll   CR    CFG    FL_IWDT_SetPeriod
  * @param    IWDTx IWDT instance
  * @param    period This parameter can be one of the following values:
  *           @arg @ref FL_IWDT_PERIOD_125MS
  *           @arg @ref FL_IWDT_PERIOD_250MS
  *           @arg @ref FL_IWDT_PERIOD_500MS
  *           @arg @ref FL_IWDT_PERIOD_1000MS
  *           @arg @ref FL_IWDT_PERIOD_2000MS
  *           @arg @ref FL_IWDT_PERIOD_4000MS
  *           @arg @ref FL_IWDT_PERIOD_8000MS
  *           @arg @ref FL_IWDT_PERIOD_16000MS
  * @retval   None
  */
__STATIC_INLINE void FL_IWDT_SetPeriod(IWDT_Type *IWDTx, uint32_t period)
{
    volatile uint32_t val = 0;
    MODIFY_REG(IWDTx->CR, IWDT_CR_CFG_Msk, period);
    val = READ_REG(IWDTx->SERV);
}

/**
  * @brief    Get IWDT overflow period
  * @rmtoll   CR    CFG    FL_IWDT_GetPeriod
  * @param    IWDTx IWDT instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_IWDT_PERIOD_125MS
  *           @arg @ref FL_IWDT_PERIOD_250MS
  *           @arg @ref FL_IWDT_PERIOD_500MS
  *           @arg @ref FL_IWDT_PERIOD_1000MS
  *           @arg @ref FL_IWDT_PERIOD_2000MS
  *           @arg @ref FL_IWDT_PERIOD_4000MS
  *           @arg @ref FL_IWDT_PERIOD_8000MS
  *           @arg @ref FL_IWDT_PERIOD_16000MS
  */
__STATIC_INLINE uint32_t FL_IWDT_GetPeriod(IWDT_Type *IWDTx)
{
    volatile uint32_t val = 0;
    uint32_t temp;
    temp = (uint32_t)(READ_BIT(IWDTx->CR, IWDT_CR_CFG_Msk));
    val = READ_REG(IWDTx->SERV);
    return temp;
}

/**
  * @brief    Get IWDT current counter value
  * @rmtoll   CNT        FL_IWDT_ReadCounter
  * @param    IWDTx IWDT instance
  * @retval
  */
__STATIC_INLINE uint32_t FL_IWDT_ReadCounter(IWDT_Type *IWDTx)
{
    volatile uint32_t val = 0;
    uint32_t temp;
    temp = (uint32_t)(READ_BIT(IWDTx->CNT, (0xfffU << 0U)) >> 0U);
    val = READ_REG(IWDTx->SERV);
    return temp;
}

/**
  * @brief    Set IWDT window register
  * @rmtoll   WIN        FL_IWDT_WriteWindow
  * @param    IWDTx IWDT instance
  * @param    value
  * @retval   None
  */
__STATIC_INLINE void FL_IWDT_WriteWindow(IWDT_Type *IWDTx, uint32_t value)
{
    volatile uint32_t val = 0;
    IWDTx->WIN = (value & 0xFFF);
    val = READ_REG(IWDTx->SERV);
}

/**
  * @brief    Get IWDT window register
  * @rmtoll   WIN        FL_IWDT_ReadWindow
  * @param    IWDTx IWDT instance
  * @retval
  */
__STATIC_INLINE uint32_t FL_IWDT_ReadWindow(IWDT_Type *IWDTx)
{
    volatile uint32_t val = 0;
    uint32_t temp;
    temp = (uint32_t)(READ_BIT(IWDTx->WIN, (0xfffU << 0U)) >> 0U);
    val = READ_REG(IWDTx->SERV);
    return temp;
}

/**
  * @brief    IWDT interrupt enable
  * @rmtoll   IER    IE    FL_IWDT_EnableIT_EnterWindow
  * @param    IWDTx IWDT instance
  * @retval   None
  */
__STATIC_INLINE void FL_IWDT_EnableIT_EnterWindow(IWDT_Type *IWDTx)
{
    volatile uint32_t val = 0;
    IWDTx->IER = FL_ENABLE;
    val = READ_REG(IWDTx->SERV);
}

/**
  * @brief    IWDT interrupt disable
  * @rmtoll   IER    IE    FL_IWDT_DisableIT_EnterWindow
  * @param    IWDTx IWDT instance
  * @retval   None
  */
__STATIC_INLINE void FL_IWDT_DisableIT_EnterWindow(IWDT_Type *IWDTx)
{
    volatile uint32_t val = 0;
    IWDTx->IER = FL_DISABLE;
    val = READ_REG(IWDTx->SERV);
}

/**
  * @brief    Get IWDT interrupt enable status
  * @rmtoll   IER    IE    FL_IWDT_IsEnabledIT_EnterWindow
  * @param    IWDTx IWDT instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_IWDT_IsEnabledIT_EnterWindow(IWDT_Type *IWDTx)
{
    volatile uint32_t val = 0;
    uint32_t temp;
    temp = (uint32_t)(READ_BIT(IWDTx->IER, IWDT_IER_IE_Msk) == IWDT_IER_IE_Msk);
    val = READ_REG(IWDTx->SERV);
    return temp;
}

/**
  * @brief    Get IWDT window interrupt flag
  * @rmtoll   ISR    WINF    FL_IWDT_IsActiveFlag_EnterWindow
  * @param    IWDTx IWDT instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_IWDT_IsActiveFlag_EnterWindow(IWDT_Type *IWDTx)
{
    volatile uint32_t val = 0;
    uint32_t temp;
    temp = (uint32_t)(READ_BIT(IWDTx->ISR, IWDT_ISR_WINF_Msk));
    val = READ_REG(IWDTx->SERV);
    return temp;
}

/**
  * @brief    Clear IWDT window interrupt flag
  * @rmtoll   ISR    WINF    FL_IWDT_ClearFlag_EnterWindow
  * @param    IWDTx IWDT instance
  * @retval   None
  */
__STATIC_INLINE void FL_IWDT_ClearFlag_EnterWindow(IWDT_Type *IWDTx)
{
    volatile uint32_t val = 0;
    IWDTx->ISR = IWDT_ISR_WINF_Msk;
    val = READ_REG(IWDTx->SERV);
}

/**
  * @}
  */

/** @defgroup IWDT_FL_EF_Init Initialization and de-initialization functions
  * @{
  */
FL_ErrorStatus FL_IWDT_DeInit(IWDT_Type *IWDTx);
void FL_IWDT_StructInit(FL_IWDT_InitTypeDef *IWDT_InitStruct);
FL_ErrorStatus FL_IWDT_Init(IWDT_Type *IWDTx, FL_IWDT_InitTypeDef *IWDT_InitStruct);

/**
  * @}
  */


/**
  * @}
  */

#ifdef __cplusplus
}
#endif

#endif /* __FM33FG0XXA_FL_IWDT_H*/

/*************************Py_Code_Generator Version: 0.1-0.14-0.1 @ 2023-03-27*************************/
/*************************(C) COPYRIGHT Fudan Microelectronics **** END OF FILE*************************/
