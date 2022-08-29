---
author: "Stefan Wagner"
breadcrumbs: 2
date: 2022-08-29
description: "The ao/ao_assert.h module of the ao real-time operating system."
draft: true
permalink: /ao/ao_assert.h/ 
subtitle: "<code>ao</code>"
title: "<code>ao_assert.h</code>"
toc: true
---

#ifndef ao_assert

#define ao_assert(exp)                                                      \
{                                                                           \
        if (!(exp))                                                         \
        {                                                                   \
            ao_break();                                                     \
        }                                                                   \
}

#endif

