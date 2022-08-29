---
author: "Stefan Wagner"
date: 2022-08-17
description: "The ao_threshold.h module of the ao real-time operating system."
draft: true
permalink: /modules/threshold/
title: "<code>ao_threshold.h</code>"
toc: true
---

# Overview

...

- with a counter, each task can define its own matching function.
- in contrast, with a threshold, there is single matching function for all tasks.

...

## Types

### Threshold

The `ao_threshold_t` type represents a threshold.

```c
struct ao_threshold_t
{
    ao_threshold_adjust_t adjust;
    void *                adjust_parameter;
    ao_list_t             list;
    ao_threshold_match_t  match;
    void *                match_parameter;
    ao_uint_t             value;
};
```

It consists of the following members.

| Member | |
|--------|-|
| `adjust` | This function is to adjust the value after a match. |
| `adjust_parameter` | An additional parameter for the post-match adjusting. |
| `list` | The list of tasks waiting for a match. |
| `match` | The matching function. |
| `match_parameter` | An additional parameter for the matching function. |
| `value` | The value. |


### Threshold Waiting

The `ao_threshold_wait_t` type represents the waiting for a threshold match.

```c
struct ao_threshold_wait_t
{
    ao_async_t       async;
    ao_list_node_t   node;
    bool volatile    result;
    ao_threshold_t * threshold;
};
```

It consists of the following members.

| Member | |
|--------|-|
| `async` | The asynchronous event. |
| `node` | The node for the threshold's waiting list. |
| `result` | Indicates whether a match has occured. |
| `threshold` | The threshold. |

### Threshold Adjusting

The `ao_threshold_adjust_t` type represents a function to adjust the value of a threshold. The function takes the old value and an additional parameter and returns the new value.

```c
typedef ao_uint_t (* ao_threshold_adjust_t)
(
    ao_uint_t value,
    void *    parameter
);
```

### Threshold Matching

The `ao_threshold_match_t` type represents a function to check whether a specific value is a match. The function takes the value and an additional parameter.

```c
typedef bool (* ao_threshold_match_t)
(
    ao_uint_t value,
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
