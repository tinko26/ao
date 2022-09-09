---
author: "Stefan Wagner"
date: 2022-09-09
draft: true
permalink: /linear-feedback-shift-registers/
seealso:
- /api/src/ao/ao_lfsr.h/
toc: true
---

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
