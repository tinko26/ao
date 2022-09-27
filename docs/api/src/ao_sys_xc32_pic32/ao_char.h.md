---
author: "Stefan Wagner"
date: 2022-09-27
draft: true
permalink: /api/src/ao_sys_xc32_pic32/ao_char.h/
toc: true
---

# Notes

This module provides a couple of functions that classify characters. Although the standard library contains similar functions, they are not available in a freestanding runtime environment.

# Include

| `ctype.h` |
| `stdbool.h` |

# Functions

## `ao_char_is_*`

```c
#define ao_char_is_alphanumeric(x) (isalnum ((int) (x)) ? true : false)
#define ao_char_is_alphabetic(x)   (isalpha ((int) (x)) ? true : false)
#define ao_char_is_blank(x)        (isblank ((int) (x)) ? true : false)
#define ao_char_is_control(x)      (iscntrl ((int) (x)) ? true : false)
#define ao_char_is_decimal(x)      (isdigit ((int) (x)) ? true : false)
#define ao_char_is_graphical(x)    (isgraph ((int) (x)) ? true : false)
#define ao_char_is_hexadecimal(x)  (isxdigit((int) (x)) ? true : false)
#define ao_char_is_lower(x)        (islower ((int) (x)) ? true : false)
#define ao_char_is_printable(x)    (isprint ((int) (x)) ? true : false)
#define ao_char_is_punctuation(x)  (ispunct ((int) (x)) ? true : false)
#define ao_char_is_upper(x)        (isupper ((int) (x)) ? true : false)
#define ao_char_is_whitespace(x)   (isspace ((int) (x)) ? true : false)
```

Classifies a given character.
