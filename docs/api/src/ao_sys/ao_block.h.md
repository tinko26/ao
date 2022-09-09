---
author: "Stefan Wagner"
date: 2022-08-31
draft: true
external:
- https://en.wikipedia.org/wiki/Blocking_(computing) : "Blocking"
permalink: /api/src/ao_sys/ao_block.h/
toc: true
---

# Include

```c
#include <ao_alarm.h>
#include <ao_time.h>
```

# Identifiers

## `AO_BLOCK`

```c
#define AO_BLOCK
```

# Typedefs

```c
typedef struct ao_block_t ao_block_t;
```

# Types

## `ao_block_t`

This type represents the blocking of a task.

```c
struct ao_block_t
{
    ao_alarm_t alarm;
    ao_time_t  beginning;
    ao_time_t  timeout;
};
```

It consists of the following members.

| `alarm` | |
| `beginning` | |
| `timeout` | |
