---
author: "Stefan Wagner"
date: 2022-08-16
description: "The ao_counter.h module of the ao real-time operating system."
draft: true
permalink: /modules/counter/
title: "<code>ao_counter.h</code>"
---

# Overview

...

## Types

### Counter

The `ao_counter_t` type represents a counter.

```c
struct ao_counter_t
{
    ao_list_t list;
    ao_uint_t value;
};
```

It consists of the following members.

| Member | |
|--------|-|
| `list` | The list of waiting tasks. |
| `value` | The value. |

### Counter Waiting

The `ao_counter_wait_t` type represents the waiting for a counter match.

```c
struct ao_counter_wait_t
{
    ao_async_t         async;
    ao_counter_t *     counter;
    ao_counter_match_t match;
    void *             match_parameter;
    ao_list_node_t     node;
    bool volatile      result;
    ao_uint_t          value;
};
```

It consists of the following members.

| Member | |
|--------|-|
| `async` | ... |
| `counter` | ... |
| `match` | ... |
| `match_parameter` | ... |
| `node` | ... |
| `result` | ... |
| `value` | ... |

### Counter Adjusting

The `ao_counter_adjust_t` type represents a function to adjust the value of a counter. The function takes the old value and an additional parameter and returns the new value.

```c
typedef ao_uint_t (* ao_counter_adjust_t)
(
    ao_uint_t value,
    void *    parameter
);
```

### Counter Matching

The `ao_counter_match_t` type represents a function to check whether a specific value is a match. The function takes the current value, the waited-for value, and an additional parameter.

```c
typedef bool (* ao_counter_match_t)
(
    ao_uint_t value,
    ao_uint_t value_wait,
    void *    parameter
);
```

## Initialization

...

## Functions

### Adjusting

...

### Waiting

...
