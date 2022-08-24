---
author: "Stefan Wagner"
date: 2022-08-17
description: "The ao_xch.h module of the ao real-time operating system."
draft: true
permalink: /modules/xch/
title: "ao_xch.h"
---

# Overview

...

- client-server messaging.
- request-reply messaging

...

## Types

### Exchange

The `ao_xch_t` type represents an exchange.

```c
struct ao_xch_t
{
    ao_list_t clients;
    ao_list_t servers;
};
```

It consists of the following members.

| Member | |
|--------|-|
| `clients` | The list of waiting clients. |
| `servers` | The list of waiting servers. |

### Client

The `ao_xch_client_t` type represents the exchange activity of a client.

```c
struct ao_xch_client_t
{
    ao_async_t                 async;
    ao_task_master_t           master;
    ao_list_node_t             node;
    bool              volatile result;
    ao_xch_server_t * volatile server;
    ao_task_t *                task;
    ao_xch_t *                 xch;
};
```

It consists of the following members.

| Member | |
|--------|-|
| `async` | The asynchronous event. |
| `master` | The task master. This member is absent, if the [task scheduler](../task-scheduler.md) does not support task inheritance. |
| `node` | The node for the exchange's waiting list. |
| `result` | Indicates whether a server has replied. |
| `server` | The server. |
| `task` | The client task. This member is absent, if the task scheduler does not support task inheritance. |
| `xch` | The exchange. |

### Server

The `ao_xch_server_t` type represents the exchange activity of a server.

```c
struct ao_xch_server_t
{
    ao_async_t                 async;
    ao_xch_client_t * volatile client;
    ao_list_node_t             node;
    bool              volatile result;
    ao_task_slave_t            slave;
    ao_task_t *                task;
    ao_xch_t *                 xch;
};
```

It consists of the following members.

| Member | |
|--------|-|
| `async` | The asynchronous event. |
| `client` | The client. |
| `node` | The node for the exchange's waiting list. |
| `result` | Indicates whether a client's request has arrived. |
| `slave` | The task slave. This member is absent, if the [task scheduler](../task-scheduler.md) does not support task inheritance. |
| `task` | The server task. This member is absent, if the task scheduler does not support task inheritance. |
| `xch` | The exchange. |

## Initialization

...

- nothing to do?

...

## Functions (Client)

...

- send request and wait for a reply

...

## Functions (Server)

...

- receive request and reply

...
