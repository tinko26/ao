---
author: "Stefan Wagner"
date: 2022-09-20
draft: true
permalink: /api/src/ao_sys_xc32_pic32mx_3xx/ao_sys_clock.h/
toc: true
---

# Constants

## `AO_SYS_CLOCK_I2C`

```c
#define AO_SYS_CLOCK_I2C1 (AO_SYS_PBCLK)
#define AO_SYS_CLOCK_I2C2 (AO_SYS_PBCLK)
```

The peripheral bus clock frequency for each I²C module, in Hertz.

## `AO_SYS_CLOCK_IC`

```c
#define AO_SYS_CLOCK_IC1 (AO_SYS_PBCLK)
#define AO_SYS_CLOCK_IC2 (AO_SYS_PBCLK)
#define AO_SYS_CLOCK_IC3 (AO_SYS_PBCLK)
#define AO_SYS_CLOCK_IC4 (AO_SYS_PBCLK)
#define AO_SYS_CLOCK_IC5 (AO_SYS_PBCLK)
```

The peripheral bus clock frequency for each input capture module, in Hertz.

## `AO_SYS_CLOCK_OC`

```c
#define AO_SYS_CLOCK_OC1 (AO_SYS_PBCLK)
#define AO_SYS_CLOCK_OC2 (AO_SYS_PBCLK)
#define AO_SYS_CLOCK_OC3 (AO_SYS_PBCLK)
#define AO_SYS_CLOCK_OC4 (AO_SYS_PBCLK)
#define AO_SYS_CLOCK_OC5 (AO_SYS_PBCLK)
```

The peripheral bus clock frequency for each output compare module, in Hertz.

## `AO_SYS_CLOCK_SPI`

```c
#define AO_SYS_CLOCK_SPI1 (AO_SYS_PBCLK)
#define AO_SYS_CLOCK_SPI2 (AO_SYS_PBCLK)
```

The peripheral bus clock frequency for each SPI module, in Hertz.

## `AO_SYS_CLOCK_T`

```c
#define AO_SYS_CLOCK_T1 (AO_SYS_PBCLK)
#define AO_SYS_CLOCK_T2 (AO_SYS_PBCLK)
#define AO_SYS_CLOCK_T3 (AO_SYS_PBCLK)
#define AO_SYS_CLOCK_T4 (AO_SYS_PBCLK)
#define AO_SYS_CLOCK_T5 (AO_SYS_PBCLK)
```

The peripheral bus clock frequency for each timer module, in Hertz.

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
