 /**   
  *******************************************************************************************************
  * @file    fm33fg0xxa_fl_sfu.h
  * @author  FMSH Application Team
  * @brief   Head file of SFU FL Module 
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
#ifndef __FM33FG0XXA_FL_SFU_H
#define __FM33FG0XXA_FL_SFU_H

#ifdef __cplusplus
extern "C" {
#endif
/* Includes -------------------------------------------------------------------------------------------*/
#include "fm33fg0xxa_fl_def.h"
/** @addtogroup FM33FG0XXA_FL_Driver
  * @{
  */
/* Exported types -------------------------------------------------------------------------------------*/
/** @defgroup SFU_FL_ES_INIT SFU Exported Init structures
  * @{
  */

/**
  * @brief FL SFU Init Sturcture definition
  */

/**
  * @}
  */
/* Exported constants ---------------------------------------------------------------------------------*/
/** @defgroup SFU_FL_Exported_Constants SFU Exported Constants
  * @{
  */

#define    SFU_MAPCR_WKP_Pos                                      (26U)
#define    SFU_MAPCR_WKP_Msk                                      (0x1U << SFU_MAPCR_WKP_Pos)
#define    SFU_MAPCR_WKP                                          SFU_MAPCR_WKP_Msk

#define    SFU_MAPCR_EXTIP_Pos                                    (25U)
#define    SFU_MAPCR_EXTIP_Msk                                    (0x1U << SFU_MAPCR_EXTIP_Pos)
#define    SFU_MAPCR_EXTIP                                        SFU_MAPCR_EXTIP_Msk

#define    SFU_MAPCR_GPIOIP_Pos                                   (24U)
#define    SFU_MAPCR_GPIOIP_Msk                                   (0x1U << SFU_MAPCR_GPIOIP_Pos)
#define    SFU_MAPCR_GPIOIP                                       SFU_MAPCR_GPIOIP_Msk

#define    SFU_MAPCR_GPIOHP_Pos                                   (23U)
#define    SFU_MAPCR_GPIOHP_Msk                                   (0x1U << SFU_MAPCR_GPIOHP_Pos)
#define    SFU_MAPCR_GPIOHP                                       SFU_MAPCR_GPIOHP_Msk

#define    SFU_MAPCR_GPIOGP_Pos                                   (22U)
#define    SFU_MAPCR_GPIOGP_Msk                                   (0x1U << SFU_MAPCR_GPIOGP_Pos)
#define    SFU_MAPCR_GPIOGP                                       SFU_MAPCR_GPIOGP_Msk

#define    SFU_MAPCR_GPIOFP_Pos                                   (21U)
#define    SFU_MAPCR_GPIOFP_Msk                                   (0x1U << SFU_MAPCR_GPIOFP_Pos)
#define    SFU_MAPCR_GPIOFP                                       SFU_MAPCR_GPIOFP_Msk

#define    SFU_MAPCR_GPIOEP_Pos                                   (20U)
#define    SFU_MAPCR_GPIOEP_Msk                                   (0x1U << SFU_MAPCR_GPIOEP_Pos)
#define    SFU_MAPCR_GPIOEP                                       SFU_MAPCR_GPIOEP_Msk

#define    SFU_MAPCR_GPIODP_Pos                                   (19U)
#define    SFU_MAPCR_GPIODP_Msk                                   (0x1U << SFU_MAPCR_GPIODP_Pos)
#define    SFU_MAPCR_GPIODP                                       SFU_MAPCR_GPIODP_Msk

#define    SFU_MAPCR_GPIOCP_Pos                                   (18U)
#define    SFU_MAPCR_GPIOCP_Msk                                   (0x1U << SFU_MAPCR_GPIOCP_Pos)
#define    SFU_MAPCR_GPIOCP                                       SFU_MAPCR_GPIOCP_Msk

#define    SFU_MAPCR_GPIOBP_Pos                                   (17U)
#define    SFU_MAPCR_GPIOBP_Msk                                   (0x1U << SFU_MAPCR_GPIOBP_Pos)
#define    SFU_MAPCR_GPIOBP                                       SFU_MAPCR_GPIOBP_Msk

#define    SFU_MAPCR_GPIOAP_Pos                                   (16U)
#define    SFU_MAPCR_GPIOAP_Msk                                   (0x1U << SFU_MAPCR_GPIOAP_Pos)
#define    SFU_MAPCR_GPIOAP                                       SFU_MAPCR_GPIOAP_Msk

#define    SFU_MAPCR_CLM1P_Pos                                    (13U)
#define    SFU_MAPCR_CLM1P_Msk                                    (0x1U << SFU_MAPCR_CLM1P_Pos)
#define    SFU_MAPCR_CLM1P                                        SFU_MAPCR_CLM1P_Msk

#define    SFU_MAPCR_CLM0P_Pos                                    (12U)
#define    SFU_MAPCR_CLM0P_Msk                                    (0x1U << SFU_MAPCR_CLM0P_Pos)
#define    SFU_MAPCR_CLM0P                                        SFU_MAPCR_CLM0P_Msk

#define    SFU_MAPCR_CMPP_Pos                                     (11U)
#define    SFU_MAPCR_CMPP_Msk                                     (0x1U << SFU_MAPCR_CMPP_Pos)
#define    SFU_MAPCR_CMPP                                         SFU_MAPCR_CMPP_Msk

#define    SFU_MAPCR_WWP_Pos                                      (10U)
#define    SFU_MAPCR_WWP_Msk                                      (0x1U << SFU_MAPCR_WWP_Pos)
#define    SFU_MAPCR_WWP                                          SFU_MAPCR_WWP_Msk

#define    SFU_MAPCR_IWP_Pos                                      (9U)
#define    SFU_MAPCR_IWP_Msk                                      (0x1U << SFU_MAPCR_IWP_Pos)
#define    SFU_MAPCR_IWP                                          SFU_MAPCR_IWP_Msk

#define    SFU_MAPCR_NVMP_Pos                                     (8U)
#define    SFU_MAPCR_NVMP_Msk                                     (0x1U << SFU_MAPCR_NVMP_Pos)
#define    SFU_MAPCR_NVMP                                         SFU_MAPCR_NVMP_Msk

#define    SFU_MAPCR_MAP_SEL_Pos                                  (7U)
#define    SFU_MAPCR_MAP_SEL_Msk                                  (0x1U << SFU_MAPCR_MAP_SEL_Pos)
#define    SFU_MAPCR_MAP_SEL                                      SFU_MAPCR_MAP_SEL_Msk

#define    SFU_MAPCR_RCP_Pos                                      (6U)
#define    SFU_MAPCR_RCP_Msk                                      (0x1U << SFU_MAPCR_RCP_Pos)
#define    SFU_MAPCR_RCP                                          SFU_MAPCR_RCP_Msk

#define    SFU_MAPCR_SVDP_Pos                                     (5U)
#define    SFU_MAPCR_SVDP_Msk                                     (0x1U << SFU_MAPCR_SVDP_Pos)
#define    SFU_MAPCR_SVDP                                         SFU_MAPCR_SVDP_Msk

#define    SFU_MAPCR_CCP_Pos                                      (4U)
#define    SFU_MAPCR_CCP_Msk                                      (0x1U << SFU_MAPCR_CCP_Pos)
#define    SFU_MAPCR_CCP                                          SFU_MAPCR_CCP_Msk

#define    SFU_MAPCR_RAMWP_Pos                                    (1U)
#define    SFU_MAPCR_RAMWP_Msk                                    (0x3U << SFU_MAPCR_RAMWP_Pos)
#define    SFU_MAPCR_RAMWP                                        SFU_MAPCR_RAMWP_Msk

#define    SFU_MAPCR_MAP_EN_Pos                                   (0U)
#define    SFU_MAPCR_MAP_EN_Msk                                   (0x1U << SFU_MAPCR_MAP_EN_Pos)
#define    SFU_MAPCR_MAP_EN                                       SFU_MAPCR_MAP_EN_Msk

#define    SFU_MAPSR_MAP_IF_Pos                                   (0U)
#define    SFU_MAPSR_MAP_IF_Msk                                   (0x1U << SFU_MAPSR_MAP_IF_Pos)
#define    SFU_MAPSR_MAP_IF                                       SFU_MAPSR_MAP_IF_Msk






#define    FL_SFU_MAP_SELECT_NMI                                  (0x0U << SFU_MAPCR_MAP_SEL_Pos)
#define    FL_SFU_MAP_SELECT_RESET                                (0x1U << SFU_MAPCR_MAP_SEL_Pos)


#define    FL_SFU_RAMWP_SIZE_NONE                                 (0x0U << SFU_MAPCR_RAMWP_Pos)
#define    FL_SFU_RAMWP_SIZE_1K                                   (0x1U << SFU_MAPCR_RAMWP_Pos)
#define    FL_SFU_RAMWP_SIZE_2K                                   (0x2U << SFU_MAPCR_RAMWP_Pos)
#define    FL_SFU_RAMWP_SIZE_4K                                   (0x3U << SFU_MAPCR_RAMWP_Pos)


/**
  * @}
  */
/* Exported functions ---------------------------------------------------------------------------------*/
/** @defgroup SFU_FL_Exported_Functions SFU Exported Functions
  * @{
  */

/**
  * @brief    Enable WKUP Register Write Protection
  * @rmtoll   MAPCR    WKP    FL_SFU_EnableWKUPWriteProtection
  * @param    SFUx SFU instance
  * @retval   None
  */
__STATIC_INLINE void FL_SFU_EnableWKUPWriteProtection(SFU_Type* SFUx)
{
    SET_BIT(SFUx->MAPCR, SFU_MAPCR_WKP_Msk);
}

/**
  * @brief    Get WKUP Register Write Protection Enable Status
  * @rmtoll   MAPCR    WKP    FL_SFU_IsEnabledWKUPWriteProtection
  * @param    SFUx SFU instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_SFU_IsEnabledWKUPWriteProtection(SFU_Type* SFUx)
{
    return (uint32_t)(READ_BIT(SFUx->MAPCR, SFU_MAPCR_WKP_Msk) == SFU_MAPCR_WKP_Msk);
}

/**
  * @brief    Disable WKUP Register Write Protection
  * @rmtoll   MAPCR    WKP    FL_SFU_DisableWKUPWriteProtection
  * @param    SFUx SFU instance
  * @retval   None
  */
__STATIC_INLINE void FL_SFU_DisableWKUPWriteProtection(SFU_Type* SFUx)
{
    CLEAR_BIT(SFUx->MAPCR, SFU_MAPCR_WKP_Msk);
}

/**
  * @brief    Enable EXTI Register Write Protection
  * @rmtoll   MAPCR    EXTIP    FL_SFU_EnableEXTIWriteProtection
  * @param    SFUx SFU instance
  * @retval   None
  */
__STATIC_INLINE void FL_SFU_EnableEXTIWriteProtection(SFU_Type* SFUx)
{
    SET_BIT(SFUx->MAPCR, SFU_MAPCR_EXTIP_Msk);
}

/**
  * @brief    Get EXTI Register Write Protection Enable Status
  * @rmtoll   MAPCR    EXTIP    FL_SFU_IsEnabledEXTIWriteProtection
  * @param    SFUx SFU instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_SFU_IsEnabledEXTIWriteProtection(SFU_Type* SFUx)
{
    return (uint32_t)(READ_BIT(SFUx->MAPCR, SFU_MAPCR_EXTIP_Msk) == SFU_MAPCR_EXTIP_Msk);
}

/**
  * @brief    Disable EXTI Register Write Protection
  * @rmtoll   MAPCR    EXTIP    FL_SFU_DisableEXTIWriteProtection
  * @param    SFUx SFU instance
  * @retval   None
  */
__STATIC_INLINE void FL_SFU_DisableEXTIWriteProtection(SFU_Type* SFUx)
{
    CLEAR_BIT(SFUx->MAPCR, SFU_MAPCR_EXTIP_Msk);
}

/**
  * @brief    Enable GPIOI Register Write Protection
  * @rmtoll   MAPCR    GPIOIP    FL_SFU_EnableGPIOIWriteProtection
  * @param    SFUx SFU instance
  * @retval   None
  */
__STATIC_INLINE void FL_SFU_EnableGPIOIWriteProtection(SFU_Type* SFUx)
{
    SET_BIT(SFUx->MAPCR, SFU_MAPCR_GPIOIP_Msk);
}

/**
  * @brief    Get GPIOI Register Write Protection Enable Status
  * @rmtoll   MAPCR    GPIOIP    FL_SFU_IsEnabledGPIOIWriteProtection
  * @param    SFUx SFU instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_SFU_IsEnabledGPIOIWriteProtection(SFU_Type* SFUx)
{
    return (uint32_t)(READ_BIT(SFUx->MAPCR, SFU_MAPCR_GPIOIP_Msk) == SFU_MAPCR_GPIOIP_Msk);
}

/**
  * @brief    Disable GPIOI Register Write Protection
  * @rmtoll   MAPCR    GPIOIP    FL_SFU_DisableGPIOIWriteProtection
  * @param    SFUx SFU instance
  * @retval   None
  */
__STATIC_INLINE void FL_SFU_DisableGPIOIWriteProtection(SFU_Type* SFUx)
{
    CLEAR_BIT(SFUx->MAPCR, SFU_MAPCR_GPIOIP_Msk);
}

/**
  * @brief    Enable GPIOH Register Write Protection
  * @rmtoll   MAPCR    GPIOHP    FL_SFU_EnableGPIOHWriteProtection
  * @param    SFUx SFU instance
  * @retval   None
  */
__STATIC_INLINE void FL_SFU_EnableGPIOHWriteProtection(SFU_Type* SFUx)
{
    SET_BIT(SFUx->MAPCR, SFU_MAPCR_GPIOHP_Msk);
}

/**
  * @brief    Get GPIOH Register Write Protection Enable Status
  * @rmtoll   MAPCR    GPIOHP    FL_SFU_IsEnabledGPIOHWriteProtection
  * @param    SFUx SFU instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_SFU_IsEnabledGPIOHWriteProtection(SFU_Type* SFUx)
{
    return (uint32_t)(READ_BIT(SFUx->MAPCR, SFU_MAPCR_GPIOHP_Msk) == SFU_MAPCR_GPIOHP_Msk);
}

/**
  * @brief    Disable GPIOH Register Write Protection
  * @rmtoll   MAPCR    GPIOHP    FL_SFU_DisableGPIOHWriteProtection
  * @param    SFUx SFU instance
  * @retval   None
  */
__STATIC_INLINE void FL_SFU_DisableGPIOHWriteProtection(SFU_Type* SFUx)
{
    CLEAR_BIT(SFUx->MAPCR, SFU_MAPCR_GPIOHP_Msk);
}

/**
  * @brief    Enable GPIOG Register Write Protection
  * @rmtoll   MAPCR    GPIOGP    FL_SFU_EnableGPIOGWriteProtection
  * @param    SFUx SFU instance
  * @retval   None
  */
__STATIC_INLINE void FL_SFU_EnableGPIOGWriteProtection(SFU_Type* SFUx)
{
    SET_BIT(SFUx->MAPCR, SFU_MAPCR_GPIOGP_Msk);
}

/**
  * @brief    Get GPIOG Register Write Protection Enable Status
  * @rmtoll   MAPCR    GPIOGP    FL_SFU_IsEnabledGPIOGWriteProtection
  * @param    SFUx SFU instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_SFU_IsEnabledGPIOGWriteProtection(SFU_Type* SFUx)
{
    return (uint32_t)(READ_BIT(SFUx->MAPCR, SFU_MAPCR_GPIOGP_Msk) == SFU_MAPCR_GPIOGP_Msk);
}

/**
  * @brief    Disable GPIOG Register Write Protection
  * @rmtoll   MAPCR    GPIOGP    FL_SFU_DisableGPIOGWriteProtection
  * @param    SFUx SFU instance
  * @retval   None
  */
__STATIC_INLINE void FL_SFU_DisableGPIOGWriteProtection(SFU_Type* SFUx)
{
    CLEAR_BIT(SFUx->MAPCR, SFU_MAPCR_GPIOGP_Msk);
}

/**
  * @brief    Enable GPIOF Register Write Protection
  * @rmtoll   MAPCR    GPIOFP    FL_SFU_EnableGPIOFWriteProtection
  * @param    SFUx SFU instance
  * @retval   None
  */
__STATIC_INLINE void FL_SFU_EnableGPIOFWriteProtection(SFU_Type* SFUx)
{
    SET_BIT(SFUx->MAPCR, SFU_MAPCR_GPIOFP_Msk);
}

/**
  * @brief    Get GPIOF Register Write Protection Enable Status
  * @rmtoll   MAPCR    GPIOFP    FL_SFU_IsEnabledGPIOFWriteProtection
  * @param    SFUx SFU instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_SFU_IsEnabledGPIOFWriteProtection(SFU_Type* SFUx)
{
    return (uint32_t)(READ_BIT(SFUx->MAPCR, SFU_MAPCR_GPIOFP_Msk) == SFU_MAPCR_GPIOFP_Msk);
}

/**
  * @brief    Disable GPIOF Register Write Protection
  * @rmtoll   MAPCR    GPIOFP    FL_SFU_DisableGPIOFWriteProtection
  * @param    SFUx SFU instance
  * @retval   None
  */
__STATIC_INLINE void FL_SFU_DisableGPIOFWriteProtection(SFU_Type* SFUx)
{
    CLEAR_BIT(SFUx->MAPCR, SFU_MAPCR_GPIOFP_Msk);
}

/**
  * @brief    Enable GPIOE Register Write Protection
  * @rmtoll   MAPCR    GPIOEP    FL_SFU_EnableGPIOEWriteProtection
  * @param    SFUx SFU instance
  * @retval   None
  */
__STATIC_INLINE void FL_SFU_EnableGPIOEWriteProtection(SFU_Type* SFUx)
{
    SET_BIT(SFUx->MAPCR, SFU_MAPCR_GPIOEP_Msk);
}

/**
  * @brief    Get GPIOE Register Write Protection Enable Status
  * @rmtoll   MAPCR    GPIOEP    FL_SFU_IsEnabledGPIOEWriteProtection
  * @param    SFUx SFU instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_SFU_IsEnabledGPIOEWriteProtection(SFU_Type* SFUx)
{
    return (uint32_t)(READ_BIT(SFUx->MAPCR, SFU_MAPCR_GPIOEP_Msk) == SFU_MAPCR_GPIOEP_Msk);
}

/**
  * @brief    Disable GPIOE Register Write Protection
  * @rmtoll   MAPCR    GPIOEP    FL_SFU_DisableGPIOEWriteProtection
  * @param    SFUx SFU instance
  * @retval   None
  */
__STATIC_INLINE void FL_SFU_DisableGPIOEWriteProtection(SFU_Type* SFUx)
{
    CLEAR_BIT(SFUx->MAPCR, SFU_MAPCR_GPIOEP_Msk);
}

/**
  * @brief    Enable GPIOD Register Write Protection
  * @rmtoll   MAPCR    GPIODP    FL_SFU_EnableGPIODWriteProtection
  * @param    SFUx SFU instance
  * @retval   None
  */
__STATIC_INLINE void FL_SFU_EnableGPIODWriteProtection(SFU_Type* SFUx)
{
    SET_BIT(SFUx->MAPCR, SFU_MAPCR_GPIODP_Msk);
}

/**
  * @brief    Get GPIOD Register Write Protection Enable Status
  * @rmtoll   MAPCR    GPIODP    FL_SFU_IsEnabledGPIODWriteProtection
  * @param    SFUx SFU instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_SFU_IsEnabledGPIODWriteProtection(SFU_Type* SFUx)
{
    return (uint32_t)(READ_BIT(SFUx->MAPCR, SFU_MAPCR_GPIODP_Msk) == SFU_MAPCR_GPIODP_Msk);
}

/**
  * @brief    Disable GPIOD Register Write Protection
  * @rmtoll   MAPCR    GPIODP    FL_SFU_DisableGPIODWriteProtection
  * @param    SFUx SFU instance
  * @retval   None
  */
__STATIC_INLINE void FL_SFU_DisableGPIODWriteProtection(SFU_Type* SFUx)
{
    CLEAR_BIT(SFUx->MAPCR, SFU_MAPCR_GPIODP_Msk);
}

/**
  * @brief    Enable GPIOC Register Write Protection
  * @rmtoll   MAPCR    GPIOCP    FL_SFU_EnableGPIOCWriteProtection
  * @param    SFUx SFU instance
  * @retval   None
  */
__STATIC_INLINE void FL_SFU_EnableGPIOCWriteProtection(SFU_Type* SFUx)
{
    SET_BIT(SFUx->MAPCR, SFU_MAPCR_GPIOCP_Msk);
}

/**
  * @brief    Get GPIOC Register Write Protection Enable Status
  * @rmtoll   MAPCR    GPIOCP    FL_SFU_IsEnabledGPIOCWriteProtection
  * @param    SFUx SFU instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_SFU_IsEnabledGPIOCWriteProtection(SFU_Type* SFUx)
{
    return (uint32_t)(READ_BIT(SFUx->MAPCR, SFU_MAPCR_GPIOCP_Msk) == SFU_MAPCR_GPIOCP_Msk);
}

/**
  * @brief    Disable GPIOC Register Write Protection
  * @rmtoll   MAPCR    GPIOCP    FL_SFU_DisableGPIOCWriteProtection
  * @param    SFUx SFU instance
  * @retval   None
  */
__STATIC_INLINE void FL_SFU_DisableGPIOCWriteProtection(SFU_Type* SFUx)
{
    CLEAR_BIT(SFUx->MAPCR, SFU_MAPCR_GPIOCP_Msk);
}

/**
  * @brief    Enable GPIOB Register Write Protection
  * @rmtoll   MAPCR    GPIOBP    FL_SFU_EnableGPIOBWriteProtection
  * @param    SFUx SFU instance
  * @retval   None
  */
__STATIC_INLINE void FL_SFU_EnableGPIOBWriteProtection(SFU_Type* SFUx)
{
    SET_BIT(SFUx->MAPCR, SFU_MAPCR_GPIOBP_Msk);
}

/**
  * @brief    Get GPIOB Register Write Protection Enable Status
  * @rmtoll   MAPCR    GPIOBP    FL_SFU_IsEnabledGPIOBWriteProtection
  * @param    SFUx SFU instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_SFU_IsEnabledGPIOBWriteProtection(SFU_Type* SFUx)
{
    return (uint32_t)(READ_BIT(SFUx->MAPCR, SFU_MAPCR_GPIOBP_Msk) == SFU_MAPCR_GPIOBP_Msk);
}

/**
  * @brief    Disable GPIOB Register Write Protection
  * @rmtoll   MAPCR    GPIOBP    FL_SFU_DisableGPIOBWriteProtection
  * @param    SFUx SFU instance
  * @retval   None
  */
__STATIC_INLINE void FL_SFU_DisableGPIOBWriteProtection(SFU_Type* SFUx)
{
    CLEAR_BIT(SFUx->MAPCR, SFU_MAPCR_GPIOBP_Msk);
}

/**
  * @brief    Enable GPIOA Register Write Protection
  * @rmtoll   MAPCR    GPIOAP    FL_SFU_EnableGPIOAWriteProtection
  * @param    SFUx SFU instance
  * @retval   None
  */
__STATIC_INLINE void FL_SFU_EnableGPIOAWriteProtection(SFU_Type* SFUx)
{
    SET_BIT(SFUx->MAPCR, SFU_MAPCR_GPIOAP_Msk);
}

/**
  * @brief    Get GPIOA Register Write Protection Enable Status
  * @rmtoll   MAPCR    GPIOAP    FL_SFU_IsEnabledGPIOAWriteProtection
  * @param    SFUx SFU instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_SFU_IsEnabledGPIOAWriteProtection(SFU_Type* SFUx)
{
    return (uint32_t)(READ_BIT(SFUx->MAPCR, SFU_MAPCR_GPIOAP_Msk) == SFU_MAPCR_GPIOAP_Msk);
}

/**
  * @brief    Disable GPIOA Register Write Protection
  * @rmtoll   MAPCR    GPIOAP    FL_SFU_DisableGPIOAWriteProtection
  * @param    SFUx SFU instance
  * @retval   None
  */
__STATIC_INLINE void FL_SFU_DisableGPIOAWriteProtection(SFU_Type* SFUx)
{
    CLEAR_BIT(SFUx->MAPCR, SFU_MAPCR_GPIOAP_Msk);
}

/**
  * @brief    Enable CLM1 Register Write Protection
  * @rmtoll   MAPCR    CLM1P    FL_SFU_EnableCLM1WriteProtection
  * @param    SFUx SFU instance
  * @retval   None
  */
__STATIC_INLINE void FL_SFU_EnableCLM1WriteProtection(SFU_Type* SFUx)
{
    SET_BIT(SFUx->MAPCR, SFU_MAPCR_CLM1P_Msk);
}

/**
  * @brief    Get CLM1 Register Write Protection Enable Status
  * @rmtoll   MAPCR    CLM1P    FL_SFU_IsEnabledCLM1WriteProtection
  * @param    SFUx SFU instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_SFU_IsEnabledCLM1WriteProtection(SFU_Type* SFUx)
{
    return (uint32_t)(READ_BIT(SFUx->MAPCR, SFU_MAPCR_CLM1P_Msk) == SFU_MAPCR_CLM1P_Msk);
}

/**
  * @brief    Disable CLM1 Register Write Protection
  * @rmtoll   MAPCR    CLM1P    FL_SFU_DisableCLM1WriteProtection
  * @param    SFUx SFU instance
  * @retval   None
  */
__STATIC_INLINE void FL_SFU_DisableCLM1WriteProtection(SFU_Type* SFUx)
{
    CLEAR_BIT(SFUx->MAPCR, SFU_MAPCR_CLM1P_Msk);
}

/**
  * @brief    Enable CLM0 Register Write Protection
  * @rmtoll   MAPCR    CLM0P    FL_SFU_EnableCLM0WriteProtection
  * @param    SFUx SFU instance
  * @retval   None
  */
__STATIC_INLINE void FL_SFU_EnableCLM0WriteProtection(SFU_Type* SFUx)
{
    SET_BIT(SFUx->MAPCR, SFU_MAPCR_CLM0P_Msk);
}

/**
  * @brief    Get CLM0 Register Write Protection Enable Status
  * @rmtoll   MAPCR    CLM0P    FL_SFU_IsEnabledCLM0WriteProtection
  * @param    SFUx SFU instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_SFU_IsEnabledCLM0WriteProtection(SFU_Type* SFUx)
{
    return (uint32_t)(READ_BIT(SFUx->MAPCR, SFU_MAPCR_CLM0P_Msk) == SFU_MAPCR_CLM0P_Msk);
}

/**
  * @brief    Disable CLM0 Register Write Protection
  * @rmtoll   MAPCR    CLM0P    FL_SFU_DisableCLM0WriteProtection
  * @param    SFUx SFU instance
  * @retval   None
  */
__STATIC_INLINE void FL_SFU_DisableCLM0WriteProtection(SFU_Type* SFUx)
{
    CLEAR_BIT(SFUx->MAPCR, SFU_MAPCR_CLM0P_Msk);
}

/**
  * @brief    Enable COMP Register Write Protection
  * @rmtoll   MAPCR    CMPP    FL_SFU_EnableCOMPWriteProtection
  * @param    SFUx SFU instance
  * @retval   None
  */
__STATIC_INLINE void FL_SFU_EnableCOMPWriteProtection(SFU_Type* SFUx)
{
    SET_BIT(SFUx->MAPCR, SFU_MAPCR_CMPP_Msk);
}

/**
  * @brief    Get COMP Register Write Protection Enable Status
  * @rmtoll   MAPCR    CMPP    FL_SFU_IsEnabledCOMPWriteProtection
  * @param    SFUx SFU instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_SFU_IsEnabledCOMPWriteProtection(SFU_Type* SFUx)
{
    return (uint32_t)(READ_BIT(SFUx->MAPCR, SFU_MAPCR_CMPP_Msk) == SFU_MAPCR_CMPP_Msk);
}

/**
  * @brief    Disable COMP Register Write Protection
  * @rmtoll   MAPCR    CMPP    FL_SFU_DisableCOMPWriteProtection
  * @param    SFUx SFU instance
  * @retval   None
  */
__STATIC_INLINE void FL_SFU_DisableCOMPWriteProtection(SFU_Type* SFUx)
{
    CLEAR_BIT(SFUx->MAPCR, SFU_MAPCR_CMPP_Msk);
}

/**
  * @brief    Enable WWDT Register Write Protection
  * @rmtoll   MAPCR    WWP    FL_SFU_EnableWWDTWriteProtection
  * @param    SFUx SFU instance
  * @retval   None
  */
__STATIC_INLINE void FL_SFU_EnableWWDTWriteProtection(SFU_Type* SFUx)
{
    SET_BIT(SFUx->MAPCR, SFU_MAPCR_WWP_Msk);
}

/**
  * @brief    Get WWDT Register Write Protection Enable Status
  * @rmtoll   MAPCR    WWP    FL_SFU_IsEnabledWWDTWriteProtection
  * @param    SFUx SFU instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_SFU_IsEnabledWWDTWriteProtection(SFU_Type* SFUx)
{
    return (uint32_t)(READ_BIT(SFUx->MAPCR, SFU_MAPCR_WWP_Msk) == SFU_MAPCR_WWP_Msk);
}

/**
  * @brief    Disable WWDT Register Write Protection
  * @rmtoll   MAPCR    WWP    FL_SFU_DisableWWDTWriteProtection
  * @param    SFUx SFU instance
  * @retval   None
  */
__STATIC_INLINE void FL_SFU_DisableWWDTWriteProtection(SFU_Type* SFUx)
{
    CLEAR_BIT(SFUx->MAPCR, SFU_MAPCR_WWP_Msk);
}

/**
  * @brief    Enable IWDT Register Write Protection
  * @rmtoll   MAPCR    IWP    FL_SFU_EnableIWDTWriteProtection
  * @param    SFUx SFU instance
  * @retval   None
  */
__STATIC_INLINE void FL_SFU_EnableIWDTWriteProtection(SFU_Type* SFUx)
{
    SET_BIT(SFUx->MAPCR, SFU_MAPCR_IWP_Msk);
}

/**
  * @brief    Get IWDT Register Write Protection Enable Status
  * @rmtoll   MAPCR    IWP    FL_SFU_IsEnabledIWDTWriteProtection
  * @param    SFUx SFU instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_SFU_IsEnabledIWDTWriteProtection(SFU_Type* SFUx)
{
    return (uint32_t)(READ_BIT(SFUx->MAPCR, SFU_MAPCR_IWP_Msk) == SFU_MAPCR_IWP_Msk);
}

/**
  * @brief    Disable IWDT Register Write Protection
  * @rmtoll   MAPCR    IWP    FL_SFU_DisableIWDTWriteProtection
  * @param    SFUx SFU instance
  * @retval   None
  */
__STATIC_INLINE void FL_SFU_DisableIWDTWriteProtection(SFU_Type* SFUx)
{
    CLEAR_BIT(SFUx->MAPCR, SFU_MAPCR_IWP_Msk);
}

/**
  * @brief    Enable Flash Register Write Protection
  * @rmtoll   MAPCR    NVMP    FL_SFU_EnableFlashWriteProtection
  * @param    SFUx SFU instance
  * @retval   None
  */
__STATIC_INLINE void FL_SFU_EnableFlashWriteProtection(SFU_Type* SFUx)
{
    SET_BIT(SFUx->MAPCR, SFU_MAPCR_NVMP_Msk);
}

/**
  * @brief    Get Flash Register Write Protection Enable Status
  * @rmtoll   MAPCR    NVMP    FL_SFU_IsEnabledFlashWriteProtection
  * @param    SFUx SFU instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_SFU_IsEnabledFlashWriteProtection(SFU_Type* SFUx)
{
    return (uint32_t)(READ_BIT(SFUx->MAPCR, SFU_MAPCR_NVMP_Msk) == SFU_MAPCR_NVMP_Msk);
}

/**
  * @brief    Disable Flash Register Write Protection
  * @rmtoll   MAPCR    NVMP    FL_SFU_DisableFlashWriteProtection
  * @param    SFUx SFU instance
  * @retval   None
  */
__STATIC_INLINE void FL_SFU_DisableFlashWriteProtection(SFU_Type* SFUx)
{
    CLEAR_BIT(SFUx->MAPCR, SFU_MAPCR_NVMP_Msk);
}

/**
  * @brief    Set Memory Access Protection Select
  * @rmtoll   MAPCR    MAP_SEL    FL_SFU_SetMemoryAccessProtectionSelect
  * @param    SFUx SFU instance
  * @param    select This parameter can be one of the following values:
  *           @arg @ref FL_SFU_MAP_SELECT_NMI
  *           @arg @ref FL_SFU_MAP_SELECT_RESET
  * @retval   None
  */
__STATIC_INLINE void FL_SFU_SetMemoryAccessProtectionSelect(SFU_Type* SFUx, uint32_t select)
{
    MODIFY_REG(SFUx->MAPCR, SFU_MAPCR_MAP_SEL_Msk, select);
}

/**
  * @brief    Get Memory Access Protection Select
  * @rmtoll   MAPCR    MAP_SEL    FL_SFU_GetMemoryAccessProtectionSelect
  * @param    SFUx SFU instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_SFU_MAP_SELECT_NMI
  *           @arg @ref FL_SFU_MAP_SELECT_RESET
  */
__STATIC_INLINE uint32_t FL_SFU_GetMemoryAccessProtectionSelect(SFU_Type* SFUx)
{
    return (uint32_t)(READ_BIT(SFUx->MAPCR, SFU_MAPCR_MAP_SEL_Msk));
}

/**
  * @brief    Enable RMU Register Write Protection
  * @rmtoll   MAPCR    RCP    FL_SFU_EnableRMUWriteProtection
  * @param    SFUx SFU instance
  * @retval   None
  */
__STATIC_INLINE void FL_SFU_EnableRMUWriteProtection(SFU_Type* SFUx)
{
    SET_BIT(SFUx->MAPCR, SFU_MAPCR_RCP_Msk);
}

/**
  * @brief    Get RMU Register Write Protection Enable Status
  * @rmtoll   MAPCR    RCP    FL_SFU_IsEnabledRMUWriteProtection
  * @param    SFUx SFU instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_SFU_IsEnabledRMUWriteProtection(SFU_Type* SFUx)
{
    return (uint32_t)(READ_BIT(SFUx->MAPCR, SFU_MAPCR_RCP_Msk) == SFU_MAPCR_RCP_Msk);
}

/**
  * @brief    Disable RMU Register Write Protection
  * @rmtoll   MAPCR    RCP    FL_SFU_DisableRMUWriteProtection
  * @param    SFUx SFU instance
  * @retval   None
  */
__STATIC_INLINE void FL_SFU_DisableRMUWriteProtection(SFU_Type* SFUx)
{
    CLEAR_BIT(SFUx->MAPCR, SFU_MAPCR_RCP_Msk);
}

/**
  * @brief    Enable SVD Register Write Protection
  * @rmtoll   MAPCR    SVDP    FL_SFU_EnableSVDWriteProtection
  * @param    SFUx SFU instance
  * @retval   None
  */
__STATIC_INLINE void FL_SFU_EnableSVDWriteProtection(SFU_Type* SFUx)
{
    SET_BIT(SFUx->MAPCR, SFU_MAPCR_SVDP_Msk);
}

/**
  * @brief    Get SVD Register Write Protection Enable Status
  * @rmtoll   MAPCR    SVDP    FL_SFU_IsEnabledSVDWriteProtection
  * @param    SFUx SFU instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_SFU_IsEnabledSVDWriteProtection(SFU_Type* SFUx)
{
    return (uint32_t)(READ_BIT(SFUx->MAPCR, SFU_MAPCR_SVDP_Msk) == SFU_MAPCR_SVDP_Msk);
}

/**
  * @brief    Disable SVD Register Write Protection
  * @rmtoll   MAPCR    SVDP    FL_SFU_DisableSVDWriteProtection
  * @param    SFUx SFU instance
  * @retval   None
  */
__STATIC_INLINE void FL_SFU_DisableSVDWriteProtection(SFU_Type* SFUx)
{
    CLEAR_BIT(SFUx->MAPCR, SFU_MAPCR_SVDP_Msk);
}

/**
  * @brief    Enable CMU Register Write Protection
  * @rmtoll   MAPCR    CCP    FL_SFU_EnableCMUWriteProtection
  * @param    SFUx SFU instance
  * @retval   None
  */
__STATIC_INLINE void FL_SFU_EnableCMUWriteProtection(SFU_Type* SFUx)
{
    SET_BIT(SFUx->MAPCR, SFU_MAPCR_CCP_Msk);
}

/**
  * @brief    Get CMU Register Write Protection Enable Status
  * @rmtoll   MAPCR    CCP    FL_SFU_IsEnabledCMUWriteProtection
  * @param    SFUx SFU instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_SFU_IsEnabledCMUWriteProtection(SFU_Type* SFUx)
{
    return (uint32_t)(READ_BIT(SFUx->MAPCR, SFU_MAPCR_CCP_Msk) == SFU_MAPCR_CCP_Msk);
}

/**
  * @brief    Disable CMU Register Write Protection
  * @rmtoll   MAPCR    CCP    FL_SFU_DisableCMUWriteProtection
  * @param    SFUx SFU instance
  * @retval   None
  */
__STATIC_INLINE void FL_SFU_DisableCMUWriteProtection(SFU_Type* SFUx)
{
    CLEAR_BIT(SFUx->MAPCR, SFU_MAPCR_CCP_Msk);
}

/**
  * @brief    Set RAM Write Protection Size
  * @rmtoll   MAPCR    RAMWP    FL_SFU_SetRAMWriteProtectionSize
  * @param    SFUx SFU instance
  * @param    size This parameter can be one of the following values:
  *           @arg @ref FL_SFU_RAMWP_SIZE_NONE
  *           @arg @ref FL_SFU_RAMWP_SIZE_1K
  *           @arg @ref FL_SFU_RAMWP_SIZE_2K
  *           @arg @ref FL_SFU_RAMWP_SIZE_4K
  * @retval   None
  */
__STATIC_INLINE void FL_SFU_SetRAMWriteProtectionSize(SFU_Type* SFUx, uint32_t size)
{
    MODIFY_REG(SFUx->MAPCR, SFU_MAPCR_RAMWP_Msk, size);
}

/**
  * @brief    Get RAM Write Protection Size
  * @rmtoll   MAPCR    RAMWP    FL_SFU_GetRAMWriteProtectionSize
  * @param    SFUx SFU instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_SFU_RAMWP_SIZE_NONE
  *           @arg @ref FL_SFU_RAMWP_SIZE_1K
  *           @arg @ref FL_SFU_RAMWP_SIZE_2K
  *           @arg @ref FL_SFU_RAMWP_SIZE_4K
  */
__STATIC_INLINE uint32_t FL_SFU_GetRAMWriteProtectionSize(SFU_Type* SFUx)
{
    return (uint32_t)(READ_BIT(SFUx->MAPCR, SFU_MAPCR_RAMWP_Msk));
}

/**
  * @brief    Enable Memory Access Protection
  * @rmtoll   MAPCR    MAP_EN    FL_SFU_EnableMemoryAccessProtection
  * @param    SFUx SFU instance
  * @retval   None
  */
__STATIC_INLINE void FL_SFU_EnableMemoryAccessProtection(SFU_Type* SFUx)
{
    SET_BIT(SFUx->MAPCR, SFU_MAPCR_MAP_EN_Msk);
}

/**
  * @brief    Get Memory Access Protection Enable Status
  * @rmtoll   MAPCR    MAP_EN    FL_SFU_IsEnabledMemoryAccessProtection
  * @param    SFUx SFU instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_SFU_IsEnabledMemoryAccessProtection(SFU_Type* SFUx)
{
    return (uint32_t)(READ_BIT(SFUx->MAPCR, SFU_MAPCR_MAP_EN_Msk) == SFU_MAPCR_MAP_EN_Msk);
}

/**
  * @brief    Clear Memory Access Protection Interrupt Flag
  * @rmtoll   MAPSR    MAP_IF    FL_SFU_ClearFlag_MemoryAccessProtection
  * @param    SFUx SFU instance
  * @retval   None
  */
__STATIC_INLINE void FL_SFU_ClearFlag_MemoryAccessProtection(SFU_Type* SFUx)
{
    WRITE_REG(SFUx->MAPSR, SFU_MAPSR_MAP_IF_Msk);
}

/**
  * @brief    Get Memory Access Protection Interrupt Flag
  * @rmtoll   MAPSR    MAP_IF    FL_SFU_IsActiveFlag_MemoryAccessProtection
  * @param    SFUx SFU instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_SFU_IsActiveFlag_MemoryAccessProtection(SFU_Type* SFUx)
{
    return (uint32_t)(READ_BIT(SFUx->MAPSR, SFU_MAPSR_MAP_IF_Msk) == (SFU_MAPSR_MAP_IF_Msk));
}

/**
  * @}
  */

/** @defgroup SFU_FL_EF_Init Initialization and de-initialization functions
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

#endif /* __FM33FG0XXA_FL_SFU_H*/

/*************************Py_Code_Generator Version: 0.1-0.14-0.1 @ 2023-06-01*************************/
/*************************(C) COPYRIGHT Fudan Microelectronics **** END OF FILE*************************/
