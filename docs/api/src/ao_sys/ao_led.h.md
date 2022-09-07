---
author: "Stefan Wagner"
date: 2022-08-31
draft: true
external-wiki:
- light-emitting-diode
permalink: /api/src/ao_sys/ao_led.h/
toc: true
---

# Typedefs

```c
typedef enum ao_leds_t ao_leds_t;
```

# Constants

```c
#define AO_LED_COUNT (0)
```

# Types

## `ao_leds_t`

```c
enum ao_leds_t
{
AO_LEDS_ALL  = 0,
AO_LEDS_NONE = 0
};
```

It consists of the following members.

| `AO_LEDS_ALL` | |
| `AO_LEDS_NONE` | |

# Functions

```c
ao_leds_t ao_leds();
```

```c
void ao_leds_disable(ao_leds_t x);
```

```c
void ao_leds_enable(ao_leds_t x);
```

```c
void ao_leds_toggle(ao_leds_t x);
```
