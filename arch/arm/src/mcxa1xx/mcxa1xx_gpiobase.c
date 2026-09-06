/****************************************************************************
 * arch/arm/src/mcxa1xx/mcxa1xx_gpiobase.c
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

/****************************************************************************
 * Included Files
 ****************************************************************************/

#include <nuttx/config.h>

#include "mcxa1xx_gpio.h"

/****************************************************************************
 * Public Data
 ****************************************************************************/

#if defined(CONFIG_ARCH_CHIP_MCXA156)
/* Base address for the GPIO memory mapped registers */

const uintptr_t g_gpio_base[] =
{
  MCXA1XX_GPIO0_BASE,
  MCXA1XX_GPIO1_BASE,
  MCXA1XX_GPIO2_BASE,
  MCXA1XX_GPIO3_BASE,
  MCXA1XX_GPIO4_BASE,
};
#else
#  error Unrecognized MCX A1xx architecture
#endif

/****************************************************************************
 * Public Functions
 ****************************************************************************/
