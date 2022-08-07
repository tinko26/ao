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

#ifndef AO_MIKROE_2935_A

#define AO_MIKROE_2935_A                    (false)

#endif

#ifndef AO_MIKROE_2935_B

#define AO_MIKROE_2935_B                    (false)

#endif

#ifndef AO_MIKROE_2935_C

#define AO_MIKROE_2935_C                    (false)

#endif

#ifndef AO_MIKROE_2935_D

#define AO_MIKROE_2935_D                    (false)

#endif

// ----------------------------------------------------------------------------

#ifndef AO_MIKROE_2935_BAUD_A

#define AO_MIKROE_2935_BAUD_A               (10000000UL)

#endif

#ifndef AO_MIKROE_2935_BAUD_B

#define AO_MIKROE_2935_BAUD_B               (10000000UL)

#endif

#ifndef AO_MIKROE_2935_BAUD_C

#define AO_MIKROE_2935_BAUD_C               (10000000UL)

#endif

#ifndef AO_MIKROE_2935_BAUD_D

#define AO_MIKROE_2935_BAUD_D               (10000000UL)

#endif

// ----------------------------------------------------------------------------

#ifndef AO_MIKROE_2935_PERIOD_A

#define AO_MIKROE_2935_PERIOD_A             (AO_MILLISECONDS(100))

#endif

#ifndef AO_MIKROE_2935_PERIOD_B

#define AO_MIKROE_2935_PERIOD_B             (AO_MILLISECONDS(100))

#endif

#ifndef AO_MIKROE_2935_PERIOD_C

#define AO_MIKROE_2935_PERIOD_C             (AO_MILLISECONDS(100))

#endif

#ifndef AO_MIKROE_2935_PERIOD_D

#define AO_MIKROE_2935_PERIOD_D             (AO_MILLISECONDS(100))

#endif

// ----------------------------------------------------------------------------

#ifndef AO_MIKROE_2935_REPETITIONS_XY_A

#define AO_MIKROE_2935_REPETITIONS_XY_A     (9)

#endif

#ifndef AO_MIKROE_2935_REPETITIONS_XY_B

#define AO_MIKROE_2935_REPETITIONS_XY_B     (9)

#endif

#ifndef AO_MIKROE_2935_REPETITIONS_XY_C

#define AO_MIKROE_2935_REPETITIONS_XY_C     (9)

#endif

#ifndef AO_MIKROE_2935_REPETITIONS_XY_D

#define AO_MIKROE_2935_REPETITIONS_XY_D     (9)

#endif

// ----------------------------------------------------------------------------

#ifndef AO_MIKROE_2935_REPETITIONS_Z_A

#define AO_MIKROE_2935_REPETITIONS_Z_A      (15)

#endif

#ifndef AO_MIKROE_2935_REPETITIONS_Z_B

#define AO_MIKROE_2935_REPETITIONS_Z_B      (15)

#endif

#ifndef AO_MIKROE_2935_REPETITIONS_Z_C

#define AO_MIKROE_2935_REPETITIONS_Z_C      (15)

#endif

#ifndef AO_MIKROE_2935_REPETITIONS_Z_D

#define AO_MIKROE_2935_REPETITIONS_Z_D      (15)

#endif

// ----------------------------------------------------------------------------

extern  ao_task_t                           ao_mikroe_2935_task_a;

extern  ao_task_t                           ao_mikroe_2935_task_b;

extern  ao_task_t                           ao_mikroe_2935_task_c;

extern  ao_task_t                           ao_mikroe_2935_task_d;

// ----------------------------------------------------------------------------

#include_next <ao_mikroe_2935.h>

// ----------------------------------------------------------------------------
