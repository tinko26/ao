---
api: true
author: "Stefan Wagner"
date: 2022-08-29
description: "The ao_sys_xc32_pic32mk_gpg/ao_spi.h module of the ao real-time operating system."
draft: true
permalink: /ao_sys_xc32_pic32mk_gpg/ao_spi.h/ 
subtitle: "ao_sys_xc32_pic32mk_gpg"
title: "ao_spi.h"
toc: true
---

```c
#include <stdbool.h>

#ifndef AO_SPI_BRG_BITS

#define AO_SPI_BRG_BITS     (13)

#endif

#ifndef AO_SPI_ENHBUF

#define AO_SPI_ENHBUF       (true)

#endif

#include_next <ao_spi.h>

```
