---
author: "Stefan Wagner"
date: 2022-08-17
description: "The ao_task.h module of the ao real-time operating system."
draft: true
permalink: /modules/task/
title: "ao_task.h"
---

# ao_task.h

...

## Configuration

## Types

### Task

The `ao_task_t` type represents a task.

```c
struct ao_task_t
{
    ao_block_t *            block;
    ao_task_context_t       context;
    struct
    {
        ao_uint_t           activate;
        ao_uint_t           block;
        ao_uint_t           inactivate;
        ao_uint_t           resume;
        ao_uint_t           start;
        ao_uint_t           stop;
        ao_uint_t           suspend;
        ao_uint_t           switch_in;
        ao_uint_t           switch_out;
        ao_uint_t           unblock;
    }
                            count;
    ao_uint_t               id;
    char const *            name;
    ao_proc_t               proc;
    void *                  proc_parameter;
    ao_task_sched_t         sched;
    ao_task_stack_t         stack;
    ao_int_t                started;
    ao_task_state_t         state;
    ao_task_state_pending_t state_pending;
    ao_int_t                suspended;
    struct
    {
        struct
        {
            ao_time_t       activation;
            ao_time_t       inactivation;
            ao_time_t       start;
            ao_time_t       stop;
            ao_time_t       switch_in;
            ao_time_t       switch_out;
        }
                            point;
        struct
        {
            ao_time_t       active;
            ao_time_t       down;
            ao_time_t       inactive;
            ao_time_t       up;
        }
                            span;
    }
                            time;
};
```

It consists of the following members.

| Member | |
|--------|-|
| `block` | The blocking data. The value is `NULL`, unless the task is blocked. |
| `context` | The context data. |
| `count` | Contains counters for various state transitions. This member is absent, if the `AO_TASK_COUNT` configuration option is disabled. |
| `count.activate` | The number of times the task has been activated. |
| `count.block` | The number of times the task has blocked. |
| `count.inactivate` | The number of times the task has been inactivated. |
| `count.resume` | The number of times the task has been resumed. |
| `count.start` | The number of times the task has been started. |
| `count.stop` | The number of times the task has been stopped. |
| `count.suspend` | The number of times the task has been suspended. |
| `count.switch_in` | The number of times the task has been switched in. |
| `count.switch_out` | The number of times the task has been switched out. |
| `count.unblock` | The number of times the task has been unblocked. |
| `id` | The ID. This member is absent, if the `AO_TASK_ID` configuration option is disabled. |
| `name` | The name. This member is absent, if the `AO_TASK_NAME` configuration option is disabled. |
| `proc` | The procedure. |
| `proc_parameter` | The procedure parameter. |
| `sched` | The scheduler data. |
| `stack` | The stack data. |
| `started` | Counts the number of times that the task has been started but not stopped. This counter is incremented with each call to `ao_task_start()` and decremented with each call to either `ao_task_stop()` or `ao_stop()`. |
| `state` | The state. |
| `state_pending` | The pending state transition. |
| `suspended` | Counts the number of times that the task has been suspended but not resumed. This counter is incremented with each call to either `ao_task_suspend()` or `ao_suspend()` and decremented with each call to `ao_task_resume()`. |
| `time` | Contains various time points and accumulated time spans. This member is absent, if the `AO_TASK_TIME` configuration option is disabled. |
| `time.point.activation` | The time point of the last activation. |
| `time.point.inactivation` | The time point of the last inactivation. |
| `time.point.start` | The time point of the last start. |
| `time.point.stop` | The time point of the last stop. |
| `time.point.switch_in` | The time point of the last switching in. |
| `time.point.switch_out` | The time point of the last switching out. |
| `time.span.active` | The accumulated time span of the task being active. |
| `time.span.down` | The accumulated time span of the task being not running. |
| `time.span.inactive` | The accumulated time span of the task being inactive. |
| `time.span.up` | The accumulated time span of the task being running. |

### Task State

### Task State Pending

## Initialization

...

## Functions

... 

## Callback

...

## Variables

...

