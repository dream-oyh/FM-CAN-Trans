 /**    
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

#include "lptim16.h"
#include "clock.h"

/* 10ms 周期标志 */
volatile uint32_t Period10msFlag = 0;

/**
  * @brief  中断服务函数
  * @param  void
  * @retval void
  */
void LPTIM_BSTIM_IRQHandler(void)
{
    /* 定时器溢出中断 */
    if((0x1U == FL_LPTIM16_IsEnabledIT_Update(LPTIM16)) &&\
       (0x1U == FL_LPTIM16_IsActiveFlag_Update(LPTIM16)))
    {   
        /* 清除LPTIM16定时器溢出中断标志 */
        FL_LPTIM16_ClearFlag_Update(LPTIM16);
        Period10msFlag = 1;
    }
}


/**
  * @brief  LPTIM16初始化
  * @param  void
  * @retval void
  */
void LPTIM16_Init(void)
{
    FL_LPTIM16_InitTypeDef      TimInit;
    FL_NVIC_ConfigTypeDef       InterruptConfigStruct;
  
    /*-------------------定时器时基配置------------------- */
    /* 用于监控XTHF停振和PLL失锁事件，因此时钟源必须使用RCLP */
    TimInit.clockSource          = FL_CMU_LPTIM16_CLK_SOURCE_RCLP;      /* 工作时钟源配置：    RCLP */
    TimInit.mode                 = FL_LPTIM16_OPERATION_MODE_NORMAL;    /* 工作模式配置：      NORMAL */
    TimInit.prescalerClockSource = FL_LPTIM16_CLK_SOURCE_INTERNAL;      /* 预分频输入配置：    INTERNAL */
    TimInit.prescaler            = FL_LPTIM16_PSC_DIV1;                 /* 预分频值配置：      1分频 */
    TimInit.autoReload           = 320 - 1;                             /* 自动重装载值配置：  320(约10ms) */
    TimInit.encoderMode          = FL_LPTIM16_ENCODER_MODE_DISABLE;     /* 编码器模式使能配置：禁止 */
    TimInit.onePulseMode         = FL_LPTIM16_ONE_PULSE_MODE_CONTINUOUS;/* 单次计数模式配置：  禁止 */
    TimInit.triggerEdge          = FL_LPTIM16_ETR_TRIGGER_EDGE_RISING;  /* ETR触发沿配置：     上升沿 */
    TimInit.countEdge            = FL_LPTIM16_ETR_COUNT_EDGE_RISING;    /* ETR计数边沿配置：   上升沿 */
    FL_LPTIM16_Init(LPTIM16, &TimInit);
  
    /*-------------------定时器中断配置------------------- */
    /* 清除标志 */
    FL_LPTIM16_ClearFlag_Update(LPTIM16);
    /* 中断使能 */
    FL_LPTIM16_EnableIT_Update(LPTIM16);
    /* 配置NVIC，用于监控XTHF停振和PLL失锁事件，可配置较高优先级 */
    InterruptConfigStruct.preemptPriority = 0x01;
    FL_NVIC_Init(&InterruptConfigStruct, LPTIM_BSTIM_IRQn);
  
    /* 使能LPTIM16 */
    FL_LPTIM16_Enable(LPTIM16);
}


