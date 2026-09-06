/****************************************************************************
 * arch/arm/src/mcxa1xx/hardware/mcxa1xx_mrcc.h
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

#ifndef __ARCH_ARM_SRC_MCXA1XX_HARDWARE_MCXA1XX_MRCC_H
#define __ARCH_ARM_SRC_MCXA1XX_HARDWARE_MCXA1XX_MRCC_H

/****************************************************************************
 * Included Files
 ****************************************************************************/

#include <nuttx/config.h>

#include "hardware/mcxa1xx_memorymap.h"

/****************************************************************************
 * Pre-processor Definitions
 ****************************************************************************/

/* MRCC is this part's peripheral clock and reset controller.
 *
 * NOTE: the MCX Nxxx equivalent routes serial peripherals through
 * LPFLEXCOMM blocks. This part has NO LPFLEXCOMM at all -- LPUART0..4 and
 * FLEXCAN0 are standalone peripherals, each with its own CLKSEL/CLKDIV
 * pair in MRCC, so the MCX Nxxx clock-gating code does not apply here.
 *
 * Offsets and bitfields from the MRCC_Type layout in NXP's
 * devices/MCXA156/MCXA156.h.
 */

/* Global clock/reset control register offsets ******************************/

#define MCXA1XX_MRCC_GLB_RST0_OFFSET      0x0000  /* Peripheral Reset Control 0 */
#define MCXA1XX_MRCC_GLB_RST0_SET_OFFSET  0x0004
#define MCXA1XX_MRCC_GLB_RST0_CLR_OFFSET  0x0008
#define MCXA1XX_MRCC_GLB_RST1_OFFSET      0x0010  /* Peripheral Reset Control 1 */
#define MCXA1XX_MRCC_GLB_RST1_SET_OFFSET  0x0014
#define MCXA1XX_MRCC_GLB_RST1_CLR_OFFSET  0x0018
#define MCXA1XX_MRCC_GLB_CC0_OFFSET       0x0040  /* AHB Clock Control 0 */
#define MCXA1XX_MRCC_GLB_CC0_SET_OFFSET   0x0044
#define MCXA1XX_MRCC_GLB_CC0_CLR_OFFSET   0x0048
#define MCXA1XX_MRCC_GLB_CC1_OFFSET       0x0050  /* AHB Clock Control 1 */
#define MCXA1XX_MRCC_GLB_CC1_SET_OFFSET   0x0054
#define MCXA1XX_MRCC_GLB_CC1_CLR_OFFSET   0x0058
#define MCXA1XX_MRCC_GLB_ACC0_OFFSET      0x0080  /* Automatic Clock Gating 0 */
#define MCXA1XX_MRCC_GLB_ACC1_OFFSET      0x0084  /* Automatic Clock Gating 1 */

/* Global clock/reset control register addresses ****************************/

#define MCXA1XX_MRCC_GLB_RST0 \
  (MCXA1XX_MRCC0_BASE + MCXA1XX_MRCC_GLB_RST0_OFFSET)
#define MCXA1XX_MRCC_GLB_RST0_SET \
  (MCXA1XX_MRCC0_BASE + MCXA1XX_MRCC_GLB_RST0_SET_OFFSET)
#define MCXA1XX_MRCC_GLB_RST0_CLR \
  (MCXA1XX_MRCC0_BASE + MCXA1XX_MRCC_GLB_RST0_CLR_OFFSET)
#define MCXA1XX_MRCC_GLB_RST1 \
  (MCXA1XX_MRCC0_BASE + MCXA1XX_MRCC_GLB_RST1_OFFSET)
#define MCXA1XX_MRCC_GLB_RST1_SET \
  (MCXA1XX_MRCC0_BASE + MCXA1XX_MRCC_GLB_RST1_SET_OFFSET)
#define MCXA1XX_MRCC_GLB_RST1_CLR \
  (MCXA1XX_MRCC0_BASE + MCXA1XX_MRCC_GLB_RST1_CLR_OFFSET)
#define MCXA1XX_MRCC_GLB_CC0 \
  (MCXA1XX_MRCC0_BASE + MCXA1XX_MRCC_GLB_CC0_OFFSET)
#define MCXA1XX_MRCC_GLB_CC0_SET \
  (MCXA1XX_MRCC0_BASE + MCXA1XX_MRCC_GLB_CC0_SET_OFFSET)
#define MCXA1XX_MRCC_GLB_CC0_CLR \
  (MCXA1XX_MRCC0_BASE + MCXA1XX_MRCC_GLB_CC0_CLR_OFFSET)
#define MCXA1XX_MRCC_GLB_CC1 \
  (MCXA1XX_MRCC0_BASE + MCXA1XX_MRCC_GLB_CC1_OFFSET)
#define MCXA1XX_MRCC_GLB_CC1_SET \
  (MCXA1XX_MRCC0_BASE + MCXA1XX_MRCC_GLB_CC1_SET_OFFSET)
#define MCXA1XX_MRCC_GLB_CC1_CLR \
  (MCXA1XX_MRCC0_BASE + MCXA1XX_MRCC_GLB_CC1_CLR_OFFSET)

/* Clock gate bits in AHB Clock Control 0 (CC0) *****************************/

#define MRCC_CC0_LPUART0            (1 << 22)
#define MRCC_CC0_LPUART1            (1 << 23)
#define MRCC_CC0_LPUART2            (1 << 24)
#define MRCC_CC0_LPUART3            (1 << 25)
#define MRCC_CC0_LPUART4            (1 << 26)

/* Clock gate bits in AHB Clock Control 1 (CC1) *****************************/

#define MRCC_CC1_PORT0              (1 << 7)
#define MRCC_CC1_PORT1              (1 << 8)
#define MRCC_CC1_PORT2              (1 << 9)
#define MRCC_CC1_PORT3              (1 << 10)
#define MRCC_CC1_PORT4              (1 << 11)
#define MRCC_CC1_FLEXCAN0           (1 << 12)
#define MRCC_CC1_GPIO0              (1 << 20)
#define MRCC_CC1_GPIO1              (1 << 21)
#define MRCC_CC1_GPIO2              (1 << 22)
#define MRCC_CC1_GPIO3              (1 << 23)
#define MRCC_CC1_GPIO4              (1 << 24)

/* Per-peripheral CLKSEL/CLKDIV registers ***********************************/

/* LPUART0..4 occupy consecutive CLKSEL/CLKDIV pairs starting at 0x100 with
 * an 8-byte stride (LPUART0 CLKSEL 0x100, CLKDIV 0x104, LPUART1 CLKSEL
 * 0x108, ...). FLEXCAN0 sits separately at 0x178/0x17c.
 */

#define MCXA1XX_MRCC_LPUART_CLKSEL(n) \
  (MCXA1XX_MRCC0_BASE + 0x0100 + ((n) << 3))
#define MCXA1XX_MRCC_LPUART_CLKDIV(n) \
  (MCXA1XX_MRCC0_BASE + 0x0104 + ((n) << 3))

#define MCXA1XX_MRCC_FLEXCAN0_CLKSEL  (MCXA1XX_MRCC0_BASE + 0x0178)
#define MCXA1XX_MRCC_FLEXCAN0_CLKDIV  (MCXA1XX_MRCC0_BASE + 0x017c)

/* CLKSEL MUX encoding (common to the per-peripheral CLKSEL registers) */

#define MRCC_CLKSEL_MUX_SHIFT       (0)
#define MRCC_CLKSEL_MUX_MASK        (7 << MRCC_CLKSEL_MUX_SHIFT)
#  define MRCC_CLKSEL_FRO_12M       (0 << MRCC_CLKSEL_MUX_SHIFT)
#  define MRCC_CLKSEL_FRO_HF_DIV    (2 << MRCC_CLKSEL_MUX_SHIFT)
#  define MRCC_CLKSEL_CLK_IN        (3 << MRCC_CLKSEL_MUX_SHIFT)
#  define MRCC_CLKSEL_CLK_16K       (4 << MRCC_CLKSEL_MUX_SHIFT)
#  define MRCC_CLKSEL_CLK_1M        (5 << MRCC_CLKSEL_MUX_SHIFT)
#  define MRCC_CLKSEL_NONE          (7 << MRCC_CLKSEL_MUX_SHIFT)

/* CLKDIV fields (common to the per-peripheral CLKDIV registers) */

#define MRCC_CLKDIV_DIV_SHIFT       (0)       /* Bits 0-3: divide by DIV+1 */
#define MRCC_CLKDIV_DIV_MASK        (0xf << MRCC_CLKDIV_DIV_SHIFT)
#  define MRCC_CLKDIV_DIV(n)        (((n) - 1) << MRCC_CLKDIV_DIV_SHIFT)
#define MRCC_CLKDIV_RESET           (1 << 29) /* Bit 29: Reset the divider */
#define MRCC_CLKDIV_HALT            (1 << 30) /* Bit 30: Halt the divider */
#define MRCC_CLKDIV_UNSTAB          (1 << 31) /* Bit 31: Divider unstable */

#endif /* __ARCH_ARM_SRC_MCXA1XX_HARDWARE_MCXA1XX_MRCC_H */
