---
author: "Stefan Wagner"
date: 2022-09-26
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

| [`ao_async.h`](ao_async.h.md) |
| [`ao_list.h`](../ao/ao_list.h.md) |
| [`ao_task.h`](ao_task.h.md) |
| [`ao_time.h`](ao_time.h.md) |
| `stdbool.h` |

# Identifier

```c
#define AO_XCH
```

# Types

## `ao_xch_t`

```c
typedef struct ao_xch_t ao_xch_t;
```

This type represents an exchange.

## `ao_xch_client_t`

```c
typedef struct ao_xch_client_t ao_xch_client_t;
```

This type represents a client sending a request and receiving a reply.

## `ao_xch_server_t`

```c
typedef struct ao_xch_server_t ao_xch_server_t;
```

This type represents a server receiving a request.

# Structs

## `ao_xch_t`

```c
struct ao_xch_t
{
    ao_list_t client;
    ao_list_t server;
};
```

| `client` | The list of clients. |
| `server` | The list of servers. |

## `ao_xch_client_t`

```c
struct ao_xch_client_t
{
    ao_async_t                 async;

#if AO_TASK_INHERITANCE

    ao_task_master_t           master;

#endif

    bool              volatile result;
    ao_xch_server_t * volatile server;

#if AO_TASK_INHERITANCE

    ao_task_t *                task;

#endif

    ao_xch_t *                 xch;
    ao_list_node_t             xch_client_node;
};
```

| `async` | The asynchronous event. |
| `master` | The task master. |
| `result` | The result. |
| `server` | The server. |
| `task` | The task. |
| `xch` | The exchange. |
| `xch_client_node` | The node for the exchange's list of clients. |

## `ao_xch_server_t`

```c
struct ao_xch_server_t
{
    ao_async_t                 async;
    ao_xch_client_t * volatile client;
    bool              volatile result;

#if AO_TASK_INHERITANCE

    ao_task_slave_t            slave;
    ao_task_t       *          task;

#endif

    ao_xch_t        *          xch;
    ao_list_node_t             xch_server_node;
};
```

| `async` | The asynchronous event. |
| `client` | The client. |
| `result` | The result. |
| `slave` | The task slave. |
| `task` | The task. |
| `xch` | The exchange. |
| `xch_server_node` | The node for the exchange's list of servers. |

# Functions

## `ao_xch_client`
## `ao_xch_client_from`

```c
void ao_xch_client     (ao_xch_client_t * client, ao_time_t timeout);
void ao_xch_client_from(ao_xch_client_t * client, ao_time_t timeout, ao_time_t beginning);
```

Sends a request and receives a reply in a blocking fashion with a timeout and an optional beginning.

## `ao_xch_client_forever`

```c
void ao_xch_client_forever(ao_xch_client_t * client);
```

Sends a request and receives a reply indefinitely in a blocking fashion.

## `ao_xch_client_begin`
## `ao_xch_client_end`

```c
void ao_xch_client_begin(ao_xch_client_t * client);
void ao_xch_client_end  (ao_xch_client_t * client);
```

Begins or ends, respectively, a client sending a request and receiving a reply.

## `ao_xch_server`
## `ao_xch_server_from`

```c
void ao_xch_server     (ao_xch_server_t * server, ao_time_t timeout);
void ao_xch_server_from(ao_xch_server_t * server, ao_time_t timeout, ao_time_t beginning);
```

Receives a request in a blocking fashion with a timeout and an optional beginning.

## `ao_xch_server_forever`

```c
void ao_xch_server_forever(ao_xch_server_t * server);
```

Receives a request indefinitely in a blocking fashion.

## `ao_xch_server_try`

```c
void ao_xch_server_try(ao_xch_server_t * server);
```

Receives a request in a non-blocking fashion.

## `ao_xch_server_begin`
## `ao_xch_server_end`

```c
void ao_xch_server_begin(ao_xch_server_t * server);
void ao_xch_server_end  (ao_xch_server_t * server);
```

Begins or ends, respectively, the receiving of a request.

## `ao_xch_server_reply`

```c
void ao_xch_server_reply(ao_xch_server_t * server);
```

Sends a reply.
