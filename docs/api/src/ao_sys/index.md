---
author: "Stefan Wagner"
date: 2022-08-29
draft: false
permalink: /api/src/ao_sys/
toc: false
wide: true
---

# Files

| [`ao_alarm.h`](ao_alarm.h.md) | Alarms |
| [`ao_alarm_queue.h`](ao_alarm_queue.h.md) | Alarm queue |
| [`ao_alarm_queue_0.h`](ao_alarm_queue_0.h.md) | Alarm queue stub |
| [`ao_alarm_queue_1.h`](ao_alarm_queue_1.h.md) | Alarm queue based on sorted list |
| [`ao_alarm_queue_2.h`](ao_alarm_queue_2.h.md) | Alarm queue based on an array-based binary heap |
| [`ao_alarm_queue_3.h`](ao_alarm_queue_3.h.md) | Alarm queue based on a pointer-based binary heap |
| [`ao_alarm_queue_4.h`](ao_alarm_queue_4.h.md) | Alarm queue based on an AVL tree |
| [`ao_alarm_queue_5.h`](ao_alarm_queue_5.h.md) | Alarm queue based on a red-black tree |
| [`ao_alloc.h`](ao_alloc.h.md) | Allocator |
| [`ao_alloc_0.h`](ao_alloc_0.h.md) | Allocator stub |
| [`ao_alloc_1.h`](ao_alloc_1.h.md) | Allocator based on pools of fixed-size memory blocks |
| [`ao_alloc_2.h`](ao_alloc_2.h.md) | Allocator based on the two-level segregated fit algorithm |
| [`ao_are.h`](ao_are.h.md) | Auto-reset events |
| [`ao_async.h`](ao_async.h.md) | Asynchronous events |
| [`ao_await.h`](ao_await.h.md) | Awaiting |
| [`ao_barrier.h`](ao_barrier.h.md) | Barriers |
| [`ao_block.h`](ao_block.h.md) | Blocking |
| [`ao_boot.h`](ao_boot.h.md) | Booting |
| [`ao_bsem.h`](ao_bsem.h.md) | Binary semaphores |
| [`ao_button.h`](ao_button.h.md) | Buttons |
| [`ao_cond.h`](ao_cond.h.md) | Condition variables |
| [`ao_core.h`](ao_core.h.md) | Processor cores |
| [`ao_count.h`](ao_count.h.md) | Hardware counter |
| [`ao_counter.h`](ao_counter.h.md) | Counters |
| [`ao_flag.h`](ao_flag.h.md) | Flags |
| [`ao_ir.h`](ao_ir.h.md) | Interrupts |
| [`ao_ir_alarm.h`](ao_ir_alarm.h.md) | Alarm interrupt |
| [`ao_ir_task.h`](ao_ir_task.h.md) | Task switch interrupts |
| [`ao_led.h`](ao_led.h.md) | LEDs |
| [`ao_lock.h`](ao_lock.h.md) | Locks |
| [`ao_mail.h`](ao_mail.h.md) | Mail for asynchronous messaging |
| [`ao_monitor.h`](ao_monitor.h.md) | Monitors |
| [`ao_mutex.h`](ao_mutex.h.md) | Mutexes |
| [`ao_pmail.h`](ao_pmail.h.md) | Priority mail for asynchronous messaging |
| [`ao_poll.h`](ao_poll.h.md) | Polling |
| [`ao_queue4obj.h`](ao_queue4obj.h.md) | Queues for objects |
| [`ao_queue4ptr.h`](ao_queue4ptr.h.md) | Queues for pointers |
| [`ao_recv.h`](ao_recv.h.md) | Receiving |
| [`ao_recv_from_callback.h`](ao_recv_from_callback.h.md) | Receiving from callbacks |
| [`ao_recv_from_stream.h`](ao_recv_from_stream.h.md) | Receiving from streams |
| [`ao_recv_obj.h`](ao_recv_obj.h.md) | Receiving objects |
| [`ao_recv_obj_from_callback.h`](ao_recv_obj_from_callback.h.md) | Receiving objects from callbacks |
| [`ao_recv_obj_from_queue.h`](ao_recv_obj_from_queue.h.md) | Receiving objects from queues |
| [`ao_recv_obj_from_stream.h`](ao_recv_obj_from_stream.h.md) | Receiving objects from streams |
| [`ao_recv_ptr.h`](ao_recv_ptr.h.md) | Receiving pointers |
| [`ao_recv_ptr_from_callback.h`](ao_recv_ptr_from_callback.h.md) | Receiving pointers from callbacks |
| [`ao_recv_ptr_from_queue.h`](ao_recv_ptr_from_queue.h.md) | Receiving pointers from queues |
| [`ao_recv_ptr_from_stream.h`](ao_recv_ptr_from_stream.h.md) | Receiving pointers from streams |
| [`ao_rendezvous.h`](ao_rendezvous.h.md) | Rendezvous |
| [`ao_rw.h`](ao_rw.h.md) | Readers-writer locks preferring readers |
| [`ao_self.h`](ao_self.h.md) | Running task |
| [`ao_sem.h`](ao_sem.h.md) | Counting semaphores |
| [`ao_send.h`](ao_send.h.md) | Sending |
| [`ao_send_obj.h`](ao_send_obj.h.md) | Sending objects |
| [`ao_send_obj_to_callback.h`](ao_send_obj_to_callback.h.md) | Sending objects to callbacks |
| [`ao_send_obj_to_queue.h`](ao_send_obj_to_queue.h.md) | Sending objects to queues |
| [`ao_send_obj_to_stream.h`](ao_send_obj_to_stream.h.md) | Sending objects to streams |
| [`ao_send_ptr.h`](ao_send_ptr.h.md) | Sending pointers |
| [`ao_send_ptr_to_callback.h`](ao_send_ptr_to_callback.h.md) | Sending pointers to callbacks |
| [`ao_send_ptr_to_queue.h`](ao_send_ptr_to_queue.h.md) | Sending pointers to queues |
| [`ao_send_ptr_to_stream.h`](ao_send_ptr_to_stream.h.md) | Sending pointers to streams |
| [`ao_send_to_callback.h`](ao_send_to_callback.h.md) | Sending to callbacks |
| [`ao_send_to_stream.h`](ao_send_to_stream.h.md) | Sending to streams |
| [`ao_signal.h`](ao_signal.h.md) | Signals |
| [`ao_sleep.h`](ao_sleep.h.md) | Sleeping |
| [`ao_spin.h`](ao_spin.h.md) | Spinning |
| [`ao_stack.h`](ao_stack.h.md) | Stacks |
| [`ao_stream.h`](ao_stream.h.md) | Streams |
| [`ao_stream4obj.h`](ao_stream4obj.h.md) | Streams for objects |
| [`ao_stream4ptr.h`](ao_stream4ptr.h.md) | Streams for pointers |
| [`ao_sys.h`](ao_sys.h.md) | System |
| [`ao_task.h`](ao_task.h.md) | Tasks |
| [`ao_task_context.h`](ao_task_context.h.md) | Task context |
| [`ao_task_sched.h`](ao_task_sched.h.md) | Task scheduler |
| [`ao_task_sched_0.h`](ao_task_sched_0.h.md) | Task scheduler stub|
| [`ao_task_sched_1.h`](ao_task_sched_1.h.md) | Round-robin task scheduler without priorities |
| [`ao_task_sched_2.h`](ao_task_sched_2.h.md) | Round-robin task scheduler with priorities |
| [`ao_task_stack.h`](ao_task_stack.h.md) | Task stack |
| [`ao_task_stack_0.h`](ao_task_stack_0.h.md) | Task stack stub |
| [`ao_task_stack_1.h`](ao_task_stack_1.h.md) | Task stack from injection |
| [`ao_task_stack_2.h`](ao_task_stack_2.h.md) | Task stack from allocation |
| [`ao_threshold.h`](ao_threshold.h.md) | Thresholds |
| [`ao_time.h`](ao_time.h.md) | Time |
| [`ao_timer.h`](ao_timer.h.md) | Timers |
| [`ao_wr.h`](ao_wr.h.md) | Readers-writer locks preferring writers |
| [`ao_xch.h`](ao_xch.h.md) | Exchanges for client-server messaging |
| [`ao_yield.h`](ao_yield.h.md) | Yielding |
