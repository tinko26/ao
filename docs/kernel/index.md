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

- [booting](boot.md)
- [cores](core.md)
- [critical sections](lock.md)
- [interrupts](ir.md)
- [system identifiers](sys.md)

## Memory Management

- [memory management](memory-management.md)

- [allocators](alloc.md)

## Timing

- [Timing](timing.md)

- [hardware counter](count.md)
- [time](time.md)
- [alarms](alarm.md)
- [alarm queue](alarm-queue.md)
- [timer](timer.md)
- [spinning](spin.md)

## Multitasking

- main function is a task, no need to explicitly start the scheduler
  
- [Multitasking](multitasking.md)

- [blocking](block.md)
- main task
- [self](self.md)
- [stacks](stack.md)
- [task](task.md)
- [task context](task-context.md)
- task diagnostics (count, time, id, name)
- task entry
- task procedures
- [task schedulers](task-sched.md)
- [task stack](task-stack.md)
- task states
- [yielding](yield.md)
  
## Synchronization and IPC

**Building Blocks**

- [synchronization](synchronization.md)

- [asynchronous events](async.md)
- [awaiting](await.md)
- [polling](poll.md)

**Primitives**

- [auto-reset events](are.md)
- [barriers](barrier.md)
- [binary semaphores](bsem.md)
- [condition variables](cond.md)
- [counters](counter.md)
- [counting semaphores](sem.md)
- [exchanges](xch.md)
- [flags](flag.md)
- [mail](mail.md)
- [monitors](monitor.md)
- [mutexes](mutex.md)
- [priority mail](pmail.md)
- [queues for objects](queue4obj.md)
- [queues for pointers](queue4ptr.md)
- [readers-writer locks preferring readers](rw.md)
- [readers-writer locks preferring writers](wr.md)
- [receiving data](recv.md)
- [receiving data from callbacks](recv-from-callback.md)
- [receiving data from streams](recv-from-stream.md)
- [receiving objects](recv-obj.md)
- [receiving objects from callbacks](recv-obj-from-callback.md)
- [receiving objects from queues](recv-obj-from-queue.md)
- [receiving objects from streams](recv-obj-from-stream.md)
- [receiving pointers](recv-ptr.md)
- [receiving pointers from callbacks](recv-ptr-from-callback.md)
- [receiving pointers from queues](recv-ptr-from-queue.md)
- [receiving pointers from streams](recv-ptr-from-stream.md)
- [rendezvous](rendezvous.md)
- [sending data](send.md)
- [sending data to callbacks](send-to-callback.md)
- [sending data to streams](send-to-stream.md)
- [sending objects](send-obj.md)
- [sending objects to callbacks](send-obj-to-callback.md)
- [sending objects to queues](send-obj-to-queue.md)
- [sending objects to streams](send-obj-to-stream.md)
- [sending pointers](send-ptr.md)
- [sending pointers to callbacks](send-ptr-to-callback.md)
- [sending pointers to queues](send-ptr-to-queue.md)
- [sending pointers to streams](send-ptr-to-stream.md)
- [signals](signal.md)
- [sleeping](sleep.md)
- [streams](stream.md)
- [streams for objects](stream4obj.md)
- [streams for pointers](stream4ptr.md)
- [threshold](threshold.md)

## Drivers

- [drivers](drivers.md)

- [buttons](buttons.md)
- [LEDs](leds.md)
