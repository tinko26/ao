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

#include <stdbool.h>

// ----------------------------------------------------------------------------

#ifndef AO_CHAR

#define AO_CHAR

#endif

// ----------------------------------------------------------------------------

#ifndef ao_char_is_alphanumeric

bool    ao_char_is_alphanumeric(char x);

#endif

#ifndef ao_char_is_alphabetic

bool    ao_char_is_alphabetic(  char x);

#endif

#ifndef ao_char_is_blank

bool    ao_char_is_blank(       char x);

#endif

#ifndef ao_char_is_control

bool    ao_char_is_control(     char x);

#endif

#ifndef ao_char_is_decimal

bool    ao_char_is_decimal(     char x);

#endif

#ifndef ao_char_is_graphical

bool    ao_char_is_graphical(   char x);

#endif

#ifndef ao_char_is_hexadecimal

bool    ao_char_is_hexadecimal( char x);

#endif

#ifndef ao_char_is_lower

bool    ao_char_is_lower(       char x);

#endif

#ifndef ao_char_is_printable

bool    ao_char_is_printable(   char x);

#endif

#ifndef ao_char_is_punctuation

bool    ao_char_is_punctuation( char x);

#endif

#ifndef ao_char_is_upper

bool    ao_char_is_upper(       char x);

#endif

#ifndef ao_char_is_whitespace

bool    ao_char_is_whitespace(  char x);

#endif

// ----------------------------------------------------------------------------
