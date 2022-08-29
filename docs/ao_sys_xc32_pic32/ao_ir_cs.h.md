---
api: true
author: "Stefan Wagner"
date: 2022-08-29
description: "The ao_sys_xc32_pic32/ao_ir_cs.h module of the ao real-time operating system."
draft: true
permalink: /ao_sys_xc32_pic32/ao_ir_cs.h/ 
subtitle: ""
title: "ao_ir_cs.h"
toc: true
---

# Overview

...

# Includes

```c
#include <stdbool.h>

void    ao_ir_cs0_disable();

void    ao_ir_cs0_enable();

bool    ao_ir_cs0_is_enabled();

bool    ao_ir_cs0_is_pending();

void    ao_ir_cs0_reply();

void    ao_ir_cs0_request();

void    ao_ir_cs1_disable();

void    ao_ir_cs1_enable();

bool    ao_ir_cs1_is_enabled();

bool    ao_ir_cs1_is_pending();

void    ao_ir_cs1_reply();

void    ao_ir_cs1_request();

```
