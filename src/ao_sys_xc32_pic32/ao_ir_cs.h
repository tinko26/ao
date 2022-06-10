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

// Core software interrupts.

// ----------------------------------------------------------------------------

#include <stdbool.h>

// ----------------------------------------------------------------------------

void    ao_ir_cs0_disable();

void    ao_ir_cs0_enable();

bool    ao_ir_cs0_is_enabled();

// ----------------------------------------------------------------------------

bool    ao_ir_cs0_is_pending();

void    ao_ir_cs0_reply();

void    ao_ir_cs0_request();

// ----------------------------------------------------------------------------

void    ao_ir_cs1_disable();

void    ao_ir_cs1_enable();

bool    ao_ir_cs1_is_enabled();

// ----------------------------------------------------------------------------

bool    ao_ir_cs1_is_pending();

void    ao_ir_cs1_reply();

void    ao_ir_cs1_request();

// ----------------------------------------------------------------------------
