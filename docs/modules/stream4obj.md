---
author: "Stefan Wagner"
date: 2022-08-17
description: "The ao_stream4obj.h module of the ao real-time operating system."
draft: true
permalink: /modules/stream4obj/
title: "<code>ao_stream4obj.h</code>"
toc: true
---

# Overview

...

## Types

### Stream

The `ao_stream4obj_t` type represents a stream for objects.

```c
struct ao_stream4obj_t
{
    ao_buffer4obj_t buffer;
    ao_list_t       pop;
    ao_list_t       push;
};
```

It consists of the following members.

| Member | |
|--------|-|
| `buffer` | The buffer. |
| `pop` | The list of tasks attempting to pop an object from the stream. |
| `push` | The list of tasks attempting to push an object to the stream. |

### Stream Pushing

The `ao_spush_obj_t` type represents the pushing of an object to a stream.

```c
struct ao_spush_obj_t
{
    ao_async_t        async;
    ao_list_node_t    node;
    void *            ptr;
    void *            ptr_override;
    bool volatile     result;
    bool volatile     result_override;
    ao_stream4obj_t * stream;
};
```

It consists of the following members.

| Member | |
|--------|-|
| `async` | The asynchronous event. |
| `node` | The node for the stream's waiting list. |
| `ptr` | Points to the object to push to the stream. |
| `ptr_override` | Points to a location to store the overridden object. |
| `result` | Indicates whether the object has been pushed to the stream. |
| `result_override` | Indicates whether an object has been overridden. |
| `stream` | The stream. |

### Stream Popping

The `ao_spop_obj_t` type represents the popping of an object from a stream.

```c
struct ao_spop_obj_t
{
    ao_async_t        async;
    ao_list_node_t    node;
    void *            ptr;
    bool volatile     result;
    ao_stream4obj_t * stream;
};
```

It consists of the following members.

| Member | |
|--------|-|
| `async` | The asynchronous event. |
| `node` | The node for the stream's waiting list. |
| `ptr` | Points to a location to store the popped object. |
| `result` | Indicates whether an object has been popped from the stream. |
| `stream` | The stream. |

## Initialization

...

## Functions

### Pushing

...

### Popping

...
