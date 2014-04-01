/*
Yet Another Antweight ESC
File: sfrdefs.h

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

#ifndef _SFRDEFS_H_
#define _SFRDEFS_H_

/* AMX0P, AMX0N */
#define dAMUX_P0_0          0
#define dAMUX_P0_1          1
#define dAMUX_P0_2          2
#define dAMUX_P0_3          3
#define dAMUX_P0_4          4
#define dAMUX_P0_5          5
#define dAMUX_P0_6          6
#define dAMUX_P0_7          7
#define dAMUX_P1_0          8
#define dAMUX_P1_1          9
#define dAMUX_P1_2          10
#define dAMUX_P1_3          11
#define dAMUX_P1_4          12
#define dAMUX_P1_5          13
#define dAMUX_P1_6          14
#define dAMUX_P1_7          15
#define dAMUX_TEMP          16
#define dAMUX_VDD           17
#define dAMUX_VREF          16
#define dAMUX_GND           17

/* ADC0CF */
#define dAD0SC(n)           ((n)<< 3)
#define dAD0LJST            (1 << 2)

/* AD0CN */
#define dAD0EN              (1 << 7)
#define dAD0TM              (1 << 6)
#define dAD0INT             (1 << 5)
#define dAD0BUSY            (1 << 4)
#define dAD0WINT            (1 << 3)
#define dAD0CM_BUSY         0
#define dAD0CM_T0           1
#define dAD0CM_T2           2
#define dAD0CM_T1           3
#define dAD0CM_CNVSTR       4
#define dAD0CM_T3           5

/* REF0CN */
#define dREF_VDD            (1 << 3)
#define dREF_VREF           (0 << 3)
#define dTEMPE              (1 << 2)
#define dBIASE              (1 << 1)
#define dREFBE              (1 << 0)

/* IT01CF */
#define dIN1PL              (1 << 7)
#define dIN1P0_0            (0 << 4)
#define dIN1P0_1            (1 << 4)
#define dIN1P0_2            (2 << 4)
#define dIN1P0_3            (3 << 4)
#define dIN1P0_4            (4 << 4)
#define dIN1P0_5            (5 << 4)
#define dIN1P0_6            (6 << 4)
#define dIN1P0_7            (7 << 4)
#define dIN0PL              (1 << 3)
#define dIN0P0_0            (0 << 0)
#define dIN0P0_1            (1 << 0)
#define dIN0P0_2            (2 << 0)
#define dIN0P0_3            (3 << 0)
#define dIN0P0_4            (4 << 0)
#define dIN0P0_5            (5 << 0)
#define dIN0P0_6            (6 << 0)
#define dIN0P0_7            (7 << 0)

/* OSCICN */
#define dIOSCEN             (1 << 7)
#define dIFRDY              (1 << 6)
#define dSYSCLK_DIV_8       (0 << 0)
#define dSYSCLK_DIV_4       (1 << 0)
#define dSYSCLK_DIV_2       (2 << 0)
#define dSYSCLK_DIV_1       (3 << 0)

/* CLKSEL */
#define dINT_HF_OSC         (0 << 0)
#define dEXT_OSC            (1 << 0)
#define dINT_LF_OSC         (2 << 0)

/* XBR0 */
#define dCP0AE              (1 << 5)
#define dCP0E               (1 << 4)
#define dSYSCKE             (1 << 3)
#define dSMB0E              (1 << 2)
#define dSPI0E              (1 << 1)
#define dURT0E              (1 << 0)

/* XBR1 */
#define dWEAKPUD            (1 << 7)
#define dXBARE              (1 << 6)
#define dT1E                (1 << 5)
#define dT0E                (1 << 4)
#define dECIE               (1 << 3)
#define dCEX_DIS            (0 << 0)
#define dCEX0_EN            (1 << 0)
#define dCEX01_EN           (2 << 0)
#define dCEX012_EN          (3 << 0)

/* TCON */
#define dTF1                (1 << 7)
#define dTR1                (1 << 6)
#define dTF0                (1 << 5)
#define dTR0                (1 << 4)
#define dIE1                (1 << 3)
#define dIT1                (1 << 2)
#define dIE0                (1 << 1)
#define dIT0                (1 << 0)

/* TMOD */
#define dGATE1              (1 << 7)
#define dCT1                (1 << 6)
#define dT1M1               (1 << 5)
#define dT1M0               (1 << 4)
#define dGATE0              (1 << 3)
#define dCT0                (1 << 2)
#define dT0M1               (1 << 1)
#define dT0M0               (1 << 0)

/* CKCON */
#define dT3MH               (1 << 7)
#define dT3ML               (1 << 6)
#define dT2MH               (1 << 5)
#define dT2ML               (1 << 4)
#define dT1M                (1 << 3)
#define dT0M                (1 << 2)
#define dTMR_SYSCLK_DIV_12  (0 << 0)
#define dTMR_SYSCLK_DIV_4   (1 << 0)
#define dTMR_SYSCLK_DIV_48  (2 << 0)
#define dTMR_SYSCLK_DIV_8   (3 << 0)

/* TMR2CN */
#define dTF2H               (1 << 7)
#define dTF2L               (1 << 6)
#define dTF2LEN             (1 << 5)
#define dTF2CEN             (1 << 4)
#define dT2SPLIT            (1 << 3)
#define dTR2                (1 << 2)
#define dT2XCLK             (1 << 0)

/* TMR3CN */
#define dTF3H               (1 << 7)
#define dTF3L               (1 << 6)
#define dTF3LEN             (1 << 5)
#define dTF3CEN             (1 << 4)
#define dT3SPLIT            (1 << 3)
#define dTR3                (1 << 2)
#define dT3XCLK             (1 << 0)

/* PCA0CN */
#define dCF                 (1 << 7)
#define dCR                 (1 << 6)
#define dCCF2               (1 << 2)
#define dCCF1               (1 << 1)
#define dCCF0               (1 << 0)

/* PCA0MD */
#define dCIDL               (1 << 7)
#define dWDTE               (1 << 6)
#define dWDLCK              (1 << 5)
#define dPCA_SYSCLK_DIV_12  (0 << 1)
#define dPCA_SYSCLK_DIV_4   (1 << 1)
#define dPCA_T0_OVERFLOW    (2 << 1)
#define dPCA_ECI            (3 << 1)
#define dPCA_SYSCLK         (4 << 1)
#define dPCA_EXTCLK_DIV_8   (5 << 1)
#define dECF                (1 << 0)

/* PCA0CPMn */
#define dPWM16              (1 << 7)
#define dECOM               (1 << 6)
#define dCAPP               (1 << 5)
#define dCAPN               (1 << 4)
#define dMAT                (1 << 3)
#define dTOG                (1 << 2)
#define dPWM                (1 << 1)
#define dECCF               (1 << 0)

#endif