 /**    
  *******************************************************************************************************
  * @file    fm33fg0xxa_fl_pgl.h
  * @author  FMSH Application Team
  * @brief   Head file of PGL FL Module
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
#ifndef __FM33FG0XXA_FL_PGL_H
#define __FM33FG0XXA_FL_PGL_H

#ifdef __cplusplus
extern "C" {
#endif
/* Includes -------------------------------------------------------------------------------------------*/
#include "fm33fg0xxa_fl_def.h"
/** @addtogroup FM33FG0XX_FL_Driver
  * @{
  */

/** @defgroup PGL PGL
  * @brief PGL FL driver
  * @{
  */

/* Exported types -------------------------------------------------------------------------------------*/
/** @defgroup PGL_FL_ES_INIT PGL Exported Init structures
  * @{
  */

/**
  * @brief FL PGL Init Sturcture definition
  */

typedef struct
{
    /*! 有效边沿选择 */
    uint32_t edge;
    /*!输出模式选择*/
    uint32_t outMode;
    /*! 输入3选择*/
    uint32_t input3;
    /*! 输入2选择*/
    uint32_t input2;
    /*! 输入1选择*/
    uint32_t input1;
    /*! 输入0选择*/
    uint32_t input0;
} FL_PGL_LUT_InitTypeDef;

/**
  * @}
  */
/** PGL
  * LUT0~LUT3 LUTSEL_Group  映射表
  *
  * ===================== LUT0 ======================
  * ---------------------------------
  * Inputx | Group  | Function Name
  * ---------------------------------
  * Input3 | 0      | GPIO PA7
  *        | 1      | LPT16_CH1
  *        | 2      | GPTIM1.OCREF
  *        | 3      | ATIM.OC1REF
  * ---------------------------------
  * Input2 | 0      | GPIO PA6
  *        | 1      | GPIO PA5
  *        | 2      | GPIO PA4
  *        | 3      | RFU
  * ----------------------------------
  * Input1 | 0      | GPIO PA2
  *        | 1      | GPIO PA3
  *        | 2      | COMP2_OUT
  *        | 3      | GPTIM1.OC1REF
  * -----------------------------------
  * Input0 | 0      | GPIO PA0
  *        | 1      | GPIO PA1
  *        | 2      | COMP1_OUT
  *        | 3      | GPTIM0.OC1REF
  * ---------------------------------
  *
  * ===================== LUT1 =============
  * ----------------------------------------
  * Inputx | Group  | Function Name
  * ----------------------------------
  * Input3 | 0      | GPIO PB7
  *        | 1      | LPTIM16.OC1REF
  *        | 2      | COMP3_OUT
  *        | 3      | ATIM.OC1REF
  * -----------------------------------
  * Input2 | 0      | GPIO PB3
  *        | 1      | GPIO PB4
  *        | 2      | GPIO PB5
  *        | 3      | GPIO PB6
  * -----------------------------------
  * Input1 | 0      | GPIO PB1
  *        | 1      | GPIO PB2
  *        | 2      | COMP2_OUT
  *        | 3      | GPTIM1.OC1REF
  * -----------------------------------
  * Input0 | 0      | GPIO PB0
  *        | 1      | LUT0 output
  *        | 2      | COMP1_OUT
  *        | 3      | GPTIM0.OC1REF
  * -----------------------------------
  * ===================== LUT2 =============
  * --------------------------------------
  * Inputx | Group  | Function Name |
  * ----------------------------------
  * Input3 | 0      | GPIO PC6
  *        | 1      | LPTIM16.OC1REF
  *        | 2      | GPIO PC7
  *        | 3      | ATIM.OC1REF
  * ---------------------------------
  * Input2 | 0      | GPIO PC5
  *        | 1      | GPIO PC4
  *        | 2      | GPIO PC3
  *        | 3      | GPIO PC2
  * ----------------------------------
  * Input1 | 0      | GPIO PC1
  *        | 1      | LUT1 output
  *        | 2      | COMP2_OUT
  *        | 3      | TAU04_TRGO
  * ----------------------------------
  * Input0 | 0      | GPIO PC0
  *        | 1      | LUT0 output
  *        | 2      | COMP1_OUT
  *        | 3      | GPTIM0.OC1REF
  * ---------------------------------
  * * ===================== LUT3 =====
  * ---------------------------------
  * Inputx | Group  | Function Name
  * ----------------------------------
  * Input3 | 0      | GPIO PD7
  *        | 1      | GPIO PD6
  *        | 2      | LPT16_CH1
  *        | 3      | GPIO PD5
  * -----------------------------------
  * Input2 | 0      | GPIO PD2
  *        | 1      | LUT2 output
  *        | 2      | GPIO PD3
  *        | 3      | GPIO PD4
  * -----------------------------------
  * Input1 | 0      | GPIO PD1
  *        | 1      | LUT1 output
  *        | 2      | COMP2_OUT
  *        | 3      | GPTIM1.OC1REF
  * -----------------------------------
  * Input0 | 0      | GPIO PD0
  *        | 1      | LUT0 output
  *        | 2      | COMP1_OUT
  *        | 3      | GPTIM1.OC1REF
  * -----------------------------------
  */

/**
  * @}
  */
/* Exported constants ---------------------------------------------------------------------------------*/
/** @defgroup PGL_FL_Exported_Constants PGL Exported Constants
  * @{
  */

#define    PGL_CR_LUTEN_Pos                                       (0U)
#define    PGL_CR_LUTEN_Msk                                       (0xfU << PGL_CR_LUTEN_Pos)
#define    PGL_CR_LUTEN                                           PGL_CR_LUTEN_Msk

#define    PGL_CFGR_INSEL_Pos                                     (8U)
#define    PGL_CFGR_INSEL_Msk                                     (0x3U << PGL_CFGR_INSEL_Pos)
#define    PGL_CFGR_INSEL                                         PGL_CFGR_INSEL_Msk

#define    PGL_CFGR0_EDGESEL_Pos                                  (18U)
#define    PGL_CFGR0_EDGESEL_Msk                                  (0x3U << PGL_CFGR0_EDGESEL_Pos)
#define    PGL_CFGR0_EDGESEL                                      PGL_CFGR0_EDGESEL_Msk

#define    PGL_CFGR0_OUTSEL_Pos                                   (16U)
#define    PGL_CFGR0_OUTSEL_Msk                                   (0x3U << PGL_CFGR0_OUTSEL_Pos)
#define    PGL_CFGR0_OUTSEL                                       PGL_CFGR0_OUTSEL_Msk

#define    PGL_CFGR0_MASK_Pos                                     (0U)
#define    PGL_CFGR0_MASK_Msk                                     (0xfU << PGL_CFGR0_MASK_Pos)
#define    PGL_CFGR0_MASK                                         PGL_CFGR0_MASK_Msk

#define    PGL_IER_LUTIE_Pos                                      (0U)
#define    PGL_IER_LUTIE_Msk                                      (0xfU << PGL_IER_LUTIE_Pos)
#define    PGL_IER_LUTIE                                          PGL_IER_LUTIE_Msk

#define    PGL_ISR_LUTIF_Pos                                      (0U)
#define    PGL_ISR_LUTIF_Msk                                      (0xfU << PGL_ISR_LUTIF_Pos)
#define    PGL_ISR_LUTIF                                          PGL_ISR_LUTIF_Msk



#define    FL_PGL_LUT0                                            (0x1U << 0U)
#define    FL_PGL_LUT1                                            (0x1U << 1U)
#define    FL_PGL_LUT2                                            (0x1U << 2U)
#define    FL_PGL_LUT3                                            (0x1U << 3U)

#define    FL_PGL_INPUT0                                          (0x1U << 0U)
#define    FL_PGL_INPUT1                                          (0x1U << 1U)
#define    FL_PGL_INPUT2                                          (0x1U << 2U)
#define    FL_PGL_INPUT3                                          (0x1U << 3U)



#define    FL_PGL_LUT_INPUT_GROUP0                                (0x0U << PGL_CFGR_INSEL_Pos)
#define    FL_PGL_LUT_INPUT_GROUP1                                (0x1U << PGL_CFGR_INSEL_Pos)
#define    FL_PGL_LUT_INPUT_GROUP2                                (0x2U << PGL_CFGR_INSEL_Pos)
#define    FL_PGL_LUT_INPUT_GROUP3                                (0x3U << PGL_CFGR_INSEL_Pos)
#define    FL_PGL_LUT_INPUT_DISABLE                               (0x4U << PGL_CFGR_INSEL_Pos)

#define    FL_PGL_LUT_EDGE_RISING                                 (0x0U << PGL_CFGR0_EDGESEL_Pos)
#define    FL_PGL_LUT_EDGE_FALLING                                (0x1U << PGL_CFGR0_EDGESEL_Pos)
#define    FL_PGL_LUT_EDGE_BOTH                                   (0x2U << PGL_CFGR0_EDGESEL_Pos)
#define    FL_PGL_LUT_EDGE_NONE                                   (0x3U << PGL_CFGR0_EDGESEL_Pos)


#define    FL_PGL_LUT_OUTPUT_COMBINE_LOGIC                        (0x0U << PGL_CFGR0_OUTSEL_Pos)
#define    FL_PGL_LUT_OUTPUT_SYNC_SAMPLING                        (0x1U << PGL_CFGR0_OUTSEL_Pos)
#define    FL_PGL_LUT_OUTPUT_DIGITAL_FILTER                       (0x2U << PGL_CFGR0_OUTSEL_Pos)


/**
  * @}
  */
/* Exported functions ---------------------------------------------------------------------------------*/
/** @defgroup PGL_FL_Exported_Functions PGL Exported Functions
  * @{
  */

/**
  * @brief    LUTx enable
  * @rmtoll   CR        FL_PGL_EnableLUT
  * @param    PGLx PGL instance
  * @param    table This parameter can be one of the following values:
  *           @arg @ref FL_PGL_LUT0
  *           @arg @ref FL_PGL_LUT1
  *           @arg @ref FL_PGL_LUT2
  *           @arg @ref FL_PGL_LUT3
  * @retval   None
  */
__STATIC_INLINE void FL_PGL_EnableLUT(PGL_Type *PGLx, uint32_t table)
{
    SET_BIT(PGLx->CR, ((table & 0xf) << 0x0U));
}

/**
  * @brief    Get LUTx enable status
  * @rmtoll   CR        FL_PGL_IsEnabledLUT
  * @param    PGLx PGL instance
  * @param    table This parameter can be one of the following values:
  *           @arg @ref FL_PGL_LUT0
  *           @arg @ref FL_PGL_LUT1
  *           @arg @ref FL_PGL_LUT2
  *           @arg @ref FL_PGL_LUT3
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_PGL_IsEnabledLUT(PGL_Type *PGLx, uint32_t table)
{
    return (uint32_t)(READ_BIT(PGLx->CR, ((table & 0xf) << 0x0U)) == ((table & 0xf) << 0x0U));
}

/**
  * @brief    LUTx disable
  * @rmtoll   CR        FL_PGL_DisableLUT
  * @param    PGLx PGL instance
  * @param    table This parameter can be one of the following values:
  *           @arg @ref FL_PGL_LUT0
  *           @arg @ref FL_PGL_LUT1
  *           @arg @ref FL_PGL_LUT2
  *           @arg @ref FL_PGL_LUT3
  * @retval   None
  */
__STATIC_INLINE void FL_PGL_DisableLUT(PGL_Type *PGLx, uint32_t table)
{
    CLEAR_BIT(PGLx->CR, ((table & 0xf) << 0x0U));
}

/**
  * @brief     LUT input select
  * @rmtoll   CFGR    INSEL    FL_PGL_SetLUTInputSource
  * @param    PGLx PGL instance
  * @param    LUTx This parameter can be one of the following values:
  *           @arg @ref FL_PGL_LUT0
  *           @arg @ref FL_PGL_LUT1
  *           @arg @ref FL_PGL_LUT2
  *           @arg @ref FL_PGL_LUT3
  * @param    inputX This parameter can be one of the following values:
  *           @arg @ref FL_PGL_INPUT0
  *           @arg @ref FL_PGL_INPUT1
  *           @arg @ref FL_PGL_INPUT2
  *           @arg @ref FL_PGL_INPUT3
  * @param    source This parameter can be one of the following values:
  *           @arg @ref FL_PGL_LUT_INPUT_GROUP0
  *           @arg @ref FL_PGL_LUT_INPUT_GROUP1
  *           @arg @ref FL_PGL_LUT_INPUT_GROUP2
  *           @arg @ref FL_PGL_LUT_INPUT_GROUP3
  * @retval   None
  */
__STATIC_INLINE void FL_PGL_SetLUTInputSource(PGL_Type *PGLx, uint32_t LUTx, uint32_t inputX, uint32_t source)
{
    switch(LUTx)
    {
        case FL_PGL_LUT0:
            MODIFY_REG(PGLx->CFGR0, (inputX * inputX * (0x3U)) << 8U, (inputX * inputX * (source)));
            break;
        case FL_PGL_LUT1:
            MODIFY_REG(PGLx->CFGR1, (inputX * inputX * (0x3U)) << 8U, (inputX * inputX * (source)));
            break;
        case FL_PGL_LUT2:
            MODIFY_REG(PGLx->CFGR2, (inputX * inputX * (0x3U)) << 8U, (inputX * inputX * (source)));
            break;
        case FL_PGL_LUT3:
            MODIFY_REG(PGLx->CFGR3, (inputX * inputX * (0x3U)) << 8U, (inputX * inputX * (source)));
            break;
        default:
            MODIFY_REG(PGLx->CFGR0, (FL_PGL_INPUT0 * FL_PGL_INPUT0 * (0x3U)) << 8U, (FL_PGL_INPUT0 * FL_PGL_INPUT0 * (FL_PGL_LUT_INPUT_GROUP0)));
            break;
    }
}

/**
  * @brief    Get LUT input mode
  * @rmtoll   CFGR    INSEL    FL_PGL_GetLUTInputSource
  * @param    PGLx PGL instance
  * @param    LUTx This parameter can be one of the following values:
  *           @arg @ref FL_PGL_LUT0
  *           @arg @ref FL_PGL_LUT1
  *           @arg @ref FL_PGL_LUT2
  *           @arg @ref FL_PGL_LUT3
  * @param    inputX This parameter can be one of the following values:
  *           @arg @ref FL_PGL_INPUT0
  *           @arg @ref FL_PGL_INPUT1
  *           @arg @ref FL_PGL_INPUT2
  *           @arg @ref FL_PGL_INPUT3
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_PGL_LUT_INPUT_GROUP0
  *           @arg @ref FL_PGL_LUT_INPUT_GROUP1
  *           @arg @ref FL_PGL_LUT_INPUT_GROUP2
  *           @arg @ref FL_PGL_LUT_INPUT_GROUP3
  */
__STATIC_INLINE uint32_t FL_PGL_GetLUTInputSource(PGL_Type *PGLx, uint32_t LUTx, uint32_t inputX)
{
    uint32_t source = 0;
    switch(LUTx)
    {
        case FL_PGL_LUT0:
            source = (uint32_t)(READ_BIT(PGLx->CFGR0, (inputX * inputX * (0x3U)) << 8U) / (inputX * inputX));
            break;
        case FL_PGL_LUT1:
            source = (uint32_t)(READ_BIT(PGLx->CFGR1, (inputX * inputX * (0x3U)) << 8U) / (inputX * inputX));
            break;
        case FL_PGL_LUT2:
            source = (uint32_t)(READ_BIT(PGLx->CFGR2, (inputX * inputX * (0x3U)) << 8U) / (inputX * inputX));
            break;
        case FL_PGL_LUT3:
            source = (uint32_t)(READ_BIT(PGLx->CFGR3, (inputX * inputX * (0x3U)) << 8U) / (inputX * inputX));
            break;
        default:
            source = (uint32_t)FL_PGL_LUT_INPUT_GROUP0;
            break;
    }
    return source;
}

/**
  * @brief    Set LUTx effective edge
  * @rmtoll   CFGR0    EDGESEL    FL_PGL_SetLUTEffectiveEdge
  * @param    PGLx PGL instance
  * @param    LUTx This parameter can be one of the following values:
  *           @arg @ref FL_PGL_LUT0
  *           @arg @ref FL_PGL_LUT1
  *           @arg @ref FL_PGL_LUT2
  *           @arg @ref FL_PGL_LUT3
  * @param    edge This parameter can be one of the following values:
  *           @arg @ref FL_PGL_LUT_EDGE_RISING
  *           @arg @ref FL_PGL_LUT_EDGE_FALLING
  *           @arg @ref FL_PGL_LUT_EDGE_BOTH
  *           @arg @ref FL_PGL_LUT_EDGE_NONE
  * @retval   None
  */
__STATIC_INLINE void FL_PGL_SetLUTEffectiveEdge(PGL_Type *PGLx, uint32_t LUTx, uint32_t edge)
{
    switch(LUTx)
    {
        case FL_PGL_LUT0:
            MODIFY_REG(PGLx->CFGR0, ((0x3U)) << 18U, edge);
            break;
        case FL_PGL_LUT1:
            MODIFY_REG(PGLx->CFGR1, ((0x3U)) << 18U, edge);
            break;
        case FL_PGL_LUT2:
            MODIFY_REG(PGLx->CFGR2, ((0x3U)) << 18U, edge);
            break;
        case FL_PGL_LUT3:
            MODIFY_REG(PGLx->CFGR3, ((0x3U)) << 18U, edge);
            break;
        default:
            MODIFY_REG(PGLx->CFGR0, ((0x3U)) << 18U, FL_PGL_LUT_EDGE_NONE);
            break;
    }
}

/**
  * @brief    Get LUT0 effective edge
  * @rmtoll   CFGR0    EDGESEL    FL_PGL_GetLUTEffectiveEdge
  * @param    PGLx PGL instance
  * @param    LUTx This parameter can be one of the following values:
  *           @arg @ref FL_PGL_LUT0
  *           @arg @ref FL_PGL_LUT1
  *           @arg @ref FL_PGL_LUT2
  *           @arg @ref FL_PGL_LUT3
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_PGL_LUT_EDGE_RISING
  *           @arg @ref FL_PGL_LUT_EDGE_FALLING
  *           @arg @ref FL_PGL_LUT_EDGE_BOTH
  *           @arg @ref FL_PGL_LUT_EDGE_NONE
  */
__STATIC_INLINE uint32_t FL_PGL_GetLUTEffectiveEdge(PGL_Type *PGLx, uint32_t LUTx)
{
    uint32_t edge = 0;
    switch(LUTx)
    {
        case FL_PGL_LUT0:
            edge = (uint32_t)(READ_BIT(PGLx->CFGR0, (0x3U) << 18U));
            break;
        case FL_PGL_LUT1:
            edge = (uint32_t)(READ_BIT(PGLx->CFGR1, (0x3U) << 18U));
            break;
        case FL_PGL_LUT2:
            edge = (uint32_t)(READ_BIT(PGLx->CFGR2, (0x3U) << 18U));
            break;
        case FL_PGL_LUT3:
            edge = (uint32_t)(READ_BIT(PGLx->CFGR3, (0x3U) << 18U));
            break;
        default:
            edge = (uint32_t)FL_PGL_LUT_EDGE_RISING;
            break;
    }
    return edge;
}

/**
  * @brief    Set LUT0 output mode
  * @rmtoll   CFGR0    OUTSEL    FL_PGL_SetLUTOutputMode
  * @param    PGLx PGL instance
  * @param    LUTx This parameter can be one of the following values:
  *           @arg @ref FL_PGL_LUT0
  *           @arg @ref FL_PGL_LUT1
  *           @arg @ref FL_PGL_LUT2
  *           @arg @ref FL_PGL_LUT3
  * @param    mode This parameter can be one of the following values:
  *           @arg @ref FL_PGL_LUT_OUTPUT_COMBINE_LOGIC
  *           @arg @ref FL_PGL_LUT_OUTPUT_SYNC_SAMPLING
  *           @arg @ref FL_PGL_LUT_OUTPUT_DIGITAL_FILTER
  * @retval   None
  */
__STATIC_INLINE void FL_PGL_SetLUTOutputMode(PGL_Type *PGLx, uint32_t LUTx, uint32_t mode)
{
    switch(LUTx)
    {
        case FL_PGL_LUT0:
            MODIFY_REG(PGLx->CFGR0, ((0x3U)) << 16U, mode);
            break;
        case FL_PGL_LUT1:
            MODIFY_REG(PGLx->CFGR1, ((0x3U)) << 16U, mode);
            break;
        case FL_PGL_LUT2:
            MODIFY_REG(PGLx->CFGR2, ((0x3U)) << 16U, mode);
            break;
        case FL_PGL_LUT3:
            MODIFY_REG(PGLx->CFGR3, ((0x3U)) << 16U, mode);
            break;
        default:
            MODIFY_REG(PGLx->CFGR0, ((0x3U)) << 16U, FL_PGL_LUT_OUTPUT_COMBINE_LOGIC);
            break;
    }
}

/**
  * @brief    Get LUT0 output mode
  * @rmtoll   CFGR0    OUTSEL    FL_PGL_GetLUTOutputMode
  * @param    PGLx PGL instance
  * @param    LUTx This parameter can be one of the following values:
  *           @arg @ref FL_PGL_LUT0
  *           @arg @ref FL_PGL_LUT1
  *           @arg @ref FL_PGL_LUT2
  *           @arg @ref FL_PGL_LUT3
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_PGL_LUT_OUTPUT_COMBINE_LOGIC
  *           @arg @ref FL_PGL_LUT_OUTPUT_SYNC_SAMPLING
  *           @arg @ref FL_PGL_LUT_OUTPUT_DIGITAL_FILTER
  */
__STATIC_INLINE uint32_t FL_PGL_GetLUTOutputMode(PGL_Type *PGLx, uint32_t LUTx)
{
    uint32_t mode = 0;
    switch(LUTx)
    {
        case FL_PGL_LUT0:
            mode = (uint32_t)(READ_BIT(PGLx->CFGR0, (0x3U) << 16U));
            break;
        case FL_PGL_LUT1:
            mode = (uint32_t)(READ_BIT(PGLx->CFGR1, (0x3U) << 16U));
            break;
        case FL_PGL_LUT2:
            mode = (uint32_t)(READ_BIT(PGLx->CFGR2, (0x3U) << 16U));
            break;
        case FL_PGL_LUT3:
            mode = (uint32_t)(READ_BIT(PGLx->CFGR3, (0x3U) << 16U));
            break;
        default:
            mode = (uint32_t)FL_PGL_LUT_OUTPUT_COMBINE_LOGIC;
            break;
    }
    return mode;
}

/**
  * @brief    LUT0 input mask enable
  * @rmtoll   CFGR0    MASK    FL_PGL_EnableLUTInputMask
  * @param    PGLx PGL instance
  * @param    LUTx This parameter can be one of the following values:
  *           @arg @ref FL_PGL_LUT0
  *           @arg @ref FL_PGL_LUT1
  *           @arg @ref FL_PGL_LUT2
  *           @arg @ref FL_PGL_LUT3
  * @param    channel This parameter can be one of the following values:
  *           @arg @ref FL_PGL_INPUT0
  *           @arg @ref FL_PGL_INPUT1
  *           @arg @ref FL_PGL_INPUT2
  *           @arg @ref FL_PGL_INPUT3
  * @retval   None
  */
__STATIC_INLINE void FL_PGL_EnableLUTInputMask(PGL_Type *PGLx, uint32_t LUTx, uint32_t channel)
{
    switch(LUTx)
    {
        case FL_PGL_LUT0:
            SET_BIT(PGLx->CFGR0, ((channel & 0xf) << 0x0U));
            break;
        case FL_PGL_LUT1:
            SET_BIT(PGLx->CFGR1, ((channel & 0xf) << 0x0U));
            break;
        case FL_PGL_LUT2:
            SET_BIT(PGLx->CFGR2, ((channel & 0xf) << 0x0U));
            break;
        case FL_PGL_LUT3:
            SET_BIT(PGLx->CFGR3, ((channel & 0xf) << 0x0U));
            break;
        default:
            SET_BIT(PGLx->CFGR0, ((0x0U & 0xf) << 0x0U));
            break;
    }
}

/**
  * @brief    Get LUT0input mask status
  * @rmtoll   CFGR0    MASK    FL_PGL_IsEnabledLUTInputMask
  * @param    PGLx PGL instance
  * @param    LUTx This parameter can be one of the following values:
  *           @arg @ref FL_PGL_LUT0
  *           @arg @ref FL_PGL_LUT1
  *           @arg @ref FL_PGL_LUT2
  *           @arg @ref FL_PGL_LUT3
  * @param    channel This parameter can be one of the following values:
  *           @arg @ref FL_PGL_INPUT0
  *           @arg @ref FL_PGL_INPUT1
  *           @arg @ref FL_PGL_INPUT2
  *           @arg @ref FL_PGL_INPUT3
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_PGL_IsEnabledLUTInputMask(PGL_Type *PGLx, uint32_t LUTx, uint32_t channel)
{
    uint32_t state = 0;
    switch(LUTx)
    {
        case FL_PGL_LUT0:
            state = (uint32_t)(READ_BIT(PGLx->CFGR0, ((channel & 0xf) << 0x0U)) == ((channel & 0xf) << 0x0U));
            break;
        case FL_PGL_LUT1:
            state = (uint32_t)(READ_BIT(PGLx->CFGR1, ((channel & 0xf) << 0x0U)) == ((channel & 0xf) << 0x0U));
            break;
        case FL_PGL_LUT2:
            state = (uint32_t)(READ_BIT(PGLx->CFGR2, ((channel & 0xf) << 0x0U)) == ((channel & 0xf) << 0x0U));
            break;
        case FL_PGL_LUT3:
            state = (uint32_t)(READ_BIT(PGLx->CFGR3, ((channel & 0xf) << 0x0U)) == ((channel & 0xf) << 0x0U));
            break;
        default:
            state = 0;
            break;
    }
    return state;
}


/**
  * @brief    LUT0 input mask disable
  * @rmtoll   CFGR0    MASK    FL_PGL_DisableLUTInputMask
  * @param    PGLx PGL instance
  * @param    LUTx This parameter can be one of the following values:
  *           @arg @ref FL_PGL_LUT0
  *           @arg @ref FL_PGL_LUT1
  *           @arg @ref FL_PGL_LUT2
  *           @arg @ref FL_PGL_LUT3
  * @param    channel This parameter can be one of the following values:
  *           @arg @ref FL_PGL_INPUT0
  *           @arg @ref FL_PGL_INPUT1
  *           @arg @ref FL_PGL_INPUT2
  *           @arg @ref FL_PGL_INPUT3
  * @retval   None
  */
__STATIC_INLINE void FL_PGL_DisableLUTInputMask(PGL_Type *PGLx, uint32_t LUTx, uint32_t channel)
{
    switch(LUTx)
    {
        case FL_PGL_LUT0:
            CLEAR_BIT(PGLx->CFGR0, ((channel & 0xf) << 0x0U));
            break;
        case FL_PGL_LUT1:
            CLEAR_BIT(PGLx->CFGR1, ((channel & 0xf) << 0x0U));
            break;
        case FL_PGL_LUT2:
            CLEAR_BIT(PGLx->CFGR2, ((channel & 0xf) << 0x0U));
            break;
        case FL_PGL_LUT3:
            CLEAR_BIT(PGLx->CFGR3, ((channel & 0xf) << 0x0U));
            break;
        default:
            CLEAR_BIT(PGLx->CFGR0, ((0x0U & 0xf) << 0x0U));
            break;
    }
}


/**
  * @brief    LUT interrupt enable
  * @rmtoll   IER    LUTIE    FL_PGL_EnableIT_LUT
  * @param    PGLx PGL instance
  * @param    table This parameter can be one of the following values:
  *           @arg @ref FL_PGL_LUT0
  *           @arg @ref FL_PGL_LUT1
  *           @arg @ref FL_PGL_LUT2
  *           @arg @ref FL_PGL_LUT3
  * @retval   None
  */
__STATIC_INLINE void FL_PGL_EnableIT_LUT(PGL_Type *PGLx, uint32_t table)
{
    SET_BIT(PGLx->IER, ((table & 0xf) << 0x0U));
}

/**
  * @brief    Get LUT interrupt enable status
  * @rmtoll   IER    LUTIE    FL_PGL_IsEnabledIT_LUT
  * @param    PGLx PGL instance
  * @param    table This parameter can be one of the following values:
  *           @arg @ref FL_PGL_LUT0
  *           @arg @ref FL_PGL_LUT1
  *           @arg @ref FL_PGL_LUT2
  *           @arg @ref FL_PGL_LUT3
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_PGL_IsEnabledIT_LUT(PGL_Type *PGLx, uint32_t table)
{
    return (uint32_t)(READ_BIT(PGLx->IER, ((table & 0xf) << 0x0U)) == ((table & 0xf) << 0x0U));
}

/**
  * @brief    LUT interrupt disable
  * @rmtoll   IER    LUTIE    FL_PGL_DisableIT_LUT
  * @param    PGLx PGL instance
  * @param    table This parameter can be one of the following values:
  *           @arg @ref FL_PGL_LUT0
  *           @arg @ref FL_PGL_LUT1
  *           @arg @ref FL_PGL_LUT2
  *           @arg @ref FL_PGL_LUT3
  * @retval   None
  */
__STATIC_INLINE void FL_PGL_DisableIT_LUT(PGL_Type *PGLx, uint32_t table)
{
    CLEAR_BIT(PGLx->IER, ((table & 0xf) << 0x0U));
}

/**
  * @brief    Get LUT interrupt flag
  * @rmtoll   ISR    LUTIF    FL_PGL_IsActiveFlag_LUT
  * @param    PGLx PGL instance
  * @param    table This parameter can be one of the following values:
  *           @arg @ref FL_PGL_LUT0
  *           @arg @ref FL_PGL_LUT1
  *           @arg @ref FL_PGL_LUT2
  *           @arg @ref FL_PGL_LUT3
  * @retval   Returned value can be one of the following values:
  */
__STATIC_INLINE uint32_t FL_PGL_IsActiveFlag_LUT(PGL_Type *PGLx, uint32_t table)
{
    return (uint32_t)(READ_BIT(PGLx->ISR, ((table & 0xf) << 0x0U)) == ((table & 0xf) << 0x0U));
}

/**
  * @brief    Clear LUT interrupt flag
  * @rmtoll   ISR    LUTIF    FL_PGL_ClearFlag_LUT
  * @param    PGLx PGL instance
  * @param    table This parameter can be one of the following values:
  *           @arg @ref FL_PGL_LUT0
  *           @arg @ref FL_PGL_LUT1
  *           @arg @ref FL_PGL_LUT2
  *           @arg @ref FL_PGL_LUT3
  * @retval   None
  */
__STATIC_INLINE void FL_PGL_ClearFlag_LUT(PGL_Type *PGLx, uint32_t table)
{
    WRITE_REG(PGLx->ISR, ((table & 0xf) << 0x0U));
}

/**
  * @brief    Set LUT0 truth table
  * @rmtoll   LUT        FL_PGL_WriteLUTTruthTable
  * @param    PGLx PGL instance
  * @param    table
  * @param    truth
  * @retval   None
  */
__STATIC_INLINE void FL_PGL_WriteLUTTruthTable(PGL_Type *PGLx, uint32_t table, uint32_t truth)
{
    switch(table)
    {
        case FL_PGL_LUT0:
            MODIFY_REG(PGLx->LUT0, (0xffffU << 0U), (truth << 0U));
            break;
        case FL_PGL_LUT1:
            MODIFY_REG(PGLx->LUT1, (0xffffU << 0U), (truth << 0U));
            break;
        case FL_PGL_LUT2:
            MODIFY_REG(PGLx->LUT2, (0xffffU << 0U), (truth << 0U));
            break;
        case FL_PGL_LUT3:
            MODIFY_REG(PGLx->LUT3, (0xffffU << 0U), (truth << 0U));
            break;
        default:
            MODIFY_REG(PGLx->LUT0, (0xffffU << 0U), (0x0U << 0U));
            break;
    }
}

/**
  * @brief    Get LUT0 truth table
  * @rmtoll   LUT        FL_PGL_ReadLUTTruthTable
  * @param    PGLx PGL instance
  * @param    table This parameter can be one of the following values:
  *           @arg @ref FL_PGL_LUT0
  *           @arg @ref FL_PGL_LUT1
  *           @arg @ref FL_PGL_LUT2
  *           @arg @ref FL_PGL_LUT3
  * @retval
  */
__STATIC_INLINE uint32_t FL_PGL_ReadLUTTruthTable(PGL_Type *PGLx, uint32_t table)
{
    uint32_t truth = 0;
    switch(table)
    {
        case FL_PGL_LUT0:
            truth = (uint32_t)(READ_BIT((PGLx->LUT0), 0xffffU) >> 0U);
            break;
        case FL_PGL_LUT1:
            truth = (uint32_t)(READ_BIT((PGLx->LUT1), 0xffffU) >> 0U);
            break;
        case FL_PGL_LUT2:
            truth = (uint32_t)(READ_BIT((PGLx->LUT2), 0xffffU) >> 0U);
            break;
        case FL_PGL_LUT3:
            truth = (uint32_t)(READ_BIT((PGLx->LUT3), 0xffffU) >> 0U);
            break;
        default:
            truth = 0;
            break;
    }
    return truth;
}

/**
  * @}
  */

/** @defgroup PGL_FL_EF_Init Initialization and de-initialization functions
  * @{
  */
FL_ErrorStatus FL_PGL_DeInit(PGL_Type *PGLx);
FL_ErrorStatus FL_PGL_LUT_Init(PGL_Type *PGLx, uint32_t LUTx, FL_PGL_LUT_InitTypeDef *lutInit);
void FL_PGL_StructInit(FL_PGL_LUT_InitTypeDef *PGL_InitStruct);
/**
  * @}
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

#endif /* __FM33FG0XXA_FL_PGL_H */

/*************************Py_Code_Generator Version: 0.1-0.11-0.1 @ 2020-09-16*************************/
/*************************(C) COPYRIGHT Fudan Microelectronics **** END OF FILE*************************/
