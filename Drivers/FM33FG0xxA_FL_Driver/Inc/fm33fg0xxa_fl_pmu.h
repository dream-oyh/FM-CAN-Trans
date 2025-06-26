 /**   
  *******************************************************************************************************
  * @file    fm33fg0xxa_fl_pmu.h
  * @author  FMSH Application Team
  * @brief   Head file of PMU FL Module 
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
#ifndef __FM33FG0XXA_FL_PMU_H
#define __FM33FG0XXA_FL_PMU_H

#ifdef __cplusplus
extern "C" {
#endif
/* Includes -------------------------------------------------------------------------------------------*/
#include "fm33fg0xxa_fl_def.h"
/** @addtogroup FM33FG0XXA_FL_Driver
  * @{
  */
/* Exported types -------------------------------------------------------------------------------------*/
/** @defgroup PMU_FL_ES_INIT PMU Exported Init structures
  * @{
  */

/**
  * @brief FL PMU Init Sturcture definition
  */
typedef struct
{
    /*! 低功耗模式配置 */
    uint32_t powerMode;

    /*! 睡眠模式配置 */
    uint32_t deepSleep;

    /*! 唤醒后的系统频率，仅对RCHF */
    uint32_t wakeupFrequency;

    /*! 额外唤醒延迟 */
    uint32_t wakeupDelay;

} FL_PMU_SleepInitTypeDef;
/**
  * @}
  */
/* Exported constants ---------------------------------------------------------------------------------*/
/** @defgroup PMU_FL_Exported_Constants PMU Exported Constants
  * @{
  */

#define    PMU_CR_WKFSEL_Pos                                      (10U)
#define    PMU_CR_WKFSEL_Msk                                      (0x3U << PMU_CR_WKFSEL_Pos)
#define    PMU_CR_WKFSEL                                          PMU_CR_WKFSEL_Msk

#define    PMU_CR_SLPDP_Pos                                       (9U)
#define    PMU_CR_SLPDP_Msk                                       (0x1U << PMU_CR_SLPDP_Pos)
#define    PMU_CR_SLPDP                                           PMU_CR_SLPDP_Msk

#define    PMU_CR_PMOD_Pos                                        (0U)
#define    PMU_CR_PMOD_Msk                                        (0x3U << PMU_CR_PMOD_Pos)
#define    PMU_CR_PMOD                                            PMU_CR_PMOD_Msk

#define    PMU_WKTR_STPCLR_Pos                                    (2U)
#define    PMU_WKTR_STPCLR_Msk                                    (0x1U << PMU_WKTR_STPCLR_Pos)
#define    PMU_WKTR_STPCLR                                        PMU_WKTR_STPCLR_Msk

#define    PMU_WKTR_T1A_Pos                                       (0U)
#define    PMU_WKTR_T1A_Msk                                       (0x3U << PMU_WKTR_T1A_Pos)
#define    PMU_WKTR_T1A                                           PMU_WKTR_T1A_Msk

#define    PMU_WKFR_UART2WKF_Pos                                  (31U)
#define    PMU_WKFR_UART2WKF_Msk                                  (0x1U << PMU_WKFR_UART2WKF_Pos)
#define    PMU_WKFR_UART2WKF                                      PMU_WKFR_UART2WKF_Msk

#define    PMU_WKFR_UART1WKF_Pos                                  (30U)
#define    PMU_WKFR_UART1WKF_Msk                                  (0x1U << PMU_WKFR_UART1WKF_Pos)
#define    PMU_WKFR_UART1WKF                                      PMU_WKFR_UART1WKF_Msk

#define    PMU_WKFR_UART0WKF_Pos                                  (29U)
#define    PMU_WKFR_UART0WKF_Msk                                  (0x1U << PMU_WKFR_UART0WKF_Pos)
#define    PMU_WKFR_UART0WKF                                      PMU_WKFR_UART0WKF_Msk

#define    PMU_WKFR_RTCWKF_Pos                                    (28U)
#define    PMU_WKFR_RTCWKF_Msk                                    (0x1U << PMU_WKFR_RTCWKF_Pos)
#define    PMU_WKFR_RTCWKF                                        PMU_WKFR_RTCWKF_Msk

#define    PMU_WKFR_SVDWKF_Pos                                    (27U)
#define    PMU_WKFR_SVDWKF_Msk                                    (0x1U << PMU_WKFR_SVDWKF_Pos)
#define    PMU_WKFR_SVDWKF                                        PMU_WKFR_SVDWKF_Msk

#define    PMU_WKFR_LFDETWKF_Pos                                  (26U)
#define    PMU_WKFR_LFDETWKF_Msk                                  (0x1U << PMU_WKFR_LFDETWKF_Pos)
#define    PMU_WKFR_LFDETWKF                                      PMU_WKFR_LFDETWKF_Msk

#define    PMU_WKFR_UART3WKF_Pos                                  (25U)
#define    PMU_WKFR_UART3WKF_Msk                                  (0x1U << PMU_WKFR_UART3WKF_Pos)
#define    PMU_WKFR_UART3WKF                                      PMU_WKFR_UART3WKF_Msk

#define    PMU_WKFR_IOWKF_Pos                                     (24U)
#define    PMU_WKFR_IOWKF_Msk                                     (0x1U << PMU_WKFR_IOWKF_Pos)
#define    PMU_WKFR_IOWKF                                         PMU_WKFR_IOWKF_Msk

#define    PMU_WKFR_I2CSMB1WKF_Pos                                (23U)
#define    PMU_WKFR_I2CSMB1WKF_Msk                                (0x1U << PMU_WKFR_I2CSMB1WKF_Pos)
#define    PMU_WKFR_I2CSMB1WKF                                    PMU_WKFR_I2CSMB1WKF_Msk

#define    PMU_WKFR_I2CSMB0WKF_Pos                                (22U)
#define    PMU_WKFR_I2CSMB0WKF_Msk                                (0x1U << PMU_WKFR_I2CSMB0WKF_Pos)
#define    PMU_WKFR_I2CSMB0WKF                                    PMU_WKFR_I2CSMB0WKF_Msk

#define    PMU_WKFR_LPU2WKF_Pos                                   (21U)
#define    PMU_WKFR_LPU2WKF_Msk                                   (0x1U << PMU_WKFR_LPU2WKF_Pos)
#define    PMU_WKFR_LPU2WKF                                       PMU_WKFR_LPU2WKF_Msk

#define    PMU_WKFR_LPU1WKF_Pos                                   (20U)
#define    PMU_WKFR_LPU1WKF_Msk                                   (0x1U << PMU_WKFR_LPU1WKF_Pos)
#define    PMU_WKFR_LPU1WKF                                       PMU_WKFR_LPU1WKF_Msk

#define    PMU_WKFR_LPU0WKF_Pos                                   (19U)
#define    PMU_WKFR_LPU0WKF_Msk                                   (0x1U << PMU_WKFR_LPU0WKF_Pos)
#define    PMU_WKFR_LPU0WKF                                       PMU_WKFR_LPU0WKF_Msk

#define    PMU_WKFR_FSCANWKF_Pos                                  (18U)
#define    PMU_WKFR_FSCANWKF_Msk                                  (0x1U << PMU_WKFR_FSCANWKF_Pos)
#define    PMU_WKFR_FSCANWKF                                      PMU_WKFR_FSCANWKF_Msk

#define    PMU_WKFR_WKP9F_Pos                                     (17U)
#define    PMU_WKFR_WKP9F_Msk                                     (0x1U << PMU_WKFR_WKP9F_Pos)
#define    PMU_WKFR_WKP9F                                         PMU_WKFR_WKP9F_Msk

#define    PMU_WKFR_COMPWKF_Pos                                   (16U)
#define    PMU_WKFR_COMPWKF_Msk                                   (0x1U << PMU_WKFR_COMPWKF_Pos)
#define    PMU_WKFR_COMPWKF                                       PMU_WKFR_COMPWKF_Msk

#define    PMU_WKFR_CANFD1WKF_Pos                                 (15U)
#define    PMU_WKFR_CANFD1WKF_Msk                                 (0x1U << PMU_WKFR_CANFD1WKF_Pos)
#define    PMU_WKFR_CANFD1WKF                                     PMU_WKFR_CANFD1WKF_Msk

#define    PMU_WKFR_CANFD0WKF_Pos                                 (14U)
#define    PMU_WKFR_CANFD0WKF_Msk                                 (0x1U << PMU_WKFR_CANFD0WKF_Pos)
#define    PMU_WKFR_CANFD0WKF                                     PMU_WKFR_CANFD0WKF_Msk

#define    PMU_WKFR_LPT32WKF_Pos                                  (13U)
#define    PMU_WKFR_LPT32WKF_Msk                                  (0x1U << PMU_WKFR_LPT32WKF_Pos)
#define    PMU_WKFR_LPT32WKF                                      PMU_WKFR_LPT32WKF_Msk

#define    PMU_WKFR_LPT16WKF_Pos                                  (12U)
#define    PMU_WKFR_LPT16WKF_Msk                                  (0x1U << PMU_WKFR_LPT16WKF_Pos)
#define    PMU_WKFR_LPT16WKF                                      PMU_WKFR_LPT16WKF_Msk

#define    PMU_WKFR_BST32WKF_Pos                                  (11U)
#define    PMU_WKFR_BST32WKF_Msk                                  (0x1U << PMU_WKFR_BST32WKF_Pos)
#define    PMU_WKFR_BST32WKF                                      PMU_WKFR_BST32WKF_Msk

#define    PMU_WKFR_BST16WKF_Pos                                  (10U)
#define    PMU_WKFR_BST16WKF_Msk                                  (0x1U << PMU_WKFR_BST16WKF_Pos)
#define    PMU_WKFR_BST16WKF                                      PMU_WKFR_BST16WKF_Msk

#define    PMU_WKFR_DBGWKF_Pos                                    (9U)
#define    PMU_WKFR_DBGWKF_Msk                                    (0x1U << PMU_WKFR_DBGWKF_Pos)
#define    PMU_WKFR_DBGWKF                                        PMU_WKFR_DBGWKF_Msk

#define    PMU_WKFR_WKPXF_Pos                                     (0U)
#define    PMU_WKFR_WKPXF_Msk                                     (0x1ffU << PMU_WKFR_WKPXF_Pos)
#define    PMU_WKFR_WKPXF                                         PMU_WKFR_WKPXF_Msk

#define    PMU_IER_SLPEIE_Pos                                     (1U)
#define    PMU_IER_SLPEIE_Msk                                     (0x1U << PMU_IER_SLPEIE_Pos)
#define    PMU_IER_SLPEIE                                         PMU_IER_SLPEIE_Msk

#define    PMU_ISR_SLPEIF_Pos                                     (1U)
#define    PMU_ISR_SLPEIF_Msk                                     (0x1U << PMU_ISR_SLPEIF_Pos)
#define    PMU_ISR_SLPEIF                                         PMU_ISR_SLPEIF_Msk

#define    PMU_BUFCR_AVREFBUF_OUTEN_Pos                           (5U)
#define    PMU_BUFCR_AVREFBUF_OUTEN_Msk                           (0x1U << PMU_BUFCR_AVREFBUF_OUTEN_Pos)
#define    PMU_BUFCR_AVREFBUF_OUTEN                               PMU_BUFCR_AVREFBUF_OUTEN_Msk

#define    PMU_BUFCR_AVREFBUF_EN_Pos                              (4U)
#define    PMU_BUFCR_AVREFBUF_EN_Msk                              (0x1U << PMU_BUFCR_AVREFBUF_EN_Pos)
#define    PMU_BUFCR_AVREFBUF_EN                                  PMU_BUFCR_AVREFBUF_EN_Msk

#define    PMU_BUFCR_VPTATBUFFER_OUTEN_Pos                        (3U)
#define    PMU_BUFCR_VPTATBUFFER_OUTEN_Msk                        (0x1U << PMU_BUFCR_VPTATBUFFER_OUTEN_Pos)
#define    PMU_BUFCR_VPTATBUFFER_OUTEN                            PMU_BUFCR_VPTATBUFFER_OUTEN_Msk

#define    PMU_BUFCR_VPTATBUFFER_EN_Pos                           (2U)
#define    PMU_BUFCR_VPTATBUFFER_EN_Msk                           (0x1U << PMU_BUFCR_VPTATBUFFER_EN_Pos)
#define    PMU_BUFCR_VPTATBUFFER_EN                               PMU_BUFCR_VPTATBUFFER_EN_Msk

#define    PMU_PTAT_CR_PTAT_EN_Pos                                (0U)
#define    PMU_PTAT_CR_PTAT_EN_Msk                                (0x1U << PMU_PTAT_CR_PTAT_EN_Pos)
#define    PMU_PTAT_CR_PTAT_EN                                    PMU_PTAT_CR_PTAT_EN_Msk

#define    PMU_CFDCK_CR_CFD1WKIE_Pos                              (9U)
#define    PMU_CFDCK_CR_CFD1WKIE_Msk                              (0x1U << PMU_CFDCK_CR_CFD1WKIE_Pos)
#define    PMU_CFDCK_CR_CFD1WKIE                                  PMU_CFDCK_CR_CFD1WKIE_Msk

#define    PMU_CFDCK_CR_CFD0WKIE_Pos                              (8U)
#define    PMU_CFDCK_CR_CFD0WKIE_Msk                              (0x1U << PMU_CFDCK_CR_CFD0WKIE_Pos)
#define    PMU_CFDCK_CR_CFD0WKIE                                  PMU_CFDCK_CR_CFD0WKIE_Msk

#define    PMU_CFDCK_CR_CFD1WKEN_Pos                              (1U)
#define    PMU_CFDCK_CR_CFD1WKEN_Msk                              (0x1U << PMU_CFDCK_CR_CFD1WKEN_Pos)
#define    PMU_CFDCK_CR_CFD1WKEN                                  PMU_CFDCK_CR_CFD1WKEN_Msk

#define    PMU_CFDCK_CR_CFD0WKEN_Pos                              (0U)
#define    PMU_CFDCK_CR_CFD0WKEN_Msk                              (0x1U << PMU_CFDCK_CR_CFD0WKEN_Pos)
#define    PMU_CFDCK_CR_CFD0WKEN                                  PMU_CFDCK_CR_CFD0WKEN_Msk

#define    PMU_CFDCK_SR_CFD1WKIF_Pos                              (1U)
#define    PMU_CFDCK_SR_CFD1WKIF_Msk                              (0x1U << PMU_CFDCK_SR_CFD1WKIF_Pos)
#define    PMU_CFDCK_SR_CFD1WKIF                                  PMU_CFDCK_SR_CFD1WKIF_Msk

#define    PMU_CFDCK_SR_CFD0WKIF_Pos                              (0U)
#define    PMU_CFDCK_SR_CFD0WKIF_Msk                              (0x1U << PMU_CFDCK_SR_CFD0WKIF_Pos)
#define    PMU_CFDCK_SR_CFD0WKIF                                  PMU_CFDCK_SR_CFD0WKIF_Msk



#define    FL_PMU_WAKEUP0_PIN                                     (0x1U << 0U)
#define    FL_PMU_WAKEUP1_PIN                                     (0x1U << 1U)
#define    FL_PMU_WAKEUP2_PIN                                     (0x1U << 2U)
#define    FL_PMU_WAKEUP3_PIN                                     (0x1U << 3U)
#define    FL_PMU_WAKEUP4_PIN                                     (0x1U << 4U)
#define    FL_PMU_WAKEUP5_PIN                                     (0x1U << 5U)
#define    FL_PMU_WAKEUP6_PIN                                     (0x1U << 6U)
#define    FL_PMU_WAKEUP7_PIN                                     (0x1U << 7U)
#define    FL_PMU_WAKEUP8_PIN                                     (0x1U << 8U)
#define    FL_PMU_WAKEUP9_PIN                                     (0x1U << 17U)



#define    FL_PMU_RCHF_WAKEUP_FREQ_8MHZ                           (0x0U << PMU_CR_WKFSEL_Pos)
#define    FL_PMU_RCHF_WAKEUP_FREQ_16MHZ                          (0x1U << PMU_CR_WKFSEL_Pos)
#define    FL_PMU_RCHF_WAKEUP_FREQ_24MHZ                          (0x2U << PMU_CR_WKFSEL_Pos)


#define    FL_PMU_SLEEP_MODE_DEEP                                 (0x1U << PMU_CR_SLPDP_Pos)
#define    FL_PMU_SLEEP_MODE_NORMAL                               (0x0U << PMU_CR_SLPDP_Pos)


#define    FL_PMU_POWER_MODE_ACTIVE                               (0x0U << PMU_CR_PMOD_Pos)
#define    FL_PMU_POWER_MODE_SLEEP_OR_DEEPSLEEP                   (0x2U << PMU_CR_PMOD_Pos)


#define    FL_PMU_FLASH_STOP_CLEAR_MODE_SYNCHRONOUS               (0x0U << PMU_WKTR_STPCLR_Pos)
#define    FL_PMU_FLASH_STOP_CLEAR_MODE_ASYNCHRONOUS              (0x1U << PMU_WKTR_STPCLR_Pos)


#define    FL_PMU_WAKEUP_DELAY_0US                                (0x0U << PMU_WKTR_T1A_Pos)
#define    FL_PMU_WAKEUP_DELAY_2US                                (0x1U << PMU_WKTR_T1A_Pos)
#define    FL_PMU_WAKEUP_DELAY_4US                                (0x2U << PMU_WKTR_T1A_Pos)
#define    FL_PMU_WAKEUP_DELAY_8US                                (0x3U << PMU_WKTR_T1A_Pos)


/**
  * @}
  */
/* Exported functions ---------------------------------------------------------------------------------*/
/** @defgroup PMU_FL_Exported_Functions PMU Exported Functions
  * @{
  */

/**
  * @brief    Set RCHF Frequency After Wakeup
  * @rmtoll   CR    WKFSEL    FL_PMU_SetRCHFWakeupFrequency
  * @param    PMUx PMU instance
  * @param    Freq This parameter can be one of the following values:
  *           @arg @ref FL_PMU_RCHF_WAKEUP_FREQ_8MHZ
  *           @arg @ref FL_PMU_RCHF_WAKEUP_FREQ_16MHZ
  *           @arg @ref FL_PMU_RCHF_WAKEUP_FREQ_24MHZ
  * @retval   None
  */
__STATIC_INLINE void FL_PMU_SetRCHFWakeupFrequency(PMU_Type* PMUx, uint32_t Freq)
{
    MODIFY_REG(PMUx->CR, PMU_CR_WKFSEL_Msk, Freq);
}

/**
  * @brief    Get RCHF Frequency After Wakeup Setting
  * @rmtoll   CR    WKFSEL    FL_PMU_GetRCHFWakeupFrequency
  * @param    PMUx PMU instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_PMU_RCHF_WAKEUP_FREQ_8MHZ
  *           @arg @ref FL_PMU_RCHF_WAKEUP_FREQ_16MHZ
  *           @arg @ref FL_PMU_RCHF_WAKEUP_FREQ_24MHZ
  */
__STATIC_INLINE uint32_t FL_PMU_GetRCHFWakeupFrequency(PMU_Type* PMUx)
{
    return (uint32_t)(READ_BIT(PMUx->CR, PMU_CR_WKFSEL_Msk));
}

/**
  * @brief    Set Sleep Mode
  * @rmtoll   CR    SLPDP    FL_PMU_SetSleepMode
  * @param    PMUx PMU instance
  * @param    mode This parameter can be one of the following values:
  *           @arg @ref FL_PMU_SLEEP_MODE_DEEP
  *           @arg @ref FL_PMU_SLEEP_MODE_NORMAL
  * @retval   None
  */
__STATIC_INLINE void FL_PMU_SetSleepMode(PMU_Type* PMUx, uint32_t mode)
{
    MODIFY_REG(PMUx->CR, PMU_CR_SLPDP_Msk, mode);
}

/**
  * @brief    Get Sleep Mode Setting
  * @rmtoll   CR    SLPDP    FL_PMU_GetSleepMode
  * @param    PMUx PMU instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_PMU_SLEEP_MODE_DEEP
  *           @arg @ref FL_PMU_SLEEP_MODE_NORMAL
  */
__STATIC_INLINE uint32_t FL_PMU_GetSleepMode(PMU_Type* PMUx)
{
    return (uint32_t)(READ_BIT(PMUx->CR, PMU_CR_SLPDP_Msk));
}

/**
  * @brief    Set Low Power Mode
  * @rmtoll   CR    PMOD    FL_PMU_SetLowPowerMode
  * @param    PMUx PMU instance
  * @param    mode This parameter can be one of the following values:
  *           @arg @ref FL_PMU_POWER_MODE_ACTIVE
  *           @arg @ref FL_PMU_POWER_MODE_SLEEP_OR_DEEPSLEEP
  * @retval   None
  */
__STATIC_INLINE void FL_PMU_SetLowPowerMode(PMU_Type* PMUx, uint32_t mode)
{
    MODIFY_REG(PMUx->CR, PMU_CR_PMOD_Msk, mode);
}

/**
  * @brief    Get Low Power Mode Setting
  * @rmtoll   CR    PMOD    FL_PMU_GetLowPowerMode
  * @param    PMUx PMU instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_PMU_POWER_MODE_ACTIVE
  *           @arg @ref FL_PMU_POWER_MODE_SLEEP_OR_DEEPSLEEP
  */
__STATIC_INLINE uint32_t FL_PMU_GetLowPowerMode(PMU_Type* PMUx)
{
    return (uint32_t)(READ_BIT(PMUx->CR, PMU_CR_PMOD_Msk));
}

/**
  * @brief    Set Flash Stop Signal Clear Way
  * @rmtoll   WKTR    STPCLR    FL_PMU_SetFlashStopSignalClearMode
  * @param    PMUx PMU instance
  * @param    config This parameter can be one of the following values:
  *           @arg @ref FL_PMU_FLASH_STOP_CLEAR_MODE_SYNCHRONOUS
  *           @arg @ref FL_PMU_FLASH_STOP_CLEAR_MODE_ASYNCHRONOUS
  * @retval   None
  */
__STATIC_INLINE void FL_PMU_SetFlashStopSignalClearMode(PMU_Type* PMUx, uint32_t config)
{
    MODIFY_REG(PMUx->WKTR, PMU_WKTR_STPCLR_Msk, config);
}

/**
  * @brief    Get Flash Stop Signal Clear Way Setting
  * @rmtoll   WKTR    STPCLR    FL_PMU_GetFlashStopSignalClearMode
  * @param    PMUx PMU instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_PMU_FLASH_STOP_CLEAR_MODE_SYNCHRONOUS
  *           @arg @ref FL_PMU_FLASH_STOP_CLEAR_MODE_ASYNCHRONOUS
  */
__STATIC_INLINE uint32_t FL_PMU_GetFlashStopSignalClearMode(PMU_Type* PMUx)
{
    return (uint32_t)(READ_BIT(PMUx->WKTR, PMU_WKTR_STPCLR_Msk));
}

/**
  * @brief    Set Extra Wakeup Delay Under Sleep/DeepSleep Mode
  * @rmtoll   WKTR    T1A    FL_PMU_SetWakeupDelay
  * @param    PMUx PMU instance
  * @param    time This parameter can be one of the following values:
  *           @arg @ref FL_PMU_WAKEUP_DELAY_0US
  *           @arg @ref FL_PMU_WAKEUP_DELAY_2US
  *           @arg @ref FL_PMU_WAKEUP_DELAY_4US
  *           @arg @ref FL_PMU_WAKEUP_DELAY_8US
  * @retval   None
  */
__STATIC_INLINE void FL_PMU_SetWakeupDelay(PMU_Type* PMUx, uint32_t time)
{
    MODIFY_REG(PMUx->WKTR, PMU_WKTR_T1A_Msk, time);
}

/**
  * @brief    Get Extra Wakeup Delay Under Sleep/DeepSleep Mode Setting
  * @rmtoll   WKTR    T1A    FL_PMU_GetWakeupDelay
  * @param    PMUx PMU instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_PMU_WAKEUP_DELAY_0US
  *           @arg @ref FL_PMU_WAKEUP_DELAY_2US
  *           @arg @ref FL_PMU_WAKEUP_DELAY_4US
  *           @arg @ref FL_PMU_WAKEUP_DELAY_8US
  */
__STATIC_INLINE uint32_t FL_PMU_GetWakeupDelay(PMU_Type* PMUx)
{
    return (uint32_t)(READ_BIT(PMUx->WKTR, PMU_WKTR_T1A_Msk));
}

/**
  * @brief    Get UART2 interrupt wakeup flag
  * @rmtoll   WKFR    UART2WKF    FL_PMU_IsActiveFlag_WakeupUART2
  * @param    PMUx PMU instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_PMU_IsActiveFlag_WakeupUART2(PMU_Type* PMUx)
{
    return (uint32_t)(READ_BIT(PMUx->WKFR, PMU_WKFR_UART2WKF_Msk) == (PMU_WKFR_UART2WKF_Msk));
}

/**
  * @brief    Get UART1 interrupt wakeup flag
  * @rmtoll   WKFR    UART1WKF    FL_PMU_IsActiveFlag_WakeupUART1
  * @param    PMUx PMU instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_PMU_IsActiveFlag_WakeupUART1(PMU_Type* PMUx)
{
    return (uint32_t)(READ_BIT(PMUx->WKFR, PMU_WKFR_UART1WKF_Msk) == (PMU_WKFR_UART1WKF_Msk));
}

/**
  * @brief    Get UART0 interrupt wakeup flag
  * @rmtoll   WKFR    UART0WKF    FL_PMU_IsActiveFlag_WakeupUART0
  * @param    PMUx PMU instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_PMU_IsActiveFlag_WakeupUART0(PMU_Type* PMUx)
{
    return (uint32_t)(READ_BIT(PMUx->WKFR, PMU_WKFR_UART0WKF_Msk) == (PMU_WKFR_UART0WKF_Msk));
}

/**
  * @brief    Get RTC interrupt wakeup flag
  * @rmtoll   WKFR    RTCWKF    FL_PMU_IsActiveFlag_WakeupRTC
  * @param    PMUx PMU instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_PMU_IsActiveFlag_WakeupRTC(PMU_Type* PMUx)
{
    return (uint32_t)(READ_BIT(PMUx->WKFR, PMU_WKFR_RTCWKF_Msk) == (PMU_WKFR_RTCWKF_Msk));
}

/**
  * @brief    Get SVD interrupt wakeup flag
  * @rmtoll   WKFR    SVDWKF    FL_PMU_IsActiveFlag_WakeupSVD
  * @param    PMUx PMU instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_PMU_IsActiveFlag_WakeupSVD(PMU_Type* PMUx)
{
    return (uint32_t)(READ_BIT(PMUx->WKFR, PMU_WKFR_SVDWKF_Msk) == (PMU_WKFR_SVDWKF_Msk));
}

/**
  * @brief    Get LFDET interrupt wakeup flag
  * @rmtoll   WKFR    LFDETWKF    FL_PMU_IsActiveFlag_WakeupLFDET
  * @param    PMUx PMU instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_PMU_IsActiveFlag_WakeupLFDET(PMU_Type* PMUx)
{
    return (uint32_t)(READ_BIT(PMUx->WKFR, PMU_WKFR_LFDETWKF_Msk) == (PMU_WKFR_LFDETWKF_Msk));
}

/**
  * @brief    Get UART3 interrupt wakeup flag
  * @rmtoll   WKFR    UART3WKF    FL_PMU_IsActiveFlag_WakeupUART4
  * @param    PMUx PMU instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_PMU_IsActiveFlag_WakeupUART4(PMU_Type* PMUx)
{
    return (uint32_t)(READ_BIT(PMUx->WKFR, PMU_WKFR_UART3WKF_Msk) == (PMU_WKFR_UART3WKF_Msk));
}

/**
  * @brief    Get IO interrupt wakeup flag
  * @rmtoll   WKFR    IOWKF    FL_PMU_IsActiveFlag_WakeupEXTI
  * @param    PMUx PMU instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_PMU_IsActiveFlag_WakeupEXTI(PMU_Type* PMUx)
{
    return (uint32_t)(READ_BIT(PMUx->WKFR, PMU_WKFR_IOWKF_Msk) == (PMU_WKFR_IOWKF_Msk));
}

/**
  * @brief    Get I2CSMB1 interrupt wakeup flag
  * @rmtoll   WKFR    I2CSMB1WKF    FL_PMU_IsActiveFlag_WakeupI2C1SMB
  * @param    PMUx PMU instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_PMU_IsActiveFlag_WakeupI2C1SMB(PMU_Type* PMUx)
{
    return (uint32_t)(READ_BIT(PMUx->WKFR, PMU_WKFR_I2CSMB1WKF_Msk) == (PMU_WKFR_I2CSMB1WKF_Msk));
}

/**
  * @brief    Get I2CSMB0 interrupt wakeup flag
  * @rmtoll   WKFR    I2CSMB0WKF    FL_PMU_IsActiveFlag_WakeupI2C0SMB
  * @param    PMUx PMU instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_PMU_IsActiveFlag_WakeupI2C0SMB(PMU_Type* PMUx)
{
    return (uint32_t)(READ_BIT(PMUx->WKFR, PMU_WKFR_I2CSMB0WKF_Msk) == (PMU_WKFR_I2CSMB0WKF_Msk));
}

/**
  * @brief    Get LPUART2 interrupt wakeup flag
  * @rmtoll   WKFR    LPU2WKF    FL_PMU_IsActiveFlag_WakeupLPUART2
  * @param    PMUx PMU instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_PMU_IsActiveFlag_WakeupLPUART2(PMU_Type* PMUx)
{
    return (uint32_t)(READ_BIT(PMUx->WKFR, PMU_WKFR_LPU2WKF_Msk) == (PMU_WKFR_LPU2WKF_Msk));
}

/**
  * @brief    Get LPUART1 interrupt wakeup flag
  * @rmtoll   WKFR    LPU1WKF    FL_PMU_IsActiveFlag_WakeupLPUART1
  * @param    PMUx PMU instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_PMU_IsActiveFlag_WakeupLPUART1(PMU_Type* PMUx)
{
    return (uint32_t)(READ_BIT(PMUx->WKFR, PMU_WKFR_LPU1WKF_Msk) == (PMU_WKFR_LPU1WKF_Msk));
}

/**
  * @brief    Get LPUART0 interrupt wakeup flag
  * @rmtoll   WKFR    LPU0WKF    FL_PMU_IsActiveFlag_WakeupLPUART0
  * @param    PMUx PMU instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_PMU_IsActiveFlag_WakeupLPUART0(PMU_Type* PMUx)
{
    return (uint32_t)(READ_BIT(PMUx->WKFR, PMU_WKFR_LPU0WKF_Msk) == (PMU_WKFR_LPU0WKF_Msk));
}

/**
  * @brief    Get FSCAN interrupt wakeup flag
  * @rmtoll   WKFR    FSCANWKF    FL_PMU_IsActiveFlag_WakeupFSCAN
  * @param    PMUx PMU instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_PMU_IsActiveFlag_WakeupFSCAN(PMU_Type* PMUx)
{
    return (uint32_t)(READ_BIT(PMUx->WKFR, PMU_WKFR_FSCANWKF_Msk) == (PMU_WKFR_FSCANWKF_Msk));
}

/**
  * @brief    Get WKP9F pin interrrupt wakeup flag
  * @rmtoll   WKFR    WKP9F    FL_PMU_IsActiveFlag_Wakeup9PIN
  * @param    PMUx PMU instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_PMU_IsActiveFlag_Wakeup9PIN(PMU_Type* PMUx)
{
    return (uint32_t)(READ_BIT(PMUx->WKFR, PMU_WKFR_WKP9F_Msk) == (PMU_WKFR_WKP9F_Msk));
}

/**
  * @brief    Clear WKP9F pin interrrupt wakeup flag
  * @rmtoll   WKFR    WKP9F    FL_PMU_ClearFlag_Wakeup9PIN
  * @param    PMUx PMU instance
  * @retval   None
  */
__STATIC_INLINE void FL_PMU_ClearFlag_Wakeup9PIN(PMU_Type* PMUx)
{
    WRITE_REG(PMUx->WKFR, PMU_WKFR_DBGWKF_Msk);
}

/**
  * @brief    Get COMP interrrupt wakeup flag
  * @rmtoll   WKFR    COMPWKF    FL_PMU_IsActiveFlag_WakeupCOMP
  * @param    PMUx PMU instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_PMU_IsActiveFlag_WakeupCOMP(PMU_Type* PMUx)
{
    return (uint32_t)(READ_BIT(PMUx->WKFR, PMU_WKFR_COMPWKF_Msk) == (PMU_WKFR_COMPWKF_Msk));
}

/**
  * @brief    Get CANFD1 interrupt wakeup flag
  * @rmtoll   WKFR    CANFD1WKF    FL_PMU_IsActiveFlag_WakeupCANFD1
  * @param    PMUx PMU instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_PMU_IsActiveFlag_WakeupCANFD1(PMU_Type* PMUx)
{
    return (uint32_t)(READ_BIT(PMUx->WKFR, PMU_WKFR_CANFD1WKF_Msk) == (PMU_WKFR_CANFD1WKF_Msk));
}

/**
  * @brief    Get CANFD0 interrupt wakeup flag
  * @rmtoll   WKFR    CANFD0WKF    FL_PMU_IsActiveFlag_WakeupCANFD0
  * @param    PMUx PMU instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_PMU_IsActiveFlag_WakeupCANFD0(PMU_Type* PMUx)
{
    return (uint32_t)(READ_BIT(PMUx->WKFR, PMU_WKFR_CANFD0WKF_Msk) == (PMU_WKFR_CANFD0WKF_Msk));
}

/**
  * @brief    Get LPTIM32 interrupt wakeup flag
  * @rmtoll   WKFR    LPT32WKF    FL_PMU_IsActiveFlag_WakeupLPTIM32
  * @param    PMUx PMU instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_PMU_IsActiveFlag_WakeupLPTIM32(PMU_Type* PMUx)
{
    return (uint32_t)(READ_BIT(PMUx->WKFR, PMU_WKFR_LPT32WKF_Msk) == (PMU_WKFR_LPT32WKF_Msk));
}

/**
  * @brief    Get LPTIM16 interrupt wakeup flag
  * @rmtoll   WKFR    LPT16WKF    FL_PMU_IsActiveFlag_WakeupLPTIM16
  * @param    PMUx PMU instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_PMU_IsActiveFlag_WakeupLPTIM16(PMU_Type* PMUx)
{
    return (uint32_t)(READ_BIT(PMUx->WKFR, PMU_WKFR_LPT16WKF_Msk) == (PMU_WKFR_LPT16WKF_Msk));
}

/**
  * @brief    Get BSTIM32 interrupt wakeup flag
  * @rmtoll   WKFR    BST32WKF    FL_PMU_IsActiveFlag_WakeupBSTIM32
  * @param    PMUx PMU instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_PMU_IsActiveFlag_WakeupBSTIM32(PMU_Type* PMUx)
{
    return (uint32_t)(READ_BIT(PMUx->WKFR, PMU_WKFR_BST32WKF_Msk) == (PMU_WKFR_BST32WKF_Msk));
}

/**
  * @brief    Get BSTIM16 interrupt wakeup flag
  * @rmtoll   WKFR    BST16WKF    FL_PMU_IsActiveFlag_WakeupBSTIM16
  * @param    PMUx PMU instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_PMU_IsActiveFlag_WakeupBSTIM16(PMU_Type* PMUx)
{
    return (uint32_t)(READ_BIT(PMUx->WKFR, PMU_WKFR_BST16WKF_Msk) == (PMU_WKFR_BST16WKF_Msk));
}

/**
  * @brief    Get CPU Debugger wakeup flag
  * @rmtoll   WKFR    DBGWKF    FL_PMU_IsActiveFlag_WakeupDBG
  * @param    PMUx PMU instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_PMU_IsActiveFlag_WakeupDBG(PMU_Type* PMUx)
{
    return (uint32_t)(READ_BIT(PMUx->WKFR, PMU_WKFR_DBGWKF_Msk) == (PMU_WKFR_DBGWKF_Msk));
}

/**
  * @brief    Clear CPU Debugger wakeup flag
  * @rmtoll   WKFR    DBGWKF    FL_PMU_ClearFlag_WakeupDBG
  * @param    PMUx PMU instance
  * @retval   None
  */
__STATIC_INLINE void FL_PMU_ClearFlag_WakeupDBG(PMU_Type* PMUx)
{
    WRITE_REG(PMUx->WKFR, PMU_WKFR_DBGWKF_Msk);
}

/**
  * @brief    Get pinx wakeup flag
  * @rmtoll   WKFR    WKPXF    FL_PMU_IsActiveFlag_WakeupPIN
  * @param    PMUx PMU instance
  * @param    Pin This parameter can be one of the following values:
  *           @arg @ref FL_PMU_WAKEUP0_PIN
  *           @arg @ref FL_PMU_WAKEUP1_PIN
  *           @arg @ref FL_PMU_WAKEUP2_PIN
  *           @arg @ref FL_PMU_WAKEUP3_PIN
  *           @arg @ref FL_PMU_WAKEUP4_PIN
  *           @arg @ref FL_PMU_WAKEUP5_PIN
  *           @arg @ref FL_PMU_WAKEUP6_PIN
  *           @arg @ref FL_PMU_WAKEUP7_PIN
  *           @arg @ref FL_PMU_WAKEUP8_PIN
  *           @arg @ref FL_PMU_WAKEUP9_PIN
  * @retval   Returned value can be one of the following values:
  */
__STATIC_INLINE uint32_t FL_PMU_IsActiveFlag_WakeupPIN(PMU_Type* PMUx, uint32_t Pin)
{
    return (uint32_t)(READ_BIT(PMUx->WKFR, ((Pin & 0x201ffU) << 0x0U)) == ((Pin & 0x201ffU) << 0x0U));
}

/**
  * @brief    Clear pinx wakeup flag
  * @rmtoll   WKFR    WKPXF    FL_PMU_ClearFlag_WakeupPIN
  * @param    PMUx PMU instance
  * @param    Pin This parameter can be one of the following values:
  *           @arg @ref FL_PMU_WAKEUP0_PIN
  *           @arg @ref FL_PMU_WAKEUP1_PIN
  *           @arg @ref FL_PMU_WAKEUP2_PIN
  *           @arg @ref FL_PMU_WAKEUP3_PIN
  *           @arg @ref FL_PMU_WAKEUP4_PIN
  *           @arg @ref FL_PMU_WAKEUP5_PIN
  *           @arg @ref FL_PMU_WAKEUP6_PIN
  *           @arg @ref FL_PMU_WAKEUP7_PIN
  *           @arg @ref FL_PMU_WAKEUP8_PIN
  *           @arg @ref FL_PMU_WAKEUP9_PIN
  * @retval   None
  */
__STATIC_INLINE void FL_PMU_ClearFlag_WakeupPIN(PMU_Type* PMUx, uint32_t Pin)
{
    if (FL_PMU_WAKEUP9_PIN == Pin)
    {
        WRITE_REG(PMUx->WKFR, PMU_WKFR_DBGWKF_Msk);
    }
    else
    {
        WRITE_REG(PMUx->WKFR, ((Pin & 0x1ffU) << 0x0U));
    }
}

/**
  * @brief    Sleep error interrupt enable
  * @rmtoll   IER    SLPEIE    FL_PMU_EnableIT_SleepError
  * @param    PMUx PMU instance
  * @retval   None
  */
__STATIC_INLINE void FL_PMU_EnableIT_SleepError(PMU_Type* PMUx)
{
    SET_BIT(PMUx->IER, PMU_IER_SLPEIE_Msk);
}

/**
  * @brief    Get sleep error interrupt enable status
  * @rmtoll   IER    SLPEIE    FL_PMU_IsEnabledIT_SleepError
  * @param    PMUx PMU instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_PMU_IsEnabledIT_SleepError(PMU_Type* PMUx)
{
    return (uint32_t)(READ_BIT(PMUx->IER, PMU_IER_SLPEIE_Msk) == PMU_IER_SLPEIE_Msk);
}

/**
  * @brief    Sleep error interrupt disable
  * @rmtoll   IER    SLPEIE    FL_PMU_DisableIT_SleepError
  * @param    PMUx PMU instance
  * @retval   None
  */
__STATIC_INLINE void FL_PMU_DisableIT_SleepError(PMU_Type* PMUx)
{
    CLEAR_BIT(PMUx->IER, PMU_IER_SLPEIE_Msk);
}

/**
  * @brief    Get SLEEP error interrupt flag
  * @rmtoll   ISR    SLPEIF    FL_PMU_IsActiveFlag_SleepError
  * @param    PMUx PMU instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_PMU_IsActiveFlag_SleepError(PMU_Type* PMUx)
{
    return (uint32_t)(READ_BIT(PMUx->ISR, PMU_ISR_SLPEIF_Msk) == (PMU_ISR_SLPEIF_Msk));
}

/**
  * @brief    Clear SLEEP error interrupt flag
  * @rmtoll   ISR    SLPEIF    FL_PMU_ClearFlag_SleepError
  * @param    PMUx PMU instance
  * @retval   None
  */
__STATIC_INLINE void FL_PMU_ClearFlag_SleepError(PMU_Type* PMUx)
{
    WRITE_REG(PMUx->ISR, PMU_ISR_SLPEIF_Msk);
}

/**
  * @brief    Enable AVREF Buffer Output
  * @rmtoll   BUFCR    AVREFBUF_OUTEN    FL_PMU_EnableAVREFBufferOutput
  * @param    PMUx PMU instance
  * @retval   None
  */
__STATIC_INLINE void FL_PMU_EnableAVREFBufferOutput(PMU_Type* PMUx)
{
    SET_BIT(PMUx->BUFCR, PMU_BUFCR_AVREFBUF_OUTEN_Msk);
}

/**
  * @brief    Get AVREF Buffer Output Enable Status
  * @rmtoll   BUFCR    AVREFBUF_OUTEN    FL_PMU_IsEnabledAVREFBufferOutput
  * @param    PMUx PMU instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_PMU_IsEnabledAVREFBufferOutput(PMU_Type* PMUx)
{
    return (uint32_t)(READ_BIT(PMUx->BUFCR, PMU_BUFCR_AVREFBUF_OUTEN_Msk) == PMU_BUFCR_AVREFBUF_OUTEN_Msk);
}

/**
  * @brief    Disable AVREF Buffer Output
  * @rmtoll   BUFCR    AVREFBUF_OUTEN    FL_PMU_DisableAVREFBufferOutput
  * @param    PMUx PMU instance
  * @retval   None
  */
__STATIC_INLINE void FL_PMU_DisableAVREFBufferOutput(PMU_Type* PMUx)
{
    CLEAR_BIT(PMUx->BUFCR, PMU_BUFCR_AVREFBUF_OUTEN_Msk);
}

/**
  * @brief    Enable AVREF Buffer
  * @rmtoll   BUFCR    AVREFBUF_EN    FL_PMU_EnableAVREFBuffer
  * @param    PMUx PMU instance
  * @retval   None
  */
__STATIC_INLINE void FL_PMU_EnableAVREFBuffer(PMU_Type* PMUx)
{
    SET_BIT(PMUx->BUFCR, PMU_BUFCR_AVREFBUF_EN_Msk);
}

/**
  * @brief    Get AVREF Buffer Enable Status
  * @rmtoll   BUFCR    AVREFBUF_EN    FL_PMU_IsEnabledAVREFBuffer
  * @param    PMUx PMU instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_PMU_IsEnabledAVREFBuffer(PMU_Type* PMUx)
{
    return (uint32_t)(READ_BIT(PMUx->BUFCR, PMU_BUFCR_AVREFBUF_EN_Msk) == PMU_BUFCR_AVREFBUF_EN_Msk);
}

/**
  * @brief    Disable AVREF Buffer 
  * @rmtoll   BUFCR    AVREFBUF_EN    FL_PMU_DisableAVREFBuffer
  * @param    PMUx PMU instance
  * @retval   None
  */
__STATIC_INLINE void FL_PMU_DisableAVREFBuffer(PMU_Type* PMUx)
{
    CLEAR_BIT(PMUx->BUFCR, PMU_BUFCR_AVREFBUF_EN_Msk);
}

/**
  * @brief    Enable VPTAT Buffer Output
  * @rmtoll   BUFCR    VPTATBUFFER_OUTEN    FL_PMU_EnableVPTATBufferOutput
  * @param    PMUx PMU instance
  * @retval   None
  */
__STATIC_INLINE void FL_PMU_EnableVPTATBufferOutput(PMU_Type* PMUx)
{
    SET_BIT(PMUx->BUFCR, PMU_BUFCR_VPTATBUFFER_OUTEN_Msk);
}

/**
  * @brief    Get VPTAT Buffer Output Enable Status
  * @rmtoll   BUFCR    VPTATBUFFER_OUTEN    FL_PMU_IsEnabledVPTATBufferOutput
  * @param    PMUx PMU instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_PMU_IsEnabledVPTATBufferOutput(PMU_Type* PMUx)
{
    return (uint32_t)(READ_BIT(PMUx->BUFCR, PMU_BUFCR_VPTATBUFFER_OUTEN_Msk) == PMU_BUFCR_VPTATBUFFER_OUTEN_Msk);
}

/**
  * @brief    Disable VPTAT Buffer Output
  * @rmtoll   BUFCR    VPTATBUFFER_OUTEN    FL_PMU_DisableVPTATBufferOutput
  * @param    PMUx PMU instance
  * @retval   None
  */
__STATIC_INLINE void FL_PMU_DisableVPTATBufferOutput(PMU_Type* PMUx)
{
    CLEAR_BIT(PMUx->BUFCR, PMU_BUFCR_VPTATBUFFER_OUTEN_Msk);
}

/**
  * @brief    Enable VPTAT Buffer
  * @rmtoll   BUFCR    VPTATBUFFER_EN    FL_PMU_EnableVPTATBuffer
  * @param    PMUx PMU instance
  * @retval   None
  */
__STATIC_INLINE void FL_PMU_EnableVPTATBuffer(PMU_Type* PMUx)
{
    SET_BIT(PMUx->BUFCR, PMU_BUFCR_VPTATBUFFER_EN_Msk);
}

/**
  * @brief    Get VPTAT Buffer Enable Status
  * @rmtoll   BUFCR    VPTATBUFFER_EN    FL_PMU_IsEnabledVPTATBuffer
  * @param    PMUx PMU instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_PMU_IsEnabledVPTATBuffer(PMU_Type* PMUx)
{
    return (uint32_t)(READ_BIT(PMUx->BUFCR, PMU_BUFCR_VPTATBUFFER_EN_Msk) == PMU_BUFCR_VPTATBUFFER_EN_Msk);
}

/**
  * @brief    Disable VPTAT Buffer 
  * @rmtoll   BUFCR    VPTATBUFFER_EN    FL_PMU_DisableVPTATBuffer
  * @param    PMUx PMU instance
  * @retval   None
  */
__STATIC_INLINE void FL_PMU_DisableVPTATBuffer(PMU_Type* PMUx)
{
    CLEAR_BIT(PMUx->BUFCR, PMU_BUFCR_VPTATBUFFER_EN_Msk);
}

/**
  * @brief    Enable Temperatue Sensor
  * @rmtoll   PTAT_CR    PTAT_EN    FL_PMU_EnableTemperatureSensor
  * @param    PMUx PMU instance
  * @retval   None
  */
__STATIC_INLINE void FL_PMU_EnableTemperatureSensor(PMU_Type* PMUx)
{
    SET_BIT(PMUx->PTAT_CR, PMU_PTAT_CR_PTAT_EN_Msk);
}

/**
  * @brief    Get Temperatue Sensor Enable Status
  * @rmtoll   PTAT_CR    PTAT_EN    FL_PMU_IsEnabledTemperatureSensor
  * @param    PMUx PMU instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_PMU_IsEnabledTemperatureSensor(PMU_Type* PMUx)
{
    return (uint32_t)(READ_BIT(PMUx->PTAT_CR, PMU_PTAT_CR_PTAT_EN_Msk) == PMU_PTAT_CR_PTAT_EN_Msk);
}

/**
  * @brief    Disable Temperatue Sensor
  * @rmtoll   PTAT_CR    PTAT_EN    FL_PMU_DisableTemperatureSensor
  * @param    PMUx PMU instance
  * @retval   None
  */
__STATIC_INLINE void FL_PMU_DisableTemperatureSensor(PMU_Type* PMUx)
{
    CLEAR_BIT(PMUx->PTAT_CR, PMU_PTAT_CR_PTAT_EN_Msk);
}

/**
  * @brief    CANFD1 Asycnchronous  WakeUp Interrupt Enable
  * @rmtoll   CFDCK_CR    CFD1WKIE    FL_PMU_EnableIT_CANFD1WakeUpInterrupt
  * @param    PMUx PMU instance
  * @retval   None
  */
__STATIC_INLINE void FL_PMU_EnableIT_CANFD1WakeUpInterrupt(PMU_Type* PMUx)
{
    SET_BIT(PMUx->CFDCK_CR, PMU_CFDCK_CR_CFD1WKIE_Msk);
}

/**
  * @brief    Get CANFD1 Asycnchronous WakeUp Interrupt Enable status
  * @rmtoll   CFDCK_CR    CFD1WKIE    FL_PMU_IsEnabledIT_CANFD1WakeUpInterrupt
  * @param    PMUx PMU instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_PMU_IsEnabledIT_CANFD1WakeUpInterrupt(PMU_Type* PMUx)
{
    return (uint32_t)(READ_BIT(PMUx->CFDCK_CR, PMU_CFDCK_CR_CFD1WKIE_Msk) == PMU_CFDCK_CR_CFD1WKIE_Msk);
}

/**
  * @brief    CANFD1 Asycnchronous WakeUp Interrupt Disable
  * @rmtoll   CFDCK_CR    CFD1WKIE    FL_PMU_DisableIT_CANFD1WakeUpInterrupt
  * @param    PMUx PMU instance
  * @retval   None
  */
__STATIC_INLINE void FL_PMU_DisableIT_CANFD1WakeUpInterrupt(PMU_Type* PMUx)
{
    CLEAR_BIT(PMUx->CFDCK_CR, PMU_CFDCK_CR_CFD1WKIE_Msk);
}

/**
  * @brief    CANFD0 Asycnchronous WakeUp Interrupt Enable
  * @rmtoll   CFDCK_CR    CFD0WKIE    FL_PMU_EnableIT_CANFD0WakeUpInterrupt
  * @param    PMUx PMU instance
  * @retval   None
  */
__STATIC_INLINE void FL_PMU_EnableIT_CANFD0WakeUpInterrupt(PMU_Type* PMUx)
{
    SET_BIT(PMUx->CFDCK_CR, PMU_CFDCK_CR_CFD0WKIE_Msk);
}

/**
  * @brief    Get CANFD0 Asycnchronous WakeUp Interrupt Enable status
  * @rmtoll   CFDCK_CR    CFD0WKIE    FL_PMU_IsEnabledIT_CANFD0WakeUpInterrupt
  * @param    PMUx PMU instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_PMU_IsEnabledIT_CANFD0WakeUpInterrupt(PMU_Type* PMUx)
{
    return (uint32_t)(READ_BIT(PMUx->CFDCK_CR, PMU_CFDCK_CR_CFD0WKIE_Msk) == PMU_CFDCK_CR_CFD0WKIE_Msk);
}

/**
  * @brief    CANFD0 Asycnchronous WakeUp Interrupt Disable
  * @rmtoll   CFDCK_CR    CFD0WKIE    FL_PMU_DisableIT_CANFD0WakeUpInterrupt
  * @param    PMUx PMU instance
  * @retval   None
  */
__STATIC_INLINE void FL_PMU_DisableIT_CANFD0WakeUpInterrupt(PMU_Type* PMUx)
{
    CLEAR_BIT(PMUx->CFDCK_CR, PMU_CFDCK_CR_CFD0WKIE_Msk);
}

/**
  * @brief    CANFD1 Asycnchronous WakeUp Enable
  * @rmtoll   CFDCK_CR    CFD1WKEN    FL_PMU_EnableCANFD1WakeUp
  * @param    PMUx PMU instance
  * @retval   None
  */
__STATIC_INLINE void FL_PMU_EnableCANFD1WakeUp(PMU_Type* PMUx)
{
    SET_BIT(PMUx->CFDCK_CR, PMU_CFDCK_CR_CFD1WKEN_Msk);
}

/**
  * @brief    Get CANFD1 Asycnchronous WakeUp Enable status
  * @rmtoll   CFDCK_CR    CFD1WKEN    FL_PMU_IsEnabledCANFD1WakeUp
  * @param    PMUx PMU instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_PMU_IsEnabledCANFD1WakeUp(PMU_Type* PMUx)
{
    return (uint32_t)(READ_BIT(PMUx->CFDCK_CR, PMU_CFDCK_CR_CFD1WKEN_Msk) == PMU_CFDCK_CR_CFD1WKEN_Msk);
}

/**
  * @brief    CANFD1 Asycnchronous WakeUp Disable
  * @rmtoll   CFDCK_CR    CFD1WKEN    FL_PMU_DisableCANFD1WakeUp
  * @param    PMUx PMU instance
  * @retval   None
  */
__STATIC_INLINE void FL_PMU_DisableCANFD1WakeUp(PMU_Type* PMUx)
{
    CLEAR_BIT(PMUx->CFDCK_CR, PMU_CFDCK_CR_CFD1WKEN_Msk);
}

/**
  * @brief    CANFD0 Asycnchronous WakeUp Enable
  * @rmtoll   CFDCK_CR    CFD0WKEN    FL_PMU_EnableCANFD0WakeUp
  * @param    PMUx PMU instance
  * @retval   None
  */
__STATIC_INLINE void FL_PMU_EnableCANFD0WakeUp(PMU_Type* PMUx)
{
    SET_BIT(PMUx->CFDCK_CR, PMU_CFDCK_CR_CFD0WKEN_Msk);
}

/**
  * @brief    Get CANFD0 Asycnchronous WakeUp Enable status
  * @rmtoll   CFDCK_CR    CFD0WKEN    FL_PMU_IsEnabledCANFD0WakeUp
  * @param    PMUx PMU instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_PMU_IsEnabledCANFD0WakeUp(PMU_Type* PMUx)
{
    return (uint32_t)(READ_BIT(PMUx->CFDCK_CR, PMU_CFDCK_CR_CFD0WKEN_Msk) == PMU_CFDCK_CR_CFD0WKEN_Msk);
}

/**
  * @brief    CANFD0 Asycnchronous WakeUp Disable
  * @rmtoll   CFDCK_CR    CFD0WKEN    FL_PMU_DisableCANFD0WakeUp
  * @param    PMUx PMU instance
  * @retval   None
  */
__STATIC_INLINE void FL_PMU_DisableCANFD0WakeUp(PMU_Type* PMUx)
{
    CLEAR_BIT(PMUx->CFDCK_CR, PMU_CFDCK_CR_CFD0WKEN_Msk);
}

/**
  * @brief    Get CANFD1 Asycnchronous WakeUp Interrupt Flag
  * @rmtoll   CFDCK_SR    CFD1WKIF    FL_PMU_IsActiveFlag_CANFD1WakeUpInterrupt
  * @param    PMUx PMU instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_PMU_IsActiveFlag_CANFD1WakeUpInterrupt(PMU_Type* PMUx)
{
    return (uint32_t)(READ_BIT(PMUx->CFDCK_SR, PMU_CFDCK_SR_CFD1WKIF_Msk) == (PMU_CFDCK_SR_CFD1WKIF_Msk));
}

/**
  * @brief    Clear CANFD1 Asycnchronous WakeUp Interrupt Flag
  * @rmtoll   CFDCK_SR    CFD1WKIF    FL_PMU_ClearFlag_CANFD1WakeUpInterrupt
  * @param    PMUx PMU instance
  * @retval   None
  */
__STATIC_INLINE void FL_PMU_ClearFlag_CANFD1WakeUpInterrupt(PMU_Type* PMUx)
{
    WRITE_REG(PMUx->CFDCK_SR, PMU_CFDCK_SR_CFD1WKIF_Msk);
}

/**
  * @brief    Get CANFD0 Asycnchronous WakeUp Interrupt Flag
  * @rmtoll   CFDCK_SR    CFD0WKIF    FL_PMU_IsActiveFlag_CANFD0WakeUpInterrupt
  * @param    PMUx PMU instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_PMU_IsActiveFlag_CANFD0WakeUpInterrupt(PMU_Type* PMUx)
{
    return (uint32_t)(READ_BIT(PMUx->CFDCK_SR, PMU_CFDCK_SR_CFD0WKIF_Msk) == (PMU_CFDCK_SR_CFD0WKIF_Msk));
}

/**
  * @brief    Clear CANFD0 Asycnchronous WakeUp Interrupt Flag
  * @rmtoll   CFDCK_SR    CFD0WKIF    FL_PMU_ClearFlag_CANFD0WakeUpInterrupt
  * @param    PMUx PMU instance
  * @retval   None
  */
__STATIC_INLINE void FL_PMU_ClearFlag_CANFD0WakeUpInterrupt(PMU_Type* PMUx)
{
    WRITE_REG(PMUx->CFDCK_SR, PMU_CFDCK_SR_CFD0WKIF_Msk);
}

/**
  * @}
  */

/** @defgroup PMU_FL_EF_Init Initialization and de-initialization functions
  * @{
  */
FL_ErrorStatus FL_PMU_Sleep_DeInit(PMU_Type *PMUx);
FL_ErrorStatus FL_PMU_Sleep_Init(PMU_Type *PMUx, FL_PMU_SleepInitTypeDef *LPM_InitStruct);
void FL_PMU_StructInit(FL_PMU_SleepInitTypeDef *LPM_InitStruct);

/**
  * @}
  */


/**
  * @}
  */

#ifdef __cplusplus
}
#endif

#endif /* __FM33FG0XXA_FL_PMU_H*/

/*************************Py_Code_Generator Version: 0.1-0.14-0.1 @ 2023-03-27*************************/
/*************************(C) COPYRIGHT Fudan Microelectronics **** END OF FILE*************************/
