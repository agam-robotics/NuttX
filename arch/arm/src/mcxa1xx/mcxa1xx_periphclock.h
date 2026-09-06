/****************************************************************************
 * arch/arm/src/mcxa1xx/mcxa1xx_periphclock.h
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

#ifndef __ARCH_ARM_SRC_MCXA1XX_MCXA1XX_PERIPHCLOCK_H
#define __ARCH_ARM_SRC_MCXA1XX_MCXA1XX_PERIPHCLOCK_H

/****************************************************************************
 * Included Files
 ****************************************************************************/

#include <nuttx/config.h>

#include <stdint.h>
#include <stdbool.h>

#include "hardware/mcxa1xx_mrcc.h"

/****************************************************************************
 * Public Types
 ****************************************************************************/

/* Identifies which of the two MRCC AHB clock control registers a gate bit
 * lives in, together with the bit itself.
 */

enum mcxa1xx_ccreg_e
{
  MCXA1XX_CC0 = 0,
  MCXA1XX_CC1 = 1,
};

struct mcxa1xx_clock_gate_s
{
  enum mcxa1xx_ccreg_e reg;
  uint32_t             bit;
};

/****************************************************************************
 * Pre-processor Definitions
 ****************************************************************************/

#define CLOCK_GATE_LPUART(n)  ((struct mcxa1xx_clock_gate_s) \
                               { MCXA1XX_CC0, MRCC_CC0_LPUART0 << (n) })
#define CLOCK_GATE_FLEXCAN0   ((struct mcxa1xx_clock_gate_s) \
                               { MCXA1XX_CC1, MRCC_CC1_FLEXCAN0 })
#define CLOCK_GATE_PORT(n)    ((struct mcxa1xx_clock_gate_s) \
                               { MCXA1XX_CC1, MRCC_CC1_PORT0 << (n) })
#define CLOCK_GATE_GPIO(n)    ((struct mcxa1xx_clock_gate_s) \
                               { MCXA1XX_CC1, MRCC_CC1_GPIO0 << (n) })

/****************************************************************************
 * Public Function Prototypes
 ****************************************************************************/

/****************************************************************************
 * Name: mcxa1xx_set_clock_gate
 *
 * Description:
 *   Open or close a peripheral clock gate via the MRCC SET/CLR registers.
 *
 * Input Parameters:
 *   gate    - Identifies the clock gate of interest.
 *   enabled - True enables the clock; false disables it.
 *
 ****************************************************************************/

void mcxa1xx_set_clock_gate(struct mcxa1xx_clock_gate_s gate, bool enabled);

/****************************************************************************
 * Name: mcxa1xx_set_periphclock
 *
 * Description:
 *   Select the functional clock source and divider for one peripheral.
 *
 *   The peripheral's clock gate must be closed while CLKSEL is changed, so
 *   callers should call this before opening the gate.
 *
 * Input Parameters:
 *   clksel - Address of the peripheral's MRCC CLKSEL register.
 *   clkdiv - Address of the peripheral's MRCC CLKDIV register.
 *   mux    - Clock source, one of the MRCC_CLKSEL_* values.
 *   div    - Divider value (1..16); the register holds div - 1.
 *
 ****************************************************************************/

void mcxa1xx_set_periphclock(uintptr_t clksel, uintptr_t clkdiv,
                             uint32_t mux, uint32_t div);

#endif /* __ARCH_ARM_SRC_MCXA1XX_MCXA1XX_PERIPHCLOCK_H */
