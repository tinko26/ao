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

# Constants

## `AO_LED_COUNT`

The number of LEDs.

```c
#define AO_LED_COUNT (2)
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
    AO_LEDS_NONE = 0,
    AO_LEDS_0    = (1 << 0),
    AO_LEDS_1    = (1 << 1),
    AO_LEDS_ALL  = (1 << 2) - 1
};
```

It is used as a bitmask and defines the following symbols.

| `AO_LEDS_NONE` | Represents no LEDs. |
| `AO_LEDS_0` | Represents LED 0 at pin E7. |
| `AO_LEDS_1` | Represents LED 1 at pin A9. |
| `AO_LEDS_ALL` | Represents all LEDs. |

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
