/****************************************************************************
 * boards/arm/mcxa1xx/agam-florange/include/board.h
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

#ifndef __BOARDS_ARM_MCXA1XX_AGAM_FLORANGE_INCLUDE_BOARD_H
#define __BOARDS_ARM_MCXA1XX_AGAM_FLORANGE_INCLUDE_BOARD_H

/****************************************************************************
 * Included Files
 ****************************************************************************/

#include <nuttx/config.h>

/****************************************************************************
 * Pre-processor Definitions
 ****************************************************************************/

/* Clocking *****************************************************************/

/* This part has no PLL. The FIRC is the high-frequency source and can
 * generate 48, 64, 96 or 192 MHz directly; 96 MHz is the maximum rated
 * core frequency for the MCXA156, so the core runs from the FIRC
 * undivided.
 *
 * mcxa1xx_clockconfig() consumes these.
 */

#define BOARD_FIRC_FREQUENCY   96000000
#define BOARD_AHB_DIVIDER      1
#define BOARD_SLOW_DIVIDER     4

#define BOARD_CORECLK_FREQ     (BOARD_FIRC_FREQUENCY / BOARD_AHB_DIVIDER)
#define BOARD_SLOWCLK_FREQ     (BOARD_FIRC_FREQUENCY / BOARD_SLOW_DIVIDER)

/* LPUART clocking.
 *
 * The LPUARTs are clocked from FRO_12M rather than the FIRC so the baud
 * rate is unaffected by any later change to the core frequency.
 */

#define BOARD_LPUART_FREQUENCY 12000000

/* FlexCAN ******************************************************************/

/* CAN0 is clocked from FRO_12M, undivided. At 12 MHz a 1 Mbit/s bit time is
 * 12 time quanta, which is within the usable range; the source is chosen for
 * stability rather than resolution, so the bit timing does not move if the
 * core frequency is retuned.
 */

#define BOARD_FLEXCAN_CLKSEL     MRCC_CLKSEL_FRO_12M
#define BOARD_FLEXCAN_CLKDIV     1
#define BOARD_FLEXCAN_FREQUENCY  12000000

/* CAN0 pins on this board: P1_10 is CAN0_TXD and P1_11 is CAN0_RXD, both on
 * ALT11 (verified against the MCXA156 pinout table and the AFV3 schematic).
 * The RX pin needs its input buffer enabled.
 */

#define PIN_CAN0_TX  PORT_CFG(MCXA1XX_PORT1, 10, PORT_PCR_MUX_ALT11)
#define PIN_CAN0_RX  PORT_CFG(MCXA1XX_PORT1, 11, PORT_PCR_MUX_ALT11 | \
                                                 PORT_PCR_IBE)

/* LED definitions **********************************************************/

/* The Flo Range board drives a single status LED. Board logic maps the
 * NuttX LED states onto it.
 */

#define BOARD_NLEDS            1

#define BOARD_LED_BIT          (1 << 0)

/* LED states used by board_autoled_on()/off() */

#define LED_STARTED            0
#define LED_HEAPALLOCATE       1
#define LED_IRQSENABLED        2
#define LED_STACKCREATED       3
#define LED_INIRQ              4
#define LED_SIGNAL             5
#define LED_ASSERTION          6
#define LED_PANIC              7

#endif /* __BOARDS_ARM_MCXA1XX_AGAM_FLORANGE_INCLUDE_BOARD_H */
