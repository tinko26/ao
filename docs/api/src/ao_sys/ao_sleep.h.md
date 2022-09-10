---
author: "Stefan Wagner"
date: 2022-08-31
draft: true
permalink: /api/src/ao_sys/ao_sleep.h/
toc: true
---

# Include

```c
#include <ao_alarm.h>
#include <ao_async.h>
#include <ao_time.h>
#include <stdbool.h>
```

# Identifiers

## `AO_SLEEP`

```c
#define AO_SLEEP
```

# Types

## `ao_sleep_t`

```c
typedef struct ao_sleep_t ao_sleep_t;
```

```c
struct ao_sleep_t
{
    ao_alarm_t    alarm;
    ao_async_t    async;
    ao_time_t     beginning;
    bool volatile result;
    ao_time_t     timeout;
};
```

This type represents the sleeping of a task. It consists of the following members.

| `alarm` | The alarm. |
| `async` | The asynchronous event. |
| `beginning` | The beginning. |
| `result` | Indicates whether the task has been sleeping for the specified time span. |
| `timeout` | The timeout. |

# Functions

## `ao_sleep`

```c
bool ao_sleep(ao_time_t timeout);
```

Puts the running task to sleep. If the `timeout` is not equal to `AO_INFINITY`, then the task will wake up at `ao_now()` + `timeout`. If the `timeout` is equal to `AO_INFINITY`, then the task will sleep forever and must be woken up explicitly by another task or an interrupt calling `ao_task_wake()`. This function returns `true`, if task has woken up after the specified `timeout`, otherwise `false`.

## `ao_sleep_from`

```c
bool ao_sleep_from(ao_time_t timeout, ao_time_t beginning);
```

Puts the running task to sleep. If the `timeout` is not equal to `AO_INFINITY`, then the task will wake up at `beginning` + `timeout`. If the `timeout` is equal to `AO_INFINITY`, then the task will sleep forever and must be woken up explicitly by another task or an interrupt calling `ao_task_wake()`. This function returns `true`, if task has woken up after the specified `timeout`, otherwise `false`.


## `ao_sleep_forever`

```c
bool ao_sleep_forever();
```

Puts the running task to sleep. The task will never be woken up by the operating system. Therefore, it must be woken up explicitly by another task or an interrupt calling `ao_task_wake()`. This function returns `false`.

## `ao_sleep_begin`
## `ao_sleep_end`

```c
void ao_sleep_begin(ao_sleep_t * x);
void ao_sleep_end(  ao_sleep_t * x);
```

Begins or ends sleeping.
