---
author: "Stefan Wagner"
date: 2022-08-12
description: "Memory Management in the ao Real-Time Operating System (RTOS)."
draft: true
permalink: /kernel/memory-management/
title: "Memory Management"
---

# Memory Management

## Static

- global constants (allocated in ram or rom by the toolchain, initialized at start-up)
- global variables (allocated in ram by the toolchain, initialized or zeroed at start-up)

- function-scope variables (allocated on the stack, not initialized automatically)

## Dynamic

- [allocators](alloc.md)
