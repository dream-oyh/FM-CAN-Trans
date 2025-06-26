 /**    
  *******************************************************************************************************
  * @file    fm33fg0xxa_fl_adc.c
  * @author  FMSH Application Team
  * @brief   Source file of ADC FL Module
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

 /** @defgroup ADC ADC
  * @brief ADC FL driver
  * @{
  */
#ifdef FL_ADC_DRIVER_ENABLED

/* Private macros ------------------------------------------------------------*/
/** @addtogroup ADC_FL_Private_Macros
  * @{
  */
#define         IS_FL_ADC_INSTANCE(INSTANCE)                ((INSTANCE) == ADC)

#define         IS_FL_ADC_ADCCLK_SOURCE(__VALUE__)          (((__VALUE__) == FL_CMU_ADC_CLK_SOURCE_RCHF)||\
                                                            ((__VALUE__)  == FL_CMU_ADC_CLK_SOURCE_XTHF)||\
                                                            ((__VALUE__)  == FL_CMU_ADC_CLK_SOURCE_PLL)||\
                                                            ((__VALUE__) == FL_ADC_CLK_SOURCE_APBCLK))


#define         IS_FL_ADC_ADCCLK_PRESCALER(__VALUE__)       (((__VALUE__) == FL_CMU_ADC_PSC_DIV1)||\
                                                            ((__VALUE__) == FL_CMU_ADC_PSC_DIV2)||\
                                                            ((__VALUE__) == FL_CMU_ADC_PSC_DIV4)||\
                                                            ((__VALUE__) == FL_CMU_ADC_PSC_DIV8)||\
                                                            ((__VALUE__) == FL_CMU_ADC_PSC_DIV16)||\
                                                            ((__VALUE__) == FL_CMU_ADC_PSC_DIV32))


#define         IS_FL_ADC_APBCLK_PRESCALER(__VALUE__)       (((__VALUE__) == FL_ADC_APBCLK_PSC_DIV1)||\
                                                            ((__VALUE__) == FL_ADC_APBCLK_PSC_DIV2)||\
                                                            ((__VALUE__) == FL_ADC_APBCLK_PSC_DIV4)||\
                                                            ((__VALUE__) == FL_ADC_APBCLK_PSC_DIV8))


#define         IS_FL_ADC_ADC_REFERENCESOURCE(__VALUE__)    (((__VALUE__) == FL_ADC_REF_SOURCE_VDDA)||\
                                                            ((__VALUE__)  == FL_ADC_REF_SOURCE_VREFP))


#define         IS_FL_ADC_ADC_NEGATIVEREFERENCE(__VALUE__)  (((__VALUE__) == FL_ADC_REF_NEGA_VSSA)||\
                                                            ((__VALUE__)  == FL_ADC_REF_NEGA_VREFN))


#define         IS_FL_ADC_CONTINUOUSCONVMODE(__VALUE__)     (((__VALUE__) == FL_ADC_CONV_MODE_SINGLE)||\
                                                            ((__VALUE__) == FL_ADC_CONV_MODE_CONTINUOUS))

#define         IS_FL_ADC_AUTO_MODE(__VALUE__)              (((__VALUE__) == FL_ADC_SINGLE_CONV_MODE_AUTO)||\
                                                            ((__VALUE__) == FL_ADC_SINGLE_CONV_MODE_SEMIAUTO))


#define         IS_FL_ADC_SCANDIRECTION(__VALUE__)          (((__VALUE__) == FL_ADC_SEQ_SCAN_DIR_FORWARD)||\
                                                            ((__VALUE__) == FL_ADC_SEQ_SCAN_DIR_BACKWARD))


#define         IS_FL_ADC_EXTERNALTRIGCONV(__VALUE__)       (((__VALUE__) == FL_ADC_RGTRIGGER_EDGE_NONE)||\
                                                            ((__VALUE__) == FL_ADC_RGTRIGGER_EDGE_RISING)||\
                                                            ((__VALUE__) == FL_ADC_RGTRIGGER_EDGE_FALLING)||\
                                                            ((__VALUE__) == FL_ADC_RGTRIGGER_EDGE_BOTH))

#define         IS_FL_ADC_EXTERNALTRIGSOURCE(__VALUE__)     (((__VALUE__) == FL_ADC_TRGI_ATIM)||\
                                                            ((__VALUE__) == FL_ADC_TRGI_TAU10)||\
                                                            ((__VALUE__) == FL_ADC_TRGI_TAU11)||\
                                                            ((__VALUE__) == FL_ADC_TRGI_TAU12)||\
                                                            ((__VALUE__) == FL_ADC_TRGI_GPTIM1)||\
                                                            ((__VALUE__) == FL_ADC_TRGI_GPTIM2)||\
                                                            ((__VALUE__) == FL_ADC_TRGI_BSTIM16)||\
                                                            ((__VALUE__) == FL_ADC_TRGI_LPTIM16)||\
                                                            ((__VALUE__) == FL_ADC_TRGI_COMP1)||\
                                                            ((__VALUE__) == FL_ADC_TRGI_COMP2)||\
                                                            ((__VALUE__) == FL_ADC_TRGI_RTCA)||\
                                                            ((__VALUE__) == FL_ADC_TRGI_TAU00)||\
                                                            ((__VALUE__) == FL_ADC_TRGI_TAU01)||\
                                                            ((__VALUE__) == FL_ADC_TRGI_TAU02)||\
                                                            ((__VALUE__) == FL_ADC_TRGI_TAU03)||\
                                                            ((__VALUE__) == FL_ADC_TRGI_LUT0))

#define         IS_FL_ADC_CHANNEL_FAST_TIME(__VALUE__)      (((__VALUE__) == FL_ADC_FAST_CH_SAMPLING_TIME_2_ADCCLK)||\
                                                            ((__VALUE__) == FL_ADC_FAST_CH_SAMPLING_TIME_4_ADCCLK)||\
                                                            ((__VALUE__) == FL_ADC_FAST_CH_SAMPLING_TIME_8_ADCCLK)||\
                                                            ((__VALUE__) == FL_ADC_FAST_CH_SAMPLING_TIME_16_ADCCLK)||\
                                                            ((__VALUE__) == FL_ADC_FAST_CH_SAMPLING_TIME_32_ADCCLK)||\
                                                            ((__VALUE__) == FL_ADC_FAST_CH_SAMPLING_TIME_64_ADCCLK)||\
                                                            ((__VALUE__) == FL_ADC_FAST_CH_SAMPLING_TIME_80_ADCCLK)||\
                                                            ((__VALUE__) == FL_ADC_FAST_CH_SAMPLING_TIME_96_ADCCLK)||\
                                                            ((__VALUE__) == FL_ADC_FAST_CH_SAMPLING_TIME_128_ADCCLK)||\
                                                            ((__VALUE__) == FL_ADC_FAST_CH_SAMPLING_TIME_160_ADCCLK)||\
                                                            ((__VALUE__) == FL_ADC_FAST_CH_SAMPLING_TIME_192_ADCCLK)||\
                                                            ((__VALUE__) == FL_ADC_FAST_CH_SAMPLING_TIME_256_ADCCLK)||\
                                                            ((__VALUE__) == FL_ADC_FAST_CH_SAMPLING_TIME_320_ADCCLK)||\
                                                            ((__VALUE__) == FL_ADC_FAST_CH_SAMPLING_TIME_384_ADCCLK)||\
                                                            ((__VALUE__) == FL_ADC_FAST_CH_SAMPLING_TIME_512_ADCCLK))

#define         IS_FL_ADC_CHANNEL_SLOW_TIME(__VALUE__)      (((__VALUE__) == FL_ADC_SLOW_CH_SAMPLING_TIME_2_ADCCLK)||\
                                                            ((__VALUE__) == FL_ADC_SLOW_CH_SAMPLING_TIME_4_ADCCLK)||\
                                                            ((__VALUE__) == FL_ADC_SLOW_CH_SAMPLING_TIME_8_ADCCLK)||\
                                                            ((__VALUE__) == FL_ADC_SLOW_CH_SAMPLING_TIME_16_ADCCLK)||\
                                                            ((__VALUE__) == FL_ADC_SLOW_CH_SAMPLING_TIME_32_ADCCLK)||\
                                                            ((__VALUE__) == FL_ADC_SLOW_CH_SAMPLING_TIME_64_ADCCLK)||\
                                                            ((__VALUE__) == FL_ADC_SLOW_CH_SAMPLING_TIME_80_ADCCLK)||\
                                                            ((__VALUE__) == FL_ADC_SLOW_CH_SAMPLING_TIME_96_ADCCLK)||\
                                                            ((__VALUE__) == FL_ADC_SLOW_CH_SAMPLING_TIME_128_ADCCLK)||\
                                                            ((__VALUE__) == FL_ADC_SLOW_CH_SAMPLING_TIME_160_ADCCLK)||\
                                                            ((__VALUE__) == FL_ADC_SLOW_CH_SAMPLING_TIME_192_ADCCLK)||\
                                                            ((__VALUE__) == FL_ADC_SLOW_CH_SAMPLING_TIME_256_ADCCLK)||\
                                                            ((__VALUE__) == FL_ADC_SLOW_CH_SAMPLING_TIME_320_ADCCLK)||\
                                                            ((__VALUE__) == FL_ADC_SLOW_CH_SAMPLING_TIME_384_ADCCLK)||\
                                                            ((__VALUE__) == FL_ADC_SLOW_CH_SAMPLING_TIME_512_ADCCLK))

#define         IS_FL_ADC_OVERSAMPCOFIG(__VALUE__)          (((__VALUE__) == FL_DISABLE)||\
                                                            ((__VALUE__) == FL_ENABLE))

#define         IS_FL_ADC_OVERSAMPINGRATIO(__VALUE__)       (((__VALUE__) == FL_ADC_OVERSAMPLING_MUL_2X)||\
                                                            ((__VALUE__) == FL_ADC_OVERSAMPLING_MUL_4X)||\
                                                            ((__VALUE__) == FL_ADC_OVERSAMPLING_MUL_8X)||\
                                                            ((__VALUE__) == FL_ADC_OVERSAMPLING_MUL_16X)||\
                                                            ((__VALUE__) == FL_ADC_OVERSAMPLING_MUL_32X)||\
                                                            ((__VALUE__) == FL_ADC_OVERSAMPLING_MUL_64X)||\
                                                            ((__VALUE__) == FL_ADC_OVERSAMPLING_MUL_128X)||\
                                                            ((__VALUE__) == FL_ADC_OVERSAMPLING_MUL_256X))

#define         IS_FL_ADC_OVERSAMPINGSHIFT(__VALUE__)       (((__VALUE__) == FL_ADC_OVERSAMPLING_SHIFT_0B)||\
                                                            ((__VALUE__) == FL_ADC_OVERSAMPLING_SHIFT_1B)||\
                                                            ((__VALUE__) == FL_ADC_OVERSAMPLING_SHIFT_2B)||\
                                                            ((__VALUE__) == FL_ADC_OVERSAMPLING_SHIFT_3B)||\
                                                            ((__VALUE__) == FL_ADC_OVERSAMPLING_SHIFT_4B)||\
                                                            ((__VALUE__) == FL_ADC_OVERSAMPLING_SHIFT_5B)||\
                                                            ((__VALUE__) == FL_ADC_OVERSAMPLING_SHIFT_6B)||\
                                                            ((__VALUE__) == FL_ADC_OVERSAMPLING_SHIFT_7B)||\
                                                            ((__VALUE__) == FL_ADC_OVERSAMPLING_SHIFT_8B))

#define         ADC_CALIBRATIN_TIME_OUT                     (500000)
/**
  * @}
  */
/** @addtogroup ADC_FL_EF_Init
  * @{
  */
/**
  * @brief  恢复ADC公用寄存器到复位值
  * @param  None
  * @retval 执行结果
  *         -FL_PASS ADC公用寄存器值恢复复位值
  *         -FL_FAIL 未成功执行
  */
FL_ErrorStatus FL_ADC_CommonDeInit(void)
{
    /* 关闭总线时钟 */
    FL_CMU_DisableGroup2BusClock(FL_CMU_GROUP2_BUSCLK_ADC);
    /* 关闭工作时钟 */
    FL_CMU_DisableOperationClock(FL_CMU_OPCLK_ADC);
    return FL_PASS;
}

/**
  * @brief  配置ADC公用寄存器
  * @param  ADC_CommonInitStruct 指向 @ref FL_ADC_CommonInitTypeDef 的结构体，它包含ADC公用寄存器的配置信息
  * @retval 执行结果
  *         -FL_FAIL 配置过程发生错误
  *         -FL_PASS ADC公用寄存器配置成功
  */
FL_ErrorStatus FL_ADC_CommonInit(FL_ADC_CommonInitTypeDef *ADC_CommonInitStruct)
{
    FL_ErrorStatus status = FL_PASS;
    /* 入口参数检查 */
    assert_param(IS_FL_ADC_ADCCLK_SOURCE(ADC_CommonInitStruct->clockSource));
    assert_param(IS_FL_ADC_ADC_REFERENCESOURCE(ADC_CommonInitStruct->referenceSource));
    assert_param(IS_FL_ADC_ADC_NEGATIVEREFERENCE(ADC_CommonInitStruct->negativeReferenceSource));
    if(ADC_CommonInitStruct->clockSource == FL_ADC_CLK_SOURCE_APBCLK)
    {
        assert_param(IS_FL_ADC_APBCLK_PRESCALER(ADC_CommonInitStruct->clockPrescaler));
    }
    else
    {
        assert_param(IS_FL_ADC_ADCCLK_PRESCALER(ADC_CommonInitStruct->clockPrescaler));
    }
    /* 开启总线时钟 */
    FL_CMU_EnableGroup2BusClock(FL_CMU_GROUP2_BUSCLK_ADC);

    /* 配置ADC时钟 */
    if(ADC_CommonInitStruct->clockSource == FL_ADC_CLK_SOURCE_APBCLK)
    {
        /* 设置ADC时钟来源于APBCLK */
        FL_ADC_SetClockSource(ADC, FL_ADC_CLK_SOURCE_APBCLK);
        
        /* 配置APBCLOCK时钟预分频 */
        FL_ADC_SetAPBPrescaler(ADC, ADC_CommonInitStruct->clockPrescaler);
    }
    else
    {
        /* 设置ADC时钟来源于ADCCLK */
        FL_ADC_SetClockSource(ADC, FL_ADC_CLK_SOURCE_ADCCLK);
        
        /* 设置ADCCLK时钟源 */
        FL_CMU_SetADCClockSource(ADC_CommonInitStruct->clockSource);
        
        /* 配置ADCCLK时钟预分频 */
        FL_CMU_SetADCPrescaler(ADC_CommonInitStruct->clockPrescaler);
        
        /* 开启操作时钟 */
        FL_CMU_EnableOperationClock(FL_CMU_OPCLK_ADC);
    }
    /* 配置ADC正基准 */
    FL_ADC_SetReferenceSource(ADC,ADC_CommonInitStruct->referenceSource);
    /* 配置ADC负基准 */
    FL_ADC_SetNegativePeference(ADC,ADC_CommonInitStruct->negativeReferenceSource);
    return status;
}
/**
  * @brief  初始化 @ref FL_ADC_CommonInitTypeDef 配置结构体
  * @param  ADC_CommonInitStruct 指向需要初始化的 @ref FL_ADC_CommonInitTypeDef 结构体
  * @retval None
  */
void FL_ADC_CommonStructInit(FL_ADC_CommonInitTypeDef *ADC_CommonInitStruct)
{
    /*默认使用RCHF作为ADC时钟模块时钟源，预分频系数16*/
    ADC_CommonInitStruct->clockSource     = FL_CMU_ADC_CLK_SOURCE_RCHF;
    ADC_CommonInitStruct->clockPrescaler  = FL_CMU_ADC_PSC_DIV16;
}

/**
  * @brief  恢复ADC外设寄存器到复位值
  * @param  ADCx  外设入口地址
  * @retval 执行结果
  *         -FL_PASS ADC外设寄存器值恢复复位值
  *         -FL_FAIL 未成功执行
  */
FL_ErrorStatus FL_ADC_DeInit(ADC_Type *ADCx)
{
    FL_ErrorStatus status = FL_PASS;
    /* 入口合法性检查 */
    assert_param(IS_FL_ADC_INSTANCE(ADCx));
    /* 外设复位使能 */
    FL_RMU_EnablePeripheralReset(RMU);
    FL_RMU_EnableResetAPBPeripheral(RMU,FL_RMU_RSTAPB_ADC);
    FL_RMU_DisableResetAPBPeripheral(RMU,FL_RMU_RSTAPB_ADC);
    FL_RMU_EnableResetAPBPeripheral(RMU,FL_RMU_RSTAPB_ADCCR);
    FL_RMU_DisableResetAPBPeripheral(RMU,FL_RMU_RSTAPB_ADCCR);
    FL_RMU_DisablePeripheralReset(RMU);
    return status;
}

/**
  * @brief  配置指定的ADC外设
  * @note   用户必须检查此函数的返回值，以确保自校准完成，否则转换结果精度无法保证，除此之外ADC使能过采样实际不会增加ADC的
  *         转换精度只会提高转换结果的稳定性（同时配置移位寄存器的情况下），同时过采样会降低转换速度。
  * @param  ADCx  外设入口地址
  * @param  ADC_InitStruct 指向 @ref FL_ADC_InitTypeDef 的结构体，它包含ADC外设寄存器的配置信息
  * @retval 执行结果
  *         -FL_FAIL 配置过程发生错误
  *         -FL_PASS ADC外设寄存器配置成功
  */
FL_ErrorStatus FL_ADC_Init(ADC_Type *ADCx, FL_ADC_InitTypeDef  *ADC_InitStruct)
{
    FL_ErrorStatus status = FL_PASS;
    uint32_t i = 0, Calibration_Flag;
    /* 入口合法性检查 */
    assert_param(IS_FL_ADC_INSTANCE(ADCx));
    assert_param(IS_FL_ADC_CONTINUOUSCONVMODE(ADC_InitStruct->conversionMode));
    assert_param(IS_FL_ADC_AUTO_MODE(ADC_InitStruct->autoMode));
    assert_param(IS_FL_ADC_SCANDIRECTION(ADC_InitStruct->scanDirection));
    assert_param(IS_FL_ADC_EXTERNALTRIGCONV(ADC_InitStruct->externalTrigConv));
    assert_param(IS_FL_ADC_OVERSAMPCOFIG(ADC_InitStruct->oversamplingMode));
    assert_param(IS_FL_ADC_OVERSAMPINGRATIO(ADC_InitStruct->overSampingMultiplier));
    assert_param(IS_FL_ADC_OVERSAMPINGSHIFT(ADC_InitStruct->oversamplingShift));
    FL_PMU_EnableTemperatureSensor(PMU);
    FL_ADC_Disable(ADCx);
    FL_ADC_DisableOverSampling(ADCx);
    FL_ADC_Enable(ADCx);
    FL_ADC_EnableInternalSequencerChannel(ADC,FL_ADC_INTERNAL_AVREF);
    FL_ADC_EnableCalibration(ADC);
    i = 0;
    do
    {
        Calibration_Flag = FL_ADC_IsActiveFlag_EndOfCalibration(ADC);
        i++;
    } while((i != 0xFFFFFFFFU) && (Calibration_Flag == 0U));           //等待转换完成
    if(Calibration_Flag == 0x01)
    {
        FL_ADC_ClearFlag_EndOfCalibration(ADC);
        FL_ADC_DisableInternalSequencerChannel(ADC,FL_ADC_INTERNAL_AVREF);
        /* 关闭ADC，关闭后ADC自校准值依然保持 */
        FL_ADC_Disable(ADCx);
        if(FL_ADC_IsEnabled(ADCx) == 0U)
        {
            /* 连续转换模式 */
            FL_ADC_SetConversionMode(ADCx, ADC_InitStruct->conversionMode);
            /* 自动转换模式 */
            FL_ADC_SetSingleConversionAutoMode(ADCx, ADC_InitStruct->autoMode);
            /* 通道等待使能 */
            if(ADC_InitStruct->waitMode)
            {
                FL_ADC_EnableWaitMode(ADCx);
            }
            else
            {
                FL_ADC_DisableWaitMode(ADCx);
            }
            /*数据冲突模式设置*/
            if(ADC_InitStruct->overrunMode)
            {
                FL_ADC_EnableOverrunMode(ADCx);
            }
            else
            {
                FL_ADC_DisableOverrunMode(ADCx);
            }
            /* 多通道扫描方向 */
            FL_ADC_SetSequenceScanDirection(ADCx, ADC_InitStruct->scanDirection);
            /* 触发模式 */
            FL_ADC_SetRegularGroupTriggerEdge(ADCx, ADC_InitStruct->externalTrigConv);
            /* 触发源 */
            FL_ADC_SetTriggerSource(ADCx, ADC_InitStruct->triggerSource);
            /*通道采样时间设置*/
            FL_ADC_SetFastChannelSamplingTime(ADCx, ADC_InitStruct->fastChannelTime);
            FL_ADC_SetSlowChannelSamplingTime(ADCx, ADC_InitStruct->lowChannelTime);
            if(ADC_InitStruct->oversamplingMode)
            {
                /*使能过采样倍数后，需要配置移位寄存器进行移位，这一过程是硬件自动完成的最终最大
                可输出16位的结果值（即256被采样得到的结果是20bit的，右移4bit结果就是16bit的）*/
                FL_ADC_SetOverSamplingMultiplier(ADCx, ADC_InitStruct->overSampingMultiplier);
                FL_ADC_SetOverSamplingShift(ADCx, ADC_InitStruct->oversamplingShift);
                /* 过采样使能 */
                FL_ADC_EnableOverSampling(ADCx);
            }
            else
            {
                /* 关闭过采样 */
                FL_ADC_DisableOverSampling(ADCx);
            }
        }
        else
        {
            status = FL_FAIL;
        }
    }
    else
    {
        status = FL_FAIL;
    }
    return status;
}

/**
  * @brief  初始化 @ref FL_ADC_InitTypeDef 配置结构体
  * @param  ADC_InitStruct 指向需要初始化的 @ref FL_ADC_InitTypeDef 结构体
  * @retval None
  */
void FL_ADC_StructInit(FL_ADC_InitTypeDef *ADC_InitStruct)
{
    ADC_InitStruct->conversionMode              = FL_ADC_CONV_MODE_SINGLE;
    ADC_InitStruct->autoMode                    = FL_ADC_SINGLE_CONV_MODE_AUTO;
    ADC_InitStruct->scanDirection               = FL_ADC_SEQ_SCAN_DIR_FORWARD;
    ADC_InitStruct->externalTrigConv            = FL_ADC_RGTRIGGER_EDGE_NONE;
    ADC_InitStruct->overrunMode                 = FL_ENABLE;
    ADC_InitStruct->waitMode                    = FL_ENABLE;
    ADC_InitStruct->fastChannelTime             = FL_ADC_FAST_CH_SAMPLING_TIME_2_ADCCLK;
    ADC_InitStruct->lowChannelTime              = FL_ADC_SLOW_CH_SAMPLING_TIME_512_ADCCLK;
    ADC_InitStruct->oversamplingMode            = FL_ENABLE;
    ADC_InitStruct->overSampingMultiplier       = FL_ADC_OVERSAMPLING_MUL_16X;
    ADC_InitStruct->oversamplingShift           = FL_ADC_OVERSAMPLING_SHIFT_4B;
}

#endif



/**
  * @}
  */
/**
  * @}
  */
/*************************************************************END OF FILE************************************************************/



