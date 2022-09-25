---
author: "Stefan Wagner"
date: 2022-09-25
draft: true
permalink: /api/src/ao_sys/ao_queue4acq.h/
toc: true
---

# Include

| [`ao_queue4ptr.h`](ao_queue4ptr.h.md) |
| [`ao_time.h`](ao_time.h.md) |

# Identifier

```c
#define AO_QUEUE4ACQ
```

# Types

## `ao_queue4acq_t`

```c
typedef ao_queue4ptr_t ao_queue4acq_t;
```

This type represents a queue for acquired memory blocks.

## `ao_qinsert_acq_t`

```c
typedef ao_qinsert_ptr_t ao_qinsert_acq_t;
```

This type represents the inserting into a queue for acquired memory blocks.

## `ao_qpop_acq_t`

```c
typedef ao_qpop_ptr_t ao_qpop_acq_t;
```

This type represents the popping from a queue for acquired memory blocks.

# Functions

## `ao_qinsert_acq`
## `ao_qinsert_acq_from`

```c
void ao_qinsert_acq     (ao_qinsert_acq_t * x, ao_time_t timeout);
void ao_qinsert_acq_from(ao_qinsert_acq_t * x, ao_time_t timeout, ao_time_t beginning);
```

Inserts an acquired memory block into a queue in a blocking fashion with a timeout and an optional beginning.

## `ao_qinsert_acq_forever`

```c
void ao_qinsert_acq_forever(ao_qinsert_acq_t * x);
```

Inserts an acquired memory block into a queue indefinitely in a blocking fashion.

## `ao_qinsert_acq_try`

```c
void ao_qinsert_acq_try(ao_qinsert_acq_t * x);
```

Inserts an acquired memory block into a queue in a non-blocking fashion.

## `ao_qinsert_acq_begin`
## `ao_qinsert_acq_end`

```c
void ao_qinsert_acq_begin(ao_qinsert_acq_t * x);
void ao_qinsert_acq_end  (ao_qinsert_acq_t * x);
```

Begins or ends, respectively, an inserting of an acquired memory block into a queue.

## `ao_qpop_acq`
## `ao_qpop_acq_from`

```c
void ao_qpop_acq     (ao_qpop_acq_t * x, ao_time_t timeout);
void ao_qpop_acq_from(ao_qpop_acq_t * x, ao_time_t timeout, ao_time_t beginning);
```

Pops an acquired memory block from a queue in a blocking fashion with a timeout and an optional beginning.

## `ao_qpop_acq_forever`

```c
void ao_qpop_acq_forever(ao_qpop_acq_t * x);
```

Pops an acquired memory block from a queue indefinitely in a blocking fashion.

## `ao_qpop_acq_try`

```c
void ao_qpop_acq_try(ao_qpop_acq_t * x);
```

Pops an acquired memory block from a queue in a non-blocking fashion.

## `ao_qpop_acq_begin`
## `ao_qpop_acq_end`

```c
void ao_qpop_acq_begin(ao_qpop_acq_t * x);
void ao_qpop_acq_end  (ao_qpop_acq_t * x);
```

Begins or ends, respectively, a popping of an acquired memory block from a queue.
