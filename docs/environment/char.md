---
author: "Stefan Wagner"
date: 2022-08-04
description: "Characters in the ao Real-Time Operating System (RTOS)."
draft: false
permalink: /environment/char/
title: "Characters"
---

# Characters

The `ao_char.h` module defines a couple of functions that classify characters. They are meant as a replacement for corresponding functions of the standard library, which are not part of a freestanding runtime environment.

The module defines the following functions.

| Function | |
|----------|-|
| `ao_char_is_alphanumeric()` | Checks if a character is alphanumeric |
| `ao_char_is_alphabetic()` | Checks if a character is alphabetic |
| `ao_char_is_blank()` | Checks if a character is a blank character |
| `ao_char_is_control()` | Checks if a character is a control character |
| `ao_char_is_decimal()` | Checks if a character is a decimal digit |
| `ao_char_is_graphical()` | Checks if a character is a graphical character |
| `ao_char_is_hexadecimal()` | Checks if a character is a hexadecimal digit |
| `ao_char_is_lower()` | Checks if a character is lowercase |
| `ao_char_is_printable()` | Checks if a character can be printed |
| `ao_char_is_punctuation()` | Checks if a character is a punctuation character |
| `ao_char_is_upper()` | Checks if a character is uppercase |
| `ao_char_is_whitespace()` | Checks if a character is a space character |
