---
author: "Stefan Wagner"
date: 2022-08-15
description: "The ao_alloc.h module of the ao real-time operating system."
draft: true
permalink: /modules/alloc/
title: "ao_alloc.h"
---

# ao_alloc.h

This module encapsulates an allocator that supports dynamic memory management.

- dynamic memory management
- reference counting
- allocate, release, retain
- actual implementation in a submodule, that must be chosen via configuration
- allocator functions can be called from both task and interrupt context.
- consequently, the allocator does not track, which block is allocated to which task. the application must take care thereof, in order to avoid memory leaks.

- the allocator is a dynamic memory management option, that both the kernel and the application can. However, neither is committed to using the allocator.

- wiki: "provide ways to dynamically allocate portions of memory to programs at their request, and free it for reuse when no longer needed"

## Configuration

The implementation of the allocator is selected by a macro constant. Its default value is `2`, which selects a constant-time implementation based on the two-level segregated fit algorithm proposed by Masmano et al.

```c
#define AO_ALLOC
```

The following implementations are available.

| Value | Module                     | |
|-------|----------------------------|-|
| `0`   | [`ao_alloc_0`](alloc-0.md) | Stub |
| `1`   | [`ao_alloc_1`](alloc-1.md) | Linear-time allocator based on pools of fixed-size memory blocks. |
| `2`   | [`ao_alloc_2`](alloc-2.md) | Constant-time allocator based on the two-level segregated fit algorithm proposed by Masmano et al. |

Additionally, the allocator can execute a callback upon each call to `ao_acquire()`, `ao_release()`, or `ao_retain()`, respectively, which can aid in debugging an application or tracing and optimizing the memory usage of the allocator. By default, these options are disabled.

```c
#define AO_ACQUIRED
#define AO_RELEASED
#define AO_RETAINED
```

## Types

### Acquired

The `ao_acquired_t` type represents information about a call to `ao_acquire()`.

```c
struct ao_acquired_t
{
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
| `ptr` | The pointer returned by the function. |
| `result` | Indicates whether the operation has succeeded (`true`) or failed (`false`). |
| `size_body` | The actual size of the body of the memory block. |
| `size_body_requested` | The requested size of the body of the memory block, that is, the parameter value that the function was called with. |
| `size_head` | The size of the head of the memory block. |

### Released

The `ao_released_t` type represents information about a call to `ao_release()`.

```c
struct ao_released_t
{
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
| `ptr` | The pointer to the memory block, that is, the parameter value that the function was called with. |
| `ref` | The current reference count of the memory block. If the operation has succeeded, then the value `0` indicates, that the memory block has just been deallocated. |
| `result` | Indicates whether the operation has succeeded (`true`) or failed (`false`). |
| `size_body` | The size of the body of the memory block. |
| `size_head` | The size of the head of the memory block. |

### Retained

The `ao_retained_t` type represents information about a call to `ao_retain()`.

```c
struct ao_retained_t
{
    void * ptr;
    size_t ref;
    bool   result;
    size_t size_body;
    size_t size_head;
};
```

It consists of the following members.

| Member | |
|--------| |
| `ptr` | The pointer to the memory block, that is, the parameter value that the function was called with. |
| `ref` | The current reference count of the memory block. If the operation has succeeded, then this value should be greater than `1`. |
| `result` | Indicates whether the operation has succeeded (`true`) or failed (`false`). |
| `size_body` | The size of the body of the memory block. |
| `size_head` | The size of the head of the memory block. |

## Functions

- ao_acquire()
- ao_release()
- ao_retain()

- ao_acquired()
- ao_released()
- ao_retained()

- ao_new()
- ao_delete()

