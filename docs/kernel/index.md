---
author: "Stefan Wagner"
date: 2022-08-12
description: "The Kernel Package of the ao Real-Time Operating System (RTOS)."
draft: true
permalink: /kernel/
title: "Kernel"
---

# Kernel

## General

- kernel space only, no user space

## Booting

- boot
- main

## CPU

- [core](core.md)

## Interrupts

- [ir](ir.md)

## Locking

- [lock](lock.md)

## Timing

- [Timing](timing.md).

- [hardware counter](count.md)
- [time](time.md)
- [alarms](alarm.md)
- [alarm queue](alarm-queue.md)
- [timer](timer.md)
- [spinning](spin.md)

## Memory

- [stack](stack.md)
- allocators

## Multitasking

- [Multitasking](multitasking.md)

- blocking
- context
- diagnostics (count, time, id, name)
- entry
- procedure
- [schedulers](task-sched.md)
- self
- stack
- state
- [task](task.md)
- yield
  
## Synchronization and IPC

- asynchronous events (async, await, poll)
- auto-reset event
- barrier
- binary semaphore
- condition variable
- counter
- flag
- mail
- monitor
- mutex
- priority mail
- queue
- receiving
- rendezvous
- readers-writer lock
- semaphore
- sending
- signal
- sleep
- stream
- threshold
- exchange

## Hardware

- [buttons](buttons.md)
- [LEDs](leds.md)
