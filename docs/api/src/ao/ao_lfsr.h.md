---
api: true
author: "Stefan Wagner"
date: 2022-08-31
description: "The /src/ao/ao_lfsr.h file of the ao real-time operating system."
draft: false
permalink: /api/src/ao/ao_lfsr.h/
subtitle: "Linear-feedback shift registers"
title: "ao_lfsr.h"
toc: true
wiki:
- title: "Linear-feedback shift register"
  url: https://en.wikipedia.org/wiki/Linear-feedback_shift_register
---

# Overview

This module defines linear-feedback shift registers in Galois configuration, that can be used to generate pseudo-random values.

# Include

```c
#include <stdint.h>
```

# Typedefs

```c
typedef struct ao_lfsr8_t  ao_lfsr8_t;
typedef struct ao_lfsr16_t ao_lfsr16_t;
typedef struct ao_lfsr32_t ao_lfsr32_t;
typedef struct ao_lfsr64_t ao_lfsr64_t;
```

# Types

## `ao_lfsr8_t`

This type represents a linear-feedback shift register with a maximum width of 8 bits.

```c
struct ao_lfsr8_t
{
    uint8_t polynomial;
    uint8_t seed;
};
```

It consists of the following members.

| `polynomial` | The generator polynomial. |
| `seed` | The seed or current value of the register. |

## `ao_lfsr16_t`

This type represents a linear-feedback shift register with a maximum width of 16 bits.

```c
struct ao_lfsr16_t
{
    uint16_t polynomial;
    uint16_t seed;
};
```

It consists of the following members.

| `polynomial` | The generator polynomial. |
| `seed` | The seed or current value of the register. |

## `ao_lfsr32_t`

This type represents a linear-feedback shift register with a maximum width of 32 bits.

```c
struct ao_lfsr32_t
{
    uint32_t polynomial;
    uint32_t seed;
};
```

It consists of the following members.

| `polynomial` | The generator polynomial. |
| `seed` | The seed or current value of the register. |

## `ao_lfsr64_t`

This type represents a linear-feedback shift register with a maximum width of 64 bits.

```c
struct ao_lfsr64_t
{
    uint64_t polynomial;
    uint64_t seed;
};
```

It consists of the following members.

| `polynomial` | The generator polynomial. |
| `seed` | The seed or current value of the register. |

# Functions

Generate a new bit.

```c
void ao_lfsr8( ao_lfsr8_t  * r);
void ao_lfsr16(ao_lfsr16_t * r);
void ao_lfsr32(ao_lfsr32_t * r);
void ao_lfsr64(ao_lfsr64_t * r);
```

# Example

The register must be initialized with a generator polynomial, which appears in natural order. That is, bit 0, or the least significant bit, contains the polynomial's term $$x^1$$, bit 1 contains term $$x^2$$, and so on.

```c
ao_lfsr32_t * l;
```

```c
l->polynomial = 0x34002;
```

The most significant set bit determines the register's actual width. In the above example, bit 17, which contains term $$x^{18}$$, is the most significant set bit. Therefore, the register's actual width is 18 bits. The corresponding polynomial is $$x^{18} + x^{17} + x^{15} + x^2 + 1$$.

In addition to the generator polynomial, the register must be provided an initial value, or seed. This is a random value from the range $$[1, 2^N - 1]$$, where $$N$$ is the width of the register.

```c
l->seed = 69081;
```

The corresponding function generates a new bit, which is shifted into the register from the left.

```c
ao_lfsr32(l);
```

The new bit is located at the same position as the polynomial's most significant set bit, or bit 17 in the example.

```c
uint32_t newbit = (l->seed >> 17) & (uint32_t) 1;
```
