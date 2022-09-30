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

// System prefetch cache.

// ----------------------------------------------------------------------------

#include <xc.h>

// ----------------------------------------------------------------------------

#ifndef ao_sys_pfm_ws_set

#define ao_sys_pfm_ws_set(ws)                                               \
{                                                                           \
        PRECONSET = _PRECON_PFMWS_MASK;                                     \
        PRECONCLR = _PRECON_PFMWS_MASK & ~((ws) << _PRECON_PFMWS_POSITION); \
}

#endif

// ----------------------------------------------------------------------------

#ifndef ao_sys_pref_disable

#define ao_sys_pref_disable()                                               \
{                                                                           \
        PRECONCLR = _PRECON_PREFEN_MASK;                                    \
}

#endif

#ifndef ao_sys_pref_enable_any

#define ao_sys_pref_enable_any()                                            \
{                                                                           \
        PRECONSET = _PRECON_PREFEN_MASK;                                    \
}

#endif

#ifndef ao_sys_pref_enable_instructions

#define ao_sys_pref_enable_instructions()                                   \
{                                                                           \
        PRECONCLR = _PRECON_PREFEN_MASK;                                    \
        PRECONSET = _PRECON_PREFEN_MASK & (1 << _PRECON_PREFEN_POSITION);   \
}

#endif

#ifndef ao_sys_pref_enable_instructions_and_data

#define ao_sys_pref_enable_instructions_and_data()                          \
{                                                                           \
        PRECONCLR = _PRECON_PREFEN_MASK;                                    \
        PRECONSET = _PRECON_PREFEN_MASK & (2 << _PRECON_PREFEN_POSITION);   \
}

#endif

// ----------------------------------------------------------------------------
