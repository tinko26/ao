---
author: "Stefan Wagner"
date: 2022-09-26
draft: true
permalink: /api/src/ao_sys/ao_recv_acq.h/
toc: true
---

# Notes

This module provides an abstraction for receiving acquired memory blocks from an opaque source.

# Include

| [`ao_recv_ptr.h`](ao_recv_ptr.h.md) |
| [`ao_time.h`](ao_time.h.md) |

# Types

## `ao_recv_acq_t`

```c
typedef ao_recv_ptr_t ao_recv_acq_t;
```

Represents the receiving of an acquired memory block.

## `ao_recv_acq_proc_t`

```c
typedef ao_recv_ptr_proc_t ao_recv_acq_proc_t;
```

Represents a function beginning or ending a receiving of an acquired memory block.

# Functions

## `ao_recv_acq`
## `ao_recv_acq_from`

```c
void ao_recv_acq     (ao_recv_acq_t * r, ao_time_t timeout);
void ao_recv_acq_from(ao_recv_acq_t * r, ao_time_t timeout, ao_time_t beginning);
```

Receives an acquired memory block in a blocking fashion with a timeout and an optional beginning.

## `ao_recv_acq_forever`

```c
void ao_recv_acq_forever(ao_recv_acq_t * r);
```

Receives an acquired memory block indefinitely in a blocking fashion.

## `ao_recv_acq_try`

```c
void ao_recv_acq_try(ao_recv_acq_t * r);
```

Receives an acquired memory block in a non-blocking fashion.

## `ao_recv_acq_begin`
## `ao_recv_acq_end`

```c
void ao_recv_acq_begin(ao_recv_acq_t * r);
void ao_recv_acq_end  (ao_recv_acq_t * r);
```

Begins or ends, respectively, a receiving of an acquired memory block.
