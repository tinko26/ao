---
api: true
author: "Stefan Wagner"
date: 2022-08-29
description: "The /src/ao_sys/ao_pmail.h file of the ao real-time operating system."
draft: true
permalink: /api/src/ao_sys/ao_pmail.h/
subtitle: ""
title: "ao_pmail.h"
toc: true
---

# Include

```c
#include <ao_async.h>
#include <ao_list.h>
#include <ao_rb.h>
#include <ao_time.h>
#include <stdbool.h>
```

# Typedefs

```c
typedef struct ao_pmail_t ao_pmail_t;
```

```c
typedef struct ao_pmail_fetch_t ao_pmail_fetch_t;
```

```c
typedef struct ao_pmailbox_t ao_pmailbox_t;
```

# Types

## `ao_pmail_t`

```c
struct ao_pmail_t
{
    ao_rb_node_t node;
};
```

Members:

| `node` | |

## `ao_pmail_fetch_t`

```c
struct ao_pmail_fetch_t
{
    ao_async_t async;
    ao_pmail_t * volatile mail;
    ao_pmailbox_t * mailbox;
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

## `ao_pmailbox_t`

```c
struct ao_pmailbox_t
{
    ao_list_t fetchers;
    ao_rb_t mails;
};
```

Members:

| `fetchers` | |
| `mails` | |

# Functions

```c
void ao_pmail_post( ao_pmailbox_t * x, ao_pmail_t * m);
```

```c
bool ao_pmail_fetch( ao_pmailbox_t * x, ao_pmail_t ** m, ao_time_t timeout);
```

```c
bool ao_pmail_fetch_from( ao_pmailbox_t * x, ao_pmail_t ** m, ao_time_t timeout, ao_time_t beginning);
```

```c
bool ao_pmail_fetch_forever( ao_pmailbox_t * x, ao_pmail_t ** m);
```

```c
bool ao_pmail_fetch_try( ao_pmailbox_t * x, ao_pmail_t ** m);
```

```c
void ao_pmail_fetch_begin( ao_pmail_fetch_t * x);
```

```c
void ao_pmail_fetch_end( ao_pmail_fetch_t * x);
```

