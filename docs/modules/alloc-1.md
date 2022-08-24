---
author: "Stefan Wagner"
date: 2022-08-15
description: "The ao_alloc_1.h module of the ao real-time operating system."
draft: false
permalink: /modules/alloc-1/
title: "ao_alloc_1.h"
toc: true
---

# Overview

This module implements an [allocator](../allocator.md) that manages a number of pools. Thereby, each pool contains a number of blocks of equal size.

Both the number of blocks and the block size must be configured for each pool. For example, the following configures pool 0 to contain 16 blocks at 256 bytes.

```c
#define AO_ALLOC_POOL_BLOCK_COUNT_0 ( 16)
```

```c
#define AO_ALLOC_POOL_BLOCK_SIZE_0  (256)
```

That way, up to 64 pools can be configured. However, there is a limit to the number of pools that can actually be used. It is determined by the number of bits of the standard library's `size_t` type. So, if that type is 32 bits wide, then at most 32 pools are available.

This is due to the fact, that the module maintains a bitmask of type `size_t`, where each set bit indicates whether the respective pool contains at least one free block. Consequently, a clear bit indicates an empty pool.

Upon allocation, the module walks the bitmask starting at the least significant bit, that is, bit 0. For each bit, it checks, whether the respective pool is not empty and the block size is sufficient to fulfil the request. It stops as soon as it has found a suitable block. Consequently, pools should be configured with increasing block sizes, in order to minimize internal fragmentation.

Due to its iterative approach, allocation is a linear-time operation. In contrast, deallocation takes constant time. This is, because each block contains a header, that stores the pool, to which it belongs.

# Configuration

The allocator can be configured to keep track of the current and maximum numbers of allocated bytes. If enabled, the respective data is gathered both globally and for each pool. By default, these options are disabled.

```c
#define AO_ALLOC_ALLOCATED
```

```c
#define AO_ALLOC_ALLOCATED_MAX
```

Accordingly, the allocator can be configured to keep track of the current and minimum numbers of free bytes. If enabled, the respective data is gathered both globally and for each pool. By default, these options are disabled.

```c
#define AO_ALLOC_FREE
```

```c
#define AO_ALLOC_FREE_MIN
```

For each pool, the number of blocks and the block size must be configured. The respective pool is absent, if either value is zero, which is the default for all pools.

```c
#define AO_ALLOC_POOL_BLOCK_COUNT_0
```

```c
#define AO_ALLOC_POOL_BLOCK_SIZE_0
```

...

```c
#define AO_ALLOC_POOL_BLOCK_COUNT_63
```

```c
#define AO_ALLOC_POOL_BLOCK_SIZE_63
```

# Types

## `ao_alloc_pool_t`

This type represents a pool.

```c
struct ao_alloc_pool_t
{
    size_t volatile        allocated;
    size_t volatile        allocated_max;
    size_t                 block_size;
    size_t volatile        free;
    size_t volatile        free_min;
    ao_alloc_pool_node_t * front;
};
```

It consists of the following members.

| Member | |
|--------|-|
| `allocated` | The current number of allocated bytes. This member is absent, if both the `AO_ALLOC_ALLOCATED` and `AO_ALLOC_ALLOCATED_MAX` configuration options are disabled. |
| `allocated_max` | The maximum number of allocated bytes. This member is absent, if the `AO_ALLOC_ALLOCATED_MAX` configuration option is disabled. |
| `block_size` | The block size, in bytes. |
| `free` | The current number of free bytes. This member is absent, if both the `AO_ALLOC_FREE` and `AO_ALLOC_FREE_MIN` configuration options are disabled. |
| `free_min` | The minimum number of free bytes. This member is absent, if the `AO_ALLOC_FREE_MIN` configuration option is disabled. |
| `front` | The pool keeps its free blocks in a singly linked list. This member points to the front of that list. |

## `ao_alloc_pool_node_t`

This type represents a block. This type is not publicly exposed.

# Type Overrides

## `ao_acquired_t`

This type represents information about a call to `ao_acquire()`.

```c
struct ao_acquired_t
{
    size_t pool;
    void * ptr;
    bool   result;
    size_t size_body;
    size_t size_body_requested;
    size_t size_head;
};
```

It consists of the following members.

| Member | |
|--------|-|
| `pool` | The pool to which the memory block belongs. |
| `ptr` | The pointer returned by the function. |
| `result` | Indicates whether the operation has succeeded (`true`) or failed (`false`). |
| `size_body` | The actual size of the body of the memory block. |
| `size_body_requested` | The requested size of the body of the memory block, that is, the parameter value that the function was called with. |
| `size_head` | The size of the head of the memory block. |

## `ao_released_t`

This type represents information about a call to `ao_release()`.

```c
struct ao_released_t
{
    size_t pool;
    void * ptr;
    size_t ref;
    bool   result;
    size_t size_body;
    size_t size_head;
};
```

It consists of the following members.

| Member | |
|--------|-|
| `pool` | The pool to which the memory block belongs. |
| `ptr` | The pointer to the memory block, that is, the parameter value that the function was called with. |
| `ref` | The current reference count of the memory block. If the operation has succeeded, then the value `0` indicates, that the memory block has just been deallocated. |
| `result` | Indicates whether the operation has succeeded (`true`) or failed (`false`). |
| `size_body` | The size of the body of the memory block. |
| `size_head` | The size of the head of the memory block. |

### `ao_retained_t`

This type represents information about a call to `ao_retain()`.

```c
struct ao_retained_t
{
    size_t pool;
    void * ptr;
    size_t ref;
    bool   result;
    size_t size_body;
    size_t size_head;
};
```

It consists of the following members.

| Member | |
|--------|-|
| `pool` | The pool to which the memory block belongs. |
| `ptr` | The pointer to the memory block, that is, the parameter value that the function was called with. |
| `ref` | The current reference count of the memory block. If the operation has succeeded, then this value should be greater than `1`. |
| `result` | Indicates whether the operation has succeeded (`true`) or failed (`false`). |
| `size_body` | The size of the body of the memory block. |
| `size_head` | The size of the head of the memory block. |

# Variables

The current number of allocated bytes across all pools. 

This variable is absent, if both the `AO_ALLOC_ALLOCATED` and `AO_ALLOC_ALLOCATED_MAX` configuration options are disabled.

```c
extern size_t volatile ao_alloc_allocated;
```

The maximum number of allocated bytes across all pools. 

This variable is absent, if the `AO_ALLOC_ALLOCATED_MAX` configuration option is disabled.

```c
extern size_t volatile ao_alloc_allocated_max;
```

The current number of free bytes across all pools. 

This variable is absent, if both the `AO_ALLOC_FREE` and `AO_ALLOC_FREE_MIN` configuration options are disabled.

```c
extern size_t volatile ao_alloc_free;
```

The minimum number of free bytes across all pools. 

This variable is absent, if the `AO_ALLOC_FREE_MIN` configuration option is disabled.

```c
extern size_t volatile ao_alloc_free_min;
```

Pool 0. 

This variable is absent, if `AO_ALLOC_POOL_BLOCK_COUNT_0` is zero or if `AO_ALLOC_POOL_BLOCK_SIZE_0` is zero.

```c
extern ao_alloc_pool_t ao_alloc_pool_0;
```

Pool 1. 

This variable is absent, if `AO_ALLOC_POOL_BLOCK_COUNT_1` is zero or if `AO_ALLOC_POOL_BLOCK_SIZE_1` is zero.

```c
extern ao_alloc_pool_t ao_alloc_pool_1;
```

...

Pool 15. 

This variable is absent, if `AO_ALLOC_POOL_BLOCK_COUNT_15` is zero or if `AO_ALLOC_POOL_BLOCK_SIZE_15` is zero.

```c
extern ao_alloc_pool_t ao_alloc_pool_15;
```

Pool 16. 

This variable is absent, if `AO_ALLOC_POOL_BLOCK_COUNT_16` is zero or if `AO_ALLOC_POOL_BLOCK_SIZE_16` is zero or if the `size_t` type has less than 17 bits.

```c
extern ao_alloc_pool_t ao_alloc_pool_16;
```

...

Pool 63. 

This variable is absent, if `AO_ALLOC_POOL_BLOCK_COUNT_63` is zero or if `AO_ALLOC_POOL_BLOCK_SIZE_63` is zero or if the `size_t` type has less than 64 bits.

```c
extern ao_alloc_pool_t ao_alloc_pool_63;
```
