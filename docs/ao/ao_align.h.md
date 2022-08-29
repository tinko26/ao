---
author: "Stefan Wagner"
breadcrumbs: 2
date: 2022-08-29
description: "The ao/ao_align.h module of the ao real-time operating system."
draft: true
permalink: /ao/ao_align.h/ 
subtitle: "<code>ao</code>"
title: "<code>ao_align.h</code>"
toc: true
---

#ifndef AO_ALIGN_DOWN

#define AO_ALIGN_DOWN(x, b)     (((x) / (b)) * (b))

#endif

#ifndef AO_ALIGN_UP

#define AO_ALIGN_UP(x, b)       ((((x) + ((b) - 1)) / (b)) * (b))

#endif

#ifndef AO_IS_ALIGNED

#define AO_IS_ALIGNED(x, b)     ((x) % (b) ? false : true)

#endif

