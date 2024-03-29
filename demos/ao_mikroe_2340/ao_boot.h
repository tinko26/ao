// ----------------------------------------------------------------------------

// MIT License

// Copyright (c) 2022 Stefan Wagner

// Permission is hereby granted, free of charge, to any person obtaining a
// copy of this software and associated documentation files (the "Software"),
// to deal in the Software without restriction, including without limitation
// the rights to use, copy, modify, merge, publish, distribute, sublicense,
// and/or sell copies of the Software, and to permit persons to whom the
// Software is furnished to do so, subject to the following conditions:

// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.

// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
// FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
// DEALINGS IN THE SOFTWARE.

// ----------------------------------------------------------------------------

// Booting.

// ----------------------------------------------------------------------------

#include <xc.h>

// ----------------------------------------------------------------------------

#ifndef AO_BOOT

#define AO_BOOT

#endif

// ----------------------------------------------------------------------------

void    ao_boot();

// ----------------------------------------------------------------------------

#ifndef ao_boot_button

#define ao_boot_button()                                                    \
{                                                                           \
        TRISDSET  = 0xC00;                                                  \
}

#endif

// ----------------------------------------------------------------------------

#ifndef ao_boot_led

#define ao_boot_led()                                                       \
{                                                                           \
        TRISACLR  = 0xC0;                                                   \
        TRISECLR  = 0x03;                                                   \
        LATACLR   = 0xC0;                                                   \
        LATECLR   = 0x03;                                                   \
}

#endif

// ----------------------------------------------------------------------------

void    ao_boot_mikroe_1877();

void    ao_boot_mikroe_2334();

void    ao_boot_mikroe_2674();

void    ao_boot_mikroe_2935();

void    ao_boot_mikroe_2950();

void    ao_boot_mikroe_3063();

void    ao_boot_mikroe_4186();

// ----------------------------------------------------------------------------

void    ao_boot_uart_5();

// ----------------------------------------------------------------------------

#include_next <ao_boot.h>

// ----------------------------------------------------------------------------
