---
author: "Stefan Wagner"
date: 2022-09-20
draft: true
external:
- https://microchip.com/DS60001145 : "PIC32 Flash Programming Specification"
permalink: /api/src/ao_sys_xc32_pic32mk_gpg/ao_sys_id.h/
toc: true
---

# Include

```c
#include <xc.h>
```

# Constants

## `AO_SYS_ID_REVISION`

```c
#define AO_SYS_ID_REVISION_A1 (1)
```

The possible revision IDs.

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
