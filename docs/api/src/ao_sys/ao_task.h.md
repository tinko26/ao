---
api: true
author: "Stefan Wagner"
date: 2022-08-29
description: "The /src/ao_sys/ao_task.h file of the ao real-time operating system."
draft: true
permalink: /api/src/ao_sys/ao_task.h/
subtitle: ""
title: "ao_task.h"
toc: true
---

# Include

```c
#include <ao_block.h>
#include <ao_core.h>
#include <ao_func.h>
#include <ao_int.h>
#include <ao_task_context.h>
#include <ao_task_sched.h>
#include <ao_task_stack.h>
#include <ao_time.h>
#include <ao_uint.h>
#include <stdbool.h>
```

# Typedefs

```c
typedef struct ao_task_t ao_task_t;
```

```c
typedef enum ao_task_state_t ao_task_state_t;
```

```c
typedef enum ao_task_state_pending_t ao_task_state_pending_t;
```

# Constants

```c
#define AO_TASK_COUNT (false)
```

```c
#define AO_TASK_ID (false)
```

```c
#define AO_TASK_NAME (false)
```

```c
#define AO_TASK_TIME (false)
```

# Types

## `ao_task_state_t`

```c
enum ao_task_state_t
{
    AO_TASK_STOPPED = (0),
    AO_TASK_READY = (1 << 0),
    AO_TASK_RUNNING = (1 << 1),
    AO_TASK_BLOCKED = (1 << 2),
    AO_TASK_SUSPENDED = (1 << 3),
    AO_TASK_ACTIVE = AO_TASK_READY | AO_TASK_RUNNING,
    AO_TASK_SUSPENDABLE = AO_TASK_ACTIVE | AO_TASK_BLOCKED,
    AO_TASK_STARTED = AO_TASK_SUSPENDABLE | AO_TASK_SUSPENDED
};
```

Members:

| `AO_TASK_STOPPED` | |
| `AO_TASK_READY` | |
| `AO_TASK_RUNNING` | |
| `AO_TASK_BLOCKED` | |
| `AO_TASK_SUSPENDED` | |
| `AO_TASK_ACTIVE` | |
| `AO_TASK_SUSPENDABLE` | |
| `AO_TASK_STARTED` | |

## `ao_task_state_pending_t`

```c
enum ao_task_state_pending_t
{
    AO_TASK_STOPPING = (1 << 0),
    AO_TASK_BLOCKING = (1 << 1),
    AO_TASK_SUSPENDING = (1 << 2),
    AO_TASK_YIELDING = (1 << 3)
};
```

Members:

| `AO_TASK_STOPPING` | |
| `AO_TASK_BLOCKING` | |
| `AO_TASK_SUSPENDING` | |
| `AO_TASK_YIELDING` | |

## `ao_task_t`

```c
struct ao_task_t
{
    ao_block_t * block;
    ao_task_context_t context;
#if AO_TASK_COUNT
    struct
    {
        ao_uint_t activate;
        ao_uint_t block;
        ao_uint_t inactivate;
        ao_uint_t resume;
        ao_uint_t start;
        ao_uint_t stop;
        ao_uint_t suspend;
        ao_uint_t switch_in;
        ao_uint_t switch_out;
        ao_uint_t unblock;
    }
    count;
#endif
#if AO_TASK_ID
    ao_uint_t id;
#endif
#if AO_TASK_NAME
    char const * name;
#endif
    ao_proc_t proc;
    void * proc_parameter;
    ao_task_sched_t sched;
    ao_task_stack_t stack;
    ao_int_t started;
    ao_task_state_t state;
    ao_task_state_pending_t state_pending;
    ao_int_t suspended;
#if AO_TASK_TIME
    struct
    {
        struct
        {
            ao_time_t activation;
            ao_time_t inactivation;
            ao_time_t start;
            ao_time_t stop;
            ao_time_t switch_in;
            ao_time_t switch_out;
        }
        point;
        struct
        {
            ao_time_t active;
            ao_time_t down;
            ao_time_t inactive;
            ao_time_t up;
        }
        span;
    }
    time;
#endif
};
```

Members:

| `block` | |
| `context` | |
| `count` | |
| `count.activate` | |
| `count.block` | |
| `count.inactivate` | |
| `count.resume` | |
| `count.start` | |
| `count.stop` | |
| `count.suspend` | |
| `count.switch_in` | |
| `count.switch_out` | |
| `count.unblock` | |
| `id` | |
| `name` | |
| `proc` | |
| `proc_parameter` | |
| `sched` | |
| `stack` | |
| `started` | |
| `state` | |
| `state_pending` | |
| `suspended` | |
| `time` | |
| `time.point` | |
| `time.point.activation` | |
| `time.point.inactivation` | |
| `time.point.start` | |
| `time.point.stop` | |
| `time.point.switch_in` | |
| `time.point.switch_out` | |
| `time.span` | |
| `time.span.active` | |
| `time.span.down` | |
| `time.span.inactive` | |
| `time.span.up` | |

# Functions

```c
void ao_task_entry( ao_task_t const * t);
```

```c
ao_uint_t ao_task_get_count_activate( ao_task_t const * t);
```

```c
ao_uint_t ao_task_get_count_block( ao_task_t const * t);
```

```c
ao_uint_t ao_task_get_count_inactivate( ao_task_t const * t);
```

```c
ao_uint_t ao_task_get_count_resume( ao_task_t const * t);
```

```c
ao_uint_t ao_task_get_count_start( ao_task_t const * t);
```

```c
ao_uint_t ao_task_get_count_stop( ao_task_t const * t);
```

```c
ao_uint_t ao_task_get_count_suspend( ao_task_t const * t);
```

```c
ao_uint_t ao_task_get_count_switch_in( ao_task_t const * t);
```

```c
ao_uint_t ao_task_get_count_switch_out( ao_task_t const * t);
```

```c
ao_uint_t ao_task_get_count_unblock( ao_task_t const * t);
```

```c
ao_uint_t ao_task_get_id( ao_task_t const * t);
```

```c
char const * ao_task_get_name( ao_task_t const * t);
```

```c
ao_proc_t ao_task_get_proc( ao_task_t const * t);
```

```c
void * ao_task_get_proc_parameter( ao_task_t const * t);
```

```c
ao_task_state_t ao_task_get_state( ao_task_t const * t);
```

```c
ao_task_state_pending_t ao_task_get_state_pending( ao_task_t const * t);
```

```c
ao_time_t ao_task_get_time_point_activation( ao_task_t const * t);
```

```c
ao_time_t ao_task_get_time_point_inactivation(ao_task_t const * t);
```

```c
ao_time_t ao_task_get_time_point_start( ao_task_t const * t);
```

```c
ao_time_t ao_task_get_time_point_stop( ao_task_t const * t);
```

```c
ao_time_t ao_task_get_time_point_switch_in( ao_task_t const * t);
```

```c
ao_time_t ao_task_get_time_point_switch_out( ao_task_t const * t);
```

```c
ao_time_t ao_task_get_time_span_active( ao_task_t const * t);
```

```c
ao_time_t ao_task_get_time_span_down( ao_task_t const * t);
```

```c
ao_time_t ao_task_get_time_span_inactive( ao_task_t const * t);
```

```c
ao_time_t ao_task_get_time_span_up( ao_task_t const * t);
```

```c
bool ao_task_is_active( ao_task_t const * t);
```

```c
bool ao_task_is_blocked( ao_task_t const * t);
```

```c
bool ao_task_is_blocking( ao_task_t const * t);
```

```c
bool ao_task_is_ready( ao_task_t const * t);
```

```c
bool ao_task_is_running( ao_task_t const * t);
```

```c
bool ao_task_is_started( ao_task_t const * t);
```

```c
bool ao_task_is_stopped( ao_task_t const * t);
```

```c
bool ao_task_is_stopping( ao_task_t const * t);
```

```c
bool ao_task_is_suspendable( ao_task_t const * t);
```

```c
bool ao_task_is_suspended( ao_task_t const * t);
```

```c
bool ao_task_is_suspending( ao_task_t const * t);
```

```c
bool ao_task_is_yielding( ao_task_t const * t);
```

```c
void ao_task_resume( ao_task_t * t);
```

```c
void ao_task_set_count_activate( ao_task_t * t, ao_uint_t x);
```

```c
void ao_task_set_count_block( ao_task_t * t, ao_uint_t x);
```

```c
void ao_task_set_count_inactivate( ao_task_t * t, ao_uint_t x);
```

```c
void ao_task_set_count_resume( ao_task_t * t, ao_uint_t x);
```

```c
void ao_task_set_count_start( ao_task_t * t, ao_uint_t x);
```

```c
void ao_task_set_count_stop( ao_task_t * t, ao_uint_t x);
```

```c
void ao_task_set_count_suspend( ao_task_t * t, ao_uint_t x);
```

```c
void ao_task_set_count_switch_in( ao_task_t * t, ao_uint_t x);
```

```c
void ao_task_set_count_switch_out( ao_task_t * t, ao_uint_t x);
```

```c
void ao_task_set_count_unblock( ao_task_t * t, ao_uint_t x);
```

```c
void ao_task_set_id( ao_task_t * t, ao_uint_t x);
```

```c
void ao_task_set_name( ao_task_t * t, char const * x);
```

```c
void ao_task_set_proc( ao_task_t * t, ao_proc_t proc, void * parameter);
```

```c
void ao_task_set_time_span_active( ao_task_t * t, ao_time_t x);
```

```c
void ao_task_set_time_span_down( ao_task_t * t, ao_time_t x);
```

```c
void ao_task_set_time_span_inactive( ao_task_t * t, ao_time_t x);
```

```c
void ao_task_set_time_span_up( ao_task_t * t, ao_time_t x);
```

```c
void ao_task_start( ao_task_t * t);
```

```c
void ao_task_stop( ao_task_t * t);
```

```c
void ao_task_suspend( ao_task_t * t);
```

```c
void ao_task_wake( ao_task_t * t);
```

# Variables

```c
extern ao_task_t ao_task_main;
```

```c
extern ao_task_t * volatile ao_task_running [AO_CORE_COUNT];
```
