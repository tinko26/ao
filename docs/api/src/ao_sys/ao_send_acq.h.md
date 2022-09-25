---
author: "Stefan Wagner"
date: 2022-09-25
draft: true
permalink: /api/src/ao_sys/ao_send_acq.h/
toc: true
---

# Notes

This module provides an abstraction for sending acquired memory blocks to an opaque destination.

# Include

| [`ao_send_ptr.h`](ao_send_ptr.h.md) |
| [`ao_time.h`](ao_time.h.md) |

# Identifier

```c
#define AO_SEND_ACQ
```

# Types

## `ao_send_acq_t`

```c
typedef ao_send_ptr_t ao_send_acq_t;
```

This type represents the sending of an acquired memory block.

## `ao_send_acq_proc_t`

```c
typedef ao_send_ptr_proc_t ao_send_acq_proc_t;
```

This type represents a function beginning or ending a sending of an acquired memory block.

# Functions

## `ao_send_acq`
## `ao_send_acq_from`

```c
void ao_send_acq     (ao_send_acq_t * x, ao_time_t timeout);
void ao_send_acq_from(ao_send_acq_t * x, ao_time_t timeout, ao_time_t beginning);
```

Sends an acquired memory block in a blocking fashion with a timeout and an optional beginning.

## `ao_send_acq_forever`

```c
void ao_send_acq_forever(ao_send_acq_t * x);
```

Sends an acquired memory block indefinitely in a blocking fashion.

## `ao_send_acq_try`

```c
void ao_send_acq_try(ao_send_acq_t * x);
```

Sends an acquired memory block in a non-blocking fashion.

## `ao_send_acq_begin`
## `ao_send_acq_end`

```c
void ao_send_acq_begin(ao_send_acq_t * x);
void ao_send_acq_end  (ao_send_acq_t * x);
```

Begins or ends, respectively, a sending of an acquired memory block.
