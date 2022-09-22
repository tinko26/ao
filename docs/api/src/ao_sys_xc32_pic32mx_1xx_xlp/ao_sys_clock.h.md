---
author: "Stefan Wagner"
date: 2022-09-22
draft: true
permalink: /api/src/ao_sys_xc32_pic32mx_1xx_xlp/ao_sys_clock.h/
toc: true
---

# Constants

## `AO_SYS_CLOCK_I2C`

```c
#define AO_SYS_CLOCK_I2C1 (AO_SYS_PBCLK)
#define AO_SYS_CLOCK_I2C2 (AO_SYS_PBCLK)
```

The peripheral bus clock frequency for each I²C module, in Hertz.

## `AO_SYS_CLOCK_SPI`

```c
#define AO_SYS_CLOCK_SPI1 (AO_SYS_PBCLK)
#define AO_SYS_CLOCK_SPI2 (AO_SYS_PBCLK)
```

The peripheral bus clock frequency for each SPI module, in Hertz.

## `AO_SYS_CLOCK_U`

```c
#define AO_SYS_CLOCK_U1 (AO_SYS_PBCLK)
#define AO_SYS_CLOCK_U2 (AO_SYS_PBCLK)
```

The peripheral bus clock frequency for each UART module, in Hertz.

## `AO_SYS_PBCLK`

```c
#define AO_SYS_PBCLK (0)
```

The peripheral bus clock frequency, in Hertz.

# Include Next

```c
#include_next <ao_sys_clock.h>
```
