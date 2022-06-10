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

// Mathematics for integers.

// ----------------------------------------------------------------------------

#ifndef ao_log2u2

#define ao_log2u2(x)    ((x) & 0x0000000000000002 ?  1                         : 0            )

#endif

#ifndef ao_log2u4

#define ao_log2u4(x)    ((x) & 0x000000000000000C ?  2 + ao_log2u2( (x) >>  2) : ao_log2u2(x) )

#endif

#ifndef ao_log2u8

#define ao_log2u8(x)    ((x) & 0x00000000000000F0 ?  4 + ao_log2u4( (x) >>  4) : ao_log2u4(x) )

#endif

#ifndef ao_log2u16

#define ao_log2u16(x)   ((x) & 0x000000000000FF00 ?  8 + ao_log2u8( (x) >>  8) : ao_log2u8(x) )

#endif

#ifndef ao_log2u32

#define ao_log2u32(x)   ((x) & 0x00000000FFFF0000 ? 16 + ao_log2u16((x) >> 16) : ao_log2u16(x))

#endif

#ifndef ao_log2u64

#define ao_log2u64(x)   ((x) & 0xFFFFFFFF00000000 ? 32 + ao_log2u32((x) >> 32) : ao_log2u32(x))

#endif

#ifndef ao_log2u

#define ao_log2u(x)     ao_log2u64(x)

#endif

// ----------------------------------------------------------------------------
