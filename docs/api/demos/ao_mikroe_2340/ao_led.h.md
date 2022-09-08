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

# Constants

## `AO_LED_COUNT`

The number of LEDs.

```c
#define AO_LED_COUNT (4)
```

# Typedefs

```c
typedef enum ao_leds_t ao_leds_t;
```

# Types

## `ao_leds_t`

This type represents LEDs.

```c
enum ao_leds_t
{
    AO_LEDS_NONE = (0),
    AO_LEDS_0    = (1 << 0),
    AO_LEDS_1    = (1 << 1),
    AO_LEDS_2    = (1 << 2),
    AO_LEDS_3    = (1 << 3),
    AO_LEDS_ALL  = (1 << 4) - 1,
    AO_LEDS_A    = AO_LEDS_0,
    AO_LEDS_AB   = AO_LEDS_0 | AO_LEDS_1,
    AO_LEDS_ABC  = AO_LEDS_0 | AO_LEDS_1 | AO_LEDS_2,
    AO_LEDS_ABCD = AO_LEDS_0 | AO_LEDS_1 | AO_LEDS_2 | AO_LEDS_3,
    AO_LEDS_ABD  = AO_LEDS_0 | AO_LEDS_1 | AO_LEDS_3,
    AO_LEDS_AC   = AO_LEDS_0 | AO_LEDS_2,
    AO_LEDS_ACD  = AO_LEDS_0 | AO_LEDS_2 | AO_LEDS_3,
    AO_LEDS_B    = AO_LEDS_1,
    AO_LEDS_BC   = AO_LEDS_1 | AO_LEDS_2,
    AO_LEDS_BCD  = AO_LEDS_1 | AO_LEDS_2 | AO_LEDS_3,
    AO_LEDS_BD   = AO_LEDS_1 | AO_LEDS_3,
    AO_LEDS_C    = AO_LEDS_2,
    AO_LEDS_CD   = AO_LEDS_2 | AO_LEDS_3,
    AO_LEDS_D    = AO_LEDS_3
};
```

It is used as a bitmask and defines the following symbols.

| `AO_LEDS_NONE` | Represents no LEDs. |
| `AO_LEDS_0` | Represents LED A at pin A6. |
| `AO_LEDS_1` | Represents LED B at pin A7. |
| `AO_LEDS_2` | Represents LED C at pin E0. |
| `AO_LEDS_3` | Represents LED D at pin E1. |
| `AO_LEDS_ALL` | Represents all LEDs. |
| `AO_LEDS_A` | Represents LED A. |
| `AO_LEDS_AB` | Represents LEDs A and B. |
| `AO_LEDS_ABC` | Represents LEDs A, B, and C. |
| `AO_LEDS_ABCD` | Represents LEDs A, B, C, and D. |
| `AO_LEDS_ABD` | Represents LEDs A, B, and D. |
| `AO_LEDS_AC` | Represents LEDs A and C. |
| `AO_LEDS_ACD` | Represents LEDs A, C, and D. |
| `AO_LEDS_AD` | Represents LEDs A and D. |
| `AO_LEDS_B` | Represents LED B. |
| `AO_LEDS_BC` | Represents LEDs B and C. |
| `AO_LEDS_BCD` | Represents LEDs B, C, and D. |
| `AO_LEDS_BD` | Represents LEDs B and D. |
| `AO_LEDS_C` | Represents LED C. |
| `AO_LEDS_CD` | Represents LEDs C and D. |
| `AO_LEDS_D` | Represents LED D. |

# Functions

## `ao_leds`

Gets the LEDs that are enabled.

```c
#define ao_leds()
```

## `ao_leds_enable`
## `ao_leds_disable`
## `ao_leds_toggle`

Enable, disable, or toggle, respectively, the specified LEDs.

```c
#define ao_leds_enable( leds)
#define ao_leds_disable(leds)
#define ao_leds_toggle( leds)
```
