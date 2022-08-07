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

#include <ao_task.h>
#include <ao_time.h>
#include <stdbool.h>

// ----------------------------------------------------------------------------

#ifndef AO_MIKROE_1877_1

#define AO_MIKROE_1877_1            (false)

#endif

#ifndef AO_MIKROE_1877_2

#define AO_MIKROE_1877_2            (false)

#endif

// ----------------------------------------------------------------------------

#ifndef AO_MIKROE_1877_BAUD_1

#define AO_MIKROE_1877_BAUD_1       (400000UL)

#endif

#ifndef AO_MIKROE_1877_BAUD_2

#define AO_MIKROE_1877_BAUD_2       (400000UL)

#endif

// ----------------------------------------------------------------------------

#ifndef AO_MIKROE_1877_TIMEOUT_1

#define AO_MIKROE_1877_TIMEOUT_1    (AO_MILLISECONDS(100))

#endif

#ifndef AO_MIKROE_1877_TIMEOUT_2

#define AO_MIKROE_1877_TIMEOUT_2    (AO_MILLISECONDS(100))

#endif

// ----------------------------------------------------------------------------

extern  ao_task_t                   ao_mikroe_1877_task_1;

extern  ao_task_t                   ao_mikroe_1877_task_2;

// ----------------------------------------------------------------------------

#include_next <ao_mikroe_1877.h>

// ----------------------------------------------------------------------------
