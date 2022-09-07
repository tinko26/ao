---
author: "Stefan Wagner"
date: 2022-08-30
draft: true
permalink: /api/demos/ao_mikroe_2800/ao_led.h/
toc: true
---

# Include

```c
#include <stdint.h>
#include <xc.h>
```

# Typedefs

```c
typedef enum ao_leds_t ao_leds_t;
```

# Constants

```c
#define AO_LED_COUNT (2)
```

# Types

## `ao_leds_t`

```c
enum ao_leds_t
{
    AO_LEDS_NONE = 0,
    AO_LEDS_0    = (1 << 0),
    AO_LEDS_1    = (1 << 1),
    AO_LEDS_ALL  = 
        AO_LEDS_0 | 
        AO_LEDS_1
};
```

It consists of the following members.

| `AO_LEDS_0` | |
| `AO_LEDS_1` | |
| `AO_LEDS_ALL` | |
| `AO_LEDS_NONE` | |

# Functions

```c
#define ao_leds()
```

```c
#define ao_leds_disable(leds)
```

```c
#define ao_leds_enable(leds)
```

```c
#define ao_leds_toggle(leds)
```
