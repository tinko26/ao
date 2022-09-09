---
author: "Stefan Wagner"
date: 2022-09-09
draft: true
permalink: /strings/
seealso:
- /api/src/ao/ao_print.h/
- /api/src/ao/ao_scan.h/
toc: true
---

# Example (Printing)

```c
// String.
char s[128];

// String length.
size_t n = 128;

// Options.
ao_print_t o =
{
    .digits_fractional = 0,
    .digits_integral = 0,
    .precision = 4,
    .right = false,
    .sign = true,
    .width = 0
};

// Value.
double v = 1234.567;
```

```c
ao_printfd(s, n, &o, &v);
```

# Example (Scanning)

```c
// String.
char const * s = "The depth is -12.34567e+2 meters.";

// String length.
size_t n = 33;

// Options.
ao_scan_t o =
{
    .radix = 10,
    .seek = true
};

// Value.
double v;
```

```c
ao_scanfd(s, n, &o, &v);
```
