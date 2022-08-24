---
author: "Stefan Wagner"
date: 2022-08-04
description: "The ao_var.h module of the ao real-time operating system."
draft: false
permalink: /modules/var/
title: "ao_var.h"
---

# Overview

This module defines two convenience macro functions for variables.

## Functions

The `ao_copy()` macro function copies a variable.

```c
uint32_t a = 0xDEADBEEFU;
uint32_t b;
```

```c
ao_copy(&b, &a, uint32_t);
```

```c
ao_assert(a == b);
```

The `ao_clear()` macro function clears a variable. This is especially useful when initializing objects that have been allocated on the stack.

```c
ao_list_t l;
```

```c
ao_clear(&l, ao_list_t);
```

```c
ao_assert(l.back  == NULL);
ao_assert(l.front == NULL);
```
