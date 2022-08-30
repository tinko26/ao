---
api: true
author: "Stefan Wagner"
date: 2022-08-29
description: "The /src/ao_sys/ao_mail.h file of the ao real-time operating system."
draft: true
permalink: /api/src/ao_sys/ao_mail.h/
subtitle: ""
title: "ao_mail.h"
toc: true
---

# Include

```c
#include <ao_async.h>
#include <ao_list.h>
#include <ao_time.h>
#include <stdbool.h>
```

# Typedefs

```c
typedef struct ao_mail_t ao_mail_t;
```

```c
typedef struct ao_mail_fetch_t ao_mail_fetch_t;
```

```c
typedef struct ao_mailbox_t ao_mailbox_t;
```

# Types

## `ao_mail_t`

```c
struct ao_mail_t
{
    ao_list_node_t node;
};
```

Members:

| `node` | |

## `ao_mail_fetch_t`

```c
struct ao_mail_fetch_t
{
    ao_async_t async;
    ao_mail_t * volatile mail;
    ao_mailbox_t * mailbox;
    ao_list_node_t node;
    bool volatile result;
};
```

Members:

| `async` | |
| `mail` | |
| `mailbox` | |
| `node` | |
| `result` | |

## `ao_mailbox_t`

```c
struct ao_mailbox_t
{
    ao_list_t fetchers;
    ao_list_t mails;
};
```

Members:

| `fetchers` | |
| `mails` | |

# Functions

```c
void ao_mail_post( ao_mailbox_t * x, ao_mail_t * m);
```

```c
bool ao_mail_fetch( ao_mailbox_t * x, ao_mail_t ** m, ao_time_t timeout);
```

```c
bool ao_mail_fetch_from( ao_mailbox_t * x, ao_mail_t ** m, ao_time_t timeout, ao_time_t beginning);
```

```c
bool ao_mail_fetch_forever( ao_mailbox_t * x, ao_mail_t ** m);
```

```c
bool ao_mail_fetch_try( ao_mailbox_t * x, ao_mail_t ** m);
```

```c
void ao_mail_fetch_begin( ao_mail_fetch_t * x);
```

```c
void ao_mail_fetch_end( ao_mail_fetch_t * x);
```

