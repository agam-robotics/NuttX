/****************************************************************************
 * arch/arm/src/mcx-nxxx/hardware/mcxa1xx_gpio.h
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

#ifndef __ARCH_ARM_SRC_MCX_MCXA1XX_HARDWARE_MCXA1XX_GPIO_H
#define __ARCH_ARM_SRC_MCX_MCXA1XX_HARDWARE_MCXA1XX_GPIO_H

/****************************************************************************
 * Included Files
 ****************************************************************************/

#include <nuttx/config.h>

#if defined(CONFIG_ARCH_CHIP_MCXA156)
#  include "hardware/mcxa156_gpio.h"
#else
#  error Unrecognized MCX A1xx architecture
#endif

/****************************************************************************
 * Pre-processor Definitions
 ****************************************************************************/

#define GPIO0                           0      /* Port 0 index */
#define GPIO1                           1      /* Port 1 index */
#define GPIO2                           2      /* Port 2 index */
#define GPIO3                           3      /* Port 3 index */
#define GPIO4                           4      /* Port 4 index */

/* NOTE: this part implements five GPIO ports only (GPIO0..GPIO4).
 * Higher port indices exist on MCX Nxxx but not here.
 */

#define MCXA1XX_GPIO_NPINS                 32     /* Up to 32 pins per port */

/* Register bit definitions *************************************************/

/* Most registers are laid out simply with one bit per pin */

#define GPIO_PIN(n)                     (1 << (n)) /* Bit n: Pin n, n=0-31 */

/* ICRN Register */

#define MCXA1XX_GPIO_ICRN_ISF              (1 << 24) /* Bit 24: Interrupt Status Flag */
#define MCXA1XX_GPIO_ICRN_LK               (1 << 23) /* Bit 23: Lock Register */
#define MCXA1XX_GPIO_ICRN_IRQS             (1 << 20) /* Bit 20: Configures the selected interrupt, or DMA request. */
#define MCXA1XX_GPIO_ICRN_SHIFT            (16)      /* Bits 16-19:  Interrupt Configuration */
#define MCXA1XX_GPIO_ICRN_MASK             (0xf << MCXA1XX_GPIO_ICRN_SHIFT)
#  define MCXA1XX_GPIO_ICRN_DISABLED       (0 << MCXA1XX_GPIO_ICRN_SHIFT)  /* Interrupt Status Flag (ISF) is disabled */
#  define MCXA1XX_GPIO_ICRN_DMARISING      (1 << MCXA1XX_GPIO_ICRN_SHIFT)  /* ISF flag and DMA request on rising edge */
#  define MCXA1XX_GPIO_ICRN_DMAFALLING     (2 << MCXA1XX_GPIO_ICRN_SHIFT)  /* ISF flag and DMA request on falling edge */
#  define MCXA1XX_GPIO_ICRN_DMABOTH        (3 << MCXA1XX_GPIO_ICRN_SHIFT)  /* ISF flag and DMA request on either edge */
#  define MCXA1XX_GPIO_ICRN_ISFRISING      (5 << MCXA1XX_GPIO_ICRN_SHIFT)  /* ISF flag sets on rising edge */
#  define MCXA1XX_GPIO_ICRN_ISFFALLING     (6 << MCXA1XX_GPIO_ICRN_SHIFT)  /* ISF flag sets on falling edge */
#  define MCXA1XX_GPIO_ICRN_ISFBOTH        (7 << MCXA1XX_GPIO_ICRN_SHIFT)  /* ISF flag sets on either edge */
#  define MCXA1XX_GPIO_ICRN_ZERO           (8 << MCXA1XX_GPIO_ICRN_SHIFT)  /* ISF flag and Interrupt when logic 0 */
#  define MCXA1XX_GPIO_ICRN_RISING         (9 << MCXA1XX_GPIO_ICRN_SHIFT)  /* ISF flag and Interrupt on rising-edge */
#  define MCXA1XX_GPIO_ICRN_FALLING        (10 << MCXA1XX_GPIO_ICRN_SHIFT) /* ISF flag and Interrupt on falling-edge */
#  define MCXA1XX_GPIO_ICRN_BOTH           (11 << MCXA1XX_GPIO_ICRN_SHIFT) /* ISF flag and Interrupt on either edge */
#  define MCXA1XX_GPIO_ICRN_ONE            (12 << MCXA1XX_GPIO_ICRN_SHIFT) /* ISF flag and Interrupt when logic 1 */

/* Global Interrupt Control Low Register */

#define MCXA1XX_GPIO_GICLR_GIWD_SHIFT      (0)       /* Bits 0-15: Global Interrupt Write Data */
#define MCXA1XX_GPIO_GICLR_GIWD_MASK       (0xffff << MCXA1XX_GPIO_GICLR_GIWD_SHIFT)
#  define MCXA1XX_GPIO_GICLR_GIWD_PIN(n)   ((uint32_t)(n) << MCXA1XX_GPIO_GICLR_GIWD_SHIFT) /* Pin n=0..15 */

#define MCXA1XX_GPIO_GICLR_GIWE_SHIFT      (16)      /* Bits 16-31: Global Interrupt Write Enable */
#define MCXA1XX_GPIO_GICLR_GIWE_MASK       (0xffff << MCXA1XX_GPIO_GICLR_GIWE_SHIFT)
#  define MCXA1XX_GPIO_GICLR_GIWE_PIN(n)   ((uint32_t)(n) << MCXA1XX_GPIO_GICLR_GIWE_SHIFT) /* Pin n=0..15 */

/* Global Interrupt Control High Register */

#define MCXA1XX_GPIO_GICHR_GIWD_SHIFT      (0)       /* Bits 0-15: Global Interrupt Write Data */
#define MCXA1XX_GPIO_GICHR_GIWD_MASK       (0xffff << MCXA1XX_GPIO_GICHR_GIWD_SHIFT)
#  define MCXA1XX_GPIO_GICHR_GIWD_PIN(n)   ((uint32_t)((n) - 16) << MCXA1XX_GPIO_GICHR_GIWD_SHIFT) /* Pin n=16..31 */

#define MCXA1XX_GPIO_GICHR_GIWE_SHIFT      (16)      /* Bits 16-31: Global Interrupt Write Enable */
#define MCXA1XX_GPIO_GICHR_GIWE_MASK       (0xffff << MCXA1XX_GPIO_GICHR_GIWE_SHIFT)
#  define MCXA1XX_GPIO_GICHR_GIWE_PIN(n)   ((uint32_t)((n) - 16) << MCXA1XX_GPIO_GICHR_GIWE_SHIFT) /* Pin n=16..31 */

/* Interrupt Status Flag Register */

#define MCXA1XX_GPIO_ISFR(n)               (1 << (n))  /* Interrupt Status Flag, n=0-31 */

#endif /* __ARCH_ARM_SRC_MCX_MCXA1XX_HARDWARE_MCXA1XX_GPIO_H */
