 /**    
  *******************************************************************************************************
  * @file    fm33fg0xxa_fl_flash.h
  * @author  FMSH Application Team
  * @brief   Head file of FLASH FL Module
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
#ifndef __FM33FG0XXA_FL_FLASH_H
#define __FM33FG0XXA_FL_FLASH_H

#ifdef __cplusplus
extern "C" {
#endif
/* Includes -------------------------------------------------------------------------------------------*/
#include "fm33fg0xxa_fl_def.h"
/** @addtogroup FM33FG0XXA_FL_Driver
  * @{
  */
/* Exported types -------------------------------------------------------------------------------------*/
/** @defgroup FLASH_FL_ES_INIT FLASH Exported Init structures
  * @{
  */

/**
  * @brief FL FLASH Init Sturcture definition
  */

/**
  * @}
  */
/* Exported constants ---------------------------------------------------------------------------------*/
/** @defgroup FLASH_FL_Exported_Constants FLASH Exported Constants
  * @{
  */

#define    FLASH_RDCR_DATA_WAIT_Pos                               (4U)
#define    FLASH_RDCR_DATA_WAIT_Msk                               (0xfU << FLASH_RDCR_DATA_WAIT_Pos)
#define    FLASH_RDCR_DATA_WAIT                                   FLASH_RDCR_DATA_WAIT_Msk

#define    FLASH_RDCR_CODE_WAIT_Pos                               (0U)
#define    FLASH_RDCR_CODE_WAIT_Msk                               (0xfU << FLASH_RDCR_CODE_WAIT_Pos)
#define    FLASH_RDCR_CODE_WAIT                                   FLASH_RDCR_CODE_WAIT_Msk

#define    FLASH_OPTBR_IWDTSLP_Pos                                (31U)
#define    FLASH_OPTBR_IWDTSLP_Msk                                (0x1U << FLASH_OPTBR_IWDTSLP_Pos)
#define    FLASH_OPTBR_IWDTSLP                                    FLASH_OPTBR_IWDTSLP_Msk

#define    FLASH_OPTBR_IWDTEN_Pos                                 (30U)
#define    FLASH_OPTBR_IWDTEN_Msk                                 (0x1U << FLASH_OPTBR_IWDTEN_Pos)
#define    FLASH_OPTBR_IWDTEN                                     FLASH_OPTBR_IWDTEN_Msk

#define    FLASH_OPTBR_DBRDPEN_D_Pos                              (4U)
#define    FLASH_OPTBR_DBRDPEN_D_Msk                              (0x3U << FLASH_OPTBR_DBRDPEN_D_Pos)
#define    FLASH_OPTBR_DBRDPEN_D                                  FLASH_OPTBR_DBRDPEN_D_Msk

#define    FLASH_OPTBR_ACLOCKEN_Pos                               (2U)
#define    FLASH_OPTBR_ACLOCKEN_Msk                               (0x3U << FLASH_OPTBR_ACLOCKEN_Pos)
#define    FLASH_OPTBR_ACLOCKEN                                   FLASH_OPTBR_ACLOCKEN_Msk

#define    FLASH_OPTBR_DBRDPEN_C_Pos                              (0U)
#define    FLASH_OPTBR_DBRDPEN_C_Msk                              (0x3U << FLASH_OPTBR_DBRDPEN_C_Pos)
#define    FLASH_OPTBR_DBRDPEN_C                                  FLASH_OPTBR_DBRDPEN_C_Msk

#define    FLASH_CFLS_EPCR_ERTYPE_Pos                             (8U)
#define    FLASH_CFLS_EPCR_ERTYPE_Msk                             (0x3U << FLASH_CFLS_EPCR_ERTYPE_Pos)
#define    FLASH_CFLS_EPCR_ERTYPE                                 FLASH_CFLS_EPCR_ERTYPE_Msk

#define    FLASH_CFLS_EPCR_PREQ_Pos                               (1U)
#define    FLASH_CFLS_EPCR_PREQ_Msk                               (0x1U << FLASH_CFLS_EPCR_PREQ_Pos)
#define    FLASH_CFLS_EPCR_PREQ                                   FLASH_CFLS_EPCR_PREQ_Msk

#define    FLASH_CFLS_EPCR_EREQ_Pos                               (0U)
#define    FLASH_CFLS_EPCR_EREQ_Msk                               (0x1U << FLASH_CFLS_EPCR_EREQ_Pos)
#define    FLASH_CFLS_EPCR_EREQ                                   FLASH_CFLS_EPCR_EREQ_Msk

/* ALL SUPPOTRED EXCEPT CHIP U01. START */
#define    FLASH_CFLS_IER_DAUTHIE_Pos                             (11U)
#define    FLASH_CFLS_IER_DAUTHIE_Msk                             (0x1U << FLASH_CFLS_IER_DAUTHIE_Pos)
#define    FLASH_CFLS_IER_DAUTHIE                                 FLASH_CFLS_IER_DAUTHIE_Msk
/* ALL SUPPOTRED EXCEPT CHIP U01. END */

#define    FLASH_CFLS_IER_AUTHIE_Pos                              (10U)
#define    FLASH_CFLS_IER_AUTHIE_Msk                              (0x1U << FLASH_CFLS_IER_AUTHIE_Pos)
#define    FLASH_CFLS_IER_AUTHIE                                  FLASH_CFLS_IER_AUTHIE_Msk

#define    FLASH_CFLS_IER_KEYIE_Pos                               (9U)
#define    FLASH_CFLS_IER_KEYIE_Msk                               (0x1U << FLASH_CFLS_IER_KEYIE_Pos)
#define    FLASH_CFLS_IER_KEYIE                                   FLASH_CFLS_IER_KEYIE_Msk

#define    FLASH_CFLS_IER_CKIE_Pos                                (8U)
#define    FLASH_CFLS_IER_CKIE_Msk                                (0x1U << FLASH_CFLS_IER_CKIE_Pos)
#define    FLASH_CFLS_IER_CKIE                                    FLASH_CFLS_IER_CKIE_Msk

#define    FLASH_CFLS_IER_PRDIE_Pos                               (1U)
#define    FLASH_CFLS_IER_PRDIE_Msk                               (0x1U << FLASH_CFLS_IER_PRDIE_Pos)
#define    FLASH_CFLS_IER_PRDIE                                   FLASH_CFLS_IER_PRDIE_Msk

#define    FLASH_CFLS_IER_ERDIE_Pos                               (0U)
#define    FLASH_CFLS_IER_ERDIE_Msk                               (0x1U << FLASH_CFLS_IER_ERDIE_Pos)
#define    FLASH_CFLS_IER_ERDIE                                   FLASH_CFLS_IER_ERDIE_Msk

#define    FLASH_CFLS_ISR_KEYSTA_Pos                              (17U)
#define    FLASH_CFLS_ISR_KEYSTA_Msk                              (0x7U << FLASH_CFLS_ISR_KEYSTA_Pos)
#define    FLASH_CFLS_ISR_KEYSTA                                  FLASH_CFLS_ISR_KEYSTA_Msk

#define    FLASH_CFLS_ISR_AUTHERR_Pos                             (10U)
#define    FLASH_CFLS_ISR_AUTHERR_Msk                             (0x1U << FLASH_CFLS_ISR_AUTHERR_Pos)
#define    FLASH_CFLS_ISR_AUTHERR                                 FLASH_CFLS_ISR_AUTHERR_Msk

#define    FLASH_CFLS_ISR_KEYERR_Pos                              (9U)
#define    FLASH_CFLS_ISR_KEYERR_Msk                              (0x1U << FLASH_CFLS_ISR_KEYERR_Pos)
#define    FLASH_CFLS_ISR_KEYERR                                  FLASH_CFLS_ISR_KEYERR_Msk

#define    FLASH_CFLS_ISR_CKERR_Pos                               (8U)
#define    FLASH_CFLS_ISR_CKERR_Msk                               (0x1U << FLASH_CFLS_ISR_CKERR_Pos)
#define    FLASH_CFLS_ISR_CKERR                                   FLASH_CFLS_ISR_CKERR_Msk

#define    FLASH_CFLS_ISR_PRD_Pos                                 (1U)
#define    FLASH_CFLS_ISR_PRD_Msk                                 (0x1U << FLASH_CFLS_ISR_PRD_Pos)
#define    FLASH_CFLS_ISR_PRD                                     FLASH_CFLS_ISR_PRD_Msk

#define    FLASH_CFLS_ISR_ERD_Pos                                 (0U)
#define    FLASH_CFLS_ISR_ERD_Msk                                 (0x1U << FLASH_CFLS_ISR_ERD_Pos)
#define    FLASH_CFLS_ISR_ERD                                     FLASH_CFLS_ISR_ERD_Msk

#define    FLASH_DFLS_EPCR_ERTYPE_Pos                             (8U)
#define    FLASH_DFLS_EPCR_ERTYPE_Msk                             (0x3U << FLASH_DFLS_EPCR_ERTYPE_Pos)
#define    FLASH_DFLS_EPCR_ERTYPE                                 FLASH_DFLS_EPCR_ERTYPE_Msk

#define    FLASH_DFLS_EPCR_PREQ_Pos                               (1U)
#define    FLASH_DFLS_EPCR_PREQ_Msk                               (0x1U << FLASH_DFLS_EPCR_PREQ_Pos)
#define    FLASH_DFLS_EPCR_PREQ                                   FLASH_DFLS_EPCR_PREQ_Msk

#define    FLASH_DFLS_EPCR_EREQ_Pos                               (0U)
#define    FLASH_DFLS_EPCR_EREQ_Msk                               (0x1U << FLASH_DFLS_EPCR_EREQ_Pos)
#define    FLASH_DFLS_EPCR_EREQ                                   FLASH_DFLS_EPCR_EREQ_Msk

/* ONLY CHIP U01 IS SUPPORTED. START */
#define    FLASH_DFLS_IER_AUTHIE_Pos                              (10U)
#define    FLASH_DFLS_IER_AUTHIE_Msk                              (0x1U << FLASH_DFLS_IER_AUTHIE_Pos)
#define    FLASH_DFLS_IER_AUTHIE                                  FLASH_DFLS_IER_AUTHIE_Msk
/* ONLY CHIP U01 IS SUPPORTED. END */

#define    FLASH_DFLS_IER_KEYIE_Pos                               (9U)
#define    FLASH_DFLS_IER_KEYIE_Msk                               (0x1U << FLASH_DFLS_IER_KEYIE_Pos)
#define    FLASH_DFLS_IER_KEYIE                                   FLASH_DFLS_IER_KEYIE_Msk

#define    FLASH_DFLS_IER_CKIE_Pos                                (8U)
#define    FLASH_DFLS_IER_CKIE_Msk                                (0x1U << FLASH_DFLS_IER_CKIE_Pos)
#define    FLASH_DFLS_IER_CKIE                                    FLASH_DFLS_IER_CKIE_Msk

#define    FLASH_DFLS_IER_PRDIE_Pos                               (1U)
#define    FLASH_DFLS_IER_PRDIE_Msk                               (0x1U << FLASH_DFLS_IER_PRDIE_Pos)
#define    FLASH_DFLS_IER_PRDIE                                   FLASH_DFLS_IER_PRDIE_Msk

#define    FLASH_DFLS_IER_ERDIE_Pos                               (0U)
#define    FLASH_DFLS_IER_ERDIE_Msk                               (0x1U << FLASH_DFLS_IER_ERDIE_Pos)
#define    FLASH_DFLS_IER_ERDIE                                   FLASH_DFLS_IER_ERDIE_Msk

#define    FLASH_DFLS_ISR_KEYSTA_Pos                              (17U)
#define    FLASH_DFLS_ISR_KEYSTA_Msk                              (0x7U << FLASH_DFLS_ISR_KEYSTA_Pos)
#define    FLASH_DFLS_ISR_KEYSTA                                  FLASH_DFLS_ISR_KEYSTA_Msk

#define    FLASH_DFLS_ISR_AUTHERR_Pos                             (10U)
#define    FLASH_DFLS_ISR_AUTHERR_Msk                             (0x1U << FLASH_DFLS_ISR_AUTHERR_Pos)
#define    FLASH_DFLS_ISR_AUTHERR                                 FLASH_DFLS_ISR_AUTHERR_Msk

#define    FLASH_DFLS_ISR_KEYERR_Pos                              (9U)
#define    FLASH_DFLS_ISR_KEYERR_Msk                              (0x1U << FLASH_DFLS_ISR_KEYERR_Pos)
#define    FLASH_DFLS_ISR_KEYERR                                  FLASH_DFLS_ISR_KEYERR_Msk

#define    FLASH_DFLS_ISR_CKERR_Pos                               (8U)
#define    FLASH_DFLS_ISR_CKERR_Msk                               (0x1U << FLASH_DFLS_ISR_CKERR_Pos)
#define    FLASH_DFLS_ISR_CKERR                                   FLASH_DFLS_ISR_CKERR_Msk

#define    FLASH_DFLS_ISR_PRD_Pos                                 (1U)
#define    FLASH_DFLS_ISR_PRD_Msk                                 (0x1U << FLASH_DFLS_ISR_PRD_Pos)
#define    FLASH_DFLS_ISR_PRD                                     FLASH_DFLS_ISR_PRD_Msk

#define    FLASH_DFLS_ISR_ERD_Pos                                 (0U)
#define    FLASH_DFLS_ISR_ERD_Msk                                 (0x1U << FLASH_DFLS_ISR_ERD_Pos)
#define    FLASH_DFLS_ISR_ERD                                     FLASH_DFLS_ISR_ERD_Msk

#define    FLASH_CFLS_ECCR_ECCDD_Pos                              (31U)
#define    FLASH_CFLS_ECCR_ECCDD_Msk                              (0x1U << FLASH_CFLS_ECCR_ECCDD_Pos)
#define    FLASH_CFLS_ECCR_ECCDD                                  FLASH_CFLS_ECCR_ECCDD_Msk

#define    FLASH_CFLS_ECCR_ECCCD_Pos                              (30U)
#define    FLASH_CFLS_ECCR_ECCCD_Msk                              (0x1U << FLASH_CFLS_ECCR_ECCCD_Pos)
#define    FLASH_CFLS_ECCR_ECCCD                                  FLASH_CFLS_ECCR_ECCCD_Msk

#define    FLASH_CFLS_ECCR_ECCCIE_Pos                             (24U)
#define    FLASH_CFLS_ECCR_ECCCIE_Msk                             (0x1U << FLASH_CFLS_ECCR_ECCCIE_Pos)
#define    FLASH_CFLS_ECCR_ECCCIE                                 FLASH_CFLS_ECCR_ECCCIE_Msk

#define    FLASH_CFLS_ECCR_ADDR_ECC_Pos                           (0U)
#define    FLASH_CFLS_ECCR_ADDR_ECC_Msk                           (0x1ffffU << FLASH_CFLS_ECCR_ADDR_ECC_Pos)
#define    FLASH_CFLS_ECCR_ADDR_ECC                               FLASH_CFLS_ECCR_ADDR_ECC_Msk

#define    FLASH_DFLS_ECCR_ECCDD_Pos                              (31U)
#define    FLASH_DFLS_ECCR_ECCDD_Msk                              (0x1U << FLASH_DFLS_ECCR_ECCDD_Pos)
#define    FLASH_DFLS_ECCR_ECCDD                                  FLASH_DFLS_ECCR_ECCDD_Msk

#define    FLASH_DFLS_ECCR_ECCCD_Pos                              (30U)
#define    FLASH_DFLS_ECCR_ECCCD_Msk                              (0x1U << FLASH_DFLS_ECCR_ECCCD_Pos)
#define    FLASH_DFLS_ECCR_ECCCD                                  FLASH_DFLS_ECCR_ECCCD_Msk

#define    FLASH_DFLS_ECCR_ECCCIE_Pos                             (24U)
#define    FLASH_DFLS_ECCR_ECCCIE_Msk                             (0x1U << FLASH_DFLS_ECCR_ECCCIE_Pos)
#define    FLASH_DFLS_ECCR_ECCCIE                                 FLASH_DFLS_ECCR_ECCCIE_Msk

#define    FLASH_DFLS_ECCR_ADDR_ECC_Pos                           (0U)
#define    FLASH_DFLS_ECCR_ADDR_ECC_Msk                           (0xfffU << FLASH_DFLS_ECCR_ADDR_ECC_Pos)
#define    FLASH_DFLS_ECCR_ADDR_ECC                               FLASH_DFLS_ECCR_ADDR_ECC_Msk

#define    FLASH_RAM_ECCR_ECCDD_Pos                               (31U)
#define    FLASH_RAM_ECCR_ECCDD_Msk                               (0x1U << FLASH_RAM_ECCR_ECCDD_Pos)
#define    FLASH_RAM_ECCR_ECCDD                                   FLASH_RAM_ECCR_ECCDD_Msk

#define    FLASH_RAM_ECCR_ECCCD_Pos                               (30U)
#define    FLASH_RAM_ECCR_ECCCD_Msk                               (0x1U << FLASH_RAM_ECCR_ECCCD_Pos)
#define    FLASH_RAM_ECCR_ECCCD                                   FLASH_RAM_ECCR_ECCCD_Msk

#define    FLASH_RAM_ECCR_ECCBE_Pos                               (27U)
#define    FLASH_RAM_ECCR_ECCBE_Msk                               (0x1U << FLASH_RAM_ECCR_ECCBE_Pos)
#define    FLASH_RAM_ECCR_ECCBE                                   FLASH_RAM_ECCR_ECCBE_Msk

#define    FLASH_RAM_ECCR_ECCCIE_Pos                              (24U)
#define    FLASH_RAM_ECCR_ECCCIE_Msk                              (0x1U << FLASH_RAM_ECCR_ECCCIE_Pos)
#define    FLASH_RAM_ECCR_ECCCIE                                  FLASH_RAM_ECCR_ECCCIE_Msk

#define    FLASH_RAM_ECCR_ADDR_ECC_Pos                            (0U)
#define    FLASH_RAM_ECCR_ADDR_ECC_Msk                            (0x3fffU << FLASH_RAM_ECCR_ADDR_ECC_Pos)
#define    FLASH_RAM_ECCR_ADDR_ECC                                FLASH_RAM_ECCR_ADDR_ECC_Msk

#define    FLASH_RAM_RAW0_DATA_Pos                                (0U)
#define    FLASH_RAM_RAW0_DATA_Msk                                (0xffffffffU << FLASH_RAM_RAW0_DATA_Pos)
#define    FLASH_RAM_RAW0_DATA                                    FLASH_RAM_RAW0_DATA_Msk

#define    FLASH_RAM_RAW1_ECC_Pos                                 (0U)
#define    FLASH_RAM_RAW1_ECC_Msk                                 (0x7fU << FLASH_RAM_RAW1_ECC_Pos)
#define    FLASH_RAM_RAW1_ECC                                     FLASH_RAM_RAW1_ECC_Msk

#define    FLASH_DFLS_RAW0_DATA_Pos                               (0U)
#define    FLASH_DFLS_RAW0_DATA_Msk                               (0xffffffffU << FLASH_DFLS_RAW0_DATA_Pos)
#define    FLASH_DFLS_RAW0_DATA                                   FLASH_DFLS_RAW0_DATA_Msk

#define    FLASH_DFLS_RAW1_ECC_Pos                                (0U)
#define    FLASH_DFLS_RAW1_ECC_Msk                                (0x7fU << FLASH_DFLS_RAW1_ECC_Pos)
#define    FLASH_DFLS_RAW1_ECC                                    FLASH_DFLS_RAW1_ECC_Msk

#define    FLASH_HSRAM1_CFGR_MCS_Pos                              (2U)
#define    FLASH_HSRAM1_CFGR_MCS_Msk                              (0x3U << FLASH_HSRAM1_CFGR_MCS_Pos)
#define    FLASH_HSRAM1_CFGR_MCS                                  FLASH_HSRAM1_CFGR_MCS_Msk

#define    FLASH_HSRAM1_CFGR_PDN_SLN_Pos                          (0U)
#define    FLASH_HSRAM1_CFGR_PDN_SLN_Msk                          (0x3U << FLASH_HSRAM1_CFGR_PDN_SLN_Pos)
#define    FLASH_HSRAM1_CFGR_PDN_SLN                              FLASH_HSRAM1_CFGR_PDN_SLN_Msk

#define    FLASH_HSRAM2_CFGR_MCS_Pos                              (2U)
#define    FLASH_HSRAM2_CFGR_MCS_Msk                              (0x3U << FLASH_HSRAM2_CFGR_MCS_Pos)
#define    FLASH_HSRAM2_CFGR_MCS                                  FLASH_HSRAM2_CFGR_MCS_Msk

#define    FLASH_HSRAM2_CFGR_PDN_SLN_Pos                          (0U)
#define    FLASH_HSRAM2_CFGR_PDN_SLN_Msk                          (0x3U << FLASH_HSRAM2_CFGR_PDN_SLN_Pos)
#define    FLASH_HSRAM2_CFGR_PDN_SLN                              FLASH_HSRAM2_CFGR_PDN_SLN_Msk

#define    FLASH_BDSR_FLAG_Pos                                    (1U)
#define    FLASH_BDSR_FLAG_Msk                                    (0x1U << FLASH_BDSR_FLAG_Pos)
#define    FLASH_BDSR_FLAG                                        FLASH_BDSR_FLAG_Msk

#define    FLASH_BDSR_DONE_Pos                                    (0U)
#define    FLASH_BDSR_DONE_Msk                                    (0x1U << FLASH_BDSR_DONE_Pos)
#define    FLASH_BDSR_DONE                                        FLASH_BDSR_DONE_Msk

#define    FL_FLASH_BACK_DOOR_KEY                                 (0x55AA1357U)

#define    FL_FLASH_ERASE_KEY                                     (0x96969696U)
#define    FL_FLASH_CHIP_ERASE_KEY                                (0x7D7D7D7DU)
#define    FL_FLASH_PGAE_ERASE_KEY                                (0xEAEAEAEAU)
#define    FL_FLASH_SECTOR_ERASE_KEY                              (0x3C3C3C3CU)
#define    FL_FLASH_ERASE_REQUEST                                 (0x1234ABCDU)
#define    FL_FLASH_PROGRAM_KEY1                                  (0xA5A5A5A5U)
#define    FL_FLASH_PROGRAM_KEY2                                  (0xF1F1F1F1U)
/*8M*/                                                            
#define    FL_FLASH_ERASE_TIMEOUT                                 (0x0000FFFFU)
#define    FL_FLASH_HALFWORD_ADDRS_ALIGN                          (0x00000002U)
#define    FL_FLASH_WORD_ADDRS_ALIGN                              (0x00000004U)

#define    FL_FLASH_CODE_MAX_PAGE_NUM                             (0x00000400U)
#define    FL_FLASH_CODE_MAX_SECTOR_NUM                           (0x00000100U)
#define    FL_FLASH_CODE_SECTOR_SIZE_BYTE                         (0x00000800U)
#define    FL_FLASH_CODE_PGAE_SIZE_BYTE                           (0x00000200U)
#define    FL_FLASH_CODE_ADDR_MAXPROGRAM                          (0x0007FFFFU)

#define    FL_FLASH_INFO_MAX_PAGE_NUM                             (0x00000004U)
#define    FL_FLASH_IFFO_MAX_SECTOR_NUM                           (0x00000001U)
#define    FL_FLASH_INFO_SECTOR_SIZE_BYTE                         (0x00000800U)
#define    FL_FLASH_INFO_PGAE_SIZE_BYTE                           (0x00000200U)
#define    FL_FLASH_INFO_ADDR_MAXPROGRAM                          (0x000807FFU)
#define    FL_FLASH_INFO_ADDR_MINPROGRAM                          (0x00080000U)

#define    FL_FLASH_DATA_MAX_PAGE_NUM                             (0x00000020U)
#define    FL_FLASH_DATA_MAX_SECTOR_NUM                           (0x00000008U)
#define    FL_FLASH_DATA_SECTOR_SIZE_BYTE                         (0x00000800U)
#define    FL_FLASH_DATA_PGAE_SIZE_BYTE                           (0x00000200U)
#define    FL_FLASH_DATA_ADDR_MAXPROGRAM                          (0xA0003FFFU)
#define    FL_FLASH_DATA_ADDR_MINPROGRAM                          (0xA0000000U)

#define    FL_FLASH_APP_CODE_BLOCK_0                              (0x1U << 0U)
#define    FL_FLASH_APP_CODE_BLOCK_1                              (0x1U << 1U)
#define    FL_FLASH_APP_CODE_BLOCK_2                              (0x1U << 2U)
#define    FL_FLASH_APP_CODE_BLOCK_3                              (0x1U << 3U)
#define    FL_FLASH_APP_CODE_BLOCK_4                              (0x1U << 4U)
#define    FL_FLASH_APP_CODE_BLOCK_5                              (0x1U << 5U)
#define    FL_FLASH_APP_CODE_BLOCK_6                              (0x1U << 6U)
#define    FL_FLASH_APP_CODE_BLOCK_7                              (0x1U << 7U)
#define    FL_FLASH_APP_CODE_BLOCK_8                              (0x1U << 8U)
#define    FL_FLASH_APP_CODE_BLOCK_9                              (0x1U << 9U)
#define    FL_FLASH_APP_CODE_BLOCK_10                             (0x1U << 10U)
#define    FL_FLASH_APP_CODE_BLOCK_11                             (0x1U << 11U)
#define    FL_FLASH_APP_CODE_BLOCK_12                             (0x1U << 12U)
#define    FL_FLASH_APP_CODE_BLOCK_13                             (0x1U << 13U)
#define    FL_FLASH_APP_CODE_BLOCK_14                             (0x1U << 14U)
#define    FL_FLASH_APP_CODE_BLOCK_15                             (0x1U << 15U)
#define    FL_FLASH_LOCK_ALL                                      (0x0U << 0U)
#define    FL_FLASH_LOCK_SOFTWARE                                 (0x2U << 0U)
#define    FL_FLASH_LOCK_NONE                                     (0x3U << 0U)
#define    FL_FLASH_HSRAM_POWER_DOWN                              (0x0U << 0U)
#define    FL_FLASH_HSRAM_SLEEP                                   (0x2U << 0U)
#define    FL_FLASH_HSRAM_NORAML                                  (0x3U << 0U)



#define    FL_FLASH_READ_DATAWAIT_0CYCLE                          (0x0U << FLASH_RDCR_DATA_WAIT_Pos)
#define    FL_FLASH_READ_DATAWAIT_1CYCLE                          (0x1U << FLASH_RDCR_DATA_WAIT_Pos)
#define    FL_FLASH_READ_DATAWAIT_2CYCLE                          (0x2U << FLASH_RDCR_DATA_WAIT_Pos)
#define    FL_FLASH_READ_DATAWAIT_3CYCLE                          (0x3U << FLASH_RDCR_DATA_WAIT_Pos)
#define    FL_FLASH_READ_DATAWAIT_4CYCLE                          (0x4U << FLASH_RDCR_DATA_WAIT_Pos)
#define    FL_FLASH_READ_DATAWAIT_5CYCLE                          (0x5U << FLASH_RDCR_DATA_WAIT_Pos)
#define    FL_FLASH_READ_DATAWAIT_6CYCLE                          (0x6U << FLASH_RDCR_DATA_WAIT_Pos)
#define    FL_FLASH_READ_DATAWAIT_7CYCLE                          (0x7U << FLASH_RDCR_DATA_WAIT_Pos)
#define    FL_FLASH_READ_DATAWAIT_8CYCLE                          (0x8U << FLASH_RDCR_DATA_WAIT_Pos)
#define    FL_FLASH_READ_DATAWAIT_9CYCLE                          (0x9U << FLASH_RDCR_DATA_WAIT_Pos)
#define    FL_FLASH_READ_DATAWAIT_10CYCLE                         (0xaU << FLASH_RDCR_DATA_WAIT_Pos)
#define    FL_FLASH_READ_DATAWAIT_11CYCLE                         (0xbU << FLASH_RDCR_DATA_WAIT_Pos)
#define    FL_FLASH_READ_DATAWAIT_12CYCLE                         (0xcU << FLASH_RDCR_DATA_WAIT_Pos)
#define    FL_FLASH_READ_DATAWAIT_13CYCLE                         (0xdU << FLASH_RDCR_DATA_WAIT_Pos)
#define    FL_FLASH_READ_DATAWAIT_14CYCLE                         (0xeU << FLASH_RDCR_DATA_WAIT_Pos)
#define    FL_FLASH_READ_DATAWAIT_15CYCLE                         (0xfU << FLASH_RDCR_DATA_WAIT_Pos)


#define    FL_FLASH_READ_CODEWAIT_0CYCLE                          (0x0U << FLASH_RDCR_CODE_WAIT_Pos)
#define    FL_FLASH_READ_CODEWAIT_1CYCLE                          (0x1U << FLASH_RDCR_CODE_WAIT_Pos)
#define    FL_FLASH_READ_CODEWAIT_2CYCLE                          (0x2U << FLASH_RDCR_CODE_WAIT_Pos)
#define    FL_FLASH_READ_CODEWAIT_3CYCLE                          (0x3U << FLASH_RDCR_CODE_WAIT_Pos)
#define    FL_FLASH_READ_CODEWAIT_4CYCLE                          (0x4U << FLASH_RDCR_CODE_WAIT_Pos)
#define    FL_FLASH_READ_CODEWAIT_5CYCLE                          (0x5U << FLASH_RDCR_CODE_WAIT_Pos)
#define    FL_FLASH_READ_CODEWAIT_6CYCLE                          (0x6U << FLASH_RDCR_CODE_WAIT_Pos)
#define    FL_FLASH_READ_CODEWAIT_7CYCLE                          (0x7U << FLASH_RDCR_CODE_WAIT_Pos)
#define    FL_FLASH_READ_CODEWAIT_8CYCLE                          (0x8U << FLASH_RDCR_CODE_WAIT_Pos)
#define    FL_FLASH_READ_CODEWAIT_9CYCLE                          (0x9U << FLASH_RDCR_CODE_WAIT_Pos)
#define    FL_FLASH_READ_CODEWAIT_10CYCLE                         (0xaU << FLASH_RDCR_CODE_WAIT_Pos)
#define    FL_FLASH_READ_CODEWAIT_11CYCLE                         (0xbU << FLASH_RDCR_CODE_WAIT_Pos)
#define    FL_FLASH_READ_CODEWAIT_12CYCLE                         (0xcU << FLASH_RDCR_CODE_WAIT_Pos)
#define    FL_FLASH_READ_CODEWAIT_13CYCLE                         (0xdU << FLASH_RDCR_CODE_WAIT_Pos)
#define    FL_FLASH_READ_CODEWAIT_14CYCLE                         (0xeU << FLASH_RDCR_CODE_WAIT_Pos)
#define    FL_FLASH_READ_CODEWAIT_15CYCLE                         (0xfU << FLASH_RDCR_CODE_WAIT_Pos)


#define    FL_FLASH_IWDT_STOP_UNDER_SLEEP                         (0x0U << FLASH_OPTBR_IWDTSLP_Pos)
#define    FL_FLASH_IWDT_WORK_UNDER_SLEEP                         (0x1U << FLASH_OPTBR_IWDTSLP_Pos)

#define    FL_FLASH_IWDT_STOP_AFTERPOWERON                        (0x0U << FLASH_OPTBR_IWDTEN_Pos)
#define    FL_FLASH_IWDT_WORK_AFTERPOWERON                        (0x1U << FLASH_OPTBR_IWDTEN_Pos)

#define    FL_FLASH_DATA_SWD_READ_PEOTECTION_DISABLE              (0x1U << FLASH_OPTBR_DBRDPEN_D_Pos)
#define    FL_FLASH_DATA_SWD_READ_PEOTECTION_ENABLE               (0x2U << FLASH_OPTBR_DBRDPEN_D_Pos)


#define    FL_FLASH_APP_CODE_LOCK_DISABLE                         (0x1U << FLASH_OPTBR_ACLOCKEN_Pos)
#define    FL_FLASH_APP_CODE_LOCK_ENABLE                          (0x2U << FLASH_OPTBR_ACLOCKEN_Pos)


#define    FL_FLASH_CODE_SWD_READ_PEOTECTION_DISABLE              (0x1U << FLASH_OPTBR_DBRDPEN_C_Pos)
#define    FL_FLASH_CODE_SWD_READ_PEOTECTION_ENABLE               (0x2U << FLASH_OPTBR_DBRDPEN_C_Pos)


#define    FL_FLASH_CODE_ERASE_TYPE_PAGE                          (0x0U << FLASH_CFLS_EPCR_ERTYPE_Pos)
#define    FL_FLASH_CODE_ERASE_TYPE_SECTOR                        (0x1U << FLASH_CFLS_EPCR_ERTYPE_Pos)


#define    FL_FLASH_CODE_KEY_STATUS_LOCK                          (0x0U << FLASH_CFLS_ISR_KEYSTA_Pos)
#define    FL_FLASH_CODE_KEY_STATUS_ALL_ERASE                     (0x1U << FLASH_CFLS_ISR_KEYSTA_Pos)
#define    FL_FLASH_CODE_KEY_STATUS_PAGE_ERASE                    (0x2U << FLASH_CFLS_ISR_KEYSTA_Pos)
#define    FL_FLASH_CODE_KEY_STATUS_PROGRAM                       (0x3U << FLASH_CFLS_ISR_KEYSTA_Pos)
#define    FL_FLASH_CODE_KEY_STATUS_ERROR                         (0x4U << FLASH_CFLS_ISR_KEYSTA_Pos)
#define    FL_FLASH_CODE_KEY_STATUS_SECTOR_ERASE                  (0x5U << FLASH_CFLS_ISR_KEYSTA_Pos)

#define    FL_FLASH_DATA_ERASE_TYPE_PAGE                          (0x0U << FLASH_DFLS_EPCR_ERTYPE_Pos)
#define    FL_FLASH_DATA_ERASE_TYPE_SECTOR                        (0x1U << FLASH_DFLS_EPCR_ERTYPE_Pos)


#define    FL_FLASH_DATA_KEY_STATUS_LOCK                          (0x0U << FLASH_DFLS_ISR_KEYSTA_Pos)
#define    FL_FLASH_DATA_KEY_STATUS_ALL_ERASE                     (0x1U << FLASH_DFLS_ISR_KEYSTA_Pos)
#define    FL_FLASH_DATA_KEY_STATUS_PAGE_ERASE                    (0x2U << FLASH_DFLS_ISR_KEYSTA_Pos)
#define    FL_FLASH_DATA_KEY_STATUS_PROGRAM                       (0x3U << FLASH_DFLS_ISR_KEYSTA_Pos)
#define    FL_FLASH_DATA_KEY_STATUS_ERROR                         (0x4U << FLASH_DFLS_ISR_KEYSTA_Pos)
#define    FL_FLASH_DATA_KEY_STATUS_SECTOR_ERASE                  (0x5U << FLASH_DFLS_ISR_KEYSTA_Pos)

/**
  * @}
  */
/* Exported functions ---------------------------------------------------------------------------------*/
/** @defgroup FLASH_FL_Exported_Functions FLASH Exported Functions
  * @{
  */

/**
  * @brief    Data Flash wait cycles config
  * @rmtoll   RDCR    DATA_WAIT    FL_FLASH_SetDataReadWait
  * @param    FLASHx FLASH instance
  * @param    wait This parameter can be one of the following values:
  *           @arg @ref FL_FLASH_READ_DATAWAIT_0CYCLE
  *           @arg @ref FL_FLASH_READ_DATAWAIT_1CYCLE
  *           @arg @ref FL_FLASH_READ_DATAWAIT_2CYCLE
  *           @arg @ref FL_FLASH_READ_DATAWAIT_3CYCLE
  *           @arg @ref FL_FLASH_READ_DATAWAIT_4CYCLE
  *           @arg @ref FL_FLASH_READ_DATAWAIT_5CYCLE
  *           @arg @ref FL_FLASH_READ_DATAWAIT_6CYCLE
  *           @arg @ref FL_FLASH_READ_DATAWAIT_7CYCLE
  *           @arg @ref FL_FLASH_READ_DATAWAIT_8CYCLE
  *           @arg @ref FL_FLASH_READ_DATAWAIT_9CYCLE
  *           @arg @ref FL_FLASH_READ_DATAWAIT_10CYCLE
  *           @arg @ref FL_FLASH_READ_DATAWAIT_11CYCLE
  *           @arg @ref FL_FLASH_READ_DATAWAIT_12CYCLE
  *           @arg @ref FL_FLASH_READ_DATAWAIT_13CYCLE
  *           @arg @ref FL_FLASH_READ_DATAWAIT_14CYCLE
  *           @arg @ref FL_FLASH_READ_DATAWAIT_15CYCLE
  * @retval   None
  */
__STATIC_INLINE void FL_FLASH_SetDataReadWait(FLASH_Type* FLASHx, uint32_t wait)
{
    MODIFY_REG(FLASHx->RDCR, FLASH_RDCR_DATA_WAIT_Msk, wait);
}

/**
  * @brief    Get Data flash wait cycles config status
  * @rmtoll   RDCR    DATA_WAIT    FL_FLASH_GetDataReadWait
  * @param    FLASHx FLASH instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_FLASH_READ_DATAWAIT_0CYCLE
  *           @arg @ref FL_FLASH_READ_DATAWAIT_1CYCLE
  *           @arg @ref FL_FLASH_READ_DATAWAIT_2CYCLE
  *           @arg @ref FL_FLASH_READ_DATAWAIT_3CYCLE
  *           @arg @ref FL_FLASH_READ_DATAWAIT_4CYCLE
  *           @arg @ref FL_FLASH_READ_DATAWAIT_5CYCLE
  *           @arg @ref FL_FLASH_READ_DATAWAIT_6CYCLE
  *           @arg @ref FL_FLASH_READ_DATAWAIT_7CYCLE
  *           @arg @ref FL_FLASH_READ_DATAWAIT_8CYCLE
  *           @arg @ref FL_FLASH_READ_DATAWAIT_9CYCLE
  *           @arg @ref FL_FLASH_READ_DATAWAIT_10CYCLE
  *           @arg @ref FL_FLASH_READ_DATAWAIT_11CYCLE
  *           @arg @ref FL_FLASH_READ_DATAWAIT_12CYCLE
  *           @arg @ref FL_FLASH_READ_DATAWAIT_13CYCLE
  *           @arg @ref FL_FLASH_READ_DATAWAIT_14CYCLE
  *           @arg @ref FL_FLASH_READ_DATAWAIT_15CYCLE
  */
__STATIC_INLINE uint32_t FL_FLASH_GetDataReadWait(FLASH_Type* FLASHx)
{
    return (uint32_t)(READ_BIT(FLASHx->RDCR, FLASH_RDCR_DATA_WAIT_Msk));
}

/**
  * @brief    Flash Code wait cycles config
  * @rmtoll   RDCR    CODE_WAIT    FL_FLASH_SetCodeReadWait
  * @param    FLASHx FLASH instance
  * @param    wait This parameter can be one of the following values:
  *           @arg @ref FL_FLASH_READ_CODEWAIT_0CYCLE
  *           @arg @ref FL_FLASH_READ_CODEWAIT_1CYCLE
  *           @arg @ref FL_FLASH_READ_CODEWAIT_2CYCLE
  *           @arg @ref FL_FLASH_READ_CODEWAIT_3CYCLE
  *           @arg @ref FL_FLASH_READ_CODEWAIT_4CYCLE
  *           @arg @ref FL_FLASH_READ_CODEWAIT_5CYCLE
  *           @arg @ref FL_FLASH_READ_CODEWAIT_6CYCLE
  *           @arg @ref FL_FLASH_READ_CODEWAIT_7CYCLE
  *           @arg @ref FL_FLASH_READ_CODEWAIT_8CYCLE
  *           @arg @ref FL_FLASH_READ_CODEWAIT_9CYCLE
  *           @arg @ref FL_FLASH_READ_CODEWAIT_10CYCLE
  *           @arg @ref FL_FLASH_READ_CODEWAIT_11CYCLE
  *           @arg @ref FL_FLASH_READ_CODEWAIT_12CYCLE
  *           @arg @ref FL_FLASH_READ_CODEWAIT_13CYCLE
  *           @arg @ref FL_FLASH_READ_CODEWAIT_14CYCLE
  *           @arg @ref FL_FLASH_READ_CODEWAIT_15CYCLE
  * @retval   None
  */
__STATIC_INLINE void FL_FLASH_SetCodeReadWait(FLASH_Type* FLASHx, uint32_t wait)
{
    MODIFY_REG(FLASHx->RDCR, FLASH_RDCR_CODE_WAIT_Msk, wait);
}

/**
  * @brief    Get Code flash wait cycles config status
  * @rmtoll   RDCR    CODE_WAIT    FL_FLASH_GetCodeReadWait
  * @param    FLASHx FLASH instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_FLASH_READ_CODEWAIT_0CYCLE
  *           @arg @ref FL_FLASH_READ_CODEWAIT_1CYCLE
  *           @arg @ref FL_FLASH_READ_CODEWAIT_2CYCLE
  *           @arg @ref FL_FLASH_READ_CODEWAIT_3CYCLE
  *           @arg @ref FL_FLASH_READ_CODEWAIT_4CYCLE
  *           @arg @ref FL_FLASH_READ_CODEWAIT_5CYCLE
  *           @arg @ref FL_FLASH_READ_CODEWAIT_6CYCLE
  *           @arg @ref FL_FLASH_READ_CODEWAIT_7CYCLE
  *           @arg @ref FL_FLASH_READ_CODEWAIT_8CYCLE
  *           @arg @ref FL_FLASH_READ_CODEWAIT_9CYCLE
  *           @arg @ref FL_FLASH_READ_CODEWAIT_10CYCLE
  *           @arg @ref FL_FLASH_READ_CODEWAIT_11CYCLE
  *           @arg @ref FL_FLASH_READ_CODEWAIT_12CYCLE
  *           @arg @ref FL_FLASH_READ_CODEWAIT_13CYCLE
  *           @arg @ref FL_FLASH_READ_CODEWAIT_14CYCLE
  *           @arg @ref FL_FLASH_READ_CODEWAIT_15CYCLE
  */
__STATIC_INLINE uint32_t FL_FLASH_GetCodeReadWait(FLASH_Type* FLASHx)
{
    return (uint32_t)(READ_BIT(FLASHx->RDCR, FLASH_RDCR_CODE_WAIT_Msk));
}

/**
  * @brief    Get IWDT sleep enable status
  * @rmtoll   OPTBR    IWDTSLP    FL_FLASH_GetIWDTStateUnderSleep
  * @param    FLASHx FLASH instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_FLASH_IWDT_STOP_UNDER_SLEEP
  *           @arg @ref FL_FLASH_IWDT_WORK_UNDER_SLEEP
  */
__STATIC_INLINE uint32_t FL_FLASH_GetIWDTStateUnderSleep(FLASH_Type* FLASHx)
{
    return (uint32_t)(READ_BIT(FLASHx->OPTBR, FLASH_OPTBR_IWDTSLP_Msk));
}

/**
  * @brief    Get IWDT status after poweron
  * @rmtoll   OPTBR    IWDTEN    FL_FLASH_GetIWDTStateAfterPowerOn
  * @param    FLASHx FLASH instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_FLASH_IWDT_STOP_AFTERPOWERON
  *           @arg @ref FL_FLASH_IWDT_WORK_AFTERPOWERON
  */
__STATIC_INLINE uint32_t FL_FLASH_GetIWDTStateAfterPowerOn(FLASH_Type* FLASHx)
{
    return (uint32_t)(READ_BIT(FLASHx->OPTBR, FLASH_OPTBR_IWDTEN_Msk));
}

/**
  * @brief    Set data flash debug read protection enable status
  * @rmtoll   OPTBR    DBRDPEN_D    FL_FLASH_SetDataSWDReadProtectionState
  * @param    FLASHx FLASH instance
  * @param    protection This parameter can be one of the following values:
  *           @arg @ref FL_FLASH_DATA_SWD_READ_PEOTECTION_DISABLE
  *           @arg @ref FL_FLASH_DATA_SWD_READ_PEOTECTION_ENABLE
  * @retval   None
  */
__STATIC_INLINE void FL_FLASH_SetDataSWDReadProtectionState(FLASH_Type* FLASHx, uint32_t protection)
{
    MODIFY_REG(FLASHx->OPTBR, FLASH_OPTBR_DBRDPEN_D_Msk, protection);
}

/**
  * @brief    Get data flash debug read protection enable status
  * @rmtoll   OPTBR    DBRDPEN_D    FL_FLASH_GetDataSWDReadProtectionState
  * @param    FLASHx FLASH instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_FLASH_DATA_SWD_READ_PEOTECTION_DISABLE
  *           @arg @ref FL_FLASH_DATA_SWD_READ_PEOTECTION_ENABLE
  */
__STATIC_INLINE uint32_t FL_FLASH_GetDataSWDReadProtectionState(FLASH_Type* FLASHx)
{
    return (uint32_t)(READ_BIT(FLASHx->OPTBR, FLASH_OPTBR_DBRDPEN_D_Msk));
}

/**
  * @brief    Set AppCode lock enable
  * @rmtoll   OPTBR    ACLOCKEN    FL_FLASH_SetAppCodeLockState
  * @param    FLASHx FLASH instance
  * @param    lock This parameter can be one of the following values:
  *           @arg @ref FL_FLASH_APP_CODE_LOCK_DISABLE
  *           @arg @ref FL_FLASH_APP_CODE_LOCK_ENABLE
  * @retval   None
  */
__STATIC_INLINE void FL_FLASH_SetAppCodeLockState(FLASH_Type* FLASHx, uint32_t lock)
{
    MODIFY_REG(FLASHx->OPTBR, FLASH_OPTBR_ACLOCKEN_Msk, lock);
}

/**
  * @brief    Get AppCode lock enable
  * @rmtoll   OPTBR    ACLOCKEN    FL_FLASH_GetAppCodeLockState
  * @param    FLASHx FLASH instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_FLASH_APP_CODE_LOCK_DISABLE
  *           @arg @ref FL_FLASH_APP_CODE_LOCK_ENABLE
  */
__STATIC_INLINE uint32_t FL_FLASH_GetAppCodeLockState(FLASH_Type* FLASHx)
{
    return (uint32_t)(READ_BIT(FLASHx->OPTBR, FLASH_OPTBR_ACLOCKEN_Msk));
}

/**
  * @brief    Set code Flash debug read protection enable status
  * @rmtoll   OPTBR    DBRDPEN_C    FL_FLASH_SetCodeSWDReadProtectionState
  * @param    FLASHx FLASH instance
  * @param    protection This parameter can be one of the following values:
  *           @arg @ref FL_FLASH_CODE_SWD_READ_PEOTECTION_DISABLE
  *           @arg @ref FL_FLASH_CODE_SWD_READ_PEOTECTION_ENABLE
  * @retval   None
  */
__STATIC_INLINE void FL_FLASH_SetCodeSWDReadProtectionState(FLASH_Type* FLASHx, uint32_t protection)
{
    MODIFY_REG(FLASHx->OPTBR, FLASH_OPTBR_DBRDPEN_C_Msk, protection);
}

/**
  * @brief    Get code Flash debug read protection enable status
  * @rmtoll   OPTBR    DBRDPEN_C    FL_FLASH_GetCodeSWDReadProtectionState
  * @param    FLASHx FLASH instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_FLASH_CODE_SWD_READ_PEOTECTION_DISABLE
  *           @arg @ref FL_FLASH_CODE_SWD_READ_PEOTECTION_ENABLE
  */
__STATIC_INLINE uint32_t FL_FLASH_GetCodeSWDReadProtectionState(FLASH_Type* FLASHx)
{
    return (uint32_t)(READ_BIT(FLASHx->OPTBR, FLASH_OPTBR_DBRDPEN_C_Msk));
}

/**
  * @brief    Set ACLOCK1 register
  * @rmtoll   ACLOCK1        FL_FLASH_SetAppCodeRegion1Lock
  * @param    FLASHx FLASH instance
  * @param    region This parameter can be one of the following values:
  *           @arg @ref FL_FLASH_APP_CODE_BLOCK_0
  *           @arg @ref FL_FLASH_APP_CODE_BLOCK_1
  *           @arg @ref FL_FLASH_APP_CODE_BLOCK_2
  *           @arg @ref FL_FLASH_APP_CODE_BLOCK_3
  *           @arg @ref FL_FLASH_APP_CODE_BLOCK_4
  *           @arg @ref FL_FLASH_APP_CODE_BLOCK_5
  *           @arg @ref FL_FLASH_APP_CODE_BLOCK_6
  *           @arg @ref FL_FLASH_APP_CODE_BLOCK_7
  *           @arg @ref FL_FLASH_APP_CODE_BLOCK_8
  *           @arg @ref FL_FLASH_APP_CODE_BLOCK_9
  *           @arg @ref FL_FLASH_APP_CODE_BLOCK_10
  *           @arg @ref FL_FLASH_APP_CODE_BLOCK_11
  *           @arg @ref FL_FLASH_APP_CODE_BLOCK_12
  *           @arg @ref FL_FLASH_APP_CODE_BLOCK_13
  *           @arg @ref FL_FLASH_APP_CODE_BLOCK_14
  *           @arg @ref FL_FLASH_APP_CODE_BLOCK_15
  * @param    mode This parameter can be one of the following values:
  *           @arg @ref FL_FLASH_LOCK_ALL
  *           @arg @ref FL_FLASH_LOCK_SOFTWARE
  *           @arg @ref FL_FLASH_LOCK_NONE
  * @retval   None
  */
__STATIC_INLINE void FL_FLASH_SetAppCodeRegion1Lock(FLASH_Type* FLASHx, uint32_t region, uint32_t mode)
{
    CLEAR_BIT(FLASHx->ACLOCK1, ((region * region) * (((mode == 3) ? 0 : (~mode)) & 0x03)));
}

/**
  * @brief    Get ACLOCK1 register
  * @rmtoll   ACLOCK1        FL_FLASH_GetAppCodeRegion1Lock
  * @param    FLASHx FLASH instance
  * @param    region This parameter can be one of the following values:
  *           @arg @ref FL_FLASH_APP_CODE_BLOCK_0
  *           @arg @ref FL_FLASH_APP_CODE_BLOCK_1
  *           @arg @ref FL_FLASH_APP_CODE_BLOCK_2
  *           @arg @ref FL_FLASH_APP_CODE_BLOCK_3
  *           @arg @ref FL_FLASH_APP_CODE_BLOCK_4
  *           @arg @ref FL_FLASH_APP_CODE_BLOCK_5
  *           @arg @ref FL_FLASH_APP_CODE_BLOCK_6
  *           @arg @ref FL_FLASH_APP_CODE_BLOCK_7
  *           @arg @ref FL_FLASH_APP_CODE_BLOCK_8
  *           @arg @ref FL_FLASH_APP_CODE_BLOCK_9
  *           @arg @ref FL_FLASH_APP_CODE_BLOCK_10
  *           @arg @ref FL_FLASH_APP_CODE_BLOCK_11
  *           @arg @ref FL_FLASH_APP_CODE_BLOCK_12
  *           @arg @ref FL_FLASH_APP_CODE_BLOCK_13
  *           @arg @ref FL_FLASH_APP_CODE_BLOCK_14
  *           @arg @ref FL_FLASH_APP_CODE_BLOCK_15
  * @retval   Returned value can be one of the following values:
  */
__STATIC_INLINE uint32_t FL_FLASH_GetAppCodeRegion1Lock(FLASH_Type* FLASHx, uint32_t region)
{
    return (uint32_t)(READ_BIT(FLASHx->ACLOCK1, ((region * region) * 0x03)) / (region * region));
}

/**
  * @brief    Set ACLOCK2 register
  * @rmtoll   ACLOCK2        FL_FLASH_SetAppCodeRegion2Lock
  * @param    FLASHx FLASH instance
  * @param    region This parameter can be one of the following values:
  *           @arg @ref FL_FLASH_APP_CODE_BLOCK_0
  *           @arg @ref FL_FLASH_APP_CODE_BLOCK_1
  *           @arg @ref FL_FLASH_APP_CODE_BLOCK_2
  *           @arg @ref FL_FLASH_APP_CODE_BLOCK_3
  *           @arg @ref FL_FLASH_APP_CODE_BLOCK_4
  *           @arg @ref FL_FLASH_APP_CODE_BLOCK_5
  *           @arg @ref FL_FLASH_APP_CODE_BLOCK_6
  *           @arg @ref FL_FLASH_APP_CODE_BLOCK_7
  *           @arg @ref FL_FLASH_APP_CODE_BLOCK_8
  *           @arg @ref FL_FLASH_APP_CODE_BLOCK_9
  *           @arg @ref FL_FLASH_APP_CODE_BLOCK_10
  *           @arg @ref FL_FLASH_APP_CODE_BLOCK_11
  *           @arg @ref FL_FLASH_APP_CODE_BLOCK_12
  *           @arg @ref FL_FLASH_APP_CODE_BLOCK_13
  *           @arg @ref FL_FLASH_APP_CODE_BLOCK_14
  *           @arg @ref FL_FLASH_APP_CODE_BLOCK_15
  * @param    mode This parameter can be one of the following values:
  *           @arg @ref FL_FLASH_LOCK_ALL
  *           @arg @ref FL_FLASH_LOCK_SOFTWARE
  *           @arg @ref FL_FLASH_LOCK_NONE
  * @retval   None
  */
__STATIC_INLINE void FL_FLASH_SetAppCodeRegion2Lock(FLASH_Type* FLASHx, uint32_t region, uint32_t mode)
{
    CLEAR_BIT(FLASHx->ACLOCK2, ((region * region) * (((mode == 3) ? 0 : (~mode)) & 0x03)));
}

/**
  * @brief    Get ACLOCK2 register
  * @rmtoll   ACLOCK2        FL_FLASH_GetAppCodeRegion2Lock
  * @param    FLASHx FLASH instance
  * @param    region This parameter can be one of the following values:
  *           @arg @ref FL_FLASH_APP_CODE_BLOCK_0
  *           @arg @ref FL_FLASH_APP_CODE_BLOCK_1
  *           @arg @ref FL_FLASH_APP_CODE_BLOCK_2
  *           @arg @ref FL_FLASH_APP_CODE_BLOCK_3
  *           @arg @ref FL_FLASH_APP_CODE_BLOCK_4
  *           @arg @ref FL_FLASH_APP_CODE_BLOCK_5
  *           @arg @ref FL_FLASH_APP_CODE_BLOCK_6
  *           @arg @ref FL_FLASH_APP_CODE_BLOCK_7
  *           @arg @ref FL_FLASH_APP_CODE_BLOCK_8
  *           @arg @ref FL_FLASH_APP_CODE_BLOCK_9
  *           @arg @ref FL_FLASH_APP_CODE_BLOCK_10
  *           @arg @ref FL_FLASH_APP_CODE_BLOCK_11
  *           @arg @ref FL_FLASH_APP_CODE_BLOCK_12
  *           @arg @ref FL_FLASH_APP_CODE_BLOCK_13
  *           @arg @ref FL_FLASH_APP_CODE_BLOCK_14
  *           @arg @ref FL_FLASH_APP_CODE_BLOCK_15
  * @retval   Returned value can be one of the following values:
  */
__STATIC_INLINE uint32_t FL_FLASH_GetAppCodeRegion2Lock(FLASH_Type* FLASHx, uint32_t region)
{
    return (uint32_t)(READ_BIT(FLASHx->ACLOCK2, ((region * region) * 0x03)) / (region * region));
}

/**
  * @brief    Set ACLOCK3 register
  * @rmtoll   ACLOCK3        FL_FLASH_SetAppCodeRegion3Lock
  * @param    FLASHx FLASH instance
  * @param    region This parameter can be one of the following values:
  *           @arg @ref FL_FLASH_APP_CODE_BLOCK_0
  *           @arg @ref FL_FLASH_APP_CODE_BLOCK_1
  *           @arg @ref FL_FLASH_APP_CODE_BLOCK_2
  *           @arg @ref FL_FLASH_APP_CODE_BLOCK_3
  *           @arg @ref FL_FLASH_APP_CODE_BLOCK_4
  *           @arg @ref FL_FLASH_APP_CODE_BLOCK_5
  *           @arg @ref FL_FLASH_APP_CODE_BLOCK_6
  *           @arg @ref FL_FLASH_APP_CODE_BLOCK_7
  *           @arg @ref FL_FLASH_APP_CODE_BLOCK_8
  *           @arg @ref FL_FLASH_APP_CODE_BLOCK_9
  *           @arg @ref FL_FLASH_APP_CODE_BLOCK_10
  *           @arg @ref FL_FLASH_APP_CODE_BLOCK_11
  *           @arg @ref FL_FLASH_APP_CODE_BLOCK_12
  *           @arg @ref FL_FLASH_APP_CODE_BLOCK_13
  *           @arg @ref FL_FLASH_APP_CODE_BLOCK_14
  *           @arg @ref FL_FLASH_APP_CODE_BLOCK_15
  * @param    mode This parameter can be one of the following values:
  *           @arg @ref FL_FLASH_LOCK_ALL
  *           @arg @ref FL_FLASH_LOCK_SOFTWARE
  *           @arg @ref FL_FLASH_LOCK_NONE
  * @retval   None
  */
__STATIC_INLINE void FL_FLASH_SetAppCodeRegion3Lock(FLASH_Type* FLASHx, uint32_t region, uint32_t mode)
{
    CLEAR_BIT(FLASHx->ACLOCK3, ((region * region) * (((mode == 3) ? 0 : (~mode)) & 0x03)));
}

/**
  * @brief    Get ACLOCK3 register
  * @rmtoll   ACLOCK3        FL_FLASH_GetAppCodeRegion3Lock
  * @param    FLASHx FLASH instance
  * @param    region This parameter can be one of the following values:
  *           @arg @ref FL_FLASH_APP_CODE_BLOCK_0
  *           @arg @ref FL_FLASH_APP_CODE_BLOCK_1
  *           @arg @ref FL_FLASH_APP_CODE_BLOCK_2
  *           @arg @ref FL_FLASH_APP_CODE_BLOCK_3
  *           @arg @ref FL_FLASH_APP_CODE_BLOCK_4
  *           @arg @ref FL_FLASH_APP_CODE_BLOCK_5
  *           @arg @ref FL_FLASH_APP_CODE_BLOCK_6
  *           @arg @ref FL_FLASH_APP_CODE_BLOCK_7
  *           @arg @ref FL_FLASH_APP_CODE_BLOCK_8
  *           @arg @ref FL_FLASH_APP_CODE_BLOCK_9
  *           @arg @ref FL_FLASH_APP_CODE_BLOCK_10
  *           @arg @ref FL_FLASH_APP_CODE_BLOCK_11
  *           @arg @ref FL_FLASH_APP_CODE_BLOCK_12
  *           @arg @ref FL_FLASH_APP_CODE_BLOCK_13
  *           @arg @ref FL_FLASH_APP_CODE_BLOCK_14
  *           @arg @ref FL_FLASH_APP_CODE_BLOCK_15
  * @retval   Returned value can be one of the following values:
  */
__STATIC_INLINE uint32_t FL_FLASH_GetAppCodeRegion3Lock(FLASH_Type* FLASHx, uint32_t region)
{
    return (uint32_t)(READ_BIT(FLASHx->ACLOCK3, ((region * region) * 0x03)) / (region * region));
}

/**
  * @brief    Set ACLOCK4 register
  * @rmtoll   ACLOCK4        FL_FLASH_SetAppCodeRegion4Lock
  * @param    FLASHx FLASH instance
  * @param    region This parameter can be one of the following values:
  *           @arg @ref FL_FLASH_APP_CODE_BLOCK_0
  *           @arg @ref FL_FLASH_APP_CODE_BLOCK_1
  *           @arg @ref FL_FLASH_APP_CODE_BLOCK_2
  *           @arg @ref FL_FLASH_APP_CODE_BLOCK_3
  *           @arg @ref FL_FLASH_APP_CODE_BLOCK_4
  *           @arg @ref FL_FLASH_APP_CODE_BLOCK_5
  *           @arg @ref FL_FLASH_APP_CODE_BLOCK_6
  *           @arg @ref FL_FLASH_APP_CODE_BLOCK_7
  *           @arg @ref FL_FLASH_APP_CODE_BLOCK_8
  *           @arg @ref FL_FLASH_APP_CODE_BLOCK_9
  *           @arg @ref FL_FLASH_APP_CODE_BLOCK_10
  *           @arg @ref FL_FLASH_APP_CODE_BLOCK_11
  *           @arg @ref FL_FLASH_APP_CODE_BLOCK_12
  *           @arg @ref FL_FLASH_APP_CODE_BLOCK_13
  *           @arg @ref FL_FLASH_APP_CODE_BLOCK_14
  *           @arg @ref FL_FLASH_APP_CODE_BLOCK_15
  * @param    mode This parameter can be one of the following values:
  *           @arg @ref FL_FLASH_LOCK_ALL
  *           @arg @ref FL_FLASH_LOCK_SOFTWARE
  *           @arg @ref FL_FLASH_LOCK_NONE
  * @retval   None
  */
__STATIC_INLINE void FL_FLASH_SetAppCodeRegion4Lock(FLASH_Type* FLASHx, uint32_t region, uint32_t mode)
{
    CLEAR_BIT(FLASHx->ACLOCK4, ((region * region) * (((mode == 3) ? 0 : (~mode)) & 0x03)));
}

/**
  * @brief    Get ACLOCK4 register
  * @rmtoll   ACLOCK4        FL_FLASH_GetAppCodeRegion4Lock
  * @param    FLASHx FLASH instance
  * @param    region This parameter can be one of the following values:
  *           @arg @ref FL_FLASH_APP_CODE_BLOCK_0
  *           @arg @ref FL_FLASH_APP_CODE_BLOCK_1
  *           @arg @ref FL_FLASH_APP_CODE_BLOCK_2
  *           @arg @ref FL_FLASH_APP_CODE_BLOCK_3
  *           @arg @ref FL_FLASH_APP_CODE_BLOCK_4
  *           @arg @ref FL_FLASH_APP_CODE_BLOCK_5
  *           @arg @ref FL_FLASH_APP_CODE_BLOCK_6
  *           @arg @ref FL_FLASH_APP_CODE_BLOCK_7
  *           @arg @ref FL_FLASH_APP_CODE_BLOCK_8
  *           @arg @ref FL_FLASH_APP_CODE_BLOCK_9
  *           @arg @ref FL_FLASH_APP_CODE_BLOCK_10
  *           @arg @ref FL_FLASH_APP_CODE_BLOCK_11
  *           @arg @ref FL_FLASH_APP_CODE_BLOCK_12
  *           @arg @ref FL_FLASH_APP_CODE_BLOCK_13
  *           @arg @ref FL_FLASH_APP_CODE_BLOCK_14
  *           @arg @ref FL_FLASH_APP_CODE_BLOCK_15
  * @retval   Returned value can be one of the following values:
  */
__STATIC_INLINE uint32_t FL_FLASH_GetAppCodeRegion4Lock(FLASH_Type* FLASHx, uint32_t region)
{
    return (uint32_t)(READ_BIT(FLASHx->ACLOCK4, ((region * region) * 0x03)) / (region * region));
}

/**
  * @brief    Set code flash erase type 
  * @rmtoll   CFLS_EPCR    ERTYPE    FL_FLASH_SetCodeEraseType
  * @param    FLASHx FLASH instance
  * @param    type This parameter can be one of the following values:
  *           @arg @ref FL_FLASH_CODE_ERASE_TYPE_PAGE
  *           @arg @ref FL_FLASH_CODE_ERASE_TYPE_SECTOR
  * @retval   None
  */
__STATIC_INLINE void FL_FLASH_SetCodeEraseType(FLASH_Type* FLASHx, uint32_t type)
{
    MODIFY_REG(FLASHx->CFLS_EPCR, FLASH_CFLS_EPCR_ERTYPE_Msk, type);
}

/**
  * @brief    Get code flash erase type
  * @rmtoll   CFLS_EPCR    ERTYPE    FL_FLASH_GetCodeEraseType
  * @param    FLASHx FLASH instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_FLASH_CODE_ERASE_TYPE_PAGE
  *           @arg @ref FL_FLASH_CODE_ERASE_TYPE_SECTOR
  */
__STATIC_INLINE uint32_t FL_FLASH_GetCodeEraseType(FLASH_Type* FLASHx)
{
    return (uint32_t)(READ_BIT(FLASHx->CFLS_EPCR, FLASH_CFLS_EPCR_ERTYPE_Msk));
}

/**
  * @brief    Code Flash program request enable
  * @rmtoll   CFLS_EPCR    PREQ    FL_FLASH_EnableCodeProgram
  * @param    FLASHx FLASH instance
  * @retval   None
  */
__STATIC_INLINE void FL_FLASH_EnableCodeProgram(FLASH_Type* FLASHx)
{
    CLEAR_BIT(FLASHx->CFLS_EPCR, FLASH_CFLS_EPCR_EREQ_Msk);
    SET_BIT(FLASHx->CFLS_EPCR, FLASH_CFLS_EPCR_PREQ_Msk);
}

/**
  * @brief    Code Flash program request disable
  * @rmtoll   CFLS_EPCR    PREQ    FL_FLASH_DisableCodeProgram
  * @param    FLASHx FLASH instance
  * @retval   None
  */
__STATIC_INLINE void FL_FLASH_DisableCodeProgram(FLASH_Type* FLASHx)
{
    CLEAR_BIT(FLASHx->CFLS_EPCR, FLASH_CFLS_EPCR_PREQ_Msk);
}

/**
  * @brief    Code Flash program request enable
  * @rmtoll   CFLS_EPCR    EREQ    FL_FLASH_EnableCodeErase
  * @param    FLASHx FLASH instance
  * @retval   None
  */
__STATIC_INLINE void FL_FLASH_EnableCodeErase(FLASH_Type* FLASHx)
{
    CLEAR_BIT(FLASHx->CFLS_EPCR, FLASH_CFLS_EPCR_PREQ_Msk);
    SET_BIT(FLASHx->CFLS_EPCR, FLASH_CFLS_EPCR_EREQ_Msk);
}

/**
  * @brief    Code Flash program request disable
  * @rmtoll   CFLS_EPCR    EREQ    FL_FLASH_DisableCodeErase
  * @param    FLASHx FLASH instance
  * @retval   None
  */
__STATIC_INLINE void FL_FLASH_DisableCodeErase(FLASH_Type* FLASHx)
{
    CLEAR_BIT(FLASHx->CFLS_EPCR, FLASH_CFLS_EPCR_EREQ_Msk);
}

/**
  * @brief    Set code flash key
  * @rmtoll   CFLS_KEY        FL_FLASH_CodeUnlock
  * @param    FLASHx FLASH instance
  * @param    key 
  * @retval   None
  */
__STATIC_INLINE void FL_FLASH_CodeUnlock(FLASH_Type* FLASHx, uint32_t key)
{
    WRITE_REG(FLASHx->CFLS_KEY, key);
}

/**
  * @brief    Reset code flash key
  * @rmtoll   CFLS_KEY        FL_FLASH_CodeLock
  * @param    FLASHx FLASH instance
  * @retval   None
  */
__STATIC_INLINE void FL_FLASH_CodeLock(FLASH_Type* FLASHx)
{
    WRITE_REG(FLASHx->CFLS_KEY, 0xFFFFFFFF);
}

/**
  * @brief    Code flash authentication error interrupt enable
  * @rmtoll   CFLS_IER    AUTHIE    FL_FLASH_EnableIT_CodeAuthenticationError
  * @param    FLASHx FLASH instance
  * @retval   None
  */
__STATIC_INLINE void FL_FLASH_EnableIT_CodeAuthenticationError(FLASH_Type* FLASHx)
{
    SET_BIT(FLASHx->CFLS_IER, FLASH_CFLS_IER_AUTHIE_Msk);
}

/**
  * @brief    Code flash authentication error interrupt disable
  * @rmtoll   CFLS_IER    AUTHIE    FL_FLASH_DisableIT_CodeAuthenticationError
  * @param    FLASHx FLASH instance
  * @retval   None
  */
__STATIC_INLINE void FL_FLASH_DisableIT_CodeAuthenticationError(FLASH_Type* FLASHx)
{
    CLEAR_BIT(FLASHx->CFLS_IER, FLASH_CFLS_IER_AUTHIE_Msk);
}

/**
  * @brief    Get code flash authentication error interrupt enable status
  * @rmtoll   CFLS_IER    AUTHIE    FL_FLASH_IsEnabledIT_CodeAuthenticationError
  * @param    FLASHx FLASH instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_FLASH_IsEnabledIT_CodeAuthenticationError(FLASH_Type* FLASHx)
{
    return (uint32_t)(READ_BIT(FLASHx->CFLS_IER, FLASH_CFLS_IER_AUTHIE_Msk) == FLASH_CFLS_IER_AUTHIE_Msk);
}

/**
  * @brief    Code flash key error interrupt enable
  * @rmtoll   CFLS_IER    KEYIE    FL_FLASH_EnableIT_CodeKeyError
  * @param    FLASHx FLASH instance
  * @retval   None
  */
__STATIC_INLINE void FL_FLASH_EnableIT_CodeKeyError(FLASH_Type* FLASHx)
{
    SET_BIT(FLASHx->CFLS_IER, FLASH_CFLS_IER_KEYIE_Msk);
}

/**
  * @brief    Code flash key error interrupt disable
  * @rmtoll   CFLS_IER    KEYIE    FL_FLASH_DisableIT_CodeKeyError
  * @param    FLASHx FLASH instance
  * @retval   None
  */
__STATIC_INLINE void FL_FLASH_DisableIT_CodeKeyError(FLASH_Type* FLASHx)
{
    CLEAR_BIT(FLASHx->CFLS_IER, FLASH_CFLS_IER_KEYIE_Msk);
}

/**
  * @brief    Get code flash key error interrupt enable status
  * @rmtoll   CFLS_IER    KEYIE    FL_FLASH_IsEnabledIT_CodeKeyError
  * @param    FLASHx FLASH instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_FLASH_IsEnabledIT_CodeKeyError(FLASH_Type* FLASHx)
{
    return (uint32_t)(READ_BIT(FLASHx->CFLS_IER, FLASH_CFLS_IER_KEYIE_Msk) == FLASH_CFLS_IER_KEYIE_Msk);
}

/**
  * @brief    Code flash erase/program clock error interrupt enable
  * @rmtoll   CFLS_IER    CKIE    FL_FLASH_EnableIT_CodeClockError
  * @param    FLASHx FLASH instance
  * @retval   None
  */
__STATIC_INLINE void FL_FLASH_EnableIT_CodeClockError(FLASH_Type* FLASHx)
{
    SET_BIT(FLASHx->CFLS_IER, FLASH_CFLS_IER_CKIE_Msk);
}

/**
  * @brief    Code flash erase/program clock error interrupt disable
  * @rmtoll   CFLS_IER    CKIE    FL_FLASH_DisableIT_CodeClockError
  * @param    FLASHx FLASH instance
  * @retval   None
  */
__STATIC_INLINE void FL_FLASH_DisableIT_CodeClockError(FLASH_Type* FLASHx)
{
    CLEAR_BIT(FLASHx->CFLS_IER, FLASH_CFLS_IER_CKIE_Msk);
}

/**
  * @brief    Get program flash erase/program clock error interrupt enable status
  * @rmtoll   CFLS_IER    CKIE    FL_FLASH_IsEnabledIT_CodeClockError
  * @param    FLASHx FLASH instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_FLASH_IsEnabledIT_CodeClockError(FLASH_Type* FLASHx)
{
    return (uint32_t)(READ_BIT(FLASHx->CFLS_IER, FLASH_CFLS_IER_CKIE_Msk) == FLASH_CFLS_IER_CKIE_Msk);
}

/**
  * @brief    Code flash program done interrupt enable
  * @rmtoll   CFLS_IER    PRDIE    FL_FLASH_EnableIT_CodeProgramComplete
  * @param    FLASHx FLASH instance
  * @retval   None
  */
__STATIC_INLINE void FL_FLASH_EnableIT_CodeProgramComplete(FLASH_Type* FLASHx)
{
    SET_BIT(FLASHx->CFLS_IER, FLASH_CFLS_IER_PRDIE_Msk);
}

/**
  * @brief    Code flash program done interrupt disable
  * @rmtoll   CFLS_IER    PRDIE    FL_FLASH_DisableIT_CodeProgramComplete
  * @param    FLASHx FLASH instance
  * @retval   None
  */
__STATIC_INLINE void FL_FLASH_DisableIT_CodeProgramComplete(FLASH_Type* FLASHx)
{
    CLEAR_BIT(FLASHx->CFLS_IER, FLASH_CFLS_IER_PRDIE_Msk);
}

/**
  * @brief    Get code flash program done interrupt enable status
  * @rmtoll   CFLS_IER    PRDIE    FL_FLASH_IsEnabledIT_CodeProgramComplete
  * @param    FLASHx FLASH instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_FLASH_IsEnabledIT_CodeProgramComplete(FLASH_Type* FLASHx)
{
    return (uint32_t)(READ_BIT(FLASHx->CFLS_IER, FLASH_CFLS_IER_PRDIE_Msk) == FLASH_CFLS_IER_PRDIE_Msk);
}

/**
  * @brief    Code flash erase done interrupt enable
  * @rmtoll   CFLS_IER    ERDIE    FL_FLASH_EnableIT_CodeEraseComplete
  * @param    FLASHx FLASH instance
  * @retval   None
  */
__STATIC_INLINE void FL_FLASH_EnableIT_CodeEraseComplete(FLASH_Type* FLASHx)
{
    SET_BIT(FLASHx->CFLS_IER, FLASH_CFLS_IER_ERDIE_Msk);
}

/**
  * @brief    Code flash erase done interrupt disable
  * @rmtoll   CFLS_IER    ERDIE    FL_FLASH_DisableIT_CodeEraseComplete
  * @param    FLASHx FLASH instance
  * @retval   None
  */
__STATIC_INLINE void FL_FLASH_DisableIT_CodeEraseComplete(FLASH_Type* FLASHx)
{
    CLEAR_BIT(FLASHx->CFLS_IER, FLASH_CFLS_IER_ERDIE_Msk);
}

/**
  * @brief    Get code flash erase done interrupt enable status
  * @rmtoll   CFLS_IER    ERDIE    FL_FLASH_IsEnabledIT_CodeEraseComplete
  * @param    FLASHx FLASH instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_FLASH_IsEnabledIT_CodeEraseComplete(FLASH_Type* FLASHx)
{
    return (uint32_t)(READ_BIT(FLASHx->CFLS_IER, FLASH_CFLS_IER_ERDIE_Msk) == FLASH_CFLS_IER_ERDIE_Msk);
}

/**
  * @brief    Get code flash key status
  * @rmtoll   CFLS_ISR    KEYSTA    FL_FLASH_GetCodeLockStatus
  * @param    FLASHx FLASH instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_FLASH_CODE_KEY_STATUS_LOCK
  *           @arg @ref FL_FLASH_CODE_KEY_STATUS_ALL_ERASE
  *           @arg @ref FL_FLASH_CODE_KEY_STATUS_PAGE_ERASE
  *           @arg @ref FL_FLASH_CODE_KEY_STATUS_PROGRAM
  *           @arg @ref FL_FLASH_CODE_KEY_STATUS_ERROR
  *           @arg @ref FL_FLASH_CODE_KEY_STATUS_SECTOR_ERASE
  */
__STATIC_INLINE uint32_t FL_FLASH_GetCodeLockStatus(FLASH_Type* FLASHx)
{
    return (uint32_t)(READ_BIT(FLASHx->CFLS_ISR, FLASH_CFLS_ISR_KEYSTA_Msk));
}

/**
  * @brief    Get Code Flash Authentication Error Flag
  * @rmtoll   CFLS_ISR    AUTHERR    FL_FLASH_IsActiveFlag_CodeAuthenticationError
  * @param    FLASHx FLASH instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_FLASH_IsActiveFlag_CodeAuthenticationError(FLASH_Type* FLASHx)
{
    return (uint32_t)(READ_BIT(FLASHx->CFLS_ISR, FLASH_CFLS_ISR_AUTHERR_Msk) == (FLASH_CFLS_ISR_AUTHERR_Msk));
}

/**
  * @brief    Clear Code Flash Authentication Error Flag
  * @rmtoll   CFLS_ISR    AUTHERR    FL_FLASH_ClearFlag_CodeAuthenticationError
  * @param    FLASHx FLASH instance
  * @retval   None
  */
__STATIC_INLINE void FL_FLASH_ClearFlag_CodeAuthenticationError(FLASH_Type* FLASHx)
{
    WRITE_REG(FLASHx->CFLS_ISR, FLASH_CFLS_ISR_AUTHERR_Msk);
}

/**
  * @brief    Get Code Flash Key Error Flag
  * @rmtoll   CFLS_ISR    KEYERR    FL_FLASH_IsActiveFlag_CodeKeyError
  * @param    FLASHx FLASH instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_FLASH_IsActiveFlag_CodeKeyError(FLASH_Type* FLASHx)
{
    return (uint32_t)(READ_BIT(FLASHx->CFLS_ISR, FLASH_CFLS_ISR_KEYERR_Msk) == (FLASH_CFLS_ISR_KEYERR_Msk));
}

/**
  * @brief    Clear Code Flash Key Error Flag
  * @rmtoll   CFLS_ISR    KEYERR    FL_FLASH_ClearFlag_CodeKeyError
  * @param    FLASHx FLASH instance
  * @retval   None
  */
__STATIC_INLINE void FL_FLASH_ClearFlag_CodeKeyError(FLASH_Type* FLASHx)
{
    WRITE_REG(FLASHx->CFLS_ISR, FLASH_CFLS_ISR_KEYERR_Msk);
}

/**
  * @brief    Get Code Flash Erase/Program Clock Error Flag
  * @rmtoll   CFLS_ISR    CKERR    FL_FLASH_IsActiveFlag_CodeClockError
  * @param    FLASHx FLASH instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_FLASH_IsActiveFlag_CodeClockError(FLASH_Type* FLASHx)
{
    return (uint32_t)(READ_BIT(FLASHx->CFLS_ISR, FLASH_CFLS_ISR_CKERR_Msk) == (FLASH_CFLS_ISR_CKERR_Msk));
}

/**
  * @brief    Clear Code Flash  Erase/Program Clock Error Flag
  * @rmtoll   CFLS_ISR    CKERR    FL_FLASH_ClearFlag_CodeClockError
  * @param    FLASHx FLASH instance
  * @retval   None
  */
__STATIC_INLINE void FL_FLASH_ClearFlag_CodeClockError(FLASH_Type* FLASHx)
{
    WRITE_REG(FLASHx->CFLS_ISR, FLASH_CFLS_ISR_CKERR_Msk);
}

/**
  * @brief    Get Code Flash  Program Done Flag
  * @rmtoll   CFLS_ISR    PRD    FL_FLASH_IsActiveFlag_CodeProgramComplete
  * @param    FLASHx FLASH instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_FLASH_IsActiveFlag_CodeProgramComplete(FLASH_Type* FLASHx)
{
    return (uint32_t)(READ_BIT(FLASHx->CFLS_ISR, FLASH_CFLS_ISR_PRD_Msk) == (FLASH_CFLS_ISR_PRD_Msk));
}

/**
  * @brief    Clear Code Flash  Program Done Flag
  * @rmtoll   CFLS_ISR    PRD    FL_FLASH_ClearFlag_CodeProgramComplete
  * @param    FLASHx FLASH instance
  * @retval   None
  */
__STATIC_INLINE void FL_FLASH_ClearFlag_CodeProgramComplete(FLASH_Type* FLASHx)
{
    WRITE_REG(FLASHx->CFLS_ISR, FLASH_CFLS_ISR_PRD_Msk);
}

/**
  * @brief    Get Code Flash  Erase Done Flag
  * @rmtoll   CFLS_ISR    ERD    FL_FLASH_IsActiveFlag_CodeEraseComplete
  * @param    FLASHx FLASH instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_FLASH_IsActiveFlag_CodeEraseComplete(FLASH_Type* FLASHx)
{
    return (uint32_t)(READ_BIT(FLASHx->CFLS_ISR, FLASH_CFLS_ISR_ERD_Msk) == (FLASH_CFLS_ISR_ERD_Msk));
}

/**
  * @brief    Clear Code Flash  Erase Done Flag
  * @rmtoll   CFLS_ISR    ERD    FL_FLASH_ClearFlag_CodeEraseComplete
  * @param    FLASHx FLASH instance
  * @retval   None
  */
__STATIC_INLINE void FL_FLASH_ClearFlag_CodeEraseComplete(FLASH_Type* FLASHx)
{
    WRITE_REG(FLASHx->CFLS_ISR, FLASH_CFLS_ISR_ERD_Msk);
}

/**
  * @brief    Set data flash erase type 
  * @rmtoll   DFLS_EPCR    ERTYPE    FL_FLASH_SetDataEraseType
  * @param    FLASHx FLASH instance
  * @param    type This parameter can be one of the following values:
  *           @arg @ref FL_FLASH_DATA_ERASE_TYPE_PAGE
  *           @arg @ref FL_FLASH_DATA_ERASE_TYPE_SECTOR
  * @retval   None
  */
__STATIC_INLINE void FL_FLASH_SetDataEraseType(FLASH_Type* FLASHx, uint32_t type)
{
    MODIFY_REG(FLASHx->DFLS_EPCR, FLASH_DFLS_EPCR_ERTYPE_Msk, type);
}

/**
  * @brief    Get data flash erase type
  * @rmtoll   DFLS_EPCR    ERTYPE    FL_FLASH_GetDataEraseType
  * @param    FLASHx FLASH instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_FLASH_DATA_ERASE_TYPE_PAGE
  *           @arg @ref FL_FLASH_DATA_ERASE_TYPE_SECTOR
  */
__STATIC_INLINE uint32_t FL_FLASH_GetDataEraseType(FLASH_Type* FLASHx)
{
    return (uint32_t)(READ_BIT(FLASHx->DFLS_EPCR, FLASH_DFLS_EPCR_ERTYPE_Msk));
}

/**
  * @brief    Data Flash program request enable
  * @rmtoll   DFLS_EPCR    PREQ    FL_FLASH_EnableDataProgram
  * @param    FLASHx FLASH instance
  * @retval   None
  */
__STATIC_INLINE void FL_FLASH_EnableDataProgram(FLASH_Type* FLASHx)
{
    CLEAR_BIT(FLASHx->DFLS_EPCR, FLASH_DFLS_EPCR_EREQ_Msk);
    SET_BIT(FLASHx->DFLS_EPCR, FLASH_DFLS_EPCR_PREQ_Msk);
}

/**
  * @brief    Data Flash program request disable
  * @rmtoll   DFLS_EPCR    PREQ    FL_FLASH_DisableDataProgram
  * @param    FLASHx FLASH instance
  * @retval   None
  */
__STATIC_INLINE void FL_FLASH_DisableDataProgram(FLASH_Type* FLASHx)
{
    CLEAR_BIT(FLASHx->DFLS_EPCR, FLASH_DFLS_EPCR_PREQ_Msk);
}

/**
  * @brief    Data Flash program request enable
  * @rmtoll   DFLS_EPCR    EREQ    FL_FLASH_EnableDataErase
  * @param    FLASHx FLASH instance
  * @retval   None
  */
__STATIC_INLINE void FL_FLASH_EnableDataErase(FLASH_Type* FLASHx)
{
    CLEAR_BIT(FLASHx->DFLS_EPCR, FLASH_DFLS_EPCR_PREQ_Msk);
    SET_BIT(FLASHx->DFLS_EPCR, FLASH_DFLS_EPCR_EREQ_Msk);
}

/**
  * @brief    Data Flash program request disable
  * @rmtoll   DFLS_EPCR    EREQ    FL_FLASH_DisableDataErase
  * @param    FLASHx FLASH instance
  * @retval   None
  */
__STATIC_INLINE void FL_FLASH_DisableDataErase(FLASH_Type* FLASHx)
{
    CLEAR_BIT(FLASHx->DFLS_EPCR, FLASH_DFLS_EPCR_EREQ_Msk);
}

/**
  * @brief    Set data flash key
  * @rmtoll   DFLS_KEY        FL_FLASH_DataUnlock
  * @param    FLASHx FLASH instance
  * @param    key 
  * @retval   None
  */
__STATIC_INLINE void FL_FLASH_DataUnlock(FLASH_Type* FLASHx, uint32_t key)
{
    WRITE_REG(FLASHx->DFLS_KEY, key);
}

/**
  * @brief    Reset data flash key
  * @rmtoll   DFLS_KEY        FL_FLASH_DataLock
  * @param    FLASHx FLASH instance
  * @retval   None
  */
__STATIC_INLINE void FL_FLASH_DataLock(FLASH_Type* FLASHx)
{
    WRITE_REG(FLASHx->DFLS_KEY, 0xFFFFFFFF);
}

/**
  * @brief    Data flash authentication error interrupt enable
  * @rmtoll   DFLS_IER    AUTHIE    FL_FLASH_EnableIT_DataAuthenticationError
  * @param    FLASHx FLASH instance
  * @retval   None
  */
__STATIC_INLINE void FL_FLASH_EnableIT_DataAuthenticationError(FLASH_Type* FLASHx)
{
    if (CHIP_U01)
    {   /* Note:As this bit is not supported for reading, you must wait until all
           other bits in this register have been configured befor configuring this
           bit last. */
        SET_BIT(FLASHx->DFLS_IER, FLASH_DFLS_IER_AUTHIE_Msk);
    }
    else
    {
        SET_BIT(FLASHx->CFLS_IER, FLASH_CFLS_IER_DAUTHIE_Msk);
    }
}

/**
  * @brief    Data flash authentication error interrupt disable
  * @rmtoll   DFLS_IER    AUTHIE    FL_FLASH_DisableIT_DataAuthenticationError
  * @param    FLASHx FLASH instance
  * @retval   None
  */
__STATIC_INLINE void FL_FLASH_DisableIT_DataAuthenticationError(FLASH_Type* FLASHx)
{
    if (CHIP_U01)
    {
        CLEAR_BIT(FLASHx->DFLS_IER, FLASH_DFLS_IER_AUTHIE_Msk);
    }
    else
    {
        CLEAR_BIT(FLASHx->CFLS_IER, FLASH_CFLS_IER_DAUTHIE_Msk);
    }
}

/**
  * @brief    Get flash authentication error interrupt enable status
  * @rmtoll   DFLS_IER    AUTHIE    FL_FLASH_IsEnabledIT_DataAuthenticationError
  * @param    FLASHx FLASH instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_FLASH_IsEnabledIT_DataAuthenticationError(FLASH_Type* FLASHx)
{
    if (CHIP_U01)
    {   /* Note:Function not implemented, fixed return 0. */
        return (uint32_t)(READ_BIT(FLASHx->DFLS_IER, FLASH_DFLS_IER_AUTHIE_Msk) == FLASH_DFLS_IER_AUTHIE_Msk);
    }
    else
    {
        return (uint32_t)(READ_BIT(FLASHx->CFLS_IER, FLASH_CFLS_IER_DAUTHIE_Msk) == FLASH_CFLS_IER_DAUTHIE_Msk);
    }
}

/**
  * @brief    Data flash key error interrupt enable
  * @rmtoll   DFLS_IER    KEYIE    FL_FLASH_EnableIT_DataKeyError
  * @param    FLASHx FLASH instance
  * @retval   None
  */
__STATIC_INLINE void FL_FLASH_EnableIT_DataKeyError(FLASH_Type* FLASHx)
{
    SET_BIT(FLASHx->DFLS_IER, FLASH_DFLS_IER_KEYIE_Msk);
}

/**
  * @brief    Data flash key error interrupt disable
  * @rmtoll   DFLS_IER    KEYIE    FL_FLASH_DisableIT_DataKeyError
  * @param    FLASHx FLASH instance
  * @retval   None
  */
__STATIC_INLINE void FL_FLASH_DisableIT_DataKeyError(FLASH_Type* FLASHx)
{
    CLEAR_BIT(FLASHx->DFLS_IER, FLASH_DFLS_IER_KEYIE_Msk);
}

/**
  * @brief    Get data flash key error interrupt enable status
  * @rmtoll   DFLS_IER    KEYIE    FL_FLASH_IsEnabledIT_DataKeyError
  * @param    FLASHx FLASH instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_FLASH_IsEnabledIT_DataKeyError(FLASH_Type* FLASHx)
{
    return (uint32_t)(READ_BIT(FLASHx->DFLS_IER, FLASH_DFLS_IER_KEYIE_Msk) == FLASH_DFLS_IER_KEYIE_Msk);
}

/**
  * @brief    Data flash erase/program clock error interrupt enable
  * @rmtoll   DFLS_IER    CKIE    FL_FLASH_EnableIT_DataClockError
  * @param    FLASHx FLASH instance
  * @retval   None
  */
__STATIC_INLINE void FL_FLASH_EnableIT_DataClockError(FLASH_Type* FLASHx)
{
    SET_BIT(FLASHx->DFLS_IER, FLASH_DFLS_IER_CKIE_Msk);
}

/**
  * @brief    Data flash erase/program clock error interrupt disable
  * @rmtoll   DFLS_IER    CKIE    FL_FLASH_DisableIT_DataClockError
  * @param    FLASHx FLASH instance
  * @retval   None
  */
__STATIC_INLINE void FL_FLASH_DisableIT_DataClockError(FLASH_Type* FLASHx)
{
    CLEAR_BIT(FLASHx->DFLS_IER, FLASH_DFLS_IER_CKIE_Msk);
}

/**
  * @brief    Get data flash erase/program clock error interrupt enable status
  * @rmtoll   DFLS_IER    CKIE    FL_FLASH_IsEnabledIT_DataClockError
  * @param    FLASHx FLASH instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_FLASH_IsEnabledIT_DataClockError(FLASH_Type* FLASHx)
{
    return (uint32_t)(READ_BIT(FLASHx->DFLS_IER, FLASH_DFLS_IER_CKIE_Msk) == FLASH_DFLS_IER_CKIE_Msk);
}

/**
  * @brief    Data flash program done interrupt enable
  * @rmtoll   DFLS_IER    PRDIE    FL_FLASH_EnableIT_DataProgramComplete
  * @param    FLASHx FLASH instance
  * @retval   None
  */
__STATIC_INLINE void FL_FLASH_EnableIT_DataProgramComplete(FLASH_Type* FLASHx)
{
    SET_BIT(FLASHx->DFLS_IER, FLASH_DFLS_IER_PRDIE_Msk);
}

/**
  * @brief    Data flash program done interrupt disable
  * @rmtoll   DFLS_IER    PRDIE    FL_FLASH_DisableIT_DataProgramComplete
  * @param    FLASHx FLASH instance
  * @retval   None
  */
__STATIC_INLINE void FL_FLASH_DisableIT_DataProgramComplete(FLASH_Type* FLASHx)
{
    CLEAR_BIT(FLASHx->DFLS_IER, FLASH_DFLS_IER_PRDIE_Msk);
}

/**
  * @brief    Get data flash program done interrupt enable status
  * @rmtoll   DFLS_IER    PRDIE    FL_FLASH_IsEnabledIT_DataProgramComplete
  * @param    FLASHx FLASH instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_FLASH_IsEnabledIT_DataProgramComplete(FLASH_Type* FLASHx)
{
    return (uint32_t)(READ_BIT(FLASHx->DFLS_IER, FLASH_DFLS_IER_PRDIE_Msk) == FLASH_DFLS_IER_PRDIE_Msk);
}

/**
  * @brief    Data flash erase done interrupt enable
  * @rmtoll   DFLS_IER    ERDIE    FL_FLASH_EnableIT_DataEraseComplete
  * @param    FLASHx FLASH instance
  * @retval   None
  */
__STATIC_INLINE void FL_FLASH_EnableIT_DataEraseComplete(FLASH_Type* FLASHx)
{
    SET_BIT(FLASHx->DFLS_IER, FLASH_DFLS_IER_ERDIE_Msk);
}

/**
  * @brief    Data flash erase done interrupt disable
  * @rmtoll   DFLS_IER    ERDIE    FL_FLASH_DisableIT_DataEraseComplete
  * @param    FLASHx FLASH instance
  * @retval   None
  */
__STATIC_INLINE void FL_FLASH_DisableIT_DataEraseComplete(FLASH_Type* FLASHx)
{
    CLEAR_BIT(FLASHx->DFLS_IER, FLASH_DFLS_IER_ERDIE_Msk);
}

/**
  * @brief    Get data flash erase done interrupt enable status
  * @rmtoll   DFLS_IER    ERDIE    FL_FLASH_IsEnabledIT_DatahEraseComplete
  * @param    FLASHx FLASH instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_FLASH_IsEnabledIT_DatahEraseComplete(FLASH_Type* FLASHx)
{
    return (uint32_t)(READ_BIT(FLASHx->DFLS_IER, FLASH_DFLS_IER_ERDIE_Msk) == FLASH_DFLS_IER_ERDIE_Msk);
}

/**
  * @brief    Get data flash key status
  * @rmtoll   DFLS_ISR    KEYSTA    FL_FLASH_GetDataLockStatus
  * @param    FLASHx FLASH instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_FLASH_DATA_KEY_STATUS_LOCK
  *           @arg @ref FL_FLASH_DATA_KEY_STATUS_ALL_ERASE
  *           @arg @ref FL_FLASH_DATA_KEY_STATUS_PAGE_ERASE
  *           @arg @ref FL_FLASH_DATA_KEY_STATUS_PROGRAM
  *           @arg @ref FL_FLASH_DATA_KEY_STATUS_ERROR
  *           @arg @ref FL_FLASH_DATA_KEY_STATUS_SECTOR_ERASE
  */
__STATIC_INLINE uint32_t FL_FLASH_GetDataLockStatus(FLASH_Type* FLASHx)
{
    return (uint32_t)(READ_BIT(FLASHx->DFLS_ISR, FLASH_DFLS_ISR_KEYSTA_Msk));
}

/**
  * @brief    Get Data Flash Authentication Error Flag
  * @rmtoll   DFLS_ISR    AUTHERR    FL_FLASH_IsActiveFlag_DataAuthenticationError
  * @param    FLASHx FLASH instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_FLASH_IsActiveFlag_DataAuthenticationError(FLASH_Type* FLASHx)
{
    return (uint32_t)(READ_BIT(FLASHx->DFLS_ISR, FLASH_DFLS_ISR_AUTHERR_Msk) == (FLASH_DFLS_ISR_AUTHERR_Msk));
}

/**
  * @brief    Clear Data Flash Authentication Error Flag
  * @rmtoll   DFLS_ISR    AUTHERR    FL_FLASH_ClearFlag_DataAuthenticationError
  * @param    FLASHx FLASH instance
  * @retval   None
  */
__STATIC_INLINE void FL_FLASH_ClearFlag_DataAuthenticationError(FLASH_Type* FLASHx)
{
    WRITE_REG(FLASHx->DFLS_ISR, FLASH_DFLS_ISR_AUTHERR_Msk);
}

/**
  * @brief    Get Data Flash Key Error Flag
  * @rmtoll   DFLS_ISR    KEYERR    FL_FLASH_IsActiveFlag_DataKeyError
  * @param    FLASHx FLASH instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_FLASH_IsActiveFlag_DataKeyError(FLASH_Type* FLASHx)
{
    return (uint32_t)(READ_BIT(FLASHx->DFLS_ISR, FLASH_DFLS_ISR_KEYERR_Msk) == (FLASH_DFLS_ISR_KEYERR_Msk));
}

/**
  * @brief    Clear Data Flash Key Error Flag
  * @rmtoll   DFLS_ISR    KEYERR    FL_FLASH_ClearFlag_DataKeyError
  * @param    FLASHx FLASH instance
  * @retval   None
  */
__STATIC_INLINE void FL_FLASH_ClearFlag_DataKeyError(FLASH_Type* FLASHx)
{
    WRITE_REG(FLASHx->DFLS_ISR, FLASH_DFLS_ISR_KEYERR_Msk);
}

/**
  * @brief    Get Data Flash Erase/Program Clock Error Flag
  * @rmtoll   DFLS_ISR    CKERR    FL_FLASH_IsActiveFlag_DataClockError
  * @param    FLASHx FLASH instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_FLASH_IsActiveFlag_DataClockError(FLASH_Type* FLASHx)
{
    return (uint32_t)(READ_BIT(FLASHx->DFLS_ISR, FLASH_DFLS_ISR_CKERR_Msk) == (FLASH_DFLS_ISR_CKERR_Msk));
}

/**
  * @brief    Clear Data Flash  Erase/Program Clock Error Flag
  * @rmtoll   DFLS_ISR    CKERR    FL_FLASH_ClearFlag_DataClockError
  * @param    FLASHx FLASH instance
  * @retval   None
  */
__STATIC_INLINE void FL_FLASH_ClearFlag_DataClockError(FLASH_Type* FLASHx)
{
    WRITE_REG(FLASHx->DFLS_ISR, FLASH_DFLS_ISR_CKERR_Msk);
}

/**
  * @brief    Get Data Flash  Program Done Flag
  * @rmtoll   DFLS_ISR    PRD    FL_FLASH_IsActiveFlag_DataProgramComplete
  * @param    FLASHx FLASH instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_FLASH_IsActiveFlag_DataProgramComplete(FLASH_Type* FLASHx)
{
    return (uint32_t)(READ_BIT(FLASHx->DFLS_ISR, FLASH_DFLS_ISR_PRD_Msk) == (FLASH_DFLS_ISR_PRD_Msk));
}

/**
  * @brief    Clear Data Flash  Program Done Flag
  * @rmtoll   DFLS_ISR    PRD    FL_FLASH_ClearFlag_DataProgramComplete
  * @param    FLASHx FLASH instance
  * @retval   None
  */
__STATIC_INLINE void FL_FLASH_ClearFlag_DataProgramComplete(FLASH_Type* FLASHx)
{
    WRITE_REG(FLASHx->DFLS_ISR, FLASH_DFLS_ISR_PRD_Msk);
}

/**
  * @brief    Get Data Flash  Erase Done Flag
  * @rmtoll   DFLS_ISR    ERD    FL_FLASH_IsActiveFlag_DataEraseComplete
  * @param    FLASHx FLASH instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_FLASH_IsActiveFlag_DataEraseComplete(FLASH_Type* FLASHx)
{
    return (uint32_t)(READ_BIT(FLASHx->DFLS_ISR, FLASH_DFLS_ISR_ERD_Msk) == (FLASH_DFLS_ISR_ERD_Msk));
}

/**
  * @brief    Clear Data Flash  Erase Done Flag
  * @rmtoll   DFLS_ISR    ERD    FL_FLASH_ClearFlag_DataEraseComplete
  * @param    FLASHx FLASH instance
  * @retval   None
  */
__STATIC_INLINE void FL_FLASH_ClearFlag_DataEraseComplete(FLASH_Type* FLASHx)
{
    WRITE_REG(FLASHx->DFLS_ISR, FLASH_DFLS_ISR_ERD_Msk);
}

/**
  * @brief    Get ECC Detection Flag in Code Flash
  * @rmtoll   CFLS_ECCR    ECCDD    FL_FLASH_IsActiveFlag_ECCDetectionInCodeFlash
  * @param    FLASHx FLASH instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_FLASH_IsActiveFlag_ECCDetectionInCodeFlash(FLASH_Type* FLASHx)
{
    return (uint32_t)(READ_BIT(FLASHx->CFLS_ECCR, FLASH_CFLS_ECCR_ECCDD_Msk) == (FLASH_CFLS_ECCR_ECCDD_Msk));
}

/**
  * @brief    Clear ECC Detection Flag in Code Flash
  * @rmtoll   CFLS_ECCR    ECCDD    FL_FLASH_ClearFlag_ECCDetectionInCodeFlash
  * @param    FLASHx FLASH instance
  * @retval   None
  */
__STATIC_INLINE void FL_FLASH_ClearFlag_ECCDetectionInCodeFlash(FLASH_Type* FLASHx)
{
    WRITE_REG(FLASHx->CFLS_ECCR, (FLASH_CFLS_ECCR_ECCDD_Msk | (FLASHx->CFLS_ECCR & FLASH_CFLS_ECCR_ECCCIE_Msk)));
}

/**
  * @brief    Get ECC Correction Flag in Code Flash
  * @rmtoll   CFLS_ECCR    ECCCD    FL_FLASH_IsActiveFlag_ECCCorrectionInCodeFlash
  * @param    FLASHx FLASH instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_FLASH_IsActiveFlag_ECCCorrectionInCodeFlash(FLASH_Type* FLASHx)
{
    return (uint32_t)(READ_BIT(FLASHx->CFLS_ECCR, FLASH_CFLS_ECCR_ECCCD_Msk) == (FLASH_CFLS_ECCR_ECCCD_Msk));
}

/**
  * @brief    Clear  ECC Correction Flag in Code Flash
  * @rmtoll   CFLS_ECCR    ECCCD    FL_FLASH_ClearFlag_ECCCorrectionInCodeFlash
  * @param    FLASHx FLASH instance
  * @retval   None
  */
__STATIC_INLINE void FL_FLASH_ClearFlag_ECCCorrectionInCodeFlash(FLASH_Type* FLASHx)
{
    WRITE_REG(FLASHx->CFLS_ECCR, (FLASH_CFLS_ECCR_ECCCD_Msk | (FLASHx->CFLS_ECCR & FLASH_CFLS_ECCR_ECCCIE_Msk)));
}

/**
  * @brief    ECC interrupt enable in Code Flash
  * @rmtoll   CFLS_ECCR    ECCCIE    FL_FLASH_EnableIT_ECCInterruptInCodeFlash
  * @param    FLASHx FLASH instance
  * @retval   None
  */
__STATIC_INLINE void FL_FLASH_EnableIT_ECCInterruptInCodeFlash(FLASH_Type* FLASHx)
{
    SET_BIT(FLASHx->CFLS_ECCR, FLASH_CFLS_ECCR_ECCCIE_Msk);
}

/**
  * @brief    SECC interrupt disable in Code Flash
  * @rmtoll   CFLS_ECCR    ECCCIE    FL_FLASH_DisableIT_ECCInterruptInCodeFlash
  * @param    FLASHx FLASH instance
  * @retval   None
  */
__STATIC_INLINE void FL_FLASH_DisableIT_ECCInterruptInCodeFlash(FLASH_Type* FLASHx)
{
    CLEAR_BIT(FLASHx->CFLS_ECCR, FLASH_CFLS_ECCR_ECCCIE_Msk);
}

/**
  * @brief    Get ECC interrupt enable status in Code Flash
  * @rmtoll   CFLS_ECCR    ECCCIE    FL_FLASH_IsEnabledIT_ECCInterruptInCodeFlash
  * @param    FLASHx FLASH instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_FLASH_IsEnabledIT_ECCInterruptInCodeFlash(FLASH_Type* FLASHx)
{
    return (uint32_t)(READ_BIT(FLASHx->CFLS_ECCR, FLASH_CFLS_ECCR_ECCCIE_Msk) == FLASH_CFLS_ECCR_ECCCIE_Msk);
}

/**
  * @brief    Read ECC Error Address in Code Flash
  * @rmtoll   CFLS_ECCR    ADDR_ECC    FL_FLASH_ReadECCErrorAddressInCodeFlash
  * @param    FLASHx FLASH instance
  * @retval   
  */
__STATIC_INLINE uint32_t FL_FLASH_ReadECCErrorAddressInCodeFlash(FLASH_Type* FLASHx)
{
    return (uint32_t)(READ_BIT(FLASHx->CFLS_ECCR, (0x1ffffU << 0U)) >> 0U);
}

/**
  * @brief    Get ECC Detection Flag in Data Flash
  * @rmtoll   DFLS_ECCR    ECCDD    FL_FLASH_IsActiveFlag_ECCDetectionInDataFlash
  * @param    FLASHx FLASH instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_FLASH_IsActiveFlag_ECCDetectionInDataFlash(FLASH_Type* FLASHx)
{
    return (uint32_t)(READ_BIT(FLASHx->DFLS_ECCR, FLASH_DFLS_ECCR_ECCDD_Msk) == (FLASH_DFLS_ECCR_ECCDD_Msk));
}

/**
  * @brief    Clear ECC Detection Flag in Data Flash
  * @rmtoll   DFLS_ECCR    ECCDD    FL_FLASH_ClearFlag_ECCDetectionInDataFlash
  * @param    FLASHx FLASH instance
  * @retval   None
  */
__STATIC_INLINE void FL_FLASH_ClearFlag_ECCDetectionInDataFlash(FLASH_Type* FLASHx)
{
    WRITE_REG(FLASHx->DFLS_ECCR, (FLASH_DFLS_ECCR_ECCDD_Msk | (FLASHx->DFLS_ECCR & FLASH_DFLS_ECCR_ECCCIE_Msk)));
}

/**
  * @brief    Get ECC Correction Flag in Data Flash
  * @rmtoll   DFLS_ECCR    ECCCD    FL_FLASH_IsActiveFlag_ECCCorrectionInDataFlash
  * @param    FLASHx FLASH instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_FLASH_IsActiveFlag_ECCCorrectionInDataFlash(FLASH_Type* FLASHx)
{
    return (uint32_t)(READ_BIT(FLASHx->DFLS_ECCR, FLASH_DFLS_ECCR_ECCCD_Msk) == (FLASH_DFLS_ECCR_ECCCD_Msk));
}

/**
  * @brief    Clear ECC Correction Flag in Data Flash
  * @rmtoll   DFLS_ECCR    ECCCD    FL_FLASH_ClearFlag_ECCCorrectionInDataFlash
  * @param    FLASHx FLASH instance
  * @retval   None
  */
__STATIC_INLINE void FL_FLASH_ClearFlag_ECCCorrectionInDataFlash(FLASH_Type* FLASHx)
{
    WRITE_REG(FLASHx->DFLS_ECCR, (FLASH_DFLS_ECCR_ECCCD_Msk | (FLASHx->DFLS_ECCR & FLASH_DFLS_ECCR_ECCCIE_Msk)));
}

/**
  * @brief    ECC interrupt enable in Data Flash
  * @rmtoll   DFLS_ECCR    ECCCIE    FL_FLASH_EnableIT_ECCInterruptInDataFlash
  * @param    FLASHx FLASH instance
  * @retval   None
  */
__STATIC_INLINE void FL_FLASH_EnableIT_ECCInterruptInDataFlash(FLASH_Type* FLASHx)
{
    SET_BIT(FLASHx->DFLS_ECCR, FLASH_DFLS_ECCR_ECCCIE_Msk);
}

/**
  * @brief    ECC interrupt disable in Data Flash
  * @rmtoll   DFLS_ECCR    ECCCIE    FL_FLASH_DisableIT_ECCInterruptInDataFlash
  * @param    FLASHx FLASH instance
  * @retval   None
  */
__STATIC_INLINE void FL_FLASH_DisableIT_ECCInterruptInDataFlash(FLASH_Type* FLASHx)
{
    CLEAR_BIT(FLASHx->DFLS_ECCR, FLASH_DFLS_ECCR_ECCCIE_Msk);
}

/**
  * @brief    Get ECC interrupt enable status in Data Flash
  * @rmtoll   DFLS_ECCR    ECCCIE    FL_FLASH_IsEnabledIT_ECCInterruptInDataFlash
  * @param    FLASHx FLASH instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_FLASH_IsEnabledIT_ECCInterruptInDataFlash(FLASH_Type* FLASHx)
{
    return (uint32_t)(READ_BIT(FLASHx->DFLS_ECCR, FLASH_DFLS_ECCR_ECCCIE_Msk) == FLASH_DFLS_ECCR_ECCCIE_Msk);
}

/**
  * @brief    Read ECC Error Address in Data Flash
  * @rmtoll   DFLS_ECCR    ADDR_ECC    FL_FLASH_ReadECCErrorAddressInDataFlash
  * @param    FLASHx FLASH instance
  * @retval   
  */
__STATIC_INLINE uint32_t FL_FLASH_ReadECCErrorAddressInDataFlash(FLASH_Type* FLASHx)
{
    return (uint32_t)(READ_BIT(FLASHx->DFLS_ECCR, (0xfffU << 0U)) >> 0U);
}

/**
  * @brief    Get ECC Detection Flag in RAM
  * @rmtoll   RAM_ECCR    ECCDD    FL_FLASH_IsActiveFlag_ECCDetectionInRAM
  * @param    FLASHx FLASH instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_FLASH_IsActiveFlag_ECCDetectionInRAM(FLASH_Type* FLASHx)
{
    return (uint32_t)(READ_BIT(FLASHx->RAM_ECCR, FLASH_RAM_ECCR_ECCDD_Msk) == (FLASH_RAM_ECCR_ECCDD_Msk));
}

/**
  * @brief    Clear ECC Detection Flag in RAM
  * @rmtoll   RAM_ECCR    ECCDD    FL_FLASH_ClearFlag_ECCDetectionInRAM
  * @param    FLASHx FLASH instance
  * @retval   None
  */
__STATIC_INLINE void FL_FLASH_ClearFlag_ECCDetectionInRAM(FLASH_Type* FLASHx)
{
    WRITE_REG(FLASHx->RAM_ECCR, (FLASH_RAM_ECCR_ECCDD_Msk | (FLASHx->RAM_ECCR & FLASH_RAM_ECCR_ECCCIE_Msk)));
}

/**
  * @brief    Get ECC Correction Flag in RAM
  * @rmtoll   RAM_ECCR    ECCCD    FL_FLASH_IsActiveFlag_ECCCorrectionInRAM
  * @param    FLASHx FLASH instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_FLASH_IsActiveFlag_ECCCorrectionInRAM(FLASH_Type* FLASHx)
{
    return (uint32_t)(READ_BIT(FLASHx->RAM_ECCR, FLASH_RAM_ECCR_ECCCD_Msk) == (FLASH_RAM_ECCR_ECCCD_Msk));
}

/**
  * @brief    Clear ECC Correction Flag in RAM
  * @rmtoll   RAM_ECCR    ECCCD    FL_FLASH_ClearFlag_ECCCorrectionInRAM
  * @param    FLASHx FLASH instance
  * @retval   None
  */
__STATIC_INLINE void FL_FLASH_ClearFlag_ECCCorrectionInRAM(FLASH_Type* FLASHx)
{
    WRITE_REG(FLASHx->RAM_ECCR, (FLASH_RAM_ECCR_ECCCD_Msk | (FLASHx->RAM_ECCR & FLASH_RAM_ECCR_ECCCIE_Msk)));
}

/**
  * @brief    Get ECC Bit Error Flag in RAM
  * @rmtoll   RAM_ECCR    ECCBE    FL_FLASH_IsActiveFlag_ECCBitErrorInRAM
  * @param    FLASHx FLASH instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_FLASH_IsActiveFlag_ECCBitErrorInRAM(FLASH_Type* FLASHx)
{
    return (uint32_t)(READ_BIT(FLASHx->RAM_ECCR, FLASH_RAM_ECCR_ECCBE_Msk) == (FLASH_RAM_ECCR_ECCBE_Msk));
}

/**
  * @brief    Clear ECC Bit Error Flag in RAM
  * @rmtoll   RAM_ECCR    ECCBE    FL_FLASH_ClearFlag_ECCBitErrorInRAM
  * @param    FLASHx FLASH instance
  * @retval   None
  */
__STATIC_INLINE void FL_FLASH_ClearFlag_ECCBitErrorInRAM(FLASH_Type* FLASHx)
{
    WRITE_REG(FLASHx->RAM_ECCR, (FLASH_RAM_ECCR_ECCBE_Msk | (FLASHx->RAM_ECCR & FLASH_RAM_ECCR_ECCCIE_Msk)));
}

/**
  * @brief    ECC interrupt enable in RAM
  * @rmtoll   RAM_ECCR    ECCCIE    FL_FLASH_EnableIT_ECCInterruptInRAM
  * @param    FLASHx FLASH instance
  * @retval   None
  */
__STATIC_INLINE void FL_FLASH_EnableIT_ECCInterruptInRAM(FLASH_Type* FLASHx)
{
    SET_BIT(FLASHx->RAM_ECCR, FLASH_RAM_ECCR_ECCCIE_Msk);
}

/**
  * @brief    ECC interrupt disable in RAM
  * @rmtoll   RAM_ECCR    ECCCIE    FL_FLASH_DisableIT_ECCInterruptInRAM
  * @param    FLASHx FLASH instance
  * @retval   None
  */
__STATIC_INLINE void FL_FLASH_DisableIT_ECCInterruptInRAM(FLASH_Type* FLASHx)
{
    CLEAR_BIT(FLASHx->RAM_ECCR, FLASH_RAM_ECCR_ECCCIE_Msk);
}

/**
  * @brief    Get ECC interrupt enable status in RAM
  * @rmtoll   RAM_ECCR    ECCCIE    FL_FLASH_IsEnabledIT_ECCInterruptInRAM
  * @param    FLASHx FLASH instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_FLASH_IsEnabledIT_ECCInterruptInRAM(FLASH_Type* FLASHx)
{
    return (uint32_t)(READ_BIT(FLASHx->RAM_ECCR, FLASH_RAM_ECCR_ECCCIE_Msk) == FLASH_RAM_ECCR_ECCCIE_Msk);
}

/**
  * @brief    Read ECC Error Address in RAM
  * @rmtoll   RAM_ECCR    ADDR_ECC    FL_FLASH_ReadECCErrorAddressInRAM
  * @param    FLASHx FLASH instance
  * @retval   
  */
__STATIC_INLINE uint32_t FL_FLASH_ReadECCErrorAddressInRAM(FLASH_Type* FLASHx)
{
    return (uint32_t)(READ_BIT(FLASHx->RAM_ECCR, (0x3fffU << 0U)) >> 0U);
}

/**
  * @brief    Set HSRAM1 Power Consumption Mode
  * @rmtoll   HSRAM1_CFGR    PDN_SLN    FL_FLASH_SetHSRAM1PowerMode
  * @param    FLASHx FLASH instance
  * @param    mode This parameter can be one of the following values:
  *           @arg @ref FL_FLASH_HSRAM_POWER_DOWN
  *           @arg @ref FL_FLASH_HSRAM_SLEEP
  *           @arg @ref FL_FLASH_HSRAM_NORAML
  * @retval   None
  */
__STATIC_INLINE void FL_FLASH_SetHSRAM1PowerMode(FLASH_Type* FLASHx, uint32_t mode)
{
    MODIFY_REG(FLASHx->HSRAM1_CFGR, FLASH_HSRAM1_CFGR_PDN_SLN_Msk, mode);
}

/**
  * @brief    Get HSRAM1 Power Consumption Mode
  * @rmtoll   HSRAM1_CFGR    PDN_SLN    FL_FLASH_GetHSRAM1PowerMode
  * @param    FLASHx FLASH instance
  * @retval   Returned value can be one of the following values:
  */
__STATIC_INLINE uint32_t FL_FLASH_GetHSRAM1PowerMode(FLASH_Type* FLASHx)
{
    return (uint32_t)(READ_BIT(FLASHx->HSRAM1_CFGR, FLASH_HSRAM1_CFGR_PDN_SLN_Msk));
}

/**
  * @brief    Set HSRAM2 Power Consumption Mode
  * @rmtoll   HSRAM2_CFGR    PDN_SLN    FL_FLASH_SetHSRAM2PowerMode
  * @param    FLASHx FLASH instance
  * @param    mode This parameter can be one of the following values:
  *           @arg @ref FL_FLASH_HSRAM_POWER_DOWN
  *           @arg @ref FL_FLASH_HSRAM_SLEEP
  *           @arg @ref FL_FLASH_HSRAM_NORAML
  * @retval   None
  */
__STATIC_INLINE void FL_FLASH_SetHSRAM2PowerMode(FLASH_Type* FLASHx, uint32_t mode)
{
    MODIFY_REG(FLASHx->HSRAM2_CFGR, FLASH_HSRAM2_CFGR_PDN_SLN_Msk, mode);
}

/**
  * @brief    Get HSRAM2 Power Consumption Mode
  * @rmtoll   HSRAM2_CFGR    PDN_SLN    FL_FLASH_GetHSRAM2PowerMode
  * @param    FLASHx FLASH instance
  * @retval   Returned value can be one of the following values:
  */
__STATIC_INLINE uint32_t FL_FLASH_GetHSRAM2PowerMode(FLASH_Type* FLASHx)
{
    return (uint32_t)(READ_BIT(FLASHx->HSRAM2_CFGR, FLASH_HSRAM2_CFGR_PDN_SLN_Msk));
}

/**
  * @brief    Enable Back Door Verify
  * @rmtoll   BDVR        FL_FLASH_WriteEnableBackDoorVerify
  * @param    FLASHx FLASH instance
  * @param    key 
  * @retval   None
  */
__STATIC_INLINE void FL_FLASH_WriteEnableBackDoorVerify(FLASH_Type* FLASHx, uint32_t key)
{
    MODIFY_REG(FLASHx->BDVR, (0xffffffffU << 0U), (key << 0U));
}

/**
  * @brief    Write Back Door Code Register0
  * @rmtoll   BDCR0        FL_FLASH_WriteBackDoorCodeRegister0
  * @param    FLASHx FLASH instance
  * @param    code 
  * @retval   None
  */
__STATIC_INLINE void FL_FLASH_WriteBackDoorCodeRegister0(FLASH_Type* FLASHx, uint32_t code)
{
    MODIFY_REG(FLASHx->BDCR0, (0xffffffffU << 0U), (code << 0U));
}

/**
  * @brief    Read Back Door Code Register0
  * @rmtoll   BDCR0        FL_FLASH_ReadBackDoorCodeRegister0
  * @param    FLASHx FLASH instance
  * @retval   
  */
__STATIC_INLINE uint32_t FL_FLASH_ReadBackDoorCodeRegister0(FLASH_Type* FLASHx)
{
    return (uint32_t)(READ_BIT(FLASHx->BDCR0, (0xffffffffU << 0U)) >> 0U);
}

/**
  * @brief    Write Back Door Code Register1
  * @rmtoll   BDCR1        FL_FLASH_WriteBackDoorCodeRegister1
  * @param    FLASHx FLASH instance
  * @param    code 
  * @retval   None
  */
__STATIC_INLINE void FL_FLASH_WriteBackDoorCodeRegister1(FLASH_Type* FLASHx, uint32_t code)
{
    MODIFY_REG(FLASHx->BDCR1, (0xffffffffU << 0U), (code << 0U));
}

/**
  * @brief    Read Back Door Code Register1
  * @rmtoll   BDCR1        FL_FLASH_ReadBackDoorCodeRegister1
  * @param    FLASHx FLASH instance
  * @retval   
  */
__STATIC_INLINE uint32_t FL_FLASH_ReadBackDoorCodeRegister1(FLASH_Type* FLASHx)
{
    return (uint32_t)(READ_BIT(FLASHx->BDCR1, (0xffffffffU << 0U)) >> 0U);
}

/**
  * @brief    Get Back Door Verify Fail Flag
  * @rmtoll   BDSR    FLAG    FL_FLASH_IsActiveFlag_BackDoorVerifyFail
  * @param    FLASHx FLASH instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_FLASH_IsActiveFlag_BackDoorVerifyFail(FLASH_Type* FLASHx)
{
    return (uint32_t)(READ_BIT(FLASHx->BDSR, FLASH_BDSR_FLAG_Msk) == (FLASH_BDSR_FLAG_Msk));
}

/**
  * @brief    Get Back Dooer Verify Done Flag
  * @rmtoll   BDSR    DONE    FL_FLASH_IsActiveFlag_BackDoorVerifyDone
  * @param    FLASHx FLASH instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_FLASH_IsActiveFlag_BackDoorVerifyDone(FLASH_Type* FLASHx)
{
    return (uint32_t)(READ_BIT(FLASHx->BDSR, FLASH_BDSR_DONE_Msk) == (FLASH_BDSR_DONE_Msk));
}

/**
  * @}
  */

/** @defgroup FLASH_FL_EF_Init Initialization and de-initialization functions
  * @{
  */
FL_ErrorStatus FL_FLASH_CodePageErase(FLASH_Type *FLASHx, uint32_t address);
FL_ErrorStatus FL_FLASH_CodeSectorErase(FLASH_Type *FLASHx, uint32_t address);
FL_ErrorStatus FL_FLASH_CodeProgram_Word(FLASH_Type *FLASHx, uint32_t address, uint32_t data);
FL_ErrorStatus FL_FLASH_CodeProgram_Page(FLASH_Type *FLASHx, uint32_t pageNum, uint32_t *data);
FL_ErrorStatus FL_FLASH_CodeProgram_Sector(FLASH_Type *FLASHx, uint32_t sectorNum, uint32_t *data);
FL_ErrorStatus FL_FLASH_CodeWrite_Dma(FLASH_Type *FLASHx, uint32_t address, uint32_t *data);
FL_ErrorStatus FL_FLASH_CodeRead_Dma(FLASH_Type *FLASHx, uint32_t address, uint32_t *data, uint32_t length);


FL_ErrorStatus FL_FLASH_DataPageErase(FLASH_Type *FLASHx, uint32_t address);
FL_ErrorStatus FL_FLASH_DataSectorErase(FLASH_Type *FLASHx, uint32_t address);
FL_ErrorStatus FL_FLASH_DataProgram_Word(FLASH_Type *FLASHx, uint32_t address, uint32_t data);
FL_ErrorStatus FL_FLASH_DataProgram_Page(FLASH_Type *FLASHx, uint32_t pageNum, uint32_t *data);
FL_ErrorStatus FL_FLASH_DataProgram_Sector(FLASH_Type *FLASHx, uint32_t sectorNum, uint32_t *data);


/**
  * @}
  */


/**
  * @}
  */

#ifdef __cplusplus
}
#endif

#endif /* __FM33FG0XXA_FL_FLASH_H*/

/*************************Py_Code_Generator Version: 0.1-0.14-0.1 @ 2023-03-30*************************/
/*************************(C) COPYRIGHT Fudan Microelectronics **** END OF FILE*************************/
