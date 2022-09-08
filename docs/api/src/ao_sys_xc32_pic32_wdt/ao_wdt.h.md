---
author: "Stefan Wagner"
date: 2022-09-05
draft: true
permalink: /api/src/ao_sys_xc32_pic32_wdt/ao_wdt.h/
toc: true
---

# Include

```c
#include <stdbool.h>
#include <xc.h>
```

# Functions

## `ao_wdt_enable`
## `ao_wdt_disable`

Enable or disable the watchdog timer.

```c
#define ao_wdt_enable()
#define ao_wdt_disable()
```

## `ao_wdt_is_enabled`

Check whether the watchdog timer is enabled.

```c
#define ao_wdt_is_enabled()
```

## `ao_wdt_reset`

Reset the watchdog timer.

```c
void ao_wdt_reset();
```
