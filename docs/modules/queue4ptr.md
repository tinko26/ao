---
author: "Stefan Wagner"
date: 2022-08-12
description: "The ao_queue4ptr.h module of the ao real-time operating system."
draft: true
permalink: /modules/queue4ptr/
title: "<code>ao_queue4ptr.h</code>"
---

# Overview

...

## Types

### Queue

The `ao_queue4ptr_t` type represents a queue for pointers.

```c
struct ao_queue4ptr_t
{
    ao_heap4ptr_t heap;
    ao_list_t     insert;
    ao_list_t     pop;
};
```

It consists of the following members.

| Member | |
|--------|-|
| `heap` | The heap storing the pointers. |
| `insert` | The list of tasks attempting to insert a pointer into the queue. |
| `pop` | The list of tasks attempting to pop a pointer from the queue. |

### Queue Inserting

The `ao_qinsert_ptr_t` type represents the inserting into a queue for pointers.

```c
struct  ao_qinsert_ptr_t
{
    ao_async_t       async;
    ao_list_node_t   node;
    void *           ptr;
    ao_queue4ptr_t * queue;
    bool volatile    result;
};
```

It consists of the following members.

| Member | |
|--------|-|
| `async` | The asynchronous event. |
| `node` | The node for the queue's list of inserting tasks. |
| `ptr` | The pointer to insert. |
| `queue` | The queue. |
| `result` | Indicates whether the pointer has been inserted into the queue. |

### Queue Popping

The `ao_qpop_ptr_t` type represents the popping from a queue for pointers.

```c
struct  ao_qpop_ptr_t
{
    ao_async_t       async;
    ao_list_node_t   node;
    void *           ptr;
    ao_queue4ptr_t * queue;
    bool volatile    result;
};
```

It consists of the following members.

| Member | |
|--------|-|
| `async` | The asynchronous event. |
| `node` | The node for the queue's list of popping tasks. |
| `ptr` | The pointer popped from the queue. |
| `queue` | The queue. |
| `result` | Indicates whether a pointer has been popped from the queue. |

## Initialization

...

## Functions

### Inserting

...

### Inserting an Acquired Pointer

...

### Popping

...
