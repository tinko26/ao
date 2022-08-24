---
author: "Stefan Wagner"
date: 2022-08-16
description: "The ao_barrier.h module of the ao real-time operating system."
draft: true
permalink: /modules/barrier/
title: "ao_barrier.h"
---

# ao_barrier.h

...

## Types

### Barrier

The `ao_barrier_t` type represents a barrier.

```c
struct ao_barrier_t
{
    ao_uint_t count;
    ao_uint_t count_threshold;
    ao_list_t list;
};
```

It consists of the following members.

| Member | |
|--------|-|
| `count` | The current number of waiting tasks. |
| `count_threshold` | The maximum number waiting tasks. |
| `list` | The list of waiting tasks. |

### Barrier Waiting

The `ao_barrier_wait_t` type represents the waiting at a barrier.

```c
struct ao_barrier_wait_t
{
    ao_async_t     async;
    ao_barrier_t * barrier;
    ao_list_node_t node;
    bool volatile  result;
};
```

It consists of the following members.

| Member | |
|--------|-|
| `async` | ... |
| `barrier` | ... |
| `node` | ... |
| `result` | ... |

## Functions

...

## External Links

[https://en.wikipedia.org/wiki/Barrier_(computer_science)](https://en.wikipedia.org/wiki/Barrier_(computer_science))
