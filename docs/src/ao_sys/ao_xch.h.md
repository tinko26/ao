---
api: true
author: "Stefan Wagner"
date: 2022-08-29
description: "The /src/ao_sys/ao_xch.h file of the ao real-time operating system."
draft: true
permalink: /src/ao_sys/ao_xch.h/
subtitle: ""
title: "ao_xch.h"
toc: true
---

# Include

```c
#include <ao_async.h>
#include <ao_list.h>
#include <ao_task.h>
#include <ao_time.h>
#include <stdbool.h>
```

# Typedefs

```c
typedef struct ao_xch_t ao_xch_t;
```

```c
typedef struct ao_xch_client_t ao_xch_client_t;
```

```c
typedef struct ao_xch_server_t ao_xch_server_t;
```

# Types

## `ao_xch_t`

```c
struct ao_xch_t
{
    ao_list_t clients;
    ao_list_t servers;
};
```

Members:

| `clients` | |
| `servers` | |

## `ao_xch_client_t`

```c
struct ao_xch_client_t
{
    ao_async_t async;
#if AO_TASK_INHERITANCE
    ao_task_master_t master;
#endif
    ao_list_node_t node;
    bool volatile result;
    ao_xch_server_t * volatile server;
#if AO_TASK_INHERITANCE
    ao_task_t * task;
#endif
    ao_xch_t * xch;
};
```

Members:

| `async` | |
| `master` | |
| `node` | |
| `result` | |
| `server` | |
| `task` | |
| `xch` | |

## `ao_xch_server_t`

```c
struct ao_xch_server_t
{
    ao_async_t async;
    ao_xch_client_t * volatile client;
    ao_list_node_t node;
    bool volatile result;
#if AO_TASK_INHERITANCE
    ao_task_slave_t slave;
    ao_task_t * task;
#endif
    ao_xch_t * xch;
};
```

Members:

| `async` | |
| `client` | |
| `node` | |
| `result` | |
| `slave` | |
| `task` | |
| `xch` | |

# Functions

```c
void ao_xch_client( ao_xch_client_t * x, ao_time_t timeout);
```

```c
void ao_xch_client_from( ao_xch_client_t * x, ao_time_t timeout, ao_time_t beginning);
```

```c
void ao_xch_client_forever( ao_xch_client_t * x);
```

```c
void ao_xch_client_begin( ao_xch_client_t * x);
```

```c
void ao_xch_client_end( ao_xch_client_t * x);
```

```c
void ao_xch_server( ao_xch_server_t * x, ao_time_t timeout);
```

```c
void ao_xch_server_from( ao_xch_server_t * x, ao_time_t timeout, ao_time_t beginning);
```

```c
void ao_xch_server_forever( ao_xch_server_t * x);
```

```c
void ao_xch_server_try( ao_xch_server_t * x);
```

```c
void ao_xch_server_begin( ao_xch_server_t * x);
```

```c
void ao_xch_server_end( ao_xch_server_t * x);
```

```c
void ao_xch_server_reply( ao_xch_server_t * x);
```

