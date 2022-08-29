---
api: true
author: "Stefan Wagner"
date: 2022-08-29
description: "The ao/ao_func.h module of the ao real-time operating system."
draft: true
permalink: /ao/ao_func.h/ 
subtitle: ""
title: "ao_func.h"
toc: true
---

```c
#include <stdbool.h>

typedef void *  (*  ao_func_t)  (void *);

typedef void *  (*  ao_func0_t) ();

typedef void *  (*  ao_func1_t) (void *);

typedef void *  (*  ao_func2_t) (void *, void *);

typedef void *  (*  ao_func3_t) (void *, void *, void *);

typedef bool    (*  ao_pred_t)  (void *);

typedef bool    (*  ao_pred0_t) ();

typedef bool    (*  ao_pred1_t) (void *);

typedef bool    (*  ao_pred2_t) (void *, void *);

typedef bool    (*  ao_pred3_t) (void *, void *, void *);

typedef void    (*  ao_proc_t)  (void *);

typedef void    (*  ao_proc0_t) ();

typedef void    (*  ao_proc1_t) (void *);

typedef void    (*  ao_proc2_t) (void *, void *);

typedef void    (*  ao_proc3_t) (void *, void *, void *);

```
