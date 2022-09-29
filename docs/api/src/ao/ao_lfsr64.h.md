---
author: "Stefan Wagner"
date: 2022-09-27
draft: true
external:
- https://en.wikipedia.org/wiki/Linear-feedback_shift_register : "Linear-feedback shift register"
permalink: /api/src/ao/ao_lfsr64.h/
toc: true
---

# Notes

This module defines linear-feedback shift registers with a maximum width of 64 bits in Galois configuration, that can be used to generate pseudo-random values.

# Include

| `stdint.h` |

# Types

## `ao_lfsr64_t`

```c
typedef struct ao_lfsr64_t ao_lfsr64_t;
```

Represents a linear-feedback shift register with a maximum width of 64 bits.

# Structs

## `ao_lfsr64_t`

```c
struct ao_lfsr64_t
{
    uint64_t polynomial;
    uint64_t value;
};
```

| `polynomial` | The generator polynomial. |
| `value` | The value. |

# Functions

## `ao_lfsr64`

```c
void ao_lfsr64(ao_lfsr64_t * l);
```

Generates a new bit.
