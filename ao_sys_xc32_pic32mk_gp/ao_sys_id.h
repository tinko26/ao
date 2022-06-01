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

// IDs.

// ----------------------------------------------------------------------------

#include <xc.h>

// ----------------------------------------------------------------------------

#ifndef ao_sys_id_device

#define ao_sys_id_device()      (DEVIDbits.DEVID)

#endif

// ----------------------------------------------------------------------------

#ifndef ao_sys_id_revision

#define ao_sys_id_revision()    (DEVIDbits.VER)

#endif

// ----------------------------------------------------------------------------

#ifndef AO_SYS_ID_REVISION_A1

#define AO_SYS_ID_REVISION_A1   (1)

#endif

#ifndef AO_SYS_ID_REVISION_A2

#define AO_SYS_ID_REVISION_A2   (2)

#endif

// ----------------------------------------------------------------------------

#ifndef ao_sys_id_user

#define ao_sys_id_user()        (DEVCFG3bits.USERID)

#endif

// ----------------------------------------------------------------------------
