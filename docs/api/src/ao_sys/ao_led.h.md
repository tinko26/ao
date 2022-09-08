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

The number of LEDs.

```c
#define AO_LED_COUNT (0)
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
    AO_LEDS_ALL  = 0,
    AO_LEDS_NONE = 0
};
```

It is used as a bitmask and defines at least the following symbols.

| `AO_LEDS_ALL` | Represents all LEDs. |
| `AO_LEDS_NONE` | Represents no LEDs. |

# Functions

## `ao_leds`

Gets the LEDs that are enabled.

```c
ao_leds_t ao_leds();
```

## `ao_leds_enable`
## `ao_leds_disable`
## `ao_leds_toggle`

Enable, disable, or toggle, respectively, the specified LEDs.

```c
void ao_leds_enable( ao_leds_t x);
void ao_leds_disable(ao_leds_t x);
void ao_leds_toggle( ao_leds_t x);
```
