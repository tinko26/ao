---
author: "Stefan Wagner"
date: 2022-08-31
draft: true
external:
- https://en.wikipedia.org/wiki/Light-emitting_diode : "Light-emitting diode"
permalink: /api/src/ao_sys/ao_led.h/
toc: true
---

# Constants

## `AO_LED_COUNT`

```c
#define AO_LED_COUNT (0)
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
    AO_LEDS_ALL  = 0,
    AO_LEDS_NONE = 0
};
```

This type represents LEDs. It is used as a bitmask and defines at least the following symbols.

| `AO_LEDS_ALL` | `0` | Represents all LEDs. |
| `AO_LEDS_NONE` | `0` | Represents no LEDs. |

# Functions

## `ao_leds`

```c
ao_leds_t ao_leds();
```

Gets the LEDs that are enabled.

## `ao_leds_enable`
## `ao_leds_disable`
## `ao_leds_toggle`

```c
void ao_leds_enable( ao_leds_t x);
void ao_leds_disable(ao_leds_t x);
void ao_leds_toggle( ao_leds_t x);
```

Enables, disables, or toggles, respectively, the specified LEDs.
