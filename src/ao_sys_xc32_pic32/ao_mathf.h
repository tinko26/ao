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

// Mathematics for floating-point numbers.

// ----------------------------------------------------------------------------

#include <math.h>

// ----------------------------------------------------------------------------

#ifndef ao_acosd

#define ao_acosd(x)             acos(x)

#endif

#ifndef ao_acosf

#define ao_acosf(x)             acosf(x)

#endif

#ifndef ao_acosl

#define ao_acosl(x)             acosl(x)

#endif

// ----------------------------------------------------------------------------

#ifndef ao_acoshd

#define ao_acoshd(x)            acosh(x)

#endif

#ifndef ao_acoshf

#define ao_acoshf(x)            acoshf(x)

#endif

#ifndef ao_acoshl

#define ao_acoshl(x)            acoshl(x)

#endif

// ----------------------------------------------------------------------------

#ifndef ao_asind

#define ao_asind(x)             asin(x)

#endif

#ifndef ao_asinf

#define ao_asinf(x)             asinf(x)

#endif

#ifndef ao_asinl

#define ao_asinl(x)             asinl(x)

#endif

// ----------------------------------------------------------------------------

#ifndef ao_asinhd

#define ao_asinhd(x)            asinh(x)

#endif

#ifndef ao_asinhf

#define ao_asinhf(x)            asinhf(x)

#endif

#ifndef ao_asinhl

#define ao_asinhl(x)            asinhl(x)

#endif

// ----------------------------------------------------------------------------

#ifndef ao_atand

#define ao_atand(x)             atan(x)

#endif

#ifndef ao_atanf

#define ao_atanf(x)             atanf(x)

#endif

#ifndef ao_atanl

#define ao_atanl(x)             atanl(x)

#endif

// ----------------------------------------------------------------------------

#ifndef ao_atan2d

#define ao_atan2d(y, x)         atan2(y, x)

#endif

#ifndef ao_atan2f

#define ao_atan2f(y, x)         atan2f(y, x)

#endif

#ifndef ao_atan2l

#define ao_atan2l(y, x)         atan2l(y, x)

#endif

// ----------------------------------------------------------------------------

#ifndef ao_atanhd

#define ao_atanhd(x)            atanh(x)

#endif

#ifndef ao_atanhf

#define ao_atanhf(x)            atanhf(x)

#endif

#ifndef ao_atanhl

#define ao_atanhl(x)            atanhl(x)

#endif

// ----------------------------------------------------------------------------

#ifndef ao_cbrtd

#define ao_cbrtd(x)             cbrt(x)

#endif

#ifndef ao_cbrtf

#define ao_cbrtf(x)             cbrtf(x)

#endif

#ifndef ao_cbrtl

#define ao_cbrtl(x)             cbrtl(x)

#endif

// ----------------------------------------------------------------------------

#ifndef ao_ceild

#define ao_ceild(x)             ceil(x)

#endif

#ifndef ao_ceilf

#define ao_ceilf(x)             ceilf(x)

#endif

#ifndef ao_ceill

#define ao_ceill(x)             ceill(x)

#endif

// ----------------------------------------------------------------------------

#ifndef ao_cosd

#define ao_cosd(x)              cos(x)

#endif

#ifndef ao_cosf

#define ao_cosf(x)              cosf(x)

#endif

#ifndef ao_cosl

#define ao_cosl(x)              cosl(x)

#endif

// ----------------------------------------------------------------------------

#ifndef ao_coshd

#define ao_coshd(x)             cosh(x)

#endif

#ifndef ao_coshf

#define ao_coshf(x)             coshf(x)

#endif

#ifndef ao_coshl

#define ao_coshl(x)             coshl(x)

#endif

// ----------------------------------------------------------------------------

#ifndef ao_expd

#define ao_expd(x)              exp(x)

#endif

#ifndef ao_expf

#define ao_expf(x)              expf(x)

#endif

#ifndef ao_expl

#define ao_expl(x)              expl(x)

#endif

// ----------------------------------------------------------------------------

#ifndef ao_fabsd

#define ao_fabsd(x)             fabs(x)

#endif

#ifndef ao_fabsf

#define ao_fabsf(x)             fabsf(x)

#endif

#ifndef ao_fabsl

#define ao_fabsl(x)             fabsl(x)

#endif

// ----------------------------------------------------------------------------

#ifndef ao_floord

#define ao_floord(x)            floor(x)

#endif

#ifndef ao_floorf

#define ao_floorf(x)            floorf(x)

#endif

#ifndef ao_floorl

#define ao_floorl(x)            floorl(x)

#endif

// ----------------------------------------------------------------------------

#ifndef ao_fmodd

#define ao_fmodd(x, y)          fmod(x, y)

#endif

#ifndef ao_fmodf

#define ao_fmodf(x, y)          fmodf(x, y)

#endif

#ifndef ao_fmodl

#define ao_fmodl(x, y)          fmodl(x, y)

#endif

// ----------------------------------------------------------------------------

#ifndef ao_frexpd

#define ao_frexpd(x, exp)       frexp(x, exp)

#endif

#ifndef ao_frexpf

#define ao_frexpf(x, exp)       frexpf(x, exp)

#endif

#ifndef ao_frexpl

#define ao_frexpl(x, exp)       frexpl(x, exp)

#endif

// ----------------------------------------------------------------------------

#ifndef ao_hypotd

#define ao_hypotd(x, y)         hypot(x, y)

#endif

#ifndef ao_hypotf

#define ao_hypotf(x, y)         hypotf(x, y)

#endif

#ifndef ao_hypotl

#define ao_hypotl(x, y)         hypotl(x, y)

#endif

// ----------------------------------------------------------------------------

#ifndef ao_isfinited

#define ao_isfinited(x)         finite(x)

#endif

#ifndef ao_isfinitef

#define ao_isfinitef(x)         finite(x)

#endif

#ifndef ao_isfinitel

#define ao_isfinitel(x)         finite(x)

#endif

// ----------------------------------------------------------------------------

#ifndef ao_isinfd

#define ao_isinfd(x)            isinf(x)

#endif

#ifndef ao_isinff

#define ao_isinff(x)            isinf(x)

#endif

#ifndef ao_isinfl

#define ao_isinfl(x)            isinf(x)

#endif

// ----------------------------------------------------------------------------

#ifndef ao_isnand

#define ao_isnand(x)            isnan(x)

#endif

#ifndef ao_isnanf

#define ao_isnanf(x)            isnan(x)

#endif

#ifndef ao_isnanl

#define ao_isnanl(x)            isnan(x)

#endif

// ----------------------------------------------------------------------------

#ifndef ao_ldexpd

#define ao_ldexpd(x, exp)       ldexp(x, exp)

#endif

#ifndef ao_ldexpf

#define ao_ldexpf(x, exp)       ldexpf(x, exp)

#endif

#ifndef ao_ldexpl

#define ao_ldexpl(x, exp)       ldexpl(x, exp)

#endif

// ----------------------------------------------------------------------------

#ifndef ao_logd

#define ao_logd(x)              log(x)

#endif

#ifndef ao_logf

#define ao_logf(x)              logf(x)

#endif

#ifndef ao_logl

#define ao_logl(x)              logl(x)

#endif

// ----------------------------------------------------------------------------

#ifndef ao_log10d

#define ao_log10d(x)            log10(x)

#endif

#ifndef ao_log10f

#define ao_log10f(x)            log10f(x)

#endif

#ifndef ao_log10l

#define ao_log10l(x)            log10l(x)

#endif

// ----------------------------------------------------------------------------

#ifndef ao_modfd

#define ao_modfd(x, intpart)    modf(x, intpart)

#endif

#ifndef ao_modff

#define ao_modff(x, intpart)    modff(x, intpart)

#endif

#ifndef ao_modfl

#define ao_modfl(x, intpart)    modfl(x, intpart)

#endif

// ----------------------------------------------------------------------------

#ifndef ao_powd

#define ao_powd(x, y)           pow(x, y)

#endif

#ifndef ao_powf

#define ao_powf(x, y)           powf(x, y)

#endif

#ifndef ao_powl

#define ao_powl(x, y)           powl(x, y)

#endif

// ----------------------------------------------------------------------------

#ifndef ao_sind

#define ao_sind(x)              sin(x)

#endif

#ifndef ao_sinf

#define ao_sinf(x)              sinf(x)

#endif

#ifndef ao_sinl

#define ao_sinl(x)              sinl(x)

#endif

// ----------------------------------------------------------------------------

#ifndef ao_sinhd

#define ao_sinhd(x)             sinh(x)

#endif

#ifndef ao_sinhf

#define ao_sinhf(x)             sinhf(x)

#endif

#ifndef ao_sinhl

#define ao_sinhl(x)             sinhl(x)

#endif

// ----------------------------------------------------------------------------

#ifndef ao_sqrtd

#define ao_sqrtd(x)             sqrt(x)

#endif

#ifndef ao_sqrtf

#define ao_sqrtf(x)             sqrtf(x)

#endif

#ifndef ao_sqrtl

#define ao_sqrtl(x)             sqrtl(x)

#endif

// ----------------------------------------------------------------------------

#ifndef ao_tand

#define ao_tand(x)              tan(x)

#endif

#ifndef ao_tanf

#define ao_tanf(x)              tanf(x)

#endif

#ifndef ao_tanl

#define ao_tanl(x)              tanl(x)

#endif

// ----------------------------------------------------------------------------

#ifndef ao_tanhd

#define ao_tanhd(x)             tanh(x)

#endif

#ifndef ao_tanhf

#define ao_tanhf(x)             tanhf(x)

#endif

#ifndef ao_tanhl

#define ao_tanhl(x)             tanhl(x)

#endif

// ----------------------------------------------------------------------------

#include_next <ao_mathf.h>

// ----------------------------------------------------------------------------
