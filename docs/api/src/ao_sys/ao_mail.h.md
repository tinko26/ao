---
author: "Stefan Wagner"
date: 2022-09-26
draft: true
permalink: /api/src/ao_sys/ao_mail.h/
toc: true
---

# Include

| [`ao_async.h`](ao_async.h.md) |
| [`ao_list.h`](../ao/ao_list.h.md) |
| [`ao_time.h`](ao_time.h.md) |
| `stdbool.h` |

# Identifier

```c
#define AO_MAIL
```

# Types

## `ao_mail_t`

```c
typedef struct ao_mail_t ao_mail_t;
```

This type represents a mail.

## `ao_mail_fetch_t`

```c
typedef struct ao_mail_fetch_t ao_mail_fetch_t;
```

This type represents the fetching of a mail.

## `ao_mailbox_t`

```c
typedef struct ao_mailbox_t ao_mailbox_t;
```

This type represents a mailbox.

# Structs

## `ao_mail_t`

```c
struct ao_mail_t
{
    ao_list_node_t mailbox_mail_node;
};
```

| `mailbox_mail_node` | The node for a mailbox's list of mails. |

## `ao_mail_fetch_t`

```c
struct ao_mail_fetch_t
{
    ao_async_t              async;
    ao_mail_t    * volatile mail;
    ao_mailbox_t *          mailbox;
    ao_list_node_t          mailbox_fetch_node;
    bool           volatile result;
};
```

| `async` | The asynchronous event. |
| `mail` | The mail that has been fetched. |
| `mailbox` | The mailbox. |
| `mailbox_fetch_node` | The node for the mailbox's list of fetchings. |
| `result` | The result. |

## `ao_mailbox_t`

```c
struct ao_mailbox_t
{
    ao_list_t fetch;
    ao_list_t mail;
};
```

| `fetchers` | The list of fetchings. |
| `mails` | The list of mails. |

# Functions

## `ao_mail_fetch`
## `ao_mail_fetch_from`

```c
bool ao_mail_fetch     (ao_mailbox_t * mailbox, ao_mail_t ** mail, ao_time_t timeout);
bool ao_mail_fetch_from(ao_mailbox_t * mailbox, ao_mail_t ** mail, ao_time_t timeout, ao_time_t beginning);
```

Fetches a mail in a blocking fashion with a timeout and an optional beginning.

## `ao_mail_fetch_forever`

```c
bool ao_mail_fetch_forever(ao_mailbox_t * mailbox, ao_mail_t ** mail);
```

Fetches a mail indefinitely in a blocking fashion.

## `ao_mail_fetch_try`

```c
bool ao_mail_fetch_try(ao_mailbox_t * mailbox, ao_mail_t ** mail);
```

Fetches a mail in a non-blocking fashion.

## `ao_mail_fetch_begin`
## `ao_mail_fetch_end`

```c
void ao_mail_fetch_begin(ao_mail_fetch_t * fetch);
void ao_mail_fetch_end  (ao_mail_fetch_t * fetch);
```

Begins or ends, respectively, a fetching of a mail.

## `ao_mail_post`

```c
void ao_mail_post(ao_mailbox_t * mailbox, ao_mail_t * mail);
```

Posts a mail.
