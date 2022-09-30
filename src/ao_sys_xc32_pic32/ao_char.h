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

// Characters.

// ----------------------------------------------------------------------------

#include <ctype.h>
#include <stdbool.h>

// ----------------------------------------------------------------------------

#ifndef ao_char_is_alphanumeric

#define ao_char_is_alphanumeric(x)  (isalnum((int) (x)) ? true : false)

#endif

#ifndef ao_char_is_alphabetic

#define ao_char_is_alphabetic(x)    (isalpha((int) (x)) ? true : false)

#endif

#ifndef ao_char_is_blank

#define ao_char_is_blank(x)         (isblank((int) (x)) ? true : false)

#endif

#ifndef ao_char_is_control

#define ao_char_is_control(x)       (iscntrl((int) (x)) ? true : false)

#endif

#ifndef ao_char_is_decimal

#define ao_char_is_decimal(x)       (isdigit((int) (x)) ? true : false)

#endif

#ifndef ao_char_is_graphical

#define ao_char_is_graphical(x)     (isgraph((int) (x)) ? true : false)

#endif

#ifndef ao_char_is_hexadecimal

#define ao_char_is_hexadecimal(x)   (isxdigit((int) (x)) ? true : false)

#endif

#ifndef ao_char_is_lower

#define ao_char_is_lower(x)         (islower((int) (x)) ? true : false)

#endif

#ifndef ao_char_is_printable

#define ao_char_is_printable(x)     (isprint((int) (x)) ? true : false)

#endif

#ifndef ao_char_is_punctuation

#define ao_char_is_punctuation(x)   (ispunct((int) (x)) ? true : false)

#endif

#ifndef ao_char_is_upper

#define ao_char_is_upper(x)         (isupper((int) (x)) ? true : false)

#endif

#ifndef ao_char_is_whitespace

#define ao_char_is_whitespace(x)    (isspace((int) (x)) ? true : false)

#endif

// ----------------------------------------------------------------------------
