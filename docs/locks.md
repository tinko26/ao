---
author: "Stefan Wagner"
date: 2022-09-10
draft: true
permalink: /locks/
seealso:
- /api/src/ao_sys/ao_lock.h/
toc: true
---

# Usage

```c
ao_lock_t * l;
```

```c
ao_lock(l);
{
    // Critical section.
}
ao_unlock(l);
```
