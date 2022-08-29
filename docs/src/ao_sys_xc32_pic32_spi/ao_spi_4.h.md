---
api: true
author: "Stefan Wagner"
date: 2022-08-29
description: "The /src/ao_sys_xc32_pic32_spi/ao_spi_4.h file of the ao real-time operating system."
draft: true
permalink: /src/ao_sys_xc32_pic32_spi/ao_spi_4.h/ 
subtitle: ""
title: "ao_spi_4.h"
toc: true
---

# Overview

...

# Includes

```c
#include <ao_spi.h>
#include <ao_sys.h>
#include <stdbool.h>
#include <xc.h>

#ifndef AO_SPI_4

#ifdef  _SPI4

#define AO_SPI_4            (true)

#else

#define AO_SPI_4            (false)

#endif

#endif

#ifndef AO_SPI_BAUD_MAX_4

#define AO_SPI_BAUD_MAX_4   AO_SPI_BAUD_MAX(AO_SYS_CLOCK_SPI4)

#endif

#ifndef AO_SPI_BAUD_MIN_4

#define AO_SPI_BAUD_MIN_4   AO_SPI_BAUD_MIN(AO_SYS_CLOCK_SPI4)

#endif

#ifndef ao_spi_baud_4

#define ao_spi_baud_4(f)    ao_spi_baud(ao_spi_reg_4(), AO_SYS_CLOCK_SPI4, f)

#endif

#ifndef ao_spi_reg_4

#define ao_spi_reg_4()      ((ao_spi_reg_t *) (_SPI4_BASE_ADDRESS))

#endif

```
