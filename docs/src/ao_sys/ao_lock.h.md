---
api: true
author: "Stefan Wagner"
date: 2022-08-29
description: "The /src/ao_sys/ao_lock.h file of the ao real-time operating system."
draft: true
permalink: /src/ao_sys/ao_lock.h/
subtitle: ""
title: "ao_lock.h"
toc: true
---

# Typedefs

```c
typedef struct ao_lock_t ao_lock_t;
```

# Types

## `ao_lock_t`

```c
struct ao_lock_t { };
```

# Functions

```c
void ao_lock( ao_lock_t * x);
```

```c
void ao_unlock( ao_lock_t * x);
```

