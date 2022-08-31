---
api: true
author: "Stefan Wagner"
date: 2022-08-31
description: "The /src/ao_sys/ao_mail.h file of the ao real-time operating system."
draft: true
permalink: /api/src/ao_sys/ao_mail.h/
subtitle: "Mail for asynchronous messaging"
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
typedef struct ao_mail_t       ao_mail_t;
```

```c
typedef struct ao_mail_fetch_t ao_mail_fetch_t;
```

```c
typedef struct ao_mailbox_t    ao_mailbox_t;
```

# Types

## `ao_mail_t`

This type represents a mail.

```c
struct ao_mail_t
{
    ao_list_node_t node;
};
```

It consists of the following members.

| `node` | The node for a mailbox's list of mails. |

## `ao_mail_fetch_t`

This type represents the fetching of a mail.

```c
struct ao_mail_fetch_t
{
    ao_async_t           async;
    ao_mail_t * volatile mail;
    ao_mailbox_t *       mailbox;
    ao_list_node_t       node;
    bool        volatile result;
};
```

It consists of the following members.

| `async` | |
| `mail` | |
| `mailbox` | |
| `node` | |
| `result` | |

## `ao_mailbox_t`

This type represents a mailbox.

```c
struct ao_mailbox_t
{
    ao_list_t fetchers;
    ao_list_t mails;
};
```

It consists of the following members.

| `fetchers` | The list of fetchers. |
| `mails` | The list of mails. |

# Functions

```c
void ao_mail_post(ao_mailbox_t * x, ao_mail_t * m);
```

```c
bool ao_mail_fetch(ao_mailbox_t * x, ao_mail_t ** m, ao_time_t timeout);
```

```c
bool ao_mail_fetch_from(ao_mailbox_t * x, ao_mail_t ** m, ao_time_t timeout, ao_time_t beginning);
```

```c
bool ao_mail_fetch_forever(ao_mailbox_t * x, ao_mail_t ** m);
```

```c
bool ao_mail_fetch_try(ao_mailbox_t * x, ao_mail_t ** m);
```

```c
void ao_mail_fetch_begin(ao_mail_fetch_t * x);
```

```c
void ao_mail_fetch_end(ao_mail_fetch_t * x);
```
