---
author: "Stefan Wagner"
date: 2022-09-29
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

# Types

## `ao_pmail_t`

```c
typedef struct ao_pmail_t ao_pmail_t;
```

Represents a priority mail.

## `ao_pmail_fetch_t`

```c
typedef struct ao_pmail_fetch_t ao_pmail_fetch_t;
```

Represents the fetching of a priority mail.

## `ao_pmailbox_t`

```c
typedef struct ao_pmailbox_t ao_pmailbox_t;
```

Represents a priority mailbox.

# Structs

## `ao_pmail_t`

```c
struct ao_pmail_t
{
    ao_rb_node_t pmailbox_pmail_node;
};
```

| `pmailbox_pmail_node` | The node for the mailbox's priority queue of mails. |

## `ao_pmail_fetch_t`

```c
struct ao_pmail_fetch_t
{
    ao_async_t            async;
    ao_pmail_t * volatile pmail;
    ao_pmailbox_t *       pmailbox;
    ao_list_node_t        pmailbox_fetch_node;
    bool         volatile result;
};
```

| `async` | The asynchronous event. |
| `pmail` | The priority mail that has been fetched. |
| `pmailbox` | The priority mailbox. |
| `pmailbox_fetch_node` | The node for the mailbox's list of fetchings. |
| `result` | The result. |

## `ao_pmailbox_t`

```c
struct ao_pmailbox_t
{
    ao_list_t fetch;
    ao_rb_t   pmail;
};
```

| `fetch` | The list of fetchings. |
| `pmail` | The priority queue of mails. |

# Functions

## `ao_pmail_fetch`
## `ao_pmail_fetch_from`

```c
void ao_pmail_fetch     (ao_pmail_fetch_t * f, ao_time_t timeout);
void ao_pmail_fetch_from(ao_pmail_fetch_t * f, ao_time_t timeout, ao_time_t beginning);
```

Fetches a priority mail in a blocking fashion with a timeout and an optional beginning.

## `ao_pmail_fetch_forever`

```c
void ao_pmail_fetch_forever(ao_pmail_fetch_t * f);
```

Fetches a priority mail indefinitely in a blocking fashion.

## `ao_pmail_fetch_try`

```c
void ao_pmail_fetch_try(ao_pmail_fetch_t * f);
```

Fetches a priority mail in a non-blocking fashion.

## `ao_pmail_fetch_begin`
## `ao_pmail_fetch_end`

```c
void ao_pmail_fetch_begin(ao_pmail_fetch_t * f);
void ao_pmail_fetch_end  (ao_pmail_fetch_t * f);
```

Begins or ends, respectively, a fetching of a priority mail.

## `ao_pmail_post`

```c
void ao_pmail_post(ao_pmailbox_t * x, ao_pmail_t * p);
```

Posts a priority mail.
