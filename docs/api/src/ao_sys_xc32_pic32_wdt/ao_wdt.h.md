---
author: "Stefan Wagner"
date: 2022-09-05
draft: true
permalink: /api/src/ao_sys_xc32_pic32_wdt/ao_wdt.h/
toc: true
---

# Include

| `stdbool.h` |
| `xc.h` |

# Functions

## `ao_wdt_enable`
## `ao_wdt_disable`

```c
#define ao_wdt_enable()
#define ao_wdt_disable()
```

Enables or disables the watchdog timer.

## `ao_wdt_is_enabled`

```c
#define ao_wdt_is_enabled()
```

Checks whether the watchdog timer is enabled.

## `ao_wdt_reset`

```c
void ao_wdt_reset();
```

Resets the watchdog timer.
