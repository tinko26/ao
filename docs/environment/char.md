---
author: "Stefan Wagner"
date: 2022-08-05
description: "Characters in the ao Real-Time Operating System (RTOS)."
draft: false
permalink: /environment/char/
title: "Characters"
---

# Characters

The `ao_char.h` module defines a couple of functions that classify characters. They are meant as a replacement for corresponding functions of the standard library, which are not part of a freestanding runtime environment.

## Functions

Check if a character is alphanumeric.

```c
if (ao_char_is_alphanumeric(x)) { }
```

Check if a character is alphabetic.

```c
if (ao_char_is_alphabetic(x)) { }
```

Check if a character is a blank character.

```c
if (ao_char_is_blank(x)) { }
```

Check if a character is a control character.

```c
if (ao_char_is_control(x)) { }
```

Check if a character is a decimal digit.

```c
if (ao_char_is_decimal(x)) { }
```

Check if a character is a graphical character.

```c
if (ao_char_is_graphical(x)) { }
```

Check if a character is a hexadecimal digit.

```c
if (ao_char_is_hexadecimal(x)) { }
```

Check if a character is lowercase.

```c
if (ao_char_is_lower(x)) { }
```

Check if a character can be printed.

```c
if (ao_char_is_printable(x)) { }
```

Check if a character is a punctuation character.

```c
if (ao_char_is_punctuation(x)) { }
```

Check if a character is uppercase.

```c
if (ao_char_is_upper(x)) { }
```

Check if a character is a space character.

```c
if (ao_char_is_whitespace(x)) { }
```
