---
api: true
author: "Stefan Wagner"
date: 2022-08-29
description: "The ao_sys_xc32_pic32mk_gpk/ao_sys_id.h module of the ao real-time operating system."
draft: true
permalink: /ao_sys_xc32_pic32mk_gpk/ao_sys_id.h/ 
subtitle: ""
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

#ifndef ao_sys_id_user

#define ao_sys_id_user()        (DEVCFG3bits.USERID)

#endif

```
