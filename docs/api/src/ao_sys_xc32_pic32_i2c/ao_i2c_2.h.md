---
author: "Stefan Wagner"
date: 2022-09-20
draft: true
permalink: /api/src/ao_sys_xc32_pic32_i2c/ao_i2c_2.h/
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
#define AO_I2C_2
```

# Constants

## `AO_I2C_2`

```c
#define AO_I2C_2
```

Indicates whether the module is available.

# Functions

## `ao_i2c_ack_2`
## `ao_i2c_ack_from_2`
## `ao_i2c_ack_forever_2`

```c
#define ao_i2c_ack_2(t)         ao_i2c_ack        (ao_i2c_reg_2(), t)
#define ao_i2c_ack_from_2(t, b) ao_i2c_ack_from   (ao_i2c_reg_2(), t, b)
#define ao_i2c_ack_forever_2()  ao_i2c_ack_forever(ao_i2c_reg_2())
```

Generates an acknowledge. The return value indicates, whether the operation succeeded.

| `t` | The timeout. |
| `b` | The beginning. |

## `ao_i2c_acked_2`

```c
#define ao_i2c_acked_2()         \
(                                \
    ao_i2c_acked(ao_i2c_reg_2()) \
)
```

Checks whether an acknowledge has been received.

## `ao_i2c_baud_2`

```c
#define ao_i2c_baud_2(f)   \
(                          \
    ao_i2c_baud            \
    (                      \
        ao_i2c_reg_2(),    \
        AO_SYS_CLOCK_I2C2, \
        f                  \
    )                      \
)
```

Sets up the baud rate, in bits per second.

## `ao_i2c_nack_2`
## `ao_i2c_nack_from_2`
## `ao_i2c_nack_forever_2`

```c
#define ao_i2c_nack_2(t)         ao_i2c_nack        (ao_i2c_reg_2(), t)
#define ao_i2c_nack_from_2(t, b) ao_i2c_nack_from   (ao_i2c_reg_2(), t, b)
#define ao_i2c_nack_forever_2()  ao_i2c_nack_forever(ao_i2c_reg_2())
```

Generates a not acknowledge. The return value indicates, whether the operation succeeded.

| `t` | The timeout. |
| `b` | The beginning. |

## `ao_i2c_nacked_2`

```c
#define ao_i2c_nacked_2()         \
(                                 \
    ao_i2c_nacked(ao_i2c_reg_2()) \
)
```

Checks whether a not acknowledge has been received.

## `ao_i2c_recv_2`
## `ao_i2c_recv_from_2`
## `ao_i2c_recv_forever_2`

```c
#define ao_i2c_recv_2(v, t)         ao_i2c_recv        (ao_i2c_reg_2(), v, t)
#define ao_i2c_recv_from_2(v, t, b) ao_i2c_recv_from   (ao_i2c_reg_2(), v, t, b)
#define ao_i2c_recv_forever_2(v)    ao_i2c_recv_forever(ao_i2c_reg_2(), v)
```

Receives data. The return value indicates, whether the operation succeeded.

| `v` | The pointer to the location to store the received data. |
| `t` | The timeout. |
| `b` | The beginning. |

## `ao_i2c_reg_2`

```c
#define ao_i2c_reg_2()     \
(                          \
    (ao_i2c_reg_t *)       \
    (                      \
        _I2C2_BASE_ADDRESS \
    )                      \
)
```

Gets the control registers.

## `ao_i2c_restart_2`
## `ao_i2c_restart_from_2`
## `ao_i2c_restart_forever_2`

```c
#define ao_i2c_restart_2(t)         ao_i2c_restart        (ao_i2c_reg_2(), t)
#define ao_i2c_restart_from_2(t, b) ao_i2c_restart_from   (ao_i2c_reg_2(), t, b)
#define ao_i2c_restart_forever_2()  ao_i2c_restart_forever(ao_i2c_reg_2())
```

Generates a repeated start bus event. The return value indicates, whether the operation succeeded.

| `t` | The timeout. |
| `b` | The beginning. |

## `ao_i2c_send_2`
## `ao_i2c_send_from_2`
## `ao_i2c_send_forever_2`

```c
#define ao_i2c_send_2(v, t)         ao_i2c_send        (ao_i2c_reg_2(), v, t)
#define ao_i2c_send_from_2(v, t, b) ao_i2c_send_from   (ao_i2c_reg_2(), v, t, b)
#define ao_i2c_send_forever_2(v)    ao_i2c_send_forever(ao_i2c_reg_2(), v)
```

Sends data. The return value indicates, whether the operation succeeded.

| `v` | The data. |
| `t` | The timeout. |
| `b` | The beginning. |

## `ao_i2c_start_2`
## `ao_i2c_start_from_2`
## `ao_i2c_start_forever_2`

```c
#define ao_i2c_start_2(t)         ao_i2c_start        (ao_i2c_reg_2(), t)
#define ao_i2c_start_from_2(t, b) ao_i2c_start_from   (ao_i2c_reg_2(), t, b)
#define ao_i2c_start_forever_2()  ao_i2c_start_forever(ao_i2c_reg_2())
```

Generates a start bus event. The return value indicates, whether the operation succeeded.

| `t` | The timeout. |
| `b` | The beginning. |

## `ao_i2c_stop_2`
## `ao_i2c_stop_from_2`
## `ao_i2c_stop_forever_2`

```c
#define ao_i2c_stop_2(t)         ao_i2c_stop        (ao_i2c_reg_2(), t)
#define ao_i2c_stop_from_2(t, b) ao_i2c_stop_fro    (ao_i2c_reg_2(), t, b)
#define ao_i2c_stop_forever_2()  ao_i2c_stop_forever(ao_i2c_reg_2())
```

Generates a stop bus event. The return value indicates, whether the operation succeeded.

| `t` | The timeout. |
| `b` | The beginning. |
