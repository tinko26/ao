---
author: "Stefan Wagner"
date: 2022-09-09
draft: true
groups:
- priority-queues
permalink: /avl-trees/
seealso:
- /api/src/ao/ao_avl.h/
toc: true
---

# Usage

Trees and nodes must be initialized prior to being used. A node can be initialized by clearing all of its members.

```c
ao_avl_node_t * n;
```

```c
n->height = 0;
n->left = NULL;
n->parent = NULL;
n->right = NULL;
```

A tree can be initialized by clearing all of its members, too.

```c
ao_avl_t * a;
```

```c
a->less = NULL;
a->less_parameter = NULL;
a->root = NULL;
```

However, prior to inserting nodes, a compare function must be set.

```c
bool compare(ao_avl_node_t * n1, ao_avl_node_t * n2, void * p)
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
a->less = compare;
```
