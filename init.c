/*
Yet Another Antweight ESC
File: init.c

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

/**
 * Header files
 */
#include <c8051f330.h>  // Target SFR definitions
#include "sfrdefs.h"
#include "typedefs.h"
#include "board.h"
#include "init.h"

/**
 * fAdcInit
 * Initialise ADC to monitor battery voltage
 */
void fAdcInit(void)
{
    AMX0P = (dVMON_PORT << 3) | dVMON_BIT;  // P1.0
    AMX0N = dAMUX_GND;                      // GND
    ADC0CF = dAD0SC(31);                    // Clk = SYSCLK / 32, Result right-justified
	REF0CN = dREF_VDD;	                    // Use Vdd as Vref for ADC
    ADC0CN = dAD0EN | dAD0CM_BUSY;          // Enable ADC, convert on write to AD0BUSY
}

/**
 * fPCAInit
 * Initialise Programmable Counter Array for PWM output
 */
void fPCAInit(void)
{
	// Clear watchdog lock bit so that PCA mode can be set
    PCA0MD &= ~dWDLCK;
	// Start with PCA disabled
	PCA0CN = 0x00;
	// Clock = SYSCLK / 12       
	PCA0MD = dPCA_SYSCLK_DIV_12;
	// Enable 8-bit PWM mode
    PCA0CPM0 = dECOM | dPWM;
	// Reset PCA counter to zero
    PCA0L = 0x00;
    PCA0H = 0x00;
	// Set comparator 0 to 0% duty cycle - high byte gets reloaded into low byte which is used for PWM control
    PCA0CPL0 = 0x00;
    PCA0CPH0 = 0x00;
    // Enable CEX0 via crossbar
    XBR1 |= dCEX0_EN;
	// Enable PCA
    CR = 1;
}

/**
 * fPortInit
 * Initialise I/O Port control registers
 */
void fPortInit(void)
{
    // Set up port 0
    P0MDIN = dP0MDIN;
    P0 = dP0INIT;
    P0MDOUT = dP0MDOUT;
    P0SKIP = dP0SKIP;

    // Set up port 1
    P1MDIN = dP1MDIN;
    P1 = dP1INIT;
    P1MDOUT = dP1MDOUT;
	P1SKIP = dP1SKIP;

    // Set up interrupt
    IT01CF = dIT01CF;       // Map INT0 to R/C pulse input pin
    TCON |= dIT0;           // Set INT0 edge triggered
    PX0 = 1;                // Set INT0 to high priority
    EX0 = 1;                // Enable INT0

    // Set up crosssbar
    XBR0 = 0x00;            // No digital peripherals selected
    XBR1 = dXBARE;          // Enable crossbar and no pullups
}

/**
 * fSysclkInit
 * Set up system clock
 */
void fSysclkInit(void)
{
	PCA0MD &= ~dWDTE;                   // Disable watchdog
    OSCICN = dIOSCEN | dSYSCLK_DIV_1;   // Set internal oscillator to run at its maximum frequency
    CLKSEL = dINT_HF_OSC;               // SYSCLK = internal oscillator
}

/**
 * fTimerInit
 * Initialise all timers as they share control registers
 */
void fTimerInit(void)
{
    // Initialise Timer 0 to zero
    TH0 = 0x00;
    TL0 = 0x00;
    // Initialise Timer 1 to zero
	TH1 = 0x00;
    TL1 = 0x00;
	// Timer 0 16-bit mode gated by INT0
	// Timer 1 16-bit mode, free running
    TMOD = dT1M0 | dGATE0 | dT0M0;
    // Timers 0 & 1 clocked by SYSCLK/4, timer 2 clocked by SYSCLK
    CKCON = dT2ML | dTMR_SYSCLK_DIV_4;
    // Timer 1 interrupt high priority otherwise it doesn't trigger?
    PT1 = 1;
	// Timer 1 interrupt enabled
    ET1 = 1;
	// Timer 0 running with INT0 edge detection
    // Timer 1 running
    TCON |= dTR1 | dTR0 | dIT0;
    // Timer 2 reload set for 200us period
    TMR2RLL = 0xDB;
    TMR2RLH = 0xEC;
}
