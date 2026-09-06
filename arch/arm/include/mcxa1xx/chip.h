/****************************************************************************
 * arch/arm/include/mcxa1xx/chip.h
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

#ifndef __ARCH_ARM_INCLUDE_MCXA1XX_CHIP_H
#define __ARCH_ARM_INCLUDE_MCXA1XX_CHIP_H

/****************************************************************************
 * Included Files
 ****************************************************************************/

#include <nuttx/config.h>

/****************************************************************************
 * Pre-processor Definitions
 ****************************************************************************/

/* NVIC priority levels *****************************************************/

/* The MCX A1xx implements 3 priority bits (__NVIC_PRIO_BITS == 3 in NXP's
 * CMSIS header), i.e. msbits [7:5] are used and the rest are reserved.
 */

#define NVIC_SYSH_PRIORITY_MIN        0xe0 /* E0h is minimum priority */
#define NVIC_SYSH_PRIORITY_DEFAULT    0x80 /* Midpoint is the default */
#define NVIC_SYSH_PRIORITY_MAX        0x00 /* Zero is maximum priority */
#define NVIC_SYSH_PRIORITY_STEP       0x20 /* Step is the 5th bit */

/* This part has five GPIO ports, GPIO0..GPIO4 */

#define MCXA1XX_GPIO_NPORTS           5

#endif /* __ARCH_ARM_INCLUDE_MCXA1XX_CHIP_H */
