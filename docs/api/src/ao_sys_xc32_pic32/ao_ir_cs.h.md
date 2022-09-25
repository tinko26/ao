---
author: "Stefan Wagner"
date: 2022-09-25
draft: true
permalink: /api/src/ao_sys_xc32_pic32/ao_ir_cs.h/
toc: true
---

# Include

| `stdbool.h` |

# Identifier

```c
#define AO_IR_CS
```

# Functions

## `ao_ir_cs0_*`

```c
void ao_ir_cs0_enable();
void ao_ir_cs0_disable();
```

Enables or disables the interrupt.

```c
void ao_ir_cs0_request();
void ao_ir_cs0_reply();
```

Requests the interrupt or replies thereto.

```c
bool ao_ir_cs0_is_enabled();
```

Checks whether the interrupt is enabled.

```c
bool ao_ir_cs0_is_pending();
```

Checks whether the interrupt is pending.

## `ao_ir_cs1_*`

```c
void ao_ir_cs1_enable();
void ao_ir_cs1_disable();
```

Enables or disables the interrupt.

```c
void ao_ir_cs1_request();
void ao_ir_cs1_reply();
```

Requests the interrupt or replies thereto.

```c
bool ao_ir_cs1_is_enabled();
```

Checks whether the interrupt is enabled.

```c
bool ao_ir_cs1_is_pending();
```

Checks whether the interrupt is pending.
