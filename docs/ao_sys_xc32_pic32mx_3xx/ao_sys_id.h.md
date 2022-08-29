---
api: true
author: "Stefan Wagner"
date: 2022-08-29
description: "The ao_sys_xc32_pic32mx_3xx/ao_sys_id.h module of the ao real-time operating system."
draft: true
permalink: /ao_sys_xc32_pic32mx_3xx/ao_sys_id.h/ 
subtitle: "ao_sys_xc32_pic32mx_3xx"
title: "ao_sys_id.h"
toc: true
---

```c
#include <xc.h>

#ifndef ao_sys_id_device

#define ao_sys_id_device()      (DEVIDbits.DEVID)

#endif

#ifndef ao_sys_id_revision

#define ao_sys_id_revision()    (DEVIDbits.VER)

#endif

#ifndef AO_SYS_ID_REVISION_B2

#define AO_SYS_ID_REVISION_B2   (3)

#endif

#ifndef AO_SYS_ID_REVISION_B3

#define AO_SYS_ID_REVISION_B3   (4)

#endif

#ifndef AO_SYS_ID_REVISION_B4

#define AO_SYS_ID_REVISION_B4   (5)

#endif

#ifndef AO_SYS_ID_REVISION_B6

#define AO_SYS_ID_REVISION_B6   (5)

#endif

#ifndef AO_SYS_ID_REVISION_C0

#define AO_SYS_ID_REVISION_C0   (6)

#endif

#ifndef ao_sys_id_user

#define ao_sys_id_user()        (DEVCFG3bits.USERID)

#endif

```
