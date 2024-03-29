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

// I2C.

// ----------------------------------------------------------------------------

#include <ao_sys.h>
#include <ao_time.h>
#include <stdbool.h>
#include <stdint.h>

// ----------------------------------------------------------------------------

typedef struct  ao_i2c_reg_t            ao_i2c_reg_t;

// ----------------------------------------------------------------------------

typedef struct  ao_i2c_reg_add_t        ao_i2c_reg_add_t;

typedef struct  ao_i2c_reg_brg_t        ao_i2c_reg_brg_t;

typedef struct  ao_i2c_reg_con_t        ao_i2c_reg_con_t;

typedef struct  ao_i2c_reg_msk_t        ao_i2c_reg_msk_t;

typedef struct  ao_i2c_reg_rcv_t        ao_i2c_reg_rcv_t;

typedef struct  ao_i2c_reg_stat_t       ao_i2c_reg_stat_t;

typedef struct  ao_i2c_reg_trn_t        ao_i2c_reg_trn_t;

// ----------------------------------------------------------------------------

#ifndef AO_I2C

#define AO_I2C

#endif

// ----------------------------------------------------------------------------

#ifndef AO_I2C_BRG_BITS

#define AO_I2C_BRG_BITS                 (16)

#endif

// ----------------------------------------------------------------------------

#ifndef AO_I2C_BRG_MAX

#define AO_I2C_BRG_MAX                  ((1 << (AO_I2C_BRG_BITS)) - 1)

#endif

#ifndef AO_I2C_BRG_MIN

#define AO_I2C_BRG_MIN                  (0)

#endif

// ----------------------------------------------------------------------------

#ifndef AO_I2C_REG_ADD_T

#define AO_I2C_REG_ADD_T

// ----------------------------------------------------------------------------

struct  ao_i2c_reg_add_t
{
        union
        {
            uint32_t        volatile    reg;

            struct
            {
                uint32_t    volatile    add     : 10;
            }
                                        bits;
        };

        uint32_t            volatile    clr;

        uint32_t            volatile    set;

        uint32_t            volatile    inv;
};

// ----------------------------------------------------------------------------

#endif

#ifndef AO_I2C_REG_BRG_T

#define AO_I2C_REG_BRG_T

// ----------------------------------------------------------------------------

struct  ao_i2c_reg_brg_t
{
        union
        {
            uint32_t        volatile    reg;

            struct
            {
                uint32_t    volatile    brg     : 16;
            }
                                        bits;
        };

        uint32_t            volatile    clr;

        uint32_t            volatile    set;

        uint32_t            volatile    inv;
};

// ----------------------------------------------------------------------------

#endif

#ifndef AO_I2C_REG_CON_T

#define AO_I2C_REG_CON_T

// ----------------------------------------------------------------------------

struct  ao_i2c_reg_con_t
{
        union
        {
            uint32_t        volatile    reg;

            struct
            {
                uint32_t    volatile    sen     :  1;

                uint32_t    volatile    rsen    :  1;

                uint32_t    volatile    pen     :  1;

                uint32_t    volatile    rcen    :  1;

                uint32_t    volatile    acken   :  1;

                uint32_t    volatile    ackdt   :  1;

                uint32_t    volatile    stren   :  1;

                uint32_t    volatile    gcen    :  1;

                uint32_t    volatile    smen    :  1;

                uint32_t    volatile    disslw  :  1;

                uint32_t    volatile    a10m    :  1;

                uint32_t    volatile    strict  :  1;

                uint32_t    volatile    sckrel  :  1;

                uint32_t    volatile    sidl    :  1;

                uint32_t    volatile            :  1;

                uint32_t    volatile    on      :  1;

                uint32_t    volatile    dhen    :  1;

                uint32_t    volatile    ahen    :  1;

                uint32_t    volatile    sbcde   :  1;

                uint32_t    volatile    sdaht   :  1;

                uint32_t    volatile    boen    :  1;

                uint32_t    volatile    scie    :  1;

                uint32_t    volatile    pcie    :  1;
            }
                                        bits;
        };

        uint32_t            volatile    clr;

        uint32_t            volatile    set;

        uint32_t            volatile    inv;
};

// ----------------------------------------------------------------------------

#endif

#ifndef AO_I2C_REG_MSK_T

#define AO_I2C_REG_MSK_T

// ----------------------------------------------------------------------------

struct  ao_i2c_reg_msk_t
{
        union
        {
            uint32_t        volatile    reg;

            struct
            {
                uint32_t    volatile    msk     : 10;
            }
                                        bits;
        };

        uint32_t            volatile    clr;

        uint32_t            volatile    set;

        uint32_t            volatile    inv;
};

// ----------------------------------------------------------------------------

#endif

#ifndef AO_I2C_REG_RCV_T

#define AO_I2C_REG_RCV_T

// ----------------------------------------------------------------------------

struct  ao_i2c_reg_rcv_t
{
        union
        {
            uint32_t        volatile    reg;

            struct
            {
                uint32_t    volatile    rxdata  : 8;
            }
                                        bits;
        };
};

// ----------------------------------------------------------------------------

#endif

#ifndef AO_I2C_REG_STAT_T

#define AO_I2C_REG_STAT_T

// ----------------------------------------------------------------------------

struct  ao_i2c_reg_stat_t
{
        union
        {
            uint32_t        volatile    reg;

            struct
            {
                uint32_t    volatile    tbf     : 1;

                uint32_t    volatile    rbf     : 1;

                uint32_t    volatile    r_w     : 1;

                uint32_t    volatile    s       : 1;

                uint32_t    volatile    p       : 1;

                uint32_t    volatile    d_a     : 1;

                uint32_t    volatile    i2cov   : 1;

                uint32_t    volatile    iwcol   : 1;

                uint32_t    volatile    add10   : 1;

                uint32_t    volatile    gcstat  : 1;

                uint32_t    volatile    bcl     : 1;

                uint32_t    volatile            : 2;

                uint32_t    volatile    acktim  : 1;

                uint32_t    volatile    trstat  : 1;

                uint32_t    volatile    ackstat : 1;
            }
                                        bits;
        };

        uint32_t            volatile    clr;

        uint32_t            volatile    set;

        uint32_t            volatile    inv;
};

// ----------------------------------------------------------------------------

#endif

#ifndef AO_I2C_REG_TRN_T

#define AO_I2C_REG_TRN_T

// ----------------------------------------------------------------------------

struct  ao_i2c_reg_trn_t
{
        union
        {
            uint32_t        volatile    reg;

            struct
            {
                uint32_t    volatile    txdata  : 8;
            }
                                        bits;
        };

        uint32_t            volatile    clr;

        uint32_t            volatile    set;

        uint32_t            volatile    inv;
};

// ----------------------------------------------------------------------------

#endif

#ifndef AO_I2C_REG_T

#define AO_I2C_REG_T

// ----------------------------------------------------------------------------

struct  ao_i2c_reg_t
{
        ao_i2c_reg_con_t                con;

        ao_i2c_reg_stat_t               stat;

        ao_i2c_reg_add_t                add;

        ao_i2c_reg_msk_t                msk;

        ao_i2c_reg_brg_t                brg;

        ao_i2c_reg_trn_t                trn;

        ao_i2c_reg_rcv_t                rcv;
};

// ----------------------------------------------------------------------------

#endif

// ----------------------------------------------------------------------------

bool    ao_i2c_ack(                     ao_i2c_reg_t * r, ao_time_t t);

bool    ao_i2c_ack_from(                ao_i2c_reg_t * r, ao_time_t t, ao_time_t b);

bool    ao_i2c_ack_forever(             ao_i2c_reg_t * r);

// ----------------------------------------------------------------------------

bool    ao_i2c_acked(                   ao_i2c_reg_t const * r);

// ----------------------------------------------------------------------------

void    ao_i2c_baud(                    ao_i2c_reg_t * r, uint32_t f_pbclk, uint32_t f);

// ----------------------------------------------------------------------------

bool    ao_i2c_nack(                    ao_i2c_reg_t * r, ao_time_t t);

bool    ao_i2c_nack_from(               ao_i2c_reg_t * r, ao_time_t t, ao_time_t b);

bool    ao_i2c_nack_forever(            ao_i2c_reg_t * r);

// ----------------------------------------------------------------------------

bool    ao_i2c_nacked(                  ao_i2c_reg_t const * r);

// ----------------------------------------------------------------------------

bool    ao_i2c_recv(                    ao_i2c_reg_t * r, uint8_t * v, ao_time_t t);

bool    ao_i2c_recv_from(               ao_i2c_reg_t * r, uint8_t * v, ao_time_t t, ao_time_t b);

bool    ao_i2c_recv_forever(            ao_i2c_reg_t * r, uint8_t * v);

// ----------------------------------------------------------------------------

bool    ao_i2c_restart(                 ao_i2c_reg_t * r, ao_time_t t);

bool    ao_i2c_restart_from(            ao_i2c_reg_t * r, ao_time_t t, ao_time_t b);

bool    ao_i2c_restart_forever(         ao_i2c_reg_t * r);

// ----------------------------------------------------------------------------

bool    ao_i2c_send(                    ao_i2c_reg_t * r, uint8_t v, ao_time_t t);

bool    ao_i2c_send_from(               ao_i2c_reg_t * r, uint8_t v, ao_time_t t, ao_time_t b);

bool    ao_i2c_send_forever(            ao_i2c_reg_t * r, uint8_t v);

// ----------------------------------------------------------------------------

bool    ao_i2c_start(                   ao_i2c_reg_t * r, ao_time_t t);

bool    ao_i2c_start_from(              ao_i2c_reg_t * r, ao_time_t t, ao_time_t b);

bool    ao_i2c_start_forever(           ao_i2c_reg_t * r);

// ----------------------------------------------------------------------------

bool    ao_i2c_stop(                    ao_i2c_reg_t * r, ao_time_t t);

bool    ao_i2c_stop_from(               ao_i2c_reg_t * r, ao_time_t t, ao_time_t b);

bool    ao_i2c_stop_forever(            ao_i2c_reg_t * r);

// ----------------------------------------------------------------------------
