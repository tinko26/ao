---
author: "Stefan Wagner"
date: 2022-09-25
draft: true
permalink: /api/demos/ao_mikroe_2800/ao_led.h/
toc: true
---

# Include

| `stdint.h` |
| `xc.h` |

# Identifier

```c
#define AO_BUTTON
```

# Constants

## `AO_LED_COUNT`

```c
#define AO_LED_COUNT (2)
```

The number of LEDs.

# Types

## `ao_leds_t`

```c
typedef enum ao_leds_t ao_leds_t;
```

This type represents LEDs.

# Enums

## `ao_leds_t`

```c
enum ao_leds_t
{
    AO_LEDS_NONE = 0,
    AO_LEDS_0    = (1 << 0),
    AO_LEDS_1    = (1 << 1),
    AO_LEDS_ALL  = (1 << 2) - 1
};
```

| `AO_LEDS_NONE` | `00` | Represents no LEDs. |
| `AO_LEDS_0`    | `01` | Represents LED 0 at pin E7. |
| `AO_LEDS_1`    | `10` | Represents LED 1 at pin A9. |
| `AO_LEDS_ALL`  | `11` | Represents all LEDs. |

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
