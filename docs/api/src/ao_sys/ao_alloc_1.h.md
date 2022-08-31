---
api: true
author: "Stefan Wagner"
date: 2022-08-29
description: "The /src/ao_sys/ao_alloc_1.h file of the ao real-time operating system."
draft: true
permalink: /api/src/ao_sys/ao_alloc_1.h/
subtitle: ""
title: "ao_alloc_1.h"
toc: true
---

# Include

```c
#include <stdbool.h>
#include <stddef.h>
```

# Typedefs

```c
typedef struct ao_alloc_pool_t ao_alloc_pool_t;
```

```c
typedef struct ao_alloc_pool_node_t ao_alloc_pool_node_t;
```

```c
typedef struct ao_acquired_t ao_acquired_t;
```

```c
typedef struct ao_released_t ao_released_t;
```

```c
typedef struct ao_retained_t ao_retained_t;
```

# Constants

```c
#define AO_ALLOC_ALLOCATED (false)
```

```c
#define AO_ALLOC_ALLOCATED_MAX (false)
```

```c
#define AO_ALLOC_FREE (false)
```

```c
#define AO_ALLOC_FREE_MIN (false)
```

```c
#define AO_ALLOC_POOL_BLOCK_COUNT_0 (0)
```

```c
#define AO_ALLOC_POOL_BLOCK_COUNT_1 (0)
```

```c
#define AO_ALLOC_POOL_BLOCK_COUNT_10 (0)
```

```c
#define AO_ALLOC_POOL_BLOCK_COUNT_11 (0)
```

```c
#define AO_ALLOC_POOL_BLOCK_COUNT_12 (0)
```

```c
#define AO_ALLOC_POOL_BLOCK_COUNT_13 (0)
```

```c
#define AO_ALLOC_POOL_BLOCK_COUNT_14 (0)
```

```c
#define AO_ALLOC_POOL_BLOCK_COUNT_15 (0)
```

```c
#define AO_ALLOC_POOL_BLOCK_COUNT_16 (0)
```

```c
#define AO_ALLOC_POOL_BLOCK_COUNT_17 (0)
```

```c
#define AO_ALLOC_POOL_BLOCK_COUNT_18 (0)
```

```c
#define AO_ALLOC_POOL_BLOCK_COUNT_19 (0)
```

```c
#define AO_ALLOC_POOL_BLOCK_COUNT_2 (0)
```

```c
#define AO_ALLOC_POOL_BLOCK_COUNT_20 (0)
```

```c
#define AO_ALLOC_POOL_BLOCK_COUNT_21 (0)
```

```c
#define AO_ALLOC_POOL_BLOCK_COUNT_22 (0)
```

```c
#define AO_ALLOC_POOL_BLOCK_COUNT_23 (0)
```

```c
#define AO_ALLOC_POOL_BLOCK_COUNT_24 (0)
```

```c
#define AO_ALLOC_POOL_BLOCK_COUNT_25 (0)
```

```c
#define AO_ALLOC_POOL_BLOCK_COUNT_26 (0)
```

```c
#define AO_ALLOC_POOL_BLOCK_COUNT_27 (0)
```

```c
#define AO_ALLOC_POOL_BLOCK_COUNT_28 (0)
```

```c
#define AO_ALLOC_POOL_BLOCK_COUNT_29 (0)
```

```c
#define AO_ALLOC_POOL_BLOCK_COUNT_3 (0)
```

```c
#define AO_ALLOC_POOL_BLOCK_COUNT_30 (0)
```

```c
#define AO_ALLOC_POOL_BLOCK_COUNT_31 (0)
```

```c
#define AO_ALLOC_POOL_BLOCK_COUNT_32 (0)
```

```c
#define AO_ALLOC_POOL_BLOCK_COUNT_33 (0)
```

```c
#define AO_ALLOC_POOL_BLOCK_COUNT_34 (0)
```

```c
#define AO_ALLOC_POOL_BLOCK_COUNT_35 (0)
```

```c
#define AO_ALLOC_POOL_BLOCK_COUNT_36 (0)
```

```c
#define AO_ALLOC_POOL_BLOCK_COUNT_37 (0)
```

```c
#define AO_ALLOC_POOL_BLOCK_COUNT_38 (0)
```

```c
#define AO_ALLOC_POOL_BLOCK_COUNT_39 (0)
```

```c
#define AO_ALLOC_POOL_BLOCK_COUNT_4 (0)
```

```c
#define AO_ALLOC_POOL_BLOCK_COUNT_40 (0)
```

```c
#define AO_ALLOC_POOL_BLOCK_COUNT_41 (0)
```

```c
#define AO_ALLOC_POOL_BLOCK_COUNT_42 (0)
```

```c
#define AO_ALLOC_POOL_BLOCK_COUNT_43 (0)
```

```c
#define AO_ALLOC_POOL_BLOCK_COUNT_44 (0)
```

```c
#define AO_ALLOC_POOL_BLOCK_COUNT_45 (0)
```

```c
#define AO_ALLOC_POOL_BLOCK_COUNT_46 (0)
```

```c
#define AO_ALLOC_POOL_BLOCK_COUNT_47 (0)
```

```c
#define AO_ALLOC_POOL_BLOCK_COUNT_48 (0)
```

```c
#define AO_ALLOC_POOL_BLOCK_COUNT_49 (0)
```

```c
#define AO_ALLOC_POOL_BLOCK_COUNT_5 (0)
```

```c
#define AO_ALLOC_POOL_BLOCK_COUNT_50 (0)
```

```c
#define AO_ALLOC_POOL_BLOCK_COUNT_51 (0)
```

```c
#define AO_ALLOC_POOL_BLOCK_COUNT_52 (0)
```

```c
#define AO_ALLOC_POOL_BLOCK_COUNT_53 (0)
```

```c
#define AO_ALLOC_POOL_BLOCK_COUNT_54 (0)
```

```c
#define AO_ALLOC_POOL_BLOCK_COUNT_55 (0)
```

```c
#define AO_ALLOC_POOL_BLOCK_COUNT_56 (0)
```

```c
#define AO_ALLOC_POOL_BLOCK_COUNT_57 (0)
```

```c
#define AO_ALLOC_POOL_BLOCK_COUNT_58 (0)
```

```c
#define AO_ALLOC_POOL_BLOCK_COUNT_59 (0)
```

```c
#define AO_ALLOC_POOL_BLOCK_COUNT_6 (0)
```

```c
#define AO_ALLOC_POOL_BLOCK_COUNT_60 (0)
```

```c
#define AO_ALLOC_POOL_BLOCK_COUNT_61 (0)
```

```c
#define AO_ALLOC_POOL_BLOCK_COUNT_62 (0)
```

```c
#define AO_ALLOC_POOL_BLOCK_COUNT_63 (0)
```

```c
#define AO_ALLOC_POOL_BLOCK_COUNT_7 (0)
```

```c
#define AO_ALLOC_POOL_BLOCK_COUNT_8 (0)
```

```c
#define AO_ALLOC_POOL_BLOCK_COUNT_9 (0)
```

```c
#define AO_ALLOC_POOL_BLOCK_SIZE_0 (0)
```

```c
#define AO_ALLOC_POOL_BLOCK_SIZE_1 (0)
```

```c
#define AO_ALLOC_POOL_BLOCK_SIZE_10 (0)
```

```c
#define AO_ALLOC_POOL_BLOCK_SIZE_11 (0)
```

```c
#define AO_ALLOC_POOL_BLOCK_SIZE_12 (0)
```

```c
#define AO_ALLOC_POOL_BLOCK_SIZE_13 (0)
```

```c
#define AO_ALLOC_POOL_BLOCK_SIZE_14 (0)
```

```c
#define AO_ALLOC_POOL_BLOCK_SIZE_15 (0)
```

```c
#define AO_ALLOC_POOL_BLOCK_SIZE_16 (0)
```

```c
#define AO_ALLOC_POOL_BLOCK_SIZE_17 (0)
```

```c
#define AO_ALLOC_POOL_BLOCK_SIZE_18 (0)
```

```c
#define AO_ALLOC_POOL_BLOCK_SIZE_19 (0)
```

```c
#define AO_ALLOC_POOL_BLOCK_SIZE_2 (0)
```

```c
#define AO_ALLOC_POOL_BLOCK_SIZE_20 (0)
```

```c
#define AO_ALLOC_POOL_BLOCK_SIZE_21 (0)
```

```c
#define AO_ALLOC_POOL_BLOCK_SIZE_22 (0)
```

```c
#define AO_ALLOC_POOL_BLOCK_SIZE_23 (0)
```

```c
#define AO_ALLOC_POOL_BLOCK_SIZE_24 (0)
```

```c
#define AO_ALLOC_POOL_BLOCK_SIZE_25 (0)
```

```c
#define AO_ALLOC_POOL_BLOCK_SIZE_26 (0)
```

```c
#define AO_ALLOC_POOL_BLOCK_SIZE_27 (0)
```

```c
#define AO_ALLOC_POOL_BLOCK_SIZE_28 (0)
```

```c
#define AO_ALLOC_POOL_BLOCK_SIZE_29 (0)
```

```c
#define AO_ALLOC_POOL_BLOCK_SIZE_3 (0)
```

```c
#define AO_ALLOC_POOL_BLOCK_SIZE_30 (0)
```

```c
#define AO_ALLOC_POOL_BLOCK_SIZE_31 (0)
```

```c
#define AO_ALLOC_POOL_BLOCK_SIZE_32 (0)
```

```c
#define AO_ALLOC_POOL_BLOCK_SIZE_33 (0)
```

```c
#define AO_ALLOC_POOL_BLOCK_SIZE_34 (0)
```

```c
#define AO_ALLOC_POOL_BLOCK_SIZE_35 (0)
```

```c
#define AO_ALLOC_POOL_BLOCK_SIZE_36 (0)
```

```c
#define AO_ALLOC_POOL_BLOCK_SIZE_37 (0)
```

```c
#define AO_ALLOC_POOL_BLOCK_SIZE_38 (0)
```

```c
#define AO_ALLOC_POOL_BLOCK_SIZE_39 (0)
```

```c
#define AO_ALLOC_POOL_BLOCK_SIZE_4 (0)
```

```c
#define AO_ALLOC_POOL_BLOCK_SIZE_40 (0)
```

```c
#define AO_ALLOC_POOL_BLOCK_SIZE_41 (0)
```

```c
#define AO_ALLOC_POOL_BLOCK_SIZE_42 (0)
```

```c
#define AO_ALLOC_POOL_BLOCK_SIZE_43 (0)
```

```c
#define AO_ALLOC_POOL_BLOCK_SIZE_44 (0)
```

```c
#define AO_ALLOC_POOL_BLOCK_SIZE_45 (0)
```

```c
#define AO_ALLOC_POOL_BLOCK_SIZE_46 (0)
```

```c
#define AO_ALLOC_POOL_BLOCK_SIZE_47 (0)
```

```c
#define AO_ALLOC_POOL_BLOCK_SIZE_48 (0)
```

```c
#define AO_ALLOC_POOL_BLOCK_SIZE_49 (0)
```

```c
#define AO_ALLOC_POOL_BLOCK_SIZE_5 (0)
```

```c
#define AO_ALLOC_POOL_BLOCK_SIZE_50 (0)
```

```c
#define AO_ALLOC_POOL_BLOCK_SIZE_51 (0)
```

```c
#define AO_ALLOC_POOL_BLOCK_SIZE_52 (0)
```

```c
#define AO_ALLOC_POOL_BLOCK_SIZE_53 (0)
```

```c
#define AO_ALLOC_POOL_BLOCK_SIZE_54 (0)
```

```c
#define AO_ALLOC_POOL_BLOCK_SIZE_55 (0)
```

```c
#define AO_ALLOC_POOL_BLOCK_SIZE_56 (0)
```

```c
#define AO_ALLOC_POOL_BLOCK_SIZE_57 (0)
```

```c
#define AO_ALLOC_POOL_BLOCK_SIZE_58 (0)
```

```c
#define AO_ALLOC_POOL_BLOCK_SIZE_59 (0)
```

```c
#define AO_ALLOC_POOL_BLOCK_SIZE_6 (0)
```

```c
#define AO_ALLOC_POOL_BLOCK_SIZE_60 (0)
```

```c
#define AO_ALLOC_POOL_BLOCK_SIZE_61 (0)
```

```c
#define AO_ALLOC_POOL_BLOCK_SIZE_62 (0)
```

```c
#define AO_ALLOC_POOL_BLOCK_SIZE_63 (0)
```

```c
#define AO_ALLOC_POOL_BLOCK_SIZE_7 (0)
```

```c
#define AO_ALLOC_POOL_BLOCK_SIZE_8 (0)
```

```c
#define AO_ALLOC_POOL_BLOCK_SIZE_9 (0)
```

# Types

## `ao_alloc_pool_t`

```c
struct ao_alloc_pool_t
{
#if AO_ALLOC_ALLOCATED_MAX || AO_ALLOC_ALLOCATED
    size_t volatile allocated;
#endif
#if AO_ALLOC_ALLOCATED_MAX
    size_t volatile allocated_max;
#endif
    size_t block_size;
#if AO_ALLOC_FREE_MIN || AO_ALLOC_FREE
    size_t volatile free;
#endif
#if AO_ALLOC_FREE_MIN
    size_t volatile free_min;
#endif
    ao_alloc_pool_node_t * front;
};
```

It consists of the following members.

| `allocated` | |
| `allocated_max` | |
| `block_size` | |
| `free` | |
| `free_min` | |
| `front` | |

## `ao_acquired_t`

```c
struct ao_acquired_t
{
    size_t pool;
    void * ptr;
    bool result;
    size_t size_body;
    size_t size_body_requested;
    size_t size_head;
};
```

It consists of the following members.

| `pool` | |
| `ptr` | |
| `result` | |
| `size_body` | |
| `size_body_requested` | |
| `size_head` | |

## `ao_released_t`

```c
struct ao_released_t
{
    size_t pool;
    void * ptr;
    size_t ref;
    bool result;
    size_t size_body;
    size_t size_head;
};
```

It consists of the following members.

| `pool` | |
| `ptr` | |
| `ref` | |
| `result` | |
| `size_body` | |
| `size_head` | |

## `ao_retained_t`

```c
struct ao_retained_t
{
    size_t pool;
    void * ptr;
    size_t ref;
    bool result;
    size_t size_body;
    size_t size_head;
};
```

It consists of the following members.

| `pool` | |
| `ptr` | |
| `ref` | |
| `result` | |
| `size_body` | |
| `size_head` | |

# Variables

```c
extern ao_alloc_pool_t ao_alloc_pool_0;
```

```c
extern ao_alloc_pool_t ao_alloc_pool_1;
```

```c
extern ao_alloc_pool_t ao_alloc_pool_2;
```

```c
extern ao_alloc_pool_t ao_alloc_pool_3;
```

```c
extern ao_alloc_pool_t ao_alloc_pool_4;
```

```c
extern ao_alloc_pool_t ao_alloc_pool_5;
```

```c
extern ao_alloc_pool_t ao_alloc_pool_6;
```

```c
extern ao_alloc_pool_t ao_alloc_pool_7;
```

```c
extern ao_alloc_pool_t ao_alloc_pool_8;
```

```c
extern ao_alloc_pool_t ao_alloc_pool_9;
```

```c
extern ao_alloc_pool_t ao_alloc_pool_10;
```

```c
extern ao_alloc_pool_t ao_alloc_pool_11;
```

```c
extern ao_alloc_pool_t ao_alloc_pool_12;
```

```c
extern ao_alloc_pool_t ao_alloc_pool_13;
```

```c
extern ao_alloc_pool_t ao_alloc_pool_14;
```

```c
extern ao_alloc_pool_t ao_alloc_pool_15;
```

```c
extern ao_alloc_pool_t ao_alloc_pool_16;
```

```c
extern ao_alloc_pool_t ao_alloc_pool_17;
```

```c
extern ao_alloc_pool_t ao_alloc_pool_18;
```

```c
extern ao_alloc_pool_t ao_alloc_pool_19;
```

```c
extern ao_alloc_pool_t ao_alloc_pool_20;
```

```c
extern ao_alloc_pool_t ao_alloc_pool_21;
```

```c
extern ao_alloc_pool_t ao_alloc_pool_22;
```

```c
extern ao_alloc_pool_t ao_alloc_pool_23;
```

```c
extern ao_alloc_pool_t ao_alloc_pool_24;
```

```c
extern ao_alloc_pool_t ao_alloc_pool_25;
```

```c
extern ao_alloc_pool_t ao_alloc_pool_26;
```

```c
extern ao_alloc_pool_t ao_alloc_pool_27;
```

```c
extern ao_alloc_pool_t ao_alloc_pool_28;
```

```c
extern ao_alloc_pool_t ao_alloc_pool_29;
```

```c
extern ao_alloc_pool_t ao_alloc_pool_30;
```

```c
extern ao_alloc_pool_t ao_alloc_pool_31;
```

```c
extern ao_alloc_pool_t ao_alloc_pool_32;
```

```c
extern ao_alloc_pool_t ao_alloc_pool_33;
```

```c
extern ao_alloc_pool_t ao_alloc_pool_34;
```

```c
extern ao_alloc_pool_t ao_alloc_pool_35;
```

```c
extern ao_alloc_pool_t ao_alloc_pool_36;
```

```c
extern ao_alloc_pool_t ao_alloc_pool_37;
```

```c
extern ao_alloc_pool_t ao_alloc_pool_38;
```

```c
extern ao_alloc_pool_t ao_alloc_pool_39;
```

```c
extern ao_alloc_pool_t ao_alloc_pool_40;
```

```c
extern ao_alloc_pool_t ao_alloc_pool_41;
```

```c
extern ao_alloc_pool_t ao_alloc_pool_42;
```

```c
extern ao_alloc_pool_t ao_alloc_pool_43;
```

```c
extern ao_alloc_pool_t ao_alloc_pool_44;
```

```c
extern ao_alloc_pool_t ao_alloc_pool_45;
```

```c
extern ao_alloc_pool_t ao_alloc_pool_46;
```

```c
extern ao_alloc_pool_t ao_alloc_pool_47;
```

```c
extern ao_alloc_pool_t ao_alloc_pool_48;
```

```c
extern ao_alloc_pool_t ao_alloc_pool_49;
```

```c
extern ao_alloc_pool_t ao_alloc_pool_50;
```

```c
extern ao_alloc_pool_t ao_alloc_pool_51;
```

```c
extern ao_alloc_pool_t ao_alloc_pool_52;
```

```c
extern ao_alloc_pool_t ao_alloc_pool_53;
```

```c
extern ao_alloc_pool_t ao_alloc_pool_54;
```

```c
extern ao_alloc_pool_t ao_alloc_pool_55;
```

```c
extern ao_alloc_pool_t ao_alloc_pool_56;
```

```c
extern ao_alloc_pool_t ao_alloc_pool_57;
```

```c
extern ao_alloc_pool_t ao_alloc_pool_58;
```

```c
extern ao_alloc_pool_t ao_alloc_pool_59;
```

```c
extern ao_alloc_pool_t ao_alloc_pool_60;
```

```c
extern ao_alloc_pool_t ao_alloc_pool_61;
```

```c
extern ao_alloc_pool_t ao_alloc_pool_62;
```

```c
extern ao_alloc_pool_t ao_alloc_pool_63;
```

```c
extern size_t volatile ao_alloc_allocated;
```

```c
extern size_t volatile ao_alloc_allocated_max;
```

```c
extern size_t volatile ao_alloc_free;
```

```c
extern size_t volatile ao_alloc_free_min;
```

