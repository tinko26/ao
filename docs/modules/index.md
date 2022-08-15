---
author: "Stefan Wagner"
date: 2022-08-15
description: "The modules of the ao real-time operating system."
draft: true
permalink: /modules/
title: "Modules"
---

# Modules

| Module | | |
|--------|-|-|
| [`ao_alarm.h`](alarm.md) | Alarms |
| [`ao_alarm_queue.h`](alarm-queue.md) | Alarm queue |
| [`ao_alarm_queue_0.h`](alarm-queue-0.md) | Alarm queue stub | ✅ |
| [`ao_alarm_queue_1.h`](alarm-queue-1.md) | Alarm queue based on a sorted list | ✅ |
| [`ao_alarm_queue_2.h`](alarm-queue-2.md) | Alarm queue based on an array-based heap  | ✅ |
| [`ao_alarm_queue_3.h`](alarm-queue-3.md) | Alarm queue based on a pointer-based heap | ✅ |
| [`ao_alarm_queue_4.h`](alarm-queue-4.md) | Alarm queue based on an AVL tree | ✅ |
| [`ao_alarm_queue_5.h`](alarm-queue-5.md) | Alarm queue based on a red-black tree | ✅ |
| [`ao_align.h`](align.md) | Memory alignment | ✅ |
| [`ao_alloc.h`](alloc.md) | Allocator |
| [`ao_alloc_0.h`](alloc-0.md) | Allocator stub |
| [`ao_alloc_1.h`](alloc-1.md) | Allocator based on pools of fixed-size memory blocks |
| [`ao_alloc_2.h`](alloc-2.md) | Allocator based on the two-level segregated fit algorithm |
| [`ao_are.h`](are.md) | Auto-reset events |
| [`ao_assert.h`](assert.md) | Runtime assertions | ✅ |
| [`ao_async.h`](async.md) | Asynchronous events |
| [`ao_avl.h`](avl.md) | AVL trees | ✅ |
| [`ao_await.h`](await.md) | Awaiting |
| [`ao_barrier.h`](barrier.md) | Barriers |
| [`ao_block.h`](block.md) | Blocking |
| [`ao_boot.h`](boot.md) | Booting |
| [`ao_break.h`](break.md) | Breakpoints | ✅ |
| [`ao_bsem.h`](bsem.md) | Binary semaphores |
| [`ao_buffer.h`](buffer.md) | Buffers | ✅ |
| [`ao_buffer4obj.h`](buffer4obj.md) | Buffers for objects | ✅ |
| [`ao_buffer4ptr.h`](buffer4ptr.md) | Buffers for pointers | ✅ |
| [`ao_button.h`](button.md) | Buttons |
| [`ao_char.h`](char.md) | Characters | ✅ |
| [`ao_cond.h`](cond.md) | Condition variables |
| [`ao_core.h`](core.md) | Processor cores | ✅ |
| [`ao_count.h`](count.md) | Hardware counter | ✅ |
| [`ao_counter.h`](counter.md) | Counters |
| [`ao_debug.h`](debug.md) | Debug mode | ✅ |
| [`ao_flag.h`](flag.md) | Flags |
| [`ao_float.h`](float.md) | Floating-point numbers | ✅ |
| [`ao_func.h`](func.md) | Function pointer types | ✅ |
| [`ao_heap.h`](heap.md) | Pointer-based heaps | ✅ |
| [`ao_heap4obj.h`](heap4obj.md) | Array-based heaps for objects | ✅ |
| [`ao_heap4ptr.h`](heap4ptr.md) | Array-based heaps for pointers | ✅ |
| [`ao_int.h`](int.md) | Signed integers | ✅ |
| [`ao_ir.h`](ir.md) | Interrupts | ✅ |
| [`ao_ir_alarm.h`](ir-alarm.md) | Alarm interrupt | ✅ |
| [`ao_ir_task.h`](ir-task.md) | Task switch interrupts | ✅ |
| [`ao_led.h`](led.md) | LEDs |
| [`ao_lfsr.h`](lfsr.md) | Linear-feedback shift registers | ✅ |
| [`ao_list.h`](list.md) | Doubly linked lists | ✅ |
| [`ao_lock.h`](lock.md) | Locks | ✅ |
| [`ao_mail.h`](mail.md) | Mail for asynchronous messaging |
| [`ao_math.h`](math.md) | Mathematics | ✅ |
| [`ao_mathf.h`](mathf.md) | Mathematics for floating-point numbers | ✅ |
| [`ao_mem.h`](mem.md) | Memory blocks | ✅ |
| [`ao_monitor.h`](monitor.md) | Monitors |
| [`ao_mutex.h`](mutex.md) | Mutexes |
| [`ao_pmail.h`](pmail.md) | Priority mail for asynchronous messaging |
| [`ao_poll.h`](poll.md) | Polling for asynchronous events |
| [`ao_print.h`](print.md) | Converting numbers to string | ✅ |
| [`ao_queue4obj.h`](queue4obj.md) | Queues for objects |
| [`ao_queue4ptr.h`](queue4ptr.md) | Queues for pointers |
| [`ao_rand.h`](rand.md) | Random value generators | ✅ |
| [`ao_rb.h`](rb.md) | Red-black trees | ✅ |
| [`ao_recv.h`](recv.md) | Receiving |
| [`ao_recv_from_callback.h`](recv-from-callback.md) | Receiving from callbacks |
| [`ao_recv_from_stream.h`](recv-from-stream.md) | Receiving from streams |
| [`ao_recv_obj.h`](recv-obj.md) | Receiving objects |
| [`ao_recv_obj_from_callback.h`](recv-obj-from-callback.md) | Receiving objects from callbacks |
| [`ao_recv_obj_from_queue.h`](recv-obj-from-queue.md) | Receiving objects from queues |
| [`ao_recv_obj_from_stream.h`](recv-obj-from-stream.md) | Receiving objects from streams |
| [`ao_recv_ptr.h`](recv-ptr.md) | Receiving pointers |
| [`ao_recv_ptr_from_callback.h`](recv-ptr-from-callback.md) | Receiving pointers from callbacks |
| [`ao_recv_ptr_from_queue.h`](recv-ptr-from-queue.md) | Receiving pointers from queues |
| [`ao_recv_ptr_from_stream.h`](recv-ptr-from-stream.md) | Receiving pointers from streams |
| [`ao_rendezvous.h`](rendezvous.md) | Rendezvous |
| [`ao_rw.h`](rw.md) | Readers-writer locks preferring readers |
| [`ao_scan.h`](scan.md) | Converting numbers from string | ✅ |
| [`ao_self.h`](self.md) | Running task |
| [`ao_sem.h`](sem.md) | Counting semaphores |
| [`ao_send.h`](send.md) | Sending |
| [`ao_send_obj.h`](send-obj.md) | Sending objects |
| [`ao_send_obj_to_callback.h`](send-obj-to-callback.md) | Sending objects to callbacks |
| [`ao_send_obj_to_queue.h`](send-obj-to-queue.md) | Sending objects to queues |
| [`ao_send_obj_to_stream.h`](send-obj-to-stream.md) | Sending objects to streams |
| [`ao_send_ptr.h`](send-ptr.md) | Sending pointers |
| [`ao_send_ptr_to_callback.h`](send-ptr-to-callback.md) | Sending pointers to callbacks |
| [`ao_send_ptr_to_queue.h`](send-ptr-to-queue.md) | Sending pointers to queues |
| [`ao_send_ptr_to_stream.h`](send-ptr-to-stream.md) | Sending pointers to streams |
| [`ao_send_to_callback.h`](send-to-callback.md) | Sending to callbacks |
| [`ao_send_to_stream.h`](send-to-stream.md) | Sending to streams |
| [`ao_signal.h`](signal.md) | Signals |
| [`ao_size.h`](size.md) | Sizes | ✅ |
| [`ao_sleep.h`](sleep.md) | Sleeping |
| [`ao_slist.h`](slist.md) | Sorted doubly linked lists | ✅ |
| [`ao_spin.h`](spin.md) | Spinning | ✅ |
| [`ao_stack.h`](stack.md) | Stacks | ✅ |
| [`ao_stream.h`](stream.md) | Streams |
| [`ao_stream4obj.h`](stream4obj.md) | Streams for objects |
| [`ao_stream4ptr.h`](stream4ptr.md) | Streams for pointers |
| [`ao_struct.h`](struct.md) | Structs | ✅ |
| [`ao_sys.h`](sys.md) | System | ✅ |
| [`ao_task.h`](task.md) | Tasks |
| [`ao_task_context.h`](task-context.md) | Task context |
| [`ao_task_sched.h`](task-sched.md) | Task scheduler |
| [`ao_task_sched_0.h`](task-sched-0.md) | Task scheduler stub |
| [`ao_task_sched_1.h`](task-sched-1.md) | Round-robin scheduling without priorities |
| [`ao_task_sched_2.h`](task-sched-2.md) | Round-robin scheduling with priorities |
| [`ao_task_stack.h`](task-stack.md) | Task stack |
| [`ao_task_stack_0.h`](task-stack-0.md) | Task stack stub |
| [`ao_task_stack_1.h`](task-stack-1.md) | Task stack from injection |
| [`ao_task_stack_2.h`](task-stack-2.md) | Task stack from allocator |
| [`ao_threshold.h`](threshold.md) | Thresholds |
| [`ao_time.h`](time.md) | Time | ✅ |
| [`ao_timer.h`](timer.md) | Timers |
| [`ao_uint.h`](uint.md) | Unsigned integers | ✅ |
| [`ao_var.h`](var.md) | Variables | ✅ |
| [`ao_wr.h`](wr.md) | Readers-writer locks preferring writers |
| [`ao_xch.h`](xch.md) | Exchanges for client-server messaging |
| [`ao_yield.h`](yield.md) | Yielding |
