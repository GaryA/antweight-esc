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

#ifndef _MOTOR_H_
#define _MOTOR_H_

/**
 * Function Prototypes
 */
void fDisablePwm(void);
void fEnablePwmCh1LoSide(void);
void fEnablePwmCh2LoSide(void);
void fTurnOffAllHiSide(void);
void fTurnOffAllLoSide(void);
void fTurnOffCh1HiSide(void);
void fTurnOffCh1LoSide(void);
void fTurnOffCh2HiSide(void);
void fTurnOffCh2LoSide(void);
void fTurnOffSpareChannel(void);
void fTurnOnCh1HiSide(void);
void fTurnOnCh2HiSide(void);
void fTurnOnSpareChannelHiSide(void);
#endif
