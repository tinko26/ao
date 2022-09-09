---
author: "Stefan Wagner"
date: 2022-09-09
draft: true
external:
- https://en.wikipedia.org/wiki/Circular_buffer : "Circular buffer"
- https://en.wikipedia.org/wiki/Data_buffer : "Data buffer"
permalink: /buffers-for-pointers/
seealso:
- /api/src/ao/ao_buffer4ptr.h/
toc: false
---

# Usage

A pointer buffer can be initialized by clearing all of its members.

```c
ao_buffer4ptr_t * b;
```

```c
b->capacity = 0;
b->count = 0;
b->count_max = 0;
b->front = 0;
b->store = NULL;
```

However, such a buffer is not very useful, since it cannot store a single pointer. Therefore, it should be equipped with a store.

```c
void * store[128];
```

```c
b->capacity = 128;
b->store = store;
```
