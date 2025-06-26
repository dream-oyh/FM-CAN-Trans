/**
  ******************************************************************************
  * @file      startup_fm33fg0xxa.S
  * @author
  * @brief     FM33FG0xxA devices vector table for GCC toolchain.
  *            This module performs:
  *                - Set the initial SP
  *                - Set the initial PC == Reset_Handler,
  *                - Set the vector table entries with the exceptions ISR address
  *                - Branches to main in the C library (which eventually
  *                  calls main()).
  *            After Reset the Cortex-M0+ processor is in Thread mode,
  *            priority is Privileged, and the Stack is set to Main.
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
  ******************************************************************************
  */

  .syntax unified
  .cpu cortex-m0plus
  .fpu softvfp
  .thumb

.global  g_pfnVectors
.global  Default_Handler

/* start address for the initialization values of the .data section.
defined in linker script */
.word  _sidata
/* start address for the .data section. defined in linker script */
.word  _sdata
/* end address for the .data section. defined in linker script */
.word  _edata
/* start address for the .bss section. defined in linker script */
.word  _sbss
/* end address for the .bss section. defined in linker script */
.word  _ebss

  .section  .text.Reset_Handler
  .weak  Reset_Handler
  .type  Reset_Handler, %function
Reset_Handler:
  ldr   r0, =_estack
  mov   sp, r0          /* set stack pointer */

/* Initialisation based on RAM space */
  ldr   R0, =0x1FFFFB04 /* LDT0 VOLCFG*/
  ldr   R1, [R0]
  ldr   R2, =0x00FF00FF
  ands  R1, R1, R2
  ldr   R2, =0x20010000 /* 64k RAM */
  ldr   R3, =0x00AA0055
  cmp   R1, R3
  bne   StartFillZeroRAM
  ldr   R2, =0x20008000 /* 32k RAM */
StartFillZeroRAM:
  ldr   R1, =0x20000000
  movs  R3, #0
  b     LoopFillZeroRAM
FillZeroRAM:
  str   R3, [R1]
  adds  R1, R1, #4
LoopFillZeroRAM:
  cmp   R1, R2
  bcc   FillZeroRAM
/* Initialisation RAM end */

/* Copy the data segment initializers from flash to SRAM */
  movs  r1, #0
  b  LoopCopyDataInit

CopyDataInit:
  ldr  r3, =_sidata
  ldr  r3, [r3, r1]
  str  r3, [r0, r1]
  adds  r1, r1, #4

LoopCopyDataInit:
  ldr  r0, =_sdata
  ldr  r3, =_edata
  adds  r2, r0, r1
  cmp  r2, r3
  bcc  CopyDataInit
  ldr  r2, =_sbss
  b  LoopFillZerobss
/* Zero fill the bss segment. */
FillZerobss:
  movs  r3, #0
  str  r3, [r2]
  adds r2, r2, #4

LoopFillZerobss:
  ldr  r3, = _ebss
  cmp  r2, r3
  bcc  FillZerobss

/* Call the clock system intitialization function.*/
  bl  SystemInit
/* Call static constructors */
  bl __libc_init_array
/* Call the application's entry point.*/
  bl  main

LoopForever:
  b LoopForever

.size  Reset_Handler, .-Reset_Handler

/**
 * @brief  This is the code that gets called when the processor receives an
 *         unexpected interrupt.  This simply enters an infinite loop, preserving
 *         the system state for examination by a debugger.
 *
 * @param  None
 * @retval : None
*/
  .section  .text.Default_Handler,"ax",%progbits
Default_Handler:
Infinite_Loop:
  b  Infinite_Loop
  .size  Default_Handler, .-Default_Handler
/******************************************************************************
*
* The minimal vector table for a Cortex M0.  Note that the proper constructs
* must be placed on this to ensure that it ends up at physical address
* 0x0000.0000.
*
******************************************************************************/
  .section  .isr_vector,"a",%progbits
  .type  g_pfnVectors, %object
  .size  g_pfnVectors, .-g_pfnVectors


g_pfnVectors:
  .word  _estack
  .word  Reset_Handler
  .word  NMI_Handler
  .word  HardFault_Handler
  .word  0
  .word  0
  .word  0
  .word  0
  .word  0
  .word  0
  .word  0
  .word  SVC_Handler
  .word  0
  .word  0
  .word  PendSV_Handler
  .word  SysTick_Handler
  /* External Interrupts */
  .word  WDT_IRQHandler                       /* 0:  WWDT           */
  .word  SVD_IRQHandler                       /* 1:  SVD            */
  .word  RTC_IRQHandler                       /* 2:  RTC            */
  .word  CANFD0_IRQHandler                    /* 3:  CANFD0         */
  .word  CANFD1_IRQHandler                    /* 4:  CANFD1         */
  .word  ADC_IRQHandler                       /* 5:  ADC            */
  .word  FSCAN_IRQHandler                     /* 6:  FSCAN          */
  .word  UART0_IRQHandler                     /* 7:  UART0          */
  .word  UART1_IRQHandler                     /* 8:  UART1          */
  .word  UART2_IRQHandler                     /* 9:  UART2          */
  .word  UART3_IRQHandler                     /* 10: UART3          */
  .word  UART4_UART5_IRQHandler               /* 11: UART4_UART5    */
  .word  I2CMX_IRQHandler                     /* 12: I2CMX          */
  .word  SPI0_IRQHandler                      /* 13: SPI0           */
  .word  SPI1_IRQHandler                      /* 14: SPI1           */
  .word  SPI2_IRQHandler                      /* 15: SPI2           */
  .word  SPI3_IRQHandler                      /* 16: SPI3           */
  .word  I2C_SMBX_IRQHandler                  /* 17: I2C_SMBX       */
  .word  SENTX_IRQHandler                     /* 18: SENTX          */
  .word  AES_IRQHandler                       /* 19: AES            */
  .word  LPTIM_BSTIM_IRQHandler               /* 20: LPTIM_BSTIM    */
  .word  DMA_IRQHandler                       /* 21: DMA            */
  .word  WKUPX_IRQHandler                     /* 22: WKUPX          */
  .word  TAU_PGL_IRQHandler                   /* 23: TAU_PGL        */
  .word  GPTIMX_IRQHandler                    /* 24: GPTIMX         */
  .word  COMPX_IRQHandler                     /* 25: COMPX          */
  .word  CLMX_IRQHandler                      /* 26: CLMX           */
  .word  NVMIF_IRQHandler                     /* 27: NVMIF          */
  .word  ATIM_IRQHandler                      /* 28: ATIM           */
  .word  LPUART_IRQHandler                    /* 29: LPUART         */
  .word  EXTI_DAC_IRQHandler                  /* 30: EXTI_DAC       */
  .word  ECCC_RAMP_FDET_IRQHandler            /* 31: ECCC_RAMP_FDET */

/*******************************************************************************
*
* Provide weak aliases for each Exception handler to the Default_Handler.
* As they are weak aliases, any function with the same name will override
* this definition.
*
*******************************************************************************/
   .weak      NMI_Handler
   .thumb_set NMI_Handler,Default_Handler

   .weak      HardFault_Handler
   .thumb_set HardFault_Handler,Default_Handler

   .weak      SVC_Handler
   .thumb_set SVC_Handler,Default_Handler

   .weak      PendSV_Handler
   .thumb_set PendSV_Handler,Default_Handler

   .weak      SysTick_Handler
   .thumb_set SysTick_Handler,Default_Handler




   .weak      WDT_IRQHandler
   .thumb_set WDT_IRQHandler,Default_Handler

   .weak      SVD_IRQHandler
   .thumb_set SVD_IRQHandler,Default_Handler

   .weak      RTC_IRQHandler
   .thumb_set RTC_IRQHandler,Default_Handler

   .weak      CANFD0_IRQHandler
   .thumb_set CANFD0_IRQHandler,Default_Handler

   .weak      CANFD1_IRQHandler
   .thumb_set CANFD1_IRQHandler,Default_Handler

   .weak      ADC_IRQHandler
   .thumb_set ADC_IRQHandler,Default_Handler

   .weak      FSCAN_IRQHandler
   .thumb_set FSCAN_IRQHandler,Default_Handler

   .weak      UART0_IRQHandler
   .thumb_set UART0_IRQHandler,Default_Handler

   .weak      UART1_IRQHandler
   .thumb_set UART1_IRQHandler,Default_Handler

   .weak      UART2_IRQHandler
   .thumb_set UART2_IRQHandler,Default_Handler

   .weak      UART3_IRQHandler
   .thumb_set UART3_IRQHandler,Default_Handler

   .weak      UART4_UART5_IRQHandler
   .thumb_set UART4_UART5_IRQHandler,Default_Handler

   .weak      I2CMX_IRQHandler
   .thumb_set I2CMX_IRQHandler,Default_Handler

   .weak      SPI0_IRQHandler
   .thumb_set SPI0_IRQHandler,Default_Handler

   .weak      SPI1_IRQHandler
   .thumb_set SPI1_IRQHandler,Default_Handler

   .weak      SPI2_IRQHandler
   .thumb_set SPI2_IRQHandler,Default_Handler

   .weak      SPI3_IRQHandler
   .thumb_set SPI3_IRQHandler,Default_Handler

   .weak      I2C_SMBX_IRQHandler
   .thumb_set I2C_SMBX_IRQHandler,Default_Handler

   .weak      SENTX_IRQHandler
   .thumb_set SENTX_IRQHandler,Default_Handler

   .weak      AES_IRQHandler
   .thumb_set AES_IRQHandler,Default_Handler

   .weak      LPTIM_BSTIM_IRQHandler
   .thumb_set LPTIM_BSTIM_IRQHandler,Default_Handler

   .weak      DMA_IRQHandler
   .thumb_set DMA_IRQHandler,Default_Handler

   .weak      WKUPX_IRQHandler
   .thumb_set WKUPX_IRQHandler,Default_Handler

   .weak      TAU_PGL_IRQHandler
   .thumb_set TAU_PGL_IRQHandler,Default_Handler

   .weak      GPTIMX_IRQHandler
   .thumb_set GPTIMX_IRQHandler,Default_Handler

   .weak      COMPX_IRQHandler
   .thumb_set COMPX_IRQHandler,Default_Handler

   .weak      CLMX_IRQHandler
   .thumb_set CLMX_IRQHandler,Default_Handler

   .weak      NVMIF_IRQHandler
   .thumb_set NVMIF_IRQHandler,Default_Handler

   .weak      ATIM_IRQHandler
   .thumb_set ATIM_IRQHandler,Default_Handler
   
   .weak      LPUART_IRQHandler
   .thumb_set LPUART_IRQHandler,Default_Handler

   .weak      EXTI_DAC_IRQHandler
   .thumb_set EXTI_DAC_IRQHandler,Default_Handler
   
   .weak      ECCC_RAMP_FDET_IRQHandler
   .thumb_set ECCC_RAMP_FDET_IRQHandler,Default_Handler

/*****************************END OF FILE**************************************/
