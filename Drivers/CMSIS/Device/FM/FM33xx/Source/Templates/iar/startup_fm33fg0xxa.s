
        MODULE  ?cstartup

        ;; Forward declaration of sections.
        SECTION CSTACK:DATA:NOROOT(3)

        SECTION .intvec:CODE:NOROOT(2)

        EXTERN  __iar_program_start
        PUBLIC  __vector_table

        DATA
        
__vector_table
        DCD     sfe(CSTACK)
        DCD     Reset_Handler             ; Reset Handler
        DCD     NMI_Handler               ; NMI Handler
        DCD     HardFault_Handler         ; Hard Fault Handler
        DCD     0                         ; Reserved
        DCD     0                         ; Reserved
        DCD     0                         ; Reserved
        DCD     0                         ; Reserved
        DCD     0                         ; Reserved
        DCD     0                         ; Reserved
        DCD     0                         ; Reserved
        DCD     SVC_Handler               ; SVCall Handler
        DCD     0                         ; Reserved
        DCD     0                         ; Reserved
        DCD     PendSV_Handler            ; PendSV Handler
        DCD     SysTick_Handler           ; SysTick Handler

        ; External Interrupts
        DCD     WDT_IRQHandler            ; 0:  WDT
        DCD     SVD_IRQHandler            ; 1:  SVD
        DCD     RTC_IRQHandler            ; 2:  RTC
        DCD     CANFD0_IRQHandler         ; 3:  CANFD0
        DCD     CANFD1_IRQHandler         ; 4:  CANFD1
        DCD     ADC_IRQHandler            ; 5:  ADC
        DCD     FSCAN_IRQHandler          ; 6:  FSCAN
        DCD     UART0_IRQHandler          ; 7:  UART0
        DCD     UART1_IRQHandler          ; 8:  UART1
        DCD     UART2_IRQHandler          ; 9:  UART2
        DCD     UART3_IRQHandler          ; 10: UART3
        DCD     UART4_UART5_IRQHandler    ; 11: UART4_UART5
        DCD     I2CMX_IRQHandler          ; 12: I2CMX
        DCD     SPI0_IRQHandler           ; 13: SPI0
        DCD     SPI1_IRQHandler           ; 14: SPI1
        DCD     SPI2_IRQHandler           ; 15: SPI2
        DCD     SPI3_IRQHandler           ; 16: SPI3
        DCD     I2C_SMBX_IRQHandler       ; 17: I2C_SMBX
        DCD     SENTX_IRQHandler          ; 18: SENTX
        DCD     AES_IRQHandler            ; 19: AES
        DCD     LPTIM_BSTIM_IRQHandler    ; 20: LPTIM_BSTIM
        DCD     DMA_IRQHandler            ; 21: DMA
        DCD     WKUPX_IRQHandler          ; 22: WKUPX
        DCD     TAU_PGL_IRQHandler        ; 23: TAU_PGL
        DCD     GPTIMX_IRQHandler         ; 24: GPTIMX
        DCD     COMPX_IRQHandler          ; 25: COMPX
        DCD     CLMX_IRQHandler           ; 26: CLMX
        DCD     NVMIF_IRQHandler          ; 27: NVMIF
        DCD     ATIM_IRQHandler           ; 28: ATIM
        DCD     LPUART_IRQHandler         ; 29: LPUART
        DCD     EXTI_DAC_IRQHandler       ; 30: EXTI_DAC
        DCD     ECCC_RAMP_FDET_IRQHandler ; 31: ECCC_RAMP_FDET
__Vectors_End
                
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;
;; Default interrupt handlers.
;;
        THUMB

        PUBWEAK Reset_Handler
        SECTION .text:CODE:NOROOT:REORDER(2)
Reset_Handler
        IMPORT  SystemInit

        LDR     R0, =0x1FFFFB04
        LDR     R1, [R0]
        LDR     R2, =0x00FF00FF
        ANDS    R1, R1, R2
        LDR     R2, =0x20010000
        LDR     R3, =0x00AA0055
        CMP     R1, R3
        BNE     StartFillZeroRAM
        LDR     R2, =0x20008000
StartFillZeroRAM
        LDR     R1, =0x20000000
        MOVS    R3, #0
        B       LoopFillZeroRAM
FillZeroRAM
        STR     R3, [R1]
        ADDS    R1, R1, #4
LoopFillZeroRAM
        CMP     R1, R2
        BCC     FillZeroRAM

        LDR     R0, =SystemInit
        BLX     R0
        LDR     R0, =__iar_program_start
        ;LDR     R0, =__main
        BX      R0
        
        PUBWEAK NMI_Handler
        SECTION .text:CODE:NOROOT:REORDER(1)
NMI_Handler
        B NMI_Handler
        
        
        PUBWEAK HardFault_Handler
        SECTION .text:CODE:NOROOT:REORDER(1)
HardFault_Handler
        B HardFault_Handler
       
        
        PUBWEAK SVC_Handler
        SECTION .text:CODE:NOROOT:REORDER(1)
SVC_Handler
        B SVC_Handler
        
        
        PUBWEAK PendSV_Handler
        SECTION .text:CODE:NOROOT:REORDER(1)
PendSV_Handler  
        B PendSV_Handler
        
        
        PUBWEAK SysTick_Handler
        SECTION .text:CODE:NOROOT:REORDER(1)
SysTick_Handler
        B SysTick_Handler
        
        
        PUBWEAK WDT_IRQHandler
        SECTION .text:CODE:NOROOT:REORDER(1)
WDT_IRQHandler
        B WDT_IRQHandler
        
                
        PUBWEAK SVD_IRQHandler
        SECTION .text:CODE:NOROOT:REORDER(1)
SVD_IRQHandler
        B SVD_IRQHandler
        
                
        PUBWEAK RTC_IRQHandler
        SECTION .text:CODE:NOROOT:REORDER(1)
RTC_IRQHandler
        B RTC_IRQHandler
        
                
        PUBWEAK CANFD0_IRQHandler
        SECTION .text:CODE:NOROOT:REORDER(1)
CANFD0_IRQHandler
        B CANFD0_IRQHandler
        
                
        PUBWEAK CANFD1_IRQHandler
        SECTION .text:CODE:NOROOT:REORDER(1)
CANFD1_IRQHandler
        B CANFD1_IRQHandler
        
                
        PUBWEAK ADC_IRQHandler
        SECTION .text:CODE:NOROOT:REORDER(1)
ADC_IRQHandler
        B ADC_IRQHandler
  
        PUBWEAK FSCAN_IRQHandler
        SECTION .text:CODE:NOROOT:REORDER(1)
FSCAN_IRQHandler
        B FSCAN_IRQHandler
       
       
        PUBWEAK UART0_IRQHandler
        SECTION .text:CODE:NOROOT:REORDER(1)
UART0_IRQHandler
        B UART0_IRQHandler
        

        PUBWEAK UART1_IRQHandler
        SECTION .text:CODE:NOROOT:REORDER(1)
UART1_IRQHandler
        B UART1_IRQHandler
        
                                
        PUBWEAK UART2_IRQHandler
        SECTION .text:CODE:NOROOT:REORDER(1)
UART2_IRQHandler
        B UART2_IRQHandler
        
                
        PUBWEAK UART3_IRQHandler
        SECTION .text:CODE:NOROOT:REORDER(1)
UART3_IRQHandler
        B UART3_IRQHandler
        
                
        PUBWEAK UART4_UART5_IRQHandler
        SECTION .text:CODE:NOROOT:REORDER(1)
UART4_UART5_IRQHandler
        B UART4_UART5_IRQHandler
        
                
        PUBWEAK I2CMX_IRQHandler
        SECTION .text:CODE:NOROOT:REORDER(1)
I2CMX_IRQHandler
        B I2CMX_IRQHandler
        
                
        PUBWEAK SPI0_IRQHandler
        SECTION .text:CODE:NOROOT:REORDER(1)
SPI0_IRQHandler
        B SPI0_IRQHandler
        
                
        PUBWEAK SPI1_IRQHandler
        SECTION .text:CODE:NOROOT:REORDER(1)
SPI1_IRQHandler
        B SPI1_IRQHandler
        
                 
        PUBWEAK SPI2_IRQHandler
        SECTION .text:CODE:NOROOT:REORDER(1)
SPI2_IRQHandler
        B SPI2_IRQHandler
        
                 
        PUBWEAK SPI3_IRQHandler
        SECTION .text:CODE:NOROOT:REORDER(1)
SPI3_IRQHandler
        B SPI3_IRQHandler
        
                
        PUBWEAK I2C_SMBX_IRQHandler
        SECTION .text:CODE:NOROOT:REORDER(1)
I2C_SMBX_IRQHandler
        B I2C_SMBX_IRQHandler
        
        PUBWEAK SENTX_IRQHandler
        SECTION .text:CODE:NOROOT:REORDER(1)
SENTX_IRQHandler
        B SENTX_IRQHandler
        
                
        PUBWEAK AES_IRQHandler
        SECTION .text:CODE:NOROOT:REORDER(1)
AES_IRQHandler
        B AES_IRQHandler
                  
                  
        PUBWEAK LPTIM_BSTIM_IRQHandler
        SECTION .text:CODE:NOROOT:REORDER(1)
LPTIM_BSTIM_IRQHandler
        B LPTIM_BSTIM_IRQHandler
                
                
        PUBWEAK DMA_IRQHandler
        SECTION .text:CODE:NOROOT:REORDER(1)
DMA_IRQHandler
        B DMA_IRQHandler
        
        
        PUBWEAK WKUPX_IRQHandler
        SECTION .text:CODE:NOROOT:REORDER(1)
WKUPX_IRQHandler
        B WKUPX_IRQHandler
   
   
        PUBWEAK TAU_PGL_IRQHandler
        SECTION .text:CODE:NOROOT:REORDER(1)
TAU_PGL_IRQHandler
        B TAU_PGL_IRQHandler


        PUBWEAK GPTIMX_IRQHandler
        SECTION .text:CODE:NOROOT:REORDER(1)
GPTIMX_IRQHandler
        B GPTIMX_IRQHandler 
      
      
        PUBWEAK COMPX_IRQHandler
        SECTION .text:CODE:NOROOT:REORDER(1)
COMPX_IRQHandler
        B COMPX_IRQHandler



        PUBWEAK CLMX_IRQHandler
        SECTION .text:CODE:NOROOT:REORDER(1)
CLMX_IRQHandler
        B CLMX_IRQHandler
        
                
        PUBWEAK NVMIF_IRQHandler
        SECTION .text:CODE:NOROOT:REORDER(1)
NVMIF_IRQHandler
        B NVMIF_IRQHandler
               
        
        
        PUBWEAK ATIM_IRQHandler
        SECTION .text:CODE:NOROOT:REORDER(1)
ATIM_IRQHandler
        B ATIM_IRQHandler
         
         
        PUBWEAK LPUART_IRQHandler
        SECTION .text:CODE:NOROOT:REORDER(1)
LPUART_IRQHandler
        B LPUART_IRQHandler
        
        
         PUBWEAK EXTI_DAC_IRQHandler
        SECTION .text:CODE:NOROOT:REORDER(1)
EXTI_DAC_IRQHandler
        B EXTI_DAC_IRQHandler
        
        
         PUBWEAK ECCC_RAMP_FDET_IRQHandler
        SECTION .text:CODE:NOROOT:REORDER(1)
ECCC_RAMP_FDET_IRQHandler
        B ECCC_RAMP_FDET_IRQHandler
        END