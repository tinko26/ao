---
author: "Stefan Wagner"
date: 2022-09-13
draft: true
permalink: /api/src/ao_sys/ao_task.h/
toc: true
---

# Notes

...

- pending state:
- when a task is running, a state transition might not be possible immediately. First, the task must be switched out, which is a scheduler function, which can be executed in the context of a task switch interrupt, only.
- task blocks
- task yields
- task suspends itself
- task stops itself
- task is suspended by an interrupt or by another task (that is running on another core)
- task is stopped by in interrupt or by another task (that is running on another core)
- therefore, such a state transition is recorded in the `state_pending` member.

...

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

# Identifier

```c
#define AO_TASK
```

# Configuration

## `AO_TASK_COUNT`

```c
#define AO_TASK_COUNT (false)
```

Defines whether to count various state transitions.

## `AO_TASK_ID`

```c
#define AO_TASK_ID (false)
```

Defines whether tasks can be assigned an ID.

## `AO_TASK_NAME`

```c
#define AO_TASK_NAME (false)
```

Defines whether tasks can be assigned a name.

## `AO_TASK_TIME`

```c
#define AO_TASK_TIME (false)
```

Defines whether to measure various accumulated time spans.

# Types

## `ao_task_state_t`

```c
typedef enum ao_task_state_t ao_task_state_t;
```

```c
enum ao_task_state_t
{
    AO_TASK_STOPPED     = (0),
    AO_TASK_READY       = (1 << 0),
    AO_TASK_RUNNING     = (1 << 1),
    AO_TASK_BLOCKED     = (1 << 2),
    AO_TASK_SUSPENDED   = (1 << 3),
    AO_TASK_ACTIVE      = 
        AO_TASK_READY |
        AO_TASK_RUNNING,
    AO_TASK_SUSPENDABLE = 
        AO_TASK_ACTIVE |
        AO_TASK_BLOCKED,
    AO_TASK_STARTED     = 
        AO_TASK_SUSPENDABLE |
        AO_TASK_SUSPENDED
};
```

This type represents task states. It is used as a bitmask and defines the following symbols.

| `AO_TASK_STOPPED`     | `0000` | The task is stopped. |
| `AO_TASK_READY`       | `0001` | The task is ready. |
| `AO_TASK_RUNNING`     | `0010` | The task is running. |
| `AO_TASK_BLOCKED`     | `0100` | The task is blocked. |
| `AO_TASK_SUSPENDED`   | `1000` | The task is suspended. |
| `AO_TASK_ACTIVE`      | `0011` | The task is active, that is, it is ready or running. |
| `AO_TASK_SUSPENDABLE` | `0111` | The task is suspendable, that is, it is ready, running, or blocked. |
| `AO_TASK_STARTED`     | `1111` | The task is started, that is, it is ready, running, blocked, or suspended. |

## `ao_task_state_pending_t`

```c
typedef enum ao_task_state_pending_t ao_task_state_pending_t;
```

```c
enum ao_task_state_pending_t
{
    AO_TASK_STOPPING   = (1 << 0),
    AO_TASK_BLOCKING   = (1 << 1),
    AO_TASK_SUSPENDING = (1 << 2),
    AO_TASK_YIELDING   = (1 << 3)
};
```

This type represents pending task state transitions. It is used as a bitmask and defines the following symbols.

| `AO_TASK_STOPPING`   | `0001` | The task is stopping. |
| `AO_TASK_BLOCKING`   | `0010` | The task is blocking. |
| `AO_TASK_SUSPENDING` | `0100` | The task is supending. |
| `AO_TASK_YIELDING`   | `1000` | The task is yielding. |

## `ao_task_t`

```c
typedef struct ao_task_t ao_task_t;
```

```c
struct ao_task_t
{
    ao_block_t *            block;
    ao_task_context_t       context;

#if AO_TASK_COUNT

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
    }                       count;

#endif

#if AO_TASK_ID

    ao_uint_t               id;

#endif

#if AO_TASK_NAME

    char const *            name;

#endif

    ao_proc_t               proc;
    void *                  proc_parameter;
    ao_task_sched_t         sched;
    ao_task_stack_t         stack;
    ao_int_t                started;
    ao_task_state_t         state;
    ao_task_state_pending_t state_pending;
    ao_int_t                suspended;

#if AO_TASK_TIME

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
        }                   point;
        struct
        {
            ao_time_t       active;
            ao_time_t       down;
            ao_time_t       inactive;
            ao_time_t       up;
        }                   span;
    }                       time;

#endif

};
```

This type represents a task. It consists of the following members.

| `block` | The blocking data. |
| `context` | The context data. |
| `count` | Contains counters for various state transitions. |
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
| `id` | The ID. |
| `name` | The name. |
| `proc` | The procedure. |
| `proc_parameter` | The procedure parameter. |
| `sched` | The scheduler data. |
| `stack` | The stack data. |
| `started` | Counts the number of times that the task has been started but not stopped. This counter is incremented with each call to `ao_task_start()` and decremented with each call to either `ao_task_stop()` or `ao_stop()`. |
| `state` | The state. |
| `state_pending` | The pending state transition. |
| `suspended` | Counts the number of times that the task has been suspended but not resumed. This counter is incremented with each call to either `ao_task_suspend()` or `ao_suspend()` and decremented with each call to `ao_task_resume()`. |
| `time` | Contains various time points and accumulated time spans. |
| `time.point` | Contains various time points. |
| `time.point.activation` | The time point of the last activation. |
| `time.point.inactivation` | The time point of the last inactivation. |
| `time.point.start` | The time point of the last start. |
| `time.point.stop` | The time point of the last stop. |
| `time.point.switch_in` | The time point of the last switching in. |
| `time.point.switch_out` | The time point of the last switching out. |
| `time.span` | Contains various accumulated time spans. |
| `time.span.active` | The accumulated time span of the task being active. |
| `time.span.down` | The accumulated time span of the task being not running. |
| `time.span.inactive` | The accumulated time span of the task being inactive. |
| `time.span.up` | The accumulated time span of the task being running. |

# Functions

## `ao_task_entry`

```c
void ao_task_entry(ao_task_t const * t);
```

The entry point for each task. It takes the respective task as its only argument.

First, this function calls the task procedure, if specified. Then, after the task procedure has returned, it locks the task in an infinite loop, in order to avoid to return accidentally.

## `ao_task_get_count`

```c
ao_uint_t ao_task_get_count_activate  (ao_task_t const * t);
ao_uint_t ao_task_get_count_block     (ao_task_t const * t);
ao_uint_t ao_task_get_count_inactivate(ao_task_t const * t);
ao_uint_t ao_task_get_count_resume    (ao_task_t const * t);
ao_uint_t ao_task_get_count_start     (ao_task_t const * t);
ao_uint_t ao_task_get_count_stop      (ao_task_t const * t);
ao_uint_t ao_task_get_count_suspend   (ao_task_t const * t);
ao_uint_t ao_task_get_count_switch_in (ao_task_t const * t);
ao_uint_t ao_task_get_count_switch_out(ao_task_t const * t);
ao_uint_t ao_task_get_count_unblock   (ao_task_t const * t);
```

Gets the number of state transitions a task has gone through.

## `ao_task_get_id`

```c
ao_uint_t ao_task_get_id(ao_task_t const * t);
```

Gets the ID of a task.

## `ao_task_get_name`

```c
char const * ao_task_get_name(ao_task_t const * t);
```

Gets the name of a task.

## `ao_task_get_proc`

```c
ao_proc_t ao_task_get_proc          (ao_task_t const * t);
void *    ao_task_get_proc_parameter(ao_task_t const * t);
```

Gets the procedure or procedure parameter, respectively, of a task.

## `ao_task_get_state`

```c
ao_task_state_t ao_task_get_state(ao_task_t const * t);
```

Gets the current state of a task.

## `ao_task_get_state_pending`

```c
ao_task_state_pending_t ao_task_get_state_pending(ao_task_t const * t);
```

Gets the current pending state transition of a task.

## `ao_task_get_time_point`

```c
ao_time_t ao_task_get_time_point_activation  (ao_task_t const * t);
ao_time_t ao_task_get_time_point_inactivation(ao_task_t const * t);
ao_time_t ao_task_get_time_point_start       (ao_task_t const * t);
ao_time_t ao_task_get_time_point_stop        (ao_task_t const * t);
ao_time_t ao_task_get_time_point_switch_in   (ao_task_t const * t);
ao_time_t ao_task_get_time_point_switch_out  (ao_task_t const * t);
```

Gets a time point of a task.

## `ao_task_get_time_span`

```c
ao_time_t ao_task_get_time_span_active  (ao_task_t const * t);
ao_time_t ao_task_get_time_span_down    (ao_task_t const * t);
ao_time_t ao_task_get_time_span_inactive(ao_task_t const * t);
ao_time_t ao_task_get_time_span_up      (ao_task_t const * t);
```

Gets an accumulated time span measured for a task.

## `ao_task_is`

```c
bool ao_task_is_active     (ao_task_t const * t);
bool ao_task_is_blocked    (ao_task_t const * t);
bool ao_task_is_ready      (ao_task_t const * t);
bool ao_task_is_running    (ao_task_t const * t);
bool ao_task_is_started    (ao_task_t const * t);
bool ao_task_is_stopped    (ao_task_t const * t);
bool ao_task_is_suspendable(ao_task_t const * t);
bool ao_task_is_suspended  (ao_task_t const * t);
```

Checks whether a task is in a specific state.

```c
bool ao_task_is_blocking   (ao_task_t const * t);
bool ao_task_is_stopping   (ao_task_t const * t);
bool ao_task_is_suspending (ao_task_t const * t);
bool ao_task_is_yielding   (ao_task_t const * t);
```

Checks whether a specific state transition is pending for a task.

## `ao_task_resume`

```c
void ao_task_resume(ao_task_t * t);
```

Resumes a task.

## `ao_task_set_count`

```c
void ao_task_set_count_activate  (ao_task_t * t, ao_uint_t x);
void ao_task_set_count_block     (ao_task_t * t, ao_uint_t x);
void ao_task_set_count_inactivate(ao_task_t * t, ao_uint_t x);
void ao_task_set_count_resume    (ao_task_t * t, ao_uint_t x);
void ao_task_set_count_start     (ao_task_t * t, ao_uint_t x);
void ao_task_set_count_stop      (ao_task_t * t, ao_uint_t x);
void ao_task_set_count_suspend   (ao_task_t * t, ao_uint_t x);
void ao_task_set_count_switch_in (ao_task_t * t, ao_uint_t x);
void ao_task_set_count_switch_out(ao_task_t * t, ao_uint_t x);
void ao_task_set_count_unblock   (ao_task_t * t, ao_uint_t x);
```

Sets a specific state transition counter of a task.

## `ao_task_set_id`

```c
void ao_task_set_id(ao_task_t * t, ao_uint_t x);
```

Sets the ID of a task.

## `ao_task_set_name`

```c
void ao_task_set_name(ao_task_t * t, char const * x);
```

Sets the name of a task.

## `ao_task_set_proc`

```c
void ao_task_set_proc(ao_task_t * t, ao_proc_t proc, void * parameter);
```

Sets the procedure and procedure parameter of a task.

## `ao_task_set_time_span`

```c
void ao_task_set_time_span_active  (ao_task_t * t, ao_time_t x);
void ao_task_set_time_span_down    (ao_task_t * t, ao_time_t x);
void ao_task_set_time_span_inactive(ao_task_t * t, ao_time_t x);
void ao_task_set_time_span_up      (ao_task_t * t, ao_time_t x);
```

Sets an accumulated time span of a task.

## `ao_task_start`

```c
void ao_task_start(ao_task_t * t);
```

Starts a task.

## `ao_task_stop`

```c
void ao_task_stop(ao_task_t * t);
```

Stops a task.

## `ao_task_suspend`

```c
void ao_task_suspend(ao_task_t * t);
```

Suspends a task.

## `ao_task_wake`

```c
void ao_task_wake(ao_task_t * t);
```

Wakes up a task.

# Variables

## `ao_task_main`

```c
extern ao_task_t ao_task_main;
```

The task executing the `main()` function.

## `ao_task_running`

```c
extern ao_task_t * volatile ao_task_running [AO_CORE_COUNT];
```

The running task for each core.
