---
author: "Stefan Wagner"
date: 2022-08-16
description: "The ao_pmail.h module of the ao real-time operating system."
draft: true
permalink: /modules/pmail/
title: "ao_pmail.h"
---

# ao_pmail.h

...

- asynchronous messaging with priorities

...

## Types

### Mailbox

The `ao_pmailbox_t` type represents a mailbox.

```c
struct ao_pmailbox_t
{
    ao_list_t fetchers;
    ao_rb_t   mails;
};
```

It consists of the following members.

| Member | |
|--------|-|
| `fetchers` | The list of fetchers. |
| `mails` | The priority queue of mails. |

### Mail

The `ao_pmail_t` type represents a mail.

```c
struct ao_pmail_t
{
    ao_rb_node_t node;
};
```

It consists of the following members.

| Member | |
|--------|-|
| `node` | The priority queue node. |

### Mail Fetching

The `ao_pmail_fetch_t` type represents the fetching of a mail.

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

It consists of the following members.

| Member | |
|--------|-|
| `async` | ... |
| `mail` | ... |
| `mailbox` | ... |
| `node` | ... |
| `result` | ... |

## Functions

### Posting

...

### Fetching

...
