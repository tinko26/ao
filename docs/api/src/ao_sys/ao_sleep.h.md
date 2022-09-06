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

# Typedefs

```c
typedef struct ao_sleep_t ao_sleep_t;
```

# Types

## `ao_sleep_t`

This type represents the sleeping of a task.

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

It consists of the following members.

| `alarm` | The alarm. |
| `async` | The asynchronous event. |
| `beginning` | The beginning. |
| `result` | Indicates whether the task has been sleeping for the specified time span. |
| `timeout` | The timeout. |

# Functions

```c
bool ao_sleep(ao_time_t timeout);
```

```c
bool ao_sleep_from(ao_time_t timeout, ao_time_t beginning);
```

```c
bool ao_sleep_forever();
```

```c
void ao_sleep_begin(ao_sleep_t * x);
```

```c
void ao_sleep_end(ao_sleep_t * x);
```
