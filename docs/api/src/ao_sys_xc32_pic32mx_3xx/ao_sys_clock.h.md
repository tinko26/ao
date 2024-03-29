---
author: "Stefan Wagner"
date: 2022-09-25
draft: true
permalink: /api/src/ao_sys_xc32_pic32mx_3xx/ao_sys_clock.h/
toc: true
---

# Configuration

## `AO_SYS_PBCLK`

```c
#define AO_SYS_PBCLK (0)
```

The peripheral bus clock frequency, in Hertz.

# Constants

## `AO_SYS_CLOCK_I2C*`

```c
#define AO_SYS_CLOCK_I2C1 (AO_SYS_PBCLK)
#define AO_SYS_CLOCK_I2C2 (AO_SYS_PBCLK)
```

The peripheral bus clock frequency for each I²C module, in Hertz.

## `AO_SYS_CLOCK_SPI*`

```c
#define AO_SYS_CLOCK_SPI1 (AO_SYS_PBCLK)
#define AO_SYS_CLOCK_SPI2 (AO_SYS_PBCLK)
```

The peripheral bus clock frequency for each SPI module, in Hertz.

## `AO_SYS_CLOCK_UART*`

```c
#define AO_SYS_CLOCK_UART1 (AO_SYS_PBCLK)
#define AO_SYS_CLOCK_UART2 (AO_SYS_PBCLK)
```

The peripheral bus clock frequency for each UART module, in Hertz.

# Include Next

| [`ao_sys_clock.h`](../ao_sys_xc32_pic32/ao_sys_clock.h.md) |
