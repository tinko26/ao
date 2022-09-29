---
author: "Stefan Wagner"
date: 2022-09-26
draft: true
permalink: /api/src/ao_sys/ao_queue4ptr.h/
toc: true
---

# Include

| [`ao_async.h`](ao_async.h.md) |
| [`ao_heap4ptr.h`](../ao/ao_heap4ptr.h.md) |
| [`ao_list.h`](../ao/ao_list.h.md) |
| [`ao_time.h`](ao_time.h.md) |
| `stdbool.h` |

# Types

## `ao_queue4ptr_t`

```c
typedef struct ao_queue4ptr_t ao_queue4ptr_t;
```

Represents a queue for pointers.

## `ao_qinsert_ptr_t`

```c
typedef struct ao_qinsert_ptr_t ao_qinsert_ptr_t;
```

Represents the inserting into a queue for pointers.

## `ao_qpop_ptr_t`

```c
typedef struct ao_qpop_ptr_t ao_qpop_ptr_t;
```

Represents the popping from a queue for pointers.

# Structs

## `ao_queue4ptr_t`

```c
struct ao_queue4ptr_t
{
    ao_heap4ptr_t heap;
    ao_list_t     insert;
    ao_list_t     pop;
};
```

| `heap` | The heap. |
| `insert` | The list of insertings. |
| `pop` | The list of poppings. |

## `ao_qinsert_ptr_t`

```c
struct ao_qinsert_ptr_t
{
    ao_async_t       async;
    void *           ptr;
    ao_queue4ptr_t * queue;
    ao_list_node_t   queue_insert_node;
    bool volatile    result;
};
```

| `async` | The asynchronous event. |
| `ptr` | The pointer to insert. |
| `queue` | The queue. |
| `queue_insert_node` | The node for the queue's list of insertings. |
| `result` | The result. |

## `ao_qpop_ptr_t`

```c
struct ao_qpop_ptr_t
{
    ao_async_t       async;
    void * volatile  ptr;
    ao_queue4ptr_t * queue;
    ao_list_node_t   queue_pop_node;
    bool   volatile  result;
};
```

| `async` | The asynchronous event. |
| `ptr` | The pointer that has been popped. |
| `queue` | The queue. |
| `queue_pop_node` | The node for the queue's list of poppings. |
| `result` | The result. |

# Functions

## `ao_qinsert_ptr`
## `ao_qinsert_ptr_from`

```c
void ao_qinsert_ptr     (ao_qinsert_ptr_t * i, ao_time_t timeout);
void ao_qinsert_ptr_from(ao_qinsert_ptr_t * i, ao_time_t timeout, ao_time_t beginning);
```

Inserts a pointer into a queue in a blocking fashion with a timeout and an optional beginning.

## `ao_qinsert_ptr_forever`

```c
void ao_qinsert_ptr_forever(ao_qinsert_ptr_t * i);
```

Inserts a pointer into a queue indefinitely in a blocking fashion.

## `ao_qinsert_ptr_try`

```c
void ao_qinsert_ptr_try(ao_qinsert_ptr_t * i);
```

Inserts a pointer into a queue in a non-blocking fashion.

## `ao_qinsert_ptr_begin`
## `ao_qinsert_ptr_end`

```c
void ao_qinsert_ptr_begin(ao_qinsert_ptr_t * i);
void ao_qinsert_ptr_end  (ao_qinsert_ptr_t * i);
```

Begins or ends, respectively, an inserting of a pointer into a queue.

## `ao_qpop_ptr`
## `ao_qpop_ptr_from`

```c
void ao_qpop_ptr     (ao_qpop_ptr_t * p, ao_time_t timeout);
void ao_qpop_ptr_from(ao_qpop_ptr_t * p, ao_time_t timeout, ao_time_t beginning);
```

Pops a pointer from a queue in a blocking fashion with a timeout and an optional beginning.

## `ao_qpop_ptr_forever`

```c
void ao_qpop_ptr_forever(ao_qpop_ptr_t * p);
```

Pops a pointer from a queue indefinitely in a blocking fashion.

## `ao_qpop_ptr_try`

```c
void ao_qpop_ptr_try(ao_qpop_ptr_t * p);
```

Pops a pointer from a queue in a non-blocking fashion.

## `ao_qpop_ptr_begin`
## `ao_qpop_ptr_end`

```c
void ao_qpop_ptr_begin(ao_qpop_ptr_t * p);
void ao_qpop_ptr_end  (ao_qpop_ptr_t * p);
```

Begins or ends, respectively, a popping of a pointer from a queue.
