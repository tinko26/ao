---
author: "Stefan Wagner"
date: 2022-09-27
draft: true
external:
- https://en.wikipedia.org/wiki/Linear-feedback_shift_register : "Linear-feedback shift register"
permalink: /api/src/ao/ao_lfsr16.h/
toc: true
---

# Notes

This module defines linear-feedback shift registers with a maximum width of 16 bits in Galois configuration, that can be used to generate pseudo-random values.

# Include

| `stdint.h` |

# Types

## `ao_lfsr16_t`

```c
typedef struct ao_lfsr16_t ao_lfsr16_t;
```

Represents a linear-feedback shift register with a maximum width of 16 bits.

# Structs

## `ao_lfsr16_t`

```c
struct ao_lfsr16_t
{
    uint16_t polynomial;
    uint16_t value;
};
```

| `polynomial` | The generator polynomial. |
| `value` | The value. |

# Functions

## `ao_lfsr16`

```c
void ao_lfsr16(ao_lfsr16_t * lfsr);
```

Generates a new bit.
