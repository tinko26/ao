---
author: "Stefan Wagner"
date: 2022-09-22
draft: true
permalink: /api/src/ao_sys_xc32_pic32mx_3xx/ao_ir_int.h/
toc: true
---

# Include

`stdbool.h` <br/>
`sys/attribs.h` <br/>
`xc.h`

# Configuration

## `AO_IR_INT0`

```c
#define AO_IR_INT0_ATTRIBUTE __ISR(_EXTERNAL_0_VECTOR, IPL4SOFT)
```

The interrupt handler attribute.

```c
#define AO_IR_INT0_PRIO    (4)
#define AO_IR_INT0_SUBPRIO (0)
```

The interrupt priority and subpriority.

## `AO_IR_INT1`

```c
#define AO_IR_INT1_ATTRIBUTE __ISR(_EXTERNAL_1_VECTOR, IPL4SOFT)
```

The interrupt handler attribute.

```c
#define AO_IR_INT1_PRIO    (4)
#define AO_IR_INT1_SUBPRIO (0)
```

The interrupt priority and subpriority.

## `AO_IR_INT2`

```c
#define AO_IR_INT2_ATTRIBUTE __ISR(_EXTERNAL_2_VECTOR, IPL4SOFT)
```

The interrupt handler attribute.

```c
#define AO_IR_INT2_PRIO    (4)
#define AO_IR_INT2_SUBPRIO (0)
```

The interrupt priority and subpriority.

## `AO_IR_INT3`

```c
#define AO_IR_INT3_ATTRIBUTE __ISR(_EXTERNAL_3_VECTOR, IPL4SOFT)
```

The interrupt handler attribute.

```c
#define AO_IR_INT3_PRIO    (4)
#define AO_IR_INT3_SUBPRIO (0)
```

The interrupt priority and subpriority.

## `AO_IR_INT4`

```c
#define AO_IR_INT4_ATTRIBUTE __ISR(_EXTERNAL_4_VECTOR, IPL4SOFT)
```

The interrupt handler attribute.

```c
#define AO_IR_INT4_PRIO    (4)
#define AO_IR_INT4_SUBPRIO (0)
```

The interrupt priority and subpriority.

# Functions

## `ao_ir_int0`

```c
#define ao_ir_int0_enable()  { IEC0SET = _IEC0_INT0IE_MASK; }
#define ao_ir_int0_disable() { IEC0CLR = _IEC0_INT0IE_MASK; }
```

Enables or disables the interrupt.

```c
#define ao_ir_int0_request() { IFS0SET = _IFS0_INT0IF_MASK; }
#define ao_ir_int0_reply()   { IFS0CLR = _IFS0_INT0IF_MASK; }
```

Requests the interrupt or replies thereto.

```c
#define ao_ir_int0_falling() { INTCONCLR = _INTCON_INT0EP_MASK; }
#define ao_ir_int0_rising()  { INTCONSET = _INTCON_INT0EP_MASK; }
```

Sets up the interrupt to detect falling or rising edges, respectively.

```c
#define ao_ir_int0_is_enabled() \
(                               \
    (IEC0 & _IEC0_INT0IE_MASK)  \
    ? true                      \
    : false                     \
)
```

Checks whether the interrupt is enabled.

```c
#define ao_ir_int0_is_pending() \
(                               \
    (IFS0 & _IFS0_INT0IF_MASK)  \
    ? true                      \
    : false                     \
)
```

Checks whether the interrupt is pending.

```c
#define ao_ir_int0_is_falling() ((INTCON & _INTCON_INT0EP_MASK) ? false : true )
#define ao_ir_int0_is_rising()  ((INTCON & _INTCON_INT0EP_MASK) ? true  : false)
```

Checks whether the interrupt detects falling or rising edges, respectively.

## `ao_ir_int1`

```c
#define ao_ir_int1_enable()  { IEC0SET = _IEC0_INT1IE_MASK; }
#define ao_ir_int1_disable() { IEC0CLR = _IEC0_INT1IE_MASK; }
```

Enables or disables the interrupt.

```c
#define ao_ir_int1_request() { IFS0SET = _IFS0_INT1IF_MASK; }
#define ao_ir_int1_reply()   { IFS0CLR = _IFS0_INT1IF_MASK; }
```

Requests the interrupt or replies thereto.

```c
#define ao_ir_int1_falling() { INTCONCLR = _INTCON_INT1EP_MASK; }
#define ao_ir_int1_rising()  { INTCONSET = _INTCON_INT1EP_MASK; }
```

Sets up the interrupt to detect falling or rising edges, respectively.

```c
#define ao_ir_int1_is_enabled() \
(                               \
    (IEC0 & _IEC0_INT1IE_MASK)  \
    ? true                      \
    : false                     \
)
```

Checks whether the interrupt is enabled.

```c
#define ao_ir_int1_is_pending() \
(                               \
    (IFS0 & _IFS0_INT1IF_MASK)  \
    ? true                      \
    : false                     \
)
```

Checks whether the interrupt is pending.

```c
#define ao_ir_int1_is_falling() ((INTCON & _INTCON_INT1EP_MASK) ? false : true )
#define ao_ir_int1_is_rising()  ((INTCON & _INTCON_INT1EP_MASK) ? true  : false)
```

Checks whether the interrupt detects falling or rising edges, respectively.

## `ao_ir_int2`

```c
#define ao_ir_int2_enable()  { IEC0SET = _IEC0_INT2IE_MASK; }
#define ao_ir_int2_disable() { IEC0CLR = _IEC0_INT2IE_MASK; }
```

Enables or disables the interrupt.

```c
#define ao_ir_int2_request() { IFS0SET = _IFS0_INT2IF_MASK; }
#define ao_ir_int2_reply()   { IFS0CLR = _IFS0_INT2IF_MASK; }
```

Requests the interrupt or replies thereto.

```c
#define ao_ir_int2_falling() { INTCONCLR = _INTCON_INT2EP_MASK; }
#define ao_ir_int2_rising()  { INTCONSET = _INTCON_INT2EP_MASK; }
```

Sets up the interrupt to detect falling or rising edges, respectively.

```c
#define ao_ir_int2_is_enabled() \
(                               \
    (IEC0 & _IEC0_INT2IE_MASK)  \
    ? true                      \
    : false                     \
)
```

Checks whether the interrupt is enabled.

```c
#define ao_ir_int2_is_pending() \
(                               \
    (IFS0 & _IFS0_INT2IF_MASK)  \
    ? true                      \
    : false                     \
)
```

Checks whether the interrupt is pending.

```c
#define ao_ir_int2_is_falling() ((INTCON & _INTCON_INT2EP_MASK) ? false : true )
#define ao_ir_int2_is_rising()  ((INTCON & _INTCON_INT2EP_MASK) ? true  : false)
```

Checks whether the interrupt detects falling or rising edges, respectively.

## `ao_ir_int3`

```c
#define ao_ir_int3_enable()  { IEC0SET = _IEC0_INT3IE_MASK; }
#define ao_ir_int3_disable() { IEC0CLR = _IEC0_INT3IE_MASK; }
```

Enables or disables the interrupt.

```c
#define ao_ir_int3_request() { IFS0SET = _IFS0_INT3IF_MASK; }
#define ao_ir_int3_reply()   { IFS0CLR = _IFS0_INT3IF_MASK; }
```

Requests the interrupt or replies thereto.

```c
#define ao_ir_int3_falling() { INTCONCLR = _INTCON_INT3EP_MASK; }
#define ao_ir_int3_rising()  { INTCONSET = _INTCON_INT3EP_MASK; }
```

Sets up the interrupt to detect falling or rising edges, respectively.

```c
#define ao_ir_int3_is_enabled() \
(                               \
    (IEC0 & _IEC0_INT3IE_MASK)  \
    ? true                      \
    : false                     \
)
```

Checks whether the interrupt is enabled.

```c
#define ao_ir_int3_is_pending() \
(                               \
    (IFS0 & _IFS0_INT3IF_MASK)  \
    ? true                      \
    : false                     \
)
```

Checks whether the interrupt is pending.

```c
#define ao_ir_int3_is_falling() ((INTCON & _INTCON_INT3EP_MASK) ? false : true )
#define ao_ir_int3_is_rising()  ((INTCON & _INTCON_INT3EP_MASK) ? true  : false)
```

Checks whether the interrupt detects falling or rising edges, respectively.

## `ao_ir_int4`

```c
#define ao_ir_int4_enable()  { IEC0SET = _IEC0_INT4IE_MASK; }
#define ao_ir_int4_disable() { IEC0CLR = _IEC0_INT4IE_MASK; }
```

Enables or disables the interrupt.

```c
#define ao_ir_int4_request() { IFS0SET = _IFS0_INT4IF_MASK; }
#define ao_ir_int4_reply()   { IFS0CLR = _IFS0_INT4IF_MASK; }
```

Requests the interrupt or replies thereto.

```c
#define ao_ir_int4_falling() { INTCONCLR = _INTCON_INT4EP_MASK; }
#define ao_ir_int4_rising()  { INTCONSET = _INTCON_INT4EP_MASK; }
```

Sets up the interrupt to detect falling or rising edges, respectively.

```c
#define ao_ir_int4_is_enabled() \
(                               \
    (IEC0 & _IEC0_INT4IE_MASK)  \
    ? true                      \
    : false                     \
)
```

Checks whether the interrupt is enabled.

```c
#define ao_ir_int4_is_pending() \
(                               \
    (IFS0 & _IFS0_INT4IF_MASK)  \
    ? true                      \
    : false                     \
)
```

Checks whether the interrupt is pending.

```c
#define ao_ir_int4_is_falling() ((INTCON & _INTCON_INT4EP_MASK) ? false : true )
#define ao_ir_int4_is_rising()  ((INTCON & _INTCON_INT4EP_MASK) ? true  : false)
```

Checks whether the interrupt detects falling or rising edges, respectively.

