 /**    
  *******************************************************************************************************
  * @file    fm33fg0xxa_fl_cmu.h
  * @author  FMSH Application Team
  * @brief   Head file of CMU FL Module
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
#ifndef __FM33FG0XXA_FL_CMU_H
#define __FM33FG0XXA_FL_CMU_H

#ifdef __cplusplus
extern "C" {
#endif
/* Includes -------------------------------------------------------------------------------------------*/
#include "fm33fg0xxa_fl_def.h"
/** @addtogroup FM33FG0XXA_FL_Driver
  * @{
  */
/* Exported types -------------------------------------------------------------------------------------*/
/** @defgroup CMU_FL_ES_INIT CMU Exported Init structures
  * @{
  */

/**
  * @brief FL CMU Init Sturcture definition
  */
typedef enum
{
    FL_SYSTEM_CLOCK_RCHF_8M = 0,
    FL_SYSTEM_CLOCK_RCHF_16M,
    FL_SYSTEM_CLOCK_RCHF_24M,
    FL_SYSTEM_CLOCK_PLL_RCHF_32M,
    FL_SYSTEM_CLOCK_PLL_RCHF_48M,
    FL_SYSTEM_CLOCK_RCLP,
    FL_SYSTEM_CLOCK_XTLF,
    FL_SYSTEM_CLOCK_XTHF,
} FL_SystemClock;

/**
  * @brief FL CMU RCHF Init Sturcture definition
  */
typedef struct
{
    /* RCHF频率 */
    uint32_t Frequency;
}FL_CMU_RCHF_InitTypeDef;

/**
  * @brief FL CMU XTHF Init Sturcture definition
  */
typedef struct
{
    /* XTHF频率 */
    uint32_t Frequency;
    /* XTHF启动等待时间 */
    uint32_t StartWaitTime;
    /* XTHF Bypss使能或禁止 */
    uint32_t Bypass;
    /* XTHF振荡强度 */
    uint32_t DriverStrength;
}FL_CMU_XTHF_InitTypeDef;

/**
  * @brief FL CMU PLL Init Sturcture definition
  */
typedef struct
{
    /* PLL倍频比 */
    uint32_t Multiplier;
    /* PLL参考时钟预分频 */
    uint32_t Prescaler;
    /* PLL时钟源输入选择 */
    uint32_t ClockSource;
}FL_CMU_PLL_InitTypeDef;

/**
  * @}
  */
/* Exported constants ---------------------------------------------------------------------------------*/
/** @defgroup CMU_FL_Exported_Constants CMU Exported Constants
  * @{
  */

#define    CMU_SYSCLKCR_LSCATS_Pos                                (27U)
#define    CMU_SYSCLKCR_LSCATS_Msk                                (0x1U << CMU_SYSCLKCR_LSCATS_Pos)
#define    CMU_SYSCLKCR_LSCATS                                    CMU_SYSCLKCR_LSCATS_Msk

#define    CMU_SYSCLKCR_SLP_ENEXTI_Pos                            (25U)
#define    CMU_SYSCLKCR_SLP_ENEXTI_Msk                            (0x1U << CMU_SYSCLKCR_SLP_ENEXTI_Pos)
#define    CMU_SYSCLKCR_SLP_ENEXTI                                CMU_SYSCLKCR_SLP_ENEXTI_Msk

#define    CMU_SYSCLKCR_APB2PRES_Pos                              (19U)
#define    CMU_SYSCLKCR_APB2PRES_Msk                              (0x7U << CMU_SYSCLKCR_APB2PRES_Pos)
#define    CMU_SYSCLKCR_APB2PRES                                  CMU_SYSCLKCR_APB2PRES_Msk

#define    CMU_SYSCLKCR_APB1PRES_Pos                              (16U)
#define    CMU_SYSCLKCR_APB1PRES_Msk                              (0x7U << CMU_SYSCLKCR_APB1PRES_Pos)
#define    CMU_SYSCLKCR_APB1PRES                                  CMU_SYSCLKCR_APB1PRES_Msk

#define    CMU_SYSCLKCR_AHBPRES_Pos                               (8U)
#define    CMU_SYSCLKCR_AHBPRES_Msk                               (0x7U << CMU_SYSCLKCR_AHBPRES_Pos)
#define    CMU_SYSCLKCR_AHBPRES                                   CMU_SYSCLKCR_AHBPRES_Msk

#define    CMU_SYSCLKCR_STCLKSEL_Pos                              (6U)
#define    CMU_SYSCLKCR_STCLKSEL_Msk                              (0x3U << CMU_SYSCLKCR_STCLKSEL_Pos)
#define    CMU_SYSCLKCR_STCLKSEL                                  CMU_SYSCLKCR_STCLKSEL_Msk

#define    CMU_SYSCLKCR_SYSCLKSEL_Pos                             (0U)
#define    CMU_SYSCLKCR_SYSCLKSEL_Msk                             (0x7U << CMU_SYSCLKCR_SYSCLKSEL_Pos)
#define    CMU_SYSCLKCR_SYSCLKSEL                                 CMU_SYSCLKCR_SYSCLKSEL_Msk

#define    CMU_RCHFCR_FSEL_Pos                                    (16U)
#define    CMU_RCHFCR_FSEL_Msk                                    (0xfU << CMU_RCHFCR_FSEL_Pos)
#define    CMU_RCHFCR_FSEL                                        CMU_RCHFCR_FSEL_Msk

#define    CMU_RCHFCR_EN_Pos                                      (0U)
#define    CMU_RCHFCR_EN_Msk                                      (0x1U << CMU_RCHFCR_EN_Pos)
#define    CMU_RCHFCR_EN                                          CMU_RCHFCR_EN_Msk

#define    CMU_RCHFTR_TRIM_Pos                                    (0U)
#define    CMU_RCHFTR_TRIM_Msk                                    (0xffU << CMU_RCHFTR_TRIM_Pos)
#define    CMU_RCHFTR_TRIM                                        CMU_RCHFTR_TRIM_Msk

#define    CMU_PLLCR_DB_Pos                                       (16U)
#define    CMU_PLLCR_DB_Msk                                       (0x3ffU << CMU_PLLCR_DB_Pos)
#define    CMU_PLLCR_DB                                           CMU_PLLCR_DB_Msk

#define    CMU_PLLCR_LOCKED_Pos                                   (7U)
#define    CMU_PLLCR_LOCKED_Msk                                   (0x1U << CMU_PLLCR_LOCKED_Pos)
#define    CMU_PLLCR_LOCKED                                       CMU_PLLCR_LOCKED_Msk

#define    CMU_PLLCR_REFPRSC_Pos                                  (4U)
#define    CMU_PLLCR_REFPRSC_Msk                                  (0x7U << CMU_PLLCR_REFPRSC_Pos)
#define    CMU_PLLCR_REFPRSC                                      CMU_PLLCR_REFPRSC_Msk

#define    CMU_PLLCR_INSEL_Pos                                    (1U)
#define    CMU_PLLCR_INSEL_Msk                                    (0x1U << CMU_PLLCR_INSEL_Pos)
#define    CMU_PLLCR_INSEL                                        CMU_PLLCR_INSEL_Msk

#define    CMU_PLLCR_EN_Pos                                       (0U)
#define    CMU_PLLCR_EN_Msk                                       (0x1U << CMU_PLLCR_EN_Pos)
#define    CMU_PLLCR_EN                                           CMU_PLLCR_EN_Msk

#define    CMU_RCLPTR_TRIM_Pos                                    (0U)
#define    CMU_RCLPTR_TRIM_Msk                                    (0xffU << CMU_RCLPTR_TRIM_Pos)
#define    CMU_RCLPTR_TRIM                                        CMU_RCLPTR_TRIM_Msk

#define    CMU_XTLFCR_BYPASS_Pos                                  (16U)
#define    CMU_XTLFCR_BYPASS_Msk                                  (0x1U << CMU_XTLFCR_BYPASS_Pos)
#define    CMU_XTLFCR_BYPASS                                      CMU_XTLFCR_BYPASS_Msk

#define    CMU_XTLFCR_WAIT_Pos                                    (13U)
#define    CMU_XTLFCR_WAIT_Msk                                    (0x7U << CMU_XTLFCR_WAIT_Pos)
#define    CMU_XTLFCR_WAIT                                        CMU_XTLFCR_WAIT_Msk

#define    CMU_XTLFCR_EXCKSEN_Pos                                 (12U)
#define    CMU_XTLFCR_EXCKSEN_Msk                                 (0x1U << CMU_XTLFCR_EXCKSEN_Pos)
#define    CMU_XTLFCR_EXCKSEN                                     CMU_XTLFCR_EXCKSEN_Msk

#define    CMU_XTLFCR_EN_Pos                                      (8U)
#define    CMU_XTLFCR_EN_Msk                                      (0xfU << CMU_XTLFCR_EN_Pos)
#define    CMU_XTLFCR_EN                                          CMU_XTLFCR_EN_Msk

#define    CMU_XTLFCR_RDY_Pos                                     (5U)
#define    CMU_XTLFCR_RDY_Msk                                     (0x1U << CMU_XTLFCR_RDY_Pos)
#define    CMU_XTLFCR_RDY                                         CMU_XTLFCR_RDY_Msk

#define    CMU_XTLFCR_GMCFG_Pos                                   (2U)
#define    CMU_XTLFCR_GMCFG_Msk                                   (0x7U << CMU_XTLFCR_GMCFG_Pos)
#define    CMU_XTLFCR_GMCFG                                       CMU_XTLFCR_GMCFG_Msk

#define    CMU_XTLFCR_ICFG_Pos                                    (0U)
#define    CMU_XTLFCR_ICFG_Msk                                    (0x3U << CMU_XTLFCR_ICFG_Pos)
#define    CMU_XTLFCR_ICFG                                        CMU_XTLFCR_ICFG_Msk

#define    CMU_LSCLKSEL_LSSTA_Pos                                 (8U)
#define    CMU_LSCLKSEL_LSSTA_Msk                                 (0x1U << CMU_LSCLKSEL_LSSTA_Pos)
#define    CMU_LSCLKSEL_LSSTA                                     CMU_LSCLKSEL_LSSTA_Msk

#define    CMU_LSCLKSEL_SEL_Pos                                   (0U)
#define    CMU_LSCLKSEL_SEL_Msk                                   (0xffU << CMU_LSCLKSEL_SEL_Pos)
#define    CMU_LSCLKSEL_SEL                                       CMU_LSCLKSEL_SEL_Msk

#define    CMU_XTHFCR_WAIT_Pos                                    (13U)
#define    CMU_XTHFCR_WAIT_Msk                                    (0x7U << CMU_XTHFCR_WAIT_Pos)
#define    CMU_XTHFCR_WAIT                                        CMU_XTHFCR_WAIT_Msk

#define    CMU_XTHFCR_BYP_Pos                                     (12U)
#define    CMU_XTHFCR_BYP_Msk                                     (0x1U << CMU_XTHFCR_BYP_Pos)
#define    CMU_XTHFCR_BYP                                         CMU_XTHFCR_BYP_Msk

#define    CMU_XTHFCR_CFG_Pos                                     (8U)
#define    CMU_XTHFCR_CFG_Msk                                     (0xfU << CMU_XTHFCR_CFG_Pos)
#define    CMU_XTHFCR_CFG                                         CMU_XTHFCR_CFG_Msk

#define    CMU_XTHFCR_RDY_Pos                                     (1U)
#define    CMU_XTHFCR_RDY_Msk                                     (0x1U << CMU_XTHFCR_RDY_Pos)
#define    CMU_XTHFCR_RDY                                         CMU_XTHFCR_RDY_Msk

#define    CMU_XTHFCR_EN_Pos                                      (0U)
#define    CMU_XTHFCR_EN_Msk                                      (0x1U << CMU_XTHFCR_EN_Pos)
#define    CMU_XTHFCR_EN                                          CMU_XTHFCR_EN_Msk

#define    CMU_IER_SYSCKE_IE_Pos                                  (2U)
#define    CMU_IER_SYSCKE_IE_Msk                                  (0x1U << CMU_IER_SYSCKE_IE_Pos)
#define    CMU_IER_SYSCKE_IE                                      CMU_IER_SYSCKE_IE_Msk

#define    CMU_IER_HFDET_IE_Pos                                   (1U)
#define    CMU_IER_HFDET_IE_Msk                                   (0x1U << CMU_IER_HFDET_IE_Pos)
#define    CMU_IER_HFDET_IE                                       CMU_IER_HFDET_IE_Msk

#define    CMU_IER_LFDET_IE_Pos                                   (0U)
#define    CMU_IER_LFDET_IE_Msk                                   (0x1U << CMU_IER_LFDET_IE_Pos)
#define    CMU_IER_LFDET_IE                                       CMU_IER_LFDET_IE_Msk

#define    CMU_ISR_HFDETO_Pos                                     (9U)
#define    CMU_ISR_HFDETO_Msk                                     (0x1U << CMU_ISR_HFDETO_Pos)
#define    CMU_ISR_HFDETO                                         CMU_ISR_HFDETO_Msk

#define    CMU_ISR_LFDETO_Pos                                     (8U)
#define    CMU_ISR_LFDETO_Msk                                     (0x1U << CMU_ISR_LFDETO_Pos)
#define    CMU_ISR_LFDETO                                         CMU_ISR_LFDETO_Msk

#define    CMU_ISR_LOLIF_Pos                                      (3U)
#define    CMU_ISR_LOLIF_Msk                                      (0x1U << CMU_ISR_LOLIF_Pos)
#define    CMU_ISR_LOLIF                                          CMU_ISR_LOLIF_Msk

#define    CMU_ISR_SYSCSE_IF_Pos                                  (2U)
#define    CMU_ISR_SYSCSE_IF_Msk                                  (0x1U << CMU_ISR_SYSCSE_IF_Pos)
#define    CMU_ISR_SYSCSE_IF                                      CMU_ISR_SYSCSE_IF_Msk

#define    CMU_ISR_HFDET_IF_Pos                                   (1U)
#define    CMU_ISR_HFDET_IF_Msk                                   (0x1U << CMU_ISR_HFDET_IF_Pos)
#define    CMU_ISR_HFDET_IF                                       CMU_ISR_HFDET_IF_Msk

#define    CMU_ISR_LFDET_IF_Pos                                   (0U)
#define    CMU_ISR_LFDET_IF_Msk                                   (0x1U << CMU_ISR_LFDET_IF_Pos)
#define    CMU_ISR_LFDET_IF                                       CMU_ISR_LFDET_IF_Msk

#define    CMU_OPCCR1_EXTICKS_Pos                                 (30U)
#define    CMU_OPCCR1_EXTICKS_Msk                                 (0x1U << CMU_OPCCR1_EXTICKS_Pos)
#define    CMU_OPCCR1_EXTICKS                                     CMU_OPCCR1_EXTICKS_Msk

#define    CMU_OPCCR1_UART3CKS_Pos                                (28U)
#define    CMU_OPCCR1_UART3CKS_Msk                                (0x3U << CMU_OPCCR1_UART3CKS_Pos)
#define    CMU_OPCCR1_UART3CKS                                    CMU_OPCCR1_UART3CKS_Msk

#define    CMU_OPCCR1_LPUART2CKS_Pos                              (26U)
#define    CMU_OPCCR1_LPUART2CKS_Msk                              (0x3U << CMU_OPCCR1_LPUART2CKS_Pos)
#define    CMU_OPCCR1_LPUART2CKS                                  CMU_OPCCR1_LPUART2CKS_Msk

#define    CMU_OPCCR1_LPUART1CKS_Pos                              (24U)
#define    CMU_OPCCR1_LPUART1CKS_Msk                              (0x3U << CMU_OPCCR1_LPUART1CKS_Pos)
#define    CMU_OPCCR1_LPUART1CKS                                  CMU_OPCCR1_LPUART1CKS_Msk

#define    CMU_OPCCR1_LPUART0CKS_Pos                              (22U)
#define    CMU_OPCCR1_LPUART0CKS_Msk                              (0x3U << CMU_OPCCR1_LPUART0CKS_Pos)
#define    CMU_OPCCR1_LPUART0CKS                                  CMU_OPCCR1_LPUART0CKS_Msk

#define    CMU_OPCCR1_UART2CKS_Pos                                (20U)
#define    CMU_OPCCR1_UART2CKS_Msk                                (0x3U << CMU_OPCCR1_UART2CKS_Pos)
#define    CMU_OPCCR1_UART2CKS                                    CMU_OPCCR1_UART2CKS_Msk

#define    CMU_OPCCR1_I2CSMB1CKS_Pos                              (18U)
#define    CMU_OPCCR1_I2CSMB1CKS_Msk                              (0x3U << CMU_OPCCR1_I2CSMB1CKS_Pos)
#define    CMU_OPCCR1_I2CSMB1CKS                                  CMU_OPCCR1_I2CSMB1CKS_Msk

#define    CMU_OPCCR1_I2CSMB0CKS_Pos                              (16U)
#define    CMU_OPCCR1_I2CSMB0CKS_Msk                              (0x3U << CMU_OPCCR1_I2CSMB0CKS_Pos)
#define    CMU_OPCCR1_I2CSMB0CKS                                  CMU_OPCCR1_I2CSMB0CKS_Msk

#define    CMU_OPCCR1_BT16CKS_Pos                                 (14U)
#define    CMU_OPCCR1_BT16CKS_Msk                                 (0x3U << CMU_OPCCR1_BT16CKS_Pos)
#define    CMU_OPCCR1_BT16CKS                                     CMU_OPCCR1_BT16CKS_Msk

#define    CMU_OPCCR1_BT32CKS_Pos                                 (12U)
#define    CMU_OPCCR1_BT32CKS_Msk                                 (0x3U << CMU_OPCCR1_BT32CKS_Pos)
#define    CMU_OPCCR1_BT32CKS                                     CMU_OPCCR1_BT32CKS_Msk

#define    CMU_OPCCR1_LPT16CKS_Pos                                (10U)
#define    CMU_OPCCR1_LPT16CKS_Msk                                (0x3U << CMU_OPCCR1_LPT16CKS_Pos)
#define    CMU_OPCCR1_LPT16CKS                                    CMU_OPCCR1_LPT16CKS_Msk

#define    CMU_OPCCR1_LPT32CKS_Pos                                (8U)
#define    CMU_OPCCR1_LPT32CKS_Msk                                (0x3U << CMU_OPCCR1_LPT32CKS_Pos)
#define    CMU_OPCCR1_LPT32CKS                                    CMU_OPCCR1_LPT32CKS_Msk

#define    CMU_OPCCR1_ATCKS_Pos                                   (7U)
#define    CMU_OPCCR1_ATCKS_Msk                                   (0x1U << CMU_OPCCR1_ATCKS_Pos)
#define    CMU_OPCCR1_ATCKS                                       CMU_OPCCR1_ATCKS_Msk

#define    CMU_OPCCR1_FSCANCKS_Pos                                (4U)
#define    CMU_OPCCR1_FSCANCKS_Msk                                (0x3U << CMU_OPCCR1_FSCANCKS_Pos)
#define    CMU_OPCCR1_FSCANCKS                                    CMU_OPCCR1_FSCANCKS_Msk

#define    CMU_OPCCR1_UART1CKS_Pos                                (2U)
#define    CMU_OPCCR1_UART1CKS_Msk                                (0x3U << CMU_OPCCR1_UART1CKS_Pos)
#define    CMU_OPCCR1_UART1CKS                                    CMU_OPCCR1_UART1CKS_Msk

#define    CMU_OPCCR1_UART0CKS_Pos                                (0U)
#define    CMU_OPCCR1_UART0CKS_Msk                                (0x3U << CMU_OPCCR1_UART0CKS_Pos)
#define    CMU_OPCCR1_UART0CKS                                    CMU_OPCCR1_UART0CKS_Msk

#define    CMU_OPCCR2_RTCPRSC_Pos                                 (22U)
#define    CMU_OPCCR2_RTCPRSC_Msk                                 (0x3ffU << CMU_OPCCR2_RTCPRSC_Pos)
#define    CMU_OPCCR2_RTCPRSC                                     CMU_OPCCR2_RTCPRSC_Msk

#define    CMU_OPCCR2_RTCCKS_Pos                                  (16U)
#define    CMU_OPCCR2_RTCCKS_Msk                                  (0x1U << CMU_OPCCR2_RTCCKS_Pos)
#define    CMU_OPCCR2_RTCCKS                                      CMU_OPCCR2_RTCCKS_Msk

#define    CMU_OPCCR2_RNGPRSC_Pos                                 (10U)
#define    CMU_OPCCR2_RNGPRSC_Msk                                 (0x7U << CMU_OPCCR2_RNGPRSC_Pos)
#define    CMU_OPCCR2_RNGPRSC                                     CMU_OPCCR2_RNGPRSC_Msk

#define    CMU_OPCCR2_ADCPRSC_Pos                                 (2U)
#define    CMU_OPCCR2_ADCPRSC_Msk                                 (0x7U << CMU_OPCCR2_ADCPRSC_Pos)
#define    CMU_OPCCR2_ADCPRSC                                     CMU_OPCCR2_ADCPRSC_Msk

#define    CMU_OPCCR2_ADCCKS_Pos                                  (0U)
#define    CMU_OPCCR2_ADCCKS_Msk                                  (0x3U << CMU_OPCCR2_ADCCKS_Pos)
#define    CMU_OPCCR2_ADCCKS                                      CMU_OPCCR2_ADCCKS_Msk

/* ALL SUPPOTRED EXCEPT CHIP U01. START */
#define    CMU_AHBMCR_LOL_IE_Pos                                  (30U)
#define    CMU_AHBMCR_LOL_IE_Msk                                  (0x1U << CMU_AHBMCR_LOL_IE_Pos)
#define    CMU_AHBMCR_LOL_IE                                      CMU_AHBMCR_LOL_IE_Msk
/* ALL SUPPOTRED EXCEPT CHIP U01. END */

#define    CMU_AHBMCR_MPRIL_Pos                                   (0U)
#define    CMU_AHBMCR_MPRIL_Msk                                   (0x1U << CMU_AHBMCR_MPRIL_Pos)
#define    CMU_AHBMCR_MPRIL                                       CMU_AHBMCR_MPRIL_Msk

#define    CMU_CFDCR_CANFD1CKS_Pos                                (6U)
#define    CMU_CFDCR_CANFD1CKS_Msk                                (0x3U << CMU_CFDCR_CANFD1CKS_Pos)
#define    CMU_CFDCR_CANFD1CKS                                    CMU_CFDCR_CANFD1CKS_Msk

#define    CMU_CFDCR_CANFD1CKRS_Pos                               (4U)
#define    CMU_CFDCR_CANFD1CKRS_Msk                               (0x3U << CMU_CFDCR_CANFD1CKRS_Pos)
#define    CMU_CFDCR_CANFD1CKRS                                   CMU_CFDCR_CANFD1CKRS_Msk

#define    CMU_CFDCR_CANFD0CKS_Pos                                (2U)
#define    CMU_CFDCR_CANFD0CKS_Msk                                (0x3U << CMU_CFDCR_CANFD0CKS_Pos)
#define    CMU_CFDCR_CANFD0CKS                                    CMU_CFDCR_CANFD0CKS_Msk

#define    CMU_CFDCR_CANFD0CKRS_Pos                               (0U)
#define    CMU_CFDCR_CANFD0CKRS_Msk                               (0x3U << CMU_CFDCR_CANFD0CKRS_Pos)
#define    CMU_CFDCR_CANFD0CKRS                                   CMU_CFDCR_CANFD0CKRS_Msk



#define    FL_CMU_GROUP1_BUSCLK_LPTIM32                           (0x1U << 0U)
#define    FL_CMU_GROUP1_BUSCLK_LPTIM16                           (0x1U << 1U)
#define    FL_CMU_GROUP1_BUSCLK_RTC                               (0x1U << 2U)
#define    FL_CMU_GROUP1_BUSCLK_PMU                               (0x1U << 3U)
#define    FL_CMU_GROUP1_BUSCLK_SCU                               (0x1U << 4U)
#define    FL_CMU_GROUP1_BUSCLK_IWDT                              (0x1U << 5U)
#define    FL_CMU_GROUP1_BUSCLK_ANAC                              (0x1U << 6U)
#define    FL_CMU_GROUP1_BUSCLK_PAD                               (0x1U << 7U)
#define    FL_CMU_GROUP1_BUSCLK_SVD                               (0x1U << 8U)
#define    FL_CMU_GROUP1_BUSCLK_COMP                              (0x1U << 9U)
#define    FL_CMU_GROUP1_BUSCLK_CLM0                              (0x1U << 10U)
#define    FL_CMU_GROUP1_BUSCLK_CLM1                              (0x1U << 11U)
#define    FL_CMU_GROUP2_BUSCLK_CRC                               (0x1U << 0U)
#define    FL_CMU_GROUP2_BUSCLK_RNG                               (0x1U << 1U)
#define    FL_CMU_GROUP2_BUSCLK_AES                               (0x1U << 2U)
#define    FL_CMU_GROUP2_BUSCLK_DMA                               (0x1U << 4U)
#define    FL_CMU_GROUP2_BUSCLK_FLASH                             (0x1U << 5U)
#define    FL_CMU_GROUP2_BUSCLK_RAMBIST                           (0x1U << 6U)
#define    FL_CMU_GROUP2_BUSCLK_WWDT                              (0x1U << 7U)
#define    FL_CMU_GROUP2_BUSCLK_ADC                               (0x1U << 8U)
#define    FL_CMU_GROUP2_BUSCLK_HDIV                              (0x1U << 9U)
#define    FL_CMU_GROUP2_BUSCLK_DAC                               (0x1U << 10U)
#define    FL_CMU_GROUP2_BUSCLK_PGL                               (0x1U << 11U)
#define    FL_CMU_GROUP3_BUSCLK_SPI0                              (0x1U << 0U)
#define    FL_CMU_GROUP3_BUSCLK_SPI1                              (0x1U << 1U)
#define    FL_CMU_GROUP3_BUSCLK_SPI2                              (0x1U << 2U)
#define    FL_CMU_GROUP3_BUSCLK_SPI3                              (0x1U << 3U)
#define    FL_CMU_GROUP3_BUSCLK_UART0                             (0x1U << 8U)
#define    FL_CMU_GROUP3_BUSCLK_UART1                             (0x1U << 9U)
#define    FL_CMU_GROUP3_BUSCLK_UART2                             (0x1U << 10U)
#define    FL_CMU_GROUP3_BUSCLK_UART3                             (0x1U << 11U)
#define    FL_CMU_GROUP3_BUSCLK_UART4                             (0x1U << 12U)
#define    FL_CMU_GROUP3_BUSCLK_UART5                             (0x1U << 13U)
#define    FL_CMU_GROUP3_BUSCLK_UARTIR                            (0x1U << 14U)
#define    FL_CMU_GROUP3_BUSCLK_LPUART0                           (0x1U << 16U)
#define    FL_CMU_GROUP3_BUSCLK_LPUART1                           (0x1U << 17U)
#define    FL_CMU_GROUP3_BUSCLK_LPUART2                           (0x1U << 18U)
#define    FL_CMU_GROUP3_BUSCLK_FSCAN                             (0x1U << 19U)
#define    FL_CMU_GROUP3_BUSCLK_CANFD0                            (0x1U << 22U)
#define    FL_CMU_GROUP3_BUSCLK_CANFD1                            (0x1U << 23U)
#define    FL_CMU_GROUP3_BUSCLK_I2C0                              (0x1U << 24U)
#define    FL_CMU_GROUP3_BUSCLK_I2C1                              (0x1U << 25U)
#define    FL_CMU_GROUP3_BUSCLK_I2CSMB0                           (0x1U << 28U)
#define    FL_CMU_GROUP3_BUSCLK_I2CSMB1                           (0x1U << 29U)
#define    FL_CMU_GROUP3_BUSCLK_SENT0                             (0x1U << 30U)
#define    FL_CMU_GROUP3_BUSCLK_SENT1                             (0x1U << 31U)
#define    FL_CMU_GROUP4_BUSCLK_BSTIM32                           (0x1U << 0U)
#define    FL_CMU_GROUP4_BUSCLK_GPTIM0                            (0x1U << 1U)
#define    FL_CMU_GROUP4_BUSCLK_GPTIM1                            (0x1U << 2U)
#define    FL_CMU_GROUP4_BUSCLK_GPTIM2                            (0x1U << 3U)
#define    FL_CMU_GROUP4_BUSCLK_TAU0                              (0x1U << 4U)
#define    FL_CMU_GROUP4_BUSCLK_TAU1                              (0x1U << 5U)
#define    FL_CMU_GROUP4_BUSCLK_ATIM                              (0x1U << 7U)
#define    FL_CMU_GROUP4_BUSCLK_BSTIM16                           (0x1U << 8U)
#define    FL_CMU_OPCLK_EXTI                                      (0x1U << 31U)
#define    FL_CMU_OPCLK_FLASH                                     (0x1U << 30U)
#define    FL_CMU_OPCLK_LPUART0                                   (0x1U << 29U)
#define    FL_CMU_OPCLK_LPUART1                                   (0x1U << 28U)
#define    FL_CMU_OPCLK_LPUART2                                   (0x1U << 27U)
#define    FL_CMU_OPCLK_RNG                                       (0x1U << 24U)
#define    FL_CMU_OPCLK_I2CSMB1                                   (0x1U << 21U)
#define    FL_CMU_OPCLK_I2CSMB0                                   (0x1U << 20U)
#define    FL_CMU_OPCLK_ADC                                       (0x1U << 16U)
#define    FL_CMU_OPCLK_ATIM                                      (0x1U << 15U)
#define    FL_CMU_OPCLK_FSCAN                                     (0x1U << 13U)
#define    FL_CMU_OPCLK_LIN                                       (0x1U << 12U)
#define    FL_CMU_OPCLK_UART3                                     (0x1U << 11U)
#define    FL_CMU_OPCLK_UART2                                     (0x1U << 10U)
#define    FL_CMU_OPCLK_UART1                                     (0x1U << 9U)
#define    FL_CMU_OPCLK_UART0                                     (0x1U << 8U)
#define    FL_CMU_OPCLK_BSTIM16                                   (0x1U << 3U)
#define    FL_CMU_OPCLK_BSTIM32                                   (0x1U << 2U)
#define    FL_CMU_OPCLK_LPTIM16                                   (0x1U << 1U)
#define    FL_CMU_OPCLK_LPTIM32                                   (0x1U << 0U)
#define    FL_CMU_OPCLK_CANFD1_COMM                               (0x1U << 5U)
#define    FL_CMU_OPCLK_CANFD1_RAM                                (0x1U << 4U)
#define    FL_CMU_OPCLK_CANFD0_COMM                               (0x1U << 1U)
#define    FL_CMU_OPCLK_CANFD0_RAM                                (0x1U << 0U)



#define    FL_CMU_APB2CLK_PSC_DIV1                                (0x0U << CMU_SYSCLKCR_APB2PRES_Pos)
#define    FL_CMU_APB2CLK_PSC_DIV2                                (0x4U << CMU_SYSCLKCR_APB2PRES_Pos)
#define    FL_CMU_APB2CLK_PSC_DIV4                                (0x5U << CMU_SYSCLKCR_APB2PRES_Pos)
#define    FL_CMU_APB2CLK_PSC_DIV8                                (0x6U << CMU_SYSCLKCR_APB2PRES_Pos)
#define    FL_CMU_APB2CLK_PSC_DIV16                               (0x7U << CMU_SYSCLKCR_APB2PRES_Pos)


#define    FL_CMU_APB1CLK_PSC_DIV1                                (0x0U << CMU_SYSCLKCR_APB1PRES_Pos)
#define    FL_CMU_APB1CLK_PSC_DIV2                                (0x4U << CMU_SYSCLKCR_APB1PRES_Pos)
#define    FL_CMU_APB1CLK_PSC_DIV4                                (0x5U << CMU_SYSCLKCR_APB1PRES_Pos)
#define    FL_CMU_APB1CLK_PSC_DIV8                                (0x6U << CMU_SYSCLKCR_APB1PRES_Pos)
#define    FL_CMU_APB1CLK_PSC_DIV16                               (0x7U << CMU_SYSCLKCR_APB1PRES_Pos)


#define    FL_CMU_AHBCLK_PSC_DIV1                                 (0x0U << CMU_SYSCLKCR_AHBPRES_Pos)
#define    FL_CMU_AHBCLK_PSC_DIV2                                 (0x4U << CMU_SYSCLKCR_AHBPRES_Pos)
#define    FL_CMU_AHBCLK_PSC_DIV4                                 (0x5U << CMU_SYSCLKCR_AHBPRES_Pos)
#define    FL_CMU_AHBCLK_PSC_DIV8                                 (0x6U << CMU_SYSCLKCR_AHBPRES_Pos)
#define    FL_CMU_AHBCLK_PSC_DIV16                                (0x7U << CMU_SYSCLKCR_AHBPRES_Pos)


#define    FL_CMU_SYSTICK_CLK_SOURCE_SCLK                         (0x0U << CMU_SYSCLKCR_STCLKSEL_Pos)
#define    FL_CMU_SYSTICK_CLK_SOURCE_LSCLK                        (0x1U << CMU_SYSCLKCR_STCLKSEL_Pos)


#define    FL_CMU_SYSTEM_CLK_SOURCE_RCHF                          (0x0U << CMU_SYSCLKCR_SYSCLKSEL_Pos)
#define    FL_CMU_SYSTEM_CLK_SOURCE_XTHF                          (0x1U << CMU_SYSCLKCR_SYSCLKSEL_Pos)
#define    FL_CMU_SYSTEM_CLK_SOURCE_PLL                           (0x2U << CMU_SYSCLKCR_SYSCLKSEL_Pos)
#define    FL_CMU_SYSTEM_CLK_SOURCE_RCLP                          (0x6U << CMU_SYSCLKCR_SYSCLKSEL_Pos)


#define    FL_CMU_RCHF_FREQUENCY_8MHZ                             (0x0U << CMU_RCHFCR_FSEL_Pos)
#define    FL_CMU_RCHF_FREQUENCY_16MHZ                            (0x1U << CMU_RCHFCR_FSEL_Pos)
#define    FL_CMU_RCHF_FREQUENCY_24MHZ                            (0x2U << CMU_RCHFCR_FSEL_Pos)
#define    FL_CMU_RCHF_FREQUENCY_32MHZ                            (0x3U << CMU_RCHFCR_FSEL_Pos)


#define    FL_CMU_PLL_PSC_DIV1                                    (0x0U << CMU_PLLCR_REFPRSC_Pos)
#define    FL_CMU_PLL_PSC_DIV2                                    (0x1U << CMU_PLLCR_REFPRSC_Pos)
#define    FL_CMU_PLL_PSC_DIV4                                    (0x2U << CMU_PLLCR_REFPRSC_Pos)
#define    FL_CMU_PLL_PSC_DIV8                                    (0x3U << CMU_PLLCR_REFPRSC_Pos)
#define    FL_CMU_PLL_PSC_DIV12                                   (0x4U << CMU_PLLCR_REFPRSC_Pos)
#define    FL_CMU_PLL_PSC_DIV16                                   (0x5U << CMU_PLLCR_REFPRSC_Pos)
#define    FL_CMU_PLL_PSC_DIV24                                   (0x6U << CMU_PLLCR_REFPRSC_Pos)
#define    FL_CMU_PLL_PSC_DIV32                                   (0x7U << CMU_PLLCR_REFPRSC_Pos)


#define    FL_CMU_PLL_CLK_SOURCE_RCHF                             (0x0U << CMU_PLLCR_INSEL_Pos)
#define    FL_CMU_PLL_CLK_SOURCE_XTHF                             (0x1U << CMU_PLLCR_INSEL_Pos)


#define    FL_CMU_XTLF_START_WAIT_CYCLE_128                       (0x0U << CMU_XTLFCR_WAIT_Pos)
#define    FL_CMU_XTLF_START_WAIT_CYCLE_256                       (0x1U << CMU_XTLFCR_WAIT_Pos)
#define    FL_CMU_XTLF_START_WAIT_CYCLE_512                       (0x2U << CMU_XTLFCR_WAIT_Pos)
#define    FL_CMU_XTLF_START_WAIT_CYCLE_1024                      (0x3U << CMU_XTLFCR_WAIT_Pos)
#define    FL_CMU_XTLF_START_WAIT_CYCLE_2048                      (0x4U << CMU_XTLFCR_WAIT_Pos)
#define    FL_CMU_XTLF_START_WAIT_CYCLE_4096                      (0x5U << CMU_XTLFCR_WAIT_Pos)
#define    FL_CMU_XTLF_START_WAIT_CYCLE_8192                      (0x6U << CMU_XTLFCR_WAIT_Pos)
#define    FL_CMU_XTLF_START_WAIT_CYCLE_16384                     (0x7U << CMU_XTLFCR_WAIT_Pos)


#define    FL_CMU_XTLF_FDET_ENABLE                                (0x5U << CMU_XTLFCR_EN_Pos)

#define    FL_CMU_XTLF_FDET_DISABLE                               (0xaU << CMU_XTLFCR_EN_Pos)

#define    FL_CMU_XTLF_WORK_GAIN0                                 (0x0U << CMU_XTLFCR_GMCFG_Pos)
#define    FL_CMU_XTLF_WORK_GAIN1                                 (0x1U << CMU_XTLFCR_GMCFG_Pos)
#define    FL_CMU_XTLF_WORK_GAIN2                                 (0x2U << CMU_XTLFCR_GMCFG_Pos)
#define    FL_CMU_XTLF_WORK_GAIN3                                 (0x3U << CMU_XTLFCR_GMCFG_Pos)
#define    FL_CMU_XTLF_WORK_GAIN4                                 (0x4U << CMU_XTLFCR_GMCFG_Pos)
#define    FL_CMU_XTLF_WORK_GAIN5                                 (0x5U << CMU_XTLFCR_GMCFG_Pos)
#define    FL_CMU_XTLF_WORK_GAIN6                                 (0x6U << CMU_XTLFCR_GMCFG_Pos)
#define    FL_CMU_XTLF_WORK_GAIN7                                 (0x7U << CMU_XTLFCR_GMCFG_Pos)


#define    FL_CMU_XTLF_WORK_CURRENT0                              (0x0U << CMU_XTLFCR_ICFG_Pos)
#define    FL_CMU_XTLF_WORK_CURRENT1                              (0x1U << CMU_XTLFCR_ICFG_Pos)
#define    FL_CMU_XTLF_WORK_CURRENT2                              (0x2U << CMU_XTLFCR_ICFG_Pos)
#define    FL_CMU_XTLF_WORK_CURRENT3                              (0x3U << CMU_XTLFCR_ICFG_Pos)


#define    FL_CMU_LSCLK_SOURCE_XTLF                               (0x0U << CMU_LSCLKSEL_LSSTA_Pos)
#define    FL_CMU_LSCLK_SOURCE_RCLP                               (0x1U << CMU_LSCLKSEL_LSSTA_Pos)

#define    FL_CMU_SET_LSCLK_SOURCE_RCLP                           (0x55U << CMU_LSCLKSEL_SEL_Pos)
#define    FL_CMU_SET_LSCLK_SOURCE_XTLF                           (0xAAU << CMU_LSCLKSEL_SEL_Pos)

#define    FL_CMU_XTHF_START_WAIT_CYCLE_128                       (0x0U << CMU_XTHFCR_WAIT_Pos)
#define    FL_CMU_XTHF_START_WAIT_CYCLE_256                       (0x1U << CMU_XTHFCR_WAIT_Pos)
#define    FL_CMU_XTHF_START_WAIT_CYCLE_512                       (0x2U << CMU_XTHFCR_WAIT_Pos)
#define    FL_CMU_XTHF_START_WAIT_CYCLE_1024                      (0x3U << CMU_XTHFCR_WAIT_Pos)
#define    FL_CMU_XTHF_START_WAIT_CYCLE_2048                      (0x4U << CMU_XTHFCR_WAIT_Pos)
#define    FL_CMU_XTHF_START_WAIT_CYCLE_4096                      (0x5U << CMU_XTHFCR_WAIT_Pos)
#define    FL_CMU_XTHF_START_WAIT_CYCLE_8192                      (0x6U << CMU_XTHFCR_WAIT_Pos)
#define    FL_CMU_XTHF_START_WAIT_CYCLE_16384                     (0x7U << CMU_XTHFCR_WAIT_Pos)


#define    FL_CMU_EXTI_CLK_SOURCE_LSCLK                           (0x1U << CMU_OPCCR1_EXTICKS_Pos)
#define    FL_CMU_EXTI_CLK_SOURCE_AHBCLK                          (0x0U << CMU_OPCCR1_EXTICKS_Pos)

#define    FL_CMU_UART3_CLK_SOURCE_APBCLK                         (0x0U << CMU_OPCCR1_UART3CKS_Pos)
#define    FL_CMU_UART3_CLK_SOURCE_RCHF                           (0x1U << CMU_OPCCR1_UART3CKS_Pos)
#define    FL_CMU_UART3_CLK_SOURCE_SYSCLK                         (0x2U << CMU_OPCCR1_UART3CKS_Pos)
#define    FL_CMU_UART3_CLK_SOURCE_XTHF                           (0x3U << CMU_OPCCR1_UART3CKS_Pos)


#define    FL_CMU_LPUART2_CLK_SOURCE_LSCLK                        (0x0U << CMU_OPCCR1_LPUART2CKS_Pos)
#define    FL_CMU_LPUART2_CLK_SOURCE_RCHF_PSC                     (0x1U << CMU_OPCCR1_LPUART2CKS_Pos)


#define    FL_CMU_LPUART1_CLK_SOURCE_LSCLK                        (0x0U << CMU_OPCCR1_LPUART1CKS_Pos)
#define    FL_CMU_LPUART1_CLK_SOURCE_RCHF_PSC                     (0x1U << CMU_OPCCR1_LPUART1CKS_Pos)


#define    FL_CMU_LPUART0_CLK_SOURCE_LSCLK                        (0x0U << CMU_OPCCR1_LPUART0CKS_Pos)
#define    FL_CMU_LPUART0_CLK_SOURCE_RCHF_PSC                     (0x1U << CMU_OPCCR1_LPUART0CKS_Pos)


#define    FL_CMU_UART2_CLK_SOURCE_APBCLK                         (0x0U << CMU_OPCCR1_UART2CKS_Pos)
#define    FL_CMU_UART2_CLK_SOURCE_RCHF                           (0x1U << CMU_OPCCR1_UART2CKS_Pos)
#define    FL_CMU_UART2_CLK_SOURCE_SYSCLK                         (0x2U << CMU_OPCCR1_UART2CKS_Pos)
#define    FL_CMU_UART2_CLK_SOURCE_XTHF                           (0x3U << CMU_OPCCR1_UART2CKS_Pos)


#define    FL_CMU_I2CSMB1_CLK_SOURCE_APBCLK                       (0x0U << CMU_OPCCR1_I2CSMB1CKS_Pos)
#define    FL_CMU_I2CSMB1_CLK_SOURCE_RCHF                         (0x1U << CMU_OPCCR1_I2CSMB1CKS_Pos)
#define    FL_CMU_I2CSMB1_CLK_SOURCE_SYSCLK                       (0x2U << CMU_OPCCR1_I2CSMB1CKS_Pos)


#define    FL_CMU_I2CSMB0_CLK_SOURCE_APBCLK                       (0x0U << CMU_OPCCR1_I2CSMB0CKS_Pos)
#define    FL_CMU_I2CSMB0_CLK_SOURCE_RCHF                         (0x1U << CMU_OPCCR1_I2CSMB0CKS_Pos)
#define    FL_CMU_I2CSMB0_CLK_SOURCE_SYSCLK                       (0x2U << CMU_OPCCR1_I2CSMB0CKS_Pos)


#define    FL_CMU_BSTIM16_CLK_SOURCE_APBCLK                       (0x0U << CMU_OPCCR1_BT16CKS_Pos)
#define    FL_CMU_BSTIM16_CLK_SOURCE_LSCLK                        (0x1U << CMU_OPCCR1_BT16CKS_Pos)
#define    FL_CMU_BSTIM16_CLK_SOURCE_RCLP                         (0x2U << CMU_OPCCR1_BT16CKS_Pos)


#define    FL_CMU_BSTIM32_CLK_SOURCE_APBCLK                       (0x0U << CMU_OPCCR1_BT32CKS_Pos)
#define    FL_CMU_BSTIM32_CLK_SOURCE_LSCLK                        (0x1U << CMU_OPCCR1_BT32CKS_Pos)
#define    FL_CMU_BSTIM32_CLK_SOURCE_RCLP                         (0x2U << CMU_OPCCR1_BT32CKS_Pos)


#define    FL_CMU_LPTIM16_CLK_SOURCE_APBCLK                       (0x0U << CMU_OPCCR1_LPT16CKS_Pos)
#define    FL_CMU_LPTIM16_CLK_SOURCE_LSCLK                        (0x1U << CMU_OPCCR1_LPT16CKS_Pos)
#define    FL_CMU_LPTIM16_CLK_SOURCE_RCLP                         (0x2U << CMU_OPCCR1_LPT16CKS_Pos)


#define    FL_CMU_LPTIM32_CLK_SOURCE_APBCLK                       (0x0U << CMU_OPCCR1_LPT32CKS_Pos)
#define    FL_CMU_LPTIM32_CLK_SOURCE_LSCLK                        (0x1U << CMU_OPCCR1_LPT32CKS_Pos)
#define    FL_CMU_LPTIM32_CLK_SOURCE_RCLP                         (0x2U << CMU_OPCCR1_LPT32CKS_Pos)


#define    FL_CMU_ATIM_CLK_SOURCE_APBCLK                          (0x0U << CMU_OPCCR1_ATCKS_Pos)
#define    FL_CMU_ATIM_CLK_SOURCE_PLL_X2                          (0x1U << CMU_OPCCR1_ATCKS_Pos)


#define    FL_CMU_FSCAN_CLK_SOURCE_RCHF                           (0x0U << CMU_OPCCR1_FSCANCKS_Pos)
#define    FL_CMU_FSCAN_CLK_SOURCE_XTHF                           (0x1U << CMU_OPCCR1_FSCANCKS_Pos)
#define    FL_CMU_FSCAN_CLK_SOURCE_PLL                            (0x2U << CMU_OPCCR1_FSCANCKS_Pos)
#define    FL_CMU_FSCAN_CLK_SOURCE_APBCLK                         (0x3U << CMU_OPCCR1_FSCANCKS_Pos)


#define    FL_CMU_UART1_CLK_SOURCE_APBCLK                         (0x0U << CMU_OPCCR1_UART1CKS_Pos)
#define    FL_CMU_UART1_CLK_SOURCE_RCHF                           (0x1U << CMU_OPCCR1_UART1CKS_Pos)
#define    FL_CMU_UART1_CLK_SOURCE_SYSCLK                         (0x2U << CMU_OPCCR1_UART1CKS_Pos)
#define    FL_CMU_UART1_CLK_SOURCE_XTHF                           (0x3U << CMU_OPCCR1_UART1CKS_Pos)


#define    FL_CMU_UART0_CLK_SOURCE_APBCLK                         (0x0U << CMU_OPCCR1_UART0CKS_Pos)
#define    FL_CMU_UART0_CLK_SOURCE_RCHF                           (0x1U << CMU_OPCCR1_UART0CKS_Pos)
#define    FL_CMU_UART0_CLK_SOURCE_SYSCLK                         (0x2U << CMU_OPCCR1_UART0CKS_Pos)
#define    FL_CMU_UART0_CLK_SOURCE_XTHF                           (0x3U << CMU_OPCCR1_UART0CKS_Pos)


#define    FL_CMU_RTC_CLK_SOURCE_LSCLK                            (0x0U << CMU_OPCCR2_RTCCKS_Pos)
#define    FL_CMU_RTC_CLK_SOURCE_XTHF_PSC                         (0x1U << CMU_OPCCR2_RTCCKS_Pos)


#define    FL_CMU_RNG_PSC_DIV1                                    (0x0U << CMU_OPCCR2_RNGPRSC_Pos)
#define    FL_CMU_RNG_PSC_DIV2                                    (0x1U << CMU_OPCCR2_RNGPRSC_Pos)
#define    FL_CMU_RNG_PSC_DIV4                                    (0x2U << CMU_OPCCR2_RNGPRSC_Pos)
#define    FL_CMU_RNG_PSC_DIV8                                    (0x3U << CMU_OPCCR2_RNGPRSC_Pos)
#define    FL_CMU_RNG_PSC_DIV16                                   (0x4U << CMU_OPCCR2_RNGPRSC_Pos)
#define    FL_CMU_RNG_PSC_DIV32                                   (0x5U << CMU_OPCCR2_RNGPRSC_Pos)


#define    FL_CMU_ADC_PSC_DIV1                                    (0x0U << CMU_OPCCR2_ADCPRSC_Pos)
#define    FL_CMU_ADC_PSC_DIV2                                    (0x1U << CMU_OPCCR2_ADCPRSC_Pos)
#define    FL_CMU_ADC_PSC_DIV4                                    (0x2U << CMU_OPCCR2_ADCPRSC_Pos)
#define    FL_CMU_ADC_PSC_DIV8                                    (0x3U << CMU_OPCCR2_ADCPRSC_Pos)
#define    FL_CMU_ADC_PSC_DIV16                                   (0x4U << CMU_OPCCR2_ADCPRSC_Pos)
#define    FL_CMU_ADC_PSC_DIV32                                   (0x5U << CMU_OPCCR2_ADCPRSC_Pos)


#define    FL_CMU_ADC_CLK_SOURCE_RCHF                             (0x1U << CMU_OPCCR2_ADCCKS_Pos)
#define    FL_CMU_ADC_CLK_SOURCE_XTHF                             (0x2U << CMU_OPCCR2_ADCCKS_Pos)
#define    FL_CMU_ADC_CLK_SOURCE_PLL                              (0x3U << CMU_OPCCR2_ADCCKS_Pos)


#define    FL_CMU_AHB_MASTER_PRIORITY_DMA                         (0x0U << CMU_AHBMCR_MPRIL_Pos)
#define    FL_CMU_AHB_MASTER_PRIORITY_CPU                         (0x1U << CMU_AHBMCR_MPRIL_Pos)


#define    FL_CMU_CANFD1_CLK_SOURCE_APBCLK                        (0x0U << CMU_CFDCR_CANFD1CKS_Pos)
#define    FL_CMU_CANFD1_CLK_SOURCE_XTHF                          (0x1U << CMU_CFDCR_CANFD1CKS_Pos)
#define    FL_CMU_CANFD1_CLK_SOURCE_PLL                           (0x2U << CMU_CFDCR_CANFD1CKS_Pos)
#define    FL_CMU_CANFD1_CLK_SOURCE_RCHF                          (0x3U << CMU_CFDCR_CANFD1CKS_Pos)


#define    FL_CMU_CANFD1_CLK_SOURCE_RAM_AHBCLK                    (0x0U << CMU_CFDCR_CANFD1CKRS_Pos)
#define    FL_CMU_CANFD1_CLK_SOURCE_RAM_PLL_VCO                   (0x1U << CMU_CFDCR_CANFD1CKRS_Pos)


#define    FL_CMU_CANFD0_CLK_SOURCE_APBCLK                        (0x0U << CMU_CFDCR_CANFD0CKS_Pos)
#define    FL_CMU_CANFD0_CLK_SOURCE_XTHF                          (0x1U << CMU_CFDCR_CANFD0CKS_Pos)
#define    FL_CMU_CANFD0_CLK_SOURCE_PLL                           (0x2U << CMU_CFDCR_CANFD0CKS_Pos)
#define    FL_CMU_CANFD0_CLK_SOURCE_RCHF                          (0x3U << CMU_CFDCR_CANFD0CKS_Pos)


#define    FL_CMU_CANFD0_CLK_SOURCE_RAM_AHBCLK                    (0x0U << CMU_CFDCR_CANFD0CKRS_Pos)
#define    FL_CMU_CANFD0_CLK_SOURCE_RAM_PLL_VCO                   (0x1U << CMU_CFDCR_CANFD0CKRS_Pos)


/**
  * @}
  */
/* Exported functions ---------------------------------------------------------------------------------*/
/** @defgroup CMU_FL_Exported_Functions CMU Exported Functions
  * @{
  */

/**
  * @brief    Enable LSCLK Auto Switch
  * @rmtoll   SYSCLKCR    LSCATS    FL_CMU_EnableLSCLKAutoSwitch
  * @retval   None
  */
__STATIC_INLINE void FL_CMU_EnableLSCLKAutoSwitch(void)
{
    SET_BIT(CMU->SYSCLKCR, CMU_SYSCLKCR_LSCATS_Msk);
}

/**
  * @brief    Get LSCLK Auto Switch Enable Status
  * @rmtoll   SYSCLKCR    LSCATS    FL_CMU_IsEnabledLSCLKAutoSwitch
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_CMU_IsEnabledLSCLKAutoSwitch(void)
{
    return (uint32_t)(READ_BIT(CMU->SYSCLKCR, CMU_SYSCLKCR_LSCATS_Msk) == CMU_SYSCLKCR_LSCATS_Msk);
}

/**
  * @brief    Disable LSCLK Auto Switch
  * @rmtoll   SYSCLKCR    LSCATS    FL_CMU_DisableLSCLKAutoSwitch
  * @retval   None
  */
__STATIC_INLINE void FL_CMU_DisableLSCLKAutoSwitch(void)
{
    CLEAR_BIT(CMU->SYSCLKCR, CMU_SYSCLKCR_LSCATS_Msk);
}

/**
  * @brief    Enable Sleep/DeepSleep Mode External Interrupt
  * @rmtoll   SYSCLKCR    SLP_ENEXTI    FL_CMU_EnableEXTIOnSleep
  * @retval   None
  */
__STATIC_INLINE void FL_CMU_EnableEXTIOnSleep(void)
{
    SET_BIT(CMU->SYSCLKCR, CMU_SYSCLKCR_SLP_ENEXTI_Msk);
}

/**
  * @brief    Get Sleep/DeepSleep Mode External Interrupt Enable Status
  * @rmtoll   SYSCLKCR    SLP_ENEXTI    FL_CMU_IsEnabledEXTIOnSleep
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_CMU_IsEnabledEXTIOnSleep(void)
{
    return (uint32_t)(READ_BIT(CMU->SYSCLKCR, CMU_SYSCLKCR_SLP_ENEXTI_Msk) == CMU_SYSCLKCR_SLP_ENEXTI_Msk);
}

/**
  * @brief    Disable Sleep/DeepSleep Mode External Interrupt
  * @rmtoll   SYSCLKCR    SLP_ENEXTI    FL_CMU_DisableEXTIOnSleep
  * @retval   None
  */
__STATIC_INLINE void FL_CMU_DisableEXTIOnSleep(void)
{
    CLEAR_BIT(CMU->SYSCLKCR, CMU_SYSCLKCR_SLP_ENEXTI_Msk);
}

/**
  * @brief    Set APB2 Prescaler
  * @rmtoll   SYSCLKCR    APB2PRES    FL_CMU_SetAPB2Prescaler
  * @param    prescaler This parameter can be one of the following values:
  *           @arg @ref FL_CMU_APB2CLK_PSC_DIV1
  *           @arg @ref FL_CMU_APB2CLK_PSC_DIV2
  *           @arg @ref FL_CMU_APB2CLK_PSC_DIV4
  *           @arg @ref FL_CMU_APB2CLK_PSC_DIV8
  *           @arg @ref FL_CMU_APB2CLK_PSC_DIV16
  * @retval   None
  */
__STATIC_INLINE void FL_CMU_SetAPB2Prescaler(uint32_t prescaler)
{
    MODIFY_REG(CMU->SYSCLKCR, CMU_SYSCLKCR_APB2PRES_Msk, prescaler);
}

/**
  * @brief    Get APB2 Prescaler
  * @rmtoll   SYSCLKCR    APB2PRES    FL_CMU_GetAPB2Prescaler
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_CMU_APB2CLK_PSC_DIV1
  *           @arg @ref FL_CMU_APB2CLK_PSC_DIV2
  *           @arg @ref FL_CMU_APB2CLK_PSC_DIV4
  *           @arg @ref FL_CMU_APB2CLK_PSC_DIV8
  *           @arg @ref FL_CMU_APB2CLK_PSC_DIV16
  */
__STATIC_INLINE uint32_t FL_CMU_GetAPB2Prescaler(void)
{
    return (uint32_t)(READ_BIT(CMU->SYSCLKCR, CMU_SYSCLKCR_APB2PRES_Msk));
}

/**
  * @brief    Set APB1 Prescaler
  * @rmtoll   SYSCLKCR    APB1PRES    FL_CMU_SetAPB1Prescaler
  * @param    prescaler This parameter can be one of the following values:
  *           @arg @ref FL_CMU_APB1CLK_PSC_DIV1
  *           @arg @ref FL_CMU_APB1CLK_PSC_DIV2
  *           @arg @ref FL_CMU_APB1CLK_PSC_DIV4
  *           @arg @ref FL_CMU_APB1CLK_PSC_DIV8
  *           @arg @ref FL_CMU_APB1CLK_PSC_DIV16
  * @retval   None
  */
__STATIC_INLINE void FL_CMU_SetAPB1Prescaler(uint32_t prescaler)
{
    MODIFY_REG(CMU->SYSCLKCR, CMU_SYSCLKCR_APB1PRES_Msk, prescaler);
}

/**
  * @brief    Get APB1 Prescaler
  * @rmtoll   SYSCLKCR    APB1PRES    FL_CMU_GetAPB1Prescaler
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_CMU_APB1CLK_PSC_DIV1
  *           @arg @ref FL_CMU_APB1CLK_PSC_DIV2
  *           @arg @ref FL_CMU_APB1CLK_PSC_DIV4
  *           @arg @ref FL_CMU_APB1CLK_PSC_DIV8
  *           @arg @ref FL_CMU_APB1CLK_PSC_DIV16
  */
__STATIC_INLINE uint32_t FL_CMU_GetAPB1Prescaler(void)
{
    return (uint32_t)(READ_BIT(CMU->SYSCLKCR, CMU_SYSCLKCR_APB1PRES_Msk));
}

/**
  * @brief    Set AHB Prescaler
  * @rmtoll   SYSCLKCR    AHBPRES    FL_CMU_SetAHBPrescaler
  * @param    prescaler This parameter can be one of the following values:
  *           @arg @ref FL_CMU_AHBCLK_PSC_DIV1
  *           @arg @ref FL_CMU_AHBCLK_PSC_DIV2
  *           @arg @ref FL_CMU_AHBCLK_PSC_DIV4
  *           @arg @ref FL_CMU_AHBCLK_PSC_DIV8
  *           @arg @ref FL_CMU_AHBCLK_PSC_DIV16
  * @retval   None
  */
__STATIC_INLINE void FL_CMU_SetAHBPrescaler(uint32_t prescaler)
{
    MODIFY_REG(CMU->SYSCLKCR, CMU_SYSCLKCR_AHBPRES_Msk, prescaler);
}

/**
  * @brief    Get AHB Prescaler
  * @rmtoll   SYSCLKCR    AHBPRES    FL_CMU_GetAHBPrescaler
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_CMU_AHBCLK_PSC_DIV1
  *           @arg @ref FL_CMU_AHBCLK_PSC_DIV2
  *           @arg @ref FL_CMU_AHBCLK_PSC_DIV4
  *           @arg @ref FL_CMU_AHBCLK_PSC_DIV8
  *           @arg @ref FL_CMU_AHBCLK_PSC_DIV16
  */
__STATIC_INLINE uint32_t FL_CMU_GetAHBPrescaler(void)
{
    return (uint32_t)(READ_BIT(CMU->SYSCLKCR, CMU_SYSCLKCR_AHBPRES_Msk));
}

/**
  * @brief    Set SysTick Clock Source
  * @rmtoll   SYSCLKCR    STCLKSEL    FL_CMU_SetSysTickClockSource
  * @param    clock This parameter can be one of the following values:
  *           @arg @ref FL_CMU_SYSTICK_CLK_SOURCE_SCLK
  *           @arg @ref FL_CMU_SYSTICK_CLK_SOURCE_LSCLK
  * @retval   None
  */
__STATIC_INLINE void FL_CMU_SetSysTickClockSource(uint32_t clock)
{
    MODIFY_REG(CMU->SYSCLKCR, CMU_SYSCLKCR_STCLKSEL_Msk, clock);
}

/**
  * @brief    Get SysTick Clock Source
  * @rmtoll   SYSCLKCR    STCLKSEL    FL_CMU_GetSysTickClockSource
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_CMU_SYSTICK_CLK_SOURCE_SCLK
  *           @arg @ref FL_CMU_SYSTICK_CLK_SOURCE_LSCLK
  */
__STATIC_INLINE uint32_t FL_CMU_GetSysTickClockSource(void)
{
    return (uint32_t)(READ_BIT(CMU->SYSCLKCR, CMU_SYSCLKCR_STCLKSEL_Msk));
}

/**
  * @brief    Set System Clock Source
  * @rmtoll   SYSCLKCR    SYSCLKSEL    FL_CMU_SetSystemClockSource
  * @param    clock This parameter can be one of the following values:
  *           @arg @ref FL_CMU_SYSTEM_CLK_SOURCE_RCHF
  *           @arg @ref FL_CMU_SYSTEM_CLK_SOURCE_XTHF
  *           @arg @ref FL_CMU_SYSTEM_CLK_SOURCE_PLL
  *           @arg @ref FL_CMU_SYSTEM_CLK_SOURCE_RCLP
  * @retval   None
  */
__STATIC_INLINE void FL_CMU_SetSystemClockSource(uint32_t clock)
{
    MODIFY_REG(CMU->SYSCLKCR, CMU_SYSCLKCR_SYSCLKSEL_Msk, clock);
}

/**
  * @brief    Set System Clock Source Setting
  * @rmtoll   SYSCLKCR    SYSCLKSEL    FL_CMU_GetSystemClockSource
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_CMU_SYSTEM_CLK_SOURCE_RCHF
  *           @arg @ref FL_CMU_SYSTEM_CLK_SOURCE_XTHF
  *           @arg @ref FL_CMU_SYSTEM_CLK_SOURCE_PLL
  *           @arg @ref FL_CMU_SYSTEM_CLK_SOURCE_RCLP
  */
__STATIC_INLINE uint32_t FL_CMU_GetSystemClockSource(void)
{
    return (uint32_t)(READ_BIT(CMU->SYSCLKCR, CMU_SYSCLKCR_SYSCLKSEL_Msk));
}

/**
  * @brief    Set RCHF Frequency
  * @rmtoll   RCHFCR    FSEL    FL_CMU_RCHF_SetFrequency
  * @param    frequency This parameter can be one of the following values:
  *           @arg @ref FL_CMU_RCHF_FREQUENCY_8MHZ
  *           @arg @ref FL_CMU_RCHF_FREQUENCY_16MHZ
  *           @arg @ref FL_CMU_RCHF_FREQUENCY_24MHZ
  *           @arg @ref FL_CMU_RCHF_FREQUENCY_32MHZ
  * @retval   None
  */
__STATIC_INLINE void FL_CMU_RCHF_SetFrequency(uint32_t frequency)
{
    MODIFY_REG(CMU->RCHFCR, CMU_RCHFCR_FSEL_Msk, frequency);
}

/**
  * @brief    Get RCHF Frequency Setting
  * @rmtoll   RCHFCR    FSEL    FL_CMU_RCHF_GetFrequency
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_CMU_RCHF_FREQUENCY_8MHZ
  *           @arg @ref FL_CMU_RCHF_FREQUENCY_16MHZ
  *           @arg @ref FL_CMU_RCHF_FREQUENCY_24MHZ
  *           @arg @ref FL_CMU_RCHF_FREQUENCY_32MHZ
  */
__STATIC_INLINE uint32_t FL_CMU_RCHF_GetFrequency(void)
{
    return (uint32_t)(READ_BIT(CMU->RCHFCR, CMU_RCHFCR_FSEL_Msk));
}

/**
  * @brief    Enable RCHF
  * @rmtoll   RCHFCR    EN    FL_CMU_RCHF_Enable
  * @retval   None
  */
__STATIC_INLINE void FL_CMU_RCHF_Enable(void)
{
    SET_BIT(CMU->RCHFCR, CMU_RCHFCR_EN_Msk);
}

/**
  * @brief    Get RCHF Enable Status
  * @rmtoll   RCHFCR    EN    FL_CMU_RCHF_IsEnabled
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_CMU_RCHF_IsEnabled(void)
{
    return (uint32_t)(READ_BIT(CMU->RCHFCR, CMU_RCHFCR_EN_Msk) == CMU_RCHFCR_EN_Msk);
}

/**
  * @brief    Disable RCHF
  * @rmtoll   RCHFCR    EN    FL_CMU_RCHF_Disable
  * @retval   None
  */
__STATIC_INLINE void FL_CMU_RCHF_Disable(void)
{
    CLEAR_BIT(CMU->RCHFCR, CMU_RCHFCR_EN_Msk);
}

/**
  * @brief    Set RCHF Freqency Trim Value
  * @rmtoll   RCHFTR    TRIM    FL_CMU_RCHF_WriteTrimValue
  * @param    value TrimValue The value of RCHF trim
  * @retval   None
  */
__STATIC_INLINE void FL_CMU_RCHF_WriteTrimValue(uint32_t value)
{
    MODIFY_REG(CMU->RCHFTR, (0xffU << 0U), (value << 0U));
}

/**
  * @brief    Get RCHF Freqency Trim Value
  * @rmtoll   RCHFTR    TRIM    FL_CMU_RCHF_ReadTrimValue
  * @retval   The value of RCHF trim
  */
__STATIC_INLINE uint32_t FL_CMU_RCHF_ReadTrimValue(void)
{
    return (uint32_t)(READ_BIT(CMU->RCHFTR, (0xffU << 0U)) >> 0U);
}

/**
  * @brief    Set PLL Multiplier
  * @rmtoll   PLLCR    DB    FL_CMU_PLL_WriteMultiplier
  * @param    multiplier 
  * @retval   None
  */
__STATIC_INLINE void FL_CMU_PLL_WriteMultiplier(uint32_t multiplier)
{
    MODIFY_REG(CMU->PLLCR, (0x3ffU << 16U), (multiplier << 16U));
}

/**
  * @brief    Get PLL Multiplier Setting 
  * @rmtoll   PLLCR    DB    FL_CMU_PLL_ReadMultiplier
  * @retval   
  */
__STATIC_INLINE uint32_t FL_CMU_PLL_ReadMultiplier(void)
{
    return (uint32_t)(READ_BIT(CMU->PLLCR, (0x3ffU << 16U)) >> 16U);
}

/**
  * @brief    Get PLL Ready Status
  * @rmtoll   PLLCR    LOCKED    FL_CMU_IsActiveFlag_PLLReady
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_CMU_IsActiveFlag_PLLReady(void)
{
    return (uint32_t)(READ_BIT(CMU->PLLCR, CMU_PLLCR_LOCKED_Msk) == (CMU_PLLCR_LOCKED_Msk));
}

/**
  * @brief    Set PLL Prescaler
  * @rmtoll   PLLCR    REFPRSC    FL_CMU_PLL_SetPrescaler
  * @param    prescaler This parameter can be one of the following values:
  *           @arg @ref FL_CMU_PLL_PSC_DIV1
  *           @arg @ref FL_CMU_PLL_PSC_DIV2
  *           @arg @ref FL_CMU_PLL_PSC_DIV4
  *           @arg @ref FL_CMU_PLL_PSC_DIV8
  *           @arg @ref FL_CMU_PLL_PSC_DIV12
  *           @arg @ref FL_CMU_PLL_PSC_DIV16
  *           @arg @ref FL_CMU_PLL_PSC_DIV24
  *           @arg @ref FL_CMU_PLL_PSC_DIV32
  * @retval   None
  */
__STATIC_INLINE void FL_CMU_PLL_SetPrescaler(uint32_t prescaler)
{
    MODIFY_REG(CMU->PLLCR, CMU_PLLCR_REFPRSC_Msk, prescaler);
}

/**
  * @brief    Get PLL Prescaler Setting
  * @rmtoll   PLLCR    REFPRSC    FL_CMU_PLL_GetPrescaler
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_CMU_PLL_PSC_DIV1
  *           @arg @ref FL_CMU_PLL_PSC_DIV2
  *           @arg @ref FL_CMU_PLL_PSC_DIV4
  *           @arg @ref FL_CMU_PLL_PSC_DIV8
  *           @arg @ref FL_CMU_PLL_PSC_DIV12
  *           @arg @ref FL_CMU_PLL_PSC_DIV16
  *           @arg @ref FL_CMU_PLL_PSC_DIV24
  *           @arg @ref FL_CMU_PLL_PSC_DIV32
  */
__STATIC_INLINE uint32_t FL_CMU_PLL_GetPrescaler(void)
{
    return (uint32_t)(READ_BIT(CMU->PLLCR, CMU_PLLCR_REFPRSC_Msk));
}

/**
  * @brief    Set PLL Input Source
  * @rmtoll   PLLCR    INSEL    FL_CMU_PLL_SetClockSource
  * @param    clock This parameter can be one of the following values:
  *           @arg @ref FL_CMU_PLL_CLK_SOURCE_RCHF
  *           @arg @ref FL_CMU_PLL_CLK_SOURCE_XTHF
  * @retval   None
  */
__STATIC_INLINE void FL_CMU_PLL_SetClockSource(uint32_t clock)
{
    MODIFY_REG(CMU->PLLCR, CMU_PLLCR_INSEL_Msk, clock);
}

/**
  * @brief    Get PLL Input Source Setting
  * @rmtoll   PLLCR    INSEL    FL_CMU_PLL_GetClockSource
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_CMU_PLL_CLK_SOURCE_RCHF
  *           @arg @ref FL_CMU_PLL_CLK_SOURCE_XTHF
  */
__STATIC_INLINE uint32_t FL_CMU_PLL_GetClockSource(void)
{
    return (uint32_t)(READ_BIT(CMU->PLLCR, CMU_PLLCR_INSEL_Msk));
}

/**
  * @brief    Enable PLL
  * @rmtoll   PLLCR    EN    FL_CMU_PLL_Enable
  * @retval   None
  */
__STATIC_INLINE void FL_CMU_PLL_Enable(void)
{
    SET_BIT(CMU->PLLCR, CMU_PLLCR_EN_Msk);
}

/**
  * @brief    Disable PLL
  * @rmtoll   PLLCR    EN    FL_CMU_PLL_Disable
  * @retval   None
  */
__STATIC_INLINE void FL_CMU_PLL_Disable(void)
{
    CLEAR_BIT(CMU->PLLCR, CMU_PLLCR_EN_Msk);
}

/**
  * @brief    Get PLL Enable Status
  * @rmtoll   PLLCR    EN    FL_CMU_PLL_IsEnabled
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_CMU_PLL_IsEnabled(void)
{
    return (uint32_t)(READ_BIT(CMU->PLLCR, CMU_PLLCR_EN_Msk) == CMU_PLLCR_EN_Msk);
}

/**
  * @brief    Set RCLP Frequency Trim Value
  * @rmtoll   RCLPTR    TRIM    FL_CMU_RCLP_WriteTrimValue
  * @param    value TrimValue The value of RCLP trim
  * @retval   None
  */
__STATIC_INLINE void FL_CMU_RCLP_WriteTrimValue(uint32_t value)
{
    MODIFY_REG(CMU->RCLPTR, (0xffU << 0U), (value << 0U));
}

/**
  * @brief    Get RCLP Frequency Trim Value
  * @rmtoll   RCLPTR    TRIM    FL_CMU_RCLP_ReadTrimValue
  * @retval   The Value of RCLP trim
  */
__STATIC_INLINE uint32_t FL_CMU_RCLP_ReadTrimValue(void)
{
    return (uint32_t)(READ_BIT(CMU->RCLPTR, (0xffU << 0U)) >> 0U);
}

/**
  * @brief    Enable Bypass
  * @rmtoll   XTLFCR    BYPASS    FL_CMU_XTLF_EnableBypass
  * @retval   None
  */
__STATIC_INLINE void FL_CMU_XTLF_EnableBypass(void)
{
    SET_BIT(CMU->XTLFCR, CMU_XTLFCR_BYPASS_Msk);
}

/**
  * @brief    Get Bypass Enable Status
  * @rmtoll   XTLFCR    BYPASS    FL_CMU_XTLF_IsEnabledBypass
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_CMU_XTLF_IsEnabledBypass(void)
{
    return (uint32_t)(READ_BIT(CMU->XTLFCR, CMU_XTLFCR_BYPASS_Msk) == CMU_XTLFCR_BYPASS_Msk);
}

/**
  * @brief    Disable Bypass
  * @rmtoll   XTLFCR    BYPASS    FL_CMU_XTLF_DisableBypass
  * @retval   None
  */
__STATIC_INLINE void FL_CMU_XTLF_DisableBypass(void)
{
    CLEAR_BIT(CMU->XTLFCR, CMU_XTLFCR_BYPASS_Msk);
}

/**
  * @brief    Set XTLF Start Wait Time
  * @rmtoll   XTLFCR    WAIT    FL_CMU_XTLF_SetStartWaitTime
  * @param    clock This parameter can be one of the following values:
  *           @arg @ref FL_CMU_XTLF_START_WAIT_CYCLE_128
  *           @arg @ref FL_CMU_XTLF_START_WAIT_CYCLE_256
  *           @arg @ref FL_CMU_XTLF_START_WAIT_CYCLE_512
  *           @arg @ref FL_CMU_XTLF_START_WAIT_CYCLE_1024
  *           @arg @ref FL_CMU_XTLF_START_WAIT_CYCLE_2048
  *           @arg @ref FL_CMU_XTLF_START_WAIT_CYCLE_4096
  *           @arg @ref FL_CMU_XTLF_START_WAIT_CYCLE_8192
  *           @arg @ref FL_CMU_XTLF_START_WAIT_CYCLE_16384
  * @retval   None
  */
__STATIC_INLINE void FL_CMU_XTLF_SetStartWaitTime(uint32_t clock)
{
    MODIFY_REG(CMU->XTLFCR, CMU_XTLFCR_WAIT_Msk, clock);
}

/**
  * @brief    Get XTLF Start Wait Time
  * @rmtoll   XTLFCR    WAIT    FL_CMU_XTLF_GetStartWaitTime
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_CMU_XTLF_START_WAIT_CYCLE_128
  *           @arg @ref FL_CMU_XTLF_START_WAIT_CYCLE_256
  *           @arg @ref FL_CMU_XTLF_START_WAIT_CYCLE_512
  *           @arg @ref FL_CMU_XTLF_START_WAIT_CYCLE_1024
  *           @arg @ref FL_CMU_XTLF_START_WAIT_CYCLE_2048
  *           @arg @ref FL_CMU_XTLF_START_WAIT_CYCLE_4096
  *           @arg @ref FL_CMU_XTLF_START_WAIT_CYCLE_8192
  *           @arg @ref FL_CMU_XTLF_START_WAIT_CYCLE_16384
  */
__STATIC_INLINE uint32_t FL_CMU_XTLF_GetStartWaitTime(void)
{
    return (uint32_t)(READ_BIT(CMU->XTLFCR, CMU_XTLFCR_WAIT_Msk));
}

/**
  * @brief    Enable XT32KI
  * @rmtoll   XTLFCR    EXCKSEN    FL_CMU_Enable_XT32KI_Input
  * @retval   None
  */
__STATIC_INLINE void FL_CMU_Enable_XT32KI_Input(void)
{
    SET_BIT(CMU->XTLFCR, CMU_XTLFCR_EXCKSEN_Msk);
}

/**
  * @brief    Disable XT32KI
  * @rmtoll   XTLFCR    EXCKSEN    FL_CMU_Disable_XT32KI_Input
  * @retval   None
  */
__STATIC_INLINE void FL_CMU_Disable_XT32KI_Input(void)
{
    CLEAR_BIT(CMU->XTLFCR, CMU_XTLFCR_EXCKSEN_Msk);
}

/**
  * @brief    Get XT32KI Enable Status
  * @rmtoll   XTLFCR    EXCKSEN    FL_CMU_IsEnabled_XT32KI_Input
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_CMU_IsEnabled_XT32KI_Input(void)
{
    return (uint32_t)(READ_BIT(CMU->XTLFCR, CMU_XTLFCR_EXCKSEN_Msk) == CMU_XTLFCR_EXCKSEN_Msk);
}

/**
  * @brief    Enable XTLF
  * @rmtoll   XTLFCR    EN    FL_CMU_XTLF_Enable
  * @retval   None
  */
__STATIC_INLINE void FL_CMU_XTLF_Enable(void)
{
    MODIFY_REG(CMU->XTLFCR, CMU_XTLFCR_EN_Msk, FL_CMU_XTLF_FDET_ENABLE);
}

/**
  * @brief    Disable XTLF
  * @rmtoll   XTLFCR    EN    FL_CMU_XTLF_Disable
  * @retval   None
  */
__STATIC_INLINE void FL_CMU_XTLF_Disable(void)
{
    MODIFY_REG(CMU->XTLFCR, CMU_XTLFCR_EN_Msk, FL_CMU_XTLF_FDET_DISABLE);
}

/**
  * @brief    Get XTLF Enable Status
  * @rmtoll   XTLFCR    EN    FL_CMU_XTLF_IsEnabled
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_CMU_XTLF_IsEnabled(void)
{
    return (uint32_t)(READ_BIT(CMU->XTLFCR, CMU_XTLFCR_EN_Msk) == (0x1UL << CMU_XTLFCR_EN_Pos));
}

/**
  * @brief    Get XTLF Ready Status
  * @rmtoll   XTLFCR    RDY    FL_CMU_XTLF_IsReady
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_CMU_XTLF_IsReady(void)
{
    return (uint32_t)(READ_BIT(CMU->XTLFCR, CMU_XTLFCR_RDY_Msk) == CMU_XTLFCR_RDY_Msk);
}

/**
  * @brief    Set XTLF Gain
  * @rmtoll   XTLFCR    GMCFG    FL_CMU_XTLF_SetWorkGain
  * @param    gain This parameter can be one of the following values:
  *           @arg @ref FL_CMU_XTLF_WORK_GAIN0
  *           @arg @ref FL_CMU_XTLF_WORK_GAIN1
  *           @arg @ref FL_CMU_XTLF_WORK_GAIN2
  *           @arg @ref FL_CMU_XTLF_WORK_GAIN3
  *           @arg @ref FL_CMU_XTLF_WORK_GAIN4
  *           @arg @ref FL_CMU_XTLF_WORK_GAIN5
  *           @arg @ref FL_CMU_XTLF_WORK_GAIN6
  *           @arg @ref FL_CMU_XTLF_WORK_GAIN7
  * @retval   None
  */
__STATIC_INLINE void FL_CMU_XTLF_SetWorkGain(uint32_t gain)
{
    MODIFY_REG(CMU->XTLFCR, CMU_XTLFCR_GMCFG_Msk, gain);
}

/**
  * @brief    Get XTLF Gain Setting
  * @rmtoll   XTLFCR    GMCFG    FL_CMU_XTLF_GetWorkGain
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_CMU_XTLF_WORK_GAIN0
  *           @arg @ref FL_CMU_XTLF_WORK_GAIN1
  *           @arg @ref FL_CMU_XTLF_WORK_GAIN2
  *           @arg @ref FL_CMU_XTLF_WORK_GAIN3
  *           @arg @ref FL_CMU_XTLF_WORK_GAIN4
  *           @arg @ref FL_CMU_XTLF_WORK_GAIN5
  *           @arg @ref FL_CMU_XTLF_WORK_GAIN6
  *           @arg @ref FL_CMU_XTLF_WORK_GAIN7
  */
__STATIC_INLINE uint32_t FL_CMU_XTLF_GetWorkGain(void)
{
    return (uint32_t)(READ_BIT(CMU->XTLFCR, CMU_XTLFCR_GMCFG_Msk));
}

/**
  * @brief    Set XTLF Current
  * @rmtoll   XTLFCR    ICFG    FL_CMU_XTLF_SetWorkCurrent
  * @param    current This parameter can be one of the following values:
  *           @arg @ref FL_CMU_XTLF_WORK_CURRENT0
  *           @arg @ref FL_CMU_XTLF_WORK_CURRENT1
  *           @arg @ref FL_CMU_XTLF_WORK_CURRENT2
  *           @arg @ref FL_CMU_XTLF_WORK_CURRENT3
  * @retval   None
  */
__STATIC_INLINE void FL_CMU_XTLF_SetWorkCurrent(uint32_t current)
{
    MODIFY_REG(CMU->XTLFCR, CMU_XTLFCR_ICFG_Msk, current);
}

/**
  * @brief    Get XTLF Current Setting
  * @rmtoll   XTLFCR    ICFG    FL_CMU_XTLF_GetWorkCurrent
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_CMU_XTLF_WORK_CURRENT0
  *           @arg @ref FL_CMU_XTLF_WORK_CURRENT1
  *           @arg @ref FL_CMU_XTLF_WORK_CURRENT2
  *           @arg @ref FL_CMU_XTLF_WORK_CURRENT3
  */
__STATIC_INLINE uint32_t FL_CMU_XTLF_GetWorkCurrent(void)
{
    return (uint32_t)(READ_BIT(CMU->XTLFCR, CMU_XTLFCR_ICFG_Msk));
}

/**
  * @brief    Get LSCLK Source
  * @rmtoll   LSCLKSEL    LSSTA    FL_CMU_GetLSCLKClockSource
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_CMU_LSCLK_SOURCE_XTLF
  *           @arg @ref FL_CMU_LSCLK_SOURCE_RCLP
  */
__STATIC_INLINE uint32_t FL_CMU_GetLSCLKClockSource(void)
{
    return (uint32_t)(READ_BIT(CMU->LSCLKSEL, CMU_LSCLKSEL_LSSTA_Msk));
}

/**
  * @brief    Set LSCLK Clock Source
  * @rmtoll   LSCLKSEL    SEL    FL_CMU_SetLSCLKClockSource
  * @param    clock This parameter can be one of the following values:
  *           @arg @ref FL_CMU_SET_LSCLK_SOURCE_RCLP
  *           @arg @ref FL_CMU_SET_LSCLK_SOURCE_XTLF
  * @retval   None
  */
__STATIC_INLINE void FL_CMU_SetLSCLKClockSource(uint32_t clock)
{
    MODIFY_REG(CMU->LSCLKSEL, CMU_LSCLKSEL_SEL_Msk, clock);
}

/**
  * @brief    Set XTHF Start Wait Time
  * @rmtoll   XTHFCR    WAIT    FL_CMU_XTHF_SetStartWaitTime
  * @param    clock This parameter can be one of the following values:
  *           @arg @ref FL_CMU_XTHF_START_WAIT_CYCLE_128
  *           @arg @ref FL_CMU_XTHF_START_WAIT_CYCLE_256
  *           @arg @ref FL_CMU_XTHF_START_WAIT_CYCLE_512
  *           @arg @ref FL_CMU_XTHF_START_WAIT_CYCLE_1024
  *           @arg @ref FL_CMU_XTHF_START_WAIT_CYCLE_2048
  *           @arg @ref FL_CMU_XTHF_START_WAIT_CYCLE_4096
  *           @arg @ref FL_CMU_XTHF_START_WAIT_CYCLE_8192
  *           @arg @ref FL_CMU_XTHF_START_WAIT_CYCLE_16384
  * @retval   None
  */
__STATIC_INLINE void FL_CMU_XTHF_SetStartWaitTime(uint32_t clock)
{
    MODIFY_REG(CMU->XTHFCR, CMU_XTHFCR_WAIT_Msk, clock);
}

/**
  * @brief    Get XTHF Start Wait Time
  * @rmtoll   XTHFCR    WAIT    FL_CMU_XTHF_GetStartWaitTime
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_CMU_XTHF_START_WAIT_CYCLE_128
  *           @arg @ref FL_CMU_XTHF_START_WAIT_CYCLE_256
  *           @arg @ref FL_CMU_XTHF_START_WAIT_CYCLE_512
  *           @arg @ref FL_CMU_XTHF_START_WAIT_CYCLE_1024
  *           @arg @ref FL_CMU_XTHF_START_WAIT_CYCLE_2048
  *           @arg @ref FL_CMU_XTHF_START_WAIT_CYCLE_4096
  *           @arg @ref FL_CMU_XTHF_START_WAIT_CYCLE_8192
  *           @arg @ref FL_CMU_XTHF_START_WAIT_CYCLE_16384
  */
__STATIC_INLINE uint32_t FL_CMU_XTHF_GetStartWaitTime(void)
{
    return (uint32_t)(READ_BIT(CMU->XTHFCR, CMU_XTHFCR_WAIT_Msk));
}

/**
  * @brief    Enable Bypass
  * @rmtoll   XTHFCR    BYP    FL_CMU_XTHF_EnableBypass
  * @retval   None
  */
__STATIC_INLINE void FL_CMU_XTHF_EnableBypass(void)
{
    SET_BIT(CMU->XTHFCR, CMU_XTHFCR_BYP_Msk);
}

/**
  * @brief    Get Bypass Enable Status
  * @rmtoll   XTHFCR    BYP    FL_CMU_XTHF_IsEnabledBypass
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_CMU_XTHF_IsEnabledBypass(void)
{
    return (uint32_t)(READ_BIT(CMU->XTHFCR, CMU_XTHFCR_BYP_Msk) == CMU_XTHFCR_BYP_Msk);
}

/**
  * @brief    Disable Bypass
  * @rmtoll   XTHFCR    BYP    FL_CMU_XTHF_DisableBypass
  * @retval   None
  */
__STATIC_INLINE void FL_CMU_XTHF_DisableBypass(void)
{
    CLEAR_BIT(CMU->XTHFCR, CMU_XTHFCR_BYP_Msk);
}

/**
  * @brief    Set XTHF Oscillation Strength
  * @rmtoll   XTHFCR    CFG    FL_CMU_XTHF_WriteDriverStrength
  * @param    strength 
  * @retval   None
  */
__STATIC_INLINE void FL_CMU_XTHF_WriteDriverStrength(uint32_t strength)
{
    MODIFY_REG(CMU->XTHFCR, (0xfU << 8U), (strength << 8U));
}

/**
  * @brief    Get XTHF Oscillation Strength Setting
  * @rmtoll   XTHFCR    CFG    FL_CMU_XTHF_ReadDriverStrength
  * @retval   
  */
__STATIC_INLINE uint32_t FL_CMU_XTHF_ReadDriverStrength(void)
{
    return (uint32_t)(READ_BIT(CMU->XTHFCR, (0xfU << 8U)) >> 8U);
}

/**
  * @brief    Get XTHF Ready Status
  * @rmtoll   XTHFCR    RDY    FL_CMU_XTHF_IsReady
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_CMU_XTHF_IsReady(void)
{
    return (uint32_t)(READ_BIT(CMU->XTHFCR, CMU_XTHFCR_RDY_Msk) == CMU_XTHFCR_RDY_Msk);
}

/**
  * @brief    Enable XTHF
  * @rmtoll   XTHFCR    EN    FL_CMU_XTHF_Enable
  * @retval   None
  */
__STATIC_INLINE void FL_CMU_XTHF_Enable(void)
{
    SET_BIT(CMU->XTHFCR, CMU_XTHFCR_EN_Msk);
}

/**
  * @brief    Get XTHF Enable Status
  * @rmtoll   XTHFCR    EN    FL_CMU_XTHF_IsEnabled
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_CMU_XTHF_IsEnabled(void)
{
    return (uint32_t)(READ_BIT(CMU->XTHFCR, CMU_XTHFCR_EN_Msk) == CMU_XTHFCR_EN_Msk);
}

/**
  * @brief    Disable XTHF
  * @rmtoll   XTHFCR    EN    FL_CMU_XTHF_Disable
  * @retval   None
  */
__STATIC_INLINE void FL_CMU_XTHF_Disable(void)
{
    CLEAR_BIT(CMU->XTHFCR, CMU_XTHFCR_EN_Msk);
}

/**
  * @brief    Enable SYSCKE Wrong Interrupt
  * @rmtoll   IER    SYSCKE_IE    FL_CMU_EnableIT_SYSCKEWrong
  * @retval   None
  */
__STATIC_INLINE void FL_CMU_EnableIT_SYSCKEWrong(void)
{
    SET_BIT(CMU->IER, CMU_IER_SYSCKE_IE_Msk);
}

/**
  * @brief    Get SYSCKE Wrong Interrupt Enable Status
  * @rmtoll   IER    SYSCKE_IE    FL_CMU_IsEnabledIT_SYSCKEWrong
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_CMU_IsEnabledIT_SYSCKEWrong(void)
{
    return (uint32_t)(READ_BIT(CMU->IER, CMU_IER_SYSCKE_IE_Msk) == CMU_IER_SYSCKE_IE_Msk);
}

/**
  * @brief    Disable SYSCKE Wrong Interrupt
  * @rmtoll   IER    SYSCKE_IE    FL_CMU_DisableIT_SYSCKEWrong
  * @retval   None
  */
__STATIC_INLINE void FL_CMU_DisableIT_SYSCKEWrong(void)
{
    CLEAR_BIT(CMU->IER, CMU_IER_SYSCKE_IE_Msk);
}

/**
  * @brief    Enable XTHF Fail Interrupt
  * @rmtoll   IER    HFDET_IE    FL_CMU_EnableIT_XTHFFail
  * @retval   None
  */
__STATIC_INLINE void FL_CMU_EnableIT_XTHFFail(void)
{
    SET_BIT(CMU->IER, CMU_IER_HFDET_IE_Msk);
}

/**
  * @brief    Get XTHF Fail Interrupt Enable Status
  * @rmtoll   IER    HFDET_IE    FL_CMU_IsEnabledIT_XTHFFail
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_CMU_IsEnabledIT_XTHFFail(void)
{
    return (uint32_t)(READ_BIT(CMU->IER, CMU_IER_HFDET_IE_Msk) == CMU_IER_HFDET_IE_Msk);
}

/**
  * @brief    Disable XTHF Fail Interrupt
  * @rmtoll   IER    HFDET_IE    FL_CMU_DisableIT_XTHFFail
  * @retval   None
  */
__STATIC_INLINE void FL_CMU_DisableIT_XTHFFail(void)
{
    CLEAR_BIT(CMU->IER, CMU_IER_HFDET_IE_Msk);
}

/**
  * @brief    Enable XTLF Fail Interrupt
  * @rmtoll   IER    LFDET_IE    FL_CMU_EnableIT_XTLFFail
  * @retval   None
  */
__STATIC_INLINE void FL_CMU_EnableIT_XTLFFail(void)
{
    SET_BIT(CMU->IER, CMU_IER_LFDET_IE_Msk);
}

/**
  * @brief    Get XTLF Fail Interrupt Enable Status
  * @rmtoll   IER    LFDET_IE    FL_CMU_IsEnabledIT_XTLFFail
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_CMU_IsEnabledIT_XTLFFail(void)
{
    return (uint32_t)(READ_BIT(CMU->IER, CMU_IER_LFDET_IE_Msk) == CMU_IER_LFDET_IE_Msk);
}

/**
  * @brief    Disable XTLF Fail Interrupt
  * @rmtoll   IER    LFDET_IE    FL_CMU_DisableIT_XTLFFail
  * @retval   None
  */
__STATIC_INLINE void FL_CMU_DisableIT_XTLFFail(void)
{
    CLEAR_BIT(CMU->IER, CMU_IER_LFDET_IE_Msk);
}

/**
  * @brief    Get XTHF Vibrating Output
  * @rmtoll   ISR    HFDETO    FL_CMU_IsActiveFlag_XTHFFailOutput
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_CMU_IsActiveFlag_XTHFFailOutput(void)
{
    return (uint32_t)(READ_BIT(CMU->ISR, CMU_ISR_HFDETO_Msk) == (CMU_ISR_HFDETO_Msk));
}

/**
  * @brief    Get XTLF Vibrating Output
  * @rmtoll   ISR    LFDETO    FL_CMU_IsActiveFlag_XTLFFailOutput
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_CMU_IsActiveFlag_XTLFFailOutput(void)
{
    return (uint32_t)(READ_BIT(CMU->ISR, CMU_ISR_LFDETO_Msk) == (CMU_ISR_LFDETO_Msk));
}

/**
  * @brief    Get PLL Lost Lock Flag
  * @rmtoll   ISR    LOLIF    FL_CMU_IsActiveFlag_PLLLostLock
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_CMU_IsActiveFlag_PLLLostLock(void)
{
    return (uint32_t)(READ_BIT(CMU->ISR, CMU_ISR_LOLIF_Msk) == (CMU_ISR_LOLIF_Msk));
}

/**
  * @brief    Clear PLL Lost Lock Flag
  * @rmtoll   ISR    LOLIF    FL_CMU_ClearFlag_PLLLostLock
  * @retval   None
  */
__STATIC_INLINE void FL_CMU_ClearFlag_PLLLostLock(void)
{
    WRITE_REG(CMU->ISR, CMU_ISR_LOLIF_Msk);
}

/**
  * @brief    Get SYSCKE Wrong Flag
  * @rmtoll   ISR    SYSCSE_IF    FL_CMU_IsActiveFlag_SYSCSEWrong
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_CMU_IsActiveFlag_SYSCSEWrong(void)
{
    return (uint32_t)(READ_BIT(CMU->ISR, CMU_ISR_SYSCSE_IF_Msk) == (CMU_ISR_SYSCSE_IF_Msk));
}

/**
  * @brief    Clear SYSCKE Wrong Flag
  * @rmtoll   ISR    SYSCSE_IF    FL_CMU_ClearFlag_SYSCSEWrong
  * @retval   None
  */
__STATIC_INLINE void FL_CMU_ClearFlag_SYSCSEWrong(void)
{
    WRITE_REG(CMU->ISR, CMU_ISR_SYSCSE_IF_Msk);
}

/**
  * @brief    Get XTHF Vibrating Flag
  * @rmtoll   ISR    HFDET_IF    FL_CMU_IsActiveFlag_XTHFFail
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_CMU_IsActiveFlag_XTHFFail(void)
{
    return (uint32_t)(READ_BIT(CMU->ISR, CMU_ISR_HFDET_IF_Msk) == (CMU_ISR_HFDET_IF_Msk));
}

/**
  * @brief    Clear XTHF Vibrating Flag
  * @rmtoll   ISR    HFDET_IF    FL_CMU_ClearFlag_XTHFFail
  * @retval   None
  */
__STATIC_INLINE void FL_CMU_ClearFlag_XTHFFail(void)
{
    WRITE_REG(CMU->ISR, CMU_ISR_HFDET_IF_Msk);
}

/**
  * @brief    Get XTLF Vibrating Flag
  * @rmtoll   ISR    LFDET_IF    FL_CMU_IsActiveFlag_XTLFFail
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_CMU_IsActiveFlag_XTLFFail(void)
{
    return (uint32_t)(READ_BIT(CMU->ISR, CMU_ISR_LFDET_IF_Msk) == (CMU_ISR_LFDET_IF_Msk));
}

/**
  * @brief    Clear XTLF Vibrating Flag
  * @rmtoll   ISR    LFDET_IF    FL_CMU_ClearFlag_XTLFFail
  * @retval   None
  */
__STATIC_INLINE void FL_CMU_ClearFlag_XTLFFail(void)
{
    WRITE_REG(CMU->ISR, CMU_ISR_LFDET_IF_Msk);
}

/**
  * @brief    Enable Group1 Periph Bus Clock
  * @rmtoll   PCLKCR1        FL_CMU_EnableGroup1BusClock
  * @param    peripheral This parameter can be one of the following values:
  *           @arg @ref FL_CMU_GROUP1_BUSCLK_LPTIM32
  *           @arg @ref FL_CMU_GROUP1_BUSCLK_LPTIM16
  *           @arg @ref FL_CMU_GROUP1_BUSCLK_RTC
  *           @arg @ref FL_CMU_GROUP1_BUSCLK_PMU
  *           @arg @ref FL_CMU_GROUP1_BUSCLK_SCU
  *           @arg @ref FL_CMU_GROUP1_BUSCLK_IWDT
  *           @arg @ref FL_CMU_GROUP1_BUSCLK_ANAC
  *           @arg @ref FL_CMU_GROUP1_BUSCLK_PAD
  *           @arg @ref FL_CMU_GROUP1_BUSCLK_SVD
  *           @arg @ref FL_CMU_GROUP1_BUSCLK_COMP
  *           @arg @ref FL_CMU_GROUP1_BUSCLK_CLM0
  *           @arg @ref FL_CMU_GROUP1_BUSCLK_CLM1
  * @retval   None
  */
__STATIC_INLINE void FL_CMU_EnableGroup1BusClock(uint32_t peripheral)
{
    SET_BIT(CMU->PCLKCR1, ((peripheral & 0xffffffff) << 0x0U));
}

/**
  * @brief    Enable Group2 Periph Bus Clock
  * @rmtoll   PCLKCR2        FL_CMU_EnableGroup2BusClock
  * @param    peripheral This parameter can be one of the following values:
  *           @arg @ref FL_CMU_GROUP2_BUSCLK_CRC
  *           @arg @ref FL_CMU_GROUP2_BUSCLK_RNG
  *           @arg @ref FL_CMU_GROUP2_BUSCLK_AES
  *           @arg @ref FL_CMU_GROUP2_BUSCLK_DMA
  *           @arg @ref FL_CMU_GROUP2_BUSCLK_FLASH
  *           @arg @ref FL_CMU_GROUP2_BUSCLK_RAMBIST
  *           @arg @ref FL_CMU_GROUP2_BUSCLK_WWDT
  *           @arg @ref FL_CMU_GROUP2_BUSCLK_ADC
  *           @arg @ref FL_CMU_GROUP2_BUSCLK_HDIV
  *           @arg @ref FL_CMU_GROUP2_BUSCLK_DAC
  *           @arg @ref FL_CMU_GROUP2_BUSCLK_PGL
  * @retval   None
  */
__STATIC_INLINE void FL_CMU_EnableGroup2BusClock(uint32_t peripheral)
{
    SET_BIT(CMU->PCLKCR2, ((peripheral & 0xffffffff) << 0x0U));
}

/**
  * @brief    Enable Group3 Periph Bus Clock
  * @rmtoll   PCLKCR3        FL_CMU_EnableGroup3BusClock
  * @param    peripheral This parameter can be one of the following values:
  *           @arg @ref FL_CMU_GROUP3_BUSCLK_SPI0
  *           @arg @ref FL_CMU_GROUP3_BUSCLK_SPI1
  *           @arg @ref FL_CMU_GROUP3_BUSCLK_SPI2
  *           @arg @ref FL_CMU_GROUP3_BUSCLK_SPI3
  *           @arg @ref FL_CMU_GROUP3_BUSCLK_UART0
  *           @arg @ref FL_CMU_GROUP3_BUSCLK_UART1
  *           @arg @ref FL_CMU_GROUP3_BUSCLK_UART2
  *           @arg @ref FL_CMU_GROUP3_BUSCLK_UART3
  *           @arg @ref FL_CMU_GROUP3_BUSCLK_UART4
  *           @arg @ref FL_CMU_GROUP3_BUSCLK_UART5
  *           @arg @ref FL_CMU_GROUP3_BUSCLK_UARTIR
  *           @arg @ref FL_CMU_GROUP3_BUSCLK_LPUART0
  *           @arg @ref FL_CMU_GROUP3_BUSCLK_LPUART1
  *           @arg @ref FL_CMU_GROUP3_BUSCLK_LPUART2
  *           @arg @ref FL_CMU_GROUP3_BUSCLK_FSCAN
  *           @arg @ref FL_CMU_GROUP3_BUSCLK_CANFD0
  *           @arg @ref FL_CMU_GROUP3_BUSCLK_CANFD1
  *           @arg @ref FL_CMU_GROUP3_BUSCLK_I2C0
  *           @arg @ref FL_CMU_GROUP3_BUSCLK_I2C1
  *           @arg @ref FL_CMU_GROUP3_BUSCLK_I2CSMB0
  *           @arg @ref FL_CMU_GROUP3_BUSCLK_I2CSMB1
  *           @arg @ref FL_CMU_GROUP3_BUSCLK_SENT0
  *           @arg @ref FL_CMU_GROUP3_BUSCLK_SENT1
  * @retval   None
  */
__STATIC_INLINE void FL_CMU_EnableGroup3BusClock(uint32_t peripheral)
{
    SET_BIT(CMU->PCLKCR3, ((peripheral & 0xffffffff) << 0x0U));
}

/**
  * @brief    Enable Group4 Periph Bus Clock
  * @rmtoll   PCLKCR4        FL_CMU_EnableGroup4BusClock
  * @param    peripheral This parameter can be one of the following values:
  *           @arg @ref FL_CMU_GROUP4_BUSCLK_BSTIM32
  *           @arg @ref FL_CMU_GROUP4_BUSCLK_GPTIM0
  *           @arg @ref FL_CMU_GROUP4_BUSCLK_GPTIM1
  *           @arg @ref FL_CMU_GROUP4_BUSCLK_GPTIM2
  *           @arg @ref FL_CMU_GROUP4_BUSCLK_TAU0
  *           @arg @ref FL_CMU_GROUP4_BUSCLK_TAU1
  *           @arg @ref FL_CMU_GROUP4_BUSCLK_ATIM
  *           @arg @ref FL_CMU_GROUP4_BUSCLK_BSTIM16
  * @retval   None
  */
__STATIC_INLINE void FL_CMU_EnableGroup4BusClock(uint32_t peripheral)
{
    SET_BIT(CMU->PCLKCR4, ((peripheral & 0xffffffff) << 0x0U));
}

/**
  * @brief    Disable Group1 Periph Bus Clock
  * @rmtoll   PCLKCR1        FL_CMU_DisableGroup1BusClock
  * @param    peripheral This parameter can be one of the following values:
  *           @arg @ref FL_CMU_GROUP1_BUSCLK_LPTIM32
  *           @arg @ref FL_CMU_GROUP1_BUSCLK_LPTIM16
  *           @arg @ref FL_CMU_GROUP1_BUSCLK_RTC
  *           @arg @ref FL_CMU_GROUP1_BUSCLK_PMU
  *           @arg @ref FL_CMU_GROUP1_BUSCLK_SCU
  *           @arg @ref FL_CMU_GROUP1_BUSCLK_IWDT
  *           @arg @ref FL_CMU_GROUP1_BUSCLK_ANAC
  *           @arg @ref FL_CMU_GROUP1_BUSCLK_PAD
  *           @arg @ref FL_CMU_GROUP1_BUSCLK_SVD
  *           @arg @ref FL_CMU_GROUP1_BUSCLK_COMP
  *           @arg @ref FL_CMU_GROUP1_BUSCLK_CLM0
  *           @arg @ref FL_CMU_GROUP1_BUSCLK_CLM1
  * @retval   None
  */
__STATIC_INLINE void FL_CMU_DisableGroup1BusClock(uint32_t peripheral)
{
    CLEAR_BIT(CMU->PCLKCR1, ((peripheral & 0xffffffff) << 0x0U));
}

/**
  * @brief    Disable Group2 Periph Bus Clock
  * @rmtoll   PCLKCR2        FL_CMU_DisableGroup2BusClock
  * @param    peripheral This parameter can be one of the following values:
  *           @arg @ref FL_CMU_GROUP2_BUSCLK_CRC
  *           @arg @ref FL_CMU_GROUP2_BUSCLK_RNG
  *           @arg @ref FL_CMU_GROUP2_BUSCLK_AES
  *           @arg @ref FL_CMU_GROUP2_BUSCLK_DMA
  *           @arg @ref FL_CMU_GROUP2_BUSCLK_FLASH
  *           @arg @ref FL_CMU_GROUP2_BUSCLK_RAMBIST
  *           @arg @ref FL_CMU_GROUP2_BUSCLK_WWDT
  *           @arg @ref FL_CMU_GROUP2_BUSCLK_ADC
  *           @arg @ref FL_CMU_GROUP2_BUSCLK_HDIV
  *           @arg @ref FL_CMU_GROUP2_BUSCLK_DAC
  *           @arg @ref FL_CMU_GROUP2_BUSCLK_PGL
  * @retval   None
  */
__STATIC_INLINE void FL_CMU_DisableGroup2BusClock(uint32_t peripheral)
{
    CLEAR_BIT(CMU->PCLKCR2, ((peripheral & 0xffffffff) << 0x0U));
}

/**
  * @brief    Disable Group3 Periph Bus Clock
  * @rmtoll   PCLKCR3        FL_CMU_DisableGroup3BusClock
  * @param    peripheral This parameter can be one of the following values:
  *           @arg @ref FL_CMU_GROUP3_BUSCLK_SPI0
  *           @arg @ref FL_CMU_GROUP3_BUSCLK_SPI1
  *           @arg @ref FL_CMU_GROUP3_BUSCLK_SPI2
  *           @arg @ref FL_CMU_GROUP3_BUSCLK_SPI3
  *           @arg @ref FL_CMU_GROUP3_BUSCLK_UART0
  *           @arg @ref FL_CMU_GROUP3_BUSCLK_UART1
  *           @arg @ref FL_CMU_GROUP3_BUSCLK_UART2
  *           @arg @ref FL_CMU_GROUP3_BUSCLK_UART3
  *           @arg @ref FL_CMU_GROUP3_BUSCLK_UART4
  *           @arg @ref FL_CMU_GROUP3_BUSCLK_UART5
  *           @arg @ref FL_CMU_GROUP3_BUSCLK_UARTIR
  *           @arg @ref FL_CMU_GROUP3_BUSCLK_LPUART0
  *           @arg @ref FL_CMU_GROUP3_BUSCLK_LPUART1
  *           @arg @ref FL_CMU_GROUP3_BUSCLK_LPUART2
  *           @arg @ref FL_CMU_GROUP3_BUSCLK_FSCAN
  *           @arg @ref FL_CMU_GROUP3_BUSCLK_CANFD0
  *           @arg @ref FL_CMU_GROUP3_BUSCLK_CANFD1
  *           @arg @ref FL_CMU_GROUP3_BUSCLK_I2C0
  *           @arg @ref FL_CMU_GROUP3_BUSCLK_I2C1
  *           @arg @ref FL_CMU_GROUP3_BUSCLK_I2CSMB0
  *           @arg @ref FL_CMU_GROUP3_BUSCLK_I2CSMB1
  *           @arg @ref FL_CMU_GROUP3_BUSCLK_SENT0
  *           @arg @ref FL_CMU_GROUP3_BUSCLK_SENT1
  * @retval   None
  */
__STATIC_INLINE void FL_CMU_DisableGroup3BusClock(uint32_t peripheral)
{
    CLEAR_BIT(CMU->PCLKCR3, ((peripheral & 0xffffffff) << 0x0U));
}

/**
  * @brief    Disable Group4 Periph Bus Clock
  * @rmtoll   PCLKCR4        FL_CMU_DisableGroup4BusClock
  * @param    peripheral This parameter can be one of the following values:
  *           @arg @ref FL_CMU_GROUP4_BUSCLK_BSTIM32
  *           @arg @ref FL_CMU_GROUP4_BUSCLK_GPTIM0
  *           @arg @ref FL_CMU_GROUP4_BUSCLK_GPTIM1
  *           @arg @ref FL_CMU_GROUP4_BUSCLK_GPTIM2
  *           @arg @ref FL_CMU_GROUP4_BUSCLK_TAU0
  *           @arg @ref FL_CMU_GROUP4_BUSCLK_TAU1
  *           @arg @ref FL_CMU_GROUP4_BUSCLK_ATIM
  *           @arg @ref FL_CMU_GROUP4_BUSCLK_BSTIM16
  * @retval   None
  */
__STATIC_INLINE void FL_CMU_DisableGroup4BusClock(uint32_t peripheral)
{
    CLEAR_BIT(CMU->PCLKCR4, ((peripheral & 0xffffffff) << 0x0U));
}

/**
  * @brief    Get Group1 Periph Bus Clock Enable Status
  * @rmtoll   PCLKCR1        FL_CMU_IsEnabledGroup1BusClock
  * @param    peripheral This parameter can be one of the following values:
  *           @arg @ref FL_CMU_GROUP1_BUSCLK_LPTIM32
  *           @arg @ref FL_CMU_GROUP1_BUSCLK_LPTIM16
  *           @arg @ref FL_CMU_GROUP1_BUSCLK_RTC
  *           @arg @ref FL_CMU_GROUP1_BUSCLK_PMU
  *           @arg @ref FL_CMU_GROUP1_BUSCLK_SCU
  *           @arg @ref FL_CMU_GROUP1_BUSCLK_IWDT
  *           @arg @ref FL_CMU_GROUP1_BUSCLK_ANAC
  *           @arg @ref FL_CMU_GROUP1_BUSCLK_PAD
  *           @arg @ref FL_CMU_GROUP1_BUSCLK_SVD
  *           @arg @ref FL_CMU_GROUP1_BUSCLK_COMP
  *           @arg @ref FL_CMU_GROUP1_BUSCLK_CLM0
  *           @arg @ref FL_CMU_GROUP1_BUSCLK_CLM1
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_CMU_IsEnabledGroup1BusClock(uint32_t peripheral)
{
    return (uint32_t)(READ_BIT(CMU->PCLKCR1, ((peripheral & 0xffffffff) << 0x0U)) == ((peripheral & 0xffffffff) << 0x0U));
}

/**
  * @brief    Get Group2 Periph Bus Clock Enable Status
  * @rmtoll   PCLKCR2        FL_CMU_IsEnabledGroup2BusClock
  * @param    peripheral This parameter can be one of the following values:
  *           @arg @ref FL_CMU_GROUP2_BUSCLK_CRC
  *           @arg @ref FL_CMU_GROUP2_BUSCLK_RNG
  *           @arg @ref FL_CMU_GROUP2_BUSCLK_AES
  *           @arg @ref FL_CMU_GROUP2_BUSCLK_DMA
  *           @arg @ref FL_CMU_GROUP2_BUSCLK_FLASH
  *           @arg @ref FL_CMU_GROUP2_BUSCLK_RAMBIST
  *           @arg @ref FL_CMU_GROUP2_BUSCLK_WWDT
  *           @arg @ref FL_CMU_GROUP2_BUSCLK_ADC
  *           @arg @ref FL_CMU_GROUP2_BUSCLK_HDIV
  *           @arg @ref FL_CMU_GROUP2_BUSCLK_DAC
  *           @arg @ref FL_CMU_GROUP2_BUSCLK_PGL
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_CMU_IsEnabledGroup2BusClock(uint32_t peripheral)
{
    return (uint32_t)(READ_BIT(CMU->PCLKCR2, ((peripheral & 0xffffffff) << 0x0U)) == ((peripheral & 0xffffffff) << 0x0U));
}

/**
  * @brief    Get Group3 Periph Bus Clock Enable Status
  * @rmtoll   PCLKCR3        FL_CMU_IsEnabledGroup3BusClock
  * @param    peripheral This parameter can be one of the following values:
  *           @arg @ref FL_CMU_GROUP3_BUSCLK_SPI0
  *           @arg @ref FL_CMU_GROUP3_BUSCLK_SPI1
  *           @arg @ref FL_CMU_GROUP3_BUSCLK_SPI2
  *           @arg @ref FL_CMU_GROUP3_BUSCLK_SPI3
  *           @arg @ref FL_CMU_GROUP3_BUSCLK_UART0
  *           @arg @ref FL_CMU_GROUP3_BUSCLK_UART1
  *           @arg @ref FL_CMU_GROUP3_BUSCLK_UART2
  *           @arg @ref FL_CMU_GROUP3_BUSCLK_UART3
  *           @arg @ref FL_CMU_GROUP3_BUSCLK_UART4
  *           @arg @ref FL_CMU_GROUP3_BUSCLK_UART5
  *           @arg @ref FL_CMU_GROUP3_BUSCLK_UARTIR
  *           @arg @ref FL_CMU_GROUP3_BUSCLK_LPUART0
  *           @arg @ref FL_CMU_GROUP3_BUSCLK_LPUART1
  *           @arg @ref FL_CMU_GROUP3_BUSCLK_LPUART2
  *           @arg @ref FL_CMU_GROUP3_BUSCLK_FSCAN
  *           @arg @ref FL_CMU_GROUP3_BUSCLK_CANFD0
  *           @arg @ref FL_CMU_GROUP3_BUSCLK_CANFD1
  *           @arg @ref FL_CMU_GROUP3_BUSCLK_I2C0
  *           @arg @ref FL_CMU_GROUP3_BUSCLK_I2C1
  *           @arg @ref FL_CMU_GROUP3_BUSCLK_I2CSMB0
  *           @arg @ref FL_CMU_GROUP3_BUSCLK_I2CSMB1
  *           @arg @ref FL_CMU_GROUP3_BUSCLK_SENT0
  *           @arg @ref FL_CMU_GROUP3_BUSCLK_SENT1
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_CMU_IsEnabledGroup3BusClock(uint32_t peripheral)
{
    return (uint32_t)(READ_BIT(CMU->PCLKCR3, ((peripheral & 0xffffffff) << 0x0U)) == ((peripheral & 0xffffffff) << 0x0U));
}

/**
  * @brief    Get Group4 Periph Bus Clock Enable Status
  * @rmtoll   PCLKCR4        FL_CMU_IsEnabledGroup4BusClock
  * @param    peripheral This parameter can be one of the following values:
  *           @arg @ref FL_CMU_GROUP4_BUSCLK_BSTIM32
  *           @arg @ref FL_CMU_GROUP4_BUSCLK_GPTIM0
  *           @arg @ref FL_CMU_GROUP4_BUSCLK_GPTIM1
  *           @arg @ref FL_CMU_GROUP4_BUSCLK_GPTIM2
  *           @arg @ref FL_CMU_GROUP4_BUSCLK_TAU0
  *           @arg @ref FL_CMU_GROUP4_BUSCLK_TAU1
  *           @arg @ref FL_CMU_GROUP4_BUSCLK_ATIM
  *           @arg @ref FL_CMU_GROUP4_BUSCLK_BSTIM16
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_CMU_IsEnabledGroup4BusClock(uint32_t peripheral)
{
    return (uint32_t)(READ_BIT(CMU->PCLKCR4, ((peripheral & 0xffffffff) << 0x0U)) == ((peripheral & 0xffffffff) << 0x0U));
}

/**
  * @brief    Enable Periph Operation Clock
  * @rmtoll   OPCCR3        FL_CMU_EnableOperationClock
  * @param    peripheral This parameter can be one of the following values:
  *           @arg @ref FL_CMU_OPCLK_EXTI
  *           @arg @ref FL_CMU_OPCLK_FLASH
  *           @arg @ref FL_CMU_OPCLK_LPUART0
  *           @arg @ref FL_CMU_OPCLK_LPUART1
  *           @arg @ref FL_CMU_OPCLK_LPUART2
  *           @arg @ref FL_CMU_OPCLK_RNG
  *           @arg @ref FL_CMU_OPCLK_I2CSMB1
  *           @arg @ref FL_CMU_OPCLK_I2CSMB0
  *           @arg @ref FL_CMU_OPCLK_ADC
  *           @arg @ref FL_CMU_OPCLK_ATIM
  *           @arg @ref FL_CMU_OPCLK_FSCAN
  *           @arg @ref FL_CMU_OPCLK_LIN
  *           @arg @ref FL_CMU_OPCLK_UART3
  *           @arg @ref FL_CMU_OPCLK_UART2
  *           @arg @ref FL_CMU_OPCLK_UART1
  *           @arg @ref FL_CMU_OPCLK_UART0
  *           @arg @ref FL_CMU_OPCLK_BSTIM16
  *           @arg @ref FL_CMU_OPCLK_BSTIM32
  *           @arg @ref FL_CMU_OPCLK_LPTIM16
  *           @arg @ref FL_CMU_OPCLK_LPTIM32
  * @retval   None
  */
__STATIC_INLINE void FL_CMU_EnableOperationClock(uint32_t peripheral)
{
    SET_BIT(CMU->OPCCR3, ((peripheral & 0xffffffff) << 0x0U));
}

/**
  * @brief    Disable Periph Operation Clock
  * @rmtoll   OPCCR3        FL_CMU_DisableOperationClock
  * @param    peripheral This parameter can be one of the following values:
  *           @arg @ref FL_CMU_OPCLK_EXTI
  *           @arg @ref FL_CMU_OPCLK_FLASH
  *           @arg @ref FL_CMU_OPCLK_LPUART0
  *           @arg @ref FL_CMU_OPCLK_LPUART1
  *           @arg @ref FL_CMU_OPCLK_LPUART2
  *           @arg @ref FL_CMU_OPCLK_RNG
  *           @arg @ref FL_CMU_OPCLK_I2CSMB1
  *           @arg @ref FL_CMU_OPCLK_I2CSMB0
  *           @arg @ref FL_CMU_OPCLK_ADC
  *           @arg @ref FL_CMU_OPCLK_ATIM
  *           @arg @ref FL_CMU_OPCLK_FSCAN
  *           @arg @ref FL_CMU_OPCLK_LIN
  *           @arg @ref FL_CMU_OPCLK_UART3
  *           @arg @ref FL_CMU_OPCLK_UART2
  *           @arg @ref FL_CMU_OPCLK_UART1
  *           @arg @ref FL_CMU_OPCLK_UART0
  *           @arg @ref FL_CMU_OPCLK_BSTIM16
  *           @arg @ref FL_CMU_OPCLK_BSTIM32
  *           @arg @ref FL_CMU_OPCLK_LPTIM16
  *           @arg @ref FL_CMU_OPCLK_LPTIM32
  * @retval   None
  */
__STATIC_INLINE void FL_CMU_DisableOperationClock(uint32_t peripheral)
{
    CLEAR_BIT(CMU->OPCCR3, ((peripheral & 0xffffffff) << 0x0U));
}

/**
  * @brief    Get Periph Operation Clock Enable Status
  * @rmtoll   OPCCR3        FL_CMU_IsEnabledOperationClock
  * @param    peripheral This parameter can be one of the following values:
  *           @arg @ref FL_CMU_OPCLK_EXTI
  *           @arg @ref FL_CMU_OPCLK_FLASH
  *           @arg @ref FL_CMU_OPCLK_LPUART0
  *           @arg @ref FL_CMU_OPCLK_LPUART1
  *           @arg @ref FL_CMU_OPCLK_LPUART2
  *           @arg @ref FL_CMU_OPCLK_RNG
  *           @arg @ref FL_CMU_OPCLK_I2CSMB1
  *           @arg @ref FL_CMU_OPCLK_I2CSMB0
  *           @arg @ref FL_CMU_OPCLK_ADC
  *           @arg @ref FL_CMU_OPCLK_ATIM
  *           @arg @ref FL_CMU_OPCLK_FSCAN
  *           @arg @ref FL_CMU_OPCLK_LIN
  *           @arg @ref FL_CMU_OPCLK_UART3
  *           @arg @ref FL_CMU_OPCLK_UART2
  *           @arg @ref FL_CMU_OPCLK_UART1
  *           @arg @ref FL_CMU_OPCLK_UART0
  *           @arg @ref FL_CMU_OPCLK_BSTIM16
  *           @arg @ref FL_CMU_OPCLK_BSTIM32
  *           @arg @ref FL_CMU_OPCLK_LPTIM16
  *           @arg @ref FL_CMU_OPCLK_LPTIM32
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_CMU_IsEnabledOperationClock(uint32_t peripheral)
{
    return (uint32_t)(READ_BIT(CMU->OPCCR3, ((peripheral & 0xffffffff) << 0x0U)) == ((peripheral & 0xffffffff) << 0x0U));
}

/**
  * @brief    Enable CANFD Operation Clock
  * @rmtoll   CFDER        FL_CMU_EnableCANFDOperationClock
  * @param    peripheral This parameter can be one of the following values:
  *           @arg @ref FL_CMU_OPCLK_CANFD1_COMM
  *           @arg @ref FL_CMU_OPCLK_CANFD1_RAM
  *           @arg @ref FL_CMU_OPCLK_CANFD0_COMM
  *           @arg @ref FL_CMU_OPCLK_CANFD0_RAM
  * @retval   None
  */
__STATIC_INLINE void FL_CMU_EnableCANFDOperationClock(uint32_t peripheral)
{
    SET_BIT(CMU->CFDER, ((peripheral & 0xffffffff) << 0x0U));
}

/**
  * @brief    Disable CANFD Operation Clock
  * @rmtoll   CFDER        FL_CMU_DisableCANFDOperationClock
  * @param    peripheral This parameter can be one of the following values:
  *           @arg @ref FL_CMU_OPCLK_CANFD1_COMM
  *           @arg @ref FL_CMU_OPCLK_CANFD1_RAM
  *           @arg @ref FL_CMU_OPCLK_CANFD0_COMM
  *           @arg @ref FL_CMU_OPCLK_CANFD0_RAM
  * @retval   None
  */
__STATIC_INLINE void FL_CMU_DisableCANFDOperationClock(uint32_t peripheral)
{
    CLEAR_BIT(CMU->CFDER, ((peripheral & 0xffffffff) << 0x0U));
}

/**
  * @brief    Get CANFD Operation Clock Enable Status
  * @rmtoll   CFDER        FL_CMU_IsEnabledCANFDOperationClock
  * @param    peripheral This parameter can be one of the following values:
  *           @arg @ref FL_CMU_OPCLK_CANFD1_COMM
  *           @arg @ref FL_CMU_OPCLK_CANFD1_RAM
  *           @arg @ref FL_CMU_OPCLK_CANFD0_COMM
  *           @arg @ref FL_CMU_OPCLK_CANFD0_RAM
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_CMU_IsEnabledCANFDOperationClock(uint32_t peripheral)
{
    return (uint32_t)(READ_BIT(CMU->CFDER, ((peripheral & 0xffffffff) << 0x0U)) == ((peripheral & 0xffffffff) << 0x0U));
}

/**
  * @brief    Set EXTI Clock Source
  * @rmtoll   OPCCR1    EXTICKS    FL_CMU_SetEXTIClockSource
  * @param    clock This parameter can be one of the following values:
  *           @arg @ref FL_CMU_EXTI_CLK_SOURCE_LSCLK
  *           @arg @ref FL_CMU_EXTI_CLK_SOURCE_AHBCLK
  * @retval   None
  */
__STATIC_INLINE void FL_CMU_SetEXTIClockSource(uint32_t clock)
{
    MODIFY_REG(CMU->OPCCR1, CMU_OPCCR1_EXTICKS_Msk, clock);
}

/**
  * @brief    Get EXTI Clock Source Setting
  * @rmtoll   OPCCR1    EXTICKS    FL_CMU_GetEXTIClockSource
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_CMU_EXTI_CLK_SOURCE_LSCLK
  *           @arg @ref FL_CMU_EXTI_CLK_SOURCE_AHBCLK
  */
__STATIC_INLINE uint32_t FL_CMU_GetEXTIClockSource(void)
{
    return (uint32_t)(READ_BIT(CMU->OPCCR1, CMU_OPCCR1_EXTICKS_Msk));
}

/**
  * @brief    Set UART3 Clock Source
  * @rmtoll   OPCCR1    UART3CKS    FL_CMU_SetUART3ClockSource
  * @param    clock This parameter can be one of the following values:
  *           @arg @ref FL_CMU_UART3_CLK_SOURCE_APBCLK
  *           @arg @ref FL_CMU_UART3_CLK_SOURCE_RCHF
  *           @arg @ref FL_CMU_UART3_CLK_SOURCE_SYSCLK
  *           @arg @ref FL_CMU_UART3_CLK_SOURCE_XTHF
  * @retval   None
  */
__STATIC_INLINE void FL_CMU_SetUART3ClockSource(uint32_t clock)
{
    MODIFY_REG(CMU->OPCCR1, CMU_OPCCR1_UART3CKS_Msk, clock);
}

/**
  * @brief    Get UART3 Clock Source Setting
  * @rmtoll   OPCCR1    UART3CKS    FL_CMU_GetUART3ClockSource
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_CMU_UART3_CLK_SOURCE_APBCLK
  *           @arg @ref FL_CMU_UART3_CLK_SOURCE_RCHF
  *           @arg @ref FL_CMU_UART3_CLK_SOURCE_SYSCLK
  *           @arg @ref FL_CMU_UART3_CLK_SOURCE_XTHF
  */
__STATIC_INLINE uint32_t FL_CMU_GetUART3ClockSource(void)
{
    return (uint32_t)(READ_BIT(CMU->OPCCR1, CMU_OPCCR1_UART3CKS_Msk));
}

/**
  * @brief    Set LPUART2 Clock Source
  * @rmtoll   OPCCR1    LPUART2CKS    FL_CMU_SetLPUART2ClockSource
  * @param    clock This parameter can be one of the following values:
  *           @arg @ref FL_CMU_LPUART2_CLK_SOURCE_LSCLK
  *           @arg @ref FL_CMU_LPUART2_CLK_SOURCE_RCHF_PSC
  * @retval   None
  */
__STATIC_INLINE void FL_CMU_SetLPUART2ClockSource(uint32_t clock)
{
    MODIFY_REG(CMU->OPCCR1, CMU_OPCCR1_LPUART2CKS_Msk, clock);
}

/**
  * @brief    Get LPUART2 Clock Source Setting
  * @rmtoll   OPCCR1    LPUART2CKS    FL_CMU_GetLPUART2ClockSource
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_CMU_LPUART2_CLK_SOURCE_LSCLK
  *           @arg @ref FL_CMU_LPUART2_CLK_SOURCE_RCHF_PSC
  */
__STATIC_INLINE uint32_t FL_CMU_GetLPUART2ClockSource(void)
{
    return (uint32_t)(READ_BIT(CMU->OPCCR1, CMU_OPCCR1_LPUART2CKS_Msk));
}

/**
  * @brief    Set LPUART1 Clock Source
  * @rmtoll   OPCCR1    LPUART1CKS    FL_CMU_SetLPUART1ClockSource
  * @param    clock This parameter can be one of the following values:
  *           @arg @ref FL_CMU_LPUART1_CLK_SOURCE_LSCLK
  *           @arg @ref FL_CMU_LPUART1_CLK_SOURCE_RCHF_PSC
  * @retval   None
  */
__STATIC_INLINE void FL_CMU_SetLPUART1ClockSource(uint32_t clock)
{
    MODIFY_REG(CMU->OPCCR1, CMU_OPCCR1_LPUART1CKS_Msk, clock);
}

/**
  * @brief    Get LPUART1 Clock Source Setting
  * @rmtoll   OPCCR1    LPUART1CKS    FL_CMU_GetLPUART1ClockSource
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_CMU_LPUART1_CLK_SOURCE_LSCLK
  *           @arg @ref FL_CMU_LPUART1_CLK_SOURCE_RCHF_PSC
  */
__STATIC_INLINE uint32_t FL_CMU_GetLPUART1ClockSource(void)
{
    return (uint32_t)(READ_BIT(CMU->OPCCR1, CMU_OPCCR1_LPUART1CKS_Msk));
}

/**
  * @brief    Set LPUART0 Clock Source
  * @rmtoll   OPCCR1    LPUART0CKS    FL_CMU_SetLPUART0ClockSource
  * @param    clock This parameter can be one of the following values:
  *           @arg @ref FL_CMU_LPUART0_CLK_SOURCE_LSCLK
  *           @arg @ref FL_CMU_LPUART0_CLK_SOURCE_RCHF_PSC
  * @retval   None
  */
__STATIC_INLINE void FL_CMU_SetLPUART0ClockSource(uint32_t clock)
{
    MODIFY_REG(CMU->OPCCR1, CMU_OPCCR1_LPUART0CKS_Msk, clock);
}

/**
  * @brief    Get LPUART0 Clock Source Setting
  * @rmtoll   OPCCR1    LPUART0CKS    FL_CMU_GetLPUART0ClockSource
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_CMU_LPUART0_CLK_SOURCE_LSCLK
  *           @arg @ref FL_CMU_LPUART0_CLK_SOURCE_RCHF_PSC
  */
__STATIC_INLINE uint32_t FL_CMU_GetLPUART0ClockSource(void)
{
    return (uint32_t)(READ_BIT(CMU->OPCCR1, CMU_OPCCR1_LPUART0CKS_Msk));
}

/**
  * @brief    Set UART2 Clock Source
  * @rmtoll   OPCCR1    UART2CKS    FL_CMU_SetUART2ClockSource
  * @param    clock This parameter can be one of the following values:
  *           @arg @ref FL_CMU_UART2_CLK_SOURCE_APBCLK
  *           @arg @ref FL_CMU_UART2_CLK_SOURCE_RCHF
  *           @arg @ref FL_CMU_UART2_CLK_SOURCE_SYSCLK
  *           @arg @ref FL_CMU_UART2_CLK_SOURCE_XTHF
  * @retval   None
  */
__STATIC_INLINE void FL_CMU_SetUART2ClockSource(uint32_t clock)
{
    MODIFY_REG(CMU->OPCCR1, CMU_OPCCR1_UART2CKS_Msk, clock);
}

/**
  * @brief    Get UART2 Clock Source
  * @rmtoll   OPCCR1    UART2CKS    FL_CMU_GetUART2ClockSource
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_CMU_UART2_CLK_SOURCE_APBCLK
  *           @arg @ref FL_CMU_UART2_CLK_SOURCE_RCHF
  *           @arg @ref FL_CMU_UART2_CLK_SOURCE_SYSCLK
  *           @arg @ref FL_CMU_UART2_CLK_SOURCE_XTHF
  */
__STATIC_INLINE uint32_t FL_CMU_GetUART2ClockSource(void)
{
    return (uint32_t)(READ_BIT(CMU->OPCCR1, CMU_OPCCR1_UART2CKS_Msk));
}

/**
  * @brief    Set I2C_SMB1 Clock Source
  * @rmtoll   OPCCR1    I2CSMB1CKS    FL_CMU_SetI2CSMB1ClockSource
  * @param    clock This parameter can be one of the following values:
  *           @arg @ref FL_CMU_I2CSMB1_CLK_SOURCE_APBCLK
  *           @arg @ref FL_CMU_I2CSMB1_CLK_SOURCE_RCHF
  *           @arg @ref FL_CMU_I2CSMB1_CLK_SOURCE_SYSCLK
  * @retval   None
  */
__STATIC_INLINE void FL_CMU_SetI2CSMB1ClockSource(uint32_t clock)
{
    MODIFY_REG(CMU->OPCCR1, CMU_OPCCR1_I2CSMB1CKS_Msk, clock);
}

/**
  * @brief    Get I2C_SMB1 Source Setting
  * @rmtoll   OPCCR1    I2CSMB1CKS    FL_CMU_GetI2CSMB1ClockSource
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_CMU_I2CSMB1_CLK_SOURCE_APBCLK
  *           @arg @ref FL_CMU_I2CSMB1_CLK_SOURCE_RCHF
  *           @arg @ref FL_CMU_I2CSMB1_CLK_SOURCE_SYSCLK
  */
__STATIC_INLINE uint32_t FL_CMU_GetI2CSMB1ClockSource(void)
{
    return (uint32_t)(READ_BIT(CMU->OPCCR1, CMU_OPCCR1_I2CSMB1CKS_Msk));
}

/**
  * @brief    Set I2C_SMB0 Clock Source
  * @rmtoll   OPCCR1    I2CSMB0CKS    FL_CMU_SetI2CSMB0ClockSource
  * @param    clock This parameter can be one of the following values:
  *           @arg @ref FL_CMU_I2CSMB0_CLK_SOURCE_APBCLK
  *           @arg @ref FL_CMU_I2CSMB0_CLK_SOURCE_RCHF
  *           @arg @ref FL_CMU_I2CSMB0_CLK_SOURCE_SYSCLK
  * @retval   None
  */
__STATIC_INLINE void FL_CMU_SetI2CSMB0ClockSource(uint32_t clock)
{
    MODIFY_REG(CMU->OPCCR1, CMU_OPCCR1_I2CSMB0CKS_Msk, clock);
}

/**
  * @brief    Get I2C_SMB0 Source Setting
  * @rmtoll   OPCCR1    I2CSMB0CKS    FL_CMU_GetI2CSMB0ClockSource
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_CMU_I2CSMB0_CLK_SOURCE_APBCLK
  *           @arg @ref FL_CMU_I2CSMB0_CLK_SOURCE_RCHF
  *           @arg @ref FL_CMU_I2CSMB0_CLK_SOURCE_SYSCLK
  */
__STATIC_INLINE uint32_t FL_CMU_GetI2CSMB0ClockSource(void)
{
    return (uint32_t)(READ_BIT(CMU->OPCCR1, CMU_OPCCR1_I2CSMB0CKS_Msk));
}

/**
  * @brief    Set BSTIM16 Clock Source
  * @rmtoll   OPCCR1    BT16CKS    FL_CMU_SetBSTIM16ClockSource
  * @param    clock This parameter can be one of the following values:
  *           @arg @ref FL_CMU_BSTIM16_CLK_SOURCE_APBCLK
  *           @arg @ref FL_CMU_BSTIM16_CLK_SOURCE_LSCLK
  *           @arg @ref FL_CMU_BSTIM16_CLK_SOURCE_RCLP
  * @retval   None
  */
__STATIC_INLINE void FL_CMU_SetBSTIM16ClockSource(uint32_t clock)
{
    MODIFY_REG(CMU->OPCCR1, CMU_OPCCR1_BT16CKS_Msk, clock);
}

/**
  * @brief    Get BSTIM16 Clock Source Setting
  * @rmtoll   OPCCR1    BT16CKS    FL_CMU_GetBSTIM16ClockSource
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_CMU_BSTIM16_CLK_SOURCE_APBCLK
  *           @arg @ref FL_CMU_BSTIM16_CLK_SOURCE_LSCLK
  *           @arg @ref FL_CMU_BSTIM16_CLK_SOURCE_RCLP
  */
__STATIC_INLINE uint32_t FL_CMU_GetBSTIM16ClockSource(void)
{
    return (uint32_t)(READ_BIT(CMU->OPCCR1, CMU_OPCCR1_BT16CKS_Msk));
}

/**
  * @brief    Set BSTIM32 Clock Source
  * @rmtoll   OPCCR1    BT32CKS    FL_CMU_SetBSTIM32ClockSource
  * @param    clock This parameter can be one of the following values:
  *           @arg @ref FL_CMU_BSTIM32_CLK_SOURCE_APBCLK
  *           @arg @ref FL_CMU_BSTIM32_CLK_SOURCE_LSCLK
  *           @arg @ref FL_CMU_BSTIM32_CLK_SOURCE_RCLP
  * @retval   None
  */
__STATIC_INLINE void FL_CMU_SetBSTIM32ClockSource(uint32_t clock)
{
    MODIFY_REG(CMU->OPCCR1, CMU_OPCCR1_BT32CKS_Msk, clock);
}

/**
  * @brief    Get BSTIM32 Clock Source Setting
  * @rmtoll   OPCCR1    BT32CKS    FL_CMU_GetBSTIM32ClockSource
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_CMU_BSTIM32_CLK_SOURCE_APBCLK
  *           @arg @ref FL_CMU_BSTIM32_CLK_SOURCE_LSCLK
  *           @arg @ref FL_CMU_BSTIM32_CLK_SOURCE_RCLP
  */
__STATIC_INLINE uint32_t FL_CMU_GetBSTIM32ClockSource(void)
{
    return (uint32_t)(READ_BIT(CMU->OPCCR1, CMU_OPCCR1_BT32CKS_Msk));
}

/**
  * @brief    Set LPTIM16 Clock Source
  * @rmtoll   OPCCR1    LPT16CKS    FL_CMU_SetLPTIM16ClockSource
  * @param    clock This parameter can be one of the following values:
  *           @arg @ref FL_CMU_LPTIM16_CLK_SOURCE_APBCLK
  *           @arg @ref FL_CMU_LPTIM16_CLK_SOURCE_LSCLK
  *           @arg @ref FL_CMU_LPTIM16_CLK_SOURCE_RCLP
  * @retval   None
  */
__STATIC_INLINE void FL_CMU_SetLPTIM16ClockSource(uint32_t clock)
{
    MODIFY_REG(CMU->OPCCR1, CMU_OPCCR1_LPT16CKS_Msk, clock);
}

/**
  * @brief    Get LPTIM16 Clock Source Setting
  * @rmtoll   OPCCR1    LPT16CKS    FL_CMU_GetLPTIM16ClockSource
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_CMU_LPTIM16_CLK_SOURCE_APBCLK
  *           @arg @ref FL_CMU_LPTIM16_CLK_SOURCE_LSCLK
  *           @arg @ref FL_CMU_LPTIM16_CLK_SOURCE_RCLP
  */
__STATIC_INLINE uint32_t FL_CMU_GetLPTIM16ClockSource(void)
{
    return (uint32_t)(READ_BIT(CMU->OPCCR1, CMU_OPCCR1_LPT16CKS_Msk));
}

/**
  * @brief    Set LPTIM32 Clock Source
  * @rmtoll   OPCCR1    LPT32CKS    FL_CMU_SetLPTIM32ClockSource
  * @param    clock This parameter can be one of the following values:
  *           @arg @ref FL_CMU_LPTIM32_CLK_SOURCE_APBCLK
  *           @arg @ref FL_CMU_LPTIM32_CLK_SOURCE_LSCLK
  *           @arg @ref FL_CMU_LPTIM32_CLK_SOURCE_RCLP
  * @retval   None
  */
__STATIC_INLINE void FL_CMU_SetLPTIM32ClockSource(uint32_t clock)
{
    MODIFY_REG(CMU->OPCCR1, CMU_OPCCR1_LPT32CKS_Msk, clock);
}

/**
  * @brief    Get LPTIM32 Clock Source Setting
  * @rmtoll   OPCCR1    LPT32CKS    FL_CMU_GetLPTIM32ClockSource
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_CMU_LPTIM32_CLK_SOURCE_APBCLK
  *           @arg @ref FL_CMU_LPTIM32_CLK_SOURCE_LSCLK
  *           @arg @ref FL_CMU_LPTIM32_CLK_SOURCE_RCLP
  */
__STATIC_INLINE uint32_t FL_CMU_GetLPTIM32ClockSource(void)
{
    return (uint32_t)(READ_BIT(CMU->OPCCR1, CMU_OPCCR1_LPT32CKS_Msk));
}

/**
  * @brief    Set ATIM Clock Source
  * @rmtoll   OPCCR1    ATCKS    FL_CMU_SetATIMClockSource
  * @param    clock This parameter can be one of the following values:
  *           @arg @ref FL_CMU_ATIM_CLK_SOURCE_APBCLK
  *           @arg @ref FL_CMU_ATIM_CLK_SOURCE_PLL_X2
  * @retval   None
  */
__STATIC_INLINE void FL_CMU_SetATIMClockSource(uint32_t clock)
{
    MODIFY_REG(CMU->OPCCR1, CMU_OPCCR1_ATCKS_Msk, clock);
}

/**
  * @brief    Get ATIM Clock Source Setting
  * @rmtoll   OPCCR1    ATCKS    FL_CMU_GetATIMClockSource
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_CMU_ATIM_CLK_SOURCE_APBCLK
  *           @arg @ref FL_CMU_ATIM_CLK_SOURCE_PLL_X2
  */
__STATIC_INLINE uint32_t FL_CMU_GetATIMClockSource(void)
{
    return (uint32_t)(READ_BIT(CMU->OPCCR1, CMU_OPCCR1_ATCKS_Msk));
}

/**
  * @brief    Set FSCAN Clock Source
  * @rmtoll   OPCCR1    FSCANCKS    FL_CMU_SetFSCANClockSource
  * @param    clock This parameter can be one of the following values:
  *           @arg @ref FL_CMU_FSCAN_CLK_SOURCE_RCHF
  *           @arg @ref FL_CMU_FSCAN_CLK_SOURCE_XTHF
  *           @arg @ref FL_CMU_FSCAN_CLK_SOURCE_PLL
  *           @arg @ref FL_CMU_FSCAN_CLK_SOURCE_APBCLK
  * @retval   None
  */
__STATIC_INLINE void FL_CMU_SetFSCANClockSource(uint32_t clock)
{
    MODIFY_REG(CMU->OPCCR1, CMU_OPCCR1_FSCANCKS_Msk, clock);
}

/**
  * @brief    Get FSCAN Clock Source Setting
  * @rmtoll   OPCCR1    FSCANCKS    FL_CMU_GetFSCANClockSource
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_CMU_FSCAN_CLK_SOURCE_RCHF
  *           @arg @ref FL_CMU_FSCAN_CLK_SOURCE_XTHF
  *           @arg @ref FL_CMU_FSCAN_CLK_SOURCE_PLL
  *           @arg @ref FL_CMU_FSCAN_CLK_SOURCE_APBCLK
  */
__STATIC_INLINE uint32_t FL_CMU_GetFSCANClockSource(void)
{
    return (uint32_t)(READ_BIT(CMU->OPCCR1, CMU_OPCCR1_FSCANCKS_Msk));
}

/**
  * @brief    Set UART1 Clock Source
  * @rmtoll   OPCCR1    UART1CKS    FL_CMU_SetUART1ClockSource
  * @param    clock This parameter can be one of the following values:
  *           @arg @ref FL_CMU_UART1_CLK_SOURCE_APBCLK
  *           @arg @ref FL_CMU_UART1_CLK_SOURCE_RCHF
  *           @arg @ref FL_CMU_UART1_CLK_SOURCE_SYSCLK
  *           @arg @ref FL_CMU_UART1_CLK_SOURCE_XTHF
  * @retval   None
  */
__STATIC_INLINE void FL_CMU_SetUART1ClockSource(uint32_t clock)
{
    MODIFY_REG(CMU->OPCCR1, CMU_OPCCR1_UART1CKS_Msk, clock);
}

/**
  * @brief    Get UART1 Clock Source Setting
  * @rmtoll   OPCCR1    UART1CKS    FL_CMU_GetUART1ClockSource
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_CMU_UART1_CLK_SOURCE_APBCLK
  *           @arg @ref FL_CMU_UART1_CLK_SOURCE_RCHF
  *           @arg @ref FL_CMU_UART1_CLK_SOURCE_SYSCLK
  *           @arg @ref FL_CMU_UART1_CLK_SOURCE_XTHF
  */
__STATIC_INLINE uint32_t FL_CMU_GetUART1ClockSource(void)
{
    return (uint32_t)(READ_BIT(CMU->OPCCR1, CMU_OPCCR1_UART1CKS_Msk));
}

/**
  * @brief    Set UART0 Clock Source
  * @rmtoll   OPCCR1    UART0CKS    FL_CMU_SetUART0ClockSource
  * @param    clock This parameter can be one of the following values:
  *           @arg @ref FL_CMU_UART0_CLK_SOURCE_APBCLK
  *           @arg @ref FL_CMU_UART0_CLK_SOURCE_RCHF
  *           @arg @ref FL_CMU_UART0_CLK_SOURCE_SYSCLK
  *           @arg @ref FL_CMU_UART0_CLK_SOURCE_XTHF
  * @retval   None
  */
__STATIC_INLINE void FL_CMU_SetUART0ClockSource(uint32_t clock)
{
    MODIFY_REG(CMU->OPCCR1, CMU_OPCCR1_UART0CKS_Msk, clock);
}

/**
  * @brief    Get UART0 Clock Source Setting
  * @rmtoll   OPCCR1    UART0CKS    FL_CMU_GetUART0ClockSource
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_CMU_UART0_CLK_SOURCE_APBCLK
  *           @arg @ref FL_CMU_UART0_CLK_SOURCE_RCHF
  *           @arg @ref FL_CMU_UART0_CLK_SOURCE_SYSCLK
  *           @arg @ref FL_CMU_UART0_CLK_SOURCE_XTHF
  */
__STATIC_INLINE uint32_t FL_CMU_GetUART0ClockSource(void)
{
    return (uint32_t)(READ_BIT(CMU->OPCCR1, CMU_OPCCR1_UART0CKS_Msk));
}

/**
  * @brief    Set XTHF Prescaler for RTC
  * @rmtoll   OPCCR2    RTCPRSC    FL_CMU_SetRTC_Prescaler
  * @param    prescaler
  * @retval   None
  */
__STATIC_INLINE void FL_CMU_SetRTC_Prescaler(uint32_t prescaler)
{
    MODIFY_REG(CMU->OPCCR2, (0x3ffU << 22U), (prescaler << 22U));
}

/**
  * @brief    Get XTHF Prescaler for RTC
  * @rmtoll   OPCCR2    RTCPRSC    FL_CMU_GetRTC_Prescaler
  * @retval
  */
__STATIC_INLINE uint32_t FL_CMU_GetRTC_Prescaler(void)
{
    return (uint32_t)(READ_BIT(CMU->OPCCR2, (0x3ffU << 22U)) >> 22U);
}

/**
  * @brief    Set RTC Clock Source
  * @rmtoll   OPCCR2    RTCCKS    FL_CMU_SetRTCClockSource
  * @param    clock This parameter can be one of the following values:
  *           @arg @ref FL_CMU_RTC_CLK_SOURCE_LSCLK
  *           @arg @ref FL_CMU_RTC_CLK_SOURCE_XTHF_PSC
  * @retval   None
  */
__STATIC_INLINE void FL_CMU_SetRTCClockSource(uint32_t clock)
{
    MODIFY_REG(CMU->OPCCR2, CMU_OPCCR2_RTCCKS_Msk, clock);
}

/**
  * @brief    Get RTC Clock Source
  * @rmtoll   OPCCR2    RTCCKS    FL_CMU_GetRTCClockSource
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_CMU_RTC_CLK_SOURCE_LSCLK
  *           @arg @ref FL_CMU_RTC_CLK_SOURCE_XTHF_PSC
  */
__STATIC_INLINE uint32_t FL_CMU_GetRTCClockSource(void)
{
    return (uint32_t)(READ_BIT(CMU->OPCCR2, CMU_OPCCR2_RTCCKS_Msk));
}

/**
  * @brief    Set RNG Prescaler
  * @rmtoll   OPCCR2    RNGPRSC    FL_CMU_SetRNGPrescaler
  * @param    prescaler This parameter can be one of the following values:
  *           @arg @ref FL_CMU_RNG_PSC_DIV1
  *           @arg @ref FL_CMU_RNG_PSC_DIV2
  *           @arg @ref FL_CMU_RNG_PSC_DIV4
  *           @arg @ref FL_CMU_RNG_PSC_DIV8
  *           @arg @ref FL_CMU_RNG_PSC_DIV16
  *           @arg @ref FL_CMU_RNG_PSC_DIV32
  * @retval   None
  */
__STATIC_INLINE void FL_CMU_SetRNGPrescaler(uint32_t prescaler)
{
    MODIFY_REG(CMU->OPCCR2, CMU_OPCCR2_RNGPRSC_Msk, prescaler);
}

/**
  * @brief    Get RNG Prescaler Setting
  * @rmtoll   OPCCR2    RNGPRSC    FL_CMU_GetRNGPrescaler
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_CMU_RNG_PSC_DIV1
  *           @arg @ref FL_CMU_RNG_PSC_DIV2
  *           @arg @ref FL_CMU_RNG_PSC_DIV4
  *           @arg @ref FL_CMU_RNG_PSC_DIV8
  *           @arg @ref FL_CMU_RNG_PSC_DIV16
  *           @arg @ref FL_CMU_RNG_PSC_DIV32
  */
__STATIC_INLINE uint32_t FL_CMU_GetRNGPrescaler(void)
{
    return (uint32_t)(READ_BIT(CMU->OPCCR2, CMU_OPCCR2_RNGPRSC_Msk));
}

/**
  * @brief    Set ADC Prescaler
  * @rmtoll   OPCCR2    ADCPRSC    FL_CMU_SetADCPrescaler
  * @param    prescaler This parameter can be one of the following values:
  *           @arg @ref FL_CMU_ADC_PSC_DIV1
  *           @arg @ref FL_CMU_ADC_PSC_DIV2
  *           @arg @ref FL_CMU_ADC_PSC_DIV4
  *           @arg @ref FL_CMU_ADC_PSC_DIV8
  *           @arg @ref FL_CMU_ADC_PSC_DIV16
  *           @arg @ref FL_CMU_ADC_PSC_DIV32
  * @retval   None
  */
__STATIC_INLINE void FL_CMU_SetADCPrescaler(uint32_t prescaler)
{
    MODIFY_REG(CMU->OPCCR2, CMU_OPCCR2_ADCPRSC_Msk, prescaler);
}

/**
  * @brief    Get ADC Prescaler Setting
  * @rmtoll   OPCCR2    ADCPRSC    FL_CMU_GetADCPrescaler
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_CMU_ADC_PSC_DIV1
  *           @arg @ref FL_CMU_ADC_PSC_DIV2
  *           @arg @ref FL_CMU_ADC_PSC_DIV4
  *           @arg @ref FL_CMU_ADC_PSC_DIV8
  *           @arg @ref FL_CMU_ADC_PSC_DIV16
  *           @arg @ref FL_CMU_ADC_PSC_DIV32
  */
__STATIC_INLINE uint32_t FL_CMU_GetADCPrescaler(void)
{
    return (uint32_t)(READ_BIT(CMU->OPCCR2, CMU_OPCCR2_ADCPRSC_Msk));
}

/**
  * @brief    Set ADC Clock Source
  * @rmtoll   OPCCR2    ADCCKS    FL_CMU_SetADCClockSource
  * @param    clock This parameter can be one of the following values:
  *           @arg @ref FL_CMU_ADC_CLK_SOURCE_RCHF
  *           @arg @ref FL_CMU_ADC_CLK_SOURCE_XTHF
  *           @arg @ref FL_CMU_ADC_CLK_SOURCE_PLL
  * @retval   None
  */
__STATIC_INLINE void FL_CMU_SetADCClockSource(uint32_t clock)
{
    MODIFY_REG(CMU->OPCCR2, CMU_OPCCR2_ADCCKS_Msk, clock);
}

/**
  * @brief    Get ADC Clock Source Setting
  * @rmtoll   OPCCR2    ADCCKS    FL_CMU_GetADCClockSource
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_CMU_ADC_CLK_SOURCE_RCHF
  *           @arg @ref FL_CMU_ADC_CLK_SOURCE_XTHF
  *           @arg @ref FL_CMU_ADC_CLK_SOURCE_PLL
  */
__STATIC_INLINE uint32_t FL_CMU_GetADCClockSource(void)
{
    return (uint32_t)(READ_BIT(CMU->OPCCR2, CMU_OPCCR2_ADCCKS_Msk));
}

/**
  * @brief    Enable PLL Lost Lock Interrupt
  * @rmtoll   AHBMCR    LOL_IE    FL_CMU_EnableIT_PLLLostLock
  * @retval   None
  */
__STATIC_INLINE void FL_CMU_EnableIT_PLLLostLock(void)
{
    if (CHIP_U01)
    {   /* Note:Function not implemented. */
    }
    else
    {
        SET_BIT(CMU->AHBMCR, CMU_AHBMCR_LOL_IE_Msk);
    }
}

/**
  * @brief    Get PLL Lost Lock Interrupt Enable Status
  * @rmtoll   AHBMCR    LOL_IE    FL_CMU_IsEnabledIT_PLLLostLock
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_CMU_IsEnabledIT_PLLLostLock(void)
{
    if (CHIP_U01)
    {   /* Note:Function not implemented, fixed return 0. */
        return 0;
    }
    else
    {
        return (uint32_t)(READ_BIT(CMU->AHBMCR, CMU_AHBMCR_LOL_IE_Msk) == CMU_AHBMCR_LOL_IE_Msk);
    }
}

/**
  * @brief    Disable PLL Lost Lock Interrupt
  * @rmtoll   AHBMCR    LOL_IE    FL_CMU_DisableIT_PLLLostLock
  * @retval   None
  */
__STATIC_INLINE void FL_CMU_DisableIT_PLLLostLock(void)
{
    if (CHIP_U01)
    {   /* Note:Function not implemented. */
    }
    else
    {
        CLEAR_BIT(CMU->AHBMCR, CMU_AHBMCR_LOL_IE_Msk);
    }
}

/**
  * @brief    Set AHB Master Priority
  * @rmtoll   AHBMCR    MPRIL    FL_CMU_SetAHBMasterPriority
  * @param    priority This parameter can be one of the following values:
  *           @arg @ref FL_CMU_AHB_MASTER_PRIORITY_DMA
  *           @arg @ref FL_CMU_AHB_MASTER_PRIORITY_CPU
  * @retval   None
  */
__STATIC_INLINE void FL_CMU_SetAHBMasterPriority(uint32_t priority)
{
    MODIFY_REG(CMU->AHBMCR, CMU_AHBMCR_MPRIL_Msk, priority);
}

/**
  * @brief    Get AHB Master Priority Setting
  * @rmtoll   AHBMCR    MPRIL    FL_CMU_GetAHBMasterPriority
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_CMU_AHB_MASTER_PRIORITY_DMA
  *           @arg @ref FL_CMU_AHB_MASTER_PRIORITY_CPU
  */
__STATIC_INLINE uint32_t FL_CMU_GetAHBMasterPriority(void)
{
    return (uint32_t)(READ_BIT(CMU->AHBMCR, CMU_AHBMCR_MPRIL_Msk));
}

/**
  * @brief    Set CANFD1 Clock Source
  * @rmtoll   CFDCR    CANFD1CKS    FL_CMU_SetCANFD1ClockSource
  * @param    clock This parameter can be one of the following values:
  *           @arg @ref FL_CMU_CANFD1_CLK_SOURCE_APBCLK
  *           @arg @ref FL_CMU_CANFD1_CLK_SOURCE_XTHF
  *           @arg @ref FL_CMU_CANFD1_CLK_SOURCE_PLL
  *           @arg @ref FL_CMU_CANFD1_CLK_SOURCE_RCHF
  * @retval   None
  */
__STATIC_INLINE void FL_CMU_SetCANFD1ClockSource(uint32_t clock)
{
    MODIFY_REG(CMU->CFDCR, CMU_CFDCR_CANFD1CKS_Msk, clock);
}

/**
  * @brief    Get CANFD1 Clock Source Setting
  * @rmtoll   CFDCR    CANFD1CKS    FL_CMU_GetCANFD1ClockSource
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_CMU_CANFD1_CLK_SOURCE_APBCLK
  *           @arg @ref FL_CMU_CANFD1_CLK_SOURCE_XTHF
  *           @arg @ref FL_CMU_CANFD1_CLK_SOURCE_PLL
  *           @arg @ref FL_CMU_CANFD1_CLK_SOURCE_RCHF
  */
__STATIC_INLINE uint32_t FL_CMU_GetCANFD1ClockSource(void)
{
    return (uint32_t)(READ_BIT(CMU->CFDCR, CMU_CFDCR_CANFD1CKS_Msk));
}

/**
  * @brief    Set CANFD1 Clock Source RAM 
  * @rmtoll   CFDCR    CANFD1CKRS    FL_CMU_SetCANFD1ClockSourceRam
  * @param    clock This parameter can be one of the following values:
  *           @arg @ref FL_CMU_CANFD1_CLK_SOURCE_RAM_AHBCLK
  *           @arg @ref FL_CMU_CANFD1_CLK_SOURCE_RAM_PLL_VCO
  * @retval   None
  */
__STATIC_INLINE void FL_CMU_SetCANFD1ClockSourceRam(uint32_t clock)
{
    MODIFY_REG(CMU->CFDCR, CMU_CFDCR_CANFD1CKRS_Msk, clock);
}

/**
  * @brief    Set CANFD1 Clock Source RAM 
  * @rmtoll   CFDCR    CANFD1CKRS    FL_CMU_GetCANFD1ClockSourceRam
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_CMU_CANFD1_CLK_SOURCE_RAM_AHBCLK
  *           @arg @ref FL_CMU_CANFD1_CLK_SOURCE_RAM_PLL_VCO
  */
__STATIC_INLINE uint32_t FL_CMU_GetCANFD1ClockSourceRam(void)
{
    return (uint32_t)(READ_BIT(CMU->CFDCR, CMU_CFDCR_CANFD1CKRS_Msk));
}

/**
  * @brief    Set CANFD0 Clock Source
  * @rmtoll   CFDCR    CANFD0CKS    FL_CMU_SetCANFD0ClockSource
  * @param    clock This parameter can be one of the following values:
  *           @arg @ref FL_CMU_CANFD0_CLK_SOURCE_APBCLK
  *           @arg @ref FL_CMU_CANFD0_CLK_SOURCE_XTHF
  *           @arg @ref FL_CMU_CANFD0_CLK_SOURCE_PLL
  *           @arg @ref FL_CMU_CANFD0_CLK_SOURCE_RCHF
  * @retval   None
  */
__STATIC_INLINE void FL_CMU_SetCANFD0ClockSource(uint32_t clock)
{
    MODIFY_REG(CMU->CFDCR, CMU_CFDCR_CANFD0CKS_Msk, clock);
}

/**
  * @brief    Get CANFD0 Clock Source Setting
  * @rmtoll   CFDCR    CANFD0CKS    FL_CMU_GetCANFD0ClockSource
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_CMU_CANFD0_CLK_SOURCE_APBCLK
  *           @arg @ref FL_CMU_CANFD0_CLK_SOURCE_XTHF
  *           @arg @ref FL_CMU_CANFD0_CLK_SOURCE_PLL
  *           @arg @ref FL_CMU_CANFD0_CLK_SOURCE_RCHF
  */
__STATIC_INLINE uint32_t FL_CMU_GetCANFD0ClockSource(void)
{
    return (uint32_t)(READ_BIT(CMU->CFDCR, CMU_CFDCR_CANFD0CKS_Msk));
}

/**
  * @brief    Set CANFD0 Clock Source RAM 
  * @rmtoll   CFDCR    CANFD0CKRS    FL_CMU_SetCANFD0ClockSourceRam
  * @param    clock This parameter can be one of the following values:
  *           @arg @ref FL_CMU_CANFD0_CLK_SOURCE_RAM_AHBCLK
  *           @arg @ref FL_CMU_CANFD0_CLK_SOURCE_RAM_PLL_VCO
  * @retval   None
  */
__STATIC_INLINE void FL_CMU_SetCANFD0ClockSourceRam(uint32_t clock)
{
    MODIFY_REG(CMU->CFDCR, CMU_CFDCR_CANFD0CKRS_Msk, clock);
}

/**
  * @brief    Set CANFD0 Clock Source RAM 
  * @rmtoll   CFDCR    CANFD0CKRS    FL_CMU_GetCANFD0ClockSourceRam
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_CMU_CANFD0_CLK_SOURCE_RAM_AHBCLK
  *           @arg @ref FL_CMU_CANFD0_CLK_SOURCE_RAM_PLL_VCO
  */
__STATIC_INLINE uint32_t FL_CMU_GetCANFD0ClockSourceRam(void)
{
    return (uint32_t)(READ_BIT(CMU->CFDCR, CMU_CFDCR_CANFD0CKRS_Msk));
}

/**
  * @}
  */

/** @defgroup CMU_FL_EF_Init Initialization and de-initialization functions
  * @{
  */

FL_ErrorStatus FL_CMU_SetSystemClock(FL_SystemClock systemClock);

uint32_t FL_CMU_GetPLLClockFreq(void);
uint32_t FL_CMU_GetRCHFClockFreq(void);
uint32_t FL_CMU_GetSystemClockFreq(void);
uint32_t FL_CMU_GetAPB2ClockFreq(void);
uint32_t FL_CMU_GetAPB1ClockFreq(void);
uint32_t FL_CMU_GetAHBClockFreq(void);

/**
  * @}
  */


/**
  * @}
  */

#ifdef __cplusplus
}
#endif

#endif /* __FM33FG0XXA_FL_CMU_H*/

/*************************Py_Code_Generator Version: 0.1-0.14-0.1 @ 2023-07-07*************************/
/*************************(C) COPYRIGHT Fudan Microelectronics **** END OF FILE*************************/
