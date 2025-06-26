 /**    
  *******************************************************************************************************
  * @file    fm33fg0xx_fl_adc.h
  * @author  FMSH Application Team
  * @brief   Head file of ADC FL Module
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
#ifndef __FM33FG0XX_FL_ADC_H
#define __FM33FG0XX_FL_ADC_H

#ifdef __cplusplus
extern "C" {
#endif
/* Includes -------------------------------------------------------------------------------------------*/
#include "fm33fg0xxa_fl_def.h"
/** @addtogroup FM33FG0XXA_FL_Driver
  * @{
  */

/** @defgroup ADC ADC
  * @brief ADC FL driver
  * @{
  */
/* Exported types -------------------------------------------------------------------------------------*/
/** @defgroup ADC_FL_ES_INIT ADC Exported Init structures
  * @{
  */
/*VREF1P0电压值*/
#define ADC_VREF_SOURCE     (*((uint32_t *)(0x1FFFFB0C)))   /* VREF1P0电压初始值 (*10000) */
#define ADC_VREF_BAK        (*((uint32_t *)(0x1FFFFBF4)))   /* VREF1P0电压备份值 (*10000) */
#define ADC_VREF            (LDT_CHECK(ADC_VREF_SOURCE, ADC_VREF_BAK) & 0xFFFFU)   /* VREF1P0电压值 (*10000) */

#define ADC_PTAT            (*((uint16_t *)0x1FFFFB10)) 
#define ADC_PTAT_BACKUP     (*((uint16_t *)0x1FFFFBE0)) 
#define ADC_TS              (((ADC_PTAT != 0x0U) && (ADC_PTAT != 0xFFFFU)) ? ADC_PTAT : ADC_PTAT_BACKUP) 

/**
  * @brief ADC Common Init Structure Definition
  */
typedef  struct
{
    /* ADCCLK源选择 */
    uint32_t clockSource;
    /* ADCCLK分频 */
    uint32_t clockPrescaler;
    /* ADC正基准 */
    uint32_t referenceSource;
    /* ADC负基准 */
    uint32_t negativeReferenceSource;
} FL_ADC_CommonInitTypeDef;

typedef struct
{
    /*连续转换模式配置*/
    uint32_t conversionMode;
    /*单次自动转换模式配置*/
    uint32_t autoMode;
    /*等待模式配置*/
    FL_FunState waitMode;
    /*覆盖模式配置*/
    FL_FunState overrunMode;
    /*通道扫描顺序配置*/
    uint32_t scanDirection;
    /*触发信号使能配置*/
    uint32_t externalTrigConv;
    /*触发源选择*/
    uint32_t triggerSource;
    /*快速通道采样时间配置*/
    uint32_t fastChannelTime;
    /*慢速通道采样时间配置*/
    uint32_t lowChannelTime;
    /*过采样使能配置*/
    FL_FunState oversamplingMode;
    /*过采样率配置*/
    uint32_t overSampingMultiplier;
    /*过采样移位配置*/
    uint32_t oversamplingShift;
}FL_ADC_InitTypeDef;

/**
  * @}
  */
/* Exported constants ---------------------------------------------------------------------------------*/
/** @defgroup ADC_FL_Exported_Constants ADC Exported Constants
  * @{
  */

#define    ADC_ISR_EOC_Pos                                        (0U)
#define    ADC_ISR_EOC_Msk                                        (0x1U << ADC_ISR_EOC_Pos)
#define    ADC_ISR_EOC                                            ADC_ISR_EOC_Msk

#define    ADC_ISR_EOS_Pos                                        (1U)
#define    ADC_ISR_EOS_Msk                                        (0x1U << ADC_ISR_EOS_Pos)
#define    ADC_ISR_EOS                                            ADC_ISR_EOS_Msk

#define    ADC_ISR_OVR_Pos                                        (2U)
#define    ADC_ISR_OVR_Msk                                        (0x1U << ADC_ISR_OVR_Pos)
#define    ADC_ISR_OVR                                            ADC_ISR_OVR_Msk

#define    ADC_ISR_BUSY_Pos                                       (3U)
#define    ADC_ISR_BUSY_Msk                                       (0x1U << ADC_ISR_BUSY_Pos)
#define    ADC_ISR_BUSY                                           ADC_ISR_BUSY_Msk

#define    ADC_ISR_EOCAL_Pos                                      (4U)
#define    ADC_ISR_EOCAL_Msk                                      (0x1U << ADC_ISR_EOCAL_Pos)
#define    ADC_ISR_EOCAL                                          ADC_ISR_EOCAL_Msk

#define    ADC_ISR_AWD_UL_Pos                                     (5U)
#define    ADC_ISR_AWD_UL_Msk                                     (0x1U << ADC_ISR_AWD_UL_Pos)
#define    ADC_ISR_AWD_UL                                         ADC_ISR_AWD_UL_Msk

#define    ADC_ISR_AWD_AH_Pos                                     (6U)
#define    ADC_ISR_AWD_AH_Msk                                     (0x1U << ADC_ISR_AWD_AH_Pos)
#define    ADC_ISR_AWD_AH                                         ADC_ISR_AWD_AH_Msk

#define    ADC_IER_EOCIE_Pos                                      (0U)
#define    ADC_IER_EOCIE_Msk                                      (0x1U << ADC_IER_EOCIE_Pos)
#define    ADC_IER_EOCIE                                          ADC_IER_EOCIE_Msk

#define    ADC_IER_EOSIE_Pos                                      (1U)
#define    ADC_IER_EOSIE_Msk                                      (0x1U << ADC_IER_EOSIE_Pos)
#define    ADC_IER_EOSIE                                          ADC_IER_EOSIE_Msk

#define    ADC_IER_OVRIE_Pos                                      (2U)
#define    ADC_IER_OVRIE_Msk                                      (0x1U << ADC_IER_OVRIE_Pos)
#define    ADC_IER_OVRIE                                          ADC_IER_OVRIE_Msk

#define    ADC_IER_EOCALIE_Pos                                    (4U)
#define    ADC_IER_EOCALIE_Msk                                    (0x1U << ADC_IER_EOCALIE_Pos)
#define    ADC_IER_EOCALIE                                        ADC_IER_EOCALIE_Msk

#define    ADC_IER_AWD_ULIE_Pos                                   (5U)
#define    ADC_IER_AWD_ULIE_Msk                                   (0x1U << ADC_IER_AWD_ULIE_Pos)
#define    ADC_IER_AWD_ULIE                                       ADC_IER_AWD_ULIE_Msk

#define    ADC_IER_AWD_AHIE_Pos                                   (6U)
#define    ADC_IER_AWD_AHIE_Msk                                   (0x1U << ADC_IER_AWD_AHIE_Pos)
#define    ADC_IER_AWD_AHIE                                       ADC_IER_AWD_AHIE_Msk

#define    ADC_CR1_ADEN_Pos                                       (0U)
#define    ADC_CR1_ADEN_Msk                                       (0x1U << ADC_CR1_ADEN_Pos)
#define    ADC_CR1_ADEN                                           ADC_CR1_ADEN_Msk

#define    ADC_CR1_RSTART_Pos                                     (1U)
#define    ADC_CR1_RSTART_Msk                                     (0x1U << ADC_CR1_RSTART_Pos)
#define    ADC_CR1_RSTART                                         ADC_CR1_RSTART_Msk

#define    ADC_CR1_JSTART_Pos                                     (2U)
#define    ADC_CR1_JSTART_Msk                                     (0x1U << ADC_CR1_JSTART_Pos)
#define    ADC_CR1_JSTART                                         ADC_CR1_JSTART_Msk

#define    ADC_CR1_RSTOP_Pos                                      (3U)
#define    ADC_CR1_RSTOP_Msk                                      (0x1U << ADC_CR1_RSTOP_Pos)
#define    ADC_CR1_RSTOP                                          ADC_CR1_RSTOP_Msk

#define    ADC_CR1_JSTOP_Pos                                      (4U)
#define    ADC_CR1_JSTOP_Msk                                      (0x1U << ADC_CR1_JSTOP_Pos)
#define    ADC_CR1_JSTOP                                          ADC_CR1_JSTOP_Msk

#define    ADC_CR2_RTRGCFG_Pos                                    (0U)
#define    ADC_CR2_RTRGCFG_Msk                                    (0x3U << ADC_CR2_RTRGCFG_Pos)
#define    ADC_CR2_RTRGCFG                                        ADC_CR2_RTRGCFG_Msk

#define    ADC_CR2_JTRGCFG_Pos                                    (2U)
#define    ADC_CR2_JTRGCFG_Msk                                    (0x3U << ADC_CR2_JTRGCFG_Pos)
#define    ADC_CR2_JTRGCFG                                        ADC_CR2_JTRGCFG_Msk

#define    ADC_CALR_CALEN_Pos                                     (0U)
#define    ADC_CALR_CALEN_Msk                                     (0x1U << ADC_CALR_CALEN_Pos)
#define    ADC_CALR_CALEN                                         ADC_CALR_CALEN_Msk

#define    ADC_CALR_CKDIG_DELAY_Pos                               (1U)
#define    ADC_CALR_CKDIG_DELAY_Msk                               (0x3U << ADC_CALR_CKDIG_DELAY_Pos)
#define    ADC_CALR_CKDIG_DELAY                                   ADC_CALR_CKDIG_DELAY_Msk

#define    ADC_CALR_CMP_MODE_Pos                                  (3U)
#define    ADC_CALR_CMP_MODE_Msk                                  (0x1U << ADC_CALR_CMP_MODE_Pos)
#define    ADC_CALR_CMP_MODE                                      ADC_CALR_CMP_MODE_Msk

#define    ADC_CALR_CMPRDY_DELAY_Pos                              (4U)
#define    ADC_CALR_CMPRDY_DELAY_Msk                              (0x3U << ADC_CALR_CMPRDY_DELAY_Pos)
#define    ADC_CALR_CMPRDY_DELAY                                  ADC_CALR_CMPRDY_DELAY_Msk

#define    ADC_CALR_VCM_MODE_Pos                                  (6U)
#define    ADC_CALR_VCM_MODE_Msk                                  (0x1U << ADC_CALR_VCM_MODE_Pos)
#define    ADC_CALR_VCM_MODE                                      ADC_CALR_VCM_MODE_Msk

#define    ADC_CALR_VCM_CTRL_Pos                                  (7U)
#define    ADC_CALR_VCM_CTRL_Msk                                  (0x1U << ADC_CALR_VCM_CTRL_Pos)
#define    ADC_CALR_VCM_CTRL                                      ADC_CALR_VCM_CTRL_Msk

#define    ADC_CALR_OFFL_EN_Pos                                   (12U)
#define    ADC_CALR_OFFL_EN_Msk                                   (0x1U << ADC_CALR_OFFL_EN_Pos)
#define    ADC_CALR_OFFL_EN                                       ADC_CALR_OFFL_EN_Msk

#define    ADC_CALR_OSCAL_CYCLE_Pos                               (16U)
#define    ADC_CALR_OSCAL_CYCLE_Msk                               (0xffU << ADC_CALR_OSCAL_CYCLE_Pos)
#define    ADC_CALR_OSCAL_CYCLE                                   ADC_CALR_OSCAL_CYCLE_Msk

#define    ADC_CFGR1_PEFSEL_Pos                                   (0U)
#define    ADC_CFGR1_PEFSEL_Msk                                   (0x1U << ADC_CFGR1_PEFSEL_Pos)
#define    ADC_CFGR1_PEFSEL                                       ADC_CFGR1_PEFSEL_Msk

#define    ADC_CFGR1_CLKSEL_Pos                                   (2U)
#define    ADC_CFGR1_CLKSEL_Msk                                   (0x1U << ADC_CFGR1_CLKSEL_Pos)
#define    ADC_CFGR1_CLKSEL                                       ADC_CFGR1_CLKSEL_Msk

#define    ADC_CFGR1_BITSEL_Pos                                   (3U)
#define    ADC_CFGR1_BITSEL_Msk                                   (0x3U << ADC_CFGR1_BITSEL_Pos)
#define    ADC_CFGR1_BITSEL                                       ADC_CFGR1_BITSEL_Msk

#define    ADC_CFGR1_APBCLK_PSC_Pos                               (6U)
#define    ADC_CFGR1_APBCLK_PSC_Msk                               (0x3U << ADC_CFGR1_APBCLK_PSC_Pos)
#define    ADC_CFGR1_APBCLK_PSC                                   ADC_CFGR1_APBCLK_PSC_Msk

#define    ADC_CFGR1_REFNSEL_Pos                                  (8U)
#define    ADC_CFGR1_REFNSEL_Msk                                  (0x1U << ADC_CFGR1_REFNSEL_Pos)
#define    ADC_CFGR1_REFNSEL                                      ADC_CFGR1_REFNSEL_Msk

#define    ADC_CFGR2_DMAEN_Pos                                    (0U)
#define    ADC_CFGR2_DMAEN_Msk                                    (0x1U << ADC_CFGR2_DMAEN_Pos)
#define    ADC_CFGR2_DMAEN                                        ADC_CFGR2_DMAEN_Msk

#define    ADC_CFGR2_SCANDIR_Pos                                  (2U)
#define    ADC_CFGR2_SCANDIR_Msk                                  (0x1U << ADC_CFGR2_SCANDIR_Pos)
#define    ADC_CFGR2_SCANDIR                                      ADC_CFGR2_SCANDIR_Msk

#define    ADC_CFGR2_EXTS_Pos                                     (4U)
#define    ADC_CFGR2_EXTS_Msk                                     (0xfU << ADC_CFGR2_EXTS_Pos)
#define    ADC_CFGR2_EXTS                                         ADC_CFGR2_EXTS_Msk

#define    ADC_CFGR2_OVRM_Pos                                     (8U)
#define    ADC_CFGR2_OVRM_Msk                                     (0x1U << ADC_CFGR2_OVRM_Pos)
#define    ADC_CFGR2_OVRM                                         ADC_CFGR2_OVRM_Msk

#define    ADC_CFGR2_CONT_Pos                                     (9U)
#define    ADC_CFGR2_CONT_Msk                                     (0x1U << ADC_CFGR2_CONT_Pos)
#define    ADC_CFGR2_CONT                                         ADC_CFGR2_CONT_Msk

#define    ADC_CFGR2_WAIT_Pos                                     (10U)
#define    ADC_CFGR2_WAIT_Msk                                     (0x1U << ADC_CFGR2_WAIT_Pos)
#define    ADC_CFGR2_WAIT                                         ADC_CFGR2_WAIT_Msk

#define    ADC_CFGR2_SEMI_Pos                                     (11U)
#define    ADC_CFGR2_SEMI_Msk                                     (0x1U << ADC_CFGR2_SEMI_Pos)
#define    ADC_CFGR2_SEMI                                         ADC_CFGR2_SEMI_Msk

#define    ADC_CFGR2_IOTRFEN_Pos                                  (14U)
#define    ADC_CFGR2_IOTRFEN_Msk                                  (0x1U << ADC_CFGR2_IOTRFEN_Pos)
#define    ADC_CFGR2_IOTRFEN                                      ADC_CFGR2_IOTRFEN_Msk

#define    ADC_CFGR2_OVSEN_Pos                                    (16U)
#define    ADC_CFGR2_OVSEN_Msk                                    (0x1U << ADC_CFGR2_OVSEN_Pos)
#define    ADC_CFGR2_OVSEN                                        ADC_CFGR2_OVSEN_Msk

#define    ADC_CFGR2_OVSR_Pos                                     (17U)
#define    ADC_CFGR2_OVSR_Msk                                     (0x7U << ADC_CFGR2_OVSR_Pos)
#define    ADC_CFGR2_OVSR                                         ADC_CFGR2_OVSR_Msk

#define    ADC_CFGR2_OVSS_Pos                                     (20U)
#define    ADC_CFGR2_OVSS_Msk                                     (0xfU << ADC_CFGR2_OVSS_Pos)
#define    ADC_CFGR2_OVSS                                         ADC_CFGR2_OVSS_Msk

#define    ADC_CFGR2_AWDEN_Pos                                    (24U)
#define    ADC_CFGR2_AWDEN_Msk                                    (0x1U << ADC_CFGR2_AWDEN_Pos)
#define    ADC_CFGR2_AWDEN                                        ADC_CFGR2_AWDEN_Msk

#define    ADC_CFGR2_AWDSC_Pos                                    (25U)
#define    ADC_CFGR2_AWDSC_Msk                                    (0x1U << ADC_CFGR2_AWDSC_Pos)
#define    ADC_CFGR2_AWDSC                                        ADC_CFGR2_AWDSC_Msk

#define    ADC_CFGR2_AWDCH_Pos                                    (26U)
#define    ADC_CFGR2_AWDCH_Msk                                    (0x1fU << ADC_CFGR2_AWDCH_Pos)
#define    ADC_CFGR2_AWDCH                                        ADC_CFGR2_AWDCH_Msk

#define    ADC_SMTR_SMTS1_Pos                                     (0U)
#define    ADC_SMTR_SMTS1_Msk                                     (0xfU << ADC_SMTR_SMTS1_Pos)
#define    ADC_SMTR_SMTS1                                         ADC_SMTR_SMTS1_Msk

#define    ADC_SMTR_SMTS2_Pos                                     (4U)
#define    ADC_SMTR_SMTS2_Msk                                     (0xfU << ADC_SMTR_SMTS2_Pos)
#define    ADC_SMTR_SMTS2                                         ADC_SMTR_SMTS2_Msk

#define    ADC_DR_DATA_Pos                                        (0U)
#define    ADC_DR_DATA_Msk                                        (0xffffU << ADC_DR_DATA_Pos)
#define    ADC_DR_DATA                                            ADC_DR_DATA_Msk

#define    ADC_DR_CHID_Pos                                        (24U)
#define    ADC_DR_CHID_Msk                                        (0x3fU << ADC_DR_CHID_Pos)
#define    ADC_DR_CHID                                            ADC_DR_CHID_Msk

#define    ADC_HLTR_AWD_LT_Pos                                    (0U)
#define    ADC_HLTR_AWD_LT_Msk                                    (0xffffU << ADC_HLTR_AWD_LT_Pos)
#define    ADC_HLTR_AWD_LT                                        ADC_HLTR_AWD_LT_Msk

#define    ADC_HLTR_AWD_HT_Pos                                    (16U)
#define    ADC_HLTR_AWD_HT_Msk                                    (0xffffU << ADC_HLTR_AWD_HT_Pos)
#define    ADC_HLTR_AWD_HT                                        ADC_HLTR_AWD_HT_Msk

#define    ADC_JGCFGR_JEXTS_Pos                                   (0U)
#define    ADC_JGCFGR_JEXTS_Msk                                   (0xfU << ADC_JGCFGR_JEXTS_Pos)
#define    ADC_JGCFGR_JEXTS                                       ADC_JGCFGR_JEXTS_Msk

#define    ADC_JGCFGR_JMOD_Pos                                    (7U)
#define    ADC_JGCFGR_JMOD_Msk                                    (0x1U << ADC_JGCFGR_JMOD_Pos)
#define    ADC_JGCFGR_JMOD                                        ADC_JGCFGR_JMOD_Msk

#define    ADC_JGCFGR_JL_Pos                                      (8U)
#define    ADC_JGCFGR_JL_Msk                                      (0x7U << ADC_JGCFGR_JL_Pos)
#define    ADC_JGCFGR_JL                                          ADC_JGCFGR_JL_Msk

#define    ADC_JCFGR_JSEL0_Pos                                    (0U)
#define    ADC_JCFGR_JSEL0_Msk                                    (0xfU << ADC_JCFGR_JSEL0_Pos)
#define    ADC_JCFGR_JSEL0                                        ADC_JCFGR_JSEL0_Msk

#define    ADC_JCFGR_JSEL1_Pos                                    (4U)
#define    ADC_JCFGR_JSEL1_Msk                                    (0xfU << ADC_JCFGR_JSEL1_Pos)
#define    ADC_JCFGR_JSEL1                                        ADC_JCFGR_JSEL1_Msk

#define    ADC_JCFGR_JOVS0_Pos                                    (8U)
#define    ADC_JCFGR_JOVS0_Msk                                    (0x1U << ADC_JCFGR_JOVS0_Pos)
#define    ADC_JCFGR_JOVS0                                        ADC_JCFGR_JOVS0_Msk

#define    ADC_JCFGR_JOVSR0_Pos                                   (9U)
#define    ADC_JCFGR_JOVSR0_Msk                                   (0x3U << ADC_JCFGR_JOVSR0_Pos)
#define    ADC_JCFGR_JOVSR0                                       ADC_JCFGR_JOVSR0_Msk

#define    ADC_JCFGR_JSEL0_4_Pos                                  (11U)
#define    ADC_JCFGR_JSEL0_4_Msk                                  (0x1U << ADC_JCFGR_JSEL0_4_Pos)
#define    ADC_JCFGR_JSEL0_4                                      ADC_JCFGR_JSEL0_4_Msk

#define    ADC_JCFGR_JOVS1_Pos                                    (12U)
#define    ADC_JCFGR_JOVS1_Msk                                    (0x1U << ADC_JCFGR_JOVS1_Pos)
#define    ADC_JCFGR_JOVS1                                        ADC_JCFGR_JOVS1_Msk

#define    ADC_JCFGR_JOVSR1_Pos                                   (13U)
#define    ADC_JCFGR_JOVSR1_Msk                                   (0x3U << ADC_JCFGR_JOVSR1_Pos)
#define    ADC_JCFGR_JOVSR1                                       ADC_JCFGR_JOVSR1_Msk

#define    ADC_JCFGR_JSEL1_4_Pos                                  (15U)
#define    ADC_JCFGR_JSEL1_4_Msk                                  (0x1U << ADC_JCFGR_JSEL1_4_Pos)
#define    ADC_JCFGR_JSEL1_4                                      ADC_JCFGR_JSEL1_4_Msk

#define    ADC_JCFGR_JSEL2_Pos                                    (16U)
#define    ADC_JCFGR_JSEL2_Msk                                    (0xfU << ADC_JCFGR_JSEL2_Pos)
#define    ADC_JCFGR_JSEL2                                        ADC_JCFGR_JSEL2_Msk

#define    ADC_JCFGR_JSEL3_Pos                                    (20U)
#define    ADC_JCFGR_JSEL3_Msk                                    (0xfU << ADC_JCFGR_JSEL3_Pos)
#define    ADC_JCFGR_JSEL3                                        ADC_JCFGR_JSEL3_Msk

#define    ADC_JCFGR_JOVS2_Pos                                    (24U)
#define    ADC_JCFGR_JOVS2_Msk                                    (0x1U << ADC_JCFGR_JOVS2_Pos)
#define    ADC_JCFGR_JOVS2                                        ADC_JCFGR_JOVS2_Msk

#define    ADC_JCFGR_JOVSR2_Pos                                   (25U)
#define    ADC_JCFGR_JOVSR2_Msk                                   (0x3U << ADC_JCFGR_JOVSR2_Pos)
#define    ADC_JCFGR_JOVSR2                                       ADC_JCFGR_JOVSR2_Msk

#define    ADC_JCFGR_JSEL2_4_Pos                                  (27U)
#define    ADC_JCFGR_JSEL2_4_Msk                                  (0x1U << ADC_JCFGR_JSEL2_4_Pos)
#define    ADC_JCFGR_JSEL2_4                                      ADC_JCFGR_JSEL2_4_Msk

#define    ADC_JCFGR_JOVS3_Pos                                    (28U)
#define    ADC_JCFGR_JOVS3_Msk                                    (0x1U << ADC_JCFGR_JOVS3_Pos)
#define    ADC_JCFGR_JOVS3                                        ADC_JCFGR_JOVS3_Msk

#define    ADC_JCFGR_JOVSR3_Pos                                   (29U)
#define    ADC_JCFGR_JOVSR3_Msk                                   (0x3U << ADC_JCFGR_JOVSR3_Pos)
#define    ADC_JCFGR_JOVSR3                                       ADC_JCFGR_JOVSR3_Msk

#define    ADC_JCFGR_JSEL3_4_Pos                                  (31U)
#define    ADC_JCFGR_JSEL3_4_Msk                                  (0x1U << ADC_JCFGR_JSEL3_4_Pos)
#define    ADC_JCFGR_JSEL3_4                                      ADC_JCFGR_JSEL3_4_Msk

#define    ADC_JDR0_JDATA0_Pos                                    (0U)
#define    ADC_JDR0_JDATA0_Msk                                    (0xfffU << ADC_JDR0_JDATA0_Pos)
#define    ADC_JDR0_JDATA0                                        ADC_JDR0_JDATA0_Msk

#define    ADC_JDR1_JDATA1_Pos                                    (0U)
#define    ADC_JDR1_JDATA1_Msk                                    (0xfffU << ADC_JDR1_JDATA1_Pos)
#define    ADC_JDR1_JDATA1                                        ADC_JDR1_JDATA1_Msk

#define    ADC_JDR2_JDATA2_Pos                                    (0U)
#define    ADC_JDR2_JDATA2_Msk                                    (0xfffU << ADC_JDR2_JDATA2_Pos)
#define    ADC_JDR2_JDATA2                                        ADC_JDR2_JDATA2_Msk

#define    ADC_JDR3_JDATA3_Pos                                    (0U)
#define    ADC_JDR3_JDATA3_Msk                                    (0xfffU << ADC_JDR3_JDATA3_Pos)
#define    ADC_JDR3_JDATA3                                        ADC_JDR3_JDATA3_Msk

#define    ADC_RAWR_RAWD_Pos                                      (0U)
#define    ADC_RAWR_RAWD_Msk                                      (0x1fffU << ADC_RAWR_RAWD_Pos)
#define    ADC_RAWR_RAWD                                          ADC_RAWR_RAWD_Msk



#define    FL_ADC_EXTERNAL_CH0                                    (0x1U << 0U)
#define    FL_ADC_EXTERNAL_CH1                                    (0x1U << 1U)
#define    FL_ADC_EXTERNAL_CH2                                    (0x1U << 2U)
#define    FL_ADC_EXTERNAL_CH3                                    (0x1U << 3U)
#define    FL_ADC_EXTERNAL_CH4                                    (0x1U << 4U)
#define    FL_ADC_EXTERNAL_CH5                                    (0x1U << 5U)
#define    FL_ADC_EXTERNAL_CH6                                    (0x1U << 6U)
#define    FL_ADC_EXTERNAL_CH7                                    (0x1U << 7U)
#define    FL_ADC_EXTERNAL_CH8                                    (0x1U << 8U)
#define    FL_ADC_EXTERNAL_CH9                                    (0x1U << 9U)
#define    FL_ADC_EXTERNAL_CH10                                   (0x1U << 10U)
#define    FL_ADC_EXTERNAL_CH11                                   (0x1U << 11U)
#define    FL_ADC_EXTERNAL_CH12                                   (0x1U << 12U)
#define    FL_ADC_EXTERNAL_CH13                                   (0x1U << 13U)
#define    FL_ADC_EXTERNAL_CH14                                   (0x1U << 14U)
#define    FL_ADC_EXTERNAL_CH15                                   (0x1U << 15U)
#define    FL_ADC_EXTERNAL_CH16                                   (0x1U << 16U)
#define    FL_ADC_EXTERNAL_CH17                                   (0x1U << 17U)
#define    FL_ADC_EXTERNAL_CH18                                   (0x1U << 18U)
#define    FL_ADC_EXTERNAL_CH19                                   (0x1U << 19U)
#define    FL_ADC_EXTERNAL_CH20                                   (0x1U << 20U)
#define    FL_ADC_EXTERNAL_CH21                                   (0x1U << 21U)
#define    FL_ADC_EXTERNAL_CH22                                   (0x1U << 22U)
#define    FL_ADC_EXTERNAL_CH23                                   (0x1U << 23U)
#define    FL_ADC_EXTERNAL_CH24                                   (0x1U << 24U)
#define    FL_ADC_EXTERNAL_CH25                                   (0x1U << 25U)
#define    FL_ADC_EXTERNAL_CH26                                   (0x1U << 26U)
#define    FL_ADC_EXTERNAL_CH27                                   (0x1U << 27U)
#define    FL_ADC_EXTERNAL_CH28                                   (0x1U << 28U)
#define    FL_ADC_EXTERNAL_CH29                                   (0x1U << 29U)
#define    FL_ADC_EXTERNAL_CH30                                   (0x1U << 30U)
#define    FL_ADC_INTERNAL_TS                                     (0x1U << 0U)
#define    FL_ADC_INTERNAL_AVREF                                  (0x1U << 1U)
#define    FL_ADC_INTERNAL_DAC                                    (0x1U << 2U)



#define    FL_ADC_RGTRIGGER_EDGE_NONE                             (0x0U << ADC_CR2_RTRGCFG_Pos)
#define    FL_ADC_RGTRIGGER_EDGE_RISING                           (0x1U << ADC_CR2_RTRGCFG_Pos)
#define    FL_ADC_RGTRIGGER_EDGE_FALLING                          (0x2U << ADC_CR2_RTRGCFG_Pos)
#define    FL_ADC_RGTRIGGER_EDGE_BOTH                             (0x3U << ADC_CR2_RTRGCFG_Pos)


#define    FL_ADC_JGTRIGGER_EDGE_NONE                             (0x0U << ADC_CR2_JTRGCFG_Pos)
#define    FL_ADC_JGTRIGGER_EDGE_RISING                           (0x1U << ADC_CR2_JTRGCFG_Pos)
#define    FL_ADC_JGTRIGGER_EDGE_FALLING                          (0x2U << ADC_CR2_JTRGCFG_Pos)
#define    FL_ADC_JGTRIGGER_EDGE_BOTH                             (0x3U << ADC_CR2_JTRGCFG_Pos)


#define    FL_ADC_CKDIG_DELAY_MIN                                 (0x0U << ADC_CALR_CKDIG_DELAY_Pos)
#define    FL_ADC_CKDIG_DELAY_MAX                                 (0x3U << ADC_CALR_CKDIG_DELAY_Pos)


#define    FL_ADC_CMP_MODE_Normal                                 (0x0U << ADC_CALR_CMP_MODE_Pos)
#define    FL_ADC_CMP_MODE_Fast                                   (0x1U << ADC_CALR_CMP_MODE_Pos)


#define    FL_ADC_CMP_DELAY_MIN                                   (0x0U << ADC_CALR_CMPRDY_DELAY_Pos)
#define    FL_ADC_CMP_DELAY_MAX                                   (0x3U << ADC_CALR_CMPRDY_DELAY_Pos)


#define    FL_ADC_VCM_MODE_NORMAL                                 (0x0U << ADC_CALR_VCM_MODE_Pos)
#define    FL_ADC_VCM_MODE_CONTINUOUS                             (0x1U << ADC_CALR_VCM_MODE_Pos)


#define    FL_ADC_CALIBRA_AUTO                                    (0x0U << ADC_CALR_OFFL_EN_Pos)
#define    FL_ADC_CALIBRA_OFFLINE                                 (0x1U << ADC_CALR_OFFL_EN_Pos)


#define    FL_ADC_REF_SOURCE_VDDA                                 (0x0U << ADC_CFGR1_PEFSEL_Pos)
#define    FL_ADC_REF_SOURCE_VREFP                                (0x1U << ADC_CFGR1_PEFSEL_Pos)


#define    FL_ADC_CLK_SOURCE_ADCCLK                               (0x0U << ADC_CFGR1_CLKSEL_Pos)
#define    FL_ADC_CLK_SOURCE_APBCLK                               (0x1U << ADC_CFGR1_CLKSEL_Pos)


#define    FL_ADC_BIT_WIDTH_12B                                   (0x0U << ADC_CFGR1_BITSEL_Pos)
#define    FL_ADC_BIT_WIDTH_10B                                   (0x1U << ADC_CFGR1_BITSEL_Pos)
#define    FL_ADC_BIT_WIDTH_8B                                    (0x2U << ADC_CFGR1_BITSEL_Pos)
#define    FL_ADC_BIT_WIDTH_6B                                    (0x3U << ADC_CFGR1_BITSEL_Pos)


#define    FL_ADC_APBCLK_PSC_DIV1                                 (0x0U << ADC_CFGR1_APBCLK_PSC_Pos)
#define    FL_ADC_APBCLK_PSC_DIV2                                 (0x1U << ADC_CFGR1_APBCLK_PSC_Pos)
#define    FL_ADC_APBCLK_PSC_DIV4                                 (0x2U << ADC_CFGR1_APBCLK_PSC_Pos)
#define    FL_ADC_APBCLK_PSC_DIV8                                 (0x3U << ADC_CFGR1_APBCLK_PSC_Pos)


#define    FL_ADC_REF_NEGA_VSSA                                   (0x0U << ADC_CFGR1_REFNSEL_Pos)
#define    FL_ADC_REF_NEGA_VREFN                                  (0x1U << ADC_CFGR1_REFNSEL_Pos)


#define    FL_ADC_SEQ_SCAN_DIR_FORWARD                            (0x0U << ADC_CFGR2_SCANDIR_Pos)
#define    FL_ADC_SEQ_SCAN_DIR_BACKWARD                           (0x1U << ADC_CFGR2_SCANDIR_Pos)


#define    FL_ADC_TRGI_ATIM                                       (0x0U << ADC_CFGR2_EXTS_Pos)
#define    FL_ADC_TRGI_TAU10                                      (0x1U << ADC_CFGR2_EXTS_Pos)
#define    FL_ADC_TRGI_TAU11                                      (0x2U << ADC_CFGR2_EXTS_Pos)
#define    FL_ADC_TRGI_TAU12                                      (0x3U << ADC_CFGR2_EXTS_Pos)
#define    FL_ADC_TRGI_GPTIM1                                     (0x4U << ADC_CFGR2_EXTS_Pos)
#define    FL_ADC_TRGI_GPTIM2                                     (0x5U << ADC_CFGR2_EXTS_Pos)
#define    FL_ADC_TRGI_BSTIM16                                    (0x6U << ADC_CFGR2_EXTS_Pos)
#define    FL_ADC_TRGI_LPTIM16                                    (0x7U << ADC_CFGR2_EXTS_Pos)
#define    FL_ADC_TRGI_COMP1                                      (0x8U << ADC_CFGR2_EXTS_Pos)
#define    FL_ADC_TRGI_COMP2                                      (0x9U << ADC_CFGR2_EXTS_Pos)
#define    FL_ADC_TRGI_RTCA                                       (0xaU << ADC_CFGR2_EXTS_Pos)
#define    FL_ADC_TRGI_TAU00                                      (0xbU << ADC_CFGR2_EXTS_Pos)
#define    FL_ADC_TRGI_TAU01                                      (0xcU << ADC_CFGR2_EXTS_Pos)
#define    FL_ADC_TRGI_TAU02                                      (0xdU << ADC_CFGR2_EXTS_Pos)
#define    FL_ADC_TRGI_TAU03                                      (0xeU << ADC_CFGR2_EXTS_Pos)
#define    FL_ADC_TRGI_LUT0                                       (0xfU << ADC_CFGR2_EXTS_Pos)


#define    FL_ADC_CONV_MODE_SINGLE                                (0x0U << ADC_CFGR2_CONT_Pos)
#define    FL_ADC_CONV_MODE_CONTINUOUS                            (0x1U << ADC_CFGR2_CONT_Pos)


#define    FL_ADC_SINGLE_CONV_MODE_AUTO                           (0x0U << ADC_CFGR2_SEMI_Pos)
#define    FL_ADC_SINGLE_CONV_MODE_SEMIAUTO                       (0x1U << ADC_CFGR2_SEMI_Pos)


#define    FL_ADC_OVERSAMPLING_MUL_2X                             (0x0U << ADC_CFGR2_OVSR_Pos)
#define    FL_ADC_OVERSAMPLING_MUL_4X                             (0x1U << ADC_CFGR2_OVSR_Pos)
#define    FL_ADC_OVERSAMPLING_MUL_8X                             (0x2U << ADC_CFGR2_OVSR_Pos)
#define    FL_ADC_OVERSAMPLING_MUL_16X                            (0x3U << ADC_CFGR2_OVSR_Pos)
#define    FL_ADC_OVERSAMPLING_MUL_32X                            (0x4U << ADC_CFGR2_OVSR_Pos)
#define    FL_ADC_OVERSAMPLING_MUL_64X                            (0x5U << ADC_CFGR2_OVSR_Pos)
#define    FL_ADC_OVERSAMPLING_MUL_128X                           (0x6U << ADC_CFGR2_OVSR_Pos)
#define    FL_ADC_OVERSAMPLING_MUL_256X                           (0x7U << ADC_CFGR2_OVSR_Pos)


#define    FL_ADC_OVERSAMPLING_SHIFT_0B                           (0x0U << ADC_CFGR2_OVSS_Pos)
#define    FL_ADC_OVERSAMPLING_SHIFT_1B                           (0x1U << ADC_CFGR2_OVSS_Pos)
#define    FL_ADC_OVERSAMPLING_SHIFT_2B                           (0x2U << ADC_CFGR2_OVSS_Pos)
#define    FL_ADC_OVERSAMPLING_SHIFT_3B                           (0x3U << ADC_CFGR2_OVSS_Pos)
#define    FL_ADC_OVERSAMPLING_SHIFT_4B                           (0x4U << ADC_CFGR2_OVSS_Pos)
#define    FL_ADC_OVERSAMPLING_SHIFT_5B                           (0x5U << ADC_CFGR2_OVSS_Pos)
#define    FL_ADC_OVERSAMPLING_SHIFT_6B                           (0x6U << ADC_CFGR2_OVSS_Pos)
#define    FL_ADC_OVERSAMPLING_SHIFT_7B                           (0x7U << ADC_CFGR2_OVSS_Pos)
#define    FL_ADC_OVERSAMPLING_SHIFT_8B                           (0x8U << ADC_CFGR2_OVSS_Pos)


#define    FL_ADC_AWDG_ALL_CHANNEL                                (0x0U << ADC_CFGR2_AWDSC_Pos)
#define    FL_ADC_AWDG_SINGLE_CHANNEL                             (0x1U << ADC_CFGR2_AWDSC_Pos)


#define    FL_ADC_AWDG_CH0                                        (0x0U << ADC_CFGR2_AWDCH_Pos)
#define    FL_ADC_AWDG_CH1                                        (0x1U << ADC_CFGR2_AWDCH_Pos)
#define    FL_ADC_AWDG_CH2                                        (0x2U << ADC_CFGR2_AWDCH_Pos)
#define    FL_ADC_AWDG_CH3                                        (0x3U << ADC_CFGR2_AWDCH_Pos)
#define    FL_ADC_AWDG_CH4                                        (0x4U << ADC_CFGR2_AWDCH_Pos)
#define    FL_ADC_AWDG_CH5                                        (0x5U << ADC_CFGR2_AWDCH_Pos)
#define    FL_ADC_AWDG_CH6                                        (0x6U << ADC_CFGR2_AWDCH_Pos)
#define    FL_ADC_AWDG_CH7                                        (0x7U << ADC_CFGR2_AWDCH_Pos)
#define    FL_ADC_AWDG_CH8                                        (0x8U << ADC_CFGR2_AWDCH_Pos)
#define    FL_ADC_AWDG_CH9                                        (0x9U << ADC_CFGR2_AWDCH_Pos)
#define    FL_ADC_AWDG_CH10                                       (0xaU << ADC_CFGR2_AWDCH_Pos)
#define    FL_ADC_AWDG_CH11                                       (0xbU << ADC_CFGR2_AWDCH_Pos)
#define    FL_ADC_AWDG_CH12                                       (0xcU << ADC_CFGR2_AWDCH_Pos)
#define    FL_ADC_AWDG_CH13                                       (0xdU << ADC_CFGR2_AWDCH_Pos)
#define    FL_ADC_AWDG_CH14                                       (0xeU << ADC_CFGR2_AWDCH_Pos)
#define    FL_ADC_AWDG_CH15                                       (0xfU << ADC_CFGR2_AWDCH_Pos)
#define    FL_ADC_AWDG_CH16                                       (0x10U << ADC_CFGR2_AWDCH_Pos)
#define    FL_ADC_AWDG_CH17                                       (0x11U << ADC_CFGR2_AWDCH_Pos)
#define    FL_ADC_AWDG_CH18                                       (0x12U << ADC_CFGR2_AWDCH_Pos)
#define    FL_ADC_AWDG_CH19                                       (0x13U << ADC_CFGR2_AWDCH_Pos)
#define    FL_ADC_AWDG_CH20                                       (0x14U << ADC_CFGR2_AWDCH_Pos)
#define    FL_ADC_AWDG_CH21                                       (0x15U << ADC_CFGR2_AWDCH_Pos)
#define    FL_ADC_AWDG_CH22                                       (0x16U << ADC_CFGR2_AWDCH_Pos)
#define    FL_ADC_AWDG_CH23                                       (0x17U << ADC_CFGR2_AWDCH_Pos)
#define    FL_ADC_AWDG_CH24                                       (0x18U << ADC_CFGR2_AWDCH_Pos)
#define    FL_ADC_AWDG_CH25                                       (0x19U << ADC_CFGR2_AWDCH_Pos)
#define    FL_ADC_AWDG_CH26                                       (0x1aU << ADC_CFGR2_AWDCH_Pos)
#define    FL_ADC_AWDG_CH27                                       (0x1bU << ADC_CFGR2_AWDCH_Pos)
#define    FL_ADC_AWDG_CH28                                       (0x1cU << ADC_CFGR2_AWDCH_Pos)
#define    FL_ADC_AWDG_CH29                                       (0x1dU << ADC_CFGR2_AWDCH_Pos)
#define    FL_ADC_AWDG_CH30                                       (0x1eU << ADC_CFGR2_AWDCH_Pos)


#define    FL_ADC_SLOW_CH_SAMPLING_TIME_2_ADCCLK                  (0x0U << ADC_SMTR_SMTS1_Pos)
#define    FL_ADC_SLOW_CH_SAMPLING_TIME_4_ADCCLK                  (0x1U << ADC_SMTR_SMTS1_Pos)
#define    FL_ADC_SLOW_CH_SAMPLING_TIME_8_ADCCLK                  (0x2U << ADC_SMTR_SMTS1_Pos)
#define    FL_ADC_SLOW_CH_SAMPLING_TIME_12_ADCCLK                 (0x3U << ADC_SMTR_SMTS1_Pos)
#define    FL_ADC_SLOW_CH_SAMPLING_TIME_16_ADCCLK                 (0x4U << ADC_SMTR_SMTS1_Pos)
#define    FL_ADC_SLOW_CH_SAMPLING_TIME_32_ADCCLK                 (0x5U << ADC_SMTR_SMTS1_Pos)
#define    FL_ADC_SLOW_CH_SAMPLING_TIME_64_ADCCLK                 (0x6U << ADC_SMTR_SMTS1_Pos)
#define    FL_ADC_SLOW_CH_SAMPLING_TIME_80_ADCCLK                 (0x7U << ADC_SMTR_SMTS1_Pos)
#define    FL_ADC_SLOW_CH_SAMPLING_TIME_96_ADCCLK                 (0x8U << ADC_SMTR_SMTS1_Pos)
#define    FL_ADC_SLOW_CH_SAMPLING_TIME_128_ADCCLK                (0x9U << ADC_SMTR_SMTS1_Pos)
#define    FL_ADC_SLOW_CH_SAMPLING_TIME_160_ADCCLK                (0xaU << ADC_SMTR_SMTS1_Pos)
#define    FL_ADC_SLOW_CH_SAMPLING_TIME_192_ADCCLK                (0xbU << ADC_SMTR_SMTS1_Pos)
#define    FL_ADC_SLOW_CH_SAMPLING_TIME_256_ADCCLK                (0xcU << ADC_SMTR_SMTS1_Pos)
#define    FL_ADC_SLOW_CH_SAMPLING_TIME_320_ADCCLK                (0xdU << ADC_SMTR_SMTS1_Pos)
#define    FL_ADC_SLOW_CH_SAMPLING_TIME_384_ADCCLK                (0xeU << ADC_SMTR_SMTS1_Pos)
#define    FL_ADC_SLOW_CH_SAMPLING_TIME_512_ADCCLK                (0xfU << ADC_SMTR_SMTS1_Pos)


#define    FL_ADC_FAST_CH_SAMPLING_TIME_2_ADCCLK                  (0x0U << ADC_SMTR_SMTS2_Pos)
#define    FL_ADC_FAST_CH_SAMPLING_TIME_4_ADCCLK                  (0x1U << ADC_SMTR_SMTS2_Pos)
#define    FL_ADC_FAST_CH_SAMPLING_TIME_8_ADCCLK                  (0x2U << ADC_SMTR_SMTS2_Pos)
#define    FL_ADC_FAST_CH_SAMPLING_TIME_12_ADCCLK                 (0x3U << ADC_SMTR_SMTS2_Pos)
#define    FL_ADC_FAST_CH_SAMPLING_TIME_16_ADCCLK                 (0x4U << ADC_SMTR_SMTS2_Pos)
#define    FL_ADC_FAST_CH_SAMPLING_TIME_32_ADCCLK                 (0x5U << ADC_SMTR_SMTS2_Pos)
#define    FL_ADC_FAST_CH_SAMPLING_TIME_64_ADCCLK                 (0x6U << ADC_SMTR_SMTS2_Pos)
#define    FL_ADC_FAST_CH_SAMPLING_TIME_80_ADCCLK                 (0x7U << ADC_SMTR_SMTS2_Pos)
#define    FL_ADC_FAST_CH_SAMPLING_TIME_96_ADCCLK                 (0x8U << ADC_SMTR_SMTS2_Pos)
#define    FL_ADC_FAST_CH_SAMPLING_TIME_128_ADCCLK                (0x9U << ADC_SMTR_SMTS2_Pos)
#define    FL_ADC_FAST_CH_SAMPLING_TIME_160_ADCCLK                (0xaU << ADC_SMTR_SMTS2_Pos)
#define    FL_ADC_FAST_CH_SAMPLING_TIME_192_ADCCLK                (0xbU << ADC_SMTR_SMTS2_Pos)
#define    FL_ADC_FAST_CH_SAMPLING_TIME_256_ADCCLK                (0xcU << ADC_SMTR_SMTS2_Pos)
#define    FL_ADC_FAST_CH_SAMPLING_TIME_320_ADCCLK                (0xdU << ADC_SMTR_SMTS2_Pos)
#define    FL_ADC_FAST_CH_SAMPLING_TIME_384_ADCCLK                (0xeU << ADC_SMTR_SMTS2_Pos)
#define    FL_ADC_FAST_CH_SAMPLING_TIME_512_ADCCLK                (0xfU << ADC_SMTR_SMTS2_Pos)


#define    FL_ADC_CONV_CHANNEL_CH0                                (0x0U << ADC_DR_CHID_Pos)
#define    FL_ADC_CONV_CHANNEL_CH1                                (0x1U << ADC_DR_CHID_Pos)
#define    FL_ADC_CONV_CHANNEL_CH2                                (0x2U << ADC_DR_CHID_Pos)
#define    FL_ADC_CONV_CHANNEL_CH3                                (0x3U << ADC_DR_CHID_Pos)
#define    FL_ADC_CONV_CHANNEL_CH4                                (0x4U << ADC_DR_CHID_Pos)
#define    FL_ADC_CONV_CHANNEL_CH5                                (0x5U << ADC_DR_CHID_Pos)
#define    FL_ADC_CONV_CHANNEL_CH6                                (0x6U << ADC_DR_CHID_Pos)
#define    FL_ADC_CONV_CHANNEL_CH7                                (0x7U << ADC_DR_CHID_Pos)
#define    FL_ADC_CONV_CHANNEL_CH8                                (0x8U << ADC_DR_CHID_Pos)
#define    FL_ADC_CONV_CHANNEL_CH9                                (0x9U << ADC_DR_CHID_Pos)
#define    FL_ADC_CONV_CHANNEL_CH10                               (0xaU << ADC_DR_CHID_Pos)
#define    FL_ADC_CONV_CHANNEL_CH11                               (0xbU << ADC_DR_CHID_Pos)
#define    FL_ADC_CONV_CHANNEL_CH12                               (0xcU << ADC_DR_CHID_Pos)
#define    FL_ADC_CONV_CHANNEL_CH13                               (0xdU << ADC_DR_CHID_Pos)
#define    FL_ADC_CONV_CHANNEL_CH14                               (0xeU << ADC_DR_CHID_Pos)
#define    FL_ADC_CONV_CHANNEL_CH15                               (0xfU << ADC_DR_CHID_Pos)
#define    FL_ADC_CONV_CHANNEL_CH16                               (0x10U << ADC_DR_CHID_Pos)
#define    FL_ADC_CONV_CHANNEL_CH17                               (0x11U << ADC_DR_CHID_Pos)
#define    FL_ADC_CONV_CHANNEL_CH18                               (0x12U << ADC_DR_CHID_Pos)
#define    FL_ADC_CONV_CHANNEL_CH19                               (0x13U << ADC_DR_CHID_Pos)
#define    FL_ADC_CONV_CHANNEL_CH20                               (0x14U << ADC_DR_CHID_Pos)
#define    FL_ADC_CONV_CHANNEL_CH21                               (0x15U << ADC_DR_CHID_Pos)
#define    FL_ADC_CONV_CHANNEL_CH22                               (0x16U << ADC_DR_CHID_Pos)
#define    FL_ADC_CONV_CHANNEL_CH23                               (0x17U << ADC_DR_CHID_Pos)
#define    FL_ADC_CONV_CHANNEL_CH24                               (0x18U << ADC_DR_CHID_Pos)
#define    FL_ADC_CONV_CHANNEL_CH25                               (0x19U << ADC_DR_CHID_Pos)
#define    FL_ADC_CONV_CHANNEL_CH26                               (0x1aU << ADC_DR_CHID_Pos)
#define    FL_ADC_CONV_CHANNEL_CH27                               (0x1bU << ADC_DR_CHID_Pos)
#define    FL_ADC_CONV_CHANNEL_CH28                               (0x1cU << ADC_DR_CHID_Pos)
#define    FL_ADC_CONV_CHANNEL_CH29                               (0x1dU << ADC_DR_CHID_Pos)
#define    FL_ADC_CONV_CHANNEL_CH30                               (0x1eU << ADC_DR_CHID_Pos)
#define    FL_ADC_CONV_CHANNEL_TS                                 (0x1fU << ADC_DR_CHID_Pos)
#define    FL_ADC_CONV_CHANNEL_AVREF                              (0x20U << ADC_DR_CHID_Pos)
#define    FL_ADC_CONV_CHANNEL_DAC                                (0x21U << ADC_DR_CHID_Pos)

#define    FL_ADC_JG_EXTS_ATIM_TRGO                               (0x0U << ADC_JGCFGR_JEXTS_Pos)
#define    FL_ADC_JG_EXTS_TAU10_TRGO                              (0x1U << ADC_JGCFGR_JEXTS_Pos)
#define    FL_ADC_JG_EXTS_TAU11_TRGO                              (0x2U << ADC_JGCFGR_JEXTS_Pos)
#define    FL_ADC_JG_EXTS_TAU12_TRGO                              (0x3U << ADC_JGCFGR_JEXTS_Pos)
#define    FL_ADC_JG_EXTS_GPTIM1_TRGO                             (0x4U << ADC_JGCFGR_JEXTS_Pos)
#define    FL_ADC_JG_EXTS_GPTIM2_TRGO                             (0x5U << ADC_JGCFGR_JEXTS_Pos)
#define    FL_ADC_JG_EXTS_BSTIM16_TRGO                            (0x6U << ADC_JGCFGR_JEXTS_Pos)
#define    FL_ADC_JG_EXTS_LPTIM16_TRGO                            (0x7U << ADC_JGCFGR_JEXTS_Pos)
#define    FL_ADC_JG_EXTS_COMP1_TRGO                              (0x8U << ADC_JGCFGR_JEXTS_Pos)
#define    FL_ADC_JG_EXTS_COMP2_TRGO                              (0x9U << ADC_JGCFGR_JEXTS_Pos)
#define    FL_ADC_JG_EXTS_RTC_TRGO                                (0xaU << ADC_JGCFGR_JEXTS_Pos)
#define    FL_ADC_JG_EXTS_TAU00_TRGO                              (0xbU << ADC_JGCFGR_JEXTS_Pos)
#define    FL_ADC_JG_EXTS_TAU01_TRGO                              (0xcU << ADC_JGCFGR_JEXTS_Pos)
#define    FL_ADC_JG_EXTS_TAU02_TRGO                              (0xdU << ADC_JGCFGR_JEXTS_Pos)
#define    FL_ADC_JG_EXTS_TAU03_TRGO                              (0xeU << ADC_JGCFGR_JEXTS_Pos)
#define    FL_ADC_JG_EXTS_LUT0_TRGO                               (0xfU << ADC_JGCFGR_JEXTS_Pos)


#define    FL_ADC_JG_CONV_MODE_AUTO                               (0x0U << ADC_JGCFGR_JSEMI_Pos)
#define    FL_ADC_JG_CONV_MODE_SEMIAUTO                           (0x1U << ADC_JGCFGR_JSEMI_Pos)


#define    FL_ADC_JG_MODE_IMMEDIATE                               (0x0U << ADC_JGCFGR_JMOD_Pos)
#define    FL_ADC_JG_MODE_DELAYED                                 (0x1U << ADC_JGCFGR_JMOD_Pos)


#define    FL_ADC_JG_LENGTH_0L                                    (0x0U << ADC_JGCFGR_JL_Pos)
#define    FL_ADC_JG_LENGTH_1L                                    (0x1U << ADC_JGCFGR_JL_Pos)
#define    FL_ADC_JG_LENGTH_2L                                    (0x2U << ADC_JGCFGR_JL_Pos)
#define    FL_ADC_JG_LENGTH_3L                                    (0x3U << ADC_JGCFGR_JL_Pos)
#define    FL_ADC_JG_LENGTH_4L                                    (0x4U << ADC_JGCFGR_JL_Pos)


#define    FL_ADC_JG_CHANNLE0_CH0                                 (0x0U << ADC_JCFGR_JSEL0_Pos)
#define    FL_ADC_JG_CHANNLE0_CH1                                 (0x1U << ADC_JCFGR_JSEL0_Pos)
#define    FL_ADC_JG_CHANNLE0_CH2                                 (0x2U << ADC_JCFGR_JSEL0_Pos)
#define    FL_ADC_JG_CHANNLE0_CH3                                 (0x3U << ADC_JCFGR_JSEL0_Pos)
#define    FL_ADC_JG_CHANNLE0_CH4                                 (0x4U << ADC_JCFGR_JSEL0_Pos)
#define    FL_ADC_JG_CHANNLE0_CH5                                 (0x5U << ADC_JCFGR_JSEL0_Pos)
#define    FL_ADC_JG_CHANNLE0_CH6                                 (0x6U << ADC_JCFGR_JSEL0_Pos)
#define    FL_ADC_JG_CHANNLE0_CH7                                 (0x7U << ADC_JCFGR_JSEL0_Pos)
#define    FL_ADC_JG_CHANNLE0_CH8                                 (0x8U << ADC_JCFGR_JSEL0_Pos)
#define    FL_ADC_JG_CHANNLE0_CH9                                 (0x9U << ADC_JCFGR_JSEL0_Pos)
#define    FL_ADC_JG_CHANNLE0_CH10                                (0xaU << ADC_JCFGR_JSEL0_Pos)
#define    FL_ADC_JG_CHANNLE0_CH11                                (0xbU << ADC_JCFGR_JSEL0_Pos)
#define    FL_ADC_JG_CHANNLE0_CH12                                (0xcU << ADC_JCFGR_JSEL0_Pos)
#define    FL_ADC_JG_CHANNLE0_CH13                                (0xdU << ADC_JCFGR_JSEL0_Pos)
#define    FL_ADC_JG_CHANNLE0_CH14                                (0xeU << ADC_JCFGR_JSEL0_Pos)
#define    FL_ADC_JG_CHANNLE0_CH15                                (0xfU << ADC_JCFGR_JSEL0_Pos)
#define    FL_ADC_JG_CHANNLE0_CH16                                (0x0U << ADC_JCFGR_JSEL0_Pos | 0x1U << ADC_JCFGR_JSEL0_4_Pos)
#define    FL_ADC_JG_CHANNLE0_CH17                                (0x1U << ADC_JCFGR_JSEL0_Pos | 0x1U << ADC_JCFGR_JSEL0_4_Pos)
#define    FL_ADC_JG_CHANNLE0_CH18                                (0x2U << ADC_JCFGR_JSEL0_Pos | 0x1U << ADC_JCFGR_JSEL0_4_Pos)
#define    FL_ADC_JG_CHANNLE0_CH19                                (0x3U << ADC_JCFGR_JSEL0_Pos | 0x1U << ADC_JCFGR_JSEL0_4_Pos)
#define    FL_ADC_JG_CHANNLE0_CH20                                (0x4U << ADC_JCFGR_JSEL0_Pos | 0x1U << ADC_JCFGR_JSEL0_4_Pos)
#define    FL_ADC_JG_CHANNLE0_CH21                                (0x5U << ADC_JCFGR_JSEL0_Pos | 0x1U << ADC_JCFGR_JSEL0_4_Pos)
#define    FL_ADC_JG_CHANNLE0_CH22                                (0x6U << ADC_JCFGR_JSEL0_Pos | 0x1U << ADC_JCFGR_JSEL0_4_Pos)
#define    FL_ADC_JG_CHANNLE0_CH23                                (0x7U << ADC_JCFGR_JSEL0_Pos | 0x1U << ADC_JCFGR_JSEL0_4_Pos)
#define    FL_ADC_JG_CHANNLE0_CH24                                (0x8U << ADC_JCFGR_JSEL0_Pos | 0x1U << ADC_JCFGR_JSEL0_4_Pos)
#define    FL_ADC_JG_CHANNLE0_CH25                                (0x9U << ADC_JCFGR_JSEL0_Pos | 0x1U << ADC_JCFGR_JSEL0_4_Pos)
#define    FL_ADC_JG_CHANNLE0_CH26                                (0xaU << ADC_JCFGR_JSEL0_Pos | 0x1U << ADC_JCFGR_JSEL0_4_Pos)
#define    FL_ADC_JG_CHANNLE0_CH27                                (0xbU << ADC_JCFGR_JSEL0_Pos | 0x1U << ADC_JCFGR_JSEL0_4_Pos)
#define    FL_ADC_JG_CHANNLE0_CH28                                (0xcU << ADC_JCFGR_JSEL0_Pos | 0x1U << ADC_JCFGR_JSEL0_4_Pos)
#define    FL_ADC_JG_CHANNLE0_CH29                                (0xdU << ADC_JCFGR_JSEL0_Pos | 0x1U << ADC_JCFGR_JSEL0_4_Pos)
#define    FL_ADC_JG_CHANNLE0_CH30                                (0xeU << ADC_JCFGR_JSEL0_Pos | 0x1U << ADC_JCFGR_JSEL0_4_Pos)


#define    FL_ADC_JG_CHANNLE1_CH0                                 (0x0U << ADC_JCFGR_JSEL1_Pos)
#define    FL_ADC_JG_CHANNLE1_CH1                                 (0x1U << ADC_JCFGR_JSEL1_Pos)
#define    FL_ADC_JG_CHANNLE1_CH2                                 (0x2U << ADC_JCFGR_JSEL1_Pos)
#define    FL_ADC_JG_CHANNLE1_CH3                                 (0x3U << ADC_JCFGR_JSEL1_Pos)
#define    FL_ADC_JG_CHANNLE1_CH4                                 (0x4U << ADC_JCFGR_JSEL1_Pos)
#define    FL_ADC_JG_CHANNLE1_CH5                                 (0x5U << ADC_JCFGR_JSEL1_Pos)
#define    FL_ADC_JG_CHANNLE1_CH6                                 (0x6U << ADC_JCFGR_JSEL1_Pos)
#define    FL_ADC_JG_CHANNLE1_CH7                                 (0x7U << ADC_JCFGR_JSEL1_Pos)
#define    FL_ADC_JG_CHANNLE1_CH8                                 (0x8U << ADC_JCFGR_JSEL1_Pos)
#define    FL_ADC_JG_CHANNLE1_CH9                                 (0x9U << ADC_JCFGR_JSEL1_Pos)
#define    FL_ADC_JG_CHANNLE1_CH10                                (0xaU << ADC_JCFGR_JSEL1_Pos)
#define    FL_ADC_JG_CHANNLE1_CH11                                (0xbU << ADC_JCFGR_JSEL1_Pos)
#define    FL_ADC_JG_CHANNLE1_CH12                                (0xcU << ADC_JCFGR_JSEL1_Pos)
#define    FL_ADC_JG_CHANNLE1_CH13                                (0xdU << ADC_JCFGR_JSEL1_Pos)
#define    FL_ADC_JG_CHANNLE1_CH14                                (0xeU << ADC_JCFGR_JSEL1_Pos)
#define    FL_ADC_JG_CHANNLE1_CH15                                (0xfU << ADC_JCFGR_JSEL1_Pos)
#define    FL_ADC_JG_CHANNLE1_CH16                                (0x0U << ADC_JCFGR_JSEL1_Pos | 0x1U << ADC_JCFGR_JSEL1_4_Pos)
#define    FL_ADC_JG_CHANNLE1_CH17                                (0x1U << ADC_JCFGR_JSEL1_Pos | 0x1U << ADC_JCFGR_JSEL1_4_Pos)
#define    FL_ADC_JG_CHANNLE1_CH18                                (0x2U << ADC_JCFGR_JSEL1_Pos | 0x1U << ADC_JCFGR_JSEL1_4_Pos)
#define    FL_ADC_JG_CHANNLE1_CH19                                (0x3U << ADC_JCFGR_JSEL1_Pos | 0x1U << ADC_JCFGR_JSEL1_4_Pos)
#define    FL_ADC_JG_CHANNLE1_CH20                                (0x4U << ADC_JCFGR_JSEL1_Pos | 0x1U << ADC_JCFGR_JSEL1_4_Pos)
#define    FL_ADC_JG_CHANNLE1_CH21                                (0x5U << ADC_JCFGR_JSEL1_Pos | 0x1U << ADC_JCFGR_JSEL1_4_Pos)
#define    FL_ADC_JG_CHANNLE1_CH22                                (0x6U << ADC_JCFGR_JSEL1_Pos | 0x1U << ADC_JCFGR_JSEL1_4_Pos)
#define    FL_ADC_JG_CHANNLE1_CH23                                (0x7U << ADC_JCFGR_JSEL1_Pos | 0x1U << ADC_JCFGR_JSEL1_4_Pos)
#define    FL_ADC_JG_CHANNLE1_CH24                                (0x8U << ADC_JCFGR_JSEL1_Pos | 0x1U << ADC_JCFGR_JSEL1_4_Pos)
#define    FL_ADC_JG_CHANNLE1_CH25                                (0x9U << ADC_JCFGR_JSEL1_Pos | 0x1U << ADC_JCFGR_JSEL1_4_Pos)
#define    FL_ADC_JG_CHANNLE1_CH26                                (0xaU << ADC_JCFGR_JSEL1_Pos | 0x1U << ADC_JCFGR_JSEL1_4_Pos)
#define    FL_ADC_JG_CHANNLE1_CH27                                (0xbU << ADC_JCFGR_JSEL1_Pos | 0x1U << ADC_JCFGR_JSEL1_4_Pos)
#define    FL_ADC_JG_CHANNLE1_CH28                                (0xcU << ADC_JCFGR_JSEL1_Pos | 0x1U << ADC_JCFGR_JSEL1_4_Pos)
#define    FL_ADC_JG_CHANNLE1_CH29                                (0xdU << ADC_JCFGR_JSEL1_Pos | 0x1U << ADC_JCFGR_JSEL1_4_Pos)
#define    FL_ADC_JG_CHANNLE1_CH30                                (0xeU << ADC_JCFGR_JSEL1_Pos | 0x1U << ADC_JCFGR_JSEL1_4_Pos)


#define    FL_ADC_JGCH0_OVERSAMPLING_MUL_2X                       (0x0U << ADC_JCFGR_JOVSR0_Pos)
#define    FL_ADC_JGCH0_OVERSAMPLING_MUL_4X                       (0x1U << ADC_JCFGR_JOVSR0_Pos)
#define    FL_ADC_JGCH0_OVERSAMPLING_MUL_8X                       (0x2U << ADC_JCFGR_JOVSR0_Pos)
#define    FL_ADC_JGCH0_OVERSAMPLING_MUL_16X                      (0x3U << ADC_JCFGR_JOVSR0_Pos)


#define    FL_ADC_JGCH1_OVERSAMPLING_MUL_2X                       (0x0U << ADC_JCFGR_JOVSR1_Pos)
#define    FL_ADC_JGCH1_OVERSAMPLING_MUL_4X                       (0x1U << ADC_JCFGR_JOVSR1_Pos)
#define    FL_ADC_JGCH1_OVERSAMPLING_MUL_8X                       (0x2U << ADC_JCFGR_JOVSR1_Pos)
#define    FL_ADC_JGCH1_OVERSAMPLING_MUL_16X                      (0x3U << ADC_JCFGR_JOVSR1_Pos)


#define    FL_ADC_JG_CHANNLE2_CH0                                 (0x0U << ADC_JCFGR_JSEL2_Pos)
#define    FL_ADC_JG_CHANNLE2_CH1                                 (0x1U << ADC_JCFGR_JSEL2_Pos)
#define    FL_ADC_JG_CHANNLE2_CH2                                 (0x2U << ADC_JCFGR_JSEL2_Pos)
#define    FL_ADC_JG_CHANNLE2_CH3                                 (0x3U << ADC_JCFGR_JSEL2_Pos)
#define    FL_ADC_JG_CHANNLE2_CH4                                 (0x4U << ADC_JCFGR_JSEL2_Pos)
#define    FL_ADC_JG_CHANNLE2_CH5                                 (0x5U << ADC_JCFGR_JSEL2_Pos)
#define    FL_ADC_JG_CHANNLE2_CH6                                 (0x6U << ADC_JCFGR_JSEL2_Pos)
#define    FL_ADC_JG_CHANNLE2_CH7                                 (0x7U << ADC_JCFGR_JSEL2_Pos)
#define    FL_ADC_JG_CHANNLE2_CH8                                 (0x8U << ADC_JCFGR_JSEL2_Pos)
#define    FL_ADC_JG_CHANNLE2_CH9                                 (0x9U << ADC_JCFGR_JSEL2_Pos)
#define    FL_ADC_JG_CHANNLE2_CH10                                (0xaU << ADC_JCFGR_JSEL2_Pos)
#define    FL_ADC_JG_CHANNLE2_CH11                                (0xbU << ADC_JCFGR_JSEL2_Pos)
#define    FL_ADC_JG_CHANNLE2_CH12                                (0xcU << ADC_JCFGR_JSEL2_Pos)
#define    FL_ADC_JG_CHANNLE2_CH13                                (0xdU << ADC_JCFGR_JSEL2_Pos)
#define    FL_ADC_JG_CHANNLE2_CH14                                (0xeU << ADC_JCFGR_JSEL2_Pos)
#define    FL_ADC_JG_CHANNLE2_CH15                                (0xfU << ADC_JCFGR_JSEL2_Pos)
#define    FL_ADC_JG_CHANNLE2_CH16                                (0x0U << ADC_JCFGR_JSEL2_Pos | 0x1U << ADC_JCFGR_JSEL2_4_Pos)
#define    FL_ADC_JG_CHANNLE2_CH17                                (0x1U << ADC_JCFGR_JSEL2_Pos | 0x1U << ADC_JCFGR_JSEL2_4_Pos)
#define    FL_ADC_JG_CHANNLE2_CH18                                (0x2U << ADC_JCFGR_JSEL2_Pos | 0x1U << ADC_JCFGR_JSEL2_4_Pos)
#define    FL_ADC_JG_CHANNLE2_CH19                                (0x3U << ADC_JCFGR_JSEL2_Pos | 0x1U << ADC_JCFGR_JSEL2_4_Pos)
#define    FL_ADC_JG_CHANNLE2_CH20                                (0x4U << ADC_JCFGR_JSEL2_Pos | 0x1U << ADC_JCFGR_JSEL2_4_Pos)
#define    FL_ADC_JG_CHANNLE2_CH21                                (0x5U << ADC_JCFGR_JSEL2_Pos | 0x1U << ADC_JCFGR_JSEL2_4_Pos)
#define    FL_ADC_JG_CHANNLE2_CH22                                (0x6U << ADC_JCFGR_JSEL2_Pos | 0x1U << ADC_JCFGR_JSEL2_4_Pos)
#define    FL_ADC_JG_CHANNLE2_CH23                                (0x7U << ADC_JCFGR_JSEL2_Pos | 0x1U << ADC_JCFGR_JSEL2_4_Pos)
#define    FL_ADC_JG_CHANNLE2_CH24                                (0x8U << ADC_JCFGR_JSEL2_Pos | 0x1U << ADC_JCFGR_JSEL2_4_Pos)
#define    FL_ADC_JG_CHANNLE2_CH25                                (0x9U << ADC_JCFGR_JSEL2_Pos | 0x1U << ADC_JCFGR_JSEL2_4_Pos)
#define    FL_ADC_JG_CHANNLE2_CH26                                (0xaU << ADC_JCFGR_JSEL2_Pos | 0x1U << ADC_JCFGR_JSEL2_4_Pos)
#define    FL_ADC_JG_CHANNLE2_CH27                                (0xbU << ADC_JCFGR_JSEL2_Pos | 0x1U << ADC_JCFGR_JSEL2_4_Pos)
#define    FL_ADC_JG_CHANNLE2_CH28                                (0xcU << ADC_JCFGR_JSEL2_Pos | 0x1U << ADC_JCFGR_JSEL2_4_Pos)
#define    FL_ADC_JG_CHANNLE2_CH29                                (0xdU << ADC_JCFGR_JSEL2_Pos | 0x1U << ADC_JCFGR_JSEL2_4_Pos)
#define    FL_ADC_JG_CHANNLE2_CH30                                (0xeU << ADC_JCFGR_JSEL2_Pos | 0x1U << ADC_JCFGR_JSEL2_4_Pos)


#define    FL_ADC_JG_CHANNLE3_CH0                                 (0x0U << ADC_JCFGR_JSEL3_Pos)
#define    FL_ADC_JG_CHANNLE3_CH1                                 (0x1U << ADC_JCFGR_JSEL3_Pos)
#define    FL_ADC_JG_CHANNLE3_CH2                                 (0x2U << ADC_JCFGR_JSEL3_Pos)
#define    FL_ADC_JG_CHANNLE3_CH3                                 (0x3U << ADC_JCFGR_JSEL3_Pos)
#define    FL_ADC_JG_CHANNLE3_CH4                                 (0x4U << ADC_JCFGR_JSEL3_Pos)
#define    FL_ADC_JG_CHANNLE3_CH5                                 (0x5U << ADC_JCFGR_JSEL3_Pos)
#define    FL_ADC_JG_CHANNLE3_CH6                                 (0x6U << ADC_JCFGR_JSEL3_Pos)
#define    FL_ADC_JG_CHANNLE3_CH7                                 (0x7U << ADC_JCFGR_JSEL3_Pos)
#define    FL_ADC_JG_CHANNLE3_CH8                                 (0x8U << ADC_JCFGR_JSEL3_Pos)
#define    FL_ADC_JG_CHANNLE3_CH9                                 (0x9U << ADC_JCFGR_JSEL3_Pos)
#define    FL_ADC_JG_CHANNLE3_CH10                                (0xaU << ADC_JCFGR_JSEL3_Pos)
#define    FL_ADC_JG_CHANNLE3_CH11                                (0xbU << ADC_JCFGR_JSEL3_Pos)
#define    FL_ADC_JG_CHANNLE3_CH12                                (0xcU << ADC_JCFGR_JSEL3_Pos)
#define    FL_ADC_JG_CHANNLE3_CH13                                (0xdU << ADC_JCFGR_JSEL3_Pos)
#define    FL_ADC_JG_CHANNLE3_CH14                                (0xeU << ADC_JCFGR_JSEL3_Pos)
#define    FL_ADC_JG_CHANNLE3_CH15                                (0xfU << ADC_JCFGR_JSEL3_Pos)
#define    FL_ADC_JG_CHANNLE3_CH16                                (0x0U << ADC_JCFGR_JSEL3_Pos | 0x1U << ADC_JCFGR_JSEL3_4_Pos)
#define    FL_ADC_JG_CHANNLE3_CH17                                (0x1U << ADC_JCFGR_JSEL3_Pos | 0x1U << ADC_JCFGR_JSEL3_4_Pos)
#define    FL_ADC_JG_CHANNLE3_CH18                                (0x2U << ADC_JCFGR_JSEL3_Pos | 0x1U << ADC_JCFGR_JSEL3_4_Pos)
#define    FL_ADC_JG_CHANNLE3_CH19                                (0x3U << ADC_JCFGR_JSEL3_Pos | 0x1U << ADC_JCFGR_JSEL3_4_Pos)
#define    FL_ADC_JG_CHANNLE3_CH20                                (0x4U << ADC_JCFGR_JSEL3_Pos | 0x1U << ADC_JCFGR_JSEL3_4_Pos)
#define    FL_ADC_JG_CHANNLE3_CH21                                (0x5U << ADC_JCFGR_JSEL3_Pos | 0x1U << ADC_JCFGR_JSEL3_4_Pos)
#define    FL_ADC_JG_CHANNLE3_CH22                                (0x6U << ADC_JCFGR_JSEL3_Pos | 0x1U << ADC_JCFGR_JSEL3_4_Pos)
#define    FL_ADC_JG_CHANNLE3_CH23                                (0x7U << ADC_JCFGR_JSEL3_Pos | 0x1U << ADC_JCFGR_JSEL3_4_Pos)
#define    FL_ADC_JG_CHANNLE3_CH24                                (0x8U << ADC_JCFGR_JSEL3_Pos | 0x1U << ADC_JCFGR_JSEL3_4_Pos)
#define    FL_ADC_JG_CHANNLE3_CH25                                (0x9U << ADC_JCFGR_JSEL3_Pos | 0x1U << ADC_JCFGR_JSEL3_4_Pos)
#define    FL_ADC_JG_CHANNLE3_CH26                                (0xaU << ADC_JCFGR_JSEL3_Pos | 0x1U << ADC_JCFGR_JSEL3_4_Pos)
#define    FL_ADC_JG_CHANNLE3_CH27                                (0xbU << ADC_JCFGR_JSEL3_Pos | 0x1U << ADC_JCFGR_JSEL3_4_Pos)
#define    FL_ADC_JG_CHANNLE3_CH28                                (0xcU << ADC_JCFGR_JSEL3_Pos | 0x1U << ADC_JCFGR_JSEL3_4_Pos)
#define    FL_ADC_JG_CHANNLE3_CH29                                (0xdU << ADC_JCFGR_JSEL3_Pos | 0x1U << ADC_JCFGR_JSEL3_4_Pos)
#define    FL_ADC_JG_CHANNLE3_CH30                                (0xeU << ADC_JCFGR_JSEL3_Pos | 0x1U << ADC_JCFGR_JSEL3_4_Pos)


#define    FL_ADC_JGCH2_OVERSAMPLING_MUL_2X                       (0x0U << ADC_JCFGR_JOVSR2_Pos)
#define    FL_ADC_JGCH2_OVERSAMPLING_MUL_4X                       (0x1U << ADC_JCFGR_JOVSR2_Pos)
#define    FL_ADC_JGCH2_OVERSAMPLING_MUL_8X                       (0x2U << ADC_JCFGR_JOVSR2_Pos)
#define    FL_ADC_JGCH2_OVERSAMPLING_MUL_16X                      (0x3U << ADC_JCFGR_JOVSR2_Pos)


#define    FL_ADC_JGCH3_OVERSAMPLING_MUL_2X                       (0x0U << ADC_JCFGR_JOVSR3_Pos)
#define    FL_ADC_JGCH3_OVERSAMPLING_MUL_4X                       (0x1U << ADC_JCFGR_JOVSR3_Pos)
#define    FL_ADC_JGCH3_OVERSAMPLING_MUL_8X                       (0x2U << ADC_JCFGR_JOVSR3_Pos)
#define    FL_ADC_JGCH3_OVERSAMPLING_MUL_16X                      (0x3U << ADC_JCFGR_JOVSR3_Pos)


/**
  * @}
  */
/* Exported functions ---------------------------------------------------------------------------------*/
/** @defgroup ADC_FL_Exported_Functions ADC Exported Functions
  * @{
  */

/**
  * @brief    Get ADC End Of Conversion Flag
  * @rmtoll   ISR    EOC    FL_ADC_IsActiveFlag_EndOfConversion
  * @param    ADCx ADC instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_ADC_IsActiveFlag_EndOfConversion(ADC_Type *ADCx)
{
    return (uint32_t)(READ_BIT(ADCx->ISR, ADC_ISR_EOC_Msk) == (ADC_ISR_EOC_Msk));
}

/**
  * @brief    Clear ADC End Of Conversion Flag
  * @rmtoll   ISR    EOC    FL_ADC_ClearFlag_EndOfConversion
  * @param    ADCx ADC instance
  * @retval   None
  */
__STATIC_INLINE void FL_ADC_ClearFlag_EndOfConversion(ADC_Type *ADCx)
{
    WRITE_REG(ADCx->ISR, ADC_ISR_EOC_Msk);
}

/**
  * @brief    Get ADC End Of Sequence Flag
  * @rmtoll   ISR    EOS    FL_ADC_IsActiveFlag_EndOfSequence
  * @param    ADCx ADC instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_ADC_IsActiveFlag_EndOfSequence(ADC_Type *ADCx)
{
    return (uint32_t)(READ_BIT(ADCx->ISR, ADC_ISR_EOS_Msk) == (ADC_ISR_EOS_Msk));
}

/**
  * @brief    Clear ADC End Of Sequence Flag
  * @rmtoll   ISR    EOS    FL_ADC_ClearFlag_EndOfSequence
  * @param    ADCx ADC instance
  * @retval   None
  */
__STATIC_INLINE void FL_ADC_ClearFlag_EndOfSequence(ADC_Type *ADCx)
{
    WRITE_REG(ADCx->ISR, ADC_ISR_EOS_Msk);
}

/**
  * @brief    Get ADC Data Overrun Flag
  * @rmtoll   ISR    OVR    FL_ADC_IsActiveFlag_Overrun
  * @param    ADCx ADC instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_ADC_IsActiveFlag_Overrun(ADC_Type *ADCx)
{
    return (uint32_t)(READ_BIT(ADCx->ISR, ADC_ISR_OVR_Msk) == (ADC_ISR_OVR_Msk));
}

/**
  * @brief    Clear ADC  Data Overrun Flag
  * @rmtoll   ISR    OVR    FL_ADC_ClearFlag_Overrun
  * @param    ADCx ADC instance
  * @retval   None
  */
__STATIC_INLINE void FL_ADC_ClearFlag_Overrun(ADC_Type *ADCx)
{
    WRITE_REG(ADCx->ISR, ADC_ISR_OVR_Msk);
}

/**
  * @brief    Get ADC Busy Flag
  * @rmtoll   ISR    BUSY    FL_ADC_IsActiveFlag_Busy
  * @param    ADCx ADC instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_ADC_IsActiveFlag_Busy(ADC_Type *ADCx)
{
    return (uint32_t)(READ_BIT(ADCx->ISR, ADC_ISR_BUSY_Msk) == (ADC_ISR_BUSY_Msk));
}

/**
  * @brief    Get ADC End Of Calibration Flag
  * @rmtoll   ISR    EOCAL    FL_ADC_IsActiveFlag_EndOfCalibration
  * @param    ADCx ADC instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_ADC_IsActiveFlag_EndOfCalibration(ADC_Type *ADCx)
{
    return (uint32_t)(READ_BIT(ADCx->ISR, ADC_ISR_EOCAL_Msk) == (ADC_ISR_EOCAL_Msk));
}

/**
  * @brief    Clear ADC End Of Calibration Flag
  * @rmtoll   ISR    EOCAL    FL_ADC_ClearFlag_EndOfCalibration
  * @param    ADCx ADC instance
  * @retval   None
  */
__STATIC_INLINE void FL_ADC_ClearFlag_EndOfCalibration(ADC_Type *ADCx)
{
    WRITE_REG(ADCx->ISR, ADC_ISR_EOCAL_Msk);
}

/**
  * @brief    Get ADC Analog Watchdog Under Low
  * @rmtoll   ISR    AWD_UL    FL_ADC_IsActiveFlag_AnalogWDGUnderLow
  * @param    ADCx ADC instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_ADC_IsActiveFlag_AnalogWDGUnderLow(ADC_Type *ADCx)
{
    return (uint32_t)(READ_BIT(ADCx->ISR, ADC_ISR_AWD_UL_Msk) == (ADC_ISR_AWD_UL_Msk));
}

/**
  * @brief    Clear ADC Analog Watchdog Under Low
  * @rmtoll   ISR    AWD_UL    FL_ADC_ClearFlag_AnalogWDGUnderLow
  * @param    ADCx ADC instance
  * @retval   None
  */
__STATIC_INLINE void FL_ADC_ClearFlag_AnalogWDGUnderLow(ADC_Type *ADCx)
{
    WRITE_REG(ADCx->ISR, ADC_ISR_AWD_UL_Msk);
}

/**
  * @brief    Get ADC Analog Watchdog Above High
  * @rmtoll   ISR    AWD_AH    FL_ADC_IsActiveFlag_AnalogWDGAboveHigh
  * @param    ADCx ADC instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_ADC_IsActiveFlag_AnalogWDGAboveHigh(ADC_Type *ADCx)
{
    return (uint32_t)(READ_BIT(ADCx->ISR, ADC_ISR_AWD_AH_Msk) == (ADC_ISR_AWD_AH_Msk));
}

/**
  * @brief    Clear ADC Analog Watchdog Above High
  * @rmtoll   ISR    AWD_AH    FL_ADC_ClearFlag_AnalogWDGAboveHigh
  * @param    ADCx ADC instance
  * @retval   None
  */
__STATIC_INLINE void FL_ADC_ClearFlag_AnalogWDGAboveHigh(ADC_Type *ADCx)
{
    WRITE_REG(ADCx->ISR, ADC_ISR_AWD_AH_Msk);
}

/**
  * @brief    Enable ADC End 0f Conversion interrupt
  * @rmtoll   IER    EOCIE    FL_ADC_EnableIT_EndOfConversion
  * @param    ADCx ADC instance
  * @retval   None
  */
__STATIC_INLINE void FL_ADC_EnableIT_EndOfConversion(ADC_Type *ADCx)
{
    SET_BIT(ADCx->IER, ADC_IER_EOCIE_Msk);
}

/**
  * @brief    Disable ADC End 0f Conversion interrupt
  * @rmtoll   IER    EOCIE    FL_ADC_DisableIT_EndOfConversion
  * @param    ADCx ADC instance
  * @retval   None
  */
__STATIC_INLINE void FL_ADC_DisableIT_EndOfConversion(ADC_Type *ADCx)
{
    CLEAR_BIT(ADCx->IER, ADC_IER_EOCIE_Msk);
}

/**
  * @brief    Get ADC End 0f Conversion interrupt Enable Status
  * @rmtoll   IER    EOCIE    FL_ADC_IsEnabledIT_EndOfConversion
  * @param    ADCx ADC instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_ADC_IsEnabledIT_EndOfConversion(ADC_Type *ADCx)
{
    return (uint32_t)(READ_BIT(ADCx->IER, ADC_IER_EOCIE_Msk) == ADC_IER_EOCIE_Msk);
}

/**
  * @brief    Enable ADC End Of Sequence interrupt
  * @rmtoll   IER    EOSIE    FL_ADC_EnableIT_EndOfSequence
  * @param    ADCx ADC instance
  * @retval   None
  */
__STATIC_INLINE void FL_ADC_EnableIT_EndOfSequence(ADC_Type *ADCx)
{
    SET_BIT(ADCx->IER, ADC_IER_EOSIE_Msk);
}

/**
  * @brief    Disable ADC End Of Sequence interrupt
  * @rmtoll   IER    EOSIE    FL_ADC_DisableIT_EndOfSequence
  * @param    ADCx ADC instance
  * @retval   None
  */
__STATIC_INLINE void FL_ADC_DisableIT_EndOfSequence(ADC_Type *ADCx)
{
    CLEAR_BIT(ADCx->IER, ADC_IER_EOSIE_Msk);
}

/**
  * @brief    Get ADC End Of Sequence interrupt Enable Status
  * @rmtoll   IER    EOSIE    FL_ADC_IsEnabledIT_EndOfSequence
  * @param    ADCx ADC instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_ADC_IsEnabledIT_EndOfSequence(ADC_Type *ADCx)
{
    return (uint32_t)(READ_BIT(ADCx->IER, ADC_IER_EOSIE_Msk) == ADC_IER_EOSIE_Msk);
}

/**
  * @brief    Enable ADC Data Overrun interrupt
  * @rmtoll   IER    OVRIE    FL_ADC_EnableIT_Overrun
  * @param    ADCx ADC instance
  * @retval   None
  */
__STATIC_INLINE void FL_ADC_EnableIT_Overrun(ADC_Type *ADCx)
{
    SET_BIT(ADCx->IER, ADC_IER_OVRIE_Msk);
}

/**
  * @brief    Disable ADC Data Overrun interrupt
  * @rmtoll   IER    OVRIE    FL_ADC_DisableIT_Overrun
  * @param    ADCx ADC instance
  * @retval   None
  */
__STATIC_INLINE void FL_ADC_DisableIT_Overrun(ADC_Type *ADCx)
{
    CLEAR_BIT(ADCx->IER, ADC_IER_OVRIE_Msk);
}

/**
  * @brief    Get ADC Data Overrun interrupt Enable Status
  * @rmtoll   IER    OVRIE    FL_ADC_IsEnabledIT_Overrun
  * @param    ADCx ADC instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_ADC_IsEnabledIT_Overrun(ADC_Type *ADCx)
{
    return (uint32_t)(READ_BIT(ADCx->IER, ADC_IER_OVRIE_Msk) == ADC_IER_OVRIE_Msk);
}

/**
  * @brief    Enable ADC End Of Calibration interrupt
  * @rmtoll   IER    EOCALIE    FL_ADC_EnableIT_EndOfCalibration
  * @param    ADCx ADC instance
  * @retval   None
  */
__STATIC_INLINE void FL_ADC_EnableIT_EndOfCalibration(ADC_Type *ADCx)
{
    SET_BIT(ADCx->IER, ADC_IER_EOCALIE_Msk);
}

/**
  * @brief    Disable ADC End Of Calibration interrupt
  * @rmtoll   IER    EOCALIE    FL_ADC_DisableIT_EndOfCalibration
  * @param    ADCx ADC instance
  * @retval   None
  */
__STATIC_INLINE void FL_ADC_DisableIT_EndOfCalibration(ADC_Type *ADCx)
{
    CLEAR_BIT(ADCx->IER, ADC_IER_EOCALIE_Msk);
}

/**
  * @brief    Get ADC End Of Calibration interrupt Enable Status
  * @rmtoll   IER    EOCALIE    FL_ADC_IsEnabledIT_EndOfCalibration
  * @param    ADCx ADC instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_ADC_IsEnabledIT_EndOfCalibration(ADC_Type *ADCx)
{
    return (uint32_t)(READ_BIT(ADCx->IER, ADC_IER_EOCALIE_Msk) == ADC_IER_EOCALIE_Msk);
}

/**
  * @brief    Enable ADC Analog Watchdog Under Low interrupt
  * @rmtoll   IER    AWD_ULIE    FL_ADC_EnableIT_AnalogWDGUnderLow
  * @param    ADCx ADC instance
  * @retval   None
  */
__STATIC_INLINE void FL_ADC_EnableIT_AnalogWDGUnderLow(ADC_Type *ADCx)
{
    SET_BIT(ADCx->IER, ADC_IER_AWD_ULIE_Msk);
}

/**
  * @brief    Disable ADC Analog Watchdog Under Low interrupt
  * @rmtoll   IER    AWD_ULIE    FL_ADC_DisableIT_AnalogWDGUnderLow
  * @param    ADCx ADC instance
  * @retval   None
  */
__STATIC_INLINE void FL_ADC_DisableIT_AnalogWDGUnderLow(ADC_Type *ADCx)
{
    CLEAR_BIT(ADCx->IER, ADC_IER_AWD_ULIE_Msk);
}

/**
  * @brief    Get ADC Analog Watchdog Under Low interrupt Enable Status
  * @rmtoll   IER    AWD_ULIE    FL_ADC_IsEnabledIT_AnalogWDGUnderLow
  * @param    ADCx ADC instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_ADC_IsEnabledIT_AnalogWDGUnderLow(ADC_Type *ADCx)
{
    return (uint32_t)(READ_BIT(ADCx->IER, ADC_IER_AWD_ULIE_Msk) == ADC_IER_AWD_ULIE_Msk);
}

/**
  * @brief    Enable ADC Analog Watchdog Above High interrupt
  * @rmtoll   IER    AWD_AHIE    FL_ADC_EnableIT_AnalogWDGAboveHigh
  * @param    ADCx ADC instance
  * @retval   None
  */
__STATIC_INLINE void FL_ADC_EnableIT_AnalogWDGAboveHigh(ADC_Type *ADCx)
{
    SET_BIT(ADCx->IER, ADC_IER_AWD_AHIE_Msk);
}

/**
  * @brief    Disable ADC Analog Watchdog Above High interrupt
  * @rmtoll   IER    AWD_AHIE    FL_ADC_DisableIT_AnalogWDGAboveHigh
  * @param    ADCx ADC instance
  * @retval   None
  */
__STATIC_INLINE void FL_ADC_DisableIT_AnalogWDGAboveHigh(ADC_Type *ADCx)
{
    CLEAR_BIT(ADCx->IER, ADC_IER_AWD_AHIE_Msk);
}

/**
  * @brief    Get ADC Analog Watchdog Above High interrupt Enable Status
  * @rmtoll   IER    AWD_AHIE    FL_ADC_IsEnabledIT_AnalogWDGAboveHigh
  * @param    ADCx ADC instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_ADC_IsEnabledIT_AnalogWDGAboveHigh(ADC_Type *ADCx)
{
    return (uint32_t)(READ_BIT(ADCx->IER, ADC_IER_AWD_AHIE_Msk) == ADC_IER_AWD_AHIE_Msk);
}

/**
  * @brief    Enable ADC
  * @rmtoll   CR1    ADEN    FL_ADC_Enable
  * @param    ADCx ADC instance
  * @retval   None
  */
__STATIC_INLINE void FL_ADC_Enable(ADC_Type *ADCx)
{
    SET_BIT(ADCx->CR1, ADC_CR1_ADEN_Msk);
}

/**
  * @brief    Disable ADC
  * @rmtoll   CR1    ADEN    FL_ADC_Disable
  * @param    ADCx ADC instance
  * @retval   None
  */
__STATIC_INLINE void FL_ADC_Disable(ADC_Type *ADCx)
{
    CLEAR_BIT(ADCx->CR1, ADC_CR1_ADEN_Msk);
}

/**
  * @brief    Get ADC Enable Status
  * @rmtoll   CR1    ADEN    FL_ADC_IsEnabled
  * @param    ADCx ADC instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_ADC_IsEnabled(ADC_Type *ADCx)
{
    return (uint32_t)(READ_BIT(ADCx->CR1, ADC_CR1_ADEN_Msk) == ADC_CR1_ADEN_Msk);
}

/**
  * @brief    Enable ADC Regular Group Software Triggered Conversion
  * @rmtoll   CR1    RSTART    FL_ADC_EnableRegularGroupSWConversion
  * @param    ADCx ADC instance
  * @retval   None
  */
__STATIC_INLINE void FL_ADC_EnableRegularGroupSWConversion(ADC_Type *ADCx)
{
    SET_BIT(ADCx->CR1, ADC_CR1_RSTART_Msk);
}

/**
  * @brief    Enable ADC Injection Group Software Triggered Conversion
  * @rmtoll   CR1    JSTART    FL_ADC_EnableInjectionGroupSWConversion
  * @param    ADCx ADC instance
  * @retval   None
  */
__STATIC_INLINE void FL_ADC_EnableInjectionGroupSWConversion(ADC_Type *ADCx)
{
    SET_BIT(ADCx->CR1, ADC_CR1_JSTART_Msk);
}

/**
  * @brief    Disable Stop ADC Regular Group Software Triggered Conversion
  * @rmtoll   CR1    RSTOP    FL_ADC_DisableRegularGroupSWConversion
  * @param    ADCx ADC instance
  * @retval   None
  */
__STATIC_INLINE void FL_ADC_DisableRegularGroupSWConversion(ADC_Type *ADCx)
{
    CLEAR_BIT(ADCx->CR1, ADC_CR1_RSTOP_Msk);
}

/**
  * @brief    Disable Stop ADC Injection Group Software Triggered Conversion
  * @rmtoll   CR1    JSTOP    FL_ADC_DisableInjectionGroupSWConversion
  * @param    ADCx ADC instance
  * @retval   None
  */
__STATIC_INLINE void FL_ADC_DisableInjectionGroupSWConversion(ADC_Type *ADCx)
{
    CLEAR_BIT(ADCx->CR1, ADC_CR1_JSTOP_Msk);
}

/**
  * @brief    Set ADC Regular Group
Trigger Edge
  * @rmtoll   CR2    RTRGCFG    FL_ADC_SetRegularGroupTriggerEdge
  * @param    ADCx ADC instance
  * @param    edge This parameter can be one of the following values:
  *           @arg @ref FL_ADC_RGTRIGGER_EDGE_NONE
  *           @arg @ref FL_ADC_RGTRIGGER_EDGE_RISING
  *           @arg @ref FL_ADC_RGTRIGGER_EDGE_FALLING
  *           @arg @ref FL_ADC_RGTRIGGER_EDGE_BOTH
  * @retval   None
  */
__STATIC_INLINE void FL_ADC_SetRegularGroupTriggerEdge(ADC_Type *ADCx, uint32_t edge)
{
    MODIFY_REG(ADCx->CR2, ADC_CR2_RTRGCFG_Msk, edge);
}

/**
  * @brief    Read ADC Regular Group
Trigger Edge
  * @rmtoll   CR2    RTRGCFG    FL_ADC_GetRegularGroupTriggerEdge
  * @param    ADCx ADC instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_ADC_RGTRIGGER_EDGE_NONE
  *           @arg @ref FL_ADC_RGTRIGGER_EDGE_RISING
  *           @arg @ref FL_ADC_RGTRIGGER_EDGE_FALLING
  *           @arg @ref FL_ADC_RGTRIGGER_EDGE_BOTH
  */
__STATIC_INLINE uint32_t FL_ADC_GetRegularGroupTriggerEdge(ADC_Type *ADCx)
{
    return (uint32_t)(READ_BIT(ADCx->CR2, ADC_CR2_RTRGCFG_Msk));
}

/**
  * @brief    Set ADC Injection Group
Trigger Edge
  * @rmtoll   CR2    JTRGCFG    FL_ADC_SetInjectionGroupTriggerEdge
  * @param    ADCx ADC instance
  * @param    edge This parameter can be one of the following values:
  *           @arg @ref FL_ADC_JGTRIGGER_EDGE_NONE
  *           @arg @ref FL_ADC_JGTRIGGER_EDGE_RISING
  *           @arg @ref FL_ADC_JGTRIGGER_EDGE_FALLING
  *           @arg @ref FL_ADC_JGTRIGGER_EDGE_BOTH
  * @retval   None
  */
__STATIC_INLINE void FL_ADC_SetInjectionGroupTriggerEdge(ADC_Type *ADCx, uint32_t edge)
{
    MODIFY_REG(ADCx->CR2, ADC_CR2_JTRGCFG_Msk, edge);
}

/**
  * @brief    Read ADC Injection Group
Trigger Edge
  * @rmtoll   CR2    JTRGCFG    FL_ADC_GetInjectionGroupTriggerEdge
  * @param    ADCx ADC instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_ADC_JGTRIGGER_EDGE_NONE
  *           @arg @ref FL_ADC_JGTRIGGER_EDGE_RISING
  *           @arg @ref FL_ADC_JGTRIGGER_EDGE_FALLING
  *           @arg @ref FL_ADC_JGTRIGGER_EDGE_BOTH
  */
__STATIC_INLINE uint32_t FL_ADC_GetInjectionGroupTriggerEdge(ADC_Type *ADCx)
{
    return (uint32_t)(READ_BIT(ADCx->CR2, ADC_CR2_JTRGCFG_Msk));
}

/**
  * @brief    Enable ADC Calibration
  * @rmtoll   CALR    CALEN    FL_ADC_EnableCalibration
  * @param    ADCx ADC instance
  * @retval   None
  */
__STATIC_INLINE void FL_ADC_EnableCalibration(ADC_Type *ADCx)
{
    SET_BIT(ADCx->CALR, ADC_CALR_CALEN_Msk);
}

/**
  * @brief    Disable ADC Calibration
  * @rmtoll   CALR    CALEN    FL_ADC_DisableCalibration
  * @param    ADCx ADC instance
  * @retval   None
  */
__STATIC_INLINE void FL_ADC_DisableCalibration(ADC_Type *ADCx)
{
    CLEAR_BIT(ADCx->CALR, ADC_CALR_CALEN_Msk);
}

/**
  * @brief    Get ADC Calibration Enable Status
  * @rmtoll   CALR    CALEN    FL_ADC_IsEnabledCalibration
  * @param    ADCx ADC instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_ADC_IsEnabledCalibration(ADC_Type *ADCx)
{
    return (uint32_t)(READ_BIT(ADCx->CALR, ADC_CALR_CALEN_Msk) == ADC_CALR_CALEN_Msk);
}

/**
  * @brief    Set ADC Digital Clock Delay
  * @rmtoll   CALR    CKDIG_DELAY    FL_ADC_SetDigitalClockDelay
  * @param    ADCx ADC instance
  * @param    time This parameter can be one of the following values:
  *           @arg @ref FL_ADC_CKDIG_DELAY_MIN
  *           @arg @ref FL_ADC_CKDIG_DELAY_MAX
  * @retval   None
  */
__STATIC_INLINE void FL_ADC_SetDigitalClockDelay(ADC_Type *ADCx, uint32_t time)
{
    MODIFY_REG(ADCx->CALR, ADC_CALR_CKDIG_DELAY_Msk, time);
}

/**
  * @brief    Read ADC Digital Clock Delay
  * @rmtoll   CALR    CKDIG_DELAY    FL_ADC_GetDigitalClockDelay
  * @param    ADCx ADC instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_ADC_CKDIG_DELAY_MIN
  *           @arg @ref FL_ADC_CKDIG_DELAY_MAX
  */
__STATIC_INLINE uint32_t FL_ADC_GetDigitalClockDelay(ADC_Type *ADCx)
{
    return (uint32_t)(READ_BIT(ADCx->CALR, ADC_CALR_CKDIG_DELAY_Msk));
}

/**
  * @brief    Set ADC Comparator Mode
  * @rmtoll   CALR    CMP_MODE    FL_ADC_SetComparatorMode
  * @param    ADCx ADC instance
  * @param    mode This parameter can be one of the following values:
  *           @arg @ref FL_ADC_CMP_MODE_Normal
  *           @arg @ref FL_ADC_CMP_MODE_Fast
  * @retval   None
  */
__STATIC_INLINE void FL_ADC_SetComparatorMode(ADC_Type *ADCx, uint32_t mode)
{
    MODIFY_REG(ADCx->CALR, ADC_CALR_CMP_MODE_Msk, mode);
}

/**
  * @brief    Read ADC Comparator Mode
  * @rmtoll   CALR    CMP_MODE    FL_ADC_GetComparatorMode
  * @param    ADCx ADC instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_ADC_CMP_MODE_Normal
  *           @arg @ref FL_ADC_CMP_MODE_Fast
  */
__STATIC_INLINE uint32_t FL_ADC_GetComparatorMode(ADC_Type *ADCx)
{
    return (uint32_t)(READ_BIT(ADCx->CALR, ADC_CALR_CMP_MODE_Msk));
}

/**
  * @brief    Set ADC Comparator Delay
  * @rmtoll   CALR    CMPRDY_DELAY    FL_ADC_SetComparatorDelay
  * @param    ADCx ADC instance
  * @param    time This parameter can be one of the following values:
  *           @arg @ref FL_ADC_CMP_DELAY_MIN
  *           @arg @ref FL_ADC_CMP_DELAY_MAX
  * @retval   None
  */
__STATIC_INLINE void FL_ADC_SetComparatorDelay(ADC_Type *ADCx, uint32_t time)
{
    MODIFY_REG(ADCx->CALR, ADC_CALR_CMPRDY_DELAY_Msk, time);
}

/**
  * @brief    Read ADC Comparator Delay
  * @rmtoll   CALR    CMPRDY_DELAY    FL_ADC_GetComparatorDelay
  * @param    ADCx ADC instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_ADC_CMP_DELAY_MIN
  *           @arg @ref FL_ADC_CMP_DELAY_MAX
  */
__STATIC_INLINE uint32_t FL_ADC_GetComparatorDelay(ADC_Type *ADCx)
{
    return (uint32_t)(READ_BIT(ADCx->CALR, ADC_CALR_CMPRDY_DELAY_Msk));
}

/**
  * @brief    Set ADC VCM Control Mode
  * @rmtoll   CALR    VCM_MODE    FL_ADC_SetVCMControlMode
  * @param    ADCx ADC instance
  * @param    mode This parameter can be one of the following values:
  *           @arg @ref FL_ADC_VCM_MODE_NORMAL
  *           @arg @ref FL_ADC_VCM_MODE_CONTINUOUS
  * @retval   None
  */
__STATIC_INLINE void FL_ADC_SetVCMControlMode(ADC_Type *ADCx, uint32_t mode)
{
    MODIFY_REG(ADCx->CALR, ADC_CALR_VCM_MODE_Msk, mode);
}

/**
  * @brief    Get ADC VCM Control Mode
  * @rmtoll   CALR    VCM_MODE    FL_ADC_GetVCMControlMode
  * @param    ADCx ADC instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_ADC_VCM_MODE_NORMAL
  *           @arg @ref FL_ADC_VCM_MODE_CONTINUOUS
  */
__STATIC_INLINE uint32_t FL_ADC_GetVCMControlMode(ADC_Type *ADCx)
{
    return (uint32_t)(READ_BIT(ADCx->CALR, ADC_CALR_VCM_MODE_Msk));
}

/**
  * @brief    Set ADC Offline Calibration Enable
  * @rmtoll   CALR    OFFL_EN    FL_ADC_SetOfflineCalibration
  * @param    ADCx ADC instance
  * @param    mode This parameter can be one of the following values:
  *           @arg @ref FL_ADC_CALIBRA_AUTO
  *           @arg @ref FL_ADC_CALIBRA_OFFLINE
  * @retval   None
  */
__STATIC_INLINE void FL_ADC_SetOfflineCalibration(ADC_Type *ADCx, uint32_t mode)
{
    MODIFY_REG(ADCx->CALR, ADC_CALR_OFFL_EN_Msk, mode);
}

/**
  * @brief    Get ADC Offline Calibration Enable Status
  * @rmtoll   CALR    OFFL_EN    FL_ADC_GetOfflineCalibration
  * @param    ADCx ADC instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_ADC_CALIBRA_AUTO
  *           @arg @ref FL_ADC_CALIBRA_OFFLINE
  */
__STATIC_INLINE uint32_t FL_ADC_GetOfflineCalibration(ADC_Type *ADCx)
{
    return (uint32_t)(READ_BIT(ADCx->CALR, ADC_CALR_OFFL_EN_Msk));
}

/**
  * @brief    Set ADC Reference Source
  * @rmtoll   CFGR1    PEFSEL    FL_ADC_SetReferenceSource
  * @param    ADCx ADC instance
  * @param    ref This parameter can be one of the following values:
  *           @arg @ref FL_ADC_REF_SOURCE_VDDA
  *           @arg @ref FL_ADC_REF_SOURCE_VREFP
  * @retval   None
  */
__STATIC_INLINE void FL_ADC_SetReferenceSource(ADC_Type *ADCx, uint32_t ref)
{
    MODIFY_REG(ADCx->CFGR1, ADC_CFGR1_PEFSEL_Msk, ref);
}

/**
  * @brief    Get ADC Reference Source
  * @rmtoll   CFGR1    PEFSEL    FL_ADC_GetReferenceSource
  * @param    ADCx ADC instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_ADC_REF_SOURCE_VDDA
  *           @arg @ref FL_ADC_REF_SOURCE_VREFP
  */
__STATIC_INLINE uint32_t FL_ADC_GetReferenceSource(ADC_Type *ADCx)
{
    return (uint32_t)(READ_BIT(ADCx->CFGR1, ADC_CFGR1_PEFSEL_Msk));
}

/**
  * @brief    Set ADC Working Clock
  * @rmtoll   CFGR1    CLKSEL    FL_ADC_SetClockSource
  * @param    ADCx ADC instance
  * @param    clock This parameter can be one of the following values:
  *           @arg @ref FL_ADC_CLK_SOURCE_ADCCLK
  *           @arg @ref FL_ADC_CLK_SOURCE_APBCLK
  * @retval   None
  */
__STATIC_INLINE void FL_ADC_SetClockSource(ADC_Type *ADCx, uint32_t clock)
{
    MODIFY_REG(ADCx->CFGR1, ADC_CFGR1_CLKSEL_Msk, clock);
}

/**
  * @brief    Get ADC Working Clock
  * @rmtoll   CFGR1    CLKSEL    FL_ADC_GetClockSource
  * @param    ADCx ADC instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_ADC_CLK_SOURCE_ADCCLK
  *           @arg @ref FL_ADC_CLK_SOURCE_APBCLK
  */
__STATIC_INLINE uint32_t FL_ADC_GetClockSource(ADC_Type *ADCx)
{
    return (uint32_t)(READ_BIT(ADCx->CFGR1, ADC_CFGR1_CLKSEL_Msk));
}

/**
  * @brief    Set ADC Output Bit Width
  * @rmtoll   CFGR1    BITSEL    FL_ADC_SetBitWidth
  * @param    ADCx ADC instance
  * @param    bitWidth This parameter can be one of the following values:
  *           @arg @ref FL_ADC_BIT_WIDTH_12B
  *           @arg @ref FL_ADC_BIT_WIDTH_10B
  *           @arg @ref FL_ADC_BIT_WIDTH_8B
  *           @arg @ref FL_ADC_BIT_WIDTH_6B
  * @retval   None
  */
__STATIC_INLINE void FL_ADC_SetBitWidth(ADC_Type *ADCx, uint32_t bitWidth)
{
    MODIFY_REG(ADCx->CFGR1, ADC_CFGR1_BITSEL_Msk, bitWidth);
}

/**
  * @brief    Get ADC Output Bit Width
  * @rmtoll   CFGR1    BITSEL    FL_ADC_GetBitWidth
  * @param    ADCx ADC instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_ADC_BIT_WIDTH_12B
  *           @arg @ref FL_ADC_BIT_WIDTH_10B
  *           @arg @ref FL_ADC_BIT_WIDTH_8B
  *           @arg @ref FL_ADC_BIT_WIDTH_6B
  */
__STATIC_INLINE uint32_t FL_ADC_GetBitWidth(ADC_Type *ADCx)
{
    return (uint32_t)(READ_BIT(ADCx->CFGR1, ADC_CFGR1_BITSEL_Msk));
}

/**
  * @brief    Set ADC APBCLK Prescaler 
  * @rmtoll   CFGR1    APBCLK_PSC    FL_ADC_SetAPBPrescaler
  * @param    ADCx ADC instance
  * @param    psc This parameter can be one of the following values:
  *           @arg @ref FL_ADC_APBCLK_PSC_DIV1
  *           @arg @ref FL_ADC_APBCLK_PSC_DIV2
  *           @arg @ref FL_ADC_APBCLK_PSC_DIV4
  *           @arg @ref FL_ADC_APBCLK_PSC_DIV8
  * @retval   None
  */
__STATIC_INLINE void FL_ADC_SetAPBPrescaler(ADC_Type *ADCx, uint32_t psc)
{
    MODIFY_REG(ADCx->CFGR1, ADC_CFGR1_APBCLK_PSC_Msk, psc);
}

/**
  * @brief    Get ADC APBCLK Prescaler
  * @rmtoll   CFGR1    APBCLK_PSC    FL_ADC_GetAPBPrescaler
  * @param    ADCx ADC instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_ADC_APBCLK_PSC_DIV1
  *           @arg @ref FL_ADC_APBCLK_PSC_DIV2
  *           @arg @ref FL_ADC_APBCLK_PSC_DIV4
  *           @arg @ref FL_ADC_APBCLK_PSC_DIV8
  */
__STATIC_INLINE uint32_t FL_ADC_GetAPBPrescaler(ADC_Type *ADCx)
{
    return (uint32_t)(READ_BIT(ADCx->CFGR1, ADC_CFGR1_APBCLK_PSC_Msk));
}

/**
  * @brief    Set ADC Negative Peference
  * @rmtoll   CFGR1    REFNSEL    FL_ADC_SetNegativePeference
  * @param    ADCx ADC instance
  * @param    mode This parameter can be one of the following values:
  *           @arg @ref FL_ADC_REF_NEGA_VSSA
  *           @arg @ref FL_ADC_REF_NEGA_VREFN
  * @retval   None
  */
__STATIC_INLINE void FL_ADC_SetNegativePeference(ADC_Type *ADCx, uint32_t mode)
{
    MODIFY_REG(ADCx->CFGR1, ADC_CFGR1_REFNSEL_Msk, mode);
}

/**
  * @brief    Get ADC Negative Peference 
  * @rmtoll   CFGR1    REFNSEL    FL_ADC_GetNegativePeference
  * @param    ADCx ADC instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_ADC_REF_NEGA_VSSA
  *           @arg @ref FL_ADC_REF_NEGA_VREFN
  */
__STATIC_INLINE uint32_t FL_ADC_GetNegativePeference(ADC_Type *ADCx)
{
    return (uint32_t)(READ_BIT(ADCx->CFGR1, ADC_CFGR1_REFNSEL_Msk));
}

/**
  * @brief    Enable ADC DMA
  * @rmtoll   CFGR2    DMAEN    FL_ADC_EnableDMAReq
  * @param    ADCx ADC instance
  * @retval   None
  */
__STATIC_INLINE void FL_ADC_EnableDMAReq(ADC_Type *ADCx)
{
    SET_BIT(ADCx->CFGR2, ADC_CFGR2_DMAEN_Msk);
}

/**
  * @brief    Disable ADC DMA
  * @rmtoll   CFGR2    DMAEN    FL_ADC_DisableDMAReq
  * @param    ADCx ADC instance
  * @retval   None
  */
__STATIC_INLINE void FL_ADC_DisableDMAReq(ADC_Type *ADCx)
{
    CLEAR_BIT(ADCx->CFGR2, ADC_CFGR2_DMAEN_Msk);
}

/**
  * @brief    Get ADC DMA Enable Status
  * @rmtoll   CFGR2    DMAEN    FL_ADC_IsEnabledDMAReq
  * @param    ADCx ADC instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_ADC_IsEnabledDMAReq(ADC_Type *ADCx)
{
    return (uint32_t)(READ_BIT(ADCx->CFGR2, ADC_CFGR2_DMAEN_Msk) == ADC_CFGR2_DMAEN_Msk);
}

/**
  * @brief    Set ADC Channel Scan Direction
  * @rmtoll   CFGR2    SCANDIR    FL_ADC_SetSequenceScanDirection
  * @param    ADCx ADC instance
  * @param    dir This parameter can be one of the following values:
  *           @arg @ref FL_ADC_SEQ_SCAN_DIR_FORWARD
  *           @arg @ref FL_ADC_SEQ_SCAN_DIR_BACKWARD
  * @retval   None
  */
__STATIC_INLINE void FL_ADC_SetSequenceScanDirection(ADC_Type *ADCx, uint32_t dir)
{
    MODIFY_REG(ADCx->CFGR2, ADC_CFGR2_SCANDIR_Msk, dir);
}

/**
  * @brief    Get ADC Channel Scan Direction
  * @rmtoll   CFGR2    SCANDIR    FL_ADC_GetSequenceScanDirection
  * @param    ADCx ADC instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_ADC_SEQ_SCAN_DIR_FORWARD
  *           @arg @ref FL_ADC_SEQ_SCAN_DIR_BACKWARD
  */
__STATIC_INLINE uint32_t FL_ADC_GetSequenceScanDirection(ADC_Type *ADCx)
{
    return (uint32_t)(READ_BIT(ADCx->CFGR2, ADC_CFGR2_SCANDIR_Msk));
}

/**
  * @brief    Set ADC Trigger Source
  * @rmtoll   CFGR2    EXTS    FL_ADC_SetTriggerSource
  * @param    ADCx ADC instance
  * @param    source This parameter can be one of the following values:
  *           @arg @ref FL_ADC_TRGI_ATIM
  *           @arg @ref FL_ADC_TRGI_TAU10
  *           @arg @ref FL_ADC_TRGI_TAU11
  *           @arg @ref FL_ADC_TRGI_TAU12
  *           @arg @ref FL_ADC_TRGI_GPTIM1
  *           @arg @ref FL_ADC_TRGI_GPTIM2
  *           @arg @ref FL_ADC_TRGI_BSTIM16
  *           @arg @ref FL_ADC_TRGI_LPTIM16
  *           @arg @ref FL_ADC_TRGI_COMP1
  *           @arg @ref FL_ADC_TRGI_COMP2
  *           @arg @ref FL_ADC_TRGI_RTCA
  *           @arg @ref FL_ADC_TRGI_TAU00
  *           @arg @ref FL_ADC_TRGI_TAU01
  *           @arg @ref FL_ADC_TRGI_TAU02
  *           @arg @ref FL_ADC_TRGI_TAU03
  *           @arg @ref FL_ADC_TRGI_LUT0
  * @retval   None
  */
__STATIC_INLINE void FL_ADC_SetTriggerSource(ADC_Type *ADCx, uint32_t source)
{
    MODIFY_REG(ADCx->CFGR2, ADC_CFGR2_EXTS_Msk, source);
}

/**
  * @brief    Get ADC Trigger Source
  * @rmtoll   CFGR2    EXTS    FL_ADC_GetTriggerSource
  * @param    ADCx ADC instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_ADC_TRGI_ATIM
  *           @arg @ref FL_ADC_TRGI_TAU10
  *           @arg @ref FL_ADC_TRGI_TAU11
  *           @arg @ref FL_ADC_TRGI_TAU12
  *           @arg @ref FL_ADC_TRGI_GPTIM1
  *           @arg @ref FL_ADC_TRGI_GPTIM2
  *           @arg @ref FL_ADC_TRGI_BSTIM16
  *           @arg @ref FL_ADC_TRGI_LPTIM16
  *           @arg @ref FL_ADC_TRGI_COMP1
  *           @arg @ref FL_ADC_TRGI_COMP2
  *           @arg @ref FL_ADC_TRGI_RTCA
  *           @arg @ref FL_ADC_TRGI_TAU00
  *           @arg @ref FL_ADC_TRGI_TAU01
  *           @arg @ref FL_ADC_TRGI_TAU02
  *           @arg @ref FL_ADC_TRGI_TAU03
  *           @arg @ref FL_ADC_TRGI_LUT0
  */
__STATIC_INLINE uint32_t FL_ADC_GetTriggerSource(ADC_Type *ADCx)
{
    return (uint32_t)(READ_BIT(ADCx->CFGR2, ADC_CFGR2_EXTS_Msk));
}

/**
  * @brief    Enable ADC Overrun Mode
  * @rmtoll   CFGR2    OVRM    FL_ADC_EnableOverrunMode
  * @param    ADCx ADC instance
  * @retval   None
  */
__STATIC_INLINE void FL_ADC_EnableOverrunMode(ADC_Type *ADCx)
{
    SET_BIT(ADCx->CFGR2, ADC_CFGR2_OVRM_Msk);
}

/**
  * @brief    Disable ADC Overrun Mode
  * @rmtoll   CFGR2    OVRM    FL_ADC_DisableOverrunMode
  * @param    ADCx ADC instance
  * @retval   None
  */
__STATIC_INLINE void FL_ADC_DisableOverrunMode(ADC_Type *ADCx)
{
    CLEAR_BIT(ADCx->CFGR2, ADC_CFGR2_OVRM_Msk);
}

/**
  * @brief    Get ADC Overrun Mode Enable Status
  * @rmtoll   CFGR2    OVRM    FL_ADC_IsEnabledOverrunMode
  * @param    ADCx ADC instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_ADC_IsEnabledOverrunMode(ADC_Type *ADCx)
{
    return (uint32_t)(READ_BIT(ADCx->CFGR2, ADC_CFGR2_OVRM_Msk) == ADC_CFGR2_OVRM_Msk);
}

/**
  * @brief    Set ADC Conversion Mode
  * @rmtoll   CFGR2    CONT    FL_ADC_SetConversionMode
  * @param    ADCx ADC instance
  * @param    mode This parameter can be one of the following values:
  *           @arg @ref FL_ADC_CONV_MODE_SINGLE
  *           @arg @ref FL_ADC_CONV_MODE_CONTINUOUS
  * @retval   None
  */
__STATIC_INLINE void FL_ADC_SetConversionMode(ADC_Type *ADCx, uint32_t mode)
{
    MODIFY_REG(ADCx->CFGR2, ADC_CFGR2_CONT_Msk, mode);
}

/**
  * @brief    Get ADC Conversion Mode
  * @rmtoll   CFGR2    CONT    FL_ADC_GetConversionMode
  * @param    ADCx ADC instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_ADC_CONV_MODE_SINGLE
  *           @arg @ref FL_ADC_CONV_MODE_CONTINUOUS
  */
__STATIC_INLINE uint32_t FL_ADC_GetConversionMode(ADC_Type *ADCx)
{
    return (uint32_t)(READ_BIT(ADCx->CFGR2, ADC_CFGR2_CONT_Msk));
}

/**
  * @brief    Enable ADC Wait Mode
  * @rmtoll   CFGR2    WAIT    FL_ADC_EnableWaitMode
  * @param    ADCx ADC instance
  * @retval   None
  */
__STATIC_INLINE void FL_ADC_EnableWaitMode(ADC_Type *ADCx)
{
    SET_BIT(ADCx->CFGR2, ADC_CFGR2_WAIT_Msk);
}

/**
  * @brief    Disable ADC Wait Mode
  * @rmtoll   CFGR2    WAIT    FL_ADC_DisableWaitMode
  * @param    ADCx ADC instance
  * @retval   None
  */
__STATIC_INLINE void FL_ADC_DisableWaitMode(ADC_Type *ADCx)
{
    CLEAR_BIT(ADCx->CFGR2, ADC_CFGR2_WAIT_Msk);
}

/**
  * @brief    Get ADC Wait Mode Enable Status
  * @rmtoll   CFGR2    WAIT    FL_ADC_IsEnabledWaitMode
  * @param    ADCx ADC instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_ADC_IsEnabledWaitMode(ADC_Type *ADCx)
{
    return (uint32_t)(READ_BIT(ADCx->CFGR2, ADC_CFGR2_WAIT_Msk) == ADC_CFGR2_WAIT_Msk);
}

/**
  * @brief    Set ADC Single Conversion Mode
  * @rmtoll   CFGR2    SEMI    FL_ADC_SetSingleConversionAutoMode
  * @param    ADCx ADC instance
  * @param    mode This parameter can be one of the following values:
  *           @arg @ref FL_ADC_SINGLE_CONV_MODE_AUTO
  *           @arg @ref FL_ADC_SINGLE_CONV_MODE_SEMIAUTO
  * @retval   None
  */
__STATIC_INLINE void FL_ADC_SetSingleConversionAutoMode(ADC_Type *ADCx, uint32_t mode)
{
    MODIFY_REG(ADCx->CFGR2, ADC_CFGR2_SEMI_Msk, mode);
}

/**
  * @brief    Get ADC Single Conversion Mode
  * @rmtoll   CFGR2    SEMI    FL_ADC_GetSingleConversionAutoMode
  * @param    ADCx ADC instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_ADC_SINGLE_CONV_MODE_AUTO
  *           @arg @ref FL_ADC_SINGLE_CONV_MODE_SEMIAUTO
  */
__STATIC_INLINE uint32_t FL_ADC_GetSingleConversionAutoMode(ADC_Type *ADCx)
{
    return (uint32_t)(READ_BIT(ADCx->CFGR2, ADC_CFGR2_SEMI_Msk));
}

/**
  * @brief    Enable ADC Trigger Filter
  * @rmtoll   CFGR2    IOTRFEN    FL_ADC_EnableTriggerFilter
  * @param    ADCx ADC instance
  * @retval   None
  */
__STATIC_INLINE void FL_ADC_EnableTriggerFilter(ADC_Type *ADCx)
{
    SET_BIT(ADCx->CFGR2, ADC_CFGR2_IOTRFEN_Msk);
}

/**
  * @brief    Disable ADC Trigger Filter
  * @rmtoll   CFGR2    IOTRFEN    FL_ADC_DisableTriggerFilter
  * @param    ADCx ADC instance
  * @retval   None
  */
__STATIC_INLINE void FL_ADC_DisableTriggerFilter(ADC_Type *ADCx)
{
    CLEAR_BIT(ADCx->CFGR2, ADC_CFGR2_IOTRFEN_Msk);
}

/**
  * @brief    Get ADC Trigger Filter Enable Status
  * @rmtoll   CFGR2    IOTRFEN    FL_ADC_IsEnabledTriggerFilter
  * @param    ADCx ADC instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_ADC_IsEnabledTriggerFilter(ADC_Type *ADCx)
{
    return (uint32_t)(READ_BIT(ADCx->CFGR2, ADC_CFGR2_IOTRFEN_Msk) == ADC_CFGR2_IOTRFEN_Msk);
}

/**
  * @brief    Enable ADC OverSampling
  * @rmtoll   CFGR2    OVSEN    FL_ADC_EnableOverSampling
  * @param    ADCx ADC instance
  * @retval   None
  */
__STATIC_INLINE void FL_ADC_EnableOverSampling(ADC_Type *ADCx)
{
    SET_BIT(ADCx->CFGR2, ADC_CFGR2_OVSEN_Msk);
}

/**
  * @brief    Disable ADC OverSampling
  * @rmtoll   CFGR2    OVSEN    FL_ADC_DisableOverSampling
  * @param    ADCx ADC instance
  * @retval   None
  */
__STATIC_INLINE void FL_ADC_DisableOverSampling(ADC_Type *ADCx)
{
    CLEAR_BIT(ADCx->CFGR2, ADC_CFGR2_OVSEN_Msk);
}

/**
  * @brief    Get ADC OverSampling Enable Status
  * @rmtoll   CFGR2    OVSEN    FL_ADC_IsEnabledOverSampling
  * @param    ADCx ADC instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_ADC_IsEnabledOverSampling(ADC_Type *ADCx)
{
    return (uint32_t)(READ_BIT(ADCx->CFGR2, ADC_CFGR2_OVSEN_Msk) == ADC_CFGR2_OVSEN_Msk);
}

/**
  * @brief    Set ADC OverSampling Multiplier
  * @rmtoll   CFGR2    OVSR    FL_ADC_SetOverSamplingMultiplier
  * @param    ADCx ADC instance
  * @param    mul This parameter can be one of the following values:
  *           @arg @ref FL_ADC_OVERSAMPLING_MUL_2X
  *           @arg @ref FL_ADC_OVERSAMPLING_MUL_4X
  *           @arg @ref FL_ADC_OVERSAMPLING_MUL_8X
  *           @arg @ref FL_ADC_OVERSAMPLING_MUL_16X
  *           @arg @ref FL_ADC_OVERSAMPLING_MUL_32X
  *           @arg @ref FL_ADC_OVERSAMPLING_MUL_64X
  *           @arg @ref FL_ADC_OVERSAMPLING_MUL_128X
  *           @arg @ref FL_ADC_OVERSAMPLING_MUL_256X
  * @retval   None
  */
__STATIC_INLINE void FL_ADC_SetOverSamplingMultiplier(ADC_Type *ADCx, uint32_t mul)
{
    MODIFY_REG(ADCx->CFGR2, ADC_CFGR2_OVSR_Msk, mul);
}

/**
  * @brief    Read ADC OverSampling Multiplier
  * @rmtoll   CFGR2    OVSR    FL_ADC_GetOverSamplingMultiplier
  * @param    ADCx ADC instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_ADC_OVERSAMPLING_MUL_2X
  *           @arg @ref FL_ADC_OVERSAMPLING_MUL_4X
  *           @arg @ref FL_ADC_OVERSAMPLING_MUL_8X
  *           @arg @ref FL_ADC_OVERSAMPLING_MUL_16X
  *           @arg @ref FL_ADC_OVERSAMPLING_MUL_32X
  *           @arg @ref FL_ADC_OVERSAMPLING_MUL_64X
  *           @arg @ref FL_ADC_OVERSAMPLING_MUL_128X
  *           @arg @ref FL_ADC_OVERSAMPLING_MUL_256X
  */
__STATIC_INLINE uint32_t FL_ADC_GetOverSamplingMultiplier(ADC_Type *ADCx)
{
    return (uint32_t)(READ_BIT(ADCx->CFGR2, ADC_CFGR2_OVSR_Msk));
}

/**
  * @brief    Set ADC OverSampling Shift
  * @rmtoll   CFGR2    OVSS    FL_ADC_SetOverSamplingShift
  * @param    ADCx ADC instance
  * @param    shift This parameter can be one of the following values:
  *           @arg @ref FL_ADC_OVERSAMPLING_SHIFT_0B
  *           @arg @ref FL_ADC_OVERSAMPLING_SHIFT_1B
  *           @arg @ref FL_ADC_OVERSAMPLING_SHIFT_2B
  *           @arg @ref FL_ADC_OVERSAMPLING_SHIFT_3B
  *           @arg @ref FL_ADC_OVERSAMPLING_SHIFT_4B
  *           @arg @ref FL_ADC_OVERSAMPLING_SHIFT_5B
  *           @arg @ref FL_ADC_OVERSAMPLING_SHIFT_6B
  *           @arg @ref FL_ADC_OVERSAMPLING_SHIFT_7B
  *           @arg @ref FL_ADC_OVERSAMPLING_SHIFT_8B
  * @retval   None
  */
__STATIC_INLINE void FL_ADC_SetOverSamplingShift(ADC_Type *ADCx, uint32_t shift)
{
    MODIFY_REG(ADCx->CFGR2, ADC_CFGR2_OVSS_Msk, shift);
}

/**
  * @brief    Read ADC OverSampling Shift
  * @rmtoll   CFGR2    OVSS    FL_ADC_GetOverSamplingShift
  * @param    ADCx ADC instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_ADC_OVERSAMPLING_SHIFT_0B
  *           @arg @ref FL_ADC_OVERSAMPLING_SHIFT_1B
  *           @arg @ref FL_ADC_OVERSAMPLING_SHIFT_2B
  *           @arg @ref FL_ADC_OVERSAMPLING_SHIFT_3B
  *           @arg @ref FL_ADC_OVERSAMPLING_SHIFT_4B
  *           @arg @ref FL_ADC_OVERSAMPLING_SHIFT_5B
  *           @arg @ref FL_ADC_OVERSAMPLING_SHIFT_6B
  *           @arg @ref FL_ADC_OVERSAMPLING_SHIFT_7B
  *           @arg @ref FL_ADC_OVERSAMPLING_SHIFT_8B
  */
__STATIC_INLINE uint32_t FL_ADC_GetOverSamplingShift(ADC_Type *ADCx)
{
    return (uint32_t)(READ_BIT(ADCx->CFGR2, ADC_CFGR2_OVSS_Msk));
}

/**
  * @brief    Enable ADC Analog WDG
  * @rmtoll   CFGR2    AWDEN    FL_ADC_EnableAnalogWDG
  * @param    ADCx ADC instance
  * @retval   None
  */
__STATIC_INLINE void FL_ADC_EnableAnalogWDG(ADC_Type *ADCx)
{
    SET_BIT(ADCx->CFGR2, ADC_CFGR2_AWDEN_Msk);
}

/**
  * @brief    Disable ADC Analog WDG
  * @rmtoll   CFGR2    AWDEN    FL_ADC_DisableAnalogWDG
  * @param    ADCx ADC instance
  * @retval   None
  */
__STATIC_INLINE void FL_ADC_DisableAnalogWDG(ADC_Type *ADCx)
{
    CLEAR_BIT(ADCx->CFGR2, ADC_CFGR2_AWDEN_Msk);
}

/**
  * @brief    Get ADC Analog WDG Enable Status
  * @rmtoll   CFGR2    AWDEN    FL_ADC_IsEnabledAnalogWDG
  * @param    ADCx ADC instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_ADC_IsEnabledAnalogWDG(ADC_Type *ADCx)
{
    return (uint32_t)(READ_BIT(ADCx->CFGR2, ADC_CFGR2_AWDEN_Msk) == ADC_CFGR2_AWDEN_Msk);
}

/**
  * @brief    Set ADC Analog WDG Monitor Mode
  * @rmtoll   CFGR2    AWDSC    FL_ADC_SetAnalogWDGMonitorMode
  * @param    ADCx ADC instance
  * @param    mode This parameter can be one of the following values:
  *           @arg @ref FL_ADC_AWDG_ALL_CHANNEL
  *           @arg @ref FL_ADC_AWDG_SINGLE_CHANNEL
  * @retval   None
  */
__STATIC_INLINE void FL_ADC_SetAnalogWDGMonitorMode(ADC_Type *ADCx, uint32_t mode)
{
    MODIFY_REG(ADCx->CFGR2, ADC_CFGR2_AWDSC_Msk, mode);
}

/**
  * @brief    Read ADC Analog WDG Monitor Mode
  * @rmtoll   CFGR2    AWDSC    FL_ADC_GetAnalogWDGMonitorMode
  * @param    ADCx ADC instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_ADC_AWDG_ALL_CHANNEL
  *           @arg @ref FL_ADC_AWDG_SINGLE_CHANNEL
  */
__STATIC_INLINE uint32_t FL_ADC_GetAnalogWDGMonitorMode(ADC_Type *ADCx)
{
    return (uint32_t)(READ_BIT(ADCx->CFGR2, ADC_CFGR2_AWDSC_Msk));
}

/**
  * @brief    Set ADC Analog WDG Monitor Channel
  * @rmtoll   CFGR2    AWDCH    FL_ADC_SetAnalogWDGMonitorChannel
  * @param    ADCx ADC instance
  * @param    monitorChannel This parameter can be one of the following values:
  *           @arg @ref FL_ADC_AWDG_CH0
  *           @arg @ref FL_ADC_AWDG_CH1
  *           @arg @ref FL_ADC_AWDG_CH2
  *           @arg @ref FL_ADC_AWDG_CH3
  *           @arg @ref FL_ADC_AWDG_CH4
  *           @arg @ref FL_ADC_AWDG_CH5
  *           @arg @ref FL_ADC_AWDG_CH6
  *           @arg @ref FL_ADC_AWDG_CH7
  *           @arg @ref FL_ADC_AWDG_CH8
  *           @arg @ref FL_ADC_AWDG_CH9
  *           @arg @ref FL_ADC_AWDG_CH10
  *           @arg @ref FL_ADC_AWDG_CH11
  *           @arg @ref FL_ADC_AWDG_CH12
  *           @arg @ref FL_ADC_AWDG_CH13
  *           @arg @ref FL_ADC_AWDG_CH14
  *           @arg @ref FL_ADC_AWDG_CH15
  *           @arg @ref FL_ADC_AWDG_CH16
  *           @arg @ref FL_ADC_AWDG_CH17
  *           @arg @ref FL_ADC_AWDG_CH18
  *           @arg @ref FL_ADC_AWDG_CH19
  *           @arg @ref FL_ADC_AWDG_CH20
  *           @arg @ref FL_ADC_AWDG_CH21
  *           @arg @ref FL_ADC_AWDG_CH22
  *           @arg @ref FL_ADC_AWDG_CH23
  *           @arg @ref FL_ADC_AWDG_CH24
  *           @arg @ref FL_ADC_AWDG_CH25
  *           @arg @ref FL_ADC_AWDG_CH26
  *           @arg @ref FL_ADC_AWDG_CH27
  *           @arg @ref FL_ADC_AWDG_CH28
  *           @arg @ref FL_ADC_AWDG_CH29
  *           @arg @ref FL_ADC_AWDG_CH30
  * @retval   None
  */
__STATIC_INLINE void FL_ADC_SetAnalogWDGMonitorChannel(ADC_Type *ADCx, uint32_t monitorChannel)
{
    MODIFY_REG(ADCx->CFGR2, ADC_CFGR2_AWDCH_Msk, monitorChannel);
}

/**
  * @brief    Read ADC Analog WDG Monitor Channel
  * @rmtoll   CFGR2    AWDCH    FL_ADC_GetAnalogWDGMonitorChannel
  * @param    ADCx ADC instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_ADC_AWDG_CH0
  *           @arg @ref FL_ADC_AWDG_CH1
  *           @arg @ref FL_ADC_AWDG_CH2
  *           @arg @ref FL_ADC_AWDG_CH3
  *           @arg @ref FL_ADC_AWDG_CH4
  *           @arg @ref FL_ADC_AWDG_CH5
  *           @arg @ref FL_ADC_AWDG_CH6
  *           @arg @ref FL_ADC_AWDG_CH7
  *           @arg @ref FL_ADC_AWDG_CH8
  *           @arg @ref FL_ADC_AWDG_CH9
  *           @arg @ref FL_ADC_AWDG_CH10
  *           @arg @ref FL_ADC_AWDG_CH11
  *           @arg @ref FL_ADC_AWDG_CH12
  *           @arg @ref FL_ADC_AWDG_CH13
  *           @arg @ref FL_ADC_AWDG_CH14
  *           @arg @ref FL_ADC_AWDG_CH15
  *           @arg @ref FL_ADC_AWDG_CH16
  *           @arg @ref FL_ADC_AWDG_CH17
  *           @arg @ref FL_ADC_AWDG_CH18
  *           @arg @ref FL_ADC_AWDG_CH19
  *           @arg @ref FL_ADC_AWDG_CH20
  *           @arg @ref FL_ADC_AWDG_CH21
  *           @arg @ref FL_ADC_AWDG_CH22
  *           @arg @ref FL_ADC_AWDG_CH23
  *           @arg @ref FL_ADC_AWDG_CH24
  *           @arg @ref FL_ADC_AWDG_CH25
  *           @arg @ref FL_ADC_AWDG_CH26
  *           @arg @ref FL_ADC_AWDG_CH27
  *           @arg @ref FL_ADC_AWDG_CH28
  *           @arg @ref FL_ADC_AWDG_CH29
  *           @arg @ref FL_ADC_AWDG_CH30
  */
__STATIC_INLINE uint32_t FL_ADC_GetAnalogWDGMonitorChannel(ADC_Type *ADCx)
{
    return (uint32_t)(READ_BIT(ADCx->CFGR2, ADC_CFGR2_AWDCH_Msk));
}

/**
  * @brief    Set ADC Slow Channel Sampling Time
  * @rmtoll   SMTR    SMTS1    FL_ADC_SetSlowChannelSamplingTime
  * @param    ADCx ADC instance
  * @param    time This parameter can be one of the following values:
  *           @arg @ref FL_ADC_SLOW_CH_SAMPLING_TIME_2_ADCCLK
  *           @arg @ref FL_ADC_SLOW_CH_SAMPLING_TIME_4_ADCCLK
  *           @arg @ref FL_ADC_SLOW_CH_SAMPLING_TIME_8_ADCCLK
  *           @arg @ref FL_ADC_SLOW_CH_SAMPLING_TIME_12_ADCCLK
  *           @arg @ref FL_ADC_SLOW_CH_SAMPLING_TIME_16_ADCCLK
  *           @arg @ref FL_ADC_SLOW_CH_SAMPLING_TIME_32_ADCCLK
  *           @arg @ref FL_ADC_SLOW_CH_SAMPLING_TIME_64_ADCCLK
  *           @arg @ref FL_ADC_SLOW_CH_SAMPLING_TIME_80_ADCCLK
  *           @arg @ref FL_ADC_SLOW_CH_SAMPLING_TIME_96_ADCCLK
  *           @arg @ref FL_ADC_SLOW_CH_SAMPLING_TIME_128_ADCCLK
  *           @arg @ref FL_ADC_SLOW_CH_SAMPLING_TIME_160_ADCCLK
  *           @arg @ref FL_ADC_SLOW_CH_SAMPLING_TIME_192_ADCCLK
  *           @arg @ref FL_ADC_SLOW_CH_SAMPLING_TIME_256_ADCCLK
  *           @arg @ref FL_ADC_SLOW_CH_SAMPLING_TIME_320_ADCCLK
  *           @arg @ref FL_ADC_SLOW_CH_SAMPLING_TIME_384_ADCCLK
  *           @arg @ref FL_ADC_SLOW_CH_SAMPLING_TIME_512_ADCCLK
  * @retval   None
  */
__STATIC_INLINE void FL_ADC_SetSlowChannelSamplingTime(ADC_Type *ADCx, uint32_t time)
{
    MODIFY_REG(ADCx->SMTR, ADC_SMTR_SMTS1_Msk, time);
}

/**
  * @brief    Read ADC Slow Channel Sampling Time
  * @rmtoll   SMTR    SMTS1    FL_ADC_GetSlowChannelSamplingTime
  * @param    ADCx ADC instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_ADC_SLOW_CH_SAMPLING_TIME_2_ADCCLK
  *           @arg @ref FL_ADC_SLOW_CH_SAMPLING_TIME_4_ADCCLK
  *           @arg @ref FL_ADC_SLOW_CH_SAMPLING_TIME_8_ADCCLK
  *           @arg @ref FL_ADC_SLOW_CH_SAMPLING_TIME_12_ADCCLK
  *           @arg @ref FL_ADC_SLOW_CH_SAMPLING_TIME_16_ADCCLK
  *           @arg @ref FL_ADC_SLOW_CH_SAMPLING_TIME_32_ADCCLK
  *           @arg @ref FL_ADC_SLOW_CH_SAMPLING_TIME_64_ADCCLK
  *           @arg @ref FL_ADC_SLOW_CH_SAMPLING_TIME_80_ADCCLK
  *           @arg @ref FL_ADC_SLOW_CH_SAMPLING_TIME_96_ADCCLK
  *           @arg @ref FL_ADC_SLOW_CH_SAMPLING_TIME_128_ADCCLK
  *           @arg @ref FL_ADC_SLOW_CH_SAMPLING_TIME_160_ADCCLK
  *           @arg @ref FL_ADC_SLOW_CH_SAMPLING_TIME_192_ADCCLK
  *           @arg @ref FL_ADC_SLOW_CH_SAMPLING_TIME_256_ADCCLK
  *           @arg @ref FL_ADC_SLOW_CH_SAMPLING_TIME_320_ADCCLK
  *           @arg @ref FL_ADC_SLOW_CH_SAMPLING_TIME_384_ADCCLK
  *           @arg @ref FL_ADC_SLOW_CH_SAMPLING_TIME_512_ADCCLK
  */
__STATIC_INLINE uint32_t FL_ADC_GetSlowChannelSamplingTime(ADC_Type *ADCx)
{
    return (uint32_t)(READ_BIT(ADCx->SMTR, ADC_SMTR_SMTS1_Msk));
}

/**
  * @brief    Set ADC Fast Channel Sampling Time
  * @rmtoll   SMTR    SMTS2    FL_ADC_SetFastChannelSamplingTime
  * @param    ADCx ADC instance
  * @param    time This parameter can be one of the following values:
  *           @arg @ref FL_ADC_FAST_CH_SAMPLING_TIME_2_ADCCLK
  *           @arg @ref FL_ADC_FAST_CH_SAMPLING_TIME_4_ADCCLK
  *           @arg @ref FL_ADC_FAST_CH_SAMPLING_TIME_8_ADCCLK
  *           @arg @ref FL_ADC_FAST_CH_SAMPLING_TIME_12_ADCCLK
  *           @arg @ref FL_ADC_FAST_CH_SAMPLING_TIME_16_ADCCLK
  *           @arg @ref FL_ADC_FAST_CH_SAMPLING_TIME_32_ADCCLK
  *           @arg @ref FL_ADC_FAST_CH_SAMPLING_TIME_64_ADCCLK
  *           @arg @ref FL_ADC_FAST_CH_SAMPLING_TIME_80_ADCCLK
  *           @arg @ref FL_ADC_FAST_CH_SAMPLING_TIME_96_ADCCLK
  *           @arg @ref FL_ADC_FAST_CH_SAMPLING_TIME_128_ADCCLK
  *           @arg @ref FL_ADC_FAST_CH_SAMPLING_TIME_160_ADCCLK
  *           @arg @ref FL_ADC_FAST_CH_SAMPLING_TIME_192_ADCCLK
  *           @arg @ref FL_ADC_FAST_CH_SAMPLING_TIME_256_ADCCLK
  *           @arg @ref FL_ADC_FAST_CH_SAMPLING_TIME_320_ADCCLK
  *           @arg @ref FL_ADC_FAST_CH_SAMPLING_TIME_384_ADCCLK
  *           @arg @ref FL_ADC_FAST_CH_SAMPLING_TIME_512_ADCCLK
  * @retval   None
  */
__STATIC_INLINE void FL_ADC_SetFastChannelSamplingTime(ADC_Type *ADCx, uint32_t time)
{
    MODIFY_REG(ADCx->SMTR, ADC_SMTR_SMTS2_Msk, time);
}

/**
  * @brief    Read ADC Fast Channel Sampling Time
  * @rmtoll   SMTR    SMTS2    FL_ADC_GetFastChannelSamplingTime
  * @param    ADCx ADC instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_ADC_FAST_CH_SAMPLING_TIME_2_ADCCLK
  *           @arg @ref FL_ADC_FAST_CH_SAMPLING_TIME_4_ADCCLK
  *           @arg @ref FL_ADC_FAST_CH_SAMPLING_TIME_8_ADCCLK
  *           @arg @ref FL_ADC_FAST_CH_SAMPLING_TIME_12_ADCCLK
  *           @arg @ref FL_ADC_FAST_CH_SAMPLING_TIME_16_ADCCLK
  *           @arg @ref FL_ADC_FAST_CH_SAMPLING_TIME_32_ADCCLK
  *           @arg @ref FL_ADC_FAST_CH_SAMPLING_TIME_64_ADCCLK
  *           @arg @ref FL_ADC_FAST_CH_SAMPLING_TIME_80_ADCCLK
  *           @arg @ref FL_ADC_FAST_CH_SAMPLING_TIME_96_ADCCLK
  *           @arg @ref FL_ADC_FAST_CH_SAMPLING_TIME_128_ADCCLK
  *           @arg @ref FL_ADC_FAST_CH_SAMPLING_TIME_160_ADCCLK
  *           @arg @ref FL_ADC_FAST_CH_SAMPLING_TIME_192_ADCCLK
  *           @arg @ref FL_ADC_FAST_CH_SAMPLING_TIME_256_ADCCLK
  *           @arg @ref FL_ADC_FAST_CH_SAMPLING_TIME_320_ADCCLK
  *           @arg @ref FL_ADC_FAST_CH_SAMPLING_TIME_384_ADCCLK
  *           @arg @ref FL_ADC_FAST_CH_SAMPLING_TIME_512_ADCCLK
  */
__STATIC_INLINE uint32_t FL_ADC_GetFastChannelSamplingTime(ADC_Type *ADCx)
{
    return (uint32_t)(READ_BIT(ADCx->SMTR, ADC_SMTR_SMTS2_Msk));
}

/**
  * @brief    Enable ADC External Channel
  * @rmtoll   ECHER        FL_ADC_EnableExternalSequencerChannel
  * @param    ADCx ADC instance
  * @param    channel This parameter can be one of the following values:
  *           @arg @ref FL_ADC_EXTERNAL_CH0
  *           @arg @ref FL_ADC_EXTERNAL_CH1
  *           @arg @ref FL_ADC_EXTERNAL_CH2
  *           @arg @ref FL_ADC_EXTERNAL_CH3
  *           @arg @ref FL_ADC_EXTERNAL_CH4
  *           @arg @ref FL_ADC_EXTERNAL_CH5
  *           @arg @ref FL_ADC_EXTERNAL_CH6
  *           @arg @ref FL_ADC_EXTERNAL_CH7
  *           @arg @ref FL_ADC_EXTERNAL_CH8
  *           @arg @ref FL_ADC_EXTERNAL_CH9
  *           @arg @ref FL_ADC_EXTERNAL_CH10
  *           @arg @ref FL_ADC_EXTERNAL_CH11
  *           @arg @ref FL_ADC_EXTERNAL_CH12
  *           @arg @ref FL_ADC_EXTERNAL_CH13
  *           @arg @ref FL_ADC_EXTERNAL_CH14
  *           @arg @ref FL_ADC_EXTERNAL_CH15
  *           @arg @ref FL_ADC_EXTERNAL_CH16
  *           @arg @ref FL_ADC_EXTERNAL_CH17
  *           @arg @ref FL_ADC_EXTERNAL_CH18
  *           @arg @ref FL_ADC_EXTERNAL_CH19
  *           @arg @ref FL_ADC_EXTERNAL_CH20
  *           @arg @ref FL_ADC_EXTERNAL_CH21
  *           @arg @ref FL_ADC_EXTERNAL_CH22
  *           @arg @ref FL_ADC_EXTERNAL_CH23
  *           @arg @ref FL_ADC_EXTERNAL_CH24
  *           @arg @ref FL_ADC_EXTERNAL_CH25
  *           @arg @ref FL_ADC_EXTERNAL_CH26
  *           @arg @ref FL_ADC_EXTERNAL_CH27
  *           @arg @ref FL_ADC_EXTERNAL_CH28
  *           @arg @ref FL_ADC_EXTERNAL_CH29
  *           @arg @ref FL_ADC_EXTERNAL_CH30
  * @retval   None
  */
__STATIC_INLINE void FL_ADC_EnableExternalSequencerChannel(ADC_Type *ADCx, uint32_t channel)
{
    SET_BIT(ADCx->ECHER, ((channel & 0xffffffff) << 0x0U));
}

/**
  * @brief    Disable ADC External Channel
  * @rmtoll   ECHER        FL_ADC_DisableExternalSequencerChannel
  * @param    ADCx ADC instance
  * @param    channel This parameter can be one of the following values:
  *           @arg @ref FL_ADC_EXTERNAL_CH0
  *           @arg @ref FL_ADC_EXTERNAL_CH1
  *           @arg @ref FL_ADC_EXTERNAL_CH2
  *           @arg @ref FL_ADC_EXTERNAL_CH3
  *           @arg @ref FL_ADC_EXTERNAL_CH4
  *           @arg @ref FL_ADC_EXTERNAL_CH5
  *           @arg @ref FL_ADC_EXTERNAL_CH6
  *           @arg @ref FL_ADC_EXTERNAL_CH7
  *           @arg @ref FL_ADC_EXTERNAL_CH8
  *           @arg @ref FL_ADC_EXTERNAL_CH9
  *           @arg @ref FL_ADC_EXTERNAL_CH10
  *           @arg @ref FL_ADC_EXTERNAL_CH11
  *           @arg @ref FL_ADC_EXTERNAL_CH12
  *           @arg @ref FL_ADC_EXTERNAL_CH13
  *           @arg @ref FL_ADC_EXTERNAL_CH14
  *           @arg @ref FL_ADC_EXTERNAL_CH15
  *           @arg @ref FL_ADC_EXTERNAL_CH16
  *           @arg @ref FL_ADC_EXTERNAL_CH17
  *           @arg @ref FL_ADC_EXTERNAL_CH18
  *           @arg @ref FL_ADC_EXTERNAL_CH19
  *           @arg @ref FL_ADC_EXTERNAL_CH20
  *           @arg @ref FL_ADC_EXTERNAL_CH21
  *           @arg @ref FL_ADC_EXTERNAL_CH22
  *           @arg @ref FL_ADC_EXTERNAL_CH23
  *           @arg @ref FL_ADC_EXTERNAL_CH24
  *           @arg @ref FL_ADC_EXTERNAL_CH25
  *           @arg @ref FL_ADC_EXTERNAL_CH26
  *           @arg @ref FL_ADC_EXTERNAL_CH27
  *           @arg @ref FL_ADC_EXTERNAL_CH28
  *           @arg @ref FL_ADC_EXTERNAL_CH29
  *           @arg @ref FL_ADC_EXTERNAL_CH30
  * @retval   None
  */
__STATIC_INLINE void FL_ADC_DisableExternalSequencerChannel(ADC_Type *ADCx, uint32_t channel)
{
    CLEAR_BIT(ADCx->ECHER, ((channel & 0xffffffff) << 0x0U));
}

/**
  * @brief    Get ADC External Channel Enable Status
  * @rmtoll   ECHER        FL_ADC_IsEnabledExternalSequencerChannel
  * @param    ADCx ADC instance
  * @param    channel This parameter can be one of the following values:
  *           @arg @ref FL_ADC_EXTERNAL_CH0
  *           @arg @ref FL_ADC_EXTERNAL_CH1
  *           @arg @ref FL_ADC_EXTERNAL_CH2
  *           @arg @ref FL_ADC_EXTERNAL_CH3
  *           @arg @ref FL_ADC_EXTERNAL_CH4
  *           @arg @ref FL_ADC_EXTERNAL_CH5
  *           @arg @ref FL_ADC_EXTERNAL_CH6
  *           @arg @ref FL_ADC_EXTERNAL_CH7
  *           @arg @ref FL_ADC_EXTERNAL_CH8
  *           @arg @ref FL_ADC_EXTERNAL_CH9
  *           @arg @ref FL_ADC_EXTERNAL_CH10
  *           @arg @ref FL_ADC_EXTERNAL_CH11
  *           @arg @ref FL_ADC_EXTERNAL_CH12
  *           @arg @ref FL_ADC_EXTERNAL_CH13
  *           @arg @ref FL_ADC_EXTERNAL_CH14
  *           @arg @ref FL_ADC_EXTERNAL_CH15
  *           @arg @ref FL_ADC_EXTERNAL_CH16
  *           @arg @ref FL_ADC_EXTERNAL_CH17
  *           @arg @ref FL_ADC_EXTERNAL_CH18
  *           @arg @ref FL_ADC_EXTERNAL_CH19
  *           @arg @ref FL_ADC_EXTERNAL_CH20
  *           @arg @ref FL_ADC_EXTERNAL_CH21
  *           @arg @ref FL_ADC_EXTERNAL_CH22
  *           @arg @ref FL_ADC_EXTERNAL_CH23
  *           @arg @ref FL_ADC_EXTERNAL_CH24
  *           @arg @ref FL_ADC_EXTERNAL_CH25
  *           @arg @ref FL_ADC_EXTERNAL_CH26
  *           @arg @ref FL_ADC_EXTERNAL_CH27
  *           @arg @ref FL_ADC_EXTERNAL_CH28
  *           @arg @ref FL_ADC_EXTERNAL_CH29
  *           @arg @ref FL_ADC_EXTERNAL_CH30
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_ADC_IsEnabledExternalSequencerChannel(ADC_Type *ADCx, uint32_t channel)
{
    return (uint32_t)(READ_BIT(ADCx->ECHER, ((channel & 0xffffffff) << 0x0U)) == ((channel & 0xffffffff) << 0x0U));
}

/**
  * @brief    Enable ADC Internal Channel
  * @rmtoll   ICHER        FL_ADC_EnableInternalSequencerChannel
  * @param    ADCx ADC instance
  * @param    channel This parameter can be one of the following values:
  *           @arg @ref FL_ADC_INTERNAL_DAC
  *           @arg @ref FL_ADC_INTERNAL_TS
  *           @arg @ref FL_ADC_INTERNAL_AVREF
  * @retval   None
  */
__STATIC_INLINE void FL_ADC_EnableInternalSequencerChannel(ADC_Type *ADCx, uint32_t channel)
{
    SET_BIT(ADCx->ICHER, ((channel & 0x7) << 0x0U));
}

/**
  * @brief    Disable ADC Internal Channel
  * @rmtoll   ICHER        FL_ADC_DisableInternalSequencerChannel
  * @param    ADCx ADC instance
  * @param    channel This parameter can be one of the following values:
  *           @arg @ref FL_ADC_INTERNAL_DAC
  *           @arg @ref FL_ADC_INTERNAL_TS
  *           @arg @ref FL_ADC_INTERNAL_AVREF
  * @retval   None
  */
__STATIC_INLINE void FL_ADC_DisableInternalSequencerChannel(ADC_Type *ADCx, uint32_t channel)
{
    CLEAR_BIT(ADCx->ICHER, ((channel & 0x7) << 0x0U));
}

/**
  * @brief    Get ADC Internal Channel Enable Status
  * @rmtoll   ICHER        FL_ADC_IsEnabledInternalSequencerChannel
  * @param    ADCx ADC instance
  * @param    channel This parameter can be one of the following values:
  *           @arg @ref FL_ADC_INTERNAL_DAC
  *           @arg @ref FL_ADC_INTERNAL_TS
  *           @arg @ref FL_ADC_INTERNAL_AVREF
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_ADC_IsEnabledInternalSequencerChannel(ADC_Type *ADCx, uint32_t channel)
{
    return (uint32_t)(READ_BIT(ADCx->ICHER, ((channel & 0x7) << 0x0U)) == ((channel & 0x7) << 0x0U));
}

/**
  * @brief    Get ADC Conversion Data
  * @rmtoll   DR    DATA    FL_ADC_ReadConversionData
  * @param    ADCx ADC instance
  * @retval   
  */
__STATIC_INLINE uint32_t FL_ADC_ReadConversionData(ADC_Type *ADCx)
{
    return (uint32_t)(READ_BIT(ADCx->DR, (0xffffU << 0U)) >> 0U);
}

/**
  * @brief    Get ADC Conversion Channel
  * @rmtoll   DR    CHID    FL_ADC_GetConversionChannel
  * @param    ADCx ADC instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_ADC_CONV_CHANNEL_CH0
  *           @arg @ref FL_ADC_CONV_CHANNEL_CH1
  *           @arg @ref FL_ADC_CONV_CHANNEL_CH2
  *           @arg @ref FL_ADC_CONV_CHANNEL_CH3
  *           @arg @ref FL_ADC_CONV_CHANNEL_CH4
  *           @arg @ref FL_ADC_CONV_CHANNEL_CH5
  *           @arg @ref FL_ADC_CONV_CHANNEL_CH6
  *           @arg @ref FL_ADC_CONV_CHANNEL_CH7
  *           @arg @ref FL_ADC_CONV_CHANNEL_CH8
  *           @arg @ref FL_ADC_CONV_CHANNEL_CH9
  *           @arg @ref FL_ADC_CONV_CHANNEL_CH10
  *           @arg @ref FL_ADC_CONV_CHANNEL_CH11
  *           @arg @ref FL_ADC_CONV_CHANNEL_CH12
  *           @arg @ref FL_ADC_CONV_CHANNEL_CH13
  *           @arg @ref FL_ADC_CONV_CHANNEL_CH14
  *           @arg @ref FL_ADC_CONV_CHANNEL_CH15
  *           @arg @ref FL_ADC_CONV_CHANNEL_CH16
  *           @arg @ref FL_ADC_CONV_CHANNEL_CH17
  *           @arg @ref FL_ADC_CONV_CHANNEL_CH18
  *           @arg @ref FL_ADC_CONV_CHANNEL_CH19
  *           @arg @ref FL_ADC_CONV_CHANNEL_CH20
  *           @arg @ref FL_ADC_CONV_CHANNEL_CH21
  *           @arg @ref FL_ADC_CONV_CHANNEL_CH22
  *           @arg @ref FL_ADC_CONV_CHANNEL_CH23
  *           @arg @ref FL_ADC_CONV_CHANNEL_CH24
  *           @arg @ref FL_ADC_CONV_CHANNEL_CH25
  *           @arg @ref FL_ADC_CONV_CHANNEL_CH26
  *           @arg @ref FL_ADC_CONV_CHANNEL_CH27
  *           @arg @ref FL_ADC_CONV_CHANNEL_CH28
  *           @arg @ref FL_ADC_CONV_CHANNEL_CH29
  *           @arg @ref FL_ADC_CONV_CHANNEL_CH30
  *           @arg @ref FL_ADC_CONV_CHANNEL_TS
  *           @arg @ref FL_ADC_CONV_CHANNEL_AVREF
  *           @arg @ref FL_ADC_CONV_CHANNEL_DAC
  */
__STATIC_INLINE uint32_t FL_ADC_GetConversionChannel(ADC_Type *ADCx)
{
    return (uint32_t)(READ_BIT(ADCx->DR, ADC_DR_CHID_Msk));
}

/**
  * @brief    Write ADC Analog Watchdog Under Low
  * @rmtoll   HLTR    AWD_LT    FL_ADC_WriteAnalogWDGLowThreshold
  * @param    ADCx ADC instance
  * @param    threshold 
  * @retval   None
  */
__STATIC_INLINE void FL_ADC_WriteAnalogWDGLowThreshold(ADC_Type *ADCx, uint32_t threshold)
{
    MODIFY_REG(ADCx->HLTR, (0xffffU << 0U), (threshold << 0U));
}

/**
  * @brief    Read ADC Analog Watchdog Under Low
  * @rmtoll   HLTR    AWD_LT    FL_ADC_ReadAnalogWDGLowThreshold
  * @param    ADCx ADC instance
  * @retval   
  */
__STATIC_INLINE uint32_t FL_ADC_ReadAnalogWDGLowThreshold(ADC_Type *ADCx)
{
    return (uint32_t)(READ_BIT(ADCx->HLTR, (0xffffU << 0U)) >> 0U);
}

/**
  * @brief    Write ADC Analog Watchdog Above High
  * @rmtoll   HLTR    AWD_HT    FL_ADC_WriteAnalogWDGHighThreshold
  * @param    ADCx ADC instance
  * @param    threshold 
  * @retval   None
  */
__STATIC_INLINE void FL_ADC_WriteAnalogWDGHighThreshold(ADC_Type *ADCx, uint32_t threshold)
{
    MODIFY_REG(ADCx->HLTR, (0xffffU << 16U), (threshold << 16U));
}

/**
  * @brief    Read ADC Analog Watchdog Above High
  * @rmtoll   HLTR    AWD_HT    FL_ADC_ReadAnalogWDGHighThreshold
  * @param    ADCx ADC instance
  * @retval   
  */
__STATIC_INLINE uint32_t FL_ADC_ReadAnalogWDGHighThreshold(ADC_Type *ADCx)
{
    return (uint32_t)(READ_BIT(ADCx->HLTR, (0xffffU << 16U)) >> 16U);
}

/**
  * @brief    Set ADC Injection Group External Trriger Source
  * @rmtoll   JGCFGR    JEXTS    FL_ADC_SetInjectionGroupExternalTrigerSouce
  * @param    ADCx ADC instance
  * @param    source This parameter can be one of the following values:
  *           @arg @ref FL_ADC_JG_EXTS_ATIM_TRGO
  *           @arg @ref FL_ADC_JG_EXTS_TAU10_TRGO
  *           @arg @ref FL_ADC_JG_EXTS_TAU11_TRGO
  *           @arg @ref FL_ADC_JG_EXTS_TAU12_TRGO
  *           @arg @ref FL_ADC_JG_EXTS_GPTIM1_TRGO
  *           @arg @ref FL_ADC_JG_EXTS_GPTIM2_TRGO
  *           @arg @ref FL_ADC_JG_EXTS_BSTIM16_TRGO
  *           @arg @ref FL_ADC_JG_EXTS_LPTIM16_TRGO
  *           @arg @ref FL_ADC_JG_EXTS_COMP1_TRGO
  *           @arg @ref FL_ADC_JG_EXTS_COMP2_TRGO
  *           @arg @ref FL_ADC_JG_EXTS_RTC_TRGO
  *           @arg @ref FL_ADC_JG_EXTS_TAU00_TRGO
  *           @arg @ref FL_ADC_JG_EXTS_TAU01_TRGO
  *           @arg @ref FL_ADC_JG_EXTS_TAU02_TRGO
  *           @arg @ref FL_ADC_JG_EXTS_TAU03_TRGO
  *           @arg @ref FL_ADC_JG_EXTS_LUT0_TRGO
  * @retval   None
  */
__STATIC_INLINE void FL_ADC_SetInjectionGroupExternalTrigerSouce(ADC_Type *ADCx, uint32_t source)
{
    MODIFY_REG(ADCx->JGCFGR, ADC_JGCFGR_JEXTS_Msk, source);
}

/**
  * @brief    Get ADC Injection Group External Trriger Source
  * @rmtoll   JGCFGR    JEXTS    FL_ADC_GetInjectionGroupExternalTrigerSouce
  * @param    ADCx ADC instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_ADC_JG_EXTS_ATIM_TRGO
  *           @arg @ref FL_ADC_JG_EXTS_TAU10_TRGO
  *           @arg @ref FL_ADC_JG_EXTS_TAU11_TRGO
  *           @arg @ref FL_ADC_JG_EXTS_TAU12_TRGO
  *           @arg @ref FL_ADC_JG_EXTS_GPTIM1_TRGO
  *           @arg @ref FL_ADC_JG_EXTS_GPTIM2_TRGO
  *           @arg @ref FL_ADC_JG_EXTS_BSTIM16_TRGO
  *           @arg @ref FL_ADC_JG_EXTS_LPTIM16_TRGO
  *           @arg @ref FL_ADC_JG_EXTS_COMP1_TRGO
  *           @arg @ref FL_ADC_JG_EXTS_COMP2_TRGO
  *           @arg @ref FL_ADC_JG_EXTS_RTC_TRGO
  *           @arg @ref FL_ADC_JG_EXTS_TAU00_TRGO
  *           @arg @ref FL_ADC_JG_EXTS_TAU01_TRGO
  *           @arg @ref FL_ADC_JG_EXTS_TAU02_TRGO
  *           @arg @ref FL_ADC_JG_EXTS_TAU03_TRGO
  *           @arg @ref FL_ADC_JG_EXTS_LUT0_TRGO
  */
__STATIC_INLINE uint32_t FL_ADC_GetInjectionGroupExternalTrigerSouce(ADC_Type *ADCx)
{
    return (uint32_t)(READ_BIT(ADCx->JGCFGR, ADC_JGCFGR_JEXTS_Msk));
}

/**
  * @brief    Set ADC Injection Mode
  * @rmtoll   JGCFGR    JMOD    FL_ADC_SetInjectionMode
  * @param    ADCx ADC instance
  * @param    mode This parameter can be one of the following values:
  *           @arg @ref FL_ADC_JG_MODE_IMMEDIATE
  *           @arg @ref FL_ADC_JG_MODE_DELAYED
  * @retval   None
  */
__STATIC_INLINE void FL_ADC_SetInjectionMode(ADC_Type *ADCx, uint32_t mode)
{
    MODIFY_REG(ADCx->JGCFGR, ADC_JGCFGR_JMOD_Msk, mode);
}

/**
  * @brief    Get ADC Injection Mode
  * @rmtoll   JGCFGR    JMOD    FL_ADC_GetInjectionMode
  * @param    ADCx ADC instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_ADC_JG_MODE_IMMEDIATE
  *           @arg @ref FL_ADC_JG_MODE_DELAYED
  */
__STATIC_INLINE uint32_t FL_ADC_GetInjectionMode(ADC_Type *ADCx)
{
    return (uint32_t)(READ_BIT(ADCx->JGCFGR, ADC_JGCFGR_JMOD_Msk));
}

/**
  * @brief    Set ADC Injection Group Conversion Length
  * @rmtoll   JGCFGR    JL    FL_ADC_SetInjectionGroupConversionLength
  * @param    ADCx ADC instance
  * @param    length This parameter can be one of the following values:
  *           @arg @ref FL_ADC_JG_LENGTH_0L
  *           @arg @ref FL_ADC_JG_LENGTH_1L
  *           @arg @ref FL_ADC_JG_LENGTH_2L
  *           @arg @ref FL_ADC_JG_LENGTH_3L
  *           @arg @ref FL_ADC_JG_LENGTH_4L
  * @retval   None
  */
__STATIC_INLINE void FL_ADC_SetInjectionGroupConversionLength(ADC_Type *ADCx, uint32_t length)
{
    MODIFY_REG(ADCx->JGCFGR, ADC_JGCFGR_JL_Msk, length);
}

/**
  * @brief    Get ADC Injection Group Conversion Length
  * @rmtoll   JGCFGR    JL    FL_ADC_GetInjectionGroupConversionLength
  * @param    ADCx ADC instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_ADC_JG_LENGTH_0L
  *           @arg @ref FL_ADC_JG_LENGTH_1L
  *           @arg @ref FL_ADC_JG_LENGTH_2L
  *           @arg @ref FL_ADC_JG_LENGTH_3L
  *           @arg @ref FL_ADC_JG_LENGTH_4L
  */
__STATIC_INLINE uint32_t FL_ADC_GetInjectionGroupConversionLength(ADC_Type *ADCx)
{
    return (uint32_t)(READ_BIT(ADCx->JGCFGR, ADC_JGCFGR_JL_Msk));
}

/**
  * @brief    Set ADC Injection Group Channel0
  * @rmtoll   JCFGR    JSEL0    FL_ADC_SetInjectionGroupChannel0
  * @param    ADCx ADC instance
  * @param    channel This parameter can be one of the following values:
  *           @arg @ref FL_ADC_JG_CHANNLE0_CH0
  *           @arg @ref FL_ADC_JG_CHANNLE0_CH1
  *           @arg @ref FL_ADC_JG_CHANNLE0_CH2
  *           @arg @ref FL_ADC_JG_CHANNLE0_CH3
  *           @arg @ref FL_ADC_JG_CHANNLE0_CH4
  *           @arg @ref FL_ADC_JG_CHANNLE0_CH5
  *           @arg @ref FL_ADC_JG_CHANNLE0_CH6
  *           @arg @ref FL_ADC_JG_CHANNLE0_CH7
  *           @arg @ref FL_ADC_JG_CHANNLE0_CH8
  *           @arg @ref FL_ADC_JG_CHANNLE0_CH9
  *           @arg @ref FL_ADC_JG_CHANNLE0_CH10
  *           @arg @ref FL_ADC_JG_CHANNLE0_CH11
  *           @arg @ref FL_ADC_JG_CHANNLE0_CH12
  *           @arg @ref FL_ADC_JG_CHANNLE0_CH13
  *           @arg @ref FL_ADC_JG_CHANNLE0_CH14
  *           @arg @ref FL_ADC_JG_CHANNLE0_CH15
  *           @arg @ref FL_ADC_JG_CHANNLE0_CH16
  *           @arg @ref FL_ADC_JG_CHANNLE0_CH17
  *           @arg @ref FL_ADC_JG_CHANNLE0_CH18
  *           @arg @ref FL_ADC_JG_CHANNLE0_CH19
  *           @arg @ref FL_ADC_JG_CHANNLE0_CH20
  *           @arg @ref FL_ADC_JG_CHANNLE0_CH21
  *           @arg @ref FL_ADC_JG_CHANNLE0_CH22
  *           @arg @ref FL_ADC_JG_CHANNLE0_CH23
  *           @arg @ref FL_ADC_JG_CHANNLE0_CH24
  *           @arg @ref FL_ADC_JG_CHANNLE0_CH25
  *           @arg @ref FL_ADC_JG_CHANNLE0_CH26
  *           @arg @ref FL_ADC_JG_CHANNLE0_CH27
  *           @arg @ref FL_ADC_JG_CHANNLE0_CH28
  *           @arg @ref FL_ADC_JG_CHANNLE0_CH29
  *           @arg @ref FL_ADC_JG_CHANNLE0_CH30
  * @retval   None
  */
__STATIC_INLINE void FL_ADC_SetInjectionGroupChannel0(ADC_Type *ADCx, uint32_t channel)
{
    MODIFY_REG(ADCx->JCFGR, (ADC_JCFGR_JSEL0_Msk | ADC_JCFGR_JSEL0_4_Msk), channel);
}

/**
  * @brief    Get ADC Injection Group Channel0
  * @rmtoll   JCFGR    JSEL0    FL_ADC_GetInjectionGroupChannel0
  * @param    ADCx ADC instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_ADC_JG_CHANNLE0_CH0
  *           @arg @ref FL_ADC_JG_CHANNLE0_CH1
  *           @arg @ref FL_ADC_JG_CHANNLE0_CH2
  *           @arg @ref FL_ADC_JG_CHANNLE0_CH3
  *           @arg @ref FL_ADC_JG_CHANNLE0_CH4
  *           @arg @ref FL_ADC_JG_CHANNLE0_CH5
  *           @arg @ref FL_ADC_JG_CHANNLE0_CH6
  *           @arg @ref FL_ADC_JG_CHANNLE0_CH7
  *           @arg @ref FL_ADC_JG_CHANNLE0_CH8
  *           @arg @ref FL_ADC_JG_CHANNLE0_CH9
  *           @arg @ref FL_ADC_JG_CHANNLE0_CH10
  *           @arg @ref FL_ADC_JG_CHANNLE0_CH11
  *           @arg @ref FL_ADC_JG_CHANNLE0_CH12
  *           @arg @ref FL_ADC_JG_CHANNLE0_CH13
  *           @arg @ref FL_ADC_JG_CHANNLE0_CH14
  *           @arg @ref FL_ADC_JG_CHANNLE0_CH15
  *           @arg @ref FL_ADC_JG_CHANNLE0_CH16
  *           @arg @ref FL_ADC_JG_CHANNLE0_CH17
  *           @arg @ref FL_ADC_JG_CHANNLE0_CH18
  *           @arg @ref FL_ADC_JG_CHANNLE0_CH19
  *           @arg @ref FL_ADC_JG_CHANNLE0_CH20
  *           @arg @ref FL_ADC_JG_CHANNLE0_CH21
  *           @arg @ref FL_ADC_JG_CHANNLE0_CH22
  *           @arg @ref FL_ADC_JG_CHANNLE0_CH23
  *           @arg @ref FL_ADC_JG_CHANNLE0_CH24
  *           @arg @ref FL_ADC_JG_CHANNLE0_CH25
  *           @arg @ref FL_ADC_JG_CHANNLE0_CH26
  *           @arg @ref FL_ADC_JG_CHANNLE0_CH27
  *           @arg @ref FL_ADC_JG_CHANNLE0_CH28
  *           @arg @ref FL_ADC_JG_CHANNLE0_CH29
  *           @arg @ref FL_ADC_JG_CHANNLE0_CH30
  */
__STATIC_INLINE uint32_t FL_ADC_GetInjectionGroupChannel0(ADC_Type *ADCx)
{
    return (uint32_t)(READ_BIT(ADCx->JCFGR, (ADC_JCFGR_JSEL0_Msk | ADC_JCFGR_JSEL0_4_Msk)));
}

/**
  * @brief    Set ADC Injection Group
Channel1
  * @rmtoll   JCFGR    JSEL1    FL_ADC_SetInjectionGroupChannel1
  * @param    ADCx ADC instance
  * @param    channel This parameter can be one of the following values:
  *           @arg @ref FL_ADC_JG_CHANNLE1_CH0
  *           @arg @ref FL_ADC_JG_CHANNLE1_CH1
  *           @arg @ref FL_ADC_JG_CHANNLE1_CH2
  *           @arg @ref FL_ADC_JG_CHANNLE1_CH3
  *           @arg @ref FL_ADC_JG_CHANNLE1_CH4
  *           @arg @ref FL_ADC_JG_CHANNLE1_CH5
  *           @arg @ref FL_ADC_JG_CHANNLE1_CH6
  *           @arg @ref FL_ADC_JG_CHANNLE1_CH7
  *           @arg @ref FL_ADC_JG_CHANNLE1_CH8
  *           @arg @ref FL_ADC_JG_CHANNLE1_CH9
  *           @arg @ref FL_ADC_JG_CHANNLE1_CH10
  *           @arg @ref FL_ADC_JG_CHANNLE1_CH11
  *           @arg @ref FL_ADC_JG_CHANNLE1_CH12
  *           @arg @ref FL_ADC_JG_CHANNLE1_CH13
  *           @arg @ref FL_ADC_JG_CHANNLE1_CH14
  *           @arg @ref FL_ADC_JG_CHANNLE1_CH15
  *           @arg @ref FL_ADC_JG_CHANNLE1_CH16
  *           @arg @ref FL_ADC_JG_CHANNLE1_CH17
  *           @arg @ref FL_ADC_JG_CHANNLE1_CH18
  *           @arg @ref FL_ADC_JG_CHANNLE1_CH19
  *           @arg @ref FL_ADC_JG_CHANNLE1_CH20
  *           @arg @ref FL_ADC_JG_CHANNLE1_CH21
  *           @arg @ref FL_ADC_JG_CHANNLE1_CH22
  *           @arg @ref FL_ADC_JG_CHANNLE1_CH23
  *           @arg @ref FL_ADC_JG_CHANNLE1_CH24
  *           @arg @ref FL_ADC_JG_CHANNLE1_CH25
  *           @arg @ref FL_ADC_JG_CHANNLE1_CH26
  *           @arg @ref FL_ADC_JG_CHANNLE1_CH27
  *           @arg @ref FL_ADC_JG_CHANNLE1_CH28
  *           @arg @ref FL_ADC_JG_CHANNLE1_CH29
  *           @arg @ref FL_ADC_JG_CHANNLE1_CH30
  * @retval   None
  */
__STATIC_INLINE void FL_ADC_SetInjectionGroupChannel1(ADC_Type *ADCx, uint32_t channel)
{
    MODIFY_REG(ADCx->JCFGR, (ADC_JCFGR_JSEL1_Msk | ADC_JCFGR_JSEL1_4_Msk), channel);
}

/**
  * @brief    Get ADC Injection Group Channel1
  * @rmtoll   JCFGR    JSEL1    FL_ADC_GetInjectionGroupChannel1
  * @param    ADCx ADC instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_ADC_JG_CHANNLE1_CH0
  *           @arg @ref FL_ADC_JG_CHANNLE1_CH1
  *           @arg @ref FL_ADC_JG_CHANNLE1_CH2
  *           @arg @ref FL_ADC_JG_CHANNLE1_CH3
  *           @arg @ref FL_ADC_JG_CHANNLE1_CH4
  *           @arg @ref FL_ADC_JG_CHANNLE1_CH5
  *           @arg @ref FL_ADC_JG_CHANNLE1_CH6
  *           @arg @ref FL_ADC_JG_CHANNLE1_CH7
  *           @arg @ref FL_ADC_JG_CHANNLE1_CH8
  *           @arg @ref FL_ADC_JG_CHANNLE1_CH9
  *           @arg @ref FL_ADC_JG_CHANNLE1_CH10
  *           @arg @ref FL_ADC_JG_CHANNLE1_CH11
  *           @arg @ref FL_ADC_JG_CHANNLE1_CH12
  *           @arg @ref FL_ADC_JG_CHANNLE1_CH13
  *           @arg @ref FL_ADC_JG_CHANNLE1_CH14
  *           @arg @ref FL_ADC_JG_CHANNLE1_CH15
  *           @arg @ref FL_ADC_JG_CHANNLE1_CH16
  *           @arg @ref FL_ADC_JG_CHANNLE1_CH17
  *           @arg @ref FL_ADC_JG_CHANNLE1_CH18
  *           @arg @ref FL_ADC_JG_CHANNLE1_CH19
  *           @arg @ref FL_ADC_JG_CHANNLE1_CH20
  *           @arg @ref FL_ADC_JG_CHANNLE1_CH21
  *           @arg @ref FL_ADC_JG_CHANNLE1_CH22
  *           @arg @ref FL_ADC_JG_CHANNLE1_CH23
  *           @arg @ref FL_ADC_JG_CHANNLE1_CH24
  *           @arg @ref FL_ADC_JG_CHANNLE1_CH25
  *           @arg @ref FL_ADC_JG_CHANNLE1_CH26
  *           @arg @ref FL_ADC_JG_CHANNLE1_CH27
  *           @arg @ref FL_ADC_JG_CHANNLE1_CH28
  *           @arg @ref FL_ADC_JG_CHANNLE1_CH29
  *           @arg @ref FL_ADC_JG_CHANNLE1_CH30
  */
__STATIC_INLINE uint32_t FL_ADC_GetInjectionGroupChannel1(ADC_Type *ADCx)
{
    return (uint32_t)(READ_BIT(ADCx->JCFGR, (ADC_JCFGR_JSEL1_Msk | ADC_JCFGR_JSEL1_4_Msk)));
}

/**
  * @brief    Enable ADC Injection Group Channel0 OverSampling
  * @rmtoll   JCFGR    JOVS0    FL_ADC_EnableInjectionGroupChannel0Oversampling
  * @param    ADCx ADC instance
  * @retval   None
  */
__STATIC_INLINE void FL_ADC_EnableInjectionGroupChannel0Oversampling(ADC_Type *ADCx)
{
    SET_BIT(ADCx->JCFGR, ADC_JCFGR_JOVS0_Msk);
}

/**
  * @brief    Disable ADC Injection Group Channel0 OverSampling
  * @rmtoll   JCFGR    JOVS0    FL_ADC_DisableInjectionGroupChannel0Oversampling
  * @param    ADCx ADC instance
  * @retval   None
  */
__STATIC_INLINE void FL_ADC_DisableInjectionGroupChannel0Oversampling(ADC_Type *ADCx)
{
    CLEAR_BIT(ADCx->JCFGR, ADC_JCFGR_JOVS0_Msk);
}

/**
  * @brief    Get ADC Injection Group Channel0 OverSampling Enable Status
  * @rmtoll   JCFGR    JOVS0    FL_ADC_IsEnabledInjectionGroupChannel0Oversampling
  * @param    ADCx ADC instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_ADC_IsEnabledInjectionGroupChannel0Oversampling(ADC_Type *ADCx)
{
    return (uint32_t)(READ_BIT(ADCx->JCFGR, ADC_JCFGR_JOVS0_Msk) == ADC_JCFGR_JOVS0_Msk);
}

/**
  * @brief    Set ADC Injection Group Channel0 OverSampling Multiplier
  * @rmtoll   JCFGR    JOVSR0    FL_ADC_SetInjectionGroupChannel0OversamplingMultiplier
  * @param    ADCx ADC instance
  * @param    mul This parameter can be one of the following values:
  *           @arg @ref FL_ADC_JGCH0_OVERSAMPLING_MUL_2X
  *           @arg @ref FL_ADC_JGCH0_OVERSAMPLING_MUL_4X
  *           @arg @ref FL_ADC_JGCH0_OVERSAMPLING_MUL_8X
  *           @arg @ref FL_ADC_JGCH0_OVERSAMPLING_MUL_16X
  * @retval   None
  */
__STATIC_INLINE void FL_ADC_SetInjectionGroupChannel0OversamplingMultiplier(ADC_Type *ADCx, uint32_t mul)
{
    MODIFY_REG(ADCx->JCFGR, ADC_JCFGR_JOVSR0_Msk, mul);
}

/**
  * @brief    Get ADC Injection Group Channel0 OverSampling Multiplier
  * @rmtoll   JCFGR    JOVSR0    FL_ADC_GetInjectionGroupChannel0OversamplingMultiplier
  * @param    ADCx ADC instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_ADC_JGCH0_OVERSAMPLING_MUL_2X
  *           @arg @ref FL_ADC_JGCH0_OVERSAMPLING_MUL_4X
  *           @arg @ref FL_ADC_JGCH0_OVERSAMPLING_MUL_8X
  *           @arg @ref FL_ADC_JGCH0_OVERSAMPLING_MUL_16X
  */
__STATIC_INLINE uint32_t FL_ADC_GetInjectionGroupChannel0OversamplingMultiplier(ADC_Type *ADCx)
{
    return (uint32_t)(READ_BIT(ADCx->JCFGR, ADC_JCFGR_JOVSR0_Msk));
}

/**
  * @brief    Enable ADC Injection Group Channel1 OverSampling
  * @rmtoll   JCFGR    JOVS1    FL_ADC_EnableInjectionGroupChannel1Oversampling
  * @param    ADCx ADC instance
  * @retval   None
  */
__STATIC_INLINE void FL_ADC_EnableInjectionGroupChannel1Oversampling(ADC_Type *ADCx)
{
    SET_BIT(ADCx->JCFGR, ADC_JCFGR_JOVS1_Msk);
}

/**
  * @brief    Disable ADC Injection Group Channel1 OverSampling
  * @rmtoll   JCFGR    JOVS1    FL_ADC_DisableInjectionGroupChannel1Oversampling
  * @param    ADCx ADC instance
  * @retval   None
  */
__STATIC_INLINE void FL_ADC_DisableInjectionGroupChannel1Oversampling(ADC_Type *ADCx)
{
    CLEAR_BIT(ADCx->JCFGR, ADC_JCFGR_JOVS1_Msk);
}

/**
  * @brief    Get ADC Injection Group Channel1 OverSampling Enable Status
  * @rmtoll   JCFGR    JOVS1    FL_ADC_IsEnabledInjectionGroupChannel1Oversampling
  * @param    ADCx ADC instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_ADC_IsEnabledInjectionGroupChannel1Oversampling(ADC_Type *ADCx)
{
    return (uint32_t)(READ_BIT(ADCx->JCFGR, ADC_JCFGR_JOVS1_Msk) == ADC_JCFGR_JOVS1_Msk);
}

/**
  * @brief    Set ADC Injection Group Channel1 OverSampling Multiplier
  * @rmtoll   JCFGR    JOVSR1    FL_ADC_SetInjectionGroupChannel1OversamplingMultiplier
  * @param    ADCx ADC instance
  * @param    mul This parameter can be one of the following values:
  *           @arg @ref FL_ADC_JGCH1_OVERSAMPLING_MUL_2X
  *           @arg @ref FL_ADC_JGCH1_OVERSAMPLING_MUL_4X
  *           @arg @ref FL_ADC_JGCH1_OVERSAMPLING_MUL_8X
  *           @arg @ref FL_ADC_JGCH1_OVERSAMPLING_MUL_16X
  * @retval   None
  */
__STATIC_INLINE void FL_ADC_SetInjectionGroupChannel1OversamplingMultiplier(ADC_Type *ADCx, uint32_t mul)
{
    MODIFY_REG(ADCx->JCFGR, ADC_JCFGR_JOVSR1_Msk, mul);
}

/**
  * @brief    Get ADC Injection Group Channel1 OverSampling Multiplier
  * @rmtoll   JCFGR    JOVSR1    FL_ADC_GetInjectionGroupChannel1OversamplingMultiplier
  * @param    ADCx ADC instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_ADC_JGCH1_OVERSAMPLING_MUL_2X
  *           @arg @ref FL_ADC_JGCH1_OVERSAMPLING_MUL_4X
  *           @arg @ref FL_ADC_JGCH1_OVERSAMPLING_MUL_8X
  *           @arg @ref FL_ADC_JGCH1_OVERSAMPLING_MUL_16X
  */
__STATIC_INLINE uint32_t FL_ADC_GetInjectionGroupChannel1OversamplingMultiplier(ADC_Type *ADCx)
{
    return (uint32_t)(READ_BIT(ADCx->JCFGR, ADC_JCFGR_JOVSR1_Msk));
}

/**
  * @brief    Set ADC Injection Group
Channel2
  * @rmtoll   JCFGR    JSEL2    FL_ADC_SetInjectionGroupChannel2
  * @param    ADCx ADC instance
  * @param    channel This parameter can be one of the following values:
  *           @arg @ref FL_ADC_JG_CHANNLE2_CH0
  *           @arg @ref FL_ADC_JG_CHANNLE2_CH1
  *           @arg @ref FL_ADC_JG_CHANNLE2_CH2
  *           @arg @ref FL_ADC_JG_CHANNLE2_CH3
  *           @arg @ref FL_ADC_JG_CHANNLE2_CH4
  *           @arg @ref FL_ADC_JG_CHANNLE2_CH5
  *           @arg @ref FL_ADC_JG_CHANNLE2_CH6
  *           @arg @ref FL_ADC_JG_CHANNLE2_CH7
  *           @arg @ref FL_ADC_JG_CHANNLE2_CH8
  *           @arg @ref FL_ADC_JG_CHANNLE2_CH9
  *           @arg @ref FL_ADC_JG_CHANNLE2_CH10
  *           @arg @ref FL_ADC_JG_CHANNLE2_CH11
  *           @arg @ref FL_ADC_JG_CHANNLE2_CH12
  *           @arg @ref FL_ADC_JG_CHANNLE2_CH13
  *           @arg @ref FL_ADC_JG_CHANNLE2_CH14
  *           @arg @ref FL_ADC_JG_CHANNLE2_CH15
  *           @arg @ref FL_ADC_JG_CHANNLE2_CH16
  *           @arg @ref FL_ADC_JG_CHANNLE2_CH17
  *           @arg @ref FL_ADC_JG_CHANNLE2_CH18
  *           @arg @ref FL_ADC_JG_CHANNLE2_CH19
  *           @arg @ref FL_ADC_JG_CHANNLE2_CH20
  *           @arg @ref FL_ADC_JG_CHANNLE2_CH21
  *           @arg @ref FL_ADC_JG_CHANNLE2_CH22
  *           @arg @ref FL_ADC_JG_CHANNLE2_CH23
  *           @arg @ref FL_ADC_JG_CHANNLE2_CH24
  *           @arg @ref FL_ADC_JG_CHANNLE2_CH25
  *           @arg @ref FL_ADC_JG_CHANNLE2_CH26
  *           @arg @ref FL_ADC_JG_CHANNLE2_CH27
  *           @arg @ref FL_ADC_JG_CHANNLE2_CH28
  *           @arg @ref FL_ADC_JG_CHANNLE2_CH29
  *           @arg @ref FL_ADC_JG_CHANNLE2_CH30
  * @retval   None
  */
__STATIC_INLINE void FL_ADC_SetInjectionGroupChannel2(ADC_Type *ADCx, uint32_t channel)
{
    MODIFY_REG(ADCx->JCFGR, (ADC_JCFGR_JSEL2_Msk | ADC_JCFGR_JSEL2_4_Msk), channel);
}

/**
  * @brief    Get ADC Injection Group
Channel2
  * @rmtoll   JCFGR    JSEL2    FL_ADC_GetInjectionGroupChannel2
  * @param    ADCx ADC instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_ADC_JG_CHANNLE2_CH0
  *           @arg @ref FL_ADC_JG_CHANNLE2_CH1
  *           @arg @ref FL_ADC_JG_CHANNLE2_CH2
  *           @arg @ref FL_ADC_JG_CHANNLE2_CH3
  *           @arg @ref FL_ADC_JG_CHANNLE2_CH4
  *           @arg @ref FL_ADC_JG_CHANNLE2_CH5
  *           @arg @ref FL_ADC_JG_CHANNLE2_CH6
  *           @arg @ref FL_ADC_JG_CHANNLE2_CH7
  *           @arg @ref FL_ADC_JG_CHANNLE2_CH8
  *           @arg @ref FL_ADC_JG_CHANNLE2_CH9
  *           @arg @ref FL_ADC_JG_CHANNLE2_CH10
  *           @arg @ref FL_ADC_JG_CHANNLE2_CH11
  *           @arg @ref FL_ADC_JG_CHANNLE2_CH12
  *           @arg @ref FL_ADC_JG_CHANNLE2_CH13
  *           @arg @ref FL_ADC_JG_CHANNLE2_CH14
  *           @arg @ref FL_ADC_JG_CHANNLE2_CH15
  *           @arg @ref FL_ADC_JG_CHANNLE2_CH16
  *           @arg @ref FL_ADC_JG_CHANNLE2_CH17
  *           @arg @ref FL_ADC_JG_CHANNLE2_CH18
  *           @arg @ref FL_ADC_JG_CHANNLE2_CH19
  *           @arg @ref FL_ADC_JG_CHANNLE2_CH20
  *           @arg @ref FL_ADC_JG_CHANNLE2_CH21
  *           @arg @ref FL_ADC_JG_CHANNLE2_CH22
  *           @arg @ref FL_ADC_JG_CHANNLE2_CH23
  *           @arg @ref FL_ADC_JG_CHANNLE2_CH24
  *           @arg @ref FL_ADC_JG_CHANNLE2_CH25
  *           @arg @ref FL_ADC_JG_CHANNLE2_CH26
  *           @arg @ref FL_ADC_JG_CHANNLE2_CH27
  *           @arg @ref FL_ADC_JG_CHANNLE2_CH28
  *           @arg @ref FL_ADC_JG_CHANNLE2_CH29
  *           @arg @ref FL_ADC_JG_CHANNLE2_CH30
  */
__STATIC_INLINE uint32_t FL_ADC_GetInjectionGroupChannel2(ADC_Type *ADCx)
{
    return (uint32_t)(READ_BIT(ADCx->JCFGR, (ADC_JCFGR_JSEL2_Msk | ADC_JCFGR_JSEL2_4_Msk)));
}

/**
  * @brief    Set ADC Injection Group
Channel3
  * @rmtoll   JCFGR    JSEL25    FL_ADC_SetInjectionGroupChannel3
  * @param    ADCx ADC instance
  * @param    channel This parameter can be one of the following values:
  *           @arg @ref FL_ADC_JG_CHANNLE3_CH0
  *           @arg @ref FL_ADC_JG_CHANNLE3_CH1
  *           @arg @ref FL_ADC_JG_CHANNLE3_CH2
  *           @arg @ref FL_ADC_JG_CHANNLE3_CH3
  *           @arg @ref FL_ADC_JG_CHANNLE3_CH4
  *           @arg @ref FL_ADC_JG_CHANNLE3_CH5
  *           @arg @ref FL_ADC_JG_CHANNLE3_CH6
  *           @arg @ref FL_ADC_JG_CHANNLE3_CH7
  *           @arg @ref FL_ADC_JG_CHANNLE3_CH8
  *           @arg @ref FL_ADC_JG_CHANNLE3_CH9
  *           @arg @ref FL_ADC_JG_CHANNLE3_CH10
  *           @arg @ref FL_ADC_JG_CHANNLE3_CH11
  *           @arg @ref FL_ADC_JG_CHANNLE3_CH12
  *           @arg @ref FL_ADC_JG_CHANNLE3_CH13
  *           @arg @ref FL_ADC_JG_CHANNLE3_CH14
  *           @arg @ref FL_ADC_JG_CHANNLE3_CH15
  *           @arg @ref FL_ADC_JG_CHANNLE3_CH16
  *           @arg @ref FL_ADC_JG_CHANNLE3_CH17
  *           @arg @ref FL_ADC_JG_CHANNLE3_CH18
  *           @arg @ref FL_ADC_JG_CHANNLE3_CH19
  *           @arg @ref FL_ADC_JG_CHANNLE3_CH20
  *           @arg @ref FL_ADC_JG_CHANNLE3_CH21
  *           @arg @ref FL_ADC_JG_CHANNLE3_CH22
  *           @arg @ref FL_ADC_JG_CHANNLE3_CH23
  *           @arg @ref FL_ADC_JG_CHANNLE3_CH24
  *           @arg @ref FL_ADC_JG_CHANNLE3_CH25
  *           @arg @ref FL_ADC_JG_CHANNLE3_CH26
  *           @arg @ref FL_ADC_JG_CHANNLE3_CH27
  *           @arg @ref FL_ADC_JG_CHANNLE3_CH28
  *           @arg @ref FL_ADC_JG_CHANNLE3_CH29
  *           @arg @ref FL_ADC_JG_CHANNLE3_CH30
  * @retval   None
  */
__STATIC_INLINE void FL_ADC_SetInjectionGroupChannel3(ADC_Type *ADCx, uint32_t channel)
{
    MODIFY_REG(ADCx->JCFGR, (ADC_JCFGR_JSEL3_Msk | ADC_JCFGR_JSEL3_4_Msk), channel);
}

/**
  * @brief    Get ADC Injection Group
Channel3
  * @rmtoll   JCFGR    JSEL25    FL_ADC_GetInjectionGroupChannel3
  * @param    ADCx ADC instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_ADC_JG_CHANNLE3_CH0
  *           @arg @ref FL_ADC_JG_CHANNLE3_CH1
  *           @arg @ref FL_ADC_JG_CHANNLE3_CH2
  *           @arg @ref FL_ADC_JG_CHANNLE3_CH3
  *           @arg @ref FL_ADC_JG_CHANNLE3_CH4
  *           @arg @ref FL_ADC_JG_CHANNLE3_CH5
  *           @arg @ref FL_ADC_JG_CHANNLE3_CH6
  *           @arg @ref FL_ADC_JG_CHANNLE3_CH7
  *           @arg @ref FL_ADC_JG_CHANNLE3_CH8
  *           @arg @ref FL_ADC_JG_CHANNLE3_CH9
  *           @arg @ref FL_ADC_JG_CHANNLE3_CH10
  *           @arg @ref FL_ADC_JG_CHANNLE3_CH11
  *           @arg @ref FL_ADC_JG_CHANNLE3_CH12
  *           @arg @ref FL_ADC_JG_CHANNLE3_CH13
  *           @arg @ref FL_ADC_JG_CHANNLE3_CH14
  *           @arg @ref FL_ADC_JG_CHANNLE3_CH15
  *           @arg @ref FL_ADC_JG_CHANNLE3_CH16
  *           @arg @ref FL_ADC_JG_CHANNLE3_CH17
  *           @arg @ref FL_ADC_JG_CHANNLE3_CH18
  *           @arg @ref FL_ADC_JG_CHANNLE3_CH19
  *           @arg @ref FL_ADC_JG_CHANNLE3_CH20
  *           @arg @ref FL_ADC_JG_CHANNLE3_CH21
  *           @arg @ref FL_ADC_JG_CHANNLE3_CH22
  *           @arg @ref FL_ADC_JG_CHANNLE3_CH23
  *           @arg @ref FL_ADC_JG_CHANNLE3_CH24
  *           @arg @ref FL_ADC_JG_CHANNLE3_CH25
  *           @arg @ref FL_ADC_JG_CHANNLE3_CH26
  *           @arg @ref FL_ADC_JG_CHANNLE3_CH27
  *           @arg @ref FL_ADC_JG_CHANNLE3_CH28
  *           @arg @ref FL_ADC_JG_CHANNLE3_CH29
  *           @arg @ref FL_ADC_JG_CHANNLE3_CH30
  */
__STATIC_INLINE uint32_t FL_ADC_GetInjectionGroupChannel3(ADC_Type *ADCx)
{
    return (uint32_t)(READ_BIT(ADCx->JCFGR, (ADC_JCFGR_JSEL3_Msk | ADC_JCFGR_JSEL3_4_Msk)));
}

/**
  * @brief    Enable ADC Injection Group Channel2 OverSampling
  * @rmtoll   JCFGR    JOVS2    FL_ADC_EnableInjectionGroupChannel2Oversampling
  * @param    ADCx ADC instance
  * @retval   None
  */
__STATIC_INLINE void FL_ADC_EnableInjectionGroupChannel2Oversampling(ADC_Type *ADCx)
{
    SET_BIT(ADCx->JCFGR, ADC_JCFGR_JOVS2_Msk);
}

/**
  * @brief    Disable ADC Injection Group Channel2 OverSampling
  * @rmtoll   JCFGR    JOVS2    FL_ADC_DisableInjectionGroupChannel2Oversampling
  * @param    ADCx ADC instance
  * @retval   None
  */
__STATIC_INLINE void FL_ADC_DisableInjectionGroupChannel2Oversampling(ADC_Type *ADCx)
{
    CLEAR_BIT(ADCx->JCFGR, ADC_JCFGR_JOVS2_Msk);
}

/**
  * @brief    Get ADC Injection Group Channel2 OverSampling Enable Status
  * @rmtoll   JCFGR    JOVS2    FL_ADC_IsEnabledInjectionGroupChannel2Oversampling
  * @param    ADCx ADC instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_ADC_IsEnabledInjectionGroupChannel2Oversampling(ADC_Type *ADCx)
{
    return (uint32_t)(READ_BIT(ADCx->JCFGR, ADC_JCFGR_JOVS2_Msk) == ADC_JCFGR_JOVS2_Msk);
}

/**
  * @brief    Set ADC Injection Group Channel2 OverSampling Multiplier
  * @rmtoll   JCFGR    JOVSR2    FL_ADC_SetInjectionGroupChannel2OversamplingMultiplier
  * @param    ADCx ADC instance
  * @param    mul This parameter can be one of the following values:
  *           @arg @ref FL_ADC_JGCH2_OVERSAMPLING_MUL_2X
  *           @arg @ref FL_ADC_JGCH2_OVERSAMPLING_MUL_4X
  *           @arg @ref FL_ADC_JGCH2_OVERSAMPLING_MUL_8X
  *           @arg @ref FL_ADC_JGCH2_OVERSAMPLING_MUL_16X
  * @retval   None
  */
__STATIC_INLINE void FL_ADC_SetInjectionGroupChannel2OversamplingMultiplier(ADC_Type *ADCx, uint32_t mul)
{
    MODIFY_REG(ADCx->JCFGR, ADC_JCFGR_JOVSR2_Msk, mul);
}

/**
  * @brief    Get ADC Injection Group Channel2 OverSampling Multiplier
  * @rmtoll   JCFGR    JOVSR2    FL_ADC_GetInjectionGroupChannel2OversamplingMultiplier
  * @param    ADCx ADC instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_ADC_JGCH2_OVERSAMPLING_MUL_2X
  *           @arg @ref FL_ADC_JGCH2_OVERSAMPLING_MUL_4X
  *           @arg @ref FL_ADC_JGCH2_OVERSAMPLING_MUL_8X
  *           @arg @ref FL_ADC_JGCH2_OVERSAMPLING_MUL_16X
  */
__STATIC_INLINE uint32_t FL_ADC_GetInjectionGroupChannel2OversamplingMultiplier(ADC_Type *ADCx)
{
    return (uint32_t)(READ_BIT(ADCx->JCFGR, ADC_JCFGR_JOVSR2_Msk));
}

/**
  * @brief    Enable ADC Injection Group Channel3 OverSampling
  * @rmtoll   JCFGR    JOVS3    FL_ADC_EnableInjectionGroupChannel3Oversampling
  * @param    ADCx ADC instance
  * @retval   None
  */
__STATIC_INLINE void FL_ADC_EnableInjectionGroupChannel3Oversampling(ADC_Type *ADCx)
{
    SET_BIT(ADCx->JCFGR, ADC_JCFGR_JOVS3_Msk);
}

/**
  * @brief    Disable ADC Injection Group Channel3 OverSampling
  * @rmtoll   JCFGR    JOVS3    FL_ADC_DisableInjectionGroupChannel3Oversampling
  * @param    ADCx ADC instance
  * @retval   None
  */
__STATIC_INLINE void FL_ADC_DisableInjectionGroupChannel3Oversampling(ADC_Type *ADCx)
{
    CLEAR_BIT(ADCx->JCFGR, ADC_JCFGR_JOVS3_Msk);
}

/**
  * @brief    Get ADC Injection Group Channel3 OverSampling Enable Status
  * @rmtoll   JCFGR    JOVS3    FL_ADC_IsEnabledInjectionGroupChannel3Oversampling
  * @param    ADCx ADC instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_ADC_IsEnabledInjectionGroupChannel3Oversampling(ADC_Type *ADCx)
{
    return (uint32_t)(READ_BIT(ADCx->JCFGR, ADC_JCFGR_JOVS3_Msk) == ADC_JCFGR_JOVS3_Msk);
}

/**
  * @brief    Set ADC Injection Group Channel3 OverSampling Multiplier
  * @rmtoll   JCFGR    JOVSR3    FL_ADC_SetInjectionGroupChannel3OversamplingMultiplier
  * @param    ADCx ADC instance
  * @param    mul This parameter can be one of the following values:
  *           @arg @ref FL_ADC_JGCH3_OVERSAMPLING_MUL_2X
  *           @arg @ref FL_ADC_JGCH3_OVERSAMPLING_MUL_4X
  *           @arg @ref FL_ADC_JGCH3_OVERSAMPLING_MUL_8X
  *           @arg @ref FL_ADC_JGCH3_OVERSAMPLING_MUL_16X
  * @retval   None
  */
__STATIC_INLINE void FL_ADC_SetInjectionGroupChannel3OversamplingMultiplier(ADC_Type *ADCx, uint32_t mul)
{
    MODIFY_REG(ADCx->JCFGR, ADC_JCFGR_JOVSR3_Msk, mul);
}

/**
  * @brief    Get ADC Injection Group Channel3 OverSampling Multiplier
  * @rmtoll   JCFGR    JOVSR3    FL_ADC_GetInjectionGroupChannel3OversamplingMultiplier
  * @param    ADCx ADC instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_ADC_JGCH3_OVERSAMPLING_MUL_2X
  *           @arg @ref FL_ADC_JGCH3_OVERSAMPLING_MUL_4X
  *           @arg @ref FL_ADC_JGCH3_OVERSAMPLING_MUL_8X
  *           @arg @ref FL_ADC_JGCH3_OVERSAMPLING_MUL_16X
  */
__STATIC_INLINE uint32_t FL_ADC_GetInjectionGroupChannel3OversamplingMultiplier(ADC_Type *ADCx)
{
    return (uint32_t)(READ_BIT(ADCx->JCFGR, ADC_JCFGR_JOVSR3_Msk));
}

/**
  * @brief    Set ADC Injection Group Channel0 Conversion Data
  * @rmtoll   JDR0    JDATA0    FL_ADC_WriteInjectionGroupChannel0ConversionData
  * @param    ADCx ADC instance
  * @param    data 
  * @retval   None
  */
__STATIC_INLINE void FL_ADC_WriteInjectionGroupChannel0ConversionData(ADC_Type *ADCx, uint32_t data)
{
    MODIFY_REG(ADCx->JDR0, ADC_JDR0_JDATA0_Msk, (data << ADC_JDR0_JDATA0_Pos));
}

/**
  * @brief    Get ADC Injection Group Channel0 Conversion Data
  * @rmtoll   JDR0    JDATA0    FL_ADC_ReadInjectionGroupChannel0ConversionData
  * @param    ADCx ADC instance
  * @retval   
  */
__STATIC_INLINE uint32_t FL_ADC_ReadInjectionGroupChannel0ConversionData(ADC_Type *ADCx)
{
    return (uint32_t)(READ_BIT(ADCx->JDR0, ADC_JDR0_JDATA0_Msk) >> ADC_JDR0_JDATA0_Pos);
}

/**
  * @brief    Set ADC Injection Group Channel1 Conversion Data
  * @rmtoll   JDR1    JDATA1    FL_ADC_WriteInjectionGroupChannel1ConversionData
  * @param    ADCx ADC instance
  * @param    data 
  * @retval   None
  */
__STATIC_INLINE void FL_ADC_WriteInjectionGroupChannel1ConversionData(ADC_Type *ADCx, uint32_t data)
{
    MODIFY_REG(ADCx->JDR1, ADC_JDR1_JDATA1_Msk, (data << ADC_JDR1_JDATA1_Pos));
}

/**
  * @brief    Get ADC Injection Group Channel1 Conversion Data
  * @rmtoll   JDR1    JDATA1    FL_ADC_ReadInjectionGroupChannel1ConversionData
  * @param    ADCx ADC instance
  * @retval   
  */
__STATIC_INLINE uint32_t FL_ADC_ReadInjectionGroupChannel1ConversionData(ADC_Type *ADCx)
{
    return (uint32_t)(READ_BIT(ADCx->JDR1, ADC_JDR1_JDATA1_Msk) >> ADC_JDR1_JDATA1_Pos);
}

/**
  * @brief    Set ADC Injection Group Channel2 Conversion Data
  * @rmtoll   JDR2    JDATA2    FL_ADC_WriteInjectionGroupChannel2ConversionData
  * @param    ADCx ADC instance
  * @param    data 
  * @retval   None
  */
__STATIC_INLINE void FL_ADC_WriteInjectionGroupChannel2ConversionData(ADC_Type *ADCx, uint32_t data)
{
    MODIFY_REG(ADCx->JDR2, ADC_JDR2_JDATA2_Msk, (data << ADC_JDR2_JDATA2_Pos));
}

/**
  * @brief    Get ADC Injection Group Channel2 Conversion Data
  * @rmtoll   JDR2    JDATA2    FL_ADC_ReadInjectionGroupChannel2ConversionData
  * @param    ADCx ADC instance
  * @retval   
  */
__STATIC_INLINE uint32_t FL_ADC_ReadInjectionGroupChannel2ConversionData(ADC_Type *ADCx)
{
    return (uint32_t)(READ_BIT(ADCx->JDR2, ADC_JDR2_JDATA2_Msk) >> ADC_JDR2_JDATA2_Pos);
}

/**
  * @brief    Set ADC Injection Group Channel3 Conversion Data
  * @rmtoll   JDR3    JDATA3    FL_ADC_WriteInjectionGroupChannel3ConversionData
  * @param    ADCx ADC instance
  * @param    data 
  * @retval   None
  */
__STATIC_INLINE void FL_ADC_WriteInjectionGroupChannel3ConversionData(ADC_Type *ADCx, uint32_t data)
{
    MODIFY_REG(ADCx->JDR3, ADC_JDR3_JDATA3_Msk, (data << ADC_JDR3_JDATA3_Pos));
}

/**
  * @brief    Get ADC Injection Group Channel3 Conversion Data
  * @rmtoll   JDR3    JDATA3    FL_ADC_ReadInjectionGroupChannel3ConversionData
  * @param    ADCx ADC instance
  * @retval   
  */
__STATIC_INLINE uint32_t FL_ADC_ReadInjectionGroupChannel3ConversionData(ADC_Type *ADCx)
{
    return (uint32_t)(READ_BIT(ADCx->JDR3, ADC_JDR3_JDATA3_Msk) >> ADC_JDR3_JDATA3_Pos);
}

/**
  * @brief    Get ADC Raw Data
  * @rmtoll   RAWR    RAWD    FL_ADC_ReadRawData
  * @param    ADCx ADC instance
  * @retval   
  */
__STATIC_INLINE uint32_t FL_ADC_ReadRawData(ADC_Type *ADCx)
{
    return (uint32_t)(READ_BIT(ADCx->RAWR, ADC_RAWR_RAWD_Msk) >> ADC_RAWR_RAWD_Pos);
}

/**
  * @}
  */

/** @defgroup ADC_FL_EF_Init Initialization and de-initialization functions
  * @{
  */
extern FL_ErrorStatus FL_ADC_CommonDeInit(void);
extern FL_ErrorStatus FL_ADC_DeInit(ADC_Type *ADCx);
extern FL_ErrorStatus FL_ADC_CommonInit(FL_ADC_CommonInitTypeDef *ADC_CommonInitStruct);
extern FL_ErrorStatus FL_ADC_Init(ADC_Type *ADCx, FL_ADC_InitTypeDef  *ADC_InitStruct);
extern void FL_ADC_StructInit(FL_ADC_InitTypeDef *ADC_InitStruct);
extern void FL_ADC_CommonStructInit(FL_ADC_CommonInitTypeDef *ADC_CommonInitStruct);

/**
  * @}
  */


/**
  * @}
  */

#ifdef __cplusplus
}
#endif

#endif /* __FM33FG0XX_FL_ADC_H*/

/*************************Py_Code_Generator Version: 0.1-0.14-0.1 @ 2023-03-24*************************/
/*************************(C) COPYRIGHT Fudan Microelectronics **** END OF FILE*************************/
