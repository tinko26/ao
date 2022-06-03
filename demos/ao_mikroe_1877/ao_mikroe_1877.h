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

// MikroElektronika.

// 3D Motion Click.

// ----------------------------------------------------------------------------

// @seeAlso

// https://www.mikroe.com/3d-motion-click

// http://microchip.com/DS00001888 (MM7150 Motion Module)

// http://microchip.com/DS00001873 (MM7150 Motion Module Host API Design)

// http://microchip.com/DS50002322 (MM7150 Motion Module User's Guide)

// http://microchip.com/DS00001885 (SSC7150 Motion Coprocessor)

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

#define AO_MIKROE_1877

#endif

// ----------------------------------------------------------------------------

#ifndef AO_MIKROE_1877_CONNECTION

#define AO_MIKROE_1877_CONNECTION

// ----------------------------------------------------------------------------

enum    ao_mikroe_1877_connection_t
{
        AO_MIKROE_1877_CONNECTION_PC_INTEGRATED             = 1,

        AO_MIKROE_1877_CONNECTION_PC_ATTACHED               = 2,

        AO_MIKROE_1877_CONNECTION_PC_EXTERNAL               = 3
};

// ----------------------------------------------------------------------------

#endif

#ifndef AO_MIKROE_1877_EVENT

#define AO_MIKROE_1877_EVENT

// ----------------------------------------------------------------------------

enum    ao_mikroe_1877_event_t
{
        // The sensor event type is not known.

        AO_MIKROE_1877_EVENT_UNKNOWN                        = 1,

        // The sensor state has changed.

        AO_MIKROE_1877_EVENT_STATE_CHANGED                  = 2,

        // A property value has changed.

        AO_MIKROE_1877_EVENT_PROPERTY_CHANGED               = 3,

        // A data field has changed.

        AO_MIKROE_1877_EVENT_DATA_UPDATED                   = 4,

        // The most current sensor data is being returned as the result of a poll request (Get Input).

        AO_MIKROE_1877_EVENT_POLL_RESPONSE                  = 5,

        // The change sensitivity has been exceeded for a data field.

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

#ifndef AO_MIKROE_1877_POWER

#define AO_MIKROE_1877_POWER

// ----------------------------------------------------------------------------

enum    ao_mikroe_1877_power_t
{
        // The device power state is currently unknown or undefined.

        AO_MIKROE_1877_POWER_UNDEFINED                      = 1,

        // The device is in full power operation.

        AO_MIKROE_1877_POWER_FULL                           = 2,

        // The device is in a low power operation mode.

        AO_MIKROE_1877_POWER_LOW                            = 3,

        // The device is at a standby power mode (e.g., halted and awaiting interrupts) and can be awakened.

        AO_MIKROE_1877_POWER_STANDBY                        = 4,

        // The device is in a sleep mode and can be awakened.

        AO_MIKROE_1877_POWER_SLEEP                          = 5,

        // The device is completely powered off and cannot be awakened.

        AO_MIKROE_1877_POWER_OFF                            = 6
};

// ----------------------------------------------------------------------------

#endif

#ifndef AO_MIKROE_1877_REPORTING

#define AO_MIKROE_1877_REPORTING

// ----------------------------------------------------------------------------

enum    ao_mikroe_1877_reporting_t
{
        // All Input reports are sent without any filtering.

        AO_MIKROE_1877_REPORTING_ALL                        = 2,

        // All Input reports are sent without any filtering.

        // A Wake On event is performed.

        AO_MIKROE_1877_REPORTING_ALL_WAKE                   = 5,

        // No asynchronous Input reports are sent.

        AO_MIKROE_1877_REPORTING_NONE                       = 1,

        // No asynchronous Input reports are sent.

        // A Wake On event is never performed.

        AO_MIKROE_1877_REPORTING_NONE_WAKE                  = 4,

        // Input reports are sent only when it exceeds a pre-programmed threshold.

        AO_MIKROE_1877_REPORTING_THRESHOLD                  = 3,

        // Input reports are sent only when it exceeds a pre-programmed threshold.

        // A Wake On event is performed.

        AO_MIKROE_1877_REPORTING_THRESHOLD_WAKE             = 6
};

// ----------------------------------------------------------------------------

#endif

#ifndef AO_MIKROE_1877_SENSOR

#define AO_MIKROE_1877_SENSOR

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

#ifndef AO_MIKROE_1877_STATE

#define AO_MIKROE_1877_STATE

// ----------------------------------------------------------------------------

enum    ao_mikroe_1877_state_t
{
        // The sensor state is not known.

        AO_MIKROE_1877_STATE_UNDEFINED                      = 1,

        // Sensor is able to provide new complete and accurate data.

        AO_MIKROE_1877_STATE_READY                          = 2,

        // The sensor not available.

        AO_MIKROE_1877_STATE_NOT_AVAILABLE                  = 3,

        // The sensor is available, but is not yet providing data.

        // It is not known in what timeframe data will, if ever, be provided.

        AO_MIKROE_1877_STATE_NO_DATA                        = 4,

        // The sensor is available, but is not yet providing data due to initialization activities.

        // It is expected the sensor will provide data, but the timeframe in which that data will be available is not known.

        AO_MIKROE_1877_STATE_INITIALIZING                   = 5,

        // In the case where an ID must be provided to access sensor data, and the requester fails to match the ID, this state will be returned.

        AO_MIKROE_1877_STATE_ACCESS_DENIED                  = 6,

        // The sensor has encountered a major error.

        // The sensor may recover from the state, but the time frame for recovery is unknown.

        AO_MIKROE_1877_STATE_ERROR                          = 7
};

// ----------------------------------------------------------------------------

#endif

// ----------------------------------------------------------------------------

#ifndef AO_MIKROE_1877_DATA_ACCELEROMETER

#define AO_MIKROE_1877_DATA_ACCELEROMETER

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

#ifndef AO_MIKROE_1877_DATA_GYROSCOPE

#define AO_MIKROE_1877_DATA_GYROSCOPE

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

#ifndef AO_MIKROE_1877_DATA_INCLINOMETER

#define AO_MIKROE_1877_DATA_INCLINOMETER

// ----------------------------------------------------------------------------

struct  ao_mikroe_1877_data_inclinometer_t
{
        ao_float_t                                          x;

        ao_float_t                                          y;

        ao_float_t                                          z;
};

// ----------------------------------------------------------------------------

#endif

#ifndef AO_MIKROE_1877_DATA_MAGNETOMETER

#define AO_MIKROE_1877_DATA_MAGNETOMETER

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

#ifndef AO_MIKROE_1877_DATA_ORIENTATION

#define AO_MIKROE_1877_DATA_ORIENTATION

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

#ifndef AO_MIKROE_1877_DATA

#define AO_MIKROE_1877_DATA

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

#ifndef AO_MIKROE_1877_INFO

#define AO_MIKROE_1877_INFO

// ----------------------------------------------------------------------------

struct  ao_mikroe_1877_info_t
{
        ao_float_t                                          accuracy;

        // Specifies the absolute amount that by which a data field should change before an event (such as an asynchronous Input Report) is generated.

        // Absolute sensitivity values are expressed using the same units as the corresponding data field.

        ao_float_t                                          change_sensitivity;

        ao_mikroe_1877_connection_t                         connection;

        // Specifies the elapsed time for periodic sensor Input Report generation.

        // A value of 0 means set or use the device default value, not 0 milliseconds.

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
