---
author: "Stefan Wagner"
date: 2022-08-17
description: "The ao_stream4ptr.h module of the ao real-time operating system."
draft: true
permalink: /modules/stream4ptr/
title: "ao_stream4ptr.h"
---

# ao_stream4ptr.h

...

## Types

### Stream

The `ao_stream4ptr_t` type represents a stream for pointers.

```c
struct ao_stream4ptr_t
{
    ao_buffer4ptr_t buffer;
    ao_list_t       pop;
    ao_list_t       push;
};
```

It consists of the following members.

| Member | |
|--------|-|
| `buffer` | The buffer. |
| `pop` | The list of tasks attempting to pop a pointer from the stream. |
| `push` | The list of tasks attempting to push a pointer to the stream. |

### Stream Pushing

The `ao_spush_ptr_t` type represents the pushing of a pointer to a stream.

```c
struct ao_spush_ptr_t
{
    ao_async_t        async;
    ao_list_node_t    node;
    void *            ptr;
    void * volatile   ptr_override;
    bool   volatile   result;
    bool   volatile   result_override;
    ao_stream4ptr_t * stream;
};
```

It consists of the following members.

| Member | |
|--------|-|
| `async` | The asynchronous event. |
| `node` | The node for the stream's waiting list. |
| `ptr` | The pointer to push. |
| `ptr_override` | The pointer that has been overridden. |
| `result` | Indicates whether the pointer has been pushed to the stream. |
| `result_override` | Indicates whether a pointer has been overridden. |
| `stream` | The stream. |

### Stream Popping

The `ao_spop_ptr_t` type represents the popping of a pointer from a stream.

```c
struct ao_spop_ptr_t
{
    ao_async_t        async;
    ao_list_node_t    node;
    void * volatile   ptr;
    bool   volatile   result;
    ao_stream4ptr_t * stream;
};
```

It consists of the following members.

| Member | |
|--------|-|
| `async` | The asynchronous event. |
| `node` | The node for the stream's waiting list. |
| `ptr` | The pointer that has been popped from the stream. |
| `result` | Indicates whether a pointer has been popped from the stream. |
| `stream` | The stream. |

## Initialization

...

## Functions

### Pushing

...

### Pushing an Acquired Pointer

...

### Popping

...
