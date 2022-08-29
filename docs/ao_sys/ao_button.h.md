---
author: "Stefan Wagner"
breadcrumbs: 2
date: 2022-08-29
description: "The ao_sys/ao_button.h module of the ao real-time operating system."
draft: true
permalink: /ao_sys/ao_button.h/ 
subtitle: "<code>ao_sys</code>"
title: "<code>ao_button.h</code>"
toc: true
---

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

