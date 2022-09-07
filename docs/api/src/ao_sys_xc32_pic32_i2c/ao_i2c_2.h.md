---
author: "Stefan Wagner"
date: 2022-08-29
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

# Constants

## `AO_I2C`

Indicates whether the I²C module is available.

```c
#define AO_I2C_2
```

# Functions

```c
#define ao_i2c_ack_2(t)
```

```c
#define ao_i2c_ack_from_2(t, b)
```

```c
#define ao_i2c_ack_forever_2()
```

```c
#define ao_i2c_acked_2()
```

```c
#define ao_i2c_baud_2(f)
```

```c
#define ao_i2c_nack_2(t)
```

```c
#define ao_i2c_nack_from_2(t, b)
```

```c
#define ao_i2c_nack_forever_2()
```

```c
#define ao_i2c_nacked_2()
```

```c
#define ao_i2c_recv_2(v, t)
```

```c
#define ao_i2c_recv_from_2(v, t, b)
```

```c
#define ao_i2c_recv_forever_2(v)
```

```c
#define ao_i2c_reg_2()
```

```c
#define ao_i2c_restart_2(t)
```

```c
#define ao_i2c_restart_from_2(t, b)
```

```c
#define ao_i2c_restart_forever_2()
```

```c
#define ao_i2c_send_2(v, t)
```

```c
#define ao_i2c_send_from_2(v, t, b)
```

```c
#define ao_i2c_send_forever_2(v)
```

```c
#define ao_i2c_start_2(t)
```

```c
#define ao_i2c_start_from_2(t, b)
```

```c
#define ao_i2c_start_forever_2()
```

```c
#define ao_i2c_stop_2(t)
```

```c
#define ao_i2c_stop_from_2(t, b)
```

```c
#define ao_i2c_stop_forever_2()
```
