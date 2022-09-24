---
author: "Stefan Wagner"
date: 2022-08-31
draft: true
permalink: /api/src/ao_sys/ao_alloc.h/
toc: true
---

# Notes

...

This module encapsulates an allocator that supports dynamic memory management.

- standard library contains similar functions, but not in a freestanding runtime environment.
- dynamic memory management
- reference counting
- allocate, release, retain
- actual implementation in a submodule, that must be chosen via configuration
- allocator functions can be called from both task and interrupt context.
- consequently, the allocator does not track, which block is allocated to which task. the application must take care thereof, in order to avoid memory leaks.

- the allocator is a dynamic memory management option, that both the kernel and the application can. However, neither is committed to using the allocator.

- wiki: "provide ways to dynamically allocate portions of memory to programs at their request, and free it for reuse when no longer needed"

...

# Include

`stdbool.h` <br/>
`stddef.h`

# Identifier

```c
#define AO_ALLOC
```

# Configuration

## `AO_ALLOC`

```c
#define AO_ALLOC (2)
```

Selects the allocator implementation. The following options are available.

| [`ao_alloc_0`](ao_alloc_0.h.md) | Stub |
| [`ao_alloc_1`](ao_alloc_1.h.md) | Linear-time allocator based on pools of fixed-size memory blocks |
| [`ao_alloc_2`](ao_alloc_2.h.md) | Constant-time allocator based on the two-level segregated fit algorithm |

## `AO_ACQUIRED`
## `AO_RELEASED`
## `AO_RETAINED`

```c
#define AO_ACQUIRED (false)
#define AO_RELEASED (false)
#define AO_RETAINED (false)
```

Defines whether to execute a callback upon each call to `ao_acquire()`, `ao_release()`, or `ao_retain()`, respectively, which can aid in debugging an application or tracing and optimizing the memory usage of the allocator.

# Types

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

## `ao_acquired_t`

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

| `ptr` | The pointer returned by the function. |
| `result` | Indicates whether the operation has succeeded (`true`) or failed (`false`). |
| `size_body` | The actual size of the body of the memory block. |
| `size_body_requested` | The requested size of the body of the memory block, that is, the parameter value that the function was called with. |
| `size_head` | The size of the head of the memory block. |

## `ao_released_t`

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

| `ptr` | The pointer to the memory block, that is, the parameter value that the function was called with. |
| `ref` | The current reference count of the memory block. If the operation has succeeded, then the value `0` indicates, that the memory block has just been deallocated. |
| `result` | Indicates whether the operation has succeeded (`true`) or failed (`false`). |
| `size_body` | The size of the body of the memory block. |
| `size_head` | The size of the head of the memory block. |

## `ao_retained_t`

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

| `ptr` | The pointer to the memory block, that is, the parameter value that the function was called with. |
| `ref` | The current reference count of the memory block. If the operation has succeeded, then this value should be greater than 1. |
| `result` | Indicates whether the operation has succeeded (`true`) or failed (`false`). |
| `size_body` | The size of the body of the memory block. |
| `size_head` | The size of the head of the memory block. |

# Functions

## `ao_acquire`

```c
void * ao_acquire(size_t size);
```

Allocates a memory block of the specified size.

If the operation succeeds, then the function returns a pointer to the beginning of the allocated memory block. Thereby, that pointer is suitably aligned for any object type with fundamental alignment. But, the content of the memory block is not initialized, remaining with indeterminate values.

Additionally, the reference count of the memory block is initialized with 1. Therefore, the calling thread of execution takes ownership of the memory block.

If the operation fails, then the function returns `NULL`. This is either because the specified size is 0 or the allocator cannot find a memory block large enough.

## `ao_acquired`

```c
void ao_acquired(ao_acquired_t const * info);
```

The callback for each call to `ao_acquire()`. This function must be implemented by the application.

## `ao_delete`

```c
#define ao_delete(ptr) \
(                      \
    ao_release(ptr)    \
)
```

Deallocates a memory block.

## `ao_new`

```c
#define ao_new(type)         \
(                            \
    ao_acquire(sizeof(type)) \
)
```

Allocates a memory block large enough for the specified type. If the operation succeeds, then this function returns a pointer of type `type *`.

## `ao_release`

```c
bool ao_release(void * ptr);
```

Reliquinshes ownership of a memory block, which decrements its reference count. If the reference count reaches zero, then this function additionally deallocates the memory block, making it available for further allocations.

The behavior of this function is undefined, if the memory block has been deallocated previously. Therefore, ownership of a memory block should be relinquished only, if it has been taken previously by the same thread of execution by calling `ao_acquire()` or `ao_retain()`, respectively.

The return value indicates whether the operation has succeeded or failed. The latter happens, if the specified pointer is `NULL`. Nevertheless, the functions' behavior is well-defined in this case, that is, it simply does nothing but return.

## `ao_released`

```c
void ao_released(ao_released_t const * info);
```

The callback for each call to `ao_release()`. This function must be implemented by the application.

## `ao_retain`

```c
bool ao_retain(void * ptr);
```

Increments the reference count of a memory block, which means, that the calling thread of execution (once again) takes ownership thereof.

The return value indicates whether the operation has succeeded or failed. The latter happens, if the specified pointer is `NULL`. Nevertheless, the functions' behavior is well-defined in this case, that is, it simply does nothing but return.

## `ao_retained`

```c
void ao_retained(ao_retained_t const * info);
```

The callback for each call to `ao_retain()`. This function must be implemented by the application.
