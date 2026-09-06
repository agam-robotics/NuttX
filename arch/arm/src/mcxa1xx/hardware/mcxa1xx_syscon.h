/****************************************************************************
 * arch/arm/src/mcxa1xx/hardware/mcxa1xx_syscon.h
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

#ifndef __ARCH_ARM_SRC_MCXA1XX_HARDWARE_MCXA1XX_SYSCON_H
#define __ARCH_ARM_SRC_MCXA1XX_HARDWARE_MCXA1XX_SYSCON_H

/****************************************************************************
 * Included Files
 ****************************************************************************/

#include <nuttx/config.h>

#include "hardware/mcxa1xx_memorymap.h"

/****************************************************************************
 * Pre-processor Definitions
 ****************************************************************************/

/* SYSCON and MRCC share one base address (0x40091000): MRCC is the
 * peripheral clock/reset control window of the same block. Both names
 * appear in NXP's header with that identical address, so
 * MCXA1XX_MRCC0_BASE is used here as the block base.
 *
 * Offsets and bitfields from the SYSCON_Type layout in
 * devices/MCXA156/MCXA156.h.
 */

#define MCXA1XX_SYSCON_BASE            MCXA1XX_MRCC0_BASE

/* SYSCON Register Offsets **************************************************/

#define MCXA1XX_SYSCON_SLOWCLKDIV_OFFSET  0x0378  /* SLOW_CLK Clock Divider */
#define MCXA1XX_SYSCON_AHBCLKDIV_OFFSET   0x0380  /* System Clock Divider */
#define MCXA1XX_SYSCON_NVM_CTRL_OFFSET    0x0400  /* NVM Control */

/* SYSCON Register Addresses ************************************************/

#define MCXA1XX_SYSCON_SLOWCLKDIV \
  (MCXA1XX_SYSCON_BASE + MCXA1XX_SYSCON_SLOWCLKDIV_OFFSET)
#define MCXA1XX_SYSCON_AHBCLKDIV \
  (MCXA1XX_SYSCON_BASE + MCXA1XX_SYSCON_AHBCLKDIV_OFFSET)
#define MCXA1XX_SYSCON_NVM_CTRL \
  (MCXA1XX_SYSCON_BASE + MCXA1XX_SYSCON_NVM_CTRL_OFFSET)

/* SYSCON Register Bitfield Definitions *************************************/

/* Clock divider registers (AHBCLKDIV, SLOWCLKDIV).
 *
 * DIV is "divide by DIV+1". RESET/HALT/UNSTAB share the same layout in
 * both registers.
 */

#define SYSCON_CLKDIV_DIV_SHIFT     (0)       /* Bits 0-7: Clock divider value */
#define SYSCON_CLKDIV_DIV_MASK      (0xff << SYSCON_CLKDIV_DIV_SHIFT)
#  define SYSCON_CLKDIV_DIV(n)      (((n) - 1) << SYSCON_CLKDIV_DIV_SHIFT)
#define SYSCON_CLKDIV_RESET         (1 << 29) /* Bit 29: Reset the divider counter */
#define SYSCON_CLKDIV_HALT          (1 << 30) /* Bit 30: Halt the divider counter */
#define SYSCON_CLKDIV_UNSTAB        (1 << 31) /* Bit 31: Divider transition in progress */

/* NVM Control */

#define SYSCON_NVM_CTRL_DIS_FLASH_SPEC  (1 << 0)  /* Bit 0:  Disable flash speculation */
#define SYSCON_NVM_CTRL_DIS_DATA_SPEC   (1 << 1)  /* Bit 1:  Disable data speculation */
#define SYSCON_NVM_CTRL_FLASH_STALL_EN  (1 << 10) /* Bit 10: Flash stall enable */

#endif /* __ARCH_ARM_SRC_MCXA1XX_HARDWARE_MCXA1XX_SYSCON_H */
