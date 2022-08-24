---
author: "Stefan Wagner"
date: 2022-08-16
description: "The ao_mail.h module of the ao real-time operating system."
draft: true
permalink: /modules/mail/
title: "ao_mail.h"
---

# Overview

...

- asynchronous messaging

...

## Types

### Mailbox

The `ao_mailbox_t` type represents a mailbox.

```c
struct ao_mailbox_t
{
    ao_list_t fetchers;
    ao_list_t mails;
};
```

It consists of the following members.

| Member | |
|--------|-|
| `fetchers` | The list of fetchers. |
| `mails` | The list of mails. |

### Mail

The `ao_mail_t` type represents a mail.

```c
struct ao_mail_t
{
    ao_list_node_t node;
};
```

It consists of the following members.

| Member | |
|--------|-|
| `node` | The list node. |

### Mail Fetching

The `ao_mail_fetch_t` type represents the fetching of a mail.

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
