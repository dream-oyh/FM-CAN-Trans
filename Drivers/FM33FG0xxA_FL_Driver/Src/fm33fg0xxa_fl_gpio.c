 /**    
  *******************************************************************************************************
  * @file    fm33fg0xxa_gpio.c
  * @author  FMSH Application Team
  * @brief   Source file of GPIO FL Module 
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
  
/* Includes ------------------------------------------------------------------*/
#include "fm33fg0xxa_fl.h"

/** @addtogroup FM33FG0XXA_FL_Driver
  * @{
  */

/* Private macros ------------------------------------------------------------*/
/** @addtogroup GPIO_FL_Private_Macros
  * @{
  */
#define         IS_GPIO_ALL_INSTANCE(INTENCE)              (((INTENCE) == GPIOA)||\
                                                            ((INTENCE) == GPIOB)||\
                                                            ((INTENCE) == GPIOC)||\
                                                            ((INTENCE) == GPIOD)||\
                                                            ((INTENCE) == GPIOE)||\
                                                            ((INTENCE) == GPIOF)||\
                                                            ((INTENCE) == GPIOG)||\
                                                            ((INTENCE) == GPIOH)||\
                                                            ((INTENCE) == GPIOI))

#define         IS_FL_GPIO_PIN(__VALUE__)                  ((((uint32_t)0x00000000U) < (__VALUE__)) &&\
                                                            ((__VALUE__) <= (FL_GPIO_PIN_ALL)))

#define         IS_FL_GPIO_MODE(__VALUE__)                  (((__VALUE__) == FL_GPIO_MODE_ANALOG)||\
                                                             ((__VALUE__) == FL_GPIO_MODE_INPUT)||\
                                                             ((__VALUE__) == FL_GPIO_MODE_OUTPUT)||\
                                                             ((__VALUE__) == FL_GPIO_MODE_DIGITAL))

#define         IS_FL_GPIO_OPENDRAIN(__VALUE__)             (((__VALUE__) == FL_GPIO_OUTPUT_OPENDRAIN)||\
                                                             ((__VALUE__) == FL_GPIO_OUTPUT_PUSHPULL))

#define         IS_FL_GPIO_DRIVESTRENGTH(__VALUE__)         (((__VALUE__) == FL_GPIO_DRIVESTRENGTH_CLOSE)||\
                                                             ((__VALUE__) == FL_GPIO_DRIVESTRENGTH_X1)||\
                                                             ((__VALUE__) == FL_GPIO_DRIVESTRENGTH_X3)||\
                                                             ((__VALUE__) == FL_GPIO_DRIVESTRENGTH_X4))

#define         IS_FL_GPIO_PULL(__VALUE__)                  (((__VALUE__) == FL_GPIO_PULLUP_ENABLE)||\
                                                             ((__VALUE__) == FL_GPIO_PULLDOWN_ENABLE)||\
                                                             ((__VALUE__) == FL_GPIO_BOTH_DISABLE))

#define         IS_FL_GPIO_REMAPPIN(__VALUE__)              (((__VALUE__) == FL_GPIO_PINREMAP_FUNCTON0)||\
                                                             ((__VALUE__) == FL_GPIO_PINREMAP_FUNCTON1)||\
                                                             ((__VALUE__) == FL_GPIO_PINREMAP_FUNCTON2)||\
                                                             ((__VALUE__) == FL_GPIO_PINREMAP_FUNCTON3))

#define         IS_FL_GPIO_WKUP_ENTRY(__VALUE__)            (((__VALUE__) == FL_GPIO_WKUP_INT_ENTRY_NMI)||\
                                                             ((__VALUE__) == FL_GPIO_WKUP_INT_ENTRY_NUM_39))

#define         IS_FL_GPIO_WKUP_EDGE(__VALUE__)             (((__VALUE__) == FL_GPIO_WAKEUP_TRIGGER_FALLING)||\
                                                             ((__VALUE__) == FL_GPIO_WAKEUP_TRIGGER_RISING)||\
                                                             ((__VALUE__) == FL_GPIO_WAKEUP_TRIGGER_BOTH))

#define         IS_FL_GPIO_WKUP_NUM(__VALUE__)              (((__VALUE__) == FL_GPIO_WAKEUP_0)||\
                                                             ((__VALUE__) == FL_GPIO_WAKEUP_1)||\
                                                             ((__VALUE__) == FL_GPIO_WAKEUP_2)||\
                                                             ((__VALUE__) == FL_GPIO_WAKEUP_3)||\
                                                             ((__VALUE__) == FL_GPIO_WAKEUP_4)||\
                                                             ((__VALUE__) == FL_GPIO_WAKEUP_5)||\
                                                             ((__VALUE__) == FL_GPIO_WAKEUP_6)||\
                                                             ((__VALUE__) == FL_GPIO_WAKEUP_7)||\
                                                             ((__VALUE__) == FL_GPIO_WAKEUP_8)||\
                                                             ((__VALUE__) == FL_GPIO_WAKEUP_9))

/**
  * @}
  */

/** @addtogroup GPIO_FL_EF_Init
  * @{
  */

/**
  * @brief  复位对应GPIO控制寄存器.
  * @param  GPIOx GPIO Port
  * @retval ErrorStatus枚举值:
  *         -FL_PASS 外设寄存器值恢复复位值
  *         -FL_FAIL 未成功执行
  */
FL_ErrorStatus FL_GPIO_DeInit(GPIO_Type *GPIOx, uint32_t pin)
{
    uint32_t pinPos     = 0x00000000U;
    uint32_t currentPin = 0x00000000U;
    /* 入口参数检查 */
    assert_param(IS_GPIO_ALL_INSTANCE(GPIOx));
    assert_param(IS_FL_GPIO_PIN(pin));
    /* 恢复寄存器值为默认值 */
    while(((pin) >> pinPos) != 0x00000000U)
    {
        /* 获取当前遍历到的Pin脚 */
        currentPin = (pin) & (0x1UL << pinPos);
        if(currentPin != 0X0U)
        {
            FL_GPIO_SetPinMode(GPIOx, currentPin, FL_GPIO_MODE_INPUT);
            FL_GPIO_DisablePinInput(GPIOx, currentPin);
            FL_GPIO_DisablePinOpenDrain(GPIOx, currentPin);
            FL_GPIO_SetPinDriveStrength(GPIOx, currentPin, FL_GPIO_DRIVESTRENGTH_X3);
            FL_GPIO_DisablePullDown(GPIOx, currentPin);
            FL_GPIO_DisablePullUp(GPIOx, currentPin);
            FL_GPIO_SetPinRemap(GPIOx, currentPin, FL_GPIO_PINREMAP_FUNCTON0);
        }
        pinPos++;
    }
    return FL_PASS;
}

/* FM33FG0x5A有引脚复用，以下是相关处理机制 */
#if defined(FM33FG0x5A)
/**
* @brief  复用GPIO数据类型,单个元素为一组复用的GPIO
  */
static const struct MultiplexGpioType 
{
    /* 成员元素 */
    const struct 
    {
        GPIO_Type *GPIox;      /* 元素信息: GPIO的Port索引 */
        uint32_t   Pin;        /* 元素信息: GPIO的Pin索引  */
    } MultiplexGpioElement[2]; /* 一组复用关系，无先后顺序 */

} MultiplexGpioTable[] =       /* 复用GPIO的表格清单 */
{
    { {{GPIOD, (uint32_t)FL_GPIO_PIN_0 }/*PD0 */, {GPIOE, (uint32_t)FL_GPIO_PIN_7 }/*PE7 */} },/* 此为一组复用关系 */
};

/**
* @brief  复用GPIO的组数
  */
static const uint32_t u32MultiplexGpioCount =\
    (uint32_t)((sizeof(MultiplexGpioTable)) / (sizeof(MultiplexGpioTable[0])));

/**
* @brief  针对复用GPIO，如有一个GPIO使用，则将另一个GPIO配置为高阻抗，避免相互影响
  * @param  GPIOx 当前使用的GPIO Port索引
  * @param  pin   当前使用的GPIO Pin索引
  * @retval 无
  */
static void FL_GPIO_Multiplex_DeInit(GPIO_Type *GPIOx, uint32_t pin)
{
    /* 指向复用GPIO表格的指针 */
    const struct MultiplexGpioType *pMultiplexGpio = MultiplexGpioTable;
    
    /* 入口参数检查 */
    assert_param(IS_GPIO_ALL_INSTANCE(GPIOx));
    assert_param(IS_FL_GPIO_PIN(pin));
    
    for( ; pMultiplexGpio < (MultiplexGpioTable + u32MultiplexGpioCount); pMultiplexGpio++)
    {
        if(   (pMultiplexGpio->MultiplexGpioElement[0].Pin   == pin)\
           && (pMultiplexGpio->MultiplexGpioElement[0].GPIox == GPIOx))
        {
            /* 未使用的GPIO执行高阻抗初始化 */
            (void)FL_GPIO_DeInit(pMultiplexGpio->MultiplexGpioElement[1].GPIox,\
                                 pMultiplexGpio->MultiplexGpioElement[1].Pin );
            break;            
        }
        else if(   (pMultiplexGpio->MultiplexGpioElement[1].Pin   == pin)\
                && (pMultiplexGpio->MultiplexGpioElement[1].GPIox == GPIOx))
        {
            /* 未使用的GPIO执行高阻抗初始化 */
            (void)FL_GPIO_DeInit(pMultiplexGpio->MultiplexGpioElement[0].GPIox,\
                                 pMultiplexGpio->MultiplexGpioElement[0].Pin );
            break;            
        }    
    }
}
#endif /* defined(FM33FG0x5A) */


/**
  * @brief  根据 GPIO_InitStruct的配置信息初始化对应外设.
  * @param  GPIOx GPIO Port
  * @param  GPIO_InitStruct 指向一个 @ref FL_GPIO_InitTypeDef 结构体
  *         其中包含了外设的相关配置信息.
  * @retval ErrorStatus枚举值
  *         -FL_FAIL 配置过程发生错误
  *         -FL_PASS 配置成功
  */
FL_ErrorStatus FL_GPIO_Init(GPIO_Type *GPIOx, FL_GPIO_InitTypeDef *initStruct)
{
    uint32_t pinPos     = 0x00000000U;
    uint32_t currentPin = 0x00000000U;
    FL_ErrorStatus status = FL_FAIL;
    if(initStruct != NULL)
    {
        /* 入口参数检查 */
        assert_param(IS_GPIO_ALL_INSTANCE(GPIOx));
        assert_param(IS_FL_GPIO_PIN(initStruct->pin));
        assert_param(IS_FL_GPIO_MODE(initStruct->mode));
        assert_param(IS_FL_GPIO_OPENDRAIN(initStruct->outputType));
        assert_param(IS_FL_GPIO_DRIVESTRENGTH(initStruct->driveStrength));
        assert_param(IS_FL_GPIO_PULL(initStruct->pull));
        assert_param(IS_FL_GPIO_REMAPPIN(initStruct->remapPin));
        /* 使能时钟总线 */
        FL_CMU_EnableGroup1BusClock(FL_CMU_GROUP1_BUSCLK_PAD);
        /* 这里考虑到PIN有可能不止一个因此需要遍历 */
        while(((initStruct->pin) >> pinPos) != 0x00000000U)
        {
            /* 获取当前遍历到的Pin脚 */
            currentPin = (initStruct->pin) & (0x1UL << pinPos);
            if(currentPin != 0X0U)
            {
                /* 仅针对48pin处理 */ 
            #if defined (FM33FG0x5A)
                /* 检查复用引脚，并做处理 */
                FL_GPIO_Multiplex_DeInit(GPIOx, currentPin);
            #endif /* defined (FM33FG0x5A) */
                /* Pin脚模拟模式设置 */
                if(initStruct->mode == FL_GPIO_MODE_ANALOG)
                {
                    FL_GPIO_DisablePinInput(GPIOx, currentPin);
                    FL_GPIO_DisablePinOpenDrain(GPIOx, currentPin);
                }
                else
                {
                    /* Pin脚输入使能控制 */
                    if(initStruct->mode == FL_GPIO_MODE_INPUT)
                    {
                        FL_GPIO_EnablePinInput(GPIOx, currentPin);
                    }
                    else
                    {
                        FL_GPIO_DisablePinInput(GPIOx, currentPin);
                    }
                    /* Pin脚输出模式设置 */
                    if(initStruct->outputType == FL_GPIO_OUTPUT_PUSHPULL)
                    {
                        FL_GPIO_DisablePinOpenDrain(GPIOx, currentPin);
                    }
                    else
                    {
                        FL_GPIO_EnablePinOpenDrain(GPIOx, currentPin);
                    }
                    /* Pin脚驱动强度设置 */
                    FL_GPIO_SetPinDriveStrength(GPIOx, currentPin, initStruct->driveStrength);
                }
                /* Pin脚上拉/下拉模式设置 */
                if(initStruct->pull == FL_GPIO_PULLUP_ENABLE)
                {
                    FL_GPIO_DisablePullDown(GPIOx, currentPin);
                    FL_GPIO_EnablePullUp(GPIOx, currentPin);
                }
                else if(initStruct->pull == FL_GPIO_PULLDOWN_ENABLE)
                {
                    FL_GPIO_DisablePullUp(GPIOx, currentPin);
                    FL_GPIO_EnablePullDown(GPIOx, currentPin);
                }
                else
                {
                    FL_GPIO_DisablePullDown(GPIOx, currentPin);
                    FL_GPIO_DisablePullUp(GPIOx, currentPin);
                }
                /* 数字模式复用功能选择 */
                if(initStruct->mode == FL_GPIO_MODE_DIGITAL)
                {
                    /*重定向*/
                    FL_GPIO_SetPinRemap(GPIOx, currentPin, initStruct->remapPin);
                }
                else
                {
                    FL_GPIO_SetPinRemap(GPIOx, currentPin, FL_GPIO_PINREMAP_FUNCTON0);
                }
                /* Pin脚工作模式设置 */
                FL_GPIO_SetPinMode(GPIOx, currentPin, initStruct->mode);
            }
            pinPos++;
        }
        status = FL_PASS;
    }
    return status;
}

/**
  * @brief  设置 GPIO_InitStruct 为默认配置
  * @param  GPIO_InitStruct 指向需要将值设置为默认配置的结构体 @ref FL_GPIO_InitTypeDef 结构体
  *
  * @retval None
  */
void FL_GPIO_StructInit(FL_GPIO_InitTypeDef *initStruct)
{
    if(initStruct != NULL)
    {
        /* 复位配置信息 */
        initStruct->pin           = FL_GPIO_PIN_ALL;
        initStruct->mode          = FL_GPIO_MODE_INPUT;
        initStruct->outputType    = FL_GPIO_OUTPUT_OPENDRAIN;
        initStruct->driveStrength = FL_GPIO_DRIVESTRENGTH_X3;
        initStruct->pull          = FL_GPIO_PULLUP_ENABLE;
        initStruct->remapPin      = FL_GPIO_PINREMAP_FUNCTON0;
    }
}

/**
  * @brief  根据 WKUP_InitTypeDef的配置信息初始化对应外设.
  * @param  WKUP_InitTypeDef 指向一个 @ref FL_WKUP_InitTypeDef 结构体
  *    @arg @ref FL_GPIO_WAKEUP_TRIGGER_FALLING
  *    @arg @ref FL_GPIO_WAKEUP_TRIGGER_RISING
  *    @arg @ref FL_GPIO_WAKEUP_TRIGGER_BOTH
  * @param  Wkupx 唤醒入口
  *    @arg @ref FL_GPIO_WAKEUP_0
  *    @arg @ref FL_GPIO_WAKEUP_1
  *    @arg @ref FL_GPIO_WAKEUP_2
  *    @arg @ref FL_GPIO_WAKEUP_3
  *    @arg @ref FL_GPIO_WAKEUP_4
  *    @arg @ref FL_GPIO_WAKEUP_5
  *    @arg @ref FL_GPIO_WAKEUP_6
  *    @arg @ref FL_GPIO_WAKEUP_7
  *    @arg @ref FL_GPIO_WAKEUP_8
  *    @arg @ref FL_GPIO_WAKEUP_9
  * @retval ErrorStatus枚举值
  *         -FL_FAIL 配置过程发生错误
  *         -FL_PASS 配置成功
  */
FL_ErrorStatus FL_WKUP_Init(FL_WKUP_InitTypeDef *initStruct, uint32_t wakeup)
{
    FL_ErrorStatus status = FL_FAIL;
    if(initStruct != NULL)
    {
        /* 入口参数检查 */
        assert_param(IS_FL_GPIO_WKUP_EDGE(initStruct->polarity));
        assert_param(IS_FL_GPIO_WKUP_NUM(wakeup));
        FL_GPIO_SetWakeupEdge(GPIO, wakeup, initStruct->polarity);
        FL_GPIO_EnableWakeup(GPIO, wakeup);
        status = FL_PASS;
    }
    return status;
}

/**
  * @brief  去初始化Wakeup设置.
  * @param  Wkupx 唤醒入口
  *    @arg @ref FL_GPIO_WAKEUP_0
  *    @arg @ref FL_GPIO_WAKEUP_1
  *    @arg @ref FL_GPIO_WAKEUP_2
  *    @arg @ref FL_GPIO_WAKEUP_3
  *    @arg @ref FL_GPIO_WAKEUP_4
  *    @arg @ref FL_GPIO_WAKEUP_5
  *    @arg @ref FL_GPIO_WAKEUP_6
  *    @arg @ref FL_GPIO_WAKEUP_7
  *    @arg @ref FL_GPIO_WAKEUP_8
  *    @arg @ref FL_GPIO_WAKEUP_9
  * @retval ErrorStatus枚举值
  *         -FL_FAIL 配置过程发生错误
  *         -FL_PASS 配置成功
  */
FL_ErrorStatus FL_WKUP_DeInit(uint32_t wakeup)
{
    /* 入口参数检查 */
    assert_param(IS_FL_GPIO_WKUP_NUM(wakeup));
    FL_GPIO_DisableWakeup(GPIO, wakeup);
    return FL_PASS;
}
/**
  * @brief  设置 GPIO_InitStruct 为默认配置
  * @param  GPIO_InitStruct 指向需要将值设置为默认配置的结构体 @ref FL_GPIO_InitTypeDef 结构体
  *  @arg @ref FL_GPIO_WAKEUP_TRIGGER_FALLING
  *  @arg @ref FL_GPIO_WAKEUP_TRIGGER_RISING
  *  @arg @ref FL_GPIO_WAKEUP_TRIGGER_BOTH
  *
  * @retval None
  */
void FL_WKUP_StructInit(FL_WKUP_InitTypeDef *initStruct_Wakeup)
{
    if(initStruct_Wakeup != NULL)
    {
        /* 复位配置信息 */
        initStruct_Wakeup->polarity = FL_GPIO_WAKEUP_TRIGGER_FALLING;
    }
}

/**
  * @brief  配置所有IO口为输入模式、输入使能关闭（高阻态），SWD接口除外。
  * @note   PD7和PD8为调试接口
  *
  * @param  None
  *
  * @retval None
  */
void FL_GPIO_ALLPIN_LPM_MODE(void)
{
    (void)FL_GPIO_DeInit(GPIOA, FL_GPIO_PIN_ALL);
    (void)FL_GPIO_DeInit(GPIOB, FL_GPIO_PIN_ALL);
    (void)FL_GPIO_DeInit(GPIOC, FL_GPIO_PIN_ALL);
    (void)FL_GPIO_DeInit(GPIOD, FL_GPIO_PIN_ALL_EXCEPTSWD);
    (void)FL_GPIO_DeInit(GPIOE, FL_GPIO_PIN_ALL);
    (void)FL_GPIO_DeInit(GPIOF, FL_GPIO_PIN_ALL);
    (void)FL_GPIO_DeInit(GPIOG, FL_GPIO_PIN_ALL);
    (void)FL_GPIO_DeInit(GPIOH, FL_GPIO_PIN_ALL);
    (void)FL_GPIO_DeInit(GPIOI, FL_GPIO_PIN_ALL);
}
/**
  * @}
  */

/**
  * @}
  */
/*************************************************************END OF FILE************************************************************/
