---
author: "Stefan Wagner"
date: 2022-09-05
draft: true
permalink: /api/src/ao_sys_xc32_pic32/ao_ir_stack.h/
toc: true
---

# Include

| [`ao_align.h`](../ao/ao_align.h.md) |
| [`ao_func.h`](../ao/ao_func.h.md) |
| [`ao_stack.h`](ao_stack.h.md) |
| `stdbool.h` |
| `stddef.h` |
| `stdint.h` |

# Configuration

## `AO_IR_STACK_DEPTH_MAX`

```c
#define AO_IR_STACK_DEPTH_MAX (false)
```

Defines whether to keep track of the maximum depth.

## `AO_IR_STACK_FILL`

```c
#define AO_IR_STACK_FILL (false)
```

Defines whether to keep track of the high water mark.

## `AO_IR_STACK_SIZE`

```c
#define AO_IR_STACK_SIZE (4096)
```

The size of the interrupt stack, in bytes.

# Constants

## `AO_IR_STACK_SIZE_ALIGNED`

```c
#define AO_IR_STACK_SIZE_ALIGNED AO_ALIGN_UP(AO_IR_STACK_SIZE, AO_STACK_ALIGN)
```

The aligned stack size, in bytes.

## `AO_IR_STACK_SIZE_AS`

```c
#define AO_IR_STACK_SIZE_AS (24)
```

The size of the argument section, in bytes.

# Types

## `ao_ir_stack_t`

```c
typedef struct ao_ir_stack_t ao_ir_stack_t;
```

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

This type represents the interrupt stack. It consists of the following members.

| `depth` | The current depth. |
| `depth_max` | The maximum depth. |
| `fp_backup` | The frame pointer backup. |
| `high_water_mark` | The high water mark, in bytes. |
| `sp` | The stack pointer. |
| `sp_backup` | The stack pointer backup. |

# Functions

## `ao_ir_stack_func0`
## `ao_ir_stack_func1`
## `ao_ir_stack_func2`
## `ao_ir_stack_func3`

```c
void * ao_ir_stack_func0(ao_func0_t f);
void * ao_ir_stack_func1(void * p1, ao_func1_t f);
void * ao_ir_stack_func2(void * p1, void * p2, ao_func2_t f);
void * ao_ir_stack_func3(void * p1, void * p2, void * p3, ao_func3_t f);
```

Executes function `f` on the interrupt stack.

## `ao_ir_stack_high_water_mark`

```c
void ao_ir_stack_high_water_mark();
```

Measures the high water mark of the interrupt stack.

# Variables

## `ao_ir_stack`

```c
extern ao_ir_stack_t ao_ir_stack;
```

The interrupt stack.
