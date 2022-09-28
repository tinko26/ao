---
author: "Stefan Wagner"
date: 2022-09-26
draft: true
permalink: /api/src/ao_sys/ao_sleep.h/
toc: true
---

# Include

| [`ao_alarm.h`](ao_alarm.h.md) |
| [`ao_async.h`](ao_async.h.md) |
| [`ao_time.h`](ao_time.h.md) |
| `stdbool.h` |

# Types

## `ao_sleep_t`

```c
typedef struct ao_sleep_t ao_sleep_t;
```

Represents the sleeping of a task.

# Structs

## `ao_sleep_t`

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

| `alarm` | The alarm. |
| `async` | The asynchronous event. |
| `beginning` | The beginning. |
| `result` | The result. |
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
void ao_sleep_begin(ao_sleep_t * sleep);
void ao_sleep_end  (ao_sleep_t * sleep);
```

Begins or ends, respectively, a sleeping.
