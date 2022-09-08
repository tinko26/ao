---
author: "Stefan Wagner"
date: 2022-08-30
draft: true
permalink: /api/demos/ao_mikroe_2340/ao_button.h/
toc: true
---

# Include

```c
#include <xc.h>
```

# Constants

The number of buttons.

```c
#define AO_BUTTON_COUNT (2)
```

# Typedefs

```c
typedef enum ao_buttons_t ao_buttons_t;
```

# Types

## `ao_buttons_t`

This type represents buttons.

```c
enum ao_buttons_t
{
    AO_BUTTONS_NONE = (0),
    AO_BUTTONS_0    = (1 << 0),
    AO_BUTTONS_1    = (1 << 1),
    AO_BUTTONS_ALL  =
        AO_BUTTONS_0 |
        AO_BUTTONS_1
};
```

It is used as a bitmask and defines the following symbols.

| `AO_BUTTONS_NONE` | Represents no buttons. |
| `AO_BUTTONS_0` | Represents button 0 at pin D10. |
| `AO_BUTTONS_1` | Represents button 1 at pin D11. |
| `AO_BUTTONS_ALL` | Represents all buttons. |

# Functions

## `ao_buttons`

Gets the buttons that are pressed.

```c
#define ao_buttons()
```
