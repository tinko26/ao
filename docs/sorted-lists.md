---
author: "Stefan Wagner"
date: 2022-09-09
draft: true
groups:
- priority-queues
permalink: /sorted-lists/
seealso:
- /api/src/ao/ao_slist.h/
toc: true
---

# Usage

Both lists and list nodes can be initialized by clearing their respective members.

```c
ao_slist_t * l;
```

```c
l->back = NULL;
l->front = NULL;
l->less = NULL;
l->less_parameter = NULL;
```

```c
ao_slist_node_t * n;
```

```c
n->next = NULL;
n->prev = NULL;
```

However, prior to inserting elements, a compare function must be set.

```c
bool compare(ao_slist_node_t * n1, ao_slist_node_t * n2, void * p)
{
    if (/* n1 is less than n2 */)
    {
        return true;
    }
    else
    {
        return false;
    }
}
```

```c
l->less = compare;
```
