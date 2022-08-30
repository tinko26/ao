---
api: true
author: "Stefan Wagner"
date: 2022-08-29
description: "The /src/ao_sys_xc32_pic32_i2c/ao_i2c_4.h file of the ao real-time operating system."
draft: true
permalink: /api/src/ao_sys_xc32_pic32_i2c/ao_i2c_4.h/
subtitle: ""
title: "ao_i2c_4.h"
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
#define AO_I2C_4 (false)
```

```c
#define AO_I2C_4 (true)
```

# Functions

```c
#define ao_i2c_ack_4(t)
```

```c
#define ao_i2c_ack_from_4(t, b)
```

```c
#define ao_i2c_ack_forever_4()
```

```c
#define ao_i2c_acked_4()
```

```c
#define ao_i2c_baud_4(f)
```

```c
#define ao_i2c_nack_4(t)
```

```c
#define ao_i2c_nack_from_4(t, b)
```

```c
#define ao_i2c_nack_forever_4()
```

```c
#define ao_i2c_nacked_4()
```

```c
#define ao_i2c_recv_4(v, t)
```

```c
#define ao_i2c_recv_from_4(v, t, b)
```

```c
#define ao_i2c_recv_forever_4(v)
```

```c
#define ao_i2c_reg_4()
```

```c
#define ao_i2c_restart_4(t)
```

```c
#define ao_i2c_restart_from_4(t, b)
```

```c
#define ao_i2c_restart_forever_4()
```

```c
#define ao_i2c_send_4(v, t)
```

```c
#define ao_i2c_send_from_4(v, t, b)
```

```c
#define ao_i2c_send_forever_4(v)
```

```c
#define ao_i2c_start_4(t)
```

```c
#define ao_i2c_start_from_4(t, b)
```

```c
#define ao_i2c_start_forever_4()
```

```c
#define ao_i2c_stop_4(t)
```

```c
#define ao_i2c_stop_from_4(t, b)
```

```c
#define ao_i2c_stop_forever_4()
```

