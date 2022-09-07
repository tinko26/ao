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

# Typedefs

```c
typedef enum ao_buttons_t ao_buttons_t;
```

# Constants

```c
#define AO_BUTTON_COUNT (2)
```

# Types

## `ao_buttons_t`

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

It consists of the following members.

| `AO_BUTTONS_NONE` | |
| `AO_BUTTONS_0` | |
| `AO_BUTTONS_1` | |
| `AO_BUTTONS_ALL` | |

# Functions

```c
#define ao_buttons()
```
