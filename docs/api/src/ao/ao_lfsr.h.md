---
author: "Stefan Wagner"
date: 2022-09-24
draft: true
external:
- https://en.wikipedia.org/wiki/Linear-feedback_shift_register : "Linear-feedback shift register"
permalink: /api/src/ao/ao_lfsr.h/
toc: true
---

# Notes

This module defines linear-feedback shift registers in Galois configuration, that can be used to generate pseudo-random values.

# Include

`stdint.h`

# Identifiers

```c
#define AO_LFSR8
#define AO_LFSR16
#define AO_LFSR32
#define AO_LFSR64
```

# Types

## `ao_lfsr8_t`

```c
typedef struct ao_lfsr8_t ao_lfsr8_t;
```

This type represents a linear-feedback shift register with a maximum width of 8 bits.

## `ao_lfsr16_t`

```c
typedef struct ao_lfsr16_t ao_lfsr16_t;
```

This type represents a linear-feedback shift register with a maximum width of 16 bits.

## `ao_lfsr32_t`

```c
typedef struct ao_lfsr32_t ao_lfsr32_t;
```

This type represents a linear-feedback shift register with a maximum width of 32 bits.

## `ao_lfsr64_t`

```c
typedef struct ao_lfsr64_t ao_lfsr64_t;
```

This type represents a linear-feedback shift register with a maximum width of 64 bits.

# Structs

## `ao_lfsr8_t`

```c
struct ao_lfsr8_t
{
    uint8_t polynomial;
    uint8_t seed;
};
```

| `polynomial` | The generator polynomial. |
| `seed` | The seed or current value of the register. |

## `ao_lfsr16_t`

```c
struct ao_lfsr16_t
{
    uint16_t polynomial;
    uint16_t seed;
};
```

| `polynomial` | The generator polynomial. |
| `seed` | The seed or current value of the register. |

## `ao_lfsr32_t`

```c
struct ao_lfsr32_t
{
    uint32_t polynomial;
    uint32_t seed;
};
```

| `polynomial` | The generator polynomial. |
| `seed` | The seed or current value of the register. |

## `ao_lfsr64_t`

```c
struct ao_lfsr64_t
{
    uint64_t polynomial;
    uint64_t seed;
};
```

| `polynomial` | The generator polynomial. |
| `seed` | The seed or current value of the register. |

# Functions

## `ao_lfsr*`

```c
void ao_lfsr8 (ao_lfsr8_t  * r);
void ao_lfsr16(ao_lfsr16_t * r);
void ao_lfsr32(ao_lfsr32_t * r);
void ao_lfsr64(ao_lfsr64_t * r);
```

Generates a new bit.
