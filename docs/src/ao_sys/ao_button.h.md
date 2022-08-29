---
api: true
author: "Stefan Wagner"
date: 2022-08-29
description: "The /src/ao_sys/ao_button.h file of the ao real-time operating system."
draft: true
permalink: /src/ao_sys/ao_button.h/ 
subtitle: ""
title: "ao_button.h"
toc: true
---

# Overview

...

# Includes

```c
typedef enum    ao_buttons_t    ao_buttons_t;

#ifndef AO_BUTTON_COUNT

#define AO_BUTTON_COUNT         (0)

#endif

#ifndef AO_BUTTONS

#define AO_BUTTONS

enum    ao_buttons_t
{
        AO_BUTTONS_ALL          = 0,

        AO_BUTTONS_NONE         = 0
};

#endif

ao_buttons_t

        ao_buttons();

```
