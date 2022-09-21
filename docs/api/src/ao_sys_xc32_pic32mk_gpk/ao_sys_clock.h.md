---
author: "Stefan Wagner"
date: 2022-09-20
draft: true
permalink: /api/src/ao_sys_xc32_pic32mk_gpk/ao_sys_clock.h/
toc: true
---

# Constants

## `AO_SYS_CLOCK_CAN`

```c
#define AO_SYS_CLOCK_CAN1 (AO_SYS_PBCLK5)
#define AO_SYS_CLOCK_CAN2 (AO_SYS_PBCLK5)
#define AO_SYS_CLOCK_CAN3 (AO_SYS_PBCLK5)
#define AO_SYS_CLOCK_CAN4 (AO_SYS_PBCLK5)
```

The peripheral bus clock frequency for each CAN module, in Hertz.

## `AO_SYS_CLOCK_I2C`

```c
#define AO_SYS_CLOCK_I2C1 (AO_SYS_PBCLK2)
#define AO_SYS_CLOCK_I2C2 (AO_SYS_PBCLK2)
#define AO_SYS_CLOCK_I2C3 (AO_SYS_PBCLK3)
#define AO_SYS_CLOCK_I2C4 (AO_SYS_PBCLK3)
```

The peripheral bus clock frequency for each I²C module, in Hertz.

## `AO_SYS_CLOCK_IC`

```c
#define AO_SYS_CLOCK_IC1  (AO_SYS_PBCLK2)
#define AO_SYS_CLOCK_IC2  (AO_SYS_PBCLK2)
#define AO_SYS_CLOCK_IC3  (AO_SYS_PBCLK2)
#define AO_SYS_CLOCK_IC4  (AO_SYS_PBCLK2)
#define AO_SYS_CLOCK_IC5  (AO_SYS_PBCLK2)
#define AO_SYS_CLOCK_IC6  (AO_SYS_PBCLK2)
#define AO_SYS_CLOCK_IC7  (AO_SYS_PBCLK2)
#define AO_SYS_CLOCK_IC8  (AO_SYS_PBCLK2)
#define AO_SYS_CLOCK_IC9  (AO_SYS_PBCLK2)
#define AO_SYS_CLOCK_IC10 (AO_SYS_PBCLK3)
#define AO_SYS_CLOCK_IC11 (AO_SYS_PBCLK3)
#define AO_SYS_CLOCK_IC12 (AO_SYS_PBCLK3)
#define AO_SYS_CLOCK_IC13 (AO_SYS_PBCLK3)
#define AO_SYS_CLOCK_IC14 (AO_SYS_PBCLK3)
#define AO_SYS_CLOCK_IC15 (AO_SYS_PBCLK3)
#define AO_SYS_CLOCK_IC16 (AO_SYS_PBCLK3)
```

The peripheral bus clock frequency for each input capture module, in Hertz.

## `AO_SYS_CLOCK_OC`

```c
#define AO_SYS_CLOCK_OC1  (AO_SYS_PBCLK2)
#define AO_SYS_CLOCK_OC2  (AO_SYS_PBCLK2)
#define AO_SYS_CLOCK_OC3  (AO_SYS_PBCLK2)
#define AO_SYS_CLOCK_OC4  (AO_SYS_PBCLK2)
#define AO_SYS_CLOCK_OC5  (AO_SYS_PBCLK2)
#define AO_SYS_CLOCK_OC6  (AO_SYS_PBCLK2)
#define AO_SYS_CLOCK_OC7  (AO_SYS_PBCLK2)
#define AO_SYS_CLOCK_OC8  (AO_SYS_PBCLK2)
#define AO_SYS_CLOCK_OC9  (AO_SYS_PBCLK2)
#define AO_SYS_CLOCK_OC10 (AO_SYS_PBCLK3)
#define AO_SYS_CLOCK_OC11 (AO_SYS_PBCLK3)
#define AO_SYS_CLOCK_OC12 (AO_SYS_PBCLK3)
#define AO_SYS_CLOCK_OC13 (AO_SYS_PBCLK3)
#define AO_SYS_CLOCK_OC14 (AO_SYS_PBCLK3)
#define AO_SYS_CLOCK_OC15 (AO_SYS_PBCLK3)
#define AO_SYS_CLOCK_OC16 (AO_SYS_PBCLK3)
```

The peripheral bus clock frequency for each output compare module, in Hertz.

## `AO_SYS_CLOCK_SPI`

```c
#define AO_SYS_CLOCK_SPI1 (AO_SYS_PBCLK2)
#define AO_SYS_CLOCK_SPI2 (AO_SYS_PBCLK2)
#define AO_SYS_CLOCK_SPI3 (AO_SYS_PBCLK3)
#define AO_SYS_CLOCK_SPI4 (AO_SYS_PBCLK3)
#define AO_SYS_CLOCK_SPI5 (AO_SYS_PBCLK3)
#define AO_SYS_CLOCK_SPI6 (AO_SYS_PBCLK3)
```

The peripheral bus clock frequency for each SPI module, in Hertz.

## `AO_SYS_CLOCK_T`

```c
#define AO_SYS_CLOCK_T1 (AO_SYS_PBCLK2)
#define AO_SYS_CLOCK_T2 (AO_SYS_PBCLK2)
#define AO_SYS_CLOCK_T3 (AO_SYS_PBCLK2)
#define AO_SYS_CLOCK_T4 (AO_SYS_PBCLK2)
#define AO_SYS_CLOCK_T5 (AO_SYS_PBCLK2)
#define AO_SYS_CLOCK_T6 (AO_SYS_PBCLK2)
#define AO_SYS_CLOCK_T7 (AO_SYS_PBCLK2)
#define AO_SYS_CLOCK_T8 (AO_SYS_PBCLK2)
#define AO_SYS_CLOCK_T9 (AO_SYS_PBCLK2)
```

The peripheral bus clock frequency for each timer module, in Hertz.

## `AO_SYS_CLOCK_U`

```c
#define AO_SYS_CLOCK_U1 (AO_SYS_PBCLK2)
#define AO_SYS_CLOCK_U2 (AO_SYS_PBCLK2)
#define AO_SYS_CLOCK_U3 (AO_SYS_PBCLK3)
#define AO_SYS_CLOCK_U4 (AO_SYS_PBCLK3)
#define AO_SYS_CLOCK_U5 (AO_SYS_PBCLK3)
#define AO_SYS_CLOCK_U6 (AO_SYS_PBCLK3)
```

The peripheral bus clock frequency for each UART module, in Hertz.

## `AO_SYS_PBCLK`

```c
#define AO_SYS_PBCLK1 (0)
#define AO_SYS_PBCLK2 (0)
#define AO_SYS_PBCLK3 (0)
#define AO_SYS_PBCLK4 (0)
#define AO_SYS_PBCLK5 (0)
#define AO_SYS_PBCLK6 (0)
#define AO_SYS_PBCLK7 (0)
```

The peripheral bus clock frequencies, in Hertz.

# Include Next

```c
#include_next <ao_sys_clock.h>
```
