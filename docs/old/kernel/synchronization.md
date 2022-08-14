---
author: "Stefan Wagner"
date: 2022-08-12
description: ""
draft: true
permalink: /kernel/synchronization/
title: "Synchronization"
---

# Synchronization

- asynchronous events (checking, callbacks)

- awaiting a single asynchronous event
- difference to async-await pattern

- polling for a single asynchronous event

- awaiting or polling for one out many asynchronous events
- awaiting or polling for all out many asynchronous events

- proxies

- the typical synchronization API

## Primitives

The following modules provide synchronization primitives.

| Module | |
|--------|-|
| [`ao_are.h`](are.md) | Auto-reset events. |
| [`ao_barrier.h`](barrier.md) | Execution barriers where tasks can meet. |
| [`ao_bsem.h`](bsem.md) | Binary semaphores. |
| [`ao_cond.h`](cond.md) | Condition variables. |
| [`ao_counter.h`](counter.md) | Counters. |
| [`ao_flag.h`](flag.md) | Flags. |
| [`ao_mail.h`](mail.md) | Mail for asynchronous messaging. |
| [`ao_monitor.h`](monitor.md) | Monitors. |
| [`ao_mutex.h`](mutex.md) | Mutexes. |
| [`ao_pmail.h`](pmail.md) | Priority mail for asynchronous messaging. |
| [`ao_queue4obj.h`](queue4obj.md) | Priority queues for objects. |
| [`ao_queue4ptr.h`](queue4ptr.md) | Priority queues for pointers. |
| [`ao_rw.h`](rw.md) | Readers-writer locks preferring readers. |
| [`ao_recv.h`](recv.md) | Receiving bytes. |
| [`ao_recv_obj.h`](recv-obj.md) | Receiving objects. |
| [`ao_recv_ptr.h`](recv-ptr.md) | Receiving pointers. |
| [`ao_rendezvous.h`](rendezvous.md) | Rendezvous. |
| [`ao_sem.h`](sem.md) | Counting semaphores. |
| [`ao_send.h`](send.md) | Sending bytes. |
| [`ao_send_obj.h`](send-obj.md) | Sending objects. |
| [`ao_send_ptr.h`](send-ptr.md) | Sending pointers. |
| [`ao_signal.h`](signal.md) | Signals. |
| [`ao_sleep.h`](sleep.md) | Sleeping. |
| [`ao_stream.h`](stream.md) | Streams for bytes. |
| [`ao_stream4obj.h`](stream4obj.md) | Streams for objects. |
| [`ao_stream4ptr.h`](stream4ptr.md) | Streams for pointers. |
| [`ao_threshold.h`](threshold.md) | Thresholds. |
| [`ao_wr.h`](wr.md) | Readers-writer locks preferring writers. |
| [`ao_xch.h`](xch.md) | Exchanges for client-server messaging. |
