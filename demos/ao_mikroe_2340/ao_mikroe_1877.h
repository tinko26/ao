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

#ifndef AO_MIKROE_1877_A

#define AO_MIKROE_1877_A            (false)

#endif

#ifndef AO_MIKROE_1877_B

#define AO_MIKROE_1877_B            (false)

#endif

#ifndef AO_MIKROE_1877_C

#define AO_MIKROE_1877_C            (false)

#endif

#ifndef AO_MIKROE_1877_D

#define AO_MIKROE_1877_D            (false)

#endif

// ----------------------------------------------------------------------------

#ifndef AO_MIKROE_1877_BAUD_A

#define AO_MIKROE_1877_BAUD_A       (400000UL)

#endif

#ifndef AO_MIKROE_1877_BAUD_B

#define AO_MIKROE_1877_BAUD_B       (400000UL)

#endif

#ifndef AO_MIKROE_1877_BAUD_C

#define AO_MIKROE_1877_BAUD_C       (400000UL)

#endif

#ifndef AO_MIKROE_1877_BAUD_D

#define AO_MIKROE_1877_BAUD_D       (400000UL)

#endif

// ----------------------------------------------------------------------------

#ifndef AO_MIKROE_1877_TIMEOUT_A

#define AO_MIKROE_1877_TIMEOUT_A    (AO_MILLISECONDS(100))

#endif

#ifndef AO_MIKROE_1877_TIMEOUT_B

#define AO_MIKROE_1877_TIMEOUT_B    (AO_MILLISECONDS(100))

#endif

#ifndef AO_MIKROE_1877_TIMEOUT_C

#define AO_MIKROE_1877_TIMEOUT_C    (AO_MILLISECONDS(100))

#endif

#ifndef AO_MIKROE_1877_TIMEOUT_D

#define AO_MIKROE_1877_TIMEOUT_D    (AO_MILLISECONDS(100))

#endif

// ----------------------------------------------------------------------------

#ifndef AO_MIKROE_1877

#define AO_MIKROE_1877                                                      \
(                                                                           \
        AO_MIKROE_1877_A ||                                                 \
        AO_MIKROE_1877_B ||                                                 \
        AO_MIKROE_1877_C ||                                                 \
        AO_MIKROE_1877_D                                                    \
)

#endif

// ----------------------------------------------------------------------------

extern  ao_task_t                   ao_mikroe_1877_task_a;

extern  ao_task_t                   ao_mikroe_1877_task_b;

extern  ao_task_t                   ao_mikroe_1877_task_c;

extern  ao_task_t                   ao_mikroe_1877_task_d;

// ----------------------------------------------------------------------------

#include_next <ao_mikroe_1877.h>

// ----------------------------------------------------------------------------
