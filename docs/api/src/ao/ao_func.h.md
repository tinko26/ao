---
author: "Stefan Wagner"
date: 2022-09-24
draft: true
permalink: /api/src/ao/ao_func.h/
toc: true
---

# Include

| `stdbool.h` |

# Identifier

```c
#define AO_FUNC
```

# Types

## `ao_func_t`

```c
typedef void * (* ao_func_t) (void *);
```

Function.

## `ao_func*_t`

```c
typedef void * (* ao_func0_t) ();
typedef void * (* ao_func1_t) (void *);
typedef void * (* ao_func2_t) (void *, void *);
typedef void * (* ao_func3_t) (void *, void *, void *);
```

Functions.

## `ao_pred_t`

```c
typedef bool (* ao_pred_t) (void *);
```

Predicate.

## `ao_pred*_t`

```c
typedef bool (* ao_pred0_t) ();
typedef bool (* ao_pred1_t) (void *);
typedef bool (* ao_pred2_t) (void *, void *);
typedef bool (* ao_pred3_t) (void *, void *, void *);
```

Predicates.

## `ao_proc_t`

```c
typedef void (* ao_proc_t) (void *);
```

Procedure.

## `ao_proc*_t`

```c
typedef void (* ao_proc0_t) ();
typedef void (* ao_proc1_t) (void *);
typedef void (* ao_proc2_t) (void *, void *);
typedef void (* ao_proc3_t) (void *, void *, void *);
```

Procedures.
