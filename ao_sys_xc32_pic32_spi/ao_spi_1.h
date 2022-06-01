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

// SPI 1.

// ----------------------------------------------------------------------------

#include <ao_spi.h>
#include <ao_sys.h>
#include <stdbool.h>
#include <xc.h>

// ----------------------------------------------------------------------------

#ifndef AO_SPI_1

#ifdef  _SPI1

#define AO_SPI_1            (true)

#else

#define AO_SPI_1            (false)

#endif

#endif

// ----------------------------------------------------------------------------

#ifndef AO_SPI_BAUD_MAX_1

#define AO_SPI_BAUD_MAX_1   ao_spi_baud_max(AO_SYS_CLOCK_SPI1)

#endif

#ifndef AO_SPI_BAUD_MIN_1

#define AO_SPI_BAUD_MIN_1   ao_spi_baud_min(AO_SYS_CLOCK_SPI1)

#endif

// ----------------------------------------------------------------------------

#ifndef ao_spi_baud_1

#define ao_spi_baud_1(f)    ao_spi_baud(ao_spi_reg_1(), AO_SYS_CLOCK_SPI1, f)

#endif

// ----------------------------------------------------------------------------

#ifndef ao_spi_reg_1

#define ao_spi_reg_1()      ((ao_spi_reg_t *) (_SPI1_BASE_ADDRESS))

#endif

// ----------------------------------------------------------------------------
