---
author: "Stefan Wagner"
date: 2022-09-27
draft: true
external:
- https://en.wikipedia.org/wiki/Linear-feedback_shift_register : "Linear-feedback shift register"
permalink: /api/src/ao/ao_lfsr8.h/
toc: true
---

# Notes

This module defines linear-feedback shift registers with a maximum width of 8 bits in Galois configuration, that can be used to generate pseudo-random values.

# Include

| `stdint.h` |

# Types

## `ao_lfsr8_t`

```c
typedef struct ao_lfsr8_t ao_lfsr8_t;
```

This type represents a linear-feedback shift register with a maximum width of 8 bits.

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

# Functions

## `ao_lfsr8`

```c
void ao_lfsr8(ao_lfsr8_t * r);
```

Generates a new bit.
