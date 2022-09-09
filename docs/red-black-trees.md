---
author: "Stefan Wagner"
date: 2022-09-09
draft: true
groups:
- priority-queues
permalink: /red-black-trees/
seealso:
- /api/src/ao/ao_rb.h/
toc: true
---

# Usage

Trees and nodes must be initialized prior to being used. A node can be initialized by clearing all of its members.

```c
ao_rb_node_t * n;
```

```c
n->black = false;
n->left = NULL;
n->parent = NULL;
n->right = NULL;
```

A tree can be initialized by clearing all of its members, too.

```c
ao_rb_t * r;
```

```c
r->less = NULL;
r->less_parameter = NULL;
r->root = NULL;
```

However, prior to inserting nodes, a compare function must be set.

```c
bool compare(ao_rb_node_t * n1, ao_rb_node_t * n2, void * p)
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
r->less = compare;
```
