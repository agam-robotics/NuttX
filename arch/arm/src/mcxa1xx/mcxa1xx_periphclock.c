/****************************************************************************
 * arch/arm/src/mcxa1xx/mcxa1xx_periphclock.c
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

#include <sys/types.h>
#include <stdint.h>
#include <stdbool.h>

#include "arm_internal.h"
#include "chip.h"
#include "mcxa1xx_periphclock.h"

/****************************************************************************
 * Public Functions
 ****************************************************************************/

/****************************************************************************
 * Name: mcxa1xx_set_clock_gate
 *
 * Description:
 *   Open or close a peripheral clock gate via the MRCC SET/CLR registers.
 *
 ****************************************************************************/

void mcxa1xx_set_clock_gate(struct mcxa1xx_clock_gate_s gate, bool enabled)
{
  uintptr_t regaddr;

  /* The SET and CLR registers are write-only aliases that affect only the
   * bits written, so no read-modify-write (and no critical section) is
   * needed to touch one peripheral's gate.
   */

  if (gate.reg == MCXA1XX_CC0)
    {
      regaddr = enabled ? MCXA1XX_MRCC_GLB_CC0_SET : MCXA1XX_MRCC_GLB_CC0_CLR;
    }
  else
    {
      regaddr = enabled ? MCXA1XX_MRCC_GLB_CC1_SET : MCXA1XX_MRCC_GLB_CC1_CLR;
    }

  putreg32(gate.bit, regaddr);
}

/****************************************************************************
 * Name: mcxa1xx_set_periphclock
 *
 * Description:
 *   Select the functional clock source and divider for one peripheral.
 *
 ****************************************************************************/

void mcxa1xx_set_periphclock(uintptr_t clksel, uintptr_t clkdiv,
                             uint32_t mux, uint32_t div)
{
  uint32_t regval;

  /* Select the clock source */

  regval  = getreg32(clksel);
  regval &= ~MRCC_CLKSEL_MUX_MASK;
  regval |= (mux & MRCC_CLKSEL_MUX_MASK);
  putreg32(regval, clksel);

  /* Program the divider and reset the divider counter so the new ratio
   * takes effect from a known state.
   */

  putreg32(MRCC_CLKDIV_DIV(div) | MRCC_CLKDIV_RESET, clkdiv);
  putreg32(MRCC_CLKDIV_DIV(div), clkdiv);

  /* Wait for the divider to settle before the peripheral is clocked */

  while ((getreg32(clkdiv) & MRCC_CLKDIV_UNSTAB) != 0)
    {
    }
}
