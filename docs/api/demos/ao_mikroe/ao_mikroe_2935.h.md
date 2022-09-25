---
author: "Stefan Wagner"
date: 2022-09-25
draft: true
external:
- https://www.bosch-sensortec.com/products/motion-sensors/magnetometers-bmm150/ : "Bosch Sensortec BMM150"
- https://www.bosch-sensortec.com/software-tools/software/sensor-fusion-software/ : "Bosch Sensortec Sensor fusion software"
- https://www.mikroe.com/geomagnetic-click : "GeoMagnetic Click"
- https://en.wikipedia.org/wiki/Magnetometer : "Magnetometer"
permalink: /api/demos/ao_mikroe/ao_mikroe_2935.h/
toc: true
---

# Include

| [`ao_float.h`](../../src/ao_sys_xc32_pic32/ao_float.h.md) |
| `stdbool.h` |
| `stddef.h` |

# Identifier

```c
#define AO_MIKROE_2935
```

# Configuration

```c
#define AO_MIKROE_2935 (false)
```

Defines whether the clickboard is used.

# Types

## `ao_mikroe_2935_t`

```c
typedef struct ao_mikroe_2935_t ao_mikroe_2935_t;
```

# Structs

## `ao_mikroe_2935_t`

```c
struct ao_mikroe_2935_t
{
    bool       ready;
    ao_float_t x;
    ao_float_t y;
    ao_float_t z;
};
```

| `ready` | |
| `x` | &my;T |
| `y` | &my;T |
| `z` | &my;T |

# Functions

## `ao_mikroe_2935`

```c
void ao_mikroe_2935(size_t i, ao_mikroe_2935_t const * x);
```

## `ao_mikroe_2935_start`

```c
void ao_mikroe_2935_start(size_t i);
```

## `ao_mikroe_2935_stop`

```c
void ao_mikroe_2935_stop(size_t i);
```
