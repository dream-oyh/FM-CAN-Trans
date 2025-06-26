/**
  *******************************************************************************************************
  * @file    fm33fg0xxa_fl_sent.h
  * @author  FMSH Application Team
  * @brief   Head file of SENT FL Module
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
#ifndef __FM33FG0XXA_FL_SENT_H
#define __FM33FG0XXA_FL_SENT_H

#ifdef __cplusplus
extern "C" {
#endif
/* Includes -------------------------------------------------------------------------------------------*/
#include "fm33fg0xxa_fl_def.h"
/** @addtogroup FM33FG0XX_FL_Driver
  * @{
  */
/* Exported types -------------------------------------------------------------------------------------*/
/** @defgroup SENT_FL_ES_INIT SENT Exported Init structures
  * @{
  */

/**
  * @brief FL SENT Init Sturcture definition
  */
typedef struct
{
    /*配置接收发送*/
    uint32_t transferDirection;
    /*时钟预分频*/
    uint32_t prescaler;
    /*发送模式*/
    uint32_t transmitMode;
    /*数据Nibble个数*/
    uint32_t dataNibbleNumber;
    /*硬件CRC*/
    uint32_t hardwareCRC;
    /*CRC模式*/
    uint32_t CRCMode;
    /*暂停脉冲*/
    uint32_t pausePulse;
    /*发送帧长度*/
    uint32_t frameTime;
    /*空闲时输出电平*/
    uint32_t idleoutputpulse;
    /*sync长度范围最大值*/
    uint32_t syncPulseMax;
    /*sync长度范围最小值*/
    uint32_t syncPulseMin;
} FL_SENT_InitTypeDef;


/**
  * @brief    
  */
typedef enum
{
    FL_SENT_NIBBLE_STATUS,
    FL_SENT_NIBBLE_DATA_1ST,
    FL_SENT_NIBBLE_DATA_2ST,
    FL_SENT_NIBBLE_DATA_3ST,
    FL_SENT_NIBBLE_DATA_4ST,
    FL_SENT_NIBBLE_DATA_5ST,
    FL_SENT_NIBBLE_DATA_6ST,
    FL_SENT_NIBBLE_CRC
}fl_sent_nib_type;
/**
  * @brief    
  */
typedef enum
{
    FL_SENT_PAUSESTATUS_NO_TXANDRX,
    FL_SENT_PAUSESTATUS_TXANDRX
}fl_sent_pause_type;

/**
  * @brief    
  */
typedef enum
{
    FL_SENT_SYNCSTATUS_NO_TXANDRX,
    FL_SENT_SYNCSTATUS_TXANDRX
}fl_sent_sync_type;


/**
  * @}
  */
/* Exported constants ---------------------------------------------------------------------------------*/
/** @defgroup SENT_FL_Exported_Constants SENT Exported Constants
  * @{
  */

#define    SENT_CR_RXEN_Pos                                       (1U)
#define    SENT_CR_RXEN_Msk                                       (0x1U << SENT_CR_RXEN_Pos)
#define    SENT_CR_RXEN                                           SENT_CR_RXEN_Msk

#define    SENT_CR_TXEN_Pos                                       (0U)
#define    SENT_CR_TXEN_Msk                                       (0x1U << SENT_CR_TXEN_Pos)
#define    SENT_CR_TXEN                                           SENT_CR_TXEN_Msk

#define    SENT_CFGR_FTXIE_Pos                                    (21U)
#define    SENT_CFGR_FTXIE_Msk                                    (0x1U << SENT_CFGR_FTXIE_Pos)
#define    SENT_CFGR_FTXIE                                        SENT_CFGR_FTXIE_Msk

#define    SENT_CFGR_NTXIE_Pos                                    (20U)
#define    SENT_CFGR_NTXIE_Msk                                    (0x1U << SENT_CFGR_NTXIE_Pos)
#define    SENT_CFGR_NTXIE                                        SENT_CFGR_NTXIE_Msk

#define    SENT_CFGR_SYNCIE_Pos                                   (19U)
#define    SENT_CFGR_SYNCIE_Msk                                   (0x1U << SENT_CFGR_SYNCIE_Pos)
#define    SENT_CFGR_SYNCIE                                       SENT_CFGR_SYNCIE_Msk

#define    SENT_CFGR_ERRIE_Pos                                    (18U)
#define    SENT_CFGR_ERRIE_Msk                                    (0x1U << SENT_CFGR_ERRIE_Pos)
#define    SENT_CFGR_ERRIE                                        SENT_CFGR_ERRIE_Msk

#define    SENT_CFGR_FRXIE_Pos                                    (17U)
#define    SENT_CFGR_FRXIE_Msk                                    (0x1U << SENT_CFGR_FRXIE_Pos)
#define    SENT_CFGR_FRXIE                                        SENT_CFGR_FRXIE_Msk

#define    SENT_CFGR_NRXIE_Pos                                    (16U)
#define    SENT_CFGR_NRXIE_Msk                                    (0x1U << SENT_CFGR_NRXIE_Pos)
#define    SENT_CFGR_NRXIE                                        SENT_CFGR_NRXIE_Msk

#define    SENT_CFGR_NIBCNT_Pos                                   (8U)
#define    SENT_CFGR_NIBCNT_Msk                                   (0x7U << SENT_CFGR_NIBCNT_Pos)
#define    SENT_CFGR_NIBCNT                                       SENT_CFGR_NIBCNT_Msk

#define    SENT_CFGR_CRCM_Pos                                     (5U)
#define    SENT_CFGR_CRCM_Msk                                     (0x1U << SENT_CFGR_CRCM_Pos)
#define    SENT_CFGR_CRCM                                         SENT_CFGR_CRCM_Msk

#define    SENT_CFGR_PPEN_Pos                                     (4U)
#define    SENT_CFGR_PPEN_Msk                                     (0x1U << SENT_CFGR_PPEN_Pos)
#define    SENT_CFGR_PPEN                                         SENT_CFGR_PPEN_Msk

#define    SENT_CFGR_CRCEN_Pos                                    (3U)
#define    SENT_CFGR_CRCEN_Msk                                    (0x1U << SENT_CFGR_CRCEN_Pos)
#define    SENT_CFGR_CRCEN                                        SENT_CFGR_CRCEN_Msk

#define    SENT_CFGR_TXPOL_Pos                                    (2U)
#define    SENT_CFGR_TXPOL_Msk                                    (0x1U << SENT_CFGR_TXPOL_Pos)
#define    SENT_CFGR_TXPOL                                        SENT_CFGR_TXPOL_Msk

#define    SENT_CFGR_TXM_Pos                                      (1U)
#define    SENT_CFGR_TXM_Msk                                      (0x1U << SENT_CFGR_TXM_Pos)
#define    SENT_CFGR_TXM                                          SENT_CFGR_TXM_Msk

#define    SENT_CFGR_MOD_Pos                                      (0U)
#define    SENT_CFGR_MOD_Msk                                      (0x1U << SENT_CFGR_MOD_Pos)
#define    SENT_CFGR_MOD                                          SENT_CFGR_MOD_Msk

#define    SENT_PSR_PRESCALER_Pos                                 (0U)
#define    SENT_PSR_PRESCALER_Msk                                 (0xffffU << SENT_PSR_PRESCALER_Pos)
#define    SENT_PSR_PRESCALER                                     SENT_PSR_PRESCALER_Msk

#define    SENT_FTR_FRAMETIME_Pos                                 (0U)
#define    SENT_FTR_FRAMETIME_Msk                                 (0xfffU << SENT_FTR_FRAMETIME_Pos)
#define    SENT_FTR_FRAMETIME                                     SENT_FTR_FRAMETIME_Msk

#define    SENT_SR_NIB_Pos                                        (19U)
#define    SENT_SR_NIB_Msk                                        (0x7U << SENT_SR_NIB_Pos)
#define    SENT_SR_NIB                                            SENT_SR_NIB_Msk

#define    SENT_SR_RXIDLE_Pos                                     (18U)
#define    SENT_SR_RXIDLE_Msk                                     (0x1U << SENT_SR_RXIDLE_Pos)
#define    SENT_SR_RXIDLE                                         SENT_SR_RXIDLE_Msk

#define    SENT_SR_PAUSE_Pos                                      (17U)
#define    SENT_SR_PAUSE_Msk                                      (0x1U << SENT_SR_PAUSE_Pos)
#define    SENT_SR_PAUSE                                          SENT_SR_PAUSE_Msk

#define    SENT_SR_SYNC_Pos                                       (16U)
#define    SENT_SR_SYNC_Msk                                       (0x1U << SENT_SR_SYNC_Pos)
#define    SENT_SR_SYNC                                           SENT_SR_SYNC_Msk

#define    SENT_SR_TCOERR_Pos                                     (13U)
#define    SENT_SR_TCOERR_Msk                                     (0x1U << SENT_SR_TCOERR_Pos)
#define    SENT_SR_TCOERR                                         SENT_SR_TCOERR_Msk

#define    SENT_SR_SSERR_Pos                                      (12U)
#define    SENT_SR_SSERR_Msk                                      (0x1U << SENT_SR_SSERR_Pos)
#define    SENT_SR_SSERR                                          SENT_SR_SSERR_Msk

#define    SENT_SR_NBERR_Pos                                      (11U)
#define    SENT_SR_NBERR_Msk                                      (0x1U << SENT_SR_NBERR_Pos)
#define    SENT_SR_NBERR                                          SENT_SR_NBERR_Msk

#define    SENT_SR_CRCERR_Pos                                     (10U)
#define    SENT_SR_CRCERR_Msk                                     (0x1U << SENT_SR_CRCERR_Pos)
#define    SENT_SR_CRCERR                                         SENT_SR_CRCERR_Msk

#define    SENT_SR_NCNTERR_Pos                                    (9U)
#define    SENT_SR_NCNTERR_Msk                                    (0x1U << SENT_SR_NCNTERR_Pos)
#define    SENT_SR_NCNTERR                                        SENT_SR_NCNTERR_Msk

#define    SENT_SR_SYNCERR_Pos                                    (8U)
#define    SENT_SR_SYNCERR_Msk                                    (0x1U << SENT_SR_SYNCERR_Pos)
#define    SENT_SR_SYNCERR                                        SENT_SR_SYNCERR_Msk

#define    SENT_SR_FTXF_Pos                                       (5U)
#define    SENT_SR_FTXF_Msk                                       (0x1U << SENT_SR_FTXF_Pos)
#define    SENT_SR_FTXF                                           SENT_SR_FTXF_Msk

#define    SENT_SR_NTXF_Pos                                       (4U)
#define    SENT_SR_NTXF_Msk                                       (0x1U << SENT_SR_NTXF_Pos)
#define    SENT_SR_NTXF                                           SENT_SR_NTXF_Msk

#define    SENT_SR_SYNCF_Pos                                      (3U)
#define    SENT_SR_SYNCF_Msk                                      (0x1U << SENT_SR_SYNCF_Pos)
#define    SENT_SR_SYNCF                                          SENT_SR_SYNCF_Msk

#define    SENT_SR_FRXF_Pos                                       (1U)
#define    SENT_SR_FRXF_Msk                                       (0x1U << SENT_SR_FRXF_Pos)
#define    SENT_SR_FRXF                                           SENT_SR_FRXF_Msk

#define    SENT_SR_NRXF_Pos                                       (0U)
#define    SENT_SR_NRXF_Msk                                       (0x1U << SENT_SR_NRXF_Pos)
#define    SENT_SR_NRXF                                           SENT_SR_NRXF_Msk

#define    SENT_DR_CRC_Pos                                        (28U)
#define    SENT_DR_CRC_Msk                                        (0xfU << SENT_DR_CRC_Pos)
#define    SENT_DR_CRC                                            SENT_DR_CRC_Msk

#define    SENT_DR_DATA6_Pos                                      (24U)
#define    SENT_DR_DATA6_Msk                                      (0xfU << SENT_DR_DATA6_Pos)
#define    SENT_DR_DATA6                                          SENT_DR_DATA6_Msk

#define    SENT_DR_DATA5_Pos                                      (20U)
#define    SENT_DR_DATA5_Msk                                      (0xfU << SENT_DR_DATA5_Pos)
#define    SENT_DR_DATA5                                          SENT_DR_DATA5_Msk

#define    SENT_DR_DATA4_Pos                                      (16U)
#define    SENT_DR_DATA4_Msk                                      (0xfU << SENT_DR_DATA4_Pos)
#define    SENT_DR_DATA4                                          SENT_DR_DATA4_Msk

#define    SENT_DR_DATA3_Pos                                      (12U)
#define    SENT_DR_DATA3_Msk                                      (0xfU << SENT_DR_DATA3_Pos)
#define    SENT_DR_DATA3                                          SENT_DR_DATA3_Msk

#define    SENT_DR_DATA2_Pos                                      (8U)
#define    SENT_DR_DATA2_Msk                                      (0xfU << SENT_DR_DATA2_Pos)
#define    SENT_DR_DATA2                                          SENT_DR_DATA2_Msk

#define    SENT_DR_DATA1_Pos                                      (4U)
#define    SENT_DR_DATA1_Msk                                      (0xfU << SENT_DR_DATA1_Pos)
#define    SENT_DR_DATA1                                          SENT_DR_DATA1_Msk

#define    SENT_DR_STATUS_Pos                                     (0U)
#define    SENT_DR_STATUS_Msk                                     (0xfU << SENT_DR_STATUS_Pos)
#define    SENT_DR_STATUS                                         SENT_DR_STATUS_Msk

#define    SENT_SYNC_SYNCMAX_Pos                                  (16U)
#define    SENT_SYNC_SYNCMAX_Msk                                  (0xfffU << SENT_SYNC_SYNCMAX_Pos)
#define    SENT_SYNC_SYNCMAX                                      SENT_SYNC_SYNCMAX_Msk

#define    SENT_SYNC_SYNCMIN_Pos                                  (0U)
#define    SENT_SYNC_SYNCMIN_Msk                                  (0xfffU << SENT_SYNC_SYNCMIN_Pos)
#define    SENT_SYNC_SYNCMIN                                      SENT_SYNC_SYNCMIN_Msk

#define    SENT_RCAL_BASECNT_Pos                                  (16U)
#define    SENT_RCAL_BASECNT_Msk                                  (0x3fU << SENT_RCAL_BASECNT_Pos)
#define    SENT_RCAL_BASECNT                                      SENT_RCAL_BASECNT_Msk

#define    SENT_RCAL_RCAL_Pos                                     (0U)
#define    SENT_RCAL_RCAL_Msk                                     (0xfffU << SENT_RCAL_RCAL_Pos)
#define    SENT_RCAL_RCAL                                         SENT_RCAL_RCAL_Msk


#define    FL_SENT_DATANIBBLES_COUNT_1N                           (0x1U << SENT_CFGR_NIBCNT_Pos)
#define    FL_SENT_DATANIBBLES_COUNT_2N                           (0x2U << SENT_CFGR_NIBCNT_Pos)
#define    FL_SENT_DATANIBBLES_COUNT_3N                           (0x3U << SENT_CFGR_NIBCNT_Pos)
#define    FL_SENT_DATANIBBLES_COUNT_4N                           (0x4U << SENT_CFGR_NIBCNT_Pos)
#define    FL_SENT_DATANIBBLES_COUNT_5N                           (0x5U << SENT_CFGR_NIBCNT_Pos)
#define    FL_SENT_DATANIBBLES_COUNT_6N                           (0x6U << SENT_CFGR_NIBCNT_Pos)

#define    FL_SENT_CRCMODE_RECOMMENDED                            (0x0U << SENT_CFGR_CRCM_Pos)
#define    FL_SENT_CRCMODE_LEGACY                                 (0x1U << SENT_CFGR_CRCM_Pos)

#define    FL_SENT_IDLEOUTPUT_HIGH                                (0x0U << SENT_CFGR_TXPOL_Pos)
#define    FL_SENT_IDLEOUTPUT_LOW                                 (0x1U << SENT_CFGR_TXPOL_Pos)

#define    FL_SENT_TXMODE_SOFTWARE                                (0x0U << SENT_CFGR_TXM_Pos)
#define    FL_SENT_TXMODE_SERIAL                                  (0x1U << SENT_CFGR_TXM_Pos)

#define    FL_SENT_MODE_RX                                        (0x0U << SENT_CFGR_MOD_Pos)
#define    FL_SENT_MODE_TX                                        (0x1U << SENT_CFGR_MOD_Pos)

#define    FL_SENT_NIBBLE_STATUS                                  (0x0U << SENT_SR_NIB_Pos)
#define    FL_SENT_NIBBLE_DATA_1ST                                (0x1U << SENT_SR_NIB_Pos)
#define    FL_SENT_NIBBLE_DATA_2ST                                (0x2U << SENT_SR_NIB_Pos)
#define    FL_SENT_NIBBLE_DATA_3ST                                (0x3U << SENT_SR_NIB_Pos)
#define    FL_SENT_NIBBLE_DATA_4ST                                (0x4U << SENT_SR_NIB_Pos)
#define    FL_SENT_NIBBLE_DATA_5ST                                (0x5U << SENT_SR_NIB_Pos)
#define    FL_SENT_NIBBLE_DATA_6ST                                (0x6U << SENT_SR_NIB_Pos)
#define    FL_SENT_NIBBLE_CRC                                     (0x7U << SENT_SR_NIB_Pos)

#define    FL_SENT_PAUSESTATUS_TXANDRX                             0x1U
#define    FL_SENT_PAUSESTATUS_NO_TXANDRX                          0x0U

#define    FL_SENT_SYNCSTATUS_TXANDRX                              0x1U
#define    FL_SENT_SYNCSTATUS_NO_TXANDRX                           0x0U

/**
  * @}
  */
/* Exported functions ---------------------------------------------------------------------------------*/
/** @defgroup SENT_FL_Exported_Functions SENT Exported Functions
  * @{
  */

/**
  * @brief    SENT receive enable  
  * @rmtoll   CR    RXEN    FL_SENT_EnableRX
  * @param    SENTx SENT instance
  * @retval   None
  */
__STATIC_INLINE void FL_SENT_EnableRX(SENT_Type* SENTx)
{
    SET_BIT(SENTx->CR, SENT_CR_RXEN_Msk);
}

/**
  * @brief    SENT receive disable  
  * @rmtoll   CR    RXEN    FL_SENT_DisableRX
  * @param    SENTx SENT instance
  * @retval   None
  */
__STATIC_INLINE void FL_SENT_DisableRX(SENT_Type* SENTx)
{
    CLEAR_BIT(SENTx->CR, SENT_CR_RXEN_Msk);
}

/**
  * @brief    Get SENT receive enable status
  * @rmtoll   CR    RXEN    FL_SENT_IsEnableRX
  * @param    SENTx SENT instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_SENT_IsEnableRX(SENT_Type* SENTx)
{
    return (uint32_t)(READ_BIT(SENTx->CR, SENT_CR_RXEN_Msk) == SENT_CR_RXEN_Msk);
}

/**
  * @brief    SENT transmit enable  
  * @rmtoll   CR    TXEN    FL_SENT_EnableTX
  * @param    SENTx SENT instance
  * @retval   None
  */
__STATIC_INLINE void FL_SENT_EnableTX(SENT_Type* SENTx)
{
    SET_BIT(SENTx->CR, SENT_CR_TXEN_Msk);
}

/**
  * @brief    SENT transmit disable  
  * @rmtoll   CR    TXEN    FL_SENT_DisableTX
  * @param    SENTx SENT instance
  * @retval   None
  */
__STATIC_INLINE void FL_SENT_DisableTX(SENT_Type* SENTx)
{
    CLEAR_BIT(SENTx->CR, SENT_CR_TXEN_Msk);
}

/**
  * @brief    Get SENT transmit enable status  
  * @rmtoll   CR    TXEN    FL_SENT_IsEnableTX
  * @param    SENTx SENT instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_SENT_IsEnableTX(SENT_Type* SENTx)
{
    return (uint32_t)(READ_BIT(SENTx->CR, SENT_CR_TXEN_Msk) == SENT_CR_TXEN_Msk);
}

/**
  * @brief    Enable SENT Frame Send complete interrupt 
  * @rmtoll   CFGR    FTXIE    FL_SENT_EnableIT_FrameTransmitComplete
  * @param    SENTx SENT instance
  * @retval   None
  */
__STATIC_INLINE void FL_SENT_EnableIT_FrameTransmitComplete(SENT_Type* SENTx)
{
    SET_BIT(SENTx->CFGR, SENT_CFGR_FTXIE_Msk);
}

/**
  * @brief    Disable SENT Frame Send complete interrupt 
  * @rmtoll   CFGR    FTXIE    FL_SENT_DisableIT_FrameTransmitComplete
  * @param    SENTx SENT instance
  * @retval   None
  */
__STATIC_INLINE void FL_SENT_DisableIT_FrameTransmitComplete(SENT_Type* SENTx)
{
    CLEAR_BIT(SENTx->CFGR, SENT_CFGR_FTXIE_Msk);
}

/**
  * @brief    Get SENT Frame Send complete interrupt State 
  * @rmtoll   CFGR    FTXIE    FL_SENT_IsEnabledIT_FrameTransmitComplete
  * @param    SENTx SENT instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_SENT_IsEnabledIT_FrameTransmitComplete(SENT_Type* SENTx)
{
    return (uint32_t)(READ_BIT(SENTx->CFGR, SENT_CFGR_FTXIE_Msk) == SENT_CFGR_FTXIE_Msk);
}

/**
  * @brief    Enable SENT Nibble Send completion interrupt 
  * @rmtoll   CFGR    NTXIE    FL_SENT_EnableIT_NibbleTransmitComplete
  * @param    SENTx SENT instance
  * @retval   None
  */
__STATIC_INLINE void FL_SENT_EnableIT_NibbleTransmitComplete(SENT_Type* SENTx)
{
    SET_BIT(SENTx->CFGR, SENT_CFGR_NTXIE_Msk);
}

/**
  * @brief    Disable SENT Nibble Send completion interrupt
  * @rmtoll   CFGR    NTXIE    FL_SENT_DisableIT_NibbleTransmitComplete
  * @param    SENTx SENT instance
  * @retval   None
  */
__STATIC_INLINE void FL_SENT_DisableIT_NibbleTransmitComplete(SENT_Type* SENTx)
{
    CLEAR_BIT(SENTx->CFGR, SENT_CFGR_NTXIE_Msk);
}

/**
  * @brief    Get SENT Nibble Send completion interrupt State
  * @rmtoll   CFGR    NTXIE    FL_SENT_IsEnabledIT_NibbleTransmitComplete
  * @param    SENTx SENT instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_SENT_IsEnabledIT_NibbleTransmitComplete(SENT_Type* SENTx)
{
    return (uint32_t)(READ_BIT(SENTx->CFGR, SENT_CFGR_NTXIE_Msk) == SENT_CFGR_NTXIE_Msk);
}

/**
  * @brief    Enable SENT Sync pulse Interrupt 
  * @rmtoll   CFGR    SYNCIE    FL_SENT_EnableIT_SyncPulseReceiveCorrectly
  * @param    SENTx SENT instance
  * @retval   None
  */
__STATIC_INLINE void FL_SENT_EnableIT_SyncPulseReceiveCorrectly(SENT_Type* SENTx)
{
    SET_BIT(SENTx->CFGR, SENT_CFGR_SYNCIE_Msk);
}

/**
  * @brief    Disable SENT Sync pulse Interrup
  * @rmtoll   CFGR    SYNCIE    FL_SENT_DisableIT_SyncPulseReceiveCorrectly
  * @param    SENTx SENT instance
  * @retval   None
  */
__STATIC_INLINE void FL_SENT_DisableIT_SyncPulseReceiveCorrectly(SENT_Type* SENTx)
{
    CLEAR_BIT(SENTx->CFGR, SENT_CFGR_SYNCIE_Msk);
}

/**
  * @brief    Get SENT Sync pulse Interrup State
  * @rmtoll   CFGR    SYNCIE    FL_SENT_IsEnabledIT_SyncPulseReceiveCorrectly
  * @param    SENTx SENT instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_SENT_IsEnabledIT_SyncPulseReceiveCorrectly(SENT_Type* SENTx)
{
    return (uint32_t)(READ_BIT(SENTx->CFGR, SENT_CFGR_SYNCIE_Msk) == SENT_CFGR_SYNCIE_Msk);
}

/**
  * @brief    Enable SENT Error event interrupt
  * @rmtoll   CFGR    ERRIE    FL_SENT_EnableIT_ErrEventsOccurred
  * @param    SENTx SENT instance
  * @retval   None
  */
__STATIC_INLINE void FL_SENT_EnableIT_ErrEventsOccurred(SENT_Type* SENTx)
{
    SET_BIT(SENTx->CFGR, SENT_CFGR_ERRIE_Msk);
}

/**
  * @brief    Disable SENT Error event interrupt
  * @rmtoll   CFGR    ERRIE    FL_SENT_DisableIT_ErrEventsOccurred
  * @param    SENTx SENT instance
  * @retval   None
  */
__STATIC_INLINE void FL_SENT_DisableIT_ErrEventsOccurred(SENT_Type* SENTx)
{
    CLEAR_BIT(SENTx->CFGR, SENT_CFGR_ERRIE_Msk);
}

/**
  * @brief    Get SENT Error event interrupt State
  * @rmtoll   CFGR    ERRIE    FL_SENT_IsEnabledIT_ErrEventsOccurred
  * @param    SENTx SENT instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_SENT_IsEnabledIT_ErrEventsOccurred(SENT_Type* SENTx)
{
    return (uint32_t)(READ_BIT(SENTx->CFGR, SENT_CFGR_ERRIE_Msk) == SENT_CFGR_ERRIE_Msk);
}

/**
  * @brief    Enable SENT Frame receives complete interrupt
  * @rmtoll   CFGR    FRXIE    FL_SENT_EnableIT_FrameReceiveComplete
  * @param    SENTx SENT instance
  * @retval   None
  */
__STATIC_INLINE void FL_SENT_EnableIT_FrameReceiveComplete(SENT_Type* SENTx)
{
    SET_BIT(SENTx->CFGR, SENT_CFGR_FRXIE_Msk);
}

/**
  * @brief    Disable SENT Frame receives complete interrupt
  * @rmtoll   CFGR    FRXIE    FL_SENT_DisableIT_FrameReceiveComplete
  * @param    SENTx SENT instance
  * @retval   None
  */
__STATIC_INLINE void FL_SENT_DisableIT_FrameReceiveComplete(SENT_Type* SENTx)
{
    CLEAR_BIT(SENTx->CFGR, SENT_CFGR_FRXIE_Msk);
}

/**
  * @brief    Get SENT Frame receives complete interrupt State
  * @rmtoll   CFGR    FRXIE    FL_SENT_IsEnabledIT_FrameReceiveComplete
  * @param    SENTx SENT instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_SENT_IsEnabledIT_FrameReceiveComplete(SENT_Type* SENTx)
{
    return (uint32_t)(READ_BIT(SENTx->CFGR, SENT_CFGR_FRXIE_Msk) == SENT_CFGR_FRXIE_Msk);
}

/**
  * @brief    Enable SENT Nibble Receiving completion interrupt
  * @rmtoll   CFGR    NRXIE    FL_SENT_EnableIT_NibbleReceiveComplete
  * @param    SENTx SENT instance
  * @retval   None
  */
__STATIC_INLINE void FL_SENT_EnableIT_NibbleReceiveComplete(SENT_Type* SENTx)
{
    SET_BIT(SENTx->CFGR, SENT_CFGR_NRXIE_Msk);
}

/**
  * @brief    Disable SENT Nibble Receiving completion interrupt
  * @rmtoll   CFGR    NRXIE    FL_SENT_DisableIT_NibbleReceiveComplete
  * @param    SENTx SENT instance
  * @retval   None
  */
__STATIC_INLINE void FL_SENT_DisableIT_NibbleReceiveComplete(SENT_Type* SENTx)
{
    CLEAR_BIT(SENTx->CFGR, SENT_CFGR_NRXIE_Msk);
}

/**
  * @brief    Get SENT Nibble Receiving completion interrupt State
  * @rmtoll   CFGR    NRXIE    FL_SENT_IsEnabledIT_NibbleReceiveComplete
  * @param    SENTx SENT instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_SENT_IsEnabledIT_NibbleReceiveComplete(SENT_Type* SENTx)
{
    return (uint32_t)(READ_BIT(SENTx->CFGR, SENT_CFGR_NRXIE_Msk) == SENT_CFGR_NRXIE_Msk);
}

/**
  * @brief    Set Number of Data Nibbles in the frame
  * @rmtoll   CFGR    NIBCNT    FL_SENT_SetDataNibblesCount
  * @param    SENTx SENT instance
  * @param    nibblecount This parameter can be one of the following values:
  *           @arg @ref FL_SENT_DATANIBBLES_COUNT_1N
  *           @arg @ref FL_SENT_DATANIBBLES_COUNT_2N
  *           @arg @ref FL_SENT_DATANIBBLES_COUNT_3N
  *           @arg @ref FL_SENT_DATANIBBLES_COUNT_4N
  *           @arg @ref FL_SENT_DATANIBBLES_COUNT_5N
  *           @arg @ref FL_SENT_DATANIBBLES_COUNT_6N
  * @retval   None
  */
__STATIC_INLINE void FL_SENT_SetDataNibblesCount(SENT_Type* SENTx, uint32_t nibblecount)
{
    MODIFY_REG(SENTx->CFGR, SENT_CFGR_NIBCNT_Msk, nibblecount);
}

/**
  * @brief    Get Number of Data Nibbles in the frame
  * @rmtoll   CFGR    NIBCNT    FL_SENT_GetDataNibblesCount
  * @param    SENTx SENT instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_SENT_DATANIBBLES_COUNT_1N
  *           @arg @ref FL_SENT_DATANIBBLES_COUNT_2N
  *           @arg @ref FL_SENT_DATANIBBLES_COUNT_3N
  *           @arg @ref FL_SENT_DATANIBBLES_COUNT_4N
  *           @arg @ref FL_SENT_DATANIBBLES_COUNT_5N
  *           @arg @ref FL_SENT_DATANIBBLES_COUNT_6N
  */
__STATIC_INLINE uint32_t FL_SENT_GetDataNibblesCount(SENT_Type* SENTx)
{
    return (uint32_t)(READ_BIT(SENTx->CFGR, SENT_CFGR_NIBCNT_Msk) >> SENT_CFGR_NIBCNT_Pos);
}

/**
  * @brief    Set CRC mode selection
  * @rmtoll   CFGR    CRCM    FL_SENT_SetCRCModeSelect
  * @param    SENTx SENT instance
  * @param    mode This parameter can be one of the following values:
  *           @arg @ref FL_SENT_CRCMODE_RECOMMENDED
  *           @arg @ref FL_SENT_CRCMODE_LEGACY
  * @retval   None
  */
__STATIC_INLINE void FL_SENT_SetCRCModeSelect(SENT_Type* SENTx, uint32_t mode)
{
    MODIFY_REG(SENTx->CFGR, SENT_CFGR_CRCM_Msk, mode);
}

/**
  * @brief    Get CRC mode selection
  * @rmtoll   CFGR    CRCM    FL_SENT_GetCRCModeSelect
  * @param    SENTx SENT instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_SENT_CRCMODE_RECOMMENDED
  *           @arg @ref FL_SENT_CRCMODE_LEGACY
  */
__STATIC_INLINE uint32_t FL_SENT_GetCRCModeSelect(SENT_Type* SENTx)
{
    return (uint32_t)(READ_BIT(SENTx->CFGR, SENT_CFGR_CRCM_Msk));
}

/**
  * @brief    Enable Pause pulse
  * @rmtoll   CFGR    PPEN    FL_SENT_EnablePausePulse
  * @param    SENTx SENT instance
  * @retval   None
  */
__STATIC_INLINE void FL_SENT_EnablePausePulse(SENT_Type* SENTx)
{
    SET_BIT(SENTx->CFGR, SENT_CFGR_PPEN_Msk);
}

/**
  * @brief    Disable Pause pulse
  * @rmtoll   CFGR    PPEN    FL_SENT_DisablePausePulse
  * @param    SENTx SENT instance
  * @retval   None
  */
__STATIC_INLINE void FL_SENT_DisablePausePulse(SENT_Type* SENTx)
{
    CLEAR_BIT(SENTx->CFGR, SENT_CFGR_PPEN_Msk);
}

/**
  * @brief    Get Pause pulse State
  * @rmtoll   CFGR    PPEN    FL_SENT_IsEnabledPausePulse
  * @param    SENTx SENT instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_SENT_IsEnabledPausePulse(SENT_Type* SENTx)
{
    return (uint32_t)(READ_BIT(SENTx->CFGR, SENT_CFGR_PPEN_Msk) == SENT_CFGR_PPEN_Msk);
}

/**
  * @brief    Enable Hardware CRC
  * @rmtoll   CFGR    CRCEN    FL_SENT_EnableCRCHardware
  * @param    SENTx SENT instance
  * @retval   None
  */
__STATIC_INLINE void FL_SENT_EnableCRCHardware(SENT_Type* SENTx)
{
    SET_BIT(SENTx->CFGR, SENT_CFGR_CRCEN_Msk);
}

/**
  * @brief    Disable Hardware CRC
  * @rmtoll   CFGR    CRCEN    FL_SENT_DisableCRCHardware
  * @param    SENTx SENT instance
  * @retval   None
  */
__STATIC_INLINE void FL_SENT_DisableCRCHardware(SENT_Type* SENTx)
{
    CLEAR_BIT(SENTx->CFGR, SENT_CFGR_CRCEN_Msk);
}

/**
  * @brief    Get Hardware CRC State
  * @rmtoll   CFGR    CRCEN    FL_SENT_IsEnabledCRCHardware
  * @param    SENTx SENT instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_SENT_IsEnabledCRCHardware(SENT_Type* SENTx)
{
    return (uint32_t)(READ_BIT(SENTx->CFGR, SENT_CFGR_CRCEN_Msk) == SENT_CFGR_CRCEN_Msk);
}

/**
  * @brief    Set the output level in the transmission idle state 
  * @rmtoll   CFGR    TXPOL    FL_SENT_SetIdleTXOutputPulse
  * @param    SENTx SENT instance
  * @param    pulse This parameter can be one of the following values:
  *           @arg @ref FL_SENT_OUTPUT_HIGH
  *           @arg @ref FL_SENT_OUTPUT_LOW
  * @retval   None
  */
__STATIC_INLINE void FL_SENT_SetIdleTXOutputPulse(SENT_Type* SENTx, uint32_t pulse)
{
    MODIFY_REG(SENTx->CFGR, SENT_CFGR_TXPOL_Msk, pulse);
}

/**
  * @brief    Get the output level in the transmission idle state
  * @rmtoll   CFGR    TXPOL    FL_SENT_GetIdleTXOutputPulse
  * @param    SENTx SENT instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_SENT_OUTPUT_HIGH
  *           @arg @ref FL_SENT_OUTPUT_LOW
  */
__STATIC_INLINE uint32_t FL_SENT_GetIdleTXOutputPulse(SENT_Type* SENTx)
{
    return (uint32_t)(READ_BIT(SENTx->CFGR, SENT_CFGR_TXPOL_Msk));
}

/**
  * @brief    Set transmit mode
  * @rmtoll   CFGR    TXM    FL_SENT_SetTXModeSelect
  * @param    SENTx SENT instance
  * @param    mode This parameter can be one of the following values:
  *           @arg @ref FL_SENT_TXMODE_SOFTWARE
  *           @arg @ref FL_SENT_TXMODE_SERIAL
  * @retval   None
  */
__STATIC_INLINE void FL_SENT_SetTXModeSelect(SENT_Type* SENTx, uint32_t mode)
{
    MODIFY_REG(SENTx->CFGR, SENT_CFGR_TXM_Msk, mode);
}

/**
  * @brief    Get transmit mode
  * @rmtoll   CFGR    TXM    FL_SENT_GetTXModeSelect
  * @param    SENTx SENT instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_SENT_TXMODE_SOFTWARE
  *           @arg @ref FL_SENT_TXMODE_SERIAL
  */
__STATIC_INLINE uint32_t FL_SENT_GetTXModeSelect(SENT_Type* SENTx)
{
    return (uint32_t)(READ_BIT(SENTx->CFGR, SENT_CFGR_TXM_Msk));
}

/**
  * @brief    Set SENT work mode
  * @rmtoll   CFGR    MOD    FL_SENT_SetModeSelect
  * @param    SENTx SENT instance
  * @param    mode This parameter can be one of the following values:
  *           @arg @ref FL_SENT_MODE_RX
  *           @arg @ref FL_SENT_MODE_TX
  * @retval   None
  */
__STATIC_INLINE void FL_SENT_SetModeSelect(SENT_Type* SENTx, uint32_t mode)
{
    MODIFY_REG(SENTx->CFGR, SENT_CFGR_MOD_Msk, mode);
}

/**
  * @brief    Get SENT work mode
  * @rmtoll   CFGR    MOD    FL_SENT_GetModeSelect
  * @param    SENTx SENT instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_SENT_MODE_RX
  *           @arg @ref FL_SENT_MODE_TX
  */
__STATIC_INLINE uint32_t FL_SENT_GetModeSelect(SENT_Type* SENTx)
{
    return (uint32_t)(READ_BIT(SENTx->CFGR, SENT_CFGR_MOD_Msk));
}

/**
  * @brief    Write SENT clock Prescaler
  * @rmtoll   PSR    PRESCALER    FL_SENT_WritePrescaler
  * @param    SENTx SENT instance
  * @param    psc 
  * @retval   None
  */
__STATIC_INLINE void FL_SENT_WritePrescaler(SENT_Type* SENTx, uint32_t psc)
{
    MODIFY_REG(SENTx->PSR, (0xffffU << 0U), (psc << 0U));
}

/**
  * @brief    Read SENT clock Prescaler
  * @rmtoll   PSR    PRESCALER    FL_SENT_ReadPrescaler
  * @param    SENTx SENT instance
  * @retval   
  */
__STATIC_INLINE uint32_t FL_SENT_ReadPrescaler(SENT_Type* SENTx)
{
    return (uint32_t)(READ_BIT(SENTx->PSR, (0xffffU << 0U)) >> 0U);
}

/**
  * @brief    Write Send frame length
  * @rmtoll   FTR    FRAMETIME    FL_SENT_WriteFrameTimeLength
  * @param    SENTx SENT instance
  * @param    length 
  * @retval   None
  */
__STATIC_INLINE void FL_SENT_WriteFrameTimeLength(SENT_Type* SENTx, uint32_t length)
{
    MODIFY_REG(SENTx->FTR, (0xfffU << 0U), (length << 0U));
}

/**
  * @brief    Read Send frame length
  * @rmtoll   FTR    FRAMETIME    FL_SENT_ReadFrameTimeLength
  * @param    SENTx SENT instance
  * @retval   
  */
__STATIC_INLINE uint32_t FL_SENT_ReadFrameTimeLength(SENT_Type* SENTx)
{
    return (uint32_t)(READ_BIT(SENTx->FTR, (0xfffU << 0U)) >> 0U);
}

/**
  * @brief    Get Nibble Transmit and Receive status
  * @rmtoll   SR    NIB    FL_SENT_GetTransmitAndReceiveNibbleStatus
  * @param    SENTx SENT instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_SENT_NIBBLE_STATUS
  *           @arg @ref FL_SENT_NIBBLE_DATA_1ST
  *           @arg @ref FL_SENT_NIBBLE_DATA_2ST
  *           @arg @ref FL_SENT_NIBBLE_DATA_3ST
  *           @arg @ref FL_SENT_NIBBLE_DATA_4ST
  *           @arg @ref FL_SENT_NIBBLE_DATA_5ST
  *           @arg @ref FL_SENT_NIBBLE_DATA_6ST
  *           @arg @ref FL_SENT_NIBBLE_CRC
  */
__STATIC_INLINE uint32_t FL_SENT_GetTransmitAndReceiveNibbleStatus(SENT_Type* SENTx)
{
    return (uint32_t)(READ_BIT(SENTx->SR, SENT_SR_NIB_Msk) >> SENT_SR_NIB_Pos);
}

/**
  * @brief    Get Receive Idle status
  * @rmtoll   SR    RXIDLE    FL_SENT_GetRxdleStatus
  * @param    SENTx SENT instance
  * @retval   Returned value can be one of the following values:
  */
__STATIC_INLINE uint32_t FL_SENT_GetRxdleStatus(SENT_Type* SENTx)
{
    return (uint32_t)(READ_BIT(SENTx->SR, SENT_SR_RXIDLE_Msk) >> SENT_SR_RXIDLE_Pos);
}

/**
  * @brief    Get Nibble Transmit and Receive Pause status
  * @rmtoll   SR    PAUSE    FL_SENT_GetTransmitAndReceivePauseStatus
  * @param    SENTx SENT instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_SENT_PAUSESTATUS_TXANDRX
  *           @arg @ref FL_SENT_PAUSESTATUS_NO_TXANDRX
  */
__STATIC_INLINE uint32_t FL_SENT_GetTransmitAndReceivePauseStatus(SENT_Type* SENTx)
{
    return (uint32_t)(READ_BIT(SENTx->SR, SENT_SR_PAUSE_Msk) >> SENT_SR_PAUSE_Pos);
}

/**
  * @brief    Get Nibble Transmit and Receive Sync status
  * @rmtoll   SR    SYNC    FL_SENT_GetTransmitAndReceiveSyncStatus
  * @param    SENTx SENT instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_SENT_SYNCSTATUS_TXANDRX
  *           @arg @ref FL_SENT_SYNCSTATUS_NO_TXANDRX
  */
__STATIC_INLINE uint32_t FL_SENT_GetTransmitAndReceiveSyncStatus(SENT_Type* SENTx)
{
    return (uint32_t)(READ_BIT(SENTx->SR, SENT_SR_SYNC_Msk) >> SENT_SR_SYNC_Pos);
}

/**
  * @brief    Get Tick Counter Overflow Error Tick status
  * @rmtoll   SR    TCOERR    FL_SENT_IsActiveFlag_TickCounterOverflowErr
  * @param    SENTx SENT instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_SENT_IsActiveFlag_TickCounterOverflowErr(SENT_Type* SENTx)
{
    return (uint32_t)(READ_BIT(SENTx->SR, SENT_SR_TCOERR_Msk) >> SENT_SR_TCOERR_Pos);
}

/**
  * @brief    Clear Tick Counter Overflow Error Tick status
  * @rmtoll   SR    TCOERR    FL_SENT_ClearFlag_TickCounterOverflowErr
  * @param    SENTx SENT instance
  * @retval   None
  */
__STATIC_INLINE void FL_SENT_ClearFlag_TickCounterOverflowErr(SENT_Type* SENTx)
{
    WRITE_REG(SENTx->SR, SENT_SR_TCOERR_Msk);
}

/**
  * @brief    Get Continuous Sync (Successive Sync) length error exceeds the range status
  * @rmtoll   SR    SSERR    FL_SENT_IsActiveFlag_SuccessiveSyncErr
  * @param    SENTx SENT instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_SENT_IsActiveFlag_SuccessiveSyncErr(SENT_Type* SENTx)
{
    return (uint32_t)(READ_BIT(SENTx->SR, SENT_SR_SSERR_Msk) == (SENT_SR_SSERR_Msk));
}

/**
  * @brief    Clear Continuous Sync (Successive Sync) length error exceeds the range status
  * @rmtoll   SR    SSERR    FL_SENT_ClearFlag_SuccessiveSyncErr
  * @param    SENTx SENT instance
  * @retval   None
  */
__STATIC_INLINE void FL_SENT_ClearFlag_SuccessiveSyncErr(SENT_Type* SENTx)
{
    WRITE_REG(SENTx->SR, SENT_SR_SSERR_Msk);
}

/**
  * @brief    Get Nibble Ticks Count error
  * @rmtoll   SR    NBERR    FL_SENT_IsActiveFlag_NibbleTicksCountErr
  * @param    SENTx SENT instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_SENT_IsActiveFlag_NibbleTicksCountErr(SENT_Type* SENTx)
{
    return (uint32_t)(READ_BIT(SENTx->SR, SENT_SR_NBERR_Msk) == (SENT_SR_NBERR_Msk));
}

/**
  * @brief    Clear Nibble Ticks Count error
  * @rmtoll   SR    NBERR    FL_SENT_ClearFlag_NibbleTicksCountErr
  * @param    SENTx SENT instance
  * @retval   None
  */
__STATIC_INLINE void FL_SENT_ClearFlag_NibbleTicksCountErr(SENT_Type* SENTx)
{
    WRITE_REG(SENTx->SR, SENT_SR_NBERR_Msk);
}

/**
  * @brief    Get The CRC check error flag
  * @rmtoll   SR    CRCERR    FL_SENT_IsActiveFlag_CRCCheckErr
  * @param    SENTx SENT instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_SENT_IsActiveFlag_CRCCheckErr(SENT_Type* SENTx)
{
    return (uint32_t)(READ_BIT(SENTx->SR, SENT_SR_CRCERR_Msk) == (SENT_SR_CRCERR_Msk));
}

/**
  * @brief    Clear The CRC check error flag
  * @rmtoll   SR    CRCERR    FL_SENT_ClearFlag_CRCCheckErr
  * @param    SENTx SENT instance
  * @retval   None
  */
__STATIC_INLINE void FL_SENT_ClearFlag_CRCCheckErr(SENT_Type* SENTx)
{
    WRITE_REG(SENTx->SR, SENT_SR_CRCERR_Msk);
}

/**
  * @brief    Get The Nibble Number Err State
  * @rmtoll   SR    NCNTERR    FL_SENT_IsActiveFlag_NibblesCountErr
  * @param    SENTx SENT instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_SENT_IsActiveFlag_NibblesCountErr(SENT_Type* SENTx)
{
    return (uint32_t)(READ_BIT(SENTx->SR, SENT_SR_NCNTERR_Msk) == (SENT_SR_NCNTERR_Msk));
}

/**
  * @brief    Clear The Nibble Number Err State
  * @rmtoll   SR    NCNTERR    FL_SENT_ClearFlag_NibblesCountErr
  * @param    SENTx SENT instance
  * @retval   None
  */
__STATIC_INLINE void FL_SENT_ClearFlag_NibblesCountErr(SENT_Type* SENTx)
{
    WRITE_REG(SENTx->SR, SENT_SR_NCNTERR_Msk);
}

/**
  * @brief    Get Sync pulse length State
  * @rmtoll   SR    SYNCERR    FL_SENT_IsActiveFlag_SyncPusleWidth
  * @param    SENTx SENT instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_SENT_IsActiveFlag_SyncPusleWidthErr(SENT_Type* SENTx)
{
    return (uint32_t)(READ_BIT(SENTx->SR, SENT_SR_SYNCERR_Msk) == (SENT_SR_SYNCERR_Msk));
}

/**
  * @brief    Clear Sync pulse length State
  * @rmtoll   SR    SYNCERR    FL_SENT_ClearFlag_SyncPusleWidth
  * @param    SENTx SENT instance
  * @retval   None
  */
__STATIC_INLINE void FL_SENT_ClearFlag_SyncPusleWidthErr(SENT_Type* SENTx)
{
    WRITE_REG(SENTx->SR, SENT_SR_SYNCERR_Msk);
}

/**
  * @brief    Get Frame Transmit completion flag
  * @rmtoll   SR    FTXF    FL_SENT_IsActiveFlag_FrameTransmitComplete
  * @param    SENTx SENT instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_SENT_IsActiveFlag_FrameTransmitComplete(SENT_Type* SENTx)
{
    return (uint32_t)(READ_BIT(SENTx->SR, SENT_SR_FTXF_Msk) == (SENT_SR_FTXF_Msk));
}

/**
  * @brief    Clear Frame Transmit completion flag
  * @rmtoll   SR    FTXF    FL_SENT_ClearFlag_FrameTransmitComplete
  * @param    SENTx SENT instance
  * @retval   None
  */
__STATIC_INLINE void FL_SENT_ClearFlag_FrameTransmitComplete(SENT_Type* SENTx)
{
    WRITE_REG(SENTx->SR, SENT_SR_FTXF_Msk);
}

/**
  * @brief    Get Nibbles Transmit completion flag
  * @rmtoll   SR    NTXF    FL_SENT_IsActiveFlag_NibblesTransmitComplete
  * @param    SENTx SENT instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_SENT_IsActiveFlag_NibblesTransmitComplete(SENT_Type* SENTx)
{
    return (uint32_t)(READ_BIT(SENTx->SR, SENT_SR_NTXF_Msk) == (SENT_SR_NTXF_Msk));
}

/**
  * @brief    Clear Nibbles Transmit completion flag
  * @rmtoll   SR    NTXF    FL_SENT_ClearFlag_NibblesTransmitComplete
  * @param    SENTx SENT instance
  * @retval   None
  */
__STATIC_INLINE void FL_SENT_ClearFlag_NibblesTransmitComplete(SENT_Type* SENTx)
{
    WRITE_REG(SENTx->SR, SENT_SR_NTXF_Msk);
}

/**
  * @brief    Get Sync Receive Complete flag
  * @rmtoll   SR    SYNCF    FL_SENT_IsActiveFlag_SyncReceiveComplete
  * @param    SENTx SENT instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_SENT_IsActiveFlag_SyncReceiveComplete(SENT_Type* SENTx)
{
    return (uint32_t)(READ_BIT(SENTx->SR, SENT_SR_SYNCF_Msk) == (SENT_SR_SYNCF_Msk));
}

/**
  * @brief    Clear Sync Receive Complete flag
  * @rmtoll   SR    SYNCF    FL_SENT_ClearFlag_SyncReceiveComplete
  * @param    SENTx SENT instance
  * @retval   None
  */
__STATIC_INLINE void FL_SENT_ClearFlag_SyncReceiveComplete(SENT_Type* SENTx)
{
    WRITE_REG(SENTx->SR, SENT_SR_SYNCF_Msk);
}

/**
  * @brief    Get Frame Receive Complete flag
  * @rmtoll   SR    FRXF    FL_SENT_IsActiveFlag_FrameReceiveComplete
  * @param    SENTx SENT instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_SENT_IsActiveFlag_FrameReceiveComplete(SENT_Type* SENTx)
{
    return (uint32_t)(READ_BIT(SENTx->SR, SENT_SR_FRXF_Msk) == (SENT_SR_FRXF_Msk));
}

/**
  * @brief    Clear Frame Receive Complete flag
  * @rmtoll   SR    FRXF    FL_SENT_ClearFlag_FrameReceiveComplete
  * @param    SENTx SENT instance
  * @retval   None
  */
__STATIC_INLINE void FL_SENT_ClearFlag_FrameReceiveComplete(SENT_Type* SENTx)
{
    WRITE_REG(SENTx->SR, SENT_SR_FRXF_Msk);
}

/**
  * @brief    Get Nibbles Receive Complete flag
  * @rmtoll   SR    NRXF    FL_SENT_IsActiveFlag_NibblesReceiveComplete
  * @param    SENTx SENT instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_SENT_IsActiveFlag_NibblesReceiveComplete(SENT_Type* SENTx)
{
    return (uint32_t)(READ_BIT(SENTx->SR, SENT_SR_NRXF_Msk) == (SENT_SR_NRXF_Msk));
}

/**
  * @brief    Clear Nibbles Receive Complete flag
  * @rmtoll   SR    NRXF    FL_SENT_ClearFlag_NibblesReceiveComplete
  * @param    SENTx SENT instance
  * @retval   None
  */
__STATIC_INLINE void FL_SENT_ClearFlag_NibblesReceiveComplete(SENT_Type* SENTx)
{
    WRITE_REG(SENTx->SR, SENT_SR_NRXF_Msk);
}

/**
  * @brief    Write CRC nibble
  * @rmtoll   DR    CRC    FL_SENT_WriteNibbleData_CRC
  * @param    SENTx SENT instance
  * @param    nibble 
  * @retval   None
  */
__STATIC_INLINE void FL_SENT_WriteNibbleData_CRC(SENT_Type* SENTx, uint32_t nibble)
{
    MODIFY_REG(SENTx->DR, (0xfU << 28U), (nibble << 28U));
}

/**
  * @brief    Read CRC nibble
  * @rmtoll   DR    CRC    FL_SENT_ReadNibbleData_CRC
  * @param    SENTx SENT instance
  * @retval   
  */
__STATIC_INLINE uint32_t FL_SENT_ReadNibbleData_CRC(SENT_Type* SENTx)
{
    return (uint32_t)(READ_BIT(SENTx->DR, (0xfU << 28U)) >> 28U);
}
/**
  * @brief    Write DATA6 nibble
  * @rmtoll   DR    DATA6    FL_SENT_WriteNibbleData_DATA6
  * @param    SENTx SENT instance
  * @param    nibble 
  * @retval   None
  */
__STATIC_INLINE void FL_SENT_WriteNibbleData_DATA6(SENT_Type* SENTx, uint32_t nibble)
{
    MODIFY_REG(SENTx->DR, (0xfU << 24U), (nibble << 24U));
}

/**
  * @brief    Read DATA6 nibble
  * @rmtoll   DR    DATA6    FL_SENT_ReadNibbleData_DATA6
  * @param    SENTx SENT instance
  * @retval   
  */
__STATIC_INLINE uint32_t FL_SENT_ReadNibbleData_DATA6(SENT_Type* SENTx)
{
    return (uint32_t)(READ_BIT(SENTx->DR, (0xfU << 24U)) >> 24U);
}

/**
  * @brief    Write DATA5 nibble
  * @rmtoll   DR    DATA5    FL_SENT_WriteNibbleData_DATA5
  * @param    SENTx SENT instance
  * @param    nibble 
  * @retval   None
  */
__STATIC_INLINE void FL_SENT_WriteNibbleData_DATA5(SENT_Type* SENTx, uint32_t nibble)
{
    MODIFY_REG(SENTx->DR, (0xfU << 20U), (nibble << 20U));
}

/**
  * @brief    Read DATA5 nibble
  * @rmtoll   DR    DATA5    FL_SENT_ReadNibbleData_DATA5
  * @param    SENTx SENT instance
  * @retval   
  */
__STATIC_INLINE uint32_t FL_SENT_ReadNibbleData_DATA5(SENT_Type* SENTx)
{
    return (uint32_t)(READ_BIT(SENTx->DR, (0xfU << 20U)) >> 20U);
}

/**
  * @brief    Write DATA4 nibble
  * @rmtoll   DR    DATA4    FL_SENT_WriteNibbleData_DATA4
  * @param    SENTx SENT instance
  * @param    nibble 
  * @retval   None
  */
__STATIC_INLINE void FL_SENT_WriteNibbleData_DATA4(SENT_Type* SENTx, uint32_t nibble)
{
    MODIFY_REG(SENTx->DR, (0xfU << 16U), (nibble << 16U));
}

/**
  * @brief    Read DATA4 nibble
  * @rmtoll   DR    DATA4    FL_SENT_ReadNibbleData_DATA4
  * @param    SENTx SENT instance
  * @retval   
  */
__STATIC_INLINE uint32_t FL_SENT_ReadNibbleData_DATA4(SENT_Type* SENTx)
{
    return (uint32_t)(READ_BIT(SENTx->DR, (0xfU << 16U)) >> 16U);
}

/**
  * @brief    Write DATA3 nibble
  * @rmtoll   DR    DATA3    FL_SENT_WriteNibbleData_DATA3
  * @param    SENTx SENT instance
  * @param    nibble 
  * @retval   None
  */
__STATIC_INLINE void FL_SENT_WriteNibbleData_DATA3(SENT_Type* SENTx, uint32_t nibble)
{
    MODIFY_REG(SENTx->DR, (0xfU << 12U), (nibble << 12U));
}

/**
  * @brief    Read DATA3 nibble
  * @rmtoll   DR    DATA3    FL_SENT_ReadNibbleData_DATA3
  * @param    SENTx SENT instance
  * @retval   
  */
__STATIC_INLINE uint32_t FL_SENT_ReadNibbleData_DATA3(SENT_Type* SENTx)
{
    return (uint32_t)(READ_BIT(SENTx->DR, (0xfU << 12U)) >> 12U);
}

/**
  * @brief    Write DATA2 nibble
  * @rmtoll   DR    DATA2    FL_SENT_WriteNibbleData_DATA2
  * @param    SENTx SENT instance
  * @param    nibble 
  * @retval   None
  */
__STATIC_INLINE void FL_SENT_WriteNibbleData_DATA2(SENT_Type* SENTx, uint32_t nibble)
{
    MODIFY_REG(SENTx->DR, (0xfU << 8U), (nibble << 8U));
}

/**
  * @brief    Read DATA2 nibble
  * @rmtoll   DR    DATA2    FL_SENT_ReadNibbleData_DATA2
  * @param    SENTx SENT instance
  * @retval   
  */
__STATIC_INLINE uint32_t FL_SENT_ReadNibbleData_DATA2(SENT_Type* SENTx)
{
    return (uint32_t)(READ_BIT(SENTx->DR, (0xfU << 8U)) >> 8U);
}

/**
  * @brief    Write DATA1 nibble
  * @rmtoll   DR    DATA1    FL_SENT_WriteNibbleData_DATA1
  * @param    SENTx SENT instance
  * @param    nibble 
  * @retval   None
  */
__STATIC_INLINE void FL_SENT_WriteNibbleData_DATA1(SENT_Type* SENTx, uint32_t nibble)
{
    MODIFY_REG(SENTx->DR, (0xfU << 4U), (nibble << 4U));
}

/**
  * @brief    Read DATA1 nibble
  * @rmtoll   DR    DATA1    FL_SENT_ReadNibbleData_DATA1
  * @param    SENTx SENT instance
  * @retval   
  */
__STATIC_INLINE uint32_t FL_SENT_ReadNibbleData_DATA1(SENT_Type* SENTx)
{
    return (uint32_t)(READ_BIT(SENTx->DR, (0xfU << 4U)) >> 4U);
}

/**
  * @brief    Write STATUS nibble
  * @rmtoll   DR    STATUS    FL_SENT_WriteNibbleData_STATUS
  * @param    SENTx SENT instance
  * @param    nibble 
  * @retval   None
  */
__STATIC_INLINE void FL_SENT_WriteNibbleData_STATUS(SENT_Type* SENTx, uint32_t nibble)
{
    MODIFY_REG(SENTx->DR, (0xfU << 0U), (nibble << 0U));
}

/**
  * @brief    Read STATUS nibble
  * @rmtoll   DR    STATUS    FL_SENT_ReadNibbleData_STATUS
  * @param    SENTx SENT instance
  * @retval   
  */
__STATIC_INLINE uint32_t FL_SENT_ReadNibbleData_STATUS(SENT_Type* SENTx)
{
    return (uint32_t)(READ_BIT(SENTx->DR, (0xfU << 0U)) >> 0U);
}

/**
  * @brief    Write DR Register data
  * @rmtoll   DR    FL_SENT_WriteDataRegister
  * @param    SENTx SENT instance
  * @param    nibble 
  * @retval   None
  */
__STATIC_INLINE void FL_SENT_WriteDataRegister(SENT_Type* SENTx, uint32_t data)
{
    MODIFY_REG(SENTx->DR, (0xffffffffU << 0U), (data << 0U));
}

/**
  * @brief    Read DR Register data
  * @rmtoll   DR    FL_SENT_ReadDataRegister
  * @param    SENTx SENT instance
  * @retval   
  */
__STATIC_INLINE uint32_t FL_SENT_ReadDataRegister(SENT_Type* SENTx)
{
    return (uint32_t)(READ_BIT(SENTx->DR, (0xffffffffU << 0U)) >> 0U);
}

/**
  * @brief    Write the Max Length of Sync
  * @rmtoll   SYNC    SYNCMAX    FL_SENT_WriteSyncMaxLength
  * @param    SENTx SENT instance
  * @param    length 
  * @retval   None
  */
__STATIC_INLINE void FL_SENT_WriteSyncMaxLength(SENT_Type* SENTx, uint32_t length)
{
    MODIFY_REG(SENTx->SYNC, (0xfffU << 16U), (length << 16U));
}

/**
  * @brief    Read the Max Length of Sync
  * @rmtoll   SYNC    SYNCMAX    FL_SENT_ReadSyncMaxLength
  * @param    SENTx SENT instance
  * @retval   
  */
__STATIC_INLINE uint32_t FL_SENT_ReadSyncMaxLength(SENT_Type* SENTx)
{
    return (uint32_t)(READ_BIT(SENTx->SYNC, (0xfffU << 16U)) >> 16U);
}

/**
  * @brief    Write the Min Length of Sync
  * @rmtoll   SYNC    SYNCMIN    FL_SENT_WriteSyncMinLength
  * @param    SENTx SENT instance
  * @param    length 
  * @retval   None
  */
__STATIC_INLINE void FL_SENT_WriteSyncMinLength(SENT_Type* SENTx, uint32_t length)
{
    MODIFY_REG(SENTx->SYNC, (0xfffU << 0U), (length << 0U));
}

/**
  * @brief    Read the Min Length of Sync
  * @rmtoll   SYNC    SYNCMIN    FL_SENT_ReadSyncMinLength
  * @param    SENTx SENT instance
  * @retval   
  */
__STATIC_INLINE uint32_t FL_SENT_ReadSyncMinLength(SENT_Type* SENTx)
{
    return (uint32_t)(READ_BIT(SENTx->SYNC, (0xfffU << 0U)) >> 0U);
}


/**
  * @brief    Read Sync Base Tick Time
  * @rmtoll   RCAL    BASECNT    FL_SENT_ReadSyncBaseTickTime
  * @param    SENTx SENT instance
  * @retval   
  */
__STATIC_INLINE uint32_t FL_SENT_ReadSyncBaseTickTime(SENT_Type* SENTx)
{
    return (uint32_t)(READ_BIT(SENTx->RCAL, (0x3fU << 16U)) >> 16U);
}

/**
  * @brief    Read Sync Calibration
  * @rmtoll   RCAL    RCAL    FL_SENT_ReadSyncCalibrationPulse
  * @param    SENTx SENT instance
  * @retval   
  */
__STATIC_INLINE uint32_t FL_SENT_ReadSyncCalibrationPulse(SENT_Type* SENTx)
{
    return (uint32_t)(READ_BIT(SENTx->RCAL, (0xfffU << 0U)) >> 0U);
}
/**
  * @}
  */

/** @defgroup SENT_FL_EF_Init Initialization and de-initialization functions
  * @{
  */
FL_ErrorStatus FL_SENT_DeInit(SENT_Type *SENTx);
FL_ErrorStatus FL_SENT_Init(SENT_Type *SENTx, FL_SENT_InitTypeDef *initStruct);
void FL_SENT_StructInit(FL_SENT_InitTypeDef *initStruct);

/**
  * @}
  */


/**
  * @}
  */

#ifdef __cplusplus
}
#endif

#endif /* __FM33FG0XXA_FL_SENT_H*/

/*************************Py_Code_Generator Version: 0.1-0.14-0.1 @ 2023-05-11*************************/
/*************************(C) COPYRIGHT Fudan Microelectronics **** END OF FILE*************************/
