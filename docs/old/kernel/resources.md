---
author: "Stefan Wagner"
date: 2022-08-13
description: ""
draft: true
permalink: /kernel/resources/
title: "Resources"
---

# Resources

## Management

- in general, the kernel does not track resources, except for specific situations
- does not keep track of tasks, unless they are active (care of taken by the scheduler) or blocked (care of taken indirectly by an alarm, if any). 
- advantage: save time and memory, no need for create() and delete() methods, memory for resources can be allocated automatically or manually --> freedom
- disadvantage: resources must be tracked by the application.

## Allocation and Deallocation

- up to the application, see [memory](memory.md)

## Initialization

- kernel assumes, that resources provided by the application are always in a valid state.
- initialization is zeroing plus setting some members

## Resource Leaks

- must be prevented by the application

## Resource Contention

- must be resolved by the application
- the kernel simply provides the means therefore, such as mutexes.

