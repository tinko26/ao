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

// Function pointer types.

// ----------------------------------------------------------------------------

#include <stdbool.h>

// ----------------------------------------------------------------------------

typedef void *  (*  ao_func_t)  (void *);

// ----------------------------------------------------------------------------

typedef void *  (*  ao_func0_t) ();

typedef void *  (*  ao_func1_t) (void *);

typedef void *  (*  ao_func2_t) (void *, void *);

typedef void *  (*  ao_func3_t) (void *, void *, void *);

// ----------------------------------------------------------------------------

typedef bool    (*  ao_pred_t)  (void *);

// ----------------------------------------------------------------------------

typedef bool    (*  ao_pred0_t) ();

typedef bool    (*  ao_pred1_t) (void *);

typedef bool    (*  ao_pred2_t) (void *, void *);

typedef bool    (*  ao_pred3_t) (void *, void *, void *);

// ----------------------------------------------------------------------------

typedef void    (*  ao_proc_t)  (void *);

// ----------------------------------------------------------------------------

typedef void    (*  ao_proc0_t) ();

typedef void    (*  ao_proc1_t) (void *);

typedef void    (*  ao_proc2_t) (void *, void *);

typedef void    (*  ao_proc3_t) (void *, void *, void *);

// ----------------------------------------------------------------------------
