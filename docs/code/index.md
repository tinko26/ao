---
author: "Stefan Wagner"
date: 2022-08-08
description: "The Source Code of the ao Real-Time Operating System (RTOS)."
draft: true
permalink: /code/
title: "Code"
---

# Code

## Location

The source code of the real-time operating system is located in the repository's `src` folder.

## Packages

The source code is subdivided into C files and folders containing header files. Thereby, folders and corresponding C files constitute the following three packages.

### Environment Package

**Folder:** `ao`

**File:** `ao.c`

The environment package is an extension to the freestanding runtime environment. It provides environment constants and variables, type definitions, support for debugging, as well as plenty of useful functions and data structures.

### Kernel Package

**Folder:** `ao_sys`

**File:** `ao_sys.c`

The kernel package provides functions for timing, multi-tasking, real-time scheduling, inter-process communication, synchronization, and dynamic memory management.

### Port Package

**Folders:** `ao_sys_xc32*`

**File:** `ao_sys_xc32_pic32.c`

This package contains a port targeting PIC32 microcontrollers using the XC32 compiler.

### Modules

...
