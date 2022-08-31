---
api: true
author: "Stefan Wagner"
date: 2022-08-31
description: "The /src/ao_sys/ao_button.h file of the ao real-time operating system."
draft: true
permalink: /api/src/ao_sys/ao_button.h/
subtitle: "Buttons"
title: "ao_button.h"
toc: true
---

# Typedefs

```c
typedef enum ao_buttons_t ao_buttons_t;
```

# Constants

```c
#define AO_BUTTON_COUNT (0)
```

# Types

## `ao_buttons_t`

```c
enum ao_buttons_t
{
    AO_BUTTONS_ALL  = 0,
    AO_BUTTONS_NONE = 0
};
```

It consists of the following members.

| `AO_BUTTONS_ALL` | |
| `AO_BUTTONS_NONE` | |

# Functions

```c
ao_buttons_t ao_buttons();
```
