---
api: true
author: "Stefan Wagner"
date: 2022-08-29
description: "The /src/ao_sys_xc32_pic32/ao_ir_stack.h file of the ao real-time operating system."
draft: true
permalink: /api/src/ao_sys_xc32_pic32/ao_ir_stack.h/
subtitle: ""
title: "ao_ir_stack.h"
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

# Constants

```c
#define AO_IR_STACK_DEPTH_MAX (false)
```

```c
#define AO_IR_STACK_FILL (false)
```

```c
#define AO_IR_STACK_SIZE (4096)
```

```c
#define AO_IR_STACK_SIZE_ALIGNED AO_ALIGN_UP(AO_IR_STACK_SIZE, AO_STACK_ALIGN)
```

```c
#define AO_IR_STACK_SIZE_AS (24)
```

# Types

## `ao_ir_stack_t`

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
    size_t high_water_mark;
#endif
};
```

Members:

| `depth` | |
| `depth_max` | |
| `fp_backup` | |
| `high_water_mark` | |
| `sp` | |
| `sp_backup` | |

# Functions

```c
void * ao_ir_stack_func0( ao_func0_t f);
```

```c
void * ao_ir_stack_func1( void * p1, ao_func1_t f);
```

```c
void * ao_ir_stack_func2( void * p1, void * p2, ao_func2_t f);
```

```c
void * ao_ir_stack_func3( void * p1, void * p2, void * p3, ao_func3_t f);
```

```c
void ao_ir_stack_high_water_mark();
```

# Variables

```c
extern ao_ir_stack_t ao_ir_stack;
```

