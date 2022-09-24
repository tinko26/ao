---
author: "Stefan Wagner"
date: 2022-09-22
draft: true
permalink: /api/src/ao_sys_xc32_pic32/ao_ir_int.h/
toc: true
---

# Include

| `stdbool.h` |

# Functions

## `ao_ir_int0`

```c
void ao_ir_int0_enable();
void ao_ir_int0_disable();
```

Enables or disables the interrupt.

```c
void ao_ir_int0_request();
void ao_ir_int0_reply();
```

Requests the interrupt or replies thereto.

```c
void ao_ir_int0_falling();
void ao_ir_int0_rising();
```

Sets up the interrupt to detect falling or rising edges, respectively.

```c
bool ao_ir_int0_is_enabled();
```

Checks whether the interrupt is enabled.

```c
bool ao_ir_int0_is_pending();
```

Checks whether the interrupt is pending.

```c
bool ao_ir_int0_is_falling();
bool ao_ir_int0_is_rising();
```

Checks whether the interrupt detects falling or rising edges, respectively.

## `ao_ir_int1`

```c
void ao_ir_int1_enable();
void ao_ir_int1_disable();
```

Enables or disables the interrupt.

```c
void ao_ir_int1_request();
void ao_ir_int1_reply();
```

Requests the interrupt or replies thereto.

```c
void ao_ir_int1_falling();
void ao_ir_int1_rising();
```

Sets up the interrupt to detect falling or rising edges, respectively.

```c
bool ao_ir_int1_is_enabled();
```

Checks whether the interrupt is enabled.

```c
bool ao_ir_int1_is_pending();
```

Checks whether the interrupt is pending.

```c
bool ao_ir_int1_is_falling();
bool ao_ir_int1_is_rising();
```

Checks whether the interrupt detects falling or rising edges, respectively.

## `ao_ir_int2`

```c
void ao_ir_int2_enable();
void ao_ir_int2_disable();
```

Enables or disables the interrupt.

```c
void ao_ir_int2_request();
void ao_ir_int2_reply();
```

Requests the interrupt or replies thereto.

```c
void ao_ir_int2_falling();
void ao_ir_int2_rising();
```

Sets up the interrupt to detect falling or rising edges, respectively.

```c
bool ao_ir_int2_is_enabled();
```

Checks whether the interrupt is enabled.

```c
bool ao_ir_int2_is_pending();
```

Checks whether the interrupt is pending.

```c
bool ao_ir_int2_is_falling();
bool ao_ir_int2_is_rising();
```

Checks whether the interrupt detects falling or rising edges, respectively.

## `ao_ir_int3`

```c
void ao_ir_int3_enable();
void ao_ir_int3_disable();
```

Enables or disables the interrupt.

```c
void ao_ir_int3_request();
void ao_ir_int3_reply();
```

Requests the interrupt or replies thereto.

```c
void ao_ir_int3_falling();
void ao_ir_int3_rising();
```

Sets up the interrupt to detect falling or rising edges, respectively.

```c
bool ao_ir_int3_is_enabled();
```

Checks whether the interrupt is enabled.

```c
bool ao_ir_int3_is_pending();
```

Checks whether the interrupt is pending.

```c
bool ao_ir_int3_is_falling();
bool ao_ir_int3_is_rising();
```

Checks whether the interrupt detects falling or rising edges, respectively.

## `ao_ir_int4`

```c
void ao_ir_int4_enable();
void ao_ir_int4_disable();
```

Enables or disables the interrupt.

```c
void ao_ir_int4_request();
void ao_ir_int4_reply();
```

Requests the interrupt or replies thereto.

```c
void ao_ir_int4_falling();
void ao_ir_int4_rising();
```

Sets up the interrupt to detect falling or rising edges, respectively.

```c
bool ao_ir_int4_is_enabled();
```

Checks whether the interrupt is enabled.

```c
bool ao_ir_int4_is_pending();
```

Checks whether the interrupt is pending.

```c
bool ao_ir_int4_is_falling();
bool ao_ir_int4_is_rising();
```

Checks whether the interrupt detects falling or rising edges, respectively.
