---
author: "Stefan Wagner"
date: 2022-08-04
description: "The ao_func.h module of the ao real-time operating system."
draft: false
permalink: /modules/func/
title: "ao_func.h"
---

# Overview

This module defines the following general-purpose pointer types for functions, ...

```c
typedef void * (* ao_func_t ) (void *);
```

```c
typedef void * (* ao_func0_t) ();
typedef void * (* ao_func1_t) (void *);
typedef void * (* ao_func2_t) (void *, void *);
typedef void * (* ao_func3_t) (void *, void *, void *);
```

... predicates, ...

```c
typedef bool   (* ao_pred_t ) (void *);
```

```c
typedef bool   (* ao_pred0_t) ();
typedef bool   (* ao_pred1_t) (void *);
typedef bool   (* ao_pred2_t) (void *, void *);
typedef bool   (* ao_pred3_t) (void *, void *, void *);
```

... and procedures.

```c
typedef void   (* ao_proc_t ) (void *);
```

```c
typedef void   (* ao_proc0_t) ();
typedef void   (* ao_proc1_t) (void *);
typedef void   (* ao_proc2_t) (void *, void *);
typedef void   (* ao_proc3_t) (void *, void *, void *);
```
