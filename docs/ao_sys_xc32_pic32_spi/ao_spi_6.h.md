---
author: "Stefan Wagner"
date: 2022-08-29
description: "The ao_sys_xc32_pic32_spi/ao_spi_6.h module of the ao real-time operating system."
draft: true
permalink: /ao_sys_xc32_pic32_spi/ao_spi_6.h/ 
subtitle: "<code>ao_sys_xc32_pic32_spi</code>"
title: "<code>ao_spi_6.h</code>"
toc: true
---

#ifndef AO_SPI_6

#ifdef  _SPI6

#define AO_SPI_6            (true)

#else

#define AO_SPI_6            (false)

#endif

#endif

#ifndef AO_SPI_BAUD_MAX_6

#define AO_SPI_BAUD_MAX_6   AO_SPI_BAUD_MAX(AO_SYS_CLOCK_SPI6)

#endif

#ifndef AO_SPI_BAUD_MIN_6

#define AO_SPI_BAUD_MIN_6   AO_SPI_BAUD_MIN(AO_SYS_CLOCK_SPI6)

#endif

#ifndef ao_spi_baud_6

#define ao_spi_baud_6(f)    ao_spi_baud(ao_spi_reg_6(), AO_SYS_CLOCK_SPI6, f)

#endif

#ifndef ao_spi_reg_6

#define ao_spi_reg_6()      ((ao_spi_reg_t *) (_SPI6_BASE_ADDRESS))

#endif

