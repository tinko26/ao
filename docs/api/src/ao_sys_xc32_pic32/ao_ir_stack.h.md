---
author: "Stefan Wagner"
date: 2022-09-05
draft: true
permalink: /api/src/ao_sys_xc32_pic32/ao_ir_stack.h/
toc: true
---

# Include

```c
#include <ao_align.h>
#include <ao_func.h>
#include <ao_stack.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
```

# Typedefs

```c
typedef struct ao_ir_stack_t ao_ir_stack_t;
```

# Configuration

Keep track of the maximum depth.

```c
#define AO_IR_STACK_DEPTH_MAX (false)
```

Keep track of the high water mark.

```c
#define AO_IR_STACK_FILL      (false)
```

The size of the interrupt stack, in bytes.

```c
#define AO_IR_STACK_SIZE      (4096)
```

# Constants

The aligned stack size, in bytes.

```c
#define AO_IR_STACK_SIZE_ALIGNED AO_ALIGN_UP(AO_IR_STACK_SIZE, AO_STACK_ALIGN)
```

The size of the argument section, in bytes.

```c
#define AO_IR_STACK_SIZE_AS     (24)
```

# Types

## `ao_ir_stack_t`

This type represents the interrupt stack.

```c
struct ao_ir_stack_t
{
uint32_t sp;
uint32_t sp_backup;
uint32_t fp_backup;
uint32_t depth;

#if AO_IR_STACK_DEPTH_MAX

uint32_t depth_max;

#endif

#if AO_IR_STACK_FILL

size_t   high_water_mark;

#endif

};
```

It consists of the following members.

| `depth` | The current depth. |
| `depth_max` | The maximum depth. |
| `fp_backup` | The frame pointer backup. |
| `high_water_mark` | The high water mark, in bytes. |
| `sp` | The stack pointer. |
| `sp_backup` | The stack pointer backup. |

# Functions

Execute function `f` on the interrupt stack.

```c
void * ao_ir_stack_func0(ao_func0_t f);
void * ao_ir_stack_func1(void * p1, ao_func1_t f);
void * ao_ir_stack_func2(void * p1, void * p2, ao_func2_t f);
void * ao_ir_stack_func3(void * p1, void * p2, void * p3, ao_func3_t f);
```

Measure the high water mark of the interrupt stack.

```c
void ao_ir_stack_high_water_mark();
```

# Variables

The interrupt stack.

```c
extern ao_ir_stack_t ao_ir_stack;
```
