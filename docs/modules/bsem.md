---
author: "Stefan Wagner"
date: 2022-08-12
description: "The ao_bsem.h module of the ao real-time operating system."
draft: true
permalink: /modules/bsem/
title: "ao_bsem.h"
toc: true
---

# Overview

...

# Types

## Binary Semaphore

The `ao_bsem_t` type represents a binary semaphore.

```c
struct ao_bsem_t
{
    ao_list_t list;
    bool      taken;
};
```

It consists of the following members.

| Member | |
|--------|-|
| `list` | The list of tasks attempting to take the semaphore. |
| `taken` | Indicates whether the semaphore is taken. |

## Binary Semaphore Taking

The `ao_bsem_take_t` type represents the taking of a binary semaphore.

```c
struct ao_bsem_take_t
{
    ao_async_t     async;
    ao_list_node_t node;
    bool volatile  result;
    ao_bsem_t *    sem;
};
```

It consists of the following members.

| Member | |
|--------|-|
| `async` | The asynchronous event. |
| `node` | The list node. |
| `result` | Indicates whether the binary semaphore has been taken. |
| `sem` | The binary semaphore. |

# Functions

## Giving

A binary semaphore can be given from both task and interrupt context.

```c
ao_bsem_t * s;
```

```c
ao_bsem_give(s);
```

## Taking

In contrast, a binary semaphore can be taken by a task, only.

```c
bool r;
```

```c
r = ao_bsem_take(s, AO_MILLISECONDS(500));

if (r)
{
    // Binary semaphore has been taken.
}
```

# External Links

[https://en.wikipedia.org/wiki/Semaphore_(programming)](https://en.wikipedia.org/wiki/Semaphore_(programming))
