---
author: "Stefan Wagner"
date: 2022-08-31
draft: true
permalink: /api/src/ao_sys/ao_mail.h/
toc: true
---

# Include

```c
#include <ao_async.h>
#include <ao_list.h>
#include <ao_time.h>
#include <stdbool.h>
```

# Identifiers

## `AO_MAIL`

```c
#define AO_MAIL
```

# Types

## `ao_mail_t`

```c
typedef struct ao_mail_t ao_mail_t;
```

```c
struct ao_mail_t
{
    ao_list_node_t node;
};
```

This type represents a mail. It consists of the following members.

| `node` | The node for a mailbox's list of mails. |

## `ao_mail_fetch_t`

```c
typedef struct ao_mail_fetch_t ao_mail_fetch_t;
```

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

This type represents the fetching of a mail. It consists of the following members.

| `async` | |
| `mail` | |
| `mailbox` | |
| `node` | |
| `result` | |

## `ao_mailbox_t`

```c
typedef struct ao_mailbox_t ao_mailbox_t;
```

```c
struct ao_mailbox_t
{
    ao_list_t fetchers;
    ao_list_t mails;
};
```

This type represents a mailbox. It consists of the following members.

| `fetchers` | The list of fetchers. |
| `mails` | The list of mails. |

# Functions

## `ao_mail_fetch`
## `ao_mail_fetch_from`

```c
bool ao_mail_fetch(     ao_mailbox_t * x, ao_mail_t ** m, ao_time_t timeout);
bool ao_mail_fetch_from(ao_mailbox_t * x, ao_mail_t ** m, ao_time_t timeout, ao_time_t beginning);
```

## `ao_mail_fetch_forever`

```c
bool ao_mail_fetch_forever(ao_mailbox_t * x, ao_mail_t ** m);
```

## `ao_mail_fetch_try`

```c
bool ao_mail_fetch_try(ao_mailbox_t * x, ao_mail_t ** m);
```

## `ao_mail_fetch_begin`
## `ao_mail_fetch_end`

```c
void ao_mail_fetch_begin(ao_mail_fetch_t * x);
void ao_mail_fetch_end(  ao_mail_fetch_t * x);
```

## `ao_mail_post`

```c
void ao_mail_post(ao_mailbox_t * x, ao_mail_t * m);
```
