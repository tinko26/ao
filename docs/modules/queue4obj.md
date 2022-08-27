---
author: "Stefan Wagner"
date: 2022-08-16
description: "The ao_queue4obj.h module of the ao real-time operating system."
draft: true
permalink: /modules/queue4obj/
title: "<code>ao_queue4obj.h</code>"
---

# Overview

...

## Types

### Queue

The `ao_queue4obj_t` type represents a queue for objects.

```c
struct ao_queue4obj_t
{
    ao_heap4obj_t heap;
    ao_list_t     insert;
    ao_list_t     pop;
};
```

It consists of the following members.

| Member | |
|--------|-|
| `heap` | The heap storing the data. |
| `insert` | The list of tasks attempting to insert data into the queue. |
| `pop` | The list of tasks attempting to pop data from the queue. |

### Queue Inserting

The `ao_qinsert_obj_t` type represents the inserting into a queue for objects.

```c
struct  ao_qinsert_obj_t
{
    ao_async_t       async;
    ao_list_node_t   node;
    void *           ptr;
    ao_queue4obj_t * queue;
    bool volatile    result;
};
```

It consists of the following members.

| Member | |
|--------|-|
| `async` | The asynchronous event. |
| `node` | The node for the queue's list of inserting tasks. |
| `ptr` | Points to the data to insert. |
| `queue` | The queue. |
| `result` | Indicates whether data has been inserted into the queue. |

### Queue Popping

The `ao_qpop_obj_t` type represents the popping from a queue for objects.

```c
struct  ao_qpop_obj_t
{
    ao_async_t       async;
    ao_list_node_t   node;
    void *           ptr;
    ao_queue4obj_t * queue;
    bool volatile    result;
};
```

It consists of the following members.

| Member | |
|--------|-|
| `async` | The asynchronous event. |
| `node` | The node for the queue's list of popping tasks. |
| `ptr` | Points to a location to store the data to pop. |
| `queue` | The queue. |
| `result` | Indicates whether data has been popped from the queue. |

## Initialization

...

## Functions

### Inserting

...

### Popping

...
