---
author: "Stefan Wagner"
date: 2022-08-31
draft: true
permalink: /api/src/ao_sys/ao_button.h/
toc: true
---

# Constants

## `AO_BUTTON_COUNT`

```c
#define AO_BUTTON_COUNT (0)
```

The number of buttons.

# Types

## `ao_buttons_t`

```c
typedef enum ao_buttons_t ao_buttons_t;
```

```c
enum ao_buttons_t
{
    AO_BUTTONS_ALL  = 0,
    AO_BUTTONS_NONE = 0
};
```

This type represents buttons. It is used as a bitmask and defines at least the following symbols.

| `AO_BUTTONS_ALL` | `0` | Represents all buttons. |
| `AO_BUTTONS_NONE` | `0` | Represents no buttons. |

# Functions

## `ao_buttons`

```c
ao_buttons_t ao_buttons();
```

Gets the buttons that are pressed.
