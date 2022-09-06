---
author: "Stefan Wagner"
date: 2022-08-30
draft: true
permalink: /api/demos/ao_mikroe_2340/ao_led.h/
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
#define AO_LED_COUNT (4)
```

# Types

## `ao_leds_t`

```c
enum ao_leds_t
{
AO_LEDS_NONE = (0),
AO_LEDS_0 = (1 << 0),
AO_LEDS_1 = (1 << 1),
AO_LEDS_2 = (1 << 2),
AO_LEDS_3 = (1 << 3),
AO_LEDS_ALL = (1 << 4) - 1,
AO_LEDS_A = AO_LEDS_0,
AO_LEDS_AB = AO_LEDS_0 | AO_LEDS_1,
AO_LEDS_ABC = AO_LEDS_0 | AO_LEDS_1 | AO_LEDS_2,
AO_LEDS_ABCD = AO_LEDS_0 | AO_LEDS_1 | AO_LEDS_2 | AO_LEDS_3,
AO_LEDS_ABD = AO_LEDS_0 | AO_LEDS_1 | AO_LEDS_3,
AO_LEDS_AC = AO_LEDS_0 | AO_LEDS_2,
AO_LEDS_ACD = AO_LEDS_0 | AO_LEDS_2 | AO_LEDS_3,
AO_LEDS_B = AO_LEDS_1,
AO_LEDS_BC = AO_LEDS_1 | AO_LEDS_2,
AO_LEDS_BCD = AO_LEDS_1 | AO_LEDS_2 | AO_LEDS_3,
AO_LEDS_BD = AO_LEDS_1 | AO_LEDS_3,
AO_LEDS_C = AO_LEDS_2,
AO_LEDS_CD = AO_LEDS_2 | AO_LEDS_3,
AO_LEDS_D = AO_LEDS_3
};
```

It consists of the following members.

| `AO_LEDS_NONE` | |
| `AO_LEDS_0` | |
| `AO_LEDS_1` | |
| `AO_LEDS_2` | |
| `AO_LEDS_3` | |
| `AO_LEDS_ALL` | |
| `AO_LEDS_A` | |
| `AO_LEDS_AB` | |
| `AO_LEDS_ABC` | |
| `AO_LEDS_ABCD` | |
| `AO_LEDS_ABD` | |
| `AO_LEDS_AC` | |
| `AO_LEDS_ACD` | |
| `AO_LEDS_B` | |
| `AO_LEDS_BC` | |
| `AO_LEDS_BCD` | |
| `AO_LEDS_BD` | |
| `AO_LEDS_C` | |
| `AO_LEDS_CD` | |
| `AO_LEDS_D` | |

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
