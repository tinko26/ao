---
author: "Stefan Wagner"
date: 2022-09-27
draft: true
permalink: /memory-blocks/
seealso:
- /api/src/ao/ao_mem.h/
toc: true
---

# Example

A memory block can be copied to another location.

```c
char block[512];
```

```c
ao_mem_copy(block + 256, block, 256);
```

This function copies the data directly, that is, without using a temporary buffer. Therefore, the two memory blocks should not overlap. However, if that is the case, then another function can be used.

```c
ao_mem_move(block + 32 , block, 256);
```

Finally, a memory block can be filled with a constant value.

```c
ao_mem_set(block, 'a', 512);
```
