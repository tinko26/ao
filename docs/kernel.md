---
author: "Stefan Wagner"
date: 2022-09-27
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
- [counter](counter.md)
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
- counting semaphores
- exchanges
- mail
- monitors
- mutexes
- numbers
- priority mail
- queues for acquired memory block
- queues for objects
- queues for pointers
- readers-writer locks preferring readers
- readers-writer locks preferring writers
- receiving
- receiving acquired memory blocks
- receiving objects
- receiving pointers
- rendezvous
- sending
- sending acquired memory blocks
- sending objects
- sending pointers
- signals
- sleeping
- streams
- streams for acquired memory blocks
- streams for objects
- streams for pointers
- thresholds

# Drivers

- CAN
- buttons
- [drivers](drivers.md)
- LEDs
