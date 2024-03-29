---
author: "Stefan Wagner"
date: 2022-09-25
draft: true
external:
- https://www.mikroe.com/expand-5-click : "EXPAND 5 Click"
- https://www.ti.com/product/TCA6424A : "TCA6426A 24-bit I/O expander"
permalink: /api/demos/ao_mikroe/ao_mikroe_4186.h/
toc: true
---

# Include

| `stdbool.h` |
| `stddef.h` |
| `stdint.h` |

# Configuration

```c
#define AO_MIKROE_4186 (false)
```

Defines whether the clickboard is used.

# Types

## `ao_mikroe_4186_t`

```c
typedef union ao_mikroe_4186_t ao_mikroe_4186_t;
```

## `ao_mikroe_4186_port_t`

```c
typedef union ao_mikroe_4186_port_t ao_mikroe_4186_port_t;
```

# Unions

## `ao_mikroe_4186_t`

```c
union ao_mikroe_4186_t
{
    uint32_t                  ports;
    struct
    {
        ao_mikroe_4186_port_t port0;
        ao_mikroe_4186_port_t port1;
        ao_mikroe_4186_port_t port2;
    };
};
```

| `port0` | |
| `port1` | |
| `port2` | |
| `ports` | |

## `ao_mikroe_4186_port_t`

```c
union ao_mikroe_4186_port_t
{
    uint8_t     pins;
    struct
    {
        uint8_t pin0 : 1;
        uint8_t pin1 : 1;
        uint8_t pin2 : 1;
        uint8_t pin3 : 1;
        uint8_t pin4 : 1;
        uint8_t pin5 : 1;
        uint8_t pin6 : 1;
        uint8_t pin7 : 1;
    };
};
```

| `pin0` | |
| `pin1` | |
| `pin2` | |
| `pin3` | |
| `pin4` | |
| `pin5` | |
| `pin6` | |
| `pin7` | |
| `pins` | |

# Functions

## `ao_mikroe_4186_get_config`

```c
uint32_t ao_mikroe_4186_get_config(size_t i);
```

## `ao_mikroe_4186_get_input`

```c
uint32_t ao_mikroe_4186_get_input(size_t i);
```

## `ao_mikroe_4186_get_output`

```c
uint32_t ao_mikroe_4186_get_output(size_t i);
```

## `ao_mikroe_4186_get_polarity`

```c
uint32_t ao_mikroe_4186_get_polarity(size_t i);
```

## `ao_mikroe_4186_get_port_config`

```c
uint8_t ao_mikroe_4186_get_port_config(size_t i, size_t p);
```

## `ao_mikroe_4186_get_port_input`

```c
uint8_t ao_mikroe_4186_get_port_input(size_t i, size_t p);
```

## `ao_mikroe_4186_get_port_output`

```c
uint8_t ao_mikroe_4186_get_port_output(size_t i, size_t p);
```

## `ao_mikroe_4186_get_port_polarity`

```c
uint8_t ao_mikroe_4186_get_port_polarity(size_t i, size_t p);
```

## `ao_mikroe_4186_int`

```c
void ao_mikroe_4186_int(size_t i);
```

## `ao_mikroe_4186_reset`

```c
void ao_mikroe_4186_reset(size_t i);
```

## `ao_mikroe_4186_set_config`

```c
void ao_mikroe_4186_set_config(size_t i, uint32_t x);
```

## `ao_mikroe_4186_set_input`

```c
void ao_mikroe_4186_set_input(size_t i, uint32_t x);
```

## `ao_mikroe_4186_set_output`

```c
void ao_mikroe_4186_set_output(size_t i, uint32_t x);
```

## `ao_mikroe_4186_set_polarity`

```c
void ao_mikroe_4186_set_polarity(size_t i, uint32_t x);
```

## `ao_mikroe_4186_set_port_config`

```c
void ao_mikroe_4186_set_port_config(size_t i, size_t p, uint8_t x);
```

## `ao_mikroe_4186_set_port_input`

```c
void ao_mikroe_4186_set_port_input(size_t i, size_t p, uint8_t x);
```

## `ao_mikroe_4186_set_port_output`

```c
void ao_mikroe_4186_set_port_output(size_t i, size_t p, uint8_t x);
```

## `ao_mikroe_4186_set_port_polarity`

```c
void ao_mikroe_4186_set_port_polarity(size_t i, size_t p, uint8_t x);
```
