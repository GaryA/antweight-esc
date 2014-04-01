/*
Yet Another Antweight ESC
File: motor.c

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

/**
 * Header files
 */
#include <c8051f330.h>  // Target SFR definitions
#include "sfrdefs.h"
#include "typedefs.h"   // C99 type definitions
#include "board.h"
#include "init.h"
#include "motor.h"

/**
 * fDisablePwm
 * Disable PWM output by setting crossbar to skip all output pins
 */
void fDisablePwm(void)
{
#if dMOTOR_A_LO_PORT
    P1SKIP |= (1 << dMOTOR_A_LO_BIT);
#else // dMOTOR_A_LO_PORT
    P0SKIP |= (1 << dMOTOR_A_LO_BIT);
#endif

#if dMOTOR_B_LO_PORT
    P1SKIP |= (1 << dMOTOR_B_LO_BIT);
#else // dMOTOR_B_LO_PORT
    P0SKIP |= (1 << dMOTOR_B_LO_BIT);
#endif

#if dMOTOR_C_LO_PORT
    P1SKIP |= (1 << dMOTOR_C_LO_BIT);
#else // dMOTOR_C_LO_PORT
    P0SKIP |= (1 << dMOTOR_C_LO_BIT);
#endif
}

/**
 * fEnablePwmCh1LoSide
 * Enable PWM drive to channel 1 low-side FET
 */
void fEnablePwmCh1LoSide(void)
{
#if dMOTOR_B_LO_PORT
    P1SKIP &= ~(1 << dMOTOR_B_LO_BIT);
#else // dMOTOR_B_LO_PORT
    P0SKIP &= ~(1 << dMOTOR_B_LO_BIT);
#endif
}

/**
 * fEnablePwmCh2LoSide
 * Enable PWM drive to channel 2 low-side FET
 */
void fEnablePwmCh2LoSide(void)
{
#if dMOTOR_C_LO_PORT
    P1SKIP &= ~(1 << dMOTOR_C_LO_BIT);
#else // dMOTOR_C_LO_PORT
    P0SKIP &= ~(1 << dMOTOR_C_LO_BIT);
#endif
}

/**
 * fTurnOffAllHiSide
 * Turn off all high-side FETs
 */
void fTurnOffAllHiSide(void)
{
#if dMOTOR_B_HI_PORT
#if dMOTOR_B_HI_POL
    P1 &= ~(1 << dMOTOR_B_HI_BIT);
#else // dMOTOR_B_HI_POL
    P1 |= (1 << dMOTOR_B_HI_BIT);
#endif
#else // dMOTOR_B_HI_PORT
#if dMOTOR_B_HI_POL
    P0 &= ~(1 << dMOTOR_B_HI_BIT);
#else // dMOTOR_B_HI_POL
    P0 |= (1 << dMOTOR_B_HI_BIT);
#endif
#endif // dMOTOR_B_HI_PORT

#if dMOTOR_C_HI_PORT
#if dMOTOR_C_HI_POL
    P1 &= ~(1 << dMOTOR_C_HI_BIT);
#else // dMOTOR_C_HI_POL
    P1 |= (1 << dMOTOR_C_HI_BIT);
#endif
#else // dMOTOR_C_HI_PORT
#if dMOTOR_C_HI_POL
    P0 &= ~(1 << dMOTOR_C_HI_BIT);
#else // dMOTOR_C_HI_POL
    P0 |= (1 << dMOTOR_C_HI_BIT);
#endif
#endif // dMOTOR_C_HI_PORT
}

/**
 * fTurnOffAllLoSide
 * Turn off all low side FETs
 */
void fTurnOffAllLoSide(void)
{
#if dMOTOR_B_LO_PORT
#if dMOTOR_B_LO_POL
    P1 &= ~(1 << dMOTOR_B_LO_BIT);
#else // dMOTOR_B_LO_POL
    P1 |= (1 << dMOTOR_B_LO_BIT);
#endif
#else // dMOTOR_B_LO_PORT
#if dMOTOR_B_LO_POL
    P0 &= ~(1 << dMOTOR_B_LO_BIT);
#else // dMOTOR_B_LO_POL
    P0 |= (1 << dMOTOR_B_LO_BIT);
#endif
#endif // dMOTOR_B_LO_PORT

#if dMOTOR_C_LO_PORT
#if dMOTOR_C_LO_POL
    P1 &= ~(1 << dMOTOR_C_LO_BIT);
#else // dMOTOR_C_LO_POL
    P1 |= (1 << dMOTOR_C_LO_BIT);
#endif
#else // dMOTOR_C_LO_PORT
#if dMOTOR_C_LO_POL
    P0 &= ~(1 << dMOTOR_C_LO_BIT);
#else // dMOTOR_C_LO_POL
    P0 |= (1 << dMOTOR_C_LO_BIT);
#endif
#endif // dMOTOR_C_LO_PORT
}

/**
 * fTurnOffCh1HiSide
 * Turn off high-side FET for channel 1
 */
void fTurnOffCh1HiSide(void)
{
#if dMOTOR_B_HI_PORT
#if dMOTOR_B_HI_POL
    P1 &= ~(1 << dMOTOR_B_HI_BIT);
#else // dMOTOR_B_HI_POL
    P1 |= (1 << dMOTOR_B_HI_BIT);
#endif
#else // dMOTOR_B_HI_PORT
#if dMOTOR_B_HI_POL
    P0 &= ~(1 << dMOTOR_B_HI_BIT);
#else // dMOTOR_B_HI_POL
    P0 |= (1 << dMOTOR_B_HI_BIT);
#endif
#endif // dMOTOR_B_HI_PORT
}

/**
 * fTurnOffCh1LoSide
 * Turn off low-side FET for channel 1
 */
void fTurnOffCh1LoSide(void)
{
#if dMOTOR_B_LO_PORT
#if dMOTOR_B_LO_POL
    P1 &= ~(1 << dMOTOR_B_LO_BIT);
#else // dMOTOR_B_LO_POL
    P1 |= (1 << dMOTOR_B_LO_BIT);
#endif
#else // dMOTOR_B_LO_PORT
#if dMOTOR_B_LO_POL
    P0 &= ~(1 << dMOTOR_B_LO_BIT);
#else // dMOTOR_B_LO_POL
    P0 |= (1 << dMOTOR_B_LO_BIT);
#endif
#endif // dMOTOR_B_LO_PORT
}

/**
 * fTurnOffCh2HiSide
 * Turn off high-side FET for channel 2
 */
void fTurnOffCh2HiSide(void)
{
#if dMOTOR_C_HI_PORT
#if dMOTOR_C_HI_POL
    P1 &= ~(1 << dMOTOR_C_HI_BIT);
#else // dMOTOR_C_HI_POL
    P1 |= (1 << dMOTOR_C_HI_BIT);
#endif
#else // dMOTOR_C_HI_PORT
#if dMOTOR_C_HI_POL
    P0 &= ~(1 << dMOTOR_C_HI_BIT);
#else // dMOTOR_C_HI_POL
    P0 |= (1 << dMOTOR_C_HI_BIT);
#endif
#endif // dMOTOR_C_HI_PORT
}

/**
 * fTurnOffCh2LoSide
 * Turn off low-side FET for channel 2
 */
void fTurnOffCh2LoSide(void)
{
#if dMOTOR_C_LO_PORT
#if dMOTOR_C_LO_POL
    P1 &= ~(1 << dMOTOR_C_LO_BIT);
#else // dMOTOR_C_LO_POL
    P1 |= (1 << dMOTOR_C_LO_BIT);
#endif
#else // dMOTOR_C_LO_PORT
#if dMOTOR_C_LO_POL
    P0 &= ~(1 << dMOTOR_C_LO_BIT);
#else // dMOTOR_C_LO_POL
    P0 |= (1 << dMOTOR_C_LO_BIT);
#endif
#endif // dMOTOR_C_LO_PORT
}

/**
 * fTurnOffSpareChannel
 * Turn off FETs for spare channel
 */
void fTurnOffSpareChannel(void)
{
#if dMOTOR_A_HI_PORT
#if dMOTOR_A_HI_POL
    P1 &= ~(1 << dMOTOR_A_HI_BIT);
#else // dMOTOR_A_HI_POL
    P1 |= (1 << dMOTOR_A_HI_BIT);
#endif
#else // dMOTOR_A_HI_PORT
#if dMOTOR_A_HI_POL
    P0 &= ~(1 << dMOTOR_A_HI_BIT);
#else // dMOTOR_A_HI_POL
    P0 |= (1 << dMOTOR_A_HI_BIT);
#endif
#endif // dMOTOR_A_HI_PORT

#if dMOTOR_A_LO_PORT
#if dMOTOR_A_LO_POL
    P1 &= ~(1 << dMOTOR_A_LO_BIT);
#else // dMOTOR_A_LO_POL
    P1 |= (1 << dMOTOR_A_LO_BIT);
#endif
#else // dMOTOR_A_LO_PORT
#if dMOTOR_A_LO_POL
    P0 &= ~(1 << dMOTOR_A_LO_BIT);
#else // dMOTOR_A_LO_POL
    P0 |= (1 << dMOTOR_A_LO_BIT);
#endif
#endif // dMOTOR_A_LO_PORT
}

/**
 * fTurnOnCh1HiSide
 * Turn on high-side FET for channel 1
 */
void fTurnOnCh1HiSide(void)
{
#if dMOTOR_B_HI_PORT
#if dMOTOR_B_HI_POL
    P1 |= (1 << dMOTOR_B_HI_BIT);
#else // dMOTOR_B_HI_POL
    P1 &= ~(1 << dMOTOR_B_HI_BIT);
#endif
#else // dMOTOR_B_HI_PORT
#if dMOTOR_B_HI_POL
    P0 |= (1 << dMOTOR_B_HI_BIT);
#else // dMOTOR_B_HI_POL
    P0 &= ~(1 << dMOTOR_B_HI_BIT);
#endif
#endif // dMOTOR_B_HI_PORT
}

/**
 * fTurnOnCh2HiSide
 * Turn on high-side FET for channel 2
 */
void fTurnOnCh2HiSide(void)
{
#if dMOTOR_C_HI_PORT
#if dMOTOR_C_HI_POL
    P1 |= (1 << dMOTOR_C_HI_BIT);
#else // dMOTOR_C_HI_POL
    P1 &= ~(1 << dMOTOR_C_HI_BIT);
#endif
#else // dMOTOR_C_HI_PORT
#if dMOTOR_C_HI_POL
    P0 |= (1 << dMOTOR_C_HI_BIT);
#else // dMOTOR_C_HI_POL
    P0 &= ~(1 << dMOTOR_C_HI_BIT);
#endif
#endif // dMOTOR_C_HI_PORT
}

/**
 * fTurnOnSpareChannelHiSide
 * Turn on high-side FET for spare channel
 */
void fTurnOnSpareChannelHiSide(void)
{
#if dMOTOR_A_HI_PORT
#if dMOTOR_A_HI_POL
    P1 |= (1 << dMOTOR_A_HI_BIT);
#else // dMOTOR_A_HI_POL
    P1 &= ~(1 << dMOTOR_A_HI_BIT);
#endif
#else // dMOTOR_A_HI_PORT
#if dMOTOR_A_HI_POL
    P0 |= (1 << dMOTOR_A_HI_BIT);
#else // dMOTOR_A_HI_POL
    P0 &= ~(1 << dMOTOR_A_HI_BIT);
#endif
#endif // dMOTOR_A_HI_PORT
}
