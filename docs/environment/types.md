---
author: "Stefan Wagner"
date: 2022-08-13
description: ""
draft: false
permalink: /environment/types/
title: "Types"
---

# Types

Based on the language-defined types, the standard library defines plenty of arithmetic types for specific purposes. The use of these types in embedded applications is strongly encouraged by several industrial coding standards, especially fixed-width integer types. 

Yet, in order to improve platform independency and portability, the environment package defines its own types for floating-point numbers as well as signed and unsigned integers. Additionally, it defines some commonplace function types.

| Module | |
|--------|-|
| [`ao_float.h`](float.md) | Defines the fastest floating-point type of the target platform and mathematical operations for that type. |
| [`ao_func.h`](func.md) | Defines general-purpose function types. |
| [`ao_int.h`](int.md) | Defines the fastest signed integer type of the target platform, along with a couple of properties thereof. |
| [`ao_rand.h`](rand.md) | Defines random value generator types. |
| [`ao_size.h`](size.md) | Defines properties of and useful operations for the standard library's `size_t` type. Especially, these definitions are required by the allocators. |
| [`ao_uint.h`](uint.md) | Defines the fastest unsigned integer type of the target platform, along with a couple of properties thereof. Additionally, it defines useful operations, such as calculating the base-2 logarithm. |
