/****************************************************************************
 * arch/arm/src/mcxa1xx/mcxa1xx_clockconfig.h
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

#ifndef __ARCH_ARM_SRC_MCXA1XX_MCXA1XX_CLOCKCONFIG_H
#define __ARCH_ARM_SRC_MCXA1XX_MCXA1XX_CLOCKCONFIG_H

/****************************************************************************
 * Included Files
 ****************************************************************************/

#include <nuttx/config.h>
#include <stdint.h>
#include <stdbool.h>

#include "hardware/mcxa1xx_scg.h"
#include "hardware/mcxa1xx_syscon.h"

/****************************************************************************
 * Public Function Prototypes
 ****************************************************************************/

/****************************************************************************
 * Name: mcxa1xx_clockconfig
 *
 * Description:
 *   Called to initialize the clocks for MCX A1xx. This brings the FIRC up
 *   at the frequency requested by board.h (BOARD_FIRC_FREQUENCY), selects
 *   it as the system clock source and applies the core/slow dividers.
 *
 *   The MCX A1xx has no PLL: the FIRC is the high-frequency source, so
 *   this is the whole of the high-speed clock bring-up.
 *
 ****************************************************************************/

void mcxa1xx_clockconfig(void);

/****************************************************************************
 * Name: mcxa1xx_get_coreclk
 *
 * Description:
 *   Return the current value of the CORE clock frequency, derived from the
 *   active system clock source and the AHB divider.
 *
 * Returned Value:
 *   The current CORE clock frequency in Hz. Zero on any failure.
 *
 ****************************************************************************/

uint32_t mcxa1xx_get_coreclk(void);

#endif /* __ARCH_ARM_SRC_MCXA1XX_MCXA1XX_CLOCKCONFIG_H */
