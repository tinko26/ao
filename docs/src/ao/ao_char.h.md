---
api: true
author: "Stefan Wagner"
date: 2022-08-29
description: "The /src/ao/ao_char.h file of the ao real-time operating system."
draft: true
permalink: /src/ao/ao_char.h/ 
subtitle: ""
title: "ao_char.h"
toc: true
---

# Overview

...

# Includes

```c
#include <stdbool.h>

#ifndef AO_CHAR

#define AO_CHAR

#endif

#ifndef ao_char_is_alphanumeric

bool    ao_char_is_alphanumeric(char x);

#endif

#ifndef ao_char_is_alphabetic

bool    ao_char_is_alphabetic(  char x);

#endif

#ifndef ao_char_is_blank

bool    ao_char_is_blank(       char x);

#endif

#ifndef ao_char_is_control

bool    ao_char_is_control(     char x);

#endif

#ifndef ao_char_is_decimal

bool    ao_char_is_decimal(     char x);

#endif

#ifndef ao_char_is_graphical

bool    ao_char_is_graphical(   char x);

#endif

#ifndef ao_char_is_hexadecimal

bool    ao_char_is_hexadecimal( char x);

#endif

#ifndef ao_char_is_lower

bool    ao_char_is_lower(       char x);

#endif

#ifndef ao_char_is_printable

bool    ao_char_is_printable(   char x);

#endif

#ifndef ao_char_is_punctuation

bool    ao_char_is_punctuation( char x);

#endif

#ifndef ao_char_is_upper

bool    ao_char_is_upper(       char x);

#endif

#ifndef ao_char_is_whitespace

bool    ao_char_is_whitespace(  char x);

#endif

```
