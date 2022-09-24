---
author: "Stefan Wagner"
date: 2022-09-22
draft: true
external:
- https://microchip.com/DS60001145 : "PIC32 Flash Programming Specification"
permalink: /api/src/ao_sys_xc32_pic32/ao_sys_id.h/
toc: true
---

# Include

`xc.h`

# Functions

## `ao_sys_id_device`

```c
#define ao_sys_id_device() \
(                          \
    DEVIDbits.DEVID        \
)
```

Gets the 28-bit device ID.

## `ao_sys_id_revision`

```c
#define ao_sys_id_revision() \
(                            \
    DEVIDbits.VER            \
)
```

Gets the 4-bit revision ID.

## `ao_sys_id_user`

```c
#define ao_sys_id_user() \
(                        \
    DEVCFG3bits.USERID   \
)
```

Gets the configured 16-bit user ID.
