---
author: "Stefan Wagner"
date: 2022-09-24
draft: true
permalink: /api/src/ao_sys_xc32_pic32_can/ao_ir_can.h/
toc: true
---

# Include

| `stdbool.h` |

# Identifier

```c
#define AO_IR_CAN
```

# Functions

## `ao_ir_can1`

```c
void ao_ir_can1_enable();
void ao_ir_can1_disable();
```

Enables or disables the interrupt.

```c
void ao_ir_can1_request();
void ao_ir_can1_reply();
```

Requests the interrupt or replies thereto.

```c
bool ao_ir_can1_is_enabled();
```

Checks whether the interrupt is enabled.

```c
bool ao_ir_can1_is_pending();
```

Checks whether the interrupt is pending.

## `ao_ir_can2`

```c
void ao_ir_can2_enable();
void ao_ir_can2_disable();
```

Enables or disables the interrupt.

```c
void ao_ir_can2_request();
void ao_ir_can2_reply();
```

Requests the interrupt or replies thereto.

```c
bool ao_ir_can2_is_enabled();
```

Checks whether the interrupt is enabled.

```c
bool ao_ir_can2_is_pending();
```

Checks whether the interrupt is pending.

## `ao_ir_can3`

```c
void ao_ir_can3_enable();
void ao_ir_can3_disable();
```

Enables or disables the interrupt.

```c
void ao_ir_can3_request();
void ao_ir_can3_reply();
```

Requests the interrupt or replies thereto.

```c
bool ao_ir_can3_is_enabled();
```

Checks whether the interrupt is enabled.

```c
bool ao_ir_can3_is_pending();
```

Checks whether the interrupt is pending.

## `ao_ir_can4`

```c
void ao_ir_can4_enable();
void ao_ir_can4_disable();
```

Enables or disables the interrupt.

```c
void ao_ir_can4_request();
void ao_ir_can4_reply();
```

Requests the interrupt or replies thereto.

```c
bool ao_ir_can4_is_enabled();
```

Checks whether the interrupt is enabled.

```c
bool ao_ir_can4_is_pending();
```

Checks whether the interrupt is pending.
