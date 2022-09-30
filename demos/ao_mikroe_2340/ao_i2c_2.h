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

// I2C 2.

// ----------------------------------------------------------------------------

#include <ao_mikroe_1877.h>
#include <ao_mikroe_2950.h>
#include <ao_mikroe_4186.h>

// ----------------------------------------------------------------------------

#ifndef AO_I2C_2

#define AO_I2C_2                                                            \
(                                                                           \
        AO_MIKROE_1877_A ||                                                 \
        AO_MIKROE_1877_B ||                                                 \
        AO_MIKROE_2950_A ||                                                 \
        AO_MIKROE_2950_B ||                                                 \
        AO_MIKROE_4186_A ||                                                 \
        AO_MIKROE_4186_B                                                    \
)

#endif

// ----------------------------------------------------------------------------

#include_next <ao_i2c_2.h>

// ----------------------------------------------------------------------------
