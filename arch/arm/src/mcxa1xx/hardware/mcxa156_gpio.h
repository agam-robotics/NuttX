/****************************************************************************
 * arch/arm/src/mcxa1xx/hardware/mcxa156_gpio.h
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

#ifndef __ARCH_ARM_SRC_MCXA1XX_HARDWARE_MCXA156_GPIO_H
#define __ARCH_ARM_SRC_MCXA1XX_HARDWARE_MCXA156_GPIO_H

/****************************************************************************
 * Included Files
 ****************************************************************************/

#include <nuttx/config.h>

#include "hardware/mcxa1xx_memorymap.h"

/****************************************************************************
 * Pre-processor Definitions
 ****************************************************************************/

/* GPIO Register Offsets ****************************************************/

/* Offsets from the GPIO_Type layout in NXP's devices/MCXA156/MCXA156.h.
 *
 * NOTE: unlike the MCX Nxxx (n236) part, this GPIO block has a SINGLE
 * interrupt status flag register (ISFR[1] at 0x120). There is no ISFR1 at
 * 0x124, so none is defined here.
 *
 * This part also has no Lock/Nonsecure/Nonprivilege registers (0x0c-0x1c)
 * -- it implements no TrustZone.
 */

#define MCXA1XX_GPIO_VERID_OFFSET       (0x0000) /* Version ID */
#define MCXA1XX_GPIO_PARAM_OFFSET       (0x0004) /* Parameter */
#define MCXA1XX_GPIO_PDOR_OFFSET        (0x0040) /* Port Data Output */
#define MCXA1XX_GPIO_PSOR_OFFSET        (0x0044) /* Port Set Output */
#define MCXA1XX_GPIO_PCOR_OFFSET        (0x0048) /* Port Clear Output */
#define MCXA1XX_GPIO_PTOR_OFFSET        (0x004c) /* Port Toggle Output */
#define MCXA1XX_GPIO_PDIR_OFFSET        (0x0050) /* Port Data Input */
#define MCXA1XX_GPIO_PDDR_OFFSET        (0x0054) /* Port Data Direction */
#define MCXA1XX_GPIO_PIDR_OFFSET        (0x0058) /* Port Input Disable */
#define MCXA1XX_GPIO_ICR0_OFFSET        (0x0080) /* Interrupt Control (0-31 at offsets of n * 4h) */
#define MCXA1XX_GPIO_GICLR_OFFSET       (0x0100) /* Global Interrupt Control Low */
#define MCXA1XX_GPIO_GICHR_OFFSET       (0x0104) /* Global Interrupt Control High */
#define MCXA1XX_GPIO_ISFR0_OFFSET       (0x0120) /* Interrupt Status Flag */

#endif /* __ARCH_ARM_SRC_MCXA1XX_HARDWARE_MCXA156_GPIO_H */
