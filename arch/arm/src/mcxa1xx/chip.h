/****************************************************************************
 * arch/arm/src/mcxa1xx/chip.h
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

#ifndef __ARCH_ARM_SRC_MCXA1XX_CHIP_H
#define __ARCH_ARM_SRC_MCXA1XX_CHIP_H

/****************************************************************************
 * Included Files
 ****************************************************************************/

#include <nuttx/config.h>

/****************************************************************************
 * Pre-processor Definitions
 ****************************************************************************/

/* Memory map.
 *
 * MCXA156 specifically (highest-memory part in the MCX A144-156 family):
 * 1024KB flash, 128KB SRAM (8KB of which is ECC-protected). Verified
 * against the family datasheet (MCXAP100M96FS6, Rev. 10). Flash/SRAM
 * base addresses follow the standard Cortex-M memory map, as used by
 * every other NuttX arch in this tree -- not chip-specific.
 */

#define MCXA1XX_FLASH_BASE      0x00000000
#define MCXA1XX_SRAM_BASE       0x20000000

#if defined(CONFIG_ARCH_CHIP_MCXA156)
#  define MCXA1XX_FLASH_SIZE    (1024 * 1024)
#  define MCXA1XX_SRAM_SIZE     (128 * 1024)
#else
#  error "Unknown MCX A1xx chip"
#endif

/* Peripheral base addresses.
 *
 * Verified against devices/MCXA156/MCXA156.h in NXP's mcux-sdk
 * (github.com/nxp-mcuxpresso/mcux-sdk), not hand-derived.
 */

#define MCXA1XX_SCG0_BASE       0x4008f000
#define MCXA1XX_SPC0_BASE       0x40090000
#define MCXA1XX_MRCC0_BASE      0x40091000
#define MCXA1XX_FMC0_BASE       0x40094000
#define MCXA1XX_FMU0_BASE       0x40095000
#define MCXA1XX_LPUART0_BASE    0x4009f000
#define MCXA1XX_LPUART1_BASE    0x400a0000
#define MCXA1XX_LPUART2_BASE    0x400a1000
#define MCXA1XX_LPUART3_BASE    0x400a2000
#define MCXA1XX_LPUART4_BASE    0x400a3000
#define MCXA1XX_CAN0_BASE       0x400cc000
#define MCXA1XX_PORT0_BASE      0x400bc000
#define MCXA1XX_PORT1_BASE      0x400bd000
#define MCXA1XX_PORT2_BASE      0x400be000
#define MCXA1XX_PORT3_BASE      0x400bf000
#define MCXA1XX_PORT4_BASE      0x400c0000
#define MCXA1XX_GPIO0_BASE      0x40102000
#define MCXA1XX_GPIO1_BASE      0x40103000
#define MCXA1XX_GPIO2_BASE      0x40104000
#define MCXA1XX_GPIO3_BASE      0x40105000
#define MCXA1XX_GPIO4_BASE      0x40106000

/* IRQ numbers (NVIC external interrupt numbers, i.e. IRQn_Type from the
 * CMSIS device header -- NuttX's vector table adds the 16 fixed Cortex-M
 * exceptions on top of these when building irq.h numbering).
 *
 * Verified against devices/MCXA156/MCXA156.h.
 */

#define MCXA1XX_IRQ_CAN0        19
#define MCXA1XX_IRQ_LPUART0     31
#define MCXA1XX_IRQ_LPUART1     32
#define MCXA1XX_IRQ_LPUART2     33
#define MCXA1XX_IRQ_LPUART3     34
#define MCXA1XX_IRQ_LPUART4     35
#define MCXA1XX_IRQ_WWDT0       60
#define MCXA1XX_IRQ_GPIO0       71
#define MCXA1XX_IRQ_GPIO1       72
#define MCXA1XX_IRQ_GPIO2       73
#define MCXA1XX_IRQ_GPIO3       74
#define MCXA1XX_IRQ_GPIO4       75

#endif /* __ARCH_ARM_SRC_MCXA1XX_CHIP_H */
