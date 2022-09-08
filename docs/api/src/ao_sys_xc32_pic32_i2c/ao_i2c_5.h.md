---
author: "Stefan Wagner"
date: 2022-08-29
draft: true
permalink: /api/src/ao_sys_xc32_pic32_i2c/ao_i2c_5.h/
toc: true
---

# Include

```c
#include <ao_i2c.h>
#include <ao_sys.h>
#include <stdbool.h>
#include <xc.h>
```

# Constants

## `AO_I2C_5`

Indicates whether the I²C module is available.

```c
#define AO_I2C_5
```

# Functions

## `ao_i2c_ack_5`
## `ao_i2c_ack_from_5`

```c
#define ao_i2c_ack_5(t)
#define ao_i2c_ack_from_5(t, b)
```

## `ao_i2c_ack_forever_5`

```c
#define ao_i2c_ack_forever_5()
```

## `ao_i2c_acked_5`

```c
#define ao_i2c_acked_5()
```

## `ao_i2c_baud_5`

```c
#define ao_i2c_baud_5(f)
```

## `ao_i2c_nack_5`
## `ao_i2c_nack_from_5`

```c
#define ao_i2c_nack_5(t)
#define ao_i2c_nack_from_5(t, b)
```

## `ao_i2c_nack_forever_5`

```c
#define ao_i2c_nack_forever_5()
```

## `ao_i2c_nacked_5`

```c
#define ao_i2c_nacked_5()
```

## `ao_i2c_recv_5`
## `ao_i2c_recv_from_5`

```c
#define ao_i2c_recv_5(v, t)
#define ao_i2c_recv_from_5(v, t, b)
```

## `ao_i2c_recv_forever_5`

```c
#define ao_i2c_recv_forever_5(v)
```

## `ao_i2c_reg_5`

```c
#define ao_i2c_reg_5()
```

## `ao_i2c_restart_5`
## `ao_i2c_restart_from_5`

```c
#define ao_i2c_restart_5(t)
#define ao_i2c_restart_from_5(t, b)
```

## `ao_i2c_restart_forever_5`

```c
#define ao_i2c_restart_forever_5()
```

## `ao_i2c_send_5`
## `ao_i2c_send_from_5`

```c
#define ao_i2c_send_5(v, t)
#define ao_i2c_send_from_5(v, t, b)
```

## `ao_i2c_send_forever_5`

```c
#define ao_i2c_send_forever_5(v)
```

## `ao_i2c_start_5`
## `ao_i2c_start_from_5`

```c
#define ao_i2c_start_5(t)
#define ao_i2c_start_from_5(t, b)
```

## `ao_i2c_start_forever_5`

```c
#define ao_i2c_start_forever_5()
```

## `ao_i2c_stop_5`
## `ao_i2c_stop_from_5`

```c
#define ao_i2c_stop_5(t)
#define ao_i2c_stop_from_5(t, b)
```

## `ao_i2c_stop_forever_5`

```c
#define ao_i2c_stop_forever_5()
```
