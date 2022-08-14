---
author: "Stefan Wagner"
date: 2022-08-14
description: "The ao_char.h module of the ao real-time operating system."
draft: true
permalink: /modules/char/
title: "ao_char.h"
---

# ao_char.h

This module provides a couple of functions that classify characters. Although the standard library contains similar functions, they are not available in a freestanding runtime environment.

## Functions

Check if a character is alphanumeric.

```c
bool ao_char_is_alphanumeric(bool x);
```

Check if a character is alphabetic.

```c
bool ao_char_is_alphabetic(bool x);
```

Check if a character is a blank character.

```c
bool ao_char_is_blank(bool x);
```

Check if a character is a control character.

```c
bool ao_char_is_control(bool x);
```

Check if a character is a decimal digit.

```c
bool ao_char_is_decimal(bool x);
```

Check if a character is a graphical character.

```c
bool ao_char_is_graphical(bool x);
```

Check if a character is a hexadecimal digit.

```c
bool ao_char_is_hexadecimal(bool x);
```

Check if a character is lowercase.

```c
bool ao_char_is_lower(bool x);
```

Check if a character can be printed.

```c
bool ao_char_is_printable(bool x);
```

Check if a character is a punctuation character.

```c
bool ao_char_is_punctuation(bool x);
```

Check if a character is uppercase.

```c
bool ao_char_is_upper(bool x);
```

Check if a character is a space character.

```c
bool ao_char_is_whitespace(bool x);
```
