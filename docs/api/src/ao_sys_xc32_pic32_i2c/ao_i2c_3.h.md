---
api: true
author: "Stefan Wagner"
date: 2022-08-29
description: "The /src/ao_sys_xc32_pic32_i2c/ao_i2c_3.h file of the ao real-time operating system."
draft: true
permalink: /api/src/ao_sys_xc32_pic32_i2c/ao_i2c_3.h/
subtitle: "I²C 3"
title: "ao_i2c_3.h"
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

```c
#define AO_I2C_3 (false)
```

```c
#define AO_I2C_3 (true)
```

# Functions

```c
#define ao_i2c_ack_3(t)
```

```c
#define ao_i2c_ack_from_3(t, b)
```

```c
#define ao_i2c_ack_forever_3()
```

```c
#define ao_i2c_acked_3()
```

```c
#define ao_i2c_baud_3(f)
```

```c
#define ao_i2c_nack_3(t)
```

```c
#define ao_i2c_nack_from_3(t, b)
```

```c
#define ao_i2c_nack_forever_3()
```

```c
#define ao_i2c_nacked_3()
```

```c
#define ao_i2c_recv_3(v, t)
```

```c
#define ao_i2c_recv_from_3(v, t, b)
```

```c
#define ao_i2c_recv_forever_3(v)
```

```c
#define ao_i2c_reg_3()
```

```c
#define ao_i2c_restart_3(t)
```

```c
#define ao_i2c_restart_from_3(t, b)
```

```c
#define ao_i2c_restart_forever_3()
```

```c
#define ao_i2c_send_3(v, t)
```

```c
#define ao_i2c_send_from_3(v, t, b)
```

```c
#define ao_i2c_send_forever_3(v)
```

```c
#define ao_i2c_start_3(t)
```

```c
#define ao_i2c_start_from_3(t, b)
```

```c
#define ao_i2c_start_forever_3()
```

```c
#define ao_i2c_stop_3(t)
```

```c
#define ao_i2c_stop_from_3(t, b)
```

```c
#define ao_i2c_stop_forever_3()
```
