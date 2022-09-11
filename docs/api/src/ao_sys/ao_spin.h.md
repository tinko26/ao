---
author: "Stefan Wagner"
date: 2022-08-31
draft: true
external:
- https://en.wikipedia.org/wiki/Busy_waiting : "Busy waiting"
permalink: /api/src/ao_sys/ao_spin.h/
toc: true
---

# Notes

This module defines functions for spinning or busy waiting, respectively, that can be used to generate time delays.

# Include

```c
#include <ao_time.h>
```

# Identifier

```c
#define AO_SPIN
```

# Functions

## `ao_spin`
## `ao_spin_from`

```c
void ao_spin(ao_time_t timeout);
void ao_spin_from(ao_time_t timeout, ao_time_t beginning);
```

## `ao_spin_forever`

```c
void ao_spin_forever();
```
