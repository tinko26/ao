---
author: "Stefan Wagner"
date: 2022-09-27
draft: true
permalink: /api/demos/ao_mikroe_2800/ao_button.h/
toc: true
---

# Include

| `xc.h` |

# Constants

```c
#define AO_BUTTON_COUNT (2)
```

The number of buttons.

# Types

## `ao_buttons_t`

```c
typedef enum ao_buttons_t ao_buttons_t;
```

Represents buttons.

# Enums

## `ao_buttons_t`

```c
enum ao_buttons_t
{
    AO_BUTTONS_NONE = 0,
    AO_BUTTONS_0    = (1 << 0),
    AO_BUTTONS_1    = (1 << 1),
    AO_BUTTONS_ALL  = 
        AO_BUTTONS_0 | 
        AO_BUTTONS_1
};
```

| `AO_BUTTONS_NONE` | `00` | Represents no buttons. |
| `AO_BUTTONS_0`    | `01` | Represents button 0 at pin C3. |
| `AO_BUTTONS_1`    | `10` | Represents button 1 at pin B0. |
| `AO_BUTTONS_ALL`  | `11` | Represents all buttons. |

# Functions

## `ao_buttons`

```c
#define ao_buttons()
```

Gets the buttons that are pressed.
