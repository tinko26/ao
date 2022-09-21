---
author: "Stefan Wagner"
date: 2022-09-20
draft: true
permalink: /api/src/ao_sys_xc32_pic32_i2c/ao_i2c_4.h/
toc: true
---

# Include

```c
#include <ao_i2c.h>
#include <ao_sys.h>
#include <stdbool.h>
#include <xc.h>
```

# Identifier

```c
#define AO_I2C_4
```

# Constants

## `AO_I2C_4`

```c
#define AO_I2C_4 (false)
```

Indicates whether the module is available.

# Functions

## `ao_i2c_ack`

```c
#define ao_i2c_ack_4(t)         ao_i2c_ack        (ao_i2c_reg_4(), t)
#define ao_i2c_ack_from_4(t, b) ao_i2c_ack_from   (ao_i2c_reg_4(), t, b)
#define ao_i2c_ack_forever_4()  ao_i2c_ack_forever(ao_i2c_reg_4())
```

Generates an acknowledge. The return value indicates, whether the operation succeeded.

| `t` | The timeout. |
| `b` | The beginning. |

## `ao_i2c_acked`

```c
#define ao_i2c_acked_4()         \
(                                \
    ao_i2c_acked(ao_i2c_reg_4()) \
)
```

Checks whether an acknowledge has been received.

## `ao_i2c_baud`

```c
#define ao_i2c_baud_4(f)   \
(                          \
    ao_i2c_baud            \
    (                      \
        ao_i2c_reg_4(),    \
        AO_SYS_CLOCK_I2C4, \
        f                  \
    )                      \
)
```

Sets up the baud rate, in bits per second.

## `ao_i2c_nack`

```c
#define ao_i2c_nack_4(t)         ao_i2c_nack        (ao_i2c_reg_4(), t)
#define ao_i2c_nack_from_4(t, b) ao_i2c_nack_from   (ao_i2c_reg_4(), t, b)
#define ao_i2c_nack_forever_4()  ao_i2c_nack_forever(ao_i2c_reg_4())
```

Generates a not acknowledge. The return value indicates, whether the operation succeeded.

| `t` | The timeout. |
| `b` | The beginning. |

## `ao_i2c_nacked`

```c
#define ao_i2c_nacked_4()         \
(                                 \
    ao_i2c_nacked(ao_i2c_reg_4()) \
)
```

Checks whether a not acknowledge has been received.

## `ao_i2c_recv`

```c
#define ao_i2c_recv_4(v, t)         ao_i2c_recv        (ao_i2c_reg_4(), v, t)
#define ao_i2c_recv_from_4(v, t, b) ao_i2c_recv_from   (ao_i2c_reg_4(), v, t, b)
#define ao_i2c_recv_forever_4(v)    ao_i2c_recv_forever(ao_i2c_reg_4(), v)
```

Receives data. The return value indicates, whether the operation succeeded.

| `v` | The pointer to the location to store the received data. |
| `t` | The timeout. |
| `b` | The beginning. |

## `ao_i2c_reg_4`

```c
#define ao_i2c_reg_4()     \
(                          \
    (ao_i2c_reg_t *)       \
    (                      \
        _I2C4_BASE_ADDRESS \
    )                      \
)
```

Gets the control registers.

## `ao_i2c_restart`

```c
#define ao_i2c_restart_4(t)         ao_i2c_restart        (ao_i2c_reg_4(), t)
#define ao_i2c_restart_from_4(t, b) ao_i2c_restart_from   (ao_i2c_reg_4(), t, b)
#define ao_i2c_restart_forever_4()  ao_i2c_restart_forever(ao_i2c_reg_4())
```

Generates a repeated start bus event. The return value indicates, whether the operation succeeded.

| `t` | The timeout. |
| `b` | The beginning. |

## `ao_i2c_send`

```c
#define ao_i2c_send_4(v, t)         ao_i2c_send        (ao_i2c_reg_4(), v, t)
#define ao_i2c_send_from_4(v, t, b) ao_i2c_send_from   (ao_i2c_reg_4(), v, t, b)
#define ao_i2c_send_forever_4(v)    ao_i2c_send_forever(ao_i2c_reg_4(), v)
```

Sends data. The return value indicates, whether the operation succeeded.

| `v` | The data. |
| `t` | The timeout. |
| `b` | The beginning. |

## `ao_i2c_start`

```c
#define ao_i2c_start_4(t)         ao_i2c_start        (ao_i2c_reg_4(), t)
#define ao_i2c_start_from_4(t, b) ao_i2c_start_from   (ao_i2c_reg_4(), t, b)
#define ao_i2c_start_forever_4()  ao_i2c_start_forever(ao_i2c_reg_4())
```

Generates a start bus event. The return value indicates, whether the operation succeeded.

| `t` | The timeout. |
| `b` | The beginning. |

## `ao_i2c_stop`

```c
#define ao_i2c_stop_4(t)         ao_i2c_stop        (ao_i2c_reg_4(), t)
#define ao_i2c_stop_from_4(t, b) ao_i2c_stop_fro    (ao_i2c_reg_4(), t, b)
#define ao_i2c_stop_forever_4()  ao_i2c_stop_forever(ao_i2c_reg_4())
```

Generates a stop bus event. The return value indicates, whether the operation succeeded.

| `t` | The timeout. |
| `b` | The beginning. |
