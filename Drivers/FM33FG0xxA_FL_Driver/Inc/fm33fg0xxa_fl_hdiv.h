 /**    
  *******************************************************************************************************
  * @file    fm33fg0xxa_fl_hdiv.h
  * @author  FMSH Application Team
  * @brief   Head file of HDIV FL Module
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
#ifndef __FM33FG0XXA_FL_HDIV_H
#define __FM33FG0XXA_FL_HDIV_H

#ifdef __cplusplus
extern "C" {
#endif
/* Includes -------------------------------------------------------------------------------------------*/
#include "fm33fg0xxa_fl_def.h"
/** @addtogroup FM33FG0XXA_FL_Driver
  * @{
  */
/* Exported types -------------------------------------------------------------------------------------*/
/** @defgroup HDIV_FL_ES_INIT HDIV Exported Init structures
  * @{
  */

/**
  * @brief FL HDIV Init Sturcture definition
  */

/**
  * @}
  */
/* Exported constants ---------------------------------------------------------------------------------*/
/** @defgroup HDIV_FL_Exported_Constants HDIV Exported Constants
  * @{
  */

#define    HDIV_SR_DIVBYZERO_Pos                                  (1U)
#define    HDIV_SR_DIVBYZERO_Msk                                  (0x1U << HDIV_SR_DIVBYZERO_Pos)
#define    HDIV_SR_DIVBYZERO                                      HDIV_SR_DIVBYZERO_Msk

#define    HDIV_SR_BUSY_Pos                                       (0U)
#define    HDIV_SR_BUSY_Msk                                       (0x1U << HDIV_SR_BUSY_Pos)
#define    HDIV_SR_BUSY                                           HDIV_SR_BUSY_Msk



#define    FL_HDIV_SR_BUSY_TIMEOUT                                0xFFFU


/**
  * @}
  */
/* Exported functions ---------------------------------------------------------------------------------*/
/** @defgroup HDIV_FL_Exported_Functions HDIV Exported Functions
  * @{
  */

/**
  * @brief    Write 32bit Signed Dividend Register
  * @rmtoll   END        FL_HDIV_WriteOperand
  * @param    HDIVx HDIV instance
  * @param    number 
  * @retval   None
  */
__STATIC_INLINE void FL_HDIV_WriteOperand(HDIV_Type* HDIVx, uint32_t number)
{
    WRITE_REG(HDIVx->END, (number << 0U));
}

/**
  * @brief    Read 32bit Signed Dividend Register
  * @rmtoll   END        FL_HDIV_ReadOperand
  * @param    HDIVx HDIV instance
  * @retval   
  */
__STATIC_INLINE uint32_t FL_HDIV_ReadOperand(HDIV_Type* HDIVx)
{
    return (uint32_t)(READ_REG(HDIVx->END));
}

/**
  * @brief    Write 16bit Signed Divisor
  * @rmtoll   SOR        FL_HDIV_WriteDivisor
  * @param    HDIVx HDIV instance
  * @param    number 
  * @retval   None
  */
__STATIC_INLINE void FL_HDIV_WriteDivisor(HDIV_Type* HDIVx, uint32_t number)
{
    MODIFY_REG(HDIVx->SOR, (0xffffU << 0U), (number << 0U));
}

/**
  * @brief    Read 16bit Signed Divisor
  * @rmtoll   SOR        FL_HDIV_ReadDivisor
  * @param    HDIVx HDIV instance
  * @retval   
  */
__STATIC_INLINE uint32_t FL_HDIV_ReadDivisor(HDIV_Type* HDIVx)
{
    return (uint32_t)(READ_BIT(HDIVx->SOR, (0xffffU << 0U)) >> 0U);
}

/**
  * @brief    Read 32bit Signed QUTO
  * @rmtoll   QUOT        FL_HDIV_ReadQuotient
  * @param    HDIVx HDIV instance
  * @retval   
  */
__STATIC_INLINE uint32_t FL_HDIV_ReadQuotient(HDIV_Type* HDIVx)
{
    return (uint32_t)(READ_REG(HDIVx->QUOT));
}

/**
  * @brief    Read 16bit Signed Reminder
  * @rmtoll   REMD        FL_HDIV_ReadResidue
  * @param    HDIVx HDIV instance
  * @retval   
  */
__STATIC_INLINE uint32_t FL_HDIV_ReadResidue(HDIV_Type* HDIVx)
{
    return (uint32_t)(READ_BIT(HDIVx->REMD, (0xffffU << 0U)) >> 0U);
}

/**
  * @brief    Get divided by 0 flag
  * @rmtoll   SR    DIVBYZERO    FL_HDIV_IsActiveFlag_DividedZero
  * @param    HDIVx HDIV instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_HDIV_IsActiveFlag_DividedZero(HDIV_Type* HDIVx)
{
    return (uint32_t)(READ_BIT(HDIVx->SR, HDIV_SR_DIVBYZERO_Msk) == (HDIV_SR_DIVBYZERO_Msk));
}

/**
  * @brief    Get Busy flag
  * @rmtoll   SR    BUSY    FL_HDIV_IsActiveFlag_Busy
  * @param    HDIVx HDIV instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_HDIV_IsActiveFlag_Busy(HDIV_Type* HDIVx)
{
    return (uint32_t)(READ_BIT(HDIVx->SR, HDIV_SR_BUSY_Msk) == (HDIV_SR_BUSY_Msk));
}

/**
  * @}
  */

/** @defgroup HDIV_FL_EF_Init Initialization and de-initialization functions
  * @{
  */
FL_ErrorStatus FL_HDIV_DeInit(HDIV_Type* HDIVx);
FL_ErrorStatus FL_HDIV_Init(HDIV_Type* HDIVx);
FL_ErrorStatus FL_HDIV_Calculation(HDIV_Type* HDIVx, int32_t DivisorEnd, int16_t Divisor, int32_t *Quotient, int16_t *Residue);

/**
  * @}
  */


/**
  * @}
  */

#ifdef __cplusplus
}
#endif

#endif /* __FM33FG0XXA_FL_HDIV_H*/

/*************************Py_Code_Generator Version: 0.1-0.14-0.1 @ 2023-05-30*************************/
/*************************(C) COPYRIGHT Fudan Microelectronics **** END OF FILE*************************/
