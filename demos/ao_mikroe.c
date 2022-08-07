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

#include <ao.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <xc.h>

// ----------------------------------------------------------------------------

typedef struct  ao_mikroe_1877_i2c_t        ao_mikroe_1877_i2c_t;

typedef struct  ao_mikroe_1877_job_t        ao_mikroe_1877_job_t;

typedef enum    ao_mikroe_1877_job_type_t   ao_mikroe_1877_job_type_t;

typedef struct  ao_mikroe_1877_mod_t        ao_mikroe_1877_mod_t;

typedef enum    ao_mikroe_1877_mod_state_t  ao_mikroe_1877_mod_state_t;

// ----------------------------------------------------------------------------

typedef struct  ao_mikroe_2935_mod_t        ao_mikroe_2935_mod_t;

typedef struct  ao_mikroe_2935_spi_t        ao_mikroe_2935_spi_t;

typedef struct  ao_mikroe_2935_trim_t       ao_mikroe_2935_trim_t;

// ----------------------------------------------------------------------------

typedef struct  ao_mikroe_2950_i2c_t        ao_mikroe_2950_i2c_t;

// ----------------------------------------------------------------------------

typedef struct  ao_mikroe_4186_i2c_t        ao_mikroe_4186_i2c_t;

// ----------------------------------------------------------------------------

#if defined AO_MIKROE_1877

// ----------------------------------------------------------------------------

#define AO_MIKROE_1877_I2C_ADDR             (0x40 << 1)

#define AO_MIKROE_1877_I2C_ADDR_RECV        (AO_MIKROE_1877_I2C_ADDR | 1)

#define AO_MIKROE_1877_I2C_ADDR_SEND        (AO_MIKROE_1877_I2C_ADDR | 0)

// ----------------------------------------------------------------------------

#define AO_MIKROE_1877_I2C_ATTEMPTS_DELAY   (ao_milliseconds(10))

#define AO_MIKROE_1877_I2C_ATTEMPTS_MAX     (8)

// ----------------------------------------------------------------------------

#define AO_MIKROE_1877_STREAM_CAPACITY      (64)

// ----------------------------------------------------------------------------

struct  ao_mikroe_1877_i2c_t
{
        ao_time_t                           delay_beginning;

        ao_time_t                           delay_timeout;

        uint32_t                            f;

        uint32_t                            f_pbclk;

        ao_i2c_reg_t *                      reg;

        ao_time_t                           timeout;
};

// ----------------------------------------------------------------------------

enum    ao_mikroe_1877_job_type_t
{
        AO_MIKROE_1877_JOB_TYPE_CONFIG      = 1,

        AO_MIKROE_1877_JOB_TYPE_GET_DATA    = 2,

        AO_MIKROE_1877_JOB_TYPE_GET_INFO    = 3,

        AO_MIKROE_1877_JOB_TYPE_INT         = 4,

        AO_MIKROE_1877_JOB_TYPE_RESET       = 5,

        AO_MIKROE_1877_JOB_TYPE_SLEEP       = 6,

        AO_MIKROE_1877_JOB_TYPE_STOP        = 7,

        AO_MIKROE_1877_JOB_TYPE_WAKE        = 8
};

struct  ao_mikroe_1877_job_t
{
        ao_float_t                          change_sensitivity;

        ao_time_t                           interval;

        ao_mikroe_1877_power_t              power;

        ao_mikroe_1877_reporting_t          reporting;

        ao_mikroe_1877_sensor_t             sensor;

        ao_mikroe_1877_job_type_t           type;
};

// ----------------------------------------------------------------------------

enum    ao_mikroe_1877_mod_state_t
{
        AO_MIKROE_1877_MOD_STATE_INIT1      = (1 <<  0),

        AO_MIKROE_1877_MOD_STATE_INIT2      = (1 <<  1),

        AO_MIKROE_1877_MOD_STATE_INIT3      = (1 <<  2),

        AO_MIKROE_1877_MOD_STATE_INIT4      = (1 <<  3),

        AO_MIKROE_1877_MOD_STATE_INIT5      = (1 <<  4),

        AO_MIKROE_1877_MOD_STATE_INIT6      = (1 <<  5),

        AO_MIKROE_1877_MOD_STATE_INIT7      = (1 <<  6),

        AO_MIKROE_1877_MOD_STATE_INIT8      = (1 <<  7),

        AO_MIKROE_1877_MOD_STATE_INIT9      = (1 <<  8),

        AO_MIKROE_1877_MOD_STATE_INIT10     = (1 <<  9),

        AO_MIKROE_1877_MOD_STATE_INIT       =

                                            AO_MIKROE_1877_MOD_STATE_INIT1      |
                                            AO_MIKROE_1877_MOD_STATE_INIT2      |
                                            AO_MIKROE_1877_MOD_STATE_INIT3      |
                                            AO_MIKROE_1877_MOD_STATE_INIT4      |
                                            AO_MIKROE_1877_MOD_STATE_INIT5      |
                                            AO_MIKROE_1877_MOD_STATE_INIT6      |
                                            AO_MIKROE_1877_MOD_STATE_INIT7      |
                                            AO_MIKROE_1877_MOD_STATE_INIT8      |
                                            AO_MIKROE_1877_MOD_STATE_INIT9      |
                                            AO_MIKROE_1877_MOD_STATE_INIT10,

        AO_MIKROE_1877_MOD_STATE_ON         = (1 << 10),

        AO_MIKROE_1877_MOD_STATE_OFF1       = (1 << 16),

        AO_MIKROE_1877_MOD_STATE_OFF2       = (1 << 17),

        AO_MIKROE_1877_MOD_STATE_OFF3       = (1 << 18),

        AO_MIKROE_1877_MOD_STATE_OFF4       = (1 << 19),

        AO_MIKROE_1877_MOD_STATE_OFF5       = (1 << 20),

        AO_MIKROE_1877_MOD_STATE_OFF6       = (1 << 21),

        AO_MIKROE_1877_MOD_STATE_OFF7       = (1 << 22),

        AO_MIKROE_1877_MOD_STATE_OFF        =

                                            AO_MIKROE_1877_MOD_STATE_OFF1 |
                                            AO_MIKROE_1877_MOD_STATE_OFF2 |
                                            AO_MIKROE_1877_MOD_STATE_OFF3 |
                                            AO_MIKROE_1877_MOD_STATE_OFF4 |
                                            AO_MIKROE_1877_MOD_STATE_OFF5 |
                                            AO_MIKROE_1877_MOD_STATE_OFF6 |
                                            AO_MIKROE_1877_MOD_STATE_OFF7,

        AO_MIKROE_1877_MOD_STATE_RESET      = (1 << 14),

        AO_MIKROE_1877_MOD_STATE_SLEEP1     = (1 << 24),

        AO_MIKROE_1877_MOD_STATE_SLEEP2     = (1 << 25),

        AO_MIKROE_1877_MOD_STATE_SLEEP3     = (1 << 26),

        AO_MIKROE_1877_MOD_STATE_SLEEP4     = (1 << 27),

        AO_MIKROE_1877_MOD_STATE_SLEEP5     = (1 << 28),

        AO_MIKROE_1877_MOD_STATE_SLEEP6     = (1 << 29),

        AO_MIKROE_1877_MOD_STATE_SLEEP7     = (1 << 30),

        AO_MIKROE_1877_MOD_STATE_SLEEP      =

                                            AO_MIKROE_1877_MOD_STATE_SLEEP1 |
                                            AO_MIKROE_1877_MOD_STATE_SLEEP2 |
                                            AO_MIKROE_1877_MOD_STATE_SLEEP3 |
                                            AO_MIKROE_1877_MOD_STATE_SLEEP4 |
                                            AO_MIKROE_1877_MOD_STATE_SLEEP5 |
                                            AO_MIKROE_1877_MOD_STATE_SLEEP6 |
                                            AO_MIKROE_1877_MOD_STATE_SLEEP7
};

struct  ao_mikroe_1877_mod_t
{
        ao_async_any_t                      async;

        ao_async_t *                        async_store [2];

        ao_cond_t                           cond;

        ao_cond_wait_t                      cond_wait;

        size_t                              i;

        ao_mikroe_1877_i2c_t *              i2c;

        ao_uint_t                           i2c_attempt;

        bool                                i2c_result;

        ao_pred0_t                          int_asserted;

        ao_proc0_t                          int_disable;

        ao_proc0_t                          int_enable;

        ao_mikroe_1877_job_t                job;

        ao_proc0_t                          reset_disable;

        ao_proc0_t                          reset_enable;

        ao_sleep_t                          sleep;

        ao_spop_obj_t                       spop;

        ao_mikroe_1877_mod_state_t          state;

        ao_stream4obj_t                     stream;

        ao_mikroe_1877_job_t                stream_store[AO_MIKROE_1877_STREAM_CAPACITY];

        ao_task_t *                         task;

        ao_proc0_t                          wake_disable;

        ao_proc0_t                          wake_enable;
};

// ----------------------------------------------------------------------------

#endif

#if defined AO_MIKROE_2935

// ----------------------------------------------------------------------------

struct  ao_mikroe_2935_spi_t
{
        ao_proc0_t              begin;

        ao_proc0_t              end;

        uint32_t                f;

        uint32_t                f_pbclk;

        ao_spi_reg_t *          reg;
};

struct  ao_mikroe_2935_trim_t
{
        int8_t                  x1;

        int8_t                  y1;

        int8_t                  x2;

        int8_t                  y2;

        uint16_t                z1;

        int16_t                 z2;

        int16_t                 z3;

        int16_t                 z4;

        uint8_t                 xy1;

        int8_t                  xy2;

        uint16_t                xyz1;
};

struct  ao_mikroe_2935_mod_t
{
        ao_async_any_t          async;

        ao_async_t *            async_store [3];

        ao_mikroe_2935_t        data;

        size_t                  i;

        ao_time_t               period;

        uint16_t                repetitions_xy;

        uint16_t                repetitions_z;

        ao_sem_t                sem;

        ao_sem_take_t           sem_take;

        ao_sleep_t              sleep_1;

        ao_sleep_t              sleep_2;

        ao_mikroe_2935_spi_t *  spi;

        ao_task_t *             task;

        ao_mikroe_2935_trim_t   trim;
};

// ----------------------------------------------------------------------------

#endif

#if defined AO_MIKROE_2950

// ----------------------------------------------------------------------------

struct  ao_mikroe_2950_i2c_t
{
        uint32_t        f;

        uint32_t        f_pbclk;

        ao_i2c_reg_t *  reg;
};

// ----------------------------------------------------------------------------

#endif

#if defined AO_MIKROE_4186

// ----------------------------------------------------------------------------

#define AO_MIKROE_4186_ADDR         (0x22 << 1)

#define AO_MIKROE_4186_ADDR_RECV    (AO_MIKROE_4186_ADDR | 1)

#define AO_MIKROE_4186_ADDR_SEND    (AO_MIKROE_4186_ADDR | 0)

// ----------------------------------------------------------------------------

#define AO_MIKROE_4186_CONFIG       (0x0C)

#define AO_MIKROE_4186_INPUT        (0x00)

#define AO_MIKROE_4186_OUTPUT       (0x04)

#define AO_MIKROE_4186_POLARITY     (0x08)

// ----------------------------------------------------------------------------

struct  ao_mikroe_4186_i2c_t
{
        ao_time_t                   delay_beginning;

        ao_time_t                   delay_timeout;

        uint32_t                    f;

        uint32_t                    f_pbclk;

        ao_i2c_reg_t *              reg;

        ao_time_t                   timeout;
};

// ----------------------------------------------------------------------------

#endif

// ----------------------------------------------------------------------------

#if defined AO_MIKROE_1877

// ----------------------------------------------------------------------------

static  void                    ao_boot_mikroe_1877_i2c(                ao_mikroe_1877_i2c_t * I);

// ----------------------------------------------------------------------------

static  void                    ao_mikroe_1877_data_scan(               uint8_t * x, ao_mikroe_1877_data_t * D);

// ----------------------------------------------------------------------------

static  ao_float_t              ao_mikroe_1877_decode(                  ao_mikroe_1877_sensor_t S, ao_float_t x);

// ----------------------------------------------------------------------------

static  ao_float_t              ao_mikroe_1877_encode(                  ao_mikroe_1877_sensor_t S, ao_float_t x);

// ----------------------------------------------------------------------------

static  bool                    ao_mikroe_1877_i2c_config(              ao_mikroe_1877_i2c_t * I, ao_mikroe_1877_info_t * X);

// ----------------------------------------------------------------------------

static  void                    ao_mikroe_1877_i2c_delay(               ao_mikroe_1877_i2c_t * I);

static  void                    ao_mikroe_1877_i2c_delay_begin(         ao_mikroe_1877_i2c_t * I);

static  void                    ao_mikroe_1877_i2c_delay_end(           ao_mikroe_1877_i2c_t * I);

// ----------------------------------------------------------------------------

static  void                    ao_mikroe_1877_i2c_error(               ao_mikroe_1877_i2c_t * I);

// ----------------------------------------------------------------------------

static  bool                    ao_mikroe_1877_i2c_get_data(            ao_mikroe_1877_i2c_t * I, ao_mikroe_1877_data_t * D);

static  bool                    ao_mikroe_1877_i2c_get_data_next(       ao_mikroe_1877_i2c_t * I, ao_mikroe_1877_data_t * D);

static  bool                    ao_mikroe_1877_i2c_get_info(            ao_mikroe_1877_i2c_t * I, ao_mikroe_1877_info_t * X);

// ----------------------------------------------------------------------------

static  bool                    ao_mikroe_1877_i2c_hid(                 ao_mikroe_1877_i2c_t * I);

// ----------------------------------------------------------------------------

static  bool                    ao_mikroe_1877_i2c_power_on(            ao_mikroe_1877_i2c_t * I);

static  bool                    ao_mikroe_1877_i2c_power_sleep(         ao_mikroe_1877_i2c_t * I);

// ----------------------------------------------------------------------------

static  bool                    ao_mikroe_1877_i2c_recv(                ao_mikroe_1877_i2c_t * I);

// ----------------------------------------------------------------------------

static  bool                    ao_mikroe_1877_i2c_reset(               ao_mikroe_1877_i2c_t * I);

// ----------------------------------------------------------------------------

static  bool                    ao_mikroe_1877_i2c_zero(                ao_mikroe_1877_i2c_t * I);

// ----------------------------------------------------------------------------

static  void                    ao_mikroe_1877_info_print(              uint8_t * x, ao_mikroe_1877_info_t * I);

static  void                    ao_mikroe_1877_info_scan(               uint8_t * x, ao_mikroe_1877_info_t * I);

// ----------------------------------------------------------------------------

static  ao_mikroe_1877_mod_t *  ao_mikroe_1877_mod(                     size_t i);

// ----------------------------------------------------------------------------

static  void                    ao_mikroe_1877_mod_int(                 ao_mikroe_1877_mod_t * M);

// ----------------------------------------------------------------------------

static  void                    ao_mikroe_1877_mod_job(                 ao_mikroe_1877_mod_t * M, ao_mikroe_1877_job_t * J);

// ----------------------------------------------------------------------------

static  void                    ao_mikroe_1877_mod_run_init(            ao_mikroe_1877_mod_t * M);

// ----------------------------------------------------------------------------

static  void                    ao_mikroe_1877_mod_run_init1(           ao_mikroe_1877_mod_t * M);

static  void                    ao_mikroe_1877_mod_run_init2(           ao_mikroe_1877_mod_t * M);

static  void                    ao_mikroe_1877_mod_run_init3(           ao_mikroe_1877_mod_t * M);

static  void                    ao_mikroe_1877_mod_run_init4(           ao_mikroe_1877_mod_t * M);

static  void                    ao_mikroe_1877_mod_run_init5(           ao_mikroe_1877_mod_t * M);

static  void                    ao_mikroe_1877_mod_run_init6(           ao_mikroe_1877_mod_t * M);

static  void                    ao_mikroe_1877_mod_run_init7(           ao_mikroe_1877_mod_t * M);

static  void                    ao_mikroe_1877_mod_run_init8(           ao_mikroe_1877_mod_t * M);

static  void                    ao_mikroe_1877_mod_run_init9(           ao_mikroe_1877_mod_t * M);

static  void                    ao_mikroe_1877_mod_run_init10(          ao_mikroe_1877_mod_t * M);

// ----------------------------------------------------------------------------

static  void                    ao_mikroe_1877_mod_run_off(             ao_mikroe_1877_mod_t * M);

// ----------------------------------------------------------------------------

static  void                    ao_mikroe_1877_mod_run_off1(            ao_mikroe_1877_mod_t * M);

static  void                    ao_mikroe_1877_mod_run_off2(            ao_mikroe_1877_mod_t * M);

static  void                    ao_mikroe_1877_mod_run_off3(            ao_mikroe_1877_mod_t * M);

static  void                    ao_mikroe_1877_mod_run_off4(            ao_mikroe_1877_mod_t * M);

static  void                    ao_mikroe_1877_mod_run_off5(            ao_mikroe_1877_mod_t * M);

static  void                    ao_mikroe_1877_mod_run_off6(            ao_mikroe_1877_mod_t * M);

static  void                    ao_mikroe_1877_mod_run_off7(            ao_mikroe_1877_mod_t * M);

// ----------------------------------------------------------------------------

static  void                    ao_mikroe_1877_mod_run_on(              ao_mikroe_1877_mod_t * M);

// ----------------------------------------------------------------------------

static  void                    ao_mikroe_1877_mod_run_on_job(          ao_mikroe_1877_mod_t * M);

// ----------------------------------------------------------------------------

static  void                    ao_mikroe_1877_mod_run_on_job_config(   ao_mikroe_1877_mod_t * M);

static  void                    ao_mikroe_1877_mod_run_on_job_get_data( ao_mikroe_1877_mod_t * M);

static  void                    ao_mikroe_1877_mod_run_on_job_get_info( ao_mikroe_1877_mod_t * M);

static  void                    ao_mikroe_1877_mod_run_on_job_int(      ao_mikroe_1877_mod_t * M);

static  void                    ao_mikroe_1877_mod_run_on_job_reset(    ao_mikroe_1877_mod_t * M);

static  void                    ao_mikroe_1877_mod_run_on_job_sleep(    ao_mikroe_1877_mod_t * M);

static  void                    ao_mikroe_1877_mod_run_on_job_stop(     ao_mikroe_1877_mod_t * M);

// ----------------------------------------------------------------------------

static  void                    ao_mikroe_1877_mod_run_reset(           ao_mikroe_1877_mod_t * M);

// ----------------------------------------------------------------------------

static  void                    ao_mikroe_1877_mod_run_sleep(           ao_mikroe_1877_mod_t * M);

// ----------------------------------------------------------------------------

static  void                    ao_mikroe_1877_mod_run_sleep1(          ao_mikroe_1877_mod_t * M);

static  void                    ao_mikroe_1877_mod_run_sleep2(          ao_mikroe_1877_mod_t * M);

static  void                    ao_mikroe_1877_mod_run_sleep3(          ao_mikroe_1877_mod_t * M);

static  void                    ao_mikroe_1877_mod_run_sleep4(          ao_mikroe_1877_mod_t * M);

static  void                    ao_mikroe_1877_mod_run_sleep5(          ao_mikroe_1877_mod_t * M);

static  void                    ao_mikroe_1877_mod_run_sleep6(          ao_mikroe_1877_mod_t * M);

static  void                    ao_mikroe_1877_mod_run_sleep7(          ao_mikroe_1877_mod_t * M);

// ----------------------------------------------------------------------------

static  void                    ao_mikroe_1877_mod_set_init(            ao_mikroe_1877_mod_t * M);

// ----------------------------------------------------------------------------

static  void                    ao_mikroe_1877_mod_set_init1(           ao_mikroe_1877_mod_t * M);

static  void                    ao_mikroe_1877_mod_set_init2(           ao_mikroe_1877_mod_t * M);

static  void                    ao_mikroe_1877_mod_set_init3(           ao_mikroe_1877_mod_t * M);

static  void                    ao_mikroe_1877_mod_set_init4(           ao_mikroe_1877_mod_t * M);

static  void                    ao_mikroe_1877_mod_set_init5(           ao_mikroe_1877_mod_t * M);

static  void                    ao_mikroe_1877_mod_set_init6(           ao_mikroe_1877_mod_t * M);

static  void                    ao_mikroe_1877_mod_set_init7(           ao_mikroe_1877_mod_t * M);

static  void                    ao_mikroe_1877_mod_set_init8(           ao_mikroe_1877_mod_t * M);

static  void                    ao_mikroe_1877_mod_set_init9(           ao_mikroe_1877_mod_t * M);

static  void                    ao_mikroe_1877_mod_set_init10(          ao_mikroe_1877_mod_t * M);

// ----------------------------------------------------------------------------

static  void                    ao_mikroe_1877_mod_set_off(             ao_mikroe_1877_mod_t * M);

// ----------------------------------------------------------------------------

static  void                    ao_mikroe_1877_mod_set_off1(            ao_mikroe_1877_mod_t * M);

static  void                    ao_mikroe_1877_mod_set_off2(            ao_mikroe_1877_mod_t * M);

static  void                    ao_mikroe_1877_mod_set_off3(            ao_mikroe_1877_mod_t * M);

static  void                    ao_mikroe_1877_mod_set_off4(            ao_mikroe_1877_mod_t * M);

static  void                    ao_mikroe_1877_mod_set_off5(            ao_mikroe_1877_mod_t * M);

static  void                    ao_mikroe_1877_mod_set_off6(            ao_mikroe_1877_mod_t * M);

static  void                    ao_mikroe_1877_mod_set_off7(            ao_mikroe_1877_mod_t * M);

// ----------------------------------------------------------------------------

static  void                    ao_mikroe_1877_mod_set_on(              ao_mikroe_1877_mod_t * M);

// ----------------------------------------------------------------------------

static  void                    ao_mikroe_1877_mod_set_reset(           ao_mikroe_1877_mod_t * M);

// ----------------------------------------------------------------------------

static  void                    ao_mikroe_1877_mod_set_sleep(           ao_mikroe_1877_mod_t * M);

// ----------------------------------------------------------------------------

static  void                    ao_mikroe_1877_mod_set_sleep1(          ao_mikroe_1877_mod_t * M);

static  void                    ao_mikroe_1877_mod_set_sleep2(          ao_mikroe_1877_mod_t * M);

static  void                    ao_mikroe_1877_mod_set_sleep3(          ao_mikroe_1877_mod_t * M);

static  void                    ao_mikroe_1877_mod_set_sleep4(          ao_mikroe_1877_mod_t * M);

static  void                    ao_mikroe_1877_mod_set_sleep5(          ao_mikroe_1877_mod_t * M);

static  void                    ao_mikroe_1877_mod_set_sleep6(          ao_mikroe_1877_mod_t * M);

static  void                    ao_mikroe_1877_mod_set_sleep7(          ao_mikroe_1877_mod_t * M);

// ----------------------------------------------------------------------------

static  void                    ao_mikroe_1877_task_proc(               void * x);

// ----------------------------------------------------------------------------

void ao_boot_mikroe_1877_i2c(ao_mikroe_1877_i2c_t * I)
{
    // Assert.

    ao_assert(I);

    ao_assert(I->f);

    ao_assert(I->f_pbclk);

    ao_assert(I->reg);


    // Variables.

    uint32_t f = I->f;

    uint32_t f_pbclk = I->f_pbclk;

    ao_i2c_reg_t * R = I->reg;


    // Ready.

    // DS00001888.

    // Bus Free Time.

    // The amount of time the bus must be free before a new transmission can
    // start.

    // 100 kHz mode: 4.7 µs.

    // 400 kHz mode: 1.3 µs.

    if (f >= 400000UL)
    {
        I->delay_timeout = ao_microseconds(1.3);
    }

    else
    {
        I->delay_timeout = ao_microseconds(4.7);
    }


    // Ready.

    R->con.reg = 0;

    ao_i2c_baud(R, f_pbclk, f);

    R->con.bits.on = 1;
}

// ----------------------------------------------------------------------------

void ao_mikroe_1877_config(size_t i, ao_mikroe_1877_info_t const * I)
{
    // Variables.

    ao_mikroe_1877_job_t J;

    ao_mikroe_1877_mod_t * M;


    // Ready.

    M = ao_mikroe_1877_mod(i);

    if (M)
    {
        J.type = AO_MIKROE_1877_JOB_TYPE_CONFIG;

        J.sensor = I->sensor;

        J.change_sensitivity = I->change_sensitivity;

        J.interval = I->interval;

        J.power = I->power;

        J.reporting = I->reporting;

        ao_mikroe_1877_mod_job(M, &J);
    }

    else
    {
        ao_assert(false);
    }
}

// ----------------------------------------------------------------------------

void ao_mikroe_1877_data_scan(uint8_t * x, ao_mikroe_1877_data_t * D)
{
    // Variables.

    ao_float_t f;

    int16_t i;

    ao_mikroe_1877_sensor_t S = (ao_mikroe_1877_sensor_t) x[2];

    uint16_t u0;

    uint16_t u1;


    // Ready.

    D->sensor = S;

    D->state = (ao_mikroe_1877_state_t) x[3];

    D->event = (ao_mikroe_1877_event_t) x[4];

    switch (S)
    {
        case AO_MIKROE_1877_SENSOR_ACCELEROMETER:
        case AO_MIKROE_1877_SENSOR_ACCELEROMETER_RAW:

            u0 = (uint16_t) x[5];

            u1 = (uint16_t) x[6];

            u1 = (u1 << 8) | u0;

            i = *((int16_t *) &u1);

            f = (ao_float_t) i;

            D->data.accelerometer.x = ao_mikroe_1877_decode(S, f);

            u0 = (uint16_t) x[7];

            u1 = (uint16_t) x[8];

            u1 = (u1 << 8) | u0;

            i = *((int16_t *) &u1);

            f = (ao_float_t) i;

            D->data.accelerometer.y = ao_mikroe_1877_decode(S, f);

            u0 = (uint16_t) x[9];

            u1 = (uint16_t) x[10];

            u1 = (u1 << 8) | u0;

            i = *((int16_t *) &u1);

            f = (ao_float_t) i;

            D->data.accelerometer.z = ao_mikroe_1877_decode(S, f);

            D->data.accelerometer.shake_detected = x[11] ? true : false;

            break;

        case AO_MIKROE_1877_SENSOR_GYROSCOPE:
        case AO_MIKROE_1877_SENSOR_GYROSCOPE_RAW:

            u0 = (uint16_t) x[5];

            u1 = (uint16_t) x[6];

            u1 = (u1 << 8) | u0;

            i = *((int16_t *) &u1);

            f = (ao_float_t) i;

            D->data.gyroscope.x = ao_mikroe_1877_decode(S, f);

            u0 = (uint16_t) x[7];

            u1 = (uint16_t) x[8];

            u1 = (u1 << 8) | u0;

            i = *((int16_t *) &u1);

            f = (ao_float_t) i;

            D->data.gyroscope.y = ao_mikroe_1877_decode(S, f);

            u0 = (uint16_t) x[9];

            u1 = (uint16_t) x[10];

            u1 = (u1 << 8) | u0;

            i = *((int16_t *) &u1);

            f = (ao_float_t) i;

            D->data.gyroscope.z = ao_mikroe_1877_decode(S, f);

            D->data.gyroscope.shake_detected = x[11] ? true : false;

            break;

        case AO_MIKROE_1877_SENSOR_INCLINOMETER:

            u0 = (uint16_t) x[5];

            u1 = (uint16_t) x[6];

            u1 = (u1 << 8) | u0;

            i = *((int16_t *) &u1);

            f = (ao_float_t) i;

            D->data.inclinometer.x = ao_mikroe_1877_decode(S, f);

            u0 = (uint16_t) x[7];

            u1 = (uint16_t) x[8];

            u1 = (u1 << 8) | u0;

            i = *((int16_t *) &u1);

            f = (ao_float_t) i;

            D->data.inclinometer.y = ao_mikroe_1877_decode(S, f);

            u0 = (uint16_t) x[9];

            u1 = (uint16_t) x[10];

            u1 = (u1 << 8) | u0;

            i = *((int16_t *) &u1);

            f = (ao_float_t) i;

            D->data.inclinometer.z = ao_mikroe_1877_decode(S, f);

            break;

        case AO_MIKROE_1877_SENSOR_MAGNETOMETER:
        case AO_MIKROE_1877_SENSOR_MAGNETOMETER_RAW:

            u0 = (uint16_t) x[5];

            u1 = (uint16_t) x[6];

            u1 = (u1 << 8) | u0;

            i = *((int16_t *) &u1);

            f = (ao_float_t) i;

            D->data.magnetometer.heading = ao_mikroe_1877_decode(S, f);

            u0 = (uint16_t) x[7];

            u1 = (uint16_t) x[8];

            u1 = (u1 << 8) | u0;

            i = *((int16_t *) &u1);

            f = (ao_float_t) i;

            D->data.magnetometer.x = ao_mikroe_1877_decode(S, f);

            u0 = (uint16_t) x[9];

            u1 = (uint16_t) x[10];

            u1 = (u1 << 8) | u0;

            i = *((int16_t *) &u1);

            f = (ao_float_t) i;

            D->data.magnetometer.y = ao_mikroe_1877_decode(S, f);

            u0 = (uint16_t) x[11];

            u1 = (uint16_t) x[12];

            u1 = (u1 << 8) | u0;

            i = *((int16_t *) &u1);

            f = (ao_float_t) i;

            D->data.magnetometer.z = ao_mikroe_1877_decode(S, f);

            break;

        case AO_MIKROE_1877_SENSOR_ORIENTATION:

            u0 = (uint16_t) x[5];

            u1 = (uint16_t) x[6];

            u1 = (u1 << 8) | u0;

            i = *((int16_t *) &u1);

            f = (ao_float_t) i;

            D->data.orientation.x = ao_mikroe_1877_decode(S, f);

            u0 = (uint16_t) x[7];

            u1 = (uint16_t) x[8];

            u1 = (u1 << 8) | u0;

            i = *((int16_t *) &u1);

            f = (ao_float_t) i;

            D->data.orientation.y = ao_mikroe_1877_decode(S, f);

            u0 = (uint16_t) x[9];

            u1 = (uint16_t) x[10];

            u1 = (u1 << 8) | u0;

            i = *((int16_t *) &u1);

            f = (ao_float_t) i;

            D->data.orientation.z = ao_mikroe_1877_decode(S, f);

            u0 = (uint16_t) x[11];

            u1 = (uint16_t) x[12];

            u1 = (u1 << 8) | u0;

            i = *((int16_t *) &u1);

            f = (ao_float_t) i;

            D->data.orientation.w = ao_mikroe_1877_decode(S, f);

            break;

        default:

            ao_assert(false);

            break;
    }
}

// ----------------------------------------------------------------------------

ao_float_t ao_mikroe_1877_decode(ao_mikroe_1877_sensor_t S, ao_float_t x)
{
    switch (S)
    {
        case AO_MIKROE_1877_SENSOR_ACCELEROMETER:
        case AO_MIKROE_1877_SENSOR_ACCELEROMETER_RAW:
        case AO_MIKROE_1877_SENSOR_ORIENTATION:

            x = x * (ao_float_t) 0.001;

            break;

        case AO_MIKROE_1877_SENSOR_GYROSCOPE:
        case AO_MIKROE_1877_SENSOR_GYROSCOPE_RAW:

            x = x * (ao_float_t) 0.1;

            break;

        case AO_MIKROE_1877_SENSOR_INCLINOMETER:
        case AO_MIKROE_1877_SENSOR_MAGNETOMETER:
        case AO_MIKROE_1877_SENSOR_MAGNETOMETER_RAW:

            break;

        default:

            ao_assert(false);

            break;
    }

    return x;
}

// ----------------------------------------------------------------------------

ao_float_t ao_mikroe_1877_encode(ao_mikroe_1877_sensor_t S, ao_float_t x)
{
    switch (S)
    {
        case AO_MIKROE_1877_SENSOR_ACCELEROMETER:
        case AO_MIKROE_1877_SENSOR_ACCELEROMETER_RAW:
        case AO_MIKROE_1877_SENSOR_ORIENTATION:

            x = x * (ao_float_t) 1000.0;

            break;

        case AO_MIKROE_1877_SENSOR_GYROSCOPE:
        case AO_MIKROE_1877_SENSOR_GYROSCOPE_RAW:

            x = x * (ao_float_t) 10.0;

            break;

        case AO_MIKROE_1877_SENSOR_INCLINOMETER:
        case AO_MIKROE_1877_SENSOR_MAGNETOMETER:
        case AO_MIKROE_1877_SENSOR_MAGNETOMETER_RAW:

            break;

        default:

            ao_assert(false);

            break;
    }

    return x;
}

// ----------------------------------------------------------------------------

void ao_mikroe_1877_get_data(size_t i, ao_mikroe_1877_sensor_t S)
{
    // Variables.

    ao_mikroe_1877_job_t J;

    ao_mikroe_1877_mod_t * M;


    // Ready.

    M = ao_mikroe_1877_mod(i);

    if (M)
    {
        J.type = AO_MIKROE_1877_JOB_TYPE_GET_DATA;

        J.sensor = S;

        ao_mikroe_1877_mod_job(M, &J);
    }

    else
    {
        ao_assert(false);
    }
}

void ao_mikroe_1877_get_info(size_t i, ao_mikroe_1877_sensor_t S)
{
    // Variables.

    ao_mikroe_1877_job_t J;

    ao_mikroe_1877_mod_t * M;


    // Ready.

    M = ao_mikroe_1877_mod(i);

    if (M)
    {
        J.type = AO_MIKROE_1877_JOB_TYPE_GET_INFO;

        J.sensor = S;

        ao_mikroe_1877_mod_job(M, &J);
    }

    else
    {
        ao_assert(false);
    }
}

// ----------------------------------------------------------------------------

bool ao_mikroe_1877_i2c_config(ao_mikroe_1877_i2c_t * I, ao_mikroe_1877_info_t * X)
{
    // Variables.

    ao_time_t B = ao_now();

    uint8_t d[33];

    ptrdiff_t n;

    bool r;

    ao_i2c_reg_t * R = I->reg;

    ao_mikroe_1877_sensor_t S = X->sensor;

    uint8_t s = (uint8_t) S;

    ao_time_t T = I->timeout;


    // Ready.

    ao_mikroe_1877_info_print(d, X);

    r = true;

    r = r && ao_i2c_start_from(R, T, B);

    r = r && ao_i2c_send_from(R, AO_MIKROE_1877_I2C_ADDR_SEND, T, B);

    r = r && ao_i2c_send_from(R, 0x05, T, B);       // Command register LO.

    r = r && ao_i2c_send_from(R, 0x00, T, B);       // Command register HI.

    r = r && ao_i2c_send_from(R, 0x30 | s, T, B);   // Command data     LO.

    r = r && ao_i2c_send_from(R, 0x03, T, B);       // Command data     HI: SET_REPORT.

    r = r && ao_i2c_send_from(R, 0x06, T, B);       // Data register    LO.

    r = r && ao_i2c_send_from(R, 0x00, T, B);       // Data register    HI.

    n = 33;

    do
    {
        r = r && ao_i2c_send_from(R, d[33 - n], T, B);

        n--;
    }
    while (r && n);

    r = r && ao_i2c_stop_from(R, T, B);

    ao_mikroe_1877_i2c_delay(I);

    return r;
}

// ----------------------------------------------------------------------------

void ao_mikroe_1877_i2c_delay(ao_mikroe_1877_i2c_t * I)
{
    ao_time_t t = I->delay_timeout;

    ao_spin(t);
}

void ao_mikroe_1877_i2c_delay_begin(ao_mikroe_1877_i2c_t * I)
{
    I->delay_beginning = ao_now();
}

void ao_mikroe_1877_i2c_delay_end(ao_mikroe_1877_i2c_t * I)
{
    ao_time_t b = I->delay_beginning;

    ao_time_t t = I->delay_timeout;

    ao_spin_from(t, b);
}

// ----------------------------------------------------------------------------

void ao_mikroe_1877_i2c_error(ao_mikroe_1877_i2c_t * I)
{
    // Variables.

    ao_i2c_reg_t * R = I->reg;


    // Ready.

    // DS80000663.

    // PIC32MZ Embedded Connectivity with Floating Point Unit (EF) Family.

    // Silicon Errata and Data Sheet Clarification.

    // Issue 6. Reference DSCAPP-4878.

    // ... Indeterminate I2C module behavior may result ...

    // ... transactions in progress are inadvertently suspended without error indications ...

    // Workaround:

    // ... disable the module ...

    // ... wait 4 instruction cycles ...

    // ... Then, re-enable the module ... and resume normal operation ...

    R->con.bits.on = 0;

    asm volatile ("nop");
    asm volatile ("nop");
    asm volatile ("nop");
    asm volatile ("nop");
    asm volatile ("nop");
    asm volatile ("nop");
    asm volatile ("nop");
    asm volatile ("nop");

    R->con.bits.on = 1;
}

// ----------------------------------------------------------------------------

bool ao_mikroe_1877_i2c_get_data(ao_mikroe_1877_i2c_t * I, ao_mikroe_1877_data_t * D)
{
    // Variables.

    ao_time_t B = ao_now();

    uint8_t d[13];

    ptrdiff_t n;

    bool r1;

    bool r2;

    ao_i2c_reg_t * R = I->reg;

    ao_mikroe_1877_sensor_t S = D->sensor;

    uint8_t s = (uint8_t) S;

    ao_time_t T = I->timeout;


    // Ready.

    r2 = true;

    r1 = true;

    r1 = r1 && ao_i2c_start_from(R, T, B);

    r1 = r1 && ao_i2c_send_from(R, AO_MIKROE_1877_I2C_ADDR_SEND, T, B);

    r1 = r1 && ao_i2c_send_from(R, 0x05, T, B);     // Command register LO.

    r1 = r1 && ao_i2c_send_from(R, 0x00, T, B);     // Command register HI.

    r1 = r1 && ao_i2c_send_from(R, 0x10 | s, T, B); // Command data     LO.

    r1 = r1 && ao_i2c_send_from(R, 0x02, T, B);     // Command data     HI: GET_REPORT.

    r1 = r1 && ao_i2c_send_from(R, 0x06, T, B);     // Data register    LO.

    r1 = r1 && ao_i2c_send_from(R, 0x00, T, B);     // Data register    HI.

    r1 = r1 && ao_i2c_restart_from(R, T, B);

    r1 = r1 && ao_i2c_send_from(R, AO_MIKROE_1877_I2C_ADDR_RECV, T, B);

    r1 = r1 && ao_i2c_recv_from(R, d + 0, T, B);

    r1 = r1 && ao_i2c_ack_from(R, T, B);

    r1 = r1 && ao_i2c_recv_from(R, d + 1, T, B);

    if
    (
        d[0] >= 11 &&
        d[0] <= 13 &&
        d[1] ==  0
    )
    {
        r1 = r1 && ao_i2c_ack_from(R, T, B);

        r1 = r1 && ao_i2c_recv_from(R, d + 2, T, B);

        if (d[2] == s)
        {
            n = (ptrdiff_t) d[0];

            n = n - 3;

            do
            {
                r1 = r1 && ao_i2c_ack_from(R, T, B);

                r1 = r1 && ao_i2c_recv_from(R, d + 13 - n, T, B);

                n--;
            }
            while (r1 && n);
        }

        else
        {
            r2 = false;
        }
    }

    else
    {
        r2 = false;
    }

    r1 = r1 && ao_i2c_nack_from(R, T, B);

    r1 = r1 && ao_i2c_stop_from(R, T, B);

    if (r2)
    {
        ao_mikroe_1877_i2c_delay_begin(I);

        ao_mikroe_1877_data_scan(d, D);

        ao_mikroe_1877_i2c_delay_end(I);
    }

    else
    {
        ao_mikroe_1877_i2c_delay(I);
    }

    return r1 && r2;
}

bool ao_mikroe_1877_i2c_get_data_next(ao_mikroe_1877_i2c_t * I, ao_mikroe_1877_data_t * D)
{
    // Variables.

    ao_time_t B = ao_now();

    uint8_t d[13];

    ptrdiff_t n;

    bool r1;

    bool r2;

    ao_i2c_reg_t * R = I->reg;

    ao_time_t T = I->timeout;


    // Ready.

    r2 = true;

    r1 = true;

    r1 = r1 && ao_i2c_start_from(R, T, B);

    r1 = r1 && ao_i2c_send_from(R, AO_MIKROE_1877_I2C_ADDR_RECV, T, B);

    r1 = r1 && ao_i2c_recv_from(R, d + 0, T, B);

    r1 = r1 && ao_i2c_ack_from(R, T, B);

    r1 = r1 && ao_i2c_recv_from(R, d + 1, T, B);

    if
    (
        d[0] >= 11 &&
        d[0] <= 13 &&
        d[1] ==  0
    )
    {
        r1 = r1 && ao_i2c_ack_from(R, T, B);

        r1 = r1 && ao_i2c_recv_from(R, d + 2, T, B);

        if
        (
            d[2] >= 1 &&
            d[2] <= 8
        )
        {
            n = (ptrdiff_t) d[0];

            n = n - 3;

            do
            {
                r1 = r1 && ao_i2c_ack_from(R, T, B);

                r1 = r1 && ao_i2c_recv_from(R, d + 13 - n, T, B);

                n--;
            }
            while (r1 && n);
        }

        else
        {
            r2 = false;
        }
    }

    else
    {
        r2 = false;
    }

    r1 = r1 && ao_i2c_nack_from(R, T, B);

    r1 = r1 && ao_i2c_stop_from(R, T, B);

    if (r2)
    {
        ao_mikroe_1877_i2c_delay_begin(I);

        ao_mikroe_1877_data_scan(d, D);

        ao_mikroe_1877_i2c_delay_end(I);
    }

    else
    {
        ao_mikroe_1877_i2c_delay(I);
    }

    return r1 && r2;
}

bool ao_mikroe_1877_i2c_get_info(ao_mikroe_1877_i2c_t * I, ao_mikroe_1877_info_t * X)
{
    // Variables.

    ao_time_t B = ao_now();

    uint8_t d[33];

    ptrdiff_t n;

    bool r1;

    bool r2;

    ao_i2c_reg_t * R = I->reg;

    ao_mikroe_1877_sensor_t S = X->sensor;

    uint8_t s = (uint8_t) S;

    ao_time_t T = I->timeout;


    // Ready.

    r2 = true;

    r1 = true;

    r1 = r1 && ao_i2c_start_from(R, T, B);

    r1 = r1 && ao_i2c_send_from(R, AO_MIKROE_1877_I2C_ADDR_SEND, T, B);

    r1 = r1 && ao_i2c_send_from(R, 0x05, T, B);     // Command register LO.

    r1 = r1 && ao_i2c_send_from(R, 0x00, T, B);     // Command register HI.

    r1 = r1 && ao_i2c_send_from(R, 0x30 | s, T, B); // Command data     LO.

    r1 = r1 && ao_i2c_send_from(R, 0x02, T, B);     // Command data     HI: GET_REPORT.

    r1 = r1 && ao_i2c_send_from(R, 0x06, T, B);     // Data register    LO.

    r1 = r1 && ao_i2c_send_from(R, 0x00, T, B);     // Data register    HI.

    r1 = r1 && ao_i2c_restart_from(R, T, B);

    r1 = r1 && ao_i2c_send_from(R, AO_MIKROE_1877_I2C_ADDR_RECV, T, B);

    r1 = r1 && ao_i2c_recv_from(R, d + 0, T, B);

    r1 = r1 && ao_i2c_ack_from(R, T, B);

    r1 = r1 && ao_i2c_recv_from(R, d + 1, T, B);

    if
    (
        d[0] == 33 &&
        d[1] ==  0
    )
    {
        r1 = r1 && ao_i2c_ack_from(R, T, B);

        r1 = r1 && ao_i2c_recv_from(R, d + 2, T, B);

        if (d[2] == s)
        {
            n = 30;

            do
            {
                r1 = r1 && ao_i2c_ack_from(R, T, B);

                r1 = r1 && ao_i2c_recv_from(R, d + 33 - n, T, B);

                n--;
            }
            while (r1 && n);
        }

        else
        {
            r2 = false;
        }
    }

    else
    {
        r2 = false;
    }

    r1 = r1 && ao_i2c_nack_from(R, T, B);

    r1 = r1 && ao_i2c_stop_from(R, T, B);

    if (r2)
    {
        ao_mikroe_1877_i2c_delay_begin(I);

        ao_mikroe_1877_info_scan(d, X);

        ao_mikroe_1877_i2c_delay_end(I);
    }

    else
    {
        ao_mikroe_1877_i2c_delay(I);
    }

    return r1 && r2;
}

// ----------------------------------------------------------------------------

bool ao_mikroe_1877_i2c_hid(ao_mikroe_1877_i2c_t * I)
{
    // Variables.

    ao_time_t B = ao_now();

    uint8_t d[30];

    ptrdiff_t n;

    bool r;

    ao_i2c_reg_t * R = I->reg;

    ao_time_t T = I->timeout;


    // Ready.

    r = true;

    r = r && ao_i2c_start_from(R, T, B);

    r = r && ao_i2c_send_from(R, AO_MIKROE_1877_I2C_ADDR_SEND, T, B);

    r = r && ao_i2c_send_from(R, 0x01, T, B);

    r = r && ao_i2c_send_from(R, 0x00, T, B);

    r = r && ao_i2c_restart_from(R, T, B);

    r = r && ao_i2c_send_from(R, AO_MIKROE_1877_I2C_ADDR_RECV, T, B);

    n = 29;

    do
    {
        r = r && ao_i2c_recv_from(R, d + 29 - n, T, B);

        r = r && ao_i2c_ack_from(R, T, B);

        n--;
    }
    while (r && n);

    r = r && ao_i2c_recv_from(R, d + 29, T, B);

    r = r && ao_i2c_nack_from(R, T, B);

    r = r && ao_i2c_stop_from(R, T, B);

    ao_assert(d[ 0] == 0x1E);

    ao_assert(d[ 1] == 0x00);

    ao_assert(d[ 2] == 0x00);

    ao_assert(d[ 3] == 0x01);

    ao_assert(d[ 4] == 0x8D);

    ao_assert(d[ 5] == 0x0C);

    ao_assert(d[ 6] == 0x02);

    ao_assert(d[ 7] == 0x00);

    ao_assert(d[ 8] == 0x03);

    ao_assert(d[ 9] == 0x00);

    ao_assert(d[10] == 0x0D);

    ao_assert(d[11] == 0x00);

    ao_assert(d[12] == 0x00);

    ao_assert(d[13] == 0x00);

    ao_assert(d[14] == 0x00);

    ao_assert(d[15] == 0x00);

    ao_assert(d[16] == 0x05);

    ao_assert(d[17] == 0x00);

    ao_assert(d[18] == 0x06);

    ao_assert(d[19] == 0x00);

    ao_assert(d[20] == 0xD8);

    ao_assert(d[21] == 0x04);

    ao_assert(d[22] == 0x01);

    ao_assert(d[23] == 0x0F);

    ao_assert(d[24] == 0x50);

    ao_assert(d[25] == 0x71);

    ao_assert(d[26] == 0x00);

    ao_assert(d[27] == 0x00);

    ao_assert(d[28] == 0x00);

    ao_assert(d[29] == 0x00);

    ao_mikroe_1877_i2c_delay(I);

    return r;
}

// ----------------------------------------------------------------------------

bool ao_mikroe_1877_i2c_power_on(ao_mikroe_1877_i2c_t * I)
{
    // Variables.

    ao_time_t B = ao_now();

    bool r;

    ao_i2c_reg_t * R = I->reg;

    ao_time_t T = I->timeout;


    // Ready.

    r = true;

    r = r && ao_i2c_start_from(R, T, B);

    r = r && ao_i2c_send_from(R, AO_MIKROE_1877_I2C_ADDR_SEND, T, B);

    r = r && ao_i2c_send_from(R, 0x05, T, B);   // Command register LO.

    r = r && ao_i2c_send_from(R, 0x00, T, B);   // Command register HI.

    r = r && ao_i2c_send_from(R, 0x00, T, B);   // Command data     LO: ON.

    r = r && ao_i2c_send_from(R, 0x08, T, B);   // Command data     HI: SET POWER.

    r = r && ao_i2c_stop_from(R, T, B);

    ao_mikroe_1877_i2c_delay(I);

    return r;
}

bool ao_mikroe_1877_i2c_power_sleep(ao_mikroe_1877_i2c_t * I)
{
    // Variables.

    ao_time_t B = ao_now();

    bool r;

    ao_i2c_reg_t * R = I->reg;

    ao_time_t T = I->timeout;


    // Ready.

    r = true;

    r = r && ao_i2c_start_from(R, T, B);

    r = r && ao_i2c_send_from(R, AO_MIKROE_1877_I2C_ADDR_SEND, T, B);

    r = r && ao_i2c_send_from(R, 0x05, T, B);   // Command register LO.

    r = r && ao_i2c_send_from(R, 0x00, T, B);   // Command register HI.

    r = r && ao_i2c_send_from(R, 0x01, T, B);   // Command data     LO: SLEEP.

    r = r && ao_i2c_send_from(R, 0x08, T, B);   // Command data     HI: SET POWER.

    r = r && ao_i2c_stop_from(R, T, B);

    ao_mikroe_1877_i2c_delay(I);

    return r;
}

// ----------------------------------------------------------------------------

bool ao_mikroe_1877_i2c_recv(ao_mikroe_1877_i2c_t * I)
{
    // Notes.

    // This function simply reads all the bytes that are to be read.


    // Variables.

    ao_time_t B = ao_now();

    uint8_t d0;

    uint8_t d1;

    uint32_t n0;

    uint32_t n1;

    bool r;

    ao_i2c_reg_t * R = I->reg;

    ao_time_t T = I->timeout;


    // Ready.

    r = true;

    r = r && ao_i2c_start_from(R, T, B);

    r = r && ao_i2c_send_from(R, AO_MIKROE_1877_I2C_ADDR_RECV, T, B);

    r = r && ao_i2c_recv_from(R, &d0, T, B);

    r = r && ao_i2c_ack_from(R, T, B);

    r = r && ao_i2c_recv_from(R, &d1, T, B);

    n0 = (uint32_t) d0;

    n1 = (uint32_t) d1 << 8;

    n1 = n1 | n0;

    if (n1 > 2)
    {
        n1 = n1 - 2;

        do
        {
            r = r && ao_i2c_ack_from(R, T, B);

            r = r && ao_i2c_recv_from(R, &d0, T, B);

            n1--;
        }
        while (r && n1);
    }

    r = r && ao_i2c_nack_from(R, T, B);

    r = r && ao_i2c_stop_from(R, T, B);

    ao_mikroe_1877_i2c_delay(I);

    return r;
}

// ----------------------------------------------------------------------------

bool ao_mikroe_1877_i2c_reset(ao_mikroe_1877_i2c_t * I)
{
    // Variables.

    ao_time_t B = ao_now();

    bool r;

    ao_i2c_reg_t * R = I->reg;

    ao_time_t T = I->timeout;


    // Ready.

    r = true;

    r = r && ao_i2c_start_from(R, T, B);

    r = r && ao_i2c_send_from(R, AO_MIKROE_1877_I2C_ADDR_SEND, T, B);

    r = r && ao_i2c_send_from(R, 0x05, T, B);   // Command register LO.

    r = r && ao_i2c_send_from(R, 0x00, T, B);   // Command register HI.

    r = r && ao_i2c_send_from(R, 0x00, T, B);   // Command data     LO.

    r = r && ao_i2c_send_from(R, 0x01, T, B);   // Command data     HI: RESET.

    r = r && ao_i2c_stop_from(R, T, B);

    ao_mikroe_1877_i2c_delay(I);

    return r;
}

// ----------------------------------------------------------------------------

bool ao_mikroe_1877_i2c_zero(ao_mikroe_1877_i2c_t * I)
{
    // Notes.

    // This function reads two zero bytes.


    // Variables.

    ao_time_t B = ao_now();

    uint8_t d[2];

    bool r1;

    bool r2;

    ao_i2c_reg_t * R = I->reg;

    ao_time_t T = I->timeout;


    // Ready.

    r2 = true;

    r1 = true;

    r1 = r1 && ao_i2c_start_from(R, T, B);

    r1 = r1 && ao_i2c_send_from(R, AO_MIKROE_1877_I2C_ADDR_RECV, T, B);

    r1 = r1 && ao_i2c_recv_from(R, d + 0, T, B);

    if (d[0] == 0)
    {
        r1 = r1 && ao_i2c_ack_from(R, T, B);

        r1 = r1 && ao_i2c_recv_from(R, d + 1, T, B);

        if (d[1] == 0) { }

        else
        {
            r2 = false;
        }
    }

    else
    {
        r2 = false;
    }

    r1 = r1 && ao_i2c_nack_from(R, T, B);

    r1 = r1 && ao_i2c_stop_from(R, T, B);

    ao_mikroe_1877_i2c_delay(I);

    return r1 && r2;
}

// ----------------------------------------------------------------------------

void ao_mikroe_1877_info_print(uint8_t * x, ao_mikroe_1877_info_t * I)
{
    // Variables.

    uint8_t b0;

    uint8_t b1;

    ao_float_t f;

    int16_t i;

    ao_mikroe_1877_sensor_t S = I->sensor;

    uint8_t s = (uint8_t) S;

    uint16_t u;


    // Ready.

    x[0] = 32;

    x[1] = 0;

    x[2] = s;

    x[3] = (uint8_t) I->connection;

    x[4] = (uint8_t) I->reporting;

    x[5] = (uint8_t) I->power;

    x[6] = (uint8_t) I->state;


    f = (ao_float_t) I->interval;

    f = ao_milliseconds_from_time(f);

    u = (uint16_t) f;

    b0 = (uint8_t) ((u >> 0) & 0xFF);

    b1 = (uint8_t) ((u >> 8) & 0xFF);

    x[7] = b0;

    x[8] = b1;


    f = I->accuracy;

    f = ao_mikroe_1877_encode(S, f);

    u = (uint16_t) f;

    b0 = (uint8_t) ((u >> 0) & 0xFF);

    b1 = (uint8_t) ((u >> 8) & 0xFF);

    x[9] = b0;

    x[10] = b1;


    f = I->resolution;

    f = ao_mikroe_1877_encode(S, f);

    u = (uint16_t) f;

    b0 = (uint8_t) ((u >> 0) & 0xFF);

    b1 = (uint8_t) ((u >> 8) & 0xFF);

    x[11] = b0;

    x[12] = b1;


    f = I->change_sensitivity;

    f = ao_mikroe_1877_encode(S, f);

    u = (uint16_t) f;

    b0 = (uint8_t) ((u >> 0) & 0xFF);

    b1 = (uint8_t) ((u >> 8) & 0xFF);

    x[13] = b0;

    x[14] = b1;


    f = I->max;

    f = ao_mikroe_1877_encode(S, f);

    i = (int16_t) f;

    u = *((uint16_t *) &i);

    b0 = (uint8_t) ((u >> 0) & 0xFF);

    b1 = (uint8_t) ((u >> 8) & 0xFF);

    x[15] = b0;

    x[16] = b1;


    f = I->min;

    f = ao_mikroe_1877_encode(S, f);

    i = (int16_t) f;

    u = *((uint16_t *) &i);

    b0 = (uint8_t) ((u >> 0) & 0xFF);

    b1 = (uint8_t) ((u >> 8) & 0xFF);

    x[17] = b0;

    x[18] = b1;


    f = (ao_float_t) I->interval_min;

    f = ao_milliseconds_from_time(f);

    u = (uint16_t) f;

    b0 = (uint8_t) ((u >> 0) & 0xFF);

    b1 = (uint8_t) ((u >> 8) & 0xFF);

    x[19] = b0;

    x[20] = b1;


    x[21] = 'M';

    x[22] = 0;

    x[23] = 'C';

    x[24] = 0;

    x[25] = 'H';

    x[26] = 0;

    x[27] = 'P';

    x[28] = 0;

    x[29] = 's';

    x[30] = 0;

    x[31] = 'f';

    x[32] = 0;
}

void ao_mikroe_1877_info_scan(uint8_t * x, ao_mikroe_1877_info_t * I)
{
    // Variables.

    ao_float_t f;

    int16_t i;

    ao_mikroe_1877_sensor_t S = (ao_mikroe_1877_sensor_t) x[2];

    uint16_t u0;

    uint16_t u1;


    // Ready.

    I->connection = (ao_mikroe_1877_connection_t) x[3];

    I->reporting = (ao_mikroe_1877_reporting_t) x[4];

    I->power = (ao_mikroe_1877_power_t) x[5];

    I->state = (ao_mikroe_1877_state_t) x[6];


    u0 = (uint16_t) x[7];

    u1 = (uint16_t) x[8];

    u1 = (u1 << 8) | u0;

    f = (ao_float_t) u1;

    f = ao_milliseconds(f);

    I->interval = (ao_time_t) f;


    u0 = (uint16_t) x[9];

    u1 = (uint16_t) x[10];

    u1 = (u1 << 8) | u0;

    f = (ao_float_t) u1;

    I->accuracy = ao_mikroe_1877_decode(S, f);


    u0 = (uint16_t) x[11];

    u1 = (uint16_t) x[12];

    u1 = (u1 << 8) | u0;

    f = (ao_float_t) u1;

    I->resolution = ao_mikroe_1877_decode(S, f);


    u0 = (uint16_t) x[13];

    u1 = (uint16_t) x[14];

    u1 = (u1 << 8) | u0;

    f = (ao_float_t) u1;

    I->change_sensitivity = ao_mikroe_1877_decode(S, f);


    u0 = (uint16_t) x[15];

    u1 = (uint16_t) x[16];

    u1 = (u1 << 8) | u0;

    i = *((int16_t *) &u1);

    f = (ao_float_t) i;

    I->max = ao_mikroe_1877_decode(S, f);


    u0 = (uint16_t) x[17];

    u1 = (uint16_t) x[18];

    u1 = (u1 << 8) | u0;

    i = *((int16_t *) &u1);

    f = (ao_float_t) i;

    I->min = ao_mikroe_1877_decode(S, f);


    u0 = (uint16_t) x[19];

    u1 = (uint16_t) x[20];

    u1 = (u1 << 8) | u0;

    f = (ao_float_t) u1;

    f = ao_milliseconds(f);

    I->interval_min = (ao_time_t) f;


    // DS00001888.

    // 3.2.1. Feature Report.

    // The sensor description should be "MCHPSF".

    // However, this is not the case.

    // ao_assert(x[21] == 'M');

    // ao_assert(x[22] == 0);

    // ao_assert(x[23] == 'C');

    // ao_assert(x[24] == 0);

    // ao_assert(x[25] == 'H');

    // ao_assert(x[26] == 0);

    // ao_assert(x[27] == 'P');

    // ao_assert(x[28] == 0);

    // ao_assert(x[29] == 's');

    // ao_assert(x[30] == 0);

    // ao_assert(x[31] == 'f');

    // ao_assert(x[32] == 0);
}

// ----------------------------------------------------------------------------

void ao_mikroe_1877_mod_int(ao_mikroe_1877_mod_t * M)
{
    if (M)
    {
        ao_cond_set(&M->cond);
    }

    else
    {
        ao_assert(false);
    }
}

// ----------------------------------------------------------------------------

void ao_mikroe_1877_mod_job(ao_mikroe_1877_mod_t * M, ao_mikroe_1877_job_t * J)
{
    // Variables.

    ao_spush_obj_t P;


    // Ready.

    ao_clear(&P, ao_spush_obj_t);

    P.ptr = J;

    P.stream = &M->stream;

    ao_spush_obj_override(&P);
}

// ----------------------------------------------------------------------------

void ao_mikroe_1877_mod_run_init(ao_mikroe_1877_mod_t * M)
{
    switch (M->state)
    {
        case AO_MIKROE_1877_MOD_STATE_INIT1:    ao_mikroe_1877_mod_run_init1(M);    break;

        case AO_MIKROE_1877_MOD_STATE_INIT2:    ao_mikroe_1877_mod_run_init2(M);    break;

        case AO_MIKROE_1877_MOD_STATE_INIT3:    ao_mikroe_1877_mod_run_init3(M);    break;

        case AO_MIKROE_1877_MOD_STATE_INIT4:    ao_mikroe_1877_mod_run_init4(M);    break;

        case AO_MIKROE_1877_MOD_STATE_INIT5:    ao_mikroe_1877_mod_run_init5(M);    break;

        case AO_MIKROE_1877_MOD_STATE_INIT6:    ao_mikroe_1877_mod_run_init6(M);    break;

        case AO_MIKROE_1877_MOD_STATE_INIT7:    ao_mikroe_1877_mod_run_init7(M);    break;

        case AO_MIKROE_1877_MOD_STATE_INIT8:    ao_mikroe_1877_mod_run_init8(M);    break;

        case AO_MIKROE_1877_MOD_STATE_INIT9:    ao_mikroe_1877_mod_run_init9(M);    break;

        case AO_MIKROE_1877_MOD_STATE_INIT10:   ao_mikroe_1877_mod_run_init10(M);   break;

        default:                                ao_assert(false);                   break;
    }
}

// ----------------------------------------------------------------------------

void ao_mikroe_1877_mod_run_init1(ao_mikroe_1877_mod_t * M)
{
    if (M->sleep.result)
    {
        ao_mikroe_1877_mod_set_init2(M);
    }
}

void ao_mikroe_1877_mod_run_init2(ao_mikroe_1877_mod_t * M)
{
    (void) M;
}

void ao_mikroe_1877_mod_run_init3(ao_mikroe_1877_mod_t * M)
{
    if (M->sleep.result)
    {
        ao_mikroe_1877_mod_set_init4(M);
    }
}

void ao_mikroe_1877_mod_run_init4(ao_mikroe_1877_mod_t * M)
{
    if (M->sleep.result)
    {
        ao_mikroe_1877_mod_set_init4(M);
    }
}

void ao_mikroe_1877_mod_run_init5(ao_mikroe_1877_mod_t * M)
{
    if (M->sleep.result)
    {
        ao_mikroe_1877_mod_set_init5(M);
    }
}

void ao_mikroe_1877_mod_run_init6(ao_mikroe_1877_mod_t * M)
{
    if (M->sleep.result)
    {
        ao_mikroe_1877_mod_set_init6(M);
    }
}

void ao_mikroe_1877_mod_run_init7(ao_mikroe_1877_mod_t * M)
{
    if (M->i2c_result)
    {
        if (M->cond_wait.result)
        {
            ao_mikroe_1877_mod_set_init8(M);
        }
    }

    else
    {
        if (M->sleep.result)
        {
            ao_mikroe_1877_mod_set_init7(M);
        }
    }
}

void ao_mikroe_1877_mod_run_init8(ao_mikroe_1877_mod_t * M)
{
    if (M->sleep.result)
    {
        ao_mikroe_1877_mod_set_init8(M);
    }
}

void ao_mikroe_1877_mod_run_init9(ao_mikroe_1877_mod_t * M)
{
    if (M->sleep.result)
    {
        ao_mikroe_1877_mod_set_init9(M);
    }
}

void ao_mikroe_1877_mod_run_init10(ao_mikroe_1877_mod_t * M)
{
    if (M->sleep.result)
    {
        ao_mikroe_1877_mod_set_init10(M);
    }
}

// ----------------------------------------------------------------------------

void ao_mikroe_1877_mod_run_off(ao_mikroe_1877_mod_t * M)
{
    switch (M->state)
    {
        case AO_MIKROE_1877_MOD_STATE_OFF1: ao_mikroe_1877_mod_run_off1(M); break;

        case AO_MIKROE_1877_MOD_STATE_OFF2: ao_mikroe_1877_mod_run_off2(M); break;

        case AO_MIKROE_1877_MOD_STATE_OFF3: ao_mikroe_1877_mod_run_off3(M); break;

        case AO_MIKROE_1877_MOD_STATE_OFF4: ao_mikroe_1877_mod_run_off4(M); break;

        case AO_MIKROE_1877_MOD_STATE_OFF5: ao_mikroe_1877_mod_run_off5(M); break;

        case AO_MIKROE_1877_MOD_STATE_OFF6: ao_mikroe_1877_mod_run_off6(M); break;

        case AO_MIKROE_1877_MOD_STATE_OFF7: ao_mikroe_1877_mod_run_off7(M); break;

        default:                            ao_assert(false);               break;
    }
}

// ----------------------------------------------------------------------------

void ao_mikroe_1877_mod_run_off1(ao_mikroe_1877_mod_t * M)
{
    if (M->sleep.result)
    {
        ao_mikroe_1877_mod_set_off1(M);
    }
}

void ao_mikroe_1877_mod_run_off2(ao_mikroe_1877_mod_t * M)
{
    if (M->sleep.result)
    {
        ao_mikroe_1877_mod_set_off3(M);
    }
}

void ao_mikroe_1877_mod_run_off3(ao_mikroe_1877_mod_t * M)
{
    (void) M;
}

void ao_mikroe_1877_mod_run_off4(ao_mikroe_1877_mod_t * M)
{
    if (M->sleep.result)
    {
        ao_mikroe_1877_mod_set_off5(M);
    }
}

void ao_mikroe_1877_mod_run_off5(ao_mikroe_1877_mod_t * M)
{
    if (M->sleep.result)
    {
        ao_mikroe_1877_mod_set_off6(M);
    }
}

void ao_mikroe_1877_mod_run_off6(ao_mikroe_1877_mod_t * M)
{
    if (M->sleep.result)
    {
        ao_mikroe_1877_mod_set_off6(M);
    }
}

void ao_mikroe_1877_mod_run_off7(ao_mikroe_1877_mod_t * M)
{
    if (M->sleep.result)
    {
        ao_mikroe_1877_mod_set_reset(M);
    }
}

// ----------------------------------------------------------------------------

void ao_mikroe_1877_mod_run_on(ao_mikroe_1877_mod_t * M)
{
    // Variables.

    ao_mikroe_1877_job_t J;


    // Ready.

    if (M->i2c_result)
    {
        if (M->cond_wait.result)
        {
            J.type = AO_MIKROE_1877_JOB_TYPE_INT;

            ao_mikroe_1877_mod_job(M, &J);

            M->int_disable();

            ao_cond_clear(&M->cond);

            M->int_enable();
        }

        if (M->spop.result)
        {
            ao_mikroe_1877_mod_run_on_job(M);
        }
    }

    else
    {
        if (M->sleep.result)
        {
            M->i2c_attempt++;

            if (M->i2c_attempt == AO_MIKROE_1877_I2C_ATTEMPTS_MAX)
            {
                ao_mikroe_1877_mod_set_init(M);
            }

            else
            {
                ao_mikroe_1877_mod_run_on_job(M);
            }
        }
    }
}

// ----------------------------------------------------------------------------

void ao_mikroe_1877_mod_run_on_job(ao_mikroe_1877_mod_t * M)
{
    switch (M->job.type)
    {
        case AO_MIKROE_1877_JOB_TYPE_CONFIG:    ao_mikroe_1877_mod_run_on_job_config(M);    break;

        case AO_MIKROE_1877_JOB_TYPE_GET_DATA:  ao_mikroe_1877_mod_run_on_job_get_data(M);  break;

        case AO_MIKROE_1877_JOB_TYPE_GET_INFO:  ao_mikroe_1877_mod_run_on_job_get_info(M);  break;

        case AO_MIKROE_1877_JOB_TYPE_INT:       ao_mikroe_1877_mod_run_on_job_int(M);       break;

        case AO_MIKROE_1877_JOB_TYPE_RESET:     ao_mikroe_1877_mod_run_on_job_reset(M);     break;

        case AO_MIKROE_1877_JOB_TYPE_SLEEP:     ao_mikroe_1877_mod_run_on_job_sleep(M);     break;

        case AO_MIKROE_1877_JOB_TYPE_STOP:      ao_mikroe_1877_mod_run_on_job_stop(M);      break;

        default:                                                                            break;
    }
}

// ----------------------------------------------------------------------------

void ao_mikroe_1877_mod_run_on_job_config(ao_mikroe_1877_mod_t * M)
{
    // Variables.

    size_t i;

    ao_mikroe_1877_i2c_t * I = M->i2c;

    bool r;

    ao_mikroe_1877_info_t X =
    {
        .sensor = M->job.sensor
    };


    // Ready.

    r = true;

    r = r && ao_mikroe_1877_i2c_get_info(I, &X);

    i = 3;

    do
    {
        X.change_sensitivity = M->job.change_sensitivity;

        X.interval = M->job.interval;

        X.power = M->job.power;

        X.reporting = M->job.reporting;

        r = r && ao_mikroe_1877_i2c_config(I, &X);

        r = r && ao_mikroe_1877_i2c_get_info(I, &X);

        i--;
    }
    while (r && i);

    if (r)
    {
        M->i2c_result = true;

        M->i2c_attempt = 0;

        M->sleep.timeout = AO_INFINITY;
    }

    else
    {
        M->i2c_result = false;

        M->i2c_attempt++;

        if (M->i2c_attempt == AO_MIKROE_1877_I2C_ATTEMPTS_MAX)
        {
            ao_mikroe_1877_mod_set_init(M);
        }

        else
        {
            M->sleep.beginning = ao_now();

            M->sleep.timeout = AO_MIKROE_1877_I2C_ATTEMPTS_DELAY;
        }
    }
}

void ao_mikroe_1877_mod_run_on_job_get_data(ao_mikroe_1877_mod_t * M)
{
    // Variables.

    ao_mikroe_1877_data_t D =
    {
        .sensor = M->job.sensor
    };


    // Ready.

    M->i2c_result = ao_mikroe_1877_i2c_get_data(M->i2c, &D);

    if (M->i2c_result)
    {
        M->i2c_attempt = 0;

        M->sleep.timeout = AO_INFINITY;

        ao_mikroe_1877_data(M->i, &D);
    }

    else
    {
        M->i2c_attempt++;

        if (M->i2c_attempt == AO_MIKROE_1877_I2C_ATTEMPTS_MAX)
        {
            ao_mikroe_1877_mod_set_init(M);
        }

        else
        {
            M->sleep.beginning = ao_now();

            M->sleep.timeout = AO_MIKROE_1877_I2C_ATTEMPTS_DELAY;
        }
    }
}

void ao_mikroe_1877_mod_run_on_job_get_info(ao_mikroe_1877_mod_t * M)
{
    // Variables.

    ao_mikroe_1877_info_t X =
    {
        .sensor = M->job.sensor
    };


    // Ready.

    M->i2c_result = ao_mikroe_1877_i2c_get_info(M->i2c, &X);

    if (M->i2c_result)
    {
        M->i2c_attempt = 0;

        M->sleep.timeout = AO_INFINITY;

        ao_mikroe_1877_info(M->i, &X);
    }

    else
    {
        M->i2c_attempt++;

        if (M->i2c_attempt == AO_MIKROE_1877_I2C_ATTEMPTS_MAX)
        {
            ao_mikroe_1877_mod_set_init(M);
        }

        else
        {
            M->sleep.beginning = ao_now();

            M->sleep.timeout = AO_MIKROE_1877_I2C_ATTEMPTS_DELAY;
        }
    }
}

void ao_mikroe_1877_mod_run_on_job_int(ao_mikroe_1877_mod_t * M)
{
    // Variables.

    ao_mikroe_1877_data_t D;

    bool r;


    // Ready.

    r = true;

    do
    {
        r = r && ao_mikroe_1877_i2c_get_data_next(M->i2c, &D);

        if (r)
        {
            ao_mikroe_1877_data(M->i, &D);
        }
    }
    while (r && M->int_asserted());

    if (r)
    {
        M->i2c_result = true;

        M->i2c_attempt = 0;

        M->sleep.timeout = AO_INFINITY;
    }

    else
    {
        M->i2c_result = false;

        M->i2c_attempt++;

        if (M->i2c_attempt == AO_MIKROE_1877_I2C_ATTEMPTS_MAX)
        {
            ao_mikroe_1877_mod_set_init(M);
        }

        else
        {
            M->sleep.beginning = ao_now();

            M->sleep.timeout = AO_MIKROE_1877_I2C_ATTEMPTS_DELAY;
        }
    }
}

void ao_mikroe_1877_mod_run_on_job_reset(ao_mikroe_1877_mod_t * M)
{
    ao_mikroe_1877_mod_set_reset(M);
}

void ao_mikroe_1877_mod_run_on_job_sleep(ao_mikroe_1877_mod_t * M)
{
    ao_mikroe_1877_mod_set_sleep(M);
}

void ao_mikroe_1877_mod_run_on_job_stop(ao_mikroe_1877_mod_t * M)
{
    ao_mikroe_1877_mod_set_off(M);
}

// ----------------------------------------------------------------------------

void ao_mikroe_1877_mod_run_reset(ao_mikroe_1877_mod_t * M)
{
    (void) M;
}

// ----------------------------------------------------------------------------

void ao_mikroe_1877_mod_run_sleep(ao_mikroe_1877_mod_t * M)
{
    switch (M->state)
    {
        case AO_MIKROE_1877_MOD_STATE_SLEEP1:   ao_mikroe_1877_mod_run_sleep1(M);   break;

        case AO_MIKROE_1877_MOD_STATE_SLEEP2:   ao_mikroe_1877_mod_run_sleep2(M);   break;

        case AO_MIKROE_1877_MOD_STATE_SLEEP3:   ao_mikroe_1877_mod_run_sleep3(M);   break;

        case AO_MIKROE_1877_MOD_STATE_SLEEP4:   ao_mikroe_1877_mod_run_sleep4(M);   break;

        case AO_MIKROE_1877_MOD_STATE_SLEEP5:   ao_mikroe_1877_mod_run_sleep5(M);   break;

        case AO_MIKROE_1877_MOD_STATE_SLEEP6:   ao_mikroe_1877_mod_run_sleep6(M);   break;

        case AO_MIKROE_1877_MOD_STATE_SLEEP7:   ao_mikroe_1877_mod_run_sleep7(M);   break;

        default:                                ao_assert(false);                   break;
    }
}

// ----------------------------------------------------------------------------

void ao_mikroe_1877_mod_run_sleep1(ao_mikroe_1877_mod_t * M)
{
    if (M->sleep.result)
    {
        ao_mikroe_1877_mod_set_sleep1(M);
    }
}

void ao_mikroe_1877_mod_run_sleep2(ao_mikroe_1877_mod_t * M)
{
    if (M->sleep.result)
    {
        ao_mikroe_1877_mod_set_sleep3(M);
    }
}

void ao_mikroe_1877_mod_run_sleep3(ao_mikroe_1877_mod_t * M)
{
    // Variables.

    bool r;


    // Ready.

    if (M->i2c_result)
    {
        if (M->spop.result)
        {
            r = true;
        }

        else
        {
            r = false;
        }
    }

    else
    {
        if (M->sleep.result)
        {
            M->i2c_attempt++;

            if (M->i2c_attempt == AO_MIKROE_1877_I2C_ATTEMPTS_MAX)
            {
                ao_mikroe_1877_mod_set_init(M);

                r = false;
            }

            else
            {
                r = true;
            }
        }

        else
        {
            r = false;
        }
    }

    if (r)
    {
        switch (M->job.type)
        {
            case AO_MIKROE_1877_JOB_TYPE_RESET: ao_mikroe_1877_mod_set_off4(M);     break;

            case AO_MIKROE_1877_JOB_TYPE_STOP:  ao_mikroe_1877_mod_set_off3(M);     break;

            case AO_MIKROE_1877_JOB_TYPE_WAKE:  ao_mikroe_1877_mod_set_sleep4(M);   break;

            default:                                                                break;
        }
    }
}

void ao_mikroe_1877_mod_run_sleep4(ao_mikroe_1877_mod_t * M)
{
    if (M->sleep.result)
    {
        ao_mikroe_1877_mod_set_sleep5(M);
    }
}

void ao_mikroe_1877_mod_run_sleep5(ao_mikroe_1877_mod_t * M)
{
    if (M->sleep.result)
    {
        ao_mikroe_1877_mod_set_sleep6(M);
    }
}

void ao_mikroe_1877_mod_run_sleep6(ao_mikroe_1877_mod_t * M)
{
    if (M->sleep.result)
    {
        ao_mikroe_1877_mod_set_sleep6(M);
    }
}

void ao_mikroe_1877_mod_run_sleep7(ao_mikroe_1877_mod_t * M)
{
    if (M->sleep.result)
    {
        ao_mikroe_1877_mod_set_on(M);
    }
}

// ----------------------------------------------------------------------------

void ao_mikroe_1877_mod_set_init(ao_mikroe_1877_mod_t * M)
{
    ao_mikroe_1877_mod_set_init1(M);
}

// ----------------------------------------------------------------------------

void ao_mikroe_1877_mod_set_init1(ao_mikroe_1877_mod_t * M)
{
    M->int_disable();

    M->reset_enable();


    M->i2c_attempt = 0;

    M->i2c_result = true;

    M->sleep.beginning = ao_now();

    M->sleep.timeout = ao_milliseconds(2);

    M->state = AO_MIKROE_1877_MOD_STATE_INIT1;
}

void ao_mikroe_1877_mod_set_init2(ao_mikroe_1877_mod_t * M)
{
    M->reset_disable();

    M->sleep.timeout = AO_INFINITY;

    M->state = AO_MIKROE_1877_MOD_STATE_INIT2;

    ao_mikroe_1877_mod_set_init3(M);
}

void ao_mikroe_1877_mod_set_init3(ao_mikroe_1877_mod_t * M)
{
    M->state = AO_MIKROE_1877_MOD_STATE_INIT3;

    M->sleep.beginning = ao_now();

    M->sleep.timeout = ao_seconds(2);
}

void ao_mikroe_1877_mod_set_init4(ao_mikroe_1877_mod_t * M)
{
    M->state = AO_MIKROE_1877_MOD_STATE_INIT4;

    M->i2c_result = ao_mikroe_1877_i2c_recv(M->i2c);

    if (M->i2c_result)
    {
        M->i2c_attempt = 0;

        M->sleep.timeout = AO_INFINITY;

        ao_mikroe_1877_mod_set_init5(M);
    }

    else
    {
        M->i2c_attempt++;

        if (M->i2c_attempt == AO_MIKROE_1877_I2C_ATTEMPTS_MAX)
        {
            ao_mikroe_1877_mod_set_init(M);
        }

        else
        {
            M->sleep.beginning = ao_now();

            M->sleep.timeout = AO_MIKROE_1877_I2C_ATTEMPTS_DELAY;
        }
    }
}

void ao_mikroe_1877_mod_set_init5(ao_mikroe_1877_mod_t * M)
{
    M->state = AO_MIKROE_1877_MOD_STATE_INIT5;

    M->i2c_result = ao_mikroe_1877_i2c_hid(M->i2c);

    if (M->i2c_result)
    {
        M->i2c_attempt = 0;

        M->sleep.timeout = AO_INFINITY;

        ao_mikroe_1877_mod_set_init6(M);
    }

    else
    {
        M->i2c_attempt++;

        if (M->i2c_attempt == AO_MIKROE_1877_I2C_ATTEMPTS_MAX)
        {
            ao_mikroe_1877_mod_set_init(M);
        }

        else
        {
            M->sleep.beginning = ao_now();

            M->sleep.timeout = AO_MIKROE_1877_I2C_ATTEMPTS_DELAY;
        }
    }
}

void ao_mikroe_1877_mod_set_init6(ao_mikroe_1877_mod_t * M)
{
    M->state = AO_MIKROE_1877_MOD_STATE_INIT6;

    M->i2c_result = ao_mikroe_1877_i2c_power_on(M->i2c);

    if (M->i2c_result)
    {
        M->i2c_attempt = 0;

        M->sleep.timeout = AO_INFINITY;

        ao_mikroe_1877_mod_set_init7(M);
    }

    else
    {
        M->i2c_attempt++;

        if (M->i2c_attempt == AO_MIKROE_1877_I2C_ATTEMPTS_MAX)
        {
            ao_mikroe_1877_mod_set_init(M);
        }

        else
        {
            M->sleep.beginning = ao_now();

            M->sleep.timeout = AO_MIKROE_1877_I2C_ATTEMPTS_DELAY;
        }
    }
}

void ao_mikroe_1877_mod_set_init7(ao_mikroe_1877_mod_t * M)
{
    M->state = AO_MIKROE_1877_MOD_STATE_INIT7;

    ao_cond_clear(&M->cond);

    M->int_enable();

    M->i2c_result = ao_mikroe_1877_i2c_reset(M->i2c);

    if (M->i2c_result)
    {
        M->i2c_attempt = 0;

        M->sleep.timeout = AO_INFINITY;
    }

    else
    {
        M->i2c_attempt++;

        if (M->i2c_attempt == AO_MIKROE_1877_I2C_ATTEMPTS_MAX)
        {
            ao_mikroe_1877_mod_set_init(M);
        }

        else
        {
            M->sleep.beginning = ao_now();

            M->sleep.timeout = AO_MIKROE_1877_I2C_ATTEMPTS_DELAY;
        }
    }
}

void ao_mikroe_1877_mod_set_init8(ao_mikroe_1877_mod_t * M)
{
    M->state = AO_MIKROE_1877_MOD_STATE_INIT8;

    M->int_disable();

    M->i2c_result = ao_mikroe_1877_i2c_zero(M->i2c);

    if (M->i2c_result)
    {
        M->i2c_attempt = 0;

        M->sleep.timeout = AO_INFINITY;

        ao_mikroe_1877_mod_set_init9(M);
    }

    else
    {
        M->i2c_attempt++;

        if (M->i2c_attempt == AO_MIKROE_1877_I2C_ATTEMPTS_MAX)
        {
            ao_mikroe_1877_mod_set_init(M);
        }

        else
        {
            M->sleep.beginning = ao_now();

            M->sleep.timeout = AO_MIKROE_1877_I2C_ATTEMPTS_DELAY;
        }
    }
}

void ao_mikroe_1877_mod_set_init9(ao_mikroe_1877_mod_t * M)
{
    M->state = AO_MIKROE_1877_MOD_STATE_INIT9;

    M->i2c_result = ao_mikroe_1877_i2c_hid(M->i2c);

    if (M->i2c_result)
    {
        M->i2c_attempt = 0;

        M->sleep.timeout = AO_INFINITY;

        ao_mikroe_1877_mod_set_init10(M);
    }

    else
    {
        M->i2c_attempt++;

        if (M->i2c_attempt == AO_MIKROE_1877_I2C_ATTEMPTS_MAX)
        {
            ao_mikroe_1877_mod_set_init(M);
        }

        else
        {
            M->sleep.beginning = ao_now();

            M->sleep.timeout = AO_MIKROE_1877_I2C_ATTEMPTS_DELAY;
        }
    }
}

void ao_mikroe_1877_mod_set_init10(ao_mikroe_1877_mod_t * M)
{
    // Variables.

    size_t i;

    ao_mikroe_1877_i2c_t * I = M->i2c;

    ao_mikroe_1877_info_t X;

    bool r;


    // Ready.

    M->state = AO_MIKROE_1877_MOD_STATE_INIT10;

    i = 1;

    r = true;

    do
    {
        X.sensor = (ao_mikroe_1877_sensor_t) i;

        r = r && ao_mikroe_1877_i2c_get_info(I, &X);

        i++;
    }
    while (r && i <= 8);

    if (r)
    {
        M->i2c_result = true;

        M->i2c_attempt = 0;

        M->sleep.timeout = AO_INFINITY;

        ao_mikroe_1877_mod_set_on(M);
    }

    else
    {
        M->i2c_result = false;

        M->i2c_attempt++;

        if (M->i2c_attempt == AO_MIKROE_1877_I2C_ATTEMPTS_MAX)
        {
            ao_mikroe_1877_mod_set_init(M);
        }

        else
        {
            M->sleep.beginning = ao_now();

            M->sleep.timeout = AO_MIKROE_1877_I2C_ATTEMPTS_DELAY;
        }
    }
}

// ----------------------------------------------------------------------------

void ao_mikroe_1877_mod_set_off(ao_mikroe_1877_mod_t * M)
{
    ao_mikroe_1877_mod_set_off1(M);
}

// ----------------------------------------------------------------------------

void ao_mikroe_1877_mod_set_off1(ao_mikroe_1877_mod_t * M)
{
    M->state = AO_MIKROE_1877_MOD_STATE_OFF1;

    M->int_disable();

    M->i2c_result = ao_mikroe_1877_i2c_power_sleep(M->i2c);

    if (M->i2c_result)
    {
        M->i2c_attempt = 0;

        M->sleep.timeout = AO_INFINITY;

        ao_mikroe_1877_mod_set_off2(M);
    }

    else
    {
        M->i2c_attempt++;

        if (M->i2c_attempt == AO_MIKROE_1877_I2C_ATTEMPTS_MAX)
        {
            ao_mikroe_1877_mod_set_init(M);
        }

        else
        {
            M->sleep.beginning = ao_now();

            M->sleep.timeout = AO_MIKROE_1877_I2C_ATTEMPTS_DELAY;
        }
    }
}

void ao_mikroe_1877_mod_set_off2(ao_mikroe_1877_mod_t * M)
{
    M->state = AO_MIKROE_1877_MOD_STATE_OFF2;

    // DS50002322.

    // Required delay between sending the SLEEP command & toggling WAKE.

    // 70 ms.

    // This is required for the coefficient write in flash during D3 plus other
    // housekeeping activities to go into D3 state.

    M->sleep.beginning = ao_now();

    M->sleep.timeout = ao_milliseconds(71);
}

void ao_mikroe_1877_mod_set_off3(ao_mikroe_1877_mod_t * M)
{
    M->state = AO_MIKROE_1877_MOD_STATE_OFF3;

    M->sleep.timeout = AO_INFINITY;

    ao_mikroe_1877_off(M->i);
}

void ao_mikroe_1877_mod_set_off4(ao_mikroe_1877_mod_t * M)
{
    M->state = AO_MIKROE_1877_MOD_STATE_OFF4;

    M->wake_enable();

    M->sleep.beginning = ao_now();

    M->sleep.timeout = ao_milliseconds(3);
}

void ao_mikroe_1877_mod_set_off5(ao_mikroe_1877_mod_t * M)
{
    M->state = AO_MIKROE_1877_MOD_STATE_OFF5;

    M->wake_disable();

    // DS50002322.

    // Required delay between toggling the wake signal and sending the power
    // ON command.

    // 11 ms.

    // This is required for clock source switching after coming out of D3
    // state.

    M->sleep.beginning = ao_now();

    M->sleep.timeout = ao_milliseconds(12);
}

void ao_mikroe_1877_mod_set_off6(ao_mikroe_1877_mod_t * M)
{
    M->state = AO_MIKROE_1877_MOD_STATE_OFF6;

    M->i2c_result = ao_mikroe_1877_i2c_power_on(M->i2c);

    if (M->i2c_result)
    {
        M->i2c_attempt = 0;

        M->sleep.timeout = AO_INFINITY;

        ao_mikroe_1877_mod_set_off7(M);
    }

    else
    {
        M->i2c_attempt++;

        if (M->i2c_attempt == AO_MIKROE_1877_I2C_ATTEMPTS_MAX)
        {
            ao_mikroe_1877_mod_set_init(M);
        }

        else
        {
            M->sleep.beginning = ao_now();

            M->sleep.timeout = AO_MIKROE_1877_I2C_ATTEMPTS_DELAY;
        }
    }
}

void ao_mikroe_1877_mod_set_off7(ao_mikroe_1877_mod_t * M)
{
    M->state = AO_MIKROE_1877_MOD_STATE_OFF7;

    // DS50002322.

    // Required delay between D3 wake and enumeration sequence start.

    // 30 ms.

    // This is required for sensor initialization after D3 state.

    M->sleep.beginning = ao_now();

    M->sleep.timeout = ao_milliseconds(31);
}

// ----------------------------------------------------------------------------

void ao_mikroe_1877_mod_set_on(ao_mikroe_1877_mod_t * M)
{
    M->state = AO_MIKROE_1877_MOD_STATE_ON;

    ao_cond_clear(&M->cond);

    M->int_enable();

    M->sleep.timeout = AO_INFINITY;

    ao_mikroe_1877_on(M->i);
}

// ----------------------------------------------------------------------------

void ao_mikroe_1877_mod_set_reset(ao_mikroe_1877_mod_t * M)
{
    M->state = AO_MIKROE_1877_MOD_STATE_RESET;

    M->int_disable();

    ao_mikroe_1877_mod_set_init7(M);
}

// ----------------------------------------------------------------------------

void ao_mikroe_1877_mod_set_sleep(ao_mikroe_1877_mod_t * M)
{
    ao_mikroe_1877_mod_set_sleep1(M);
}

// ----------------------------------------------------------------------------

void ao_mikroe_1877_mod_set_sleep1(ao_mikroe_1877_mod_t * M)
{
    M->state = AO_MIKROE_1877_MOD_STATE_SLEEP1;

    M->int_disable();

    M->i2c_result = ao_mikroe_1877_i2c_power_sleep(M->i2c);

    if (M->i2c_result)
    {
        M->i2c_attempt = 0;

        M->sleep.timeout = AO_INFINITY;

        ao_mikroe_1877_mod_set_sleep2(M);
    }

    else
    {
        M->i2c_attempt++;

        if (M->i2c_attempt == AO_MIKROE_1877_I2C_ATTEMPTS_MAX)
        {
            ao_mikroe_1877_mod_set_init(M);
        }

        else
        {
            M->sleep.beginning = ao_now();

            M->sleep.timeout = AO_MIKROE_1877_I2C_ATTEMPTS_DELAY;
        }
    }
}

void ao_mikroe_1877_mod_set_sleep2(ao_mikroe_1877_mod_t * M)
{
    M->state = AO_MIKROE_1877_MOD_STATE_SLEEP2;

    // DS50002322.

    // Required delay between sending the SLEEP command & toggling WAKE.

    // 70 ms.

    // This is required for the coefficient write in flash during D3 plus other
    // housekeeping activities to go into D3 state.

    M->sleep.beginning = ao_now();

    M->sleep.timeout = ao_milliseconds(71);
}

void ao_mikroe_1877_mod_set_sleep3(ao_mikroe_1877_mod_t * M)
{
    M->state = AO_MIKROE_1877_MOD_STATE_SLEEP3;

    M->sleep.timeout = AO_INFINITY;

    ao_mikroe_1877_sleeping(M->i);
}

void ao_mikroe_1877_mod_set_sleep4(ao_mikroe_1877_mod_t * M)
{
    M->state = AO_MIKROE_1877_MOD_STATE_SLEEP4;

    M->wake_enable();

    M->sleep.beginning = ao_now();

    M->sleep.timeout = ao_milliseconds(3);
}

void ao_mikroe_1877_mod_set_sleep5(ao_mikroe_1877_mod_t * M)
{
    M->state = AO_MIKROE_1877_MOD_STATE_SLEEP5;

    M->wake_disable();

    // DS50002322.

    // Required delay between toggling the wake signal and sending the power
    // ON command.

    // 11 ms.

    // This is required for clock source switching after coming out of D3
    // state.

    M->sleep.beginning = ao_now();

    M->sleep.timeout = ao_milliseconds(12);
}

void ao_mikroe_1877_mod_set_sleep6(ao_mikroe_1877_mod_t * M)
{
    M->state = AO_MIKROE_1877_MOD_STATE_SLEEP6;

    M->i2c_result = ao_mikroe_1877_i2c_power_on(M->i2c);

    if (M->i2c_result)
    {
        M->i2c_attempt = 0;

        M->sleep.timeout = AO_INFINITY;

        ao_mikroe_1877_mod_set_sleep7(M);
    }

    else
    {
        M->i2c_attempt++;

        if (M->i2c_attempt == AO_MIKROE_1877_I2C_ATTEMPTS_MAX)
        {
            ao_mikroe_1877_mod_set_init(M);
        }

        else
        {
            M->sleep.beginning = ao_now();

            M->sleep.timeout = AO_MIKROE_1877_I2C_ATTEMPTS_DELAY;
        }
    }
}

void ao_mikroe_1877_mod_set_sleep7(ao_mikroe_1877_mod_t * M)
{
    M->state = AO_MIKROE_1877_MOD_STATE_SLEEP7;

    // DS50002322.

    // Required delay between D3 wake and enumeration sequence start.

    // 30 ms.

    // This is required for sensor initialization after D3 state.

    M->sleep.beginning = ao_now();

    M->sleep.timeout = ao_milliseconds(31);
}

// ----------------------------------------------------------------------------

void ao_mikroe_1877_reset(size_t i)
{
    // Variables.

    ao_mikroe_1877_job_t J;

    ao_mikroe_1877_mod_t * M;


    // Ready.

    M = ao_mikroe_1877_mod(i);

    if (M)
    {
        J.type = AO_MIKROE_1877_JOB_TYPE_RESET;

        ao_mikroe_1877_mod_job(M, &J);
    }

    else
    {
        ao_assert(false);
    }
}

// ----------------------------------------------------------------------------

void ao_mikroe_1877_sleep(size_t i)
{
    // Variables.

    ao_mikroe_1877_job_t J;

    ao_mikroe_1877_mod_t * M;


    // Ready.

    M = ao_mikroe_1877_mod(i);

    if (M)
    {
        J.type = AO_MIKROE_1877_JOB_TYPE_SLEEP;

        ao_mikroe_1877_mod_job(M, &J);
    }

    else
    {
        ao_assert(false);
    }
}

// ----------------------------------------------------------------------------

void ao_mikroe_1877_start(size_t i)
{
    // Variables.

    ao_mikroe_1877_mod_t * M;

    ao_task_t * T;


    // Ready.

    M = ao_mikroe_1877_mod(i);

    if (M)
    {
        T = M->task;

        if (T)
        {
            ao_assert(M->i2c);

            ao_assert(M->int_asserted);

            ao_assert(M->int_disable);

            ao_assert(M->int_enable);

            ao_assert(M->reset_disable);

            ao_assert(M->reset_enable);

            ao_assert(M->wake_disable);

            ao_assert(M->wake_enable);

            ao_task_set_proc(T, ao_mikroe_1877_task_proc, M);

            ao_task_start(T);
        }

        else
        {
            ao_assert(false);
        }
    }

    else
    {
        ao_assert(false);
    }
}

void ao_mikroe_1877_stop(size_t i)
{
    // Variables.

    ao_mikroe_1877_job_t J;

    ao_mikroe_1877_mod_t * M;


    // Ready.

    M = ao_mikroe_1877_mod(i);

    if (M)
    {
        J.type = AO_MIKROE_1877_JOB_TYPE_STOP;

        ao_mikroe_1877_mod_job(M, &J);
    }

    else
    {
        ao_assert(false);
    }
}

// ----------------------------------------------------------------------------

void ao_mikroe_1877_task_proc(void * x)
{
    // Variables.

    ao_mikroe_1877_mod_t *      const   M               =  x;


    // Variables.

    ao_async_any_t *            const   async           = &M->async;

    ao_async_t *                const   async_cond_wait = &M->cond_wait.async;

    ao_async_t *                const   async_sleep     = &M->sleep.async;

    ao_async_t *                const   async_spop      = &M->spop.async;

    ao_async_t **               const   async_store     = &M->async_store[0];

    ao_cond_t *                 const   cond            = &M->cond;

    ao_cond_wait_t *            const   cond_wait       = &M->cond_wait;

    ao_mikroe_1877_job_t *      const   J               = &M->job;

    ao_mikroe_1877_mod_state_t          S;

    ao_sleep_t *                const   sleep           = &M->sleep;

    ao_spop_obj_t *             const   spop            = &M->spop;

    ao_stream4obj_t *           const   stream          = &M->stream;

    ao_mikroe_1877_job_t *      const   stream_store    = &M->stream_store[0];


    // Ready.

    async->store            = async_store;

    cond_wait->cond         = cond;

    spop->ptr               = J;

    spop->stream            = stream;

    stream->buffer.capacity = AO_MIKROE_1877_STREAM_CAPACITY;

    stream->buffer.size     = sizeof(ao_mikroe_1877_job_t);

    stream->buffer.store    = stream_store;


    // Pins.

    M->int_disable();

    M->reset_disable();

    M->wake_disable();


    // FSM.

    ao_mikroe_1877_mod_set_init(M);


    // Loop.

    while (1)
    {
        // Start.

        while (1)
        {
            // State.

            S = M->state;


            // State INIT.

            if (S == AO_MIKROE_1877_MOD_STATE_INIT7)
            {
                async->count = 2;

                async_store[0] = async_cond_wait;

                async_store[1] = async_sleep;


                ao_cond_wait_begin(cond_wait);

                ao_sleep_begin(sleep);

                ao_await_any_forever(async);

                ao_sleep_end(sleep);

                ao_cond_wait_end(cond_wait);


                ao_mikroe_1877_mod_run_init7(M);
            }

            else if (S & AO_MIKROE_1877_MOD_STATE_INIT)
            {
                ao_sleep_begin(sleep);

                ao_await_forever(async_sleep);

                ao_sleep_end(sleep);


                ao_mikroe_1877_mod_run_init(M);
            }


            // State OFF.

            else if (S == AO_MIKROE_1877_MOD_STATE_OFF3)
            {
                break;
            }

            else if (S & AO_MIKROE_1877_MOD_STATE_OFF)
            {
                ao_sleep_begin(sleep);

                ao_await_forever(async_sleep);

                ao_sleep_end(sleep);


                ao_mikroe_1877_mod_run_off(M);
            }


            // State ON.

            else if (S == AO_MIKROE_1877_MOD_STATE_ON)
            {
                if (M->i2c_result)
                {
                    async->count = 2;

                    async_store[0] = async_cond_wait;

                    async_store[1] = async_spop;


                    ao_cond_wait_begin(cond_wait);

                    ao_spop_obj_begin(spop);

                    ao_await_any_forever(async);

                    ao_spop_obj_end(spop);

                    ao_cond_wait_end(cond_wait);
                }

                else
                {
                    ao_sleep_begin(sleep);

                    ao_await_forever(async_sleep);

                    ao_sleep_end(sleep);
                }

                ao_mikroe_1877_mod_run_on(M);
            }


            // State RESET.

            else if (S == AO_MIKROE_1877_MOD_STATE_RESET)
            {
                ao_mikroe_1877_mod_run_reset(M);
            }


            // State SLEEP.

            else if (S == AO_MIKROE_1877_MOD_STATE_SLEEP3)
            {
                if (M->i2c_result)
                {
                    ao_spop_obj_begin(spop);

                    ao_await_forever(async_spop);

                    ao_spop_obj_end(spop);
                }

                else
                {
                    ao_sleep_begin(sleep);

                    ao_await_forever(async_sleep);

                    ao_sleep_end(sleep);
                }

                ao_mikroe_1877_mod_run_sleep3(M);
            }

            else if (S & AO_MIKROE_1877_MOD_STATE_SLEEP)
            {
                ao_sleep_begin(sleep);

                ao_await_forever(async_sleep);

                ao_sleep_end(sleep);


                ao_mikroe_1877_mod_run_sleep(M);
            }


            // State invalid.

            else
            {
                ao_assert(false);
            }
        }


        // Stop.

        ao_stop();


        // FSM.

        ao_mikroe_1877_mod_set_off4(M);
    }
}

// ----------------------------------------------------------------------------

void ao_mikroe_1877_wake(size_t i)
{
    // Variables.

    ao_mikroe_1877_job_t J;

    ao_mikroe_1877_mod_t * M;


    // Ready.

    M = ao_mikroe_1877_mod(i);

    if (M)
    {
        J.type = AO_MIKROE_1877_JOB_TYPE_WAKE;

        ao_mikroe_1877_mod_job(M, &J);
    }

    else
    {
        ao_assert(false);
    }
}

// ----------------------------------------------------------------------------

#endif

#if defined AO_MIKROE_2935

// ----------------------------------------------------------------------------

static  void                    ao_boot_mikroe_2935_spi(        ao_mikroe_2935_spi_t * S);

// ----------------------------------------------------------------------------

static  int16_t                 ao_mikroe_2935_convert(         uint16_t x, uint8_t n);

// ----------------------------------------------------------------------------

static  ao_mikroe_2935_mod_t *  ao_mikroe_2935_mod(             size_t i);

// ----------------------------------------------------------------------------

static  void                    ao_mikroe_2935_mod_data(        ao_mikroe_2935_mod_t * M);

// ----------------------------------------------------------------------------

static  bool                    ao_mikroe_2935_mod_data_x(      ao_mikroe_2935_mod_t * M, uint16_t r, int16_t v);

static  bool                    ao_mikroe_2935_mod_data_y(      ao_mikroe_2935_mod_t * M, uint16_t r, int16_t v);

static  bool                    ao_mikroe_2935_mod_data_z(      ao_mikroe_2935_mod_t * M, uint16_t r, int16_t v);

// ----------------------------------------------------------------------------

static  void                    ao_mikroe_2935_mod_trim(        ao_mikroe_2935_mod_t * M);

// ----------------------------------------------------------------------------

static  void                    ao_mikroe_2935_spi_read(        ao_mikroe_2935_spi_t * S, uint8_t a, uint8_t * x);

static  void                    ao_mikroe_2935_spi_read_from(   ao_mikroe_2935_spi_t * S, uint8_t a, uint8_t * x, size_t n);

// ----------------------------------------------------------------------------

static  void                    ao_mikroe_2935_spi_write(       ao_mikroe_2935_spi_t * S, uint8_t a, uint8_t x);

// ----------------------------------------------------------------------------

static  void                    ao_mikroe_2935_task_proc(       void * x);

// ----------------------------------------------------------------------------

void ao_boot_mikroe_2935_spi(ao_mikroe_2935_spi_t * S)
{
    // Assert.

    ao_assert(S);

    ao_assert(S->begin);

    ao_assert(S->end);

    ao_assert(S->reg);


    // Variables.

    ao_spi_reg_t * R = S->reg;

    uint8_t t;


    // Ready.

    // SPI slave select.

    S->end();


    // SPI.

    R->con.reg = 0;

    t = R->buf.reg;

    R->stat.reg = 0;

    R->con.bits.cke = 0;

    R->con.bits.ckp = 1;

    R->con.bits.msten = 1;

    R->con.bits.smp = 1;

    ao_spi_baud(R, S->f_pbclk, S->f);
}

// ----------------------------------------------------------------------------

int16_t ao_mikroe_2935_convert(uint16_t i, uint8_t n)
{
    int16_t o = (int16_t) i;

    if (i & (1 << (n - 1)))
    {
        o -= (int16_t) (1 << n);
    }

    return o;
}

// ----------------------------------------------------------------------------

void ao_mikroe_2935_mod_data(ao_mikroe_2935_mod_t * M)
{
    // Notes.

    // This function is an adaption of like functions of the BMM150 Sensor API
    // provided by Bosch Sensortec.

    // https://github.com/BoschSensortec/BMM150-Sensor-API

    // Use of the API source code in modified form has been permitted, provided
    // that the following copyright notice is included.


    // Copyright notice.

    // Copyright (c) 2020 Bosch Sensortec GmbH. All rights reserved.

    // BSD-3-Clause

    // Redistribution and use in source and binary forms, with or without
    // modification, are permitted provided that the following conditions are
    // met:

    // 1. Redistributions of source code must retain the above copyright
    //    notice, this list of conditions and the following disclaimer.

    // 2. Redistributions in binary form must reproduce the above copyright
    //    notice, this list of conditions and the following disclaimer in the
    //    documentation and/or other materials provided with the distribution.

    // 3. Neither the name of the copyright holder nor the names of its
    //    contributors may be used to endorse or promote products derived from
    //    this software without specific prior written permission.

    // THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
    // "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
    // LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A
    // PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
    // HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
    // SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED
    // TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
    // PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
    // LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
    // NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
    // SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.


    // Variables.

    bool b;

    uint8_t r[8];

    uint16_t rr;

    int16_t rx;

    int16_t ry;

    int16_t rz;


    // Ready.

    ao_mikroe_2935_spi_read_from(M->spi, 0x42, r, 8);

    b = (r[6] & 0x01) ? true : false;

    if (b)
    {
        // Raw data least significant bits.

        r[0] = (r[0] >> 3) & 0x1F;
        r[2] = (r[2] >> 3) & 0x1F;
        r[4] = (r[4] >> 1) & 0x7F;
        r[6] = (r[6] >> 2) & 0x3F;

        // Raw data.

        rr = (((uint16_t) r[1]) << 5) | (uint16_t) r[0];

        rx = ao_mikroe_2935_convert(rr, 8 + 5);

        rr = (((uint16_t) r[3]) << 5) | (uint16_t) r[2];

        ry = ao_mikroe_2935_convert(rr, 8 + 5);

        rr = (((uint16_t) r[5]) << 7) | (uint16_t) r[4];

        rz = ao_mikroe_2935_convert(rr, 8 + 7);

        rr = (((uint16_t) r[7]) << 6) | (uint16_t) r[6];

        // Data.

        b = b && ao_mikroe_2935_mod_data_x(M, rr, rx);
        b = b && ao_mikroe_2935_mod_data_y(M, rr, ry);
        b = b && ao_mikroe_2935_mod_data_z(M, rr, rz);
    }

    M->data.ready = b;
}

// ----------------------------------------------------------------------------

bool ao_mikroe_2935_mod_data_x(ao_mikroe_2935_mod_t * M, uint16_t r, int16_t v)
{
    // Notes.

    // This function is an adaption of like functions of the BMM150 Sensor API
    // provided by Bosch Sensortec.

    // https://github.com/BoschSensortec/BMM150-Sensor-API

    // Use of the API source code in modified form has been permitted, provided
    // that the following copyright notice is included.


    // Copyright notice.

    // Copyright (c) 2020 Bosch Sensortec GmbH. All rights reserved.

    // BSD-3-Clause

    // Redistribution and use in source and binary forms, with or without
    // modification, are permitted provided that the following conditions are
    // met:

    // 1. Redistributions of source code must retain the above copyright
    //    notice, this list of conditions and the following disclaimer.

    // 2. Redistributions in binary form must reproduce the above copyright
    //    notice, this list of conditions and the following disclaimer in the
    //    documentation and/or other materials provided with the distribution.

    // 3. Neither the name of the copyright holder nor the names of its
    //    contributors may be used to endorse or promote products derived from
    //    this software without specific prior written permission.

    // THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
    // "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
    // LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A
    // PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
    // HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
    // SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED
    // TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
    // PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
    // LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
    // NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
    // SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.


    // Variables.

    ao_float_t d;

    ao_float_t d0;

    ao_float_t d1;

    ao_float_t d2;

    ao_float_t d3;

    ao_float_t d4;


    // Ready.

    // Overflow.

    if (v == -4096)         return false;

    if (r == 0)             return false;

    if (M->trim.xyz1 == 0)  return false;

    // Compensation.

    d0 = (ao_float_t) M->trim.xyz1 * (ao_float_t) 16384 / (ao_float_t) r;

    d = d0 - (ao_float_t) 16384;

    d1 = (ao_float_t) M->trim.xy2 * (d * d / (ao_float_t) 268435456);

    d2 = d1 + d * (ao_float_t) M->trim.xy1 / (ao_float_t) 16384;

    d3 = (ao_float_t) M->trim.x2 + (ao_float_t) 160;

    d4 = (ao_float_t) v * ((d2 + (ao_float_t) 256) * d3);

    d = (d4 / (ao_float_t) 8192 + (ao_float_t) M->trim.x1 * (ao_float_t) 8) / (ao_float_t) 16;

    M->data.x = d;

    return true;
}

bool ao_mikroe_2935_mod_data_y(ao_mikroe_2935_mod_t * M, uint16_t r, int16_t v)
{
    // Notes.

    // This function is an adaption of like functions of the BMM150 Sensor API
    // provided by Bosch Sensortec.

    // https://github.com/BoschSensortec/BMM150-Sensor-API

    // Use of the API source code in modified form has been permitted, provided
    // that the following copyright notice is included.


    // Copyright notice.

    // Copyright (c) 2020 Bosch Sensortec GmbH. All rights reserved.

    // BSD-3-Clause

    // Redistribution and use in source and binary forms, with or without
    // modification, are permitted provided that the following conditions are
    // met:

    // 1. Redistributions of source code must retain the above copyright
    //    notice, this list of conditions and the following disclaimer.

    // 2. Redistributions in binary form must reproduce the above copyright
    //    notice, this list of conditions and the following disclaimer in the
    //    documentation and/or other materials provided with the distribution.

    // 3. Neither the name of the copyright holder nor the names of its
    //    contributors may be used to endorse or promote products derived from
    //    this software without specific prior written permission.

    // THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
    // "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
    // LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A
    // PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
    // HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
    // SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED
    // TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
    // PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
    // LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
    // NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
    // SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.


    // Variables.

    ao_float_t d;

    ao_float_t d0;

    ao_float_t d1;

    ao_float_t d2;

    ao_float_t d3;

    ao_float_t d4;


    // Ready.

    // Overflow.

    if (v == -4096) return false;

    if (r == 0) return false;

    if (M->trim.xyz1 == 0) return false;

    // Compensation.

    d0 = (ao_float_t) M->trim.xyz1 * (ao_float_t) 16384 / (ao_float_t) r;

    d = d0 - (ao_float_t) 16384;

    d1 = (ao_float_t) M->trim.xy2 * (d * d / (ao_float_t) 268435456);

    d2 = d1 + d * (ao_float_t) M->trim.xy1 / (ao_float_t) 16384;

    d3 = (ao_float_t) M->trim.y2 + (ao_float_t) 160;

    d4 = (ao_float_t) v * ((d2 + (ao_float_t) 256) * d3);

    d = (d4 / (ao_float_t) 8192 + (ao_float_t) M->trim.y1 * (ao_float_t) 8) / (ao_float_t) 16;

    M->data.y = d;

    return true;
}

bool ao_mikroe_2935_mod_data_z(ao_mikroe_2935_mod_t * M, uint16_t r, int16_t v)
{
    // Notes.

    // This function is an adaption of like functions of the BMM150 Sensor API
    // provided by Bosch Sensortec.

    // https://github.com/BoschSensortec/BMM150-Sensor-API

    // Use of the API source code in modified form has been permitted, provided
    // that the following copyright notice is included.


    // Copyright notice.

    // Copyright (c) 2020 Bosch Sensortec GmbH. All rights reserved.

    // BSD-3-Clause

    // Redistribution and use in source and binary forms, with or without
    // modification, are permitted provided that the following conditions are
    // met:

    // 1. Redistributions of source code must retain the above copyright
    //    notice, this list of conditions and the following disclaimer.

    // 2. Redistributions in binary form must reproduce the above copyright
    //    notice, this list of conditions and the following disclaimer in the
    //    documentation and/or other materials provided with the distribution.

    // 3. Neither the name of the copyright holder nor the names of its
    //    contributors may be used to endorse or promote products derived from
    //    this software without specific prior written permission.

    // THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
    // "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
    // LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A
    // PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
    // HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
    // SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED
    // TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
    // PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
    // LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
    // NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
    // SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.


    // Variables.

    ao_float_t d;

    ao_float_t d0;

    ao_float_t d1;

    ao_float_t d2;

    ao_float_t d3;

    ao_float_t d4;

    ao_float_t d5;


    // Ready.

    // Overflow.

    if (v == -16384) return false;

    if (r == 0) return false;

    if (M->trim.xyz1 == 0) return false;

    if (M->trim.z1 == 0) return false;

    if (M->trim.z2 == 0) return false;

    // Compensation.

    d0 = (ao_float_t) v - (ao_float_t) M->trim.z4;

    d1 = (ao_float_t) r - (ao_float_t) M->trim.xyz1;

    d2 = (ao_float_t) M->trim.z3 * d1;

    d3 = (ao_float_t) M->trim.z1 * (ao_float_t) r / (ao_float_t) 32768;

    d4 = (ao_float_t) M->trim.z2 + d3;

    d5 = d0 * (ao_float_t) 131072 - d2;

    d = (d5 / (d4 * (ao_float_t) 4)) / (ao_float_t) 16;

    M->data.z = d;

    return true;
}

// ----------------------------------------------------------------------------

void ao_mikroe_2935_mod_trim(ao_mikroe_2935_mod_t * M)
{
    // Notes.

    // This function is an adaption of like functions of the BMM150 Sensor API
    // provided by Bosch Sensortec.

    // https://github.com/BoschSensortec/BMM150-Sensor-API

    // Use of the API source code in modified form has been permitted, provided
    // that the following copyright notice is included.


    // Copyright notice.

    // Copyright (c) 2020 Bosch Sensortec GmbH. All rights reserved.

    // BSD-3-Clause

    // Redistribution and use in source and binary forms, with or without
    // modification, are permitted provided that the following conditions are
    // met:

    // 1. Redistributions of source code must retain the above copyright
    //    notice, this list of conditions and the following disclaimer.

    // 2. Redistributions in binary form must reproduce the above copyright
    //    notice, this list of conditions and the following disclaimer in the
    //    documentation and/or other materials provided with the distribution.

    // 3. Neither the name of the copyright holder nor the names of its
    //    contributors may be used to endorse or promote products derived from
    //    this software without specific prior written permission.

    // THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
    // "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
    // LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A
    // PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
    // HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
    // SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED
    // TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
    // PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
    // LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
    // NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
    // SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.


    // Variables.

    uint8_t r5d[2];

    uint8_t r62[4];

    uint8_t r68[10];

    ao_mikroe_2935_spi_t * S = M->spi;

    uint16_t v = 0;


    // Ready.

    ao_mikroe_2935_spi_read_from(S, 0x5d, r5d, 2);

    ao_mikroe_2935_spi_read_from(S, 0x62, r62, 4);

    ao_mikroe_2935_spi_read_from(S, 0x68, r68, 10);


    // Ready.

    v               = 0;

    M->trim.x1      = (int8_t) r5d[0];

    M->trim.y1      = (int8_t) r5d[1];

    M->trim.x2      = (int8_t) r62[2];

    M->trim.y2      = (int8_t) r62[3];

    v               = ((uint16_t) r68[3]) << 8;

    M->trim.z1      = (uint16_t) (v | r68[2]);

    v               = ((uint16_t) r68[1]) << 8;

    M->trim.z2      = (int16_t) (v | r68[0]);

    v               = ((uint16_t) r68[7]) << 8;

    M->trim.z3      = (int16_t) (v | r68[6]);

    v               = ((uint16_t) r62[1]) << 8;

    M->trim.z4      = (int16_t) (v | r62[0]);

    M->trim.xy1     = r68[9];

    M->trim.xy2     = (int8_t) r68[8];

    v               = ((uint16_t) (r68[5] & 0x7F)) << 8;

    M->trim.xyz1    = (uint16_t) (v | r68[4]);
}

// ----------------------------------------------------------------------------

void ao_mikroe_2935_spi_read(ao_mikroe_2935_spi_t * S, uint8_t a, uint8_t * x)
{
    // Assert.

    ao_assert(S);

    ao_assert(S->begin);

    ao_assert(S->end);

    ao_assert(S->reg);

    ao_assert(a >= 0x40);

    ao_assert(a <= 0x71);

    ao_assert(x);


    // Variables.

    ao_spi_reg_t * R = S->reg;

    uint8_t t;


    // Ready.

    // Slave select setup time is 20 nanoseconds.

    R->con.bits.on = 1;

    S->begin();

    ao_spin(ao_nanoseconds(20));


    // Address.

    R->buf.reg = 0x80 | a;

    while (!R->stat.bits.spirbf) { }

    t = R->buf.reg;


    // Value.

    R->buf.reg = 0;

    while (!R->stat.bits.spirbf) { }

    t = R->buf.reg;


    // Slave select hold time is 40 nanoseconds.

    ao_spin(ao_nanoseconds(40));

    S->end();

    R->con.bits.on = 0;

    *x = t;
}

void ao_mikroe_2935_spi_read_from(ao_mikroe_2935_spi_t * S, uint8_t a, uint8_t * x, size_t n)
{
    // Assert.

    ao_assert(S);

    ao_assert(S->begin);

    ao_assert(S->end);

    ao_assert(S->reg);

    ao_assert(a >= 0x40);

    ao_assert(a <= 0x71 + 1 - (uint8_t) n);

    ao_assert(x);

    ao_assert(n);


    // Variables.

    ao_spi_reg_t * R = S->reg;

    uint8_t t;


    // Ready.

    // Slave select setup time is 20 nanoseconds.

    R->con.bits.on = 1;

    S->begin();

    ao_spin(ao_nanoseconds(20));


    // Address.

    R->buf.reg = 0x80 | a;

    while (!R->stat.bits.spirbf) { }

    t = R->buf.reg;


    // Values.

    while (n)
    {
        R->buf.reg = 0;

        while (!R->stat.bits.spirbf) { }

        *x = R->buf.reg;

        n--;
        x++;
    }


    // Slave select hold time is 40 nanoseconds.

    ao_spin(ao_nanoseconds(40));

    S->end();

    R->con.bits.on = 0;
}

// ----------------------------------------------------------------------------

void ao_mikroe_2935_spi_write(ao_mikroe_2935_spi_t * S, uint8_t a, uint8_t x)
{
    // Assert.

    ao_assert(S);

    ao_assert(S->begin);

    ao_assert(S->end);

    ao_assert(S->reg);

    ao_assert(a >= 0x40);

    ao_assert(a <= 0x71);


    // Variables.

    ao_spi_reg_t * R = S->reg;

    uint8_t t;


    // Ready.

    // Slave select setup time is 20 nanoseconds.

    R->con.bits.on = 1;

    S->begin();

    ao_spin(ao_nanoseconds(20));


    // Address.

    R->buf.reg = a;

    while (!R->stat.bits.spirbf) { }

    t = R->buf.reg;


    // Value.

    R->buf.reg = x;

    while (!R->stat.bits.spirbf) { }

    t = R->buf.reg;


    // Slave select hold time is 40 nanoseconds.

    ao_spin(ao_nanoseconds(40));

    S->end();

    R->con.bits.on = 0;


    // Time before a new transmission can start is 1.3 microseconds.

    ao_spin(ao_microseconds(1.3));
}

// ----------------------------------------------------------------------------

void ao_mikroe_2935_start(size_t i)
{
    // Variables.

    ao_mikroe_2935_mod_t * M;

    ao_task_t * T;


    // Ready.

    M = ao_mikroe_2935_mod(i);

    if (M)
    {
        T = M->task;

        ao_task_set_proc(T, ao_mikroe_2935_task_proc, M);

        ao_task_start(T);
    }

    else
    {
        ao_assert(false);
    }
}

void ao_mikroe_2935_stop(size_t i)
{
    // Variables.

    ao_mikroe_2935_mod_t * M;


    // Ready.

    M = ao_mikroe_2935_mod(i);

    if (M)
    {
        ao_sem_give(&M->sem, 1);
    }

    else
    {
        ao_assert(false);
    }
}

// ----------------------------------------------------------------------------

void ao_mikroe_2935_task_proc(void * x)
{
    // Variables.

    ao_mikroe_2935_mod_t *  const   M               =  x;


    // Variables.

    ao_async_any_t *        const   async           = &M->async;

    ao_async_t *            const   async_sem_take  = &M->sem_take.async;

    ao_async_t *            const   async_sleep_1   = &M->sleep_1.async;

    ao_async_t *            const   async_sleep_2   = &M->sleep_2.async;

    ao_async_t **           const   async_store     = &M->async_store[0];

    ao_time_t                       beginning_1;

    ao_time_t                       beginning_2;

    size_t                  const   i               =  M->i;

    ao_time_t                       measurement;

    uint16_t                        nxy             = M->repetitions_xy;

    uint16_t                        nz              = M->repetitions_z;

    ao_time_t               const   period          = M->period;

    uint8_t                         r40;

    uint8_t                         r4b;

    uint8_t                         r4c;

    uint8_t                         r51;

    uint8_t                         r52;

    ao_mikroe_2935_spi_t *  const   S               =  M->spi;

    ao_sem_t *              const   sem             = &M->sem;

    ao_sem_take_t *         const   sem_take        = &M->sem_take;

    ao_sleep_t *            const   sleep_1         = &M->sleep_1;

    ao_sleep_t *            const   sleep_2         = &M->sleep_2;

    bool                            started;

    ao_time_t                       timeout_1;

    ao_time_t                       timeout_2;

    ao_mikroe_2935_t *      const   X               = &M->data;


    // Ready.

    async->count    = 3;

    async->store    = async_store;

    async_store[0]  = async_sem_take;

    async_store[1]  = async_sleep_1;

    async_store[2]  = async_sleep_2;

    sem_take->count = 1;

    sem_take->sem   = sem;


    // Ready.

    nxy = AO_CLAMP(nxy, 1, 511);

    nz = AO_CLAMP(nz, 1, 256);

    r51 = (uint8_t) ((nxy - 1) / 2);

    r52 = (uint8_t) (nz - 1);

    nxy = 1 + (uint16_t) r51 * 2;

    nz = 1 + (uint16_t) r52;

    measurement =
        ao_microseconds(145) * (ao_time_t) nxy +
        ao_microseconds(500) * (ao_time_t) nz +
        ao_microseconds(980);


    // Ready.

    while (1)
    {
        // Start.

        // Start-up time from POR to suspend mode is 1 millisecond.

        ao_spin(ao_milliseconds(1));


        // Clear power control bit.

        ao_mikroe_2935_spi_read(S, 0x4b, &r4b);

        r4b = r4b & 0xFE;

        ao_mikroe_2935_spi_write(S, 0x4b, r4b);


        // Set power control bit.

        // Start-up time from suspend mode to sleep mode is 3 milliseconds.

        r4b = r4b | 0x01;

        ao_mikroe_2935_spi_write(S, 0x4b, r4b);

        ao_spin(ao_milliseconds(3));


        // Read the chip ID.

        ao_mikroe_2935_spi_read(S, 0x40, &r40);

        ao_assert(r40 == 0x32);


        // Set operation mode.

        ao_mikroe_2935_spi_read(S, 0x4c, &r4c);

        r4c = r4c & 0xF9;

        r4c = r4c | 0x06;

        ao_mikroe_2935_spi_write(S, 0x4c, r4c);

        r4c = r4c & 0xF9;

        r4c = r4c | 0x02;


        // Get trim registers.

        ao_mikroe_2935_mod_trim(M);


        // Set the number of repetitions.

        ao_mikroe_2935_spi_write(S, 0x51, r51);

        ao_mikroe_2935_spi_write(S, 0x52, r52);


        // Start.

        beginning_1 = ao_now();

        beginning_2 = 0;

        timeout_1   = period;

        timeout_2   = AO_INFINITY;

        started     = true;

        do
        {
            // Sleep.

            sleep_1->beginning  = beginning_1;

            sleep_2->beginning  = beginning_2;

            sleep_1->timeout    = timeout_1;

            sleep_2->timeout    = timeout_2;


            // Await.

            ao_sem_take_begin(sem_take);

            ao_sleep_begin(sleep_1);

            ao_sleep_begin(sleep_2);

            ao_await_any_forever(async);

            ao_sleep_end(sleep_2);

            ao_sleep_end(sleep_1);

            ao_sem_take_end(sem_take);


            // Stop.

            if (sem_take->result)
            {
                started = false;
            }


            // Timeout expired.

            else
            {
                if (sleep_2->result)
                {
                    ao_mikroe_2935_mod_data(M);

                    ao_mikroe_2935(i, X);

                    timeout_2 = AO_INFINITY;
                }

                if (sleep_1->result)
                {
                    // Force a measurement.

                    ao_mikroe_2935_spi_write(S, 0x4c, r4c);

                    beginning_1 = beginning_1 + timeout_1;

                    beginning_2 = ao_now();

                    timeout_2   = measurement;
                }
            }
        }
        while (started);


        // Clear power control bit.

        r4b = r4b & 0xFE;

        ao_mikroe_2935_spi_write(S, 0x4b, r4b);


        // Stop.

        ao_stop();
    }
}

// ----------------------------------------------------------------------------

#endif

#if defined AO_MIKROE_2950

// ----------------------------------------------------------------------------

static  void    ao_boot_mikroe_2950_i2c(ao_mikroe_2950_i2c_t * I);

// ----------------------------------------------------------------------------

static  void *  ao_mikroe_2950_i2c(     size_t i);

// ----------------------------------------------------------------------------

static  void    ao_mikroe_2950_send(    size_t i, uint8_t x);

// ----------------------------------------------------------------------------

void ao_boot_mikroe_2950_i2c(ao_mikroe_2950_i2c_t * I)
{
    // Assert.

    ao_assert(I);

    ao_assert(I->f);

    ao_assert(I->f <= 400000UL);

    ao_assert(I->f_pbclk);


    // Variables.

    uint32_t f = I->f;

    uint32_t f_pbclk = I->f_pbclk;

    ao_i2c_reg_t * R = I->reg;


    // Ready.

    R->con.reg = 0;

    ao_i2c_baud(R, f_pbclk, f);

    R->con.bits.on = 1;

    ao_spin(ao_microseconds(150));
}

// ----------------------------------------------------------------------------

void ao_mikroe_2950_color(size_t i, uint8_t r, uint8_t g, uint8_t b)
{
    ao_mikroe_2950_send(i, 0b01000000 | (r >> 3));

    ao_mikroe_2950_send(i, 0b01100000 | (g >> 3));

    ao_mikroe_2950_send(i, 0b10000000 | (b >> 3));
}

// ----------------------------------------------------------------------------

void ao_mikroe_2950_luminance(size_t i, uint8_t l)
{
    ao_mikroe_2950_send(i, 0b00100000 | (l >> 3));
}

// ----------------------------------------------------------------------------

void ao_mikroe_2950_luminance_down(size_t i, uint8_t l, ao_time_t t)
{
    // Variables.

    uintmax_t x = (uintmax_t) t;


    // Ready.

    x = ao_milliseconds_from_time(x);

    x = AO_MAX(x,   8);

    x = AO_MIN(x, 248);

    ao_mikroe_2950_send(i, 0b11000000 | (          l >> 3));

    ao_mikroe_2950_send(i, 0b11100000 | ((uint8_t) x >> 3));
}

void ao_mikroe_2950_luminance_up(size_t i, uint8_t l, ao_time_t t)
{
    // Variables.

    uintmax_t x = (uintmax_t) t;


    // Ready.

    x = ao_milliseconds_from_time(x);

    x = AO_MAX(x,   8);

    x = AO_MIN(x, 248);

    ao_mikroe_2950_send(i, 0b10100000 | (          l >> 3));

    ao_mikroe_2950_send(i, 0b11100000 | ((uint8_t) x >> 3));
}

// ----------------------------------------------------------------------------

void ao_mikroe_2950_send(size_t i, uint8_t x)
{
    // Variables.

    ao_mikroe_2950_i2c_t * I;

    bool r;

    ao_i2c_reg_t * R;


    // Ready.

    I = ao_mikroe_2950_i2c(i);

    ao_assert(I);

    ao_assert(I->reg);


    // Ready.

    R = I->reg;

    r = true;

    r = r && ao_i2c_start_forever(R);

    r = r && ao_i2c_send_forever(R, 0x70);

    r = r && ao_i2c_acked(R);

    r = r && ao_i2c_send_forever(R, x);

    r = r && ao_i2c_acked(R);

    r = r && ao_i2c_stop_forever(R);

    ao_assert(r);


    // Ready.

    // NCP5623B Datasheet.

    // The datasheet specifies a start-up time.

    // The setup specified in an I2C transfer will take effect 150 µs after the
    // last ack bit.

    // It seems like this delay is also required between subsequent I2C
    // transfers.

    ao_spin(ao_microseconds(150));
}

// ----------------------------------------------------------------------------

#endif

#if defined AO_MIKROE_3063

// ----------------------------------------------------------------------------

static  void    ao_mikroe_3063_reset_disable(   size_t i);

static  void    ao_mikroe_3063_reset_enable(    size_t i);

// ----------------------------------------------------------------------------

static  void    ao_mikroe_3063_wakeup_disable(  size_t i);

static  void    ao_mikroe_3063_wakeup_enable(   size_t i);

// ----------------------------------------------------------------------------

void ao_mikroe_3063_reset(size_t i)
{
    // CP2102N Data Sheet.

    // Minimum RSTb low time to generate reset is 15 microseconds.

    ao_mikroe_3063_reset_enable(i);

    ao_spin(ao_microseconds(15));

    ao_mikroe_3063_reset_disable(i);
}

// ----------------------------------------------------------------------------

#endif

#if defined AO_MIKROE_4186

// ----------------------------------------------------------------------------

static  void                    ao_boot_mikroe_4186_i2c(        ao_mikroe_4186_i2c_t * I);

// ----------------------------------------------------------------------------

static  uint32_t                ao_mikroe_4186_get(             size_t i, uint8_t c);

// ----------------------------------------------------------------------------

static  uint8_t                 ao_mikroe_4186_get_port(        size_t i, size_t p, uint8_t c);

// ----------------------------------------------------------------------------

static  ao_mikroe_4186_i2c_t *  ao_mikroe_4186_i2c(             size_t i);

// ----------------------------------------------------------------------------

static  void                    ao_mikroe_4186_i2c_delay(       ao_mikroe_4186_i2c_t * I);

static  void                    ao_mikroe_4186_i2c_delay_begin( ao_mikroe_4186_i2c_t * I);

static  void                    ao_mikroe_4186_i2c_delay_end(   ao_mikroe_4186_i2c_t * I);

// ----------------------------------------------------------------------------

static  void                    ao_mikroe_4186_int_disable(     size_t i);

static  void                    ao_mikroe_4186_int_enable(      size_t i);

// ----------------------------------------------------------------------------

static  void                    ao_mikroe_4186_reset_disable(   size_t i);

static  void                    ao_mikroe_4186_reset_enable(    size_t i);

// ----------------------------------------------------------------------------

static  void                    ao_mikroe_4186_set(             size_t i, uint32_t x, uint8_t c);

// ----------------------------------------------------------------------------

static  void                    ao_mikroe_4186_set_port(        size_t i, size_t p, uint8_t x, uint8_t c);

// ----------------------------------------------------------------------------

void ao_boot_mikroe_4186_i2c(ao_mikroe_4186_i2c_t * I)
{
    // Assert.

    ao_assert(I);

    ao_assert(I->f);

    ao_assert(I->f_pbclk);

    ao_assert(I->reg);


    // Variables.

    uint32_t f = I->f;

    uint32_t f_pbclk = I->f_pbclk;

    ao_i2c_reg_t * R = I->reg;


    // Ready.

    // I2C bus free time between stop and start.

    // 100 kHz mode: 4.7 µs.

    // 400 kHz mode: 1.3 µs.

    if (f >= 400000UL)
    {
        I->delay_timeout = ao_microseconds(1.3);
    }

    else
    {
        I->delay_timeout = ao_microseconds(4.7);
    }

    R->con.reg = 0;

    ao_i2c_baud(R, f_pbclk, f);

    R->con.bits.on = 1;
}

// ----------------------------------------------------------------------------

uint32_t ao_mikroe_4186_get(size_t i, uint8_t c)
{
    // Variables.

    ao_time_t B = ao_now();

    ao_mikroe_4186_i2c_t * I;

    bool r;

    ao_i2c_reg_t * R;

    ao_time_t T;

    uint8_t x0;
    uint8_t x1;
    uint8_t x2;

    uint32_t X0;
    uint32_t X1;
    uint32_t X2;

    uint32_t XX;


    // Ready.

    I = ao_mikroe_4186_i2c(i);

    ao_assert(I);

    ao_assert(I->reg);


    // Ready.

    R = I->reg;

    T = I->timeout;


    // Ready.

    c = c | 0x80;


    // Ready.

    r = true;

    r = r && ao_i2c_start_from(R, T, B);

    r = r && ao_i2c_send_from(R, AO_MIKROE_4186_ADDR_SEND, T, B);

    r = r && ao_i2c_send_from(R, c, T, B);

    r = r && ao_i2c_restart_from(R, T, B);

    r = r && ao_i2c_send_from(R, AO_MIKROE_4186_ADDR_RECV, T, B);

    r = r && ao_i2c_recv_from(R, &x0, T, B);

    r = r && ao_i2c_ack_from(R, T, B);

    r = r && ao_i2c_recv_from(R, &x1, T, B);

    r = r && ao_i2c_ack_from(R, T, B);

    r = r && ao_i2c_recv_from(R, &x2, T, B);

    r = r && ao_i2c_nack_from(R, T, B);

    r = r && ao_i2c_stop_from(R, T, B);

    ao_assert(r);


    // Ready.

    ao_mikroe_4186_i2c_delay_begin(I);

    X0 = (uint32_t) x0 <<  0;

    X1 = (uint32_t) x1 <<  8;

    X2 = (uint32_t) x2 << 16;

    XX = X0 | X1 | X2;

    ao_mikroe_4186_i2c_delay_end(I);

    return XX;
}

// ----------------------------------------------------------------------------

uint32_t ao_mikroe_4186_get_config(size_t i)
{
    return ao_mikroe_4186_get(i, AO_MIKROE_4186_CONFIG);
}

uint32_t ao_mikroe_4186_get_input(size_t i)
{
    return ao_mikroe_4186_get(i, AO_MIKROE_4186_INPUT);
}

uint32_t ao_mikroe_4186_get_output(size_t i)
{
    return ao_mikroe_4186_get(i, AO_MIKROE_4186_OUTPUT);
}

uint32_t ao_mikroe_4186_get_polarity(size_t i)
{
    return ao_mikroe_4186_get(i, AO_MIKROE_4186_POLARITY);
}

// ----------------------------------------------------------------------------

uint8_t ao_mikroe_4186_get_port(size_t i, size_t p, uint8_t c)
{
    // Variables.

    ao_time_t B = ao_now();

    ao_mikroe_4186_i2c_t * I;

    bool r;

    ao_i2c_reg_t * R;

    ao_time_t T;

    uint8_t x;


    // Ready.

    I = ao_mikroe_4186_i2c(i);

    ao_assert(I);

    ao_assert(I->reg);


    // Ready.

    R = I->reg;

    T = I->timeout;


    // Ready.

    p = p & 3;

    c = c + (uint8_t) p;


    // Ready.

    r = true;

    r = r && ao_i2c_start_from(R, T, B);

    r = r && ao_i2c_send_from(R, AO_MIKROE_4186_ADDR_SEND, T, B);

    r = r && ao_i2c_send_from(R, c, T, B);

    r = r && ao_i2c_restart_from(R, T, B);

    r = r && ao_i2c_send_from(R, AO_MIKROE_4186_ADDR_RECV, T, B);

    r = r && ao_i2c_recv_from(R, &x, T, B);

    r = r && ao_i2c_nack_from(R, T, B);

    r = r && ao_i2c_stop_from(R, T, B);

    ao_assert(r);


    // Ready.

    ao_mikroe_4186_i2c_delay(I);

    return x;
}

// ----------------------------------------------------------------------------

uint8_t ao_mikroe_4186_get_port_config(size_t i, size_t p)
{
    return ao_mikroe_4186_get_port(i, p, AO_MIKROE_4186_CONFIG);
}

uint8_t ao_mikroe_4186_get_port_input(size_t i, size_t p)
{
    return ao_mikroe_4186_get_port(i, p, AO_MIKROE_4186_INPUT);
}

uint8_t ao_mikroe_4186_get_port_output(size_t i, size_t p)
{
    return ao_mikroe_4186_get_port(i, p, AO_MIKROE_4186_OUTPUT);
}

uint8_t ao_mikroe_4186_get_port_polarity(size_t i, size_t p)
{
    return ao_mikroe_4186_get_port(i, p, AO_MIKROE_4186_POLARITY);
}

// ----------------------------------------------------------------------------

void ao_mikroe_4186_i2c_delay(ao_mikroe_4186_i2c_t * I)
{
    ao_spin(I->delay_timeout);
}

void ao_mikroe_4186_i2c_delay_begin(ao_mikroe_4186_i2c_t * I)
{
    I->delay_beginning = ao_now();
}

void ao_mikroe_4186_i2c_delay_end(ao_mikroe_4186_i2c_t * I)
{
    ao_spin_from(I->delay_timeout, I->delay_beginning);
}

// ----------------------------------------------------------------------------

void ao_mikroe_4186_reset(size_t i)
{
    ao_mikroe_4186_reset_enable(i);

    ao_spin(ao_nanoseconds(4));

    ao_mikroe_4186_reset_disable(i);

    ao_spin(ao_nanoseconds(600));
}

// ----------------------------------------------------------------------------

void ao_mikroe_4186_set(size_t i, uint32_t x, uint8_t c)
{
    // Variables.

    ao_time_t B = ao_now();

    ao_mikroe_4186_i2c_t * I;

    bool r;

    ao_i2c_reg_t * R;

    ao_time_t T;

    uint8_t x0;

    uint8_t x1;

    uint8_t x2;


    // Ready.

    I = ao_mikroe_4186_i2c(i);

    ao_assert(I);

    ao_assert(I->reg);


    // Ready.

    R = I->reg;

    T = I->timeout;


    // Ready.

    c = c | 0x80;

    x0 = (uint8_t) ((x >>  0) & 0xFF);

    x1 = (uint8_t) ((x >>  8) & 0xFF);

    x2 = (uint8_t) ((x >> 16) & 0xFF);


    // Ready.

    r = true;

    r = r && ao_i2c_start_from(R, T, B);

    r = r && ao_i2c_send_from(R, AO_MIKROE_4186_ADDR_SEND, T, B);

    r = r && ao_i2c_send_from(R, c, T, B);

    r = r && ao_i2c_send_from(R, x0, T, B);

    r = r && ao_i2c_send_from(R, x1, T, B);

    r = r && ao_i2c_send_from(R, x2, T, B);

    r = r && ao_i2c_stop_from(R, T, B);

    ao_assert(r);


    // Ready.

    ao_mikroe_4186_i2c_delay(I);
}

// ----------------------------------------------------------------------------

void ao_mikroe_4186_set_config(size_t i, uint32_t x)
{
    ao_mikroe_4186_set(i, x, AO_MIKROE_4186_CONFIG);
}

void ao_mikroe_4186_set_input(size_t i, uint32_t x)
{
    ao_mikroe_4186_set(i, x, AO_MIKROE_4186_INPUT);
}

void ao_mikroe_4186_set_output(size_t i, uint32_t x)
{
    ao_mikroe_4186_set(i, x, AO_MIKROE_4186_OUTPUT);
}

void ao_mikroe_4186_set_polarity(size_t i, uint32_t x)
{
    ao_mikroe_4186_set(i, x, AO_MIKROE_4186_POLARITY);
}

// ----------------------------------------------------------------------------

void ao_mikroe_4186_set_port(size_t i, size_t p, uint8_t x, uint8_t c)
{
    // Variables.

    ao_time_t B = ao_now();

    ao_mikroe_4186_i2c_t * I;

    bool r;

    ao_i2c_reg_t * R;

    ao_time_t T;


    // Ready.

    I = ao_mikroe_4186_i2c(i);

    ao_assert(I);

    ao_assert(I->reg);


    // Ready.

    R = I->reg;

    T = I->timeout;


    // Ready.

    p = p & 3;

    c = c + (uint8_t) p;


    // Ready.

    r = true;

    r = r && ao_i2c_start_from(R, T, B);

    r = r && ao_i2c_send_from(R, AO_MIKROE_4186_ADDR_SEND, T, B);

    r = r && ao_i2c_send_from(R, c, T, B);

    r = r && ao_i2c_send_from(R, x, T, B);

    r = r && ao_i2c_stop_from(R, T, B);

    ao_assert(r);


    // Ready.

    ao_mikroe_4186_i2c_delay(I);
}

// ----------------------------------------------------------------------------

void ao_mikroe_4186_set_port_config(size_t i, size_t p, uint8_t x)
{
    ao_mikroe_4186_set_port(i, p, x, AO_MIKROE_4186_CONFIG);
}

void ao_mikroe_4186_set_port_input(size_t i, size_t p, uint8_t x)
{
    ao_mikroe_4186_set_port(i, p, x, AO_MIKROE_4186_INPUT);
}

void ao_mikroe_4186_set_port_output(size_t i, size_t p, uint8_t x)
{
    ao_mikroe_4186_set_port(i, p, x, AO_MIKROE_4186_OUTPUT);
}

void ao_mikroe_4186_set_port_polarity(size_t i, size_t p, uint8_t x)
{
    ao_mikroe_4186_set_port(i, p, x, AO_MIKROE_4186_POLARITY);
}

// ----------------------------------------------------------------------------

#endif

// ----------------------------------------------------------------------------

#if defined AO_MIKROE_2340

#if defined AO_BOOT

// ----------------------------------------------------------------------------

void ao_boot()
{
    // Count.

    ao_boot_count();


    // System.

    ao_boot_sys_pcache();


    // Interrupts.

    ao_boot_ir_stack();

    ao_boot_ir_mvec();

    ao_boot_ir_srs();


    ao_boot_ir_can1();

    ao_boot_ir_can2();

    ao_boot_ir_cs0();

    ao_boot_ir_cs1();

    ao_boot_ir_ct();

    ao_boot_ir_int1();

    ao_boot_ir_int2();

    ao_boot_ir_int3();

    ao_boot_ir_u1rx();

    ao_boot_ir_u1tx();

    ao_boot_ir_u2rx();

    ao_boot_ir_u2tx();

    ao_boot_ir_u3rx();

    ao_boot_ir_u3tx();

    ao_boot_ir_u4rx();

    ao_boot_ir_u4tx();

    ao_boot_ir_u5rx();

    ao_boot_ir_u5tx();


    // Modules.

#if defined AO_ALLOC

    ao_boot_alloc();

#endif

#if defined AO_ALARM

    ao_boot_alarm();

#endif

    ao_boot_button();

    ao_boot_led();

#if defined AO_MIKROE_1877

    ao_boot_mikroe_1877();

#endif

#if defined AO_MIKROE_2334

    ao_boot_mikroe_2334();

#endif

#if defined AO_MIKROE_2674

    ao_boot_mikroe_2674();

#endif

#if defined AO_MIKROE_2935

    ao_boot_mikroe_2935();

#endif

#if defined AO_MIKROE_2950

    ao_boot_mikroe_2950();

#endif

#if defined AO_MIKROE_3063

    ao_boot_mikroe_3063();

#endif

#if defined AO_MIKROE_4186

    ao_boot_mikroe_4186();

#endif

#if defined AO_TASK

    ao_boot_task();

#endif

#if defined AO_UART_5

    ao_boot_uart_5();

#endif


    // Interrupts.

    ao_ir_enable();
}

// ----------------------------------------------------------------------------

#endif

#if defined AO_MIKROE_1877_A && AO_MIKROE_1877_A

// ----------------------------------------------------------------------------

static  void                    ao_boot_mikroe_1877_a();

// ----------------------------------------------------------------------------

static  bool                    ao_mikroe_1877_int_asserted_a();

static  void                    ao_mikroe_1877_int_disable_a();

static  void                    ao_mikroe_1877_int_enable_a();

// ----------------------------------------------------------------------------

static  void                    ao_mikroe_1877_reset_disable_a();

static  void                    ao_mikroe_1877_reset_enable_a();

// ----------------------------------------------------------------------------

static  void                    ao_mikroe_1877_wake_disable_a();

static  void                    ao_mikroe_1877_wake_enable_a();

// ----------------------------------------------------------------------------

static  ao_mikroe_1877_i2c_t    ao_mikroe_1877_i2c_a =
{
        .f                      = AO_MIKROE_1877_BAUD_A,

        .f_pbclk                = AO_SYS_CLOCK_I2C2,

        .reg                    = ao_i2c_reg_2(),

        .timeout                = AO_MIKROE_1877_TIMEOUT_A
};

// ----------------------------------------------------------------------------

        ao_task_t               ao_mikroe_1877_task_a;

// ----------------------------------------------------------------------------

static  ao_mikroe_1877_mod_t    ao_mikroe_1877_mod_a =
{
        .i                      = AO_MIKROE_A,

        .i2c                    = &ao_mikroe_1877_i2c_a,

        .int_asserted           = ao_mikroe_1877_int_asserted_a,

        .int_disable            = ao_mikroe_1877_int_disable_a,

        .int_enable             = ao_mikroe_1877_int_enable_a,

        .reset_disable          = ao_mikroe_1877_reset_disable_a,

        .reset_enable           = ao_mikroe_1877_reset_enable_a,

        .task                   = &ao_mikroe_1877_task_a,

        .wake_disable           = ao_mikroe_1877_wake_disable_a,

        .wake_enable            = ao_mikroe_1877_wake_enable_a
};

// ----------------------------------------------------------------------------

void ao_boot_mikroe_1877_a()
{
    // Variables.

    ao_sys_lock_pps_t l;


    // Interrupt.

    ao_ir_int2_falling();


    // Pins.

    // INT2  = D9,  pps.

    // RESET = E2,  out, active low.

    // SCL2  = A2.

    // SDA2  = A3.

    // WAKE  = B11, out, active high.

    ANSELBCLR = _ANSELB_ANSB11_MASK;

    TRISBCLR = _TRISB_TRISB11_MASK;

    TRISECLR = _TRISE_TRISE2_MASK;

    ao_sys_unlock_pps(&l);
    {
        INT2R = 0b0000;
    }
    ao_sys_lock_pps(&l);


    // I2C.

    ao_boot_mikroe_1877_i2c(&ao_mikroe_1877_i2c_a);
}

// ----------------------------------------------------------------------------

AO_IR_INT2_ATTRIBUTE
void ao_ir_int2()
{
    ao_mikroe_1877_mod_int(&ao_mikroe_1877_mod_a);

    ao_ir_int2_reply();
}

// ----------------------------------------------------------------------------

bool ao_mikroe_1877_int_asserted_a()
{
    return (PORTD & _PORTD_RD9_MASK) ? false : true;
}

void ao_mikroe_1877_int_disable_a()
{
    ao_ir_int2_disable();
}

void ao_mikroe_1877_int_enable_a()
{
    ao_ir_int2_enable();
}

// ----------------------------------------------------------------------------

void ao_mikroe_1877_reset_disable_a()
{
    LATESET = _LATE_LATE2_MASK;
}

void ao_mikroe_1877_reset_enable_a()
{
    LATECLR = _LATE_LATE2_MASK;
}

// ----------------------------------------------------------------------------

void ao_mikroe_1877_wake_disable_a()
{
    LATBCLR = _LATB_LATB11_MASK;
}

void ao_mikroe_1877_wake_enable_a()
{
    LATBSET = _LATB_LATB11_MASK;
}

// ----------------------------------------------------------------------------

#endif

#if defined AO_MIKROE_1877_B && AO_MIKROE_1877_B

// ----------------------------------------------------------------------------

static  void                    ao_boot_mikroe_1877_b();

// ----------------------------------------------------------------------------

static  bool                    ao_mikroe_1877_int_asserted_b();

static  void                    ao_mikroe_1877_int_disable_b();

static  void                    ao_mikroe_1877_int_enable_b();

// ----------------------------------------------------------------------------

static  void                    ao_mikroe_1877_reset_disable_b();

static  void                    ao_mikroe_1877_reset_enable_b();

// ----------------------------------------------------------------------------

static  void                    ao_mikroe_1877_wake_disable_b();

static  void                    ao_mikroe_1877_wake_enable_b();

// ----------------------------------------------------------------------------

static  ao_mikroe_1877_i2c_t    ao_mikroe_1877_i2c_b =
{
        .f                      = AO_MIKROE_1877_BAUD_B,

        .f_pbclk                = AO_SYS_CLOCK_I2C2,

        .reg                    = ao_i2c_reg_2(),

        .timeout                = AO_MIKROE_1877_TIMEOUT_B
};

// ----------------------------------------------------------------------------

        ao_task_t               ao_mikroe_1877_task_b;

// ----------------------------------------------------------------------------

static  ao_mikroe_1877_mod_t    ao_mikroe_1877_mod_b =
{
        .i                      = AO_MIKROE_B,

        .i2c                    = &ao_mikroe_1877_i2c_b,

        .int_asserted           = ao_mikroe_1877_int_asserted_b,

        .int_disable            = ao_mikroe_1877_int_disable_b,

        .int_enable             = ao_mikroe_1877_int_enable_b,

        .reset_disable          = ao_mikroe_1877_reset_disable_b,

        .reset_enable           = ao_mikroe_1877_reset_enable_b,

        .task                   = &ao_mikroe_1877_task_b,

        .wake_disable           = ao_mikroe_1877_wake_disable_b,

        .wake_enable            = ao_mikroe_1877_wake_enable_b
};

// ----------------------------------------------------------------------------

void ao_boot_mikroe_1877_b()
{
    // Variables.

    ao_sys_lock_pps_t l;


    // Interrupt.

    ao_ir_int3_falling();


    // Pins.

    // INT3  = G1,  pps.

    // RESET = G13, out, active low.

    // SCL2  = A2.

    // SDA2  = A3.

    // WAKE  = E7,  out, active high.

    ANSELECLR = _ANSELE_ANSE7_MASK;

    TRISECLR = _TRISE_TRISE7_MASK;

    TRISGCLR = _TRISG_TRISG13_MASK;

    ao_sys_unlock_pps(&l);
    {
        INT3R = 0b1100;
    }
    ao_sys_lock_pps(&l);


    // I2C.

    ao_boot_mikroe_1877_i2c(&ao_mikroe_1877_i2c_b);
}

// ----------------------------------------------------------------------------

AO_IR_INT3_ATTRIBUTE
void ao_ir_int3()
{
    ao_mikroe_1877_mod_int(&ao_mikroe_1877_mod_b);

    ao_ir_int3_reply();
}

// ----------------------------------------------------------------------------

bool ao_mikroe_1877_int_asserted_b()
{
    return (PORTG & _PORTG_RG1_MASK) ? false : true;
}

void ao_mikroe_1877_int_disable_b()
{
    ao_ir_int3_disable();
}

void ao_mikroe_1877_int_enable_b()
{
    ao_ir_int3_enable();
}

// ----------------------------------------------------------------------------

void ao_mikroe_1877_reset_disable_b()
{
    LATGSET = _LATG_LATG13_MASK;
}

void ao_mikroe_1877_reset_enable_b()
{
    LATGCLR = _LATG_LATG13_MASK;
}

// ----------------------------------------------------------------------------

void ao_mikroe_1877_wake_disable_b()
{
    LATECLR = _LATE_LATE7_MASK;
}

void ao_mikroe_1877_wake_enable_b()
{
    LATESET = _LATE_LATE7_MASK;
}

// ----------------------------------------------------------------------------

#endif

#if defined AO_MIKROE_1877_C && AO_MIKROE_1877_C

// ----------------------------------------------------------------------------

static  void                    ao_boot_mikroe_1877_c();

// ----------------------------------------------------------------------------

static  bool                    ao_mikroe_1877_int_asserted_c();

static  void                    ao_mikroe_1877_int_disable_c();

static  void                    ao_mikroe_1877_int_enable_c();

// ----------------------------------------------------------------------------

static  void                    ao_mikroe_1877_reset_disable_c();

static  void                    ao_mikroe_1877_reset_enable_c();

// ----------------------------------------------------------------------------

static  void                    ao_mikroe_1877_wake_disable_c();

static  void                    ao_mikroe_1877_wake_enable_c();

// ----------------------------------------------------------------------------

static  ao_mikroe_1877_i2c_t    ao_mikroe_1877_i2c_c =
{
        .f                      = AO_MIKROE_1877_BAUD_C,

        .f_pbclk                = AO_SYS_CLOCK_I2C1,

        .reg                    = ao_i2c_reg_1(),

        .timeout                = AO_MIKROE_1877_TIMEOUT_C
};

// ----------------------------------------------------------------------------

        ao_task_t               ao_mikroe_1877_task_c;

// ----------------------------------------------------------------------------

static  ao_mikroe_1877_mod_t    ao_mikroe_1877_mod_c =
{
        .i                      = AO_MIKROE_C,

        .i2c                    = &ao_mikroe_1877_i2c_c,

        .int_asserted           = ao_mikroe_1877_int_asserted_c,

        .int_disable            = ao_mikroe_1877_int_disable_c,

        .int_enable             = ao_mikroe_1877_int_enable_c,

        .reset_disable          = ao_mikroe_1877_reset_disable_c,

        .reset_enable           = ao_mikroe_1877_reset_enable_c,

        .task                   = &ao_mikroe_1877_task_c,

        .wake_disable           = ao_mikroe_1877_wake_disable_c,

        .wake_enable            = ao_mikroe_1877_wake_enable_c
};

// ----------------------------------------------------------------------------

void ao_boot_mikroe_1877_c()
{
    // Variables.

    ao_sys_lock_pps_t l;


    // Interrupt.

    ao_ir_int1_falling();


    // Pins.

    // INT1  = D5,  pps.

    // RESET = G14, out, active low.

    // SCL1  = A14.

    // SDA1  = A15.

    // WAKE  = A5,  out, active high.

    ANSELACLR = _ANSELA_ANSA5_MASK;

    TRISACLR = _TRISA_TRISA5_MASK;

    TRISGCLR = _TRISG_TRISG14_MASK;

    ao_sys_unlock_pps(&l);
    {
        INT1R = 0b0110;
    }
    ao_sys_lock_pps(&l);


    // I2C.

    ao_boot_mikroe_1877_i2c(&ao_mikroe_1877_i2c_c);
}

// ----------------------------------------------------------------------------

AO_IR_INT1_ATTRIBUTE
void ao_ir_int1()
{
    ao_mikroe_1877_mod_int(&ao_mikroe_1877_mod_c);

    ao_ir_int1_reply();
}

// ----------------------------------------------------------------------------

bool ao_mikroe_1877_int_asserted_c()
{
    return (PORTD & _PORTD_RD5_MASK) ? false : true;
}

void ao_mikroe_1877_int_disable_c()
{
    ao_ir_int1_disable();
}

void ao_mikroe_1877_int_enable_c()
{
    ao_ir_int1_enable();
}

// ----------------------------------------------------------------------------

void ao_mikroe_1877_reset_disable_c()
{
    LATGSET = _LATG_LATG14_MASK;
}

void ao_mikroe_1877_reset_enable_c()
{
    LATGCLR = _LATG_LATG14_MASK;
}

// ----------------------------------------------------------------------------

void ao_mikroe_1877_wake_disable_c()
{
    LATACLR = _LATA_LATA5_MASK;
}

void ao_mikroe_1877_wake_enable_c()
{
    LATASET = _LATA_LATA5_MASK;
}

// ----------------------------------------------------------------------------

#endif

#if defined AO_MIKROE_1877_D && AO_MIKROE_1877_D

// ----------------------------------------------------------------------------

static  void                    ao_boot_mikroe_1877_d();

// ----------------------------------------------------------------------------

static  bool                    ao_mikroe_1877_int_asserted_d();

static  void                    ao_mikroe_1877_int_disable_d();

static  void                    ao_mikroe_1877_int_enable_d();

// ----------------------------------------------------------------------------

static  void                    ao_mikroe_1877_reset_disable_d();

static  void                    ao_mikroe_1877_reset_enable_d();

// ----------------------------------------------------------------------------

static  void                    ao_mikroe_1877_wake_disable_d();

static  void                    ao_mikroe_1877_wake_enable_d();

// ----------------------------------------------------------------------------

static  ao_mikroe_1877_i2c_t    ao_mikroe_1877_i2c_d =
{
        .f                      = AO_MIKROE_1877_BAUD_D,

        .f_pbclk                = AO_SYS_CLOCK_I2C1,

        .reg                    = ao_i2c_reg_1(),

        .timeout                = AO_MIKROE_1877_TIMEOUT_D
};

// ----------------------------------------------------------------------------

        ao_task_t               ao_mikroe_1877_task_d;

// ----------------------------------------------------------------------------

static  ao_mikroe_1877_mod_t    ao_mikroe_1877_mod_d =
{
        .i                      = AO_MIKROE_D,

        .i2c                    = &ao_mikroe_1877_i2c_d,

        .int_asserted           = ao_mikroe_1877_int_asserted_d,

        .int_disable            = ao_mikroe_1877_int_disable_d,

        .int_enable             = ao_mikroe_1877_int_enable_d,

        .reset_disable          = ao_mikroe_1877_reset_disable_d,

        .reset_enable           = ao_mikroe_1877_reset_enable_d,

        .task                   = &ao_mikroe_1877_task_d,

        .wake_disable           = ao_mikroe_1877_wake_disable_d,

        .wake_enable            = ao_mikroe_1877_wake_enable_d
};

// ----------------------------------------------------------------------------

void ao_boot_mikroe_1877_d()
{
    // Variables.

    ao_sys_lock_pps_t l;


    // Interrupt.

    ao_ir_int2_falling();


    // Pins.

    // INT2  = D4,  pps.

    // RESET = G12, out, active low.

    // SCL1  = A14.

    // SDA1  = A15.

    // WAKE  = E6,  out, active high.

    ANSELECLR = _ANSELE_ANSE6_MASK;

    TRISECLR = _TRISE_TRISE6_MASK;

    TRISGCLR = _TRISG_TRISG12_MASK;

    ao_sys_unlock_pps(&l);
    {
        INT2R = 0b0100;
    }
    ao_sys_lock_pps(&l);


    // I2C.

    ao_boot_mikroe_1877_i2c(&ao_mikroe_1877_i2c_d);
}

// ----------------------------------------------------------------------------

AO_IR_INT2_ATTRIBUTE
void ao_ir_int2()
{
    ao_mikroe_1877_mod_int(&ao_mikroe_1877_mod_d);

    ao_ir_int2_reply();
}

// ----------------------------------------------------------------------------

bool ao_mikroe_1877_int_asserted_d()
{
    return (PORTD & _PORTD_RD4_MASK) ? false : true;
}

void ao_mikroe_1877_int_disable_d()
{
    ao_ir_int2_disable();
}

void ao_mikroe_1877_int_enable_d()
{
    ao_ir_int2_enable();
}

// ----------------------------------------------------------------------------

void ao_mikroe_1877_reset_disable_d()
{
    LATGSET = _LATG_LATG12_MASK;
}

void ao_mikroe_1877_reset_enable_d()
{
    LATGCLR = _LATG_LATG12_MASK;
}

// ----------------------------------------------------------------------------

void ao_mikroe_1877_wake_disable_d()
{
    LATECLR = _LATE_LATE6_MASK;
}

void ao_mikroe_1877_wake_enable_d()
{
    LATESET = _LATE_LATE6_MASK;
}

// ----------------------------------------------------------------------------

#endif

#if defined AO_MIKROE_1877

// ----------------------------------------------------------------------------

void ao_boot_mikroe_1877()
{

#if AO_MIKROE_1877_A

    ao_boot_mikroe_1877_a();

#endif

#if AO_MIKROE_1877_B

    ao_boot_mikroe_1877_b();

#endif

#if AO_MIKROE_1877_C

    ao_boot_mikroe_1877_c();

#endif

#if AO_MIKROE_1877_D

    ao_boot_mikroe_1877_d();

#endif

}

// ----------------------------------------------------------------------------

ao_mikroe_1877_mod_t * ao_mikroe_1877_mod(size_t i)
{
    switch (i)
    {

#if AO_MIKROE_1877_A

        case AO_MIKROE_A:

            return &ao_mikroe_1877_mod_a;

#endif

#if AO_MIKROE_1877_B

        case AO_MIKROE_B:

            return &ao_mikroe_1877_mod_b;

#endif

#if AO_MIKROE_1877_C

        case AO_MIKROE_C:

            return &ao_mikroe_1877_mod_c;

#endif

#if AO_MIKROE_1877_D

        case AO_MIKROE_D:

            return &ao_mikroe_1877_mod_d;

#endif

        default:

            ao_assert(false);

            return NULL;
    }
}

// ----------------------------------------------------------------------------

#endif

#if defined AO_MIKROE_2334

// ----------------------------------------------------------------------------

static  void    ao_boot_mikroe_2334_b();

static  void    ao_boot_mikroe_2334_d();

// ----------------------------------------------------------------------------

void ao_boot_mikroe_2334()
{

#if AO_MIKROE_2334_B

    ao_boot_mikroe_2334_b();

#endif

#if AO_MIKROE_2334_D

    ao_boot_mikroe_2334_d();

#endif

}

// ----------------------------------------------------------------------------

void ao_boot_mikroe_2334_b()
{
    // Variables.

    ao_sys_lock_pps_t l;


    // Pins.

    // C1RX = F0, pps.

    // C1TX = F1, pps.

    ao_sys_unlock_pps(&l);
    {
        C1RXR = 0b0100;

        RPF1R = 0b1111;
    }
    ao_sys_lock_pps(&l);
}

void ao_boot_mikroe_2334_d()
{
    // Variables.

    ao_sys_lock_pps_t l;


    // Pins.

    // C2RX = C3, pps.

    // C2TX = C2, pps.

    ANSELCCLR = _ANSELC_ANSC2_MASK;

    ANSELCCLR = _ANSELC_ANSC3_MASK;

    ao_sys_unlock_pps(&l);
    {
        C2RXR = 0b1100;

        RPC2R = 0b1111;
    }
    ao_sys_lock_pps(&l);
}

// ----------------------------------------------------------------------------

#endif

#if defined AO_MIKROE_2674

// ----------------------------------------------------------------------------

static  void    ao_boot_mikroe_2674_a();

static  void    ao_boot_mikroe_2674_b();

static  void    ao_boot_mikroe_2674_c();

static  void    ao_boot_mikroe_2674_d();

// ----------------------------------------------------------------------------

void ao_boot_mikroe_2674()
{

#if AO_MIKROE_2674_A

    ao_boot_mikroe_2674_a();

#endif

#if AO_MIKROE_2674_B

    ao_boot_mikroe_2674_b();

#endif

#if AO_MIKROE_2674_C

    ao_boot_mikroe_2674_c();

#endif

#if AO_MIKROE_2674_D

    ao_boot_mikroe_2674_d();

#endif

}

// ----------------------------------------------------------------------------

void ao_boot_mikroe_2674_a()
{
    // Variables.

    ao_sys_lock_pps_t l;

    ao_uart_reg_t * r = ao_uart_reg_4();


    // Pins.

    // PWREN = C14, in, active high.

    // SLEEP = A0,  in, active low.

    // U4RX  = G9,  pps.

    // U4TX  = E3,  pps.

    ANSELACLR = _ANSELA_ANSA0_MASK;

    ANSELGCLR = _ANSELG_ANSG9_MASK;

    TRISASET = _TRISA_TRISA0_MASK;

    TRISCSET = _TRISC_TRISC14_MASK;

    ao_sys_unlock_pps(&l);
    {
        U4RXR = 0b0001;

        RPE3R = 0b0010;
    }
    ao_sys_lock_pps(&l);


    // UART.

    r->mode.bits.clksel = 0b00;

    r->mode.bits.rtsmd = 0;

    r->mode.bits.rxinv = 0;

    r->mode.bits.uen = 0b00;

    r->sta.bits.utxinv = 0;
}

void ao_boot_mikroe_2674_b()
{
    // Variables.

    ao_sys_lock_pps_t l;

    ao_uart_reg_t * r = ao_uart_reg_3();


    // Pins.

    // PWREN = G0, in, active high.

    // SLEEP = E4, in, active low.

    // U3RX  = F0, pps.

    // U3TX  = F1, pps.

    ANSELECLR = _ANSELE_ANSE4_MASK;

    TRISESET = _TRISE_TRISE4_MASK;

    TRISGSET = _TRISG_TRISG0_MASK;

    ao_sys_unlock_pps(&l);
    {
        U3RXR = 0b0100;

        RPF1R = 0b0001;
    }
    ao_sys_lock_pps(&l);


    // UART.

    r->mode.bits.clksel = 0b00;

    r->mode.bits.rtsmd = 0;

    r->mode.bits.rxinv = 0;

    r->mode.bits.uen = 0b00;

    r->sta.bits.utxinv = 0;
}

void ao_boot_mikroe_2674_c()
{
    // Variables.

    ao_sys_lock_pps_t l;

    ao_uart_reg_t * r = ao_uart_reg_1();


    // Pins.

    // PWREN = G7,  in, active high.

    // SLEEP = D12, in, active low.

    // U1RX  = C1,  pps.

    // U1TX  = E5,  pps.

    ANSELCCLR = _ANSELC_ANSC1_MASK;

    ANSELECLR = _ANSELE_ANSE5_MASK;

    ANSELGCLR = _ANSELG_ANSG7_MASK;

    TRISDSET = _TRISD_TRISD12_MASK;

    TRISGSET = _TRISG_TRISG7_MASK;

    ao_sys_unlock_pps(&l);
    {
        U1RXR = 0b1010;

        RPE5R = 0b0001;
    }
    ao_sys_lock_pps(&l);


    // UART.

    r->mode.bits.clksel = 0b00;

    r->mode.bits.rtsmd = 0;

    r->mode.bits.rxinv = 0;

    r->mode.bits.uen = 0b00;

    r->sta.bits.utxinv = 0;
}

void ao_boot_mikroe_2674_d()
{
    // Variables.

    ao_sys_lock_pps_t l;

    ao_uart_reg_t * r = ao_uart_reg_2();


    // Pins.

    // PWREN = G8,  in, active high.

    // SLEEP = D13, in, active low.

    // U2RX  = C3,  pps.

    // U2TX  = C2,  pps.

    ANSELCCLR = _ANSELC_ANSC2_MASK;

    ANSELCCLR = _ANSELC_ANSC3_MASK;

    ANSELGCLR = _ANSELG_ANSG8_MASK;

    TRISDSET = _TRISD_TRISD13_MASK;

    TRISGSET = _TRISG_TRISG8_MASK;

    ao_sys_unlock_pps(&l);
    {
        U2RXR = 0b1100;

        RPC2R = 0b0010;
    }
    ao_sys_lock_pps(&l);


    // UART.

    r->mode.bits.clksel = 0b00;

    r->mode.bits.rtsmd = 0;

    r->mode.bits.rxinv = 0;

    r->mode.bits.uen = 0b00;

    r->sta.bits.utxinv = 0;
}

// ----------------------------------------------------------------------------

bool ao_mikroe_2674_suspended(size_t i)
{
    switch (i)
    {

#if AO_MIKROE_2674_A

        case AO_MIKROE_A:

            return (PORTC & _PORTC_RC14_MASK) ? true : false;

#endif

#if AO_MIKROE_2674_B

        case AO_MIKROE_B:

            return (PORTG & _PORTG_RG0_MASK) ? true : false;

#endif

#if AO_MIKROE_2674_C

        case AO_MIKROE_C:

            return (PORTG & _PORTG_RG7_MASK) ? true : false;

#endif

#if AO_MIKROE_2674_D

        case AO_MIKROE_D:

            return (PORTG & _PORTG_RG8_MASK) ? true : false;

#endif

        default:

            ao_assert(false);

            return false;
    }
}

// ----------------------------------------------------------------------------

#endif

#if defined AO_MIKROE_2935_A && AO_MIKROE_2935_A

// ----------------------------------------------------------------------------

static  void                    ao_boot_mikroe_2935_a();

// ----------------------------------------------------------------------------

static  void                    ao_mikroe_2935_spi_begin_a();

static  void                    ao_mikroe_2935_spi_end_a();

// ----------------------------------------------------------------------------

static  ao_mikroe_2935_spi_t    ao_mikroe_2935_spi_a =
{
        .begin                  = ao_mikroe_2935_spi_begin_a,

        .end                    = ao_mikroe_2935_spi_end_a,

        .f                      = AO_MIKROE_2935_BAUD_A,

        .f_pbclk                = AO_SYS_CLOCK_SPI2,

        .reg                    = ao_spi_reg_2()
};

// ----------------------------------------------------------------------------

        ao_task_t               ao_mikroe_2935_task_a;

// ----------------------------------------------------------------------------

static  ao_mikroe_2935_mod_t    ao_mikroe_2935_mod_a =
{
        .i                      = AO_MIKROE_A,

        .period                 = AO_MIKROE_2935_PERIOD_A,

        .repetitions_xy         = AO_MIKROE_2935_REPETITIONS_XY_A,

        .repetitions_z          = AO_MIKROE_2935_REPETITIONS_Z_A,

        .spi                    = &ao_mikroe_2935_spi_a,

        .task                   = &ao_mikroe_2935_task_a
};

// ----------------------------------------------------------------------------

void ao_boot_mikroe_2935_a()
{
    // Variables.

    ao_sys_lock_pps_t l;


    // Pins.

    // SCK2 = G6.

    // SDI2 = C4, pps.

    // SDO2 = B5, pps.

    // SS2  = A0, out, active low.

    ANSELACLR = _ANSELA_ANSA0_MASK;

    ANSELBCLR = _ANSELB_ANSB5_MASK;

    ANSELCCLR = _ANSELC_ANSC4_MASK;

    ANSELGCLR = _ANSELG_ANSG6_MASK;

    TRISACLR = _TRISA_TRISA0_MASK;

    ao_sys_unlock_pps(&l);
    {
        SDI2R = 0b1010;

        RPB5R = 0b0110;
    }
    ao_sys_lock_pps(&l);


    // Device.

    ao_boot_mikroe_2935_spi(&ao_mikroe_2935_spi_a);
}

// ----------------------------------------------------------------------------

void ao_mikroe_2935_spi_begin_a()
{
    LATACLR = _LATA_LATA0_MASK;
}

void ao_mikroe_2935_spi_end_a()
{
    LATASET = _LATA_LATA0_MASK;
}

// ----------------------------------------------------------------------------

#endif

#if defined AO_MIKROE_2935_B && AO_MIKROE_2935_B

// ----------------------------------------------------------------------------

static  void                    ao_boot_mikroe_2935_b();

// ----------------------------------------------------------------------------

static  void                    ao_mikroe_2935_spi_begin_b();

static  void                    ao_mikroe_2935_spi_end_b();

// ----------------------------------------------------------------------------

static  ao_mikroe_2935_spi_t    ao_mikroe_2935_spi_b =
{
        .begin                  = ao_mikroe_2935_spi_begin_b,

        .end                    = ao_mikroe_2935_spi_end_b,

        .f                      = AO_MIKROE_2935_BAUD_B,

        .f_pbclk                = AO_SYS_CLOCK_SPI2,

        .reg                    = ao_spi_reg_2()
};

// ----------------------------------------------------------------------------

        ao_task_t               ao_mikroe_2935_task_b;

// ----------------------------------------------------------------------------

static  ao_mikroe_2935_mod_t    ao_mikroe_2935_mod_b =
{
        .i                      = AO_MIKROE_B,

        .period                 = AO_MIKROE_2935_PERIOD_B,

        .repetitions_xy         = AO_MIKROE_2935_REPETITIONS_XY_B,

        .repetitions_z          = AO_MIKROE_2935_REPETITIONS_Z_B,

        .spi                    = &ao_mikroe_2935_spi_b,

        .task                   = &ao_mikroe_2935_task_b
};

// ----------------------------------------------------------------------------

void ao_boot_mikroe_2935_b()
{
    // Variables.

    ao_sys_lock_pps_t l;


    // Pins.

    // SCK2 = G6.

    // SDI2 = C4, pps.

    // SDO2 = B5, pps.

    // SS2  = E4, out, active low.

    ANSELBCLR = _ANSELB_ANSB5_MASK;

    ANSELCCLR = _ANSELC_ANSC4_MASK;

    ANSELECLR = _ANSELE_ANSE4_MASK;

    ANSELGCLR = _ANSELG_ANSG6_MASK;

    TRISECLR = _TRISE_TRISE4_MASK;

    ao_sys_unlock_pps(&l);
    {
        SDI2R = 0b1010;

        RPB5R = 0b0110;
    }
    ao_sys_lock_pps(&l);


    // Device.

    ao_boot_mikroe_2935_spi(&ao_mikroe_2935_spi_b);
}

// ----------------------------------------------------------------------------

void ao_mikroe_2935_spi_begin_b()
{
    LATECLR = _LATE_LATE4_MASK;
}

void ao_mikroe_2935_spi_end_b()
{
    LATESET = _LATE_LATE4_MASK;
}

// ----------------------------------------------------------------------------

#endif

#if defined AO_MIKROE_2935_C && AO_MIKROE_2935_C

// ----------------------------------------------------------------------------

static  void                    ao_boot_mikroe_2935_c();

// ----------------------------------------------------------------------------

static  void                    ao_mikroe_2935_spi_begin_c();

static  void                    ao_mikroe_2935_spi_end_c();

// ----------------------------------------------------------------------------

static  ao_mikroe_2935_spi_t    ao_mikroe_2935_spi_c =
{
        .begin                  = ao_mikroe_2935_spi_begin_c,

        .end                    = ao_mikroe_2935_spi_end_c,

        .f                      = AO_MIKROE_2935_BAUD_C,

        .f_pbclk                = AO_SYS_CLOCK_SPI1,

        .reg                    = ao_spi_reg_1()
};

// ----------------------------------------------------------------------------

        ao_task_t               ao_mikroe_2935_task_c;

// ----------------------------------------------------------------------------

static  ao_mikroe_2935_mod_t    ao_mikroe_2935_mod_c =
{
        .i                      = AO_MIKROE_C,

        .period                 = AO_MIKROE_2935_PERIOD_C,

        .repetitions_xy         = AO_MIKROE_2935_REPETITIONS_XY_C,

        .repetitions_z          = AO_MIKROE_2935_REPETITIONS_Z_C,

        .spi                    = &ao_mikroe_2935_spi_c,

        .task                   = &ao_mikroe_2935_task_c
};

// ----------------------------------------------------------------------------

void ao_boot_mikroe_2935_c()
{
    // Variables.

    ao_sys_lock_pps_t l;


    // Pins.

    // SCK1 = D1.

    // SDI1 = D2, pps.

    // SDO1 = D3, pps.

    // SS1  = D12, out, active low.

    TRISDCLR = _TRISD_TRISD12_MASK;

    ao_sys_unlock_pps(&l);
    {
        SDI1R = 0b0000;

        RPD3R = 0b0101;
    }
    ao_sys_lock_pps(&l);


    // Device.

    ao_boot_mikroe_2935_spi(&ao_mikroe_2935_spi_c);
}

// ----------------------------------------------------------------------------

void ao_mikroe_2935_spi_begin_c()
{
    LATDCLR = _LATD_LATD12_MASK;
}

void ao_mikroe_2935_spi_end_c()
{
    LATDSET = _LATD_LATD12_MASK;
}

// ----------------------------------------------------------------------------

#endif

#if defined AO_MIKROE_2935_D && AO_MIKROE_2935_D

// ----------------------------------------------------------------------------

static  void                    ao_boot_mikroe_2935_d();

// ----------------------------------------------------------------------------

static  void                    ao_mikroe_2935_spi_begin_d();

static  void                    ao_mikroe_2935_spi_end_d();

// ----------------------------------------------------------------------------

static  ao_mikroe_2935_spi_t    ao_mikroe_2935_spi_d =
{
        .begin                  = ao_mikroe_2935_spi_begin_d,

        .end                    = ao_mikroe_2935_spi_end_d,

        .f                      = AO_MIKROE_2935_BAUD_D,

        .f_pbclk                = AO_SYS_CLOCK_SPI1,

        .reg                    = ao_spi_reg_1()
};

// ----------------------------------------------------------------------------

        ao_task_t               ao_mikroe_2935_task_d;

// ----------------------------------------------------------------------------

static  ao_mikroe_2935_mod_t    ao_mikroe_2935_mod_d =
{
        .i                      = AO_MIKROE_D,

        .period                 = AO_MIKROE_2935_PERIOD_D,

        .repetitions_xy         = AO_MIKROE_2935_REPETITIONS_XY_D,

        .repetitions_z          = AO_MIKROE_2935_REPETITIONS_Z_D,

        .spi                    = &ao_mikroe_2935_spi_d,

        .task                   = &ao_mikroe_2935_task_d
};

// ----------------------------------------------------------------------------

void ao_boot_mikroe_2935_d()
{
    // Variables.

    ao_sys_lock_pps_t l;


    // Pins.

    // SCK1 = D1.

    // SDI1 = D2, pps.

    // SDO1 = D3, pps.

    // SS1  = D13, out, active low.

    TRISDCLR = _TRISD_TRISD13_MASK;

    ao_sys_unlock_pps(&l);
    {
        SDI1R = 0b0000;

        RPD3R = 0b0101;
    }
    ao_sys_lock_pps(&l);


    // Device.

    ao_boot_mikroe_2935_spi(&ao_mikroe_2935_spi_d);
}

// ----------------------------------------------------------------------------

void ao_mikroe_2935_spi_begin_d()
{
    LATDCLR = _LATD_LATD13_MASK;
}

void ao_mikroe_2935_spi_end_d()
{
    LATDSET = _LATD_LATD13_MASK;
}

// ----------------------------------------------------------------------------

#endif

#if defined AO_MIKROE_2935

// ----------------------------------------------------------------------------

void ao_boot_mikroe_2935()
{

#if AO_MIKROE_2935_A

    ao_boot_mikroe_2935_a();

#endif

#if AO_MIKROE_2935_B

    ao_boot_mikroe_2935_b();

#endif

#if AO_MIKROE_2935_C

    ao_boot_mikroe_2935_c();

#endif

#if AO_MIKROE_2935_D

    ao_boot_mikroe_2935_d();

#endif

}

// ----------------------------------------------------------------------------

ao_mikroe_2935_mod_t * ao_mikroe_2935_mod(size_t i)
{
    switch (i)
    {

#if AO_MIKROE_2935_A

        case AO_MIKROE_A:

            return &ao_mikroe_2935_mod_a;

#endif

#if AO_MIKROE_2935_B

        case AO_MIKROE_B:

            return &ao_mikroe_2935_mod_b;

#endif

#if AO_MIKROE_2935_C

        case AO_MIKROE_C:

            return &ao_mikroe_2935_mod_c;

#endif

#if AO_MIKROE_2935_D

        case AO_MIKROE_D:

            return &ao_mikroe_2935_mod_d;

#endif

        default:

            ao_assert(false);

            return NULL;
    }
}

// ----------------------------------------------------------------------------

#endif

#if defined AO_MIKROE_2950_A && AO_MIKROE_2950_A

// ----------------------------------------------------------------------------

static  void                    ao_boot_mikroe_2950_a();

// ----------------------------------------------------------------------------

static  ao_mikroe_2950_i2c_t    ao_mikroe_2950_i2c_a =
{
        .f                      = AO_MIKROE_2950_BAUD_A,

        .f_pbclk                = AO_SYS_CLOCK_I2C2,

        .reg                    = ao_i2c_reg_2()
};

// ----------------------------------------------------------------------------

void ao_boot_mikroe_2950_a()
{
    // Pins.

    // SCL2 = A2.

    // SDA2 = A3.


    // Device.

    ao_boot_mikroe_2950_i2c(&ao_mikroe_2950_i2c_a);
}

// ----------------------------------------------------------------------------

#endif

#if defined AO_MIKROE_2950_B && AO_MIKROE_2950_B

// ----------------------------------------------------------------------------

static  void                    ao_boot_mikroe_2950_b();

// ----------------------------------------------------------------------------

static  ao_mikroe_2950_i2c_t    ao_mikroe_2950_i2c_b =
{
        .f                      = AO_MIKROE_2950_BAUD_B,

        .f_pbclk                = AO_SYS_CLOCK_I2C2,

        .reg                    = ao_i2c_reg_2()
};

// ----------------------------------------------------------------------------

void ao_boot_mikroe_2950_b()
{
    // Pins.

    // SCL2 = A2.

    // SDA2 = A3.


    // Device.

    ao_boot_mikroe_2950_i2c(&ao_mikroe_2950_i2c_b);
}

// ----------------------------------------------------------------------------

#endif

#if defined AO_MIKROE_2950_C && AO_MIKROE_2950_C

// ----------------------------------------------------------------------------

static  void                    ao_boot_mikroe_2950_c();

// ----------------------------------------------------------------------------

static  ao_mikroe_2950_i2c_t    ao_mikroe_2950_i2c_c =
{
        .f                      = AO_MIKROE_2950_BAUD_C,

        .f_pbclk                = AO_SYS_CLOCK_I2C1,

        .reg                    = ao_i2c_reg_1()
};

// ----------------------------------------------------------------------------

void ao_boot_mikroe_2950_c()
{
    // Pins.

    // SCL1 = A14.

    // SDA1 = A15.


    // Device.

    ao_boot_mikroe_2950_i2c(&ao_mikroe_2950_i2c_c);
}

// ----------------------------------------------------------------------------

#endif

#if defined AO_MIKROE_2950_D && AO_MIKROE_2950_D

// ----------------------------------------------------------------------------

static  void                    ao_boot_mikroe_2950_d();

// ----------------------------------------------------------------------------

static  ao_mikroe_2950_i2c_t    ao_mikroe_2950_i2c_d =
{
        .f                      = AO_MIKROE_2950_BAUD_D,

        .f_pbclk                = AO_SYS_CLOCK_I2C1,

        .reg                    = ao_i2c_reg_1()
};

// ----------------------------------------------------------------------------

void ao_boot_mikroe_2950_d()
{
    // Pins.

    // SCL1 = A14.

    // SDA1 = A15.


    // Device.

    ao_boot_mikroe_2950_i2c(&ao_mikroe_2950_i2c_d);
}

// ----------------------------------------------------------------------------

#endif

#if defined AO_MIKROE_2950

// ----------------------------------------------------------------------------

void ao_boot_mikroe_2950()
{

#if AO_MIKROE_2950_A

    ao_boot_mikroe_2950_a();

#endif

#if AO_MIKROE_2950_B

    ao_boot_mikroe_2950_b();

#endif

#if AO_MIKROE_2950_C

    ao_boot_mikroe_2950_c();

#endif

#if AO_MIKROE_2950_D

    ao_boot_mikroe_2950_d();

#endif

}

// ----------------------------------------------------------------------------

void * ao_mikroe_2950_i2c(size_t i)
{
    switch (i)
    {

#if AO_MIKROE_2950_A

        case AO_MIKROE_A:

            return &ao_mikroe_2950_i2c_a;

#endif

#if AO_MIKROE_2950_B

        case AO_MIKROE_B:

            return &ao_mikroe_2950_i2c_b;

#endif

#if AO_MIKROE_2950_C

        case AO_MIKROE_C:

            return &ao_mikroe_2950_i2c_c;

#endif

#if AO_MIKROE_2950_D

        case AO_MIKROE_D:

            return &ao_mikroe_2950_i2c_d;

#endif

        default:

            ao_assert(false);

            return NULL;
    }
}

// ----------------------------------------------------------------------------

#endif

#if defined AO_MIKROE_3063

// ----------------------------------------------------------------------------

static  void    ao_boot_mikroe_3063_a();

static  void    ao_boot_mikroe_3063_b();

static  void    ao_boot_mikroe_3063_c();

static  void    ao_boot_mikroe_3063_d();

// ----------------------------------------------------------------------------

void ao_boot_mikroe_3063()
{

#if AO_MIKROE_3063_A

    ao_boot_mikroe_3063_a();

#endif

#if AO_MIKROE_3063_B

    ao_boot_mikroe_3063_b();

#endif

#if AO_MIKROE_3063_C

    ao_boot_mikroe_3063_c();

#endif

#if AO_MIKROE_3063_D

    ao_boot_mikroe_3063_d();

#endif

}

// ----------------------------------------------------------------------------

void ao_boot_mikroe_3063_a()
{
    // Variables.

    ao_sys_lock_pps_t l;

    ao_uart_reg_t * r = ao_uart_reg_4();


    // Pins.

    // RESET   = E2,  out, active low.

    // SUSPEND = B11, in,  active high.

    // U4RX    = G9,  pps.

    // U4TX    = E3,  pps.

    // WAKEUP  = C14, out, active low.

    ANSELBCLR = _ANSELB_ANSB11_MASK;

    ANSELGCLR = _ANSELG_ANSG9_MASK;

    TRISBSET = _TRISB_TRISB11_MASK;

    TRISCCLR = _TRISC_TRISC14_MASK;

    TRISECLR = _TRISE_TRISE2_MASK;

    ao_sys_unlock_pps(&l);
    {
        U4RXR = 0b0001;

        RPE3R = 0b0010;
    }
    ao_sys_lock_pps(&l);


    // Clickboard.

    ao_mikroe_3063_reset_disable(AO_MIKROE_A);

    ao_mikroe_3063_wakeup_disable(AO_MIKROE_A);


    // UART.

    r->mode.bits.clksel = 0b00;

    r->mode.bits.rtsmd = 0;

    r->mode.bits.rxinv = 0;

    r->mode.bits.uen = 0b00;

    r->sta.bits.utxinv = 0;
}

void ao_boot_mikroe_3063_b()
{
    // Variables.

    ao_sys_lock_pps_t l;

    ao_uart_reg_t * r = ao_uart_reg_3();


    // Pins.

    // RESET   = G13, out, active low.

    // SUSPEND = E7,  in,  active high.

    // U3RX    = F0,  pps.

    // U3TX    = F1,  pps.

    // WAKEUP  = G0,  out, active low.

    ANSELECLR = _ANSELE_ANSE7_MASK;

    TRISESET = _TRISE_TRISE7_MASK;

    TRISGCLR = _TRISG_TRISG0_MASK;

    TRISGCLR = _TRISG_TRISG13_MASK;

    ao_sys_unlock_pps(&l);
    {
        U3RXR = 0b0100;

        RPF1R = 0b0001;
    }
    ao_sys_lock_pps(&l);


    // Clickboard.

    ao_mikroe_3063_reset_disable(AO_MIKROE_B);

    ao_mikroe_3063_wakeup_disable(AO_MIKROE_B);


    // UART.

    r->mode.bits.clksel = 0b00;

    r->mode.bits.rtsmd = 0;

    r->mode.bits.rxinv = 0;

    r->mode.bits.uen = 0b00;

    r->sta.bits.utxinv = 0;
}

void ao_boot_mikroe_3063_c()
{
    // Variables.

    ao_sys_lock_pps_t l;

    ao_uart_reg_t * r = ao_uart_reg_1();


    // Pins.

    // RESET   = G14, out, active low.

    // SUSPEND = A5,  in,  active high.

    // U1RX    = C1,  pps.

    // U1TX    = E5,  pps.

    // WAKEUP  = G7,  out, active low.

    ANSELACLR = _ANSELA_ANSA5_MASK;

    ANSELCCLR = _ANSELC_ANSC1_MASK;

    ANSELECLR = _ANSELE_ANSE5_MASK;

    ANSELGCLR = _ANSELG_ANSG7_MASK;

    TRISASET = _TRISA_TRISA5_MASK;

    TRISGCLR = _TRISG_TRISG7_MASK;

    TRISGCLR = _TRISG_TRISG14_MASK;

    ao_sys_unlock_pps(&l);
    {
        U1RXR = 0b1010;

        RPE5R = 0b0001;
    }
    ao_sys_lock_pps(&l);


    // Clickboard.

    ao_mikroe_3063_reset_disable(AO_MIKROE_C);

    ao_mikroe_3063_wakeup_disable(AO_MIKROE_C);


    // UART.

    r->mode.bits.clksel = 0b00;

    r->mode.bits.rtsmd = 0;

    r->mode.bits.rxinv = 0;

    r->mode.bits.uen = 0b00;

    r->sta.bits.utxinv = 0;
}

void ao_boot_mikroe_3063_d()
{
    // Variables.

    ao_sys_lock_pps_t l;

    ao_uart_reg_t * r = ao_uart_reg_2();


    // Pins.

    // RESET   = G12, out, active low.

    // SUSPEND = E6,  in,  active high.

    // U2RX    = C3,  pps.

    // U2TX    = C2,  pps.

    // WAKEUP  = G8,  out, active low.

    ANSELCCLR = _ANSELC_ANSC2_MASK;

    ANSELCCLR = _ANSELC_ANSC3_MASK;

    ANSELECLR = _ANSELE_ANSE6_MASK;

    ANSELGCLR = _ANSELG_ANSG8_MASK;

    TRISESET = _TRISE_TRISE6_MASK;

    TRISGCLR = _TRISG_TRISG8_MASK;

    TRISGCLR = _TRISG_TRISG12_MASK;

    ao_sys_unlock_pps(&l);
    {
        U2RXR = 0b1100;

        RPC2R = 0b0010;
    }
    ao_sys_lock_pps(&l);


    // Clickboard.

    ao_mikroe_3063_reset_disable(AO_MIKROE_D);

    ao_mikroe_3063_wakeup_disable(AO_MIKROE_D);


    // UART.

    r->mode.bits.clksel = 0b00;

    r->mode.bits.rtsmd = 0;

    r->mode.bits.rxinv = 0;

    r->mode.bits.uen = 0b00;

    r->sta.bits.utxinv = 0;
}

// ----------------------------------------------------------------------------

void ao_mikroe_3063_reset_disable(size_t i)
{
    switch (i)
    {

#if AO_MIKROE_3063_A

        case AO_MIKROE_A:

            LATESET = _LATE_LATE2_MASK;

            break;

#endif

#if AO_MIKROE_3063_B

        case AO_MIKROE_B:

            LATGSET = _LATG_LATG13_MASK;

            break;

#endif

#if AO_MIKROE_3063_C

        case AO_MIKROE_C:

            LATGSET = _LATG_LATG14_MASK;

            break;

#endif

#if AO_MIKROE_3063_D

        case AO_MIKROE_D:

            LATGSET = _LATG_LATG12_MASK;

            break;

#endif

        default:

            ao_assert(false);

            break;
    }
}

void ao_mikroe_3063_reset_enable(size_t i)
{
    switch (i)
    {

#if AO_MIKROE_3063_A

        case AO_MIKROE_A:

            LATECLR = _LATE_LATE2_MASK;

            break;

#endif

#if AO_MIKROE_3063_B

        case AO_MIKROE_B:

            LATGCLR = _LATG_LATG13_MASK;

            break;

#endif

#if AO_MIKROE_3063_C

        case AO_MIKROE_C:

            LATGCLR = _LATG_LATG14_MASK;

            break;

#endif

#if AO_MIKROE_3063_D

        case AO_MIKROE_D:

            LATGCLR = _LATG_LATG12_MASK;

            break;

#endif

        default:

            ao_assert(false);

            break;
    }
}

// ----------------------------------------------------------------------------

bool ao_mikroe_3063_suspended(size_t i)
{
    switch (i)
    {

#if AO_MIKROE_3063_A

        case AO_MIKROE_A:

            return (PORTB & _PORTB_RB11_MASK) ? true : false;

#endif

#if AO_MIKROE_3063_B

        case AO_MIKROE_B:

            return (PORTE & _PORTE_RE7_MASK) ? true : false;

#endif

#if AO_MIKROE_3063_C

        case AO_MIKROE_C:

            return (PORTA & _PORTA_RA5_MASK) ? true : false;

#endif

#if AO_MIKROE_3063_D

        case AO_MIKROE_D:

            return (PORTE & _PORTE_RE6_MASK) ? true : false;

#endif

        default:

            ao_assert(false);

            return false;
    }
}

// ----------------------------------------------------------------------------

void ao_mikroe_3063_wakeup_disable(size_t i)
{
    switch (i)
    {

#if AO_MIKROE_3063_A

        case AO_MIKROE_A:

            LATCSET = _LATC_LATC14_MASK;

            break;

#endif

#if AO_MIKROE_3063_B

        case AO_MIKROE_B:

            LATGSET = _LATG_LATG0_MASK;

            break;

#endif

#if AO_MIKROE_3063_C

        case AO_MIKROE_C:

            LATGSET = _LATG_LATG7_MASK;

            break;

#endif

#if AO_MIKROE_3063_D

        case AO_MIKROE_D:

            LATGSET = _LATG_LATG8_MASK;

            break;

#endif

        default:

            ao_assert(false);

            break;
    }
}

void ao_mikroe_3063_wakeup_enable(size_t i)
{
    switch (i)
    {

#if AO_MIKROE_3063_A

        case AO_MIKROE_A:

            LATCCLR = _LATC_LATC14_MASK;

            break;

#endif

#if AO_MIKROE_3063_B

        case AO_MIKROE_B:

            LATGCLR = _LATG_LATG0_MASK;

            break;

#endif

#if AO_MIKROE_3063_C

        case AO_MIKROE_C:

            LATGCLR = _LATG_LATG7_MASK;

            break;

#endif

#if AO_MIKROE_3063_D

        case AO_MIKROE_D:

            LATGCLR = _LATG_LATG8_MASK;

            break;

#endif

        default:

            ao_assert(false);

            break;
    }
}

// ----------------------------------------------------------------------------

#endif

#if defined AO_MIKROE_4186_A && AO_MIKROE_4186_A

// ----------------------------------------------------------------------------

static  void                    ao_boot_mikroe_4186_a();

// ----------------------------------------------------------------------------

static  ao_mikroe_4186_i2c_t    ao_mikroe_4186_i2c_a =
{
        .f                      = AO_MIKROE_4186_BAUD_A,

        .f_pbclk                = AO_SYS_CLOCK_I2C2,

        .reg                    = ao_i2c_reg_2(),

        .timeout                = AO_MIKROE_4186_TIMEOUT_A
};

// ----------------------------------------------------------------------------

void ao_boot_mikroe_4186_a()
{
    // Variables.

    ao_sys_lock_pps_t l;


    // Interrupt.

    ao_ir_int2_falling();


    // Pins.

    // INT2  = D9,  pps.

    // RESET = E2,  out, active low.

    // SCL2  = A2.

    // SDA2  = A3.

    TRISECLR = _TRISE_TRISE2_MASK;


    // Pins.

    ao_mikroe_4186_reset_disable(AO_MIKROE_A);


    // Pins.

    ao_sys_unlock_pps(&l);
    {
        INT2R = 0b0000;
    }
    ao_sys_lock_pps(&l);


    // I2C.

    ao_boot_mikroe_4186_i2c(&ao_mikroe_4186_i2c_a);
}

// ----------------------------------------------------------------------------

AO_IR_INT2_ATTRIBUTE
void ao_ir_int2()
{
    ao_ir_stack_func1((void *) AO_MIKROE_A, (ao_func1_t) ao_mikroe_4186_int);

    ao_ir_int2_reply();
}

// ----------------------------------------------------------------------------

#endif

#if defined AO_MIKROE_4186_B && AO_MIKROE_4186_B

// ----------------------------------------------------------------------------

static  void                    ao_boot_mikroe_4186_b();

// ----------------------------------------------------------------------------

static  ao_mikroe_4186_i2c_t    ao_mikroe_4186_i2c_b =
{
        .f                      = AO_MIKROE_4186_BAUD_B,

        .f_pbclk                = AO_SYS_CLOCK_I2C2,

        .reg                    = ao_i2c_reg_2(),

        .timeout                = AO_MIKROE_4186_TIMEOUT_B
};

// ----------------------------------------------------------------------------

void ao_boot_mikroe_4186_b()
{
    // Variables.

    ao_sys_lock_pps_t l;


    // Interrupt.

    ao_ir_int3_falling();


    // Pins.

    // INT3  = G1,  pps.

    // RESET = G13, out, active low.

    // SCL2  = A2.

    // SDA2  = A3.

    TRISGCLR = _TRISG_TRISG13_MASK;


    // Pins.

    ao_mikroe_4186_reset_disable(AO_MIKROE_B);


    // Pins.

    ao_sys_unlock_pps(&l);
    {
        INT3R = 0b1100;
    }
    ao_sys_lock_pps(&l);


    // I2C.

    ao_boot_mikroe_4186_i2c(&ao_mikroe_4186_i2c_b);
}

// ----------------------------------------------------------------------------

AO_IR_INT3_ATTRIBUTE
void ao_ir_int3()
{
    ao_ir_stack_func1((void *) AO_MIKROE_B, (ao_func1_t) ao_mikroe_4186_int);

    ao_ir_int3_reply();
}

// ----------------------------------------------------------------------------

#endif

#if defined AO_MIKROE_4186_C && AO_MIKROE_4186_C

// ----------------------------------------------------------------------------

static  void                    ao_boot_mikroe_4186_c();

// ----------------------------------------------------------------------------

static  ao_mikroe_4186_i2c_t    ao_mikroe_4186_i2c_c =
{
        .f                      = AO_MIKROE_4186_BAUD_C,

        .f_pbclk                = AO_SYS_CLOCK_I2C1,

        .reg                    = ao_i2c_reg_1(),

        .timeout                = AO_MIKROE_4186_TIMEOUT_C
};

// ----------------------------------------------------------------------------

void ao_boot_mikroe_4186_c()
{
    // Variables.

    ao_sys_lock_pps_t l;


    // Interrupt.

    ao_ir_int1_falling();


    // Pins.

    // INT1  = D5,  pps.

    // RESET = G14, out, active low.

    // SCL1  = A14.

    // SDA1  = A15.

    TRISGCLR = _TRISG_TRISG14_MASK;


    // Pins.

    ao_mikroe_4186_reset_disable(AO_MIKROE_C);


    // Pins.

    ao_sys_unlock_pps(&l);
    {
        INT1R = 0b0110;
    }
    ao_sys_lock_pps(&l);


    // I2C.

    ao_boot_mikroe_4186_i2c(&ao_mikroe_4186_i2c_c);
}

// ----------------------------------------------------------------------------

AO_IR_INT1_ATTRIBUTE
void ao_ir_int1()
{
    ao_ir_stack_func1((void *) AO_MIKROE_C, (ao_func1_t) ao_mikroe_4186_int);

    ao_ir_int1_reply();
}

// ----------------------------------------------------------------------------

#endif

#if defined AO_MIKROE_4186_D && AO_MIKROE_4186_D

// ----------------------------------------------------------------------------

static  void                    ao_boot_mikroe_4186_d();

// ----------------------------------------------------------------------------

static  ao_mikroe_4186_i2c_t    ao_mikroe_4186_i2c_d =
{
        .f                      = AO_MIKROE_4186_BAUD_D,

        .f_pbclk                = AO_SYS_CLOCK_I2C1,

        .reg                    = ao_i2c_reg_1(),

        .timeout                = AO_MIKROE_4186_TIMEOUT_D
};

// ----------------------------------------------------------------------------

void ao_boot_mikroe_4186_d()
{
    // Variables.

    ao_sys_lock_pps_t l;


    // Interrupt.

    ao_ir_int2_falling();


    // Pins.

    // INT2  = D4,  pps.

    // RESET = G12, out, active low.

    // SCL1  = A14.

    // SDA1  = A15.

    TRISGCLR = _TRISG_TRISG12_MASK;


    // Pins.

    ao_mikroe_4186_reset_disable(AO_MIKROE_D);


    // Pins.

    ao_sys_unlock_pps(&l);
    {
        INT2R = 0b0100;
    }
    ao_sys_lock_pps(&l);


    // I2C.

    ao_boot_mikroe_4186_i2c(&ao_mikroe_4186_i2c_d);
}

// ----------------------------------------------------------------------------

AO_IR_INT2_ATTRIBUTE
void ao_ir_int2()
{
    ao_ir_stack_func1((void *) AO_MIKROE_D, (ao_func1_t) ao_mikroe_4186_int);

    ao_ir_int2_reply();
}

// ----------------------------------------------------------------------------

#endif

#if defined AO_MIKROE_4186

// ----------------------------------------------------------------------------

void ao_boot_mikroe_4186()
{

#if AO_MIKROE_4186_A

    ao_boot_mikroe_4186_a();

#endif

#if AO_MIKROE_4186_B

    ao_boot_mikroe_4186_b();

#endif

#if AO_MIKROE_4186_C

    ao_boot_mikroe_4186_c();

#endif

#if AO_MIKROE_4186_D

    ao_boot_mikroe_4186_d();

#endif

}

// ----------------------------------------------------------------------------

ao_mikroe_4186_i2c_t * ao_mikroe_4186_i2c(size_t i)
{
    switch (i)
    {

#if AO_MIKROE_4186_A

        case AO_MIKROE_A:

            return &ao_mikroe_4186_i2c_a;

#endif

#if AO_MIKROE_4186_B

        case AO_MIKROE_B:

            return &ao_mikroe_4186_i2c_b;

#endif

#if AO_MIKROE_4186_C

        case AO_MIKROE_C:

            return &ao_mikroe_4186_i2c_c;

#endif

#if AO_MIKROE_4186_D

        case AO_MIKROE_D:

            return &ao_mikroe_4186_i2c_d;

#endif

        default:

            ao_assert(false);

            return NULL;
    }
}

// ----------------------------------------------------------------------------

void ao_mikroe_4186_int_disable(size_t i)
{
    switch (i)
    {

#if AO_MIKROE_4186_A

        case AO_MIKROE_A:

            ao_ir_int2_disable();

            break;

#endif

#if AO_MIKROE_4186_B

        case AO_MIKROE_B:

            ao_ir_int3_disable();

            break;

#endif

#if AO_MIKROE_4186_C

        case AO_MIKROE_C:

            ao_ir_int1_disable();

            break;

#endif

#if AO_MIKROE_4186_D

        case AO_MIKROE_D:

            ao_ir_int2_disable();

            break;

#endif

        default:

            ao_assert(false);

            break;
    }
}

void ao_mikroe_4186_int_enable(size_t i)
{
    switch (i)
    {

#if AO_MIKROE_4186_A

        case AO_MIKROE_A:

            ao_ir_int2_enable();

            break;

#endif

#if AO_MIKROE_4186_B

        case AO_MIKROE_B:

            ao_ir_int3_enable();

            break;

#endif

#if AO_MIKROE_4186_C

        case AO_MIKROE_C:

            ao_ir_int1_enable();

            break;

#endif

#if AO_MIKROE_4186_D

        case AO_MIKROE_D:

            ao_ir_int2_enable();

            break;

#endif

        default:

            ao_assert(false);

            break;
    }
}

// ----------------------------------------------------------------------------

void ao_mikroe_4186_reset_disable(size_t i)
{
    switch (i)
    {

#if AO_MIKROE_4186_A

        case AO_MIKROE_A:

            LATESET = _LATE_LATE2_MASK;

            break;

#endif

#if AO_MIKROE_4186_B

        case AO_MIKROE_B:

            LATGSET = _LATG_LATG13_MASK;

            break;

#endif

#if AO_MIKROE_4186_C

        case AO_MIKROE_C:

            LATGSET = _LATG_LATG14_MASK;

            break;

#endif

#if AO_MIKROE_4186_D

        case AO_MIKROE_D:

            LATGSET = _LATG_LATG12_MASK;

            break;

#endif

        default:

            ao_assert(false);

            break;
    }
}

void ao_mikroe_4186_reset_enable(size_t i)
{
    switch (i)
    {

#if AO_MIKROE_4186_A

        case AO_MIKROE_A:

            LATECLR = _LATE_LATE2_MASK;

            break;

#endif

#if AO_MIKROE_4186_B

        case AO_MIKROE_B:

            LATGCLR = _LATG_LATG13_MASK;

            break;

#endif

#if AO_MIKROE_4186_C

        case AO_MIKROE_C:

            LATGCLR = _LATG_LATG14_MASK;

            break;

#endif

#if AO_MIKROE_4186_D

        case AO_MIKROE_D:

            LATGCLR = _LATG_LATG12_MASK;

            break;

#endif

        default:

            ao_assert(false);

            break;
    }
}

// ----------------------------------------------------------------------------

#endif

#if defined AO_SYS_CONFIG

#if defined AO_SYS_CONFIG_BOOTISA

// ----------------------------------------------------------------------------

// DEVCFG0.BOOTISA

// Boot ISA Selection.

// ----------------------------------------------------------------------------

#if 0

#pragma config BOOTISA = MIPS32
#pragma config BOOTISA = MICROMIPS

#endif

// ----------------------------------------------------------------------------

#endif

#if defined AO_SYS_CONFIG_CP

// ----------------------------------------------------------------------------

// DEVCP0.CP

// Code Protect.

// ----------------------------------------------------------------------------

#if 0

#pragma config CP = ON
#pragma config CP = OFF

#endif

// ----------------------------------------------------------------------------

#endif

#if defined AO_SYS_CONFIG_CSEQ

// ----------------------------------------------------------------------------

// SEQ3.CSEQ

// Boot Flash Complement Sequence Number.

// ----------------------------------------------------------------------------

#if 0

#pragma config CSEQ = 0x0000
#pragma config CSEQ = 0xFFFF

#endif

// ----------------------------------------------------------------------------

#endif

#if defined AO_SYS_CONFIG_DBGPER

// ----------------------------------------------------------------------------

// DEVCFG0.DBGPER

// Debug Mode CPU Access Permission.

// ----------------------------------------------------------------------------

#if 0

#pragma config DBGPER = ALLOW_PG2
#pragma config DBGPER = ALLOW_PG1
#pragma config DBGPER = ALLOW_PG0
#pragma config DBGPER = PG_1_0
#pragma config DBGPER = PG_2_0
#pragma config DBGPER = PG_2_1
#pragma config DBGPER = PG_ALL
#pragma config DBGPER = PG_NONE

#endif

// ----------------------------------------------------------------------------

#endif

#if defined AO_SYS_CONFIG_DEBUG

// ----------------------------------------------------------------------------

// DEVCFG0.DEBUG

// Background Debugger Enable.

// ----------------------------------------------------------------------------

#if 0

#pragma config DEBUG = ON
#pragma config DEBUG = OFF

#endif

// ----------------------------------------------------------------------------

#endif

#if defined AO_SYS_CONFIG_DMTCNT

// ----------------------------------------------------------------------------

// DEVCFG1.DMTCNT

// Deadman Timer Count Select.

// ----------------------------------------------------------------------------

#pragma config DMTCNT = DMT31

// ----------------------------------------------------------------------------

#if 0

#pragma config DMTCNT = DMT8
#pragma config DMTCNT = DMT9
#pragma config DMTCNT = DMT10
#pragma config DMTCNT = DMT11
#pragma config DMTCNT = DMT12
#pragma config DMTCNT = DMT13
#pragma config DMTCNT = DMT14
#pragma config DMTCNT = DMT15
#pragma config DMTCNT = DMT16
#pragma config DMTCNT = DMT17
#pragma config DMTCNT = DMT18
#pragma config DMTCNT = DMT19
#pragma config DMTCNT = DMT20
#pragma config DMTCNT = DMT21
#pragma config DMTCNT = DMT22
#pragma config DMTCNT = DMT23
#pragma config DMTCNT = DMT24
#pragma config DMTCNT = DMT25
#pragma config DMTCNT = DMT26
#pragma config DMTCNT = DMT27
#pragma config DMTCNT = DMT28
#pragma config DMTCNT = DMT29
#pragma config DMTCNT = DMT30
#pragma config DMTCNT = DMT31

#endif

// ----------------------------------------------------------------------------

#endif

#if defined AO_SYS_CONFIG_DMTINTV

// ----------------------------------------------------------------------------

// DEVCFG1.DMTINTV

// Deadman Timer Count Window Interval.

// ----------------------------------------------------------------------------

#if 0

#pragma config DMTINTV = WIN_0
#pragma config DMTINTV = WIN_1_2
#pragma config DMTINTV = WIN_3_4
#pragma config DMTINTV = WIN_7_8
#pragma config DMTINTV = WIN_15_16
#pragma config DMTINTV = WIN_31_32
#pragma config DMTINTV = WIN_63_64
#pragma config DMTINTV = WIN_127_128

#endif

// ----------------------------------------------------------------------------

#endif

#if defined AO_SYS_CONFIG_EJTAGBEN

// ----------------------------------------------------------------------------

// DEVCFG0.EJTAGBEN

// EJTAG Boot Enable.

// ----------------------------------------------------------------------------

#if 0

#pragma config EJTAGBEN = NORMAL
#pragma config EJTAGBEN = REDUCED

#endif

// ----------------------------------------------------------------------------

#endif

#if defined AO_SYS_CONFIG_FCKSM

// ----------------------------------------------------------------------------

// DEVCFG1.FCKSM

// Clock Switching and Monitoring Selection Configuration.

// ----------------------------------------------------------------------------

#pragma config FCKSM = CSECME

// ----------------------------------------------------------------------------

#if 0

#pragma config FCKSM = CSDCMD
#pragma config FCKSM = CSDCME
#pragma config FCKSM = CSECMD
#pragma config FCKSM = CSECME

#endif

// ----------------------------------------------------------------------------

#endif

#if defined AO_SYS_CONFIG_FDMTEN

// ----------------------------------------------------------------------------

// DEVCFG1.FDMTEN

// Deadman Timer Enable.

// ----------------------------------------------------------------------------

#pragma config FDMTEN = OFF

// ----------------------------------------------------------------------------

#if 0

#pragma config FDMTEN = OFF
#pragma config FDMTEN = ON

#endif

// ----------------------------------------------------------------------------

#endif

#if defined AO_SYS_CONFIG_FECCCON

// ----------------------------------------------------------------------------

// DEVCFG0.FECCCON

// Dynamic Flash ECC Configuration.

// ----------------------------------------------------------------------------

#if 0

#pragma config FECCCON = ON
#pragma config FECCCON = DYNAMIC
#pragma config FECCCON = OFF_LOCKED
#pragma config FECCCON = OFF_UNLOCKED

#endif

// ----------------------------------------------------------------------------

#endif

#if defined AO_SYS_CONFIG_FETHIO

// ----------------------------------------------------------------------------

// DEVCFG3.FETHIO

// Ethernet I/O Pin Selection Configuration.

// ----------------------------------------------------------------------------

#if 0

#pragma config FETHIO = OFF
#pragma config FETHIO = ON

#endif

// ----------------------------------------------------------------------------

#endif

#if defined AO_SYS_CONFIG_FMIIEN

// ----------------------------------------------------------------------------

// DEVCFG3.FMIIEN

// Ethernet MII Enable Configuration.

// ----------------------------------------------------------------------------

#if 0

#pragma config FMIIEN = OFF
#pragma config FMIIEN = ON

#endif

// ----------------------------------------------------------------------------

#endif

#if defined AO_SYS_CONFIG_FNOSC

// ----------------------------------------------------------------------------

// DEVCFG1.FNOSC

// Oscillator Selection.

// ----------------------------------------------------------------------------

#pragma config FNOSC = SPLL

// ----------------------------------------------------------------------------

#if 0

#pragma config FNOSC = FRCDIV
#pragma config FNOSC = LPRC
#pragma config FNOSC = POSC
#pragma config FNOSC = SOSC
#pragma config FNOSC = SPLL

#endif

// ----------------------------------------------------------------------------

#endif

#if defined AO_SYS_CONFIG_FPLLICLK

// ----------------------------------------------------------------------------

// DEVCFG2.FPLLICLK

// System PLL Input Clock Select.

// ----------------------------------------------------------------------------

#pragma config FPLLICLK = PLL_POSC

// ----------------------------------------------------------------------------

#if 0

#pragma config FPLLICLK = PLL_FRC
#pragma config FPLLICLK = PLL_POSC

#endif

// ----------------------------------------------------------------------------

#endif

#if defined AO_SYS_CONFIG_FPLLIDIV

// ----------------------------------------------------------------------------

// DEVCFG2.FPLLIDIV

// PLL Input Divider.

// ----------------------------------------------------------------------------

#pragma config FPLLIDIV = DIV_3

// ----------------------------------------------------------------------------

#if 0

#pragma config FPLLIDIV = DIV_1
#pragma config FPLLIDIV = DIV_2
#pragma config FPLLIDIV = DIV_3
#pragma config FPLLIDIV = DIV_4
#pragma config FPLLIDIV = DIV_5
#pragma config FPLLIDIV = DIV_6
#pragma config FPLLIDIV = DIV_7
#pragma config FPLLIDIV = DIV_8

#endif

// ----------------------------------------------------------------------------

#endif

#if defined AO_SYS_CONFIG_FPLLMULT

// ----------------------------------------------------------------------------

// DEVCFG2.FPLLMULT

// System PLL Feedback Divider.

// ----------------------------------------------------------------------------

#pragma config FPLLMULT = MUL_50

// ----------------------------------------------------------------------------

#if 0

#pragma config FPLLMULT = MUL_1
#pragma config FPLLMULT = MUL_2
#pragma config FPLLMULT = MUL_3
#pragma config FPLLMULT = MUL_4
#pragma config FPLLMULT = MUL_5
#pragma config FPLLMULT = MUL_6
#pragma config FPLLMULT = MUL_7
#pragma config FPLLMULT = MUL_8
#pragma config FPLLMULT = MUL_9
#pragma config FPLLMULT = MUL_10
#pragma config FPLLMULT = MUL_11
#pragma config FPLLMULT = MUL_12
#pragma config FPLLMULT = MUL_13
#pragma config FPLLMULT = MUL_14
#pragma config FPLLMULT = MUL_15
#pragma config FPLLMULT = MUL_16
#pragma config FPLLMULT = MUL_17
#pragma config FPLLMULT = MUL_18
#pragma config FPLLMULT = MUL_19
#pragma config FPLLMULT = MUL_20
#pragma config FPLLMULT = MUL_21
#pragma config FPLLMULT = MUL_22
#pragma config FPLLMULT = MUL_23
#pragma config FPLLMULT = MUL_24
#pragma config FPLLMULT = MUL_25
#pragma config FPLLMULT = MUL_26
#pragma config FPLLMULT = MUL_27
#pragma config FPLLMULT = MUL_28
#pragma config FPLLMULT = MUL_29
#pragma config FPLLMULT = MUL_30
#pragma config FPLLMULT = MUL_31
#pragma config FPLLMULT = MUL_32
#pragma config FPLLMULT = MUL_33
#pragma config FPLLMULT = MUL_34
#pragma config FPLLMULT = MUL_35
#pragma config FPLLMULT = MUL_36
#pragma config FPLLMULT = MUL_37
#pragma config FPLLMULT = MUL_38
#pragma config FPLLMULT = MUL_39
#pragma config FPLLMULT = MUL_40
#pragma config FPLLMULT = MUL_41
#pragma config FPLLMULT = MUL_42
#pragma config FPLLMULT = MUL_43
#pragma config FPLLMULT = MUL_44
#pragma config FPLLMULT = MUL_45
#pragma config FPLLMULT = MUL_46
#pragma config FPLLMULT = MUL_47
#pragma config FPLLMULT = MUL_48
#pragma config FPLLMULT = MUL_49
#pragma config FPLLMULT = MUL_50
#pragma config FPLLMULT = MUL_51
#pragma config FPLLMULT = MUL_52
#pragma config FPLLMULT = MUL_53
#pragma config FPLLMULT = MUL_54
#pragma config FPLLMULT = MUL_55
#pragma config FPLLMULT = MUL_56
#pragma config FPLLMULT = MUL_57
#pragma config FPLLMULT = MUL_58
#pragma config FPLLMULT = MUL_59
#pragma config FPLLMULT = MUL_60
#pragma config FPLLMULT = MUL_61
#pragma config FPLLMULT = MUL_62
#pragma config FPLLMULT = MUL_63
#pragma config FPLLMULT = MUL_64
#pragma config FPLLMULT = MUL_65
#pragma config FPLLMULT = MUL_66
#pragma config FPLLMULT = MUL_67
#pragma config FPLLMULT = MUL_68
#pragma config FPLLMULT = MUL_69
#pragma config FPLLMULT = MUL_70
#pragma config FPLLMULT = MUL_71
#pragma config FPLLMULT = MUL_72
#pragma config FPLLMULT = MUL_73
#pragma config FPLLMULT = MUL_74
#pragma config FPLLMULT = MUL_75
#pragma config FPLLMULT = MUL_76
#pragma config FPLLMULT = MUL_77
#pragma config FPLLMULT = MUL_78
#pragma config FPLLMULT = MUL_79
#pragma config FPLLMULT = MUL_80
#pragma config FPLLMULT = MUL_81
#pragma config FPLLMULT = MUL_82
#pragma config FPLLMULT = MUL_83
#pragma config FPLLMULT = MUL_84
#pragma config FPLLMULT = MUL_85
#pragma config FPLLMULT = MUL_86
#pragma config FPLLMULT = MUL_87
#pragma config FPLLMULT = MUL_88
#pragma config FPLLMULT = MUL_89
#pragma config FPLLMULT = MUL_90
#pragma config FPLLMULT = MUL_91
#pragma config FPLLMULT = MUL_92
#pragma config FPLLMULT = MUL_93
#pragma config FPLLMULT = MUL_94
#pragma config FPLLMULT = MUL_95
#pragma config FPLLMULT = MUL_96
#pragma config FPLLMULT = MUL_97
#pragma config FPLLMULT = MUL_98
#pragma config FPLLMULT = MUL_99
#pragma config FPLLMULT = MUL_100
#pragma config FPLLMULT = MUL_101
#pragma config FPLLMULT = MUL_102
#pragma config FPLLMULT = MUL_103
#pragma config FPLLMULT = MUL_104
#pragma config FPLLMULT = MUL_105
#pragma config FPLLMULT = MUL_106
#pragma config FPLLMULT = MUL_107
#pragma config FPLLMULT = MUL_108
#pragma config FPLLMULT = MUL_109
#pragma config FPLLMULT = MUL_110
#pragma config FPLLMULT = MUL_111
#pragma config FPLLMULT = MUL_112
#pragma config FPLLMULT = MUL_113
#pragma config FPLLMULT = MUL_114
#pragma config FPLLMULT = MUL_115
#pragma config FPLLMULT = MUL_116
#pragma config FPLLMULT = MUL_117
#pragma config FPLLMULT = MUL_118
#pragma config FPLLMULT = MUL_119
#pragma config FPLLMULT = MUL_120
#pragma config FPLLMULT = MUL_121
#pragma config FPLLMULT = MUL_122
#pragma config FPLLMULT = MUL_123
#pragma config FPLLMULT = MUL_124
#pragma config FPLLMULT = MUL_125
#pragma config FPLLMULT = MUL_126
#pragma config FPLLMULT = MUL_127
#pragma config FPLLMULT = MUL_128

#endif

// ----------------------------------------------------------------------------

#endif

#if defined AO_SYS_CONFIG_FPLLODIV

// ----------------------------------------------------------------------------

// DEVCFG2.FPLLODIV

// Default System PLL Output Divisor.

// ----------------------------------------------------------------------------

#pragma config FPLLODIV = DIV_2

// ----------------------------------------------------------------------------

#if 0

#pragma config FPLLODIV = DIV_2
#pragma config FPLLODIV = DIV_4
#pragma config FPLLODIV = DIV_8
#pragma config FPLLODIV = DIV_16
#pragma config FPLLODIV = DIV_32

#endif

// ----------------------------------------------------------------------------

#endif

#if defined AO_SYS_CONFIG_FPLLRNG

// ----------------------------------------------------------------------------

// DEVCFG2.FPLLRNG

// System PLL Divided Input Clock Frequency Range.

// ----------------------------------------------------------------------------

#pragma config FPLLRNG = RANGE_8_16_MHZ

// ----------------------------------------------------------------------------

#if 0

#pragma config FPLLRNG = RANGE_BYPASS
#pragma config FPLLRNG = RANGE_5_10_MHZ
#pragma config FPLLRNG = RANGE_8_16_MHZ
#pragma config FPLLRNG = RANGE_13_26_MHZ
#pragma config FPLLRNG = RANGE_21_42_MHZ
#pragma config FPLLRNG = RANGE_34_68_MHZ

#endif

// ----------------------------------------------------------------------------

#endif

#if defined AO_SYS_CONFIG_FSLEEP

// ----------------------------------------------------------------------------

// DEVCFG0.FSLEEP

// Flash Sleep Mode.

// ----------------------------------------------------------------------------

#if 0

#pragma config FSLEEP = OFF
#pragma config FSLEEP = VREGS

#endif

// ----------------------------------------------------------------------------

#endif

#if defined AO_SYS_CONFIG_FSOSCEN

// ----------------------------------------------------------------------------

// DEVCFG1.FSOSCEN

// Secondary Oscillator Enable.

// ----------------------------------------------------------------------------

#pragma config FSOSCEN = OFF

// ----------------------------------------------------------------------------

#if 0

#pragma config FSOSCEN = OFF
#pragma config FSOSCEN = ON

#endif

// ----------------------------------------------------------------------------

#endif

#if defined AO_SYS_CONFIG_FUSBIDIO

// ----------------------------------------------------------------------------

// DEVCFG3.FUSBIDIO

// USB USBID Selection.

// ----------------------------------------------------------------------------

#if 0

#pragma config FUSBIDIO = OFF
#pragma config FUSBIDIO = ON

#endif

// ----------------------------------------------------------------------------

#endif

#if defined AO_SYS_CONFIG_FWDTEN

// ----------------------------------------------------------------------------

// DEVCFG1.FWDTEN

// Watchdog Timer Enable.

// ----------------------------------------------------------------------------

#pragma config FWDTEN = OFF

// ----------------------------------------------------------------------------

#if 0

#pragma config FWDTEN = OFF
#pragma config FWDTEN = ON

#endif

// ----------------------------------------------------------------------------

#endif

#if defined AO_SYS_CONFIG_FWDTWINSZ

// ----------------------------------------------------------------------------

// DEVCFG1.FWDTWINSZ

// Watchdog Timer Window Size.

// ----------------------------------------------------------------------------

#if 0

#pragma config FWDTWINSZ = WINSZ_25
#pragma config FWDTWINSZ = WINSZ_37
#pragma config FWDTWINSZ = WINSZ_50
#pragma config FWDTWINSZ = WINSZ_75

#endif

// ----------------------------------------------------------------------------

#endif

#if defined AO_SYS_CONFIG_ICESEL

// ----------------------------------------------------------------------------

// DEVCFG0.ICESEL

// In-Circuit Emulator/Debugger Communication Channel Selection.

// ----------------------------------------------------------------------------

#pragma config ICESEL = ICS_PGx2

// ----------------------------------------------------------------------------

#if 0

#pragma config ICESEL = ICS_PGx1
#pragma config ICESEL = ICS_PGx2

#endif

// ----------------------------------------------------------------------------

#endif

#if defined AO_SYS_CONFIG_IESO

// ----------------------------------------------------------------------------

// DEVCFG1.IESO

// Internal External Switchover.

// ----------------------------------------------------------------------------

#pragma config IESO = OFF

// ----------------------------------------------------------------------------

#if 0

#pragma config IESO = OFF
#pragma config IESO = ON

#endif

// ----------------------------------------------------------------------------

#endif

#if defined AO_SYS_CONFIG_IOL1WAY

// ----------------------------------------------------------------------------

// DEVCFG3.IOL1WAY

// Peripheral Pin Select Configuration.

// ----------------------------------------------------------------------------

#if 0

#pragma config IOL1WAY = ON
#pragma config IOL1WAY = OFF

#endif

// ----------------------------------------------------------------------------

#endif

#if defined AO_SYS_CONFIG_JTAGEN

// ----------------------------------------------------------------------------

// DEVCFG0.JTAGEN

// JTAG Enable.

// ----------------------------------------------------------------------------

#pragma config JTAGEN = OFF

// ----------------------------------------------------------------------------

#if 0

#pragma config JTAGEN = ON
#pragma config JTAGEN = OFF

#endif

// ----------------------------------------------------------------------------

#endif

#if defined AO_SYS_CONFIG_OSCIOFNC

// ----------------------------------------------------------------------------

// DEVCFG1.OSCIOFNC

// CLKO Output Signal Active on the OSCO Pin.

// ----------------------------------------------------------------------------

#if 0

#pragma config OSCIOFNC = OFF
#pragma config OSCIOFNC = ON

#endif

// ----------------------------------------------------------------------------

#endif

#if defined AO_SYS_CONFIG_PGL1WAY

// ----------------------------------------------------------------------------

// DEVCFG3.PGL1WAY

// Permission Group Lock One Way Configuration.

// ----------------------------------------------------------------------------

#if 0

#pragma config PGL1WAY = ON
#pragma config PGL1WAY = OFF

#endif

// ----------------------------------------------------------------------------

#endif

#if defined AO_SYS_CONFIG_PMDL1WAY

// ----------------------------------------------------------------------------

// DEVCFG3.PMDL1WAY

// Peripheral Module Disable Configuration.

// ----------------------------------------------------------------------------

#if 0

#pragma config PMDL1WAY = ON
#pragma config PMDL1WAY = OFF

#endif

// ----------------------------------------------------------------------------

#endif

#if defined AO_SYS_CONFIG_POSCBOOST

// ----------------------------------------------------------------------------

// DEVCFG0.POSCBOOST

// Primary Oscillator Boost Kick Start Enable.

// ----------------------------------------------------------------------------

#if 0

#pragma config POSCBOOST = ON
#pragma config POSCBOOST = OFF

#endif

// ----------------------------------------------------------------------------

#endif

#if defined AO_SYS_CONFIG_POSCGAIN

// ----------------------------------------------------------------------------

// DEVCFG0.POSCGAIN

// Primary Oscillator Gain Control.

// ----------------------------------------------------------------------------

#if 0

#pragma config POSCGAIN = GAIN_2X
#pragma config POSCGAIN = GAIN_1_5X
#pragma config POSCGAIN = GAIN_0_5X
#pragma config POSCGAIN = GAIN_1X
#pragma config POSCGAIN = GAIN_LEVEL_3
#pragma config POSCGAIN = GAIN_LEVEL_2
#pragma config POSCGAIN = GAIN_LEVEL_1
#pragma config POSCGAIN = GAIN_LEVEL_0

#endif

// ----------------------------------------------------------------------------

#endif

#if defined AO_SYS_CONFIG_POSCMOD

// ----------------------------------------------------------------------------

// DEVCFG1.POSCMOD

// Primary Oscillator Configuration.

// ----------------------------------------------------------------------------

#pragma config POSCMOD = EC

// ----------------------------------------------------------------------------

#if 0

#pragma config POSCMOD = EC
#pragma config POSCMOD = HS
#pragma config POSCMOD = OFF

#endif

// ----------------------------------------------------------------------------

#endif

#if defined AO_SYS_CONFIG_SMCLR

// ----------------------------------------------------------------------------

// DEVCFG0.SMCLR

// Soft Master Clear Enable.

// ----------------------------------------------------------------------------

#if 0

#pragma config SMCLR = MCLR_NORM
#pragma config SMCLR = MCLR_POR

#endif

// ----------------------------------------------------------------------------

#endif

#if defined AO_SYS_CONFIG_SOSCBOOST

// ----------------------------------------------------------------------------

// DEVCFG0.SOSCBOOST

// Secondary Oscillator Boost Kick Start Enable.

// ----------------------------------------------------------------------------

#if 0

#pragma config SOSCBOOST = ON
#pragma config SOSCBOOST = OFF

#endif

// ----------------------------------------------------------------------------

#endif

#if defined AO_SYS_CONFIG_SOSCGAIN

// ----------------------------------------------------------------------------

// DEVCFG0.SOSCGAIN

// Secondary Oscillator Gain Control.

// ----------------------------------------------------------------------------

#if 0

#pragma config SOSCGAIN = GAIN_2X
#pragma config SOSCGAIN = GAIN_1_5X
#pragma config SOSCGAIN = GAIN_0_5X
#pragma config SOSCGAIN = GAIN_1X
#pragma config SOSCGAIN = GAIN_LEVEL_3
#pragma config SOSCGAIN = GAIN_LEVEL_2
#pragma config SOSCGAIN = GAIN_LEVEL_1
#pragma config SOSCGAIN = GAIN_LEVEL_0

#endif

// ----------------------------------------------------------------------------

#endif

#if defined AO_SYS_CONFIG_TRCEN

// ----------------------------------------------------------------------------

// DEVCFG0.TRCEN

// Trace Enable.

// ----------------------------------------------------------------------------

#pragma config TRCEN = OFF

// ----------------------------------------------------------------------------

#if 0

#pragma config TRCEN = ON
#pragma config TRCEN = OFF

#endif

// ----------------------------------------------------------------------------

#endif

#if defined AO_SYS_CONFIG_TSEQ

// ----------------------------------------------------------------------------

// SEQ3.TSEQ

// Boot Flash True Sequence Number.

// ----------------------------------------------------------------------------

#if 0

#pragma config TSEQ = 0x0000
#pragma config TSEQ = 0xFFFF

#endif

// ----------------------------------------------------------------------------

#endif

#if defined AO_SYS_CONFIG_UPLLFSEL

// ----------------------------------------------------------------------------

// DEVCFG2.UPLLFSEL

// USB PLL Input Frequency Select.

// ----------------------------------------------------------------------------

#if 0

#pragma config UPLLFSEL = FREQ_24MHZ
#pragma config UPLLFSEL = FREQ_12MHZ

#endif

// ----------------------------------------------------------------------------

#endif

#if defined AO_SYS_CONFIG_USERID

// ----------------------------------------------------------------------------

// DEVCFG3.USERID

// This is a 16-bit value that is user-defined and is readable via ICSP™ and
// JTAG.

// ----------------------------------------------------------------------------

#if 0

#pragma config USERID = 0x0000
#pragma config USERID = 0xFFFF

#endif

// ----------------------------------------------------------------------------

#endif

#if defined AO_SYS_CONFIG_WDTPS

// ----------------------------------------------------------------------------

// DEVCFG1.WDTPS

// Watchdog Timer Postscale Select.

// ----------------------------------------------------------------------------

#if 0

#pragma config WDTPS = PS1
#pragma config WDTPS = PS2
#pragma config WDTPS = PS4
#pragma config WDTPS = PS8
#pragma config WDTPS = PS16
#pragma config WDTPS = PS32
#pragma config WDTPS = PS64
#pragma config WDTPS = PS128
#pragma config WDTPS = PS256
#pragma config WDTPS = PS512
#pragma config WDTPS = PS1024
#pragma config WDTPS = PS2048
#pragma config WDTPS = PS4096
#pragma config WDTPS = PS8192
#pragma config WDTPS = PS16384
#pragma config WDTPS = PS32768
#pragma config WDTPS = PS65536
#pragma config WDTPS = PS131072
#pragma config WDTPS = PS262144
#pragma config WDTPS = PS524288
#pragma config WDTPS = PS1048576

#endif

// ----------------------------------------------------------------------------

#endif

#if defined AO_SYS_CONFIG_WDTSPGM

// ----------------------------------------------------------------------------

// DEVCFG1.WDTSPGM

// Watchdog Timer Stop During Flash Programming.

// ----------------------------------------------------------------------------

#if 0

#pragma config WDTSPGM = RUN
#pragma config WDTSPGM = STOP

#endif

// ----------------------------------------------------------------------------

#endif

#if defined AO_SYS_CONFIG_WINDIS

// ----------------------------------------------------------------------------

// DEVCFG1.WINDIS

// Watchdog Timer Window Enable.

// ----------------------------------------------------------------------------

#if 0

#pragma config WINDIS = NORMAL
#pragma config WINDIS = WINDOW

#endif

// ----------------------------------------------------------------------------

#endif

#endif

#if defined AO_SYS_EXC

#if AO_DEBUG

// ----------------------------------------------------------------------------

// @seeAlso

// Imagination Technologies.

// MIPS32® M5150 Processor Core Family Software User’s Manual.

// ----------------------------------------------------------------------------

void _general_exception_handler(uint32_t cause, uint32_t status)
{
    // Variables.

    ao_sys_exc_t code = (ao_sys_exc_t) ((cause & _CP0_CAUSE_EXCCODE_MASK) >> _CP0_CAUSE_EXCCODE_POSITION);

    (void) status;


    // Ready.

    switch (code)
    {
        case AO_SYS_EXC_INT:

            // Interrupt.

            // This really should not have happend.

            ao_break();

            break;

        case AO_SYS_EXC_MOD:

            // TLB modified.

            ao_break();

            break;

        case AO_SYS_EXC_TLBL:
        case AO_SYS_EXC_TLBS:

            // TLB invalid.

            ao_break();

            break;

        case AO_SYS_EXC_ADEL:
        case AO_SYS_EXC_ADES:

            // Address error.

            // An address error exception occurs on an instruction or data
            // access when an attempt is made to execute one of the following.

            // * Fetch an instruction, load a word, or store a word that is not
            //   aligned on a word boundary.

            // * Load or store a halfword that is not aligned on a halfword
            //   boundary.

            // * Reference the kernel address space from user mode.

            // Note that in the case of an instruction fetch that is not
            // aligned on a word boundary, PC is updated before the condition
            // is detected.

            // Therefore, both EPC and BadVAddr point to the unaligned
            // instruction address.

            // In the case of a data access the exception is taken if either an
            // unaligned address or an address that was inaccessible in the
            // current processor mode was referenced by a load or store
            // instruction.

            // Additional state saved.

            // * BadVAddr       Failing address.

            // * Context.VPN2   UNPREDICTABLE.

            // * EntryHi.VPN2   UNPREDICTABLE.

            // * EntryLo0       UNPREDICTABLE.

            // * EntryLo1       UNPREDICTABLE.

            ao_break();

            break;

        case AO_SYS_EXC_IBE:
        case AO_SYS_EXC_DBE:

            // Bus error.

            // A bus error exception occurs when an instruction or data access
            // makes a bus request (due to a cache miss or an uncacheable
            // reference) and that request terminates in an error.

            // The bus error exception can occur on either an instruction fetch
            // or a data access.

            // Bus error exceptions that occur on an instruction fetch have a
            // higher priority than bus error exceptions that occur on a data
            // access.

            // Bus errors taken on the requested (critical) word of an
            // instruction fetch or data load are precise. Other bus errors,
            // such as stores or non-critical words of a burst read, can be
            // imprecise. These errors are taken when an AHB slave responds
            // with an error code.

            // The M5150 family core does not support imprecise instruction
            // fetch bus error exceptions. Thus, when a slave signals a bus
            // error, this notification must be repeated for all similar
            // instruction fetches until the core has taken the exception.

            ao_break();

            break;

        case AO_SYS_EXC_SYS:

            // System call.

            // The system call exception is one of the execution exceptions.
            // All of these exceptions have the same priority.

            // A system call exception occurs when a SYSCALL instruction is
            // executed.

            ao_break();

            break;

        case AO_SYS_EXC_BP:

            // Breakpoint.

            // The breakpoint exception is one of the execution exceptions. All
            // of these exceptions have the same priority.

            // A breakpoint exception occurs when a BREAK instruction is
            // executed.

            ao_break();

            break;

        case AO_SYS_EXC_RI:

            // Reserved instruction.

            // The reserved instruction exception is one of the execution
            /// exceptions. All of these exceptions have the same priority.

            // A reserved instruction exception occurs when a reserved or
            // undefined major opcode or function field is executed.

            // This includes coprocessor 2 instructions which are decoded
            // reserved in the coprocessor 2.

            ao_break();

            break;

        case AO_SYS_EXC_CPU:

            // Coprocessor unusable.

            // The coprocessor unusable exception is one of the execution
            // exceptions. All of these exceptions have the same priority.

            // A coprocessor unusable exception occurs when an attempt is made
            // to execute a coprocessor instruction for one of the following.

            // * A corresponding coprocessor unit that has not been marked
            //   usable by setting its CU bit in the Status register.

            // * CP0 instructions, when the unit has not been marked usable,
            //   and the processor is executing in user mode.

            // Additional state saved.

            // * Cause.CE   Unit number of the coprocessor being referenced.

            ao_break();

            break;

        case AO_SYS_EXC_OV:

            // Integer overflow.

            // The integer overflow exception is one of the execution
            // exceptions. All of these exceptions have the same priority.

            // An integer overflow exception occurs when selected integer
            // instructions result in a 2’s complement overflow.

            ao_break();

            break;

        case AO_SYS_EXC_TR:

            // Trap.

            // The trap exception is one of the execution exceptions. All of
            // these exceptions have the same priority.

            // A trap exception occurs when a trap instruction results in a
            // TRUE value.

            ao_break();

            break;

        case AO_SYS_EXC_FPE:

            // FPU.

            ao_break();

            break;

        case AO_SYS_EXC_TLBRI:

            // TLB read-inhibit.

            ao_break();

            break;

        case AO_SYS_EXC_TLBEI:

            // TLB execute-inhibit.

            ao_break();

            break;

        case AO_SYS_EXC_WATCH:

            // Watch.

            // The watch facility provides a software debugging vehicle by
            // initiating a watch exception when an instruction or data
            // reference matches the address information stored in the WatchHi
            // and WatchLo registers.

            // A watch exception is taken immediately if the EXL and ERL bits
            // of the Status register are both zero and the DM bit of the Debug
            // register is also zero.

            // If any of those bits is a one at the time that a watch exception
            // would normally be taken, then the WP bit in the Cause register
            // is set, and the exception is deferred until all three bits are
            // zero.

            // Software may use the WP bit in the Cause register to determine
            // if the EPC register points at the instruction that caused the
            // watch exception, or if the exception actually occurred while in
            // kernel mode.

            // The watch exception can occur on either an instruction fetch or
            // a data access. Watch exceptions that occur on an instruction
            // fetch have a higher priority than watch exceptions that occur on
            // a data access.

            // Additional state saved.

            // * Cause.WP   Indicates that the watch exception was deferred
            //              until after Status.EXL, Status.ERL, and Debug.DM
            //              were zero. This bit directly causes a watch
            //              exception, so software must clear this bit as part
            //              of the exception handler to prevent a watch
            //              exception loop at the end of the current handler
            //              execution.

            ao_break();

            break;

        case AO_SYS_EXC_MCHECK:

            // Machine check.

            // A machine check exception occurs when the processor detects an
            // internal inconsistency.

            // The following condition causes a machine check exception.

            // * The detection of multiple matching entries in the TLB
            //   (TLB-based MMU only). The core detects this condition on a TLB
            //   write and prevents the write from being completed. The TS bit
            //   in the Status register is set to indicate this condition. This
            //   bit is only a status flag and does not affect the operation of
            //   the device. Software clears this bit at the appropriate time.
            //   This condition is resolved by flushing the conflicting TLB
            //   entries. The TLB write can then be completed.

            ao_break();

            break;

        case AO_SYS_EXC_DSPDIS:

            // DSP module state disabled.

            // The DSP module state disabled exception is an execution
            // exception.

            // It occurs when an attempt is made to execute a DSP module
            // instruction when the MX bit in the Status register is not set.
            // This allows an OS to do “lazy” context switching.

            ao_break();

            break;

        default:

            // Reserved.

            // This really should not have happend.

            ao_break();

            break;
    }
}

#else

void _general_exception_handler(uint32_t cause, uint32_t status)
{
    // Variables.

    (void) cause;
    (void) status;


    // Ready.

    ao_boot_led();

    while (1)
    {
        ao_spin(ao_milliseconds(100));

        ao_leds_toggle(AO_LEDS_ALL);
    }
}

#endif

#endif

#if defined AO_UART_5

// ----------------------------------------------------------------------------

void ao_boot_uart_5()
{
    // Variables.

    ao_sys_lock_pps_t l;

    ao_uart_reg_t * r = ao_uart_reg_5();


    // Pins.

    // U5RX = D14, pps.

    // U5TX = D15, pps.

    ANSELDCLR = _ANSELD_ANSD14_MASK;

    ANSELDCLR = _ANSELD_ANSD15_MASK;

    ao_sys_unlock_pps(&l);
    {
        U5RXR = 0b1011;

        RPD15R = 0b0011;
    }
    ao_sys_lock_pps(&l);


    // UART.

    r->mode.bits.clksel = 0b00;

    r->mode.bits.rtsmd = 0;

    r->mode.bits.rxinv = 0;

    r->mode.bits.uen = 0b00;

    r->sta.bits.utxinv = 0;
}

// ----------------------------------------------------------------------------

#endif

#endif

#if defined AO_MIKROE_2800

#if defined AO_BOOT

// ----------------------------------------------------------------------------

void ao_boot()
{
    // Count.

    ao_boot_count();


    // System.

    ao_boot_sys_pcache();


    // Interrupts.

    ao_boot_ir_stack();

    ao_boot_ir_mvec();

    ao_boot_ir_srs();


    ao_boot_ir_can1();

    ao_boot_ir_can2();

    ao_boot_ir_cs0();

    ao_boot_ir_cs1();

    ao_boot_ir_ct();

    ao_boot_ir_int2();

    ao_boot_ir_int4();

    ao_boot_ir_u2rx();

    ao_boot_ir_u2tx();

    ao_boot_ir_u3rx();

    ao_boot_ir_u3tx();


    // Modules.

#if defined AO_ALLOC

    ao_boot_alloc();

#endif

#if defined AO_ALARM

    ao_boot_alarm();

#endif

    ao_boot_button();

    ao_boot_led();

#if defined AO_MIKROE_1877

    ao_boot_mikroe_1877();

#endif

#if defined AO_MIKROE_2334

    ao_boot_mikroe_2334();

#endif

#if defined AO_MIKROE_2674

    ao_boot_mikroe_2674();

#endif

#if defined AO_MIKROE_2935

    ao_boot_mikroe_2935();

#endif

#if defined AO_MIKROE_2950

    ao_boot_mikroe_2950();

#endif

#if defined AO_MIKROE_3063

    ao_boot_mikroe_3063();

#endif

#if defined AO_MIKROE_4186

    ao_boot_mikroe_4186();

#endif

#if defined AO_TASK

    ao_boot_task();

#endif


    // Interrupts.

    ao_ir_enable();
}

// ----------------------------------------------------------------------------

#endif

#if defined AO_MIKROE_1877_1 && AO_MIKROE_1877_1

// ----------------------------------------------------------------------------

static  void                    ao_boot_mikroe_1877_1();

// ----------------------------------------------------------------------------

static  bool                    ao_mikroe_1877_int_asserted_1();

static  void                    ao_mikroe_1877_int_disable_1();

static  void                    ao_mikroe_1877_int_enable_1();

// ----------------------------------------------------------------------------

static  void                    ao_mikroe_1877_reset_disable_1();

static  void                    ao_mikroe_1877_reset_enable_1();

// ----------------------------------------------------------------------------

static  void                    ao_mikroe_1877_wake_disable_1();

static  void                    ao_mikroe_1877_wake_enable_1();

// ----------------------------------------------------------------------------

static  ao_mikroe_1877_i2c_t    ao_mikroe_1877_i2c_1 =
{
        .f                      = AO_MIKROE_1877_BAUD_1,

        .f_pbclk                = AO_SYS_CLOCK_I2C4,

        .reg                    = ao_i2c_reg_4(),

        .timeout                = AO_MIKROE_1877_TIMEOUT_1
};

// ----------------------------------------------------------------------------

        ao_task_t               ao_mikroe_1877_task_1;

// ----------------------------------------------------------------------------

static  ao_mikroe_1877_mod_t    ao_mikroe_1877_mod_1 =
{
        .i                      = AO_MIKROE_1,

        .i2c                    = &ao_mikroe_1877_i2c_1,

        .int_asserted           = ao_mikroe_1877_int_asserted_1,

        .int_disable            = ao_mikroe_1877_int_disable_1,

        .int_enable             = ao_mikroe_1877_int_enable_1,

        .reset_disable          = ao_mikroe_1877_reset_disable_1,

        .reset_enable           = ao_mikroe_1877_reset_enable_1,

        .task                   = &ao_mikroe_1877_task_1,

        .wake_disable           = ao_mikroe_1877_wake_disable_1,

        .wake_enable            = ao_mikroe_1877_wake_enable_1
};

// ----------------------------------------------------------------------------

void ao_boot_mikroe_1877_1()
{
    // Variables.

    ao_sys_lock_pps_t l;


    // Interrupt.

    ao_ir_int4_falling();


    // Pins.

    // INT4  = B1, pps.

    // RESET = B3, out, active low.

    // SCL4  = G8.

    // SDA4  = G7.

    // WAKE  = B4, out, active high.

    ANSELBCLR = _ANSELB_ANSB1_MASK;

    ANSELBCLR = _ANSELB_ANSB3_MASK;

    ANSELBCLR = _ANSELB_ANSB4_MASK;

    ANSELGCLR = _ANSELG_ANSG7_MASK;

    ANSELGCLR = _ANSELG_ANSG8_MASK;

    TRISBCLR = _TRISB_TRISB3_MASK;

    TRISBCLR = _TRISB_TRISB4_MASK;

    ao_sys_unlock_pps(&l);
    {
        INT4R = 0b0101;
    }
    ao_sys_lock_pps(&l);


    // I2C.

    ao_boot_mikroe_1877_i2c(&ao_mikroe_1877_i2c_1);
}

// ----------------------------------------------------------------------------

AO_IR_INT4_ATTRIBUTE
void ao_ir_int4()
{
    ao_mikroe_1877_mod_int(&ao_mikroe_1877_mod_1);

    ao_ir_int4_reply();
}

// ----------------------------------------------------------------------------

bool ao_mikroe_1877_int_asserted_1()
{
    return (PORTB & _PORTB_RB1_MASK) ? false : true;
}

void ao_mikroe_1877_int_disable_1()
{
    ao_ir_int4_disable();
}

void ao_mikroe_1877_int_enable_1()
{
    ao_ir_int4_enable();
}

// ----------------------------------------------------------------------------

void ao_mikroe_1877_reset_disable_1()
{
    LATBSET = _LATB_LATB3_MASK;
}

void ao_mikroe_1877_reset_enable_1()
{
    LATBCLR = _LATB_LATB3_MASK;
}

// ----------------------------------------------------------------------------

void ao_mikroe_1877_wake_disable_1()
{
    LATBCLR = _LATB_LATB4_MASK;
}

void ao_mikroe_1877_wake_enable_1()
{
    LATBSET = _LATB_LATB4_MASK;
}

// ----------------------------------------------------------------------------

#endif

#if defined AO_MIKROE_1877_2 && AO_MIKROE_1877_2

// ----------------------------------------------------------------------------

static  void                    ao_boot_mikroe_1877_2();

// ----------------------------------------------------------------------------

static  bool                    ao_mikroe_1877_int_asserted_2();

static  void                    ao_mikroe_1877_int_disable_2();

static  void                    ao_mikroe_1877_int_enable_2();

// ----------------------------------------------------------------------------

static  void                    ao_mikroe_1877_reset_disable_2();

static  void                    ao_mikroe_1877_reset_enable_2();

// ----------------------------------------------------------------------------

static  void                    ao_mikroe_1877_wake_disable_2();

static  void                    ao_mikroe_1877_wake_enable_2();

// ----------------------------------------------------------------------------

static  ao_mikroe_1877_i2c_t    ao_mikroe_1877_i2c_2 =
{
        .f                      = AO_MIKROE_1877_BAUD_2,

        .f_pbclk                = AO_SYS_CLOCK_I2C2,

        .reg                    = ao_i2c_reg_2(),

        .timeout                = AO_MIKROE_1877_TIMEOUT_2
};

// ----------------------------------------------------------------------------

        ao_task_t               ao_mikroe_1877_task_2;

// ----------------------------------------------------------------------------

static  ao_mikroe_1877_mod_t    ao_mikroe_1877_mod_2 =
{
        .i                      = AO_MIKROE_2,

        .i2c                    = &ao_mikroe_1877_i2c_2,

        .int_asserted           = ao_mikroe_1877_int_asserted_2,

        .int_disable            = ao_mikroe_1877_int_disable_2,

        .int_enable             = ao_mikroe_1877_int_enable_2,

        .reset_disable          = ao_mikroe_1877_reset_disable_2,

        .reset_enable           = ao_mikroe_1877_reset_enable_2,

        .task                   = &ao_mikroe_1877_task_2,

        .wake_disable           = ao_mikroe_1877_wake_disable_2,

        .wake_enable            = ao_mikroe_1877_wake_enable_2
};

// ----------------------------------------------------------------------------

void ao_boot_mikroe_1877_2()
{
    // Variables.

    ao_sys_lock_pps_t l;


    // Interrupt.

    ao_ir_int2_falling();


    // Pins.

    // INT2  = B15, pps.

    // RESET = A10, out, active low.

    // SCL2  = A2.

    // SDA2  = A3.

    // WAKE  = B13, out, active high.

    ANSELACLR = _ANSELA_ANSA10_MASK;

    ANSELBCLR = _ANSELB_ANSB13_MASK;

    ANSELBCLR = _ANSELB_ANSB15_MASK;

    TRISACLR = _TRISA_TRISA10_MASK;

    TRISBCLR = _TRISB_TRISB13_MASK;

    ao_sys_unlock_pps(&l);
    {
        INT2R = 0b0011;
    }
    ao_sys_lock_pps(&l);


    // I2C.

    ao_boot_mikroe_1877_i2c(&ao_mikroe_1877_i2c_2);
}

// ----------------------------------------------------------------------------

AO_IR_INT2_ATTRIBUTE
void ao_ir_int2()
{
    ao_mikroe_1877_mod_int(&ao_mikroe_1877_mod_2);

    ao_ir_int2_reply();
}

// ----------------------------------------------------------------------------

bool ao_mikroe_1877_int_asserted_2()
{
    return (PORTB & _PORTB_RB15_MASK) ? false : true;
}

void ao_mikroe_1877_int_disable_2()
{
    ao_ir_int2_disable();
}

void ao_mikroe_1877_int_enable_2()
{
    ao_ir_int2_enable();
}

// ----------------------------------------------------------------------------

void ao_mikroe_1877_reset_disable_2()
{
    LATASET = _LATA_LATA10_MASK;
}

void ao_mikroe_1877_reset_enable_2()
{
    LATACLR = _LATA_LATA10_MASK;
}

// ----------------------------------------------------------------------------

void ao_mikroe_1877_wake_disable_2()
{
    LATBCLR = _LATB_LATB13_MASK;
}

void ao_mikroe_1877_wake_enable_2()
{
    LATBSET = _LATB_LATB13_MASK;
}

// ----------------------------------------------------------------------------

#endif

#if defined AO_MIKROE_1877

// ----------------------------------------------------------------------------

void ao_boot_mikroe_1877()
{

#if AO_MIKROE_1877_1

    ao_boot_mikroe_1877_1();

#endif

#if AO_MIKROE_1877_2

    ao_boot_mikroe_1877_2();

#endif

}

// ----------------------------------------------------------------------------

ao_mikroe_1877_mod_t * ao_mikroe_1877_mod(size_t i)
{
    switch (i)
    {

#if AO_MIKROE_1877_1

        case AO_MIKROE_1:

            return &ao_mikroe_1877_mod_1;

#endif

#if AO_MIKROE_1877_2

        case AO_MIKROE_2:

            return &ao_mikroe_1877_mod_2;

#endif

        default:

            ao_assert(false);

            return NULL;
    }
}

// ----------------------------------------------------------------------------

#endif

#if defined AO_MIKROE_2334

// ----------------------------------------------------------------------------

static  void    ao_boot_mikroe_2334_1();

static  void    ao_boot_mikroe_2334_2();

// ----------------------------------------------------------------------------

void ao_boot_mikroe_2334()
{

#if AO_MIKROE_2334_1

    ao_boot_mikroe_2334_1();

#endif

#if AO_MIKROE_2334_2

    ao_boot_mikroe_2334_2();

#endif

}

// ----------------------------------------------------------------------------

void ao_boot_mikroe_2334_1()
{
    // Variables.

    ao_sys_lock_pps_t l;


    // Pins.

    // C2RX = E9, pps.

    // C2TX = E8, pps.

    ANSELECLR =_ANSELE_ANSE8_MASK;

    ANSELECLR =_ANSELE_ANSE9_MASK;

    ao_sys_unlock_pps(&l);
    {
        C2RXR = 0b1101;

        RPE8R = 0b1111;
    }
    ao_sys_lock_pps(&l);
}

void ao_boot_mikroe_2334_2()
{
    // Variables.

    ao_sys_lock_pps_t l;


    // Pins.

    // C1RX = F5,  pps.

    // C1TX = A14, pps.

    ao_sys_unlock_pps(&l);
    {
        C1RXR = 0b0010;

        RPA14R = 0b1111;
    }
    ao_sys_lock_pps(&l);
}

// ----------------------------------------------------------------------------

#endif

#if defined AO_MIKROE_2674

// ----------------------------------------------------------------------------

static  void    ao_boot_mikroe_2674_1();

static  void    ao_boot_mikroe_2674_2();

// ----------------------------------------------------------------------------

void ao_boot_mikroe_2674()
{

#if AO_MIKROE_2674_1

    ao_boot_mikroe_2674_1();

#endif

#if AO_MIKROE_2674_2

    ao_boot_mikroe_2674_2();

#endif

}

// ----------------------------------------------------------------------------

void ao_boot_mikroe_2674_1()
{
    // Variables.

    ao_sys_lock_pps_t l;

    ao_uart_reg_t * r = ao_uart_reg_2();


    // Pins.

    // PWREN = B2, in,  active high.

    // SLEEP = C2, in,  active low.

    // U2RX  = E9, pps.

    // U2TX  = E8, pps.

    ANSELBCLR = _ANSELB_ANSB2_MASK;

    ANSELCCLR = _ANSELC_ANSC2_MASK;

    ANSELECLR = _ANSELE_ANSE8_MASK;

    ANSELECLR = _ANSELE_ANSE9_MASK;

    TRISBSET = _TRISB_TRISB2_MASK;

    TRISCSET = _TRISC_TRISC2_MASK;

    ao_sys_unlock_pps(&l);
    {
        U2RXR = 0b1101;

        RPE8R = 0b0010;
    }
    ao_sys_lock_pps(&l);


    // UART.

    r->mode.bits.clksel = 0b00;

    r->mode.bits.rtsmd = 0;

    r->mode.bits.rxinv = 0;

    r->mode.bits.uen = 0b00;

    r->sta.bits.utxinv = 0;
}

void ao_boot_mikroe_2674_2()
{
    // Variables.

    ao_sys_lock_pps_t l;

    ao_uart_reg_t * r = ao_uart_reg_3();


    // Pins.

    // PWREN = B14, in,  active high.

    // SLEEP = D9,  in,  active low.

    // U3RX  = F5,  pps.

    // U3TX  = A14, pps.

    ANSELBCLR = _ANSELB_ANSB14_MASK;

    TRISBSET = _TRISB_TRISB14_MASK;

    TRISDSET = _TRISD_TRISD9_MASK;

    ao_sys_unlock_pps(&l);
    {
        U3RXR = 0b0010;

        RPA14R = 0b0001;
    }
    ao_sys_lock_pps(&l);


    // UART.

    r->mode.bits.clksel = 0b00;

    r->mode.bits.rtsmd = 0;

    r->mode.bits.rxinv = 0;

    r->mode.bits.uen = 0b00;

    r->sta.bits.utxinv = 0;
}

// ----------------------------------------------------------------------------

bool ao_mikroe_2674_suspended(size_t i)
{
    switch (i)
    {

#if AO_MIKROE_2674_1

        case AO_MIKROE_1:

            return (PORTB & _PORTB_RB2_MASK) ? true : false;

#endif

#if AO_MIKROE_2674_2

        case AO_MIKROE_2:

            return (PORTB & _PORTB_RB14_MASK) ? true : false;

#endif

        default:

            ao_assert(false);

            return false;
    }
}

// ----------------------------------------------------------------------------

#endif

#if defined AO_MIKROE_2935_1 && AO_MIKROE_2935_1

// ----------------------------------------------------------------------------

static  void                    ao_boot_mikroe_2935_1();

// ----------------------------------------------------------------------------

static  void                    ao_mikroe_2935_spi_begin_1();

static  void                    ao_mikroe_2935_spi_end_1();

// ----------------------------------------------------------------------------

static  ao_mikroe_2935_spi_t    ao_mikroe_2935_spi_1 =
{
        .begin                  = ao_mikroe_2935_spi_begin_1,

        .end                    = ao_mikroe_2935_spi_end_1,

        .f                      = AO_MIKROE_2935_BAUD_1,

        .f_pbclk                = AO_SYS_CLOCK_SPI2,

        .reg                    = ao_spi_reg_2()
};

// ----------------------------------------------------------------------------

        ao_task_t               ao_mikroe_2935_task_1;

// ----------------------------------------------------------------------------

static  ao_mikroe_2935_mod_t    ao_mikroe_2935_mod_1 =
{
        .i                      = AO_MIKROE_1,

        .period                 = AO_MIKROE_2935_PERIOD_1,

        .repetitions_xy         = AO_MIKROE_2935_REPETITIONS_XY_1,

        .repetitions_z          = AO_MIKROE_2935_REPETITIONS_Z_1,

        .spi                    = &ao_mikroe_2935_spi_1,

        .task                   = &ao_mikroe_2935_task_1
};

// ----------------------------------------------------------------------------

void ao_boot_mikroe_2935_1()
{
    // Variables.

    ao_sys_lock_pps_t l;


    // Pins.

    // SCK2 = G6.

    // SDI2 = C4, pps.

    // SDO2 = C1, pps.

    // SS2  = C2, out, active low.

    ANSELCCLR = _ANSELC_ANSC1_MASK;

    ANSELCCLR = _ANSELC_ANSC2_MASK;

    ANSELCCLR = _ANSELC_ANSC4_MASK;

    TRISCCLR = _TRISC_TRISC2_MASK;

    ao_sys_unlock_pps(&l);
    {
        SDI2R = 0b1010;

        RPC1R = 0b0110;
    }
    ao_sys_lock_pps(&l);


    // Device.

    ao_boot_mikroe_2935_spi(&ao_mikroe_2935_spi_1);
}

// ----------------------------------------------------------------------------

void ao_mikroe_2935_spi_begin_1()
{
    LATCCLR = _LATC_LATC2_MASK;
}

void ao_mikroe_2935_spi_end_1()
{
    LATCSET = _LATC_LATC2_MASK;
}

// ----------------------------------------------------------------------------

#endif

#if defined AO_MIKROE_2935_2 && AO_MIKROE_2935_2

// ----------------------------------------------------------------------------

static  void                    ao_boot_mikroe_2935_2();

// ----------------------------------------------------------------------------

static  void                    ao_mikroe_2935_spi_begin_2();

static  void                    ao_mikroe_2935_spi_end_2();

// ----------------------------------------------------------------------------

static  ao_mikroe_2935_spi_t    ao_mikroe_2935_spi_2 =
{
        .begin                  = ao_mikroe_2935_spi_begin_2,

        .end                    = ao_mikroe_2935_spi_end_2,

        .f                      = AO_MIKROE_2935_BAUD_2,

        .f_pbclk                = AO_SYS_CLOCK_SPI4,

        .reg                    = ao_spi_reg_4()
};

// ----------------------------------------------------------------------------

        ao_task_t               ao_mikroe_2935_task_2;

// ----------------------------------------------------------------------------

static  ao_mikroe_2935_mod_t    ao_mikroe_2935_mod_2 =
{
        .i                      = AO_MIKROE_2,

        .period                 = AO_MIKROE_2935_PERIOD_2,

        .repetitions_xy         = AO_MIKROE_2935_REPETITIONS_XY_2,

        .repetitions_z          = AO_MIKROE_2935_REPETITIONS_Z_2,

        .spi                    = &ao_mikroe_2935_spi_2,

        .task                   = &ao_mikroe_2935_task_2
};

// ----------------------------------------------------------------------------

void ao_boot_mikroe_2935_2()
{
    // Variables.

    ao_sys_lock_pps_t l;


    // Pins.

    // SCK4 = D10.

    // SDI4 = D11, pps.

    // SDO4 = A15, pps.

    // SS4  = D9, out, active low.

    TRISDCLR = _TRISD_TRISD9_MASK;

    ao_sys_unlock_pps(&l);
    {
        SDI4R = 0b0011;

        RPA15R = 0b1000;
    }
    ao_sys_lock_pps(&l);


    // Device.

    ao_boot_mikroe_2935_spi(&ao_mikroe_2935_spi_2);
}

// ----------------------------------------------------------------------------

void ao_mikroe_2935_spi_begin_2()
{
    LATDCLR = _LATD_LATD9_MASK;
}

void ao_mikroe_2935_spi_end_2()
{
    LATDSET = _LATD_LATD9_MASK;
}

// ----------------------------------------------------------------------------

#endif

#if defined AO_MIKROE_2935

// ----------------------------------------------------------------------------

void ao_boot_mikroe_2935()
{

#if AO_MIKROE_2935_1

    ao_boot_mikroe_2935_1();

#endif

#if AO_MIKROE_2935_2

    ao_boot_mikroe_2935_2();

#endif

}

// ----------------------------------------------------------------------------

ao_mikroe_2935_mod_t * ao_mikroe_2935_mod(size_t i)
{
    switch (i)
    {

#if AO_MIKROE_2935_1

        case AO_MIKROE_1:

            return &ao_mikroe_2935_mod_1;

#endif

#if AO_MIKROE_2935_2

        case AO_MIKROE_2:

            return &ao_mikroe_2935_mod_2;

#endif

        default:

            ao_assert(false);

            return NULL;
    }
}

// ----------------------------------------------------------------------------

#endif

#if defined AO_MIKROE_2950_1 && AO_MIKROE_2950_1

// ----------------------------------------------------------------------------

static  void                    ao_boot_mikroe_2950_1();

// ----------------------------------------------------------------------------

static  ao_mikroe_2950_i2c_t    ao_mikroe_2950_i2c_1 =
{
        .f                      = AO_MIKROE_2950_BAUD_1,

        .f_pbclk                = AO_SYS_CLOCK_I2C4,

        .reg                    = ao_i2c_reg_4()
};

// ----------------------------------------------------------------------------

void ao_boot_mikroe_2950_1()
{
    // Pins.

    // SCL4 = G8.

    // SDA4 = G7.

    ANSELGCLR = _ANSELG_ANSG7_MASK;

    ANSELGCLR = _ANSELG_ANSG8_MASK;


    // Device.

    ao_boot_mikroe_2950_i2c(&ao_mikroe_2950_i2c_1);
}

// ----------------------------------------------------------------------------

#endif

#if defined AO_MIKROE_2950_2 && AO_MIKROE_2950_2

// ----------------------------------------------------------------------------

static  void                    ao_boot_mikroe_2950_2();

// ----------------------------------------------------------------------------

static  ao_mikroe_2950_i2c_t    ao_mikroe_2950_i2c_2 =
{
        .f                      = AO_MIKROE_2950_BAUD_2,

        .f_pbclk                = AO_SYS_CLOCK_I2C2,

        .reg                    = ao_i2c_reg_2()
};

// ----------------------------------------------------------------------------

void ao_boot_mikroe_2950_2()
{
    // Pins.

    // SCL2 = A2.

    // SDA2 = A3.


    // Device.

    ao_boot_mikroe_2950_i2c(&ao_mikroe_2950_i2c_2);
}

// ----------------------------------------------------------------------------

#endif

#if defined AO_MIKROE_2950

// ----------------------------------------------------------------------------

void ao_boot_mikroe_2950()
{

#if AO_MIKROE_2950_1

    ao_boot_mikroe_2950_1();

#endif

#if AO_MIKROE_2950_2

    ao_boot_mikroe_2950_2();

#endif

}

// ----------------------------------------------------------------------------

void * ao_mikroe_2950_i2c(size_t i)
{
    switch (i)
    {

#if AO_MIKROE_2950_1

        case AO_MIKROE_1:

            return &ao_mikroe_2950_i2c_1;

#endif

#if AO_MIKROE_2950_2

        case AO_MIKROE_2:

            return &ao_mikroe_2950_i2c_2;

#endif

        default:

            ao_assert(false);

            return NULL;
    }
}

// ----------------------------------------------------------------------------

#endif

#if defined AO_MIKROE_3063

// ----------------------------------------------------------------------------

static  void    ao_boot_mikroe_3063_1();

static  void    ao_boot_mikroe_3063_2();

// ----------------------------------------------------------------------------

void ao_boot_mikroe_3063()
{

#if AO_MIKROE_3063_1

    ao_boot_mikroe_3063_1();

#endif

#if AO_MIKROE_3063_2

    ao_boot_mikroe_3063_2();

#endif

}

// ----------------------------------------------------------------------------

void ao_boot_mikroe_3063_1()
{
    // Variables.

    ao_sys_lock_pps_t l;

    ao_uart_reg_t * r = ao_uart_reg_2();


    // Pins.

    // RESET   = B3, out, active low.

    // SUSPEND = B4, in,  active high.

    // U2RX    = E9, pps.

    // U2TX    = E8, pps.

    // WAKEUP  = B2, out, active low.

    ANSELBCLR = _ANSELB_ANSB2_MASK;

    ANSELBCLR = _ANSELB_ANSB3_MASK;

    ANSELBCLR = _ANSELB_ANSB4_MASK;

    ANSELECLR = _ANSELE_ANSE8_MASK;

    ANSELECLR = _ANSELE_ANSE9_MASK;

    TRISBCLR = _TRISB_TRISB2_MASK;

    TRISBCLR = _TRISB_TRISB3_MASK;

    TRISBSET = _TRISB_TRISB4_MASK;

    ao_sys_unlock_pps(&l);
    {
        U2RXR = 0b1101;

        RPE8R = 0b0010;
    }
    ao_sys_lock_pps(&l);


    // UART.

    r->mode.bits.clksel = 0b00;

    r->mode.bits.rtsmd = 0;

    r->mode.bits.rxinv = 0;

    r->mode.bits.uen = 0b00;

    r->sta.bits.utxinv = 0;


    // Clickboard.

    ao_mikroe_3063_reset_disable(AO_MIKROE_1);

    ao_mikroe_3063_wakeup_disable(AO_MIKROE_1);
}

void ao_boot_mikroe_3063_2()
{
    // Variables.

    ao_sys_lock_pps_t l;

    ao_uart_reg_t * r = ao_uart_reg_3();


    // Pins.

    // RESET   = A10, out, active low.

    // SUSPEND = B13, in,  active high.

    // U3RX    = F5,  pps.

    // U3TX    = A14, pps.

    // WAKEUP  = B14, out, active low.

    ANSELACLR = _ANSELA_ANSA10_MASK;

    ANSELBCLR = _ANSELB_ANSB13_MASK;

    ANSELBCLR = _ANSELB_ANSB14_MASK;

    TRISACLR = _TRISA_TRISA10_MASK;

    TRISBSET = _TRISB_TRISB13_MASK;

    TRISBCLR = _TRISB_TRISB14_MASK;

    ao_sys_unlock_pps(&l);
    {
        U3RXR = 0b0010;

        RPA14R = 0b0001;
    }
    ao_sys_lock_pps(&l);


    // UART.

    r->mode.bits.clksel = 0b00;

    r->mode.bits.rtsmd = 0;

    r->mode.bits.rxinv = 0;

    r->mode.bits.uen = 0b00;

    r->sta.bits.utxinv = 0;


    // Clickboard.

    ao_mikroe_3063_reset_disable(AO_MIKROE_2);

    ao_mikroe_3063_wakeup_disable(AO_MIKROE_2);
}

// ----------------------------------------------------------------------------

void ao_mikroe_3063_reset_disable(size_t i)
{
    switch (i)
    {

#if AO_MIKROE_3063_1

        case AO_MIKROE_1:

            LATBSET = _LATB_LATB3_MASK;

            break;

#endif

#if AO_MIKROE_3063_2

        case AO_MIKROE_2:

            LATASET = _LATA_LATA10_MASK;

            break;

#endif

        default:

            ao_assert(false);

            break;
    }
}

void ao_mikroe_3063_reset_enable(size_t i)
{
    switch (i)
    {

#if AO_MIKROE_3063_1

        case AO_MIKROE_1:

            LATBCLR = _LATB_LATB3_MASK;

            break;

#endif

#if AO_MIKROE_3063_2

        case AO_MIKROE_2:

            LATACLR = _LATA_LATA10_MASK;;

            break;

#endif

        default:

            ao_assert(false);

            break;
    }
}

// ----------------------------------------------------------------------------

bool ao_mikroe_3063_suspended(size_t i)
{
    switch (i)
    {

#if AO_MIKROE_3063_1

        case AO_MIKROE_1:

            return (PORTB & _PORTB_RB4_MASK) ? true : false;

#endif

#if AO_MIKROE_3063_2

        case AO_MIKROE_2:

            return (PORTB & _PORTB_RB13_MASK) ? true : false;

#endif

        default:

            ao_assert(false);

            return false;
    }
}

// ----------------------------------------------------------------------------

void ao_mikroe_3063_wakeup_disable(size_t i)
{
    switch (i)
    {

#if AO_MIKROE_3063_1

        case AO_MIKROE_1:

            LATBSET = _LATB_LATB2_MASK;

            break;

#endif

#if AO_MIKROE_3063_2

        case AO_MIKROE_2:

            LATBSET = _LATB_LATB14_MASK;

            break;

#endif

        default:

            ao_assert(false);

            break;
    }
}

void ao_mikroe_3063_wakeup_enable(size_t i)
{
    switch (i)
    {

#if AO_MIKROE_3063_1

        case AO_MIKROE_1:

            LATBCLR = _LATB_LATB2_MASK;

            break;

#endif

#if AO_MIKROE_3063_2

        case AO_MIKROE_2:

            LATBCLR = _LATB_LATB14_MASK;

            break;

#endif

        default:

            ao_assert(false);

            break;
    }
}

// ----------------------------------------------------------------------------

#endif

#if defined AO_MIKROE_4186_1 && AO_MIKROE_4186_1

// ----------------------------------------------------------------------------

static  void                    ao_boot_mikroe_4186_1();

// ----------------------------------------------------------------------------

static  ao_mikroe_4186_i2c_t    ao_mikroe_4186_i2c_1 =
{
        .f                      = AO_MIKROE_4186_BAUD_1,

        .f_pbclk                = AO_SYS_CLOCK_I2C4,

        .reg                    = ao_i2c_reg_4(),

        .timeout                = AO_MIKROE_4186_TIMEOUT_1
};

// ----------------------------------------------------------------------------

void ao_boot_mikroe_4186_1()
{
    // Variables.

    ao_sys_lock_pps_t l;


    // Interrupt.

    ao_ir_int4_falling();


    // Pins.

    // INT4  = B1, pps.

    // RESET = B3, out, active low.

    // SCL4  = G8.

    // SDA4  = G7.

    ANSELBCLR = _ANSELB_ANSB1_MASK;

    ANSELBCLR = _ANSELB_ANSB3_MASK;

    ANSELGCLR = _ANSELG_ANSG7_MASK;

    ANSELGCLR = _ANSELG_ANSG8_MASK;

    TRISBCLR = _TRISB_TRISB3_MASK;


    // Pins.

    ao_mikroe_4186_reset_disable(AO_MIKROE_1);


    // Pins.

    ao_sys_unlock_pps(&l);
    {
        INT4R = 0b0101;
    }
    ao_sys_lock_pps(&l);


    // I2C.

    ao_boot_mikroe_4186_i2c(&ao_mikroe_4186_i2c_1);
}

// ----------------------------------------------------------------------------

AO_IR_INT4_ATTRIBUTE
void ao_ir_int4()
{
    ao_ir_stack_func1((void *) AO_MIKROE_1, (ao_func1_t) ao_mikroe_4186_int);

    ao_ir_int4_reply();
}

// ----------------------------------------------------------------------------

#endif

#if defined AO_MIKROE_4186_2 && AO_MIKROE_4186_2

// ----------------------------------------------------------------------------

static  void                    ao_boot_mikroe_4186_2();

// ----------------------------------------------------------------------------

static  ao_mikroe_4186_i2c_t    ao_mikroe_4186_i2c_2 =
{
        .f                      = AO_MIKROE_4186_BAUD_2,

        .f_pbclk                = AO_SYS_CLOCK_I2C2,

        .reg                    = ao_i2c_reg_2(),

        .timeout                = AO_MIKROE_4186_TIMEOUT_2
};

// ----------------------------------------------------------------------------

void ao_boot_mikroe_4186_2()
{
    // Variables.

    ao_sys_lock_pps_t l;


    // Interrupt.

    ao_ir_int2_falling();


    // Pins.

    // INT2  = B15, pps.

    // RESET = A10, out, active low.

    // SCL2  = A2.

    // SDA2  = A3.

    ANSELACLR = _ANSELA_ANSA10_MASK;

    ANSELBCLR = _ANSELB_ANSB15_MASK;

    TRISACLR = _TRISA_TRISA10_MASK;


    // Pins.

    ao_mikroe_4186_reset_disable(AO_MIKROE_2);


    // Pins.

    ao_sys_unlock_pps(&l);
    {
        INT2R = 0b0011;
    }
    ao_sys_lock_pps(&l);


    // I2C.

    ao_boot_mikroe_4186_i2c(&ao_mikroe_4186_i2c_2);
}

// ----------------------------------------------------------------------------

AO_IR_INT2_ATTRIBUTE
void ao_ir_int2()
{
    ao_ir_stack_func1((void *) AO_MIKROE_2, (ao_func1_t) ao_mikroe_4186_int);

    ao_ir_int2_reply();
}

// ----------------------------------------------------------------------------

#endif

#if defined AO_MIKROE_4186

// ----------------------------------------------------------------------------

void ao_boot_mikroe_4186()
{

#if AO_MIKROE_4186_1

    ao_boot_mikroe_4186_1();

#endif

#if AO_MIKROE_4186_2

    ao_boot_mikroe_4186_2();

#endif

}

// ----------------------------------------------------------------------------

ao_mikroe_4186_i2c_t * ao_mikroe_4186_i2c(size_t i)
{
    switch (i)
    {

#if AO_MIKROE_4186_1

        case AO_MIKROE_1:

            return &ao_mikroe_4186_i2c_1;

#endif

#if AO_MIKROE_4186_2

        case AO_MIKROE_2:

            return &ao_mikroe_4186_i2c_2;

#endif

        default:

            ao_assert(false);

            return NULL;
    }
}

// ----------------------------------------------------------------------------

void ao_mikroe_4186_int_disable(size_t i)
{
    switch (i)
    {

#if AO_MIKROE_4186_1

        case AO_MIKROE_1:

            ao_ir_int4_disable();

            break;

#endif

#if AO_MIKROE_4186_2

        case AO_MIKROE_2:

            ao_ir_int2_disable();

            break;

#endif

        default:

            ao_assert(false);

            break;
    }
}

void ao_mikroe_4186_int_enable(size_t i)
{
    switch (i)
    {

#if AO_MIKROE_4186_1

        case AO_MIKROE_1:

            ao_ir_int4_enable();

            break;

#endif

#if AO_MIKROE_4186_2

        case AO_MIKROE_2:

            ao_ir_int2_enable();

            break;

#endif

        default:

            ao_assert(false);

            break;
    }
}

// ----------------------------------------------------------------------------

void ao_mikroe_4186_reset_disable(size_t i)
{
    switch (i)
    {

#if AO_MIKROE_4186_1

        case AO_MIKROE_1:

            LATBSET = _LATB_LATB3_MASK;

            break;

#endif

#if AO_MIKROE_4186_2

        case AO_MIKROE_2:

            LATASET = _LATA_LATA10_MASK;

            break;

#endif

        default:

            ao_assert(false);

            break;
    }
}

void ao_mikroe_4186_reset_enable(size_t i)
{
    switch (i)
    {

#if AO_MIKROE_4186_1

        case AO_MIKROE_1:

            LATBCLR = _LATB_LATB3_MASK;

            break;

#endif

#if AO_MIKROE_4186_2

        case AO_MIKROE_2:

            LATACLR = _LATA_LATA10_MASK;

            break;

#endif

        default:

            ao_assert(false);

            break;
    }
}

// ----------------------------------------------------------------------------

#endif

#if defined AO_SYS_CONFIG

#if defined AO_SYS_CONFIG_BOOTISA

// ----------------------------------------------------------------------------

// DEVCFG0.BOOTISA

// Boot ISA Selection.

// ----------------------------------------------------------------------------

#if 0

#pragma config BOOTISA = MIPS32
#pragma config BOOTISA = MICROMIPS

#endif

// ----------------------------------------------------------------------------

#endif

#if defined AO_SYS_CONFIG_CP

// ----------------------------------------------------------------------------

// DEVCP0.CP

// Code Protect.

// ----------------------------------------------------------------------------

#if 0

#pragma config CP = ON
#pragma config CP = OFF

#endif

// ----------------------------------------------------------------------------

#endif

#if defined AO_SYS_CONFIG_CSEQ

// ----------------------------------------------------------------------------

// SEQ3.CSEQ

// Boot Flash Complement Sequence Number.

// ----------------------------------------------------------------------------

#if 0

#pragma config CSEQ = 0x0000
#pragma config CSEQ = 0xFFFF

#endif

// ----------------------------------------------------------------------------

#endif

#if defined AO_SYS_CONFIG_DBGPER

// ----------------------------------------------------------------------------

// DEVCFG0.DBGPER

// Debug Mode CPU Access Permission.

// ----------------------------------------------------------------------------

#if 0

#pragma config DBGPER = ALLOW_PG2
#pragma config DBGPER = ALLOW_PG1
#pragma config DBGPER = ALLOW_PG0
#pragma config DBGPER = PG_1_0
#pragma config DBGPER = PG_2_0
#pragma config DBGPER = PG_2_1
#pragma config DBGPER = PG_ALL
#pragma config DBGPER = PG_NONE

#endif

// ----------------------------------------------------------------------------

#endif

#if defined AO_SYS_CONFIG_DEBUG

// ----------------------------------------------------------------------------

// DEVCFG0.DEBUG

// Background Debugger Enable.

// ----------------------------------------------------------------------------

#if 0

#pragma config DEBUG = ON
#pragma config DEBUG = OFF

#endif

// ----------------------------------------------------------------------------

#endif

#if defined AO_SYS_CONFIG_DMTCNT

// ----------------------------------------------------------------------------

// DEVCFG1.DMTCNT

// Deadman Timer Count Select.

// ----------------------------------------------------------------------------

#pragma config DMTCNT = DMT31

// ----------------------------------------------------------------------------

#if 0

#pragma config DMTCNT = DMT8
#pragma config DMTCNT = DMT9
#pragma config DMTCNT = DMT10
#pragma config DMTCNT = DMT11
#pragma config DMTCNT = DMT12
#pragma config DMTCNT = DMT13
#pragma config DMTCNT = DMT14
#pragma config DMTCNT = DMT15
#pragma config DMTCNT = DMT16
#pragma config DMTCNT = DMT17
#pragma config DMTCNT = DMT18
#pragma config DMTCNT = DMT19
#pragma config DMTCNT = DMT20
#pragma config DMTCNT = DMT21
#pragma config DMTCNT = DMT22
#pragma config DMTCNT = DMT23
#pragma config DMTCNT = DMT24
#pragma config DMTCNT = DMT25
#pragma config DMTCNT = DMT26
#pragma config DMTCNT = DMT27
#pragma config DMTCNT = DMT28
#pragma config DMTCNT = DMT29
#pragma config DMTCNT = DMT30
#pragma config DMTCNT = DMT31

#endif

// ----------------------------------------------------------------------------

#endif

#if defined AO_SYS_CONFIG_DMTINTV

// ----------------------------------------------------------------------------

// DEVCFG1.DMTINTV

// Deadman Timer Count Window Interval.

// ----------------------------------------------------------------------------

#if 0

#pragma config DMTINTV = WIN_0
#pragma config DMTINTV = WIN_1_2
#pragma config DMTINTV = WIN_3_4
#pragma config DMTINTV = WIN_7_8
#pragma config DMTINTV = WIN_15_16
#pragma config DMTINTV = WIN_31_32
#pragma config DMTINTV = WIN_63_64
#pragma config DMTINTV = WIN_127_128

#endif

// ----------------------------------------------------------------------------

#endif

#if defined AO_SYS_CONFIG_EJTAGBEN

// ----------------------------------------------------------------------------

// DEVCFG0.EJTAGBEN

// EJTAG Boot Enable.

// ----------------------------------------------------------------------------

#if 0

#pragma config EJTAGBEN = NORMAL
#pragma config EJTAGBEN = REDUCED

#endif

// ----------------------------------------------------------------------------

#endif

#if defined AO_SYS_CONFIG_FCKSM

// ----------------------------------------------------------------------------

// DEVCFG1.FCKSM

// Clock Switching and Monitoring Selection Configuration.

// ----------------------------------------------------------------------------

#pragma config FCKSM = CSECME

// ----------------------------------------------------------------------------

#if 0

#pragma config FCKSM = CSDCMD
#pragma config FCKSM = CSDCME
#pragma config FCKSM = CSECMD
#pragma config FCKSM = CSECME

#endif

// ----------------------------------------------------------------------------

#endif

#if defined AO_SYS_CONFIG_FDMTEN

// ----------------------------------------------------------------------------

// DEVCFG1.FDMTEN

// Deadman Timer Enable.

// ----------------------------------------------------------------------------

#pragma config FDMTEN = OFF

// ----------------------------------------------------------------------------

#if 0

#pragma config FDMTEN = OFF
#pragma config FDMTEN = ON

#endif

// ----------------------------------------------------------------------------

#endif

#if defined AO_SYS_CONFIG_FECCCON

// ----------------------------------------------------------------------------

// DEVCFG0.FECCCON

// Dynamic Flash ECC Configuration.

// ----------------------------------------------------------------------------

#if 0

#pragma config FECCCON = ON
#pragma config FECCCON = DYNAMIC
#pragma config FECCCON = OFF_LOCKED
#pragma config FECCCON = OFF_UNLOCKED

#endif

// ----------------------------------------------------------------------------

#endif

#if defined AO_SYS_CONFIG_FETHIO

// ----------------------------------------------------------------------------

// DEVCFG3.FETHIO

// Ethernet I/O Pin Selection Configuration.

// ----------------------------------------------------------------------------

#if 0

#pragma config FETHIO = OFF
#pragma config FETHIO = ON

#endif

// ----------------------------------------------------------------------------

#endif

#if defined AO_SYS_CONFIG_FMIIEN

// ----------------------------------------------------------------------------

// DEVCFG3.FMIIEN

// Ethernet MII Enable Configuration.

// ----------------------------------------------------------------------------

#if 0

#pragma config FMIIEN = OFF
#pragma config FMIIEN = ON

#endif

// ----------------------------------------------------------------------------

#endif

#if defined AO_SYS_CONFIG_FNOSC

// ----------------------------------------------------------------------------

// DEVCFG1.FNOSC

// Oscillator Selection.

// ----------------------------------------------------------------------------

#pragma config FNOSC = SPLL

// ----------------------------------------------------------------------------

#if 0

#pragma config FNOSC = FRCDIV
#pragma config FNOSC = LPRC
#pragma config FNOSC = POSC
#pragma config FNOSC = SOSC
#pragma config FNOSC = SPLL

#endif

// ----------------------------------------------------------------------------

#endif

#if defined AO_SYS_CONFIG_FPLLICLK

// ----------------------------------------------------------------------------

// DEVCFG2.FPLLICLK

// System PLL Input Clock Select.

// ----------------------------------------------------------------------------

#pragma config FPLLICLK = PLL_POSC

// ----------------------------------------------------------------------------

#if 0

#pragma config FPLLICLK = PLL_FRC
#pragma config FPLLICLK = PLL_POSC

#endif

// ----------------------------------------------------------------------------

#endif

#if defined AO_SYS_CONFIG_FPLLIDIV

// ----------------------------------------------------------------------------

// DEVCFG2.FPLLIDIV

// PLL Input Divider.

// ----------------------------------------------------------------------------

#pragma config FPLLIDIV = DIV_3

// ----------------------------------------------------------------------------

#if 0

#pragma config FPLLIDIV = DIV_1
#pragma config FPLLIDIV = DIV_2
#pragma config FPLLIDIV = DIV_3
#pragma config FPLLIDIV = DIV_4
#pragma config FPLLIDIV = DIV_5
#pragma config FPLLIDIV = DIV_6
#pragma config FPLLIDIV = DIV_7
#pragma config FPLLIDIV = DIV_8

#endif

// ----------------------------------------------------------------------------

#endif

#if defined AO_SYS_CONFIG_FPLLMULT

// ----------------------------------------------------------------------------

// DEVCFG2.FPLLMULT

// System PLL Feedback Divider.

// ----------------------------------------------------------------------------

#pragma config FPLLMULT = MUL_50

// ----------------------------------------------------------------------------

#if 0

#pragma config FPLLMULT = MUL_1
#pragma config FPLLMULT = MUL_2
#pragma config FPLLMULT = MUL_3
#pragma config FPLLMULT = MUL_4
#pragma config FPLLMULT = MUL_5
#pragma config FPLLMULT = MUL_6
#pragma config FPLLMULT = MUL_7
#pragma config FPLLMULT = MUL_8
#pragma config FPLLMULT = MUL_9
#pragma config FPLLMULT = MUL_10
#pragma config FPLLMULT = MUL_11
#pragma config FPLLMULT = MUL_12
#pragma config FPLLMULT = MUL_13
#pragma config FPLLMULT = MUL_14
#pragma config FPLLMULT = MUL_15
#pragma config FPLLMULT = MUL_16
#pragma config FPLLMULT = MUL_17
#pragma config FPLLMULT = MUL_18
#pragma config FPLLMULT = MUL_19
#pragma config FPLLMULT = MUL_20
#pragma config FPLLMULT = MUL_21
#pragma config FPLLMULT = MUL_22
#pragma config FPLLMULT = MUL_23
#pragma config FPLLMULT = MUL_24
#pragma config FPLLMULT = MUL_25
#pragma config FPLLMULT = MUL_26
#pragma config FPLLMULT = MUL_27
#pragma config FPLLMULT = MUL_28
#pragma config FPLLMULT = MUL_29
#pragma config FPLLMULT = MUL_30
#pragma config FPLLMULT = MUL_31
#pragma config FPLLMULT = MUL_32
#pragma config FPLLMULT = MUL_33
#pragma config FPLLMULT = MUL_34
#pragma config FPLLMULT = MUL_35
#pragma config FPLLMULT = MUL_36
#pragma config FPLLMULT = MUL_37
#pragma config FPLLMULT = MUL_38
#pragma config FPLLMULT = MUL_39
#pragma config FPLLMULT = MUL_40
#pragma config FPLLMULT = MUL_41
#pragma config FPLLMULT = MUL_42
#pragma config FPLLMULT = MUL_43
#pragma config FPLLMULT = MUL_44
#pragma config FPLLMULT = MUL_45
#pragma config FPLLMULT = MUL_46
#pragma config FPLLMULT = MUL_47
#pragma config FPLLMULT = MUL_48
#pragma config FPLLMULT = MUL_49
#pragma config FPLLMULT = MUL_50
#pragma config FPLLMULT = MUL_51
#pragma config FPLLMULT = MUL_52
#pragma config FPLLMULT = MUL_53
#pragma config FPLLMULT = MUL_54
#pragma config FPLLMULT = MUL_55
#pragma config FPLLMULT = MUL_56
#pragma config FPLLMULT = MUL_57
#pragma config FPLLMULT = MUL_58
#pragma config FPLLMULT = MUL_59
#pragma config FPLLMULT = MUL_60
#pragma config FPLLMULT = MUL_61
#pragma config FPLLMULT = MUL_62
#pragma config FPLLMULT = MUL_63
#pragma config FPLLMULT = MUL_64
#pragma config FPLLMULT = MUL_65
#pragma config FPLLMULT = MUL_66
#pragma config FPLLMULT = MUL_67
#pragma config FPLLMULT = MUL_68
#pragma config FPLLMULT = MUL_69
#pragma config FPLLMULT = MUL_70
#pragma config FPLLMULT = MUL_71
#pragma config FPLLMULT = MUL_72
#pragma config FPLLMULT = MUL_73
#pragma config FPLLMULT = MUL_74
#pragma config FPLLMULT = MUL_75
#pragma config FPLLMULT = MUL_76
#pragma config FPLLMULT = MUL_77
#pragma config FPLLMULT = MUL_78
#pragma config FPLLMULT = MUL_79
#pragma config FPLLMULT = MUL_80
#pragma config FPLLMULT = MUL_81
#pragma config FPLLMULT = MUL_82
#pragma config FPLLMULT = MUL_83
#pragma config FPLLMULT = MUL_84
#pragma config FPLLMULT = MUL_85
#pragma config FPLLMULT = MUL_86
#pragma config FPLLMULT = MUL_87
#pragma config FPLLMULT = MUL_88
#pragma config FPLLMULT = MUL_89
#pragma config FPLLMULT = MUL_90
#pragma config FPLLMULT = MUL_91
#pragma config FPLLMULT = MUL_92
#pragma config FPLLMULT = MUL_93
#pragma config FPLLMULT = MUL_94
#pragma config FPLLMULT = MUL_95
#pragma config FPLLMULT = MUL_96
#pragma config FPLLMULT = MUL_97
#pragma config FPLLMULT = MUL_98
#pragma config FPLLMULT = MUL_99
#pragma config FPLLMULT = MUL_100
#pragma config FPLLMULT = MUL_101
#pragma config FPLLMULT = MUL_102
#pragma config FPLLMULT = MUL_103
#pragma config FPLLMULT = MUL_104
#pragma config FPLLMULT = MUL_105
#pragma config FPLLMULT = MUL_106
#pragma config FPLLMULT = MUL_107
#pragma config FPLLMULT = MUL_108
#pragma config FPLLMULT = MUL_109
#pragma config FPLLMULT = MUL_110
#pragma config FPLLMULT = MUL_111
#pragma config FPLLMULT = MUL_112
#pragma config FPLLMULT = MUL_113
#pragma config FPLLMULT = MUL_114
#pragma config FPLLMULT = MUL_115
#pragma config FPLLMULT = MUL_116
#pragma config FPLLMULT = MUL_117
#pragma config FPLLMULT = MUL_118
#pragma config FPLLMULT = MUL_119
#pragma config FPLLMULT = MUL_120
#pragma config FPLLMULT = MUL_121
#pragma config FPLLMULT = MUL_122
#pragma config FPLLMULT = MUL_123
#pragma config FPLLMULT = MUL_124
#pragma config FPLLMULT = MUL_125
#pragma config FPLLMULT = MUL_126
#pragma config FPLLMULT = MUL_127
#pragma config FPLLMULT = MUL_128

#endif

// ----------------------------------------------------------------------------

#endif

#if defined AO_SYS_CONFIG_FPLLODIV

// ----------------------------------------------------------------------------

// DEVCFG2.FPLLODIV

// Default System PLL Output Divisor.

// ----------------------------------------------------------------------------

#pragma config FPLLODIV = DIV_2

// ----------------------------------------------------------------------------

#if 0

#pragma config FPLLODIV = DIV_2
#pragma config FPLLODIV = DIV_4
#pragma config FPLLODIV = DIV_8
#pragma config FPLLODIV = DIV_16
#pragma config FPLLODIV = DIV_32

#endif

// ----------------------------------------------------------------------------

#endif

#if defined AO_SYS_CONFIG_FPLLRNG

// ----------------------------------------------------------------------------

// DEVCFG2.FPLLRNG

// System PLL Divided Input Clock Frequency Range.

// ----------------------------------------------------------------------------

#pragma config FPLLRNG = RANGE_8_16_MHZ

// ----------------------------------------------------------------------------

#if 0

#pragma config FPLLRNG = RANGE_BYPASS
#pragma config FPLLRNG = RANGE_5_10_MHZ
#pragma config FPLLRNG = RANGE_8_16_MHZ
#pragma config FPLLRNG = RANGE_13_26_MHZ
#pragma config FPLLRNG = RANGE_21_42_MHZ
#pragma config FPLLRNG = RANGE_34_68_MHZ

#endif

// ----------------------------------------------------------------------------

#endif

#if defined AO_SYS_CONFIG_FSLEEP

// ----------------------------------------------------------------------------

// DEVCFG0.FSLEEP

// Flash Sleep Mode.

// ----------------------------------------------------------------------------

#if 0

#pragma config FSLEEP = OFF
#pragma config FSLEEP = VREGS

#endif

// ----------------------------------------------------------------------------

#endif

#if defined AO_SYS_CONFIG_FSOSCEN

// ----------------------------------------------------------------------------

// DEVCFG1.FSOSCEN

// Secondary Oscillator Enable.

// ----------------------------------------------------------------------------

#pragma config FSOSCEN = OFF

// ----------------------------------------------------------------------------

#if 0

#pragma config FSOSCEN = OFF
#pragma config FSOSCEN = ON

#endif

// ----------------------------------------------------------------------------

#endif

#if defined AO_SYS_CONFIG_FUSBIDIO

// ----------------------------------------------------------------------------

// DEVCFG3.FUSBIDIO

// USB USBID Selection.

// ----------------------------------------------------------------------------

#if 0

#pragma config FUSBIDIO = OFF
#pragma config FUSBIDIO = ON

#endif

// ----------------------------------------------------------------------------

#endif

#if defined AO_SYS_CONFIG_FWDTEN

// ----------------------------------------------------------------------------

// DEVCFG1.FWDTEN

// Watchdog Timer Enable.

// ----------------------------------------------------------------------------

#pragma config FWDTEN = OFF

// ----------------------------------------------------------------------------

#if 0

#pragma config FWDTEN = OFF
#pragma config FWDTEN = ON

#endif

// ----------------------------------------------------------------------------

#endif

#if defined AO_SYS_CONFIG_FWDTWINSZ

// ----------------------------------------------------------------------------

// DEVCFG1.FWDTWINSZ

// Watchdog Timer Window Size.

// ----------------------------------------------------------------------------

#if 0

#pragma config FWDTWINSZ = WINSZ_25
#pragma config FWDTWINSZ = WINSZ_37
#pragma config FWDTWINSZ = WINSZ_50
#pragma config FWDTWINSZ = WINSZ_75

#endif

// ----------------------------------------------------------------------------

#endif

#if defined AO_SYS_CONFIG_ICESEL

// ----------------------------------------------------------------------------

// DEVCFG0.ICESEL

// In-Circuit Emulator/Debugger Communication Channel Selection.

// ----------------------------------------------------------------------------

#pragma config ICESEL = ICS_PGx2

// ----------------------------------------------------------------------------

#if 0

#pragma config ICESEL = ICS_PGx1
#pragma config ICESEL = ICS_PGx2

#endif

// ----------------------------------------------------------------------------

#endif

#if defined AO_SYS_CONFIG_IESO

// ----------------------------------------------------------------------------

// DEVCFG1.IESO

// Internal External Switchover.

// ----------------------------------------------------------------------------

#pragma config IESO = OFF

// ----------------------------------------------------------------------------

#if 0

#pragma config IESO = OFF
#pragma config IESO = ON

#endif

// ----------------------------------------------------------------------------

#endif

#if defined AO_SYS_CONFIG_IOL1WAY

// ----------------------------------------------------------------------------

// DEVCFG3.IOL1WAY

// Peripheral Pin Select Configuration.

// ----------------------------------------------------------------------------

#if 0

#pragma config IOL1WAY = ON
#pragma config IOL1WAY = OFF

#endif

// ----------------------------------------------------------------------------

#endif

#if defined AO_SYS_CONFIG_JTAGEN

// ----------------------------------------------------------------------------

// DEVCFG0.JTAGEN

// JTAG Enable.

// ----------------------------------------------------------------------------

#pragma config JTAGEN = OFF

// ----------------------------------------------------------------------------

#if 0

#pragma config JTAGEN = ON
#pragma config JTAGEN = OFF

#endif

// ----------------------------------------------------------------------------

#endif

#if defined AO_SYS_CONFIG_OSCIOFNC

// ----------------------------------------------------------------------------

// DEVCFG1.OSCIOFNC

// CLKO Output Signal Active on the OSCO Pin.

// ----------------------------------------------------------------------------

#if 0

#pragma config OSCIOFNC = OFF
#pragma config OSCIOFNC = ON

#endif

// ----------------------------------------------------------------------------

#endif

#if defined AO_SYS_CONFIG_PGL1WAY

// ----------------------------------------------------------------------------

// DEVCFG3.PGL1WAY

// Permission Group Lock One Way Configuration.

// ----------------------------------------------------------------------------

#if 0

#pragma config PGL1WAY = ON
#pragma config PGL1WAY = OFF

#endif

// ----------------------------------------------------------------------------

#endif

#if defined AO_SYS_CONFIG_PMDL1WAY

// ----------------------------------------------------------------------------

// DEVCFG3.PMDL1WAY

// Peripheral Module Disable Configuration.

// ----------------------------------------------------------------------------

#if 0

#pragma config PMDL1WAY = ON
#pragma config PMDL1WAY = OFF

#endif

// ----------------------------------------------------------------------------

#endif

#if defined AO_SYS_CONFIG_POSCBOOST

// ----------------------------------------------------------------------------

// DEVCFG0.POSCBOOST

// Primary Oscillator Boost Kick Start Enable.

// ----------------------------------------------------------------------------

#if 0

#pragma config POSCBOOST = ON
#pragma config POSCBOOST = OFF

#endif

// ----------------------------------------------------------------------------

#endif

#if defined AO_SYS_CONFIG_POSCGAIN

// ----------------------------------------------------------------------------

// DEVCFG0.POSCGAIN

// Primary Oscillator Gain Control.

// ----------------------------------------------------------------------------

#if 0

#pragma config POSCGAIN = GAIN_2X
#pragma config POSCGAIN = GAIN_1_5X
#pragma config POSCGAIN = GAIN_0_5X
#pragma config POSCGAIN = GAIN_1X
#pragma config POSCGAIN = GAIN_LEVEL_3
#pragma config POSCGAIN = GAIN_LEVEL_2
#pragma config POSCGAIN = GAIN_LEVEL_1
#pragma config POSCGAIN = GAIN_LEVEL_0

#endif

// ----------------------------------------------------------------------------

#endif

#if defined AO_SYS_CONFIG_POSCMOD

// ----------------------------------------------------------------------------

// DEVCFG1.POSCMOD

// Primary Oscillator Configuration.

// ----------------------------------------------------------------------------

#pragma config POSCMOD = EC

// ----------------------------------------------------------------------------

#if 0

#pragma config POSCMOD = EC
#pragma config POSCMOD = HS
#pragma config POSCMOD = OFF

#endif

// ----------------------------------------------------------------------------

#endif

#if defined AO_SYS_CONFIG_SMCLR

// ----------------------------------------------------------------------------

// DEVCFG0.SMCLR

// Soft Master Clear Enable.

// ----------------------------------------------------------------------------

#if 0

#pragma config SMCLR = MCLR_NORM
#pragma config SMCLR = MCLR_POR

#endif

// ----------------------------------------------------------------------------

#endif

#if defined AO_SYS_CONFIG_SOSCBOOST

// ----------------------------------------------------------------------------

// DEVCFG0.SOSCBOOST

// Secondary Oscillator Boost Kick Start Enable.

// ----------------------------------------------------------------------------

#if 0

#pragma config SOSCBOOST = ON
#pragma config SOSCBOOST = OFF

#endif

// ----------------------------------------------------------------------------

#endif

#if defined AO_SYS_CONFIG_SOSCGAIN

// ----------------------------------------------------------------------------

// DEVCFG0.SOSCGAIN

// Secondary Oscillator Gain Control.

// ----------------------------------------------------------------------------

#if 0

#pragma config SOSCGAIN = GAIN_2X
#pragma config SOSCGAIN = GAIN_1_5X
#pragma config SOSCGAIN = GAIN_0_5X
#pragma config SOSCGAIN = GAIN_1X
#pragma config SOSCGAIN = GAIN_LEVEL_3
#pragma config SOSCGAIN = GAIN_LEVEL_2
#pragma config SOSCGAIN = GAIN_LEVEL_1
#pragma config SOSCGAIN = GAIN_LEVEL_0

#endif

// ----------------------------------------------------------------------------

#endif

#if defined AO_SYS_CONFIG_TRCEN

// ----------------------------------------------------------------------------

// DEVCFG0.TRCEN

// Trace Enable.

// ----------------------------------------------------------------------------

#pragma config TRCEN = OFF

// ----------------------------------------------------------------------------

#if 0

#pragma config TRCEN = ON
#pragma config TRCEN = OFF

#endif

// ----------------------------------------------------------------------------

#endif

#if defined AO_SYS_CONFIG_TSEQ

// ----------------------------------------------------------------------------

// SEQ3.TSEQ

// Boot Flash True Sequence Number.

// ----------------------------------------------------------------------------

#if 0

#pragma config TSEQ = 0x0000
#pragma config TSEQ = 0xFFFF

#endif

// ----------------------------------------------------------------------------

#endif

#if defined AO_SYS_CONFIG_UPLLFSEL

// ----------------------------------------------------------------------------

// DEVCFG2.UPLLFSEL

// USB PLL Input Frequency Select.

// ----------------------------------------------------------------------------

#if 0

#pragma config UPLLFSEL = FREQ_24MHZ
#pragma config UPLLFSEL = FREQ_12MHZ

#endif

// ----------------------------------------------------------------------------

#endif

#if defined AO_SYS_CONFIG_USERID

// ----------------------------------------------------------------------------

// DEVCFG3.USERID

// This is a 16-bit value that is user-defined and is readable via ICSP™ and
// JTAG.

// ----------------------------------------------------------------------------

#if 0

#pragma config USERID = 0x0000
#pragma config USERID = 0xFFFF

#endif

// ----------------------------------------------------------------------------

#endif

#if defined AO_SYS_CONFIG_WDTPS

// ----------------------------------------------------------------------------

// DEVCFG1.WDTPS

// Watchdog Timer Postscale Select.

// ----------------------------------------------------------------------------

#if 0

#pragma config WDTPS = PS1
#pragma config WDTPS = PS2
#pragma config WDTPS = PS4
#pragma config WDTPS = PS8
#pragma config WDTPS = PS16
#pragma config WDTPS = PS32
#pragma config WDTPS = PS64
#pragma config WDTPS = PS128
#pragma config WDTPS = PS256
#pragma config WDTPS = PS512
#pragma config WDTPS = PS1024
#pragma config WDTPS = PS2048
#pragma config WDTPS = PS4096
#pragma config WDTPS = PS8192
#pragma config WDTPS = PS16384
#pragma config WDTPS = PS32768
#pragma config WDTPS = PS65536
#pragma config WDTPS = PS131072
#pragma config WDTPS = PS262144
#pragma config WDTPS = PS524288
#pragma config WDTPS = PS1048576

#endif

// ----------------------------------------------------------------------------

#endif

#if defined AO_SYS_CONFIG_WDTSPGM

// ----------------------------------------------------------------------------

// DEVCFG1.WDTSPGM

// Watchdog Timer Stop During Flash Programming.

// ----------------------------------------------------------------------------

#if 0

#pragma config WDTSPGM = RUN
#pragma config WDTSPGM = STOP

#endif

// ----------------------------------------------------------------------------

#endif

#if defined AO_SYS_CONFIG_WINDIS

// ----------------------------------------------------------------------------

// DEVCFG1.WINDIS

// Watchdog Timer Window Enable.

// ----------------------------------------------------------------------------

#if 0

#pragma config WINDIS = NORMAL
#pragma config WINDIS = WINDOW

#endif

// ----------------------------------------------------------------------------

#endif

#endif

#if defined AO_SYS_EXC

#if AO_DEBUG

// ----------------------------------------------------------------------------

// @seeAlso

// Imagination Technologies.

// MIPS32® M5150 Processor Core Family Software User’s Manual.

// ----------------------------------------------------------------------------

void _general_exception_handler(uint32_t cause, uint32_t status)
{
    // Variables.

    ao_sys_exc_t code = (ao_sys_exc_t) ((cause & _CP0_CAUSE_EXCCODE_MASK) >> _CP0_CAUSE_EXCCODE_POSITION);

    (void) status;


    // Ready.

    switch (code)
    {
        case AO_SYS_EXC_INT:

            // Interrupt.

            // This really should not have happend.

            ao_break();

            break;

        case AO_SYS_EXC_MOD:

            // TLB modified.

            ao_break();

            break;

        case AO_SYS_EXC_TLBL:
        case AO_SYS_EXC_TLBS:

            // TLB invalid.

            ao_break();

            break;

        case AO_SYS_EXC_ADEL:
        case AO_SYS_EXC_ADES:

            // Address error.

            // An address error exception occurs on an instruction or data
            // access when an attempt is made to execute one of the following.

            // * Fetch an instruction, load a word, or store a word that is not
            //   aligned on a word boundary.

            // * Load or store a halfword that is not aligned on a halfword
            //   boundary.

            // * Reference the kernel address space from user mode.

            // Note that in the case of an instruction fetch that is not
            // aligned on a word boundary, PC is updated before the condition
            // is detected.

            // Therefore, both EPC and BadVAddr point to the unaligned
            // instruction address.

            // In the case of a data access the exception is taken if either an
            // unaligned address or an address that was inaccessible in the
            // current processor mode was referenced by a load or store
            // instruction.

            // Additional state saved.

            // * BadVAddr       Failing address.

            // * Context.VPN2   UNPREDICTABLE.

            // * EntryHi.VPN2   UNPREDICTABLE.

            // * EntryLo0       UNPREDICTABLE.

            // * EntryLo1       UNPREDICTABLE.

            ao_break();

            break;

        case AO_SYS_EXC_IBE:
        case AO_SYS_EXC_DBE:

            // Bus error.

            // A bus error exception occurs when an instruction or data access
            // makes a bus request (due to a cache miss or an uncacheable
            // reference) and that request terminates in an error.

            // The bus error exception can occur on either an instruction fetch
            // or a data access.

            // Bus error exceptions that occur on an instruction fetch have a
            // higher priority than bus error exceptions that occur on a data
            // access.

            // Bus errors taken on the requested (critical) word of an
            // instruction fetch or data load are precise. Other bus errors,
            // such as stores or non-critical words of a burst read, can be
            // imprecise. These errors are taken when an AHB slave responds
            // with an error code.

            // The M5150 family core does not support imprecise instruction
            // fetch bus error exceptions. Thus, when a slave signals a bus
            // error, this notification must be repeated for all similar
            // instruction fetches until the core has taken the exception.

            ao_break();

            break;

        case AO_SYS_EXC_SYS:

            // System call.

            // The system call exception is one of the execution exceptions.
            // All of these exceptions have the same priority.

            // A system call exception occurs when a SYSCALL instruction is
            // executed.

            ao_break();

            break;

        case AO_SYS_EXC_BP:

            // Breakpoint.

            // The breakpoint exception is one of the execution exceptions. All
            // of these exceptions have the same priority.

            // A breakpoint exception occurs when a BREAK instruction is
            // executed.

            ao_break();

            break;

        case AO_SYS_EXC_RI:

            // Reserved instruction.

            // The reserved instruction exception is one of the execution
            /// exceptions. All of these exceptions have the same priority.

            // A reserved instruction exception occurs when a reserved or
            // undefined major opcode or function field is executed.

            // This includes coprocessor 2 instructions which are decoded
            // reserved in the coprocessor 2.

            ao_break();

            break;

        case AO_SYS_EXC_CPU:

            // Coprocessor unusable.

            // The coprocessor unusable exception is one of the execution
            // exceptions. All of these exceptions have the same priority.

            // A coprocessor unusable exception occurs when an attempt is made
            // to execute a coprocessor instruction for one of the following.

            // * A corresponding coprocessor unit that has not been marked
            //   usable by setting its CU bit in the Status register.

            // * CP0 instructions, when the unit has not been marked usable,
            //   and the processor is executing in user mode.

            // Additional state saved.

            // * Cause.CE   Unit number of the coprocessor being referenced.

            ao_break();

            break;

        case AO_SYS_EXC_OV:

            // Integer overflow.

            // The integer overflow exception is one of the execution
            // exceptions. All of these exceptions have the same priority.

            // An integer overflow exception occurs when selected integer
            // instructions result in a 2’s complement overflow.

            ao_break();

            break;

        case AO_SYS_EXC_TR:

            // Trap.

            // The trap exception is one of the execution exceptions. All of
            // these exceptions have the same priority.

            // A trap exception occurs when a trap instruction results in a
            // TRUE value.

            ao_break();

            break;

        case AO_SYS_EXC_FPE:

            // FPU.

            ao_break();

            break;

        case AO_SYS_EXC_TLBRI:

            // TLB read-inhibit.

            ao_break();

            break;

        case AO_SYS_EXC_TLBEI:

            // TLB execute-inhibit.

            ao_break();

            break;

        case AO_SYS_EXC_WATCH:

            // Watch.

            // The watch facility provides a software debugging vehicle by
            // initiating a watch exception when an instruction or data
            // reference matches the address information stored in the WatchHi
            // and WatchLo registers.

            // A watch exception is taken immediately if the EXL and ERL bits
            // of the Status register are both zero and the DM bit of the Debug
            // register is also zero.

            // If any of those bits is a one at the time that a watch exception
            // would normally be taken, then the WP bit in the Cause register
            // is set, and the exception is deferred until all three bits are
            // zero.

            // Software may use the WP bit in the Cause register to determine
            // if the EPC register points at the instruction that caused the
            // watch exception, or if the exception actually occurred while in
            // kernel mode.

            // The watch exception can occur on either an instruction fetch or
            // a data access. Watch exceptions that occur on an instruction
            // fetch have a higher priority than watch exceptions that occur on
            // a data access.

            // Additional state saved.

            // * Cause.WP   Indicates that the watch exception was deferred
            //              until after Status.EXL, Status.ERL, and Debug.DM
            //              were zero. This bit directly causes a watch
            //              exception, so software must clear this bit as part
            //              of the exception handler to prevent a watch
            //              exception loop at the end of the current handler
            //              execution.

            ao_break();

            break;

        case AO_SYS_EXC_MCHECK:

            // Machine check.

            // A machine check exception occurs when the processor detects an
            // internal inconsistency.

            // The following condition causes a machine check exception.

            // * The detection of multiple matching entries in the TLB
            //   (TLB-based MMU only). The core detects this condition on a TLB
            //   write and prevents the write from being completed. The TS bit
            //   in the Status register is set to indicate this condition. This
            //   bit is only a status flag and does not affect the operation of
            //   the device. Software clears this bit at the appropriate time.
            //   This condition is resolved by flushing the conflicting TLB
            //   entries. The TLB write can then be completed.

            ao_break();

            break;

        case AO_SYS_EXC_DSPDIS:

            // DSP module state disabled.

            // The DSP module state disabled exception is an execution
            // exception.

            // It occurs when an attempt is made to execute a DSP module
            // instruction when the MX bit in the Status register is not set.
            // This allows an OS to do “lazy” context switching.

            ao_break();

            break;

        default:

            // Reserved.

            // This really should not have happend.

            ao_break();

            break;
    }
}

#else

void _general_exception_handler(uint32_t cause, uint32_t status)
{
    // Variables.

    (void) cause;
    (void) status;


    // Ready.

    ao_boot_led();

    while (1)
    {
        ao_spin(ao_milliseconds(100));

        ao_leds_toggle(AO_LEDS_ALL);
    }
}

#endif

#endif

#endif

// ----------------------------------------------------------------------------
