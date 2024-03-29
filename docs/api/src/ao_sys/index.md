---
author: "Stefan Wagner"
date: 2022-09-26
draft: false
permalink: /api/src/ao_sys/
toc: true
wide: false
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
| [`ao_can.h`](ao_can.h.md) | CAN |
| [`ao_cond.h`](ao_cond.h.md) | Conditions |
| [`ao_core.h`](ao_core.h.md) | Processor cores |
| [`ao_count.h`](ao_count.h.md) | Counter |
| [`ao_ir.h`](ao_ir.h.md) | Interrupts |
| [`ao_ir_alarm.h`](ao_ir_alarm.h.md) | Alarm interrupt |
| [`ao_ir_task.h`](ao_ir_task.h.md) | Task interrupts |
| [`ao_led.h`](ao_led.h.md) | LEDs |
| [`ao_lock.h`](ao_lock.h.md) | Locks |
| [`ao_mail.h`](ao_mail.h.md) | Mail for asynchronous messaging |
| [`ao_monitor.h`](ao_monitor.h.md) | Monitors |
| [`ao_mre.h`](ao_mre.h.md) | Manual-reset events |
| [`ao_mutex.h`](ao_mutex.h.md) | Mutexes |
| [`ao_num.h`](ao_num.h.md) | Numbers based on the fastest unsigned integer type |
| [`ao_num8.h`](ao_num8.h.md) | Numbers based on the 8-bit unsigned integer type |
| [`ao_num16.h`](ao_num16.h.md) | Numbers based on the 16-bit unsigned integer type |
| [`ao_num32.h`](ao_num32.h.md) | Numbers based on the 32-bit unsigned integer type |
| [`ao_num64.h`](ao_num64.h.md) | Numbers based on the 64-bit unsigned integer type |
| [`ao_pmail.h`](ao_pmail.h.md) | Priority mail for asynchronous messaging |
| [`ao_poll.h`](ao_poll.h.md) | Polling |
| [`ao_queue4acq.h`](ao_queue4acq.h.md) | Queues for acquired memory blocks |
| [`ao_queue4obj.h`](ao_queue4obj.h.md) | Queues for objects |
| [`ao_queue4ptr.h`](ao_queue4ptr.h.md) | Queues for pointers |
| [`ao_recv.h`](ao_recv.h.md) | Receiving |
| [`ao_recv_acq.h`](ao_recv_acq.h.md) | Receiving acquired memory blocks |
| [`ao_recv_acq_from_callback.h`](ao_recv_acq_from_callback.h.md) | Receiving acquired memory blocks from callbacks |
| [`ao_recv_acq_from_queue.h`](ao_recv_acq_from_queue.h.md) | Receiving acquired memory blocks from queues |
| [`ao_recv_acq_from_stream.h`](ao_recv_acq_from_stream.h.md) | Receiving acquired memory blocks from streams |
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
| [`ao_send_acq.h`](ao_send_acq.h.md) | Sending acquired memory blocks |
| [`ao_send_acq_to_callback.h`](ao_send_acq_to_callback.h.md) | Sending acquired memory blocks to callbacks |
| [`ao_send_acq_to_queue.h`](ao_send_acq_to_queue.h.md) | Sending acquired memory blocks to queues |
| [`ao_send_acq_to_stream.h`](ao_send_acq_to_stream.h.md) | Sending acquired memory blocks to streams |
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
| [`ao_stream4acq.h`](ao_stream4acq.h.md) | Streams for acquired memory blocks |
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
| [`ao_threshold.h`](ao_threshold.h.md) | Thresholds based on the fastest unsigned integer type |
| [`ao_threshold8.h`](ao_threshold8.h.md) | Thresholds based on the 8-bit unsigned integer type |
| [`ao_threshold16.h`](ao_threshold16.h.md) | Thresholds based on the 16-bit unsigned integer type |
| [`ao_threshold32.h`](ao_threshold32.h.md) | Thresholds based on the 32-bit unsigned integer type |
| [`ao_threshold64.h`](ao_threshold64.h.md) | Thresholds based on the 64-bit unsigned integer type |
| [`ao_time.h`](ao_time.h.md) | Time |
| [`ao_timer.h`](ao_timer.h.md) | Timers |
| [`ao_wr.h`](ao_wr.h.md) | Readers-writer locks preferring writers |
| [`ao_xch.h`](ao_xch.h.md) | Exchanges for client-server messaging |
| [`ao_yield.h`](ao_yield.h.md) | Yielding |
