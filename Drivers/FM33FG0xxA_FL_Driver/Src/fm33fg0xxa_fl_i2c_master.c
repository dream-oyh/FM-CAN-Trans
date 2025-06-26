/**
  *******************************************************************************************************
  * @file    fm33fg0xxa_fl_i2c_master.c
  * @author  FMSH Application Team
  * @brief   Source file of I2C MASTER FL Module
  *******************************************************************************************************
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

/** @addtogroup I2C
  * @{
  */

#ifdef FL_I2C_MASTER_DRIVER_ENABLED

/* Private macros ------------------------------------------------------------*/
/** @addtogroup I2C_FL_Private_Macros
  * @{
  */

#define         IS_FL_I2C_INSTANCE(INSTANCE)                    (((INSTANCE) == I2C0)||\
                                                                 ((INSTANCE) == I2C1))

#define         IS_FL_I2C_BAUDRATE(__VALUE__)                   (((__VALUE__) > 0 )&&((__VALUE__) <= 1000000))


#define         IS_FL_I2C_MSATER_TIMEOUT(__VALUE__)             (((__VALUE__) == FL_IWDT_PERIOD_125MS)||\
                                                                 ((__VALUE__) == FL_IWDT_PERIOD_16000MS))




#define         IS_FL_I2C_ADDRSIZE10BIT(__VALUE__)              (((__VALUE__) == FL_ENABLE)||\
                                                                 ((__VALUE__) == FL_DISABLE))



/**
  * @}
  */

/** @addtogroup I2C_FL_EF_Init
  * @{
  */

/**
  * @brief  复位I2C外设.
  * @param  I2Cx 外设入口地址
  * @retval 错误状态，可能值：
  *         -FL_PASS 外设寄存器值恢复复位值
  *         -FL_FAIL 未成功执行
  */
FL_ErrorStatus FL_I2C_DeInit(I2C_Type *I2Cx)
{
    assert_param(IS_FL_I2C_INSTANCE(I2Cx));
    /* 使能外设复位 */
    FL_RMU_EnablePeripheralReset(RMU);
    if(I2Cx == I2C0)
    {
        /* 复位I2C0外设寄存器 */
        FL_RMU_EnableResetAPBPeripheral(RMU, FL_RMU_RSTAPB_I2C0);
        FL_RMU_DisableResetAPBPeripheral(RMU, FL_RMU_RSTAPB_I2C0);
    }
    else if(I2Cx == I2C1)
    {
        /* 复位I2C1外设寄存器 */
        FL_RMU_EnableResetAPBPeripheral(RMU, FL_RMU_RSTAPB_I2C1);
        FL_RMU_DisableResetAPBPeripheral(RMU, FL_RMU_RSTAPB_I2C1);
    }
    else
    {
        FL_RMU_DisablePeripheralReset(RMU);
        return FL_FAIL;
    }
    return FL_PASS;
}

/**
  * @brief  配置I2C主机模式.
  * @param  I2Cx 外设入口地址
  * @param  I2C_InitStruct 指向 @ref FL_I2C_MasterMode_InitTypeDef 结构体的指针
  * @retval 错误状态，可能值：
  *         -FL_PASS 配置成功
  *         -FL_FAIL 配置过程发生错误
  */
FL_ErrorStatus FL_I2C_MasterMode_Init(I2C_Type *I2Cx, FL_I2C_MasterMode_InitTypeDef *I2C_InitStruct)
{
    uint32_t I2C_Clk_Freq = 0, BRG = 0;
    FL_ErrorStatus status = FL_FAIL;
    if(I2C_InitStruct != NULL)
    {
        assert_param(IS_FL_I2C_INSTANCE(I2Cx));
        assert_param(IS_FL_I2C_BAUDRATE(I2C_InitStruct->baudRate));
        /* 外设总线时钟开启 */
        if(I2Cx == I2C0)
        {
            /* 外设总线始时钟 */
            FL_CMU_EnableGroup3BusClock(FL_CMU_GROUP3_BUSCLK_I2C0);
        }
        else
        {
            if(I2Cx == I2C1)
            {
                /* 外设总线始时钟 */
                FL_CMU_EnableGroup3BusClock(FL_CMU_GROUP3_BUSCLK_I2C1);
            }
            else
            {
                return FL_FAIL;
            }
        }
        /* 获取时钟源速度 */
        I2C_Clk_Freq = FL_CMU_GetAPB1ClockFreq();
        /* 根据不同的时钟源速度计算出配置速率需要的寄存器值并配置相关寄存器 */
        BRG = (uint32_t)(I2C_Clk_Freq / (2 * I2C_InitStruct->baudRate)) - 1;
        FL_I2C_Master_WriteSCLHighWidth(I2Cx, BRG);
        FL_I2C_Master_WriteSCLLowWidth(I2Cx, BRG);
        FL_I2C_Master_WriteSDAHoldTime(I2Cx, (uint32_t)((BRG & 0x1FF) / 2));
        /* 使能外设 */
        FL_I2C_Master_Enable(I2Cx);
        status = FL_PASS;
    }
    return status;
}

/**
  * @brief  将 @ref FL_I2C_MasterMode_InitTypeDef 结构体初始化为默认配置
  * @param  I2C_InitStruct 指向 @ref FL_I2C_MasterMode_InitTypeDef 结构体的指针
  *
  * @retval None
  */
void FL_I2C_MasterMode_StructInit(FL_I2C_MasterMode_InitTypeDef *I2C_InitStruct)
{
    if(I2C_InitStruct != NULL)
    {
        I2C_InitStruct->baudRate = 40000;
    }
}



/**
  * @}
  */

#endif /* FL_I2C_MASTER_DRIVER_ENABLED */

/**
  * @}
  */

/**
  * @}
  */

/********************** (C) COPYRIGHT Fudan Microelectronics **** END OF FILE ***********************/

