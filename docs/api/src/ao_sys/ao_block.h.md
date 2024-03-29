---
author: "Stefan Wagner"
date: 2022-09-13
draft: true
external:
- https://en.wikipedia.org/wiki/Blocking_(computing) : "Blocking"
permalink: /api/src/ao_sys/ao_block.h/
toc: true
---

# Include

| [`ao_alarm.h`](ao_alarm.h.md) |
| [`ao_time.h`](ao_time.h.md) |

# Types

## `ao_block_t`

```c
typedef struct ao_block_t ao_block_t;
```

Represents the blocking of a task.

# Structs

## `ao_block_t`

```c
struct ao_block_t
{
    ao_alarm_t alarm;
    ao_time_t  beginning;
    ao_time_t  timeout;
};
```

| `alarm` | The alarm. |
| `beginning` | The beginning. |
| `timeout` | The timeout. |
