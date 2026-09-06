/****************************************************************************
 * arch/arm/include/mcxa1xx/mcxa156_irq.h
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Licensed to the Apache Software Foundation (ASF) under one or more
 * contributor license agreements.  See the NOTICE file distributed with
 * this work for additional information regarding copyright ownership.  The
 * ASF licenses this file to you under the Apache License, Version 2.0 (the
 * "License"); you may not use this file except in compliance with the
 * License.  You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS, WITHOUT
 * WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.  See the
 * License for the specific language governing permissions and limitations
 * under the License.
 *
 ****************************************************************************/

/* This file should never be included directly but, rather,
 * only indirectly through nuttx/irq.h
 */

#ifndef __ARCH_ARM_INCLUDE_MCXA1XX_MCXA156_IRQ_H
#define __ARCH_ARM_INCLUDE_MCXA1XX_MCXA156_IRQ_H

/****************************************************************************
 * Pre-processor Definitions
 ****************************************************************************/

/* External interrupts (vectors >= 16).
 *
 * Transcribed mechanically from the IRQn_Type enumeration in NXP's
 * devices/MCXA156/MCXA156.h (mcux-sdk) so the numbering cannot drift from
 * the vendor definition.
 */

#define MCXA156_IRQ_Reserved16             (MCXA1XX_IRQ_EXTINT +  0) /* OR IRQ1 to IRQ53 */
#define MCXA156_IRQ_CMC                    (MCXA1XX_IRQ_EXTINT +  1) /* Core Mode Controller interrupt */
#define MCXA156_IRQ_DMA_CH0                (MCXA1XX_IRQ_EXTINT +  2) /* DMA3_0_CH0 error or transfer complete */
#define MCXA156_IRQ_DMA_CH1                (MCXA1XX_IRQ_EXTINT +  3) /* DMA3_0_CH1 error or transfer complete */
#define MCXA156_IRQ_DMA_CH2                (MCXA1XX_IRQ_EXTINT +  4) /* DMA3_0_CH2 error or transfer complete */
#define MCXA156_IRQ_DMA_CH3                (MCXA1XX_IRQ_EXTINT +  5) /* DMA3_0_CH3 error or transfer complete */
#define MCXA156_IRQ_DMA_CH4                (MCXA1XX_IRQ_EXTINT +  6) /* DMA3_0_CH4 error or transfer complete */
#define MCXA156_IRQ_DMA_CH5                (MCXA1XX_IRQ_EXTINT +  7) /* DMA3_0_CH5 error or transfer complete */
#define MCXA156_IRQ_DMA_CH6                (MCXA1XX_IRQ_EXTINT +  8) /* DMA3_0_CH6 error or transfer complete */
#define MCXA156_IRQ_DMA_CH7                (MCXA1XX_IRQ_EXTINT +  9) /* DMA3_0_CH7 error or transfer complete */
#define MCXA156_IRQ_ERM0_SINGLE_BIT        (MCXA1XX_IRQ_EXTINT + 10) /* ERM Single Bit error interrupt */
#define MCXA156_IRQ_ERM0_MULTI_BIT         (MCXA1XX_IRQ_EXTINT + 11) /* ERM Multi Bit error interrupt */
#define MCXA156_IRQ_FMU0                   (MCXA1XX_IRQ_EXTINT + 12) /* Flash Management Unit interrupt */
#define MCXA156_IRQ_GLIKEY0                (MCXA1XX_IRQ_EXTINT + 13) /* GLIKEY Interrupt */
#define MCXA156_IRQ_MBC0                   (MCXA1XX_IRQ_EXTINT + 14) /* MBC secure violation interrupt */
#define MCXA156_IRQ_SCG0                   (MCXA1XX_IRQ_EXTINT + 15) /* System Clock Generator interrupt */
#define MCXA156_IRQ_SPC0                   (MCXA1XX_IRQ_EXTINT + 16) /* System Power Controller interrupt */
#define MCXA156_IRQ_VBAT0                  (MCXA1XX_IRQ_EXTINT + 17) /* VBAT interrupt */
#define MCXA156_IRQ_WUU0                   (MCXA1XX_IRQ_EXTINT + 18) /* Wake Up Unit interrupt */
#define MCXA156_IRQ_CAN0                   (MCXA1XX_IRQ_EXTINT + 19) /* Controller Area Network 0 interrupt */
#define MCXA156_IRQ_Reserved36             (MCXA1XX_IRQ_EXTINT + 20) /* Reserved interrupt */
#define MCXA156_IRQ_Reserved37             (MCXA1XX_IRQ_EXTINT + 21) /* Reserved interrupt */
#define MCXA156_IRQ_Reserved38             (MCXA1XX_IRQ_EXTINT + 22) /* Reserved interrupt */
#define MCXA156_IRQ_FLEXIO                 (MCXA1XX_IRQ_EXTINT + 23) /* Flexible Input/Output interrupt */
#define MCXA156_IRQ_I3C0                   (MCXA1XX_IRQ_EXTINT + 24) /* Improved Inter Integrated Circuit interrupt 0 */
#define MCXA156_IRQ_Reserved41             (MCXA1XX_IRQ_EXTINT + 25) /* Reserved interrupt */
#define MCXA156_IRQ_LPI2C0                 (MCXA1XX_IRQ_EXTINT + 26) /* Low-Power Inter Integrated Circuit interrupt */
#define MCXA156_IRQ_LPI2C1                 (MCXA1XX_IRQ_EXTINT + 27) /* Low-Power Inter Integrated Circuit interrupt */
#define MCXA156_IRQ_LPSPI0                 (MCXA1XX_IRQ_EXTINT + 28) /* Low-Power Serial Peripheral Interface interrupt */
#define MCXA156_IRQ_LPSPI1                 (MCXA1XX_IRQ_EXTINT + 29) /* Low-Power Serial Peripheral Interface interrupt */
#define MCXA156_IRQ_Reserved46             (MCXA1XX_IRQ_EXTINT + 30) /* Reserved interrupt */
#define MCXA156_IRQ_LPUART0                (MCXA1XX_IRQ_EXTINT + 31) /* Low-Power Universal Asynchronous Receive/Transmit interrupt */
#define MCXA156_IRQ_LPUART1                (MCXA1XX_IRQ_EXTINT + 32) /* Low-Power Universal Asynchronous Receive/Transmit interrupt */
#define MCXA156_IRQ_LPUART2                (MCXA1XX_IRQ_EXTINT + 33) /* Low-Power Universal Asynchronous Receive/Transmit interrupt */
#define MCXA156_IRQ_LPUART3                (MCXA1XX_IRQ_EXTINT + 34) /* Low-Power Universal Asynchronous Receive/Transmit interrupt */
#define MCXA156_IRQ_LPUART4                (MCXA1XX_IRQ_EXTINT + 35) /* Low-Power Universal Asynchronous Receive/Transmit interrupt */
#define MCXA156_IRQ_USB0                   (MCXA1XX_IRQ_EXTINT + 36) /* Universal Serial Bus - Full Speed interrupt */
#define MCXA156_IRQ_Reserved53             (MCXA1XX_IRQ_EXTINT + 37) /* Reserved interrupt */
#define MCXA156_IRQ_CDOG0                  (MCXA1XX_IRQ_EXTINT + 38) /* Code Watchdog Timer 0 interrupt */
#define MCXA156_IRQ_CTIMER0                (MCXA1XX_IRQ_EXTINT + 39) /* Standard counter/timer 0 interrupt */
#define MCXA156_IRQ_CTIMER1                (MCXA1XX_IRQ_EXTINT + 40) /* Standard counter/timer 1 interrupt */
#define MCXA156_IRQ_CTIMER2                (MCXA1XX_IRQ_EXTINT + 41) /* Standard counter/timer 2 interrupt */
#define MCXA156_IRQ_CTIMER3                (MCXA1XX_IRQ_EXTINT + 42) /* Standard counter/timer 3 interrupt */
#define MCXA156_IRQ_CTIMER4                (MCXA1XX_IRQ_EXTINT + 43) /* Standard counter/timer 4 interrupt */
#define MCXA156_IRQ_FLEXPWM0_RELOAD_ERROR  (MCXA1XX_IRQ_EXTINT + 44) /* FlexPWM0_reload_error interrupt */
#define MCXA156_IRQ_FLEXPWM0_FAULT         (MCXA1XX_IRQ_EXTINT + 45) /* FlexPWM0_fault interrupt */
#define MCXA156_IRQ_FLEXPWM0_SUBMODULE0    (MCXA1XX_IRQ_EXTINT + 46) /* FlexPWM0 Submodule 0 capture/compare/reload interrupt */
#define MCXA156_IRQ_FLEXPWM0_SUBMODULE1    (MCXA1XX_IRQ_EXTINT + 47) /* FlexPWM0 Submodule 1 capture/compare/reload interrupt */
#define MCXA156_IRQ_FLEXPWM0_SUBMODULE2    (MCXA1XX_IRQ_EXTINT + 48) /* FlexPWM0 Submodule 2 capture/compare/reload interrupt */
#define MCXA156_IRQ_Reserved65             (MCXA1XX_IRQ_EXTINT + 49) /* Reserved interrupt */
#define MCXA156_IRQ_QDC0_COMPARE           (MCXA1XX_IRQ_EXTINT + 50) /* Compare */
#define MCXA156_IRQ_QDC0_HOME              (MCXA1XX_IRQ_EXTINT + 51) /* Home */
#define MCXA156_IRQ_QDC0_WATCHDOG          (MCXA1XX_IRQ_EXTINT + 52) /* Watchdog / Simultaneous A and B Change */
#define MCXA156_IRQ_QDC0_INDEX             (MCXA1XX_IRQ_EXTINT + 53) /* Index / Roll Over / Roll Under */
#define MCXA156_IRQ_FREQME0                (MCXA1XX_IRQ_EXTINT + 54) /* Frequency Measurement interrupt */
#define MCXA156_IRQ_LPTMR0                 (MCXA1XX_IRQ_EXTINT + 55) /* Low Power Timer 0 interrupt */
#define MCXA156_IRQ_Reserved72             (MCXA1XX_IRQ_EXTINT + 56) /* Reserved interrupt */
#define MCXA156_IRQ_OS_EVENT               (MCXA1XX_IRQ_EXTINT + 57) /* OS event timer interrupt */
#define MCXA156_IRQ_WAKETIMER0             (MCXA1XX_IRQ_EXTINT + 58) /* Wake Timer Interrupt */
#define MCXA156_IRQ_UTICK0                 (MCXA1XX_IRQ_EXTINT + 59) /* Micro-Tick Timer interrupt */
#define MCXA156_IRQ_WWDT0                  (MCXA1XX_IRQ_EXTINT + 60) /* Windowed Watchdog Timer 0 interrupt */
#define MCXA156_IRQ_Reserved77             (MCXA1XX_IRQ_EXTINT + 61) /* Reserved interrupt */
#define MCXA156_IRQ_ADC0                   (MCXA1XX_IRQ_EXTINT + 62) /* Analog-to-Digital Converter interrupt */
#define MCXA156_IRQ_ADC1                   (MCXA1XX_IRQ_EXTINT + 63) /* Analog-to-Digital Converter interrupt */
#define MCXA156_IRQ_CMP0                   (MCXA1XX_IRQ_EXTINT + 64) /* Comparator interrupt */
#define MCXA156_IRQ_CMP1                   (MCXA1XX_IRQ_EXTINT + 65) /* Comparator interrupt */
#define MCXA156_IRQ_Reserved82             (MCXA1XX_IRQ_EXTINT + 66) /* Reserved interrupt */
#define MCXA156_IRQ_DAC0                   (MCXA1XX_IRQ_EXTINT + 67) /* Digital-to-Analog Converter 0 - General Purpose interrupt */
#define MCXA156_IRQ_Reserved84             (MCXA1XX_IRQ_EXTINT + 68) /* Reserved interrupt */
#define MCXA156_IRQ_Reserved85             (MCXA1XX_IRQ_EXTINT + 69) /* Reserved interrupt */
#define MCXA156_IRQ_Reserved86             (MCXA1XX_IRQ_EXTINT + 70) /* Reserved interrupt */
#define MCXA156_IRQ_GPIO0                  (MCXA1XX_IRQ_EXTINT + 71) /* General Purpose Input/Output interrupt 0 */
#define MCXA156_IRQ_GPIO1                  (MCXA1XX_IRQ_EXTINT + 72) /* General Purpose Input/Output interrupt 1 */
#define MCXA156_IRQ_GPIO2                  (MCXA1XX_IRQ_EXTINT + 73) /* General Purpose Input/Output interrupt 2 */
#define MCXA156_IRQ_GPIO3                  (MCXA1XX_IRQ_EXTINT + 74) /* General Purpose Input/Output interrupt 3 */
#define MCXA156_IRQ_GPIO4                  (MCXA1XX_IRQ_EXTINT + 75) /* General Purpose Input/Output interrupt 4 */
#define MCXA156_IRQ_Reserved92             (MCXA1XX_IRQ_EXTINT + 76) /* Reserved interrupt */
#define MCXA156_IRQ_LPI2C2                 (MCXA1XX_IRQ_EXTINT + 77) /* Low-Power Inter Integrated Circuit interrupt */
#define MCXA156_IRQ_LPI2C3                 (MCXA1XX_IRQ_EXTINT + 78) /* Low-Power Inter Integrated Circuit interrupt */
#define MCXA156_IRQ_FLEXPWM1_RELOAD_ERROR  (MCXA1XX_IRQ_EXTINT + 79) /* FlexPWM1_reload_error interrupt */
#define MCXA156_IRQ_FLEXPWM1_FAULT         (MCXA1XX_IRQ_EXTINT + 80) /* FlexPWM1_fault interrupt */
#define MCXA156_IRQ_FLEXPWM1_SUBMODULE0    (MCXA1XX_IRQ_EXTINT + 81) /* FlexPWM1 Submodule 0 capture/compare/reload interrupt */
#define MCXA156_IRQ_FLEXPWM1_SUBMODULE1    (MCXA1XX_IRQ_EXTINT + 82) /* FlexPWM1 Submodule 1 capture/compare/reload interrupt */
#define MCXA156_IRQ_FLEXPWM1_SUBMODULE2    (MCXA1XX_IRQ_EXTINT + 83) /* FlexPWM1 Submodule 2 capture/compare/reload interrupt */
#define MCXA156_IRQ_Reserved100            (MCXA1XX_IRQ_EXTINT + 84) /* Reserved interrupt */
#define MCXA156_IRQ_QDC1_COMPARE           (MCXA1XX_IRQ_EXTINT + 85) /* Compare */
#define MCXA156_IRQ_QDC1_HOME              (MCXA1XX_IRQ_EXTINT + 86) /* Home */
#define MCXA156_IRQ_QDC1_WATCHDOG          (MCXA1XX_IRQ_EXTINT + 87) /* Watchdog / Simultaneous A and B Change */
#define MCXA156_IRQ_QDC1_INDEX             (MCXA1XX_IRQ_EXTINT + 88) /* Index / Roll Over / Roll Under */

/* Total number of interrupt vectors: the 16 Cortex-M exceptions plus the
 * 89 external interrupts (0..88) this part implements.
 */

#define MCXA1XX_IRQ_NEXTINT      (89)
#define NR_IRQS                  (MCXA1XX_IRQ_EXTINT + MCXA1XX_IRQ_NEXTINT)

#endif /* __ARCH_ARM_INCLUDE_MCXA1XX_MCXA156_IRQ_H */
