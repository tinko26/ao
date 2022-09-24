---
author: "Stefan Wagner"
date: 2022-09-13
draft: true
permalink: /api/src/ao_sys/ao_pmail.h/
toc: true
---

# Notes

This module implements a priority queue based on a red-black tree. Fetching returns the minimum element of the tree.

# Include

| [`ao_async.h`](ao_async.h.md) |
| [`ao_list.h`](../ao/ao_list.h.md) |
| [`ao_rb.h`](../ao/ao_rb.h.md) |
| [`ao_time.h`](ao_time.h.md) |
| `stdbool.h` |

# Identifier

```c
#define AO_PMAIL
```

# Types

## `ao_pmail_t`

```c
typedef struct ao_pmail_t ao_pmail_t;
```

This type represents a mail.

## `ao_pmail_fetch_t`

```c
typedef struct ao_pmail_fetch_t ao_pmail_fetch_t;
```

This type represents the fetching of a mail.

## `ao_pmailbox_t`

```c
typedef struct ao_pmailbox_t ao_pmailbox_t;
```

This type represents a mailbox.

# Structs

## `ao_pmail_t`

```c
struct ao_pmail_t
{
    ao_rb_node_t node;
};
```

| `node` | The node for the mailbox's priority queue of mails. |

## `ao_pmail_fetch_t`

```c
struct ao_pmail_fetch_t
{
    ao_async_t            async;
    ao_pmail_t * volatile mail;
    ao_pmailbox_t *       mailbox;
    ao_list_node_t        node;
    bool         volatile result;
};
```

| `async` | The asynchronous event. |
| `mail` | The mail that has been fetched. |
| `mailbox` | The mailbox. |
| `node` | The node for the mailbox's list of fetchings. |
| `result` | The result. |

## `ao_pmailbox_t`

```c
struct ao_pmailbox_t
{
    ao_list_t fetchers;
    ao_rb_t   mails;
};
```

| `fetchers` | The list of fetchings. |
| `mails` | The priority queue of mails. |

# Functions

## `ao_pmail_fetch`
## `ao_pmail_fetch_from`

```c
bool ao_pmail_fetch     (ao_pmailbox_t * x, ao_pmail_t ** m, ao_time_t timeout);
bool ao_pmail_fetch_from(ao_pmailbox_t * x, ao_pmail_t ** m, ao_time_t timeout, ao_time_t beginning);
```

Fetches a mail in a blocking fashion with a timeout and an optional beginning.

## `ao_pmail_fetch_forever`

```c
bool ao_pmail_fetch_forever(ao_pmailbox_t * x, ao_pmail_t ** m);
```

Fetches a mail indefinitely in a blocking fashion.

## `ao_pmail_fetch_try`

```c
bool ao_pmail_fetch_try(ao_pmailbox_t * x, ao_pmail_t ** m);
```

Fetches a mail in a non-blocking fashion.

## `ao_pmail_fetch_begin`
## `ao_pmail_fetch_end`

```c
void ao_pmail_fetch_begin(ao_pmail_fetch_t * x);
void ao_pmail_fetch_end  (ao_pmail_fetch_t * x);
```

Begins or ends, respectively, a fetching of a mail.

## `ao_pmail_post`

```c
void ao_pmail_post(ao_pmailbox_t * x, ao_pmail_t * m);
```

Posts a mail.
