---
author: "Stefan Wagner"
date: 2022-08-30
draft: true
permalink: /api/demos/ao_mikroe_2340/ao_led.h/
toc: true
---

# Include

| `stdint.h` |
| `xc.h` |

# Constants

## `AO_LED_COUNT`

```c
#define AO_LED_COUNT (4)
```

The number of LEDs.

# Types

## `ao_leds_t`

```c
typedef enum ao_leds_t ao_leds_t;
```

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

This type represents LEDs. It is used as a bitmask and defines the following symbols.

| `AO_LEDS_NONE` | `0000` | Represents no LEDs. |
| `AO_LEDS_0`    | `0001` | Represents LED A at pin A6. |
| `AO_LEDS_1`    | `0010` | Represents LED B at pin A7. |
| `AO_LEDS_2`    | `0100` | Represents LED C at pin E0. |
| `AO_LEDS_3`    | `1000` | Represents LED D at pin E1. |
| `AO_LEDS_ALL`  | `1111` | Represents all LEDs. |
| `AO_LEDS_A`    | `0001` | Represents LED A. |
| `AO_LEDS_AB`   | `0011` | Represents LEDs A and B. |
| `AO_LEDS_ABC`  | `0111` | Represents LEDs A, B, and C. |
| `AO_LEDS_ABCD` | `1111` | Represents LEDs A, B, C, and D. |
| `AO_LEDS_ABD`  | `1011` | Represents LEDs A, B, and D. |
| `AO_LEDS_AC`   | `0101` | Represents LEDs A and C. |
| `AO_LEDS_ACD`  | `1101` | Represents LEDs A, C, and D. |
| `AO_LEDS_AD`   | `1001` | Represents LEDs A and D. |
| `AO_LEDS_B`    | `0010` | Represents LED B. |
| `AO_LEDS_BC`   | `0110` | Represents LEDs B and C. |
| `AO_LEDS_BCD`  | `1110` | Represents LEDs B, C, and D. |
| `AO_LEDS_BD`   | `1010` | Represents LEDs B and D. |
| `AO_LEDS_C`    | `0100` | Represents LED C. |
| `AO_LEDS_CD`   | `1100` | Represents LEDs C and D. |
| `AO_LEDS_D`    | `1000` | Represents LED D. |

# Functions

## `ao_leds`

```c
#define ao_leds()
```

Gets the LEDs that are enabled.

## `ao_leds_enable`
## `ao_leds_disable`
## `ao_leds_toggle`

```c
#define ao_leds_enable( leds)
#define ao_leds_disable(leds)
#define ao_leds_toggle( leds)
```

Enables, disables, or toggles, respectively, the specified LEDs.
