---
author: "Stefan Wagner"
date: 2022-08-13
draft: true
permalink: /memory/
---

# Memory

# Memory Management

- a form of resource management
- allocate memory upon

# Automatic Memory Management

- allocation and deallocation by runtime environment
- C RTE: global constants and variables, scoped variables
- beyond that, the runtime environment for application (that includes the kernel) does not provide further means for autmatic memory management.

# Manual Memory Management

- application explicitly allocates and deallocates memory
- thus, lifetime controlled by the application
- provides by the rtos via the allocators.

# Memory Protection

- none

# Memory Management

- dynamic = manual (malloc), lifetime controlled by app
- automatic (upon entering a new scope), lifetime controlled by rte (until leaving the scope)
- static, lifetime of the program, ie controlled by the rte

- geeksforgeeks: "Memory allocation is a process by which computer programs and services are assigned with physical or virtual memory space. The memory allocation is done either before or at the time of program execution."

# Manual Memory Management

- calling a dedicated function, such as malloc() for allocating from the heap or `alloca()` for allocating from the stack.
- the RTOS supports the heap variant, only

# Automatic Memory Management

- runtime environment is responsible for allocation and freeing.
- automatic allocation supported only for variables allocated globally or on the stack.
- automatic freeing supported only for variables allocated on the stack.
- automatic freeing not supported for memory allocated on the heap (so, no garbage collection)

- global constants (lifetime: eternally)
- global variables (lifetime: eternally)

- function-scope variables (lifetime: tied to the function)
- wiki: "the runtime environment ... automatically allocates memory in the call stack for non-static local variables of a function, called automatic variables, when the function is called, and automatically releases that memory when the function is exited."

# Static Memory Management

= compile-time memory allocation

- supported for automatically allocated memory, only.
- supported for global constants, global variables, and function-scope variables.

- lifetime of allocated memory is controlled by the runtime environment

# Dynamic Memory Management

= runtime memory allocation

- supported for manually allocated memory, only.
- [allocator](allocator.md)

- gnu: "You need dynamic allocation when the amount of memory you need, or how long you continue to need it, depends on factors that are not known before the program runs."

- lifetime of allocated memory is controlled by the application

# Reference Counting

- wiki: "is a programming technique of storing the number of references ... to a block of memory ..."
- wiki: "objects are reclaimed as soon as they can no longer be referenced ... In real-time applications or systems with limited memory, this is important to maintain responsiveness."
- wiki: "easy to implement"

# Manual Reference Counting

- rc initialized to 1 by ao_acquire()
- rc incremented by ao_retain()
- rc decremented by ao_release()

- memory block freed, as soon as rc reaches zero
