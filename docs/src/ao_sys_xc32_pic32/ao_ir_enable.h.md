---
api: true
author: "Stefan Wagner"
date: 2022-08-29
description: "The /src/ao_sys_xc32_pic32/ao_ir_enable.h file of the ao real-time operating system."
draft: true
permalink: /src/ao_sys_xc32_pic32/ao_ir_enable.h/ 
subtitle: ""
title: "ao_ir_enable.h"
toc: true
---

# Overview

...

# Includes

```c
#ifndef ao_ir_disable

#define ao_ir_disable()     __builtin_disable_interrupts()

#endif

#ifndef ao_ir_enable

#define ao_ir_enable()      __builtin_enable_interrupts()

#endif

```
