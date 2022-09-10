---
author: "Stefan Wagner"
date: 2022-09-10
draft: true
permalink: /stacks/
seealso:
- /api/src/ao_sys/ao_stack.h/
toc: true
---

# Usage

Before using the stack for a thread of execution, it must be filled with a pattern.

```c
uint8_t stack[1024];
```

```c
ao_stack_fill(stack, 1024);
```

Then, after the respective thread of execution has been running for a while, the size that has actually been used can be measured.

```c
size_t h = ao_stack_get_high_water_mark(stack, 1024);
```
