---
author: "Stefan Wagner"
date: 2022-08-15
description: "The ao_alloc_1.h module of the ao real-time operating system."
draft: true
permalink: /modules/alloc-1/
title: "ao_alloc_1.h"
---

# ao_alloc_1.h

This module implements an [allocator](../allocator.md) that supplies memory blocks from configurated memory pools.

## Configuration

## Types

### Pool

### Pool Node

## Type Overrides

### Acquired

### Released

### Retained

## Variables

The module exposes the following global variables.

| Variable | |
|----------|-|
| `ao_alloc_allocated` | The current number of allocated bytes. This variable is absent, if both the `AO_ALLOC_ALLOCATED` and `AO_ALLOC_ALLOCATED_MAX` configuration options are disabled. |
| `ao_alloc_allocated_max` | The maximum number of allocated bytes. This variable is absent, if the `AO_ALLOC_ALLOCATED_MAX` configuration option is disabled. |
| `ao_alloc_free` | The current number of free bytes. This variable is absent, if both the `AO_ALLOC_FREE` and `AO_ALLOC_FREE_MIN` configuration options are disabled. |
| `ao_alloc_free_min` | The minimum number of free bytes. This variable is absent, if the `AO_ALLOC_FREE_MIN` configuration option is disabled. |
| `ao_alloc_pool_0` | Pool 0. This variable is absent, if the configured block count of the pool is zero or if the configured block size of the pool is zero or if the `size_t` type has less than 1 bit. |
| `ao_alloc_pool_1` | Pool 1. This variable is absent, if the configured block count of the pool is zero or if the configured block size of the pool is zero or if the `size_t` type has less than 2 bits. |
| ... | ... |
| `ao_alloc_pool_63` | Pool 63. This variable is absent, if the configured block count of the pool is zero or if the configured block size of the pool is zero or if the `size_t` type has less than 64 bits. |
