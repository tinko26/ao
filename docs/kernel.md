---
author: "Stefan Wagner"
date: 2022-08-13
draft: true
permalink: /kernel/
toc: true
---

# General

- [booting](booting.md)
- [cores](cores.md)
- [critical sections](critical-sections.md)
- [interrupts](interrupts.md)
- [memory](memory.md)
- [operating modes](operating-modes.md)
- [resources](resources.md)
- [system identifiers](api/src/ao_sys/ao_sys.h.md)

# Memory Management

- [allocator](allocator.md)

# Timing

- [alarm queue](alarm-queue.md)
- [alarms](alarms.md)
- [hardware counter](hardware-counter.md)
- [time](time.md)
- [timers](timers.md)
- [timing](timing.md)
- [spinning](spinning.md)

# Multitasking

- blocking
- main task - main function is a task, no need to explicitly start the scheduler
- [multitasking](multitasking.md)
- self
- stacks
- [tasks](tasks.md)
- [task context](task-context.md)
- task diagnostics (count, time, id, name)
- task entry
- task procedures
- [task scheduler](task-scheduler.md)
- [task stack](task-stack.md)
- task states
- yielding

# Synchronization and IPC

## Building Blocks

- asynchronous events
- awaiting
- polling
- [synchronization](synchronization.md)

## Primitives

- auto-reset events
- barriers
- binary semaphores
- condition variables
- counters
- counting semaphores
- exchanges
- flags
- mail
- monitors
- mutexes
- priority mail
- queues for objects
- queues for pointers
- readers-writer locks preferring readers
- readers-writer locks preferring writers
- receiving data
- receiving data from callbacks
- receiving data from streams
- receiving objects
- receiving objects from callbacks
- receiving objects from queues
- receiving objects from streams
- receiving pointers
- receiving pointers from callbacks
- receiving pointers from queues
- receiving pointers from streams
- rendezvous
- sending data
- sending data to callbacks
- sending data to streams
- sending objects
- sending objects to callbacks
- sending objects to queues
- sending objects to streams
- sending pointers
- sending pointers to callbacks
- sending pointers to queues
- sending pointers to streams
- signals
- sleeping
- streams
- streams for objects
- streams for pointers
- threshold

# Drivers

- buttons
- [drivers](drivers.md)
- LEDs
