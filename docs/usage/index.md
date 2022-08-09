---
author: "Stefan Wagner"
date: 2022-08-08
description: "Usage of the ao Real-Time Operating System (RTOS)."
draft: true
permalink: /usage/
title: "Usage"
---

# Usage

## build system

1. must reference respective C files
2. must setup include directory hierarchy accordingly.

## application

1. must provide ao.h
2. must provide ao_boot() (in almost all but the simplest cases)
3. must provide several callbacks (optional)

## main function

1. must call ao_boot()
2. for it is a task itself, it should loop indefinitely or explicity ao_stop() itself.

## main function as idle task.

```c
void main()
{
    ao_boot();

    while (1) { }
}
```

## main function as idle task in low-power system

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

## main function stopping itself

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
