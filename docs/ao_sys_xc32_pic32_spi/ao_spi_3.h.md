---
author: "Stefan Wagner"
breadcrumbs: 2
date: 2022-08-29
description: "The ao_sys_xc32_pic32_spi/ao_spi_3.h module of the ao real-time operating system."
draft: true
permalink: /ao_sys_xc32_pic32_spi/ao_spi_3.h/ 
subtitle: "<code>ao_sys_xc32_pic32_spi</code>"
title: "<code>ao_spi_3.h</code>"
toc: true
---

#ifndef AO_SPI_3

#ifdef  _SPI3

#define AO_SPI_3            (true)

#else

#define AO_SPI_3            (false)

#endif

#endif

#ifndef AO_SPI_BAUD_MAX_3

#define AO_SPI_BAUD_MAX_3   AO_SPI_BAUD_MAX(AO_SYS_CLOCK_SPI3)

#endif

#ifndef AO_SPI_BAUD_MIN_3

#define AO_SPI_BAUD_MIN_3   AO_SPI_BAUD_MIN(AO_SYS_CLOCK_SPI3)

#endif

#ifndef ao_spi_baud_3

#define ao_spi_baud_3(f)    ao_spi_baud(ao_spi_reg_3(), AO_SYS_CLOCK_SPI3, f)

#endif

#ifndef ao_spi_reg_3

#define ao_spi_reg_3()      ((ao_spi_reg_t *) (_SPI3_BASE_ADDRESS))

#endif

