---
api: true
author: "Stefan Wagner"
date: 2022-08-29
description: "The ao_sys_xc32_pic32_spi/ao_spi_1.h module of the ao real-time operating system."
draft: true
permalink: /ao_sys_xc32_pic32_spi/ao_spi_1.h/ 
subtitle: ""
title: "ao_spi_1.h"
toc: true
---

```c
#include <ao_spi.h>
#include <ao_sys.h>
#include <stdbool.h>
#include <xc.h>

#ifndef AO_SPI_1

#ifdef  _SPI1

#define AO_SPI_1            (true)

#else

#define AO_SPI_1            (false)

#endif

#endif

#ifndef AO_SPI_BAUD_MAX_1

#define AO_SPI_BAUD_MAX_1   AO_SPI_BAUD_MAX(AO_SYS_CLOCK_SPI1)

#endif

#ifndef AO_SPI_BAUD_MIN_1

#define AO_SPI_BAUD_MIN_1   AO_SPI_BAUD_MIN(AO_SYS_CLOCK_SPI1)

#endif

#ifndef ao_spi_baud_1

#define ao_spi_baud_1(f)    ao_spi_baud(ao_spi_reg_1(), AO_SYS_CLOCK_SPI1, f)

#endif

#ifndef ao_spi_reg_1

#define ao_spi_reg_1()      ((ao_spi_reg_t *) (_SPI1_BASE_ADDRESS))

#endif

```
