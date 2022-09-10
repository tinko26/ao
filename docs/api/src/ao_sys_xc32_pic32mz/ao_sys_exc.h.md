---
author: "Stefan Wagner"
date: 2022-08-29
draft: true
permalink: /api/src/ao_sys_xc32_pic32mz/ao_sys_exc.h/
toc: true
---

# Types

## `ao_sys_exc_t`

```c
typedef enum ao_sys_exc_t ao_sys_exc_t;
```

```c
enum ao_sys_exc_t
{
    AO_SYS_EXC_INT    = 0x00,
    AO_SYS_EXC_MOD    = 0x01,
    AO_SYS_EXC_TLBL   = 0x02,
    AO_SYS_EXC_TLBS   = 0x03,
    AO_SYS_EXC_ADEL   = 0x04,
    AO_SYS_EXC_ADES   = 0x05,
    AO_SYS_EXC_IBE    = 0x06,
    AO_SYS_EXC_DBE    = 0x07,
    AO_SYS_EXC_SYS    = 0x08,
    AO_SYS_EXC_BP     = 0x09,
    AO_SYS_EXC_RI     = 0x0A,
    AO_SYS_EXC_CPU    = 0x0B,
    AO_SYS_EXC_OV     = 0x0C,
    AO_SYS_EXC_TR     = 0x0D,
    AO_SYS_EXC_FPE    = 0x0F,
    AO_SYS_EXC_TLBRI  = 0x13,
    AO_SYS_EXC_TLBEI  = 0x14,
    AO_SYS_EXC_WATCH  = 0x17,
    AO_SYS_EXC_MCHECK = 0x18,
    AO_SYS_EXC_DSPDIS = 0x1A
};
```

It consists of the following members.

| `AO_SYS_EXC_INT` | |
| `AO_SYS_EXC_MOD` | |
| `AO_SYS_EXC_TLBL` | |
| `AO_SYS_EXC_TLBS` | |
| `AO_SYS_EXC_ADEL` | |
| `AO_SYS_EXC_ADES` | |
| `AO_SYS_EXC_IBE` | |
| `AO_SYS_EXC_DBE` | |
| `AO_SYS_EXC_SYS` | |
| `AO_SYS_EXC_BP` | |
| `AO_SYS_EXC_RI` | |
| `AO_SYS_EXC_CPU` | |
| `AO_SYS_EXC_OV` | |
| `AO_SYS_EXC_TR` | |
| `AO_SYS_EXC_FPE` | |
| `AO_SYS_EXC_TLBRI` | |
| `AO_SYS_EXC_TLBEI` | |
| `AO_SYS_EXC_WATCH` | |
| `AO_SYS_EXC_MCHECK` | |
| `AO_SYS_EXC_DSPDIS` | |
