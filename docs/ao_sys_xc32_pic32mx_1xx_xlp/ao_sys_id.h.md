---
api: true
author: "Stefan Wagner"
date: 2022-08-29
description: "The ao_sys_xc32_pic32mx_1xx_xlp/ao_sys_id.h module of the ao real-time operating system."
draft: true
permalink: /ao_sys_xc32_pic32mx_1xx_xlp/ao_sys_id.h/ 
subtitle: ""
title: "ao_sys_id.h"
toc: true
---

# Overview

...

# Includes

```c
#include <xc.h>

#ifndef ao_sys_id_device

#define ao_sys_id_device()      (DEVIDbits.DEVID)

#endif

#ifndef ao_sys_id_revision

#define ao_sys_id_revision()    (DEVIDbits.VER)

#endif

#ifndef AO_SYS_ID_REVISION_A1

#define AO_SYS_ID_REVISION_A1   (1)

#endif

#ifndef AO_SYS_ID_REVISION_A3

#define AO_SYS_ID_REVISION_A3   (3)

#endif

#ifndef ao_sys_id_user

#define ao_sys_id_user()        (DEVCFG3bits.USERID)

#endif

```
