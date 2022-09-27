---
author: "Stefan Wagner"
date: 2022-09-25
draft: true
permalink: /api/src/ao_sys_xc32_pic32mx/ao_sys_exc.h/
toc: true
---

# Identifier

```c
#define AO_SYS_EXC
```

# Types

## `ao_sys_exc_t`

```c
typedef enum ao_sys_exc_t ao_sys_exc_t;
```

Represents exception conditions.

# Enums

## `ao_sys_exc_t`

```c
enum ao_sys_exc_t
{
    AO_SYS_EXC_INT  = 0x00,
    AO_SYS_EXC_ADEL = 0x04,
    AO_SYS_EXC_ADES = 0x05,
    AO_SYS_EXC_IBE  = 0x06,
    AO_SYS_EXC_DBE  = 0x07,
    AO_SYS_EXC_SYS  = 0x08,
    AO_SYS_EXC_BP   = 0x09,
    AO_SYS_EXC_RI   = 0x0A,
    AO_SYS_EXC_CPU  = 0x0B,
    AO_SYS_EXC_OV   = 0x0C,
    AO_SYS_EXC_TR   = 0x0D
};
```

| `AO_SYS_EXC_INT` | Interrupt. |
| `AO_SYS_EXC_ADEL` | Address error. |
| `AO_SYS_EXC_ADES` | Address error. |
| `AO_SYS_EXC_IBE` | Bus error. |
| `AO_SYS_EXC_DBE` | Bus error. |
| `AO_SYS_EXC_SYS` | System call. |
| `AO_SYS_EXC_BP` | Breakpoint. |
| `AO_SYS_EXC_RI` | Reserved instruction. |
| `AO_SYS_EXC_CPU` | Coprocessor unusable. |
| `AO_SYS_EXC_OV` | Integer overflow. |
| `AO_SYS_EXC_TR` | Trap. |
