/*
Yet Another Antweight ESC
File: board.h

    Copyright (c) 2014, Gary Aylward gary.aylward@ntlworld.com
    All rights reserved.

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.

*/

#ifndef _BOARD_H_
#define _BOARD_H_

/*
 * Copy and modify this file to define a different board type.
 * The software assumes that all I/O will be on ports 0 and 1.
 * Since port 2 is only a single bit and shared with the C2
 * interface, this seems likely.
 */

/* Definitions for Generic target */

/* RC pulse input */
#define dRC_PULSE_PORT      0
#define dRC_PULSE_BIT       4
#define dRC_PULSE2_PORT     0   // R/C pulse may be routed to 2 pins (???)
#define dRC_PULSE2_BIT      5

/* Voltage monitor */
#define dVMON_PORT          1
#define dVMON_BIT           0
#define dVMON_DIVIDER       11  // Voltage divider ratio
#define dVMON_VOLTAGE       5.5 // Battery voltage in volts
#define dVMON_THRESHOLD     (uint16_t)(dVMON_VOLTAGE * (1024 / (3.3 * dVMON_DIVIDER)))

/* Motor drive B (motor +) */
#define dMOTOR_B_HI_PORT    1
#define dMOTOR_B_HI_BIT     4
#define dMOTOR_B_HI_POL     1   // 1 = active high, 0 = active low
#define dMOTOR_B_LO_PORT    1
#define dMOTOR_B_LO_BIT     5
#define dMOTOR_B_LO_POL     0

/* Motor drive C (motor -) */
#define dMOTOR_C_HI_PORT    1
#define dMOTOR_C_HI_BIT     2
#define dMOTOR_C_HI_POL     1
#define dMOTOR_C_LO_PORT    1
#define dMOTOR_C_LO_BIT     3
#define dMOTOR_C_LO_POL     0

/* Motor drive A (spare) */
#define dMOTOR_A_HI_PORT    1
#define dMOTOR_A_HI_BIT     6
#define dMOTOR_A_HI_POL     1
#define dMOTOR_A_LO_PORT    1
#define dMOTOR_A_LO_BIT     7
#define dMOTOR_A_LO_POL     0

/* Motor monitor A */
#define dMOTOR_A_MON_PORT   0
#define dMOTOR_A_MON_BIT    0   // Not used

/* Motor monitor B */
#define dMOTOR_B_MON_PORT   0
#define dMOTOR_B_MON_BIT    1   // Not used

/* Motor monitor C */
#define dMOTOR_C_MON_PORT   0
#define dMOTOR_C_MON_BIT    2   // Not used

/* Motor monitor sum */
#define dMOTOR_SUM_MON_PORT 0
#define dMOTOR_SUM_MON_BIT  3   // Not used

/* Unused pins (?) */
#define dUNUSED1_PORT       0
#define dUNUSED1_BIT        6
#define dUNUSED2_PORT       0
#define dUNUSED2_BIT        7
#define dUNUSED3_PORT       1
#define dUNUSED3_BIT        1
#define dUNUSED4_PORT       2
#define dUNUSED4_BIT        0

#endif
