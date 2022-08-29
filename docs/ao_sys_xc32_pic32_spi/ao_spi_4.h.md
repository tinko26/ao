---
author: "Stefan Wagner"
breadcrumbs: 2
date: 2022-08-29
description: "The ao_sys_xc32_pic32_spi/ao_spi_4.h module of the ao real-time operating system."
draft: true
permalink: /ao_sys_xc32_pic32_spi/ao_spi_4.h/ 
subtitle: "<code>ao_sys_xc32_pic32_spi</code>"
title: "<code>ao_spi_4.h</code>"
toc: true
---

```c
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
