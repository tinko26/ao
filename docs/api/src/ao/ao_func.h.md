---
api: true
author: "Stefan Wagner"
date: 2022-08-30
description: "The /src/ao/ao_func.h file of the ao real-time operating system."
draft: false
permalink: /api/src/ao/ao_func.h/
subtitle: "Function pointer types"
title: "ao_func.h"
toc: true
---

# Include

```c
#include <stdbool.h>
```

# Typedefs

Functions.

```c
typedef void * (* ao_func_t) (void *);
```

```c
typedef void * (* ao_func0_t) ();
typedef void * (* ao_func1_t) (void *);
typedef void * (* ao_func2_t) (void *, void *);
typedef void * (* ao_func3_t) (void *, void *, void *);
```

Predicates.

```c
typedef bool (* ao_pred_t) (void *);
```

```c
typedef bool (* ao_pred0_t) ();
typedef bool (* ao_pred1_t) (void *);
typedef bool (* ao_pred2_t) (void *, void *);
typedef bool (* ao_pred3_t) (void *, void *, void *);
```

Procedures.

```c
typedef void (* ao_proc_t) (void *);
```

```c
typedef void (* ao_proc0_t) ();
typedef void (* ao_proc1_t) (void *);
typedef void (* ao_proc2_t) (void *, void *);
typedef void (* ao_proc3_t) (void *, void *, void *);
```
