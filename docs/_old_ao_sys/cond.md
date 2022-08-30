---
author: "Stefan Wagner"
date: 2022-08-16
description: "The ao_cond.h module of the ao real-time operating system."
draft: true
permalink: /modules/cond/
title: "<code>ao_cond.h</code>"
toc: true
---

# Overview

...

- Condition (variable), but not that monitor-based kind implemented in the STL.
- actually the same behavior as a binary semaphore

...

## Types

### Condition

The `ao_cond_t` type represents a condition.

```c
struct ao_cond_t
{
    ao_list_t list;
    bool      state;
};
```

It consists of the following members.

| Member | |
|--------|-|
| `list` | ... |
| `state` | ... |

### Condition Waiting

The `ao_cond_wait_t` type represents the waiting for a condition.

```c
struct ao_cond_wait_t
{
    ao_async_t     async;
    ao_cond_t *    cond;
    ao_list_node_t node;
    bool volatile  result;
};
```

It consists of the following members.

| Member | |
|--------|-|
| `async` | ... |
| `cond` | ... |
| `node` | ... |
| `result` | ... |

## Functions

### Clearing and Setting

...

### Waiting

...
