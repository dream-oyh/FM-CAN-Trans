 /**    
  *******************************************************************************************************
  * @file    fm33fg0xxa_fl_exti.h
  * @author  FMSH Application Team
  * @brief   Head file of EXTI FL Module
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
#ifndef __FM33FG0XXA_FL_EXTI_H
#define __FM33FG0XXA_FL_EXTI_H

#ifdef __cplusplus
extern "C" {
#endif
/* Includes -------------------------------------------------------------------------------------------*/
#include "fm33fg0xxa_fl_def.h"
/** @addtogroup FM33FG0XXA_FL_Driver
  * @{
  */
/* Exported types -------------------------------------------------------------------------------------*/
/** @defgroup EXTI_FL_ES_INIT EXTI Exported Init structures
  * @{
  */

/**
  * @brief FL EXTI Init Sturcture definition
  */
typedef struct
{
    /*! EXTI中断采样时钟源配置 */
    uint32_t clockSource;
    /* Sleep/DeepSleep模式下EXTI采样使能或禁止 */
    uint32_t EXTIOnSleep;

} FL_EXTI_CommonInitTypeDef;

/**
  * @brief FL EXTI Init Sturcture definition
  */
typedef struct
{
    /* EXTI PIN*/
    uint32_t extiPinX;

    /*! EXTI触发边沿配置 */
    uint32_t triggerEdge;

    /*! EXTI数字滤波配置 */
    FL_FunState filter;

} FL_EXTI_InitTypeDef;

/**
  * @}
  */
/* Exported constants ---------------------------------------------------------------------------------*/
/** @defgroup EXTI_FL_Exported_Constants EXTI Exported Constants
  * @{
  */


/**
  * @}
  */
/* Exported functions ---------------------------------------------------------------------------------*/
/** @defgroup EXTI_FL_Exported_Functions EXTI Exported Functions
  * @{
  */

/**
  * @}
  */

/** @defgroup EXTI_FL_EF_Init Initialization and de-initialization functions
  * @{
  */
FL_ErrorStatus FL_EXTI_CommonInit(FL_EXTI_CommonInitTypeDef *EXTI_CommonInitStruct);
FL_ErrorStatus FL_EXTI_CommonDeinit(void);
void FL_EXTI_CommonStructInit(FL_EXTI_CommonInitTypeDef *EXTI_CommonInitStruct);

FL_ErrorStatus FL_EXTI_Init(GPIO_Type *GPIOx, FL_EXTI_InitTypeDef *EXTI_InitStruct);
FL_ErrorStatus FL_EXTI_DeInit(GPIO_Type *GPIOx, uint32_t extiPinX);
uint32_t FL_EXTI_GetTrigEdge(GPIO_Type *GPIOx, uint32_t extiPinX);
uint32_t FL_EXTI_IsEnabledDigitalFilter(GPIO_Type *GPIOx, uint32_t extiPinX);
uint32_t FL_EXTI_IsActiveFlag(GPIO_Type *GPIOx, uint32_t extiPinX);
void FL_EXTI_ClearFlag(GPIO_Type *GPIOx, uint32_t extiPinX);
uint32_t FL_EXTI_GetInputPin(GPIO_Type *GPIOx, uint32_t extiPinX);
void FL_EXTI_StructInit(FL_EXTI_InitTypeDef *EXTI_InitStruct);

/**
  * @}
  */


/**
  * @}
  */

#ifdef __cplusplus
}
#endif

#endif /* __FM33FG0XXA_FL_EXTI_H*/

/*************************Py_Code_Generator Version: 0.1-0.14-0.1 @ 2023-04-07*************************/
/*************************(C) COPYRIGHT Fudan Microelectronics **** END OF FILE*************************/
