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

#include "can.h"
#include "fm33fg0xxa_fl.h"
#include "gpio.h"
CanTxMsg TxMessage = {0};  /* 发送缓冲区 */
CanRxMsg RxMessage = {0};  /* 接收缓冲区 */


/* CAN 中断服务函数 */
void FSCAN_IRQHandler(void)          
{
    uint32_t RXNotEmptyIT, RXNotEmptyFLAG;

    RXNotEmptyIT   = FL_CAN_IsEnabledIT_RXNotEmpty(CAN);
    RXNotEmptyFLAG = FL_CAN_IsActiveFlag_RXNotEmpty(CAN);
    if ((0x01U == RXNotEmptyIT) && ( 0x01U == RXNotEmptyFLAG))
    {
        FL_CAN_FIFO_Read(CAN);
        FL_CAN_ClearFlag_RXNotEmpty(CAN);
    }
    
    /* 必须保留 */
    if ((0x01U == FL_CAN_IsEnabledIT_BusOffRecovery(CAN)) &&\
        (0x01U == FL_CAN_IsActiveFlag_BusOffRecovery(CAN))) 
    {
        FL_CAN_ClearFlag_BusOffRecovery(CAN);
        FL_CAN_Disable(CAN);
        FL_CAN_Enable(CAN);
    }
}

/*----------------------------------------------------------------------------*/
/**
  * @brief  初始化CAN模块的同步采样功能
  * @param  Can控制器
  * @retval 返回错误状态，可能值：
  *         -0     成功 执行
  *         -非0   未成功执行
  */
int32_t Can_Rx_SynSamp_Init(CAN_Type *const CANx)
{
    FL_CAN_Disable(CANx);

    FL_CAN_EnableRXPresync(CANx);

    FL_CAN_Enable(CANx);
    
    return 0;
}

/*-----------------------------------------------------------------------------*/
/**
  * @brief  配置CAN进入Sleep模式
            在调用该功能函数之前，必须执行CAN控制器初始化函数，进入configruation
            或 normal模式，注意应同步使能唤醒功能
  * @param  Can控制器，所选择的CAN_Rx引脚
  * @retval 返回错误状态，可能值：
  *         -0     成功 执行
  *         -非0   未成功执行
  */
int32_t Can_Sleep_Mode_Init(CAN_Type *const CANx)
{
    IRQn_Type CAN_IRQ;
    uint32_t u32CMU_OPCLK_CANx, u32TimeOut;
    
    /* 使能总线时钟  */
    FL_CMU_EnableGroup3BusClock(FL_CMU_GROUP3_BUSCLK_FSCAN);
    u32CMU_OPCLK_CANx = FL_CMU_OPCLK_FSCAN;
    CAN_IRQ = FSCAN_IRQn;
    
    /* 检查在Can_Control_Init()中，是否已使能唤醒功能 */
    if (0 == FL_CAN_IsEnabledWakeup(CANx))
    {
        return -2;  /* 未使能唤醒功能，请在Can控制器初始化函数配置为使能 */
    } 
  
    /* 检查Can控制器进入sleep模式之前所处于的工作模式 */
    u32TimeOut = CAN_TIMEOUT;
    if (CAN_SR_NORMAL == (CANx->SR & CAN_SR_NORMAL_Msk))
    {/* normal模式，必须等待Bus IDLE */
        do
        {
            u32TimeOut--;
        }while(u32TimeOut && !FL_CAN_IsActiveFlag_BusIdle(CANx));  
    }
    else if (CAN_SR_LBACK == (CANx->SR & CAN_SR_LBACK_Msk))
    {/* loop back模式，不支持进入sleep，重新执行CAN控制器初始化函数 */
        u32TimeOut = 0;
    }  
    if (0 == u32TimeOut)
    {
        return -3;
    }
    
    /* 检查发送Buffer是否全部为空 */
    if ( FL_CAN_GetTXBufferStatus(CANx) ||\
         !FL_CAN_IsActiveFlag_TXBufferEmpty(CANx, FL_CAN_BUFFER0) ||\
         !FL_CAN_IsActiveFlag_TXBufferEmpty(CANx, FL_CAN_BUFFER1) ||\
         !FL_CAN_IsActiveFlag_TXBufferEmpty(CANx, FL_CAN_BUFFER2))
    {
        return -4;
    }
 
    /* 如要支持CAN 唤醒，CAN收发器的控制引脚即使在休眠模式下也应保持使能 */

    /* 清Sleep中断标志 */
    FL_CAN_ClearFlag_Sleep(CANx);
    /* 清唤醒中断标志 */
    FL_CAN_ClearFlag_Wakeup(CANx);
    /* 使能唤醒中断 */
    FL_CAN_EnableIT_Wakeup(CANx);
    NVIC_DisableIRQ(CAN_IRQ);
    NVIC_SetPriority(CAN_IRQ, 2); 
    NVIC_EnableIRQ(CAN_IRQ); 
    
    /* 进入Sleep模式 */
    FL_CAN_EnableSleepMode(CANx);
    FL_CAN_Enable(CANx);
    
    /* 确认进入Sleep模式 */
    u32TimeOut = CAN_TIMEOUT;
    do
    {
        u32TimeOut--;
    }while(u32TimeOut && !FL_CAN_IsActiveFlag_Sleep(CANx));  
    if (0 == u32TimeOut)
    {
        return -6;
    }
    
    /* 注意，必须确认进入Sleep模式后，才允许禁止CAN工作时钟 */
    FL_CMU_DisableOperationClock(u32CMU_OPCLK_CANx);    
    return 0;
}


/*----------------------------------------------------------------------------*/
 /**
  * @brief  CAN控制器初始化函数
            使用CAN功能之前，必须先执行该初始化函数
  * @param  Can控制器，所选择的CAN_Rx引脚
  * @retval 返回错误状态，可能值：
  *         -0     成功 执行
  *         -非0   未成功执行
  */
int32_t Can_Controller_Init(void)
{
    CAN_Type *CANx;   
    IRQn_Type CAN_IRQ;
    FL_GPIO_InitTypeDef      GPIO_InitStruct = {0};
    FL_CAN_InitTypeDef       CAN_InitStructure = {0};
    FL_CAN_FilterInitTypeDef CAN_FilterInitStructure = {0};
    
     /* 选择CAN控制器 */
    CANx = CAN;
    
     /* 判断CAN控制器合法性 */
    switch ((uint32_t)CANx)
    {
        case (uint32_t)CAN:
            CAN_IRQ = FSCAN_IRQn;
            break;
        default:
            return -1;
    }
    
    /* 选择CAN Rx引脚: 请参考产品说明书，正确选择 */
    GPIO_InitStruct.pin = FL_GPIO_PIN_6;
    GPIO_InitStruct.mode = FL_GPIO_MODE_DIGITAL;
    GPIO_InitStruct.pull = FL_GPIO_BOTH_DISABLE;
    GPIO_InitStruct.outputType = FL_GPIO_OUTPUT_PUSHPULL;
    GPIO_InitStruct.remapPin = FL_GPIO_PINREMAP_FUNCTON0;
    GPIO_InitStruct.driveStrength = FL_GPIO_DRIVESTRENGTH_X3;  
    (void)FL_GPIO_Init(GPIOA, &GPIO_InitStruct);
    
    /* 选择CAN Tx引脚: 请参考产品说明书，正确选择 */
    GPIO_InitStruct.pin = FL_GPIO_PIN_7;
    GPIO_InitStruct.mode = FL_GPIO_MODE_DIGITAL;
    GPIO_InitStruct.pull = FL_GPIO_BOTH_DISABLE;
    GPIO_InitStruct.outputType = FL_GPIO_OUTPUT_PUSHPULL;
    GPIO_InitStruct.remapPin = FL_GPIO_PINREMAP_FUNCTON0;
    GPIO_InitStruct.driveStrength = FL_GPIO_DRIVESTRENGTH_X3;  
    (void)FL_GPIO_Init(GPIOA, &GPIO_InitStruct);
   
    /* CAN收发模块引脚使能 */
    GPIOB->DRST = FL_GPIO_PIN_7;
    GPIO_InitStruct.pin = FL_GPIO_PIN_7;
    GPIO_InitStruct.mode = FL_GPIO_MODE_OUTPUT;
    GPIO_InitStruct.pull = FL_GPIO_BOTH_DISABLE;
    GPIO_InitStruct.outputType = FL_GPIO_OUTPUT_PUSHPULL;
    GPIO_InitStruct.remapPin = FL_GPIO_PINREMAP_FUNCTON1;
    GPIO_InitStruct.driveStrength = FL_GPIO_DRIVESTRENGTH_X3;  
    (void)FL_GPIO_Init(GPIOB, &GPIO_InitStruct);
    
    /* 配置波特率= CAN_CLK/(BRP+1)/(TS1_Tq+TS2_Tq+1);  8M/(0+1)/(11+4+1)=500K */
    CAN_InitStructure.TS1 = FL_CAN_TS1_11Tq;   // 10
    CAN_InitStructure.TS2 = FL_CAN_TS2_4Tq;    // 3   /* 位时序设置 */
    CAN_InitStructure.SJW = FL_CAN_SJW_3Tq;
    CAN_InitStructure.BRP = 0;                                      /* 分频系数 */
    CAN_InitStructure.ABOM = FL_CAN_AUTO_MANAGE_HARDWARE;           /* 自动总线关闭管理 */
    CAN_InitStructure.AREN = FL_ENABLE;                             /* 自动重发使能 */
    CAN_InitStructure.mode = FL_CAN_MODE_LOOPBACK;                    /* 工作模式设置 */
    CAN_InitStructure.clockSource = FL_CMU_FSCAN_CLK_SOURCE_APBCLK; /* 工作时钟选择 */
    CAN_InitStructure.TXPriority  = FL_CAN_TX_PRIORITY_BUFFER;      /* 发送优先级模式选择 */
    CAN_InitStructure.wakeup = FL_DISABLE;                          /* RX下降沿唤醒MCU使能 */
    (void)FL_CAN_Init(CANx, &CAN_InitStructure);
    
    /* CAN Rx 同步采样功能初始化 */ 
    Can_Rx_SynSamp_Init(CANx);
    
    /* 配置ID滤波器及掩码器 */
    CAN_FilterInitStructure.filterMaskMode = FL_CAN_MASKMODE_MASK;   /* 滤波器MASK模式设置 */
    CAN_FilterInitStructure.filterIDMode  = FL_CAN_IDMODE_32BIT;     /* 滤波器ID模式设置 */
    if (CAN_FilterInitStructure.filterIDMode  == FL_CAN_IDMODE_32BIT)/* 滤波器模式：扩展模式32bit */
    {
        CAN_FilterInitStructure.filterIdStandard = 0X6AD;            /* 过滤标准ID */
        CAN_FilterInitStructure.filterIdSRR = FL_CAN_SRR_BIT_LOW;
        CAN_FilterInitStructure.filterIdIDE = FL_CAN_IDE_BIT_LOW;
        CAN_FilterInitStructure.filterIdRTR = FL_CAN_RTR_BIT_LOW;

        CAN_FilterInitStructure.filterMaskIdStandard = 0X7FF;         /* 滤波器掩码 */
        CAN_FilterInitStructure.filterMaskIdSRR = FL_DISABLE;
        CAN_FilterInitStructure.filterMaskIdIDE = FL_DISABLE;         /* 使能该位是否参与滤波器比较 */
        CAN_FilterInitStructure.filterMaskIdRTR = FL_DISABLE;
    }
    else                                                              /* 滤波器模式：标准模式16bit */  
    {
        CAN_FilterInitStructure.filterSTD1IdStandard = 0X6AD;         /* 过滤标准ID */
        CAN_FilterInitStructure.filterSTD1IdSRR = FL_CAN_STD1SRR_BIT_LOW;
        CAN_FilterInitStructure.filterSTD1IdIDE = FL_CAN_STD1IDE_BIT_LOW;
        CAN_FilterInitStructure.filterSTD2IdExtend = 0X1AB5D993;      /* 过滤扩展ID */
        CAN_FilterInitStructure.filterSTD2IdSRR = FL_CAN_STD2SRR_BIT_HIGH;
        CAN_FilterInitStructure.filterSTD2IdIDE = FL_CAN_STD2IDE_BIT_HIGH;
    
        CAN_FilterInitStructure.filterSTD1MaskIdStandard = 0X7FF;     /* 滤波器掩码1 */
        CAN_FilterInitStructure.filterSTD1MaskIdSRR = FL_ENABLE;
        CAN_FilterInitStructure.filterSTD1MaskIdIDE = FL_ENABLE;      /* 使能该位是否参与滤波器比较 */
        CAN_FilterInitStructure.filterSTD2MaskIdExtend = 0X1FFFFFFF;  /* 滤波器掩码2 */
        CAN_FilterInitStructure.filterSTD2MaskIdSRR = FL_ENABLE;
        CAN_FilterInitStructure.filterSTD2MaskIdIDE = FL_ENABLE;      /* 使能该位是否参与滤波器比较 */
    }

    CAN_FilterInitStructure.filterEn = FL_ENABLE;                     /* 使能滤波器 */
    (void)FL_CAN_FilterInit(CANx, &CAN_FilterInitStructure, FL_CAN_FILTER1);
    
    /* 清Sleep中断标志 请保留*/
    FL_CAN_ClearFlag_Sleep(CANx);
    /* 禁止Sleep中断标志 请保留*/
    FL_CAN_DisableIT_Sleep(CANx);
    /* 清唤醒中断标志 请保留 */
    FL_CAN_ClearFlag_Wakeup(CANx);
    /* 禁止唤醒中断 请保留*/
    FL_CAN_DisableIT_Wakeup(CANx);

    /* 使能中断 */
    /* 清除RxFIFO的非空中断标志 */
    FL_CAN_ClearFlag_RXNotEmpty(CANx);
    /* 使能RxFIFO的非空中断 */
    FL_CAN_EnableIT_RXNotEmpty(CANx); 
    
    /* 必须使用：清除Bus-off Recovery中断标志 */
    FL_CAN_ClearFlag_BusOffRecovery(CANx);
    /* 必须使用：使能Bus-off Recovery中断 */
    FL_CAN_EnableIT_BusOffRecovery(CANx);

    NVIC_DisableIRQ(CAN_IRQ);
    NVIC_ClearPendingIRQ(CAN_IRQ);
    NVIC_SetPriority(CAN_IRQ, 2); 
    NVIC_EnableIRQ(CAN_IRQ);
    return 0;
}

/*----------------------------------------------------------------------------*/
 /**
  * @brief  CAN控制器反初始化函数
  * @param  void
  * @retval 返回错误状态，可能值：
  *         -0     成功 执行
  *         -非0   未成功执行
  */
int32_t Can_Controller_DeInit(void)
{
    CAN_Type *CANx;   
    IRQn_Type CAN_IRQ; 
    uint32_t u32RMU_RSTAPB_CANx, u32CMU_GROUP3_BUSCLK_CANx, u32CMU_OPCLK_CANx;
    
    /* 选择CAN控制器 */
    CANx = CAN;
    
    /* 判断CAN控制器合法性 */
    switch ((uint32_t)CANx)
    {
        case (uint32_t)CAN:
            CAN_IRQ = FSCAN_IRQn;
            u32RMU_RSTAPB_CANx = FL_RMU_RSTAPB_FSCAN;
            u32CMU_OPCLK_CANx = FL_CMU_OPCLK_FSCAN;
            u32CMU_GROUP3_BUSCLK_CANx = FL_CMU_GROUP3_BUSCLK_FSCAN;
            break;
        default:
            return -1;
    }
    
    /* 反初始化 CAN Rx引脚 */
    FL_GPIO_DeInit(GPIOA, FL_GPIO_PIN_6); 
    /* 反初始化 CAN Tx引脚 */
    FL_GPIO_DeInit(GPIOA, FL_GPIO_PIN_7); 
    /* 反初始化 CAN收发模块引脚 */
    FL_GPIO_DeInit(GPIOB, FL_GPIO_PIN_4); 
    
    /* 禁止中断 */
    NVIC_ClearPendingIRQ(CAN_IRQ);
    NVIC_DisableIRQ(CAN_IRQ);
    
    /* 使能外设复位 */
    FL_RMU_EnablePeripheralReset(RMU);
    /* 复位CAN控制器外设寄存器 */
    FL_RMU_EnableResetAPBPeripheral(RMU, u32RMU_RSTAPB_CANx);
    FL_RMU_DisableResetAPBPeripheral(RMU, u32RMU_RSTAPB_CANx);
    /* 关闭外设工作时钟 */
    FL_CMU_DisableOperationClock(u32CMU_OPCLK_CANx);
    /* 禁止关闭外设总线时钟，以确保软件对CAN外设的正常访问 */
    FL_CMU_EnableGroup3BusClock(u32CMU_GROUP3_BUSCLK_CANx); 
    /* 锁定外设复位 */
    FL_RMU_DisablePeripheralReset(RMU);
    return 0;
}


/* 通过TX Buffer发送数据 */
void FL_CAN_BUFFER_Write(uint32_t id, uint32_t len, uint32_t data1, uint32_t data2, CAN_Type *CANx, uint32_t buffer_Chl)
{
    uint32_t counter =0;
    uint32_t TXBufferEmpty;
    /* buffer空闲才能继续写buffer */
    do
    {
        TXBufferEmpty = FL_CAN_IsActiveFlag_TXBufferEmpty(CANx, buffer_Chl);
        counter++;
    }
    while((0x01U != TXBufferEmpty) && (counter != CAN_TIMEOUT));

    FL_CAN_WriteTXMessageID(CANx, id, buffer_Chl);
    FL_CAN_WriteTXMessageLength(CANx, len, buffer_Chl);
    FL_CAN_WriteTXMessageWord1(CANx, data1, buffer_Chl);
    FL_CAN_WriteTXMessageWord2(CANx, data2, buffer_Chl); 
    FL_CAN_ClearFlag_TXBufferEmpty(CANx, buffer_Chl);   /* 使能发送 */
}


/* RX FIFO数据 */
void FL_CAN_FIFO_Read(CAN_Type *CANx)
{
    uint32_t data1;
    uint32_t data2;

    /* ID需基于消息帧存储和消息帧结构进行二次解析 */
    RxMessage.StdId = (uint32_t)FL_CAN_ReadRXMessageID(CANx);
    RxMessage.DLC = (uint8_t)FL_CAN_ReadRXMessageLength(CANx);

    data1 = FL_CAN_ReadRXMessageWord1(CANx);
    data2 = FL_CAN_ReadRXMessageWord2(CANx);

    RxMessage.Data[0] = (uint8_t)(data1 & 0xFFU);
    RxMessage.Data[1] = (uint8_t)((data1 >> 8) & 0xFFU);
    RxMessage.Data[2] = (uint8_t)((data1 >> 16) & 0xFFU);
    RxMessage.Data[3] = (uint8_t)((data1 >> 24) & 0xFFU);
    RxMessage.Data[4] = (uint8_t)(data2 & 0xFFU);
    RxMessage.Data[5] = (uint8_t)((data2 >> 8) & 0xFFU);
    RxMessage.Data[6] = (uint8_t)((data2 >> 16) & 0xFFU);
    RxMessage.Data[7] = (uint8_t)((data2 >> 24) & 0xFFU);
    
    if (RxMessage.Data[0] == 0x68){
        LED0_ON();
        FL_DelayMs(1000);
        LED0_OFF();
      }
}


uint8_t Data1[8] = {0x68, 0x34, 0x55, 0xaa, 0x67, 0x36, 0x58, 0x16}; /* 要发送的数据 */
/* 数据发送设置 */
void CAN_SetMsg(CanTxMsg *TxMesg)
{
    uint8_t ubCounter;

    TxMesg->StdId = 0x6AD;                 /* 使用标准ID */
    TxMesg->DLC = 8;                       /* 数据长度为8字节 */

    /* 设置要发送的数据0-7 */
    for(ubCounter = 0; ubCounter < 8; ubCounter++)
    {
        TxMesg->Data[ubCounter] = Data1[ubCounter];
    }
}


/* 帧模式选择 */
void FL_CAN_Frame_Send(uint32_t frame_format, CanTxMsg *TxMesg, CAN_Type *CANx, uint32_t buffer_Chl)
{
    uint32_t id ;
    uint32_t len;
    uint32_t data1;
    uint32_t data2;

    if(frame_format == FL_CAN_FORMAT_STANDARD_DATA) /* 标准数据帧 */
    {
        id = TxMesg->StdId & 0x7FFU;
    }
    else if(frame_format == FL_CAN_FORMAT_STANDARD_REMOTE) /* 标准远程帧 */
    {
        id = (TxMesg->StdId & 0x7FFU) | (0x01U << 11);
    }
    else if(frame_format == FL_CAN_FORMAT_EXTEND_DATA) /* 扩展数据帧 */
    {
        id = ((TxMesg->ExtId & 0x3FFFFU) << 13) | (0x01U << 12) | (0x01U << 11) | ((TxMesg->ExtId & 0x1FFC0000U) >> 18);
    }
    else /* 扩展远程帧 */
    {
        id = ((TxMesg->ExtId & 0x3FFFFU) << 13) | ( 0x01U << 12)| (0x01U << 11) | ( 0x01U << 31) | ((TxMesg->ExtId & 0x1FFC0000U) >> 18);
    }

    len = TxMesg->DLC;
    data1 = (((uint32_t)TxMesg->Data[3] << 24) |\
             ((uint32_t)TxMesg->Data[2] << 16) |\
             ((uint32_t)TxMesg->Data[1] << 8) |\
             ((uint32_t)TxMesg->Data[0]));
    data2 = (((uint32_t)TxMesg->Data[7] << 24) |\
             ((uint32_t)TxMesg->Data[6] << 16) |\
             ((uint32_t)TxMesg->Data[5] << 8) |\
             ((uint32_t)TxMesg->Data[4]));             

    FL_CAN_BUFFER_Write(id, len, data1, data2, CANx, buffer_Chl);
}
