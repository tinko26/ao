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

#include <ao_time.h>
#include <stdbool.h>

// ----------------------------------------------------------------------------

#ifndef AO_MIKROE_4186_A

#define AO_MIKROE_4186_A            (false)

#endif

#ifndef AO_MIKROE_4186_B

#define AO_MIKROE_4186_B            (false)

#endif

#ifndef AO_MIKROE_4186_C

#define AO_MIKROE_4186_C            (false)

#endif

#ifndef AO_MIKROE_4186_D

#define AO_MIKROE_4186_D            (false)

#endif

// ----------------------------------------------------------------------------

#ifndef AO_MIKROE_4186_BAUD_A

#define AO_MIKROE_4186_BAUD_A       (400000UL)

#endif

#ifndef AO_MIKROE_4186_BAUD_B

#define AO_MIKROE_4186_BAUD_B       (400000UL)

#endif

#ifndef AO_MIKROE_4186_BAUD_C

#define AO_MIKROE_4186_BAUD_C       (400000UL)

#endif

#ifndef AO_MIKROE_4186_BAUD_D

#define AO_MIKROE_4186_BAUD_D       (400000UL)

#endif

// ----------------------------------------------------------------------------

#ifndef AO_MIKROE_4186_TIMEOUT_A

#define AO_MIKROE_4186_TIMEOUT_A    (AO_MILLISECONDS(100))

#endif

#ifndef AO_MIKROE_4186_TIMEOUT_B

#define AO_MIKROE_4186_TIMEOUT_B    (AO_MILLISECONDS(100))

#endif

#ifndef AO_MIKROE_4186_TIMEOUT_C

#define AO_MIKROE_4186_TIMEOUT_C    (AO_MILLISECONDS(100))

#endif

#ifndef AO_MIKROE_4186_TIMEOUT_D

#define AO_MIKROE_4186_TIMEOUT_D    (AO_MILLISECONDS(100))

#endif

// ----------------------------------------------------------------------------

#ifndef AO_MIKROE_4186

#define AO_MIKROE_4186                                                      \
(                                                                           \
        AO_MIKROE_4186_A ||                                                 \
        AO_MIKROE_4186_B ||                                                 \
        AO_MIKROE_4186_C ||                                                 \
        AO_MIKROE_4186_D                                                    \
)

#endif

// ----------------------------------------------------------------------------

#include_next <ao_mikroe_4186.h>

// ----------------------------------------------------------------------------
