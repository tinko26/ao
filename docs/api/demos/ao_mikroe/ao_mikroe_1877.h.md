---
author: "Stefan Wagner"
date: 2022-09-22
draft: true
external:
- https://www.mikroe.com/3d-motion-click : "3D Motion Click"
- https://en.wikipedia.org/wiki/Accelerometer : "Accelerometer"
- https://en.wikipedia.org/wiki/Gyroscope : "Gyroscope"
- https://en.wikipedia.org/wiki/Inclinometer : "Inclinometer"
- https://en.wikipedia.org/wiki/Magnetometer : "Magnetometer"
- https://microchip.com/DS00001888 : "MM7150 Motion Module"
- https://microchip.com/DS00001873 : "MM7150 Motion Module Host API Design"
- https://microchip.com/DS50002322 : "MM7150 Motion Module User's Guide"
- https://microchip.com/DS00001885 : "SSC7150 Motion Coprocessor"
permalink: /api/demos/ao_mikroe/ao_mikroe_1877.h/
toc: true
---

# Include

| [`ao_float.h`](../../src/ao_sys_xc32_pic32/ao_float.h.md) |
| [`ao_time.h`](../../src/ao_sys/ao_time.h.md) |
| `stdbool.h` |
| `stddef.h` |

# Identifier

```c
#define AO_MIKROE_1877
```

# Configuration

```c
#define AO_MIKROE_1877 (false)
```

Defines whether the clickboard is used.

# Types

## `ao_mikroe_1877_connection_t`

```c
typedef enum ao_mikroe_1877_connection_t ao_mikroe_1877_connection_t;
```

```c
enum ao_mikroe_1877_connection_t
{
    AO_MIKROE_1877_CONNECTION_PC_INTEGRATED = 1,
    AO_MIKROE_1877_CONNECTION_PC_ATTACHED   = 2,
    AO_MIKROE_1877_CONNECTION_PC_EXTERNAL   = 3
};
```

It consists of the following members.

| `AO_MIKROE_1877_CONNECTION_PC_INTEGRATED` | |
| `AO_MIKROE_1877_CONNECTION_PC_ATTACHED` | |
| `AO_MIKROE_1877_CONNECTION_PC_EXTERNAL` | |

## `ao_mikroe_1877_event_t`

```c
typedef enum ao_mikroe_1877_event_t ao_mikroe_1877_event_t;
```

```c
enum ao_mikroe_1877_event_t
{
    AO_MIKROE_1877_EVENT_UNKNOWN                       = 1,
    AO_MIKROE_1877_EVENT_STATE_CHANGED                 = 2,
    AO_MIKROE_1877_EVENT_PROPERTY_CHANGED              = 3,
    AO_MIKROE_1877_EVENT_DATA_UPDATED                  = 4,
    AO_MIKROE_1877_EVENT_POLL_RESPONSE                 = 5,
    AO_MIKROE_1877_EVENT_CHANGE_SENSITIVITY            = 6,
    AO_MIKROE_1877_EVENT_MAX_REACHED                   = 7,
    AO_MIKROE_1877_EVENT_MIN_REACHED                   = 8,
    AO_MIKROE_1877_EVENT_HIGH_THRESHOLD_CROSS_UPWARD   = 9,
    AO_MIKROE_1877_EVENT_HIGH_THRESHOLD_CROSS_DOWNWARD = 10,
    AO_MIKROE_1877_EVENT_LOW_THRESHOLD_CROSS_UPWARD    = 11,
    AO_MIKROE_1877_EVENT_LOW_THRESHOLD_CROSS_DOWNWARD  = 12,
    AO_MIKROE_1877_EVENT_ZERO_THRESHOLD_CROSS_UPWARD   = 13,
    AO_MIKROE_1877_EVENT_ZERO_THRESHOLD_CROSS_DOWNWARD = 14,
    AO_MIKROE_1877_EVENT_PERIOD_EXCEEDED               = 15,
    AO_MIKROE_1877_EVENT_FREQUENCY_EXCEEDED            = 16,
    AO_MIKROE_1877_EVENT_COMPLEX_TRIGGER               = 17
};
```

It consists of the following members.

| `AO_MIKROE_1877_EVENT_UNKNOWN` | The sensor event type is not known. |
| `AO_MIKROE_1877_EVENT_STATE_CHANGED` | The sensor state has changed. |
| `AO_MIKROE_1877_EVENT_PROPERTY_CHANGED` | A property value has changed. |
| `AO_MIKROE_1877_EVENT_DATA_UPDATED` | A data field has changed. |
| `AO_MIKROE_1877_EVENT_POLL_RESPONSE` | The most current sensor data is being returned as the result of a poll request (Get Input). |
| `AO_MIKROE_1877_EVENT_CHANGE_SENSITIVITY` | The change sensitivity has been exceeded for a data field. |
| `AO_MIKROE_1877_EVENT_MAX_REACHED` | |
| `AO_MIKROE_1877_EVENT_MIN_REACHED` | |
| `AO_MIKROE_1877_EVENT_HIGH_THRESHOLD_CROSS_UPWARD` | |
| `AO_MIKROE_1877_EVENT_HIGH_THRESHOLD_CROSS_DOWNWARD` | |
| `AO_MIKROE_1877_EVENT_LOW_THRESHOLD_CROSS_UPWARD` | |
| `AO_MIKROE_1877_EVENT_LOW_THRESHOLD_CROSS_DOWNWARD` | |
| `AO_MIKROE_1877_EVENT_ZERO_THRESHOLD_CROSS_UPWARD` | |
| `AO_MIKROE_1877_EVENT_ZERO_THRESHOLD_CROSS_DOWNWARD` | |
| `AO_MIKROE_1877_EVENT_PERIOD_EXCEEDED` | |
| `AO_MIKROE_1877_EVENT_FREQUENCY_EXCEEDED` | |
| `AO_MIKROE_1877_EVENT_COMPLEX_TRIGGER` | |

## `ao_mikroe_1877_power_t`

```c
typedef enum ao_mikroe_1877_power_t ao_mikroe_1877_power_t;
```

```c
enum ao_mikroe_1877_power_t
{
    AO_MIKROE_1877_POWER_UNDEFINED = 1,
    AO_MIKROE_1877_POWER_FULL      = 2,
    AO_MIKROE_1877_POWER_LOW       = 3,
    AO_MIKROE_1877_POWER_STANDBY   = 4,
    AO_MIKROE_1877_POWER_SLEEP     = 5,
    AO_MIKROE_1877_POWER_OFF       = 6
};
```

It consists of the following members.

| `AO_MIKROE_1877_POWER_UNDEFINED` | The device power state is currently unknown or undefined. |
| `AO_MIKROE_1877_POWER_FULL` | The device is in full power operation. |
| `AO_MIKROE_1877_POWER_LOW` | The device is in a low power operation mode. |
| `AO_MIKROE_1877_POWER_STANDBY` | The device is at a standby power mode (e.g., halted and awaiting interrupts) and can be awakened. |
| `AO_MIKROE_1877_POWER_SLEEP` | The device is in a sleep mode and can be awakened. |
| `AO_MIKROE_1877_POWER_OFF` | The device is completely powered off and cannot be awakened. |

## `ao_mikroe_1877_reporting_t`

```c
typedef enum ao_mikroe_1877_reporting_t ao_mikroe_1877_reporting_t;
```

```c
enum ao_mikroe_1877_reporting_t
{
    AO_MIKROE_1877_REPORTING_ALL            = 2,
    AO_MIKROE_1877_REPORTING_ALL_WAKE       = 5,
    AO_MIKROE_1877_REPORTING_NONE           = 1,
    AO_MIKROE_1877_REPORTING_NONE_WAKE      = 4,
    AO_MIKROE_1877_REPORTING_THRESHOLD      = 3,
    AO_MIKROE_1877_REPORTING_THRESHOLD_WAKE = 6
};
```

It consists of the following members.

| `AO_MIKROE_1877_REPORTING_ALL` | All Input reports are sent without any filtering. |
| `AO_MIKROE_1877_REPORTING_ALL_WAKE` | All Input reports are sent without any filtering. A Wake On event is performed. |
| `AO_MIKROE_1877_REPORTING_NONE` | No asynchronous Input reports are sent. |
| `AO_MIKROE_1877_REPORTING_NONE_WAKE` | No asynchronous Input reports are sent. A Wake On event is never performed. |
| `AO_MIKROE_1877_REPORTING_THRESHOLD` | Input reports are sent only when it exceeds a pre-programmed threshold. |
| `AO_MIKROE_1877_REPORTING_THRESHOLD_WAKE` | Input reports are sent only when it exceeds a pre-programmed threshold. A Wake On event is performed. |

## `ao_mikroe_1877_sensor_t`

```c
typedef enum ao_mikroe_1877_sensor_t ao_mikroe_1877_sensor_t;
```

```c
enum ao_mikroe_1877_sensor_t
{
    AO_MIKROE_1877_SENSOR_ACCELEROMETER     = 1,
    AO_MIKROE_1877_SENSOR_ACCELEROMETER_RAW = 6,
    AO_MIKROE_1877_SENSOR_GYROSCOPE         = 3,
    AO_MIKROE_1877_SENSOR_GYROSCOPE_RAW     = 8,
    AO_MIKROE_1877_SENSOR_INCLINOMETER      = 4,
    AO_MIKROE_1877_SENSOR_MAGNETOMETER      = 2,
    AO_MIKROE_1877_SENSOR_MAGNETOMETER_RAW  = 7,
    AO_MIKROE_1877_SENSOR_ORIENTATION       = 5
};
```

It consists of the following members.

| `AO_MIKROE_1877_SENSOR_ACCELEROMETER` | |
| `AO_MIKROE_1877_SENSOR_ACCELEROMETER_RAW` | |
| `AO_MIKROE_1877_SENSOR_GYROSCOPE` | |
| `AO_MIKROE_1877_SENSOR_GYROSCOPE_RAW` | |
| `AO_MIKROE_1877_SENSOR_INCLINOMETER` | |
| `AO_MIKROE_1877_SENSOR_MAGNETOMETER` | |
| `AO_MIKROE_1877_SENSOR_MAGNETOMETER_RAW` | |
| `AO_MIKROE_1877_SENSOR_ORIENTATION` | |

## `ao_mikroe_1877_state_t`

```c
typedef enum ao_mikroe_1877_state_t ao_mikroe_1877_state_t;
```

```c
enum ao_mikroe_1877_state_t
{
    AO_MIKROE_1877_STATE_UNDEFINED     = 1,
    AO_MIKROE_1877_STATE_READY         = 2,
    AO_MIKROE_1877_STATE_NOT_AVAILABLE = 3,
    AO_MIKROE_1877_STATE_NO_DATA       = 4,
    AO_MIKROE_1877_STATE_INITIALIZING  = 5,
    AO_MIKROE_1877_STATE_ACCESS_DENIED = 6,
    AO_MIKROE_1877_STATE_ERROR         = 7
};
```

It consists of the following members.

| `AO_MIKROE_1877_STATE_UNDEFINED` | The sensor state is not known. |
| `AO_MIKROE_1877_STATE_READY` | Sensor is able to provide new complete and accurate data. |
| `AO_MIKROE_1877_STATE_NOT_AVAILABLE` | The sensor not available. |
| `AO_MIKROE_1877_STATE_NO_DATA` | The sensor is available, but is not yet providing data. It is not known in what timeframe data will, if ever, be provided. |
| `AO_MIKROE_1877_STATE_INITIALIZING` | The sensor is available, but is not yet providing data due to initialization activities. It is expected the sensor will provide data, but the timeframe in which that data will be available is not known. |
| `AO_MIKROE_1877_STATE_ACCESS_DENIED` | In the case where an ID must be provided to access sensor data, and the requester fails to match the ID, this state will be returned. |
| `AO_MIKROE_1877_STATE_ERROR` | The sensor has encountered a major error. The sensor may recover from the state, but the time frame for recovery is unknown. |

## `ao_mikroe_1877_data_accelerometer_t`

```c
typedef struct ao_mikroe_1877_data_accelerometer_t ao_mikroe_1877_data_accelerometer_t;
```

```c
struct ao_mikroe_1877_data_accelerometer_t
{
    bool       shake_detected;
    ao_float_t x;
    ao_float_t y;
    ao_float_t z;
};
```

It consists of the following members.

| `shake_detected` | |
| `x` | |
| `y` | |
| `z` | |

## `ao_mikroe_1877_data_gyroscope_t`

```c
typedef struct ao_mikroe_1877_data_gyroscope_t ao_mikroe_1877_data_gyroscope_t;
```

```c
struct ao_mikroe_1877_data_gyroscope_t
{
    bool       shake_detected;
    ao_float_t x;
    ao_float_t y;
    ao_float_t z;
};
```

It consists of the following members.

| `shake_detected` | |
| `x` | |
| `y` | |
| `z` | |

## `ao_mikroe_1877_data_inclinometer_t`

```c
typedef struct ao_mikroe_1877_data_inclinometer_t ao_mikroe_1877_data_inclinometer_t;
```

```c
struct ao_mikroe_1877_data_inclinometer_t
{
    ao_float_t x;
    ao_float_t y;
    ao_float_t z;
};
```

It consists of the following members.

| `x` | |
| `y` | |
| `z` | |

## `ao_mikroe_1877_data_magnetometer_t`

```c
typedef struct ao_mikroe_1877_data_magnetometer_t ao_mikroe_1877_data_magnetometer_t;
```

```c
struct ao_mikroe_1877_data_magnetometer_t
{
    ao_float_t heading;
    ao_float_t x;
    ao_float_t y;
    ao_float_t z;
};
```

It consists of the following members.

| `heading` | |
| `x` | |
| `y` | |
| `z` | |

## `ao_mikroe_1877_data_orientation_t`

```c
typedef struct ao_mikroe_1877_data_orientation_t ao_mikroe_1877_data_orientation_t;
```

```c
struct ao_mikroe_1877_data_orientation_t
{
    ao_float_t w;
    ao_float_t x;
    ao_float_t y;
    ao_float_t z;
};
```

It consists of the following members.

| `w` | |
| `x` | |
| `y` | |
| `z` | |

## `ao_mikroe_1877_data_t`

```c
typedef struct ao_mikroe_1877_data_t ao_mikroe_1877_data_t;
```

```c
struct ao_mikroe_1877_data_t
{
    union
    {
        ao_mikroe_1877_data_accelerometer_t accelerometer;
        ao_mikroe_1877_data_gyroscope_t     gyroscope;
        ao_mikroe_1877_data_inclinometer_t  inclinometer;
        ao_mikroe_1877_data_magnetometer_t  magnetometer;
        ao_mikroe_1877_data_orientation_t   orientation;
    }                                       data;
    ao_mikroe_1877_event_t                  event;
    ao_mikroe_1877_sensor_t                 sensor;
    ao_mikroe_1877_state_t                  state;
};
```

It consists of the following members.

| `data` | |
| `data.accelerometer` | |
| `data.gyroscope` | |
| `data.inclinometer` | |
| `data.magnetometer` | |
| `data.orientation` | |
| `event` | |
| `sensor` | |
| `state` | |

## `ao_mikroe_1877_info_t`

```c
typedef struct ao_mikroe_1877_info_t ao_mikroe_1877_info_t;
```

```c
struct ao_mikroe_1877_info_t
{
    ao_float_t                  accuracy;
    ao_float_t                  change_sensitivity;
    ao_mikroe_1877_connection_t connection;
    ao_time_t                   interval;
    ao_time_t                   interval_min;
    ao_float_t                  max;
    ao_float_t                  min;
    ao_mikroe_1877_power_t      power;
    ao_mikroe_1877_reporting_t  reporting;
    ao_float_t                  resolution;
    ao_mikroe_1877_sensor_t     sensor;
    ao_mikroe_1877_state_t      state;
};
```

It consists of the following members.

| `accuracy` | |
| `change_sensitivity` | Specifies the absolute amount that by which a data field should change before an event (such as an asynchronous Input Report) is generated. Absolute sensitivity values are expressed using the same units as the corresponding data field. |
| `connection` | |
| `interval` | Specifies the elapsed time for periodic sensor Input Report generation. A value of 0 means set or use the device default value, not 0 milliseconds. |
| `interval_min` | |
| `max` | |
| `min` | |
| `power` | |
| `reporting` | |
| `resolution` | |
| `sensor` | |
| `state` | |

# Functions

## `ao_mikroe_1877_config`

```c
void ao_mikroe_1877_config(size_t i, ao_mikroe_1877_info_t const * x);
```

## `ao_mikroe_1877_data`

```c
void ao_mikroe_1877_data(size_t i, ao_mikroe_1877_data_t const * x);
```

## `ao_mikroe_1877_get_data`

```c
void ao_mikroe_1877_get_data(size_t i, ao_mikroe_1877_sensor_t x);
```

## `ao_mikroe_1877_get_info`

```c
void ao_mikroe_1877_get_info(size_t i, ao_mikroe_1877_sensor_t x);
```

## `ao_mikroe_1877_info`

```c
void ao_mikroe_1877_info(size_t i, ao_mikroe_1877_info_t const * x);
```

## `ao_mikroe_1877_off`

```c
void ao_mikroe_1877_off(size_t i);
```

## `ao_mikroe_1877_on`

```c
void ao_mikroe_1877_on(size_t i);
```

## `ao_mikroe_1877_reset`

```c
void ao_mikroe_1877_reset(size_t i);
```

## `ao_mikroe_1877_sleep`

```c
void ao_mikroe_1877_sleep(size_t i);
```

## `ao_mikroe_1877_sleeping`

```c
void ao_mikroe_1877_sleeping(size_t i);
```

## `ao_mikroe_1877_start`

```c
void ao_mikroe_1877_start(size_t i);
```

## `ao_mikroe_1877_stop`

```c
void ao_mikroe_1877_stop(size_t i);
```

## `ao_mikroe_1877_wake`

```c
void ao_mikroe_1877_wake(size_t i);
```
