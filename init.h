/*
Yet Another Antweight ESC
File: init.h

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

#ifndef _INIT_H_
#define _INIT_H_

/**
 * Port definitions
 */

#if dVMON_PORT
#define dP0MDIN1    0
#define dP1MDIN1    (1 << dVMON_BIT)
#else
#define dP0MDIN1    (1 << dVMON_BIT)
#define dP1MDIN1    0
#endif // dVMON_PORT
#if dMOTOR_A_MON_PORT
#define dP0MDIN2    0
#define dP1MDIN2    (1 << dMOTOR_A_MON_BIT)
#else
#define dP0MDIN2    (1 << dMOTOR_A_MON_BIT)
#define dP1MDIN2    0
#endif // dMOTOR_A_MON_PORT
#if dMOTOR_B_MON_PORT
#define dP0MDIN3    0
#define dP1MDIN3    (1 << dMOTOR_B_MON_BIT)
#else
#define dP0MDIN3    (1 << dMOTOR_B_MON_BIT)
#define dP1MDIN3    0
#endif // dMOTOR_B_MON_PORT
#if dMOTOR_C_MON_PORT
#define dP0MDIN4    0
#define dP1MDIN4    (1 << dMOTOR_C_MON_BIT)
#else
#define dP0MDIN4    (1 << dMOTOR_C_MON_BIT)
#define dP1MDIN4    0
#endif // dMOTOR_C_MON_PORT
#if dMOTOR_SUM_MON_PORT
#define dP0MDIN5    0
#define dP1MDIN5    (1 << dMOTOR_SUM_MON_BIT)
#else
#define dP0MDIN5    (1 << dMOTOR_SUM_MON_BIT)
#define dP1MDIN5    0
#endif // dMOTOR_SUM_MON_PORT

// Set analog input pins to analog mode, plus RC input if this is a simulation target
// ... to work around the simulator bug
#ifdef SIMULATION
#if dRC_PULSE_PORT
#define dP0MDIN     ~(dP0MDIN1 | dP0MDIN2 | dP0MDIN3 | dP0MDIN4 | dP0MDIN5)
#define dP1MDIN     ~(dP1MDIN1 | dP1MDIN2 | dP1MDIN3 | dP1MDIN4 | dP1MDIN5 | (1 << dRC_PULSE_BIT))
#else // dRC_PULSE_PORT
#define dP0MDIN     ~(dP0MDIN1 | dP0MDIN2 | dP0MDIN3 | dP0MDIN4 | dP0MDIN5 | (1 << dRC_PULSE_BIT))
#define dP1MDIN     ~(dP1MDIN1 | dP1MDIN2 | dP1MDIN3 | dP1MDIN4 | dP1MDIN5)
#endif // dRC_PULSE_PORT
#else // SIMULATION
#define dP0MDIN     ~(dP0MDIN1 | dP0MDIN2 | dP0MDIN3 | dP0MDIN4 | dP0MDIN5)
#define dP1MDIN     ~(dP1MDIN1 | dP1MDIN2 | dP1MDIN3 | dP1MDIN4 | dP1MDIN5)
#endif // SIMULATION

// #define dP0MDIN     0xF2    // Set PORT0 all digital except P0.3, P0.2, P0.0
// #define dP0_RC_IN   0x10    // Set P0.4 as (analog) input for simulation
// #define dP0SKIP     0xFF    // Crossbar skips all of port 0
// #define dP1MDIN     0xFE    // Set PORT1 all digital except P1.0
// #define dP1SKIP     0xDF    // Crossbar maps CEX0 to Motor B Low to start
// #define dP0MDOUT    0x00    // Set port 0 to all inputs
// #define dP1MDOUT    0xFC    // Set port 1 to all outputs except P1.1, P1.0

#if dMOTOR_A_HI_PORT
#define dP0MDOUT1   0
#define dP1MDOUT1   (1 << dMOTOR_A_HI_BIT)
#else
#define dP0MDOUT1   (1 << dMOTOR_A_HI_BIT)
#define dP1MDOUT1   0
#endif // dMOTOR_A_HI_PORT
#if dMOTOR_A_LO_PORT
#define dP0MDOUT2   0
#define dP1MDOUT2   (1 << dMOTOR_A_LO_BIT)
#else
#define dP0MDOUT2   (1 << dMOTOR_A_LO_BIT)
#define dP1MDOUT2   0
#endif // dMOTOR_A_LO_PORT
#if dMOTOR_B_HI_PORT
#define dP0MDOUT3   0
#define dP1MDOUT3   (1 << dMOTOR_B_HI_BIT)
#else
#define dP0MDOUT3   (1 << dMOTOR_B_HI_BIT)
#define dP1MDOUT3   0
#endif // dMOTOR_B_HI_PORT
#if dMOTOR_B_LO_PORT
#define dP0MDOUT4   0
#define dP1MDOUT4   (1 << dMOTOR_B_LO_BIT)
#else
#define dP0MDOUT4   (1 << dMOTOR_B_LO_BIT)
#define dP1MDOUT4   0
#endif // dMOTOR_B_LO_PORT
#if dMOTOR_C_HI_PORT
#define dP0MDOUT5   0
#define dP1MDOUT5   (1 << dMOTOR_C_HI_BIT)
#else
#define dP0MDOUT5   (1 << dMOTOR_C_HI_BIT)
#define dP1MDOUT5   0
#endif // dMOTOR_C_HI_PORT
#if dMOTOR_C_LO_PORT
#define dP0MDOUT6   0
#define dP1MDOUT6   (1 << dMOTOR_C_LO_BIT)
#else
#define dP0MDOUT6   (1 << dMOTOR_C_LO_BIT)
#define dP1MDOUT6   0
#endif // dMOTOR_C_LO_PORT

//Set motor drive pins as outputs, everything else as inputs
#define dP0MDOUT    (dP0MDOUT1 | dP0MDOUT2 | dP0MDOUT3 | dP0MDOUT4 | dP0MDOUT5 | dP0MDOUT6)
#define dP1MDOUT    (dP1MDOUT1 | dP1MDOUT2 | dP1MDOUT3 | dP1MDOUT4 | dP1MDOUT5 | dP1MDOUT6)

// Turning outputs off involves managing active high and active low signals...
// If bit is an input, or is an inverted output, set it high
#if dMOTOR_A_HI_POL
#if dMOTOR_A_HI_PORT
#define dP0INIT1    0
#define dP1INIT1    (1 << dMOTOR_A_HI_BIT)
#else // dMOTOR_A_HI_PORT
#define dP0INIT1    (1 << dMOTOR_A_HI_BIT)
#define dP1INIT1    0
#endif // dMOTOR_A_HI_PORT
#else //dMOTOR_A_HI_POL
#define dP0INIT1    0
#define dP1INIT1    0
#endif // dMOTOR_A_HI_POL

#if dMOTOR_A_LO_POL
#if dMOTOR_A_LO_PORT
#define dP0INIT2    0
#define dP1INIT2    (1 << dMOTOR_A_LO_BIT)
#else // dMOTOR_A_LO_PORT
#define dP0INIT2    (1 << dMOTOR_A_LO_BIT)
#define dP1INIT2    0
#endif // dMOTOR_A_LO_PORT
#else // dMOTOR_A_LO_POL
#define dP0INIT2    0
#define dP1INIT2    0
#endif // dMOTOR_A_LO_POL

#if dMOTOR_B_HI_POL
#if dMOTOR_B_HI_PORT
#define dP0INIT3    0
#define dP1INIT3    (1 << dMOTOR_B_HI_BIT)
#else // dMOTOR_B_HI_PORT
#define dP0INIT3    (1 << dMOTOR_B_HI_BIT)
#define dP1INIT3    0
#endif // dMOTOR_B_HI_PORT
#else // dMOTOR_B_HI_POL
#define dP0INIT3    0
#define dP1INIT3    0
#endif // dMOTOR_B_HI_POL

#if dMOTOR_B_LO_POL
#if dMOTOR_B_LO_PORT
#define dP0INIT4    0
#define dP1INIT4    (1 << dMOTOR_B_LO_BIT)
#else // dMOTOR_B_LO_PORT
#define dP0INIT4    (1 << dMOTOR_B_LO_BIT)
#define dP1INIT4    0
#endif // dMOTOR_B_LO_PORT
#else // dMOTOR_B_LO_POL
#define dP0INIT4    0
#define dP1INIT4    0
#endif // dMOTOR_B_LO_POL

#if dMOTOR_C_HI_POL
#if dMOTOR_C_HI_PORT
#define dP0INIT5    0
#define dP1INIT5    (1 << dMOTOR_C_HI_BIT)
#else // dMOTOR_C_HI_PORT
#define dP0INIT5    (1 << dMOTOR_C_HI_BIT)
#define dP1INIT5    0
#endif // dMOTOR_C_HI_PORT
#else // dMOTOR_C_HI_POL
#define dP0INIT5    0
#define dP1INIT5    0
#endif // dMOTOR_C_HI_POL

#if dMOTOR_C_LO_POL
#if dMOTOR_C_LO_PORT
#define dP0INIT6    0
#define dP1INIT6    (1 << dMOTOR_C_LO_BIT)
#else // dMOTOR_C_LO_PORT
#define dP0INIT6    (1 << dMOTOR_C_LO_BIT)
#define dP1INIT6    0
#endif // dMOTOR_C_LO_PORT
#else // dMOTOR_C_LO_POL
#define dP0INIT6    0
#define dP1INIT6    0
#endif // dMOTOR_C_LO_POL

#define dP0INIT     ~(dP0INIT1 | dP0INIT2 | dP0INIT3 | dP0INIT4 | dP0INIT5 | dP0INIT6)
#define dP1INIT     ~(dP1INIT1 | dP1INIT2 | dP1INIT3 | dP1INIT4 | dP1INIT5 | dP1INIT6) 

// Crossbar maps CEX0 to Motor B Low to start
#if dMOTOR_B_LO_PORT
#define dP0SKIP     0xFF
#define dP1SKIP     ~(1 << dMOTOR_B_LO_BIT)
#else
#define dP0SKIP     ~(1 << dMOTOR_B_LO_BIT)
#define dP1SKIP     0xFF
#endif // dMOTOR_B_LO_PORT

#define dIT01CF     dRC_PULSE_BIT   // Set INT0 active low on RC input pin
#define dTCON       0x01            // Set INT0 edge triggered

// Define pulse width thresholds in timer ticks
#define d0_8MS      4900
#define d1_0MS      6125
#define d1_49MS     9126
#define d1_51MS     9249
#define d2_0MS      12250
#define d2_2MS      13475

// Define pulse width scaling
#define dSCALE_FACTOR   12

/**
 * Funtion prototypes
 */
void fAdcInit(void);
void fPCAInit(void);
void fPortInit(void);
void fSysclkInit(void);
void fTimerInit(void);

#endif