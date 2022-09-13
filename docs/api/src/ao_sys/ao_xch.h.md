---
author: "Stefan Wagner"
date: 2022-08-31
draft: true
permalink: /api/src/ao_sys/ao_xch.h/
toc: true
---

# Notes

...

- client-server messaging.
- request-reply messaging

...

# Include

```c
#include <ao_async.h>
#include <ao_list.h>
#include <ao_task.h>
#include <ao_time.h>
#include <stdbool.h>
```

# Identifier

```c
#define AO_XCH
```

# Types

## `ao_xch_t`

```c
typedef struct ao_xch_t ao_xch_t;
```

```c
struct ao_xch_t
{
    ao_list_t clients;
    ao_list_t servers;
};
```

This type represents an exchange. It consists of the following members.

| `clients` | The list of waiting clients. |
| `servers` | The list of waiting servers. |

## `ao_xch_client_t`

```c
typedef struct ao_xch_client_t ao_xch_client_t;
```

```c
struct ao_xch_client_t
{
    ao_async_t                 async;

#if AO_TASK_INHERITANCE

    ao_task_master_t           master;

#endif

    ao_list_node_t             node;
    bool              volatile result;
    ao_xch_server_t * volatile server;

#if AO_TASK_INHERITANCE

    ao_task_t       *          task;

#endif

    ao_xch_t        *          xch;
};
```

This type represents the exchange activity of a client. It consists of the following members.

| `async` | The asynchronous event. |
| `master` | The task master. |
| `node` | The node for the exchange's waiting list. |
| `result` | Indicates whether a server has replied. |
| `server` | The server. |
| `task` | The client task. |
| `xch` | The exchange. |

## `ao_xch_server_t`

```c
typedef struct ao_xch_server_t ao_xch_server_t;
```

```c
struct ao_xch_server_t
{
    ao_async_t                 async;
    ao_xch_client_t * volatile client;
    ao_list_node_t             node;
    bool              volatile result;

#if AO_TASK_INHERITANCE

    ao_task_slave_t            slave;
    ao_task_t       *          task;

#endif

    ao_xch_t        *          xch;
};
```

This type represents the exchange activity of a server. It consists of the following members.

| `async` | The asynchronous event. |
| `client` | The client. |
| `node` | The node for the exchange's waiting list. |
| `result` | Indicates whether a client's request has arrived. |
| `slave` | The task slave. |
| `task` | The server task. |
| `xch` | The exchange. |

# Functions

## `ao_xch_client`
## `ao_xch_client_from`

```c
void ao_xch_client     (ao_xch_client_t * x, ao_time_t timeout);
void ao_xch_client_from(ao_xch_client_t * x, ao_time_t timeout, ao_time_t beginning);
```

## `ao_xch_client_forever`

```c
void ao_xch_client_forever(ao_xch_client_t * x);
```

## `ao_xch_client_begin`
## `ao_xch_client_end`

```c
void ao_xch_client_begin(ao_xch_client_t * x);
void ao_xch_client_end  (ao_xch_client_t * x);
```

## `ao_xch_server`
## `ao_xch_server_from`

```c
void ao_xch_server     (ao_xch_server_t * x, ao_time_t timeout);
void ao_xch_server_from(ao_xch_server_t * x, ao_time_t timeout, ao_time_t beginning);
```

## `ao_xch_server_forever`

```c
void ao_xch_server_forever(ao_xch_server_t * x);
```

## `ao_xch_server_try`

```c
void ao_xch_server_try(ao_xch_server_t * x);
```

## `ao_xch_server_begin`
## `ao_xch_server_end`

```c
void ao_xch_server_begin(ao_xch_server_t * x);
void ao_xch_server_end  (ao_xch_server_t * x);
```

## `ao_xch_server_reply`

```c
void ao_xch_server_reply(ao_xch_server_t * x);
```
