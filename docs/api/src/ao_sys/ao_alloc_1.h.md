---
author: "Stefan Wagner"
date: 2022-08-31
draft: true
permalink: /api/src/ao_sys/ao_alloc_1.h/
toc: true
---

# Notes

This module implements an allocator that manages a number of pools. Thereby, each pool contains a number of blocks of equal size.

Both the number of blocks and the block size must be configured for each pool. For example, the following configures pool 0 to contain 16 blocks at 256 bytes.

```c
#define AO_ALLOC_POOL_BLOCK_COUNT_0 ( 16)
#define AO_ALLOC_POOL_BLOCK_SIZE_0  (256)
```

That way, up to 64 pools can be configured. However, there is a limit to the number of pools that can actually be used. It is determined by the number of bits of the standard library's `size_t` type. So, if that type is 32 bits wide, then at most 32 pools are available.

This is due to the fact, that the module maintains a bitmask of type `size_t`, where each set bit indicates whether the respective pool contains at least one free block. Consequently, a clear bit indicates an empty pool.

Upon allocation, the module walks the bitmask starting at the least significant bit, that is, bit 0. For each bit, it checks, whether the respective pool is not empty and the block size is sufficient to fulfil the request. It stops as soon as it has found a suitable block. Consequently, pools should be configured with increasing block sizes, in order to minimize internal fragmentation.

Due to its iterative approach, allocation is a linear-time operation. In contrast, deallocation takes constant time. This is, because each block contains a header, that stores the pool, to which it belongs.

# Include

```c
#include <stdbool.h>
#include <stddef.h>
```

# Identifier

```c
#define AO_ALLOC_1
```

# Configuration

## `AO_ALLOC_ALLOCATED`
## `AO_ALLOC_ALLOCATED_MAX`

```c
#define AO_ALLOC_ALLOCATED     (false)
#define AO_ALLOC_ALLOCATED_MAX (false)
```

Defines whether to keep track of the current and maximum number of allocated bytes, respectively. If this configuration option is enabled, then the respective data is gathered both globally and for each pool.

## `AO_ALLOC_FREE`
## `AO_ALLOC_FREE_MIN`

```c
#define AO_ALLOC_FREE     (false)
#define AO_ALLOC_FREE_MIN (false)
```

Defines whether to keep track of the current and minimum number of free bytes, respectively. If this configuration option is enabled, then the respective data is gathered both globally and for each pool.

## `AO_ALLOC_POOL_BLOCK_COUNT`

```c
#define AO_ALLOC_POOL_BLOCK_COUNT_0  (0)
#define AO_ALLOC_POOL_BLOCK_COUNT_1  (0)

// ...

#define AO_ALLOC_POOL_BLOCK_COUNT_63 (0)
```

The number of blocks in each pool.

## `AO_ALLOC_POOL_BLOCK_SIZE`

```c
#define AO_ALLOC_POOL_BLOCK_SIZE_0  (0)
#define AO_ALLOC_POOL_BLOCK_SIZE_1  (0)

// ...

#define AO_ALLOC_POOL_BLOCK_SIZE_63 (0)
```

The size of the blocks in each pool, in bytes.

# Types

## `ao_alloc_pool_t`

```c
typedef struct ao_alloc_pool_t ao_alloc_pool_t;
```

This type represents a pool.

## `ao_alloc_pool_node_t`

```c
typedef struct ao_alloc_pool_node_t ao_alloc_pool_node_t;
```

This type represents a block.

## `ao_acquired_t`

```c
typedef struct ao_acquired_t ao_acquired_t;
```

This type represents the information about a call to `ao_acquire()`.

## `ao_released_t`

```c
typedef struct ao_released_t ao_released_t;
```

This type represents the information about a call to `ao_release()`.

## `ao_retained_t`

```c
typedef struct ao_retained_t ao_retained_t;
```

This type represents the information about a call to `ao_retain()`.

# Structs

## `ao_alloc_pool_t`

```c
struct ao_alloc_pool_t
{

#if AO_ALLOC_ALLOCATED_MAX || \
    AO_ALLOC_ALLOCATED

    size_t volatile        allocated;

#endif

#if AO_ALLOC_ALLOCATED_MAX

    size_t volatile        allocated_max;

#endif

    size_t                 block_size;

#if AO_ALLOC_FREE_MIN || \
    AO_ALLOC_FREE

    size_t volatile        free;

#endif

#if AO_ALLOC_FREE_MIN

    size_t volatile        free_min;

#endif

    ao_alloc_pool_node_t * front;
};
```

| `allocated` | The current number of allocated bytes. |
| `allocated_max` | The maximum number of allocated bytes. |
| `block_size` | The block size, in bytes. |
| `free` | The current number of free bytes. |
| `free_min` | The minimum number of free bytes. |
| `front` | The pool keeps its free blocks in a singly linked list. This member points to the front of that list. |

## `ao_alloc_pool_node_t`

This struct is not publicly exposed.

## `ao_acquired_t`

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

| `pool` | The pool to which the memory block belongs. |
| `ptr` | The pointer returned by the function. |
| `result` | Indicates whether the operation has succeeded (`true`) or failed (`false`). |
| `size_body` | The actual size of the body of the memory block. |
| `size_body_requested` | The requested size of the body of the memory block, that is, the parameter value that the function was called with. |
| `size_head` | The size of the head of the memory block. |

## `ao_released_t`

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

| `pool` | The pool to which the memory block belongs. |
| `ptr` | The pointer to the memory block, that is, the parameter value that the function was called with. |
| `ref` | The current reference count of the memory block. If the operation has succeeded, then the value `0` indicates, that the memory block has just been deallocated. |
| `result` | Indicates whether the operation has succeeded (`true`) or failed (`false`). |
| `size_body` | The size of the body of the memory block. |
| `size_head` | The size of the head of the memory block. |

## `ao_retained_t`

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

| `pool` | The pool to which the memory block belongs. |
| `ptr` | The pointer to the memory block, that is, the parameter value that the function was called with. |
| `ref` | The current reference count of the memory block. If the operation has succeeded, then this value should be greater than 1. |
| `result` | Indicates whether the operation has succeeded (`true`) or failed (`false`). |
| `size_body` | The size of the body of the memory block. |
| `size_head` | The size of the head of the memory block. |

# Variables

## `ao_alloc_allocated`
## `ao_alloc_allocated_max`

```c
extern size_t volatile ao_alloc_allocated;
extern size_t volatile ao_alloc_allocated_max;
```

The current and maximum number of allocated bytes, respectively.

## `ao_alloc_free`
## `ao_alloc_free_min`

```c
extern size_t volatile ao_alloc_free;
extern size_t volatile ao_alloc_free_min;
```

The current and minimum number of free bytes, respectively.

## `ao_alloc_pool`

```c
extern ao_alloc_pool_t ao_alloc_pool_0;
extern ao_alloc_pool_t ao_alloc_pool_1;

// ...

extern ao_alloc_pool_t ao_alloc_pool_63;
```

The pools.
