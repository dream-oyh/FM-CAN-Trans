 /**    
  *******************************************************************************************************
  * @file    fm33fg0xxa_fl_clm.c
  * @author  FMSH Application Team
  * @brief   Source file of CLM FL Module
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

/** @addtogroup FM33FG0xxA_FL_Driver
  * @{
  */

/** @addtogroup CLM
  * @{
  */

#ifdef FL_CLM_DRIVER_ENABLED

/* Private macros ------------------------------------------------------------*/
/** @addtogroup CLM_FL_Private_Macros
  * @{
  */
#define         IS_FL_CLM_INSTANCE(INSTANCE)                (((INSTANCE) == CLM0) ||\
                                                             ((INSTANCE) == CLM1))

#define         IS_FL_CLM_MODE_INSTANCE(__VALUE__)          (((__VALUE__) == FL_CLM_WORKMODE_INTERRUPT) ||\
                                                             ((__VALUE__) == FL_CLM_WORKMODE_RESET))

#define         IS_FL_CLM_MONITORCLOCK_INSTANCE(__VALUE__)  (((__VALUE__) == FL_CLM_MONCLK_RCHF) ||\
                                                             ((__VALUE__) == FL_CLM_MONCLK_PLL)  ||\
                                                             ((__VALUE__) == FL_CLM_MONCLK_XTHF))

/**
  *@}
  */
 
/* Exported functions --------------------------------------------------------*/
/** @addtogroup CLM_FL_EF_Init
  * @{
  */

/**
  * @brief  配置指定的CLM外设
  * @param  CLMx  外设入口地址
  * @param  CLM_InitStruct 指向 @ref FL_CLM_InitTypeDef 的结构体，它包含CLM外设寄存器的配置信息
  * @retval 执行结果
  *         -FL_FAIL 配置过程发生错误
  *         -FL_PASS CLM外设寄存器配置成功
  */
FL_ErrorStatus FL_CLM_Init(CLM_Type *CLMx, FL_CLM_InitTypeDef  *CLM_InitStruct)
{
    FL_ErrorStatus status = FL_PASS;
    /* 校验参数是否正确 */
    assert_param(IS_FL_CLM_INSTANCE(CLMx));  
    assert_param(IS_FL_CLM_MODE_INSTANCE(CLM_InitStruct->mode));
    assert_param(IS_FL_CLM_MONITORCLOCK_INSTANCE(CLM_InitStruct->monitorclock));
    if(CLMx == CLM0)
    {   /* 开启CLM0总线时钟 */
        FL_CMU_EnableGroup1BusClock(FL_CMU_GROUP1_BUSCLK_CLM0);
    }
    else
    {   /* 开启CLM1总线时钟 */
        FL_CMU_EnableGroup1BusClock(FL_CMU_GROUP1_BUSCLK_CLM1);
    }
    /* 配置CLMx的工作模式 */
    FL_CLM_SetWorkingMode(CLMx,CLM_InitStruct->mode);
    /* 配置CLMx的超时复位功能 */
    if(CLM_InitStruct->timeoutReset == FL_ENABLE)
    {
        FL_CLM_EnableTimeOutReset(CLMx);
    }
    else
    {
        FL_CLM_DisableTimeOutReset(CLMx);
    }
    /* 配置CLMx的参考周期 */
    FL_CLM_WriteReferenceClockCycle(CLMx,CLM_InitStruct->referenceclockCycle);
    /* 配置CLMx的监控时钟 */
    FL_CLM_SetMonitorClock(CLMx,CLM_InitStruct->monitorclock);
    /* 配置CLMx的时钟监控比较高阈值 */
    FL_CLM_WriteCompareHighThreshold(CLMx,CLM_InitStruct->CompareHighThreshold);
    /* 配置CLMx的时钟监控比较低阈值 */
    FL_CLM_WriteCompareLowThreshold(CLMx,CLM_InitStruct->CompareLowThreshold);
    return status;
}


/**
  * @brief  恢复CLM外设寄存器到复位值
  * @param  CLMx  外设入口地址
  * @retval 执行结果
  *         -FL_PASS CLM外设寄存器值恢复复位值
  *         -FL_FAIL 未成功执行
  */
FL_ErrorStatus FL_CLM_DeInit(CLM_Type *CLMx)
{
    FL_ErrorStatus status = FL_PASS;
    /* 入口合法性检查 */
    assert_param(IS_FL_CLM_INSTANCE(CLMx));
    if(CLMx == CLM0)
    {
        /* 外设复位使能 */
        FL_RMU_EnablePeripheralReset(RMU);
        FL_RMU_EnableResetAPBPeripheral(RMU,FL_RMU_RSTAPB_CLM0);
        FL_RMU_DisableResetAPBPeripheral(RMU,FL_RMU_RSTAPB_CLM0);
        FL_RMU_DisablePeripheralReset(RMU);
        FL_CMU_DisableGroup1BusClock(FL_CMU_GROUP1_BUSCLK_CLM0);
    }
    else
    {
        /* 外设复位使能 */
        FL_RMU_EnablePeripheralReset(RMU);
        FL_RMU_EnableResetAPBPeripheral(RMU,FL_RMU_RSTAPB_CLM1);
        FL_RMU_DisableResetAPBPeripheral(RMU,FL_RMU_RSTAPB_CLM1);
        FL_RMU_DisablePeripheralReset(RMU);
        FL_CMU_DisableGroup1BusClock(FL_CMU_GROUP1_BUSCLK_CLM1);
    }

    return status;
}


#endif /* FL_CLM_DRIVER_ENABLED */



/**
  * @}
  */
/**
  * @}
  */
/*************************************************************END OF FILE************************************************************/



