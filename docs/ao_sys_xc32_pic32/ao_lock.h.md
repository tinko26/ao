---
author: "Stefan Wagner"
date: 2022-08-29
description: "The ao_sys_xc32_pic32/ao_lock.h module of the ao real-time operating system."
draft: true
permalink: /ao_sys_xc32_pic32/ao_lock.h/ 
subtitle: "<code>ao_sys_xc32_pic32</code>"
title: "<code>ao_lock.h</code>"
toc: true
---

typedef uint32_t        ao_lock_t;

#ifndef AO_LOCK_PRIO

#define AO_LOCK_PRIO    (AO_IR_PRIO_MAX)

#endif

#ifndef ao_lock

#define ao_lock(x)      { *(x) = ao_sys_lock_ir(AO_LOCK_PRIO); }

#endif

#ifndef ao_unlock

#define ao_unlock(x)    { ao_sys_unlock_ir(*(x)); }

#endif

