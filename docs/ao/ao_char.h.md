---
author: "Stefan Wagner"
breadcrumbs: 2
date: 2022-08-29
description: "The ao/ao_char.h module of the ao real-time operating system."
draft: true
permalink: /ao/ao_char.h/ 
subtitle: "<code>ao</code>"
title: "<code>ao_char.h</code>"
toc: true
---

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

