/****************************************************************************
 * arch/arm/src/mcxa1xx/hardware/mcxa1xx_memorymap.h
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

#ifndef __ARCH_ARM_SRC_MCXA1XX_HARDWARE_MCXA1XX_MEMORYMAP_H
#define __ARCH_ARM_SRC_MCXA1XX_HARDWARE_MCXA1XX_MEMORYMAP_H

/****************************************************************************
 * Included Files
 ****************************************************************************/

#include <nuttx/config.h>

/****************************************************************************
 * Pre-processor Definitions
 ****************************************************************************/

/* Peripheral base addresses.
 *
 * All addresses below are taken verbatim from NXP's CMSIS device header,
 * devices/MCXA156/MCXA156.h in github.com/nxp-mcuxpresso/mcux-sdk.
 */

#define MCXA1XX_SCG0_BASE        0x4008f000  /* System Clock Generator */
#define MCXA1XX_SPC0_BASE        0x40090000  /* System Power Control */
#define MCXA1XX_MRCC0_BASE       0x40091000  /* Peripheral clock/reset control */
#define MCXA1XX_FMC0_BASE        0x40094000  /* Flash Memory Controller */
#define MCXA1XX_FMU0_BASE        0x40095000  /* Flash Management Unit */

#define MCXA1XX_LPUART0_BASE     0x4009f000
#define MCXA1XX_LPUART1_BASE     0x400a0000
#define MCXA1XX_LPUART2_BASE     0x400a1000
#define MCXA1XX_LPUART3_BASE     0x400a2000
#define MCXA1XX_LPUART4_BASE     0x400a3000

#define MCXA1XX_CAN0_BASE        0x400cc000  /* FlexCAN (CAN-FD capable) */

#define MCXA1XX_PORT0_BASE       0x400bc000
#define MCXA1XX_PORT1_BASE       0x400bd000
#define MCXA1XX_PORT2_BASE       0x400be000
#define MCXA1XX_PORT3_BASE       0x400bf000
#define MCXA1XX_PORT4_BASE       0x400c0000

#define MCXA1XX_GPIO0_BASE       0x40102000
#define MCXA1XX_GPIO1_BASE       0x40103000
#define MCXA1XX_GPIO2_BASE       0x40104000
#define MCXA1XX_GPIO3_BASE       0x40105000
#define MCXA1XX_GPIO4_BASE       0x40106000

#endif /* __ARCH_ARM_SRC_MCXA1XX_HARDWARE_MCXA1XX_MEMORYMAP_H */
