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

// SPI 5.

// ----------------------------------------------------------------------------

#include <ao_spi.h>
#include <ao_sys.h>
#include <stdbool.h>
#include <xc.h>

// ----------------------------------------------------------------------------

#ifndef AO_SPI_5

#ifdef  _SPI5

#define AO_SPI_5            (true)

#else

#define AO_SPI_5            (false)

#endif

#endif

// ----------------------------------------------------------------------------

#ifndef AO_SPI_BAUD_MAX_5

#define AO_SPI_BAUD_MAX_5   AO_SPI_BAUD_MAX(AO_SYS_CLOCK_SPI5)

#endif

#ifndef AO_SPI_BAUD_MIN_5

#define AO_SPI_BAUD_MIN_5   AO_SPI_BAUD_MIN(AO_SYS_CLOCK_SPI5)

#endif

// ----------------------------------------------------------------------------

#ifndef ao_spi_baud_5

#define ao_spi_baud_5(f)    ao_spi_baud(ao_spi_reg_5(), AO_SYS_CLOCK_SPI5, f)

#endif

// ----------------------------------------------------------------------------

#ifndef ao_spi_reg_5

#define ao_spi_reg_5()      ((ao_spi_reg_t *) (_SPI5_BASE_ADDRESS))

#endif

// ----------------------------------------------------------------------------
