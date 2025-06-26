 /**    
  *******************************************************************************************************
  * @file    fm33fg0xxa_fl_rmu.h
  * @author  FMSH Application Team
  * @brief   Head file of RMU FL Module
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
#ifndef __FM33FG0XXA_FL_RMU_H
#define __FM33FG0XXA_FL_RMU_H

#ifdef __cplusplus
extern "C" {
#endif
/* Includes -------------------------------------------------------------------------------------------*/
#include "fm33fg0xxa_fl_def.h"
/** @addtogroup FM33FG0XXA_FL_Driver
  * @{
  */
/* Exported types -------------------------------------------------------------------------------------*/
/** @defgroup RMU_FL_ES_INIT RMU Exported Init structures
  * @{
  */

/**
  * @brief FL RMU Init Sturcture definition
  */

/**
  * @}
  */
/* Exported constants ---------------------------------------------------------------------------------*/
/** @defgroup RMU_FL_Exported_Constants RMU Exported Constants
  * @{
  */

#define    RMU_PDRCR_CFG_Pos                                      (1U)
#define    RMU_PDRCR_CFG_Msk                                      (0x3U << RMU_PDRCR_CFG_Pos)
#define    RMU_PDRCR_CFG                                          RMU_PDRCR_CFG_Msk

#define    RMU_PDRCR_EN_Pos                                       (0U)
#define    RMU_PDRCR_EN_Msk                                       (0x1U << RMU_PDRCR_EN_Pos)
#define    RMU_PDRCR_EN                                           RMU_PDRCR_EN_Msk

#define    RMU_BORCR_CFG_Pos                                      (2U)
#define    RMU_BORCR_CFG_Msk                                      (0x7U << RMU_BORCR_CFG_Pos)
#define    RMU_BORCR_CFG                                          RMU_BORCR_CFG_Msk

#define    RMU_BORCR_ENB_Pos                                      (0U)
#define    RMU_BORCR_ENB_Msk                                      (0x1U << RMU_BORCR_ENB_Pos)
#define    RMU_BORCR_ENB                                          RMU_BORCR_ENB_Msk

#define    RMU_LKPCR_LOLRST_EN_Pos                                (7U)
#define    RMU_LKPCR_LOLRST_EN_Msk                                (0x1U << RMU_LKPCR_LOLRST_EN_Pos)
#define    RMU_LKPCR_LOLRST_EN                                    RMU_LKPCR_LOLRST_EN_Msk

#define    RMU_LKPCR_LOCRST_EN_Pos                                (6U)
#define    RMU_LKPCR_LOCRST_EN_Msk                                (0x1U << RMU_LKPCR_LOCRST_EN_Pos)
#define    RMU_LKPCR_LOCRST_EN                                    RMU_LKPCR_LOCRST_EN_Msk

#define    RMU_LKPCR_LKUPRST_EN_Pos                               (1U)
#define    RMU_LKPCR_LKUPRST_EN_Msk                               (0x1U << RMU_LKPCR_LKUPRST_EN_Pos)
#define    RMU_LKPCR_LKUPRST_EN                                   RMU_LKPCR_LKUPRST_EN_Msk

#define    RMU_RSTFR_CLM1_TOUT_FLAG_Pos                           (21U)
#define    RMU_RSTFR_CLM1_TOUT_FLAG_Msk                           (0x1U << RMU_RSTFR_CLM1_TOUT_FLAG_Pos)
#define    RMU_RSTFR_CLM1_TOUT_FLAG                               RMU_RSTFR_CLM1_TOUT_FLAG_Msk

#define    RMU_RSTFR_CLM1_UDF_FLAG_Pos                            (20U)
#define    RMU_RSTFR_CLM1_UDF_FLAG_Msk                            (0x1U << RMU_RSTFR_CLM1_UDF_FLAG_Pos)
#define    RMU_RSTFR_CLM1_UDF_FLAG                                RMU_RSTFR_CLM1_UDF_FLAG_Msk

#define    RMU_RSTFR_CLM1_OVF_FLAG_Pos                            (19U)
#define    RMU_RSTFR_CLM1_OVF_FLAG_Msk                            (0x1U << RMU_RSTFR_CLM1_OVF_FLAG_Pos)
#define    RMU_RSTFR_CLM1_OVF_FLAG                                RMU_RSTFR_CLM1_OVF_FLAG_Msk

#define    RMU_RSTFR_CLM0_TOUT_FLAG_Pos                           (18U)
#define    RMU_RSTFR_CLM0_TOUT_FLAG_Msk                           (0x1U << RMU_RSTFR_CLM0_TOUT_FLAG_Pos)
#define    RMU_RSTFR_CLM0_TOUT_FLAG                               RMU_RSTFR_CLM0_TOUT_FLAG_Msk

#define    RMU_RSTFR_CLM0_UDF_FLAG_Pos                            (17U)
#define    RMU_RSTFR_CLM0_UDF_FLAG_Msk                            (0x1U << RMU_RSTFR_CLM0_UDF_FLAG_Pos)
#define    RMU_RSTFR_CLM0_UDF_FLAG                                RMU_RSTFR_CLM0_UDF_FLAG_Msk

#define    RMU_RSTFR_CLM0_OVF_FLAG_Pos                            (16U)
#define    RMU_RSTFR_CLM0_OVF_FLAG_Msk                            (0x1U << RMU_RSTFR_CLM0_OVF_FLAG_Pos)
#define    RMU_RSTFR_CLM0_OVF_FLAG                                RMU_RSTFR_CLM0_OVF_FLAG_Msk

#define    RMU_RSTFR_MAP_FLAG_Pos                                 (13U)
#define    RMU_RSTFR_MAP_FLAG_Msk                                 (0x1U << RMU_RSTFR_MAP_FLAG_Pos)
#define    RMU_RSTFR_MAP_FLAG                                     RMU_RSTFR_MAP_FLAG_Msk

#define    RMU_RSTFR_MDFN_FLAG_Pos                                (12U)
#define    RMU_RSTFR_MDFN_FLAG_Msk                                (0x1U << RMU_RSTFR_MDFN_FLAG_Pos)
#define    RMU_RSTFR_MDFN_FLAG                                    RMU_RSTFR_MDFN_FLAG_Msk

#define    RMU_RSTFR_NRSTN_FLAG_Pos                               (11U)
#define    RMU_RSTFR_NRSTN_FLAG_Msk                               (0x1U << RMU_RSTFR_NRSTN_FLAG_Pos)
#define    RMU_RSTFR_NRSTN_FLAG                                   RMU_RSTFR_NRSTN_FLAG_Msk

#define    RMU_RSTFR_PRC_FLAG_Pos                                 (10U)
#define    RMU_RSTFR_PRC_FLAG_Msk                                 (0x1U << RMU_RSTFR_PRC_FLAG_Pos)
#define    RMU_RSTFR_PRC_FLAG                                     RMU_RSTFR_PRC_FLAG_Msk

#define    RMU_RSTFR_PORN_FLAG_Pos                                (9U)
#define    RMU_RSTFR_PORN_FLAG_Msk                                (0x1U << RMU_RSTFR_PORN_FLAG_Pos)
#define    RMU_RSTFR_PORN_FLAG                                    RMU_RSTFR_PORN_FLAG_Msk

#define    RMU_RSTFR_PDRN_FLAG_Pos                                (8U)
#define    RMU_RSTFR_PDRN_FLAG_Msk                                (0x1U << RMU_RSTFR_PDRN_FLAG_Pos)
#define    RMU_RSTFR_PDRN_FLAG                                    RMU_RSTFR_PDRN_FLAG_Msk

#define    RMU_RSTFR_LOL_FLAG_Pos                                 (7U)
#define    RMU_RSTFR_LOL_FLAG_Msk                                 (0x1U << RMU_RSTFR_LOL_FLAG_Pos)
#define    RMU_RSTFR_LOL_FLAG                                     RMU_RSTFR_LOL_FLAG_Msk

#define    RMU_RSTFR_LOC_FLAG_Pos                                 (6U)
#define    RMU_RSTFR_LOC_FLAG_Msk                                 (0x1U << RMU_RSTFR_LOC_FLAG_Pos)
#define    RMU_RSTFR_LOC_FLAG                                     RMU_RSTFR_LOC_FLAG_Msk

#define    RMU_RSTFR_SOFTN_FLAG_Pos                               (5U)
#define    RMU_RSTFR_SOFTN_FLAG_Msk                               (0x1U << RMU_RSTFR_SOFTN_FLAG_Pos)
#define    RMU_RSTFR_SOFTN_FLAG                                   RMU_RSTFR_SOFTN_FLAG_Msk

#define    RMU_RSTFR_IWDTN_FLAG_Pos                               (4U)
#define    RMU_RSTFR_IWDTN_FLAG_Msk                               (0x1U << RMU_RSTFR_IWDTN_FLAG_Pos)
#define    RMU_RSTFR_IWDTN_FLAG                                   RMU_RSTFR_IWDTN_FLAG_Msk

#define    RMU_RSTFR_WWDTN_FLAG_Pos                               (2U)
#define    RMU_RSTFR_WWDTN_FLAG_Msk                               (0x1U << RMU_RSTFR_WWDTN_FLAG_Pos)
#define    RMU_RSTFR_WWDTN_FLAG                                   RMU_RSTFR_WWDTN_FLAG_Msk

#define    RMU_RSTFR_LKUPN_FLAG_Pos                               (1U)
#define    RMU_RSTFR_LKUPN_FLAG_Msk                               (0x1U << RMU_RSTFR_LKUPN_FLAG_Pos)
#define    RMU_RSTFR_LKUPN_FLAG                                   RMU_RSTFR_LKUPN_FLAG_Msk

#define    RMU_RSTFR_NVICN_FLAG_Pos                               (0U)
#define    RMU_RSTFR_NVICN_FLAG_Msk                               (0x1U << RMU_RSTFR_NVICN_FLAG_Pos)
#define    RMU_RSTFR_NVICN_FLAG                                   RMU_RSTFR_NVICN_FLAG_Msk

#define    PERHRSTEN_KEY                                          (0x13579BDFUL)
#define    SOFTWARERESET_KEY                                      (0x5C5CAABBUL)

#define    FL_RMU_RSTAHB_DMA                                      (0x1U << 0U)
#define    FL_RMU_RSTAPB_UART5                                    (0x1fU << 0U)
#define    FL_RMU_RSTAPB_UART4                                    (0x1eU << 0U)
#define    FL_RMU_RSTAPB_UART3                                    (0x1dU << 0U)
#define    FL_RMU_RSTAPB_UART2                                    (0x1cU << 0U)
#define    FL_RMU_RSTAPB_UART1                                    (0x1bU << 0U)
#define    FL_RMU_RSTAPB_UART0                                    (0x1aU << 0U)
#define    FL_RMU_RSTAPB_UCIR                                     (0x19U << 0U)
#define    FL_RMU_RSTAPB_LPUART2                                  (0x18U << 0U)
#define    FL_RMU_RSTAPB_SPI3                                     (0x17U << 0U)
#define    FL_RMU_RSTAPB_SPI2                                     (0x16U << 0U)
#define    FL_RMU_RSTAPB_SPI1                                     (0x15U << 0U)
#define    FL_RMU_RSTAPB_SPI0                                     (0x14U << 0U)
#define    FL_RMU_RSTAPB_GPTIM2                                   (0x13U << 0U)
#define    FL_RMU_RSTAPB_GPTIM1                                   (0x12U << 0U)
#define    FL_RMU_RSTAPB_GPTIM0                                   (0x11U << 0U)
#define    FL_RMU_RSTAPB_FSCAN                                    (0x10U << 0U)
#define    FL_RMU_RSTAPB_LPUART1                                  (0xfU << 0U)
#define    FL_RMU_RSTAPB_LPUART0                                  (0xeU << 0U)
#define    FL_RMU_RSTAPB_I2CSMB1                                  (0xdU << 0U)
#define    FL_RMU_RSTAPB_I2CSMB0                                  (0xcU << 0U)
#define    FL_RMU_RSTAPB_I2C1                                     (0x9U << 0U)
#define    FL_RMU_RSTAPB_I2C0                                     (0x8U << 0U)
#define    FL_RMU_RSTAPB_LPTIM32                                  (0x7U << 0U)
#define    FL_RMU_RSTAPB_BSTIM32                                  (0x6U << 0U)
#define    FL_RMU_RSTAPB_PGL                                      (0x5U << 0U)
#define    FL_RMU_RSTAPB_ATIM                                     (0x4U << 0U)
#define    FL_RMU_RSTAPB_TAU1                                     (0x3U << 0U)
#define    FL_RMU_RSTAPB_TAU0                                     (0x2U << 0U)
#define    FL_RMU_RSTAPB_LPTIM16                                  (0x1U << 0U)
#define    FL_RMU_RSTAPB_BSTIM16                                  (0x0U << 0U)
#define    FL_RMU_RSTAPB_CANFD1R                                  (0x3fU << 0U)
#define    FL_RMU_RSTAPB_CANFD1P                                  (0x3eU << 0U)
#define    FL_RMU_RSTAPB_CANFD1C                                  (0x3dU << 0U)
#define    FL_RMU_RSTAPB_CANFD0R                                  (0x3cU << 0U)
#define    FL_RMU_RSTAPB_CANFD0P                                  (0x3bU << 0U)
#define    FL_RMU_RSTAPB_CANFD0C                                  (0x3aU << 0U)
#define    FL_RMU_RSTAPB_DAC                                      (0x39U << 0U)
#define    FL_RMU_RSTAPB_ADCCR                                    (0x38U << 0U)
#define    FL_RMU_RSTAPB_ADC                                      (0x37U << 0U)
#define    FL_RMU_RSTAPB_CLM1                                     (0x36U << 0U)
#define    FL_RMU_RSTAPB_CLM0                                     (0x35U << 0U)
#define    FL_RMU_RSTAPB_SENT1                                    (0x34U << 0U)
#define    FL_RMU_RSTAPB_SENT0                                    (0x33U << 0U)
#define    FL_RMU_RSTAPB_AES                                      (0x32U << 0U)
#define    FL_RMU_RSTAPB_CRC                                      (0x31U << 0U)
#define    FL_RMU_RSTAPB_RNG                                      (0x30U << 0U)
#define    FL_RMU_RSTAPB_HDIV                                     (0x23U << 0U)
#define    FL_RMU_RSTAPB_SVD                                      (0x21U << 0U)
#define    FL_RMU_RSTAPB_COMP                                     (0x20U << 0U)



#define    FL_RMU_PDR_THRESHOLD_1P40V                             (0x0U << RMU_PDRCR_CFG_Pos)
#define    FL_RMU_PDR_THRESHOLD_1P45V                             (0x1U << RMU_PDRCR_CFG_Pos)
#define    FL_RMU_PDR_THRESHOLD_1P50V                             (0x2U << RMU_PDRCR_CFG_Pos)
#define    FL_RMU_PDR_THRESHOLD_1P55V                             (0x3U << RMU_PDRCR_CFG_Pos)


#define    FL_RMU_BOR_THRESHOLD_1P80V                             (0x0U << RMU_BORCR_CFG_Pos)
#define    FL_RMU_BOR_THRESHOLD_2P00V                             (0x1U << RMU_BORCR_CFG_Pos)
#define    FL_RMU_BOR_THRESHOLD_2P20V                             (0x2U << RMU_BORCR_CFG_Pos)
#define    FL_RMU_BOR_THRESHOLD_2P40V                             (0x3U << RMU_BORCR_CFG_Pos)
#define    FL_RMU_BOR_THRESHOLD_2P70V                             (0x4U << RMU_BORCR_CFG_Pos)
#define    FL_RMU_BOR_THRESHOLD_3P00V                             (0x5U << RMU_BORCR_CFG_Pos)
#define    FL_RMU_BOR_THRESHOLD_3P60V                             (0x6U << RMU_BORCR_CFG_Pos)
#define    FL_RMU_BOR_THRESHOLD_4P00V                             (0x7U << RMU_BORCR_CFG_Pos)


/**
  * @}
  */
/* Exported functions ---------------------------------------------------------------------------------*/
/** @defgroup RMU_FL_Exported_Functions RMU Exported Functions
  * @{
  */

/**
  * @brief    Set Power Down Reset Voltage
  * @rmtoll   PDRCR    CFG    FL_RMU_PDR_SetThreshold
  * @param    RMUx RMU instance
  * @param    threshold This parameter can be one of the following values:
  *           @arg @ref FL_RMU_PDR_THRESHOLD_1P40V
  *           @arg @ref FL_RMU_PDR_THRESHOLD_1P45V
  *           @arg @ref FL_RMU_PDR_THRESHOLD_1P50V
  *           @arg @ref FL_RMU_PDR_THRESHOLD_1P55V
  * @retval   None
  */
__STATIC_INLINE void FL_RMU_PDR_SetThreshold(RMU_Type* RMUx, uint32_t threshold)
{
    MODIFY_REG(RMUx->PDRCR, RMU_PDRCR_CFG_Msk, threshold);
}

/**
  * @brief    Get Power Down Reset Voltage Setting
  * @rmtoll   PDRCR    CFG    FL_RMU_PDR_GetThreshold
  * @param    RMUx RMU instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_RMU_PDR_THRESHOLD_1P40V
  *           @arg @ref FL_RMU_PDR_THRESHOLD_1P45V
  *           @arg @ref FL_RMU_PDR_THRESHOLD_1P50V
  *           @arg @ref FL_RMU_PDR_THRESHOLD_1P55V
  */
__STATIC_INLINE uint32_t FL_RMU_PDR_GetThreshold(RMU_Type* RMUx)
{
    return (uint32_t)(READ_BIT(RMUx->PDRCR, RMU_PDRCR_CFG_Msk));
}

/**
  * @brief    Get Power Down Reset Enable Status
  * @rmtoll   PDRCR    EN    FL_RMU_PDR_IsEnabled
  * @param    RMUx RMU instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_RMU_PDR_IsEnabled(RMU_Type* RMUx)
{
    return (uint32_t)(READ_BIT(RMUx->PDRCR, RMU_PDRCR_EN_Msk) == RMU_PDRCR_EN_Msk);
}

/**
  * @brief    Disable Power Down Reset
  * @rmtoll   PDRCR    EN    FL_RMU_PDR_Disable
  * @param    RMUx RMU instance
  * @retval   None
  */
__STATIC_INLINE void FL_RMU_PDR_Disable(RMU_Type* RMUx)
{
    CLEAR_BIT(RMUx->PDRCR, RMU_PDRCR_EN_Msk);
}

/**
  * @brief    Enable Power Down Reset
  * @rmtoll   PDRCR    EN    FL_RMU_PDR_Enable
  * @param    RMUx RMU instance
  * @retval   None
  */
__STATIC_INLINE void FL_RMU_PDR_Enable(RMU_Type* RMUx)
{
    SET_BIT(RMUx->PDRCR, RMU_PDRCR_EN_Msk);
}

/**
  * @brief    Set Brown Out Reset Voltage
  * @rmtoll   BORCR    CFG    FL_RMU_BOR_SetThreshold
  * @param    RMUx RMU instance
  * @param    threshold This parameter can be one of the following values:
  *           @arg @ref FL_RMU_BOR_THRESHOLD_1P80V
  *           @arg @ref FL_RMU_BOR_THRESHOLD_2P00V
  *           @arg @ref FL_RMU_BOR_THRESHOLD_2P20V
  *           @arg @ref FL_RMU_BOR_THRESHOLD_2P40V
  *           @arg @ref FL_RMU_BOR_THRESHOLD_2P70V
  *           @arg @ref FL_RMU_BOR_THRESHOLD_3P00V
  *           @arg @ref FL_RMU_BOR_THRESHOLD_3P60V
  *           @arg @ref FL_RMU_BOR_THRESHOLD_4P00V
  * @retval   None
  */
__STATIC_INLINE void FL_RMU_BOR_SetThreshold(RMU_Type* RMUx, uint32_t threshold)
{
    MODIFY_REG(RMUx->BORCR, RMU_BORCR_CFG_Msk, threshold);
}

/**
  * @brief    Get Brown Out Reset Setting
  * @rmtoll   BORCR    CFG    FL_RMU_BOR_GetThreshold
  * @param    RMUx RMU instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_RMU_BOR_THRESHOLD_1P80V
  *           @arg @ref FL_RMU_BOR_THRESHOLD_2P00V
  *           @arg @ref FL_RMU_BOR_THRESHOLD_2P20V
  *           @arg @ref FL_RMU_BOR_THRESHOLD_2P40V
  *           @arg @ref FL_RMU_BOR_THRESHOLD_2P70V
  *           @arg @ref FL_RMU_BOR_THRESHOLD_3P00V
  *           @arg @ref FL_RMU_BOR_THRESHOLD_3P60V
  *           @arg @ref FL_RMU_BOR_THRESHOLD_4P00V
  */
__STATIC_INLINE uint32_t FL_RMU_BOR_GetThreshold(RMU_Type* RMUx)
{
    return (uint32_t)(READ_BIT(RMUx->BORCR, RMU_BORCR_CFG_Msk));
}

/**
  * @brief    Get Brown Out Reset Enable Status
  * @rmtoll   BORCR    ENB    FL_RMU_BOR_IsEnabled
  * @param    RMUx RMU instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_RMU_BOR_IsEnabled(RMU_Type* RMUx)
{
    return (uint32_t)!(READ_BIT(RMUx->BORCR, RMU_BORCR_ENB_Msk) == RMU_BORCR_ENB_Msk);
}

/**
  * @brief    Disable Brown Out Reset
  * @rmtoll   BORCR    ENB    FL_RMU_BOR_Disable
  * @param    RMUx RMU instance
  * @retval   None
  */
__STATIC_INLINE void FL_RMU_BOR_Disable(RMU_Type* RMUx)
{
    SET_BIT(RMUx->BORCR, RMU_BORCR_ENB_Msk);
}

/**
  * @brief    Enable Brown Out Reset
  * @rmtoll   BORCR    ENB    FL_RMU_BOR_Enable
  * @param    RMUx RMU instance
  * @retval   None
  */
__STATIC_INLINE void FL_RMU_BOR_Enable(RMU_Type* RMUx)
{
    CLEAR_BIT(RMUx->BORCR, RMU_BORCR_ENB_Msk);
}

/**
  * @brief    Get PLL Lost Lock Reset Enable Status
  * @rmtoll   LKPCR    LOLRST_EN    FL_RMU_IsEnabledPLLLostLockReset
  * @param    RMUx RMU instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_RMU_IsEnabledPLLLostLockReset(RMU_Type* RMUx)
{
    return (uint32_t)(READ_BIT(RMUx->LKPCR, RMU_LKPCR_LOLRST_EN_Msk) == RMU_LKPCR_LOLRST_EN_Msk);
}

/**
  * @brief    Disable  PLL Lost Lock  Reset 
  * @rmtoll   LKPCR    LOLRST_EN    FL_RMU_DisablePLLLostLockReset
  * @param    RMUx RMU instance
  * @retval   None
  */
__STATIC_INLINE void FL_RMU_DisablePLLLostLockReset(RMU_Type* RMUx)
{
    CLEAR_BIT(RMUx->LKPCR, RMU_LKPCR_LOLRST_EN_Msk);
}

/**
  * @brief    Enable PLL Lost Lock  Reset
  * @rmtoll   LKPCR    LOLRST_EN    FL_RMU_EnablePLLLostLockReset
  * @param    RMUx RMU instance
  * @retval   None
  */
__STATIC_INLINE void FL_RMU_EnablePLLLostLockReset(RMU_Type* RMUx)
{
    SET_BIT(RMUx->LKPCR, RMU_LKPCR_LOLRST_EN_Msk);
}

/**
  * @brief    Get Crystal Stop Reset Enable Status
  * @rmtoll   LKPCR    LOCRST_EN    FL_RMU_IsEnabledCrystalStopReset
  * @param    RMUx RMU instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_RMU_IsEnabledCrystalStopReset(RMU_Type* RMUx)
{
    return (uint32_t)(READ_BIT(RMUx->LKPCR, RMU_LKPCR_LOCRST_EN_Msk) == RMU_LKPCR_LOCRST_EN_Msk);
}

/**
  * @brief    Disable Crystal Stop Reset 
  * @rmtoll   LKPCR    LOCRST_EN    FL_RMU_DisableCrystalStopReset
  * @param    RMUx RMU instance
  * @retval   None
  */
__STATIC_INLINE void FL_RMU_DisableCrystalStopReset(RMU_Type* RMUx)
{
    CLEAR_BIT(RMUx->LKPCR, RMU_LKPCR_LOCRST_EN_Msk);
}

/**
  * @brief    Enable Crystal Stop Reset
  * @rmtoll   LKPCR    LOCRST_EN    FL_RMU_EnableCrystalStopReset
  * @param    RMUx RMU instance
  * @retval   None
  */
__STATIC_INLINE void FL_RMU_EnableCrystalStopReset(RMU_Type* RMUx)
{
    SET_BIT(RMUx->LKPCR, RMU_LKPCR_LOCRST_EN_Msk);
}

/**
  * @brief    Get LockUp Reset Enable Status
  * @rmtoll   LKPCR    LKUPRST_EN    FL_RMU_IsEnabledLockUpReset
  * @param    RMUx RMU instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_RMU_IsEnabledLockUpReset(RMU_Type* RMUx)
{
    return (uint32_t)(READ_BIT(RMUx->LKPCR, RMU_LKPCR_LKUPRST_EN_Msk) == RMU_LKPCR_LKUPRST_EN_Msk);
}

/**
  * @brief    Disable LockUp Reset 
  * @rmtoll   LKPCR    LKUPRST_EN    FL_RMU_DisableLockUpReset
  * @param    RMUx RMU instance
  * @retval   None
  */
__STATIC_INLINE void FL_RMU_DisableLockUpReset(RMU_Type* RMUx)
{
    CLEAR_BIT(RMUx->LKPCR, RMU_LKPCR_LKUPRST_EN_Msk);
}

/**
  * @brief    Enable LockUp Reset
  * @rmtoll   LKPCR    LKUPRST_EN    FL_RMU_EnableLockUpReset
  * @param    RMUx RMU instance
  * @retval   None
  */
__STATIC_INLINE void FL_RMU_EnableLockUpReset(RMU_Type* RMUx)
{
    SET_BIT(RMUx->LKPCR, RMU_LKPCR_LKUPRST_EN_Msk);
}

/**
  * @brief    Soft Reset Chip
  * @rmtoll   SOFTRST        FL_RMU_SetSoftReset
  * @param    RMUx RMU instance
  * @retval   None
  */
__STATIC_INLINE void FL_RMU_SetSoftReset(RMU_Type* RMUx)
{
    WRITE_REG(RMUx->SOFTRST, SOFTWARERESET_KEY);
}

/**
  * @brief    Get CLM1 Time Out Reset Flag
  * @rmtoll   RSTFR    CLM1_TOUT_FLAG    FL_RMU_IsActiveFlag_CLM1_TOUT
  * @param    RMUx RMU instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_RMU_IsActiveFlag_CLM1_TOUT(RMU_Type* RMUx)
{
    return (uint32_t)(READ_BIT(RMUx->RSTFR, RMU_RSTFR_CLM1_TOUT_FLAG_Msk) == (RMU_RSTFR_CLM1_TOUT_FLAG_Msk));
}

/**
  * @brief    Clear CLM1 Time Out Reset Flag
  * @rmtoll   RSTFR    CLM1_TOUT_FLAG    FL_RMU_ClearFlag_CLM1_TOUT
  * @param    RMUx RMU instance
  * @retval   None
  */
__STATIC_INLINE void FL_RMU_ClearFlag_CLM1_TOUT(RMU_Type* RMUx)
{
    WRITE_REG(RMUx->RSTFR, RMU_RSTFR_CLM1_TOUT_FLAG_Msk);
}

/**
  * @brief    Get CLM1 Underflow Reset Flag
  * @rmtoll   RSTFR    CLM1_UDF_FLAG    FL_RMU_IsActiveFlag_CLM1_UDF
  * @param    RMUx RMU instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_RMU_IsActiveFlag_CLM1_UDF(RMU_Type* RMUx)
{
    return (uint32_t)(READ_BIT(RMUx->RSTFR, RMU_RSTFR_CLM1_UDF_FLAG_Msk) == (RMU_RSTFR_CLM1_UDF_FLAG_Msk));
}

/**
  * @brief    Clear CLM1 Underflow Reset Flag
  * @rmtoll   RSTFR    CLM1_UDF_FLAG    FL_RMU_ClearFlag_CLM1_UDF
  * @param    RMUx RMU instance
  * @retval   None
  */
__STATIC_INLINE void FL_RMU_ClearFlag_CLM1_UDF(RMU_Type* RMUx)
{
    WRITE_REG(RMUx->RSTFR, RMU_RSTFR_CLM1_UDF_FLAG_Msk);
}

/**
  * @brief    Get CLM1 Overflow Reset Flag
  * @rmtoll   RSTFR    CLM1_OVF_FLAG    FL_RMU_IsActiveFlag_CLM1_OVF
  * @param    RMUx RMU instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_RMU_IsActiveFlag_CLM1_OVF(RMU_Type* RMUx)
{
    return (uint32_t)(READ_BIT(RMUx->RSTFR, RMU_RSTFR_CLM1_OVF_FLAG_Msk) == (RMU_RSTFR_CLM1_OVF_FLAG_Msk));
}

/**
  * @brief    Get CLM1 Overflow Reset Flag
  * @rmtoll   RSTFR    CLM1_OVF_FLAG    FL_RMU_ClearFlag_CLM1_OVF
  * @param    RMUx RMU instance
  * @retval   None
  */
__STATIC_INLINE void FL_RMU_ClearFlag_CLM1_OVF(RMU_Type* RMUx)
{
    WRITE_REG(RMUx->RSTFR, RMU_RSTFR_CLM1_OVF_FLAG_Msk);
}

/**
  * @brief    Get CLM0 Time Out Reset Flag
  * @rmtoll   RSTFR    CLM0_TOUT_FLAG    FL_RMU_IsActiveFlag_CLM0_TOUT
  * @param    RMUx RMU instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_RMU_IsActiveFlag_CLM0_TOUT(RMU_Type* RMUx)
{
    return (uint32_t)(READ_BIT(RMUx->RSTFR, RMU_RSTFR_CLM0_TOUT_FLAG_Msk) == (RMU_RSTFR_CLM0_TOUT_FLAG_Msk));
}

/**
  * @brief    Clear CLM0 Time Out Reset Flag
  * @rmtoll   RSTFR    CLM0_TOUT_FLAG    FL_RMU_ClearFlag_CLM0_TOUT
  * @param    RMUx RMU instance
  * @retval   None
  */
__STATIC_INLINE void FL_RMU_ClearFlag_CLM0_TOUT(RMU_Type* RMUx)
{
    WRITE_REG(RMUx->RSTFR, RMU_RSTFR_CLM0_TOUT_FLAG_Msk);
}

/**
  * @brief    Get CLM0 Underflow Reset Flag
  * @rmtoll   RSTFR    CLM0_UDF_FLAG    FL_RMU_IsActiveFlag_CLM0_UDF
  * @param    RMUx RMU instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_RMU_IsActiveFlag_CLM0_UDF(RMU_Type* RMUx)
{
    return (uint32_t)(READ_BIT(RMUx->RSTFR, RMU_RSTFR_CLM0_UDF_FLAG_Msk) == (RMU_RSTFR_CLM0_UDF_FLAG_Msk));
}

/**
  * @brief    Clear CLM0 Underflow Reset Flag
  * @rmtoll   RSTFR    CLM0_UDF_FLAG    FL_RMU_ClearFlag_CLM0_UDF
  * @param    RMUx RMU instance
  * @retval   None
  */
__STATIC_INLINE void FL_RMU_ClearFlag_CLM0_UDF(RMU_Type* RMUx)
{
    WRITE_REG(RMUx->RSTFR, RMU_RSTFR_CLM0_UDF_FLAG_Msk);
}

/**
  * @brief    Get CLM0 Overflow Reset Flag
  * @rmtoll   RSTFR    CLM0_OVF_FLAG    FL_RMU_IsActiveFlag_CLM0_OVF
  * @param    RMUx RMU instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_RMU_IsActiveFlag_CLM0_OVF(RMU_Type* RMUx)
{
    return (uint32_t)(READ_BIT(RMUx->RSTFR, RMU_RSTFR_CLM0_OVF_FLAG_Msk) == (RMU_RSTFR_CLM0_OVF_FLAG_Msk));
}

/**
  * @brief    Get CLM0 Overflow Reset Flag
  * @rmtoll   RSTFR    CLM0_OVF_FLAG    FL_RMU_ClearFlag_CLM0_OVF
  * @param    RMUx RMU instance
  * @retval   None
  */
__STATIC_INLINE void FL_RMU_ClearFlag_CLM0_OVF(RMU_Type* RMUx)
{
    WRITE_REG(RMUx->RSTFR, RMU_RSTFR_CLM0_OVF_FLAG_Msk);
}

/**
  * @brief    Get MAP Error Flag
  * @rmtoll   RSTFR    MAP_FLAG    FL_RMU_IsActiveFlag_MAP
  * @param    RMUx RMU instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_RMU_IsActiveFlag_MAP(RMU_Type* RMUx)
{
    return (uint32_t)(READ_BIT(RMUx->RSTFR, RMU_RSTFR_MAP_FLAG_Msk) == (RMU_RSTFR_MAP_FLAG_Msk));
}

/**
  * @brief    Clear MAP Reset Flag
  * @rmtoll   RSTFR    MAP_FLAG    FL_RMU_ClearFlag_MAP
  * @param    RMUx RMU instance
  * @retval   None
  */
__STATIC_INLINE void FL_RMU_ClearFlag_MAP(RMU_Type* RMUx)
{
    WRITE_REG(RMUx->RSTFR, RMU_RSTFR_MAP_FLAG_Msk);
}

/**
  * @brief    Get MDF Reset Flag
  * @rmtoll   RSTFR    MDFN_FLAG    FL_RMU_IsActiveFlag_MDF
  * @param    RMUx RMU instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_RMU_IsActiveFlag_MDF(RMU_Type* RMUx)
{
    return (uint32_t)(READ_BIT(RMUx->RSTFR, RMU_RSTFR_MDFN_FLAG_Msk) == (RMU_RSTFR_MDFN_FLAG_Msk));
}

/**
  * @brief    Clear MDF Reset Flag
  * @rmtoll   RSTFR    MDFN_FLAG    FL_RMU_ClearFlag_MDF
  * @param    RMUx RMU instance
  * @retval   None
  */
__STATIC_INLINE void FL_RMU_ClearFlag_MDF(RMU_Type* RMUx)
{
    WRITE_REG(RMUx->RSTFR, RMU_RSTFR_MDFN_FLAG_Msk);
}

/**
  * @brief    Get NRST Reset Flag
  * @rmtoll   RSTFR    NRSTN_FLAG    FL_RMU_IsActiveFlag_NRSTN
  * @param    RMUx RMU instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_RMU_IsActiveFlag_NRSTN(RMU_Type* RMUx)
{
    return (uint32_t)(READ_BIT(RMUx->RSTFR, RMU_RSTFR_NRSTN_FLAG_Msk) == (RMU_RSTFR_NRSTN_FLAG_Msk));
}

/**
  * @brief    Clear NRST Reset Flag
  * @rmtoll   RSTFR    NRSTN_FLAG    FL_RMU_ClearFlag_NRSTN
  * @param    RMUx RMU instance
  * @retval   None
  */
__STATIC_INLINE void FL_RMU_ClearFlag_NRSTN(RMU_Type* RMUx)
{
    WRITE_REG(RMUx->RSTFR, RMU_RSTFR_NRSTN_FLAG_Msk);
}

/**
  * @brief    Get PRC Reset Flag
  * @rmtoll   RSTFR    PRC_FLAG    FL_RMU_IsActiveFlag_PRCN
  * @param    RMUx RMU instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_RMU_IsActiveFlag_PRCN(RMU_Type* RMUx)
{
    return (uint32_t)(READ_BIT(RMUx->RSTFR, RMU_RSTFR_PRC_FLAG_Msk) == (RMU_RSTFR_PRC_FLAG_Msk));
}

/**
  * @brief    Clear PRC Reset Flag
  * @rmtoll   RSTFR    PRC_FLAG    FL_RMU_ClearFlag_PRCN
  * @param    RMUx RMU instance
  * @retval   None
  */
__STATIC_INLINE void FL_RMU_ClearFlag_PRCN(RMU_Type* RMUx)
{
    WRITE_REG(RMUx->RSTFR, RMU_RSTFR_PRC_FLAG_Msk);
}

/**
  * @brief    Get Power On Reset Flag
  * @rmtoll   RSTFR    PORN_FLAG    FL_RMU_IsActiveFlag_PORN
  * @param    RMUx RMU instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_RMU_IsActiveFlag_PORN(RMU_Type* RMUx)
{
    return (uint32_t)(READ_BIT(RMUx->RSTFR, RMU_RSTFR_PORN_FLAG_Msk) == (RMU_RSTFR_PORN_FLAG_Msk));
}

/**
  * @brief    Clear Power On Reset Flag
  * @rmtoll   RSTFR    PORN_FLAG    FL_RMU_ClearFlag_PORN
  * @param    RMUx RMU instance
  * @retval   None
  */
__STATIC_INLINE void FL_RMU_ClearFlag_PORN(RMU_Type* RMUx)
{
    WRITE_REG(RMUx->RSTFR, RMU_RSTFR_PORN_FLAG_Msk);
}

/**
  * @brief    Get Power Down Reset Flag
  * @rmtoll   RSTFR    PDRN_FLAG    FL_RMU_IsActiveFlag_PDRN
  * @param    RMUx RMU instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_RMU_IsActiveFlag_PDRN(RMU_Type* RMUx)
{
    return (uint32_t)(READ_BIT(RMUx->RSTFR, RMU_RSTFR_PDRN_FLAG_Msk) == (RMU_RSTFR_PDRN_FLAG_Msk));
}

/**
  * @brief    Clear Power Down Reset Flag
  * @rmtoll   RSTFR    PDRN_FLAG    FL_RMU_ClearFlag_PDRN
  * @param    RMUx RMU instance
  * @retval   None
  */
__STATIC_INLINE void FL_RMU_ClearFlag_PDRN(RMU_Type* RMUx)
{
    WRITE_REG(RMUx->RSTFR, RMU_RSTFR_PDRN_FLAG_Msk);
}

/**
  * @brief    Get PLL Lost Lock Reset Flag
  * @rmtoll   RSTFR    LOL_FLAG    FL_RMU_IsActiveFlag_LOL
  * @param    RMUx RMU instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_RMU_IsActiveFlag_LOL(RMU_Type* RMUx)
{
    return (uint32_t)(READ_BIT(RMUx->RSTFR, RMU_RSTFR_LOL_FLAG_Msk) == (RMU_RSTFR_LOL_FLAG_Msk));
}

/**
  * @brief    Clear PLL Lost Lock Reset Flag
  * @rmtoll   RSTFR    LOL_FLAG    FL_RMU_ClearFlag_LOL
  * @param    RMUx RMU instance
  * @retval   None
  */
__STATIC_INLINE void FL_RMU_ClearFlag_LOL(RMU_Type* RMUx)
{
    WRITE_REG(RMUx->RSTFR, RMU_RSTFR_LOL_FLAG_Msk);
}

/**
  * @brief    Get Crystal Stop Reset Flag
  * @rmtoll   RSTFR    LOC_FLAG    FL_RMU_IsActiveFlag_LOC
  * @param    RMUx RMU instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_RMU_IsActiveFlag_LOC(RMU_Type* RMUx)
{
    return (uint32_t)(READ_BIT(RMUx->RSTFR, RMU_RSTFR_LOC_FLAG_Msk) == (RMU_RSTFR_LOC_FLAG_Msk));
}

/**
  * @brief    Clear Crystal Stop Reset Flag
  * @rmtoll   RSTFR    LOC_FLAG    FL_RMU_ClearFlag_LOC
  * @param    RMUx RMU instance
  * @retval   None
  */
__STATIC_INLINE void FL_RMU_ClearFlag_LOC(RMU_Type* RMUx)
{
    WRITE_REG(RMUx->RSTFR, RMU_RSTFR_LOC_FLAG_Msk);
}

/**
  * @brief    Get Software Reset Flag
  * @rmtoll   RSTFR    SOFTN_FLAG    FL_RMU_IsActiveFlag_SOFTN
  * @param    RMUx RMU instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_RMU_IsActiveFlag_SOFTN(RMU_Type* RMUx)
{
    return (uint32_t)(READ_BIT(RMUx->RSTFR, RMU_RSTFR_SOFTN_FLAG_Msk) == (RMU_RSTFR_SOFTN_FLAG_Msk));
}

/**
  * @brief    Clear Software Reset Flag
  * @rmtoll   RSTFR    SOFTN_FLAG    FL_RMU_ClearFlag_SOFTN
  * @param    RMUx RMU instance
  * @retval   None
  */
__STATIC_INLINE void FL_RMU_ClearFlag_SOFTN(RMU_Type* RMUx)
{
    WRITE_REG(RMUx->RSTFR, RMU_RSTFR_SOFTN_FLAG_Msk);
}

/**
  * @brief    Get IWDT Reset Flag
  * @rmtoll   RSTFR    IWDTN_FLAG    FL_RMU_IsActiveFlag_IWDTN
  * @param    RMUx RMU instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_RMU_IsActiveFlag_IWDTN(RMU_Type* RMUx)
{
    return (uint32_t)(READ_BIT(RMUx->RSTFR, RMU_RSTFR_IWDTN_FLAG_Msk) == (RMU_RSTFR_IWDTN_FLAG_Msk));
}

/**
  * @brief    Clear IWDT Reset Flag
  * @rmtoll   RSTFR    IWDTN_FLAG    FL_RMU_ClearFlag_IWDTN
  * @param    RMUx RMU instance
  * @retval   None
  */
__STATIC_INLINE void FL_RMU_ClearFlag_IWDTN(RMU_Type* RMUx)
{
    WRITE_REG(RMUx->RSTFR, RMU_RSTFR_IWDTN_FLAG_Msk);
}

/**
  * @brief    Get WWDT Reset Flag
  * @rmtoll   RSTFR    WWDTN_FLAG    FL_RMU_IsActiveFlag_WWDTN
  * @param    RMUx RMU instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_RMU_IsActiveFlag_WWDTN(RMU_Type* RMUx)
{
    return (uint32_t)(READ_BIT(RMUx->RSTFR, RMU_RSTFR_WWDTN_FLAG_Msk) == (RMU_RSTFR_WWDTN_FLAG_Msk));
}

/**
  * @brief    Clear WWDT Reset Flag
  * @rmtoll   RSTFR    WWDTN_FLAG    FL_RMU_ClearFlag_WWDTN
  * @param    RMUx RMU instance
  * @retval   None
  */
__STATIC_INLINE void FL_RMU_ClearFlag_WWDTN(RMU_Type* RMUx)
{
    WRITE_REG(RMUx->RSTFR, RMU_RSTFR_WWDTN_FLAG_Msk);
}

/**
  * @brief    Get LockUp Reset Flag
  * @rmtoll   RSTFR    LKUPN_FLAG    FL_RMU_IsActiveFlag_LKUPN
  * @param    RMUx RMU instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_RMU_IsActiveFlag_LKUPN(RMU_Type* RMUx)
{
    return (uint32_t)(READ_BIT(RMUx->RSTFR, RMU_RSTFR_LKUPN_FLAG_Msk) == (RMU_RSTFR_LKUPN_FLAG_Msk));
}

/**
  * @brief    Clear LockUp Reset Flag
  * @rmtoll   RSTFR    LKUPN_FLAG    FL_RMU_ClearFlag_LKUPN
  * @param    RMUx RMU instance
  * @retval   None
  */
__STATIC_INLINE void FL_RMU_ClearFlag_LKUPN(RMU_Type* RMUx)
{
    WRITE_REG(RMUx->RSTFR, RMU_RSTFR_LKUPN_FLAG_Msk);
}

/**
  * @brief    Get NVIC Reset Flag
  * @rmtoll   RSTFR    NVICN_FLAG    FL_RMU_IsActiveFlag_NVICN
  * @param    RMUx RMU instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_RMU_IsActiveFlag_NVICN(RMU_Type* RMUx)
{
    return (uint32_t)(READ_BIT(RMUx->RSTFR, RMU_RSTFR_NVICN_FLAG_Msk) == (RMU_RSTFR_NVICN_FLAG_Msk));
}

/**
  * @brief    Clear NVIC Reset Flag
  * @rmtoll   RSTFR    NVICN_FLAG    FL_RMU_ClearFlag_NVICN
  * @param    RMUx RMU instance
  * @retval   None
  */
__STATIC_INLINE void FL_RMU_ClearFlag_NVICN(RMU_Type* RMUx)
{
    WRITE_REG(RMUx->RSTFR, RMU_RSTFR_NVICN_FLAG_Msk);
}

/**
  * @brief    Disable Peripheral Reset
  * @rmtoll   PRSTEN        FL_RMU_DisablePeripheralReset
  * @param    RMUx RMU instance
  * @retval   None
  */
__STATIC_INLINE void FL_RMU_DisablePeripheralReset(RMU_Type* RMUx)
{
    WRITE_REG(RMUx->PRSTEN, (~PERHRSTEN_KEY));
}

/**
  * @brief    Enable Peripheral Reset
  * @rmtoll   PRSTEN        FL_RMU_EnablePeripheralReset
  * @param    RMUx RMU instance
  * @retval   None
  */
__STATIC_INLINE void FL_RMU_EnablePeripheralReset(RMU_Type* RMUx)
{
    WRITE_REG(RMUx->PRSTEN, PERHRSTEN_KEY);
}

/**
  * @brief    Enable AHB Peripheral Reset
  * @rmtoll   AHBRSTCR        FL_RMU_EnableResetAHBPeripheral
  * @param    RMUx RMU instance
  * @param    peripheral This parameter can be one of the following values:
  *           @arg @ref FL_RMU_RSTAHB_DMA
  * @retval   None
  */
__STATIC_INLINE void FL_RMU_EnableResetAHBPeripheral(RMU_Type* RMUx, uint32_t peripheral)
{
    SET_BIT(RMUx->AHBRSTCR, ((peripheral & 0xffffffff) << 0x0U));
}

/**
  * @brief    Enable APB Peripheral Reset1
  * @rmtoll   APBRST        FL_RMU_EnableResetAPBPeripheral
  * @param    RMUx RMU instance
  * @param    peripheral This parameter can be one of the following values:
  *           @arg @ref FL_RMU_RSTAPB_UART5
  *           @arg @ref FL_RMU_RSTAPB_UART4
  *           @arg @ref FL_RMU_RSTAPB_UART3
  *           @arg @ref FL_RMU_RSTAPB_UART2
  *           @arg @ref FL_RMU_RSTAPB_UART1
  *           @arg @ref FL_RMU_RSTAPB_UART0
  *           @arg @ref FL_RMU_RSTAPB_UCIR
  *           @arg @ref FL_RMU_RSTAPB_LPUART2
  *           @arg @ref FL_RMU_RSTAPB_SPI3
  *           @arg @ref FL_RMU_RSTAPB_SPI2
  *           @arg @ref FL_RMU_RSTAPB_SPI1
  *           @arg @ref FL_RMU_RSTAPB_SPI0
  *           @arg @ref FL_RMU_RSTAPB_GPTIM2
  *           @arg @ref FL_RMU_RSTAPB_GPTIM1
  *           @arg @ref FL_RMU_RSTAPB_GPTIM0
  *           @arg @ref FL_RMU_RSTAPB_FSCAN
  *           @arg @ref FL_RMU_RSTAPB_LPUART1
  *           @arg @ref FL_RMU_RSTAPB_LPUART0
  *           @arg @ref FL_RMU_RSTAPB_I2CSMB1
  *           @arg @ref FL_RMU_RSTAPB_I2CSMB0
  *           @arg @ref FL_RMU_RSTAPB_I2C1
  *           @arg @ref FL_RMU_RSTAPB_I2C0
  *           @arg @ref FL_RMU_RSTAPB_LPTIM32
  *           @arg @ref FL_RMU_RSTAPB_BSTIM32
  *           @arg @ref FL_RMU_RSTAPB_PGL
  *           @arg @ref FL_RMU_RSTAPB_ATIM
  *           @arg @ref FL_RMU_RSTAPB_TAU1
  *           @arg @ref FL_RMU_RSTAPB_TAU0
  *           @arg @ref FL_RMU_RSTAPB_LPTIM16
  *           @arg @ref FL_RMU_RSTAPB_BSTIM16
  *           @arg @ref FL_RMU_RSTAPB_CANFD1R
  *           @arg @ref FL_RMU_RSTAPB_CANFD1P
  *           @arg @ref FL_RMU_RSTAPB_CANFD1C
  *           @arg @ref FL_RMU_RSTAPB_CANFD0R
  *           @arg @ref FL_RMU_RSTAPB_CANFD0P
  *           @arg @ref FL_RMU_RSTAPB_CANFD0C
  *           @arg @ref FL_RMU_RSTAPB_DAC
  *           @arg @ref FL_RMU_RSTAPB_ADCCR
  *           @arg @ref FL_RMU_RSTAPB_ADC
  *           @arg @ref FL_RMU_RSTAPB_CLM1
  *           @arg @ref FL_RMU_RSTAPB_CLM0
  *           @arg @ref FL_RMU_RSTAPB_SENT1
  *           @arg @ref FL_RMU_RSTAPB_SENT0
  *           @arg @ref FL_RMU_RSTAPB_AES
  *           @arg @ref FL_RMU_RSTAPB_CRC
  *           @arg @ref FL_RMU_RSTAPB_RNG
  *           @arg @ref FL_RMU_RSTAPB_HDIV
  *           @arg @ref FL_RMU_RSTAPB_SVD
  *           @arg @ref FL_RMU_RSTAPB_COMP
  * @retval   None
  */
__STATIC_INLINE void FL_RMU_EnableResetAPBPeripheral(RMU_Type* RMUx, uint32_t peripheral)
{
    if(peripheral <= FL_RMU_RSTAPB_UART5)
    {
        SET_BIT(RMUx->APBRSTCR1, (0x1U << peripheral));
    }
    else
    {
        SET_BIT(RMUx->APBRSTCR2, (0x1U << (peripheral - 32)));
    }
}

/**
  * @brief    Disable AHB Peripheral Reset
  * @rmtoll   AHBRSTCR        FL_RMU_DisableResetAHBPeripheral
  * @param    RMUx RMU instance
  * @param    peripheral This parameter can be one of the following values:
  *           @arg @ref FL_RMU_RSTAHB_DMA
  * @retval   None
  */
__STATIC_INLINE void FL_RMU_DisableResetAHBPeripheral(RMU_Type* RMUx, uint32_t peripheral)
{
    CLEAR_BIT(RMUx->AHBRSTCR, ((peripheral & 0xffffffff) << 0x0U));
}

/**
  * @brief    Disable APB Peripheral Reset1
  * @rmtoll   APBRST        FL_RMU_DisableResetAPBPeripheral
  * @param    RMUx RMU instance
  * @param    peripheral This parameter can be one of the following values:
  *           @arg @ref FL_RMU_RSTAPB_UART5
  *           @arg @ref FL_RMU_RSTAPB_UART4
  *           @arg @ref FL_RMU_RSTAPB_UART3
  *           @arg @ref FL_RMU_RSTAPB_UART2
  *           @arg @ref FL_RMU_RSTAPB_UART1
  *           @arg @ref FL_RMU_RSTAPB_UART0
  *           @arg @ref FL_RMU_RSTAPB_UCIR
  *           @arg @ref FL_RMU_RSTAPB_LPUART2
  *           @arg @ref FL_RMU_RSTAPB_SPI3
  *           @arg @ref FL_RMU_RSTAPB_SPI2
  *           @arg @ref FL_RMU_RSTAPB_SPI1
  *           @arg @ref FL_RMU_RSTAPB_SPI0
  *           @arg @ref FL_RMU_RSTAPB_GPTIM2
  *           @arg @ref FL_RMU_RSTAPB_GPTIM1
  *           @arg @ref FL_RMU_RSTAPB_GPTIM0
  *           @arg @ref FL_RMU_RSTAPB_FSCAN
  *           @arg @ref FL_RMU_RSTAPB_LPUART1
  *           @arg @ref FL_RMU_RSTAPB_LPUART0
  *           @arg @ref FL_RMU_RSTAPB_I2CSMB1
  *           @arg @ref FL_RMU_RSTAPB_I2CSMB0
  *           @arg @ref FL_RMU_RSTAPB_I2C1
  *           @arg @ref FL_RMU_RSTAPB_I2C0
  *           @arg @ref FL_RMU_RSTAPB_LPTIM32
  *           @arg @ref FL_RMU_RSTAPB_BSTIM32
  *           @arg @ref FL_RMU_RSTAPB_PGL
  *           @arg @ref FL_RMU_RSTAPB_ATIM
  *           @arg @ref FL_RMU_RSTAPB_TAU1
  *           @arg @ref FL_RMU_RSTAPB_TAU0
  *           @arg @ref FL_RMU_RSTAPB_LPTIM16
  *           @arg @ref FL_RMU_RSTAPB_BSTIM16
  *           @arg @ref FL_RMU_RSTAPB_CANFD1R
  *           @arg @ref FL_RMU_RSTAPB_CANFD1P
  *           @arg @ref FL_RMU_RSTAPB_CANFD1C
  *           @arg @ref FL_RMU_RSTAPB_CANFD0R
  *           @arg @ref FL_RMU_RSTAPB_CANFD0P
  *           @arg @ref FL_RMU_RSTAPB_CANFD0C
  *           @arg @ref FL_RMU_RSTAPB_DAC
  *           @arg @ref FL_RMU_RSTAPB_ADCCR
  *           @arg @ref FL_RMU_RSTAPB_ADC
  *           @arg @ref FL_RMU_RSTAPB_CLM1
  *           @arg @ref FL_RMU_RSTAPB_CLM0
  *           @arg @ref FL_RMU_RSTAPB_SENT1
  *           @arg @ref FL_RMU_RSTAPB_SENT0
  *           @arg @ref FL_RMU_RSTAPB_AES
  *           @arg @ref FL_RMU_RSTAPB_CRC
  *           @arg @ref FL_RMU_RSTAPB_RNG
  *           @arg @ref FL_RMU_RSTAPB_HDIV
  *           @arg @ref FL_RMU_RSTAPB_SVD
  *           @arg @ref FL_RMU_RSTAPB_COMP
  * @retval   None
  */
__STATIC_INLINE void FL_RMU_DisableResetAPBPeripheral(RMU_Type* RMUx, uint32_t peripheral)
{
    if(peripheral <= FL_RMU_RSTAPB_UART5)
    {
        CLEAR_BIT(RMUx->APBRSTCR1, (0x1U << peripheral));
    }
    else
    {
        CLEAR_BIT(RMUx->APBRSTCR2, (0x1U << (peripheral - 32)));
    }
}

/**
  * @}
  */

/** @defgroup RMU_FL_EF_Init Initialization and de-initialization functions
  * @{
  */


/**
  * @}
  */


/**
  * @}
  */

#ifdef __cplusplus
}
#endif

#endif /* __FM33FG0XXA_FL_RMU_H*/

/*************************Py_Code_Generator Version: 0.1-0.14-0.1 @ 2023-04-12*************************/
/*************************(C) COPYRIGHT Fudan Microelectronics **** END OF FILE*************************/
