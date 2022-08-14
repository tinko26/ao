---
author: "Stefan Wagner"
date: 2022-08-14
description: "The ao_lfsr.h module of the ao real-time operating system."
draft: true
permalink: /modules/lfsr/
title: "ao_lfsr.h"
---

# ao_lfsr.h

This module defines [linear-feedback shift registers](https://en.wikipedia.org/wiki/Linear-feedback_shift_register) in Galois configuration, that can be used to generate pseudo-random values.

## Types

The module defines the following four types representing linear-feedback shift registers of dedicated maximum widths.

| Type          | Maximum Width |
|---------------|---------------|
| `ao_lfsr8_t`  | 8 bits        |
| `ao_lfsr16_t` | 16 bits       |
| `ao_lfsr32_t` | 32 bits       |
| `ao_lfsr64_t` | 64 bits       |

Since all types work in the same way, let's focus on the `ao_lfsr32_t` type.

```c
struct ao_lfsr32_t
{
    uint32_t polynomial;
    uint32_t seed;
};
```

The register consists of the following members.

| Member | |
|--------|-|
| `polynomial` | The generator polynomial. |
| `seed` | The seed or current value of the register. |

## Generator Polynomial

The register must be initialized with a generator polynomial, which appears in natural order. That is, bit 0, or the least significant bit, contains the polynomial's term $$x^1$$, bit 1 contains term $$x^2$$, and so on.

```c
ao_lfsr32_t * l;
```

```c
l->polynomial = 0x34002;
```

The most significant set bit determines the register's actual width. In the above example, bit 17, which contains term $$x^{18}$$, is the most significant set bit. Therefore, the register's actual width is 18 bits. The corresponding polynomial is $$x^{18} + x^{17} + x^{15} + x^2 + 1$$.

## Seed

In addition to the generator polynomial, the register must be provided an initial value, or seed. This is a random value from the range $$[1, 2^N - 1]$$, where $$N$$ is the width of the register.

```c
l->seed = 69081;
```

## Bit Generation

The `ao_lfsr32()` function generates a new bit, which is shifted into the register from the left.

```c
ao_lfsr32(l);
```

The new bit is located at the same position as the polynomial's most significant set bit, or bit 17 in the example.

```c
uint32_t newbit = (l->seed >> 17) & (uint32_t) 1;
```
