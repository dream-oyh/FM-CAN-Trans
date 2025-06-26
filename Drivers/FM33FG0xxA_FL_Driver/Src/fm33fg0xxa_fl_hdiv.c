/**
  *******************************************************************************************************
  * @file    fm33fg0xxa_fl_hdiv.c
  * @author  FMSH Application Team
  * @brief   Source file of HDIV FL Module
  *******************************************************************************************************
  * @attention
  * Copyright (c) 2022, SHANGHAI FUDAN MICROELECTRONICS GROUP CO., LTD.(FUDAN MICROELECTRONICS./ FUDAN MICRO.)
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
  * THIS SOFTWARE IS PROVIDED BY FUDAN MICRO "AS IS" AND ANY EXPRESSED
    ORIMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
    OF MERCHANTABILITY NON-INFRINGEMENT AND FITNESS FOR A PARTICULAR PURPOSE
    ARE DISCLAIMED.IN NO EVENT SHALL FUDAN MICRO OR ITS CONTRIBUTORS BE LIABLE
    FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
    DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
    OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
    CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
    OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISINGIN ANY WAY OUT OF THE
    USE OF THIS SOFTWARE, EVEN IF ADVISED OFTHE POSSIBILITY OF SUCH DAMAGE.
  *
  *******************************************************************************************************
  */
/* Includes ------------------------------------------------------------------*/
#include "fm33fg0xxa_fl.h"

/** @addtogroup FM33FG0XXA_FL_Driver
  * @{
  */

/** @addtogroup HDIV
  * @{
  */

#ifdef FL_HDIV_DRIVER_ENABLED

/* Private macros ------------------------------------------------------------*/
/** @addtogroup HDIV_FL_Private_Macros
  * @{
  */

#define         IS_HDIV_ALL_INSTANCE(INTENCE)               ((INTENCE) == HDIV)

#define         IS_FL_HDIV_DIVISOR(__VALUE__)               (((__VALUE__) != 0))

/**
  * @}
  */

/* Private consts ------------------------------------------------------------*/
/** @addtogroup HDIV_FL_Private_Consts
  * @{
  */



/**
  * @}
  */

/* Private function prototypes -----------------------------------------------*/



/* Exported functions --------------------------------------------------------*/
/** @addtogroup HDIV_FL_EF_Init
  * @{
  */
/**
  * @brief  复位对应HDIV控制寄存器.
  *
  * @param  HDIVx 外设入口地址
  *
  * @retval ErrorStatus枚举值
  *         -FL_PASS 配置成功
  *         -FL_FAIL 配置过程发生错误
  */
FL_ErrorStatus FL_HDIV_DeInit(HDIV_Type* HDIVx)
{
    /* 入口参数检查 */
    assert_param(IS_HDIV_ALL_INSTANCE(HDIVx));
    /* 外设复位使能 */
    FL_RMU_EnablePeripheralReset(RMU);
    /* 恢复寄存器值为默认值 */
    FL_RMU_EnableResetAPBPeripheral(RMU, FL_RMU_RSTAPB_HDIV);
    FL_RMU_DisableResetAPBPeripheral(RMU, FL_RMU_RSTAPB_HDIV);
    /* 关闭总线时钟 */
    FL_CMU_DisableGroup2BusClock(FL_CMU_GROUP2_BUSCLK_HDIV);
    /* 锁定外设复位功能 */
    FL_RMU_DisablePeripheralReset(RMU);
    return FL_PASS;
}

/**
  * @brief  根据 初始化对应外设HDIV.
  *
  * @param  HDIVx 外设入口地址
  *
  * @retval ErrorStatus枚举值
  *         -FL_PASS 配置成功
  *         -FL_FAIL 配置过程发生错误
  */
FL_ErrorStatus FL_HDIV_Init(HDIV_Type* HDIVx)
{
    /* 入口参数检查 */
    assert_param(IS_HDIV_ALL_INSTANCE(HDIVx));
    /* 使能时钟总线 */
    FL_CMU_EnableGroup2BusClock(FL_CMU_GROUP2_BUSCLK_HDIV);
    return FL_PASS;
}

/**
  * @brief 硬件除法器计算函数
  *
  * @param  HDIVx 外设入口地址
  * @param  DivisorEnd 32位有符号被除数
  * @param  Divisor 16位有符号除数，注意不能为0
  * @param  Quotient 指向 @ref int32_t 指针 保存商的地址
  * @param  Residue 指向 @ref int16_t 指针 保存余数的地址
  *
  * @retval 计算正确性与否
  *         -FL_PASS 计算结果正确
  *         -FL_FAIL 计算过程发生错误
  */
FL_ErrorStatus FL_HDIV_Calculation(HDIV_Type* HDIVx, int32_t DivisorEnd, int16_t Divisor, int32_t *Quotient, int16_t *Residue)
{
    uint32_t TimeOut ;
    FL_ErrorStatus status = FL_FAIL;
    
    /* 入口参数检查 */
    assert_param(IS_HDIV_ALL_INSTANCE(HDIVx));
    assert_param(IS_FL_HDIV_DIVISOR(Divisor));
    
    if((Quotient != NULL) && (Residue != NULL))
    {
        FL_HDIV_WriteOperand(HDIVx, (uint32_t)DivisorEnd);
        FL_HDIV_WriteDivisor(HDIVx, (uint32_t)Divisor);
        if(FL_HDIV_IsActiveFlag_DividedZero(HDIVx) == 0X1)
        {
            /* 除数为0 */
            *Quotient = 0;
            *Residue  = 0;
            return FL_FAIL;
        }
        TimeOut = FL_HDIV_SR_BUSY_TIMEOUT;
        while(FL_HDIV_IsActiveFlag_Busy(HDIVx) == 0X1)
        {
            TimeOut--;
            if(TimeOut == 0)
            {
                /* 计算超时 */
                *Quotient = 0;
                *Residue  = 0;
                return FL_FAIL;
            }
        }
        *Quotient = FL_HDIV_ReadQuotient(HDIVx);
        *Residue  = (int16_t)FL_HDIV_ReadResidue(HDIVx);
        status = FL_PASS;
    }
    return status;
}



/**
  * @}
  */

/* Private functions ---------------------------------------------------------*/
/** @defgroup HDIV Private Functions
  * @{
  */



/**
  * @}
  */

#endif /* FL_HDIV_DRIVER_ENABLED */

/**
  * @}
  */

/**
  * @}
  */

/*************************(C) COPYRIGHT Fudan Microelectronics **** END OF FILE*************************/
