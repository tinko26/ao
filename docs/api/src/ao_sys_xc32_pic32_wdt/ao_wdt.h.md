---
api: true
author: "Stefan Wagner"
date: 2022-09-05
description: "The /src/ao_sys_xc32_pic32_wdt/ao_wdt.h file of the ao real-time operating system."
draft: true
permalink: /api/src/ao_sys_xc32_pic32_wdt/ao_wdt.h/
subtitle: "Watchdog timer"
title: "ao_wdt.h"
toc: true
---

# Include

```c
#include <stdbool.h>
#include <xc.h>
```

# Functions

Enable or disable the watchdog timer.

```c
#define ao_wdt_enable()
#define ao_wdt_disable()
```

Check whether the watchdog timer is enabled.

```c
#define ao_wdt_is_enabled()
```

Reset the watchdog timer.

```c
void ao_wdt_reset();
```
