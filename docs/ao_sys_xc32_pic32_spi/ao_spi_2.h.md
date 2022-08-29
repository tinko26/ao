---
api: true
author: "Stefan Wagner"
date: 2022-08-29
description: "The ao_sys_xc32_pic32_spi/ao_spi_2.h module of the ao real-time operating system."
draft: true
permalink: /ao_sys_xc32_pic32_spi/ao_spi_2.h/ 
subtitle: ""
title: "ao_spi_2.h"
toc: true
---

```c
#include <ao_spi.h>
#include <ao_sys.h>
#include <stdbool.h>
#include <xc.h>

#ifndef AO_SPI_2

#ifdef  _SPI2

#define AO_SPI_2            (true)

#else

#define AO_SPI_2            (false)

#endif

#endif

#ifndef AO_SPI_BAUD_MAX_2

#define AO_SPI_BAUD_MAX_2   AO_SPI_BAUD_MAX(AO_SYS_CLOCK_SPI2)

#endif

#ifndef AO_SPI_BAUD_MIN_2

#define AO_SPI_BAUD_MIN_2   AO_SPI_BAUD_MIN(AO_SYS_CLOCK_SPI2)

#endif

#ifndef ao_spi_baud_2

#define ao_spi_baud_2(f)    ao_spi_baud(ao_spi_reg_2(), AO_SYS_CLOCK_SPI2, f)

#endif

#ifndef ao_spi_reg_2

#define ao_spi_reg_2()      ((ao_spi_reg_t *) (_SPI2_BASE_ADDRESS))

#endif

```
