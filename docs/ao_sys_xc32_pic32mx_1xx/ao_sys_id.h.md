---
author: "Stefan Wagner"
date: 2022-08-29
description: "The ao_sys_xc32_pic32mx_1xx/ao_sys_id.h module of the ao real-time operating system."
draft: true
permalink: /ao_sys_xc32_pic32mx_1xx/ao_sys_id.h/ 
subtitle: "<code>ao_sys_xc32_pic32mx_1xx</code>"
title: "<code>ao_sys_id.h</code>"
toc: true
---

#ifndef ao_sys_id_device

#define ao_sys_id_device()      (DEVIDbits.DEVID)

#endif

#ifndef ao_sys_id_revision

#define ao_sys_id_revision()    (DEVIDbits.VER)

#endif

#ifndef AO_SYS_ID_REVISION_A0

#define AO_SYS_ID_REVISION_A0   (0)

#endif

#ifndef AO_SYS_ID_REVISION_A1

#define AO_SYS_ID_REVISION_A1   (1)

#endif

#ifndef ao_sys_id_user

#define ao_sys_id_user()        (DEVCFG3bits.USERID)

#endif

