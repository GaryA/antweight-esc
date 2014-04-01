/*
Yet Another Antweight ESC
File: main.c

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
#include "init.h"       // Initialisation functions
#include "motor.h"      // Motor drive functions

/**
 * Global variables
 */
bool global_vSysTick;
bool global_vNewPulse;
unsigned int global_vRcPulse;

/**
 * Funtion prototypes
 */
bool fCheckBatteryVoltage(void);
tState fProcessRCPulse(uint8_t *);
void fSetControls(tState, uint8_t);
void fWait(void);

/**
 * SFR bit definitions, must be global
 */
sbit vInput1 = P0^4;
sbit vInput2 = P0^5;

/**
 * main
 */
void main(void)
{
    tState vNewState;
    tState vThisState;
    uint8_t vTimeOut;
    uint8_t vDrive;
    bool vUnderVoltage;

    // Initialise variables
    global_vSysTick = false;
    global_vNewPulse = false;
    global_vRcPulse = 0;
    vNewState = eBrake;
    vThisState = eBrake;
    vTimeOut = 50;
    vDrive = 0;
    vUnderVoltage = false;
    
    // Call initialisation functions
    fSysclkInit();
    fPortInit();
    fTimerInit();
    fPCAInit();
    fAdcInit();
    
    // Enable global interrupts
    EA = 1;
    while (1)
    {
        // Check for new RC pulse
        if (global_vNewPulse)
        {
            global_vNewPulse = false;
            vTimeOut = 0;
            
            //Process RC pulse
            vNewState = fProcessRCPulse(&vDrive);
        }

        if (global_vSysTick)    // Run background loop every 10ms
        {
            global_vSysTick = false;
            vTimeOut++;
            // Check battery voltage if ADC conversion is complete
            vUnderVoltage = fCheckBatteryVoltage();
            
            if ((vTimeOut >= 50) || (vUnderVoltage == true))
            {
                vTimeOut = 50;
                // Shut down (failsafe) as signal has been lost or battery voltage is too low
                fDisablePwm();          // Disable any PWM drives
                fTurnOffAllLoSide();    // Turn all outputs off
                fTurnOffAllHiSide();
                PCA0CPH0 = 0x00;        // Set duty cycle to zero                
            }
            else
            {
                // Do state transition
                switch (vThisState)
                {
                    case eBrake: // Brake
                        switch (vNewState)
                        {
                            case eBrake: // Brake
                                break;
                            case eForward: // Forward
                                fTurnOffCh1HiSide();    // Turn brake (Ch1 hi) off
                                fWait();
                                break;
                            case eReverse: // Reverse
                                fTurnOffCh2HiSide();    // Turn brake (Ch2 hi) off
                                fWait();
                                break;
                            case eCoast: // Coast
                            default:
                                break;
                        }
                        vThisState = vNewState;
                        break;
                    case eForward: // Forward
                        switch (vNewState)
                        {
                            case eBrake: // Brake
                                fDisablePwm();
                                fTurnOffCh1LoSide();    // Turn PWM (Ch1 lo) off
                                fWait();
                                vThisState = eBrake;
                                break;
                            case eForward: // Forward
                                vThisState = eForward;
                                break;
                            case eReverse: // Reverse
                                fDisablePwm();
                                fTurnOffCh1LoSide();    // Turn PWM (Ch1 lo) off
                                fWait();
                                vThisState = eBrake; // Go via brake state
                                break;
                            case eCoast: // Coast
                            default:
                                vThisState = eCoast;
                                break;
                        }
                        break;
                    case eReverse: // Reverse
                        switch (vNewState)
                        {
                            case eBrake: // Brake
                                fDisablePwm();
                                fTurnOffCh2LoSide();    // Turn PWM (Ch2 lo) off
                                fWait();
                                vThisState = eBrake;
                                break;
                            case eForward: // Forward
                                fDisablePwm();
                                fTurnOffCh2LoSide();    // Turn PWM (Ch2 lo) off
                                fWait();
                                vThisState = eBrake; // Go via brake state
                                break;
                            case eReverse: // Reverse
                                vThisState = eReverse;
                                break;
                            case eCoast: // Coast
                            default:
                                vThisState = eCoast;
                                break;
                        }
                        break;
                    case eCoast: // Coast
                    default:
                        vThisState = vNewState;
                        break;
                }
                // Set controls for current state
                fSetControls(vThisState, vDrive);
            }
        }
    }
}

/**
 * fCheckBatteryVoltage
 * Check battery voltage - return true if voltage below undervoltage limit
 * This function has to be called every 10ms timer tick for the filter to work correctly
 */
bool fCheckBatteryVoltage(void)
{
    uint8_t vUnderVoltageCount;
    bool vUnderVoltage;
    uint16_t vAdcResult;
    
    vAdcResult = 0;
    vUnderVoltage = false;
    vUnderVoltageCount = 0;

    if ((ADC0CN & dAD0INT) == dAD0INT)
    {
        ADC0CN &= ~dAD0INT;
        vAdcResult = (ADC0H << 8) | ADC0L;
        if (vAdcResult < dVMON_THRESHOLD)
        {
            vUnderVoltageCount++;
        }
        else
        {
            vUnderVoltageCount = 0;
            vUnderVoltage = false;
            fTurnOffSpareChannel();         // Turn off spare channel FETs
        }
        if (vUnderVoltageCount >= 10)       // Battery voltage low for > 100ms
        {
            vUnderVoltageCount = 10;
            vUnderVoltage = true;           // Force shutdown
            fTurnOnSpareChannelHiSide();    // Turn on spare high-side FET to drive LED
        }
    }
    ADC0CN |= dAD0BUSY; // Start ADC conversion
    return(vUnderVoltage);
}

/**
 * fProcessRCPulse
 * Process the RC pulse length to determine new state and drive value
 */
tState fProcessRCPulse(uint8_t *pDrive)
{
    tState vNewState;
    
    if (global_vRcPulse <= d0_8MS)    // Pulse < 0.8ms
    {
        vNewState = eCoast;
        *pDrive = 0;
    }
    else if ((global_vRcPulse > d0_8MS) && (global_vRcPulse <= d1_0MS)) // Pulse < 1.0ms
    {
        vNewState = eReverse;
        *pDrive = 0xFF;
    }
    else if ((global_vRcPulse > d1_0MS) && (global_vRcPulse <= d1_49MS)) // Pulse < 1.49ms
    {
        vNewState = eReverse;
        *pDrive = (d1_49MS - global_vRcPulse) / dSCALE_FACTOR;
    }
    else if ((global_vRcPulse > d1_49MS) && (global_vRcPulse <= d1_51MS)) // Pulse < 1.51ms
    {
        vNewState = eBrake;
        *pDrive = 0;
    }
    else if ((global_vRcPulse > d1_51MS) && (global_vRcPulse <= d2_0MS))    // Pulse < 2ms
    {
        vNewState = eForward;
        *pDrive = (global_vRcPulse - d1_51MS) / dSCALE_FACTOR;
    }
    else if ((global_vRcPulse > d2_0MS) && (global_vRcPulse <= d2_2MS))   // Pulse < 2.2ms
    {
        vNewState = eForward;
        *pDrive = 0xFF;
    }
    else if (global_vRcPulse > d2_2MS)   // Pulse > 2.2ms
    {
        vNewState = eCoast;
        *pDrive = 0;
    }
    return(vNewState);
}

/**
 * fSetControls
 * Set outputs and duty cycle for current state
 */
void fSetControls(tState pThisState, uint8_t pDrive)
{
    switch (pThisState)
    {
        case eBrake: // Brake
            fDisablePwm();          // Disable all PWM drives
            fTurnOnCh1HiSide();     // Turn on both high side FETs
            fTurnOnCh2HiSide();
            pDrive = 0;             // Set duty cycle to zero
            break;
        case eForward: // Forward
            fEnablePwmCh1LoSide();  // Enable PWM on channel 1
            fTurnOnCh2HiSide();     // Turn on channel 2 high side FET
            break;
        case eReverse: // Reverse
            fEnablePwmCh2LoSide();  // Enable PWM on channel 2
            fTurnOnCh1HiSide();     // Turn on channel 1 high side FET
            break;
        case eCoast: // Coast
        default:
            fDisablePwm();          // Disable all PWM drives
            fTurnOffAllLoSide();    // Turn all outputs off
            fTurnOffAllHiSide();
            pDrive = 0;             // Set duty cycle to zero
            break;
    }
    // Set duty cycle
    PCA0CPH0 = pDrive;
}

/**
 * fWait
 * Short delay - approx 200us to ensure one FET is off before turning the other on
 */
void fWait(void)
{
    TMR2H = 0xEC;                       // Reset counter
    TMR2L = 0xDB;
    TMR2CN = dTR2;                      // Enable counter
    while ((TMR2CN & dTF2H) != dTF2H);  // Wait for timeout
    TMR2CN = 0x00;                      // Clear timeout flag and disable counter
}

/**
 * fInt0Isr
 * INT0 ISR - capture timer 0 count, reset timer 0, set new pulse flag
 */
void fInt0Isr(void) interrupt 0
{
    global_vRcPulse = (TH0 << 8) | TL0;
    global_vNewPulse = true;
    TL0 = 0x00;
    TH0 = 0x00;
}

/**
 * fTimer1Isr
 * Timer 1 ISR - set system tick flag
 */
void fTimer1Isr(void) interrupt 3
{
    global_vSysTick = true;
}

