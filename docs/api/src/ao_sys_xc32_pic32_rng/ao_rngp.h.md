---
author: "Stefan Wagner"
date: 2022-09-20
draft: true
external:
- https://en.wikipedia.org/wiki/Linear-feedback_shift_register : "Linear-feedback shift register"
permalink: /api/src/ao_sys_xc32_pic32_rng/ao_rngp.h/
toc: true
---

# Notes

The pseudo-random number generator generates numbers by generating a sequence of `PLEN` bits.

The numbers are generated either continuously (`RNGCON.CONT` = 1) or after reading the `RNGNUMGEN` register (`RNGCON.CONT` = 0).

Each new bit is shifted into the `RNGNUMGEN` register from the left at position `PLEN` - 1.

New bit &rarr; `RNGNUMGEN2` &rarr; `RNGNUMGEN1` &rarr; Old bit.

Consequently, the generator polynomial coefficients appear in the `RNGPOLY` register in reverse order.

`RNGPOLY1` bit 0 is the coefficient of the term $$x^(\textt{PLEN})$$.

`RNGPOLY1` bit 1 is the coefficient of the term $$x^(\textt{PLEN} - 1)$$.

`RNGPOLY1` bit 2 is the coefficient of the term $$x^(\textt{PLEN} - 2)$$.

...

`RNGPOLY1` bit 31 is the coefficient of the term $$x^(\textt{PLEN} - 31)$$.

`RNGPOLY2` bit 0 is the coefficient of the term $$x^(\textt{PLEN} - 32)$$.

`RNGPOLY2` bit 1 is the coefficient of the term $$x^(\textt{PLEN} - 33)$$.

...

`RNGPOLY2` bit 31 is the coefficient of the term $$x^(\textt{PLEN} - 63)$$.

## Example

```c
ao_leds_t ld;
ao_leds_t le;
```

```c
uint64_t v;
```

True random number generator. 

Wait until 42 bits have been generated.

```c
ao_rngt_enable();

while (ao_rngt_bits() < 42);
```

Pseudo-random number generator. 

Set the number of bits to 42. Set the polynomial to $$x^{42} + x^{41} + x^{20} + x^{19} + 1$$.

```c
ao_rngp_bits_set(42);

ao_rngp_poly_lo_set(0x00C00003);
ao_rngp_poly_hi_set(0x00000000);
```

Seed by loading the value from the true random number generator.

```c
ao_rngp_seed_true();

ao_rngp_enable();
```

Loop.

```c
while (1)
{
    // Read the random number.
    v = ao_rngp_value();

    // LEDs.
    le = AO_LEDS_NONE;
    ld = AO_LEDS_NONE;

    if (v & (1 << 0)) { le |= AO_LEDS_0; } else { ld |= AO_LEDS_0; }
    if (v & (1 << 1)) { le |= AO_LEDS_1; } else { ld |= AO_LEDS_1; }
    if (v & (1 << 2)) { le |= AO_LEDS_2; } else { ld |= AO_LEDS_2; }

    ao_leds_enable(le);
    ao_leds_disable(ld);

    // We need to wait at least 42 clock cycles 
    // before reading the next random number.
    ao_spin(AO_MILLISECONDS(100));
}
```

# Include

```c
#include <stdint.h>
#include <xc.h>
```

# Functions

## `ao_rngp_enable`
## `ao_rngp_disable`

```c
#define ao_rngp_enable()  { RNGCONbits.PRNGEN = 1; }
#define ao_rngp_disable() { RNGCONbits.PRNGEN = 0; }
```

Enables or disables the pseudo-random number generator.

## `ao_rngp_bits`

```c
#define ao_rngp_bits() (RNGCONbits.PLEN)
```

Gets the maximum number of bits to generate.

## `ao_rngp_bits_set`

```c
#define ao_rngp_bits_set(x)           \
{                                     \
    RNGCONbits.PLEN = (uint32_t) (x); \
}
```

Sets the maximum number of bits to generate.

## `ao_rngp_continuous_enable`
## `ao_rngp_continuous_disable`

```c
#define ao_rngp_continuous_enable()  { RNGCONbits.CONT = 1; }
#define ao_rngp_continuous_disable() { RNGCONbits.CONT = 0; }
```

Enables or disables, respectively, the continuous generation of random numbers. If enabled, the generation of a new random number will be triggered automatically when the generation of the previous number has finished. If disabled, the generation of a new random number must be triggered by reading the previously generated number.

## `ao_rngp_poly`

```c
#define ao_rngp_poly()            \
(                                 \
    ((uint64_t) RNGPOLY2 << 32) | \
     (uint64_t) RNGPOLY1          \
)
```

Gets the generator polynomial.

## `ao_rngp_poly_set`

```c
#define ao_rngp_poly_set(x)                                         \
{                                                                   \
    RNGPOLY2 = (uint32_t) (((uint64_t) (x) >> 32) & 0xFFFFFFFFULL); \
    RNGPOLY1 = (uint32_t) (((uint64_t) (x) >>  0) & 0xFFFFFFFFULL); \
}
```

Sets the generator polynomial.

## `ao_rngp_poly_hi`

```c
#define ao_rngp_poly_hi() (RNGPOLY2)
```

Gets the 32 most significant bits of the generator polynomial.

## `ao_rngp_poly_hi_set`

```c
#define ao_rngp_poly_hi_set(x) \
{                              \
    RNGPOLY2 = (uint32_t) (x); \
}
```

Sets the 32 most significant bits of the generator polynomial.

## `ao_rngp_poly_lo`

```c
#define ao_rngp_poly_lo() (RNGPOLY1)
```

Gets the 32 least significant bits of the generator polynomial.

## `ao_rngp_poly_lo_set`

```c
#define ao_rngp_poly_lo_set(x) \
{                              \
    RNGPOLY1 = (uint32_t) (x); \
}
```

Sets the 32 least significant bits of the generator polynomial.

## `ao_rngp_seed`

```c
#define ao_rngp_seed(x) ao_rngp_value_set(x)
```

Sets the seed.

## `ao_rngp_seed_hi`
## `ao_rngp_seed_lo`

```c
#define ao_rngp_seed_hi(x) ao_rngp_value_hi_set(x)
#define ao_rngp_seed_lo(x) ao_rngp_value_lo_set(x)
```

Sets the 32 most or least significant bits, respectively, of the seed.

## `ao_rngp_seed_true`

```c
#define ao_rngp_seed_true(x) \
{                            \
    RNGCONbits.LOAD = 1;     \
}
```

Sets up to load the value generated by true random number generator as a seed to the pseudo-random number generator.

## `ao_rngp_value`

```c
#define ao_rngp_value()             \
(                                   \
    ((uint64_t) RNGNUMGEN2 << 32) | \
     (uint64_t) RNGNUMGEN1          \
)
```

Gets the generated value.

## `ao_rngp_value_set`

```c
#define ao_rngp_value_set(x)                                          \
{                                                                     \
    RNGNUMGEN2 = (uint32_t) (((uint64_t) (x) >> 32) & 0xFFFFFFFFULL); \
    RNGNUMGEN1 = (uint32_t) (((uint64_t) (x) >>  0) & 0xFFFFFFFFULL); \
}
```

Sets the generated value.

## `ao_rngp_value_hi`

```c
#define ao_rngp_value_hi() (RNGNUMGEN2)
```

Gets the 32 most significant bits of the generated value.

## `ao_rngp_value_hi_set`

```c
#define ao_rngp_value_hi_set(x)  \
{                                \
    RNGNUMGEN2 = (uint32_t) (x); \
}
```

Sets the 32 most significant bits of the generated value.

## `ao_rngp_value_lo`

```c
#define ao_rngp_value_lo() (RNGNUMGEN1)
```

Gets the 32 least significant bits of the generated value.

## `ao_rngp_value_lo_set`

```c
#define ao_rngp_value_lo_set(x)  \
{                                \
    RNGNUMGEN1 = (uint32_t) (x); \
}
```

Sets the 32 least significant bits of the generated value.
