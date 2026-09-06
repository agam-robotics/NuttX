/****************************************************************************
 * arch/arm/src/mcxa1xx/mcxa1xx_clockconfig.c
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

#include "arm_internal.h"
#include "chip.h"
#include "mcxa1xx_clockconfig.h"

#include <arch/board/board.h>

/****************************************************************************
 * Pre-processor Definitions
 ****************************************************************************/

/* board.h selects the FIRC frequency and the core/slow dividers. Provide
 * conservative defaults so a board that has not been updated still boots.
 */

#ifndef BOARD_FIRC_FREQUENCY
#  define BOARD_FIRC_FREQUENCY  96000000
#endif

#ifndef BOARD_AHB_DIVIDER
#  define BOARD_AHB_DIVIDER     1
#endif

#ifndef BOARD_SLOW_DIVIDER
#  define BOARD_SLOW_DIVIDER    4
#endif

/****************************************************************************
 * Private Functions
 ****************************************************************************/

/****************************************************************************
 * Name: mcxa1xx_firc_freqsel
 *
 * Description:
 *   Map a requested FIRC frequency onto the FIRCCFG FREQ_SEL encoding.
 *   Only the four frequencies the hardware implements are accepted.
 *
 ****************************************************************************/

static uint32_t mcxa1xx_firc_freqsel(uint32_t frequency)
{
  switch (frequency)
    {
      case 48000000:
        return SCG_FIRCCFG_FREQ_48MHZ;

      case 64000000:
        return SCG_FIRCCFG_FREQ_64MHZ;

      case 96000000:
        return SCG_FIRCCFG_FREQ_96MHZ;

      case 192000000:
        return SCG_FIRCCFG_FREQ_192MHZ;

      default:

        /* Not a frequency the FIRC can generate. Fall back to the slowest
         * supported setting rather than writing a reserved encoding.
         */

        return SCG_FIRCCFG_FREQ_48MHZ;
    }
}

/****************************************************************************
 * Name: mcxa1xx_set_clkdiv
 *
 * Description:
 *   Program one of the SYSCON clock dividers and wait for the divider to
 *   come out of its transition (UNSTAB) state.
 *
 ****************************************************************************/

static void mcxa1xx_set_clkdiv(uintptr_t regaddr, uint32_t divider)
{
  /* Halt the divider while it is reprogrammed, then release it. The DIV
   * field is encoded as (divider - 1).
   */

  putreg32(SYSCON_CLKDIV_DIV(divider) | SYSCON_CLKDIV_RESET, regaddr);
  putreg32(SYSCON_CLKDIV_DIV(divider), regaddr);

  /* Wait for the new ratio to take effect */

  while ((getreg32(regaddr) & SYSCON_CLKDIV_UNSTAB) != 0)
    {
    }
}

/****************************************************************************
 * Public Functions
 ****************************************************************************/

/****************************************************************************
 * Name: mcxa1xx_clockconfig
 *
 * Description:
 *   Called to initialize the clocks for MCX A1xx.
 *
 ****************************************************************************/

void mcxa1xx_clockconfig(void)
{
  uint32_t regval;

  /* Bring the FIRC up at the requested frequency.
   *
   * FIRCCFG can only be written while the FIRC is disabled, so the enable
   * and the frequency select cannot be merged into one write.
   */

  putreg32(0, MCXA1XX_SCG_FIRCCSR);

  putreg32(mcxa1xx_firc_freqsel(BOARD_FIRC_FREQUENCY), MCXA1XX_SCG_FIRCCFG);

  /* Enable the FIRC and route it to the peripheral clock trees */

  putreg32(SCG_FIRCCSR_FIRCEN | SCG_FIRCCSR_FIRC_SCLK_EN |
           SCG_FIRCCSR_FIRC_FCLK_EN, MCXA1XX_SCG_FIRCCSR);

  /* Wait for the FIRC output to be valid before anything is clocked from
   * it. Switching SCS to an invalid source would stall the core.
   */

  while ((getreg32(MCXA1XX_SCG_FIRCCSR) & SCG_FIRCCSR_FIRCVLD) == 0)
    {
    }

  /* Set up the core and slow clock dividers before raising the system
   * clock, so that no bus runs over its rated frequency at any point.
   */

  mcxa1xx_set_clkdiv(MCXA1XX_SYSCON_AHBCLKDIV, BOARD_AHB_DIVIDER);
  mcxa1xx_set_clkdiv(MCXA1XX_SYSCON_SLOWCLKDIV, BOARD_SLOW_DIVIDER);

  /* Switch the system clock source to the FIRC */

  regval  = getreg32(MCXA1XX_SCG_RCCR);
  regval &= ~SCG_SCS_MASK;
  regval |= SCG_SCS_FIRC;
  putreg32(regval, MCXA1XX_SCG_RCCR);

  /* Wait until the switch has actually happened. CSR reports the source
   * that is live; RCCR only reports what was requested.
   */

  while ((getreg32(MCXA1XX_SCG_CSR) & SCG_SCS_MASK) != SCG_SCS_FIRC)
    {
    }
}

/****************************************************************************
 * Name: mcxa1xx_get_coreclk
 *
 * Description:
 *   Return the current value of the CORE clock frequency.
 *
 ****************************************************************************/

uint32_t mcxa1xx_get_coreclk(void)
{
  uint32_t divider;
  uint32_t source;
  uint32_t regval;

  /* Determine the active system clock source */

  switch (getreg32(MCXA1XX_SCG_CSR) & SCG_SCS_MASK)
    {
      case SCG_SCS_FIRC:
        source = BOARD_FIRC_FREQUENCY;
        break;

      case SCG_SCS_SIRC:
        source = MCXA1XX_SIRC_FREQUENCY;
        break;

#ifdef BOARD_SOSC_FREQUENCY
      case SCG_SCS_SOSC:
        source = BOARD_SOSC_FREQUENCY;
        break;
#endif

      case SCG_SCS_ROSC:
        source = MCXA1XX_FRO16K_FREQUENCY;
        break;

      default:

        /* Reserved encoding: the clock tree is not in a state we can
         * describe.
         */

        return 0;
    }

  /* Apply the AHB divider. The DIV field holds (divider - 1). */

  regval  = getreg32(MCXA1XX_SYSCON_AHBCLKDIV);
  divider = ((regval & SYSCON_CLKDIV_DIV_MASK) >>
             SYSCON_CLKDIV_DIV_SHIFT) + 1;

  return source / divider;
}
