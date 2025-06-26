 /*    
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
  ******************************************************************************
  */
 
#include "gpio.h"
//#include "fm33fg0xxa_fl_gpio.h"
#include "fm33fg0xxa_fl.h"
/**
  * @brief  配置KEY按键初始化
  * @param  void
  * @retval void
  */
void KEY_Init(void)
{
    //  B2口是机载按键接口
    FL_GPIO_InitTypeDef GPIO_InitStruct = {0};
    FL_EXTI_CommonInitTypeDef extiCommonInitStruct = {0};
    FL_EXTI_InitTypeDef extiInitStruct = {0};
    FL_NVIC_ConfigTypeDef InterruptConfigStruct;
    
    /* 用到的GPIO引脚，设置为输入功能，PB8、PB2为开发板按键 */
    GPIO_InitStruct.pin           = FL_GPIO_PIN_2; //FL_GPIO_PIN_8 | FL_GPIO_PIN_2; 
    GPIO_InitStruct.mode          = FL_GPIO_MODE_INPUT;
    GPIO_InitStruct.outputType    = FL_GPIO_OUTPUT_PUSHPULL;
    GPIO_InitStruct.pull          = FL_GPIO_PULLUP_ENABLE;
    GPIO_InitStruct.remapPin      = FL_GPIO_PINREMAP_FUNCTON2;
    GPIO_InitStruct.driveStrength = FL_GPIO_DRIVESTRENGTH_X3;     
    (void)FL_GPIO_Init(GPIOB, &GPIO_InitStruct);
    
    /* EXTI中断采样时钟选择 */
    extiCommonInitStruct.clockSource = FL_CMU_EXTI_CLK_SOURCE_AHBCLK;
    /* 休眠使能外部中断采样 */
    extiCommonInitStruct.EXTIOnSleep = FL_DISABLE;
    (void)FL_EXTI_CommonInit(&extiCommonInitStruct);

    /* 配置PB8、PB2引脚外部中断功能 */
    extiInitStruct.extiPinX    = FL_GPIO_PIN_2; //FL_GPIO_PIN_8 | FL_GPIO_PIN_2; 
    /* 使能数字滤波 */
    extiInitStruct.filter      = FL_ENABLE;
    /* 设置触发边沿模式 */
    extiInitStruct.triggerEdge = FL_GPIO_EXTI_TRIGGER_EDGE_FALLING;  
    (void)FL_EXTI_Init(GPIOB, &extiInitStruct);     

    /* 清除中断标识 */
    FL_EXTI_ClearFlag(GPIOB, FL_GPIO_PIN_2);
    /* NVIC中断配置 */
    InterruptConfigStruct.preemptPriority = 0x02;
    FL_NVIC_Init(&InterruptConfigStruct, EXTI_DAC_IRQn);
}
