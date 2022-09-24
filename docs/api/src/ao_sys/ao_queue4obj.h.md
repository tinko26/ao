---
author: "Stefan Wagner"
date: 2022-09-13
draft: true
permalink: /api/src/ao_sys/ao_queue4obj.h/
toc: true
---

# Include

| [`ao_async.h`](ao_async.h.md) |
| [`ao_heap4obj.h`](../ao/ao_heap4obj.h.md) |
| [`ao_list.h`](../ao/ao_list.h.md) |
| [`ao_time.h`](ao_time.h.md) |
| `stdbool.h` |

# Identifier

```c
#define AO_QUEUE4OBJ
```

# Types

## `ao_queue4obj_t`

```c
typedef struct ao_queue4obj_t ao_queue4obj_t;
```

```c
struct ao_queue4obj_t
{
    ao_heap4obj_t heap;
    ao_list_t     insert;
    ao_list_t     pop;
};
```

This type represents a queue for objects. It consists of the following members.

| `heap` | The heap. |
| `insert` | The list of insertings. |
| `pop` | The list of poppings. |

## `ao_qinsert_obj_t`

```c
typedef struct ao_qinsert_obj_t ao_qinsert_obj_t;
```

```c
struct ao_qinsert_obj_t
{
    ao_async_t       async;
    ao_list_node_t   node;
    void *           ptr;
    ao_queue4obj_t * queue;
    bool volatile    result;
};
```

This type represents the inserting into a queue for objects. It consists of the following members.

| `async` | The asynchronous event. |
| `node` | The node for the queue's list of insertings. |
| `ptr` | The pointer to the object to insert. |
| `queue` | The queue. |
| `result` | The result. |

## `ao_qpop_obj_t`

```c
typedef struct ao_qpop_obj_t ao_qpop_obj_t;
```

```c
struct ao_qpop_obj_t
{
    ao_async_t       async;
    ao_list_node_t   node;
    void *           ptr;
    ao_queue4obj_t * queue;
    bool volatile    result;
};
```

This type represents the popping from a queue for objects. It consists of the following members.

| `async` | The asynchronous event. |
| `node` | The node for the queue's list of poppings. |
| `ptr` | The pointer to the location to store the popped object. |
| `queue` | The queue. |
| `result` | The result. |

# Functions

## `ao_qinsert_obj`
## `ao_qinsert_obj_from`

```c
void ao_qinsert_obj     (ao_qinsert_obj_t * x, ao_time_t timeout);
void ao_qinsert_obj_from(ao_qinsert_obj_t * x, ao_time_t timeout, ao_time_t beginning);
```

Inserts an object into a queue in a blocking fashion with a timeout and an optional beginning.

## `ao_qinsert_obj_forever`

```c
void ao_qinsert_obj_forever(ao_qinsert_obj_t * x);
```

Inserts an object into a queue indefinitely in a blocking fashion.

## `ao_qinsert_obj_try`

```c
void ao_qinsert_obj_try(ao_qinsert_obj_t * x);
```

Inserts an object into a queue in a non-blocking fashion.

## `ao_qinsert_obj_begin`
## `ao_qinsert_obj_end`

```c
void ao_qinsert_obj_begin(ao_qinsert_obj_t * x);
void ao_qinsert_obj_end  (ao_qinsert_obj_t * x);
```

Begins or ends, respectively, an inserting of an object into a queue.

## `ao_qpop_obj`
## `ao_qpop_obj_from`

```c
void ao_qpop_obj     (ao_qpop_obj_t * x, ao_time_t timeout);
void ao_qpop_obj_from(ao_qpop_obj_t * x, ao_time_t timeout, ao_time_t beginning);
```

Pops an object from a queue in a blocking fashion with a timeout and an optional beginning.

## `ao_qpop_obj_forever`

```c
void ao_qpop_obj_forever(ao_qpop_obj_t * x);
```

Pops an object from a queue indefinitely in a blocking fashion.

## `ao_qpop_obj_try`

```c
void ao_qpop_obj_try(ao_qpop_obj_t * x);
```

Pops an object from a queue in a non-blocking fashion.

## `ao_qpop_obj_begin`
## `ao_qpop_obj_end`

```c
void ao_qpop_obj_begin(ao_qpop_obj_t * x);
void ao_qpop_obj_end  (ao_qpop_obj_t * x);
```

Begins or ends, respectively, a popping of an object from a queue.
