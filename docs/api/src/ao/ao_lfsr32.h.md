---
author: "Stefan Wagner"
date: 2022-09-27
draft: true
external:
- https://en.wikipedia.org/wiki/Linear-feedback_shift_register : "Linear-feedback shift register"
permalink: /api/src/ao/ao_lfsr32.h/
toc: true
---

# Notes

This module defines linear-feedback shift registers with a maximum width of 32 bits in Galois configuration, that can be used to generate pseudo-random values.

# Include

| `stdint.h` |

# Types

## `ao_lfsr32_t`

```c
typedef struct ao_lfsr32_t ao_lfsr32_t;
```

Represents a linear-feedback shift register with a maximum width of 32 bits.

# Structs

## `ao_lfsr32_t`

```c
struct ao_lfsr32_t
{
    uint32_t polynomial;
    uint32_t value;
};
```

| `polynomial` | The generator polynomial. |
| `value` | The value. |

# Functions

## `ao_lfsr32`

```c
void ao_lfsr32(ao_lfsr32_t * lfsr);
```

Generates a new bit.
