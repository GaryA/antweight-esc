/*
Yet Another Antweight ESC
File: typedefs.h

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

#ifndef _TYPEDEF_H_
#define _TYPEDEF_H_

/**
 * C99 type definitions
 */
 
#define int16_t int
#define int8_t char
#define uint16_t unsigned int
#define uint8_t unsigned char
#define bool bit

#define true 1
#define false 0

/**
 * Project type definitions
 */

typedef enum
{
    eBrake = 0,
    eForward,
    eReverse,
    eCoast
} tState;

#endif