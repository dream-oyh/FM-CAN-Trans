 /**    
  *******************************************************************************************************
  * @file    fm33fg0xxa_fl_dac.c
  * @author  FMSH Application Team
  * @brief   Source file of DAC FL Module
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

/** @addtogroup FM33FG0xxA_FL_Driver_DAC
  * @{
  */


 /** @defgroup DAC DAC
  * @brief DAC FL driver
  * @{
  */
#ifdef FL_DAC_DRIVER_ENABLED

/* Private macros ------------------------------------------------------------*/
/** @addtogroup DAC_FL_Private_Macros
  * @{
  */
#define           IS_FL_DAC_INSTANCE(INSTANCE)             ((INSTANCE) == DAC)

#define           IS_FL_DAC_TRIGGER_MODE(__VALUE__)        (((__VALUE__) == FL_DISABLE)||\
                                                            ((__VALUE__) == FL_ENABLE))

#define           IS_FL_DAC_TRIGGER_SOURCE(__VALUE__)      (((__VALUE__) == FL_DAC_TRGI_SOFTWARE)||\
                                                            ((__VALUE__) == FL_DAC_TRGI_ATIM)||\
                                                            ((__VALUE__) == FL_DAC_TRGI_GPTIM1)||\
                                                            ((__VALUE__) == FL_DAC_TRGI_GPTIM2)||\
                                                            ((__VALUE__) == FL_DAC_TRGI_BSTIM)||\
                                                            ((__VALUE__) == FL_DAC_TRGI_LPTIM)||\
                                                            ((__VALUE__) == FL_DAC_TRGI_TAU00)||\
                                                            ((__VALUE__) == FL_DAC_TRGI_TAU03)||\
                                                            ((__VALUE__) == FL_DAC_TRGI_EXTIFAB13)||\
                                                            ((__VALUE__) == FL_DAC_TRGI_EXTIFAB29)||\
                                                            ((__VALUE__) == FL_DAC_TRGI_EXTIFCD4)||\
                                                            ((__VALUE__) == FL_DAC_TRGI_EXTIFCD30))

#define           IS_FL_DAC_SWITCH_MODE(__VALUE__)         (((__VALUE__) == FL_DISABLE)||\
                                                            ((__VALUE__) == FL_ENABLE))


/**
  * @brief  配置指定的DAC外设
  * @param  DACx  外设入口地址
  * @param  DAC_InitStruct 指向 @ref FL_DAC_InitTypeDef 的结构体，它包含DAC外设寄存器的配置信息
  * @retval 执行结果
  *         -FL_FAIL 配置过程发生错误
  *         -FL_PASS DAC外设寄存器配置成功
  */
FL_ErrorStatus FL_DAC_Init(DAC_Type *DACx, FL_DAC_InitTypeDef  *DAC_InitStruct)
{
    FL_ErrorStatus status = FL_PASS;
    /* 入口合法性检查 */
    assert_param(IS_FL_DAC_INSTANCE(DACx));
    assert_param(IS_FL_DAC_TRIGGER_MODE(DAC_InitStruct->triggerMode));
    assert_param(IS_FL_DAC_TRIGGER_SOURCE(DAC_InitStruct->triggerSource));
    assert_param(IS_FL_DAC_SWITCH_MODE(DAC_InitStruct->switchMode));
    /* 复位清零DAC模块 */
    FL_RMU_EnablePeripheralReset(RMU);
    FL_RMU_EnableResetAPBPeripheral(RMU,FL_RMU_RSTAPB_DAC);
    FL_RMU_DisableResetAPBPeripheral(RMU,FL_RMU_RSTAPB_DAC);
    FL_RMU_DisablePeripheralReset(RMU);
    /* 使能DAC总线时钟 */
    FL_CMU_EnableGroup2BusClock(FL_CMU_GROUP2_BUSCLK_DAC);
    /* 关闭DAC模块 */
    FL_DAC_Disable(DACx);
    if(FL_DAC_IsEnabled(DACx) == 0U)
    {
        if(DAC_InitStruct->triggerMode)
        {
            FL_DAC_SetTriggerSource(DACx,DAC_InitStruct->triggerSource);
            FL_DAC_EnableTriggerMode(DACx);
        }
        else
        {
            FL_DAC_DisableTriggerMode(DACx);
        }
        if(DAC_InitStruct->switchMode)
        {
            FL_DAC_EnableFeedbackSwitch(DACx);
        }
        else
        {
            FL_DAC_DisableFeedbackSwitch(DACx);
        }
    }
    else
    {
        status = FL_FAIL;
    }

    return status;
}


/**
  * @brief  恢复DAC外设寄存器到复位值
  * @param  DACx  外设入口地址
  * @retval 执行结果
  *         -FL_PASS DAC外设寄存器值恢复复位值
  *         -FL_FAIL 未成功执行
  */
FL_ErrorStatus FL_DAC_DeInit(DAC_Type *DACx)
{
    FL_ErrorStatus status = FL_PASS;
    /* 入口合法性检查 */
    assert_param(IS_FL_DAC_INSTANCE(DACx));
    /* 复位清零DAC模块 */
    FL_RMU_EnablePeripheralReset(RMU);
    FL_RMU_EnableResetAPBPeripheral(RMU,FL_RMU_RSTAPB_DAC);
    FL_RMU_DisableResetAPBPeripheral(RMU,FL_RMU_RSTAPB_DAC);
    FL_RMU_DisablePeripheralReset(RMU);

    return status;
}


#endif /* FL_DAC_DRIVER_ENABLED */



/**
  * @}
  */
/**
  * @}
  */
/*************************************************************END OF FILE************************************************************/



