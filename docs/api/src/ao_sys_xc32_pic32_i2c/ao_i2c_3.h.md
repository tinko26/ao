---
author: "Stefan Wagner"
date: 2022-08-29
draft: true
permalink: /api/src/ao_sys_xc32_pic32_i2c/ao_i2c_3.h/
toc: true
---

# Include

```c
#include <ao_i2c.h>
#include <ao_sys.h>
#include <stdbool.h>
#include <xc.h>
```

# Identifiers

## `AO_I2C_3`

```c
#define AO_I2C_3
```

# Constants

## `AO_I2C_3`

Indicates whether the I²C module is available.

```c
#define AO_I2C_3
```

# Functions

## `ao_i2c_ack_3`
## `ao_i2c_ack_from_3`

```c
#define ao_i2c_ack_3(t)
#define ao_i2c_ack_from_3(t, b)
```

## `ao_i2c_ack_forever_3`

```c
#define ao_i2c_ack_forever_3()
```

## `ao_i2c_acked_3`

```c
#define ao_i2c_acked_3()
```

## `ao_i2c_baud_3`

```c
#define ao_i2c_baud_3(f)
```

## `ao_i2c_nack_3`
## `ao_i2c_nack_from_3`

```c
#define ao_i2c_nack_3(t)
#define ao_i2c_nack_from_3(t, b)
```

## `ao_i2c_nack_forever_3`

```c
#define ao_i2c_nack_forever_3()
```

## `ao_i2c_nacked_3`

```c
#define ao_i2c_nacked_3()
```

## `ao_i2c_recv_3`
## `ao_i2c_recv_from_3`

```c
#define ao_i2c_recv_3(v, t)
#define ao_i2c_recv_from_3(v, t, b)
```

## `ao_i2c_recv_forever_3`

```c
#define ao_i2c_recv_forever_3(v)
```

## `ao_i2c_reg_3`

```c
#define ao_i2c_reg_3()
```

## `ao_i2c_restart_3`
## `ao_i2c_restart_from_3`

```c
#define ao_i2c_restart_3(t)
#define ao_i2c_restart_from_3(t, b)
```

## `ao_i2c_restart_forever_3`

```c
#define ao_i2c_restart_forever_3()
```

## `ao_i2c_send_3`
## `ao_i2c_send_from_3`

```c
#define ao_i2c_send_3(v, t)
#define ao_i2c_send_from_3(v, t, b)
```

## `ao_i2c_send_forever_3`

```c
#define ao_i2c_send_forever_3(v)
```

## `ao_i2c_start_3`
## `ao_i2c_start_from_3`

```c
#define ao_i2c_start_3(t)
#define ao_i2c_start_from_3(t, b)
```

## `ao_i2c_start_forever_3`

```c
#define ao_i2c_start_forever_3()
```

## `ao_i2c_stop_3`
## `ao_i2c_stop_from_3`

```c
#define ao_i2c_stop_3(t)
#define ao_i2c_stop_from_3(t, b)
```

## `ao_i2c_stop_forever_3`

```c
#define ao_i2c_stop_forever_3()
```
