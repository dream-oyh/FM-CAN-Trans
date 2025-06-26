/**
  ******************************************************************************
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
  ******************************************************************************
  */

#include "clock.h"  

#define XTHF_TIMEOUT     0x0003FFFFU  /* 约10s */

/* XTHF寄存器参数检查 */
#define XTHF_REG_CHECK(xthf)  ((FL_CMU_XTHF_GetStartWaitTime()   == (xthf)->StartWaitTime) &&\
                               (FL_CMU_XTHF_IsEnabledBypass()    == (xthf)->Bypass) &&\
                               (FL_CMU_XTHF_ReadDriverStrength() == (xthf)->DriverStrength) &&\
                               (FL_CMU_XTHF_IsEnabled()          == FL_ENABLE))

/* 系统时钟选择错误变量 */
volatile uint32_t SYSCLKSELErrorState = 0;
/* 系统时钟状态变量 */
volatile SYSCLK_STATE SYSCLKState = SYSCLK_NORMAL;

/* RCHF初始化参数 */
const FL_CMU_RCHF_InitTypeDef CMU_RCHF_Init_Data = {
    /* RCHF频率必须≤24MHz, 否则需要考虑Code Wait */
    /* 当系统时钟使用XTHF时，RCHF频率和XTHF频率必须保持一致，这样才可以得到相同的目标值 */
    FL_CMU_RCHF_FREQUENCY_8MHZ
};

/* XTHF初始化参数 */
const FL_CMU_XTHF_InitTypeDef CMU_XTHF_Init_Data = {
    /* XTHF频率值，必须与外部实际晶体匹配 */
    8000000,
    /* XTHF启动等待时间 */
    FL_CMU_XTHF_START_WAIT_CYCLE_16384,
    /* XTHF Bypss使能或禁止 */
    FL_DISABLE,
    /* XTHF振荡强度 */
    0xA,
};

/**
  * @brief  ECCC_RAMP_FDET_IRQHandler中断服务
  * @param  void
  * @retval None
  */
void ECCC_RAMP_FDET_IRQHandler(void)
{
    uint32_t SYSCLKSELErrorIT = 0;
    uint32_t SYSCLKSELErrorFlag = 0;
    /* Note: CHIP U01版芯片在使能PLL后必须禁止ECCC_RAMP_FDET_IRQn中断服务，所以不应触发 */
    assert_param((!(CHIP_U01)) || (0x0 == FL_CMU_PLL_IsEnabled()));

    /* 发生XTHF停振或PLL失锁事件，切到次系统时钟 */
    if ((0x1U == FL_CMU_IsEnabledIT_XTHFFail()) && (0x1U == FL_CMU_IsActiveFlag_XTHFFail()))
    {   /* 清XTHF停振标识和PLL失锁标识在下面函数内执行 */
        SwtichToSenondarySystemClock(&CMU_RCHF_Init_Data);
    }
    
    /* 时钟选择中断处理 */
    SYSCLKSELErrorIT = FL_CMU_IsEnabledIT_SYSCKEWrong();
    SYSCLKSELErrorFlag = FL_CMU_IsActiveFlag_SYSCSEWrong();
    if ((0x1U == SYSCLKSELErrorIT) && (0x1U == SYSCLKSELErrorFlag))
    {   /* 清除系统时钟选择错误中断标志 */
        FL_CMU_ClearFlag_SYSCSEWrong();
        SYSCLKSELErrorState = 1;
    }
}


/**
  * @brief  RCHF初始化配置
  * @param  RCHFclock  RCHF参考时钟选择 This parameter can be one of the following values:
  *           @arg @ref FL_CMU_RCHF_FREQUENCY_8MHZ
  *           @arg @ref FL_CMU_RCHF_FREQUENCY_16MHZ
  *           @arg @ref FL_CMU_RCHF_FREQUENCY_24MHZ
  *           @arg @ref FL_CMU_RCHF_FREQUENCY_32MHZ
  * @retval PLL分频到1M的参量
  */
static uint32_t RCHFInit(uint32_t RCHFclock)
{   
    /* PLL分频到1M的参量 */
    uint32_t PLL_Prescaler_1M;
    
    switch (RCHFclock)
    {
        case FL_CMU_RCHF_FREQUENCY_8MHZ:
            FL_CMU_RCHF_WriteTrimValue(RCHF8M_TRIM);
            PLL_Prescaler_1M = FL_CMU_PLL_PSC_DIV8;
            break;

        case FL_CMU_RCHF_FREQUENCY_16MHZ:
            FL_CMU_RCHF_WriteTrimValue(RCHF16M_TRIM);
            PLL_Prescaler_1M = FL_CMU_PLL_PSC_DIV16;
            break;

        case FL_CMU_RCHF_FREQUENCY_24MHZ:
            FL_CMU_RCHF_WriteTrimValue(RCHF24M_TRIM);
            PLL_Prescaler_1M = FL_CMU_PLL_PSC_DIV24;
            break;

        case FL_CMU_RCHF_FREQUENCY_32MHZ:
            FL_CMU_RCHF_WriteTrimValue(RCHF32M_TRIM);
            PLL_Prescaler_1M = FL_CMU_PLL_PSC_DIV32;
            break;

        default:
            FL_CMU_RCHF_WriteTrimValue(RCHF8M_TRIM);
            PLL_Prescaler_1M = FL_CMU_PLL_PSC_DIV8;
            break;
    }

    FL_CMU_RCHF_SetFrequency(RCHFclock);
    FL_CMU_RCHF_Enable();
    return PLL_Prescaler_1M;
}


/**
  * @brief  切换到次系统时钟
  * @param  const FL_CMU_RCHF_InitTypeDef *rchf
  *             RCHF参数
  * @retval None
  */
void SwtichToSenondarySystemClock(const FL_CMU_RCHF_InitTypeDef *rchf)
{
    /* 清XTHF停振中断标识 */
    FL_CMU_ClearFlag_XTHFFail();
    /* 清PLL失锁中断标识 */
    FL_CMU_ClearFlag_PLLLostLock();
    /* 禁止高频检测报警中断 */
    FL_CMU_DisableIT_XTHFFail();
    /* 禁止PLL失锁报警中断 */
    FL_CMU_DisableIT_PLLLostLock();
    
    (void)RCHFInit(rchf->Frequency);
    FL_CMU_SetSystemClockSource(FL_CMU_SYSTEM_CLK_SOURCE_RCHF);
    SYSCLKState = SYSCLK_ERROR;
    SystemCoreClockUpdate();
}


/**
  * @brief  切换到主系统时钟
  * @param  const FL_CMU_RCHF_InitTypeDef *rchf,
  *              RCHF参数
  *         const FL_CMU_XTHF_InitTypeDef *rchf
  *              XTHF参数
  * @retval None
  */
void SwtichToMainSystemClock(const FL_CMU_XTHF_InitTypeDef *xthf)
{
    if ((SYSCLK_ERROR == SYSCLKState) &&\
        (FL_CMU_SYSTEM_CLK_SOURCE_XTHF != FL_CMU_GetSystemClockSource()))
    {   
        /* 即使发生停振或失锁事件，XTHF寄存器参数不应发生变化 */
        if (XTHF_REG_CHECK(xthf) || XTHF_REG_CHECK(xthf))
        {
            volatile uint32_t Reday[3];  /* 避免编译器优化 */
            uint32_t primask;
            
            /* 判断XTHF稳定标志是否建立，连续读三次 */
            Reday[0] = FL_CMU_XTHF_IsReady();
            Reday[1] = FL_CMU_XTHF_IsReady();
            Reday[2] = FL_CMU_XTHF_IsReady();
            if (Reday[0] && Reday[1] && Reday[2])
            {
                /* 清XTHF停振中断标识 */
                FL_CMU_ClearFlag_XTHFFail(); 
                if (0x0 == FL_CMU_IsActiveFlag_XTHFFail())
                { 
                    /* 竞态保护 */
                    primask = __get_PRIMASK();
                    __disable_irq();
                    SYSCLKState = SYSCLK_NORMAL;
                    FL_CMU_EnableIT_XTHFFail();
                    FL_CMU_SetSystemClockSource(FL_CMU_SYSTEM_CLK_SOURCE_XTHF);
                    SystemCoreClockUpdate();
                    /* 取消竞态保护 */
                    __set_PRIMASK(primask);
                }
            }
        }
        else
        {   
            /* 禁止高频检测报警中断 */
            FL_CMU_DisableIT_XTHFFail();
            /* 禁止PLL失锁报警中断 */
            FL_CMU_DisableIT_PLLLostLock();
            SYSCLKState = SYSCLK_NORMAL;
            SystemClockSel_XTHF(xthf);
        }
    }
}


/**
  * @brief  XTHF初始化配置
  * @param  const FL_CMU_XTHF_InitTypeDef *init
               XTHF初始化参数
  * @retval None
  */
void XTHFInit(const FL_CMU_XTHF_InitTypeDef *init)
{
    uint32_t counter = 0;
    uint32_t readystatus = 0;
    
    FL_GPIO_InitTypeDef    gpioInitStruction = { 0x0 };

    /* PC2, PC3配置成模拟功能，外接XTHF */
    gpioInitStruction.pin           = FL_GPIO_PIN_2 | FL_GPIO_PIN_3;
    gpioInitStruction.mode          = FL_GPIO_MODE_ANALOG;
    gpioInitStruction.outputType    = FL_GPIO_OUTPUT_PUSHPULL;
    gpioInitStruction.pull          = FL_GPIO_BOTH_DISABLE;
    gpioInitStruction.remapPin      = FL_GPIO_PINREMAP_FUNCTON0;
    gpioInitStruction.driveStrength = FL_GPIO_DRIVESTRENGTH_X3;
    (void)FL_GPIO_Init(GPIOC, &gpioInitStruction);
    /* 发生晶体停振事件，禁止复位芯片，仅产生报警 */
    FL_RMU_DisableCrystalStopReset(RMU);
    /* 配置XTHF参数 */
    FL_CMU_XTHF_WriteDriverStrength(init->DriverStrength);
    (void)((FL_ENABLE == init->Bypass) ? FL_CMU_XTHF_EnableBypass() : FL_CMU_XTHF_DisableBypass());
    FL_CMU_XTHF_SetStartWaitTime(init->StartWaitTime);
    /* 使能XTHF */
    FL_CMU_XTHF_Enable();
    do
    {
        readystatus = FL_CMU_XTHF_IsReady();
        counter++;
    
        if ((counter % 100) == 0)
        {   /* 清狗 */
            FL_IWDT_ReloadCounter(IWDT);
        }
    } while((readystatus != 0x1U) && (counter != XTHF_TIMEOUT));  /* 等待XTHF建立 */
    /* 清除高频晶体停振检测标志，必须放在XTHF稳定建立之后 */
    FL_CMU_ClearFlag_XTHFFail();

    /* 写晶体频率值，获取系统时钟使用 */
    XTHFClock = init->Frequency;
}


/**
  * @brief   SystemClockSel_XTHF 选择XTHF作为系统时钟
  * @param    const FL_CMU_XTHF_InitTypeDef *xthfInit
  *              XTHF初始化参数  
  * @retval   None
  */
void SystemClockSel_XTHF(const FL_CMU_XTHF_InitTypeDef *init)
{
    /* 先配置Wait，降低访问Flash总线时钟 */ 
    FL_FLASH_SetCodeReadWait(FLASH, FL_FLASH_READ_CODEWAIT_2CYCLE);
    FL_FLASH_SetDataReadWait(FLASH, FL_FLASH_READ_DATAWAIT_5CYCLE);
    
    XTHFInit(init);
    /* 清除时钟选择错误标志 */
    FL_CMU_ClearFlag_SYSCSEWrong();

    /* 注意：系统时钟为AHB分频后时钟，此处不分频 */
    FL_CMU_SetAHBPrescaler(FL_CMU_AHBCLK_PSC_DIV1);
    FL_CMU_SetAPB1Prescaler(FL_CMU_APB1CLK_PSC_DIV1);
    FL_CMU_SetAPB2Prescaler(FL_CMU_APB2CLK_PSC_DIV1);
    FL_CMU_SetSystemClockSource(FL_CMU_SYSTEM_CLK_SOURCE_XTHF);
    
    /* CODE Flash读等待周期配置，访问CODE Flash总线时钟频率需小于等于24Mhz */ 
    /* DATA Flash读等待周期配置，访问DATA Flash总线时钟频率需小于等于12.5Mhz */
    if (XTHFClock <= 8000000UL)
    {
        FL_FLASH_SetCodeReadWait(FLASH, FL_FLASH_READ_CODEWAIT_0CYCLE);
        FL_FLASH_SetDataReadWait(FLASH, FL_FLASH_READ_DATAWAIT_0CYCLE);
    }
    else if (XTHFClock <= 16000000UL)
    {
        FL_FLASH_SetCodeReadWait(FLASH, FL_FLASH_READ_CODEWAIT_0CYCLE);
        FL_FLASH_SetDataReadWait(FLASH, FL_FLASH_READ_DATAWAIT_1CYCLE);
    }
    else /* XTHFClock <= 24000000UL */ 
    {
        FL_FLASH_SetCodeReadWait(FLASH, FL_FLASH_READ_CODEWAIT_0CYCLE);
        FL_FLASH_SetDataReadWait(FLASH, FL_FLASH_READ_DATAWAIT_1CYCLE);
    }
    
    {   /* 监控XTHF停振事件功能配置 */
        FL_NVIC_ConfigTypeDef InterruptConfigStruct;
        /* 使能高频检测报警中断 */
        FL_CMU_EnableIT_XTHFFail(); 
         /* 使能时钟选择错误中断 */
        FL_CMU_EnableIT_SYSCKEWrong();
        /* 使能ECCC_RAMP_FDET_IRQn中断服务 */
        InterruptConfigStruct.preemptPriority = 0x00;
        FL_NVIC_Init(&InterruptConfigStruct, ECCC_RAMP_FDET_IRQn);
    }

    SystemCoreClockUpdate();
}





