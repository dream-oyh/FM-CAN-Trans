 /**    
  *******************************************************************************************************
  * @file    fm33fg0xxa_fl_atim.c
  * @author  FMSH Application Team
  * @brief   Source file of ATIM FL Module
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

/** @addtogroup ATIM
  * @{
  */

#ifdef FL_ATIM_DRIVER_ENABLED

/* Private macros ------------------------------------------------------------*/
/** @addtogroup ATIM_FL_Private_Macros
  * @{
  */


#define IS_ATIM_INSTANCE(TIMx)                         ((TIMx) == ATIM)

#define IS_ATIM_CLKSRC(__VALUE__)                      (   ((__VALUE__) == FL_CMU_ATIM_CLK_SOURCE_APBCLK)\
                                                        || ((__VALUE__) == FL_CMU_ATIM_CLK_SOURCE_PLL_X2))


#define IS_FL_ATIM_COUNTERMODE(__VALUE__)              (   ((__VALUE__) == FL_ATIM_COUNTER_DIR_UP)\
                                                        || ((__VALUE__) == FL_ATIM_COUNTER_DIR_DOWN)\
                                                        || ((__VALUE__) == FL_ATIM_COUNTER_ALIGNED_CENTER_DOWN)\
                                                        || ((__VALUE__) == FL_ATIM_COUNTER_ALIGNED_CENTER_UP)\
                                                        || ((__VALUE__) == FL_ATIM_COUNTER_ALIGNED_CENTER_UP_DOWN))

#define IS_FL_ATIM_CLOCKDIVISION(__VALUE__)            (   ((__VALUE__) == FL_ATIM_CLK_DIVISION_DIV1)\
                                                        || ((__VALUE__) == FL_ATIM_CLK_DIVISION_DIV2)\
                                                        || ((__VALUE__) == FL_ATIM_CLK_DIVISION_DIV4))


#define IS_FL_ATIM_CC_MODE(__VALUE__)                  (   ((__VALUE__) == FL_ATIM_CHANNEL_MODE_OUTPUT)\
                                                        || ((__VALUE__) == FL_ATIM_CHANNEL_MODE_INPUT_NORMAL)\
                                                        || ((__VALUE__) == FL_ATIM_CHANNEL_MODE_INPUT_CROSSOVER)\
                                                        || ((__VALUE__) == FL_ATIM_CHANNEL_MODE_INPUT_TRC))

#define IS_FL_ATIM_IC_FILTER(__VALUE__)                (   ((__VALUE__) == FL_ATIM_IC_FILTER_DIV1 )\
                                                        || ((__VALUE__) ==FL_ATIM_IC_FILTER_DIV1_N2)\
                                                        || ((__VALUE__) == FL_ATIM_IC_FILTER_DIV1_N4)\
                                                        || ((__VALUE__) == FL_ATIM_IC_FILTER_DIV1_N8)\
                                                        || ((__VALUE__) == FL_ATIM_IC_FILTER_DIV2_N6)\
                                                        || ((__VALUE__) == FL_ATIM_IC_FILTER_DIV2_N8)\
                                                        || ((__VALUE__) == FL_ATIM_IC_FILTER_DIV4_N6)\
                                                        || ((__VALUE__) == FL_ATIM_IC_FILTER_DIV4_N8)\
                                                        || ((__VALUE__) == FL_ATIM_IC_FILTER_DIV8_N6)\
                                                        || ((__VALUE__) == FL_ATIM_IC_FILTER_DIV8_N8)\
                                                        || ((__VALUE__) == FL_ATIM_IC_FILTER_DIV16_N5)\
                                                        || ((__VALUE__) == FL_ATIM_IC_FILTER_DIV16_N6)\
                                                        || ((__VALUE__) == FL_ATIM_IC_FILTER_DIV16_N8)\
                                                        || ((__VALUE__) == FL_ATIM_IC_FILTER_DIV32_N5)\
                                                        || ((__VALUE__) == FL_ATIM_IC_FILTER_DIV32_N6)\
                                                        || ((__VALUE__) == FL_ATIM_IC_FILTER_DIV32_N8))

#define IS_FL_ATIM_CHANNEL(__VALUE__)                  (   ((__VALUE__) == FL_ATIM_CHANNEL_1)\
                                                        || ((__VALUE__) == FL_ATIM_CHANNEL_2)\
                                                        || ((__VALUE__) == FL_ATIM_CHANNEL_3)\
                                                        || ((__VALUE__) == FL_ATIM_CHANNEL_4))



#define IS_FL_ATIM_SLAVE_MODE(__VALUE__)               (   ((__VALUE__) == FL_ATIM_SLAVE_MODE_PROHIBITED)\
                                                        || ((__VALUE__) == FL_ATIM_SLAVE_MODE_ENCODER_X2_TI1)\
                                                        || ((__VALUE__) == FL_ATIM_SLAVE_MODE_ENCODER_X2_TI2)\
                                                        || ((__VALUE__) == FL_ATIM_SLAVE_MODE_ENCODER_X4_TI1TI2)\
                                                        || ((__VALUE__) == FL_ATIM_SLAVE_MODE_TRGI_RISE_RST)\
                                                        || ((__VALUE__) == FL_ATIM_SLAVE_MODE_TRGI_HIGH_RUN)\
                                                        || ((__VALUE__) == FL_ATIM_SLAVE_MODE_TRGI_RISE_RUN)\
                                                        || ((__VALUE__) == FL_ATIM_SLAVE_MODE_TRGI_CLK))


#define IS_FL_ATIM_TRIGGER_SRC(__VALUE__)              (   ((__VALUE__) == FL_ATIM_TRGI_ITR0 )\
                                                        || ((__VALUE__) == FL_ATIM_TRGI_ITR1 )\
                                                        || ((__VALUE__) == FL_ATIM_TRGI_ITR2)\
                                                        || ((__VALUE__) == FL_ATIM_TRGI_ITR3)\
                                                        || ((__VALUE__) == FL_ATIM_TRGI_TI1F_EDGE)\
                                                        || ((__VALUE__) == FL_ATIM_TRGI_TI1FP1)\
                                                        || ((__VALUE__) == FL_ATIM_TRGI_TI2FP2)\
                                                        || ((__VALUE__) == FL_ATIM_TRGI_ETRF))



#define IS_FL_ATIM_ETP_FILTER(__VALUE__)               (   ((__VALUE__) == FL_ATIM_ETR_FILTER_DIV1)\
                                                        || ((__VALUE__) == FL_ATIM_ETR_FILTER_DIV1_N2)\
                                                        || ((__VALUE__) == FL_ATIM_ETR_FILTER_DIV1_N4)\
                                                        || ((__VALUE__) == FL_ATIM_ETR_FILTER_DIV1_N8)\
                                                        || ((__VALUE__) == FL_ATIM_ETR_FILTER_DIV2_N6)\
                                                        || ((__VALUE__) == FL_ATIM_ETR_FILTER_DIV2_N8)\
                                                        || ((__VALUE__) == FL_ATIM_ETR_FILTER_DIV4_N6)\
                                                        || ((__VALUE__) == FL_ATIM_ETR_FILTER_DIV4_N8)\
                                                        || ((__VALUE__) == FL_ATIM_ETR_FILTER_DIV8_N6)\
                                                        || ((__VALUE__) == FL_ATIM_ETR_FILTER_DIV8_N8)\
                                                        || ((__VALUE__) == FL_ATIM_ETR_FILTER_DIV16_N5)\
                                                        || ((__VALUE__) == FL_ATIM_ETR_FILTER_DIV16_N6)\
                                                        || ((__VALUE__) == FL_ATIM_ETR_FILTER_DIV16_N8)\
                                                        || ((__VALUE__) == FL_ATIM_ETR_FILTER_DIV32_N5)\
                                                        || ((__VALUE__) == FL_ATIM_ETR_FILTER_DIV32_N6)\
                                                        || ((__VALUE__) == FL_ATIM_ETR_FILTER_DIV32_N8))


#define IS_FL_ATIM_ETR_PSC(__VALUE__)                  (   ((__VALUE__) == FL_ATIM_ETR_PSC_DIV1)\
                                                        || ((__VALUE__) == FL_ATIM_ETR_PSC_DIV2)\
                                                        || ((__VALUE__) == FL_ATIM_ETR_PSC_DIV4)\
                                                        || ((__VALUE__) == FL_ATIM_ETR_PSC_DIV8))



#define IS_FL_ATIM_ETR_POLARITY(__VALUE__)             (   ((__VALUE__) == FL_ATIM_ETR_POLARITY_NORMAL)\
                                                        || ((__VALUE__) == FL_ATIM_ETR_POLARITY_INVERT))



#define IS_FL_ATIM_IC_POLARITY(__VALUE__)              (   ((__VALUE__) == FL_ATIM_IC_POLARITY_NORMAL)\
                                                        || ((__VALUE__) == FL_ATIM_IC_POLARITY_INVERT))



#define IS_FL_ATIM_IC_ACTIVEINPUT(__VALUE__)           (   ((__VALUE__) == FL_ATIM_CHANNEL_MODE_INPUT_NORMAL)\
                                                        || ((__VALUE__) == FL_ATIM_CHANNEL_MODE_INPUT_CROSSOVER)\
                                                        || ((__VALUE__) == FL_ATIM_CHANNEL_MODE_INPUT_TRC))


#define IS_FL_ATIM_IC_PRESCALER(__VALUE__)             (   ((__VALUE__) == FL_ATIM_IC_PSC_DIV1)\
                                                        || ((__VALUE__) == FL_ATIM_IC_PSC_DIV2)\
                                                        || ((__VALUE__) == FL_ATIM_IC_PSC_DIV4)\
                                                        || ((__VALUE__) == FL_ATIM_IC_PSC_DIV8))



#define IS_FL_ATIM_OC_POLARITY(__VALUE__)              (   ((__VALUE__) == FL_ATIM_OC_POLARITY_NORMAL)\
                                                        || ((__VALUE__) == FL_ATIM_OC_POLARITY_INVERT))



#define IS_FL_ATIM_OC_MODE(__VALUE__)                  (   ((__VALUE__) == FL_ATIM_OC_MODE_FROZEN)\
                                                        || ((__VALUE__) == FL_ATIM_OC_MODE_ACTIVE)\
                                                        || ((__VALUE__) == FL_ATIM_OC_MODE_INACTIVE)\
                                                        || ((__VALUE__) == FL_ATIM_OC_MODE_TOGGLE)\
                                                        || ((__VALUE__) == FL_ATIM_OC_MODE_FORCED_INACTIVE)\
                                                        || ((__VALUE__) == FL_ATIM_OC_MODE_FORCED_ACTIVE)\
                                                        || ((__VALUE__) == FL_ATIM_OC_MODE_PWM1)\
                                                        || ((__VALUE__) == FL_ATIM_OC_MODE_PWM2))

#define IS_FL_ATIM_AUTORELOAB_STATE(__VALUE__)         (   ((__VALUE__) == FL_ENABLE)\
                                                        || ((__VALUE__) == FL_DISABLE))

#define IS_FL_ATIM_OC_FASTMODE(__VALUE__)              (   ((__VALUE__) == FL_ENABLE)\
                                                        || ((__VALUE__) == FL_DISABLE))

#define IS_FL_ATIM_OC_PRELOAD(__VALUE__)               (   ((__VALUE__) == FL_ENABLE)\
                                                        || ((__VALUE__) == FL_DISABLE))

#define IS_FL_ATIM_OC_ETR_CLEARN(__VALUE__)            (   ((__VALUE__) == FL_ENABLE)\
                                                        || ((__VALUE__) == FL_DISABLE))

#define IS_FL_ATIM_OCN_STATE(__VALUE__)                (   ((__VALUE__) == FL_ENABLE)\
                                                        || ((__VALUE__) == FL_DISABLE))

#define IS_FL_ATIM_OC_STATE(__VALUE__)                 (   ((__VALUE__) == FL_ENABLE)\
                                                        || ((__VALUE__) == FL_DISABLE))

#define IS_FL_ATIM_OC_IDLESTATE(__VALUE__)             (   ((__VALUE__) == FL_ATIM_OC_IDLE_STATE_LOW)\
                                                        || ((__VALUE__) == FL_ATIM_OC_IDLE_STATE_HIGH))

#define IS_FL_ATIM_OC_NIDLESTATE(__VALUE__)            (   ((__VALUE__) == FL_ATIM_OCN_IDLE_STATE_LOW)\
                                                        || ((__VALUE__) == FL_ATIM_OCN_IDLE_STATE_HIGH))


#define IS_FL_ATIM_OC_NPOLARITY(__VALUE__)             (   ((__VALUE__) == FL_ATIM_OCN_POLARITY_NORMAL)\
                                                        || ((__VALUE__) == FL_ATIM_OCN_POLARITY_INVERT))



#define IS_FL_ATIM_BDTR_FILTER(__VALUE__)              (   ((__VALUE__) == FL_ATIM_BREAK_FILTER_DIV1)\
                                                        || ((__VALUE__) == FL_ATIM_BREAK_FILTER_DIV1_N2)\
                                                        || ((__VALUE__) == FL_ATIM_BREAK_FILTER_DIV1_N4)\
                                                        || ((__VALUE__) == FL_ATIM_BREAK_FILTER_DIV1_N8)\
                                                        || ((__VALUE__) == FL_ATIM_BREAK_FILTER_DIV2_N6)\
                                                        || ((__VALUE__) == FL_ATIM_BREAK_FILTER_DIV2_N8)\
                                                        || ((__VALUE__) == FL_ATIM_BREAK_FILTER_DIV4_N6)\
                                                        || ((__VALUE__) == FL_ATIM_BREAK_FILTER_DIV4_N8)\
                                                        || ((__VALUE__) == FL_ATIM_BREAK_FILTER_DIV8_N6)\
                                                        || ((__VALUE__) == FL_ATIM_BREAK_FILTER_DIV8_N8)\
                                                        || ((__VALUE__) == FL_ATIM_BREAK_FILTER_DIV16_N5)\
                                                        || ((__VALUE__) == FL_ATIM_BREAK_FILTER_DIV16_N6)\
                                                        || ((__VALUE__) == FL_ATIM_BREAK_FILTER_DIV16_N8)\
                                                        || ((__VALUE__) == FL_ATIM_BREAK_FILTER_DIV32_N5)\
                                                        || ((__VALUE__) == FL_ATIM_BREAK_FILTER_DIV32_N6)\
                                                        || ((__VALUE__) == FL_ATIM_BREAK_FILTER_DIV32_N8))

#define IS_FL_ATIM_OSSR_STATE(__VALUE__)               (   ((__VALUE__) == FL_ATIM_OSSR_DISABLE)\
                                                        || ((__VALUE__) == FL_ATIM_OSSR_ENABLE))

#define IS_FL_ATIM_OSSI_STATE(__VALUE__)               (   ((__VALUE__) == FL_ATIM_OSSI_DISABLE)\
                                                        || ((__VALUE__) == FL_ATIM_OSSI_ENABLE))

#define IS_FL_ATIM_LOCK_LEVEL(__VALUE__)               (   ((__VALUE__) == FL_ATIM_LOCK_LEVEL_OFF)\
                                                        || ((__VALUE__) == FL_ATIM_LOCK_LEVEL_1)\
                                                        || ((__VALUE__) == FL_ATIM_LOCK_LEVEL_2)\
                                                        || ((__VALUE__) == FL_ATIM_LOCK_LEVEL_3))

#define IS_FL_ATIM_BREAK_POLARITY(__VALUE__)           (   ((__VALUE__) == FL_ATIM_BREAK_POLARITY_LOW)\
                                                        || ((__VALUE__) == FL_ATIM_BREAK_POLARITY_HIGH))

#define IS_FL_ATIM_AUTOMATIC_OUTPUT_STATE(__VALUE__)   (   ((__VALUE__) == FL_DISABLE)\
                                                        || ((__VALUE__) == FL_ENABLE))

#define IS_FL_ATIM_TRIGGER_DELAY(__VALUE__)            (   ((__VALUE__) == FL_DISABLE)\
                                                        || ((__VALUE__) == FL_ENABLE))

#define IS_FL_ATIM_IC_CAPTURE_STATE(__VALUE__)         (   ((__VALUE__) == FL_DISABLE)\
                                                        || ((__VALUE__) == FL_ENABLE))

/**
  * @}
  */

/* Private function prototypes -----------------------------------------------*/
/** @defgroup TIM_FL_Private_Functions TIM Private Functions
  * @{
  */

/**
  * @}
  */

/* Exported functions --------------------------------------------------------*/
/** @addtogroup TIM_FL_EF_Init
  * @{
  */

/**
  * @brief  复位对应ATIMx寄存器.
  * @param  ATIMx
  * @retval ErrorStatus枚举值:
  *         -FL_PASS 外设寄存器值恢复复位值
  *         -FL_FAIL 未成功执行
  */
FL_ErrorStatus FL_ATIM_DeInit(ATIM_Type *TIMx)
{
    FL_ErrorStatus result = FL_PASS;
    /* Check the parameters */
    assert_param(IS_ATIM_INSTANCE(TIMx));
    /* 使能外设复位 */
    FL_RMU_EnablePeripheralReset(RMU);
    /* 复位ATIM外设寄存器 */
    FL_RMU_EnableResetAPBPeripheral(RMU, FL_RMU_RSTAPB_ATIM);
    FL_RMU_DisableResetAPBPeripheral(RMU, FL_RMU_RSTAPB_ATIM);
    /* 关闭外设总线始时钟和工作时钟 */
    FL_CMU_DisableGroup4BusClock(FL_CMU_GROUP4_BUSCLK_ATIM);
    /* 锁定外设复位 */
    FL_RMU_DisablePeripheralReset(RMU);
    return result;
}
/**
  * @brief  配置基本定时器时基单元（内部时钟源）.
  * @param  TIMx Timer Instance
  * @param  TIM_InitStruct 指向一个 @ref FL_ATIM_InitTypeDef(时基配置结构体)
  * @retval ErrorStatus枚举值
  *         -FL_FAIL 配置过程发生错误
  *         -FL_PASS 成功
  */

FL_ErrorStatus FL_ATIM_Init(ATIM_Type *TIMx, FL_ATIM_InitTypeDef *TIM_InitStruct)
{
    uint32_t i = 5;
    /* 参数检查 */
    assert_param(IS_ATIM_INSTANCE(TIMx));
    assert_param(IS_FL_ATIM_COUNTERMODE(TIM_InitStruct->counterMode));
    assert_param(IS_FL_ATIM_CLOCKDIVISION(TIM_InitStruct->clockDivision));
    assert_param(IS_FL_ATIM_AUTORELOAB_STATE(TIM_InitStruct->autoReloadState));
    assert_param(IS_ATIM_CLKSRC(TIM_InitStruct->clockSource));
    /* 时钟总线使能配置 */
    FL_CMU_SetATIMClockSource(TIM_InitStruct->clockSource);
    FL_CMU_EnableGroup4BusClock(FL_CMU_GROUP4_BUSCLK_ATIM);
    FL_CMU_EnableOperationClock(FL_CMU_OPCLK_ATIM);
    /* 设置重复计数值 */
    FL_ATIM_WriteRepetitionCounter(TIMx, TIM_InitStruct->repetitionCounter);
    /* 计数器计数模式配置 */
    switch(TIM_InitStruct->counterMode)
    {
        /* 中心对称模式 */
        case FL_ATIM_COUNTER_ALIGNED_CENTER_DOWN   :
        case FL_ATIM_COUNTER_ALIGNED_CENTER_UP     :
        case FL_ATIM_COUNTER_ALIGNED_CENTER_UP_DOWN:
            FL_ATIM_SetCounterDirection(TIMx,FL_ATIM_COUNTER_DIR_UP);
            FL_ATIM_SetCounterAlignedMode(TIMx, TIM_InitStruct->counterMode);
            break;
        default:
            /* 边沿模式 */
            FL_ATIM_SetCounterDirection(TIMx, TIM_InitStruct->counterMode);
            FL_ATIM_SetCounterAlignedMode(TIMx, FL_ATIM_COUNTER_ALIGNED_EDGE);
            break;
    }
    /* 自动重装载值 */
    FL_ATIM_WriteAutoReload(TIMx, TIM_InitStruct->autoReload);
    /* 定时器分频系数与数字滤波器所使用的采样时钟分频比 */
    FL_ATIM_SetClockDivision(TIMx, TIM_InitStruct->clockDivision);
    /* 时钟分频 */
    FL_ATIM_WritePrescaler(TIMx, TIM_InitStruct->prescaler);
    /* 预装载配置 */
    if(TIM_InitStruct->autoReloadState == FL_ENABLE)
    {
        FL_ATIM_EnableARRPreload(TIMx);
    }
    else
    {
        FL_ATIM_DisableARRPreload(TIMx);
    }
    /* 手动触发更新事件，将配置值写入 */
    FL_ATIM_GenerateUpdateEvent(TIMx);
    while((!FL_ATIM_IsActiveFlag_Update(ATIM))&&i)
    {
        i--;
    }
    /*清除UIF标志，防止产生UG事件中断*/
    FL_ATIM_ClearFlag_Update(ATIM);
    return FL_PASS;
}

/**
  * @brief  设置 FL_ATIM_InitTypeDef 为默认配置
  * @param  TIM_InitStruct 指向需要将值设置为默认配置的结构体 @ref FL_ATIM_InitTypeDef 结构体
  *
  * @retval None
  */
void FL_ATIM_StructInit(FL_ATIM_InitTypeDef *TIM_InitStruct)
{
    /* Set the default configuration */
    TIM_InitStruct->clockSource           = FL_CMU_ATIM_CLK_SOURCE_APBCLK;
    TIM_InitStruct->prescaler             = (uint16_t)0x0000;
    TIM_InitStruct->counterMode           = FL_ATIM_COUNTER_DIR_UP;
    TIM_InitStruct->autoReload            = 0xFFFFU;
    TIM_InitStruct->clockDivision         = FL_ATIM_CLK_DIVISION_DIV1;
    TIM_InitStruct->repetitionCounter     = 0;
    TIM_InitStruct->autoReloadState       = FL_DISABLE;
}

/**
  * @brief  配置基本定时器从模式，包括编码器模式.
  * @param  TIMx Timer Instance
  * @param  TIM_InitStruct 指向一个 @ref FL_ATIM_SlaveInitTypeDef 结构体
  * @retval ErrorStatus枚举值
  *         -FL_FAIL 配置过程发生错误
  *         -FL_PASS 成功
  */
FL_ErrorStatus FL_ATIM_SlaveMode_Init(ATIM_Type *TIMx, FL_ATIM_SlaveInitTypeDef *TIM_InitStruct)
{
    /* 参数检查 */
    assert_param(IS_ATIM_INSTANCE(TIMx));
    assert_param(IS_FL_ATIM_TRIGGER_DELAY(TIM_InitStruct->triggerDelay));
    assert_param(IS_FL_ATIM_TRIGGER_SRC(TIM_InitStruct->triggerSrc));
    assert_param(IS_FL_ATIM_SLAVE_MODE(TIM_InitStruct->slaveMode));
    /* 时钟总线使能配置 */
    FL_CMU_EnableGroup4BusClock(FL_CMU_GROUP4_BUSCLK_ATIM);
    /* 触发延迟默认关闭 */
    FL_ATIM_DisableMasterSlaveMode(TIMx);
    /* 关闭从模式以能写入TS */
    FL_ATIM_SetSlaveMode(TIMx, 0);
    /* 从模式输入源选择 */
    FL_ATIM_SetTriggerInput(TIMx, TIM_InitStruct->triggerSrc);
    /* 从模式选择 */
    FL_ATIM_SetSlaveMode(TIMx, TIM_InitStruct->slaveMode);
    /* 触发延迟默认关闭 */
    if(TIM_InitStruct->triggerDelay == FL_ENABLE)
    {
        FL_ATIM_EnableMasterSlaveMode(TIMx);
    }
    return FL_PASS;
}

/**
  * @brief  设置 FL_ATIM_SlaveInitTypeDef 为默认配置
  * @param  TIM_InitStruct 指向需要将值设置为默认配置的结构体 @ref FL_ATIM_SlaveInitTypeDef 结构体
  *
  * @retval None
  */
void FL_ATIM_SlaveModeStructInit(FL_ATIM_SlaveInitTypeDef *TIM_InitStruct)
{
    TIM_InitStruct->slaveMode     = FL_ATIM_SLAVE_MODE_PROHIBITED;
    TIM_InitStruct->triggerSrc    = FL_ATIM_TRGI_TI1FP1;
    TIM_InitStruct->triggerDelay  = FL_DISABLE;
}

/**
  * @brief  配置TIM的输入捕获通道.
  * @param  TIMx Timer Instance
  * @param  Channel This parameter can be one of the following values:
  *         @arg @ref FL_ATIM_CHANNEL_0
  *         @arg @ref FL_ATIM_CHANNEL_1
  *         @arg @ref FL_ATIM_CHANNEL_2
  *         @arg @ref FL_ATIM_CHANNEL_3
  * @param  TIM_IC_InitStruct 指向一个 @ref FL_ATIM_IC_InitTypeDef 结构体
  * @retval  TIM_OC_InitStruct pointer to a @ref FL_ATIM_OC_InitTypeDef structure
  *         -FL_FAIL 配置过程发生错误
  *         -FL_PASS 成功
  */
FL_ErrorStatus  FL_ATIM_IC_Init(ATIM_Type *TIMx, uint32_t channel, FL_ATIM_IC_InitTypeDef *IC_InitStruct)
{
    /* 参数检查 */
    assert_param(IS_FL_ATIM_CHANNEL(channel));
    assert_param(IS_FL_ATIM_IC_CAPTURE_STATE(IC_InitStruct->captureState));
    assert_param(IS_FL_ATIM_IC_POLARITY(IC_InitStruct->ICPolarity));
    assert_param(IS_FL_ATIM_IC_ACTIVEINPUT(IC_InitStruct->ICActiveInput));
    assert_param(IS_FL_ATIM_IC_PRESCALER(IC_InitStruct->ICPrescaler));
    assert_param(IS_FL_ATIM_IC_FILTER(IC_InitStruct->ICFilter));
    /* 时钟总线使能配置 */
    FL_CMU_EnableGroup4BusClock(FL_CMU_GROUP4_BUSCLK_ATIM);
    /* 通道关闭 */
    FL_ATIM_OC_DisableChannel(TIMx, channel);
    /*捕获极性 */
    FL_ATIM_IC_SetChannelPolarity(TIMx, IC_InitStruct->ICPolarity, channel);
    /* 捕获映射通道 */
    FL_ATIM_CC_SetChannelMode(TIMx, IC_InitStruct->ICActiveInput, channel);
    /* 捕获预分频 */
    FL_ATIM_IC_SetPrescaler(TIMx, IC_InitStruct->ICPrescaler, channel);
    /* 捕获滤波器 */
    FL_ATIM_IC_SetFilter(TIMx, IC_InitStruct->ICFilter, channel);
    if(IC_InitStruct->captureState == FL_ENABLE)
    {
        FL_ATIM_IC_EnableChannel(TIMx, channel);
    }
    return FL_PASS;
}
/**
  * @brief  设置 FL_ATIM_IC_InitTypeDef 为默认配置
  * @param  TIM_ICInitStruct 指向需要将值设置为默认配置的结构体 @ref FL_ATIM_IC_InitTypeDef 结构体
  *
  * @retval None
  */
void FL_ATIM_IC_StructInit(FL_ATIM_IC_InitTypeDef *TIM_ICInitStruct)
{
    /* 默认配置 */
    TIM_ICInitStruct->ICPolarity    = FL_ATIM_IC_POLARITY_NORMAL;
    TIM_ICInitStruct->ICActiveInput = FL_ATIM_CHANNEL_MODE_INPUT_NORMAL;
    TIM_ICInitStruct->ICPrescaler   = FL_ATIM_IC_PSC_DIV1;
    TIM_ICInitStruct->ICFilter      = FL_ATIM_IC_FILTER_DIV1;
    TIM_ICInitStruct->captureState  = FL_DISABLE;
}
/**
  * @brief  配置TIM触发输入捕获通道ETR.
  * @param  TIMx Timer Instance
  * @param  ETPolarity   极性
  * @param  ETPrescaler  分频
  * @param  ETR_Filter   滤波
  * @param  TIM_IC_InitStruct 指向一个 @ref FL_ATIM_IC_InitTypeDef 结构体
  * @retval  TIM_OC_InitStruct pointer to a @ref FL_ATIM_OC_InitTypeDef structure
  *         -FL_FAIL 配置过程发生错误
  *         -FL_PASS 成功
  */
FL_ErrorStatus  FL_ATIM_ETR_Init(ATIM_Type *TIMx, FL_ATIM_ETR_InitTypeDef *TIM_InitStruct)
{
    assert_param(IS_FL_ATIM_ETP_FILTER(TIM_InitStruct->ETRFilter));
    assert_param(IS_FL_ATIM_ETR_PSC(TIM_InitStruct->ETRClockDivision));
    assert_param(IS_FL_ATIM_ETR_POLARITY(TIM_InitStruct->ETRPolarity));
    /* 时钟总线使能配置 */
    FL_CMU_EnableGroup4BusClock(FL_CMU_GROUP4_BUSCLK_ATIM);
    /* 外部时钟极性 */
    FL_ATIM_SetETRPolarity(TIMx, TIM_InitStruct->ETRPolarity);
    /* 外部时钟滤波 */
    FL_ATIM_SetETRFilter(TIMx, TIM_InitStruct->ETRFilter);
    /* 外部时钟分频 */
    FL_ATIM_SetETRPrescaler(TIMx, TIM_InitStruct->ETRClockDivision);
    if(TIM_InitStruct->useExternalTrigger == FL_ENABLE)
    {
        FL_ATIM_EnableExternalClock(TIMx);
    }
    else
    {
        FL_ATIM_DisableExternalClock(TIMx);
    }
    return FL_PASS;
}

void FL_ATIM_ETRStructInit(FL_ATIM_ETR_InitTypeDef *TIM_InitStruct)
{
    TIM_InitStruct->useExternalTrigger          = FL_DISABLE;
    TIM_InitStruct->ETRFilter           = FL_ATIM_ETR_FILTER_DIV1;
    TIM_InitStruct->ETRPolarity         = FL_ATIM_ETR_POLARITY_NORMAL;
    TIM_InitStruct->ETRClockDivision    = FL_ATIM_ETR_PSC_DIV1;
}
/**
  * @brief  配置
  * @param  TIMx Timer Instance
  * @param  Channel This parameter can be one of the following values:
  *         @arg @ref FL_ATIM_CHANNEL_1
  *         @arg @ref FL_ATIM_CHANNEL_2
  *         @arg @ref FL_ATIM_CHANNEL_3
  *         @arg @ref FL_ATIM_CHANNEL_4
  * @param  TIM_ICInitStruct 指向需要将值设置为默认配置的结构体 @ref FL_ATIM_IC_InitTypeDef 结构体包含配置参数.
  * @retval None
  *         -FL_FAIL 配置过程发生错误
  *         -FL_PASS 成功
  */
static FL_ErrorStatus OCConfig(ATIM_Type *TIMx, uint32_t channel, FL_ATIM_OC_InitTypeDef *TIM_OC_InitStruct)
{
    FL_ErrorStatus result = FL_PASS;
    /* 配置比较输出通道模式 */
    FL_ATIM_OC_SetMode(TIMx, TIM_OC_InitStruct->OCMode, channel);
    /* 配置TRF清零使能 */
    if(TIM_OC_InitStruct->OCETRFStatus == FL_ENABLE)
    {
        FL_ATIM_OC_EnableClear(TIMx, channel);
    }
    else
    {
        FL_ATIM_OC_DisableClear(TIMx, channel);
    }
    /* 比较输出通道快速模式 */
    if(TIM_OC_InitStruct->OCFastMode == FL_ENABLE)
    {
        FL_ATIM_OC_EnableFastMode(TIMx, channel);
    }
    else
    {
        FL_ATIM_OC_DisableFastMode(TIMx, channel);
    }
    /* 比较输出通道缓冲模式 */
    if(TIM_OC_InitStruct->OCPreload == FL_ENABLE)
    {
        FL_ATIM_OC_EnablePreload(TIMx, channel);
    }
    else
    {
        FL_ATIM_OC_DisablePreload(TIMx, channel);
    }
    if(TIM_OC_InitStruct->OCNState == FL_ENABLE)
    {
        FL_ATIM_OC_EnableReverseChannel(TIMx, channel);
    }
    else
    {
        FL_ATIM_OC_DisableReverseChannel(TIMx, channel);
    }
    if(TIM_OC_InitStruct->OCState == FL_ENABLE)
    {
        /* 通道使能 */
        FL_ATIM_OC_EnableChannel(TIMx, channel);
    }
    else
    {
        FL_ATIM_OC_DisableChannel(TIMx, channel);
    }
    /* 设置比较值 */
    switch(channel)
    {
        case FL_ATIM_CHANNEL_1:
            FL_ATIM_WriteCompareCH1(TIMx, TIM_OC_InitStruct->compareValue);
            break;
        case FL_ATIM_CHANNEL_2:
            FL_ATIM_WriteCompareCH2(TIMx, TIM_OC_InitStruct->compareValue);
            break;
        case FL_ATIM_CHANNEL_3:
            FL_ATIM_WriteCompareCH3(TIMx, TIM_OC_InitStruct->compareValue);
            break;
        case FL_ATIM_CHANNEL_4:
            FL_ATIM_WriteCompareCH4(TIMx, TIM_OC_InitStruct->compareValue);
            break;
        default :
            result = FL_FAIL;
            break;
    }
    return result;
}
/**
  * @brief  配置TIM的比较输出通道.
  * @param  TIMx Timer Instance
  * @param  Channel This parameter can be one of the following values:
  *         @arg @ref FL_ATIM_CHANNEL_1
  *         @arg @ref FL_ATIM_CHANNEL_2
  *         @arg @ref FL_ATIM_CHANNEL_3
  *         @arg @ref FL_ATIM_CHANNEL_4
  * @retval TIM_OC_InitStruct pointer to a @ref FL_ATIM_OC_InitTypeDef structure
  *         -FL_FAIL 配置过程发生错误
  *         -FL_PASS 成功
  */
FL_ErrorStatus FL_ATIM_OC_Init(ATIM_Type *TIMx, uint32_t channel, FL_ATIM_OC_InitTypeDef *TIM_OC_InitStruct)
{
    uint32_t i = 5;
    FL_ErrorStatus result = FL_PASS;
    /* 参数检查 */
    assert_param(IS_ATIM_INSTANCE(TIMx));
    assert_param(IS_FL_ATIM_OC_MODE(TIM_OC_InitStruct->OCMode));
    assert_param(IS_FL_ATIM_OC_PRELOAD(TIM_OC_InitStruct->OCPreload));
    assert_param(IS_FL_ATIM_OC_POLARITY(TIM_OC_InitStruct->OCPolarity));
    assert_param(IS_FL_ATIM_OC_FASTMODE(TIM_OC_InitStruct->OCFastMode));
    assert_param(IS_FL_ATIM_OC_ETR_CLEARN(TIM_OC_InitStruct->OCETRFStatus));
    assert_param(IS_FL_ATIM_OCN_STATE(TIM_OC_InitStruct->OCNState));
    assert_param(IS_FL_ATIM_OC_STATE(TIM_OC_InitStruct->OCState));
    assert_param(IS_FL_ATIM_OC_IDLESTATE(TIM_OC_InitStruct->OCIdleState));
    assert_param(IS_FL_ATIM_OC_NIDLESTATE(TIM_OC_InitStruct->OCNIdleState));
    assert_param(IS_FL_ATIM_OC_NPOLARITY(TIM_OC_InitStruct->OCNPolarity));
    /* 通道关闭 */
    FL_ATIM_OC_DisableChannel(TIMx, channel);
    FL_ATIM_OC_DisableReverseChannel(TIMx, channel);
    /* 通道极性 */
    FL_ATIM_OC_SetChannelPolarity(TIMx, TIM_OC_InitStruct->OCPolarity, channel);
    /* 通道空闲电平 */
    FL_ATIM_OC_SetChannelIdleState(TIMx, TIM_OC_InitStruct->OCIdleState, channel);
    /* 互补通道空闲电平 */
    FL_ATIM_OC_SetReverseChannelIdleState(TIMx, TIM_OC_InitStruct->OCNIdleState, channel);
    /* 互补通道极性 */
    FL_ATIM_OC_SetReverseChannelPolarity(TIMx, TIM_OC_InitStruct->OCNPolarity, channel);
    /* 捕获映射到输出通道 */
    FL_ATIM_CC_SetChannelMode(TIMx, FL_ATIM_CHANNEL_MODE_OUTPUT, channel);
    /* 输出比较模式寄存器配置 */
    OCConfig(TIMx, channel, TIM_OC_InitStruct);
    /* 手动触发更新事件，将配置值写入 */
    FL_ATIM_GenerateUpdateEvent(TIMx);
    while((!FL_ATIM_IsActiveFlag_Update(ATIM))&&i)
    {
        i--;
    }
    /*清除UIF标志，防止产生UG事件中断*/
    FL_ATIM_ClearFlag_Update(ATIM);
    return result;
}

/**
  * @brief  设置 FL_ATIM_OC_InitTypeDef 为默认配置
  * @param  TIM_OC_InitStruct 指向需要将值设置为默认配置的结构体 @ref FL_ATIM_OC_InitTypeDef 结构体
  *
  * @retval None
  */
void FL_ATIM_OC_StructInit(FL_ATIM_OC_InitTypeDef *TIM_OC_InitStruct)
{
    /* Set the default configuration */
    TIM_OC_InitStruct->OCMode       = FL_ATIM_OC_MODE_FROZEN;
    TIM_OC_InitStruct->OCETRFStatus = FL_DISABLE;
    TIM_OC_InitStruct->OCFastMode   = FL_DISABLE;
    TIM_OC_InitStruct->compareValue = 0x00000000U;
    TIM_OC_InitStruct->OCPolarity   = FL_ATIM_OC_POLARITY_NORMAL;
    TIM_OC_InitStruct->OCPreload    = FL_DISABLE;
    TIM_OC_InitStruct->OCIdleState  = FL_ATIM_OC_IDLE_STATE_LOW;
    TIM_OC_InitStruct->OCNIdleState = FL_ATIM_OCN_IDLE_STATE_LOW;
    TIM_OC_InitStruct->OCNPolarity  = FL_ATIM_OCN_POLARITY_NORMAL;
    TIM_OC_InitStruct->OCNState     = FL_DISABLE;
}

/**
  * @brief  配置TIM的输入捕获通道.
  * @param  TIMx Timer Instance
  * @param  TIM_IC_InitStruct 指向一个 @ref FL_ATIM_IC_InitTypeDef 结构体
  * @retval  TIM_OC_InitStruct pointer to a @ref FL_ATIM_OC_InitTypeDef structure
  *         -FL_FAIL 配置过程发生错误
  *         -FL_PASS 成功
  */
FL_ErrorStatus FL_ATIM_BDTR_Init(ATIM_Type *TIMx, FL_ATIM_BDTR_InitTypeDef *TIM_BDTR_InitStruct)
{
    FL_ErrorStatus result = FL_PASS;
    /* 参数检查 */
    assert_param(IS_ATIM_INSTANCE(TIMx));
    assert_param(IS_FL_ATIM_OSSR_STATE(TIM_BDTR_InitStruct->OSSRState));
    assert_param(IS_FL_ATIM_OSSI_STATE(TIM_BDTR_InitStruct->OSSIState));
    assert_param(IS_FL_ATIM_LOCK_LEVEL(TIM_BDTR_InitStruct->lockLevel));
    assert_param(IS_FL_ATIM_BREAK_POLARITY(TIM_BDTR_InitStruct->breakPolarity));
    assert_param(IS_FL_ATIM_AUTOMATIC_OUTPUT_STATE(TIM_BDTR_InitStruct->automaticOutput));
    assert_param(IS_FL_ATIM_BDTR_FILTER(TIM_BDTR_InitStruct->breakFilter));
    /* 关闭所有输出 */
    FL_ATIM_DisableALLOutput(TIMx);
    /* 设置死区时间 */
    FL_ATIM_WriteDeadTime(TIMx, TIM_BDTR_InitStruct->deadTime);
    /* 设置寄存器锁定等级 */
    FL_ATIM_SetLockLevel(TIMx, TIM_BDTR_InitStruct->lockLevel);
    /* Idle状态下关闭状态 */
    FL_ATIM_SetOffStateIdle(TIMx, TIM_BDTR_InitStruct->OSSIState);
    /* run状态下关闭状态 */
    FL_ATIM_SetOffStateRun(TIMx, TIM_BDTR_InitStruct->OSSRState);
    /* 门控1刹车信号 */
    FL_ATIM_SetBreak1GateState(TIMx, TIM_BDTR_InitStruct->gatedBrakeSignal_1);
    /* 门控2刹车信号 */
    FL_ATIM_SetBreak2GateState(TIMx, TIM_BDTR_InitStruct->gatedBrakeSignal_2);
    /* 门控刹车信号组合方式设置  */
    FL_ATIM_SetBreakSignalCombination(TIMx, TIM_BDTR_InitStruct->brakeSignalCombined);
    /* 刹车极性设置 */
    FL_ATIM_SetBreakPolarity(TIMx, TIM_BDTR_InitStruct->breakPolarity);
    /* 更新时间自动设置输出配置，如果刹车事件发生过并且当前功能使能，则下一个更新事件将重新自动输出 */
    if(TIM_BDTR_InitStruct->automaticOutput == FL_ENABLE)
    {
        FL_ATIM_EnableAutomaticOutput(TIMx);
    }
    else
    {
        FL_ATIM_DisableAutomaticOutput(TIMx);
    }
    /* 刹车功能开关配置 */
    if(TIM_BDTR_InitStruct->breakState == FL_ENABLE)
    {
        FL_ATIM_EnableBreak(TIMx);
    }
    else
    {
        FL_ATIM_DisableBreak(TIMx);
    }
    /* 使能全部输出 */
    FL_ATIM_EnableALLOutput(TIMx);
    return result;
}

/**
  * @brief  设置 FL_ATIM_IC_InitTypeDef 为默认配置
  * @param  TIM_ICInitStruct 指向需要将值设置为默认配置的结构体 @ref FL_ATIM_IC_InitTypeDef 结构体
  *
  * @retval None
  */
void FL_ATIM_BDTR_StructInit(FL_ATIM_BDTR_InitTypeDef *TIM_BDTR_InitStruct)
{
    TIM_BDTR_InitStruct->deadTime            = 0x00;
    TIM_BDTR_InitStruct->lockLevel           = FL_ATIM_LOCK_LEVEL_OFF;
    TIM_BDTR_InitStruct->OSSRState           = FL_ATIM_OSSR_DISABLE;
    TIM_BDTR_InitStruct->OSSIState           = FL_ATIM_OSSI_DISABLE;
    TIM_BDTR_InitStruct->breakFilter         = FL_ATIM_BREAK_FILTER_DIV1;
    TIM_BDTR_InitStruct->breakPolarity       = FL_ATIM_BREAK_POLARITY_LOW;
    TIM_BDTR_InitStruct->automaticOutput     = FL_DISABLE;
    TIM_BDTR_InitStruct->gatedBrakeSignal_1  = FL_ATIM_BREAK1_GATE_AUTO;
    TIM_BDTR_InitStruct->gatedBrakeSignal_2  = FL_ATIM_BREAK2_GATE_AUTO;
    TIM_BDTR_InitStruct->breakState          = FL_DISABLE;
    TIM_BDTR_InitStruct->brakeSignalCombined = FL_ATIM_BREAK_COMBINATION_OR;
}

/**
  * @}
  */

#endif /* FL_ATIM_DRIVER_ENABLED */

/**
  * @}
  */

/**
  * @}
  */

/*************************(C) COPYRIGHT Fudan Microelectronics **** END OF FILE*************************/
