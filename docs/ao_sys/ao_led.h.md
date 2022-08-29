---
author: "Stefan Wagner"
breadcrumbs: 2
date: 2022-08-29
description: "The ao_sys/ao_led.h module of the ao real-time operating system."
draft: true
permalink: /ao_sys/ao_led.h/ 
subtitle: "<code>ao_sys</code>"
title: "<code>ao_led.h</code>"
toc: true
---

```c
typedef     enum    ao_leds_t   ao_leds_t;

#ifndef     AO_LED_COUNT

#define     AO_LED_COUNT        (0)

#endif

#ifndef     AO_LEDS

#define     AO_LEDS

enum        ao_leds_t
{
            AO_LEDS_ALL         = 0,

            AO_LEDS_NONE        = 0
};

#endif

ao_leds_t   ao_leds();

void        ao_leds_disable(    ao_leds_t x);

void        ao_leds_enable(     ao_leds_t x);

void        ao_leds_toggle(     ao_leds_t x);

```
