---
author: "Stefan Wagner"
date: 2022-08-05
description: "Mathematics for Floating-Point Numbers in the ao Real-Time Operating System (RTOS)."
draft: false
permalink: /environment/mathf/
title: "Mathematics for Floating-Point Numbers"
---

# Mathematics for Floating-Point Numbers

The `ao_mathf.h` module contains mathematical constants and functions for floating-point numbers. 

Although the standard library provides such constants and functions, too, they are not available in a freestanding runtime environment. Then again, many toolchains provide implementations, either in software, or highly optimized for target platforms with an FPU.

Therefore, the environment package does not provide an implementation for most of the functions. Consequently, an implementation must be provided by a hardware-specific package by overriding this module.
