---
author: "Stefan Wagner"
date: 2022-10-13
draft: true
permalink: /api/src/ao_sys_xc32_pic32mz_ecg/ao_sys_clock.h/
toc: true
---

# Configuration

## `AO_SYS_PBCLK*`

```c
#define AO_SYS_PBCLK1 (0)
#define AO_SYS_PBCLK2 (0)
#define AO_SYS_PBCLK3 (0)
#define AO_SYS_PBCLK4 (0)
#define AO_SYS_PBCLK5 (0)
#define AO_SYS_PBCLK7 (0)
#define AO_SYS_PBCLK8 (0)
```

The peripheral bus clock frequencies, in Hertz.

# Constants

## `AO_SYS_CLOCK_CAN*`

```c
#define AO_SYS_CLOCK_CAN1 (AO_SYS_PBCLK5)
#define AO_SYS_CLOCK_CAN2 (AO_SYS_PBCLK5)
```

The peripheral bus clock frequency for each CAN module, in Hertz.

## `AO_SYS_CLOCK_I2C*`

```c
#define AO_SYS_CLOCK_I2C1 (AO_SYS_PBCLK2)
#define AO_SYS_CLOCK_I2C2 (AO_SYS_PBCLK2)
#define AO_SYS_CLOCK_I2C3 (AO_SYS_PBCLK2)
#define AO_SYS_CLOCK_I2C4 (AO_SYS_PBCLK2)
#define AO_SYS_CLOCK_I2C5 (AO_SYS_PBCLK2)
```

The peripheral bus clock frequency for each I²C module, in Hertz.

## `AO_SYS_CLOCK_RNG`

```c
#define AO_SYS_CLOCK_RNG (AO_SYS_PBCLK5)
```

The peripheral bus clock frequency for the RNG module, in Hertz.

## `AO_SYS_CLOCK_SPI*`

```c
#define AO_SYS_CLOCK_SPI1 (AO_SYS_PBCLK2)
#define AO_SYS_CLOCK_SPI2 (AO_SYS_PBCLK2)
#define AO_SYS_CLOCK_SPI3 (AO_SYS_PBCLK2)
#define AO_SYS_CLOCK_SPI4 (AO_SYS_PBCLK2)
#define AO_SYS_CLOCK_SPI5 (AO_SYS_PBCLK2)
#define AO_SYS_CLOCK_SPI6 (AO_SYS_PBCLK2)
```

The peripheral bus clock frequency for each SPI module, in Hertz.

## `AO_SYS_CLOCK_UART*`

```c
#define AO_SYS_CLOCK_UART1 (AO_SYS_PBCLK2)
#define AO_SYS_CLOCK_UART2 (AO_SYS_PBCLK2)
#define AO_SYS_CLOCK_UART3 (AO_SYS_PBCLK2)
#define AO_SYS_CLOCK_UART4 (AO_SYS_PBCLK2)
#define AO_SYS_CLOCK_UART5 (AO_SYS_PBCLK2)
#define AO_SYS_CLOCK_UART6 (AO_SYS_PBCLK2)
```

The peripheral bus clock frequency for each UART module, in Hertz.

# Include Next

| [`ao_sys_clock.h`](../ao_sys_xc32_pic32/ao_sys_clock.h.md) |
