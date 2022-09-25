---
author: "Stefan Wagner"
date: 2022-09-25
draft: true
permalink: /api/src/ao_sys/ao_stream4acq.h/
toc: true
---

# Include

| [`ao_stream4ptr.h`](ao_stream4ptr.h.md) |
| [`ao_time.h`](ao_time.h.md) |

# Identifier

```c
#define AO_STREAM4ACQ
```

# Types

## `ao_stream4acq_t`

```c
typedef ao_stream4ptr_t ao_stream4acq_t;
```

This type represents a stream for acquired memory blocks.

## `ao_spop_acq_t`

```c
typedef ao_spop_ptr_t ao_spop_acq_t;
```

This type represents the popping of an acquired memory block from a stream.

## `ao_spush_acq_t`

```c
typedef ao_spush_ptr_t ao_spush_acq_t;
```

This type represents the pushing of an acquired memory block to a stream.

# Functions

## `ao_spop_acq`
## `ao_spop_acq_from`

```c
void ao_spop_acq     (ao_spop_acq_t * x, ao_time_t timeout);
void ao_spop_acq_from(ao_spop_acq_t * x, ao_time_t timeout, ao_time_t beginning);
```

Pops an acquired memory block from a stream in a blocking fashion with a timeout and an optional beginning.

## `ao_spop_acq_forever`

```c
void ao_spop_acq_forever(ao_spop_acq_t * x);
```

Pops an acquired memory block from a stream indefinitely in a blocking fashion.

## `ao_spop_acq_try`

```c
void ao_spop_acq_try(ao_spop_acq_t * x);
```

Pops an acquired memory block from a stream in a non-blocking fashion.

## `ao_spop_acq_begin`
## `ao_spop_acq_end`

```c
void ao_spop_acq_begin(ao_spop_acq_t * x);
void ao_spop_acq_end  (ao_spop_acq_t * x);
```

Begins or ends, respectively, a popping of an acquired memory block from a stream.

## `ao_spush_acq`
## `ao_spush_acq_from`

```c
void ao_spush_acq     (ao_spush_acq_t * x, ao_time_t timeout);
void ao_spush_acq_from(ao_spush_acq_t * x, ao_time_t timeout, ao_time_t beginning);
```

Pushes an acquired memory block to a stream in a blocking fashion with a timeout and an optional beginning.

## `ao_spush_acq_forever`

```c
void ao_spush_acq_forever(ao_spush_acq_t * x);
```

Pushes an acquired memory block to a stream indefinitely in a blocking fashion.

## `ao_spush_acq_try`

```c
void ao_spush_acq_try(ao_spush_acq_t * x);
```

Pushes an acquired memory block to a stream in a non-blocking fashion.

## `ao_spush_acq_begin`
## `ao_spush_acq_end`

```c
void ao_spush_acq_begin(ao_spush_acq_t * x);
void ao_spush_acq_end  (ao_spush_acq_t * x);
```

Begins or ends, respectively, a pushing of an acquired memory block to a stream.

## `ao_spush_acq_override`

```c
void ao_spush_acq_override(ao_spush_acq_t * x);
```

Pushes an acquired memory block to a stream in a non-blocking fashion. If the stream is full, then this function overrides and releases the oldest memory block in the stream.
