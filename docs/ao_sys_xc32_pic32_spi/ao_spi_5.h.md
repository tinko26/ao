---
author: "Stefan Wagner"
date: 2022-08-29
description: "The ao_sys_xc32_pic32_spi/ao_spi_5.h module of the ao real-time operating system."
draft: true
permalink: /ao_sys_xc32_pic32_spi/ao_spi_5.h/ 
subtitle: "<code>ao_sys_xc32_pic32_spi</code>"
title: "<code>ao_spi_5.h</code>"
toc: true
---

#ifndef AO_SPI_5

#ifdef  _SPI5

#define AO_SPI_5            (true)

#else

#define AO_SPI_5            (false)

#endif

#endif

#ifndef AO_SPI_BAUD_MAX_5

#define AO_SPI_BAUD_MAX_5   AO_SPI_BAUD_MAX(AO_SYS_CLOCK_SPI5)

#endif

#ifndef AO_SPI_BAUD_MIN_5

#define AO_SPI_BAUD_MIN_5   AO_SPI_BAUD_MIN(AO_SYS_CLOCK_SPI5)

#endif

#ifndef ao_spi_baud_5

#define ao_spi_baud_5(f)    ao_spi_baud(ao_spi_reg_5(), AO_SYS_CLOCK_SPI5, f)

#endif

#ifndef ao_spi_reg_5

#define ao_spi_reg_5()      ((ao_spi_reg_t *) (_SPI5_BASE_ADDRESS))

#endif

