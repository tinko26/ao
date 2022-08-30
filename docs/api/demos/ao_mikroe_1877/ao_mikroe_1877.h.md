---
api: true
author: "Stefan Wagner"
date: 2022-08-30
description: "The /demos/ao_mikroe_1877/ao_mikroe_1877.h file of the ao real-time operating system."
draft: true
permalink: /api/demos/ao_mikroe_1877/ao_mikroe_1877.h/
subtitle: "3D Motion Click"
title: "ao_mikroe_1877.h"
toc: true
---

# Include

```c
#include <ao_float.h>
#include <ao_time.h>
#include <stdbool.h>
#include <stddef.h>
```

# Typedefs

```c
typedef enum ao_mikroe_1877_connection_t ao_mikroe_1877_connection_t;
```

```c
typedef struct ao_mikroe_1877_data_t ao_mikroe_1877_data_t;
```

```c
typedef struct ao_mikroe_1877_data_accelerometer_t ao_mikroe_1877_data_accelerometer_t;
```

```c
typedef struct ao_mikroe_1877_data_magnetometer_t ao_mikroe_1877_data_magnetometer_t;
```

```c
typedef struct ao_mikroe_1877_data_gyroscope_t ao_mikroe_1877_data_gyroscope_t;
```

```c
typedef struct ao_mikroe_1877_data_inclinometer_t ao_mikroe_1877_data_inclinometer_t;
```

```c
typedef struct ao_mikroe_1877_data_orientation_t ao_mikroe_1877_data_orientation_t;
```

```c
typedef enum ao_mikroe_1877_event_t ao_mikroe_1877_event_t;
```

```c
typedef struct ao_mikroe_1877_info_t ao_mikroe_1877_info_t;
```

```c
typedef enum ao_mikroe_1877_power_t ao_mikroe_1877_power_t;
```

```c
typedef enum ao_mikroe_1877_reporting_t ao_mikroe_1877_reporting_t;
```

```c
typedef enum ao_mikroe_1877_sensor_t ao_mikroe_1877_sensor_t;
```

```c
typedef enum ao_mikroe_1877_state_t ao_mikroe_1877_state_t;
```

# Types

## `ao_mikroe_1877_connection_t`

```c
enum ao_mikroe_1877_connection_t
{
    AO_MIKROE_1877_CONNECTION_PC_INTEGRATED = 1,
    AO_MIKROE_1877_CONNECTION_PC_ATTACHED = 2,
    AO_MIKROE_1877_CONNECTION_PC_EXTERNAL = 3
};
```

Members:

| `AO_MIKROE_1877_CONNECTION_PC_INTEGRATED` | |
| `AO_MIKROE_1877_CONNECTION_PC_ATTACHED` | |
| `AO_MIKROE_1877_CONNECTION_PC_EXTERNAL` | |

## `ao_mikroe_1877_event_t`

```c
enum ao_mikroe_1877_event_t
{
    AO_MIKROE_1877_EVENT_UNKNOWN = 1,
    AO_MIKROE_1877_EVENT_STATE_CHANGED = 2,
    AO_MIKROE_1877_EVENT_PROPERTY_CHANGED = 3,
    AO_MIKROE_1877_EVENT_DATA_UPDATED = 4,
    AO_MIKROE_1877_EVENT_POLL_RESPONSE = 5,
    AO_MIKROE_1877_EVENT_CHANGE_SENSITIVITY = 6,
    AO_MIKROE_1877_EVENT_MAX_REACHED = 7,
    AO_MIKROE_1877_EVENT_MIN_REACHED = 8,
    AO_MIKROE_1877_EVENT_HIGH_THRESHOLD_CROSS_UPWARD = 9,
    AO_MIKROE_1877_EVENT_HIGH_THRESHOLD_CROSS_DOWNWARD = 10,
    AO_MIKROE_1877_EVENT_LOW_THRESHOLD_CROSS_UPWARD = 11,
    AO_MIKROE_1877_EVENT_LOW_THRESHOLD_CROSS_DOWNWARD = 12,
    AO_MIKROE_1877_EVENT_ZERO_THRESHOLD_CROSS_UPWARD = 13,
    AO_MIKROE_1877_EVENT_ZERO_THRESHOLD_CROSS_DOWNWARD = 14,
    AO_MIKROE_1877_EVENT_PERIOD_EXCEEDED = 15,
    AO_MIKROE_1877_EVENT_FREQUENCY_EXCEEDED = 16,
    AO_MIKROE_1877_EVENT_COMPLEX_TRIGGER = 17
};
```

Members:

| `AO_MIKROE_1877_EVENT_UNKNOWN` | |
| `AO_MIKROE_1877_EVENT_STATE_CHANGED` | |
| `AO_MIKROE_1877_EVENT_PROPERTY_CHANGED` | |
| `AO_MIKROE_1877_EVENT_DATA_UPDATED` | |
| `AO_MIKROE_1877_EVENT_POLL_RESPONSE` | |
| `AO_MIKROE_1877_EVENT_CHANGE_SENSITIVITY` | |
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
enum ao_mikroe_1877_power_t
{
    AO_MIKROE_1877_POWER_UNDEFINED = 1,
    AO_MIKROE_1877_POWER_FULL = 2,
    AO_MIKROE_1877_POWER_LOW = 3,
    AO_MIKROE_1877_POWER_STANDBY = 4,
    AO_MIKROE_1877_POWER_SLEEP = 5,
    AO_MIKROE_1877_POWER_OFF = 6
};
```

Members:

| `AO_MIKROE_1877_POWER_UNDEFINED` | |
| `AO_MIKROE_1877_POWER_FULL` | |
| `AO_MIKROE_1877_POWER_LOW` | |
| `AO_MIKROE_1877_POWER_STANDBY` | |
| `AO_MIKROE_1877_POWER_SLEEP` | |
| `AO_MIKROE_1877_POWER_OFF` | |

## `ao_mikroe_1877_reporting_t`

```c
enum ao_mikroe_1877_reporting_t
{
    AO_MIKROE_1877_REPORTING_ALL = 2,
    AO_MIKROE_1877_REPORTING_ALL_WAKE = 5,
    AO_MIKROE_1877_REPORTING_NONE = 1,
    AO_MIKROE_1877_REPORTING_NONE_WAKE = 4,
    AO_MIKROE_1877_REPORTING_THRESHOLD = 3,
    AO_MIKROE_1877_REPORTING_THRESHOLD_WAKE = 6
};
```

Members:

| `AO_MIKROE_1877_REPORTING_ALL` | |
| `AO_MIKROE_1877_REPORTING_ALL_WAKE` | |
| `AO_MIKROE_1877_REPORTING_NONE` | |
| `AO_MIKROE_1877_REPORTING_NONE_WAKE` | |
| `AO_MIKROE_1877_REPORTING_THRESHOLD` | |
| `AO_MIKROE_1877_REPORTING_THRESHOLD_WAKE` | |

## `ao_mikroe_1877_sensor_t`

```c
enum ao_mikroe_1877_sensor_t
{
    AO_MIKROE_1877_SENSOR_ACCELEROMETER = 1,
    AO_MIKROE_1877_SENSOR_ACCELEROMETER_RAW = 6,
    AO_MIKROE_1877_SENSOR_GYROSCOPE = 3,
    AO_MIKROE_1877_SENSOR_GYROSCOPE_RAW = 8,
    AO_MIKROE_1877_SENSOR_INCLINOMETER = 4,
    AO_MIKROE_1877_SENSOR_MAGNETOMETER = 2,
    AO_MIKROE_1877_SENSOR_MAGNETOMETER_RAW = 7,
    AO_MIKROE_1877_SENSOR_ORIENTATION = 5
};
```

Members:

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
enum ao_mikroe_1877_state_t
{
    AO_MIKROE_1877_STATE_UNDEFINED = 1,
    AO_MIKROE_1877_STATE_READY = 2,
    AO_MIKROE_1877_STATE_NOT_AVAILABLE = 3,
    AO_MIKROE_1877_STATE_NO_DATA = 4,
    AO_MIKROE_1877_STATE_INITIALIZING = 5,
    AO_MIKROE_1877_STATE_ACCESS_DENIED = 6,
    AO_MIKROE_1877_STATE_ERROR = 7
};
```

Members:

| `AO_MIKROE_1877_STATE_UNDEFINED` | |
| `AO_MIKROE_1877_STATE_READY` | |
| `AO_MIKROE_1877_STATE_NOT_AVAILABLE` | |
| `AO_MIKROE_1877_STATE_NO_DATA` | |
| `AO_MIKROE_1877_STATE_INITIALIZING` | |
| `AO_MIKROE_1877_STATE_ACCESS_DENIED` | |
| `AO_MIKROE_1877_STATE_ERROR` | |

## `ao_mikroe_1877_data_accelerometer_t`

```c
struct ao_mikroe_1877_data_accelerometer_t
{
    bool shake_detected;
    ao_float_t x;
    ao_float_t y;
    ao_float_t z;
};
```

Members:

| `shake_detected` | |
| `x` | |
| `y` | |
| `z` | |

## `ao_mikroe_1877_data_gyroscope_t`

```c
struct ao_mikroe_1877_data_gyroscope_t
{
    bool shake_detected;
    ao_float_t x;
    ao_float_t y;
    ao_float_t z;
};
```

Members:

| `shake_detected` | |
| `x` | |
| `y` | |
| `z` | |

## `ao_mikroe_1877_data_inclinometer_t`

```c
struct ao_mikroe_1877_data_inclinometer_t
{
    ao_float_t x;
    ao_float_t y;
    ao_float_t z;
};
```

Members:

| `x` | |
| `y` | |
| `z` | |

## `ao_mikroe_1877_data_magnetometer_t`

```c
struct ao_mikroe_1877_data_magnetometer_t
{
    ao_float_t heading;
    ao_float_t x;
    ao_float_t y;
    ao_float_t z;
};
```

Members:

| `heading` | |
| `x` | |
| `y` | |
| `z` | |

## `ao_mikroe_1877_data_orientation_t`

```c
struct ao_mikroe_1877_data_orientation_t
{
    ao_float_t w;
    ao_float_t x;
    ao_float_t y;
    ao_float_t z;
};
```

Members:

| `w` | |
| `x` | |
| `y` | |
| `z` | |

## `ao_mikroe_1877_data_t`

```c
struct ao_mikroe_1877_data_t
{
    union
    {
        ao_mikroe_1877_data_accelerometer_t accelerometer;
        ao_mikroe_1877_data_gyroscope_t gyroscope;
        ao_mikroe_1877_data_inclinometer_t inclinometer;
        ao_mikroe_1877_data_magnetometer_t magnetometer;
        ao_mikroe_1877_data_orientation_t orientation;
    }
    data;
    ao_mikroe_1877_event_t event;
    ao_mikroe_1877_sensor_t sensor;
    ao_mikroe_1877_state_t state;
};
```

Members:

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
struct ao_mikroe_1877_info_t
{
    ao_float_t accuracy;
    ao_float_t change_sensitivity;
    ao_mikroe_1877_connection_t connection;
    ao_time_t interval;
    ao_time_t interval_min;
    ao_float_t max;
    ao_float_t min;
    ao_mikroe_1877_power_t power;
    ao_mikroe_1877_reporting_t reporting;
    ao_float_t resolution;
    ao_mikroe_1877_sensor_t sensor;
    ao_mikroe_1877_state_t state;
};
```

Members:

| `accuracy` | |
| `change_sensitivity` | |
| `connection` | |
| `interval` | |
| `interval_min` | |
| `max` | |
| `min` | |
| `power` | |
| `reporting` | |
| `resolution` | |
| `sensor` | |
| `state` | |

# Functions

```c
void ao_mikroe_1877_config( size_t i, ao_mikroe_1877_info_t const * x);
```

```c
void ao_mikroe_1877_data( size_t i, ao_mikroe_1877_data_t const * x);
```

```c
void ao_mikroe_1877_get_data( size_t i, ao_mikroe_1877_sensor_t x);
```

```c
void ao_mikroe_1877_get_info( size_t i, ao_mikroe_1877_sensor_t x);
```

```c
void ao_mikroe_1877_info( size_t i, ao_mikroe_1877_info_t const * x);
```

```c
void ao_mikroe_1877_off( size_t i);
```

```c
void ao_mikroe_1877_on( size_t i);
```

```c
void ao_mikroe_1877_reset( size_t i);
```

```c
void ao_mikroe_1877_sleep( size_t i);
```

```c
void ao_mikroe_1877_sleeping( size_t i);
```

```c
void ao_mikroe_1877_start( size_t i);
```

```c
void ao_mikroe_1877_stop( size_t i);
```

```c
void ao_mikroe_1877_wake( size_t i);
```

