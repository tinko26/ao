---
author: "Stefan Wagner"
date: 2022-09-24
draft: true
permalink: /api/src/ao/ao_char.h/
toc: true
---

# Notes

This module provides a couple of functions that classify characters. Although the standard library contains similar functions, they are not available in a freestanding runtime environment.

# Include

| `stdbool.h` |

# Functions

## `ao_char_is_*`

```c
bool ao_char_is_alphanumeric(char x);
bool ao_char_is_alphabetic  (char x);
bool ao_char_is_blank       (char x);
bool ao_char_is_control     (char x);
bool ao_char_is_decimal     (char x);
bool ao_char_is_graphical   (char x);
bool ao_char_is_hexadecimal (char x);
bool ao_char_is_lower       (char x);
bool ao_char_is_printable   (char x);
bool ao_char_is_punctuation (char x);
bool ao_char_is_upper       (char x);
bool ao_char_is_whitespace  (char x);
```

Classifies a given character.
