/*
Yet Another Antweight ESC
File: board.h

Copyright (c) 2014, Gary Aylward gary.aylward@ntlworld.com
All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:
    * Redistributions of source code must retain the above copyright
      notice, this list of conditions and the following disclaimer.
    * Redistributions in binary form must reproduce the above copyright
      notice, this list of conditions and the following disclaimer in the
      documentation and/or other materials provided with the distribution.
    * Neither the name of Gary Aylward nor the
      names of the contributors may be used to endorse or promote products
      derived from this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL GARY AYLWARD BE LIABLE FOR ANY
DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

#ifndef _BOARD_H_
#define _BOARD_H_

/*
 * Copy and modify this file to define a different board type.
 * The software assumes that all I/O will be on ports 0 and 1.
 * Since port 2 is only a single bit and shared with the C2
 * interface, this seems likely.
 */

/* Definitions for HobbyWing FlyFun 6A */

/* RC pulse input */
#define dRC_PULSE_PORT      0
#define dRC_PULSE_BIT       4
#define dRC_PULSE2_PORT     0   // HobbyWing FlyFun 6A has R/C pulse routed to 2 pins (???)
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
