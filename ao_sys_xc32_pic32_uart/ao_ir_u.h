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

// UART interrupts.

// ----------------------------------------------------------------------------

#include <stdbool.h>

// ----------------------------------------------------------------------------

void    ao_ir_u1e_disable();

void    ao_ir_u1e_enable();

bool    ao_ir_u1e_is_enabled();

// ----------------------------------------------------------------------------

bool    ao_ir_u1e_is_pending();

void    ao_ir_u1e_reply();

void    ao_ir_u1e_request();

// ----------------------------------------------------------------------------

void    ao_ir_u1rx_disable();

void    ao_ir_u1rx_enable();

bool    ao_ir_u1rx_is_enabled();

// ----------------------------------------------------------------------------

bool    ao_ir_u1rx_is_pending();

void    ao_ir_u1rx_reply();

void    ao_ir_u1rx_request();

// ----------------------------------------------------------------------------

void    ao_ir_u1tx_disable();

void    ao_ir_u1tx_enable();

bool    ao_ir_u1tx_is_enabled();

// ----------------------------------------------------------------------------

bool    ao_ir_u1tx_is_pending();

void    ao_ir_u1tx_reply();

void    ao_ir_u1tx_request();

// ----------------------------------------------------------------------------

void    ao_ir_u2e_disable();

void    ao_ir_u2e_enable();

bool    ao_ir_u2e_is_enabled();

// ----------------------------------------------------------------------------

bool    ao_ir_u2e_is_pending();

void    ao_ir_u2e_reply();

void    ao_ir_u2e_request();

// ----------------------------------------------------------------------------

void    ao_ir_u2rx_disable();

void    ao_ir_u2rx_enable();

bool    ao_ir_u2rx_is_enabled();

// ----------------------------------------------------------------------------

bool    ao_ir_u2rx_is_pending();

void    ao_ir_u2rx_reply();

void    ao_ir_u2rx_request();

// ----------------------------------------------------------------------------

void    ao_ir_u2tx_disable();

void    ao_ir_u2tx_enable();

bool    ao_ir_u2tx_is_enabled();

// ----------------------------------------------------------------------------

bool    ao_ir_u2tx_is_pending();

void    ao_ir_u2tx_reply();

void    ao_ir_u2tx_request();

// ----------------------------------------------------------------------------

void    ao_ir_u3e_disable();

void    ao_ir_u3e_enable();

bool    ao_ir_u3e_is_enabled();

// ----------------------------------------------------------------------------

bool    ao_ir_u3e_is_pending();

void    ao_ir_u3e_reply();

void    ao_ir_u3e_request();

// ----------------------------------------------------------------------------

void    ao_ir_u3rx_disable();

void    ao_ir_u3rx_enable();

bool    ao_ir_u3rx_is_enabled();

// ----------------------------------------------------------------------------

bool    ao_ir_u3rx_is_pending();

void    ao_ir_u3rx_reply();

void    ao_ir_u3rx_request();

// ----------------------------------------------------------------------------

void    ao_ir_u3tx_disable();

void    ao_ir_u3tx_enable();

bool    ao_ir_u3tx_is_enabled();

// ----------------------------------------------------------------------------

bool    ao_ir_u3tx_is_pending();

void    ao_ir_u3tx_reply();

void    ao_ir_u3tx_request();

// ----------------------------------------------------------------------------

void    ao_ir_u4e_disable();

void    ao_ir_u4e_enable();

bool    ao_ir_u4e_is_enabled();

// ----------------------------------------------------------------------------

bool    ao_ir_u4e_is_pending();

void    ao_ir_u4e_reply();

void    ao_ir_u4e_request();

// ----------------------------------------------------------------------------

void    ao_ir_u4rx_disable();

void    ao_ir_u4rx_enable();

bool    ao_ir_u4rx_is_enabled();

// ----------------------------------------------------------------------------

bool    ao_ir_u4rx_is_pending();

void    ao_ir_u4rx_reply();

void    ao_ir_u4rx_request();

// ----------------------------------------------------------------------------

void    ao_ir_u4tx_disable();

void    ao_ir_u4tx_enable();

bool    ao_ir_u4tx_is_enabled();

// ----------------------------------------------------------------------------

bool    ao_ir_u4tx_is_pending();

void    ao_ir_u4tx_reply();

void    ao_ir_u4tx_request();

// ----------------------------------------------------------------------------

void    ao_ir_u5e_disable();

void    ao_ir_u5e_enable();

bool    ao_ir_u5e_is_enabled();

// ----------------------------------------------------------------------------

bool    ao_ir_u5e_is_pending();

void    ao_ir_u5e_reply();

void    ao_ir_u5e_request();

// ----------------------------------------------------------------------------

void    ao_ir_u5rx_disable();

void    ao_ir_u5rx_enable();

bool    ao_ir_u5rx_is_enabled();

// ----------------------------------------------------------------------------

bool    ao_ir_u5rx_is_pending();

void    ao_ir_u5rx_reply();

void    ao_ir_u5rx_request();

// ----------------------------------------------------------------------------

void    ao_ir_u5tx_disable();

void    ao_ir_u5tx_enable();

bool    ao_ir_u5tx_is_enabled();

// ----------------------------------------------------------------------------

bool    ao_ir_u5tx_is_pending();

void    ao_ir_u5tx_reply();

void    ao_ir_u5tx_request();

// ----------------------------------------------------------------------------

void    ao_ir_u6e_disable();

void    ao_ir_u6e_enable();

bool    ao_ir_u6e_is_enabled();

// ----------------------------------------------------------------------------

bool    ao_ir_u6e_is_pending();

void    ao_ir_u6e_reply();

void    ao_ir_u6e_request();

// ----------------------------------------------------------------------------

void    ao_ir_u6rx_disable();

void    ao_ir_u6rx_enable();

bool    ao_ir_u6rx_is_enabled();

// ----------------------------------------------------------------------------

bool    ao_ir_u6rx_is_pending();

void    ao_ir_u6rx_reply();

void    ao_ir_u6rx_request();

// ----------------------------------------------------------------------------

void    ao_ir_u6tx_disable();

void    ao_ir_u6tx_enable();

bool    ao_ir_u6tx_is_enabled();

// ----------------------------------------------------------------------------

bool    ao_ir_u6tx_is_pending();

void    ao_ir_u6tx_reply();

void    ao_ir_u6tx_request();

// ----------------------------------------------------------------------------
