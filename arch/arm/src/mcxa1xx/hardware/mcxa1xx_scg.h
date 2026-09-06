/****************************************************************************
 * arch/arm/src/mcxa1xx/hardware/mcxa1xx_scg.h
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

#ifndef __ARCH_ARM_SRC_MCXA1XX_HARDWARE_MCXA1XX_SCG_H
#define __ARCH_ARM_SRC_MCXA1XX_HARDWARE_MCXA1XX_SCG_H

/****************************************************************************
 * Included Files
 ****************************************************************************/

#include <nuttx/config.h>

#include "hardware/mcxa1xx_memorymap.h"

/****************************************************************************
 * Pre-processor Definitions
 ****************************************************************************/

/* NOTE: the MCX A1xx SCG differs substantially from the MCX Nxxx one and
 * the two are NOT interchangeable:
 *
 *   - There is no PLL of any kind (no APLL, no SPLL). The FIRC generates
 *     48/64/96/192 MHz directly, so a PLL bring-up sequence is neither
 *     needed nor possible.
 *   - There are no per-source divider registers (no SOSCDIV/SIRCDIV/
 *     FIRCDIV). Core and slow clock division is done in SYSCON
 *     (AHBCLKDIV/SLOWCLKDIV) instead of in SCG RCCR.
 *   - RCCR carries only SCS; it has no DIVCORE/DIVSLOW fields.
 *
 * All offsets and bitfields below are taken from the SCG_Type layout and
 * SCG_* masks in NXP's devices/MCXA156/MCXA156.h (mcux-sdk).
 */

/* SCG Register Offsets *****************************************************/

#define MCXA1XX_SCG_VERID_OFFSET      0x0000  /* Version ID Register */
#define MCXA1XX_SCG_PARAM_OFFSET      0x0004  /* Parameter Register */
#define MCXA1XX_SCG_TRIM_LOCK_OFFSET  0x0008  /* Trim Lock Register */
#define MCXA1XX_SCG_CSR_OFFSET        0x0010  /* Clock Status Register */
#define MCXA1XX_SCG_RCCR_OFFSET       0x0014  /* Run Clock Control Register */
#define MCXA1XX_SCG_SOSCCSR_OFFSET    0x0100  /* SOSC Control Status Register */
#define MCXA1XX_SCG_SOSCCFG_OFFSET    0x0108  /* SOSC Configuration Register */
#define MCXA1XX_SCG_SIRCCSR_OFFSET    0x0200  /* SIRC Control Status Register */
#define MCXA1XX_SCG_SIRCTCFG_OFFSET   0x020c  /* SIRC Trim Configuration Register */
#define MCXA1XX_SCG_SIRCTRIM_OFFSET   0x0210  /* SIRC Trim Register */
#define MCXA1XX_SCG_SIRCSTAT_OFFSET   0x0218  /* SIRC Auto-trimming Status Register */
#define MCXA1XX_SCG_FIRCCSR_OFFSET    0x0300  /* FIRC Control Status Register */
#define MCXA1XX_SCG_FIRCCFG_OFFSET    0x0308  /* FIRC Configuration Register */
#define MCXA1XX_SCG_FIRCTCFG_OFFSET   0x030c  /* FIRC Trim Configuration Register */
#define MCXA1XX_SCG_FIRCTRIM_OFFSET   0x0310  /* FIRC Trim Register */
#define MCXA1XX_SCG_FIRCSTAT_OFFSET   0x0318  /* FIRC Auto-trimming Status Register */
#define MCXA1XX_SCG_ROSCCSR_OFFSET    0x0400  /* ROSC Control Status Register */

/* SCG Register Addresses ***************************************************/

#define MCXA1XX_SCG_VERID      (MCXA1XX_SCG0_BASE + MCXA1XX_SCG_VERID_OFFSET)
#define MCXA1XX_SCG_PARAM      (MCXA1XX_SCG0_BASE + MCXA1XX_SCG_PARAM_OFFSET)
#define MCXA1XX_SCG_TRIM_LOCK  (MCXA1XX_SCG0_BASE + MCXA1XX_SCG_TRIM_LOCK_OFFSET)
#define MCXA1XX_SCG_CSR        (MCXA1XX_SCG0_BASE + MCXA1XX_SCG_CSR_OFFSET)
#define MCXA1XX_SCG_RCCR       (MCXA1XX_SCG0_BASE + MCXA1XX_SCG_RCCR_OFFSET)
#define MCXA1XX_SCG_SOSCCSR    (MCXA1XX_SCG0_BASE + MCXA1XX_SCG_SOSCCSR_OFFSET)
#define MCXA1XX_SCG_SOSCCFG    (MCXA1XX_SCG0_BASE + MCXA1XX_SCG_SOSCCFG_OFFSET)
#define MCXA1XX_SCG_SIRCCSR    (MCXA1XX_SCG0_BASE + MCXA1XX_SCG_SIRCCSR_OFFSET)
#define MCXA1XX_SCG_FIRCCSR    (MCXA1XX_SCG0_BASE + MCXA1XX_SCG_FIRCCSR_OFFSET)
#define MCXA1XX_SCG_FIRCCFG    (MCXA1XX_SCG0_BASE + MCXA1XX_SCG_FIRCCFG_OFFSET)
#define MCXA1XX_SCG_FIRCSTAT   (MCXA1XX_SCG0_BASE + MCXA1XX_SCG_FIRCSTAT_OFFSET)
#define MCXA1XX_SCG_ROSCCSR    (MCXA1XX_SCG0_BASE + MCXA1XX_SCG_ROSCCSR_OFFSET)

/* SCG Register Bitfield Definitions ****************************************/

/* Clock Status Register (CSR) and Run Clock Control Register (RCCR).
 * Both carry SCS in the same position; CSR reports the active source,
 * RCCR selects it.
 */

#define SCG_SCS_SHIFT               (24)      /* Bits 24-26: System Clock Source */
#define SCG_SCS_MASK                (7 << SCG_SCS_SHIFT)
#  define SCG_SCS_SOSC              (1 << SCG_SCS_SHIFT)  /* System OSC */
#  define SCG_SCS_SIRC              (2 << SCG_SCS_SHIFT)  /* Slow IRC */
#  define SCG_SCS_FIRC              (3 << SCG_SCS_SHIFT)  /* Fast IRC */
#  define SCG_SCS_ROSC              (4 << SCG_SCS_SHIFT)  /* RTC OSC */

/* SOSC Control Status Register */

#define SCG_SOSCCSR_SOSCEN          (1 << 0)  /* Bit 0:  SOSC Enable */
#define SCG_SOSCCSR_SOSCVLD         (1 << 24) /* Bit 24: SOSC Valid */
#define SCG_SOSCCSR_SOSCSEL         (1 << 25) /* Bit 25: SOSC Selected */
#define SCG_SOSCCSR_LK              (1 << 23) /* Bit 23: Lock Register */

/* SIRC Control Status Register */

#define SCG_SIRCCSR_SIRCEN          (1 << 0)  /* Bit 0:  SIRC Enable */
#define SCG_SIRCCSR_SIRCVLD         (1 << 24) /* Bit 24: SIRC Valid */
#define SCG_SIRCCSR_SIRCSEL         (1 << 25) /* Bit 25: SIRC Selected */

/* FIRC Control Status Register */

#define SCG_FIRCCSR_FIRCEN          (1 << 0)  /* Bit 0:  FIRC Enable */
#define SCG_FIRCCSR_FIRC_SCLK_EN    (1 << 4)  /* Bit 4:  FIRC SCLK to peripherals */
#define SCG_FIRCCSR_FIRC_FCLK_EN    (1 << 5)  /* Bit 5:  FIRC FCLK to peripherals */
#define SCG_FIRCCSR_FIRCVLD         (1 << 24) /* Bit 24: FIRC Valid */
#define SCG_FIRCCSR_FIRCSEL         (1 << 25) /* Bit 25: FIRC Selected */

/* FIRC Configuration Register */

#define SCG_FIRCCFG_FREQ_SEL_SHIFT  (1)       /* Bits 1-3: FIRC frequency select */
#define SCG_FIRCCFG_FREQ_SEL_MASK   (7 << SCG_FIRCCFG_FREQ_SEL_SHIFT)
#  define SCG_FIRCCFG_FREQ_48MHZ    (1 << SCG_FIRCCFG_FREQ_SEL_SHIFT)
#  define SCG_FIRCCFG_FREQ_64MHZ    (3 << SCG_FIRCCFG_FREQ_SEL_SHIFT)
#  define SCG_FIRCCFG_FREQ_96MHZ    (5 << SCG_FIRCCFG_FREQ_SEL_SHIFT)
#  define SCG_FIRCCFG_FREQ_192MHZ   (7 << SCG_FIRCCFG_FREQ_SEL_SHIFT)

/* Nominal source frequencies */

#define MCXA1XX_SIRC_FREQUENCY      12000000  /* SIRC is a fixed 12 MHz */
#define MCXA1XX_FRO16K_FREQUENCY    16384     /* Low power 16.384 kHz FRO */

#endif /* __ARCH_ARM_SRC_MCXA1XX_HARDWARE_MCXA1XX_SCG_H */
