---
author: "Stefan Wagner"
date: 2022-09-20
draft: true
permalink: /api/src/ao_sys_xc32_pic32_rng/ao_rngt.h/
toc: true
---

# Notes

The true random number generator continuously generates new bits. Each new bit is shifted into the `RNGSEED` register from the right.

Old bit &larr; `RNGSEED2` &larr; `RNGSEED1` &larr; New bit.

## Example

```c
ao_leds_t ld;
ao_leds_t le;
```

```c
uint32_t v;
```

```c
ao_rngt_enable();

while (1)
{
    // Wait until 3 bits have been generated.
    while (ao_rngt_bits() < 3);

    // Read the random number.
    v = ao_rngt_value_lo();
    v = v & 0b111;

    // LEDs.

    le = AO_LEDS_NONE;
    ld = AO_LEDS_NONE;

    if (v & (1 << 0)) { le |= AO_LEDS_0; } else { ld |= AO_LEDS_0; }
    if (v & (1 << 1)) { le |= AO_LEDS_1; } else { ld |= AO_LEDS_1; }
    if (v & (1 << 2)) { le |= AO_LEDS_2; } else { ld |= AO_LEDS_2; }

    ao_leds_enable(le);
    ao_leds_disable(ld);

    // Spin.
    ao_spin(AO_MILLISECONDS(100));
}
```

# Include

| `stdint.h` |
| `xc.h` |

# Identifier

```c
#define AO_RNGT
```

# Functions

## `ao_rngt_enable`
## `ao_rngt_disable`

```c
#define ao_rngt_enable()  { RNGCONbits.TRNGEN = 1; }
#define ao_rngt_disable() { RNGCONbits.TRNGEN = 0; }
```

Enables or disables the true random number generator.

## `ao_rngt_bits`

```c
#define ao_rngt_bits() (RNGCNT)
```

Gets the number of bits that have been generate since the last read.

## `ao_rngt_value`

```c
#define ao_rngt_value()           \
(                                 \
    ((uint64_t) RNGSEED2 << 32) | \
     (uint64_t) RNGSEED1          \
)
```

Gets the generated value.

## `ao_rngt_value_hi`
## `ao_rngt_value_lo`

```c
#define ao_rngt_value_hi() (RNGSEED2)
#define ao_rngt_value_lo() (RNGSEED1)
```

Gets the most or least significant 32 bits, respectively, of the generated value.
