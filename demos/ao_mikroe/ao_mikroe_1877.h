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

// 3D Motion Click.

// ----------------------------------------------------------------------------

#include <ao_float.h>
#include <ao_time.h>
#include <stdbool.h>
#include <stddef.h>

// ----------------------------------------------------------------------------

typedef enum    ao_mikroe_1877_connection_t                 ao_mikroe_1877_connection_t;

// ----------------------------------------------------------------------------

typedef struct  ao_mikroe_1877_data_t                       ao_mikroe_1877_data_t;

typedef struct  ao_mikroe_1877_data_accelerometer_t         ao_mikroe_1877_data_accelerometer_t;

typedef struct  ao_mikroe_1877_data_magnetometer_t          ao_mikroe_1877_data_magnetometer_t;

typedef struct  ao_mikroe_1877_data_gyroscope_t             ao_mikroe_1877_data_gyroscope_t;

typedef struct  ao_mikroe_1877_data_inclinometer_t          ao_mikroe_1877_data_inclinometer_t;

typedef struct  ao_mikroe_1877_data_orientation_t           ao_mikroe_1877_data_orientation_t;

// ----------------------------------------------------------------------------

typedef enum    ao_mikroe_1877_event_t                      ao_mikroe_1877_event_t;

// ----------------------------------------------------------------------------

typedef struct  ao_mikroe_1877_info_t                       ao_mikroe_1877_info_t;

// ----------------------------------------------------------------------------

typedef enum    ao_mikroe_1877_power_t                      ao_mikroe_1877_power_t;

// ----------------------------------------------------------------------------

typedef enum    ao_mikroe_1877_reporting_t                  ao_mikroe_1877_reporting_t;

// ----------------------------------------------------------------------------

typedef enum    ao_mikroe_1877_sensor_t                     ao_mikroe_1877_sensor_t;

// ----------------------------------------------------------------------------

typedef enum    ao_mikroe_1877_state_t                      ao_mikroe_1877_state_t;

// ----------------------------------------------------------------------------

#ifndef AO_MIKROE_1877

#define AO_MIKROE_1877                                      (false)

#endif

// ----------------------------------------------------------------------------

#ifndef AO_MIKROE_1877_CONNECTION_T

#define AO_MIKROE_1877_CONNECTION_T

// ----------------------------------------------------------------------------

enum    ao_mikroe_1877_connection_t
{
        AO_MIKROE_1877_CONNECTION_PC_INTEGRATED             = 1,

        AO_MIKROE_1877_CONNECTION_PC_ATTACHED               = 2,

        AO_MIKROE_1877_CONNECTION_PC_EXTERNAL               = 3
};

// ----------------------------------------------------------------------------

#endif

#ifndef AO_MIKROE_1877_EVENT_T

#define AO_MIKROE_1877_EVENT_T

// ----------------------------------------------------------------------------

enum    ao_mikroe_1877_event_t
{
        AO_MIKROE_1877_EVENT_UNKNOWN                        = 1,

        AO_MIKROE_1877_EVENT_STATE_CHANGED                  = 2,

        AO_MIKROE_1877_EVENT_PROPERTY_CHANGED               = 3,

        AO_MIKROE_1877_EVENT_DATA_UPDATED                   = 4,

        AO_MIKROE_1877_EVENT_POLL_RESPONSE                  = 5,

        AO_MIKROE_1877_EVENT_CHANGE_SENSITIVITY             = 6,

        AO_MIKROE_1877_EVENT_MAX_REACHED                    = 7,

        AO_MIKROE_1877_EVENT_MIN_REACHED                    = 8,

        AO_MIKROE_1877_EVENT_HIGH_THRESHOLD_CROSS_UPWARD    = 9,

        AO_MIKROE_1877_EVENT_HIGH_THRESHOLD_CROSS_DOWNWARD  = 10,

        AO_MIKROE_1877_EVENT_LOW_THRESHOLD_CROSS_UPWARD     = 11,

        AO_MIKROE_1877_EVENT_LOW_THRESHOLD_CROSS_DOWNWARD   = 12,

        AO_MIKROE_1877_EVENT_ZERO_THRESHOLD_CROSS_UPWARD    = 13,

        AO_MIKROE_1877_EVENT_ZERO_THRESHOLD_CROSS_DOWNWARD  = 14,

        AO_MIKROE_1877_EVENT_PERIOD_EXCEEDED                = 15,

        AO_MIKROE_1877_EVENT_FREQUENCY_EXCEEDED             = 16,

        AO_MIKROE_1877_EVENT_COMPLEX_TRIGGER                = 17
};

// ----------------------------------------------------------------------------

#endif

#ifndef AO_MIKROE_1877_POWER_T

#define AO_MIKROE_1877_POWER_T

// ----------------------------------------------------------------------------

enum    ao_mikroe_1877_power_t
{
        AO_MIKROE_1877_POWER_UNDEFINED                      = 1,

        AO_MIKROE_1877_POWER_FULL                           = 2,

        AO_MIKROE_1877_POWER_LOW                            = 3,

        AO_MIKROE_1877_POWER_STANDBY                        = 4,

        AO_MIKROE_1877_POWER_SLEEP                          = 5,

        AO_MIKROE_1877_POWER_OFF                            = 6
};

// ----------------------------------------------------------------------------

#endif

#ifndef AO_MIKROE_1877_REPORTING_T

#define AO_MIKROE_1877_REPORTING_T

// ----------------------------------------------------------------------------

enum    ao_mikroe_1877_reporting_t
{
        AO_MIKROE_1877_REPORTING_ALL                        = 2,

        AO_MIKROE_1877_REPORTING_ALL_WAKE                   = 5,

        AO_MIKROE_1877_REPORTING_NONE                       = 1,

        AO_MIKROE_1877_REPORTING_NONE_WAKE                  = 4,

        AO_MIKROE_1877_REPORTING_THRESHOLD                  = 3,

        AO_MIKROE_1877_REPORTING_THRESHOLD_WAKE             = 6
};

// ----------------------------------------------------------------------------

#endif

#ifndef AO_MIKROE_1877_SENSOR_T

#define AO_MIKROE_1877_SENSOR_T

// ----------------------------------------------------------------------------

enum    ao_mikroe_1877_sensor_t
{
        AO_MIKROE_1877_SENSOR_ACCELEROMETER                 = 1,

        AO_MIKROE_1877_SENSOR_ACCELEROMETER_RAW             = 6,

        AO_MIKROE_1877_SENSOR_GYROSCOPE                     = 3,

        AO_MIKROE_1877_SENSOR_GYROSCOPE_RAW                 = 8,

        AO_MIKROE_1877_SENSOR_INCLINOMETER                  = 4,

        AO_MIKROE_1877_SENSOR_MAGNETOMETER                  = 2,

        AO_MIKROE_1877_SENSOR_MAGNETOMETER_RAW              = 7,

        AO_MIKROE_1877_SENSOR_ORIENTATION                   = 5
};

// ----------------------------------------------------------------------------

#endif

#ifndef AO_MIKROE_1877_STATE_T

#define AO_MIKROE_1877_STATE_T

// ----------------------------------------------------------------------------

enum    ao_mikroe_1877_state_t
{
        AO_MIKROE_1877_STATE_UNDEFINED                      = 1,

        AO_MIKROE_1877_STATE_READY                          = 2,

        AO_MIKROE_1877_STATE_NOT_AVAILABLE                  = 3,

        AO_MIKROE_1877_STATE_NO_DATA                        = 4,

        AO_MIKROE_1877_STATE_INITIALIZING                   = 5,

        AO_MIKROE_1877_STATE_ACCESS_DENIED                  = 6,

        AO_MIKROE_1877_STATE_ERROR                          = 7
};

// ----------------------------------------------------------------------------

#endif

// ----------------------------------------------------------------------------

#ifndef AO_MIKROE_1877_DATA_ACCELEROMETER_T

#define AO_MIKROE_1877_DATA_ACCELEROMETER_T

// ----------------------------------------------------------------------------

struct  ao_mikroe_1877_data_accelerometer_t
{
        bool                                                shake_detected;

        ao_float_t                                          x;

        ao_float_t                                          y;

        ao_float_t                                          z;
};

// ----------------------------------------------------------------------------

#endif

#ifndef AO_MIKROE_1877_DATA_GYROSCOPE_T

#define AO_MIKROE_1877_DATA_GYROSCOPE_T

// ----------------------------------------------------------------------------

struct  ao_mikroe_1877_data_gyroscope_t
{
        bool                                                shake_detected;

        ao_float_t                                          x;

        ao_float_t                                          y;

        ao_float_t                                          z;
};

// ----------------------------------------------------------------------------

#endif

#ifndef AO_MIKROE_1877_DATA_INCLINOMETER_T

#define AO_MIKROE_1877_DATA_INCLINOMETER_T

// ----------------------------------------------------------------------------

struct  ao_mikroe_1877_data_inclinometer_t
{
        ao_float_t                                          x;

        ao_float_t                                          y;

        ao_float_t                                          z;
};

// ----------------------------------------------------------------------------

#endif

#ifndef AO_MIKROE_1877_DATA_MAGNETOMETER_T

#define AO_MIKROE_1877_DATA_MAGNETOMETER_T

// ----------------------------------------------------------------------------

struct  ao_mikroe_1877_data_magnetometer_t
{
        ao_float_t                                          heading;

        ao_float_t                                          x;

        ao_float_t                                          y;

        ao_float_t                                          z;
};

// ----------------------------------------------------------------------------

#endif

#ifndef AO_MIKROE_1877_DATA_ORIENTATION_T

#define AO_MIKROE_1877_DATA_ORIENTATION_T

// ----------------------------------------------------------------------------

struct  ao_mikroe_1877_data_orientation_t
{
        ao_float_t                                          w;

        ao_float_t                                          x;

        ao_float_t                                          y;

        ao_float_t                                          z;
};

// ----------------------------------------------------------------------------

#endif

#ifndef AO_MIKROE_1877_DATA_T

#define AO_MIKROE_1877_DATA_T

// ----------------------------------------------------------------------------

struct  ao_mikroe_1877_data_t
{
        union
        {
            ao_mikroe_1877_data_accelerometer_t             accelerometer;

            ao_mikroe_1877_data_gyroscope_t                 gyroscope;

            ao_mikroe_1877_data_inclinometer_t              inclinometer;

            ao_mikroe_1877_data_magnetometer_t              magnetometer;

            ao_mikroe_1877_data_orientation_t               orientation;
        }
                                                            data;

        ao_mikroe_1877_event_t                              event;

        ao_mikroe_1877_sensor_t                             sensor;

        ao_mikroe_1877_state_t                              state;
};

// ----------------------------------------------------------------------------

#endif

// ----------------------------------------------------------------------------

#ifndef AO_MIKROE_1877_INFO_T

#define AO_MIKROE_1877_INFO_T

// ----------------------------------------------------------------------------

struct  ao_mikroe_1877_info_t
{
        ao_float_t                                          accuracy;

        ao_float_t                                          change_sensitivity;

        ao_mikroe_1877_connection_t                         connection;

        ao_time_t                                           interval;

        ao_time_t                                           interval_min;

        ao_float_t                                          max;

        ao_float_t                                          min;

        ao_mikroe_1877_power_t                              power;

        ao_mikroe_1877_reporting_t                          reporting;

        ao_float_t                                          resolution;

        ao_mikroe_1877_sensor_t                             sensor;

        ao_mikroe_1877_state_t                              state;
};

// ----------------------------------------------------------------------------

#endif

// ----------------------------------------------------------------------------

void    ao_mikroe_1877_config(                              size_t i, ao_mikroe_1877_info_t const * x);

// ----------------------------------------------------------------------------

void    ao_mikroe_1877_data(                                size_t i, ao_mikroe_1877_data_t const * x);

// ----------------------------------------------------------------------------

void    ao_mikroe_1877_get_data(                            size_t i, ao_mikroe_1877_sensor_t x);

void    ao_mikroe_1877_get_info(                            size_t i, ao_mikroe_1877_sensor_t x);

// ----------------------------------------------------------------------------

void    ao_mikroe_1877_info(                                size_t i, ao_mikroe_1877_info_t const * x);

// ----------------------------------------------------------------------------

void    ao_mikroe_1877_off(                                 size_t i);

void    ao_mikroe_1877_on(                                  size_t i);

// ----------------------------------------------------------------------------

void    ao_mikroe_1877_reset(                               size_t i);

// ----------------------------------------------------------------------------

void    ao_mikroe_1877_sleep(                               size_t i);

// ----------------------------------------------------------------------------

void    ao_mikroe_1877_sleeping(                            size_t i);

// ----------------------------------------------------------------------------

void    ao_mikroe_1877_start(                               size_t i);

void    ao_mikroe_1877_stop(                                size_t i);

// ----------------------------------------------------------------------------

void    ao_mikroe_1877_wake(                                size_t i);

// ----------------------------------------------------------------------------
