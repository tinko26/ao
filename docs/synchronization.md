---
author: "Stefan Wagner"
date: 2022-09-27
draft: true
permalink: /synchronization/
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

| [`ao_are.h`](api/src/ao_sys/ao_are.h.md) | Auto-reset events. |
| [`ao_barrier.h`](api/src/ao_sys/ao_barrier.h.md) | Execution barriers where tasks can meet. |
| [`ao_bsem.h`](api/src/ao_sys/ao_bsem.h.md) | Binary semaphores. |
| [`ao_cond.h`](api/src/ao_sys/ao_cond.h.md) | Condition variables. |
| [`ao_mail.h`](api/src/ao_sys/ao_mail.h.md) | Mail for asynchronous messaging. |
| [`ao_monitor.h`](api/src/ao_sys/ao_monitor.h.md) | Monitors. |
| [`ao_mre.h`](api/src/ao_sys/ao_mre.h.md) | Manual-reset events. |
| [`ao_mutex.h`](api/src/ao_sys/ao_mutex.h.md) | Mutexes. |
| [`ao_num.h`](api/src/ao_sys/ao_num.h.md) | Numbers based on the fastest unsigned integer type. |
| [`ao_num8.h`](api/src/ao_sys/ao_num8.h.md) | Numbers based on the 8-bit unsigned integer type. |
| [`ao_num16.h`](api/src/ao_sys/ao_num16.h.md) | Numbers based on the 16-bit unsigned integer type. |
| [`ao_num32.h`](api/src/ao_sys/ao_num32.h.md) | Numbers based on the 32-bit unsigned integer type. |
| [`ao_num64.h`](api/src/ao_sys/ao_num64.h.md) | Numbers based on the 64-bit unsigned integer type. |
| [`ao_pmail.h`](api/src/ao_sys/ao_pmail.h.md) | Priority mail for asynchronous messaging. |
| [`ao_queue4acq.h`](api/src/ao_sys/ao_queue4acq.h.md) | Priority queues for acquired memory blocks. |
| [`ao_queue4obj.h`](api/src/ao_sys/ao_queue4obj.h.md) | Priority queues for objects. |
| [`ao_queue4ptr.h`](api/src/ao_sys/ao_queue4ptr.h.md) | Priority queues for pointers. |
| [`ao_recv.h`](api/src/ao_sys/ao_recv.h.md) | Receiving bytes. |
| [`ao_recv_acq.h`](api/src/ao_sys/ao_recv_acq.h.md) | Receiving acquired memory blocks. |
| [`ao_recv_obj.h`](api/src/ao_sys/ao_recv_obj.h.md) | Receiving objects. |
| [`ao_recv_ptr.h`](api/src/ao_sys/ao_recv_ptr.h.md) | Receiving pointers. |
| [`ao_rendezvous.h`](api/src/ao_sys/ao_rendezvous.h.md) | Rendezvous. |
| [`ao_rw.h`](api/src/ao_sys/ao_rw.h.md) | Readers-writer locks preferring readers. |
| [`ao_sem.h`](api/src/ao_sys/ao_sem.h.md) | Counting semaphores. |
| [`ao_send.h`](api/src/ao_sys/ao_send.h.md) | Sending bytes. |
| [`ao_send_acq.h`](api/src/ao_sys/ao_send_acq.h.md) | Sending acquired memory blocks. |
| [`ao_send_obj.h`](api/src/ao_sys/ao_send_obj.h.md) | Sending objects. |
| [`ao_send_ptr.h`](api/src/ao_sys/ao_send_ptr.h.md) | Sending pointers. |
| [`ao_signal.h`](api/src/ao_sys/ao_signal.h.md) | Signals. |
| [`ao_sleep.h`](api/src/ao_sys/ao_sleep.h.md) | Sleeping. |
| [`ao_stream.h`](api/src/ao_sys/ao_stream.h.md) | Streams for bytes. |
| [`ao_stream4acq.h`](api/src/ao_sys/ao_stream4acq.h.md) | Streams for acquired memory blocks. |
| [`ao_stream4obj.h`](api/src/ao_sys/ao_stream4obj.h.md) | Streams for objects. |
| [`ao_stream4ptr.h`](api/src/ao_sys/ao_stream4ptr.h.md) | Streams for pointers. |
| [`ao_threshold.h`](api/src/ao_sys/ao_threshold.h.md) | Thresholds based on the fastest unsigned integer type. |
| [`ao_threshold8.h`](api/src/ao_sys/ao_threshold8.h.md) | Thresholds based on the 8-bit unsigned integer type. |
| [`ao_threshold16.h`](api/src/ao_sys/ao_threshold16.h.md) | Thresholds based on the 16-bit unsigned integer type. |
| [`ao_threshold32.h`](api/src/ao_sys/ao_threshold32.h.md) | Thresholds based on the 32-bit unsigned integer type. |
| [`ao_threshold64.h`](api/src/ao_sys/ao_threshold64.h.md) | Thresholds based on the 64-bit unsigned integer type. |
| [`ao_wr.h`](api/src/ao_sys/ao_wr.h.md) | Readers-writer locks preferring writers. |
| [`ao_xch.h`](api/src/ao_sys/ao_xch.h.md) | Exchanges for client-server messaging. |
