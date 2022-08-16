---
author: "Stefan Wagner"
date: 2022-08-16
description: "The ao_flag.h module of the ao real-time operating system."
draft: true
permalink: /modules/flag/
title: "ao_flag.h"
---

# ao_flag.h

...

- event flags

...

## Types

### Flags

The `ao_flag_t` type represents a set of event flags.

```c
struct ao_flag_t
{
    ao_list_t list;
    ao_uint_t mask;
};
```

It consists of the following members.

| Member | |
|--------|-|
| `list` | The list of waiting tasks. |
| `mask` | The bitmask. |

### Flags Waiting

The `ao_flag_wait_t` type represents the waiting for a set of event flags.

```c
struct ao_flag_wait_t
{
    ao_async_t      async;
    ao_flag_t *     flag;
    ao_uint_t       mask;
    ao_flag_match_t match;
    void *          match_parameter;
    ao_list_node_t  node;
    bool volatile   result;
};
```

It consists of the following members.

| Member | |
|--------|-|
| `async` | ... |
| `flag` | ... |
| `mask` | ... |
| `match` | ... |
| `match_parameter` | ... |
| `node` | ... |
| `result` | ... |

### Flags Matching

The `` type represents a function checking for a match. It takes the current bitmask, the waited-for bitmask, and an additional parameter.

```c
typedef bool (* ao_flag_match_t)
(
    ao_uint_t mask,
    ao_uint_t mask_wait,
    void *    parameter
);
```

## Functions

### Adjusting

...

### Waiting

...
