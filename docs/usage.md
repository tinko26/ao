---
author: "Stefan Wagner"
date: 2022-08-09
description: "Usage of the ao real-time operating system."
draft: true
permalink: /usage/
toc: true
---

# Build system

1. must reference respective C files
2. must setup include directory hierarchy properly.

# Application

1. must provide ao.h, that includes all required modules (and excludes everything that is not needed, therefore saving space and minimizing the footprint).
2. must provide ao_boot() (in almost all but the simplest cases)
3. must provide several callbacks (optional)

# Main Function

1. must call ao_boot()
2. for it is a task itself, it should loop indefinitely or explicity ao_stop() itself.

## Main Function as Idle Task

```c
void main()
{
    ao_boot();

    while (1) { }
}
```

## Main Function as Idle Task in Low-Power System

```c
void main()
{
    ao_boot();

    while (1)
    {
        ao_sys_idle();
    }
}
```

## Main Function Stopping Itself

```c
void main()
{
    ao_boot();

    // Start another task.
    ao_task_start( /* ... */ );

    // Stop.
    ao_stop();
}
```

# Memory management

- everything static
- no need to allocate anything dynamically
- no "create" or "delete" functions

# Memory initialization

- basic initialization = clear object (set zeros)
- some data structures require the assignment of auxiliary objects (such as a store for buffers)
- global variables are zeroed on start-up.
