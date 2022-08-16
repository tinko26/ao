---
author: "Stefan Wagner"
date: 2022-08-16
description: "Synchronization in the ao real-time operating system."
draft: true
permalink: /synchronization/
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
- task does not directly wait for a resources, but uses a proxy object that represents the waiting.
- the proxy can be allocated on the stack
- the proxy encapsulates an asynchronous event and all other information about the waiting (e.g. result)
- the proxy concept allows to clearly separate three stages of waiting: (1) begin or prepare (2) block (3) end or follow up.
- that separation, in turn, allows to begin a multitude of waitings, then block only once in order to await (any subset) of the respective asynchronous events, then end the multitude of waitings. 
- this leads to greater flexibility in task design and less context switches / overhead

- the typical synchronization API
  
- wait_begin(proxy) ... begin, not blocking
- wait_end(proxy) ... end, not blocking
- in between, there is supposed to be a call to ao_await(), that might block.

- wait(resource, timeout) ... begin, block until timeout expires, end
- wait_from(resource, timeout, beginning) ... begin, block until timeout expires, end

- wait_forever(resource) ... begin, block indefinitely, end

- wait_try(resource) ... begin, end

## Primitives

The following modules provide synchronization primitives.

| Module | |
|--------|-|
| [`ao_are.h`](modules/are.md) | Auto-reset events. |
| [`ao_barrier.h`](modules/barrier.md) | Execution barriers where tasks can meet. |
| [`ao_bsem.h`](modules/bsem.md) | Binary semaphores. |
| [`ao_cond.h`](modules/cond.md) | Condition variables. |
| [`ao_counter.h`](modules/counter.md) | Counters. |
| [`ao_flag.h`](modules/flag.md) | Flags. |
| [`ao_mail.h`](modules/mail.md) | Mail for asynchronous messaging. |
| [`ao_monitor.h`](modules/monitor.md) | Monitors. |
| [`ao_mutex.h`](modules/mutex.md) | Mutexes. |
| [`ao_pmail.h`](modules/pmail.md) | Priority mail for asynchronous messaging. |
| [`ao_queue4obj.h`](modules/queue4obj.md) | Priority queues for objects. |
| [`ao_queue4ptr.h`](modules/queue4ptr.md) | Priority queues for pointers. |
| [`ao_recv.h`](modules/recv.md) | Receiving bytes. |
| [`ao_recv_obj.h`](modules/recv-obj.md) | Receiving objects. |
| [`ao_recv_ptr.h`](modules/recv-ptr.md) | Receiving pointers. |
| [`ao_rendezvous.h`](modules/rendezvous.md) | Rendezvous. |
| [`ao_rw.h`](modules/rw.md) | Readers-writer locks preferring readers. |
| [`ao_sem.h`](modules/sem.md) | Counting semaphores. |
| [`ao_send.h`](modules/send.md) | Sending bytes. |
| [`ao_send_obj.h`](modules/send-obj.md) | Sending objects. |
| [`ao_send_ptr.h`](modules/send-ptr.md) | Sending pointers. |
| [`ao_signal.h`](modules/signal.md) | Signals. |
| [`ao_sleep.h`](modules/sleep.md) | Sleeping. |
| [`ao_stream.h`](modules/stream.md) | Streams for bytes. |
| [`ao_stream4obj.h`](modules/stream4obj.md) | Streams for objects. |
| [`ao_stream4ptr.h`](modules/stream4ptr.md) | Streams for pointers. |
| [`ao_threshold.h`](modules/threshold.md) | Thresholds. |
| [`ao_wr.h`](modules/wr.md) | Readers-writer locks preferring writers. |
| [`ao_xch.h`](modules/xch.md) | Exchanges for client-server messaging. |
