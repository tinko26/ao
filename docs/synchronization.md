---
author: "Stefan Wagner"
date: 2022-08-16
description: "Synchronization in the ao real-time operating system."
draft: true
permalink: /synchronization/
title: "Synchronization"
---

# Overview

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

# Primitives

The following modules provide synchronization primitives.

| [`ao_are.h`](src/ao_sys/ao_are.h.md) | Auto-reset events. |
| [`ao_barrier.h`](src/ao_sys/ao_barrier.h.md) | Execution barriers where tasks can meet. |
| [`ao_bsem.h`](src/ao_sys/ao_bsem.h.md) | Binary semaphores. |
| [`ao_cond.h`](src/ao_sys/ao_cond.h.md) | Condition variables. |
| [`ao_counter.h`](src/ao_sys/ao_counter.h.md) | Counters. |
| [`ao_flag.h`](src/ao_sys/ao_flag.h.md) | Flags. |
| [`ao_mail.h`](src/ao_sys/ao_mail.h.md) | Mail for asynchronous messaging. |
| [`ao_monitor.h`](src/ao_sys/ao_monitor.h.md) | Monitors. |
| [`ao_mutex.h`](src/ao_sys/ao_mutex.h.md) | Mutexes. |
| [`ao_pmail.h`](src/ao_sys/ao_pmail.h.md) | Priority mail for asynchronous messaging. |
| [`ao_queue4obj.h`](src/ao_sys/ao_queue4obj.h.md) | Priority queues for objects. |
| [`ao_queue4ptr.h`](src/ao_sys/ao_queue4ptr.h.md) | Priority queues for pointers. |
| [`ao_recv.h`](src/ao_sys/ao_recv.h.md) | Receiving bytes. |
| [`ao_recv_obj.h`](src/ao_sys/ao_recv_obj.h.md) | Receiving objects. |
| [`ao_recv_ptr.h`](src/ao_sys/ao_recv_ptr.h.md) | Receiving pointers. |
| [`ao_rendezvous.h`](src/ao_sys/ao_rendezvous.h.md) | Rendezvous. |
| [`ao_rw.h`](src/ao_sys/ao_rw.h.md) | Readers-writer locks preferring readers. |
| [`ao_sem.h`](src/ao_sys/ao_sem.h.md) | Counting semaphores. |
| [`ao_send.h`](src/ao_sys/ao_send.h.md) | Sending bytes. |
| [`ao_send_obj.h`](src/ao_sys/ao_send_obj.h.md) | Sending objects. |
| [`ao_send_ptr.h`](src/ao_sys/ao_send_ptr.h.md) | Sending pointers. |
| [`ao_signal.h`](src/ao_sys/ao_signal.h.md) | Signals. |
| [`ao_sleep.h`](src/ao_sys/ao_sleep.h.md) | Sleeping. |
| [`ao_stream.h`](src/ao_sys/ao_stream.h.md) | Streams for bytes. |
| [`ao_stream4obj.h`](src/ao_sys/ao_stream4obj.h.md) | Streams for objects. |
| [`ao_stream4ptr.h`](src/ao_sys/ao_stream4ptr.h.md) | Streams for pointers. |
| [`ao_threshold.h`](src/ao_sys/ao_threshold.h.md) | Thresholds. |
| [`ao_wr.h`](src/ao_sys/ao_wr.h.md) | Readers-writer locks preferring writers. |
| [`ao_xch.h`](src/ao_sys/ao_xch.h.md) | Exchanges for client-server messaging. |
