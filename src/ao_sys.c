// ----------------------------------------------------------------------------

// MIT License

// Copyright (c) 2022 Stefan Wagner

// Permission is hereby granted, free of charge, to any person obtaining a
// copy of this software and associated documentation files (the "Software"),
// to deal in the Software without restriction, including without limitation
// the rights to use, copy, modify, merge, publish, distribute, sublicense,
// and/or sell copies of the Software, and to permit persons to whom the
// Software is furnished to do so, subject to the following conditions:

// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.

// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
// FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
// DEALINGS IN THE SOFTWARE.

// ----------------------------------------------------------------------------

#include <ao.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

// ----------------------------------------------------------------------------

#if defined AO_ALARM

// ----------------------------------------------------------------------------

static  bool    ao_alarm_less(              ao_alarm_t * A1, ao_alarm_t * A2);

// ----------------------------------------------------------------------------

static  void    ao_alarm_start_from_locked( ao_alarm_t * A, ao_time_t T, ao_time_t B);

static  void    ao_alarm_stop_locked(       ao_alarm_t * A);

// ----------------------------------------------------------------------------

#endif

#if defined AO_ALARM_QUEUE

// ----------------------------------------------------------------------------

static  void            ao_alarm_queue_insert(      ao_alarm_t * A);

static  bool            ao_alarm_queue_is_empty();

static  ao_alarm_t *    ao_alarm_queue_peek();

static  void            ao_alarm_queue_remove(      ao_alarm_t * A);

static  void            ao_alarm_queue_remove_peek( ao_alarm_t * A);

// ----------------------------------------------------------------------------

static  void            ao_boot_alarm_queue();

// ----------------------------------------------------------------------------

#endif

#if defined AO_ALLOC

// ----------------------------------------------------------------------------

static  void *          ao_acquire_2(   size_t  s);

static  bool            ao_release_2(   void *  p);

static  bool            ao_retain_2(    void *  p);

// ----------------------------------------------------------------------------

static  bool            ao_booted_alloc = false;

// ----------------------------------------------------------------------------

#if AO_ACQUIRED

static  ao_acquired_t   ao_acquired_info;

#endif

#if AO_RELEASED

static  ao_released_t   ao_released_info;

#endif

#if AO_RETAINED

static  ao_retained_t   ao_retained_info;

#endif

// ----------------------------------------------------------------------------

#endif

#if defined AO_ASYNC

// ----------------------------------------------------------------------------

static  void    ao_async_begin(     ao_async_t       * x);

static  void    ao_async_check(     ao_async_t       * x);

static  bool    ao_async_checked(   ao_async_t const * x);

static  void    ao_async_end(       ao_async_t       * x);

// ----------------------------------------------------------------------------

#endif

#if defined AO_BLOCK

// ----------------------------------------------------------------------------

static  void    ao_block(ao_block_t * b);

// ----------------------------------------------------------------------------

#endif

#if defined AO_MUTEX

// ----------------------------------------------------------------------------

static  void    ao_mutex_lock_begin_locked( ao_mutex_lock_t * x);

static  void    ao_mutex_lock_end_locked(   ao_mutex_lock_t * x);

// ----------------------------------------------------------------------------

static  void    ao_mutex_unlock_locked(     ao_mutex_t * x);

// ----------------------------------------------------------------------------

#endif

#if defined AO_SELF

// ----------------------------------------------------------------------------

static  ao_task_t * ao_self_locked();

// ----------------------------------------------------------------------------

#endif

#if defined AO_TASK

// ----------------------------------------------------------------------------

static  void    ao_task_pend(       ao_task_t * t, ao_task_state_pending_t p);

// ----------------------------------------------------------------------------

static  void    ao_task_switch_in(  ao_task_t * t);

static  bool    ao_task_switch_out( ao_task_t * t);

// ----------------------------------------------------------------------------

static  void    ao_task_unblock(    ao_task_t * t);

// ----------------------------------------------------------------------------

static  bool    ao_booted_task      = false;

// ----------------------------------------------------------------------------

#endif

#if defined AO_TASK_SCHED

// ----------------------------------------------------------------------------

static  void    ao_boot_task_sched();

// ----------------------------------------------------------------------------

static  void    ao_task_add(                ao_task_t * t);

// ----------------------------------------------------------------------------

static  void    ao_task_ceiling_begin(      ao_task_ceiling_t * c, ao_task_slave_t * s);

static  void    ao_task_ceiling_end(        ao_task_ceiling_t * c);

// ----------------------------------------------------------------------------

static  void    ao_task_down(               ao_task_t * t);

// ----------------------------------------------------------------------------

static  void    ao_task_inheritance_begin(  ao_task_master_t * m, ao_task_slave_t * s);

static  void    ao_task_inheritance_end(    ao_task_master_t * m);

// ----------------------------------------------------------------------------

static  void    ao_task_master_begin(       ao_task_master_t * m, ao_task_t * t);

static  void    ao_task_master_end(         ao_task_master_t * m);

// ----------------------------------------------------------------------------

static  void    ao_task_remove(             ao_task_t * t);

// ----------------------------------------------------------------------------

static  void    ao_task_slave_begin(        ao_task_slave_t * s, ao_task_t * t);

static  void    ao_task_slave_end(          ao_task_slave_t * s);

// ----------------------------------------------------------------------------

static  void    ao_task_start_sched(        ao_task_t * t);

// ----------------------------------------------------------------------------

static  void    ao_task_stop_sched(         ao_task_t * t);

// ----------------------------------------------------------------------------

#endif

#if defined AO_TASK_STACK

// ----------------------------------------------------------------------------

static  void    ao_boot_task_stack();

// ----------------------------------------------------------------------------

static  void    ao_task_start_stack(ao_task_t * t);

// ----------------------------------------------------------------------------

static  void    ao_task_stop_stack( ao_task_t * t);

// ----------------------------------------------------------------------------

#endif

// ----------------------------------------------------------------------------

#if defined AO_ALARM

// ----------------------------------------------------------------------------

static  void                    ao_alarm_update();

// ----------------------------------------------------------------------------

static  ao_time_t   volatile    ao_alarm_beginning;

// ----------------------------------------------------------------------------

void ao_alarm()
{
    // Notes.

    // This function is called by the alarm interrupt handler.

    // The kernel is not locked.


    // Variables.

    ao_alarm_t * A;

    ao_time_t B;

    ao_proc_t C;

    void * CP;

    ao_time_t E;

    ao_lock_t L;

    ao_time_t N;

    ao_time_t T;

    bool U;

    ao_time_t X;


    // Ready.

    do
    {
        // Update.

        ao_lock(&L);
        {
            // Alarm interrupt.

            ao_alarm_disable();

            ao_alarm_reply();


            // Alarm queue is not empty.

            A = ao_alarm_queue_peek();

            if (A)
            {
                // With respect to the reference point #B ...

                B = ao_alarm_beginning;


                // ... get the timeout #T of the next due alarm.

                // ... get the time span #X that has already passed until now.

                E = A->end;

                N = ao_now();

                T = E - B;

                X = N - B;


                // The next due alarm's timeout has already expired.

                if (T <= X)
                {
                    // Callback.

                    C = A->callback;

                    CP = A->callback_parameter;


                    // Alarm.

                    A->running = false;

                    ao_alarm_queue_remove_peek(A);


                    // We must run this loop once again, because another alarm could be due, too.

                    U = true;
                }


                // The next due alarm's timeout has not expired, yet.

                else
                {
                    // Callback.

                    C = NULL;


                    // Since #E is later than #N, we can safely move the reference point #B forward to #N.

                    B = N;

                    ao_alarm_beginning = N;


                    // The time span between #B and #E ...

                    T = E - B;


                    // ... must be limited.

                    // This takes into account the latency of the alarm interrupt.

                    // Otherwise, a count overflow could be missed.

                    if (T > AO_ALARM_UPDATE)
                    {
                        T = AO_ALARM_UPDATE;

                        E = B + T;
                    }


                    // Alarm interrupt.

                    ao_alarm_set(E);

                    ao_alarm_enable();


                    // The timeout #T might have expired, before the setting of the alarm interrupt actually took place.

                    // In this case, this loop must run once again.

                    N = ao_now();

                    X = N - B;

                    if (T <= X)
                    {
                        U = true;
                    }

                    else
                    {
                        U = false;
                    }
                }
            }


            // Alarm queue is empty.

            else
            {
                C = 0;

                U = false;
            }
        }
        ao_unlock(&L);


        // Callback.

        if (C)
        {
            C(CP);
        }
    }
    while (U);
}

// ----------------------------------------------------------------------------

bool ao_alarm_less(ao_alarm_t * A1, ao_alarm_t * A2)
{
    // Notes.

    // This function is called by the alarm queue.

    // It ensures a strict total order on the set of alarms.

    // @seeAlso

    // https://en.wikipedia.org/wiki/Total_order


    // Assert.

    ao_assert(A1);

    ao_assert(A2);


    // Variables.

    ao_time_t B;

    ao_time_t T1;

    ao_time_t T2;


    // Ready.

    B = ao_alarm_beginning;

    T1 = A1->end - B;

    T2 = A2->end - B;

    if (T1 < T2)
    {
        return true;
    }

    else if (T1 > T2)
    {
        return false;
    }

    else if (A1 < A2)
    {
        return true;
    }

    else
    {
        return false;
    }
}

// ----------------------------------------------------------------------------

void ao_alarm_start(ao_alarm_t * A, ao_time_t T)
{
    ao_alarm_start_from(A, T, ao_now());
}

void ao_alarm_start_from(ao_alarm_t * A, ao_time_t T, ao_time_t B)
{
    ao_lock_t L;

    ao_lock(&L);
    {
        ao_alarm_start_from_locked(A, T, B);
    }
    ao_unlock(&L);
}

void ao_alarm_start_from_locked(ao_alarm_t * A1, ao_time_t T1, ao_time_t B1)
{
    // Assert.

    ao_assert(A1);


    // Variables.

    ao_time_t B2;

    ao_time_t N;

    ao_time_t X1;

    ao_time_t X2;


    // Ready.

    // Alarm is running.

    if (A1->running)
    {
        ao_alarm_queue_remove(A1);

        if (T1 == AO_INFINITY)
        {
            A1->running = false;

            ao_alarm_update();

            return;
        }

        else { }
    }

    // Alarm is not running.

    else
    {
        if (T1 == AO_INFINITY)
        {
            return;
        }

        else
        {
            A1->running = true;
        }
    }


    // Alarm queue is empty.

    if (ao_alarm_queue_is_empty())
    {
        ao_alarm_beginning = B1;

        A1->end = B1 + T1;
    }

    // Alarm queue is not empty.

    else
    {
        // #B1 is the reference point of the alarm.

        // #B2 is the global reference point.

        B2 = ao_alarm_beginning;


        // #X1 is the time span that has expired since #B1.

        // #X2 is the time span that has expired since #B2.

        N = ao_now();

        X1 = N - B1;

        X2 = N - B2;


        // #B1 is not before #B2.

        if (X1 <= X2)
        {
            // The alarm's end point is not before #B2.

            // Therefore, we can calculate the alarm's end point based on #B1.

            A1->end = B1 + T1;
        }

        // #B1 is before #B2.

        else
        {
            // The alarm's timeout #T1 is not less than #X1.

            if (X1 <= T1)
            {
                // The alarm's end point is not before #B2.

                // Therefore, we can calculate the alarm's end point based on #B1.

                A1->end = B1 + T1;
            }

            // The alarm's timeout T1 is less than #X1.

            else
            {
                // The alarm's end point is not before #B2.

                // Therefore, we can calculate the alarm's end point based on #B1.

                if ((X1 - T1) <= X2)
                {
                    A1->end = B1 + T1;
                }

                // The alarm's end point is before #B2.

                // Therefore, we cannot calculate the alarm's end point based on #B1.

                // Instead, we move the alarm's end point to #B2.

                else
                {
                    A1->end = B2;
                }
            }
        }
    }


    // Alarm queue.

    ao_alarm_queue_insert(A1);


    // Alarm interrupt.

    ao_alarm_update();
}

// ----------------------------------------------------------------------------

void ao_alarm_stop(ao_alarm_t * A)
{
    ao_lock_t L;

    ao_lock(&L);
    {
        ao_alarm_stop_locked(A);
    }
    ao_unlock(&L);
}

void ao_alarm_stop_locked(ao_alarm_t * A)
{
    // Assert.

    ao_assert(A);


    // Ready.

    if (A->running)
    {
        A->running = false;

        ao_alarm_queue_remove(A);

        ao_alarm_update();
    }
}

// ----------------------------------------------------------------------------

void ao_alarm_update()
{
    // Notes.

    // This function is called, after an alarm has been started or stopped, in order to update the alarm interrupt.

    // The kernel is locked.


    // Variables.

    ao_alarm_t * A;


    // Variables.

    ao_time_t B;

    ao_time_t E;

    ao_time_t N;

    ao_time_t T;

    ao_time_t X;


    // Ready.

    // Alarm interrupt.

    ao_alarm_disable();

    ao_alarm_reply();


    // Alarm queue is not empty.

    A = ao_alarm_queue_peek();

    if (A)
    {
        // The reference point #B.

        B = ao_alarm_beginning;


        // The time point of the next alarm interrupt #E.

        E = A->end;


        // The time span between #B and #E ...

        T = E - B;


        // ... must be limited.

        // This takes into account the latency of the alarm interrupt.

        // Otherwise, a count overflow could be missed.

        if (T > AO_ALARM_UPDATE)
        {
            T = AO_ALARM_UPDATE;

            E = B + T;
        }


        // Alarm interrupt.

        ao_alarm_set(E);

        ao_alarm_enable();


        // The timeout #T might have expired, before the setting of the alarm interrupt actually took place.

        // In this case, the alarm interrupt must be triggered manually.

        N = ao_now();

        X = N - B;

        if (T <= X)
        {
            ao_alarm_request();
        }
    }
}

// ----------------------------------------------------------------------------

void ao_boot_alarm()
{
    ao_boot_alarm_queue();
}

// ----------------------------------------------------------------------------

#endif

#if defined AO_ALARM_QUEUE_0

// ----------------------------------------------------------------------------

void ao_alarm_queue_insert(ao_alarm_t * A)
{
    (void) A;
}

bool ao_alarm_queue_is_empty()
{
    return true;
}

ao_alarm_t * ao_alarm_queue_peek()
{
    return NULL;
}

void ao_alarm_queue_remove(ao_alarm_t * A)
{
    (void) A;
}

void ao_alarm_queue_remove_peek(ao_alarm_t * A)
{
    (void) A;
}

// ----------------------------------------------------------------------------

void ao_boot_alarm_queue() { }

// ----------------------------------------------------------------------------

#endif

#if defined AO_ALARM_QUEUE_1

// ----------------------------------------------------------------------------

static  bool                ao_alarm_queue_less(ao_alarm_queue_node_t * N1, ao_alarm_queue_node_t * N2, void * Parameter);

// ----------------------------------------------------------------------------

static  ao_alarm_queue_t    ao_alarm_queue =
{
        .less               = ao_alarm_queue_less,

        .less_parameter     = NULL
};

// ----------------------------------------------------------------------------

void ao_alarm_queue_insert(ao_alarm_t * A)
{
    ao_assert(A);

    ao_slist_insert(&ao_alarm_queue, &A->node);

#if AO_ALARM_QUEUE_ASSERT

    ao_slist_assert(&ao_alarm_queue);

#endif

}

bool ao_alarm_queue_is_empty()
{
    return ao_slist_is_empty(&ao_alarm_queue);
}

bool ao_alarm_queue_less(ao_alarm_queue_node_t * N1, ao_alarm_queue_node_t * N2, void * Parameter)
{
    (void) Parameter;

    ao_alarm_t * A1 = ao_containerof(N1, ao_alarm_t, node);

    ao_alarm_t * A2 = ao_containerof(N2, ao_alarm_t, node);

    return ao_alarm_less(A1, A2);
}

ao_alarm_t * ao_alarm_queue_peek()
{
    ao_alarm_queue_node_t * N = ao_alarm_queue.front;

    return N ? ao_containerof(N, ao_alarm_t, node) : NULL;
}

void ao_alarm_queue_remove(ao_alarm_t * A)
{
    ao_assert(A);

    ao_slist_remove(&ao_alarm_queue, &A->node);

#if AO_ALARM_QUEUE_ASSERT

    ao_slist_assert(&ao_alarm_queue);

#endif

}

void ao_alarm_queue_remove_peek(ao_alarm_t * A)
{
    (void) A;

    ao_slist_remove_front(&ao_alarm_queue);

#if AO_ALARM_QUEUE_ASSERT

    ao_slist_assert(&ao_alarm_queue);

#endif

}

// ----------------------------------------------------------------------------

void ao_boot_alarm_queue() { }

// ----------------------------------------------------------------------------

#endif

#if defined AO_ALARM_QUEUE_2

// ----------------------------------------------------------------------------

static  void                        ao_alarm_queue_assert();

// ----------------------------------------------------------------------------

static  void                        ao_alarm_queue_down(        size_t i);

static  void                        ao_alarm_queue_up(          size_t i);

// ----------------------------------------------------------------------------

#define ao_alarm_queue_left(i)      (2 * (i) + 1)

#define ao_alarm_queue_right(i)     (2 * (i) + 2)

// ----------------------------------------------------------------------------

#define ao_alarm_queue_parent(i)    (((i) - 1) / 2)

// ----------------------------------------------------------------------------

static  ao_alarm_t *                ao_alarm_queue              [AO_ALARM_QUEUE_CAPACITY];

// ----------------------------------------------------------------------------

        size_t          volatile    ao_alarm_queue_count        = 0;

#if     AO_ALARM_QUEUE_COUNT_MAX

        size_t          volatile    ao_alarm_queue_count_max    = 0;

#endif

// ----------------------------------------------------------------------------

void ao_alarm_queue_assert()
{
    // Variables.

    ao_alarm_t * AL;

    ao_alarm_t * AP;

    ao_alarm_t * AR;


    // Variables.

    size_t C;

    size_t ip;

    size_t il;

    size_t ir;


    // Ready.

    C = ao_alarm_queue_count;

    for (ip = 0; ip < C; ip++)
    {
        il = ao_alarm_queue_left(ip);

        ir = ao_alarm_queue_right(ip);

        if (ir < C)
        {
            AL = ao_alarm_queue[il];

            AP = ao_alarm_queue[ip];

            AR = ao_alarm_queue[ir];

            ao_assert(AL->node == il);

            ao_assert(AP->node == ip);

            ao_assert(AR->node == ir);

            ao_assert(ao_alarm_less(AP, AL));

            ao_assert(ao_alarm_less(AP, AR));
        }

        else if (il < C)
        {
            AL = ao_alarm_queue[il];

            AP = ao_alarm_queue[ip];

            ao_assert(AL->node == il);

            ao_assert(AP->node == ip);

            ao_assert(ao_alarm_less(AP, AL));
        }
    }
}

void ao_alarm_queue_down(size_t i1)
{
    // Assert.

    ao_assert(i1 < AO_ALARM_QUEUE_CAPACITY);

    ao_assert(i1 < ao_alarm_queue_count);


    // Variables.

    ao_alarm_t * A1;

    ao_alarm_t * AL;

    ao_alarm_t * AR;


    // Variables.

    bool B1;

    bool B2;


    // Variables.

    size_t C;

    size_t il;

    size_t ir;


    // Ready.

    B1 = true;

    B2 = false;

    C  = ao_alarm_queue_count;

    A1 = ao_alarm_queue[i1];

    do
    {
        il = ao_alarm_queue_left(i1);

        ir = ao_alarm_queue_right(i1);

        // Both left and right child.

        if (ir < C)
        {
            AL = ao_alarm_queue[il];

            AR = ao_alarm_queue[ir];

            // AR is less.

            if (ao_alarm_less(AR, A1))
            {
                // AR is less than A1.

                // AL is less than AR.

                if (ao_alarm_less(AL, AR))
                {
                    AL->node = i1;

                    ao_alarm_queue[i1] = AL;

                    i1 = il;

                    B2 = true;
                }

                // AR is less than A1.

                // AL is not less than AR.

                else
                {
                    AR->node = i1;

                    ao_alarm_queue[i1] = AR;

                    i1 = ir;

                    B2 = true;
                }
            }

            // AR is not less.

            // AL is less.

            else if (ao_alarm_less(AL, A1))
            {
                AL->node = i1;

                ao_alarm_queue[i1] = AL;

                i1 = il;

                B2 = true;
            }

            // AR is not less.

            // AL is not less.

            else
            {
                B1 = false;
            }
        }

        // Left child only.

        else if (il < C)
        {
            AL = ao_alarm_queue[il];

            // AL is less.

            if (ao_alarm_less(AL, A1))
            {
                AL->node = i1;

                ao_alarm_queue[i1] = AL;

                i1 = il;

                B2 = true;
            }

            // AL is not less.

            else
            {
                B1 = false;
            }
        }

        // No children.

        else
        {
            B1 = false;
        }
    }
    while (B1);

    if (B2)
    {
        ao_alarm_queue[i1] = A1;

        A1->node = i1;
    }
}

void ao_alarm_queue_insert(ao_alarm_t * A)
{
    // Assert.

    ao_assert(A);


    // Variables.

    size_t C1;

    size_t C2;

#if AO_ALARM_QUEUE_COUNT_MAX

    size_t CM;

#endif


    // Ready.

    // Count.

    C1 = ao_alarm_queue_count;

    C2 = C1 + 1;

    ao_assert(C1 <  C2);

    ao_assert(C2 <= AO_ALARM_QUEUE_CAPACITY);

#if AO_ALARM_QUEUE_COUNT_MAX

    CM = ao_alarm_queue_count_max;

    CM = ao_max(CM, C2);

    ao_alarm_queue_count_max = CM;

#endif

    ao_alarm_queue_count = C2;


    // Insert.

    ao_alarm_queue[C1] = A;

    A->node = C1;

    ao_alarm_queue_up(C1);


    // Verify.

#if AO_ALARM_QUEUE_ASSERT

    ao_alarm_queue_assert();

#endif

}

bool ao_alarm_queue_is_empty()
{
    return ao_alarm_queue_count == 0 ? true : false;
}

ao_alarm_t * ao_alarm_queue_peek()
{
    if (ao_alarm_queue_count > 0)
    {
        return ao_alarm_queue[0];
    }

    else
    {
        return NULL;
    }
}

void ao_alarm_queue_remove(ao_alarm_t * A1)
{
    // Notes.

    // This function removes an arbitrary element from a minimum heap as follows.

    // 1. Find the index i of the element to remove.

    // 2. Swap this element with the last element.

    // 3. Heapify up or down in order to restore the heap property. Thereby,

    // *  heapifying up   is required, when the new key of element i is less than the previous one, and

    // *  heapifying down is required, otherwise.


    // Assert.

    ao_assert(A1);


    // Variables.

    ao_alarm_t * A2;

    size_t C;

    size_t i;


    // Ready.

    // Count.

    C = ao_alarm_queue_count;

    ao_assert(C);

    C = C - 1;

    ao_alarm_queue_count = C;


    // Remove.

    i = A1->node;

    if (i < C)
    {
        A2 = ao_alarm_queue[C];

        ao_alarm_queue[i] = A2;

        A2->node = i;

        if (ao_alarm_less(A2, A1))
        {
            ao_alarm_queue_up(i);
        }

        else
        {
            ao_alarm_queue_down(i);
        }
    }


    // Verify.

#if AO_ALARM_QUEUE_ASSERT

    ao_alarm_queue_assert();

#endif

}

void ao_alarm_queue_remove_peek(ao_alarm_t * A)
{
    // Variables.

    size_t C;


    // Ready.

    // Count.

    C = ao_alarm_queue_count - 1;

    ao_alarm_queue_count = C;


    // Remove.

    if (C > 0)
    {
        A = ao_alarm_queue[C];

        ao_alarm_queue[0] = A;

        A->node = 0;

        ao_alarm_queue_down(0);
    }


    // Verify.

#if AO_ALARM_QUEUE_ASSERT

    ao_alarm_queue_assert();

#endif

}

void ao_alarm_queue_up(size_t i1)
{
    // Assert.

    ao_assert(i1 < AO_ALARM_QUEUE_CAPACITY);

    ao_assert(i1 < ao_alarm_queue_count);


    // Variables.

    ao_alarm_t * A1;

    ao_alarm_t * A2;


    // Variables.

    bool B1 = i1 > 0;

    bool B2;


    // Variables.

    size_t i2;


    // Ready.

    if (B1)
    {
        B2 = false;

        A1 = ao_alarm_queue[i1];

        do
        {
            i2 = ao_alarm_queue_parent(i1);

            A2 = ao_alarm_queue[i2];

            if (ao_alarm_less(A1, A2))
            {
                ao_alarm_queue[i1] = A2;

                A2->node = i1;

                i1 = i2;

                B1 = i1 > 0;

                B2 = true;
            }

            else
            {
                B1 = false;
            }
        }
        while (B1);

        if (B2)
        {
            ao_alarm_queue[i1] = A1;

            A1->node = i1;
        }
    }
}

// ----------------------------------------------------------------------------

void ao_boot_alarm_queue() { }

// ----------------------------------------------------------------------------

#endif

#if defined AO_ALARM_QUEUE_3

// ----------------------------------------------------------------------------

static  bool                ao_alarm_queue_less(ao_alarm_queue_node_t * N1, ao_alarm_queue_node_t * N2, void * Parameter);

// ----------------------------------------------------------------------------

static  ao_alarm_queue_t    ao_alarm_queue =
{
        .less               = ao_alarm_queue_less,

        .less_parameter     = NULL
};

// ----------------------------------------------------------------------------

void ao_alarm_queue_insert(ao_alarm_t * A)
{
    ao_assert(A);

    ao_heap_insert(&ao_alarm_queue, &A->node);

#if AO_ALARM_QUEUE_ASSERT

    ao_heap_assert(&ao_alarm_queue);

#endif

}

bool ao_alarm_queue_is_empty()
{
    return ao_heap_is_empty(&ao_alarm_queue);
}

bool ao_alarm_queue_less(ao_alarm_queue_node_t * N1, ao_alarm_queue_node_t * N2, void * Parameter)
{
    (void) Parameter;

    ao_alarm_t * A1 = ao_containerof(N1, ao_alarm_t, node);

    ao_alarm_t * A2 = ao_containerof(N2, ao_alarm_t, node);

    return ao_alarm_less(A1, A2);
}

ao_alarm_t * ao_alarm_queue_peek()
{
    ao_alarm_queue_node_t * N = ao_alarm_queue.root;

    if (N)
    {
        return ao_containerof(N, ao_alarm_t, node);
    }

    else
    {
        return NULL;
    }
}

void ao_alarm_queue_remove(ao_alarm_t * A)
{
    ao_assert(A);

    ao_heap_remove(&ao_alarm_queue, &A->node);

#if AO_ALARM_QUEUE_ASSERT

    ao_heap_assert(&ao_alarm_queue);

#endif

}

void ao_alarm_queue_remove_peek(ao_alarm_t * A)
{
    ao_alarm_queue_remove(A);
}

// ----------------------------------------------------------------------------

void ao_boot_alarm_queue() { }

// ----------------------------------------------------------------------------

#endif

#if defined AO_ALARM_QUEUE_4

// ----------------------------------------------------------------------------

static  ao_alarm_t *        ao_alarm_queue_find();

// ----------------------------------------------------------------------------

static  bool                ao_alarm_queue_less(    ao_alarm_queue_node_t * N1, ao_alarm_queue_node_t * N2, void * Parameter);

// ----------------------------------------------------------------------------

static  ao_alarm_queue_t    ao_alarm_queue =
{
        .less               = ao_alarm_queue_less,

        .less_parameter     = NULL
};

// ----------------------------------------------------------------------------

#if     AO_ALARM_QUEUE_CACHE

static  ao_alarm_t *        ao_alarm_queue_cache    = NULL;

#endif

// ----------------------------------------------------------------------------

ao_alarm_t * ao_alarm_queue_find()
{
    // Variables.

    ao_alarm_queue_node_t * N = ao_alarm_queue.root;


    // Ready.

    if (N)
    {
        while (N->left)
        {
            N = N->left;
        }

        return ao_containerof(N, ao_alarm_t, node);
    }

    else
    {
        return NULL;
    }
}

void ao_alarm_queue_insert(ao_alarm_t * A)
{
    ao_assert(A);

    ao_avl_insert(&ao_alarm_queue, &A->node);

#if AO_ALARM_QUEUE_ASSERT

    ao_avl_assert(&ao_alarm_queue);

#endif

#if AO_ALARM_QUEUE_CACHE

    ao_alarm_queue_cache = ao_alarm_queue_find();

#endif

}

bool ao_alarm_queue_is_empty()
{
    return ao_avl_is_empty(&ao_alarm_queue);
}

bool ao_alarm_queue_less(ao_alarm_queue_node_t * N1, ao_alarm_queue_node_t * N2, void * Parameter)
{
    (void) Parameter;

    ao_alarm_t * A1 = ao_containerof(N1, ao_alarm_t, node);

    ao_alarm_t * A2 = ao_containerof(N2, ao_alarm_t, node);

    return ao_alarm_less(A1, A2);
}

ao_alarm_t * ao_alarm_queue_peek()
{

#if AO_ALARM_QUEUE_CACHE

    return ao_alarm_queue_cache;

#else

    return ao_alarm_queue_find();

#endif

}

void ao_alarm_queue_remove(ao_alarm_t * A)
{
    ao_assert(A);

    ao_avl_remove(&ao_alarm_queue, &A->node);

#if AO_ALARM_QUEUE_ASSERT

    ao_avl_assert(&ao_alarm_queue);

#endif

#if AO_ALARM_QUEUE_CACHE

    ao_alarm_queue_cache = ao_alarm_queue_find();

#endif

}

void ao_alarm_queue_remove_peek(ao_alarm_t * A)
{
    ao_alarm_queue_remove(A);
}

// ----------------------------------------------------------------------------

void ao_boot_alarm_queue() { }

// ----------------------------------------------------------------------------

#endif

#if defined AO_ALARM_QUEUE_5

// ----------------------------------------------------------------------------

static  ao_alarm_t *        ao_alarm_queue_find();

// ----------------------------------------------------------------------------

static  bool                ao_alarm_queue_less(    ao_alarm_queue_node_t * N1, ao_alarm_queue_node_t * N2, void * Parameter);

// ----------------------------------------------------------------------------

static  ao_alarm_queue_t    ao_alarm_queue =
{
        .less               = ao_alarm_queue_less,

        .less_parameter     = NULL
};

// ----------------------------------------------------------------------------

#if     AO_ALARM_QUEUE_CACHE

static  ao_alarm_t *        ao_alarm_queue_cache    = NULL;

#endif

// ----------------------------------------------------------------------------

ao_alarm_t * ao_alarm_queue_find()
{
    ao_alarm_queue_node_t * N = ao_alarm_queue.root;

    if (N)
    {
        while (N->left)
        {
            N = N->left;
        }

        return ao_containerof(N, ao_alarm_t, node);
    }

    else
    {
        return NULL;
    }
}

void ao_alarm_queue_insert(ao_alarm_t * A)
{
    ao_assert(A);

    ao_rb_insert(&ao_alarm_queue, &A->node);

#if AO_ALARM_QUEUE_ASSERT

    ao_rb_assert(&ao_alarm_queue);

#endif

#if AO_ALARM_QUEUE_CACHE

    ao_alarm_queue_cache = ao_alarm_queue_find();

#endif

}

bool ao_alarm_queue_is_empty()
{
    return ao_rb_is_empty(&ao_alarm_queue);
}

bool ao_alarm_queue_less(ao_alarm_queue_node_t * N1, ao_alarm_queue_node_t * N2, void * Parameter)
{
    (void) Parameter;

    ao_alarm_t * A1 = ao_containerof(N1, ao_alarm_t, node);

    ao_alarm_t * A2 = ao_containerof(N2, ao_alarm_t, node);

    return ao_alarm_less(A1, A2);
}

ao_alarm_t * ao_alarm_queue_peek()
{

#if AO_ALARM_QUEUE_CACHE

    return ao_alarm_queue_cache;

#else

    return ao_alarm_queue_find();

#endif

}

void ao_alarm_queue_remove(ao_alarm_t * A)
{
    ao_assert(A);

    ao_rb_remove(&ao_alarm_queue, &A->node);

#if AO_ALARM_QUEUE_ASSERT

    ao_rb_assert(&ao_alarm_queue);

#endif

#if AO_ALARM_QUEUE_CACHE

    ao_alarm_queue_cache = ao_alarm_queue_find();

#endif

}

void ao_alarm_queue_remove_peek(ao_alarm_t * A)
{
    ao_alarm_queue_remove(A);
}

// ----------------------------------------------------------------------------

void ao_boot_alarm_queue() { }

// ----------------------------------------------------------------------------

#endif

#if defined AO_ALLOC

// ----------------------------------------------------------------------------

static  void *  ao_acquire_1(   size_t  s);

static  bool    ao_release_1(   void *  x);

static  bool    ao_retain_1(    void *  x);

// ----------------------------------------------------------------------------

void * ao_acquire(size_t s)
{
    // Assert.

    ao_assert(ao_booted_alloc);


    // Variables.

    ao_lock_t L;

    void * p;


    // Ready.

    if (s > 0)
    {
        ao_lock(&L);
        {
            p = ao_acquire_2(s);
        }
        ao_unlock(&L);
    }

    else
    {
        p = NULL;

#if AO_ACQUIRED

        ao_lock(&L);
        {
            ao_acquired_info.ptr = NULL;

            ao_acquired_info.result = false;

            ao_acquired_info.size_body = 0;

            ao_acquired_info.size_body_requested = 0;

            ao_acquired_info.size_head = 0;

            ao_acquired(&ao_acquired_info);
        }
        ao_unlock(&L);

#endif

    }

    return p;
}

void * ao_acquire_1(size_t s)
{
    // Assert.

    ao_assert(ao_booted_alloc);


    // Variables.

    void * p;


    // Ready.

    if (s > 0)
    {
        p = ao_acquire_2(s);
    }

    else
    {
        p = NULL;

#if AO_ACQUIRED

        ao_acquired_info.ptr = NULL;

        ao_acquired_info.result = false;

        ao_acquired_info.size_body = 0;

        ao_acquired_info.size_body_requested = 0;

        ao_acquired_info.size_head = 0;

        ao_acquired(&ao_acquired_info);

#endif

    }

    return p;
}

// ----------------------------------------------------------------------------

bool ao_release(void * p)
{
    // Assert.

    ao_assert(ao_booted_alloc);


    // Variables.

    ao_lock_t L;

    bool r;


    // Ready.

    if (p)
    {
        ao_lock(&L);
        {
            r = ao_release_2(p);
        }
        ao_unlock(&L);
    }

    else
    {
        r = false;

#if AO_RELEASED

        ao_lock(&L);
        {
            ao_released_info.ptr = NULL;

            ao_released_info.ref = 0;

            ao_released_info.result = false;

            ao_released_info.size_body = 0;

            ao_released_info.size_head = 0;

            ao_released(&ao_released_info);
        }
        ao_unlock(&L);

#endif

    }

    return r;
}

bool ao_release_1(void * p)
{
    // Assert.

    ao_assert(ao_booted_alloc);


    // Variables.

    bool r;


    // Ready.

    if (p)
    {
        r = ao_release_2(p);
    }

    else
    {
        r = false;

#if AO_RELEASED

        ao_released_info.ptr = NULL;

        ao_released_info.ref = 0;

        ao_released_info.result = false;

        ao_released_info.size_body = 0;

        ao_released_info.size_head = 0;

        ao_released(&ao_released_info);

#endif

    }

    return r;
}

// ----------------------------------------------------------------------------

bool ao_retain(void * p)
{
    // Assert.

    ao_assert(ao_booted_alloc);


    // Variables.

    ao_lock_t L;

    bool r;


    // Ready.

    if (p)
    {
        ao_lock(&L);
        {
            r = ao_retain_2(p);
        }
        ao_unlock(&L);
    }

    else
    {
        r = false;

#if AO_RETAINED

        ao_lock(&L);
        {
            ao_retained_info.ptr = NULL;

            ao_retained_info.ref = 0;

            ao_retained_info.result = false;

            ao_retained_info.size_body = 0;

            ao_retained_info.size_head = 0;

            ao_retained(&ao_retained_info);
        }
        ao_unlock(&L);

#endif

    }

    return r;
}

bool ao_retain_1(void * p)
{
    // Assert.

    ao_assert(ao_booted_alloc);


    // Variables.

    bool r;


    // Ready.

    if (p)
    {
        r = ao_retain_2(p);
    }

    else
    {
        r = false;

#if AO_RETAINED

        ao_retained_info.ptr = NULL;

        ao_retained_info.ref = 0;

        ao_retained_info.result = false;

        ao_retained_info.size_body = 0;

        ao_retained_info.size_head = 0;

        ao_retained(&ao_retained_info);

#endif

    }

    return r;
}

// ----------------------------------------------------------------------------

#endif

#if defined AO_ALLOC_0

// ----------------------------------------------------------------------------

void ao_boot_alloc()
{
    ao_assert(!ao_booted_alloc);

    ao_booted_alloc = true;
}

// ----------------------------------------------------------------------------

void * ao_acquire_2(size_t s)
{

#if AO_ACQUIRED

    ao_acquired_info.ptr = NULL;

    ao_acquired_info.result = false;

    ao_acquired_info.size_body = 0;

    ao_acquired_info.size_body_requested = s;

    ao_acquired_info.size_head = 0;

    ao_acquired(&ao_acquired_info);

#else

    (void) s;

#endif

    return NULL;
}

bool ao_release_2(void * p)
{

#if AO_RELEASED

    ao_released_info.ptr = p;

    ao_released_info.ref = 0;

    ao_released_info.result = false;

    ao_released_info.size_body = 0;

    ao_released_info.size_head = 0;

    ao_released(&ao_released_info);

#else

    (void) p;

#endif

    return false;
}

bool ao_retain_2(void * p)
{

#if AO_RETAINED

    ao_retained_info.ptr = p;

    ao_retained_info.ref = 0;

    ao_retained_info.result = false;

    ao_retained_info.size_body = 0;

    ao_retained_info.size_head = 0;

    ao_retained(&ao_retained_info);

#else

    (void) p;

#endif

    return false;
}

// ----------------------------------------------------------------------------

#endif

#if defined AO_ALLOC_1

// ----------------------------------------------------------------------------

#define AO_ALLOC_POOL_0                 (AO_ALLOC_POOL_BLOCK_COUNT_0  > 0 && AO_ALLOC_POOL_BLOCK_SIZE_0  > 0 && AO_SIZE_BITS >  0)

#define AO_ALLOC_POOL_1                 (AO_ALLOC_POOL_BLOCK_COUNT_1  > 0 && AO_ALLOC_POOL_BLOCK_SIZE_1  > 0 && AO_SIZE_BITS >  1)

#define AO_ALLOC_POOL_2                 (AO_ALLOC_POOL_BLOCK_COUNT_2  > 0 && AO_ALLOC_POOL_BLOCK_SIZE_2  > 0 && AO_SIZE_BITS >  2)

#define AO_ALLOC_POOL_3                 (AO_ALLOC_POOL_BLOCK_COUNT_3  > 0 && AO_ALLOC_POOL_BLOCK_SIZE_3  > 0 && AO_SIZE_BITS >  3)

#define AO_ALLOC_POOL_4                 (AO_ALLOC_POOL_BLOCK_COUNT_4  > 0 && AO_ALLOC_POOL_BLOCK_SIZE_4  > 0 && AO_SIZE_BITS >  4)

#define AO_ALLOC_POOL_5                 (AO_ALLOC_POOL_BLOCK_COUNT_5  > 0 && AO_ALLOC_POOL_BLOCK_SIZE_5  > 0 && AO_SIZE_BITS >  5)

#define AO_ALLOC_POOL_6                 (AO_ALLOC_POOL_BLOCK_COUNT_6  > 0 && AO_ALLOC_POOL_BLOCK_SIZE_6  > 0 && AO_SIZE_BITS >  6)

#define AO_ALLOC_POOL_7                 (AO_ALLOC_POOL_BLOCK_COUNT_7  > 0 && AO_ALLOC_POOL_BLOCK_SIZE_7  > 0 && AO_SIZE_BITS >  7)

#define AO_ALLOC_POOL_8                 (AO_ALLOC_POOL_BLOCK_COUNT_8  > 0 && AO_ALLOC_POOL_BLOCK_SIZE_8  > 0 && AO_SIZE_BITS >  8)

#define AO_ALLOC_POOL_9                 (AO_ALLOC_POOL_BLOCK_COUNT_9  > 0 && AO_ALLOC_POOL_BLOCK_SIZE_9  > 0 && AO_SIZE_BITS >  9)

#define AO_ALLOC_POOL_10                (AO_ALLOC_POOL_BLOCK_COUNT_10 > 0 && AO_ALLOC_POOL_BLOCK_SIZE_10 > 0 && AO_SIZE_BITS > 10)

#define AO_ALLOC_POOL_11                (AO_ALLOC_POOL_BLOCK_COUNT_11 > 0 && AO_ALLOC_POOL_BLOCK_SIZE_11 > 0 && AO_SIZE_BITS > 11)

#define AO_ALLOC_POOL_12                (AO_ALLOC_POOL_BLOCK_COUNT_12 > 0 && AO_ALLOC_POOL_BLOCK_SIZE_12 > 0 && AO_SIZE_BITS > 12)

#define AO_ALLOC_POOL_13                (AO_ALLOC_POOL_BLOCK_COUNT_13 > 0 && AO_ALLOC_POOL_BLOCK_SIZE_13 > 0 && AO_SIZE_BITS > 13)

#define AO_ALLOC_POOL_14                (AO_ALLOC_POOL_BLOCK_COUNT_14 > 0 && AO_ALLOC_POOL_BLOCK_SIZE_14 > 0 && AO_SIZE_BITS > 14)

#define AO_ALLOC_POOL_15                (AO_ALLOC_POOL_BLOCK_COUNT_15 > 0 && AO_ALLOC_POOL_BLOCK_SIZE_15 > 0 && AO_SIZE_BITS > 15)

#define AO_ALLOC_POOL_16                (AO_ALLOC_POOL_BLOCK_COUNT_16 > 0 && AO_ALLOC_POOL_BLOCK_SIZE_16 > 0 && AO_SIZE_BITS > 16)

#define AO_ALLOC_POOL_17                (AO_ALLOC_POOL_BLOCK_COUNT_17 > 0 && AO_ALLOC_POOL_BLOCK_SIZE_17 > 0 && AO_SIZE_BITS > 17)

#define AO_ALLOC_POOL_18                (AO_ALLOC_POOL_BLOCK_COUNT_18 > 0 && AO_ALLOC_POOL_BLOCK_SIZE_18 > 0 && AO_SIZE_BITS > 18)

#define AO_ALLOC_POOL_19                (AO_ALLOC_POOL_BLOCK_COUNT_19 > 0 && AO_ALLOC_POOL_BLOCK_SIZE_19 > 0 && AO_SIZE_BITS > 19)

#define AO_ALLOC_POOL_20                (AO_ALLOC_POOL_BLOCK_COUNT_20 > 0 && AO_ALLOC_POOL_BLOCK_SIZE_20 > 0 && AO_SIZE_BITS > 20)

#define AO_ALLOC_POOL_21                (AO_ALLOC_POOL_BLOCK_COUNT_21 > 0 && AO_ALLOC_POOL_BLOCK_SIZE_21 > 0 && AO_SIZE_BITS > 21)

#define AO_ALLOC_POOL_22                (AO_ALLOC_POOL_BLOCK_COUNT_22 > 0 && AO_ALLOC_POOL_BLOCK_SIZE_22 > 0 && AO_SIZE_BITS > 22)

#define AO_ALLOC_POOL_23                (AO_ALLOC_POOL_BLOCK_COUNT_23 > 0 && AO_ALLOC_POOL_BLOCK_SIZE_23 > 0 && AO_SIZE_BITS > 23)

#define AO_ALLOC_POOL_24                (AO_ALLOC_POOL_BLOCK_COUNT_24 > 0 && AO_ALLOC_POOL_BLOCK_SIZE_24 > 0 && AO_SIZE_BITS > 24)

#define AO_ALLOC_POOL_25                (AO_ALLOC_POOL_BLOCK_COUNT_25 > 0 && AO_ALLOC_POOL_BLOCK_SIZE_25 > 0 && AO_SIZE_BITS > 25)

#define AO_ALLOC_POOL_26                (AO_ALLOC_POOL_BLOCK_COUNT_26 > 0 && AO_ALLOC_POOL_BLOCK_SIZE_26 > 0 && AO_SIZE_BITS > 26)

#define AO_ALLOC_POOL_27                (AO_ALLOC_POOL_BLOCK_COUNT_27 > 0 && AO_ALLOC_POOL_BLOCK_SIZE_27 > 0 && AO_SIZE_BITS > 27)

#define AO_ALLOC_POOL_28                (AO_ALLOC_POOL_BLOCK_COUNT_28 > 0 && AO_ALLOC_POOL_BLOCK_SIZE_28 > 0 && AO_SIZE_BITS > 28)

#define AO_ALLOC_POOL_29                (AO_ALLOC_POOL_BLOCK_COUNT_29 > 0 && AO_ALLOC_POOL_BLOCK_SIZE_29 > 0 && AO_SIZE_BITS > 29)

#define AO_ALLOC_POOL_30                (AO_ALLOC_POOL_BLOCK_COUNT_30 > 0 && AO_ALLOC_POOL_BLOCK_SIZE_30 > 0 && AO_SIZE_BITS > 30)

#define AO_ALLOC_POOL_31                (AO_ALLOC_POOL_BLOCK_COUNT_31 > 0 && AO_ALLOC_POOL_BLOCK_SIZE_31 > 0 && AO_SIZE_BITS > 31)

#define AO_ALLOC_POOL_32                (AO_ALLOC_POOL_BLOCK_COUNT_32 > 0 && AO_ALLOC_POOL_BLOCK_SIZE_32 > 0 && AO_SIZE_BITS > 32)

#define AO_ALLOC_POOL_33                (AO_ALLOC_POOL_BLOCK_COUNT_33 > 0 && AO_ALLOC_POOL_BLOCK_SIZE_33 > 0 && AO_SIZE_BITS > 33)

#define AO_ALLOC_POOL_34                (AO_ALLOC_POOL_BLOCK_COUNT_34 > 0 && AO_ALLOC_POOL_BLOCK_SIZE_34 > 0 && AO_SIZE_BITS > 34)

#define AO_ALLOC_POOL_35                (AO_ALLOC_POOL_BLOCK_COUNT_35 > 0 && AO_ALLOC_POOL_BLOCK_SIZE_35 > 0 && AO_SIZE_BITS > 35)

#define AO_ALLOC_POOL_36                (AO_ALLOC_POOL_BLOCK_COUNT_36 > 0 && AO_ALLOC_POOL_BLOCK_SIZE_36 > 0 && AO_SIZE_BITS > 36)

#define AO_ALLOC_POOL_37                (AO_ALLOC_POOL_BLOCK_COUNT_37 > 0 && AO_ALLOC_POOL_BLOCK_SIZE_37 > 0 && AO_SIZE_BITS > 37)

#define AO_ALLOC_POOL_38                (AO_ALLOC_POOL_BLOCK_COUNT_38 > 0 && AO_ALLOC_POOL_BLOCK_SIZE_38 > 0 && AO_SIZE_BITS > 38)

#define AO_ALLOC_POOL_39                (AO_ALLOC_POOL_BLOCK_COUNT_39 > 0 && AO_ALLOC_POOL_BLOCK_SIZE_39 > 0 && AO_SIZE_BITS > 39)

#define AO_ALLOC_POOL_40                (AO_ALLOC_POOL_BLOCK_COUNT_40 > 0 && AO_ALLOC_POOL_BLOCK_SIZE_40 > 0 && AO_SIZE_BITS > 40)

#define AO_ALLOC_POOL_41                (AO_ALLOC_POOL_BLOCK_COUNT_41 > 0 && AO_ALLOC_POOL_BLOCK_SIZE_41 > 0 && AO_SIZE_BITS > 41)

#define AO_ALLOC_POOL_42                (AO_ALLOC_POOL_BLOCK_COUNT_42 > 0 && AO_ALLOC_POOL_BLOCK_SIZE_42 > 0 && AO_SIZE_BITS > 42)

#define AO_ALLOC_POOL_43                (AO_ALLOC_POOL_BLOCK_COUNT_43 > 0 && AO_ALLOC_POOL_BLOCK_SIZE_43 > 0 && AO_SIZE_BITS > 43)

#define AO_ALLOC_POOL_44                (AO_ALLOC_POOL_BLOCK_COUNT_44 > 0 && AO_ALLOC_POOL_BLOCK_SIZE_44 > 0 && AO_SIZE_BITS > 44)

#define AO_ALLOC_POOL_45                (AO_ALLOC_POOL_BLOCK_COUNT_45 > 0 && AO_ALLOC_POOL_BLOCK_SIZE_45 > 0 && AO_SIZE_BITS > 45)

#define AO_ALLOC_POOL_46                (AO_ALLOC_POOL_BLOCK_COUNT_46 > 0 && AO_ALLOC_POOL_BLOCK_SIZE_46 > 0 && AO_SIZE_BITS > 46)

#define AO_ALLOC_POOL_47                (AO_ALLOC_POOL_BLOCK_COUNT_47 > 0 && AO_ALLOC_POOL_BLOCK_SIZE_47 > 0 && AO_SIZE_BITS > 47)

#define AO_ALLOC_POOL_48                (AO_ALLOC_POOL_BLOCK_COUNT_48 > 0 && AO_ALLOC_POOL_BLOCK_SIZE_48 > 0 && AO_SIZE_BITS > 48)

#define AO_ALLOC_POOL_49                (AO_ALLOC_POOL_BLOCK_COUNT_49 > 0 && AO_ALLOC_POOL_BLOCK_SIZE_49 > 0 && AO_SIZE_BITS > 49)

#define AO_ALLOC_POOL_50                (AO_ALLOC_POOL_BLOCK_COUNT_50 > 0 && AO_ALLOC_POOL_BLOCK_SIZE_50 > 0 && AO_SIZE_BITS > 50)

#define AO_ALLOC_POOL_51                (AO_ALLOC_POOL_BLOCK_COUNT_51 > 0 && AO_ALLOC_POOL_BLOCK_SIZE_51 > 0 && AO_SIZE_BITS > 51)

#define AO_ALLOC_POOL_52                (AO_ALLOC_POOL_BLOCK_COUNT_52 > 0 && AO_ALLOC_POOL_BLOCK_SIZE_52 > 0 && AO_SIZE_BITS > 52)

#define AO_ALLOC_POOL_53                (AO_ALLOC_POOL_BLOCK_COUNT_53 > 0 && AO_ALLOC_POOL_BLOCK_SIZE_53 > 0 && AO_SIZE_BITS > 53)

#define AO_ALLOC_POOL_54                (AO_ALLOC_POOL_BLOCK_COUNT_54 > 0 && AO_ALLOC_POOL_BLOCK_SIZE_54 > 0 && AO_SIZE_BITS > 54)

#define AO_ALLOC_POOL_55                (AO_ALLOC_POOL_BLOCK_COUNT_55 > 0 && AO_ALLOC_POOL_BLOCK_SIZE_55 > 0 && AO_SIZE_BITS > 55)

#define AO_ALLOC_POOL_56                (AO_ALLOC_POOL_BLOCK_COUNT_56 > 0 && AO_ALLOC_POOL_BLOCK_SIZE_56 > 0 && AO_SIZE_BITS > 56)

#define AO_ALLOC_POOL_57                (AO_ALLOC_POOL_BLOCK_COUNT_57 > 0 && AO_ALLOC_POOL_BLOCK_SIZE_57 > 0 && AO_SIZE_BITS > 57)

#define AO_ALLOC_POOL_58                (AO_ALLOC_POOL_BLOCK_COUNT_58 > 0 && AO_ALLOC_POOL_BLOCK_SIZE_58 > 0 && AO_SIZE_BITS > 58)

#define AO_ALLOC_POOL_59                (AO_ALLOC_POOL_BLOCK_COUNT_59 > 0 && AO_ALLOC_POOL_BLOCK_SIZE_59 > 0 && AO_SIZE_BITS > 59)

#define AO_ALLOC_POOL_60                (AO_ALLOC_POOL_BLOCK_COUNT_60 > 0 && AO_ALLOC_POOL_BLOCK_SIZE_60 > 0 && AO_SIZE_BITS > 60)

#define AO_ALLOC_POOL_61                (AO_ALLOC_POOL_BLOCK_COUNT_61 > 0 && AO_ALLOC_POOL_BLOCK_SIZE_61 > 0 && AO_SIZE_BITS > 61)

#define AO_ALLOC_POOL_62                (AO_ALLOC_POOL_BLOCK_COUNT_62 > 0 && AO_ALLOC_POOL_BLOCK_SIZE_62 > 0 && AO_SIZE_BITS > 62)

#define AO_ALLOC_POOL_63                (AO_ALLOC_POOL_BLOCK_COUNT_63 > 0 && AO_ALLOC_POOL_BLOCK_SIZE_63 > 0 && AO_SIZE_BITS > 63)

// ----------------------------------------------------------------------------

#define AO_ALLOC_POOL_BITS              (AO_SIZE_BITS_LOG)

// ----------------------------------------------------------------------------

#define AO_ALLOC_REF_BITS               (AO_SIZE_BITS - AO_ALLOC_POOL_BITS)

// ----------------------------------------------------------------------------

#define AO_ALLOC_REF_MAX                ((1 << (AO_ALLOC_REF_BITS + 1)) - 1)

#define AO_ALLOC_REF_MIN                (0)

// ----------------------------------------------------------------------------

typedef struct  ao_alloc_pool_node_0_t  ao_alloc_pool_node_0_t;

typedef struct  ao_alloc_pool_node_1_t  ao_alloc_pool_node_1_t;

typedef struct  ao_alloc_pool_node_2_t  ao_alloc_pool_node_2_t;

typedef struct  ao_alloc_pool_node_3_t  ao_alloc_pool_node_3_t;

typedef struct  ao_alloc_pool_node_4_t  ao_alloc_pool_node_4_t;

typedef struct  ao_alloc_pool_node_5_t  ao_alloc_pool_node_5_t;

typedef struct  ao_alloc_pool_node_6_t  ao_alloc_pool_node_6_t;

typedef struct  ao_alloc_pool_node_7_t  ao_alloc_pool_node_7_t;

typedef struct  ao_alloc_pool_node_8_t  ao_alloc_pool_node_8_t;

typedef struct  ao_alloc_pool_node_9_t  ao_alloc_pool_node_9_t;

typedef struct  ao_alloc_pool_node_10_t ao_alloc_pool_node_10_t;

typedef struct  ao_alloc_pool_node_11_t ao_alloc_pool_node_11_t;

typedef struct  ao_alloc_pool_node_12_t ao_alloc_pool_node_12_t;

typedef struct  ao_alloc_pool_node_13_t ao_alloc_pool_node_13_t;

typedef struct  ao_alloc_pool_node_14_t ao_alloc_pool_node_14_t;

typedef struct  ao_alloc_pool_node_15_t ao_alloc_pool_node_15_t;

typedef struct  ao_alloc_pool_node_16_t ao_alloc_pool_node_16_t;

typedef struct  ao_alloc_pool_node_17_t ao_alloc_pool_node_17_t;

typedef struct  ao_alloc_pool_node_18_t ao_alloc_pool_node_18_t;

typedef struct  ao_alloc_pool_node_19_t ao_alloc_pool_node_19_t;

typedef struct  ao_alloc_pool_node_20_t ao_alloc_pool_node_20_t;

typedef struct  ao_alloc_pool_node_21_t ao_alloc_pool_node_21_t;

typedef struct  ao_alloc_pool_node_22_t ao_alloc_pool_node_22_t;

typedef struct  ao_alloc_pool_node_23_t ao_alloc_pool_node_23_t;

typedef struct  ao_alloc_pool_node_24_t ao_alloc_pool_node_24_t;

typedef struct  ao_alloc_pool_node_25_t ao_alloc_pool_node_25_t;

typedef struct  ao_alloc_pool_node_26_t ao_alloc_pool_node_26_t;

typedef struct  ao_alloc_pool_node_27_t ao_alloc_pool_node_27_t;

typedef struct  ao_alloc_pool_node_28_t ao_alloc_pool_node_28_t;

typedef struct  ao_alloc_pool_node_29_t ao_alloc_pool_node_29_t;

typedef struct  ao_alloc_pool_node_30_t ao_alloc_pool_node_30_t;

typedef struct  ao_alloc_pool_node_31_t ao_alloc_pool_node_31_t;

typedef struct  ao_alloc_pool_node_32_t ao_alloc_pool_node_32_t;

typedef struct  ao_alloc_pool_node_33_t ao_alloc_pool_node_33_t;

typedef struct  ao_alloc_pool_node_34_t ao_alloc_pool_node_34_t;

typedef struct  ao_alloc_pool_node_35_t ao_alloc_pool_node_35_t;

typedef struct  ao_alloc_pool_node_36_t ao_alloc_pool_node_36_t;

typedef struct  ao_alloc_pool_node_37_t ao_alloc_pool_node_37_t;

typedef struct  ao_alloc_pool_node_38_t ao_alloc_pool_node_38_t;

typedef struct  ao_alloc_pool_node_39_t ao_alloc_pool_node_39_t;

typedef struct  ao_alloc_pool_node_40_t ao_alloc_pool_node_40_t;

typedef struct  ao_alloc_pool_node_41_t ao_alloc_pool_node_41_t;

typedef struct  ao_alloc_pool_node_42_t ao_alloc_pool_node_42_t;

typedef struct  ao_alloc_pool_node_43_t ao_alloc_pool_node_43_t;

typedef struct  ao_alloc_pool_node_44_t ao_alloc_pool_node_44_t;

typedef struct  ao_alloc_pool_node_45_t ao_alloc_pool_node_45_t;

typedef struct  ao_alloc_pool_node_46_t ao_alloc_pool_node_46_t;

typedef struct  ao_alloc_pool_node_47_t ao_alloc_pool_node_47_t;

typedef struct  ao_alloc_pool_node_48_t ao_alloc_pool_node_48_t;

typedef struct  ao_alloc_pool_node_49_t ao_alloc_pool_node_49_t;

typedef struct  ao_alloc_pool_node_50_t ao_alloc_pool_node_50_t;

typedef struct  ao_alloc_pool_node_51_t ao_alloc_pool_node_51_t;

typedef struct  ao_alloc_pool_node_52_t ao_alloc_pool_node_52_t;

typedef struct  ao_alloc_pool_node_53_t ao_alloc_pool_node_53_t;

typedef struct  ao_alloc_pool_node_54_t ao_alloc_pool_node_54_t;

typedef struct  ao_alloc_pool_node_55_t ao_alloc_pool_node_55_t;

typedef struct  ao_alloc_pool_node_56_t ao_alloc_pool_node_56_t;

typedef struct  ao_alloc_pool_node_57_t ao_alloc_pool_node_57_t;

typedef struct  ao_alloc_pool_node_58_t ao_alloc_pool_node_58_t;

typedef struct  ao_alloc_pool_node_59_t ao_alloc_pool_node_59_t;

typedef struct  ao_alloc_pool_node_60_t ao_alloc_pool_node_60_t;

typedef struct  ao_alloc_pool_node_61_t ao_alloc_pool_node_61_t;

typedef struct  ao_alloc_pool_node_62_t ao_alloc_pool_node_62_t;

typedef struct  ao_alloc_pool_node_63_t ao_alloc_pool_node_63_t;

// ----------------------------------------------------------------------------

struct  ao_alloc_pool_node_t
{
    size_t                              pool    : AO_ALLOC_POOL_BITS;

    size_t                              ref     : AO_ALLOC_REF_BITS;

    union
    {
        max_align_t                     align;

        uint8_t                         block   [ 1 ];

        ao_alloc_pool_node_t *          next;
    };
};

// ----------------------------------------------------------------------------

struct  ao_alloc_pool_node_0_t
{
    size_t                              pool    : AO_ALLOC_POOL_BITS;

    size_t                              ref     : AO_ALLOC_REF_BITS;

    union
    {
        max_align_t                     align;

        uint8_t                         block   [ AO_ALLOC_POOL_BLOCK_SIZE_0 ];

        ao_alloc_pool_node_0_t *        next;
    };
};

struct  ao_alloc_pool_node_1_t
{
    size_t                              pool    : AO_ALLOC_POOL_BITS;

    size_t                              ref     : AO_ALLOC_REF_BITS;

    union
    {
        max_align_t                     align;

        uint8_t                         block   [ AO_ALLOC_POOL_BLOCK_SIZE_1 ];

        ao_alloc_pool_node_1_t *        next;
    };
};

struct  ao_alloc_pool_node_2_t
{
    size_t                              pool    : AO_ALLOC_POOL_BITS;

    size_t                              ref     : AO_ALLOC_REF_BITS;

    union
    {
        max_align_t                     align;

        uint8_t                         block   [ AO_ALLOC_POOL_BLOCK_SIZE_2 ];

        ao_alloc_pool_node_2_t *        next;
    };
};

struct  ao_alloc_pool_node_3_t
{
    size_t                              pool    : AO_ALLOC_POOL_BITS;

    size_t                              ref     : AO_ALLOC_REF_BITS;

    union
    {
        max_align_t                     align;

        uint8_t                         block   [ AO_ALLOC_POOL_BLOCK_SIZE_3 ];

        ao_alloc_pool_node_3_t *        next;
    };
};

struct  ao_alloc_pool_node_4_t
{
    size_t                              pool    : AO_ALLOC_POOL_BITS;

    size_t                              ref     : AO_ALLOC_REF_BITS;

    union
    {
        max_align_t                     align;

        uint8_t                         block   [ AO_ALLOC_POOL_BLOCK_SIZE_4 ];

        ao_alloc_pool_node_4_t *        next;
    };
};

struct  ao_alloc_pool_node_5_t
{
    size_t                              pool    : AO_ALLOC_POOL_BITS;

    size_t                              ref     : AO_ALLOC_REF_BITS;

    union
    {
        max_align_t                     align;

        uint8_t                         block   [ AO_ALLOC_POOL_BLOCK_SIZE_5 ];

        ao_alloc_pool_node_5_t *        next;
    };
};

struct  ao_alloc_pool_node_6_t
{
    size_t                              pool    : AO_ALLOC_POOL_BITS;

    size_t                              ref     : AO_ALLOC_REF_BITS;

    union
    {
        max_align_t                     align;

        uint8_t                         block   [ AO_ALLOC_POOL_BLOCK_SIZE_6 ];

        ao_alloc_pool_node_6_t *        next;
    };
};

struct  ao_alloc_pool_node_7_t
{
    size_t                              pool    : AO_ALLOC_POOL_BITS;

    size_t                              ref     : AO_ALLOC_REF_BITS;

    union
    {
        max_align_t                     align;

        uint8_t                         block   [ AO_ALLOC_POOL_BLOCK_SIZE_7 ];

        ao_alloc_pool_node_7_t *        next;
    };
};

struct  ao_alloc_pool_node_8_t
{
    size_t                              pool    : AO_ALLOC_POOL_BITS;

    size_t                              ref     : AO_ALLOC_REF_BITS;

    union
    {
        max_align_t                     align;

        uint8_t                         block   [ AO_ALLOC_POOL_BLOCK_SIZE_8 ];

        ao_alloc_pool_node_8_t *        next;
    };
};

struct  ao_alloc_pool_node_9_t
{
    size_t                              pool    : AO_ALLOC_POOL_BITS;

    size_t                              ref     : AO_ALLOC_REF_BITS;

    union
    {
        max_align_t                     align;

        uint8_t                         block   [ AO_ALLOC_POOL_BLOCK_SIZE_9 ];

        ao_alloc_pool_node_9_t *        next;
    };
};

struct  ao_alloc_pool_node_10_t
{
    size_t                              pool    : AO_ALLOC_POOL_BITS;

    size_t                              ref     : AO_ALLOC_REF_BITS;

    union
    {
        max_align_t                     align;

        uint8_t                         block   [ AO_ALLOC_POOL_BLOCK_SIZE_10 ];

        ao_alloc_pool_node_10_t *       next;
    };
};

struct  ao_alloc_pool_node_11_t
{
    size_t                              pool    : AO_ALLOC_POOL_BITS;

    size_t                              ref     : AO_ALLOC_REF_BITS;

    union
    {
        max_align_t                     align;

        uint8_t                         block   [ AO_ALLOC_POOL_BLOCK_SIZE_11 ];

        ao_alloc_pool_node_11_t *       next;
    };
};

struct  ao_alloc_pool_node_12_t
{
    size_t                              pool    : AO_ALLOC_POOL_BITS;

    size_t                              ref     : AO_ALLOC_REF_BITS;

    union
    {
        max_align_t                     align;

        uint8_t                         block   [ AO_ALLOC_POOL_BLOCK_SIZE_12 ];

        ao_alloc_pool_node_12_t *       next;
    };
};

struct  ao_alloc_pool_node_13_t
{
    size_t                              pool    : AO_ALLOC_POOL_BITS;

    size_t                              ref     : AO_ALLOC_REF_BITS;

    union
    {
        max_align_t                     align;

        uint8_t                         block   [ AO_ALLOC_POOL_BLOCK_SIZE_13 ];

        ao_alloc_pool_node_13_t *       next;
    };
};

struct  ao_alloc_pool_node_14_t
{
    size_t                              pool    : AO_ALLOC_POOL_BITS;

    size_t                              ref     : AO_ALLOC_REF_BITS;

    union
    {
        max_align_t                     align;

        uint8_t                         block   [ AO_ALLOC_POOL_BLOCK_SIZE_14 ];

        ao_alloc_pool_node_14_t *       next;
    };
};

struct  ao_alloc_pool_node_15_t
{
    size_t                              pool    : AO_ALLOC_POOL_BITS;

    size_t                              ref     : AO_ALLOC_REF_BITS;

    union
    {
        max_align_t                     align;

        uint8_t                         block   [ AO_ALLOC_POOL_BLOCK_SIZE_15 ];

        ao_alloc_pool_node_15_t *       next;
    };
};

struct  ao_alloc_pool_node_16_t
{
    size_t                              pool    : AO_ALLOC_POOL_BITS;

    size_t                              ref     : AO_ALLOC_REF_BITS;

    union
    {
        max_align_t                     align;

        uint8_t                         block   [ AO_ALLOC_POOL_BLOCK_SIZE_16 ];

        ao_alloc_pool_node_16_t *       next;
    };
};

struct  ao_alloc_pool_node_17_t
{
    size_t                              pool    : AO_ALLOC_POOL_BITS;

    size_t                              ref     : AO_ALLOC_REF_BITS;

    union
    {
        max_align_t                     align;

        uint8_t                         block   [ AO_ALLOC_POOL_BLOCK_SIZE_17 ];

        ao_alloc_pool_node_17_t *       next;
    };
};

struct  ao_alloc_pool_node_18_t
{
    size_t                              pool    : AO_ALLOC_POOL_BITS;

    size_t                              ref     : AO_ALLOC_REF_BITS;

    union
    {
        max_align_t                     align;

        uint8_t                         block   [ AO_ALLOC_POOL_BLOCK_SIZE_18 ];

        ao_alloc_pool_node_18_t *       next;
    };
};

struct  ao_alloc_pool_node_19_t
{
    size_t                              pool    : AO_ALLOC_POOL_BITS;

    size_t                              ref     : AO_ALLOC_REF_BITS;

    union
    {
        max_align_t                     align;

        uint8_t                         block   [ AO_ALLOC_POOL_BLOCK_SIZE_19 ];

        ao_alloc_pool_node_19_t *       next;
    };
};

struct  ao_alloc_pool_node_20_t
{
    size_t                              pool    : AO_ALLOC_POOL_BITS;

    size_t                              ref     : AO_ALLOC_REF_BITS;

    union
    {
        max_align_t                     align;

        uint8_t                         block   [ AO_ALLOC_POOL_BLOCK_SIZE_20 ];

        ao_alloc_pool_node_20_t *       next;
    };
};

struct  ao_alloc_pool_node_21_t
{
    size_t                              pool    : AO_ALLOC_POOL_BITS;

    size_t                              ref     : AO_ALLOC_REF_BITS;

    union
    {
        max_align_t                     align;

        uint8_t                         block   [ AO_ALLOC_POOL_BLOCK_SIZE_21 ];

        ao_alloc_pool_node_21_t *       next;
    };
};

struct  ao_alloc_pool_node_22_t
{
    size_t                              pool    : AO_ALLOC_POOL_BITS;

    size_t                              ref     : AO_ALLOC_REF_BITS;

    union
    {
        max_align_t                     align;

        uint8_t                         block   [ AO_ALLOC_POOL_BLOCK_SIZE_22 ];

        ao_alloc_pool_node_22_t *       next;
    };
};

struct  ao_alloc_pool_node_23_t
{
    size_t                              pool    : AO_ALLOC_POOL_BITS;

    size_t                              ref     : AO_ALLOC_REF_BITS;

    union
    {
        max_align_t                     align;

        uint8_t                         block   [ AO_ALLOC_POOL_BLOCK_SIZE_23 ];

        ao_alloc_pool_node_23_t *       next;
    };
};

struct  ao_alloc_pool_node_24_t
{
    size_t                              pool    : AO_ALLOC_POOL_BITS;

    size_t                              ref     : AO_ALLOC_REF_BITS;

    union
    {
        max_align_t                     align;

        uint8_t                         block   [ AO_ALLOC_POOL_BLOCK_SIZE_24 ];

        ao_alloc_pool_node_24_t *       next;
    };
};

struct  ao_alloc_pool_node_25_t
{
    size_t                              pool    : AO_ALLOC_POOL_BITS;

    size_t                              ref     : AO_ALLOC_REF_BITS;

    union
    {
        max_align_t                     align;

        uint8_t                         block   [ AO_ALLOC_POOL_BLOCK_SIZE_25 ];

        ao_alloc_pool_node_25_t *       next;
    };
};

struct  ao_alloc_pool_node_26_t
{
    size_t                              pool    : AO_ALLOC_POOL_BITS;

    size_t                              ref     : AO_ALLOC_REF_BITS;

    union
    {
        max_align_t                     align;

        uint8_t                         block   [ AO_ALLOC_POOL_BLOCK_SIZE_26 ];

        ao_alloc_pool_node_26_t *       next;
    };
};

struct  ao_alloc_pool_node_27_t
{
    size_t                              pool    : AO_ALLOC_POOL_BITS;

    size_t                              ref     : AO_ALLOC_REF_BITS;

    union
    {
        max_align_t                     align;

        uint8_t                         block   [ AO_ALLOC_POOL_BLOCK_SIZE_27 ];

        ao_alloc_pool_node_27_t *       next;
    };
};

struct  ao_alloc_pool_node_28_t
{
    size_t                              pool    : AO_ALLOC_POOL_BITS;

    size_t                              ref     : AO_ALLOC_REF_BITS;

    union
    {
        max_align_t                     align;

        uint8_t                         block   [ AO_ALLOC_POOL_BLOCK_SIZE_28 ];

        ao_alloc_pool_node_28_t *       next;
    };
};

struct  ao_alloc_pool_node_29_t
{
    size_t                              pool    : AO_ALLOC_POOL_BITS;

    size_t                              ref     : AO_ALLOC_REF_BITS;

    union
    {
        max_align_t                     align;

        uint8_t                         block   [ AO_ALLOC_POOL_BLOCK_SIZE_29 ];

        ao_alloc_pool_node_29_t *       next;
    };
};

struct  ao_alloc_pool_node_30_t
{
    size_t                              pool    : AO_ALLOC_POOL_BITS;

    size_t                              ref     : AO_ALLOC_REF_BITS;

    union
    {
        max_align_t                     align;

        uint8_t                         block   [ AO_ALLOC_POOL_BLOCK_SIZE_30 ];

        ao_alloc_pool_node_30_t *       next;
    };
};

struct  ao_alloc_pool_node_31_t
{
    size_t                              pool    : AO_ALLOC_POOL_BITS;

    size_t                              ref     : AO_ALLOC_REF_BITS;

    union
    {
        max_align_t                     align;

        uint8_t                         block   [ AO_ALLOC_POOL_BLOCK_SIZE_31 ];

        ao_alloc_pool_node_31_t *       next;
    };
};

struct  ao_alloc_pool_node_32_t
{
    size_t                              pool    : AO_ALLOC_POOL_BITS;

    size_t                              ref     : AO_ALLOC_REF_BITS;

    union
    {
        max_align_t                     align;

        uint8_t                         block   [ AO_ALLOC_POOL_BLOCK_SIZE_32 ];

        ao_alloc_pool_node_32_t *       next;
    };
};

struct  ao_alloc_pool_node_33_t
{
    size_t                              pool    : AO_ALLOC_POOL_BITS;

    size_t                              ref     : AO_ALLOC_REF_BITS;

    union
    {
        max_align_t                     align;

        uint8_t                         block   [ AO_ALLOC_POOL_BLOCK_SIZE_33 ];

        ao_alloc_pool_node_33_t *       next;
    };
};

struct  ao_alloc_pool_node_34_t
{
    size_t                              pool    : AO_ALLOC_POOL_BITS;

    size_t                              ref     : AO_ALLOC_REF_BITS;

    union
    {
        max_align_t                     align;

        uint8_t                         block   [ AO_ALLOC_POOL_BLOCK_SIZE_34 ];

        ao_alloc_pool_node_34_t *       next;
    };
};

struct  ao_alloc_pool_node_35_t
{
    size_t                              pool    : AO_ALLOC_POOL_BITS;

    size_t                              ref     : AO_ALLOC_REF_BITS;

    union
    {
        max_align_t                     align;

        uint8_t                         block   [ AO_ALLOC_POOL_BLOCK_SIZE_35 ];

        ao_alloc_pool_node_35_t *       next;
    };
};

struct  ao_alloc_pool_node_36_t
{
    size_t                              pool    : AO_ALLOC_POOL_BITS;

    size_t                              ref     : AO_ALLOC_REF_BITS;

    union
    {
        max_align_t                     align;

        uint8_t                         block   [ AO_ALLOC_POOL_BLOCK_SIZE_36 ];

        ao_alloc_pool_node_36_t *       next;
    };
};

struct  ao_alloc_pool_node_37_t
{
    size_t                              pool    : AO_ALLOC_POOL_BITS;

    size_t                              ref     : AO_ALLOC_REF_BITS;

    union
    {
        max_align_t                     align;

        uint8_t                         block   [ AO_ALLOC_POOL_BLOCK_SIZE_37 ];

        ao_alloc_pool_node_37_t *       next;
    };
};

struct  ao_alloc_pool_node_38_t
{
    size_t                              pool    : AO_ALLOC_POOL_BITS;

    size_t                              ref     : AO_ALLOC_REF_BITS;

    union
    {
        max_align_t                     align;

        uint8_t                         block   [ AO_ALLOC_POOL_BLOCK_SIZE_38 ];

        ao_alloc_pool_node_38_t *       next;
    };
};

struct  ao_alloc_pool_node_39_t
{
    size_t                              pool    : AO_ALLOC_POOL_BITS;

    size_t                              ref     : AO_ALLOC_REF_BITS;

    union
    {
        max_align_t                     align;

        uint8_t                         block   [ AO_ALLOC_POOL_BLOCK_SIZE_39 ];

        ao_alloc_pool_node_39_t *       next;
    };
};

struct  ao_alloc_pool_node_40_t
{
    size_t                              pool    : AO_ALLOC_POOL_BITS;

    size_t                              ref     : AO_ALLOC_REF_BITS;

    union
    {
        max_align_t                     align;

        uint8_t                         block   [ AO_ALLOC_POOL_BLOCK_SIZE_40 ];

        ao_alloc_pool_node_40_t *       next;
    };
};

struct  ao_alloc_pool_node_41_t
{
    size_t                              pool    : AO_ALLOC_POOL_BITS;

    size_t                              ref     : AO_ALLOC_REF_BITS;

    union
    {
        max_align_t                     align;

        uint8_t                         block   [ AO_ALLOC_POOL_BLOCK_SIZE_41 ];

        ao_alloc_pool_node_41_t *       next;
    };
};

struct  ao_alloc_pool_node_42_t
{
    size_t                              pool    : AO_ALLOC_POOL_BITS;

    size_t                              ref     : AO_ALLOC_REF_BITS;

    union
    {
        max_align_t                     align;

        uint8_t                         block   [ AO_ALLOC_POOL_BLOCK_SIZE_42 ];

        ao_alloc_pool_node_42_t *       next;
    };
};

struct  ao_alloc_pool_node_43_t
{
    size_t                              pool    : AO_ALLOC_POOL_BITS;

    size_t                              ref     : AO_ALLOC_REF_BITS;

    union
    {
        max_align_t                     align;

        uint8_t                         block   [ AO_ALLOC_POOL_BLOCK_SIZE_43 ];

        ao_alloc_pool_node_43_t *       next;
    };
};

struct  ao_alloc_pool_node_44_t
{
    size_t                              pool    : AO_ALLOC_POOL_BITS;

    size_t                              ref     : AO_ALLOC_REF_BITS;

    union
    {
        max_align_t                     align;

        uint8_t                         block   [ AO_ALLOC_POOL_BLOCK_SIZE_44 ];

        ao_alloc_pool_node_44_t *       next;
    };
};

struct  ao_alloc_pool_node_45_t
{
    size_t                              pool    : AO_ALLOC_POOL_BITS;

    size_t                              ref     : AO_ALLOC_REF_BITS;

    union
    {
        max_align_t                     align;

        uint8_t                         block   [ AO_ALLOC_POOL_BLOCK_SIZE_45 ];

        ao_alloc_pool_node_45_t *       next;
    };
};

struct  ao_alloc_pool_node_46_t
{
    size_t                              pool    : AO_ALLOC_POOL_BITS;

    size_t                              ref     : AO_ALLOC_REF_BITS;

    union
    {
        max_align_t                     align;

        uint8_t                         block   [ AO_ALLOC_POOL_BLOCK_SIZE_46 ];

        ao_alloc_pool_node_46_t *       next;
    };
};

struct  ao_alloc_pool_node_47_t
{
    size_t                              pool    : AO_ALLOC_POOL_BITS;

    size_t                              ref     : AO_ALLOC_REF_BITS;

    union
    {
        max_align_t                     align;

        uint8_t                         block   [ AO_ALLOC_POOL_BLOCK_SIZE_47 ];

        ao_alloc_pool_node_47_t *       next;
    };
};

struct  ao_alloc_pool_node_48_t
{
    size_t                              pool    : AO_ALLOC_POOL_BITS;

    size_t                              ref     : AO_ALLOC_REF_BITS;

    union
    {
        max_align_t                     align;

        uint8_t                         block   [ AO_ALLOC_POOL_BLOCK_SIZE_48 ];

        ao_alloc_pool_node_48_t *       next;
    };
};

struct  ao_alloc_pool_node_49_t
{
    size_t                              pool    : AO_ALLOC_POOL_BITS;

    size_t                              ref     : AO_ALLOC_REF_BITS;

    union
    {
        max_align_t                     align;

        uint8_t                         block   [ AO_ALLOC_POOL_BLOCK_SIZE_49 ];

        ao_alloc_pool_node_49_t *       next;
    };
};

struct  ao_alloc_pool_node_50_t
{
    size_t                              pool    : AO_ALLOC_POOL_BITS;

    size_t                              ref     : AO_ALLOC_REF_BITS;

    union
    {
        max_align_t                     align;

        uint8_t                         block   [ AO_ALLOC_POOL_BLOCK_SIZE_50 ];

        ao_alloc_pool_node_50_t *       next;
    };
};

struct  ao_alloc_pool_node_51_t
{
    size_t                              pool    : AO_ALLOC_POOL_BITS;

    size_t                              ref     : AO_ALLOC_REF_BITS;

    union
    {
        max_align_t                     align;

        uint8_t                         block   [ AO_ALLOC_POOL_BLOCK_SIZE_51 ];

        ao_alloc_pool_node_51_t *       next;
    };
};

struct  ao_alloc_pool_node_52_t
{
    size_t                              pool    : AO_ALLOC_POOL_BITS;

    size_t                              ref     : AO_ALLOC_REF_BITS;

    union
    {
        max_align_t                     align;

        uint8_t                         block   [ AO_ALLOC_POOL_BLOCK_SIZE_52 ];

        ao_alloc_pool_node_52_t *       next;
    };
};

struct  ao_alloc_pool_node_53_t
{
    size_t                              pool    : AO_ALLOC_POOL_BITS;

    size_t                              ref     : AO_ALLOC_REF_BITS;

    union
    {
        max_align_t                     align;

        uint8_t                         block   [ AO_ALLOC_POOL_BLOCK_SIZE_53 ];

        ao_alloc_pool_node_53_t *       next;
    };
};

struct  ao_alloc_pool_node_54_t
{
    size_t                              pool    : AO_ALLOC_POOL_BITS;

    size_t                              ref     : AO_ALLOC_REF_BITS;

    union
    {
        max_align_t                     align;

        uint8_t                         block   [ AO_ALLOC_POOL_BLOCK_SIZE_54 ];

        ao_alloc_pool_node_54_t *       next;
    };
};

struct  ao_alloc_pool_node_55_t
{
    size_t                              pool    : AO_ALLOC_POOL_BITS;

    size_t                              ref     : AO_ALLOC_REF_BITS;

    union
    {
        max_align_t                     align;

        uint8_t                         block   [ AO_ALLOC_POOL_BLOCK_SIZE_55 ];

        ao_alloc_pool_node_55_t *       next;
    };
};

struct  ao_alloc_pool_node_56_t
{
    size_t                              pool    : AO_ALLOC_POOL_BITS;

    size_t                              ref     : AO_ALLOC_REF_BITS;

    union
    {
        max_align_t                     align;

        uint8_t                         block   [ AO_ALLOC_POOL_BLOCK_SIZE_56 ];

        ao_alloc_pool_node_56_t *       next;
    };
};

struct  ao_alloc_pool_node_57_t
{
    size_t                              pool    : AO_ALLOC_POOL_BITS;

    size_t                              ref     : AO_ALLOC_REF_BITS;

    union
    {
        max_align_t                     align;

        uint8_t                         block   [ AO_ALLOC_POOL_BLOCK_SIZE_57 ];

        ao_alloc_pool_node_57_t *       next;
    };
};

struct  ao_alloc_pool_node_58_t
{
    size_t                              pool    : AO_ALLOC_POOL_BITS;

    size_t                              ref     : AO_ALLOC_REF_BITS;

    union
    {
        max_align_t                     align;

        uint8_t                         block   [ AO_ALLOC_POOL_BLOCK_SIZE_58 ];

        ao_alloc_pool_node_58_t *       next;
    };
};

struct  ao_alloc_pool_node_59_t
{
    size_t                              pool    : AO_ALLOC_POOL_BITS;

    size_t                              ref     : AO_ALLOC_REF_BITS;

    union
    {
        max_align_t                     align;

        uint8_t                         block   [ AO_ALLOC_POOL_BLOCK_SIZE_59 ];

        ao_alloc_pool_node_59_t *       next;
    };
};

struct  ao_alloc_pool_node_60_t
{
    size_t                              pool    : AO_ALLOC_POOL_BITS;

    size_t                              ref     : AO_ALLOC_REF_BITS;

    union
    {
        max_align_t                     align;

        uint8_t                         block   [ AO_ALLOC_POOL_BLOCK_SIZE_60 ];

        ao_alloc_pool_node_60_t *       next;
    };
};

struct  ao_alloc_pool_node_61_t
{
    size_t                              pool    : AO_ALLOC_POOL_BITS;

    size_t                              ref     : AO_ALLOC_REF_BITS;

    union
    {
        max_align_t                     align;

        uint8_t                         block   [ AO_ALLOC_POOL_BLOCK_SIZE_61 ];

        ao_alloc_pool_node_61_t *       next;
    };
};

struct  ao_alloc_pool_node_62_t
{
    size_t                              pool    : AO_ALLOC_POOL_BITS;

    size_t                              ref     : AO_ALLOC_REF_BITS;

    union
    {
        max_align_t                     align;

        uint8_t                         block   [ AO_ALLOC_POOL_BLOCK_SIZE_62 ];

        ao_alloc_pool_node_62_t *       next;
    };
};

struct  ao_alloc_pool_node_63_t
{
    size_t                              pool    : AO_ALLOC_POOL_BITS;

    size_t                              ref     : AO_ALLOC_REF_BITS;

    union
    {
        max_align_t                     align;

        uint8_t                         block   [ AO_ALLOC_POOL_BLOCK_SIZE_63 ];

        ao_alloc_pool_node_63_t *       next;
    };
};

// ----------------------------------------------------------------------------

static  void *                          ao_acquire_3(size_t s);

// ----------------------------------------------------------------------------

static  void                            ao_boot_alloc_pool_0();

static  void                            ao_boot_alloc_pool_1();

static  void                            ao_boot_alloc_pool_2();

static  void                            ao_boot_alloc_pool_3();

static  void                            ao_boot_alloc_pool_4();

static  void                            ao_boot_alloc_pool_5();

static  void                            ao_boot_alloc_pool_6();

static  void                            ao_boot_alloc_pool_7();

static  void                            ao_boot_alloc_pool_8();

static  void                            ao_boot_alloc_pool_9();

static  void                            ao_boot_alloc_pool_10();

static  void                            ao_boot_alloc_pool_11();

static  void                            ao_boot_alloc_pool_12();

static  void                            ao_boot_alloc_pool_13();

static  void                            ao_boot_alloc_pool_14();

static  void                            ao_boot_alloc_pool_15();

static  void                            ao_boot_alloc_pool_16();

static  void                            ao_boot_alloc_pool_17();

static  void                            ao_boot_alloc_pool_18();

static  void                            ao_boot_alloc_pool_19();

static  void                            ao_boot_alloc_pool_20();

static  void                            ao_boot_alloc_pool_21();

static  void                            ao_boot_alloc_pool_22();

static  void                            ao_boot_alloc_pool_23();

static  void                            ao_boot_alloc_pool_24();

static  void                            ao_boot_alloc_pool_25();

static  void                            ao_boot_alloc_pool_26();

static  void                            ao_boot_alloc_pool_27();

static  void                            ao_boot_alloc_pool_28();

static  void                            ao_boot_alloc_pool_29();

static  void                            ao_boot_alloc_pool_30();

static  void                            ao_boot_alloc_pool_31();

static  void                            ao_boot_alloc_pool_32();

static  void                            ao_boot_alloc_pool_33();

static  void                            ao_boot_alloc_pool_34();

static  void                            ao_boot_alloc_pool_35();

static  void                            ao_boot_alloc_pool_36();

static  void                            ao_boot_alloc_pool_37();

static  void                            ao_boot_alloc_pool_38();

static  void                            ao_boot_alloc_pool_39();

static  void                            ao_boot_alloc_pool_40();

static  void                            ao_boot_alloc_pool_41();

static  void                            ao_boot_alloc_pool_42();

static  void                            ao_boot_alloc_pool_43();

static  void                            ao_boot_alloc_pool_44();

static  void                            ao_boot_alloc_pool_45();

static  void                            ao_boot_alloc_pool_46();

static  void                            ao_boot_alloc_pool_47();

static  void                            ao_boot_alloc_pool_48();

static  void                            ao_boot_alloc_pool_49();

static  void                            ao_boot_alloc_pool_50();

static  void                            ao_boot_alloc_pool_51();

static  void                            ao_boot_alloc_pool_52();

static  void                            ao_boot_alloc_pool_53();

static  void                            ao_boot_alloc_pool_54();

static  void                            ao_boot_alloc_pool_55();

static  void                            ao_boot_alloc_pool_56();

static  void                            ao_boot_alloc_pool_57();

static  void                            ao_boot_alloc_pool_58();

static  void                            ao_boot_alloc_pool_59();

static  void                            ao_boot_alloc_pool_60();

static  void                            ao_boot_alloc_pool_61();

static  void                            ao_boot_alloc_pool_62();

static  void                            ao_boot_alloc_pool_63();

// ----------------------------------------------------------------------------

static  bool                            ao_release_3(void * p);

// ----------------------------------------------------------------------------

static  bool                            ao_retain_3(void * p);

// ----------------------------------------------------------------------------

#if     AO_ALLOC_ALLOCATED_MAX || AO_ALLOC_ALLOCATED

        size_t              volatile    ao_alloc_allocated;

#endif

#if     AO_ALLOC_ALLOCATED_MAX

        size_t              volatile    ao_alloc_allocated_max;

#endif

// ----------------------------------------------------------------------------

static  size_t                          ao_alloc_bitmap;

// ----------------------------------------------------------------------------

#if     AO_ALLOC_FREE_MIN || AO_ALLOC_FREE

        size_t              volatile    ao_alloc_free;

#endif

#if     AO_ALLOC_FREE_MIN

        size_t              volatile    ao_alloc_free_min;

#endif

// ----------------------------------------------------------------------------

#if     AO_ALLOC_POOL_0

        ao_alloc_pool_t                 ao_alloc_pool_0;

static  ao_alloc_pool_node_0_t          ao_alloc_pool_nodes_0[AO_ALLOC_POOL_BLOCK_COUNT_0];

#endif

#if     AO_ALLOC_POOL_1

        ao_alloc_pool_t                 ao_alloc_pool_1;

static  ao_alloc_pool_node_1_t          ao_alloc_pool_nodes_1[AO_ALLOC_POOL_BLOCK_COUNT_1];

#endif

#if     AO_ALLOC_POOL_2

        ao_alloc_pool_t                 ao_alloc_pool_2;

static  ao_alloc_pool_node_2_t          ao_alloc_pool_nodes_2[AO_ALLOC_POOL_BLOCK_COUNT_2];

#endif

#if     AO_ALLOC_POOL_3

        ao_alloc_pool_t                 ao_alloc_pool_3;

static  ao_alloc_pool_node_3_t          ao_alloc_pool_nodes_3[AO_ALLOC_POOL_BLOCK_COUNT_3];

#endif

#if     AO_ALLOC_POOL_4

        ao_alloc_pool_t                 ao_alloc_pool_4;

static  ao_alloc_pool_node_4_t          ao_alloc_pool_nodes_4[AO_ALLOC_POOL_BLOCK_COUNT_4];

#endif

#if     AO_ALLOC_POOL_5

        ao_alloc_pool_t                 ao_alloc_pool_5;

static  ao_alloc_pool_node_5_t          ao_alloc_pool_nodes_5[AO_ALLOC_POOL_BLOCK_COUNT_5];

#endif

#if     AO_ALLOC_POOL_6

        ao_alloc_pool_t                 ao_alloc_pool_6;

static  ao_alloc_pool_node_6_t          ao_alloc_pool_nodes_6[AO_ALLOC_POOL_BLOCK_COUNT_6];

#endif

#if     AO_ALLOC_POOL_7

        ao_alloc_pool_t                 ao_alloc_pool_7;

static  ao_alloc_pool_node_7_t          ao_alloc_pool_nodes_7[AO_ALLOC_POOL_BLOCK_COUNT_7];

#endif

#if     AO_ALLOC_POOL_8

        ao_alloc_pool_t                 ao_alloc_pool_8;

static  ao_alloc_pool_node_8_t          ao_alloc_pool_nodes_8[AO_ALLOC_POOL_BLOCK_COUNT_8];

#endif

#if     AO_ALLOC_POOL_9

        ao_alloc_pool_t                 ao_alloc_pool_9;

static  ao_alloc_pool_node_9_t          ao_alloc_pool_nodes_9[AO_ALLOC_POOL_BLOCK_COUNT_9];

#endif

#if     AO_ALLOC_POOL_10

        ao_alloc_pool_t                 ao_alloc_pool_10;

static  ao_alloc_pool_node_10_t         ao_alloc_pool_nodes_10[AO_ALLOC_POOL_BLOCK_COUNT_10];

#endif

#if     AO_ALLOC_POOL_11

        ao_alloc_pool_t                 ao_alloc_pool_11;

static  ao_alloc_pool_node_11_t         ao_alloc_pool_nodes_11[AO_ALLOC_POOL_BLOCK_COUNT_11];

#endif

#if     AO_ALLOC_POOL_12

        ao_alloc_pool_t                 ao_alloc_pool_12;

static  ao_alloc_pool_node_12_t         ao_alloc_pool_nodes_12[AO_ALLOC_POOL_BLOCK_COUNT_12];

#endif

#if     AO_ALLOC_POOL_13

        ao_alloc_pool_t                 ao_alloc_pool_13;

static  ao_alloc_pool_node_13_t         ao_alloc_pool_nodes_13[AO_ALLOC_POOL_BLOCK_COUNT_13];

#endif

#if     AO_ALLOC_POOL_14

        ao_alloc_pool_t                 ao_alloc_pool_14;

static  ao_alloc_pool_node_14_t         ao_alloc_pool_nodes_14[AO_ALLOC_POOL_BLOCK_COUNT_14];

#endif

#if     AO_ALLOC_POOL_15

        ao_alloc_pool_t                 ao_alloc_pool_15;

static  ao_alloc_pool_node_15_t         ao_alloc_pool_nodes_15[AO_ALLOC_POOL_BLOCK_COUNT_15];

#endif

#if     AO_ALLOC_POOL_16

        ao_alloc_pool_t                 ao_alloc_pool_16;

static  ao_alloc_pool_node_16_t         ao_alloc_pool_nodes_16[AO_ALLOC_POOL_BLOCK_COUNT_16];

#endif

#if     AO_ALLOC_POOL_17

        ao_alloc_pool_t                 ao_alloc_pool_17;

static  ao_alloc_pool_node_17_t         ao_alloc_pool_nodes_17[AO_ALLOC_POOL_BLOCK_COUNT_17];

#endif

#if     AO_ALLOC_POOL_18

        ao_alloc_pool_t                 ao_alloc_pool_18;

static  ao_alloc_pool_node_18_t         ao_alloc_pool_nodes_18[AO_ALLOC_POOL_BLOCK_COUNT_18];

#endif

#if     AO_ALLOC_POOL_19

        ao_alloc_pool_t                 ao_alloc_pool_19;

static  ao_alloc_pool_node_19_t         ao_alloc_pool_nodes_19[AO_ALLOC_POOL_BLOCK_COUNT_19];

#endif

#if     AO_ALLOC_POOL_20

        ao_alloc_pool_t                 ao_alloc_pool_20;

static  ao_alloc_pool_node_20_t         ao_alloc_pool_nodes_20[AO_ALLOC_POOL_BLOCK_COUNT_20];

#endif

#if     AO_ALLOC_POOL_21

        ao_alloc_pool_t                 ao_alloc_pool_21;

static  ao_alloc_pool_node_21_t         ao_alloc_pool_nodes_21[AO_ALLOC_POOL_BLOCK_COUNT_21];

#endif

#if     AO_ALLOC_POOL_22

        ao_alloc_pool_t                 ao_alloc_pool_22;

static  ao_alloc_pool_node_22_t         ao_alloc_pool_nodes_22[AO_ALLOC_POOL_BLOCK_COUNT_22];

#endif

#if     AO_ALLOC_POOL_23

        ao_alloc_pool_t                 ao_alloc_pool_23;

static  ao_alloc_pool_node_23_t         ao_alloc_pool_nodes_23[AO_ALLOC_POOL_BLOCK_COUNT_23];

#endif

#if     AO_ALLOC_POOL_24

        ao_alloc_pool_t                 ao_alloc_pool_24;

static  ao_alloc_pool_node_24_t         ao_alloc_pool_nodes_24[AO_ALLOC_POOL_BLOCK_COUNT_24];

#endif

#if     AO_ALLOC_POOL_25

        ao_alloc_pool_t                 ao_alloc_pool_25;

static  ao_alloc_pool_node_25_t         ao_alloc_pool_nodes_25[AO_ALLOC_POOL_BLOCK_COUNT_25];

#endif

#if     AO_ALLOC_POOL_26

        ao_alloc_pool_t                 ao_alloc_pool_26;

static  ao_alloc_pool_node_26_t         ao_alloc_pool_nodes_26[AO_ALLOC_POOL_BLOCK_COUNT_26];

#endif

#if     AO_ALLOC_POOL_27

        ao_alloc_pool_t                 ao_alloc_pool_27;

static  ao_alloc_pool_node_27_t         ao_alloc_pool_nodes_27[AO_ALLOC_POOL_BLOCK_COUNT_27];

#endif

#if     AO_ALLOC_POOL_28

        ao_alloc_pool_t                 ao_alloc_pool_28;

static  ao_alloc_pool_node_28_t         ao_alloc_pool_nodes_28[AO_ALLOC_POOL_BLOCK_COUNT_28];

#endif

#if     AO_ALLOC_POOL_29

        ao_alloc_pool_t                 ao_alloc_pool_29;

static  ao_alloc_pool_node_29_t         ao_alloc_pool_nodes_29[AO_ALLOC_POOL_BLOCK_COUNT_29];

#endif

#if     AO_ALLOC_POOL_30

        ao_alloc_pool_t                 ao_alloc_pool_30;

static  ao_alloc_pool_node_30_t         ao_alloc_pool_nodes_30[AO_ALLOC_POOL_BLOCK_COUNT_30];

#endif

#if     AO_ALLOC_POOL_31

        ao_alloc_pool_t                 ao_alloc_pool_31;

static  ao_alloc_pool_node_31_t         ao_alloc_pool_nodes_31[AO_ALLOC_POOL_BLOCK_COUNT_31];

#endif

#if     AO_ALLOC_POOL_32

        ao_alloc_pool_t                 ao_alloc_pool_32;

static  ao_alloc_pool_node_32_t         ao_alloc_pool_nodes_32[AO_ALLOC_POOL_BLOCK_COUNT_32];

#endif

#if     AO_ALLOC_POOL_33

        ao_alloc_pool_t                 ao_alloc_pool_33;

static  ao_alloc_pool_node_33_t         ao_alloc_pool_nodes_33[AO_ALLOC_POOL_BLOCK_COUNT_33];

#endif

#if     AO_ALLOC_POOL_34

        ao_alloc_pool_t                 ao_alloc_pool_34;

static  ao_alloc_pool_node_34_t         ao_alloc_pool_nodes_34[AO_ALLOC_POOL_BLOCK_COUNT_34];

#endif

#if     AO_ALLOC_POOL_35

        ao_alloc_pool_t                 ao_alloc_pool_35;

static  ao_alloc_pool_node_35_t         ao_alloc_pool_nodes_35[AO_ALLOC_POOL_BLOCK_COUNT_35];

#endif

#if     AO_ALLOC_POOL_36

        ao_alloc_pool_t                 ao_alloc_pool_36;

static  ao_alloc_pool_node_36_t         ao_alloc_pool_nodes_36[AO_ALLOC_POOL_BLOCK_COUNT_36];

#endif

#if     AO_ALLOC_POOL_37

        ao_alloc_pool_t                 ao_alloc_pool_37;

static  ao_alloc_pool_node_37_t         ao_alloc_pool_nodes_37[AO_ALLOC_POOL_BLOCK_COUNT_37];

#endif

#if     AO_ALLOC_POOL_38

        ao_alloc_pool_t                 ao_alloc_pool_38;

static  ao_alloc_pool_node_38_t         ao_alloc_pool_nodes_38[AO_ALLOC_POOL_BLOCK_COUNT_38];

#endif

#if     AO_ALLOC_POOL_39

        ao_alloc_pool_t                 ao_alloc_pool_39;

static  ao_alloc_pool_node_39_t         ao_alloc_pool_nodes_39[AO_ALLOC_POOL_BLOCK_COUNT_39];

#endif

#if     AO_ALLOC_POOL_40

        ao_alloc_pool_t                 ao_alloc_pool_40;

static  ao_alloc_pool_node_40_t         ao_alloc_pool_nodes_40[AO_ALLOC_POOL_BLOCK_COUNT_40];

#endif

#if     AO_ALLOC_POOL_41

        ao_alloc_pool_t                 ao_alloc_pool_41;

static  ao_alloc_pool_node_41_t         ao_alloc_pool_nodes_41[AO_ALLOC_POOL_BLOCK_COUNT_41];

#endif

#if     AO_ALLOC_POOL_42

        ao_alloc_pool_t                 ao_alloc_pool_42;

static  ao_alloc_pool_node_42_t         ao_alloc_pool_nodes_42[AO_ALLOC_POOL_BLOCK_COUNT_42];

#endif

#if     AO_ALLOC_POOL_43

        ao_alloc_pool_t                 ao_alloc_pool_43;

static  ao_alloc_pool_node_43_t         ao_alloc_pool_nodes_43[AO_ALLOC_POOL_BLOCK_COUNT_43];

#endif

#if     AO_ALLOC_POOL_44

        ao_alloc_pool_t                 ao_alloc_pool_44;

static  ao_alloc_pool_node_44_t         ao_alloc_pool_nodes_44[AO_ALLOC_POOL_BLOCK_COUNT_44];

#endif

#if     AO_ALLOC_POOL_45

        ao_alloc_pool_t                 ao_alloc_pool_45;

static  ao_alloc_pool_node_45_t         ao_alloc_pool_nodes_45[AO_ALLOC_POOL_BLOCK_COUNT_45];

#endif

#if     AO_ALLOC_POOL_46

        ao_alloc_pool_t                 ao_alloc_pool_46;

static  ao_alloc_pool_node_46_t         ao_alloc_pool_nodes_46[AO_ALLOC_POOL_BLOCK_COUNT_46];

#endif

#if     AO_ALLOC_POOL_47

        ao_alloc_pool_t                 ao_alloc_pool_47;

static  ao_alloc_pool_node_47_t         ao_alloc_pool_nodes_47[AO_ALLOC_POOL_BLOCK_COUNT_47];

#endif

#if     AO_ALLOC_POOL_48

        ao_alloc_pool_t                 ao_alloc_pool_48;

static  ao_alloc_pool_node_48_t         ao_alloc_pool_nodes_48[AO_ALLOC_POOL_BLOCK_COUNT_48];

#endif

#if     AO_ALLOC_POOL_49

        ao_alloc_pool_t                 ao_alloc_pool_49;

static  ao_alloc_pool_node_49_t         ao_alloc_pool_nodes_49[AO_ALLOC_POOL_BLOCK_COUNT_49];

#endif

#if     AO_ALLOC_POOL_50

        ao_alloc_pool_t                 ao_alloc_pool_50;

static  ao_alloc_pool_node_50_t         ao_alloc_pool_nodes_50[AO_ALLOC_POOL_BLOCK_COUNT_50];

#endif

#if     AO_ALLOC_POOL_51

        ao_alloc_pool_t                 ao_alloc_pool_51;

static  ao_alloc_pool_node_51_t         ao_alloc_pool_nodes_51[AO_ALLOC_POOL_BLOCK_COUNT_51];

#endif

#if     AO_ALLOC_POOL_52

        ao_alloc_pool_t                 ao_alloc_pool_52;

static  ao_alloc_pool_node_52_t         ao_alloc_pool_nodes_52[AO_ALLOC_POOL_BLOCK_COUNT_52];

#endif

#if     AO_ALLOC_POOL_53

        ao_alloc_pool_t                 ao_alloc_pool_53;

static  ao_alloc_pool_node_53_t         ao_alloc_pool_nodes_53[AO_ALLOC_POOL_BLOCK_COUNT_53];

#endif

#if     AO_ALLOC_POOL_54

        ao_alloc_pool_t                 ao_alloc_pool_54;

static  ao_alloc_pool_node_54_t         ao_alloc_pool_nodes_54[AO_ALLOC_POOL_BLOCK_COUNT_54];

#endif

#if     AO_ALLOC_POOL_55

        ao_alloc_pool_t                 ao_alloc_pool_55;

static  ao_alloc_pool_node_55_t         ao_alloc_pool_nodes_55[AO_ALLOC_POOL_BLOCK_COUNT_55];

#endif

#if     AO_ALLOC_POOL_56

        ao_alloc_pool_t                 ao_alloc_pool_56;

static  ao_alloc_pool_node_56_t         ao_alloc_pool_nodes_56[AO_ALLOC_POOL_BLOCK_COUNT_56];

#endif

#if     AO_ALLOC_POOL_57

        ao_alloc_pool_t                 ao_alloc_pool_57;

static  ao_alloc_pool_node_57_t         ao_alloc_pool_nodes_57[AO_ALLOC_POOL_BLOCK_COUNT_57];

#endif

#if     AO_ALLOC_POOL_58

        ao_alloc_pool_t                 ao_alloc_pool_58;

static  ao_alloc_pool_node_58_t         ao_alloc_pool_nodes_58[AO_ALLOC_POOL_BLOCK_COUNT_58];

#endif

#if     AO_ALLOC_POOL_59

        ao_alloc_pool_t                 ao_alloc_pool_59;

static  ao_alloc_pool_node_59_t         ao_alloc_pool_nodes_59[AO_ALLOC_POOL_BLOCK_COUNT_59];

#endif

#if     AO_ALLOC_POOL_60

        ao_alloc_pool_t                 ao_alloc_pool_60;

static  ao_alloc_pool_node_60_t         ao_alloc_pool_nodes_60[AO_ALLOC_POOL_BLOCK_COUNT_60];

#endif

#if     AO_ALLOC_POOL_61

        ao_alloc_pool_t                 ao_alloc_pool_61;

static  ao_alloc_pool_node_61_t         ao_alloc_pool_nodes_61[AO_ALLOC_POOL_BLOCK_COUNT_61];

#endif

#if     AO_ALLOC_POOL_62

        ao_alloc_pool_t                 ao_alloc_pool_62;

static  ao_alloc_pool_node_62_t         ao_alloc_pool_nodes_62[AO_ALLOC_POOL_BLOCK_COUNT_62];

#endif

#if     AO_ALLOC_POOL_63

        ao_alloc_pool_t                 ao_alloc_pool_63;

static  ao_alloc_pool_node_63_t         ao_alloc_pool_nodes_63[AO_ALLOC_POOL_BLOCK_COUNT_63];

#endif

// ----------------------------------------------------------------------------

static  ao_alloc_pool_t *               ao_alloc_pools[AO_SIZE_BITS];

// ----------------------------------------------------------------------------

void * ao_acquire_2(size_t s)
{
    // Variables.

    void * p;


    // Ready.

    p = ao_acquire_3(s);

#if AO_ACQUIRED

    ao_acquired_info.ptr = p;

    ao_acquired_info.result = p ? true : false;

    ao_acquired_info.size_body_requested = s;

    ao_acquired(&ao_acquired_info);

#endif

    return p;
}

void * ao_acquire_3(size_t s)
{
    // Variables.

    size_t B1;

    size_t B2;

    size_t i;

    size_t j;

    size_t m;

    ao_alloc_pool_node_t * N;

    void * p;

    ao_alloc_pool_t * P;

    size_t t1;

#if AO_ALLOC_ALLOCATED                                                  ||  \
    AO_ALLOC_ALLOCATED_MAX

    size_t t2;

    size_t t3;

#endif

#if AO_ALLOC_ALLOCATED_MAX

    size_t t4;

    size_t t5;

#endif

#if AO_ALLOC_FREE                                                       ||  \
    AO_ALLOC_FREE_MIN

    size_t t6;

    size_t t7;

#endif

#if AO_ALLOC_FREE_MIN

    size_t t8;

    size_t t9;

#endif


    // Ready.

    p = NULL;

    B1 = ao_alloc_bitmap;

    if (B1)
    {
        B2 = B1;

        do
        {
            j = ao_ffsz(B1);

            ao_assert(j >= 0);

            ao_assert(j <  AO_SIZE_BITS);

            i = j;

            P = ao_alloc_pools[i];

            ao_assert(P);

            ao_assert(P->front);

            t1 = P->block_size;

            ao_assert(t1 > 0);

            if (t1 >= s)
            {
                N = P->front;

                ao_assert(N);

                ao_assert(N->pool == j);

                ao_assert(N->ref == 0);

                N->ref = 1;

                p = N->block;

                N = N->next;

                if (!N)
                {
                    m = 1;

                    m = m << j;

                    m = ~m;

                    B2 = B2 & m;

                    ao_alloc_bitmap = B2;
                }

                P->front = N;

#if AO_ACQUIRED

                ao_acquired_info.pool = i;

                ao_acquired_info.size_body = t1;

#endif

#if AO_ALLOC_ALLOCATED                                                  ||  \
    AO_ALLOC_ALLOCATED_MAX

                t2 = P->allocated;

                t3 = ao_alloc_allocated;

                t2 = t2 + t1;

                t3 = t3 + t1;

                P->allocated = t2;

                ao_alloc_allocated = t3;

#endif

#if AO_ALLOC_ALLOCATED_MAX

                t4 = P->allocated_max;

                t5 = ao_alloc_allocated_max;

                t4 = ao_max(t2, t4);

                t5 = ao_max(t3, t5);

                P->allocated_max = t4;

                ao_alloc_allocated_max = t5;

#endif

#if AO_ALLOC_FREE                                                       ||  \
    AO_ALLOC_FREE_MIN

                t6 = P->free;

                t7 = ao_alloc_free;

                ao_assert(t1 <= t6);

                ao_assert(t1 <= t7);

                t6 = t6 - t1;

                t7 = t7 - t1;

                P->free = t6;

                ao_alloc_free = t7;

#endif

#if AO_ALLOC_FREE_MIN

                t8 = P->free_min;

                t9 = ao_alloc_free_min;

                t8 = ao_min(t6, t8);

                t9 = ao_min(t7, t9);

                P->free_min = t8;

                ao_alloc_free_min = t9;

#endif

                B1 = 0;
            }

            else
            {
                m = 1;

                m = m << j;

                m = ~m;

                B1 = B1 & m;
            }
        }
        while (B1);
    }

    return p;
}

// ----------------------------------------------------------------------------

void ao_boot_alloc()
{
    ao_assert(!ao_booted_alloc);

#if AO_ALLOC_POOL_0

    ao_boot_alloc_pool_0();

#endif

#if AO_ALLOC_POOL_1

    ao_boot_alloc_pool_1();

#endif

#if AO_ALLOC_POOL_2

    ao_boot_alloc_pool_2();

#endif

#if AO_ALLOC_POOL_3

    ao_boot_alloc_pool_3();

#endif

#if AO_ALLOC_POOL_4

    ao_boot_alloc_pool_4();

#endif

#if AO_ALLOC_POOL_5

    ao_boot_alloc_pool_5();

#endif

#if AO_ALLOC_POOL_6

    ao_boot_alloc_pool_6();

#endif

#if AO_ALLOC_POOL_7

    ao_boot_alloc_pool_7();

#endif

#if AO_ALLOC_POOL_8

    ao_boot_alloc_pool_8();

#endif

#if AO_ALLOC_POOL_9

    ao_boot_alloc_pool_9();

#endif

#if AO_ALLOC_POOL_10

    ao_boot_alloc_pool_10();

#endif

#if AO_ALLOC_POOL_11

    ao_boot_alloc_pool_11();

#endif

#if AO_ALLOC_POOL_12

    ao_boot_alloc_pool_12();

#endif

#if AO_ALLOC_POOL_13

    ao_boot_alloc_pool_13();

#endif

#if AO_ALLOC_POOL_14

    ao_boot_alloc_pool_14();

#endif

#if AO_ALLOC_POOL_15

    ao_boot_alloc_pool_15();

#endif

#if AO_ALLOC_POOL_16

    ao_boot_alloc_pool_16();

#endif

#if AO_ALLOC_POOL_17

    ao_boot_alloc_pool_17();

#endif

#if AO_ALLOC_POOL_18

    ao_boot_alloc_pool_18();

#endif

#if AO_ALLOC_POOL_19

    ao_boot_alloc_pool_19();

#endif

#if AO_ALLOC_POOL_20

    ao_boot_alloc_pool_20();

#endif

#if AO_ALLOC_POOL_21

    ao_boot_alloc_pool_21();

#endif

#if AO_ALLOC_POOL_22

    ao_boot_alloc_pool_22();

#endif

#if AO_ALLOC_POOL_23

    ao_boot_alloc_pool_23();

#endif

#if AO_ALLOC_POOL_24

    ao_boot_alloc_pool_24();

#endif

#if AO_ALLOC_POOL_25

    ao_boot_alloc_pool_25();

#endif

#if AO_ALLOC_POOL_26

    ao_boot_alloc_pool_26();

#endif

#if AO_ALLOC_POOL_27

    ao_boot_alloc_pool_27();

#endif

#if AO_ALLOC_POOL_28

    ao_boot_alloc_pool_28();

#endif

#if AO_ALLOC_POOL_29

    ao_boot_alloc_pool_29();

#endif

#if AO_ALLOC_POOL_30

    ao_boot_alloc_pool_30();

#endif

#if AO_ALLOC_POOL_31

    ao_boot_alloc_pool_31();

#endif

#if AO_ALLOC_POOL_32

    ao_boot_alloc_pool_32();

#endif

#if AO_ALLOC_POOL_33

    ao_boot_alloc_pool_33();

#endif

#if AO_ALLOC_POOL_34

    ao_boot_alloc_pool_34();

#endif

#if AO_ALLOC_POOL_35

    ao_boot_alloc_pool_35();

#endif

#if AO_ALLOC_POOL_36

    ao_boot_alloc_pool_36();

#endif

#if AO_ALLOC_POOL_37

    ao_boot_alloc_pool_37();

#endif

#if AO_ALLOC_POOL_38

    ao_boot_alloc_pool_38();

#endif

#if AO_ALLOC_POOL_39

    ao_boot_alloc_pool_39();

#endif

#if AO_ALLOC_POOL_40

    ao_boot_alloc_pool_40();

#endif

#if AO_ALLOC_POOL_41

    ao_boot_alloc_pool_41();

#endif

#if AO_ALLOC_POOL_42

    ao_boot_alloc_pool_42();

#endif

#if AO_ALLOC_POOL_43

    ao_boot_alloc_pool_43();

#endif

#if AO_ALLOC_POOL_44

    ao_boot_alloc_pool_44();

#endif

#if AO_ALLOC_POOL_45

    ao_boot_alloc_pool_45();

#endif

#if AO_ALLOC_POOL_46

    ao_boot_alloc_pool_46();

#endif

#if AO_ALLOC_POOL_47

    ao_boot_alloc_pool_47();

#endif

#if AO_ALLOC_POOL_48

    ao_boot_alloc_pool_48();

#endif

#if AO_ALLOC_POOL_49

    ao_boot_alloc_pool_49();

#endif

#if AO_ALLOC_POOL_50

    ao_boot_alloc_pool_50();

#endif

#if AO_ALLOC_POOL_51

    ao_boot_alloc_pool_51();

#endif

#if AO_ALLOC_POOL_52

    ao_boot_alloc_pool_52();

#endif

#if AO_ALLOC_POOL_53

    ao_boot_alloc_pool_53();

#endif

#if AO_ALLOC_POOL_54

    ao_boot_alloc_pool_54();

#endif

#if AO_ALLOC_POOL_55

    ao_boot_alloc_pool_55();

#endif

#if AO_ALLOC_POOL_56

    ao_boot_alloc_pool_56();

#endif

#if AO_ALLOC_POOL_57

    ao_boot_alloc_pool_57();

#endif

#if AO_ALLOC_POOL_58

    ao_boot_alloc_pool_58();

#endif

#if AO_ALLOC_POOL_59

    ao_boot_alloc_pool_59();

#endif

#if AO_ALLOC_POOL_60

    ao_boot_alloc_pool_60();

#endif

#if AO_ALLOC_POOL_61

    ao_boot_alloc_pool_61();

#endif

#if AO_ALLOC_POOL_62

    ao_boot_alloc_pool_62();

#endif

#if AO_ALLOC_POOL_63

    ao_boot_alloc_pool_63();

#endif

#if AO_ACQUIRED

    ao_acquired_info.size_head = offsetof(ao_alloc_pool_node_t, block);

#endif

#if AO_RELEASED

    ao_released_info.size_head = offsetof(ao_alloc_pool_node_t, block);

#endif

#if AO_RETAINED

    ao_retained_info.size_head = offsetof(ao_alloc_pool_node_t, block);

#endif

    ao_booted_alloc = true;
}

// ----------------------------------------------------------------------------

#if AO_ALLOC_POOL_0

void ao_boot_alloc_pool_0()
{
    // Variables.

    size_t const c = AO_ALLOC_POOL_BLOCK_COUNT_0;

    ao_alloc_pool_node_0_t * const nodes = ao_alloc_pool_nodes_0;

    size_t const p = 0;

    ao_alloc_pool_t * const pool = &ao_alloc_pool_0;

    size_t const s = AO_ALLOC_POOL_BLOCK_SIZE_0;


    // Variables.

    size_t const b = ((size_t) 1 << p);

#if AO_ALLOC_FREE_MIN                                                   ||  \
    AO_ALLOC_FREE

    size_t const f = c * s;

#endif

    size_t i;


    // Ready.

    ao_alloc_pools[p] = pool;

    ao_alloc_bitmap = ao_alloc_bitmap | b;

    pool->block_size = s;

#if AO_ALLOC_FREE

    pool->free = f;

    ao_alloc_free += f;

#endif

#if AO_ALLOC_FREE_MIN

    pool->free_min = f;

    ao_alloc_free_min += f;

#endif

    pool->front = (ao_alloc_pool_node_t *) nodes;

    for (i = 0; i < c - 1; i++)
    {
        nodes[i].pool = p;

        nodes[i].next = nodes + i + 1;
    }

    nodes[c - 1].pool = p;
}

#endif

#if AO_ALLOC_POOL_1

void ao_boot_alloc_pool_1()
{
    // Variables.

    size_t const c = AO_ALLOC_POOL_BLOCK_COUNT_1;

    ao_alloc_pool_node_1_t * const nodes = ao_alloc_pool_nodes_1;

    size_t const p = 1;

    ao_alloc_pool_t * const pool = &ao_alloc_pool_1;

    size_t const s = AO_ALLOC_POOL_BLOCK_SIZE_1;


    // Variables.

    size_t const b = ((size_t) 1 << p);

#if AO_ALLOC_FREE_MIN                                                   ||  \
    AO_ALLOC_FREE

    size_t const f = c * s;

#endif

    size_t i;


    // Ready.

    ao_alloc_pools[p] = pool;

    ao_alloc_bitmap = ao_alloc_bitmap | b;

    pool->block_size = s;

#if AO_ALLOC_FREE

    pool->free = f;

    ao_alloc_free += f;

#endif

#if AO_ALLOC_FREE_MIN

    pool->free_min = f;

    ao_alloc_free_min += f;

#endif

    pool->front = (ao_alloc_pool_node_t *) nodes;

    for (i = 0; i < c - 1; i++)
    {
        nodes[i].pool = p;

        nodes[i].next = nodes + i + 1;
    }

    nodes[c - 1].pool = p;
}

#endif

#if AO_ALLOC_POOL_2

void ao_boot_alloc_pool_2()
{
    // Variables.

    size_t const c = AO_ALLOC_POOL_BLOCK_COUNT_2;

    ao_alloc_pool_node_2_t * const nodes = ao_alloc_pool_nodes_2;

    size_t const p = 2;

    ao_alloc_pool_t * const pool = &ao_alloc_pool_2;

    size_t const s = AO_ALLOC_POOL_BLOCK_SIZE_2;


    // Variables.

    size_t const b = ((size_t) 1 << p);

#if AO_ALLOC_FREE_MIN                                                   ||  \
    AO_ALLOC_FREE

    size_t const f = c * s;

#endif

    size_t i;


    // Ready.

    ao_alloc_pools[p] = pool;

    ao_alloc_bitmap = ao_alloc_bitmap | b;

    pool->block_size = s;

#if AO_ALLOC_FREE

    pool->free = f;

    ao_alloc_free += f;

#endif

#if AO_ALLOC_FREE_MIN

    pool->free_min = f;

    ao_alloc_free_min += f;

#endif

    pool->front = (ao_alloc_pool_node_t *) nodes;

    for (i = 0; i < c - 1; i++)
    {
        nodes[i].pool = p;

        nodes[i].next = nodes + i + 1;
    }

    nodes[c - 1].pool = p;
}

#endif

#if AO_ALLOC_POOL_3

void ao_boot_alloc_pool_3()
{
    // Variables.

    size_t const c = AO_ALLOC_POOL_BLOCK_COUNT_3;

    ao_alloc_pool_node_3_t * const nodes = ao_alloc_pool_nodes_3;

    size_t const p = 3;

    ao_alloc_pool_t * const pool = &ao_alloc_pool_3;

    size_t const s = AO_ALLOC_POOL_BLOCK_SIZE_3;


    // Variables.

    size_t const b = ((size_t) 1 << p);

#if AO_ALLOC_FREE_MIN                                                   ||  \
    AO_ALLOC_FREE

    size_t const f = c * s;

#endif

    size_t i;


    // Ready.

    ao_alloc_pools[p] = pool;

    ao_alloc_bitmap = ao_alloc_bitmap | b;

    pool->block_size = s;

#if AO_ALLOC_FREE

    pool->free = f;

    ao_alloc_free += f;

#endif

#if AO_ALLOC_FREE_MIN

    pool->free_min = f;

    ao_alloc_free_min += f;

#endif

    pool->front = (ao_alloc_pool_node_t *) nodes;

    for (i = 0; i < c - 1; i++)
    {
        nodes[i].pool = p;

        nodes[i].next = nodes + i + 1;
    }

    nodes[c - 1].pool = p;
}

#endif

#if AO_ALLOC_POOL_4

void ao_boot_alloc_pool_4()
{
    // Variables.

    size_t const c = AO_ALLOC_POOL_BLOCK_COUNT_4;

    ao_alloc_pool_node_4_t * const nodes = ao_alloc_pool_nodes_4;

    size_t const p = 4;

    ao_alloc_pool_t * const pool = &ao_alloc_pool_4;

    size_t const s = AO_ALLOC_POOL_BLOCK_SIZE_4;


    // Variables.

    size_t const b = ((size_t) 1 << p);

#if AO_ALLOC_FREE_MIN                                                   ||  \
    AO_ALLOC_FREE

    size_t const f = c * s;

#endif

    size_t i;


    // Ready.

    ao_alloc_pools[p] = pool;

    ao_alloc_bitmap = ao_alloc_bitmap | b;

    pool->block_size = s;

#if AO_ALLOC_FREE

    pool->free = f;

    ao_alloc_free += f;

#endif

#if AO_ALLOC_FREE_MIN

    pool->free_min = f;

    ao_alloc_free_min += f;

#endif

    pool->front = (ao_alloc_pool_node_t *) nodes;

    for (i = 0; i < c - 1; i++)
    {
        nodes[i].pool = p;

        nodes[i].next = nodes + i + 1;
    }

    nodes[c - 1].pool = p;
}

#endif

#if AO_ALLOC_POOL_5

void ao_boot_alloc_pool_5()
{
    // Variables.

    size_t const c = AO_ALLOC_POOL_BLOCK_COUNT_5;

    ao_alloc_pool_node_5_t * const nodes = ao_alloc_pool_nodes_5;

    size_t const p = 5;

    ao_alloc_pool_t * const pool = &ao_alloc_pool_5;

    size_t const s = AO_ALLOC_POOL_BLOCK_SIZE_5;


    // Variables.

    size_t const b = ((size_t) 1 << p);

#if AO_ALLOC_FREE_MIN                                                   ||  \
    AO_ALLOC_FREE

    size_t const f = c * s;

#endif

    size_t i;


    // Ready.

    ao_alloc_pools[p] = pool;

    ao_alloc_bitmap = ao_alloc_bitmap | b;

    pool->block_size = s;

#if AO_ALLOC_FREE

    pool->free = f;

    ao_alloc_free += f;

#endif

#if AO_ALLOC_FREE_MIN

    pool->free_min = f;

    ao_alloc_free_min += f;

#endif

    pool->front = (ao_alloc_pool_node_t *) nodes;

    for (i = 0; i < c - 1; i++)
    {
        nodes[i].pool = p;

        nodes[i].next = nodes + i + 1;
    }

    nodes[c - 1].pool = p;
}

#endif

#if AO_ALLOC_POOL_6

void ao_boot_alloc_pool_6()
{
    // Variables.

    size_t const c = AO_ALLOC_POOL_BLOCK_COUNT_6;

    ao_alloc_pool_node_6_t * const nodes = ao_alloc_pool_nodes_6;

    size_t const p = 6;

    ao_alloc_pool_t * const pool = &ao_alloc_pool_6;

    size_t const s = AO_ALLOC_POOL_BLOCK_SIZE_6;


    // Variables.

    size_t const b = ((size_t) 1 << p);

#if AO_ALLOC_FREE_MIN                                                   ||  \
    AO_ALLOC_FREE

    size_t const f = c * s;

#endif

    size_t i;


    // Ready.

    ao_alloc_pools[p] = pool;

    ao_alloc_bitmap = ao_alloc_bitmap | b;

    pool->block_size = s;

#if AO_ALLOC_FREE

    pool->free = f;

    ao_alloc_free += f;

#endif

#if AO_ALLOC_FREE_MIN

    pool->free_min = f;

    ao_alloc_free_min += f;

#endif

    pool->front = (ao_alloc_pool_node_t *) nodes;

    for (i = 0; i < c - 1; i++)
    {
        nodes[i].pool = p;

        nodes[i].next = nodes + i + 1;
    }

    nodes[c - 1].pool = p;
}

#endif

#if AO_ALLOC_POOL_7

void ao_boot_alloc_pool_7()
{
    // Variables.

    size_t const c = AO_ALLOC_POOL_BLOCK_COUNT_7;

    ao_alloc_pool_node_7_t * const nodes = ao_alloc_pool_nodes_7;

    size_t const p = 7;

    ao_alloc_pool_t * const pool = &ao_alloc_pool_7;

    size_t const s = AO_ALLOC_POOL_BLOCK_SIZE_7;


    // Variables.

    size_t const b = ((size_t) 1 << p);

#if AO_ALLOC_FREE_MIN                                                   ||  \
    AO_ALLOC_FREE

    size_t const f = c * s;

#endif

    size_t i;


    // Ready.

    ao_alloc_pools[p] = pool;

    ao_alloc_bitmap = ao_alloc_bitmap | b;

    pool->block_size = s;

#if AO_ALLOC_FREE

    pool->free = f;

    ao_alloc_free += f;

#endif

#if AO_ALLOC_FREE_MIN

    pool->free_min = f;

    ao_alloc_free_min += f;

#endif

    pool->front = (ao_alloc_pool_node_t *) nodes;

    for (i = 0; i < c - 1; i++)
    {
        nodes[i].pool = p;

        nodes[i].next = nodes + i + 1;
    }

    nodes[c - 1].pool = p;
}

#endif

#if AO_ALLOC_POOL_8

void ao_boot_alloc_pool_8()
{
    // Variables.

    size_t const c = AO_ALLOC_POOL_BLOCK_COUNT_8;

    ao_alloc_pool_node_8_t * const nodes = ao_alloc_pool_nodes_8;

    size_t const p = 8;

    ao_alloc_pool_t * const pool = &ao_alloc_pool_8;

    size_t const s = AO_ALLOC_POOL_BLOCK_SIZE_8;


    // Variables.

    size_t const b = ((size_t) 1 << p);

#if AO_ALLOC_FREE_MIN                                                   ||  \
    AO_ALLOC_FREE

    size_t const f = c * s;

#endif

    size_t i;


    // Ready.

    ao_alloc_pools[p] = pool;

    ao_alloc_bitmap = ao_alloc_bitmap | b;

    pool->block_size = s;

#if AO_ALLOC_FREE

    pool->free = f;

    ao_alloc_free += f;

#endif

#if AO_ALLOC_FREE_MIN

    pool->free_min = f;

    ao_alloc_free_min += f;

#endif

    pool->front = (ao_alloc_pool_node_t *) nodes;

    for (i = 0; i < c - 1; i++)
    {
        nodes[i].pool = p;

        nodes[i].next = nodes + i + 1;
    }

    nodes[c - 1].pool = p;
}

#endif

#if AO_ALLOC_POOL_9

void ao_boot_alloc_pool_9()
{
    // Variables.

    size_t const c = AO_ALLOC_POOL_BLOCK_COUNT_9;

    ao_alloc_pool_node_9_t * const nodes = ao_alloc_pool_nodes_9;

    size_t const p = 9;

    ao_alloc_pool_t * const pool = &ao_alloc_pool_9;

    size_t const s = AO_ALLOC_POOL_BLOCK_SIZE_9;


    // Variables.

    size_t const b = ((size_t) 1 << p);

#if AO_ALLOC_FREE_MIN                                                   ||  \
    AO_ALLOC_FREE

    size_t const f = c * s;

#endif

    size_t i;


    // Ready.

    ao_alloc_pools[p] = pool;

    ao_alloc_bitmap = ao_alloc_bitmap | b;

    pool->block_size = s;

#if AO_ALLOC_FREE

    pool->free = f;

    ao_alloc_free += f;

#endif

#if AO_ALLOC_FREE_MIN

    pool->free_min = f;

    ao_alloc_free_min += f;

#endif

    pool->front = (ao_alloc_pool_node_t *) nodes;

    for (i = 0; i < c - 1; i++)
    {
        nodes[i].pool = p;

        nodes[i].next = nodes + i + 1;
    }

    nodes[c - 1].pool = p;
}

#endif

#if AO_ALLOC_POOL_10

void ao_boot_alloc_pool_10()
{
    // Variables.

    size_t const c = AO_ALLOC_POOL_BLOCK_COUNT_10;

    ao_alloc_pool_node_10_t * const nodes = ao_alloc_pool_nodes_10;

    size_t const p = 10;

    ao_alloc_pool_t * const pool = &ao_alloc_pool_10;

    size_t const s = AO_ALLOC_POOL_BLOCK_SIZE_10;


    // Variables.

    size_t const b = ((size_t) 1 << p);

#if AO_ALLOC_FREE_MIN                                                   ||  \
    AO_ALLOC_FREE

    size_t const f = c * s;

#endif

    size_t i;


    // Ready.

    ao_alloc_pools[p] = pool;

    ao_alloc_bitmap = ao_alloc_bitmap | b;

    pool->block_size = s;

#if AO_ALLOC_FREE

    pool->free = f;

    ao_alloc_free += f;

#endif

#if AO_ALLOC_FREE_MIN

    pool->free_min = f;

    ao_alloc_free_min += f;

#endif

    pool->front = (ao_alloc_pool_node_t *) nodes;

    for (i = 0; i < c - 1; i++)
    {
        nodes[i].pool = p;

        nodes[i].next = nodes + i + 1;
    }

    nodes[c - 1].pool = p;
}

#endif

#if AO_ALLOC_POOL_11

void ao_boot_alloc_pool_11()
{
    // Variables.

    size_t const c = AO_ALLOC_POOL_BLOCK_COUNT_11;

    ao_alloc_pool_node_11_t * const nodes = ao_alloc_pool_nodes_11;

    size_t const p = 11;

    ao_alloc_pool_t * const pool = &ao_alloc_pool_11;

    size_t const s = AO_ALLOC_POOL_BLOCK_SIZE_11;


    // Variables.

    size_t const b = ((size_t) 1 << p);

#if AO_ALLOC_FREE_MIN                                                   ||  \
    AO_ALLOC_FREE

    size_t const f = c * s;

#endif

    size_t i;


    // Ready.

    ao_alloc_pools[p] = pool;

    ao_alloc_bitmap = ao_alloc_bitmap | b;

    pool->block_size = s;

#if AO_ALLOC_FREE

    pool->free = f;

    ao_alloc_free += f;

#endif

#if AO_ALLOC_FREE_MIN

    pool->free_min = f;

    ao_alloc_free_min += f;

#endif

    pool->front = (ao_alloc_pool_node_t *) nodes;

    for (i = 0; i < c - 1; i++)
    {
        nodes[i].pool = p;

        nodes[i].next = nodes + i + 1;
    }

    nodes[c - 1].pool = p;
}

#endif

#if AO_ALLOC_POOL_12

void ao_boot_alloc_pool_12()
{
    // Variables.

    size_t const c = AO_ALLOC_POOL_BLOCK_COUNT_12;

    ao_alloc_pool_node_12_t * const nodes = ao_alloc_pool_nodes_12;

    size_t const p = 12;

    ao_alloc_pool_t * const pool = &ao_alloc_pool_12;

    size_t const s = AO_ALLOC_POOL_BLOCK_SIZE_12;


    // Variables.

    size_t const b = ((size_t) 1 << p);

#if AO_ALLOC_FREE_MIN                                                   ||  \
    AO_ALLOC_FREE

    size_t const f = c * s;

#endif

    size_t i;


    // Ready.

    ao_alloc_pools[p] = pool;

    ao_alloc_bitmap = ao_alloc_bitmap | b;

    pool->block_size = s;

#if AO_ALLOC_FREE

    pool->free = f;

    ao_alloc_free += f;

#endif

#if AO_ALLOC_FREE_MIN

    pool->free_min = f;

    ao_alloc_free_min += f;

#endif

    pool->front = (ao_alloc_pool_node_t *) nodes;

    for (i = 0; i < c - 1; i++)
    {
        nodes[i].pool = p;

        nodes[i].next = nodes + i + 1;
    }

    nodes[c - 1].pool = p;
}

#endif

#if AO_ALLOC_POOL_13

void ao_boot_alloc_pool_13()
{
    // Variables.

    size_t const c = AO_ALLOC_POOL_BLOCK_COUNT_13;

    ao_alloc_pool_node_13_t * const nodes = ao_alloc_pool_nodes_13;

    size_t const p = 13;

    ao_alloc_pool_t * const pool = &ao_alloc_pool_13;

    size_t const s = AO_ALLOC_POOL_BLOCK_SIZE_13;


    // Variables.

    size_t const b = ((size_t) 1 << p);

#if AO_ALLOC_FREE_MIN                                                   ||  \
    AO_ALLOC_FREE

    size_t const f = c * s;

#endif

    size_t i;


    // Ready.

    ao_alloc_pools[p] = pool;

    ao_alloc_bitmap = ao_alloc_bitmap | b;

    pool->block_size = s;

#if AO_ALLOC_FREE

    pool->free = f;

    ao_alloc_free += f;

#endif

#if AO_ALLOC_FREE_MIN

    pool->free_min = f;

    ao_alloc_free_min += f;

#endif

    pool->front = (ao_alloc_pool_node_t *) nodes;

    for (i = 0; i < c - 1; i++)
    {
        nodes[i].pool = p;

        nodes[i].next = nodes + i + 1;
    }

    nodes[c - 1].pool = p;
}

#endif

#if AO_ALLOC_POOL_14

void ao_boot_alloc_pool_14()
{
    // Variables.

    size_t const c = AO_ALLOC_POOL_BLOCK_COUNT_14;

    ao_alloc_pool_node_14_t * const nodes = ao_alloc_pool_nodes_14;

    size_t const p = 14;

    ao_alloc_pool_t * const pool = &ao_alloc_pool_14;

    size_t const s = AO_ALLOC_POOL_BLOCK_SIZE_14;


    // Variables.

    size_t const b = ((size_t) 1 << p);

#if AO_ALLOC_FREE_MIN                                                   ||  \
    AO_ALLOC_FREE

    size_t const f = c * s;

#endif

    size_t i;


    // Ready.

    ao_alloc_pools[p] = pool;

    ao_alloc_bitmap = ao_alloc_bitmap | b;

    pool->block_size = s;

#if AO_ALLOC_FREE

    pool->free = f;

    ao_alloc_free += f;

#endif

#if AO_ALLOC_FREE_MIN

    pool->free_min = f;

    ao_alloc_free_min += f;

#endif

    pool->front = (ao_alloc_pool_node_t *) nodes;

    for (i = 0; i < c - 1; i++)
    {
        nodes[i].pool = p;

        nodes[i].next = nodes + i + 1;
    }

    nodes[c - 1].pool = p;
}

#endif

#if AO_ALLOC_POOL_15

void ao_boot_alloc_pool_15()
{
    // Variables.

    size_t const c = AO_ALLOC_POOL_BLOCK_COUNT_15;

    ao_alloc_pool_node_15_t * const nodes = ao_alloc_pool_nodes_15;

    size_t const p = 15;

    ao_alloc_pool_t * const pool = &ao_alloc_pool_15;

    size_t const s = AO_ALLOC_POOL_BLOCK_SIZE_15;


    // Variables.

    size_t const b = ((size_t) 1 << p);

#if AO_ALLOC_FREE_MIN                                                   ||  \
    AO_ALLOC_FREE

    size_t const f = c * s;

#endif

    size_t i;


    // Ready.

    ao_alloc_pools[p] = pool;

    ao_alloc_bitmap = ao_alloc_bitmap | b;

    pool->block_size = s;

#if AO_ALLOC_FREE

    pool->free = f;

    ao_alloc_free += f;

#endif

#if AO_ALLOC_FREE_MIN

    pool->free_min = f;

    ao_alloc_free_min += f;

#endif

    pool->front = (ao_alloc_pool_node_t *) nodes;

    for (i = 0; i < c - 1; i++)
    {
        nodes[i].pool = p;

        nodes[i].next = nodes + i + 1;
    }

    nodes[c - 1].pool = p;
}

#endif

#if AO_ALLOC_POOL_16

void ao_boot_alloc_pool_16()
{
    // Variables.

    size_t const c = AO_ALLOC_POOL_BLOCK_COUNT_16;

    ao_alloc_pool_node_16_t * const nodes = ao_alloc_pool_nodes_16;

    size_t const p = 16;

    ao_alloc_pool_t * const pool = &ao_alloc_pool_16;

    size_t const s = AO_ALLOC_POOL_BLOCK_SIZE_16;


    // Variables.

    size_t const b = ((size_t) 1 << p);

#if AO_ALLOC_FREE_MIN                                                   ||  \
    AO_ALLOC_FREE

    size_t const f = c * s;

#endif

    size_t i;


    // Ready.

    ao_alloc_pools[p] = pool;

    ao_alloc_bitmap = ao_alloc_bitmap | b;

    pool->block_size = s;

#if AO_ALLOC_FREE

    pool->free = f;

    ao_alloc_free += f;

#endif

#if AO_ALLOC_FREE_MIN

    pool->free_min = f;

    ao_alloc_free_min += f;

#endif

    pool->front = (ao_alloc_pool_node_t *) nodes;

    for (i = 0; i < c - 1; i++)
    {
        nodes[i].pool = p;

        nodes[i].next = nodes + i + 1;
    }

    nodes[c - 1].pool = p;
}

#endif

#if AO_ALLOC_POOL_17

void ao_boot_alloc_pool_17()
{
    // Variables.

    size_t const c = AO_ALLOC_POOL_BLOCK_COUNT_17;

    ao_alloc_pool_node_17_t * const nodes = ao_alloc_pool_nodes_17;

    size_t const p = 17;

    ao_alloc_pool_t * const pool = &ao_alloc_pool_17;

    size_t const s = AO_ALLOC_POOL_BLOCK_SIZE_17;


    // Variables.

    size_t const b = ((size_t) 1 << p);

#if AO_ALLOC_FREE_MIN                                                   ||  \
    AO_ALLOC_FREE

    size_t const f = c * s;

#endif

    size_t i;


    // Ready.

    ao_alloc_pools[p] = pool;

    ao_alloc_bitmap = ao_alloc_bitmap | b;

    pool->block_size = s;

#if AO_ALLOC_FREE

    pool->free = f;

    ao_alloc_free += f;

#endif

#if AO_ALLOC_FREE_MIN

    pool->free_min = f;

    ao_alloc_free_min += f;

#endif

    pool->front = (ao_alloc_pool_node_t *) nodes;

    for (i = 0; i < c - 1; i++)
    {
        nodes[i].pool = p;

        nodes[i].next = nodes + i + 1;
    }

    nodes[c - 1].pool = p;
}

#endif

#if AO_ALLOC_POOL_18

void ao_boot_alloc_pool_18()
{
    // Variables.

    size_t const c = AO_ALLOC_POOL_BLOCK_COUNT_18;

    ao_alloc_pool_node_18_t * const nodes = ao_alloc_pool_nodes_18;

    size_t const p = 18;

    ao_alloc_pool_t * const pool = &ao_alloc_pool_18;

    size_t const s = AO_ALLOC_POOL_BLOCK_SIZE_18;


    // Variables.

    size_t const b = ((size_t) 1 << p);

#if AO_ALLOC_FREE_MIN                                                   ||  \
    AO_ALLOC_FREE

    size_t const f = c * s;

#endif

    size_t i;


    // Ready.

    ao_alloc_pools[p] = pool;

    ao_alloc_bitmap = ao_alloc_bitmap | b;

    pool->block_size = s;

#if AO_ALLOC_FREE

    pool->free = f;

    ao_alloc_free += f;

#endif

#if AO_ALLOC_FREE_MIN

    pool->free_min = f;

    ao_alloc_free_min += f;

#endif

    pool->front = (ao_alloc_pool_node_t *) nodes;

    for (i = 0; i < c - 1; i++)
    {
        nodes[i].pool = p;

        nodes[i].next = nodes + i + 1;
    }

    nodes[c - 1].pool = p;
}

#endif

#if AO_ALLOC_POOL_19

void ao_boot_alloc_pool_19()
{
    // Variables.

    size_t const c = AO_ALLOC_POOL_BLOCK_COUNT_19;

    ao_alloc_pool_node_19_t * const nodes = ao_alloc_pool_nodes_19;

    size_t const p = 19;

    ao_alloc_pool_t * const pool = &ao_alloc_pool_19;

    size_t const s = AO_ALLOC_POOL_BLOCK_SIZE_19;


    // Variables.

    size_t const b = ((size_t) 1 << p);

#if AO_ALLOC_FREE_MIN                                                   ||  \
    AO_ALLOC_FREE

    size_t const f = c * s;

#endif

    size_t i;


    // Ready.

    ao_alloc_pools[p] = pool;

    ao_alloc_bitmap = ao_alloc_bitmap | b;

    pool->block_size = s;

#if AO_ALLOC_FREE

    pool->free = f;

    ao_alloc_free += f;

#endif

#if AO_ALLOC_FREE_MIN

    pool->free_min = f;

    ao_alloc_free_min += f;

#endif

    pool->front = (ao_alloc_pool_node_t *) nodes;

    for (i = 0; i < c - 1; i++)
    {
        nodes[i].pool = p;

        nodes[i].next = nodes + i + 1;
    }

    nodes[c - 1].pool = p;
}

#endif

#if AO_ALLOC_POOL_20

void ao_boot_alloc_pool_20()
{
    // Variables.

    size_t const c = AO_ALLOC_POOL_BLOCK_COUNT_20;

    ao_alloc_pool_node_20_t * const nodes = ao_alloc_pool_nodes_20;

    size_t const p = 20;

    ao_alloc_pool_t * const pool = &ao_alloc_pool_20;

    size_t const s = AO_ALLOC_POOL_BLOCK_SIZE_20;


    // Variables.

    size_t const b = ((size_t) 1 << p);

#if AO_ALLOC_FREE_MIN                                                   ||  \
    AO_ALLOC_FREE

    size_t const f = c * s;

#endif

    size_t i;


    // Ready.

    ao_alloc_pools[p] = pool;

    ao_alloc_bitmap = ao_alloc_bitmap | b;

    pool->block_size = s;

#if AO_ALLOC_FREE

    pool->free = f;

    ao_alloc_free += f;

#endif

#if AO_ALLOC_FREE_MIN

    pool->free_min = f;

    ao_alloc_free_min += f;

#endif

    pool->front = (ao_alloc_pool_node_t *) nodes;

    for (i = 0; i < c - 1; i++)
    {
        nodes[i].pool = p;

        nodes[i].next = nodes + i + 1;
    }

    nodes[c - 1].pool = p;
}

#endif

#if AO_ALLOC_POOL_21

void ao_boot_alloc_pool_21()
{
    // Variables.

    size_t const c = AO_ALLOC_POOL_BLOCK_COUNT_21;

    ao_alloc_pool_node_21_t * const nodes = ao_alloc_pool_nodes_21;

    size_t const p = 21;

    ao_alloc_pool_t * const pool = &ao_alloc_pool_21;

    size_t const s = AO_ALLOC_POOL_BLOCK_SIZE_21;


    // Variables.

    size_t const b = ((size_t) 1 << p);

#if AO_ALLOC_FREE_MIN                                                   ||  \
    AO_ALLOC_FREE

    size_t const f = c * s;

#endif

    size_t i;


    // Ready.

    ao_alloc_pools[p] = pool;

    ao_alloc_bitmap = ao_alloc_bitmap | b;

    pool->block_size = s;

#if AO_ALLOC_FREE

    pool->free = f;

    ao_alloc_free += f;

#endif

#if AO_ALLOC_FREE_MIN

    pool->free_min = f;

    ao_alloc_free_min += f;

#endif

    pool->front = (ao_alloc_pool_node_t *) nodes;

    for (i = 0; i < c - 1; i++)
    {
        nodes[i].pool = p;

        nodes[i].next = nodes + i + 1;
    }

    nodes[c - 1].pool = p;
}

#endif

#if AO_ALLOC_POOL_22

void ao_boot_alloc_pool_22()
{
    // Variables.

    size_t const c = AO_ALLOC_POOL_BLOCK_COUNT_22;

    ao_alloc_pool_node_22_t * const nodes = ao_alloc_pool_nodes_22;

    size_t const p = 22;

    ao_alloc_pool_t * const pool = &ao_alloc_pool_22;

    size_t const s = AO_ALLOC_POOL_BLOCK_SIZE_22;


    // Variables.

    size_t const b = ((size_t) 1 << p);

#if AO_ALLOC_FREE_MIN                                                   ||  \
    AO_ALLOC_FREE

    size_t const f = c * s;

#endif

    size_t i;


    // Ready.

    ao_alloc_pools[p] = pool;

    ao_alloc_bitmap = ao_alloc_bitmap | b;

    pool->block_size = s;

#if AO_ALLOC_FREE

    pool->free = f;

    ao_alloc_free += f;

#endif

#if AO_ALLOC_FREE_MIN

    pool->free_min = f;

    ao_alloc_free_min += f;

#endif

    pool->front = (ao_alloc_pool_node_t *) nodes;

    for (i = 0; i < c - 1; i++)
    {
        nodes[i].pool = p;

        nodes[i].next = nodes + i + 1;
    }

    nodes[c - 1].pool = p;
}

#endif

#if AO_ALLOC_POOL_23

void ao_boot_alloc_pool_23()
{
    // Variables.

    size_t const c = AO_ALLOC_POOL_BLOCK_COUNT_23;

    ao_alloc_pool_node_23_t * const nodes = ao_alloc_pool_nodes_23;

    size_t const p = 23;

    ao_alloc_pool_t * const pool = &ao_alloc_pool_23;

    size_t const s = AO_ALLOC_POOL_BLOCK_SIZE_23;


    // Variables.

    size_t const b = ((size_t) 1 << p);

#if AO_ALLOC_FREE_MIN                                                   ||  \
    AO_ALLOC_FREE

    size_t const f = c * s;

#endif

    size_t i;


    // Ready.

    ao_alloc_pools[p] = pool;

    ao_alloc_bitmap = ao_alloc_bitmap | b;

    pool->block_size = s;

#if AO_ALLOC_FREE

    pool->free = f;

    ao_alloc_free += f;

#endif

#if AO_ALLOC_FREE_MIN

    pool->free_min = f;

    ao_alloc_free_min += f;

#endif

    pool->front = (ao_alloc_pool_node_t *) nodes;

    for (i = 0; i < c - 1; i++)
    {
        nodes[i].pool = p;

        nodes[i].next = nodes + i + 1;
    }

    nodes[c - 1].pool = p;
}

#endif

#if AO_ALLOC_POOL_24

void ao_boot_alloc_pool_24()
{
    // Variables.

    size_t const c = AO_ALLOC_POOL_BLOCK_COUNT_24;

    ao_alloc_pool_node_24_t * const nodes = ao_alloc_pool_nodes_24;

    size_t const p = 24;

    ao_alloc_pool_t * const pool = &ao_alloc_pool_24;

    size_t const s = AO_ALLOC_POOL_BLOCK_SIZE_24;


    // Variables.

    size_t const b = ((size_t) 1 << p);

#if AO_ALLOC_FREE_MIN                                                   ||  \
    AO_ALLOC_FREE

    size_t const f = c * s;

#endif

    size_t i;


    // Ready.

    ao_alloc_pools[p] = pool;

    ao_alloc_bitmap = ao_alloc_bitmap | b;

    pool->block_size = s;

#if AO_ALLOC_FREE

    pool->free = f;

    ao_alloc_free += f;

#endif

#if AO_ALLOC_FREE_MIN

    pool->free_min = f;

    ao_alloc_free_min += f;

#endif

    pool->front = (ao_alloc_pool_node_t *) nodes;

    for (i = 0; i < c - 1; i++)
    {
        nodes[i].pool = p;

        nodes[i].next = nodes + i + 1;
    }

    nodes[c - 1].pool = p;
}

#endif

#if AO_ALLOC_POOL_25

void ao_boot_alloc_pool_25()
{
    // Variables.

    size_t const c = AO_ALLOC_POOL_BLOCK_COUNT_25;

    ao_alloc_pool_node_25_t * const nodes = ao_alloc_pool_nodes_25;

    size_t const p = 25;

    ao_alloc_pool_t * const pool = &ao_alloc_pool_25;

    size_t const s = AO_ALLOC_POOL_BLOCK_SIZE_25;


    // Variables.

    size_t const b = ((size_t) 1 << p);

#if AO_ALLOC_FREE_MIN                                                   ||  \
    AO_ALLOC_FREE

    size_t const f = c * s;

#endif

    size_t i;


    // Ready.

    ao_alloc_pools[p] = pool;

    ao_alloc_bitmap = ao_alloc_bitmap | b;

    pool->block_size = s;

#if AO_ALLOC_FREE

    pool->free = f;

    ao_alloc_free += f;

#endif

#if AO_ALLOC_FREE_MIN

    pool->free_min = f;

    ao_alloc_free_min += f;

#endif

    pool->front = (ao_alloc_pool_node_t *) nodes;

    for (i = 0; i < c - 1; i++)
    {
        nodes[i].pool = p;

        nodes[i].next = nodes + i + 1;
    }

    nodes[c - 1].pool = p;
}

#endif

#if AO_ALLOC_POOL_26

void ao_boot_alloc_pool_26()
{
    // Variables.

    size_t const c = AO_ALLOC_POOL_BLOCK_COUNT_26;

    ao_alloc_pool_node_26_t * const nodes = ao_alloc_pool_nodes_26;

    size_t const p = 26;

    ao_alloc_pool_t * const pool = &ao_alloc_pool_26;

    size_t const s = AO_ALLOC_POOL_BLOCK_SIZE_26;


    // Variables.

    size_t const b = ((size_t) 1 << p);

#if AO_ALLOC_FREE_MIN                                                   ||  \
    AO_ALLOC_FREE

    size_t const f = c * s;

#endif

    size_t i;


    // Ready.

    ao_alloc_pools[p] = pool;

    ao_alloc_bitmap = ao_alloc_bitmap | b;

    pool->block_size = s;

#if AO_ALLOC_FREE

    pool->free = f;

    ao_alloc_free += f;

#endif

#if AO_ALLOC_FREE_MIN

    pool->free_min = f;

    ao_alloc_free_min += f;

#endif

    pool->front = (ao_alloc_pool_node_t *) nodes;

    for (i = 0; i < c - 1; i++)
    {
        nodes[i].pool = p;

        nodes[i].next = nodes + i + 1;
    }

    nodes[c - 1].pool = p;
}

#endif

#if AO_ALLOC_POOL_27

void ao_boot_alloc_pool_27()
{
    // Variables.

    size_t const c = AO_ALLOC_POOL_BLOCK_COUNT_27;

    ao_alloc_pool_node_27_t * const nodes = ao_alloc_pool_nodes_27;

    size_t const p = 27;

    ao_alloc_pool_t * const pool = &ao_alloc_pool_27;

    size_t const s = AO_ALLOC_POOL_BLOCK_SIZE_27;


    // Variables.

    size_t const b = ((size_t) 1 << p);

#if AO_ALLOC_FREE_MIN                                                   ||  \
    AO_ALLOC_FREE

    size_t const f = c * s;

#endif

    size_t i;


    // Ready.

    ao_alloc_pools[p] = pool;

    ao_alloc_bitmap = ao_alloc_bitmap | b;

    pool->block_size = s;

#if AO_ALLOC_FREE

    pool->free = f;

    ao_alloc_free += f;

#endif

#if AO_ALLOC_FREE_MIN

    pool->free_min = f;

    ao_alloc_free_min += f;

#endif

    pool->front = (ao_alloc_pool_node_t *) nodes;

    for (i = 0; i < c - 1; i++)
    {
        nodes[i].pool = p;

        nodes[i].next = nodes + i + 1;
    }

    nodes[c - 1].pool = p;
}

#endif

#if AO_ALLOC_POOL_28

void ao_boot_alloc_pool_28()
{
    // Variables.

    size_t const c = AO_ALLOC_POOL_BLOCK_COUNT_28;

    ao_alloc_pool_node_28_t * const nodes = ao_alloc_pool_nodes_28;

    size_t const p = 28;

    ao_alloc_pool_t * const pool = &ao_alloc_pool_28;

    size_t const s = AO_ALLOC_POOL_BLOCK_SIZE_28;


    // Variables.

    size_t const b = ((size_t) 1 << p);

#if AO_ALLOC_FREE_MIN                                                   ||  \
    AO_ALLOC_FREE

    size_t const f = c * s;

#endif

    size_t i;


    // Ready.

    ao_alloc_pools[p] = pool;

    ao_alloc_bitmap = ao_alloc_bitmap | b;

    pool->block_size = s;

#if AO_ALLOC_FREE

    pool->free = f;

    ao_alloc_free += f;

#endif

#if AO_ALLOC_FREE_MIN

    pool->free_min = f;

    ao_alloc_free_min += f;

#endif

    pool->front = (ao_alloc_pool_node_t *) nodes;

    for (i = 0; i < c - 1; i++)
    {
        nodes[i].pool = p;

        nodes[i].next = nodes + i + 1;
    }

    nodes[c - 1].pool = p;
}

#endif

#if AO_ALLOC_POOL_29

void ao_boot_alloc_pool_29()
{
    // Variables.

    size_t const c = AO_ALLOC_POOL_BLOCK_COUNT_29;

    ao_alloc_pool_node_29_t * const nodes = ao_alloc_pool_nodes_29;

    size_t const p = 29;

    ao_alloc_pool_t * const pool = &ao_alloc_pool_29;

    size_t const s = AO_ALLOC_POOL_BLOCK_SIZE_29;


    // Variables.

    size_t const b = ((size_t) 1 << p);

#if AO_ALLOC_FREE_MIN                                                   ||  \
    AO_ALLOC_FREE

    size_t const f = c * s;

#endif

    size_t i;


    // Ready.

    ao_alloc_pools[p] = pool;

    ao_alloc_bitmap = ao_alloc_bitmap | b;

    pool->block_size = s;

#if AO_ALLOC_FREE

    pool->free = f;

    ao_alloc_free += f;

#endif

#if AO_ALLOC_FREE_MIN

    pool->free_min = f;

    ao_alloc_free_min += f;

#endif

    pool->front = (ao_alloc_pool_node_t *) nodes;

    for (i = 0; i < c - 1; i++)
    {
        nodes[i].pool = p;

        nodes[i].next = nodes + i + 1;
    }

    nodes[c - 1].pool = p;
}

#endif

#if AO_ALLOC_POOL_30

void ao_boot_alloc_pool_30()
{
    // Variables.

    size_t const c = AO_ALLOC_POOL_BLOCK_COUNT_30;

    ao_alloc_pool_node_30_t * const nodes = ao_alloc_pool_nodes_30;

    size_t const p = 30;

    ao_alloc_pool_t * const pool = &ao_alloc_pool_30;

    size_t const s = AO_ALLOC_POOL_BLOCK_SIZE_30;


    // Variables.

    size_t const b = ((size_t) 1 << p);

#if AO_ALLOC_FREE_MIN                                                   ||  \
    AO_ALLOC_FREE

    size_t const f = c * s;

#endif

    size_t i;


    // Ready.

    ao_alloc_pools[p] = pool;

    ao_alloc_bitmap = ao_alloc_bitmap | b;

    pool->block_size = s;

#if AO_ALLOC_FREE

    pool->free = f;

    ao_alloc_free += f;

#endif

#if AO_ALLOC_FREE_MIN

    pool->free_min = f;

    ao_alloc_free_min += f;

#endif

    pool->front = (ao_alloc_pool_node_t *) nodes;

    for (i = 0; i < c - 1; i++)
    {
        nodes[i].pool = p;

        nodes[i].next = nodes + i + 1;
    }

    nodes[c - 1].pool = p;
}

#endif

#if AO_ALLOC_POOL_31

void ao_boot_alloc_pool_31()
{
    // Variables.

    size_t const c = AO_ALLOC_POOL_BLOCK_COUNT_31;

    ao_alloc_pool_node_31_t * const nodes = ao_alloc_pool_nodes_31;

    size_t const p = 31;

    ao_alloc_pool_t * const pool = &ao_alloc_pool_31;

    size_t const s = AO_ALLOC_POOL_BLOCK_SIZE_31;


    // Variables.

    size_t const b = ((size_t) 1 << p);

#if AO_ALLOC_FREE_MIN                                                   ||  \
    AO_ALLOC_FREE

    size_t const f = c * s;

#endif

    size_t i;


    // Ready.

    ao_alloc_pools[p] = pool;

    ao_alloc_bitmap = ao_alloc_bitmap | b;

    pool->block_size = s;

#if AO_ALLOC_FREE

    pool->free = f;

    ao_alloc_free += f;

#endif

#if AO_ALLOC_FREE_MIN

    pool->free_min = f;

    ao_alloc_free_min += f;

#endif

    pool->front = (ao_alloc_pool_node_t *) nodes;

    for (i = 0; i < c - 1; i++)
    {
        nodes[i].pool = p;

        nodes[i].next = nodes + i + 1;
    }

    nodes[c - 1].pool = p;
}

#endif

#if AO_ALLOC_POOL_32

void ao_boot_alloc_pool_32()
{
    // Variables.

    size_t const c = AO_ALLOC_POOL_BLOCK_COUNT_32;

    ao_alloc_pool_node_32_t * const nodes = ao_alloc_pool_nodes_32;

    size_t const p = 32;

    ao_alloc_pool_t * const pool = &ao_alloc_pool_32;

    size_t const s = AO_ALLOC_POOL_BLOCK_SIZE_32;


    // Variables.

    size_t const b = ((size_t) 1 << p);

#if AO_ALLOC_FREE_MIN                                                   ||  \
    AO_ALLOC_FREE

    size_t const f = c * s;

#endif

    size_t i;


    // Ready.

    ao_alloc_pools[p] = pool;

    ao_alloc_bitmap = ao_alloc_bitmap | b;

    pool->block_size = s;

#if AO_ALLOC_FREE

    pool->free = f;

    ao_alloc_free += f;

#endif

#if AO_ALLOC_FREE_MIN

    pool->free_min = f;

    ao_alloc_free_min += f;

#endif

    pool->front = (ao_alloc_pool_node_t *) nodes;

    for (i = 0; i < c - 1; i++)
    {
        nodes[i].pool = p;

        nodes[i].next = nodes + i + 1;
    }

    nodes[c - 1].pool = p;
}

#endif

#if AO_ALLOC_POOL_33

void ao_boot_alloc_pool_33()
{
    // Variables.

    size_t const c = AO_ALLOC_POOL_BLOCK_COUNT_33;

    ao_alloc_pool_node_33_t * const nodes = ao_alloc_pool_nodes_33;

    size_t const p = 33;

    ao_alloc_pool_t * const pool = &ao_alloc_pool_33;

    size_t const s = AO_ALLOC_POOL_BLOCK_SIZE_33;


    // Variables.

    size_t const b = ((size_t) 1 << p);

#if AO_ALLOC_FREE_MIN                                                   ||  \
    AO_ALLOC_FREE

    size_t const f = c * s;

#endif

    size_t i;


    // Ready.

    ao_alloc_pools[p] = pool;

    ao_alloc_bitmap = ao_alloc_bitmap | b;

    pool->block_size = s;

#if AO_ALLOC_FREE

    pool->free = f;

    ao_alloc_free += f;

#endif

#if AO_ALLOC_FREE_MIN

    pool->free_min = f;

    ao_alloc_free_min += f;

#endif

    pool->front = (ao_alloc_pool_node_t *) nodes;

    for (i = 0; i < c - 1; i++)
    {
        nodes[i].pool = p;

        nodes[i].next = nodes + i + 1;
    }

    nodes[c - 1].pool = p;
}

#endif

#if AO_ALLOC_POOL_34

void ao_boot_alloc_pool_34()
{
    // Variables.

    size_t const c = AO_ALLOC_POOL_BLOCK_COUNT_34;

    ao_alloc_pool_node_34_t * const nodes = ao_alloc_pool_nodes_34;

    size_t const p = 34;

    ao_alloc_pool_t * const pool = &ao_alloc_pool_34;

    size_t const s = AO_ALLOC_POOL_BLOCK_SIZE_34;


    // Variables.

    size_t const b = ((size_t) 1 << p);

#if AO_ALLOC_FREE_MIN                                                   ||  \
    AO_ALLOC_FREE

    size_t const f = c * s;

#endif

    size_t i;


    // Ready.

    ao_alloc_pools[p] = pool;

    ao_alloc_bitmap = ao_alloc_bitmap | b;

    pool->block_size = s;

#if AO_ALLOC_FREE

    pool->free = f;

    ao_alloc_free += f;

#endif

#if AO_ALLOC_FREE_MIN

    pool->free_min = f;

    ao_alloc_free_min += f;

#endif

    pool->front = (ao_alloc_pool_node_t *) nodes;

    for (i = 0; i < c - 1; i++)
    {
        nodes[i].pool = p;

        nodes[i].next = nodes + i + 1;
    }

    nodes[c - 1].pool = p;
}

#endif

#if AO_ALLOC_POOL_35

void ao_boot_alloc_pool_35()
{
    // Variables.

    size_t const c = AO_ALLOC_POOL_BLOCK_COUNT_35;

    ao_alloc_pool_node_35_t * const nodes = ao_alloc_pool_nodes_35;

    size_t const p = 35;

    ao_alloc_pool_t * const pool = &ao_alloc_pool_35;

    size_t const s = AO_ALLOC_POOL_BLOCK_SIZE_35;


    // Variables.

    size_t const b = ((size_t) 1 << p);

#if AO_ALLOC_FREE_MIN                                                   ||  \
    AO_ALLOC_FREE

    size_t const f = c * s;

#endif

    size_t i;


    // Ready.

    ao_alloc_pools[p] = pool;

    ao_alloc_bitmap = ao_alloc_bitmap | b;

    pool->block_size = s;

#if AO_ALLOC_FREE

    pool->free = f;

    ao_alloc_free += f;

#endif

#if AO_ALLOC_FREE_MIN

    pool->free_min = f;

    ao_alloc_free_min += f;

#endif

    pool->front = (ao_alloc_pool_node_t *) nodes;

    for (i = 0; i < c - 1; i++)
    {
        nodes[i].pool = p;

        nodes[i].next = nodes + i + 1;
    }

    nodes[c - 1].pool = p;
}

#endif

#if AO_ALLOC_POOL_36

void ao_boot_alloc_pool_36()
{
    // Variables.

    size_t const c = AO_ALLOC_POOL_BLOCK_COUNT_36;

    ao_alloc_pool_node_36_t * const nodes = ao_alloc_pool_nodes_36;

    size_t const p = 36;

    ao_alloc_pool_t * const pool = &ao_alloc_pool_36;

    size_t const s = AO_ALLOC_POOL_BLOCK_SIZE_36;


    // Variables.

    size_t const b = ((size_t) 1 << p);

#if AO_ALLOC_FREE_MIN                                                   ||  \
    AO_ALLOC_FREE

    size_t const f = c * s;

#endif

    size_t i;


    // Ready.

    ao_alloc_pools[p] = pool;

    ao_alloc_bitmap = ao_alloc_bitmap | b;

    pool->block_size = s;

#if AO_ALLOC_FREE

    pool->free = f;

    ao_alloc_free += f;

#endif

#if AO_ALLOC_FREE_MIN

    pool->free_min = f;

    ao_alloc_free_min += f;

#endif

    pool->front = (ao_alloc_pool_node_t *) nodes;

    for (i = 0; i < c - 1; i++)
    {
        nodes[i].pool = p;

        nodes[i].next = nodes + i + 1;
    }

    nodes[c - 1].pool = p;
}

#endif

#if AO_ALLOC_POOL_37

void ao_boot_alloc_pool_37()
{
    // Variables.

    size_t const c = AO_ALLOC_POOL_BLOCK_COUNT_37;

    ao_alloc_pool_node_37_t * const nodes = ao_alloc_pool_nodes_37;

    size_t const p = 37;

    ao_alloc_pool_t * const pool = &ao_alloc_pool_37;

    size_t const s = AO_ALLOC_POOL_BLOCK_SIZE_37;


    // Variables.

    size_t const b = ((size_t) 1 << p);

#if AO_ALLOC_FREE_MIN                                                   ||  \
    AO_ALLOC_FREE

    size_t const f = c * s;

#endif

    size_t i;


    // Ready.

    ao_alloc_pools[p] = pool;

    ao_alloc_bitmap = ao_alloc_bitmap | b;

    pool->block_size = s;

#if AO_ALLOC_FREE

    pool->free = f;

    ao_alloc_free += f;

#endif

#if AO_ALLOC_FREE_MIN

    pool->free_min = f;

    ao_alloc_free_min += f;

#endif

    pool->front = (ao_alloc_pool_node_t *) nodes;

    for (i = 0; i < c - 1; i++)
    {
        nodes[i].pool = p;

        nodes[i].next = nodes + i + 1;
    }

    nodes[c - 1].pool = p;
}

#endif

#if AO_ALLOC_POOL_38

void ao_boot_alloc_pool_38()
{
    // Variables.

    size_t const c = AO_ALLOC_POOL_BLOCK_COUNT_38;

    ao_alloc_pool_node_38_t * const nodes = ao_alloc_pool_nodes_38;

    size_t const p = 38;

    ao_alloc_pool_t * const pool = &ao_alloc_pool_38;

    size_t const s = AO_ALLOC_POOL_BLOCK_SIZE_38;


    // Variables.

    size_t const b = ((size_t) 1 << p);

#if AO_ALLOC_FREE_MIN                                                   ||  \
    AO_ALLOC_FREE

    size_t const f = c * s;

#endif

    size_t i;


    // Ready.

    ao_alloc_pools[p] = pool;

    ao_alloc_bitmap = ao_alloc_bitmap | b;

    pool->block_size = s;

#if AO_ALLOC_FREE

    pool->free = f;

    ao_alloc_free += f;

#endif

#if AO_ALLOC_FREE_MIN

    pool->free_min = f;

    ao_alloc_free_min += f;

#endif

    pool->front = (ao_alloc_pool_node_t *) nodes;

    for (i = 0; i < c - 1; i++)
    {
        nodes[i].pool = p;

        nodes[i].next = nodes + i + 1;
    }

    nodes[c - 1].pool = p;
}

#endif

#if AO_ALLOC_POOL_39

void ao_boot_alloc_pool_39()
{
    // Variables.

    size_t const c = AO_ALLOC_POOL_BLOCK_COUNT_39;

    ao_alloc_pool_node_39_t * const nodes = ao_alloc_pool_nodes_39;

    size_t const p = 39;

    ao_alloc_pool_t * const pool = &ao_alloc_pool_39;

    size_t const s = AO_ALLOC_POOL_BLOCK_SIZE_39;


    // Variables.

    size_t const b = ((size_t) 1 << p);

#if AO_ALLOC_FREE_MIN                                                   ||  \
    AO_ALLOC_FREE

    size_t const f = c * s;

#endif

    size_t i;


    // Ready.

    ao_alloc_pools[p] = pool;

    ao_alloc_bitmap = ao_alloc_bitmap | b;

    pool->block_size = s;

#if AO_ALLOC_FREE

    pool->free = f;

    ao_alloc_free += f;

#endif

#if AO_ALLOC_FREE_MIN

    pool->free_min = f;

    ao_alloc_free_min += f;

#endif

    pool->front = (ao_alloc_pool_node_t *) nodes;

    for (i = 0; i < c - 1; i++)
    {
        nodes[i].pool = p;

        nodes[i].next = nodes + i + 1;
    }

    nodes[c - 1].pool = p;
}

#endif

#if AO_ALLOC_POOL_40

void ao_boot_alloc_pool_40()
{
    // Variables.

    size_t const c = AO_ALLOC_POOL_BLOCK_COUNT_40;

    ao_alloc_pool_node_40_t * const nodes = ao_alloc_pool_nodes_40;

    size_t const p = 40;

    ao_alloc_pool_t * const pool = &ao_alloc_pool_40;

    size_t const s = AO_ALLOC_POOL_BLOCK_SIZE_40;


    // Variables.

    size_t const b = ((size_t) 1 << p);

#if AO_ALLOC_FREE_MIN                                                   ||  \
    AO_ALLOC_FREE

    size_t const f = c * s;

#endif

    size_t i;


    // Ready.

    ao_alloc_pools[p] = pool;

    ao_alloc_bitmap = ao_alloc_bitmap | b;

    pool->block_size = s;

#if AO_ALLOC_FREE

    pool->free = f;

    ao_alloc_free += f;

#endif

#if AO_ALLOC_FREE_MIN

    pool->free_min = f;

    ao_alloc_free_min += f;

#endif

    pool->front = (ao_alloc_pool_node_t *) nodes;

    for (i = 0; i < c - 1; i++)
    {
        nodes[i].pool = p;

        nodes[i].next = nodes + i + 1;
    }

    nodes[c - 1].pool = p;
}

#endif

#if AO_ALLOC_POOL_41

void ao_boot_alloc_pool_41()
{
    // Variables.

    size_t const c = AO_ALLOC_POOL_BLOCK_COUNT_41;

    ao_alloc_pool_node_41_t * const nodes = ao_alloc_pool_nodes_41;

    size_t const p = 41;

    ao_alloc_pool_t * const pool = &ao_alloc_pool_41;

    size_t const s = AO_ALLOC_POOL_BLOCK_SIZE_41;


    // Variables.

    size_t const b = ((size_t) 1 << p);

#if AO_ALLOC_FREE_MIN                                                   ||  \
    AO_ALLOC_FREE

    size_t const f = c * s;

#endif

    size_t i;


    // Ready.

    ao_alloc_pools[p] = pool;

    ao_alloc_bitmap = ao_alloc_bitmap | b;

    pool->block_size = s;

#if AO_ALLOC_FREE

    pool->free = f;

    ao_alloc_free += f;

#endif

#if AO_ALLOC_FREE_MIN

    pool->free_min = f;

    ao_alloc_free_min += f;

#endif

    pool->front = (ao_alloc_pool_node_t *) nodes;

    for (i = 0; i < c - 1; i++)
    {
        nodes[i].pool = p;

        nodes[i].next = nodes + i + 1;
    }

    nodes[c - 1].pool = p;
}

#endif

#if AO_ALLOC_POOL_42

void ao_boot_alloc_pool_42()
{
    // Variables.

    size_t const c = AO_ALLOC_POOL_BLOCK_COUNT_42;

    ao_alloc_pool_node_42_t * const nodes = ao_alloc_pool_nodes_42;

    size_t const p = 42;

    ao_alloc_pool_t * const pool = &ao_alloc_pool_42;

    size_t const s = AO_ALLOC_POOL_BLOCK_SIZE_42;


    // Variables.

    size_t const b = ((size_t) 1 << p);

#if AO_ALLOC_FREE_MIN                                                   ||  \
    AO_ALLOC_FREE

    size_t const f = c * s;

#endif

    size_t i;


    // Ready.

    ao_alloc_pools[p] = pool;

    ao_alloc_bitmap = ao_alloc_bitmap | b;

    pool->block_size = s;

#if AO_ALLOC_FREE

    pool->free = f;

    ao_alloc_free += f;

#endif

#if AO_ALLOC_FREE_MIN

    pool->free_min = f;

    ao_alloc_free_min += f;

#endif

    pool->front = (ao_alloc_pool_node_t *) nodes;

    for (i = 0; i < c - 1; i++)
    {
        nodes[i].pool = p;

        nodes[i].next = nodes + i + 1;
    }

    nodes[c - 1].pool = p;
}

#endif

#if AO_ALLOC_POOL_43

void ao_boot_alloc_pool_43()
{
    // Variables.

    size_t const c = AO_ALLOC_POOL_BLOCK_COUNT_43;

    ao_alloc_pool_node_43_t * const nodes = ao_alloc_pool_nodes_43;

    size_t const p = 43;

    ao_alloc_pool_t * const pool = &ao_alloc_pool_43;

    size_t const s = AO_ALLOC_POOL_BLOCK_SIZE_43;


    // Variables.

    size_t const b = ((size_t) 1 << p);

#if AO_ALLOC_FREE_MIN                                                   ||  \
    AO_ALLOC_FREE

    size_t const f = c * s;

#endif

    size_t i;


    // Ready.

    ao_alloc_pools[p] = pool;

    ao_alloc_bitmap = ao_alloc_bitmap | b;

    pool->block_size = s;

#if AO_ALLOC_FREE

    pool->free = f;

    ao_alloc_free += f;

#endif

#if AO_ALLOC_FREE_MIN

    pool->free_min = f;

    ao_alloc_free_min += f;

#endif

    pool->front = (ao_alloc_pool_node_t *) nodes;

    for (i = 0; i < c - 1; i++)
    {
        nodes[i].pool = p;

        nodes[i].next = nodes + i + 1;
    }

    nodes[c - 1].pool = p;
}

#endif

#if AO_ALLOC_POOL_44

void ao_boot_alloc_pool_44()
{
    // Variables.

    size_t const c = AO_ALLOC_POOL_BLOCK_COUNT_44;

    ao_alloc_pool_node_44_t * const nodes = ao_alloc_pool_nodes_44;

    size_t const p = 44;

    ao_alloc_pool_t * const pool = &ao_alloc_pool_44;

    size_t const s = AO_ALLOC_POOL_BLOCK_SIZE_44;


    // Variables.

    size_t const b = ((size_t) 1 << p);

#if AO_ALLOC_FREE_MIN                                                   ||  \
    AO_ALLOC_FREE

    size_t const f = c * s;

#endif

    size_t i;


    // Ready.

    ao_alloc_pools[p] = pool;

    ao_alloc_bitmap = ao_alloc_bitmap | b;

    pool->block_size = s;

#if AO_ALLOC_FREE

    pool->free = f;

    ao_alloc_free += f;

#endif

#if AO_ALLOC_FREE_MIN

    pool->free_min = f;

    ao_alloc_free_min += f;

#endif

    pool->front = (ao_alloc_pool_node_t *) nodes;

    for (i = 0; i < c - 1; i++)
    {
        nodes[i].pool = p;

        nodes[i].next = nodes + i + 1;
    }

    nodes[c - 1].pool = p;
}

#endif

#if AO_ALLOC_POOL_45

void ao_boot_alloc_pool_45()
{
    // Variables.

    size_t const c = AO_ALLOC_POOL_BLOCK_COUNT_45;

    ao_alloc_pool_node_45_t * const nodes = ao_alloc_pool_nodes_45;

    size_t const p = 45;

    ao_alloc_pool_t * const pool = &ao_alloc_pool_45;

    size_t const s = AO_ALLOC_POOL_BLOCK_SIZE_45;


    // Variables.

    size_t const b = ((size_t) 1 << p);

#if AO_ALLOC_FREE_MIN                                                   ||  \
    AO_ALLOC_FREE

    size_t const f = c * s;

#endif

    size_t i;


    // Ready.

    ao_alloc_pools[p] = pool;

    ao_alloc_bitmap = ao_alloc_bitmap | b;

    pool->block_size = s;

#if AO_ALLOC_FREE

    pool->free = f;

    ao_alloc_free += f;

#endif

#if AO_ALLOC_FREE_MIN

    pool->free_min = f;

    ao_alloc_free_min += f;

#endif

    pool->front = (ao_alloc_pool_node_t *) nodes;

    for (i = 0; i < c - 1; i++)
    {
        nodes[i].pool = p;

        nodes[i].next = nodes + i + 1;
    }

    nodes[c - 1].pool = p;
}

#endif

#if AO_ALLOC_POOL_46

void ao_boot_alloc_pool_46()
{
    // Variables.

    size_t const c = AO_ALLOC_POOL_BLOCK_COUNT_46;

    ao_alloc_pool_node_46_t * const nodes = ao_alloc_pool_nodes_46;

    size_t const p = 46;

    ao_alloc_pool_t * const pool = &ao_alloc_pool_46;

    size_t const s = AO_ALLOC_POOL_BLOCK_SIZE_46;


    // Variables.

    size_t const b = ((size_t) 1 << p);

#if AO_ALLOC_FREE_MIN                                                   ||  \
    AO_ALLOC_FREE

    size_t const f = c * s;

#endif

    size_t i;


    // Ready.

    ao_alloc_pools[p] = pool;

    ao_alloc_bitmap = ao_alloc_bitmap | b;

    pool->block_size = s;

#if AO_ALLOC_FREE

    pool->free = f;

    ao_alloc_free += f;

#endif

#if AO_ALLOC_FREE_MIN

    pool->free_min = f;

    ao_alloc_free_min += f;

#endif

    pool->front = (ao_alloc_pool_node_t *) nodes;

    for (i = 0; i < c - 1; i++)
    {
        nodes[i].pool = p;

        nodes[i].next = nodes + i + 1;
    }

    nodes[c - 1].pool = p;
}

#endif

#if AO_ALLOC_POOL_47

void ao_boot_alloc_pool_47()
{
    // Variables.

    size_t const c = AO_ALLOC_POOL_BLOCK_COUNT_47;

    ao_alloc_pool_node_47_t * const nodes = ao_alloc_pool_nodes_47;

    size_t const p = 47;

    ao_alloc_pool_t * const pool = &ao_alloc_pool_47;

    size_t const s = AO_ALLOC_POOL_BLOCK_SIZE_47;


    // Variables.

    size_t const b = ((size_t) 1 << p);

#if AO_ALLOC_FREE_MIN                                                   ||  \
    AO_ALLOC_FREE

    size_t const f = c * s;

#endif

    size_t i;


    // Ready.

    ao_alloc_pools[p] = pool;

    ao_alloc_bitmap = ao_alloc_bitmap | b;

    pool->block_size = s;

#if AO_ALLOC_FREE

    pool->free = f;

    ao_alloc_free += f;

#endif

#if AO_ALLOC_FREE_MIN

    pool->free_min = f;

    ao_alloc_free_min += f;

#endif

    pool->front = (ao_alloc_pool_node_t *) nodes;

    for (i = 0; i < c - 1; i++)
    {
        nodes[i].pool = p;

        nodes[i].next = nodes + i + 1;
    }

    nodes[c - 1].pool = p;
}

#endif

#if AO_ALLOC_POOL_48

void ao_boot_alloc_pool_48()
{
    // Variables.

    size_t const c = AO_ALLOC_POOL_BLOCK_COUNT_48;

    ao_alloc_pool_node_48_t * const nodes = ao_alloc_pool_nodes_48;

    size_t const p = 48;

    ao_alloc_pool_t * const pool = &ao_alloc_pool_48;

    size_t const s = AO_ALLOC_POOL_BLOCK_SIZE_48;


    // Variables.

    size_t const b = ((size_t) 1 << p);

#if AO_ALLOC_FREE_MIN                                                   ||  \
    AO_ALLOC_FREE

    size_t const f = c * s;

#endif

    size_t i;


    // Ready.

    ao_alloc_pools[p] = pool;

    ao_alloc_bitmap = ao_alloc_bitmap | b;

    pool->block_size = s;

#if AO_ALLOC_FREE

    pool->free = f;

    ao_alloc_free += f;

#endif

#if AO_ALLOC_FREE_MIN

    pool->free_min = f;

    ao_alloc_free_min += f;

#endif

    pool->front = (ao_alloc_pool_node_t *) nodes;

    for (i = 0; i < c - 1; i++)
    {
        nodes[i].pool = p;

        nodes[i].next = nodes + i + 1;
    }

    nodes[c - 1].pool = p;
}

#endif

#if AO_ALLOC_POOL_49

void ao_boot_alloc_pool_49()
{
    // Variables.

    size_t const c = AO_ALLOC_POOL_BLOCK_COUNT_49;

    ao_alloc_pool_node_49_t * const nodes = ao_alloc_pool_nodes_49;

    size_t const p = 49;

    ao_alloc_pool_t * const pool = &ao_alloc_pool_49;

    size_t const s = AO_ALLOC_POOL_BLOCK_SIZE_49;


    // Variables.

    size_t const b = ((size_t) 1 << p);

#if AO_ALLOC_FREE_MIN                                                   ||  \
    AO_ALLOC_FREE

    size_t const f = c * s;

#endif

    size_t i;


    // Ready.

    ao_alloc_pools[p] = pool;

    ao_alloc_bitmap = ao_alloc_bitmap | b;

    pool->block_size = s;

#if AO_ALLOC_FREE

    pool->free = f;

    ao_alloc_free += f;

#endif

#if AO_ALLOC_FREE_MIN

    pool->free_min = f;

    ao_alloc_free_min += f;

#endif

    pool->front = (ao_alloc_pool_node_t *) nodes;

    for (i = 0; i < c - 1; i++)
    {
        nodes[i].pool = p;

        nodes[i].next = nodes + i + 1;
    }

    nodes[c - 1].pool = p;
}

#endif

#if AO_ALLOC_POOL_50

void ao_boot_alloc_pool_50()
{
    // Variables.

    size_t const c = AO_ALLOC_POOL_BLOCK_COUNT_50;

    ao_alloc_pool_node_50_t * const nodes = ao_alloc_pool_nodes_50;

    size_t const p = 50;

    ao_alloc_pool_t * const pool = &ao_alloc_pool_50;

    size_t const s = AO_ALLOC_POOL_BLOCK_SIZE_50;


    // Variables.

    size_t const b = ((size_t) 1 << p);

#if AO_ALLOC_FREE_MIN                                                   ||  \
    AO_ALLOC_FREE

    size_t const f = c * s;

#endif

    size_t i;


    // Ready.

    ao_alloc_pools[p] = pool;

    ao_alloc_bitmap = ao_alloc_bitmap | b;

    pool->block_size = s;

#if AO_ALLOC_FREE

    pool->free = f;

    ao_alloc_free += f;

#endif

#if AO_ALLOC_FREE_MIN

    pool->free_min = f;

    ao_alloc_free_min += f;

#endif

    pool->front = (ao_alloc_pool_node_t *) nodes;

    for (i = 0; i < c - 1; i++)
    {
        nodes[i].pool = p;

        nodes[i].next = nodes + i + 1;
    }

    nodes[c - 1].pool = p;
}

#endif

#if AO_ALLOC_POOL_51

void ao_boot_alloc_pool_51()
{
    // Variables.

    size_t const c = AO_ALLOC_POOL_BLOCK_COUNT_51;

    ao_alloc_pool_node_51_t * const nodes = ao_alloc_pool_nodes_51;

    size_t const p = 51;

    ao_alloc_pool_t * const pool = &ao_alloc_pool_51;

    size_t const s = AO_ALLOC_POOL_BLOCK_SIZE_51;


    // Variables.

    size_t const b = ((size_t) 1 << p);

#if AO_ALLOC_FREE_MIN                                                   ||  \
    AO_ALLOC_FREE

    size_t const f = c * s;

#endif

    size_t i;


    // Ready.

    ao_alloc_pools[p] = pool;

    ao_alloc_bitmap = ao_alloc_bitmap | b;

    pool->block_size = s;

#if AO_ALLOC_FREE

    pool->free = f;

    ao_alloc_free += f;

#endif

#if AO_ALLOC_FREE_MIN

    pool->free_min = f;

    ao_alloc_free_min += f;

#endif

    pool->front = (ao_alloc_pool_node_t *) nodes;

    for (i = 0; i < c - 1; i++)
    {
        nodes[i].pool = p;

        nodes[i].next = nodes + i + 1;
    }

    nodes[c - 1].pool = p;
}

#endif

#if AO_ALLOC_POOL_52

void ao_boot_alloc_pool_52()
{
    // Variables.

    size_t const c = AO_ALLOC_POOL_BLOCK_COUNT_52;

    ao_alloc_pool_node_52_t * const nodes = ao_alloc_pool_nodes_52;

    size_t const p = 52;

    ao_alloc_pool_t * const pool = &ao_alloc_pool_52;

    size_t const s = AO_ALLOC_POOL_BLOCK_SIZE_52;


    // Variables.

    size_t const b = ((size_t) 1 << p);

#if AO_ALLOC_FREE_MIN                                                   ||  \
    AO_ALLOC_FREE

    size_t const f = c * s;

#endif

    size_t i;


    // Ready.

    ao_alloc_pools[p] = pool;

    ao_alloc_bitmap = ao_alloc_bitmap | b;

    pool->block_size = s;

#if AO_ALLOC_FREE

    pool->free = f;

    ao_alloc_free += f;

#endif

#if AO_ALLOC_FREE_MIN

    pool->free_min = f;

    ao_alloc_free_min += f;

#endif

    pool->front = (ao_alloc_pool_node_t *) nodes;

    for (i = 0; i < c - 1; i++)
    {
        nodes[i].pool = p;

        nodes[i].next = nodes + i + 1;
    }

    nodes[c - 1].pool = p;
}

#endif

#if AO_ALLOC_POOL_53

void ao_boot_alloc_pool_53()
{
    // Variables.

    size_t const c = AO_ALLOC_POOL_BLOCK_COUNT_53;

    ao_alloc_pool_node_53_t * const nodes = ao_alloc_pool_nodes_53;

    size_t const p = 53;

    ao_alloc_pool_t * const pool = &ao_alloc_pool_53;

    size_t const s = AO_ALLOC_POOL_BLOCK_SIZE_53;


    // Variables.

    size_t const b = ((size_t) 1 << p);

#if AO_ALLOC_FREE_MIN                                                   ||  \
    AO_ALLOC_FREE

    size_t const f = c * s;

#endif

    size_t i;


    // Ready.

    ao_alloc_pools[p] = pool;

    ao_alloc_bitmap = ao_alloc_bitmap | b;

    pool->block_size = s;

#if AO_ALLOC_FREE

    pool->free = f;

    ao_alloc_free += f;

#endif

#if AO_ALLOC_FREE_MIN

    pool->free_min = f;

    ao_alloc_free_min += f;

#endif

    pool->front = (ao_alloc_pool_node_t *) nodes;

    for (i = 0; i < c - 1; i++)
    {
        nodes[i].pool = p;

        nodes[i].next = nodes + i + 1;
    }

    nodes[c - 1].pool = p;
}

#endif

#if AO_ALLOC_POOL_54

void ao_boot_alloc_pool_54()
{
    // Variables.

    size_t const c = AO_ALLOC_POOL_BLOCK_COUNT_54;

    ao_alloc_pool_node_54_t * const nodes = ao_alloc_pool_nodes_54;

    size_t const p = 54;

    ao_alloc_pool_t * const pool = &ao_alloc_pool_54;

    size_t const s = AO_ALLOC_POOL_BLOCK_SIZE_54;


    // Variables.

    size_t const b = ((size_t) 1 << p);

#if AO_ALLOC_FREE_MIN                                                   ||  \
    AO_ALLOC_FREE

    size_t const f = c * s;

#endif

    size_t i;


    // Ready.

    ao_alloc_pools[p] = pool;

    ao_alloc_bitmap = ao_alloc_bitmap | b;

    pool->block_size = s;

#if AO_ALLOC_FREE

    pool->free = f;

    ao_alloc_free += f;

#endif

#if AO_ALLOC_FREE_MIN

    pool->free_min = f;

    ao_alloc_free_min += f;

#endif

    pool->front = (ao_alloc_pool_node_t *) nodes;

    for (i = 0; i < c - 1; i++)
    {
        nodes[i].pool = p;

        nodes[i].next = nodes + i + 1;
    }

    nodes[c - 1].pool = p;
}

#endif

#if AO_ALLOC_POOL_55

void ao_boot_alloc_pool_55()
{
    // Variables.

    size_t const c = AO_ALLOC_POOL_BLOCK_COUNT_55;

    ao_alloc_pool_node_55_t * const nodes = ao_alloc_pool_nodes_55;

    size_t const p = 55;

    ao_alloc_pool_t * const pool = &ao_alloc_pool_55;

    size_t const s = AO_ALLOC_POOL_BLOCK_SIZE_55;


    // Variables.

    size_t const b = ((size_t) 1 << p);

#if AO_ALLOC_FREE_MIN                                                   ||  \
    AO_ALLOC_FREE

    size_t const f = c * s;

#endif

    size_t i;


    // Ready.

    ao_alloc_pools[p] = pool;

    ao_alloc_bitmap = ao_alloc_bitmap | b;

    pool->block_size = s;

#if AO_ALLOC_FREE

    pool->free = f;

    ao_alloc_free += f;

#endif

#if AO_ALLOC_FREE_MIN

    pool->free_min = f;

    ao_alloc_free_min += f;

#endif

    pool->front = (ao_alloc_pool_node_t *) nodes;

    for (i = 0; i < c - 1; i++)
    {
        nodes[i].pool = p;

        nodes[i].next = nodes + i + 1;
    }

    nodes[c - 1].pool = p;
}

#endif

#if AO_ALLOC_POOL_56

void ao_boot_alloc_pool_56()
{
    // Variables.

    size_t const c = AO_ALLOC_POOL_BLOCK_COUNT_56;

    ao_alloc_pool_node_56_t * const nodes = ao_alloc_pool_nodes_56;

    size_t const p = 56;

    ao_alloc_pool_t * const pool = &ao_alloc_pool_56;

    size_t const s = AO_ALLOC_POOL_BLOCK_SIZE_56;


    // Variables.

    size_t const b = ((size_t) 1 << p);

#if AO_ALLOC_FREE_MIN                                                   ||  \
    AO_ALLOC_FREE

    size_t const f = c * s;

#endif

    size_t i;


    // Ready.

    ao_alloc_pools[p] = pool;

    ao_alloc_bitmap = ao_alloc_bitmap | b;

    pool->block_size = s;

#if AO_ALLOC_FREE

    pool->free = f;

    ao_alloc_free += f;

#endif

#if AO_ALLOC_FREE_MIN

    pool->free_min = f;

    ao_alloc_free_min += f;

#endif

    pool->front = (ao_alloc_pool_node_t *) nodes;

    for (i = 0; i < c - 1; i++)
    {
        nodes[i].pool = p;

        nodes[i].next = nodes + i + 1;
    }

    nodes[c - 1].pool = p;
}

#endif

#if AO_ALLOC_POOL_57

void ao_boot_alloc_pool_57()
{
    // Variables.

    size_t const c = AO_ALLOC_POOL_BLOCK_COUNT_57;

    ao_alloc_pool_node_57_t * const nodes = ao_alloc_pool_nodes_57;

    size_t const p = 57;

    ao_alloc_pool_t * const pool = &ao_alloc_pool_57;

    size_t const s = AO_ALLOC_POOL_BLOCK_SIZE_57;


    // Variables.

    size_t const b = ((size_t) 1 << p);

#if AO_ALLOC_FREE_MIN                                                   ||  \
    AO_ALLOC_FREE

    size_t const f = c * s;

#endif

    size_t i;


    // Ready.

    ao_alloc_pools[p] = pool;

    ao_alloc_bitmap = ao_alloc_bitmap | b;

    pool->block_size = s;

#if AO_ALLOC_FREE

    pool->free = f;

    ao_alloc_free += f;

#endif

#if AO_ALLOC_FREE_MIN

    pool->free_min = f;

    ao_alloc_free_min += f;

#endif

    pool->front = (ao_alloc_pool_node_t *) nodes;

    for (i = 0; i < c - 1; i++)
    {
        nodes[i].pool = p;

        nodes[i].next = nodes + i + 1;
    }

    nodes[c - 1].pool = p;
}

#endif

#if AO_ALLOC_POOL_58

void ao_boot_alloc_pool_58()
{
    // Variables.

    size_t const c = AO_ALLOC_POOL_BLOCK_COUNT_58;

    ao_alloc_pool_node_58_t * const nodes = ao_alloc_pool_nodes_58;

    size_t const p = 58;

    ao_alloc_pool_t * const pool = &ao_alloc_pool_58;

    size_t const s = AO_ALLOC_POOL_BLOCK_SIZE_58;


    // Variables.

    size_t const b = ((size_t) 1 << p);

#if AO_ALLOC_FREE_MIN                                                   ||  \
    AO_ALLOC_FREE

    size_t const f = c * s;

#endif

    size_t i;


    // Ready.

    ao_alloc_pools[p] = pool;

    ao_alloc_bitmap = ao_alloc_bitmap | b;

    pool->block_size = s;

#if AO_ALLOC_FREE

    pool->free = f;

    ao_alloc_free += f;

#endif

#if AO_ALLOC_FREE_MIN

    pool->free_min = f;

    ao_alloc_free_min += f;

#endif

    pool->front = (ao_alloc_pool_node_t *) nodes;

    for (i = 0; i < c - 1; i++)
    {
        nodes[i].pool = p;

        nodes[i].next = nodes + i + 1;
    }

    nodes[c - 1].pool = p;
}

#endif

#if AO_ALLOC_POOL_59

void ao_boot_alloc_pool_59()
{
    // Variables.

    size_t const c = AO_ALLOC_POOL_BLOCK_COUNT_59;

    ao_alloc_pool_node_59_t * const nodes = ao_alloc_pool_nodes_59;

    size_t const p = 59;

    ao_alloc_pool_t * const pool = &ao_alloc_pool_59;

    size_t const s = AO_ALLOC_POOL_BLOCK_SIZE_59;


    // Variables.

    size_t const b = ((size_t) 1 << p);

#if AO_ALLOC_FREE_MIN                                                   ||  \
    AO_ALLOC_FREE

    size_t const f = c * s;

#endif

    size_t i;


    // Ready.

    ao_alloc_pools[p] = pool;

    ao_alloc_bitmap = ao_alloc_bitmap | b;

    pool->block_size = s;

#if AO_ALLOC_FREE

    pool->free = f;

    ao_alloc_free += f;

#endif

#if AO_ALLOC_FREE_MIN

    pool->free_min = f;

    ao_alloc_free_min += f;

#endif

    pool->front = (ao_alloc_pool_node_t *) nodes;

    for (i = 0; i < c - 1; i++)
    {
        nodes[i].pool = p;

        nodes[i].next = nodes + i + 1;
    }

    nodes[c - 1].pool = p;
}

#endif

#if AO_ALLOC_POOL_60

void ao_boot_alloc_pool_60()
{
    // Variables.

    size_t const c = AO_ALLOC_POOL_BLOCK_COUNT_60;

    ao_alloc_pool_node_60_t * const nodes = ao_alloc_pool_nodes_60;

    size_t const p = 60;

    ao_alloc_pool_t * const pool = &ao_alloc_pool_60;

    size_t const s = AO_ALLOC_POOL_BLOCK_SIZE_60;


    // Variables.

    size_t const b = ((size_t) 1 << p);

#if AO_ALLOC_FREE_MIN                                                   ||  \
    AO_ALLOC_FREE

    size_t const f = c * s;

#endif

    size_t i;


    // Ready.

    ao_alloc_pools[p] = pool;

    ao_alloc_bitmap = ao_alloc_bitmap | b;

    pool->block_size = s;

#if AO_ALLOC_FREE

    pool->free = f;

    ao_alloc_free += f;

#endif

#if AO_ALLOC_FREE_MIN

    pool->free_min = f;

    ao_alloc_free_min += f;

#endif

    pool->front = (ao_alloc_pool_node_t *) nodes;

    for (i = 0; i < c - 1; i++)
    {
        nodes[i].pool = p;

        nodes[i].next = nodes + i + 1;
    }

    nodes[c - 1].pool = p;
}

#endif

#if AO_ALLOC_POOL_61

void ao_boot_alloc_pool_61()
{
    // Variables.

    size_t const c = AO_ALLOC_POOL_BLOCK_COUNT_61;

    ao_alloc_pool_node_61_t * const nodes = ao_alloc_pool_nodes_61;

    size_t const p = 61;

    ao_alloc_pool_t * const pool = &ao_alloc_pool_61;

    size_t const s = AO_ALLOC_POOL_BLOCK_SIZE_61;


    // Variables.

    size_t const b = ((size_t) 1 << p);

#if AO_ALLOC_FREE_MIN                                                   ||  \
    AO_ALLOC_FREE

    size_t const f = c * s;

#endif

    size_t i;


    // Ready.

    ao_alloc_pools[p] = pool;

    ao_alloc_bitmap = ao_alloc_bitmap | b;

    pool->block_size = s;

#if AO_ALLOC_FREE

    pool->free = f;

    ao_alloc_free += f;

#endif

#if AO_ALLOC_FREE_MIN

    pool->free_min = f;

    ao_alloc_free_min += f;

#endif

    pool->front = (ao_alloc_pool_node_t *) nodes;

    for (i = 0; i < c - 1; i++)
    {
        nodes[i].pool = p;

        nodes[i].next = nodes + i + 1;
    }

    nodes[c - 1].pool = p;
}

#endif

#if AO_ALLOC_POOL_62

void ao_boot_alloc_pool_62()
{
    // Variables.

    size_t const c = AO_ALLOC_POOL_BLOCK_COUNT_62;

    ao_alloc_pool_node_62_t * const nodes = ao_alloc_pool_nodes_62;

    size_t const p = 62;

    ao_alloc_pool_t * const pool = &ao_alloc_pool_62;

    size_t const s = AO_ALLOC_POOL_BLOCK_SIZE_62;


    // Variables.

    size_t const b = ((size_t) 1 << p);

#if AO_ALLOC_FREE_MIN                                                   ||  \
    AO_ALLOC_FREE

    size_t const f = c * s;

#endif

    size_t i;


    // Ready.

    ao_alloc_pools[p] = pool;

    ao_alloc_bitmap = ao_alloc_bitmap | b;

    pool->block_size = s;

#if AO_ALLOC_FREE

    pool->free = f;

    ao_alloc_free += f;

#endif

#if AO_ALLOC_FREE_MIN

    pool->free_min = f;

    ao_alloc_free_min += f;

#endif

    pool->front = (ao_alloc_pool_node_t *) nodes;

    for (i = 0; i < c - 1; i++)
    {
        nodes[i].pool = p;

        nodes[i].next = nodes + i + 1;
    }

    nodes[c - 1].pool = p;
}

#endif

#if AO_ALLOC_POOL_63

void ao_boot_alloc_pool_63()
{
    // Variables.

    size_t const c = AO_ALLOC_POOL_BLOCK_COUNT_63;

    ao_alloc_pool_node_63_t * const nodes = ao_alloc_pool_nodes_63;

    size_t const p = 63;

    ao_alloc_pool_t * const pool = &ao_alloc_pool_63;

    size_t const s = AO_ALLOC_POOL_BLOCK_SIZE_63;


    // Variables.

    size_t const b = ((size_t) 1 << p);

#if AO_ALLOC_FREE_MIN                                                   ||  \
    AO_ALLOC_FREE

    size_t const f = c * s;

#endif

    size_t i;


    // Ready.

    ao_alloc_pools[p] = pool;

    ao_alloc_bitmap = ao_alloc_bitmap | b;

    pool->block_size = s;

#if AO_ALLOC_FREE

    pool->free = f;

    ao_alloc_free += f;

#endif

#if AO_ALLOC_FREE_MIN

    pool->free_min = f;

    ao_alloc_free_min += f;

#endif

    pool->front = (ao_alloc_pool_node_t *) nodes;

    for (i = 0; i < c - 1; i++)
    {
        nodes[i].pool = p;

        nodes[i].next = nodes + i + 1;
    }

    nodes[c - 1].pool = p;
}

#endif

// ----------------------------------------------------------------------------

bool ao_release_2(void * p)
{
    // Variables.

    bool r;


    // Ready.

    r = ao_release_3(p);

#if AO_RELEASED

    ao_released_info.ptr = p;

    ao_released_info.result = r;

    ao_released(&ao_released_info);

#endif

    return r;
}

bool ao_release_3(void * p)
{
    // Variables.

    ao_alloc_pool_node_t * F;

    size_t i;

    size_t j;

    size_t m;

    ao_alloc_pool_node_t * N;

    ao_alloc_pool_t * P;

    bool r;

    size_t R;

#if AO_ALLOC_ALLOCATED                                                  ||  \
    AO_ALLOC_ALLOCATED_MAX                                              ||  \
    AO_ALLOC_FREE                                                       ||  \
    AO_ALLOC_FREE_MIN                                                   ||  \
    AO_RELEASED

    size_t t1;

#endif

#if AO_ALLOC_ALLOCATED                                                  ||  \
    AO_ALLOC_ALLOCATED_MAX

    size_t t2;

    size_t t3;

#endif


    // Ready.

    N = ao_containerof(p, ao_alloc_pool_node_t, block);

#if AO_RELEASED

    j = N->pool;

    i = j;

    P = ao_alloc_pools[i];

    t1 = P->block_size;

#endif

    R = N->ref;

    ao_assert(R > 0);

    R--;

    if (R == 0)
    {

#if AO_RELEASED

#else

        j = N->pool;

        i = j;

        P = ao_alloc_pools[i];

#endif

        m = 1;

        m = m << j;

        F = P->front;

        if (F)
        {
            ao_assert((ao_alloc_bitmap & m) == m);
        }

        else
        {
            ao_assert((ao_alloc_bitmap & m) == 0);

            ao_alloc_bitmap = ao_alloc_bitmap | m;
        }

        N->next = F;

        P->front = N;

#if AO_RELEASED

#else

#if AO_ALLOC_ALLOCATED                                                  ||  \
    AO_ALLOC_ALLOCATED_MAX                                              ||  \
    AO_ALLOC_FREE                                                       ||  \
    AO_ALLOC_FREE_MIN

        t1 = P->block_size;

#endif

#endif

#if AO_ALLOC_ALLOCATED                                                  ||  \
    AO_ALLOC_ALLOCATED_MAX

        t2 = P->allocated;

        t3 = ao_alloc_allocated;

        ao_assert(t1 <= t2);

        ao_assert(t1 <= t3);

        t2 = t2 - t1;

        t3 = t3 - t1;

        P->allocated = t2;

        ao_alloc_allocated = t3;

#endif

#if AO_ALLOC_FREE                                                       ||  \
    AO_ALLOC_FREE_MIN

        P->free += t1;

        ao_alloc_free += t1;

#endif

        r = true;
    }

    else
    {
        r = false;
    }

    N->ref = R;

#if AO_RELEASED

    ao_released_info.pool = i;

    ao_released_info.ref = R;

    ao_released_info.size_body = t1;

#endif

    return r;
}

// ----------------------------------------------------------------------------

bool ao_retain_2(void * p)
{
    // Variables.

    bool r;


    // Ready.

    r = ao_retain_3(p);

#if AO_RETAINED

    ao_retained_info.ptr = p;

    ao_retained_info.result = r;

    ao_retained(&ao_retained_info);

#endif

    return r;
}

bool ao_retain_3(void * p)
{
    // Variables.

    ao_alloc_pool_node_t * N;

    size_t R;


    // Variables.

#if AO_RETAINED

    size_t i;

    ao_alloc_pool_t * P;

#endif


    // Ready.

    N = ao_containerof(p, ao_alloc_pool_node_t, block);

    R = N->ref;

    ao_assert(R > 0);

    ao_assert(R < AO_ALLOC_REF_MAX);

    R++;

    ao_assert(R > 0);

    N->ref = R;

#if AO_RETAINED

    i = N->pool;

    P = ao_alloc_pools[i];

    ao_retained_info.pool = i;

    ao_retained_info.ref = R;

    ao_retained_info.size_body = P->block_size;

#endif

    return true;
}

// ----------------------------------------------------------------------------

#endif

#if defined AO_ALLOC_2

// ----------------------------------------------------------------------------

#define AO_ALLOC_ALIGN                  (sizeof(max_align_t))

#define AO_ALLOC_ALIGN_LOG              ao_log2u(AO_ALLOC_ALIGN)

// ----------------------------------------------------------------------------

#define AO_ALLOC_SIZE_STORE             ao_align_down(AO_ALLOC_SIZE, AO_ALLOC_ALIGN)

#define AO_ALLOC_SIZE_STORE_LOG         ao_log2u(AO_ALLOC_SIZE_STORE)

// ----------------------------------------------------------------------------

#define AO_ALLOC_L2_COUNT_LOG           (AO_ALLOC_SEGREGATION)

#define AO_ALLOC_L2_COUNT               (1 << AO_ALLOC_L2_COUNT_LOG)

// ----------------------------------------------------------------------------

#define AO_ALLOC_L1_INDEX_MIN           (AO_ALLOC_ALIGN_LOG + AO_ALLOC_L2_COUNT_LOG)

#define AO_ALLOC_L1_INDEX_MAX           ao_max(AO_ALLOC_SIZE_STORE_LOG, AO_ALLOC_L1_INDEX_MIN)

// ----------------------------------------------------------------------------

#define AO_ALLOC_L1_COUNT               (AO_ALLOC_L1_INDEX_MAX - AO_ALLOC_L1_INDEX_MIN + 1)

// ----------------------------------------------------------------------------

#define AO_ALLOC_SIZE_BLOCK             sizeof(ao_alloc_block_t)

#define AO_ALLOC_SIZE_BLOCK_BODY        sizeof(ao_alloc_block_body_t)

#define AO_ALLOC_SIZE_BLOCK_HEAD        sizeof(ao_alloc_block_head_t)

// ----------------------------------------------------------------------------

typedef struct  ao_alloc_t              ao_alloc_t;

// ----------------------------------------------------------------------------

typedef         max_align_t             ao_alloc_align_t;

// ----------------------------------------------------------------------------

typedef struct  ao_alloc_block_t        ao_alloc_block_t;

typedef union   ao_alloc_block_body_t   ao_alloc_block_body_t;

typedef union   ao_alloc_block_head_t   ao_alloc_block_head_t;

// ----------------------------------------------------------------------------

typedef struct  ao_alloc_list_t         ao_alloc_list_t;

typedef struct  ao_alloc_list_node_t    ao_alloc_list_node_t;

// ----------------------------------------------------------------------------

struct  ao_alloc_list_t
{
        ao_alloc_list_node_t *          front;
};

struct  ao_alloc_list_node_t
{
        ao_alloc_list_node_t *          next;

        ao_alloc_list_node_t *          prev;
};

// ----------------------------------------------------------------------------

union   ao_alloc_block_body_t
{
        ao_alloc_align_t                align;

        ao_alloc_list_node_t            node;

        uint8_t                         store                   [1 << AO_ALLOC_L1_INDEX_MIN];
};

union   ao_alloc_block_head_t
{
        ao_alloc_align_t                align;

        struct
        {
            ao_alloc_block_t *          prev;

            ao_uint_t                   ref;

            size_t                      size_body;
        };
};

// ----------------------------------------------------------------------------

struct  ao_alloc_block_t
{
        ao_alloc_block_head_t           head;

        ao_alloc_block_body_t           body;
};

// ----------------------------------------------------------------------------

struct  ao_alloc_t
{
        union
        {
            ao_alloc_align_t            align;

            uint8_t                     store                   [AO_ALLOC_SIZE_STORE];
        };

        ao_alloc_block_t                end;
};

// ----------------------------------------------------------------------------

static  void *                          ao_acquire_3(           size_t s);

// ----------------------------------------------------------------------------

static  ao_alloc_block_t *              ao_alloc_block_allocate(size_t s);

static  ao_alloc_block_t *              ao_alloc_block_find(    size_t s);

static  void                            ao_alloc_block_free(    ao_alloc_block_t * b);

static  ao_alloc_block_t *              ao_alloc_block_merge(   ao_alloc_block_t * b);

static  ao_alloc_block_t *              ao_alloc_block_pop(     ao_uint_t l1, ao_uint_t l2);

static  void                            ao_alloc_block_push(    ao_alloc_block_t * b);

static  void                            ao_alloc_block_remove(  ao_alloc_block_t * b);

static  void                            ao_alloc_block_split(   size_t s, ao_alloc_block_t * b);

// ----------------------------------------------------------------------------

static  bool                            ao_alloc_list_is_empty( ao_alloc_list_t * l);

static  ao_alloc_list_node_t *          ao_alloc_list_pop(      ao_alloc_list_t * l);

static  void                            ao_alloc_list_push(     ao_alloc_list_t * l, ao_alloc_list_node_t * n);

static  void                            ao_alloc_list_remove(   ao_alloc_list_t * l, ao_alloc_list_node_t * n);

// ----------------------------------------------------------------------------

static  bool                            ao_release_3(           void * p);

// ----------------------------------------------------------------------------

static  bool                            ao_retain_3(            void * p);

// ----------------------------------------------------------------------------

static  ao_alloc_t                      ao_alloc;

// ----------------------------------------------------------------------------

#if     AO_ALLOC_ALLOCATED                                      ||  \
        AO_ALLOC_ALLOCATED_MAX

        size_t              volatile    ao_alloc_allocated;

#endif

#if     AO_ALLOC_ALLOCATED_MAX

        size_t              volatile    ao_alloc_allocated_max;

#endif

// ----------------------------------------------------------------------------

static  ao_uint_t                       ao_alloc_bitmap_l1;

static  ao_uint_t                       ao_alloc_bitmap_l2      [AO_ALLOC_L1_COUNT];

// ----------------------------------------------------------------------------

#if     AO_ALLOC_FREE                                           ||  \
        AO_ALLOC_FREE_MIN

        size_t              volatile    ao_alloc_free;

#endif

#if     AO_ALLOC_FREE_MIN

        size_t              volatile    ao_alloc_free_min;

#endif

// ----------------------------------------------------------------------------

static  ao_alloc_list_t                 ao_alloc_list           [AO_ALLOC_L1_COUNT] [AO_ALLOC_L2_COUNT];

// ----------------------------------------------------------------------------

void * ao_acquire_2(size_t s)
{
    // Notes.

    // Called by ao_acquire_1().

    // Asserted that s is greater than 0.


    // Variables.

    void * p;


    // Ready.

    p = ao_acquire_3(s);

#if AO_ACQUIRED

    ao_acquired_info.ptr = p;

    ao_acquired_info.result = p ? true : false;

    ao_acquired_info.size_body_requested = s;

    ao_acquired(&ao_acquired_info);

#endif

    return p;
}

void * ao_acquire_3(size_t s)
{
    // Notes.

    // Called by ao_acquire_2().

    // Asserted that s is greater than 0.


    // Variables.

    ao_alloc_block_t * B;

    void * p;

#if AO_ACQUIRED                                                         ||  \
    AO_ALLOC_ALLOCATED                                                  ||  \
    AO_ALLOC_ALLOCATED_MAX                                              ||  \
    AO_ALLOC_FREE                                                       ||  \
    AO_ALLOC_FREE_MIN

    size_t t1;

#endif

#if AO_ALLOC_ALLOCATED                                                  ||  \
    AO_ALLOC_ALLOCATED_MAX                                              ||  \
    AO_ALLOC_FREE                                                       ||  \
    AO_ALLOC_FREE_MIN

    size_t t2;

#endif

#if AO_ALLOC_ALLOCATED                                                  ||  \
    AO_ALLOC_ALLOCATED_MAX

    size_t t3;

#endif

#if AO_ALLOC_ALLOCATED_MAX

    size_t t4;

#endif

#if AO_ALLOC_FREE                                                       ||  \
    AO_ALLOC_FREE_MIN

    size_t t5;

#endif

#if AO_ALLOC_FREE_MIN

    size_t t6;

#endif


    // Ready.

    B = ao_alloc_block_allocate(s);


    // Block allocation succeeded.

    if (B)
    {
        B->head.ref = 1;

        p = &B->body;

#if AO_ACQUIRED                                                         ||  \
    AO_ALLOC_ALLOCATED                                                  ||  \
    AO_ALLOC_ALLOCATED_MAX                                              ||  \
    AO_ALLOC_FREE                                                       ||  \
    AO_ALLOC_FREE_MIN

        t1 = B->head.size_body;

#endif

#if AO_ACQUIRED

        ao_acquired_info.size_body = t1;

#endif

#if AO_ALLOC_ALLOCATED                                                  ||  \
    AO_ALLOC_ALLOCATED_MAX                                              ||  \
    AO_ALLOC_FREE                                                       ||  \
    AO_ALLOC_FREE_MIN

        t2 = AO_ALLOC_SIZE_BLOCK_HEAD + t1;

#endif

#if AO_ALLOC_ALLOCATED                                                  ||  \
    AO_ALLOC_ALLOCATED_MAX

        t3 = ao_alloc_allocated;

        t3 = t3 + t2;

        ao_alloc_allocated = t3;

#endif

#if AO_ALLOC_ALLOCATED_MAX

        t4 = ao_alloc_allocated_max;

        t4 = ao_max(t3, t4);

        ao_alloc_allocated_max = t4;

#endif

#if AO_ALLOC_FREE                                                       ||  \
    AO_ALLOC_FREE_MIN

        t5 = ao_alloc_free;

        ao_assert(t5 >= t2);

        t5 = t5 - t2;

        ao_alloc_free = t5;

#endif

#if AO_ALLOC_FREE_MIN

        t6 = ao_alloc_free_min;

        t6 = ao_min(t5, t6);

        ao_alloc_free_min = t6;

#endif

    }


    // Block allocation failed.

    else
    {
        p = NULL;
    }

    return p;
}

// ----------------------------------------------------------------------------

ao_alloc_block_t * ao_alloc_block_allocate(size_t s)
{
    // Notes.

    // Called by ao_acquire_3().

    // Asserted that s is greater than 0.


    // Variables.

    ao_alloc_block_t * B;


    // Ready.

    // The size of the block body must be large enough.

    // The size of the block body must be aligned.

    s = ao_max(s, AO_ALLOC_SIZE_BLOCK_BODY);

    s = ao_align_up(s, AO_ALLOC_ALIGN);


    // The size of the block body must not exceed the size of the entire store.

    if (s <= AO_ALLOC_SIZE_STORE)
    {
        B = ao_alloc_block_find(s);

        if (B)
        {
            ao_alloc_block_split(s, B);
        }
    }

    else
    {
        B = NULL;
    }

    return B;
}

ao_alloc_block_t * ao_alloc_block_find(size_t s)
{
    // Notes.

    // Called by ao_alloc_block_allocate().

    // Asserted that s >= AO_ALLOC_SIZE_BLOCK_BODY.

    // Asserted that s <= AO_ALLOC_SIZE_STORE.

    // Asserted that s is aligned.


    // Variables.

    ao_uint_t b;

    ao_alloc_block_t * B;

    size_t i1;

    ao_uint_t l1;

    ao_uint_t l2;

    ao_uint_t m;

    ao_uint_t t;


    // Ready.

    t = (ao_uint_t) s;

    t = t + (1 << (ao_fls(t) - AO_ALLOC_L2_COUNT_LOG)) - 1;

    l1 = ao_fls(t);

    l2 = (t >> (l1 - AO_ALLOC_L2_COUNT_LOG)) - (1 << AO_ALLOC_L2_COUNT_LOG);

    i1 = (size_t) (l1 - AO_ALLOC_L1_INDEX_MIN);

    m = AO_UINT_MAX << l2;

    b = ao_alloc_bitmap_l2[i1];

    b = b & m;

    if (b != 0)
    {
        l2 = ao_ffs(b);

        B = ao_alloc_block_pop(l1, l2);
    }

    else
    {
        m = AO_UINT_MAX << (l1 + 1);

        b = ao_alloc_bitmap_l1;

        b = b & m;

        if (b != 0)
        {
            l1 = ao_ffs(b);

            i1 = (size_t) (l1 - AO_ALLOC_L1_INDEX_MIN);

            b = ao_alloc_bitmap_l2[i1];

            l2 = ao_ffs(b);

            B = ao_alloc_block_pop(l1, l2);
        }

        else
        {
            B = NULL;
        }
    }

    return B;
}

void ao_alloc_block_free(ao_alloc_block_t * B)
{
    // Notes.

    // Called by ao_release_3().

    // Asserted that B is not NULL.


    // Ready.

    B = ao_alloc_block_merge(B);

    ao_alloc_block_push(B);
}

ao_alloc_block_t * ao_alloc_block_merge(ao_alloc_block_t * B2)
{
    // Notes.

    // Called by ao_alloc_block_free().

    // Asserted that B2 is not NULL.


    // Variables.

    ao_alloc_block_t * B1;

    ao_alloc_block_t * B3;

    ao_alloc_block_t * E = &ao_alloc.end;

    uint8_t * p;

    size_t t1;

    size_t t2;


    // Ready.

    B1 = B2->head.prev;

    t2 = B2->head.size_body;

    p = (uint8_t *) B2;

    p += AO_ALLOC_SIZE_BLOCK_HEAD;

    p += t2;

    B3 = (ao_alloc_block_t *) p;


    // B2 = Block to merge.

    // B1 = Left neighbor.

    // B3 = Right neighbor.

    // Left neighbor does exist.

    if (B1)
    {
        // Left neighbor is allocated.

        if (B1->head.ref)
        {
            B1 = B2;

            B2 = B3;

            t1 = t2;
        }

        // Left neighbor is free.

        else
        {
            ao_alloc_block_remove(B1);

            t1 = B1->head.size_body;

            t1 += AO_ALLOC_SIZE_BLOCK_HEAD;

            t1 += t2;

            B1->head.size_body = t1;

            B2 = B3;

            B2->head.prev = B1;
        }
    }

    // Left neighbor does not exist.

    else
    {
        B1 = B2;

        B2 = B3;

        t1 = t2;
    }


    // B1 = Block merged to the left.

    // B2 = Right neighbor.

    // Right neighbor does exist.

    if (B2 != E)
    {
        // Right neighbor is allocated.

        if (B2->head.ref) { }

        // Right neighbor is free.

        else
        {
            ao_alloc_block_remove(B2);

            t2 = B2->head.size_body;

            t1 += AO_ALLOC_SIZE_BLOCK_HEAD;

            t1 += t2;

            B1->head.size_body = t1;

            p += AO_ALLOC_SIZE_BLOCK_HEAD;

            p += t2;

            B3 = (ao_alloc_block_t *) p;

            B3->head.prev = B1;
        }
    }


    // B1 = Block merged both to the left and to the right.

    return B1;
}

ao_alloc_block_t * ao_alloc_block_pop(ao_uint_t l1, ao_uint_t l2)
{
    // Notes.

    // Called by ao_alloc_block_find().

    // Asserted that l1 >= AO_ALLOC_L1_INDEX_MIN.

    // Asserted that l1 <= AO_ALLOC_L1_INDEX_MAX.

    // Asserted that l2 <  AO_ALLOC_L2_COUNT.


    // Variables.

    ao_uint_t b;

    ao_alloc_block_t * B;

    size_t i1;

    size_t i2;

    ao_alloc_list_t * L;

    ao_alloc_list_node_t * N;


    // Ready.

    i1 = (size_t) (l1 - AO_ALLOC_L1_INDEX_MIN);

    i2 = (size_t) l2;

    L = &ao_alloc_list[i1][i2];

    N = ao_alloc_list_pop(L);

    B = ao_containerof(N, ao_alloc_block_t, body.node);

    if (ao_alloc_list_is_empty(L))
    {
        b = ao_alloc_bitmap_l2[i1];

        b = b & ~(1 << l2);

        ao_alloc_bitmap_l2[i1] = b;

        if (b == 0)
        {
            b = ao_alloc_bitmap_l1;

            b = b & ~(1 << l1);

            ao_alloc_bitmap_l1 = b;
        }
    }

    return B;
}

void ao_alloc_block_push(ao_alloc_block_t * B)
{
    // Notes.

    // Called by ao_alloc_block_free().

    // Called by ao_alloc_block_split().

    // Called by ao_boot_alloc().

    // Asserted that B is not NULL.


    // Variables.

    ao_uint_t b;

    size_t i1;

    size_t i2;

    ao_alloc_list_t * L;

    ao_uint_t l1;

    ao_uint_t l2;

    ao_uint_t m;

    ao_alloc_list_node_t * N;

    ao_uint_t s;

    size_t t;


    // Ready.

    t = B->head.size_body;

    s = (ao_uint_t) t;

    l1 = ao_fls(s);

    l2 = (s >> (l1 - AO_ALLOC_L2_COUNT_LOG)) - (1 << AO_ALLOC_L2_COUNT_LOG);

    i1 = (size_t) (l1 - AO_ALLOC_L1_INDEX_MIN);

    i2 = (size_t) (l2);

    N = &B->body.node;

    L = &ao_alloc_list[i1][i2];

    ao_alloc_list_push(L, N);

    m = 1 << l1;

    b = ao_alloc_bitmap_l1;

    b = b | m;

    ao_alloc_bitmap_l1 = b;

    m = 1 << l2;

    b = ao_alloc_bitmap_l2[i1];

    b = b | m;

    ao_alloc_bitmap_l2[i1] = b;
}

void ao_alloc_block_remove(ao_alloc_block_t * B)
{
    // Notes.

    // Called by ao_alloc_block_merge().

    // Asserted that B is not NULL.


    // Variables.

    ao_uint_t b;

    size_t i1;

    size_t i2;

    ao_alloc_list_t * L;

    ao_uint_t l1;

    ao_uint_t l2;

    ao_uint_t m;

    ao_alloc_list_node_t * N;

    ao_uint_t s;

    size_t t;


    // Ready.

    t = B->head.size_body;

    s = (ao_uint_t) t;

    l1 = ao_fls(s);

    l2 = (s >> (l1 - AO_ALLOC_L2_COUNT_LOG)) - (1 << AO_ALLOC_L2_COUNT_LOG);

    i1 = (size_t) (l1 - AO_ALLOC_L1_INDEX_MIN);

    i2 = (size_t) (l2);

    N = &B->body.node;

    L = &ao_alloc_list[i1][i2];

    ao_alloc_list_remove(L, N);

    if (ao_alloc_list_is_empty(L))
    {
        m = 1 << l2;

        b = ao_alloc_bitmap_l2[i1];

        b = b & ~m;

        ao_alloc_bitmap_l2[i1] = b;

        if (b == 0)
        {
            m = 1 << l1;

            b = ao_alloc_bitmap_l1;

            b = b & ~m;

            ao_alloc_bitmap_l1 = b;
        }
    }
}

void ao_alloc_block_split(size_t s, ao_alloc_block_t * B1)
{
    // Notes.

    // Called by ao_alloc_block_allocate().


    // Variables.

    ao_alloc_block_t * B2;

    ao_alloc_block_t * B3;

    uint8_t * p;

    size_t t1;

    size_t t2;

    size_t t3;


    // Ready.

    t1 = B1->head.size_body;

    ao_assert(t1 >= s);

    t2 = t1 - s;

    if (t2 >= AO_ALLOC_SIZE_BLOCK)
    {
        t1 = s;

        t3 = t2 - AO_ALLOC_SIZE_BLOCK_HEAD;

        p = (uint8_t *) B1;

        p += AO_ALLOC_SIZE_BLOCK_HEAD;

        p += t1;

        B2 = (ao_alloc_block_t *) p;

        B2->head.prev = B1;

        B2->head.ref = 0;

        B2->head.size_body = t3;

        ao_alloc_block_push(B2);

        B1->head.size_body = t1;

        p += AO_ALLOC_SIZE_BLOCK_HEAD;

        p += t3;

        B3 = (ao_alloc_block_t *) p;

        B3->head.prev = B2;
    }
}

// ----------------------------------------------------------------------------

bool ao_alloc_list_is_empty(ao_alloc_list_t * l)
{
    return l->front == NULL;
}

ao_alloc_list_node_t * ao_alloc_list_pop(ao_alloc_list_t * l)
{
    // Variables.

    ao_alloc_list_node_t * n1;

    ao_alloc_list_node_t * n2;


    // Ready.

    n1 = l->front;

    n2 = n1->next;

    if (n2 != NULL)
    {
        n2->prev = NULL;
    }

    l->front = n2;

    return n1;
}

void ao_alloc_list_push(ao_alloc_list_t * l, ao_alloc_list_node_t * n1)
{
    // Variables.

    ao_alloc_list_node_t * n2;


    // Ready.

    n2 = l->front;

    if (n2 != NULL)
    {
        n2->prev = n1;
    }

    n1->prev = NULL;

    n1->next = n2;

    l->front = n1;
}

void ao_alloc_list_remove(ao_alloc_list_t * l, ao_alloc_list_node_t * n2)
{
    // Variables.

    ao_alloc_list_node_t * n1;

    ao_alloc_list_node_t * n3;


    // Ready.

    n1 = n2->prev;

    n3 = n2->next;

    if (n1 == NULL)
    {
        l->front = n3;
    }

    else
    {
        n1->next = n3;
    }

    if (n3 != NULL)
    {
        n3->prev = n1;
    }
}

// ----------------------------------------------------------------------------

void ao_boot_alloc()
{
    // Assert.

    ao_assert(AO_ALLOC_SEGREGATION >= AO_ALLOC_SEGREGATION_MIN);

    ao_assert(AO_ALLOC_SEGREGATION <= AO_ALLOC_SEGREGATION_MAX);


    // Assert.

    ao_assert(AO_ALLOC_SIZE_STORE >= 0);

    ao_assert(AO_ALLOC_SIZE_STORE <= AO_UINT_MAX);


    // Assert.

    ao_assert(ao_is_aligned(AO_ALLOC_SIZE_BLOCK, AO_ALLOC_ALIGN));

    ao_assert(ao_is_aligned(AO_ALLOC_SIZE_BLOCK_BODY, AO_ALLOC_ALIGN));

    ao_assert(ao_is_aligned(AO_ALLOC_SIZE_BLOCK_HEAD, AO_ALLOC_ALIGN));


    // Assert.

    ao_assert(!ao_booted_alloc);


    // Variables.

    ao_alloc_block_t * B;

    ao_alloc_block_t * E;

    size_t s;


    // Ready.

#if AO_ACQUIRED

    ao_acquired_info.size_head = AO_ALLOC_SIZE_BLOCK_HEAD;

#endif

#if AO_RELEASED

    ao_released_info.size_head = AO_ALLOC_SIZE_BLOCK_HEAD;

#endif

#if AO_RETAINED

    ao_retained_info.size_head = AO_ALLOC_SIZE_BLOCK_HEAD;

#endif


    // Ready.

#if AO_ALLOC_FREE                                                       ||  \
    AO_ALLOC_FREE_MIN

    ao_alloc_free = AO_ALLOC_SIZE_STORE;

#endif

#if AO_ALLOC_FREE_MIN

    ao_alloc_free_min = AO_ALLOC_SIZE_STORE;

#endif


    // Ready.

    E = &ao_alloc.end;

    E->head.size_body = AO_ALLOC_SIZE_BLOCK_BODY;

    if (AO_ALLOC_SIZE_STORE >= AO_ALLOC_SIZE_BLOCK)
    {
        B = (ao_alloc_block_t *) ao_alloc.store;

        s = AO_ALLOC_SIZE_STORE - AO_ALLOC_SIZE_BLOCK_HEAD;

        ao_assert(s);

        ao_assert(ao_is_aligned(s, AO_ALLOC_ALIGN));

        E->head.prev = B;

        B->head.size_body = s;

        ao_alloc_block_push(B);
    }


    // Ready.

    ao_booted_alloc = true;
}

// ----------------------------------------------------------------------------

bool ao_release_2(void * p)
{
    // Notes.

    // Called by ao_release_1().

    // Asserted that p is not NULL.


    // Variables.

    bool r;


    // Ready.

    r = ao_release_3(p);

#if AO_RELEASED

    ao_released_info.ptr = p;

    ao_released_info.result = r;

    ao_released(&ao_released_info);

#endif

    return r;
}

bool ao_release_3(void * p)
{
    // Notes.

    // Called by ao_release_2().

    // Asserted that p is not NULL.


    // Variables.

    ao_alloc_block_t * B;

    bool r;

    ao_uint_t R;

#if AO_ALLOC_ALLOCATED                                                  ||  \
    AO_ALLOC_ALLOCATED_MAX                                              ||  \
    AO_ALLOC_FREE                                                       ||  \
    AO_ALLOC_FREE_MIN                                                   ||  \
    AO_RELEASED

    size_t t1;

#endif

#if AO_ALLOC_ALLOCATED                                                  ||  \
    AO_ALLOC_ALLOCATED_MAX                                              ||  \
    AO_ALLOC_FREE                                                       ||  \
    AO_ALLOC_FREE_MIN

    size_t t2;

#endif


    // Ready.

    B = ao_containerof(p, ao_alloc_block_t, body);

    R = B->head.ref;

#if AO_ALLOC_ALLOCATED                                                  ||  \
    AO_ALLOC_ALLOCATED_MAX                                              ||  \
    AO_ALLOC_FREE                                                       ||  \
    AO_ALLOC_FREE_MIN                                                   ||  \
    AO_RELEASED

    t1 = B->head.size_body;

#endif


    // Reference counter is 0.

    if (R == 0)
    {
        r = false;
    }


    // Reference counter is greater than 0.

    else
    {
        R--;

        B->head.ref = R;


        // Reference counter is 0.

        // Release block.

        if (R == 0)
        {
            ao_alloc_block_free(B);

            r = true;

#if AO_ALLOC_ALLOCATED                                                  ||  \
    AO_ALLOC_ALLOCATED_MAX                                              ||  \
    AO_ALLOC_FREE                                                       ||  \
    AO_ALLOC_FREE_MIN

            t2 = AO_ALLOC_SIZE_BLOCK_HEAD + t1;

#endif

#if AO_ALLOC_ALLOCATED                                                  ||  \
    AO_ALLOC_ALLOCATED_MAX

            ao_assert(ao_alloc_allocated >= t2);

            ao_alloc_allocated -= t2;

#endif

#if AO_ALLOC_FREE                                                       ||  \
    AO_ALLOC_FREE_MIN

            ao_alloc_free += t2;

#endif

        }


        // Reference counter is still greater than 0.

        else
        {
            r = false;
        }
    }

#if AO_RELEASED

    ao_released_info.ref = R;

    ao_released_info.size_body = t1;

#endif

    return r;
}

// ----------------------------------------------------------------------------

bool ao_retain_2(void * p)
{
    // Notes.

    // Called by ao_retain_1().

    // Asserted that p is not NULL.


    // Variables.

    bool r;


    // Ready.

    r = ao_retain_3(p);

#if AO_RETAINED

    ao_retained_info.ptr = p;

    ao_retained_info.result = r;

    ao_retained(&ao_retained_info);

#endif

    return r;
}

bool ao_retain_3(void * p)
{
    // Notes.

    // Called by ao_retain_2().

    // Asserted that p is not NULL.


    // Variables.

    ao_alloc_block_t * B;

    bool r;

    ao_uint_t R;


    // Ready.

    B = ao_containerof(p, ao_alloc_block_t, body);

    R = B->head.ref;


    // Reference counter is 0.

    if (R == 0)
    {
        r = false;
    }


    // Reference counter is greater than 0.

    else
    {
        R++;

        ao_assert(R > 0);

        B->head.ref = R;

        r = true;
    }

#if AO_RETAINED

    ao_retained_info.ref = R;

    ao_retained_info.size_body = B->head.size_body;

#endif

    return r;
}

// ----------------------------------------------------------------------------

#endif

#if defined AO_ARE

// ----------------------------------------------------------------------------

void ao_are_clear(ao_are_t * A)
{
    // Assert.

    ao_assert(A);


    // Variables.

    ao_lock_t L;


    // Ready.

    ao_lock(&L);
    {
        ao_assert(!A->state || ao_list_is_empty(&A->list));

        A->state = false;
    }
    ao_unlock(&L);
}

void ao_are_set(ao_are_t * A)
{
    // Assert.

    ao_assert(A);


    // Variables.

    ao_lock_t L;

    ao_list_node_t * n;

    ao_are_wait_t * W;


    // Ready.

    ao_lock(&L);
    {
        // Auto-reset event is set already.

        if (A->state)
        {
            ao_assert(ao_list_is_empty(&A->list));
        }

        // Auto-reset event is clear.

        else
        {
            // There are waiting tasks.

            n = A->list.front;

            if (n)
            {
                W = ao_containerof(n, ao_are_wait_t, node);

                ao_list_remove_front(&A->list);

                W->result = true;

                ao_async_check(&W->async);
            }

            // There are no waiting tasks.

            else
            {
                A->state = true;
            }
        }
    }
    ao_unlock(&L);
}

// ----------------------------------------------------------------------------

bool ao_are_wait(ao_are_t * A, ao_time_t t)
{
    return ao_are_wait_from(A, t, ao_now());
}

void ao_are_wait_begin(ao_are_wait_t * W)
{
    // Assert.

    ao_assert(W);

    ao_assert(W->are);


    // Variables.

    ao_are_t * A;

    ao_lock_t L;


    // Ready.

    A = W->are;

    ao_async_begin(&W->async);

    ao_lock(&L);
    {
        // Auto-reset event is set.

        if (A->state)
        {
            ao_assert(ao_list_is_empty(&A->list));

            A->state = false;

            W->result = true;

            ao_async_check(&W->async);
        }

        // Auto-reset event is clear.

        else
        {
            ao_list_push_back(&W->are->list, &W->node);

            W->result = false;
        }
    }
    ao_unlock(&L);
}

void ao_are_wait_end(ao_are_wait_t * W)
{
    // Assert.

    ao_assert(W);

    ao_assert(W->are);


    // Variables.

    ao_lock_t L;


    // Ready.

    ao_lock(&L);
    {
        if (W->result) { }

        else
        {
            ao_list_remove(&W->are->list, &W->node);
        }
    }
    ao_unlock(&L);

    ao_async_end(&W->async);
}

bool ao_are_wait_forever(ao_are_t * A)
{
    return ao_are_wait_from(A, AO_INFINITY, 0);
}

bool ao_are_wait_from(ao_are_t * A, ao_time_t t, ao_time_t b)
{
    // Variables.

    ao_are_wait_t W;


    // Ready.

    ao_clear(&W, ao_are_wait_t);

    W.are = A;


    ao_are_wait_begin(&W);

    ao_await_from(&W.async, t, b);

    ao_are_wait_end(&W);


    return W.result;
}

bool ao_are_wait_try(ao_are_t * A)
{
    // Variables.

    ao_are_wait_t W;


    // Ready.

    ao_clear(&W, ao_are_wait_t);

    W.are = A;


    ao_are_wait_begin(&W);

    ao_are_wait_end(&W);


    return W.result;
}

// ----------------------------------------------------------------------------

#endif

#if defined AO_ASYNC

// ----------------------------------------------------------------------------

static void ao_async_all_checked(void * x);

static void ao_async_any_checked(void * x);

// ----------------------------------------------------------------------------

void ao_async_begin(ao_async_t * A)
{
    // Notes.

    // The caller must have exclusive access to #A.


    // Ready.

    ao_assert(A);

    A->checked = false;
}

void ao_async_check(ao_async_t * A)
{
    // Notes.

    // The kernel must be locked.


    // Assert.

    ao_assert(A);


    // Variables.

    ao_proc_t C;


    // Ready.

    if (A->checked) { }

    else
    {
        C = A->callback;

        if (C)
        {
            C(A->callback_parameter);
        }

        A->checked = true;
    }
}

bool ao_async_checked(ao_async_t const * A)
{
    // Assert.

    ao_assert(A);


    // Variables.

    bool c1;

    bool c2;


    // Ready.

    do
    {
        c1 = A->checked;

        c2 = A->checked;
    }
    while (c1 != c2);

    return c1;
}

void ao_async_end(ao_async_t * A)
{
    // Notes.

    // The caller must have exclusive access to #A.


    // Ready.

    ao_assert(A);
}

// ----------------------------------------------------------------------------

void ao_async_all_begin(ao_async_all_t * ALL)
{
    // Notes.

    // The kernel is not locked.


    // Assert.

    ao_assert(ALL);

    ao_assert(ALL->count == 0 || ALL->store);


    // Variables.

    ao_async_t * A;

    ao_async_t ** B;

    size_t c1;

    size_t c2;

    ao_async_t ** E;

    ao_lock_t L;

    ao_async_t ** P;

    bool r;


    // Ready.

    // The caller has exclusive access to #ALL and its async.

    // Therefore, we can safely access both without locking the kernel.

    ao_async_begin(&ALL->async);

    c1 = ALL->count;

    if (c1 == 0)
    {
        r = true;
    }

    else
    {
        c2 = 0;

        B = ALL->store;

        E = B + (ptrdiff_t) c1;

        // The caller does not have exclusive access to its subordinated asyncs in its store.

        // This is, because the caller has begun the subordinate asyncs.

        // Consequently, another thread of execution could kick in at all time and check any one of them.

        // See #ao_async_check().

        // Therefore, we must lock the kernel.

        ao_lock(&L);
        {
            // Check if all subordinated async are checked already.

            for (P = B; P < E; P++)
            {
                A = *P;

                ao_assert(A);

                if (A->checked)
                {
                    c2++;
                }

                else
                {
                    A->callback = ao_async_all_checked;

                    A->callback_parameter = ALL;
                }
            }

            // All subordinated asyncs are checked.

            ao_assert(c2 <= c1);

            if (c1 == c2)
            {
                r = true;
            }

            // At least one subordinated async is not checked.

            else
            {
                r = false;

                ALL->count_checked = c2;

                ALL->result = false;
            }
        }
        ao_unlock(&L);
    }

    // Either there are no subordinated asyncs or all of them are checked already.

    // In either case, no callback has been set, so the caller still has exclusive access to #ALL.

    if (r)
    {
        ALL->count_checked = c1;

        ALL->result = true;

        ao_async_check(&ALL->async);
    }
}

void ao_async_all_checked(void * x)
{
    // Notes.

    // This function is an async callback.

    // This function is called by the ao_async_check() function.

    // The kernel is locked.


    // Assert.

    ao_assert(x);


    // Variables.

    ao_async_t * A;

    ao_async_all_t * ALL = x;

    size_t c1;

    size_t c2;

    ao_async_t ** E;

    ao_async_t ** P;


    // Ready.

    c1 = ALL->count;

    c2 = ALL->count_checked;

    ao_assert(c2 < c1);

    c2++;

    if (c1 == c2)
    {
        P = ALL->store;

        E = P + (ptrdiff_t) c1;

        for (; P < E; P++)
        {
            A = *P;

            A->callback = NULL;

            A->callback_parameter = NULL;
        }

        ALL->result = true;

        ao_async_check(&ALL->async);
    }

    ALL->count_checked = c2;
}

void ao_async_all_end(ao_async_all_t * ALL)
{
    // Notes.

    // The kernel is not locked.


    // Assert.

    ao_assert(ALL);


    // Variables.

    ao_async_t * A;

    ao_async_t ** E;

    ao_lock_t L;

    ao_async_t ** P;


    // Ready.

    // The subordinated asyncs might not have been ended.

    // That is, another thread of execution could kick in at all time.

    // Eventually, this would invoke the ao_async_all_checked() callback, that manipulates #ALL.

    // Therefore, we must lock the kernel.

    ao_lock(&L);
    {
        if (ALL->result) { }

        else
        {
            P = ALL->store;

            E = P + (ptrdiff_t) ALL->count;

            for (; P < E; P++)
            {
                A = *P;

                A->callback = NULL;

                A->callback_parameter = NULL;
            }
        }
    }
    ao_unlock(&L);

    // The caller has gained exclusive access to #ALL again.

    ao_async_end(&ALL->async);
}

void ao_async_all_try(ao_async_all_t * ALL)
{
    ao_async_all_begin(ALL);

    ao_async_all_end(ALL);
}

// ----------------------------------------------------------------------------

void ao_async_any_begin(ao_async_any_t * ANY)
{
    // Notes.

    // The kernel is not locked.


    // Assert.

    ao_assert(ANY);

    ao_assert(ANY->count == 0 || ANY->store);


    // Variables.

    ao_async_t * A;

    ao_async_t ** B;

    size_t c;

    ao_async_t ** E;

    ao_lock_t L;

    ao_async_t ** P;

    bool r;


    // Ready.

    // The caller has exclusive access to #ANY and its async.

    // Therefore, we can safely access both without locking the kernel.

    ao_async_begin(&ANY->async);

    c = ANY->count;

    if (c == 0)
    {
        r = true;
    }

    else
    {
        r = false;

        B = ANY->store;

        E = B + (ptrdiff_t) c;

        // The caller does not have exclusive access to its subordinated asyncs in its store.

        // This is, because the caller has begun the subordinate asyncs.

        // Consequently, another thread of execution could kick in at any time and check any one of them.

        // See #ao_async_check().

        // Therefore, we must lock the kernel.

        ao_lock(&L);
        {
            // Check if any subordinated async is checked already.

            P = B;

            do
            {
                A = *P;

                ao_assert(A);

                if (A->checked)
                {
                    r = true;
                }

                else
                {
                    P++;
                }
            }
            while (!r && P < E);

            // At least one subordinated async is checked.

            if (r) { }

            // No subordinated async is checked.

            else
            {
                ANY->result = false;

                for (P = B; P < E; P++)
                {
                    A = *P;

                    A->callback = ao_async_any_checked;

                    A->callback_parameter = ANY;
                }
            }
        }
        ao_unlock(&L);
    }

    // Either there are no subordinated asyncs or at least one of them is checked already.

    // In either case, no callback has been set, so the caller still has exclusive access to #ANY.

    if (r)
    {
        ANY->result = true;

        ao_async_check(&ANY->async);
    }
}

void ao_async_any_checked(void * x)
{
    // Notes.

    // This function is an async callback.

    // This function is called by the ao_async_check() function.

    // The kernel is locked.


    // Assert.

    ao_assert(x);


    // Variables.

    ao_async_t * A;

    ao_async_any_t * ANY = x;

    ao_async_t ** E;

    ao_async_t ** P;


    // Ready.

    P = ANY->store;

    E = P + (ptrdiff_t) ANY->count;

    for (; P < E; P++)
    {
        A = *P;

        A->callback = NULL;

        A->callback_parameter = NULL;
    }

    ANY->result = true;

    ao_async_check(&ANY->async);
}

void ao_async_any_end(ao_async_any_t * ANY)
{
    // Notes.

    // The kernel is not locked.


    // Assert.

    ao_assert(ANY);


    // Variables.

    ao_async_t * A;

    ao_async_t ** E;

    ao_lock_t L;

    ao_async_t ** P;


    // Ready.

    // The subordinated asyncs might not have been ended.

    // That is, another thread of execution could kick in at any time.

    // Eventually, this would invoke the ao_async_any_checked() callback, that manipulates #ANY.

    // Therefore, we must lock the kernel.

    ao_lock(&L);
    {
        if (ANY->result) { }

        else
        {
            P = ANY->store;

            E = P + (ptrdiff_t) ANY->count;

            for (; P < E; P++)
            {
                A = *P;

                A->callback = NULL;

                A->callback_parameter = NULL;
            }
        }
    }
    ao_unlock(&L);

    // The caller has gained exclusive access to #ANY again.

    ao_async_end(&ANY->async);
}

void ao_async_any_try(ao_async_any_t * ANY)
{
    ao_async_any_begin(ANY);

    ao_async_any_end(ANY);
}

// ----------------------------------------------------------------------------

#endif

#if defined AO_AWAIT

// ----------------------------------------------------------------------------

static void ao_await_checked(void * x);

// ----------------------------------------------------------------------------

void ao_await(ao_async_t * A, ao_time_t t)
{
    ao_await_from(A, t, ao_now());
}

void ao_await_checked(void * x)
{
    // Notes.

    // This function is an async callback.

    // This function is called by the ao_async_check() function.

    // The kernel is locked.


    // Ready.

    ao_task_t * T = x;

    ao_task_unblock(T);
}

void ao_await_forever(ao_async_t * A)
{
    ao_await_from(A, AO_INFINITY, 0);
}

void ao_await_from(ao_async_t * A, ao_time_t t, ao_time_t b)
{
    // Assert.

    ao_assert(A);


    // Variables.

    ao_block_t B;

    ao_lock_t L;

    bool r;

    ao_task_t * T;


    // Ready.

    // Block.

    // The caller has begun the async.

    // That is, another thread of execution could kick in at any time in order to check the async and try to execute its callback.

    // See #ao_async_check().

    // Therefore, we must lock the kernel in order to safely set the callback.

    // Also, blocking requires the kernel to be locked, too.

    ao_lock(&L);
    {
        if (A->checked)
        {
            r = false;
        }

        else
        {
            r = true;

            T = ao_self_locked();

            A->callback = ao_await_checked;

            A->callback_parameter = T;

            ao_clear(&B, ao_block_t);

            B.beginning = b;

            B.timeout = t;

            ao_block(&B);
        }
    }
    ao_unlock(&L);

    if (r)
    {
        // Blocking.

        while (ao_task_is_blocking(T)) { }


        // Ready.

        // The async might not be checked, yet.

        // That is, another thread of execution could kick in at any time in order to check the async and try to execute its callback.

        // See #ao_async_check().

        // Therefore, we must lock the kernel in order to safely remove the callback.

        ao_lock(&L);
        {
            A->callback = NULL;

            A->callback_parameter = NULL;
        }
        ao_unlock(&L);
    }
}

// ----------------------------------------------------------------------------

void ao_await_all(ao_async_all_t * ALL, ao_time_t t)
{
    ao_await_all_from(ALL, t, ao_now());
}

void ao_await_all_forever(ao_async_all_t * ALL)
{
    ao_await_all_from(ALL, AO_INFINITY, 0);
}

void ao_await_all_from(ao_async_all_t * ALL, ao_time_t t, ao_time_t b)
{
    // Assert.

    ao_assert(ALL);


    // Ready.

    ao_async_all_begin(ALL);

    ao_await_from(&ALL->async, t, b);

    ao_async_all_end(ALL);
}

// ----------------------------------------------------------------------------

void ao_await_any(ao_async_any_t * ANY, ao_time_t t)
{
    ao_await_any_from(ANY, t, ao_now());
}

void ao_await_any_forever(ao_async_any_t * ANY)
{
    ao_await_any_from(ANY, AO_INFINITY, 0);
}

void ao_await_any_from(ao_async_any_t * ANY, ao_time_t t, ao_time_t b)
{
    // Assert.

    ao_assert(ANY);


    // Ready.

    ao_async_any_begin(ANY);

    ao_await_from(&ANY->async, t, b);

    ao_async_any_end(ANY);
}

// ----------------------------------------------------------------------------

#endif

#if defined AO_BARRIER

// ----------------------------------------------------------------------------

bool ao_barrier_wait(ao_barrier_t * B, ao_time_t t)
{
    return ao_barrier_wait_from(B, t, ao_now());
}

void ao_barrier_wait_begin(ao_barrier_wait_t * W)
{
    // Assert.

    ao_assert(W);

    ao_assert(W->barrier);


    // Variables.

    ao_barrier_t * B;

    ao_uint_t c1;

    ao_uint_t c2;

    ao_lock_t L;

    ao_list_node_t * n;


    // Ready.

    B = W->barrier;

    ao_async_begin(&W->async);

    ao_lock(&L);
    {
        c1 = B->count;

        c2 = B->count_threshold;

        ao_assert(c1 < c2);

        c1++;

        if (c1 == c2)
        {
            B->count = 0;

            W->result = true;

            ao_async_check(&W->async);

            n = B->list.front;

            while (n)
            {
                W = ao_containerof(n, ao_barrier_wait_t, node);

                n = n->next;

                ao_list_remove_front(&B->list);

                W->result = true;

                ao_async_check(&W->async);
            }
        }

        else
        {
            B->count = c1;

            W->result = false;

            ao_list_push_back(&B->list, &W->node);
        }
    }
    ao_unlock(&L);
}

void ao_barrier_wait_end(ao_barrier_wait_t * W)
{
    // Assert.

    ao_assert(W);


    // Variables.

    ao_barrier_t * B;

    ao_lock_t L;


    // Ready.

    ao_lock(&L);
    {
        if (W->result) { }

        else
        {
            B = W->barrier;

            ao_assert(B->count > 0);

            B->count--;

            ao_list_remove(&B->list, &W->node);
        }
    }
    ao_unlock(&L);

    ao_async_end(&W->async);
}

bool ao_barrier_wait_forever(ao_barrier_t * B)
{
    return ao_barrier_wait_from(B, AO_INFINITY, 0);
}

bool ao_barrier_wait_from(ao_barrier_t * B, ao_time_t t, ao_time_t b)
{
    // Variables.

    ao_barrier_wait_t W;


    // Ready.

    ao_clear(&W, ao_barrier_wait_t);

    W.barrier = B;


    ao_barrier_wait_begin(&W);

    ao_await_from(&W.async, t, b);

    ao_barrier_wait_end(&W);


    return W.result;
}

bool ao_barrier_wait_try(ao_barrier_t * B)
{
    // Variables.

    ao_barrier_wait_t W;


    // Ready.

    ao_clear(&W, ao_barrier_wait_t);

    W.barrier = B;


    ao_barrier_wait_begin(&W);

    ao_barrier_wait_end(&W);


    return W.result;
}

// ----------------------------------------------------------------------------

#endif

#if defined AO_BLOCK

// ----------------------------------------------------------------------------

static void ao_block_callback(void * x);

// ----------------------------------------------------------------------------

void ao_block(ao_block_t * b)
{
    // Notes.

    // The kernel is locked.


    // Assert.

    ao_assert(ao_booted_task);

    ao_assert(b);


    // Variables.

    ao_alarm_t * a;

    ao_task_t * t;


    // Ready.

    t = ao_self_locked();

    if (b->timeout != AO_INFINITY)
    {
        a = &b->alarm;

        a->callback = ao_block_callback;

        a->callback_parameter = t;

        ao_alarm_start_from
        (
            a,
            b->timeout,
            b->beginning
        );
    }

#if AO_TASK_COUNT

    t->count.block++;

#endif

    t->block = b;

    ao_task_pend(t, AO_TASK_BLOCKING);
}

void ao_block_callback(void * x)
{
    // Notes.

    // This is an alarm callback.

    // The kernel is not locked.


    // Ready.

    ao_task_t * t = x;

    ao_task_wake(t);
}

// ----------------------------------------------------------------------------

#endif

#if defined AO_BSEM

// ----------------------------------------------------------------------------

void ao_bsem_give(ao_bsem_t * S)
{
    // Assert.

    ao_assert(S);


    // Variables.

    ao_lock_t L;

    ao_list_node_t * n;

    ao_bsem_take_t * T;


    // Ready.

    ao_lock(&L);
    {
        if (S->taken)
        {
            n = S->list.front;

            if (n)
            {
                ao_list_remove_front(&S->list);

                T = ao_containerof(n, ao_bsem_take_t, node);

                T->result = true;

                ao_async_check(&T->async);
            }

            else
            {
                S->taken = false;
            }
        }
    }
    ao_unlock(&L);
}

// ----------------------------------------------------------------------------

bool ao_bsem_take(ao_bsem_t * S, ao_time_t t)
{
    return ao_bsem_take_from(S, t, ao_now());
}

void ao_bsem_take_begin(ao_bsem_take_t * T)
{
    // Assert.

    ao_assert(T);

    ao_assert(T->sem);


    // Variables.

    ao_lock_t L;

    ao_bsem_t * S;


    // Ready.

    S = T->sem;

    ao_async_begin(&T->async);

    ao_lock(&L);
    {
        // Semaphore is not available.

        if (S->taken)
        {
            ao_list_push_back(&S->list, &T->node);

            T->result = false;
        }

        // Semaphore is available.

        else
        {
            S->taken = true;

            T->result = true;

            ao_async_check(&T->async);
        }
    }
    ao_unlock(&L);
}

void ao_bsem_take_end(ao_bsem_take_t * T)
{
    // Assert.

    ao_assert(T);

    ao_assert(T->sem);


    // Variables.

    ao_lock_t L;


    // Ready.

    ao_lock(&L);
    {
        if (T->result) { }

        else
        {
            ao_list_remove(&T->sem->list, &T->node);
        }
    }
    ao_unlock(&L);

    ao_async_end(&T->async);
}

bool ao_bsem_take_forever(ao_bsem_t * S)
{
    return ao_bsem_take_from(S, AO_INFINITY, 0);
}

bool ao_bsem_take_from(ao_bsem_t * S, ao_time_t t, ao_time_t b)
{
    // Variables.

    ao_bsem_take_t T;


    // Ready.

    ao_clear(&T, ao_bsem_take_t);

    T.sem = S;


    ao_bsem_take_begin(&T);

    ao_await_from(&T.async, t, b);

    ao_bsem_take_end(&T);


    return T.result;
}

bool ao_bsem_take_try(ao_bsem_t * S)
{
    // Variables.

    ao_bsem_take_t T;


    // Ready.

    ao_clear(&T, ao_bsem_take_t);

    T.sem = S;


    ao_bsem_take_begin(&T);

    ao_bsem_take_end(&T);


    return T.result;
}

// ----------------------------------------------------------------------------

#endif

#if defined AO_COND

// ----------------------------------------------------------------------------

void ao_cond_clear(ao_cond_t * C)
{
    // Assert.

    ao_assert(C);


    // Variables.

    ao_lock_t L;


    // Ready.

    ao_lock(&L);
    {
        ao_assert(!C->state || ao_list_is_empty(&C->list));

        C->state = false;
    }
    ao_unlock(&L);
}

void ao_cond_set(ao_cond_t * C)
{
    // Assert.

    ao_assert(C);


    // Variables.

    ao_lock_t L;

    ao_list_node_t * n;

    ao_cond_wait_t * W;


    // Ready.

    ao_lock(&L);
    {
        // Condition variable is set already.

        if (C->state)
        {
            ao_assert(ao_list_is_empty(&C->list));
        }

        // Condition variable is clear.

        else
        {
            C->state = true;

            n = C->list.front;

            while (n)
            {
                W = ao_containerof(n, ao_cond_wait_t, node);

                n = n->next;

                ao_list_remove_front(&C->list);

                W->result = true;

                ao_async_check(&W->async);
            }
        }
    }
    ao_unlock(&L);
}

// ----------------------------------------------------------------------------

bool ao_cond_wait(ao_cond_t * C, ao_time_t t)
{
    return ao_cond_wait_from(C, t, ao_now());
}

void ao_cond_wait_begin(ao_cond_wait_t * W)
{
    // Assert.

    ao_assert(W);

    ao_assert(W->cond);


    // Variables.

    ao_cond_t * C;

    ao_lock_t L;


    // Ready.

    C = W->cond;

    ao_async_begin(&W->async);

    ao_lock(&L);
    {
        // Condition variable is set.

        if (C->state)
        {
            ao_assert(ao_list_is_empty(&C->list));

            W->result = true;

            ao_async_check(&W->async);
        }

        // Condition variable is clear.

        else
        {
            W->result = false;

            ao_list_push_back(&C->list, &W->node);
        }
    }
    ao_unlock(&L);
}

void ao_cond_wait_end(ao_cond_wait_t * W)
{
    // Assert.

    ao_assert(W);

    ao_assert(W->cond);


    // Variables.

    ao_lock_t L;


    // Ready.

    ao_lock(&L);
    {
        if (W->result) { }

        else
        {
            ao_list_remove(&W->cond->list, &W->node);
        }
    }
    ao_unlock(&L);

    ao_async_end(&W->async);
}

bool ao_cond_wait_forever(ao_cond_t * C)
{
    return ao_cond_wait_from(C, AO_INFINITY, 0);
}

bool ao_cond_wait_from(ao_cond_t * C, ao_time_t t, ao_time_t b)
{
    // Variables.

    ao_cond_wait_t W;


    // Ready.

    ao_clear(&W, ao_cond_wait_t);

    W.cond = C;


    ao_cond_wait_begin(&W);

    ao_await_from(&W.async, t, b);

    ao_cond_wait_end(&W);


    return W.result;
}

bool ao_cond_wait_try(ao_cond_t * C)
{
    // Variables.

    ao_cond_wait_t W;


    // Ready.

    ao_clear(&W, ao_cond_wait_t);

    W.cond = C;


    ao_cond_wait_begin(&W);

    ao_cond_wait_end(&W);


    return W.result;
}

// ----------------------------------------------------------------------------

#endif

#if defined AO_COUNTER

// ----------------------------------------------------------------------------

static void ao_counter_update_1(ao_counter_t * C, ao_uint_t v);

static void ao_counter_update_2(ao_counter_t * C, ao_uint_t v);

// ----------------------------------------------------------------------------

void ao_counter_add(ao_counter_t * C, ao_uint_t v)
{
    // Assert.

    ao_assert(C);


    // Variables.

    ao_lock_t L;


    // Ready.

    if (v != 0)
    {
        ao_lock(&L);
        {
            ao_counter_update_2(C, C->value + v);
        }
        ao_unlock(&L);
    }
}

void ao_counter_adjust(ao_counter_t * C, ao_counter_adjust_t a, void * p)
{
    // Assert.

    ao_assert(C);

    ao_assert(a);


    // Variables.

    ao_lock_t L;

    ao_uint_t v;


    // Ready.

    ao_lock(&L);
    {
        v = a(C->value, p);

        ao_counter_update_1(C, v);
    }
    ao_unlock(&L);
}

void ao_counter_decrement(ao_counter_t * C)
{
    // Assert.

    ao_assert(C);


    // Variables.

    ao_lock_t L;


    // Ready.

    ao_lock(&L);
    {
        ao_counter_update_2(C, C->value - 1);
    }
    ao_unlock(&L);
}

void ao_counter_divide(ao_counter_t * C, ao_uint_t v)
{
    // Assert.

    ao_assert(C);

    ao_assert(v != 0);


    // Variables.

    ao_lock_t L;


    // Ready.

    if (v != 1)
    {
        ao_lock(&L);
        {
            ao_counter_update_1(C, C->value / v);
        }
        ao_unlock(&L);
    }
}

void ao_counter_increment(ao_counter_t * C)
{
    // Assert.

    ao_assert(C);


    // Variables.

    ao_lock_t L;


    // Ready.

    ao_lock(&L);
    {
        ao_counter_update_2(C, C->value + 1);
    }
    ao_unlock(&L);
}

void ao_counter_modulo(ao_counter_t * C, ao_uint_t v)
{
    // Assert.

    ao_assert(C);

    ao_assert(v != 0);


    // Variables.

    ao_lock_t L;


    // Ready.

    ao_lock(&L);
    {
        ao_counter_update_1(C, C->value % v);
    }
    ao_unlock(&L);
}

void ao_counter_multiply(ao_counter_t * C, ao_uint_t v)
{
    // Assert.

    ao_assert(C);


    // Variables.

    ao_lock_t L;


    // Ready.

    if (v != 1)
    {
        ao_lock(&L);
        {
            ao_counter_update_1(C, C->value * v);
        }
        ao_unlock(&L);
    }
}

void ao_counter_set(ao_counter_t * C, ao_uint_t v)
{
    // Assert.

    ao_assert(C);


    // Variables.

    ao_lock_t L;


    // Ready.

    ao_lock(&L);
    {
        ao_counter_update_1(C, v);
    }
    ao_unlock(&L);
}

void ao_counter_subtract(ao_counter_t * C, ao_uint_t v)
{
    // Assert.

    ao_assert(C);


    // Variables.

    ao_lock_t L;


    // Ready.

    if (v != 0)
    {
        ao_lock(&L);
        {
            ao_counter_update_2(C, C->value - v);
        }
        ao_unlock(&L);
    }
}

void ao_counter_subtract_from(ao_counter_t * C, ao_uint_t v)
{
    // Assert.

    ao_assert(C);


    // Variables.

    ao_lock_t L;


    // Ready.

    ao_lock(&L);
    {
        ao_counter_update_1(C, v - C->value);
    }
    ao_unlock(&L);
}

void ao_counter_update_1(ao_counter_t * C, ao_uint_t v)
{
    // Notes.

    // The kernel is locked.


    // Ready.

    if (v != C->value)
    {
        ao_counter_update_2(C, v);
    }
}

void ao_counter_update_2(ao_counter_t * C, ao_uint_t v)
{
    // Notes.

    // The kernel is locked.


    // Variables.

    ao_list_node_t * n1;

    ao_list_node_t * n2;

    ao_counter_wait_t * W;


    // Ready.

    C->value = v;

    n1 = C->list.front;

    while (n1)
    {
        n2 = n1->next;

        W = ao_containerof(n1, ao_counter_wait_t, node);

        ao_assert(W->match);

        if (W->match(v, W->value, W->match_parameter))
        {
            ao_list_remove(&C->list, n1);

            W->result= true;

            ao_async_check(&W->async);
        }

        n1 = n2;
    }
}

// ----------------------------------------------------------------------------

bool ao_counter_wait(ao_counter_t * C, ao_uint_t v, ao_counter_match_t m, void * p, ao_time_t t)
{
    return ao_counter_wait_from(C, v, m, p, t, ao_now());
}

void ao_counter_wait_begin(ao_counter_wait_t * W)
{
    // Assert.

    ao_assert(W);

    ao_assert(W->counter);

    ao_assert(W->match);


    // Variables.

    ao_counter_t * C;

    ao_lock_t L;


    // Ready.

    C = W->counter;

    ao_async_begin(&W->async);

    ao_lock(&L);
    {
        if (W->match(C->value, W->value, W->match_parameter))
        {
            W->result = true;

            ao_async_check(&W->async);
        }

        else
        {
            W->result = false;

            ao_list_push_back(&C->list, &W->node);
        }
    }
    ao_unlock(&L);
}

void ao_counter_wait_end(ao_counter_wait_t * W)
{
    // Assert.

    ao_assert(W);

    ao_assert(W->counter);


    // Variables.

    ao_lock_t L;


    // Ready.

    ao_lock(&L);
    {
        if (W->result) { }

        else
        {
            ao_list_remove(&W->counter->list, &W->node);
        }
    }
    ao_unlock(&L);

    ao_async_end(&W->async);
}

bool ao_counter_wait_forever(ao_counter_t * C, ao_uint_t v, ao_counter_match_t m, void * p)
{
    return ao_counter_wait_from(C, v, m, p, AO_INFINITY, 0);
}

bool ao_counter_wait_from(ao_counter_t * C, ao_uint_t v, ao_counter_match_t m, void * p, ao_time_t t, ao_time_t b)
{
    // Variables.

    ao_counter_wait_t W;


    // Ready.

    ao_clear(&W, ao_counter_wait_t);

    W.counter = C;

    W.match = m;

    W.match_parameter = p;

    W.value = v;


    ao_counter_wait_begin(&W);

    ao_await_from(&W.async, t, b);

    ao_counter_wait_end(&W);


    return W.result;
}

bool ao_counter_wait_try(ao_counter_t * C, ao_uint_t v, ao_counter_match_t m, void * p)
{
    // Variables.

    ao_counter_wait_t W;


    // Ready.

    ao_clear(&W, ao_counter_wait_t);

    W.counter = C;

    W.match = m;

    W.match_parameter = p;

    W.value = v;


    ao_counter_wait_begin(&W);

    ao_counter_wait_end(&W);


    return W.result;
}

// ----------------------------------------------------------------------------

#endif

#if defined AO_FLAG

// ----------------------------------------------------------------------------

static void ao_flag_update(ao_flag_t * F, ao_uint_t m);

// ----------------------------------------------------------------------------

void ao_flag_mask_clear(ao_flag_t * F, ao_uint_t b)
{
    // Assert.

    ao_assert(F);


    // Variables.

    ao_lock_t L;


    // Ready.

    if (b)
    {
        ao_lock(&L);
        {
            ao_flag_update(F, F->mask & ~b);
        }
        ao_unlock(&L);
    }
}

void ao_flag_mask_set(ao_flag_t * F, ao_uint_t b)
{
    // Assert.

    ao_assert(F);


    // Variables.

    ao_lock_t L;


    // Ready.

    if (b)
    {
        ao_lock(&L);
        {
            ao_flag_update(F, F->mask | b);
        }
        ao_unlock(&L);
    }
}

void ao_flag_mask_toggle(ao_flag_t * F, ao_uint_t b)
{
    // Assert.

    ao_assert(F);


    // Variables.

    ao_lock_t L;


    // Ready.

    if (b)
    {
        ao_lock(&L);
        {
            ao_flag_update(F, F->mask ^ b);
        }
        ao_unlock(&L);
    }
}

void ao_flag_update(ao_flag_t * F, ao_uint_t m)
{
    // Notes.

    // The kernel is locked.


    // Variables.

    ao_list_node_t * n1;

    ao_list_node_t * n2;

    ao_flag_wait_t * W;


    // Ready.

    if (m != F->mask)
    {
        F->mask = m;

        n1 = F->list.front;

        while (n1)
        {
            n2 = n1->next;

            W = ao_containerof(n1, ao_flag_wait_t, node);

            ao_assert(W->match);

            if (W->match(m, W->mask, W->match_parameter))
            {
                ao_list_remove(&F->list, n1);

                W->result= true;

                ao_async_check(&W->async);
            }

            n1 = n2;
        }
    }
}

// ----------------------------------------------------------------------------

bool ao_flag_wait(ao_flag_t * F, ao_uint_t m, ao_flag_match_t x, void * p, ao_time_t t)
{
    return ao_flag_wait_from(F, m, x, p, t, ao_now());
}

void ao_flag_wait_begin(ao_flag_wait_t * W)
{
    // Assert.

    ao_assert(W);

    ao_assert(W->flag);

    ao_assert(W->match);


    // Variables.

    ao_flag_t * F;

    ao_lock_t L;


    // Ready.

    F = W->flag;

    ao_async_begin(&W->async);

    ao_lock(&L);
    {
        if (W->match(F->mask, W->mask, W->match_parameter))
        {
            W->result = true;

            ao_async_check(&W->async);
        }

        else
        {
            W->result = false;

            ao_list_push_back(&F->list, &W->node);
        }
    }
    ao_unlock(&L);
}

void ao_flag_wait_end(ao_flag_wait_t * W)
{
    // Assert.

    ao_assert(W);

    ao_assert(W->flag);


    // Variables.

    ao_lock_t L;


    // Ready.

    ao_lock(&L);
    {
        if (W->result) { }

        else
        {
            ao_list_remove(&W->flag->list, &W->node);
        }
    }
    ao_unlock(&L);

    ao_async_end(&W->async);
}

bool ao_flag_wait_forever(ao_flag_t * F, ao_uint_t m, ao_flag_match_t x, void * p)
{
    return ao_flag_wait_from(F, m, x, p, AO_INFINITY, 0);
}

bool ao_flag_wait_from(ao_flag_t * F, ao_uint_t m, ao_flag_match_t x, void * p, ao_time_t t, ao_time_t b)
{
    // Variables.

    ao_flag_wait_t W;


    // Ready.

    ao_clear(&W, ao_flag_wait_t);

    W.flag = F;

    W.mask = m;

    W.match = x;

    W.match_parameter = p;


    ao_flag_wait_begin(&W);

    ao_await_from(&W.async, t, b);

    ao_flag_wait_end(&W);


    return W.result;
}

bool ao_flag_wait_try(ao_flag_t * F, ao_uint_t m, ao_flag_match_t x, void * p)
{
    // Variables.

    ao_flag_wait_t W;


    // Ready.

    ao_clear(&W, ao_flag_wait_t);

    W.flag = F;

    W.mask = m;

    W.match = x;

    W.match_parameter = p;


    ao_flag_wait_begin(&W);

    ao_flag_wait_end(&W);


    return W.result;
}

// ----------------------------------------------------------------------------

#endif

#if defined AO_MAIL

// ----------------------------------------------------------------------------

bool ao_mail_fetch(ao_mailbox_t * B, ao_mail_t ** M, ao_time_t t)
{
    return ao_mail_fetch_from(B, M, t, ao_now());
}

void ao_mail_fetch_begin(ao_mail_fetch_t * F)
{
    // Assert.

    ao_assert(F);

    ao_assert(F->mailbox);


    // Variables.

    ao_mailbox_t * B;

    ao_lock_t L;

    ao_mail_t * M;

    ao_list_node_t * n;


    // Ready.

    B = F->mailbox;

    ao_async_begin(&F->async);

    ao_lock(&L);
    {
        // Mailbox is empty.

        if (ao_list_is_empty(&B->mails))
        {
            ao_list_push_back(&B->fetchers, &F->node);

            F->result = false;
        }

        // Mailbox is not empty.

        else
        {
            n = ao_list_pop_front(&B->mails);

            M = ao_containerof(n, ao_mail_t, node);

            F->mail = M;

            F->result = true;

            ao_async_check(&F->async);
        }
    }
    ao_unlock(&L);
}

void ao_mail_fetch_end(ao_mail_fetch_t * F)
{
    // Assert.

    ao_assert(F);

    ao_assert(F->mailbox);


    // Variables.

    ao_lock_t L;


    // Ready.

    ao_lock(&L);
    {
        if (F->result) { }

        else
        {
            ao_list_remove(&F->mailbox->fetchers, &F->node);
        }
    }
    ao_unlock(&L);

    ao_async_end(&F->async);
}

bool ao_mail_fetch_forever(ao_mailbox_t * B, ao_mail_t ** M)
{
    return ao_mail_fetch_from(B, M, AO_INFINITY, 0);
}

bool ao_mail_fetch_from(ao_mailbox_t * B, ao_mail_t ** M, ao_time_t t, ao_time_t b)
{
    // Assert.

    ao_assert(M);


    // Variables.

    ao_mail_fetch_t F;


    // Ready.

    ao_clear(&F, ao_mail_fetch_t);

    F.mailbox = B;


    ao_mail_fetch_begin(&F);

    ao_await_from(&F.async, t, b);

    ao_mail_fetch_end(&F);


    *M = F.mail;

    return F.result;
}

bool ao_mail_fetch_try(ao_mailbox_t * B, ao_mail_t ** M)
{
    // Assert.

    ao_assert(M);


    // Variables.

    ao_mail_fetch_t F;


    // Ready.

    ao_clear(&F, ao_mail_fetch_t);

    F.mailbox = B;


    ao_mail_fetch_begin(&F);

    ao_mail_fetch_end(&F);


    *M = F.mail;

    return F.result;
}

// ----------------------------------------------------------------------------

void ao_mail_post(ao_mailbox_t * B, ao_mail_t * M)
{
    // Assert.

    ao_assert(B);

    ao_assert(M);


    // Variables.

    ao_mail_fetch_t * F;

    ao_lock_t L;

    ao_list_node_t * n;


    // Ready.

    ao_lock(&L);
    {
        // Mailbox has no fetchers.

        if (ao_list_is_empty(&B->fetchers))
        {
            ao_list_push_back(&B->mails, &M->node);
        }

        // Mailbox has fetchers.

        else
        {
            n = ao_list_pop_front(&B->fetchers);

            F = ao_containerof(n, ao_mail_fetch_t, node);

            F->mail = M;

            F->result = true;

            ao_async_check(&F->async);
        }
    }
    ao_unlock(&L);
}

// ----------------------------------------------------------------------------

#endif

#if defined AO_MONITOR

// ----------------------------------------------------------------------------

static  void    ao_monitor_enter_checked(   void * x);

static  void    ao_monitor_wait_checked(    void * x);

// ----------------------------------------------------------------------------

bool ao_monitor_enter(ao_monitor_t * M, ao_time_t t)
{
    return ao_monitor_enter_from(M, t, ao_now());
}

void ao_monitor_enter_begin(ao_monitor_enter_t * E)
{
    // Assert.

    ao_assert(E);

    ao_assert(E->monitor);

    ao_assert(E->monitor->mutex);


    // Variables.

    ao_mutex_lock_t * XL;


    // Ready.

    // Monitor enter.

    ao_async_begin(&E->async);

    E->result = false;

    // Mutex lock.

    XL = &E->mutex_lock;

    XL->async.callback = ao_monitor_enter_checked;

    XL->async.callback_parameter = E;

    XL->mutex = E->monitor->mutex;

    ao_mutex_lock_begin(XL);
}

void ao_monitor_enter_checked(void * x)
{
    // Notes.

    // The kernel is locked.


    // Assert.

    ao_assert(x);


    // Variables.

    ao_monitor_enter_t * E;


    // Ready.

    E = x;

    E->result = true;

    ao_async_check(&E->async);
}

void ao_monitor_enter_end(ao_monitor_enter_t * E)
{
    // Assert.

    ao_assert(E);


    // Variables.

    ao_mutex_lock_t * XL;


    // Ready.

    // Mutex lock.

    XL = &E->mutex_lock;

    ao_mutex_lock_end(XL);

    XL->async.callback = NULL;

    XL->async.callback_parameter = NULL;

    XL->mutex = NULL;

    // Monitor enter.

    ao_async_end(&E->async);
}

bool ao_monitor_enter_forever(ao_monitor_t * M)
{
    return ao_monitor_enter_from(M, AO_INFINITY, 0);
}

bool ao_monitor_enter_from(ao_monitor_t * M, ao_time_t t, ao_time_t b)
{
    // Variables.

    ao_monitor_enter_t E;


    // Ready.

    ao_clear(&E, ao_monitor_enter_t);

    E.monitor = M;


    ao_monitor_enter_begin(&E);

    ao_await_from(&E.async, t, b);

    ao_monitor_enter_end(&E);


    return E.result;
}

bool ao_monitor_enter_try(ao_monitor_t * M)
{
    // Variables.

    ao_monitor_enter_t E;


    // Ready.

    ao_clear(&E, ao_monitor_enter_t);

    E.monitor = M;


    ao_monitor_enter_begin(&E);

    ao_monitor_enter_end(&E);


    return E.result;
}

// ----------------------------------------------------------------------------

void ao_monitor_exit(ao_monitor_t * M)
{
    ao_assert(M);

    ao_mutex_unlock(M->mutex);
}

// ----------------------------------------------------------------------------

void ao_monitor_notify(ao_monitor_t * M)
{
    // Assert.

    ao_assert(M);


    // Variables.

    ao_lock_t L;

    ao_list_node_t * n;

    ao_monitor_wait_t * W;


    // Ready.

    ao_lock(&L);
    {
        n = M->list.front;

        if (n)
        {
            ao_list_remove_front(&M->list);

            W = ao_containerof(n, ao_monitor_wait_t, node);

            W->waiting = false;

            ao_mutex_lock_begin_locked(&W->mutex_lock);
        }
    }
    ao_unlock(&L);
}

void ao_monitor_notify_all(ao_monitor_t * M)
{
    // Assert.

    ao_assert(M);


    // Variables.

    ao_lock_t L;

    ao_list_node_t * n;

    ao_monitor_wait_t * W;


    // Ready.

    ao_lock(&L);
    {
        n = M->list.front;

        while (n)
        {
            W = ao_containerof(n, ao_monitor_wait_t, node);

            W->waiting = false;

            ao_mutex_lock_begin_locked(&W->mutex_lock);

            n = n->next;
        }

        ao_list_remove_all(&M->list);
    }
    ao_unlock(&L);
}

// ----------------------------------------------------------------------------

bool ao_monitor_wait(ao_monitor_t * M, ao_time_t t)
{
    return ao_monitor_wait_from(M, t, ao_now());
}

void ao_monitor_wait_begin(ao_monitor_wait_t * W)
{
    // Assert.

    ao_assert(W);

    ao_assert(W->monitor);

    ao_assert(W->monitor->mutex);

    ao_assert(W->monitor->mutex->owner == ao_self());


    // Variables.

    ao_lock_t L;

    ao_monitor_t * M;

    ao_mutex_t * X;


    // Ready.

    M = W->monitor;

    X = M->mutex;

    // Monitor wait.

    ao_async_begin(&W->async);

    W->mutex_lock.async.callback = ao_monitor_wait_checked;

    W->mutex_lock.async.callback_parameter = W;

    W->mutex_lock.mutex = X;

    W->result = false;

    W->waiting = true;

    // Monitor.

    ao_lock(&L);
    {
        ao_list_push_back(&M->list, &W->node);

        ao_mutex_unlock_locked(X);
    }
    ao_unlock(&L);
}

void ao_monitor_wait_checked(void * x)
{
    // Notes.

    // The kernel is locked.


    // Variables.

    ao_monitor_wait_t * W;


    // Ready.

    W = x;

    W->result = true;

    ao_async_check(&W->async);
}

void ao_monitor_wait_end(ao_monitor_wait_t * W)
{
    // Assert.

    ao_assert(W);

    ao_assert(W->monitor);


    // Variables.

    ao_lock_t L;

    ao_monitor_t * M = W->monitor;


    // Ready.

    // Monitor.

    ao_lock(&L);
    {
        if (W->waiting)
        {
            ao_list_remove(&M->list, &W->node);
        }

        else
        {
            ao_mutex_lock_end_locked(&W->mutex_lock);
        }
    }
    ao_unlock(&L);

    // Monitor wait.

    W->mutex_lock.async.callback = NULL;

    W->mutex_lock.async.callback_parameter = NULL;

    W->mutex_lock.mutex = NULL;

    ao_async_end(&W->async);
}

bool ao_monitor_wait_forever(ao_monitor_t * M)
{
    return ao_monitor_wait_from(M, AO_INFINITY, 0);
}

bool ao_monitor_wait_from(ao_monitor_t * M, ao_time_t t, ao_time_t b)
{
    // Variables.

    ao_monitor_wait_t W;


    // Ready.

    ao_clear(&W, ao_monitor_wait_t);

    W.monitor = M;


    ao_monitor_wait_begin(&W);

    ao_await_from(&W.async, t, b);

    ao_monitor_wait_end(&W);


    return W.result;
}

bool ao_monitor_wait_try(ao_monitor_t * M)
{
    // Variables.

    ao_monitor_wait_t W;


    // Ready.

    ao_clear(&W, ao_monitor_wait_t);

    W.monitor = M;


    ao_monitor_wait_begin(&W);

    ao_monitor_wait_end(&W);


    return W.result;
}

// ----------------------------------------------------------------------------

#endif

#if defined AO_MUTEX

// ----------------------------------------------------------------------------

bool ao_mutex_lock(ao_mutex_t * X, ao_time_t t)
{
    return ao_mutex_lock_from(X, t, ao_now());
}

void ao_mutex_lock_begin(ao_mutex_lock_t * XL)
{
    ao_lock_t L;

    ao_lock(&L);
    {
        ao_mutex_lock_begin_locked(XL);
    }
    ao_unlock(&L);
}

void ao_mutex_lock_begin_locked(ao_mutex_lock_t * XL)
{
    // Assert.

    ao_assert(XL);

    ao_assert(XL->mutex);


    // Variables.

    ao_task_t * T = ao_self_locked();

    ao_mutex_t * X = XL->mutex;


    // Ready.

    ao_async_begin(&XL->async);

    // Mutex owner is null.

    if (X->owner == NULL)
    {
        X->owner = T;

        X->owner_count = 1;

#if AO_TASK_CEILING

        ao_task_ceiling_begin(&X->ceiling_immediate, &X->slave);

#endif

#if AO_TASK_SUBMISSION

        ao_task_slave_begin(&X->slave, T);

#endif

        XL->result = true;

        ao_async_check(&XL->async);
    }

    // Mutex owner is self.

    else if (X->owner == T)
    {
        X->owner_count++;

        XL->result = true;

        ao_async_check(&XL->async);
    }

    // Mutex owner is another task.

    else
    {
        ao_list_push_back(&X->list, &XL->node);

#if AO_TASK_INHERITANCE

        ao_task_master_begin(&XL->master, T);

        ao_task_inheritance_begin(&XL->master, &X->slave);

#endif

#if AO_TASK_CEILING

        ao_task_ceiling_begin(&X->ceiling_original, &X->slave);

#endif

        XL->result = false;

        XL->task = T;
    }
}

void ao_mutex_lock_end(ao_mutex_lock_t * XL)
{
    ao_lock_t L;

    ao_lock(&L);
    {
        ao_mutex_lock_end_locked(XL);
    }
    ao_unlock(&L);
}

void ao_mutex_lock_end_locked(ao_mutex_lock_t * XL)
{
    // Assert.

    ao_assert(XL);

    ao_assert(XL->mutex);


    // Variables.

    ao_mutex_t * X;


    // Ready.

    if (XL->result) { }

    else
    {
        X = XL->mutex;

        ao_list_remove(&X->list, &XL->node);

#if AO_TASK_CEILING

        if (ao_list_is_empty(&X->list))
        {
            ao_task_ceiling_end(&X->ceiling_original);
        }

#endif

#if AO_TASK_INHERITANCE

        ao_task_inheritance_end(&XL->master);

        ao_task_master_end(&XL->master);

#endif

    }

    ao_async_end(&XL->async);
}

bool ao_mutex_lock_forever(ao_mutex_t * X)
{
    return ao_mutex_lock_from(X, AO_INFINITY, 0);
}

bool ao_mutex_lock_from(ao_mutex_t * X, ao_time_t t, ao_time_t b)
{
    // Variables.

    ao_mutex_lock_t XL;


    // Ready.

    ao_clear(&XL, ao_mutex_lock_t);

    XL.mutex = X;


    ao_mutex_lock_begin(&XL);

    ao_await_from(&XL.async, t, b);

    ao_mutex_lock_end(&XL);


    return XL.result;
}

bool ao_mutex_lock_try(ao_mutex_t * X)
{
    // Variables.

    ao_mutex_lock_t XL;


    // Ready.

    ao_clear(&XL, ao_mutex_lock_t);

    XL.mutex = X;


    ao_mutex_lock_begin(&XL);

    ao_mutex_lock_end(&XL);


    return XL.result;
}

// ----------------------------------------------------------------------------

void ao_mutex_unlock(ao_mutex_t * X)
{
    ao_lock_t L;

    ao_lock(&L);
    {
        ao_mutex_unlock_locked(X);
    }
    ao_unlock(&L);
}

void ao_mutex_unlock_locked(ao_mutex_t * X)
{
    // Assert.

    ao_assert(X);

    ao_assert(X->owner);

    ao_assert(X->owner == ao_self_locked());

    ao_assert(X->owner_count > 0);


    // Variables.

    ao_list_node_t * n;

    ao_mutex_lock_t * XL;


    // Ready.

    // Mutex becomes unlocked.

    if (X->owner_count == 1)
    {

#if AO_TASK_SUBMISSION

        ao_task_slave_end(&X->slave);

#endif

        // Mutex list is empty.

        if (ao_list_is_empty(&X->list))
        {
            X->owner = NULL;

            X->owner_count = 0;

#if AO_TASK_CEILING

            ao_task_ceiling_end(&X->ceiling_immediate);

#endif

        }

        // Mutex list is not empty.

        else
        {
            n = ao_list_pop_front(&X->list);

            XL = ao_containerof(n, ao_mutex_lock_t, node);

#if AO_TASK_CEILING

            if (ao_list_is_empty(&X->list))
            {
                ao_task_ceiling_end(&X->ceiling_original);
            }

#endif

#if AO_TASK_INHERITANCE

            ao_task_inheritance_end(&XL->master);

            ao_task_master_end(&XL->master);

#endif

            XL->result = true;

            ao_async_check(&XL->async);

            X->owner = XL->task;

#if AO_TASK_SUBMISSION

            ao_task_slave_begin(&X->slave, XL->task);

#endif

        }
    }

    // Mutex remains locked.

    else
    {
        X->owner_count--;
    }
}

// ----------------------------------------------------------------------------

#endif

#if defined AO_PMAIL

// ----------------------------------------------------------------------------

bool ao_pmail_fetch(ao_pmailbox_t * B, ao_pmail_t ** M, ao_time_t t)
{
    return ao_pmail_fetch_from(B, M, t, ao_now());
}

void ao_pmail_fetch_begin(ao_pmail_fetch_t * F)
{
    // Assert.

    ao_assert(F);

    ao_assert(F->mailbox);


    // Variables.

    ao_pmailbox_t * B;

    ao_lock_t L;

    ao_pmail_t * M;

    ao_rb_node_t * n;


    // Ready.

    B = F->mailbox;

    ao_async_begin(&F->async);

    ao_lock(&L);
    {
        // Mailbox is empty.

        if (ao_rb_is_empty(&B->mails))
        {
            ao_list_push_back(&B->fetchers, &F->node);

            F->result = false;
        }

        // Mailbox is not empty.

        else
        {
            n = ao_rb_min(&B->mails);

            ao_rb_remove(&B->mails, n);

            M = ao_containerof(n, ao_pmail_t, node);

            F->mail = M;

            F->result = true;

            ao_async_check(&F->async);
        }
    }
    ao_unlock(&L);
}

void ao_pmail_fetch_end(ao_pmail_fetch_t * F)
{
    // Assert.

    ao_assert(F);

    ao_assert(F->mailbox);


    // Variables.

    ao_lock_t L;


    // Ready.

    ao_lock(&L);
    {
        if (F->result) { }

        else
        {
            ao_list_remove(&F->mailbox->fetchers, &F->node);
        }
    }
    ao_unlock(&L);

    ao_async_end(&F->async);
}

bool ao_pmail_fetch_forever(ao_pmailbox_t * B, ao_pmail_t ** M)
{
    return ao_pmail_fetch_from(B, M, AO_INFINITY, 0);
}

bool ao_pmail_fetch_from(ao_pmailbox_t * B, ao_pmail_t ** M, ao_time_t t, ao_time_t b)
{
    // Assert.

    ao_assert(M);


    // Variables.

    ao_pmail_fetch_t F;


    // Ready.

    ao_clear(&F, ao_pmail_fetch_t);

    F.mailbox = B;


    ao_pmail_fetch_begin(&F);

    ao_await_from(&F.async, t, b);

    ao_pmail_fetch_end(&F);


    *M = F.mail;

    return F.result;
}

bool ao_pmail_fetch_try(ao_pmailbox_t * B, ao_pmail_t ** M)
{
    // Assert.

    ao_assert(M);


    // Variables.

    ao_pmail_fetch_t F;


    // Ready.

    ao_clear(&F, ao_pmail_fetch_t);

    F.mailbox = B;


    ao_pmail_fetch_begin(&F);

    ao_pmail_fetch_end(&F);


    *M = F.mail;

    return F.result;
}

// ----------------------------------------------------------------------------

void ao_pmail_post(ao_pmailbox_t * B, ao_pmail_t * M)
{
    // Assert.

    ao_assert(B);

    ao_assert(M);


    // Variables.

    ao_pmail_fetch_t * F;

    ao_lock_t L;

    ao_list_node_t * n;


    // Ready.

    ao_lock(&L);
    {
        // Mailbox has no fetchers.

        if (ao_list_is_empty(&B->fetchers))
        {
            ao_rb_insert(&B->mails, &M->node);
        }

        // Mailbox has fetchers.

        else
        {
            n = ao_list_pop_front(&B->fetchers);

            F = ao_containerof(n, ao_pmail_fetch_t, node);

            F->mail = M;

            F->result = true;

            ao_async_check(&F->async);
        }
    }
    ao_unlock(&L);
}

// ----------------------------------------------------------------------------

#endif

#if defined AO_POLL

// ----------------------------------------------------------------------------

void ao_poll(ao_async_t const * A, ao_time_t t)
{
    ao_poll_from(A, t, ao_now());
}

void ao_poll_forever(ao_async_t const * A)
{
    ao_poll_from(A, AO_INFINITY, 0);
}

void ao_poll_from(ao_async_t const * A, ao_time_t t, ao_time_t b)
{
    // Assert.

    ao_assert(A);


    // Variables.

    ao_time_t e;

    ao_time_t x;


    // Ready.

    if (t == AO_INFINITY)
    {
        while (!ao_async_checked(A)) { }
    }

    else
    {
        do
        {
            e = ao_now();

            x = e - b;

            if (t > x)
            {
                t = t - x;

                b = e;
            }

            else
            {
                break;
            }
        }
        while (!ao_async_checked(A));
    }
}

// ----------------------------------------------------------------------------

void ao_poll_all(ao_async_all_t * ALL, ao_time_t t)
{
    ao_poll_all_from(ALL, t, ao_now());
}

void ao_poll_all_forever(ao_async_all_t * ALL)
{
    ao_poll_all_from(ALL, AO_INFINITY, 0);
}

void ao_poll_all_from(ao_async_all_t * ALL, ao_time_t t, ao_time_t b)
{
    // Assert.

    ao_assert(ALL);


    // Ready.

    ao_async_all_begin(ALL);

    ao_poll_from(&ALL->async, t, b);

    ao_async_all_end(ALL);
}

// ----------------------------------------------------------------------------

void ao_poll_any(ao_async_any_t * ANY, ao_time_t t)
{
    ao_poll_any_from(ANY, t, ao_now());
}

void ao_poll_any_forever(ao_async_any_t * ANY)
{
    ao_poll_any_from(ANY, AO_INFINITY, 0);
}

void ao_poll_any_from(ao_async_any_t * ANY, ao_time_t t, ao_time_t b)
{
    // Assert.

    ao_assert(ANY);


    // Ready.

    ao_async_any_begin(ANY);

    ao_poll_from(&ANY->async, t, b);

    ao_async_any_end(ANY);
}

// ----------------------------------------------------------------------------

#endif

#if defined AO_QUEUE4OBJ

// ----------------------------------------------------------------------------

void ao_qinsert_obj(ao_qinsert_obj_t * QI, ao_time_t t)
{
    ao_qinsert_obj_from(QI, t, ao_now());
}

void ao_qinsert_obj_begin(ao_qinsert_obj_t * QI)
{
    // Assert.

    ao_assert(QI);

    ao_assert(QI->queue);


    // Variables.

    ao_heap4obj_t * H;

    ao_list_t * l;

    ao_lock_t L;

    ao_list_node_t * n;

    ao_queue4obj_t * Q;

    ao_qpop_obj_t * QP;

    bool r;


    // Ready.

    Q = QI->queue;

    H = &Q->heap;

    ao_async_begin(&QI->async);

    ao_lock(&L);
    {
        // Insert and pop.

        r = ao_heap4obj_is_empty(H);

        if (r)
        {
            // Insert and pop now.

            l = &Q->pop;

            n = l->front;

            if (n)
            {
                ao_list_remove_front(l);

                QP = ao_containerof(n, ao_qpop_obj_t, node);

                ao_memcpy(QP->ptr, QI->ptr, H->size);

                QP->result = true;

                QI->result = true;

                ao_async_check(&QP->async);

                ao_async_check(&QI->async);
            }

            // Insert and pop not possible.

            else
            {
                r = false;
            }
        }

        // Insert.

        if (!r)
        {
            // Insert later.

            r = ao_heap4obj_is_full(H);

            if (r)
            {
                QI->result = false;

                ao_list_push_back(&Q->insert, &QI->node);
            }

            // Insert now.

            else
            {
                ao_heap4obj_insert(H, QI->ptr);

                QI->result = true;

                ao_async_check(&QI->async);
            }
        }
    }
    ao_unlock(&L);
}

void ao_qinsert_obj_end(ao_qinsert_obj_t * QI)
{
    // Assert.

    ao_assert(QI);

    ao_assert(QI->queue);


    // Variables.

    ao_lock_t L;


    // Ready.

    ao_lock(&L);
    {
        if (QI->result) { }

        else
        {
            ao_list_remove(&QI->queue->insert, &QI->node);
        }
    }
    ao_unlock(&L);

    ao_async_end(&QI->async);
}

void ao_qinsert_obj_forever(ao_qinsert_obj_t * QI)
{
    ao_qinsert_obj_from(QI, AO_INFINITY, 0);
}

void ao_qinsert_obj_from(ao_qinsert_obj_t * QI, ao_time_t t, ao_time_t b)
{
    // Assert.

    ao_assert(QI);


    // Ready.

    ao_qinsert_obj_begin(QI);

    ao_await_from(&QI->async, t, b);

    ao_qinsert_obj_end(QI);
}

void ao_qinsert_obj_try(ao_qinsert_obj_t * QI)
{
    ao_qinsert_obj_begin(QI);

    ao_qinsert_obj_end(QI);
}

// ----------------------------------------------------------------------------

void ao_qpop_obj(ao_qpop_obj_t * QP, ao_time_t t)
{
    ao_qpop_obj_from(QP, t, ao_now());
}

void ao_qpop_obj_begin(ao_qpop_obj_t * QP)
{
    // Assert.

    ao_assert(QP);

    ao_assert(QP->queue);


    // Variables.

    ao_heap4obj_t * H;

    ao_list_t * l;

    ao_lock_t L;

    ao_list_node_t * n;

    ao_queue4obj_t * Q;

    ao_qinsert_obj_t * QI;

    bool r;


    // Ready.

    Q = QP->queue;

    H = &Q->heap;

    ao_async_begin(&QP->async);

    ao_lock(&L);
    {
        // Heap is empty.

        r = ao_heap4obj_is_empty(H);

        if (r)
        {
            // Insert and pop.

            r = ao_heap4obj_is_full(H);

            if (r)
            {
                l = &Q->insert;

                n = l->front;

                // Insert and pop now.

                if (n)
                {
                    ao_list_remove_front(l);

                    QI = ao_containerof(n, ao_qinsert_obj_t, node);

                    ao_memcpy(QP->ptr, QI->ptr, H->size);

                    QP->result = true;

                    QI->result = true;

                    ao_async_check(&QP->async);

                    ao_async_check(&QI->async);
                }

                // Insert and pop not possible.

                else
                {
                    r = false;
                }
            }

            // Pop later.

            if (!r)
            {
                QP->result = false;

                ao_list_push_back(&Q->pop, &QP->node);
            }
        }

        // Heap is not empty.

        else
        {
            // Pop now.

            r = ao_heap4obj_is_full(H);

            ao_heap4obj_pop(H, QP->ptr);

            QP->result = true;

            ao_async_check(&QP->async);

            // Insert now.

            if (r)
            {
                l = &Q->insert;

                n = l->front;

                if (n)
                {
                    ao_list_remove_front(l);

                    QI = ao_containerof(n, ao_qinsert_obj_t, node);

                    ao_heap4obj_insert(H, QI->ptr);

                    QI->result = true;

                    ao_async_check(&QI->async);
                }
            }
        }
    }
    ao_unlock(&L);
}

void ao_qpop_obj_end(ao_qpop_obj_t * QP)
{
    // Assert.

    ao_assert(QP);

    ao_assert(QP->queue);


    // Variables.

    ao_lock_t L;


    // Ready.

    ao_lock(&L);
    {
        if (QP->result) { }

        else
        {
            ao_list_remove(&QP->queue->pop, &QP->node);
        }
    }
    ao_unlock(&L);

    ao_async_end(&QP->async);
}

void ao_qpop_obj_forever(ao_qpop_obj_t * QP)
{
    ao_qpop_obj_from(QP, AO_INFINITY, 0);
}

void ao_qpop_obj_from(ao_qpop_obj_t * QP, ao_time_t t, ao_time_t b)
{
    // Assert.

    ao_assert(QP);


    // Ready.

    ao_qpop_obj_begin(QP);

    ao_await_from(&QP->async, t, b);

    ao_qpop_obj_end(QP);
}

void ao_qpop_obj_try(ao_qpop_obj_t * QP)
{
    ao_qpop_obj_begin(QP);

    ao_qpop_obj_end(QP);
}

// ----------------------------------------------------------------------------

#endif

#if defined AO_QUEUE4PTR

// ----------------------------------------------------------------------------

void ao_qinsert_acq(ao_qinsert_ptr_t * QI, ao_time_t t)
{
    ao_qinsert_acq_from(QI, t, ao_now());
}

void ao_qinsert_acq_begin(ao_qinsert_ptr_t * QI)
{

#if defined AO_ALLOC

    ao_assert(QI);

    ao_retain(QI->ptr);

#endif

    ao_qinsert_ptr_begin(QI);
}

void ao_qinsert_acq_end(ao_qinsert_ptr_t * QI)
{
    ao_qinsert_ptr_end(QI);

#if defined AO_ALLOC

    ao_assert(QI);

    if (QI->result) { }

    else
    {
        ao_release(QI->ptr);
    }

#endif

}

void ao_qinsert_acq_forever(ao_qinsert_ptr_t * QI)
{
    ao_qinsert_acq_from(QI, AO_INFINITY, 0);
}

void ao_qinsert_acq_from(ao_qinsert_ptr_t * QI, ao_time_t t, ao_time_t b)
{
    // Assert.

    ao_assert(QI);


    // Ready.

    ao_qinsert_acq_begin(QI);

    ao_await_from(&QI->async, t, b);

    ao_qinsert_acq_end(QI);
}

void ao_qinsert_acq_try(ao_qinsert_ptr_t * QI)
{
    ao_qinsert_acq_begin(QI);

    ao_qinsert_acq_end(QI);
}

// ----------------------------------------------------------------------------

void ao_qinsert_ptr(ao_qinsert_ptr_t * QI, ao_time_t t)
{
    ao_qinsert_ptr_from(QI, t, ao_now());
}

void ao_qinsert_ptr_begin(ao_qinsert_ptr_t * QI)
{
    // Assert.

    ao_assert(QI);

    ao_assert(QI->queue);


    // Variables.

    ao_heap4ptr_t * H;

    ao_list_t * l;

    ao_lock_t L;

    ao_list_node_t * n;

    ao_queue4ptr_t * Q;

    ao_qpop_ptr_t * QP;

    bool r;


    // Ready.

    Q = QI->queue;

    H = &Q->heap;

    ao_async_begin(&QI->async);

    ao_lock(&L);
    {
        // Insert and pop.

        r = ao_heap4ptr_is_empty(H);

        if (r)
        {
            l = &Q->pop;

            n = l->front;

            // Insert and pop now.

            if (n)
            {
                ao_list_remove_front(l);

                QP = ao_containerof(n, ao_qpop_ptr_t, node);

                QP->ptr = QI->ptr;

                QP->result = true;

                QI->result = true;

                ao_async_check(&QP->async);

                ao_async_check(&QI->async);
            }

            // Insert and pop not possible.

            else
            {
                r = false;
            }
        }

        // Insert.

        if (!r)
        {
            r = ao_heap4ptr_is_full(H);

            // Insert later.

            if (r)
            {
                QI->result = false;

                ao_list_push_back(&Q->insert, &QI->node);
            }

            // Insert now.

            else
            {
                ao_heap4ptr_insert(H, QI->ptr);

                QI->result = true;

                ao_async_check(&QI->async);
            }
        }
    }
    ao_unlock(&L);
}

void ao_qinsert_ptr_end(ao_qinsert_ptr_t * QI)
{
    // Assert.

    ao_assert(QI);

    ao_assert(QI->queue);


    // Variables.

    ao_lock_t L;


    // Ready.

    ao_lock(&L);
    {
        if (QI->result) { }

        else
        {
            ao_list_remove(&QI->queue->insert, &QI->node);
        }
    }
    ao_unlock(&L);

    ao_async_end(&QI->async);
}

void ao_qinsert_ptr_forever(ao_qinsert_ptr_t * QI)
{
    ao_qinsert_ptr_from(QI, AO_INFINITY, 0);
}

void ao_qinsert_ptr_from(ao_qinsert_ptr_t * QI, ao_time_t t, ao_time_t b)
{
    // Assert.

    ao_assert(QI);


    // Ready.

    ao_qinsert_ptr_begin(QI);

    ao_await_from(&QI->async, t, b);

    ao_qinsert_ptr_end(QI);
}

void ao_qinsert_ptr_try(ao_qinsert_ptr_t * QI)
{
    ao_qinsert_ptr_begin(QI);

    ao_qinsert_ptr_end(QI);
}

// ----------------------------------------------------------------------------

void ao_qpop_ptr(ao_qpop_ptr_t * QP, ao_time_t t)
{
    ao_qpop_ptr_from(QP, t, ao_now());
}

void ao_qpop_ptr_begin(ao_qpop_ptr_t * QP)
{
    // Assert.

    ao_assert(QP);

    ao_assert(QP->queue);


    // Variables.

    ao_heap4ptr_t * H;

    ao_list_t * l;

    ao_lock_t L;

    ao_list_node_t * n;

    void * p;

    ao_queue4ptr_t * Q;

    ao_qinsert_ptr_t * QI;

    bool r;


    // Ready.

    Q = QP->queue;

    H = &Q->heap;

    ao_async_begin(&QP->async);

    ao_lock(&L);
    {
        // Heap is empty.

        r = ao_heap4ptr_is_empty(H);

        if (r)
        {
            // Insert and pop.

            r = ao_heap4ptr_is_full(H);

            if (r)
            {
                // Insert and pop now.

                l = &Q->insert;

                n = l->front;

                if (n)
                {
                    ao_list_remove_front(l);

                    QI = ao_containerof(n, ao_qinsert_ptr_t, node);

                    QP->ptr = QI->ptr;

                    QP->result = true;

                    QI->result = true;

                    ao_async_check(&QP->async);

                    ao_async_check(&QI->async);
                }

                // Insert and pop not possible.

                else
                {
                    r = false;
                }
            }

            // Pop later.

            if (!r)
            {
                QP->result = false;

                ao_list_push_back
                (
                    &Q->pop,
                    &QP->node
                );
            }
        }

        // Heap is not empty.

        else
        {
            // Pop now.

            r = ao_heap4ptr_is_full(H);

            ao_heap4ptr_pop(H, &p);

            QP->ptr = p;

            QP->result = true;

            ao_async_check(&QP->async);

            // Insert now.

            if (r)
            {
                l = &Q->insert;

                n = l->front;

                if (n)
                {
                    ao_list_remove_front(l);

                    QI = ao_containerof(n, ao_qinsert_ptr_t, node);

                    ao_heap4ptr_insert(H, QI->ptr);

                    QI->result = true;

                    ao_async_check(&QI->async);
                }
            }
        }
    }
    ao_unlock(&L);
}

void ao_qpop_ptr_end(ao_qpop_ptr_t * QP)
{
    // Assert.

    ao_assert(QP);

    ao_assert(QP->queue);


    // Variables.

    ao_lock_t L;


    // Ready.

    ao_lock(&L);
    {
        if (QP->result) { }

        else
        {
            ao_list_remove(&QP->queue->pop, &QP->node);
        }
    }
    ao_unlock(&L);

    ao_async_end(&QP->async);
}

void ao_qpop_ptr_forever(ao_qpop_ptr_t * QP)
{
    ao_qpop_ptr_from(QP, AO_INFINITY, 0);
}

void ao_qpop_ptr_from(ao_qpop_ptr_t * QP, ao_time_t t, ao_time_t b)
{
    // Assert.

    ao_assert(QP);


    // Ready.

    ao_qpop_ptr_begin(QP);

    ao_await_from(&QP->async, t, b);

    ao_qpop_ptr_end(QP);
}

void ao_qpop_ptr_try(ao_qpop_ptr_t * QP)
{
    ao_qpop_ptr_begin(QP);

    ao_qpop_ptr_end(QP);
}

// ----------------------------------------------------------------------------

#endif

#if defined AO_RECV

// ----------------------------------------------------------------------------

void ao_recv(ao_recv_t * R, ao_time_t t)
{
    ao_recv_from(R, t, ao_now());
}

void ao_recv_begin(ao_recv_t * R)
{
    ao_assert(R);

    ao_recv_proc_t B = R->begin;

    if (B)
    {
        B(R);
    }
}

void ao_recv_end(ao_recv_t * R)
{
    ao_assert(R);

    ao_recv_proc_t E = R->end;

    if (E)
    {
        E(R);
    }
}

void ao_recv_forever(ao_recv_t * R)
{
    ao_recv_from(R, AO_INFINITY, 0);
}

void ao_recv_from(ao_recv_t * R, ao_time_t t, ao_time_t b)
{
    // Assert.

    ao_assert(R);


    // Ready.

    ao_recv_begin(R);

    ao_await_from(&R->async, t, b);

    ao_recv_end(R);
}

void ao_recv_try(ao_recv_t * R)
{
    ao_recv_begin(R);

    ao_recv_end(R);
}

// ----------------------------------------------------------------------------

#endif

#if defined AO_RECV_FROM_CALLBACK

// ----------------------------------------------------------------------------

static  void    ao_recv_from_callback_begin(ao_recv_t * x);

static  void    ao_recv_from_callback_end(  ao_recv_t * x);

// ----------------------------------------------------------------------------

void ao_recv_from_callback(ao_recv_t * R, ao_recv_proc_t C)
{
    // Assert.

    ao_assert(R);

    ao_assert(C);


    // Ready.

    R->begin = ao_recv_from_callback_begin;

    R->end = ao_recv_from_callback_end;

    R->parameter = C;
}

void ao_recv_from_callback_begin(ao_recv_t * R)
{
    // Assert.

    ao_assert(R);

    ao_assert(R->parameter);


    // Variables.

    ao_recv_proc_t C;


    // Ready.

    // The caller has exclusive access to #R all the time.

    // Therefore, it is safe to not lock the kernel.

    ao_async_begin(&R->async);

    C = R->parameter;

    C(R);

    ao_async_check(&R->async);
}

void ao_recv_from_callback_end(ao_recv_t * R)
{
    ao_assert(R);

    ao_async_end(&R->async);
}

// ----------------------------------------------------------------------------

#endif

#if defined AO_RECV_FROM_STREAM

// ----------------------------------------------------------------------------

static  void    ao_recv_from_stream_begin(  ao_recv_t * x);

static  void    ao_recv_from_stream_end(    ao_recv_t * x);

// ----------------------------------------------------------------------------

static  void    ao_recv_from_stream_checked(void * x);

// ----------------------------------------------------------------------------

void ao_recv_from_stream(ao_recv_t * R, ao_spop_t * P)
{
    // Assert.

    ao_assert(R);

    ao_assert(P);


    // Ready.

    R->begin = ao_recv_from_stream_begin;

    R->end = ao_recv_from_stream_end;

    R->parameter = P;
}

void ao_recv_from_stream_begin(ao_recv_t * R)
{
    // Assert.

    ao_assert(R);

    ao_assert(R->parameter);


    // Variables.

    ao_spop_t * P;


    // Ready.

    // Receive.

    ao_async_begin(&R->async);

    R->result = false;

    // Pop.

    P = R->parameter;

    P->async.callback = ao_recv_from_stream_checked;

    P->async.callback_parameter = R;

    P->count_max = R->count_max;

    P->count_min = R->count_min;

    P->ptr = R->ptr;

    ao_spop_begin(P);
}

void ao_recv_from_stream_checked(void * x)
{
    // Notes.

    // The kernel is locked.


    // Ready.

    ao_assert(x);

    ao_recv_t * R = x;

    ao_async_check(&R->async);
}

void ao_recv_from_stream_end(ao_recv_t * R)
{
    // Assert.

    ao_assert(R);

    ao_assert(R->parameter);


    // Variables.

    ao_spop_t * P;


    // Ready.

    // Pop.

    P = R->parameter;

    ao_spop_end(P);

    P->async.callback = NULL;

    P->async.callback_parameter = NULL;

    // Receive.

    R->count = P->count;

    R->result = P->result;

    ao_async_end(&R->async);
}

// ----------------------------------------------------------------------------

#endif

#if defined AO_RECV_OBJ

// ----------------------------------------------------------------------------

void ao_recv_obj(ao_recv_obj_t * R, ao_time_t t)
{
    ao_recv_obj_from(R, t, ao_now());
}

void ao_recv_obj_begin(ao_recv_obj_t * R)
{
    ao_assert(R);

    ao_recv_obj_proc_t B = R->begin;

    if (B)
    {
        B(R);
    }
}

void ao_recv_obj_end(ao_recv_obj_t * R)
{
    ao_assert(R);

    ao_recv_obj_proc_t E = R->end;

    if (E)
    {
        E(R);
    }
}

void ao_recv_obj_forever(ao_recv_obj_t * R)
{
    ao_recv_obj_from(R, AO_INFINITY, 0);
}

void ao_recv_obj_from(ao_recv_obj_t * R, ao_time_t t, ao_time_t b)
{
    // Assert.

    ao_assert(R);


    // Ready.

    ao_recv_obj_begin(R);

    ao_await_from(&R->async, t, b);

    ao_recv_obj_end(R);
}

void ao_recv_obj_try(ao_recv_obj_t * R)
{
    ao_recv_obj_begin(R);

    ao_recv_obj_end(R);
}

// ----------------------------------------------------------------------------

#endif

#if defined AO_RECV_OBJ_FROM_CALLBACK

// ----------------------------------------------------------------------------

static  void    ao_recv_obj_from_callback_begin(ao_recv_obj_t * x);

static  void    ao_recv_obj_from_callback_end(  ao_recv_obj_t * x);

// ----------------------------------------------------------------------------

void ao_recv_obj_from_callback(ao_recv_obj_t * R, ao_recv_obj_proc_t C)
{
    ao_assert(R);

    ao_assert(C);

    R->begin = ao_recv_obj_from_callback_begin;

    R->end = ao_recv_obj_from_callback_end;

    R->parameter = C;
}

void ao_recv_obj_from_callback_begin(ao_recv_obj_t * R)
{
    // Assert.

    ao_assert(R);

    ao_assert(R->parameter);


    // Variables.

    ao_recv_obj_proc_t C;


    // Ready.

    // The caller has exclusive access to #R all the time.

    // Therefore, it is safe to not lock the kernel.

    ao_async_begin(&R->async);

    C = R->parameter;

    C(R);

    ao_async_check(&R->async);
}

void ao_recv_obj_from_callback_end(ao_recv_obj_t * R)
{
    ao_assert(R);

    ao_async_end(&R->async);
}

// ----------------------------------------------------------------------------

#endif

#if defined AO_RECV_OBJ_FROM_QUEUE

// ----------------------------------------------------------------------------

static  void    ao_recv_obj_from_queue_begin(   ao_recv_obj_t * x);

static  void    ao_recv_obj_from_queue_end(     ao_recv_obj_t * x);

// ----------------------------------------------------------------------------

static  void    ao_recv_obj_from_queue_checked( void * x);

// ----------------------------------------------------------------------------

void ao_recv_obj_from_queue(ao_recv_obj_t * R, ao_qpop_obj_t * P)
{
    ao_assert(R);

    ao_assert(P);

    R->begin = ao_recv_obj_from_queue_begin;

    R->end = ao_recv_obj_from_queue_end;

    R->parameter = P;
}

void ao_recv_obj_from_queue_begin(ao_recv_obj_t * R)
{
    // Assert.

    ao_assert(R);

    ao_assert(R->parameter);


    // Variables.

    ao_qpop_obj_t * P;


    // Ready.

    // Receive.

    ao_async_begin(&R->async);

    R->result = false;

    // Pop.

    P = R->parameter;

    P->async.callback = ao_recv_obj_from_queue_checked;

    P->async.callback_parameter = R;

    P->ptr = R->ptr;

    ao_qpop_obj_begin(P);
}

void ao_recv_obj_from_queue_checked(void * x)
{
    // Notes.

    // The kernel is locked.


    // Ready.

    ao_assert(x);

    ao_recv_obj_t * R = x;

    ao_async_check(&R->async);
}

void ao_recv_obj_from_queue_end(ao_recv_obj_t * R)
{
    // Assert.

    ao_assert(R);

    ao_assert(R->parameter);


    // Variables.

    ao_qpop_obj_t * P;


    // Ready.

    // Pop.

    P = R->parameter;

    ao_qpop_obj_end(P);

    P->async.callback = NULL;

    P->async.callback_parameter = NULL;

    // Receive.

    R->result = P->result;

    ao_async_end(&R->async);
}

// ----------------------------------------------------------------------------

#endif

#if defined AO_RECV_OBJ_FROM_STREAM

// ----------------------------------------------------------------------------

static  void    ao_recv_obj_from_stream_begin(  ao_recv_obj_t * x);

static  void    ao_recv_obj_from_stream_end(    ao_recv_obj_t * x);

// ----------------------------------------------------------------------------

static  void    ao_recv_obj_from_stream_checked(void * x);

// ----------------------------------------------------------------------------

void ao_recv_obj_from_stream(ao_recv_obj_t * R, ao_spop_obj_t * P)
{
    ao_assert(R);

    ao_assert(P);

    R->begin = ao_recv_obj_from_stream_begin;

    R->end = ao_recv_obj_from_stream_end;

    R->parameter = P;
}

void ao_recv_obj_from_stream_begin(ao_recv_obj_t * R)
{
    // Assert.

    ao_assert(R);

    ao_assert(R->parameter);


    // Variables.

    ao_spop_obj_t * P;


    // Ready.

    // Receive.

    ao_async_begin(&R->async);

    R->result = false;

    // Pop.

    P = R->parameter;

    P->async.callback = ao_recv_obj_from_stream_checked;

    P->async.callback_parameter = R;

    P->ptr = R->ptr;

    ao_spop_obj_begin(P);
}

void ao_recv_obj_from_stream_checked(void * x)
{
    // Notes.

    // The kernel is locked.


    // Ready.

    ao_assert(x);

    ao_recv_obj_t * R = x;

    ao_async_check(&R->async);
}

void ao_recv_obj_from_stream_end(ao_recv_obj_t * R)
{
    // Assert.

    ao_assert(R);

    ao_assert(R->parameter);


    // Variables.

    ao_spop_obj_t * P;


    // Ready.

    // Pop.

    P = R->parameter;

    ao_spop_obj_end(P);

    P->async.callback = NULL;

    P->async.callback_parameter = NULL;

    // Receive.

    R->result = P->result;

    ao_async_end(&R->async);
}

// ----------------------------------------------------------------------------

#endif

#if defined AO_RECV_PTR

// ----------------------------------------------------------------------------

void ao_recv_ptr(ao_recv_ptr_t * R, ao_time_t t)
{
    ao_recv_ptr_from(R, t, ao_now());
}

void ao_recv_ptr_begin(ao_recv_ptr_t * R)
{
    ao_assert(R);

    ao_recv_ptr_proc_t B = R->begin;

    if (B)
    {
        B(R);
    }
}

void ao_recv_ptr_end(ao_recv_ptr_t * R)
{
    ao_assert(R);

    ao_recv_ptr_proc_t E = R->end;

    if (E)
    {
        E(R);
    }
}

void ao_recv_ptr_forever(ao_recv_ptr_t * R)
{
    ao_recv_ptr_from(R, AO_INFINITY, 0);
}

void ao_recv_ptr_from(ao_recv_ptr_t * R, ao_time_t t, ao_time_t b)
{
    // Assert.

    ao_assert(R);


    // Ready.

    ao_recv_ptr_begin(R);

    ao_await_from(&R->async, t, b);

    ao_recv_ptr_end(R);
}

void ao_recv_ptr_try(ao_recv_ptr_t * R)
{
    ao_recv_ptr_begin(R);

    ao_recv_ptr_end(R);
}

// ----------------------------------------------------------------------------

#endif

#if defined AO_RECV_PTR_FROM_CALLBACK

// ----------------------------------------------------------------------------

static  void    ao_recv_ptr_from_callback_begin(ao_recv_ptr_t * x);

static  void    ao_recv_ptr_from_callback_end(  ao_recv_ptr_t * x);

// ----------------------------------------------------------------------------

void ao_recv_ptr_from_callback(ao_recv_ptr_t * R, ao_recv_ptr_proc_t C)
{
    ao_assert(R);

    ao_assert(C);

    R->begin = ao_recv_ptr_from_callback_begin;

    R->end = ao_recv_ptr_from_callback_end;

    R->parameter = C;
}

void ao_recv_ptr_from_callback_begin(ao_recv_ptr_t * R)
{
    // Assert.

    ao_assert(R);

    ao_assert(R->parameter);


    // Variables.

    ao_recv_ptr_proc_t C;


    // Ready.

    // The caller has exclusive access to #R all the time.

    // Therefore, it is safe to not lock the kernel.

    ao_async_begin(&R->async);

    C = R->parameter;

    C(R);

    ao_async_check(&R->async);
}

void ao_recv_ptr_from_callback_end(ao_recv_ptr_t * R)
{
    ao_assert(R);

    ao_async_end(&R->async);
}

// ----------------------------------------------------------------------------

#endif

#if defined AO_RECV_PTR_FROM_QUEUE

// ----------------------------------------------------------------------------

static  void    ao_recv_ptr_from_queue_begin(   ao_recv_ptr_t * x);

static  void    ao_recv_ptr_from_queue_end(     ao_recv_ptr_t * x);

// ----------------------------------------------------------------------------

static  void    ao_recv_ptr_from_queue_checked( void * x);

// ----------------------------------------------------------------------------

void ao_recv_ptr_from_queue(ao_recv_ptr_t * R, ao_qpop_ptr_t * P)
{
    ao_assert(R);

    ao_assert(P);

    R->begin = ao_recv_ptr_from_queue_begin;

    R->end = ao_recv_ptr_from_queue_end;

    R->parameter = P;
}

void ao_recv_ptr_from_queue_begin(ao_recv_ptr_t * R)
{
    // Assert.

    ao_assert(R);

    ao_assert(R->parameter);


    // Variables.

    ao_qpop_ptr_t * P;


    // Ready.

    // Receive.

    ao_async_begin(&R->async);

    R->result = false;

    // Pop.

    P = R->parameter;

    P->async.callback = ao_recv_ptr_from_queue_checked;

    P->async.callback_parameter = R;

    ao_qpop_ptr_begin(P);
}

void ao_recv_ptr_from_queue_checked(void * x)
{
    // Notes.

    // The kernel is locked.


    // Ready.

    ao_assert(x);

    ao_recv_ptr_t * R = x;

    ao_async_check(&R->async);
}

void ao_recv_ptr_from_queue_end(ao_recv_ptr_t * R)
{
    // Assert.

    ao_assert(R);

    ao_assert(R->parameter);


    // Variables.

    ao_qpop_ptr_t * P;


    // Ready.

    // Pop.

    P = R->parameter;

    ao_qpop_ptr_end(P);

    P->async.callback = NULL;

    P->async.callback_parameter = NULL;

    // Receive.

    R->ptr = P->ptr;

    R->result = P->result;

    ao_async_end(&R->async);
}

// ----------------------------------------------------------------------------

#endif

#if defined AO_RECV_PTR_FROM_STREAM

// ----------------------------------------------------------------------------

static  void    ao_recv_ptr_from_stream_begin(  ao_recv_ptr_t * x);

static  void    ao_recv_ptr_from_stream_end(    ao_recv_ptr_t * x);

// ----------------------------------------------------------------------------

static  void    ao_recv_ptr_from_stream_checked(void * x);

// ----------------------------------------------------------------------------

void ao_recv_ptr_from_stream(ao_recv_ptr_t * R, ao_spop_ptr_t * P)
{
    ao_assert(R);

    ao_assert(P);

    R->begin = ao_recv_ptr_from_stream_begin;

    R->end = ao_recv_ptr_from_stream_end;

    R->parameter = P;
}

void ao_recv_ptr_from_stream_begin(ao_recv_ptr_t * R)
{
    // Assert.

    ao_assert(R);

    ao_assert(R->parameter);


    // Variables.

    ao_spop_ptr_t * P;


    // Ready.

    // Receive.

    ao_async_begin(&R->async);

    R->result = false;

    // Pop.

    P = R->parameter;

    P->async.callback = ao_recv_ptr_from_stream_checked;

    P->async.callback_parameter = R;

    ao_spop_ptr_begin(P);
}

void ao_recv_ptr_from_stream_checked(void * x)
{
    // Notes.

    // The kernel is locked.


    // Ready.

    ao_assert(x);

    ao_recv_ptr_t * R = x;

    ao_async_check(&R->async);
}

void ao_recv_ptr_from_stream_end(ao_recv_ptr_t * R)
{
    // Assert.

    ao_assert(R);

    ao_assert(R->parameter);


    // Variables.

    ao_spop_ptr_t * P;


    // Ready.

    // Pop.

    P = R->parameter;

    ao_spop_ptr_end(P);

    P->async.callback = NULL;

    P->async.callback_parameter = NULL;

    // Receive.

    R->ptr = P->ptr;

    R->result = P->result;

    ao_async_end(&R->async);
}

// ----------------------------------------------------------------------------

#endif

#if defined AO_RENDEZVOUS

// ----------------------------------------------------------------------------

void ao_rendezvous(ao_rendezvous_wait_t * W, ao_time_t t)
{
    ao_rendezvous_from(W, t, ao_now());
}

void ao_rendezvous_begin(ao_rendezvous_wait_t * W2)
{
    // Assert.

    ao_assert(W2);

    ao_assert(W2->rendezvous);


    // Variables.

    ao_rendezvous_exchange_t E1;

    ao_rendezvous_exchange_t E2;

    ao_lock_t L;

    ao_rendezvous_t * R;

    ao_rendezvous_wait_t * W1;


    // Ready.

    ao_async_begin(&W2->async);

    R = W2->rendezvous;

    ao_lock(&L);
    {
        W1 = R->wait;

        if (W1)
        {
            E1 = W1->exchange;

            E2 = W2->exchange;

            if (E1) { E1(W2->ptr_in, W1->ptr_out, W1->exchange_parameter); }

            if (E2) { E2(W1->ptr_in, W2->ptr_out, W2->exchange_parameter); }

            W1->result = true;

            W2->result = true;

            ao_async_check(&W1->async);

            ao_async_check(&W2->async);

            R->wait = NULL;
        }

        else
        {
            W2->result = false;

            R->wait = W2;
        }
    }
    ao_unlock(&L);
}

void ao_rendezvous_end(ao_rendezvous_wait_t * W)
{
    // Assert.

    ao_assert(W);

    ao_assert(W->rendezvous);


    // Variables.

    ao_lock_t L;


    // Ready.

    ao_lock(&L);
    {
        if (W->result) { }

        else
        {
            W->rendezvous->wait = NULL;
        }
    }
    ao_unlock(&L);

    ao_async_end(&W->async);
}

void ao_rendezvous_forever(ao_rendezvous_wait_t * W)
{
    ao_rendezvous_from(W, AO_INFINITY, 0);
}

void ao_rendezvous_from(ao_rendezvous_wait_t * W, ao_time_t t, ao_time_t b)
{
    // Assert.

    ao_assert(W);


    // Ready.

    ao_rendezvous_begin(W);

    ao_await_from(&W->async, t, b);

    ao_rendezvous_end(W);
}

void ao_rendezvous_try(ao_rendezvous_wait_t * W)
{
    ao_rendezvous_begin(W);

    ao_rendezvous_end(W);
}

// ----------------------------------------------------------------------------

#endif

#if defined AO_RW

// ----------------------------------------------------------------------------

bool ao_rw_lock_read(ao_rw_t * R, ao_time_t t)
{
    return ao_rw_lock_read_from(R, t, ao_now());
}

void ao_rw_lock_read_begin(ao_rw_lock_t * L)
{
    // Assert.

    ao_assert(L);

    ao_assert(L->rw);


    // Variables.

    ao_lock_t l;

    ao_rw_t * R;


    // Ready.

    R = L->rw;

    ao_async_begin(&L->async);

    ao_lock(&l);
    {
        // Writing in progress.

        if (R->w_active)
        {
            ao_list_push_back(&R->r_waiting, &L->node);

            L->result = false;
        }

        // Writing not in progress.

        else
        {
            R->r_active++;

            L->result = true;

            ao_async_check(&L->async);
        }
    }
    ao_unlock(&l);
}

void ao_rw_lock_read_end(ao_rw_lock_t * L)
{
    // Assert.

    ao_assert(L);

    ao_assert(L->rw);


    // Variables.

    ao_lock_t l;


    // Ready.

    ao_lock(&l);
    {
        if (L->result) { }

        else
        {
            ao_list_remove(&L->rw->r_waiting, &L->node);
        }
    }
    ao_unlock(&l);

    ao_async_end(&L->async);
}

bool ao_rw_lock_read_forever(ao_rw_t * R)
{
    return ao_rw_lock_read_from(R, AO_INFINITY, 0);
}

bool ao_rw_lock_read_from(ao_rw_t * R, ao_time_t t, ao_time_t b)
{
    // Variables.

    ao_rw_lock_t L;


    // Ready.

    ao_clear(&L, ao_rw_lock_t);

    L.rw = R;


    // Ready.

    ao_rw_lock_read_begin(&L);

    ao_await_from(&L.async, t, b);

    ao_rw_lock_read_end(&L);


    // Ready.

    return L.result;
}

bool ao_rw_lock_read_try(ao_rw_t * R)
{
    // Variables.

    ao_rw_lock_t L;


    // Ready.

    ao_clear(&L, ao_rw_lock_t);

    L.rw = R;


    // Ready.

    ao_rw_lock_read_begin(&L);

    ao_rw_lock_read_end(&L);


    // Ready.

    return L.result;
}

// ----------------------------------------------------------------------------

bool ao_rw_lock_write(ao_rw_t * R, ao_time_t t)
{
    return ao_rw_lock_write_from(R, t, ao_now());
}

void ao_rw_lock_write_begin(ao_rw_lock_t * L)
{
    // Assert.

    ao_assert(L);

    ao_assert(L->rw);


    // Variables.

    bool b1;

    bool b2;

    ao_lock_t l;

    ao_rw_t * R;


    // Ready.

    R = L->rw;

    ao_async_begin(&L->async);

    ao_lock(&l);
    {
        // Reading in progress.

        // Writing in progress.

        b1 = R->r_active > 0 ? true : false;

        b2 = R->w_active;

        if (b1 || b2)
        {
            ao_list_push_back(&R->w_waiting, &L->node);

            L->result = false;
        }

        // No reading.

        // No writing.

        else
        {
            ao_assert(ao_list_is_empty(&R->w_waiting));

            R->w_active = true;

            L->result = true;

            ao_async_check(&L->async);
        }
    }
    ao_unlock(&l);
}

void ao_rw_lock_write_end(ao_rw_lock_t * L)
{
    // Assert.

    ao_assert(L);

    ao_assert(L->rw);


    // Variables.

    ao_lock_t l;


    // Ready.

    ao_lock(&l);
    {
        if (L->result) { }

        else
        {
            ao_list_remove(&L->rw->w_waiting, &L->node);
        }
    }
    ao_unlock(&l);

    ao_async_end(&L->async);
}

bool ao_rw_lock_write_forever(ao_rw_t * R)
{
    return ao_rw_lock_write_from(R, AO_INFINITY, 0);
}

bool ao_rw_lock_write_from(ao_rw_t * R, ao_time_t t, ao_time_t b)
{
    // Variables.

    ao_rw_lock_t L;


    // Ready.

    ao_clear(&L, ao_rw_lock_t);

    L.rw = R;


    // Ready.

    ao_rw_lock_write_begin(&L);

    ao_await_from(&L.async, t, b);

    ao_rw_lock_write_end(&L);


    // Ready.

    return L.result;
}

bool ao_rw_lock_write_try(ao_rw_t * R)
{
    // Variables.

    ao_rw_lock_t L;


    // Ready.

    ao_clear(&L, ao_rw_lock_t);

    L.rw = R;


    // Ready.

    ao_rw_lock_write_begin(&L);

    ao_rw_lock_write_end(&L);


    // Ready.

    return L.result;
}

// ----------------------------------------------------------------------------

void ao_rw_unlock_read(ao_rw_t * R)
{
    // Assert.

    ao_assert(R);

    ao_assert(R->r_active > 0)

    ao_assert(R->w_active == false);


    // Variables.

    ao_lock_t l;

    ao_rw_lock_t * L;

    ao_list_node_t * n;

    ao_uint_t r;


    // Ready.

    ao_lock(&l);
    {
        r = R->r_active;

        r--;

        // Reading in progress.

        if (r) { }

        // No more reading.

        else
        {
            // Writing in standby.

            n = R->w_waiting.front;

            if (n)
            {
                ao_list_remove_front(&R->w_waiting);

                R->w_active = true;

                L = ao_containerof(n, ao_rw_lock_t, node);

                L->result = true;

                ao_async_check(&L->async);
            }

            // No more writing.

            else { }
        }

        R->r_active = r;
    }
    ao_unlock(&l);
}

// ----------------------------------------------------------------------------

void ao_rw_unlock_write(ao_rw_t * R)
{
    // Assert.

    ao_assert(R);

    ao_assert(R->r_active == 0);

    ao_assert(R->w_active == true);


    // Variables.

    ao_lock_t l;

    ao_rw_lock_t * L;

    ao_list_node_t * n;

    ao_uint_t r;


    // Ready.

    ao_lock(&l);
    {
        // Reading in standby.

        n = R->r_waiting.front;

        if (n)
        {
            r = 0;

            do
            {
                r++;

                L = ao_containerof(n, ao_rw_lock_t, node);

                L->result = true;

                ao_async_check(&L->async);

                n = n->next;
            }
            while (n);

            R->r_active = r;

            ao_list_remove_all(&R->r_waiting);

            R->w_active = false;
        }

        // No reading.

        else
        {
            // Writing in standby.

            n = R->w_waiting.front;

            if (n)
            {
                ao_list_remove_front(&R->w_waiting);

                L = ao_containerof(n, ao_rw_lock_t, node);

                L->result = true;

                ao_async_check(&L->async);
            }

            // No writing.

            else
            {
                R->w_active = false;
            }
        }
    }
    ao_unlock(&l);
}

// ----------------------------------------------------------------------------

#endif

#if defined AO_SELF

// ----------------------------------------------------------------------------

ao_task_t * ao_self()
{
    // Variables.

    ao_lock_t L;

    ao_task_t * T;


    // Ready.

    ao_lock(&L);
    {
        T = ao_self_locked();
    }
    ao_unlock(&L);

    return T;
}

ao_task_t * ao_self_locked()
{
    // Notes.

    // The kernel is locked.


    // Variables.

    ao_core_t c;

    size_t i;

    ao_task_t * T;


    // Ready.

    // The scheduler is free to dispatch the task to another core at any time.

    // Therefore, the kernel must be locked.

    c = ao_core();

    ao_assert(c < AO_CORE_COUNT);

    i = (size_t) c;

    T = ao_task_running[i];

    ao_assert(T);

    return T;
}

// ----------------------------------------------------------------------------

void ao_stop()
{
    ao_task_t * t = ao_self();

    ao_task_stop(t);

    while (ao_task_is_stopping(t)) { }
}

// ----------------------------------------------------------------------------

void ao_suspend()
{
    ao_task_t * t = ao_self();

    ao_task_suspend(t);

    while (ao_task_is_suspending(t)) { }
}

// ----------------------------------------------------------------------------

#endif

#if defined AO_SEM

// ----------------------------------------------------------------------------

void ao_sem_give(ao_sem_t * S, ao_uint_t c1)
{
    // Assert.

    ao_assert(S);


    // Variables.

    ao_uint_t c2;

    ao_lock_t L;

    ao_list_node_t * n1;

    ao_list_node_t * n2;

    ao_sem_take_t * T;


    // Ready.

    if (c1 > 0)
    {
        ao_lock(&L);
        {
            c1 = c1 + S->count;

            n1 = S->list.front;

            if (n1)
            {
                do
                {
                    T = ao_containerof(n1, ao_sem_take_t, node);

                    n2 = n1->next;

                    c2 = T->count;

                    if (c2 <= c1)
                    {
                        c1 = c1 - c2;

                        ao_list_remove(&S->list, n1);

                        T->result = true;

                        ao_async_check(&T->async);
                    }

                    n1 = n2;
                }
                while (n1 && c1 > 0);
            }

            S->count = c1;
        }
        ao_unlock(&L);
    }
}

// ----------------------------------------------------------------------------

bool ao_sem_take(ao_sem_t * S, ao_uint_t c, ao_time_t t)
{
    return ao_sem_take_from(S, c, t, ao_now());
}

void ao_sem_take_begin(ao_sem_take_t * T)
{
    // Assert.

    ao_assert(T);

    ao_assert(T->sem);


    // Variables.

    ao_uint_t cs;

    ao_uint_t ct;

    ao_lock_t L;

    ao_sem_t * S;


    // Ready.

    ao_async_begin(&T->async);

    ct = T->count;

    if (ct > 0)
    {
        S = T->sem;

        ao_lock(&L);
        {
            // Semaphore is available.

            cs = S->count;

            if (cs >= ct)
            {
                S->count = cs - ct;

                T->result = true;

                ao_async_check(&T->async);
            }

            // Semaphore is not available.

            else
            {
                T->result = false;

                ao_list_push_back(&S->list, &T->node);
            }
        }
        ao_unlock(&L);
    }

    else
    {
        T->result = true;

        ao_async_check(&T->async);
    }
}

void ao_sem_take_end(ao_sem_take_t * T)
{
    // Assert.

    ao_assert(T);

    ao_assert(T->sem);


    // Variables.

    ao_lock_t L;


    // Ready.

    ao_lock(&L);
    {
        if (T->result) { }

        else
        {
            ao_list_remove(&T->sem->list, &T->node);
        }
    }
    ao_unlock(&L);

    ao_async_end(&T->async);
}

bool ao_sem_take_forever(ao_sem_t * S, ao_uint_t c)
{
    return ao_sem_take_from(S, c, AO_INFINITY, 0);
}

bool ao_sem_take_from(ao_sem_t * S, ao_uint_t c, ao_time_t t, ao_time_t b)
{
    // Variables.

    ao_sem_take_t T;


    // Ready.

    ao_clear(&T, ao_sem_take_t);

    T.count = c;

    T.sem = S;


    ao_sem_take_begin(&T);

    ao_await_from(&T.async, t, b);

    ao_sem_take_end(&T);


    return T.result;
}

bool ao_sem_take_try(ao_sem_t * S, ao_uint_t c)
{
    // Variables.

    ao_sem_take_t T;


    // Ready.

    ao_clear(&T, ao_sem_take_t);

    T.count = c;

    T.sem = S;


    ao_sem_take_begin(&T);

    ao_sem_take_end(&T);


    return T.result;
}

// ----------------------------------------------------------------------------

#endif

#if defined AO_SEND

// ----------------------------------------------------------------------------

void ao_send(ao_send_t * S, ao_time_t t)
{
    ao_send_from(S, t, ao_now());
}

void ao_send_begin(ao_send_t * S)
{
    ao_assert(S);

    ao_send_proc_t B = S->begin;

    if (B)
    {
        B(S);
    }
}

void ao_send_end(ao_send_t * S)
{
    ao_assert(S);

    ao_send_proc_t E = S->end;

    if (E)
    {
        E(S);
    }
}

void ao_send_forever(ao_send_t * S)
{
    ao_send_from(S, AO_INFINITY, 0);
}

void ao_send_from(ao_send_t * S, ao_time_t t, ao_time_t b)
{
    // Assert.

    ao_assert(S);


    // Ready.

    ao_send_begin(S);

    ao_await_from(&S->async, t, b);

    ao_send_end(S);
}

void ao_send_try(ao_send_t * S)
{
    ao_send_begin(S);

    ao_send_end(S);
}

// ----------------------------------------------------------------------------

#endif

#if defined AO_SEND_OBJ

// ----------------------------------------------------------------------------

void ao_send_obj(ao_send_obj_t * S, ao_time_t t)
{
    ao_send_obj_from(S, t, ao_now());
}

void ao_send_obj_begin(ao_send_obj_t * S)
{
    ao_assert(S);

    ao_send_obj_proc_t B = S->begin;

    if (B)
    {
        B(S);
    }
}

void ao_send_obj_end(ao_send_obj_t * S)
{
    ao_assert(S);

    ao_send_obj_proc_t E = S->end;

    if (E)
    {
        E(S);
    }
}

void ao_send_obj_forever(ao_send_obj_t * S)
{
    ao_send_obj_from(S, AO_INFINITY, 0);
}

void ao_send_obj_from(ao_send_obj_t * S, ao_time_t t, ao_time_t b)
{
    // Assert.

    ao_assert(S);


    // Ready.

    ao_send_obj_begin(S);

    ao_await_from(&S->async, t, b);

    ao_send_obj_end(S);
}

void ao_send_obj_try(ao_send_obj_t * S)
{
    ao_send_obj_begin(S);

    ao_send_obj_end(S);
}

// ----------------------------------------------------------------------------

#endif

#if defined AO_SEND_OBJ_TO_CALLBACK

// ----------------------------------------------------------------------------

static  void    ao_send_obj_to_callback_begin(  ao_send_obj_t * x);

static  void    ao_send_obj_to_callback_end(    ao_send_obj_t * x);

// ----------------------------------------------------------------------------

void ao_send_obj_to_callback(ao_send_obj_t * S, ao_send_obj_proc_t C)
{
    ao_assert(S);

    ao_assert(C);

    S->begin = ao_send_obj_to_callback_begin;

    S->end = ao_send_obj_to_callback_end;

    S->parameter = C;
}

void ao_send_obj_to_callback_begin(ao_send_obj_t * S)
{
    // Assert.

    ao_assert(S);

    ao_assert(S->parameter);


    // Variables.

    ao_send_obj_proc_t C;


    // Ready.

    // The caller has exclusive access to #S all the time.

    // Therefore, it is safe to not lock the kernel.

    ao_async_begin(&S->async);

    C = S->parameter;

    C(S);

    ao_async_check(&S->async);
}

void ao_send_obj_to_callback_end(ao_send_obj_t * S)
{
    ao_assert(S);

    ao_async_end(&S->async);
}

// ----------------------------------------------------------------------------

#endif

#if defined AO_SEND_OBJ_TO_QUEUE

// ----------------------------------------------------------------------------

static  void    ao_send_obj_to_queue_begin(     ao_send_obj_t * x);

static  void    ao_send_obj_to_queue_end(       ao_send_obj_t * x);

// ----------------------------------------------------------------------------

static  void    ao_send_obj_to_queue_checked(   void * x);

// ----------------------------------------------------------------------------

void ao_send_obj_to_queue(ao_send_obj_t * S, ao_qinsert_obj_t * I)
{
    ao_assert(S);

    ao_assert(I);

    S->begin = ao_send_obj_to_queue_begin;

    S->end = ao_send_obj_to_queue_end;

    S->parameter = I;
}

void ao_send_obj_to_queue_begin(ao_send_obj_t * S)
{
    // Assert.

    ao_assert(S);

    ao_assert(S->parameter);


    // Variables.

    ao_qinsert_obj_t * I;


    // Ready.

    // Send.

    ao_async_begin(&S->async);

    S->result = false;

    // Insert.

    I = S->parameter;

    I->async.callback = ao_send_obj_to_queue_checked;

    I->async.callback_parameter = S;

    I->ptr = S->ptr;

    ao_qinsert_obj_begin(I);
}

void ao_send_obj_to_queue_checked(void * x)
{
    // Notes.

    // The kernel is locked.


    // Ready.

    ao_assert(x);

    ao_send_obj_t * S = x;

    ao_async_check(&S->async);
}

void ao_send_obj_to_queue_end(ao_send_obj_t * S)
{
    // Assert.

    ao_assert(S);

    ao_assert(S->parameter);


    // Variables.

    ao_qinsert_obj_t * I;


    // Ready.

    // Insert.

    I = S->parameter;

    ao_qinsert_obj_end(I);

    I->async.callback = NULL;

    I->async.callback_parameter = NULL;

    // Send.

    S->result = I->result;

    ao_async_end(&S->async);
}

// ----------------------------------------------------------------------------

#endif

#if defined AO_SEND_OBJ_TO_STREAM

// ----------------------------------------------------------------------------

static  void    ao_send_obj_to_stream_begin(            ao_send_obj_t * x);

static  void    ao_send_obj_to_stream_end(              ao_send_obj_t * x);

// ----------------------------------------------------------------------------

static  void    ao_send_obj_to_stream_checked(          void * x);

// ----------------------------------------------------------------------------

static  void    ao_send_obj_to_stream_override_begin(   ao_send_obj_t * x);

static  void    ao_send_obj_to_stream_override_end(     ao_send_obj_t * x);

// ----------------------------------------------------------------------------

void ao_send_obj_to_stream(ao_send_obj_t * S, ao_spush_obj_t * P)
{
    ao_assert(S);

    ao_assert(P);

    S->begin = ao_send_obj_to_stream_begin;

    S->end = ao_send_obj_to_stream_end;

    S->parameter = P;
}

void ao_send_obj_to_stream_begin(ao_send_obj_t * S)
{
    // Assert.

    ao_assert(S);

    ao_assert(S->parameter);


    // Variables.

    ao_spush_obj_t * P;


    // Ready.

    // Send.

    ao_async_begin(&S->async);

    S->result = false;

    // Push.

    P = S->parameter;

    P->async.callback = ao_send_obj_to_stream_checked;

    P->async.callback_parameter = S;

    P->ptr = S->ptr;

    ao_spush_obj_begin(P);
}

void ao_send_obj_to_stream_checked(void * x)
{
    // Notes.

    // The kernel is locked.


    // Ready.

    ao_assert(x);

    ao_send_obj_t * S = x;

    ao_async_check(&S->async);
}

void ao_send_obj_to_stream_end(ao_send_obj_t * S)
{
    // Assert.

    ao_assert(S);

    ao_assert(S->parameter);


    // Variables.

    ao_spush_obj_t * P;


    // Ready.

    // Push.

    P = S->parameter;

    ao_spush_obj_end(P);

    P->async.callback = NULL;

    P->async.callback_parameter = NULL;

    // Send.

    S->result = P->result;

    ao_async_end(&S->async);
}

// ----------------------------------------------------------------------------

void ao_send_obj_to_stream_override(ao_send_obj_t * S, ao_spush_obj_t * P)
{
    ao_assert(S);

    ao_assert(P);

    S->begin = ao_send_obj_to_stream_override_begin;

    S->end = ao_send_obj_to_stream_override_end;

    S->parameter = P;
}

void ao_send_obj_to_stream_override_begin(ao_send_obj_t * S)
{
    // Assert.

    ao_assert(S);

    ao_assert(S->parameter);


    // Variables.

    ao_spush_obj_t * P;


    // Ready.

    // Push.

    P = S->parameter;

    P->ptr = S->ptr;

    ao_spush_obj_override(P);

    // Send.

    // The caller has exclusive access to #S all the time.

    // Therefore, it is safe to not lock the kernel.

    ao_async_begin(&S->async);

    S->result = P->result;

    ao_async_check(&S->async);
}

void ao_send_obj_to_stream_override_end(ao_send_obj_t * S)
{
    ao_assert(S);

    ao_async_end(&S->async);
}

// ----------------------------------------------------------------------------

#endif

#if defined AO_SEND_PTR

// ----------------------------------------------------------------------------

void ao_send_ptr(ao_send_ptr_t * S, ao_time_t t)
{
    ao_send_ptr_from(S, t, ao_now());
}

void ao_send_ptr_begin(ao_send_ptr_t * S)
{
    ao_assert(S);

    ao_send_ptr_proc_t B = S->begin;

    if (B)
    {
        B(S);
    }
}

void ao_send_ptr_end(ao_send_ptr_t * S)
{
    ao_assert(S);

    ao_send_ptr_proc_t E = S->end;

    if (E)
    {
        E(S);
    }
}

void ao_send_ptr_forever(ao_send_ptr_t * S)
{
    ao_send_ptr_from(S, AO_INFINITY, 0);
}

void ao_send_ptr_from(ao_send_ptr_t * S, ao_time_t t, ao_time_t b)
{
    // Assert.

    ao_assert(S);


    // Ready.

    ao_send_ptr_begin(S);

    ao_await_from(&S->async, t, b);

    ao_send_ptr_end(S);
}

void ao_send_ptr_try(ao_send_ptr_t * S)
{
    ao_send_ptr_begin(S);

    ao_send_ptr_end(S);
}

// ----------------------------------------------------------------------------

#endif

#if defined AO_SEND_PTR_TO_CALLBACK

// ----------------------------------------------------------------------------

static  void    ao_send_ptr_to_callback_begin(  ao_send_ptr_t * x);

static  void    ao_send_ptr_to_callback_end(    ao_send_ptr_t * x);

// ----------------------------------------------------------------------------

void ao_send_ptr_to_callback(ao_send_ptr_t * S, ao_send_ptr_proc_t C)
{
    ao_assert(S);

    ao_assert(C);

    S->begin = ao_send_ptr_to_callback_begin;

    S->end = ao_send_ptr_to_callback_end;

    S->parameter = C;
}

void ao_send_ptr_to_callback_begin(ao_send_ptr_t * S)
{
    // Assert.

    ao_assert(S);

    ao_assert(S->parameter);


    // Variables.

    ao_send_ptr_proc_t C;


    // Ready.

    // The caller has exclusive access to #S all the time.

    // Therefore, it is safe to not lock the kernel.

    ao_async_begin(&S->async);

    C = S->parameter;

    C(S);

    ao_async_check(&S->async);
}

void ao_send_ptr_to_callback_end(ao_send_ptr_t * S)
{
    ao_assert(S);

    ao_async_end(&S->async);
}

// ----------------------------------------------------------------------------

#endif

#if defined AO_SEND_PTR_TO_QUEUE

// ----------------------------------------------------------------------------

static  void    ao_send_acq_to_queue_begin(     ao_send_ptr_t * x);

static  void    ao_send_acq_to_queue_end(       ao_send_ptr_t * x);

// ----------------------------------------------------------------------------

static  void    ao_send_acq_to_queue_checked(   void * x);

// ----------------------------------------------------------------------------

static  void    ao_send_ptr_to_queue_begin(     ao_send_ptr_t * x);

static  void    ao_send_ptr_to_queue_end(       ao_send_ptr_t * x);

// ----------------------------------------------------------------------------

static  void    ao_send_ptr_to_queue_checked(   void * x);

// ----------------------------------------------------------------------------

void ao_send_acq_to_queue(ao_send_ptr_t * S, ao_qinsert_ptr_t * I)
{
    ao_assert(S);

    ao_assert(I);

    S->begin = ao_send_acq_to_queue_begin;

    S->end = ao_send_acq_to_queue_end;

    S->parameter = I;
}

void ao_send_acq_to_queue_begin(ao_send_ptr_t * S)
{
    // Assert.

    ao_assert(S);

    ao_assert(S->parameter);


    // Variables.

    ao_qinsert_ptr_t * I;


    // Ready.

    // Send.

    ao_async_begin(&S->async);

    S->result = false;

    // Insert.

    I = S->parameter;

    I->async.callback = ao_send_acq_to_queue_checked;

    I->async.callback_parameter = S;

    I->ptr = S->ptr;

    ao_qinsert_acq_begin(I);
}

void ao_send_acq_to_queue_checked(void * x)
{
    // Notes.

    // The kernel is locked.


    // Ready.

    ao_assert(x);

    ao_send_ptr_t * S = x;

    ao_async_check(&S->async);
}

void ao_send_acq_to_queue_end(ao_send_ptr_t * S)
{
    // Assert.

    ao_assert(S);

    ao_assert(S->parameter);


    // Variables.

    ao_qinsert_ptr_t * I;


    // Ready.

    // Insert.

    I = S->parameter;

    ao_qinsert_acq_end(I);

    I->async.callback = NULL;

    I->async.callback_parameter = NULL;

    // Send.

    S->result = I->result;

    ao_async_end(&S->async);
}

// ----------------------------------------------------------------------------

void ao_send_ptr_to_queue(ao_send_ptr_t * S, ao_qinsert_ptr_t * I)
{
    ao_assert(S);

    ao_assert(I);

    S->begin = ao_send_ptr_to_queue_begin;

    S->end = ao_send_ptr_to_queue_end;

    S->parameter = I;
}

void ao_send_ptr_to_queue_begin(ao_send_ptr_t * S)
{
    // Assert.

    ao_assert(S);

    ao_assert(S->parameter);


    // Variables.

    ao_qinsert_ptr_t * I;


    // Ready.

    // Send.

    ao_async_begin(&S->async);

    S->result = false;

    // Insert.

    I = S->parameter;

    I->async.callback = ao_send_ptr_to_queue_checked;

    I->async.callback_parameter = S;

    I->ptr = S->ptr;

    ao_qinsert_ptr_begin(I);
}

void ao_send_ptr_to_queue_checked(void * x)
{
    // Notes.

    // The kernel is locked.


    // Ready.

    ao_assert(x);

    ao_send_ptr_t * S = x;

    ao_async_check(&S->async);
}

void ao_send_ptr_to_queue_end(ao_send_ptr_t * S)
{
    // Assert.

    ao_assert(S);

    ao_assert(S->parameter);


    // Variables.

    ao_qinsert_ptr_t * I;


    // Ready.

    // Insert.

    I = S->parameter;

    ao_qinsert_ptr_end(I);

    I->async.callback = NULL;

    I->async.callback_parameter = NULL;

    // Send.

    S->result = I->result;

    ao_async_end(&S->async);
}

// ----------------------------------------------------------------------------

#endif

#if defined AO_SEND_PTR_TO_STREAM

// ----------------------------------------------------------------------------

static  void    ao_send_acq_to_stream_begin(            ao_send_ptr_t * x);

static  void    ao_send_acq_to_stream_end(              ao_send_ptr_t * x);

// ----------------------------------------------------------------------------

static  void    ao_send_acq_to_stream_checked(          void * x);

// ----------------------------------------------------------------------------

static  void    ao_send_acq_to_stream_override_begin(   ao_send_ptr_t * x);

static  void    ao_send_acq_to_stream_override_end(     ao_send_ptr_t * x);

// ----------------------------------------------------------------------------

static  void    ao_send_ptr_to_stream_begin(            ao_send_ptr_t * x);

static  void    ao_send_ptr_to_stream_end(              ao_send_ptr_t * x);

// ----------------------------------------------------------------------------

static  void    ao_send_ptr_to_stream_checked(          void * x);

// ----------------------------------------------------------------------------

static  void    ao_send_ptr_to_stream_override_begin(   ao_send_ptr_t * x);

static  void    ao_send_ptr_to_stream_override_end(     ao_send_ptr_t * x);

// ----------------------------------------------------------------------------

void ao_send_acq_to_stream(ao_send_ptr_t * S, ao_spush_ptr_t * P)
{
    ao_assert(S);

    ao_assert(P);

    S->begin = ao_send_acq_to_stream_begin;

    S->end = ao_send_acq_to_stream_end;

    S->parameter = P;
}

void ao_send_acq_to_stream_begin(ao_send_ptr_t * S)
{
    // Assert.

    ao_assert(S);

    ao_assert(S->parameter);


    // Variables.

    ao_spush_ptr_t * P;


    // Ready.

    // Send.

    ao_async_begin(&S->async);

    S->result = false;

    // Push.

    P = S->parameter;

    P->async.callback = ao_send_acq_to_stream_checked;

    P->async.callback_parameter = S;

    P->ptr = S->ptr;

    ao_spush_acq_begin(P);
}

void ao_send_acq_to_stream_checked(void * x)
{
    // Notes.

    // The kernel is locked.


    // Ready.

    ao_assert(x);

    ao_send_ptr_t * S = x;

    ao_async_check(&S->async);
}

void ao_send_acq_to_stream_end(ao_send_ptr_t * S)
{
    // Assert.

    ao_assert(S);

    ao_assert(S->parameter);


    // Variables.

    ao_spush_ptr_t * P;


    // Ready.

    // Push.

    P = S->parameter;

    ao_spush_acq_end(P);

    P->async.callback = NULL;

    P->async.callback_parameter = NULL;

    // Send.

    S->result = P->result;

    ao_async_end(&S->async);
}

// ----------------------------------------------------------------------------

void ao_send_acq_to_stream_override(ao_send_ptr_t * S, ao_spush_ptr_t * P)
{
    ao_assert(S);

    ao_assert(P);

    S->begin = ao_send_acq_to_stream_override_begin;

    S->end = ao_send_acq_to_stream_override_end;

    S->parameter = P;
}

void ao_send_acq_to_stream_override_begin(ao_send_ptr_t * S)
{
    // Assert.

    ao_assert(S);

    ao_assert(S->parameter);


    // Variables.

    ao_spush_ptr_t * P;


    // Ready.

    // Push.

    P = S->parameter;

    P->ptr = S->ptr;

    ao_spush_acq_override(P);

    // Send.

    // The caller has exclusive access to #S all the time.

    // Therefore, it is safe to not lock the kernel.

    ao_async_begin(&S->async);

    S->result = P->result;

    ao_async_check(&S->async);
}

void ao_send_acq_to_stream_override_end(ao_send_ptr_t * S)
{
    ao_assert(S);

    ao_async_end(&S->async);
}

// ----------------------------------------------------------------------------

void ao_send_ptr_to_stream(ao_send_ptr_t * S, ao_spush_ptr_t * P)
{
    ao_assert(S);

    ao_assert(P);

    S->begin = ao_send_ptr_to_stream_begin;

    S->end = ao_send_ptr_to_stream_end;

    S->parameter = P;
}

void ao_send_ptr_to_stream_begin(ao_send_ptr_t * S)
{
    // Assert.

    ao_assert(S);

    ao_assert(S->parameter);


    // Variables.

    ao_spush_ptr_t * P;


    // Ready.

    // Send.

    ao_async_begin(&S->async);

    S->result = false;

    // Push.

    P = S->parameter;

    P->async.callback = ao_send_ptr_to_stream_checked;

    P->async.callback_parameter = S;

    P->ptr = S->ptr;

    ao_spush_ptr_begin(P);
}

void ao_send_ptr_to_stream_checked(void * x)
{
    // Notes.

    // The kernel is locked.


    // Ready.

    ao_assert(x);

    ao_send_ptr_t * S = x;

    ao_async_check(&S->async);
}

void ao_send_ptr_to_stream_end(ao_send_ptr_t * S)
{
    // Assert.

    ao_assert(S);

    ao_assert(S->parameter);


    // Variables.

    ao_spush_ptr_t * P;


    // Ready.

    // Push.

    P = S->parameter;

    ao_spush_ptr_end(P);

    P->async.callback = NULL;

    P->async.callback_parameter = NULL;

    // Send.

    S->result = P->result;

    ao_async_end(&S->async);
}

// ----------------------------------------------------------------------------

void ao_send_ptr_to_stream_override(ao_send_ptr_t * S, ao_spush_ptr_t * P)
{
    ao_assert(S);

    ao_assert(P);

    S->begin = ao_send_ptr_to_stream_override_begin;

    S->end = ao_send_ptr_to_stream_override_end;

    S->parameter = P;
}

void ao_send_ptr_to_stream_override_begin(ao_send_ptr_t * S)
{
    // Assert.

    ao_assert(S);

    ao_assert(S->parameter);


    // Variables.

    ao_spush_ptr_t * P;


    // Ready.

    // Push.

    P = S->parameter;

    P->ptr = S->ptr;

    ao_spush_ptr_override(P);

    // Send.

    // The caller has exclusive access to #S all the time.

    // Therefore, it is safe to not lock the kernel.

    ao_async_begin(&S->async);

    S->result = P->result;

    ao_async_check(&S->async);
}

void ao_send_ptr_to_stream_override_end(ao_send_ptr_t * S)
{
    ao_assert(S);

    ao_async_end(&S->async);
}

// ----------------------------------------------------------------------------

#endif

#if defined AO_SEND_TO_CALLBACK

// ----------------------------------------------------------------------------

static  void    ao_send_to_callback_begin(  ao_send_t * x);

static  void    ao_send_to_callback_end(    ao_send_t * x);

// ----------------------------------------------------------------------------

void ao_send_to_callback(ao_send_t * S, ao_send_proc_t C)
{
    // Assert.

    ao_assert(S);

    ao_assert(C);


    // Ready.

    S->begin = ao_send_to_callback_begin;

    S->end = ao_send_to_callback_end;

    S->parameter = C;
}

void ao_send_to_callback_begin(ao_send_t * S)
{
    // Assert.

    ao_assert(S);

    ao_assert(S->parameter);


    // Variables.

    ao_send_proc_t C;


    // Ready.

    // The caller has exclusive access to #S all the time.

    // Therefore, it is safe to not lock the kernel.

    ao_async_begin(&S->async);

    C = S->parameter;

    C(S);

    ao_async_check(&S->async);
}

void ao_send_to_callback_end(ao_send_t * S)
{
    ao_assert(S);

    ao_async_end(&S->async);
}

// ----------------------------------------------------------------------------

#endif

#if defined AO_SEND_TO_STREAM

// ----------------------------------------------------------------------------

static  void    ao_send_to_stream_begin(    ao_send_t * x);

static  void    ao_send_to_stream_end(      ao_send_t * x);

// ----------------------------------------------------------------------------

static  void    ao_send_to_stream_checked(  void * x);

// ----------------------------------------------------------------------------

void ao_send_to_stream(ao_send_t * S, ao_spush_t * P)
{
    // Assert.

    ao_assert(S);

    ao_assert(P);


    // Ready.

    S->begin = ao_send_to_stream_begin;

    S->end = ao_send_to_stream_end;

    S->parameter = P;
}

void ao_send_to_stream_begin(ao_send_t * S)
{
    // Assert.

    ao_assert(S);

    ao_assert(S->parameter);


    // Variables.

    ao_spush_t * P;


    // Ready.

    // Send.

    ao_async_begin(&S->async);

    S->result = false;

    // Push.

    P = S->parameter;

    P->async.callback = ao_send_to_stream_checked;

    P->async.callback_parameter = S;

    P->count_max = S->count_max;

    P->count_min = S->count_min;

    P->ptr = S->ptr;

    ao_spush_begin(P);
}

void ao_send_to_stream_checked(void * x)
{
    // Notes.

    // The kernel is locked.


    // Ready.

    ao_assert(x);

    ao_send_t * S = x;

    ao_async_check(&S->async);
}

void ao_send_to_stream_end(ao_send_t * S)
{
    // Assert.

    ao_assert(S);

    ao_assert(S->parameter);


    // Variables.

    ao_spush_t * P;


    // Ready.

    // Push.

    P = S->parameter;

    ao_spush_end(P);

    P->async.callback = NULL;

    P->async.callback_parameter = NULL;

    // Send.

    S->count = P->count;

    S->result = P->result;

    ao_async_end(&S->async);
}

// ----------------------------------------------------------------------------

#endif

#if defined AO_SIGNAL

// ----------------------------------------------------------------------------

void ao_signal_notify(ao_signal_t * S)
{
    // Assert.

    ao_assert(S);


    // Variables.

    ao_lock_t L;

    ao_list_node_t * n;

    ao_signal_wait_t * W;


    // Ready.

    ao_lock(&L);
    {
        n = S->list.front;

        if (n)
        {
            W = ao_containerof(n, ao_signal_wait_t, node);

            W->result = true;

            ao_async_check(&W->async);

            ao_list_remove_front(&S->list);
        }
    }
    ao_unlock(&L);
}

void ao_signal_notify_all(ao_signal_t * S)
{
    // Assert.

    ao_assert(S);


    // Variables.

    ao_lock_t L;

    ao_list_node_t * n;

    ao_signal_wait_t * W;


    // Ready.

    ao_lock(&L);
    {
        n = S->list.front;

        if (n)
        {
            do
            {
                W = ao_containerof(n, ao_signal_wait_t, node);

                W->result = true;

                ao_async_check(&W->async);

                n = n->next;
            }
            while (n);

            ao_list_remove_all(&S->list);
        }
    }
    ao_unlock(&L);
}

// ----------------------------------------------------------------------------

bool ao_signal_wait(ao_signal_t * S, ao_time_t t)
{
    return ao_signal_wait_from(S, t, ao_now());
}

void ao_signal_wait_begin(ao_signal_wait_t * W)
{
    // Assert.

    ao_assert(W);

    ao_assert(W->signal);


    // Variables.

    ao_lock_t L;


    // Ready.

    ao_async_begin(&W->async);

    ao_lock(&L);
    {
        ao_list_push_back(&W->signal->list, &W->node);

        W->result = false;
    }
    ao_unlock(&L);
}

void ao_signal_wait_end(ao_signal_wait_t * W)
{
    // Assert.

    ao_assert(W);

    ao_assert(W->signal);


    // Variables.

    ao_lock_t L;


    // Ready.

    ao_lock(&L);
    {
        if (W->result) { }

        else
        {
            ao_list_remove(&W->signal->list, &W->node);
        }
    }
    ao_unlock(&L);

    ao_async_end(&W->async);
}

bool ao_signal_wait_forever(ao_signal_t * S)
{
    return ao_signal_wait_from(S, AO_INFINITY, 0);
}

bool ao_signal_wait_from(ao_signal_t * S, ao_time_t t, ao_time_t b)
{
    // Variables.

    ao_signal_wait_t W;


    // Ready.

    ao_clear(&W, ao_signal_wait_t);

    W.signal = S;


    ao_signal_wait_begin(&W);

    ao_await_from(&W.async, t, b);

    ao_signal_wait_end(&W);


    return W.result;
}

// ----------------------------------------------------------------------------

#endif

#if defined AO_SLEEP

// ----------------------------------------------------------------------------

static  void    ao_sleep_callback(void * x);

// ----------------------------------------------------------------------------

bool ao_sleep(ao_time_t t)
{
    return ao_sleep_from(t, ao_now());
}

void ao_sleep_begin(ao_sleep_t * S)
{
    // Assert.

    ao_assert(S);


    // Variables.

    ao_alarm_t * A = &S->alarm;


    // Ready.

    ao_async_begin(&S->async);

    // The alarm is not running.

    // Hence, the caller has exclusive access to #s.

    S->result = false;

    A->callback = ao_sleep_callback;

    A->callback_parameter = S;

    ao_alarm_start_from(A, S->timeout, S->beginning);

    // The alarm interrupt could kick in at any time.

    // Hence, the caller does not have exclusive access to #s any more.
}

void ao_sleep_callback(void * x)
{
    // Notes.

    // This is an alarm callback.

    // The kernel is not locked.


    // Assert.

    ao_assert(x);


    // Variables.

    ao_lock_t L;

    ao_sleep_t * S;


    // Ready.

    S = x;

    ao_lock(&L);
    {
        S->result = true;

        ao_async_check(&S->async);
    }
    ao_unlock(&L);
}

void ao_sleep_end(ao_sleep_t * S)
{
    // Assert.

    ao_assert(S);


    // Ready.

    // The alarm is possibly still running.

    // The alarm interrupt could kick in at any time.

    // Hence, the caller does not have exclusive access to #s.

    ao_alarm_stop(&S->alarm);

    // The caller has regained exclusive access to the sleep object.

    ao_async_end(&S->async);
}

bool ao_sleep_forever()
{
    return ao_sleep_from(AO_INFINITY, 0);
}

bool ao_sleep_from(ao_time_t t, ao_time_t b)
{
    // Variables.

    ao_sleep_t S;


    // Ready.

    ao_clear(&S, ao_sleep_t);

    S.beginning = b;

    S.timeout = t;


    ao_sleep_begin(&S);

    ao_await(&S.async, AO_INFINITY);

    ao_sleep_end(&S);


    return S.result;
}

// ----------------------------------------------------------------------------

#endif

#if defined AO_SPIN

// ----------------------------------------------------------------------------

void ao_spin(ao_time_t t)
{
    ao_spin_from(t, ao_now());
}

void ao_spin_forever()
{
    while (1) { }
}

void ao_spin_from(ao_time_t t, ao_time_t b)
{
    // Variables.

    ao_time_t e;

    ao_time_t x;


    // Ready.

    if (t == AO_INFINITY)
    {
        ao_spin_forever();
    }

    e = ao_now();

    x = e - b;

    if (t > x)
    {
        t = t - x;

        while (t > 0)
        {
            b = e;

            e = ao_now();

            x = e - b;

            t = t > x ? t - x : 0;
        }
    }
}

// ----------------------------------------------------------------------------

#endif

#if defined AO_STREAM

// ----------------------------------------------------------------------------

void ao_spop(ao_spop_t * PO, ao_time_t t)
{
    ao_spop_from(PO, t, ao_now());
}

void ao_spop_begin(ao_spop_t * PO)
{
    // Assert.

    ao_assert(PO);

    ao_assert(PO->stream);


    // Variables.

    ao_buffer_t * B;

    size_t c;

    ao_lock_t L;

    ao_spush_t * PU;

    ao_stream_t * S;


    // Ready.

    S = PO->stream;

    ao_async_begin(&PO->async);

    ao_lock(&L);
    {
        if (S->pop)
        {
            PO->result = false;

            ao_async_check(&PO->async);
        }

        else
        {
            // Pop.

            B = &S->buffer;

            c = ao_buffer_pop_range_front(B, PO->ptr, PO->count_min, PO->count_max);

            // Popping failed.

            if (c < PO->count_min)
            {
                PO->result = false;

                S->pop = PO;
            }

            // Popping succeeded.

            else
            {
                PO->count = c;

                PO->result = true;

                ao_async_check(&PO->async);

                // Push.

                PU = S->push;

                if (PU)
                {
                    c = ao_buffer_push_range_back(B, PU->ptr, PU->count_min, PU->count_max);

                    // Pushing failed.

                    if (c < PU->count_min) { }

                    // Pushing succeeded.

                    else
                    {
                        S->push = NULL;

                        PU->count = c;

                        PU->result = true;

                        ao_async_check(&PU->async);
                    }
                }
            }
        }
    }
    ao_unlock(&L);
}

void ao_spop_end(ao_spop_t * PO)
{
    // Assert.

    ao_assert(PO);

    ao_assert(PO->stream);


    // Variables.

    ao_lock_t L;

    ao_stream_t * S;


    // Ready.

    ao_lock(&L);
    {
        if (PO->result) { }

        else
        {
            S = PO->stream;

            if (S->pop == PO)
            {
                S->pop = NULL;
            }
        }
    }
    ao_unlock(&L);

    ao_async_end(&PO->async);
}

void ao_spop_forever(ao_spop_t * PO)
{
    ao_spop_from(PO, AO_INFINITY, 0);
}

void ao_spop_from(ao_spop_t * PO, ao_time_t t, ao_time_t b)
{
    // Assert.

    ao_assert(PO);


    // Ready.

    ao_spop_begin(PO);

    ao_await_from(&PO->async, t, b);

    ao_spop_end(PO);
}

void ao_spop_try(ao_spop_t * PO)
{
    ao_spop_begin(PO);

    ao_spop_end(PO);
}

// ----------------------------------------------------------------------------

void ao_spush(ao_spush_t * PU, ao_time_t t)
{
    ao_spush_from(PU, t, ao_now());
}

void ao_spush_begin(ao_spush_t * PU)
{
    // Assert.

    ao_assert(PU);

    ao_assert(PU->stream);


    // Variables.

    ao_buffer_t * B;

    size_t c;

    ao_lock_t L;

    ao_spop_t * PO;

    ao_stream_t * S;


    // Ready.

    S = PU->stream;

    ao_async_begin(&PU->async);

    ao_lock(&L);
    {
        if (S->push)
        {
            PU->result = false;

            ao_async_check(&PU->async);
        }

        else
        {
            // Push.

            B = &S->buffer;

            c = ao_buffer_push_range_back(B, PU->ptr, PU->count_min, PU->count_max);

            // Pushing failed.

            if (c < PU->count_min)
            {
                PU->result = false;

                S->push = PU;
            }

            // Pushing succeded.

            else
            {
                PU->count = c;

                PU->result = true;

                ao_async_check(&PU->async);

                // Pop.

                PO = S->pop;

                if (PO)
                {
                    c = ao_buffer_pop_range_front(B, PO->ptr, PO->count_min, PO->count_max);

                    // Popping failed.

                    if (c < PO->count_min) { }

                    // Popping succeeded.

                    else
                    {
                        S->pop = NULL;

                        PO->count = c;

                        PO->result = true;

                        ao_async_check(&PO->async);
                    }
                }
            }
        }
    }
    ao_unlock(&L);
}

void ao_spush_end(ao_spush_t * PU)
{
    // Assert.

    ao_assert(PU);

    ao_assert(PU->stream);


    // Variables.

    ao_lock_t L;

    ao_stream_t * S;


    // Ready.

    ao_lock(&L);
    {
        if (PU->result) { }

        else
        {
            S = PU->stream;

            if (S->push == PU)
            {
                S->push = NULL;
            }
        }
    }
    ao_unlock(&L);

    ao_async_end(&PU->async);
}

void ao_spush_forever(ao_spush_t * PU)
{
    ao_spush_from(PU, AO_INFINITY, 0);
}

void ao_spush_from(ao_spush_t * PU, ao_time_t t, ao_time_t b)
{
    // Assert.

    ao_assert(PU);


    // Ready.

    ao_spush_begin(PU);

    ao_await_from(&PU->async, t, b);

    ao_spush_end(PU);
}

void ao_spush_override(ao_spush_t * PU)
{
    // Assert.

    ao_assert(PU);

    ao_assert(PU->stream);


    // Variables.

    ao_buffer_t * B;

    size_t c;

    ao_lock_t L;

    ao_spop_t * PO;

    ao_stream_t * S;


    // Ready.

    S = PU->stream;

    ao_lock(&L);
    {
        if (S->push)
        {
            PU->result = false;
        }

        else
        {
            // Push.

            B = &S->buffer;

            c = ao_buffer_push_range_back_override(B, PU->ptr, PU->count_min, PU->count_max);

            // Pushing failed.

            if (c < PU->count_min)
            {
                PU->result = false;
            }

            // Pushing succeded.

            else
            {
                PU->count = c;

                PU->result = true;

                // Pop.

                PO = S->pop;

                if (PO)
                {
                    c = ao_buffer_pop_range_front(B, PO->ptr, PO->count_min, PO->count_max);

                    // Popping failed.

                    if (c < PO->count_min) { }

                    // Popping succeeded.

                    else
                    {
                        S->pop = NULL;

                        PO->count = c;

                        PO->result = true;

                        ao_async_check(&PO->async);
                    }
                }
            }
        }
    }
    ao_unlock(&L);
}

void ao_spush_try(ao_spush_t * PU)
{
    ao_spush_begin(PU);

    ao_spush_end(PU);
}

// ----------------------------------------------------------------------------

#endif

#if defined AO_STREAM4OBJ

// ----------------------------------------------------------------------------

void ao_spop_obj(ao_spop_obj_t * PO, ao_time_t t)
{
    ao_spop_obj_from(PO, t, ao_now());
}

void ao_spop_obj_begin(ao_spop_obj_t * PO)
{
    // Assert.

    ao_assert(PO);

    ao_assert(PO->stream);


    // Variables.

    ao_buffer4obj_t * B;

    ao_list_t * l;

    ao_lock_t L;

    ao_list_node_t * n;

    ao_spush_obj_t * PU;

    bool r;

    ao_stream4obj_t * S;


    // Ready.

    S = PO->stream;

    B = &S->buffer;

    ao_async_begin(&PO->async);

    ao_lock(&L);
    {
        // Buffer is empty.

        r = ao_buffer4obj_is_empty(B);

        if (r)
        {
            r = ao_buffer4obj_is_full(B);

            if (r)
            {
                // Push and pop now.

                l = &S->push;

                n = l->front;

                if (n)
                {
                    ao_list_remove_front(l);

                    PU = ao_containerof(n, ao_spush_obj_t, node);

                    ao_memcpy(PO->ptr, PU->ptr, B->size);

                    PO->result = true;

                    PU->result = true;

                    ao_async_check(&PO->async);

                    ao_async_check(&PU->async);
                }

                // Push and pop not possible.

                else
                {
                    r = false;
                }
            }

            // Pop later.

            if (!r)
            {
                PO->result = false;

                ao_list_push_back(&S->pop, &PO->node);
            }
        }

        // Buffer is not empty.

        else
        {
            // Pop now.

            r = ao_buffer4obj_is_full(B);

            ao_buffer4obj_pop_front(B, PO->ptr);

            PO->result = true;

            ao_async_check(&PO->async);

            // Push now.

            if (r)
            {
                l = &S->push;

                n = l->front;

                if (n)
                {
                    ao_list_remove_front(l);

                    PU = ao_containerof(n, ao_spush_obj_t, node);

                    ao_buffer4obj_push_back(B, PU->ptr);

                    PU->result = true;

                    ao_async_check(&PU->async);
                }
            }
        }
    }
    ao_unlock(&L);
}

void ao_spop_obj_end(ao_spop_obj_t * PO)
{
    // Assert.

    ao_assert(PO);

    ao_assert(PO->stream);


    // Variables.

    ao_lock_t L;


    // Ready.

    ao_lock(&L);
    {
        if (PO->result) { }

        else
        {
            ao_list_remove(&PO->stream->pop, &PO->node);
        }
    }
    ao_unlock(&L);

    ao_async_end(&PO->async);
}

void ao_spop_obj_forever(ao_spop_obj_t * PO)
{
    ao_spop_obj_from(PO, AO_INFINITY, 0);
}

void ao_spop_obj_from(ao_spop_obj_t * PO, ao_time_t t, ao_time_t b)
{
    // Assert.

    ao_assert(PO);


    // Ready.

    ao_spop_obj_begin(PO);

    ao_await_from(&PO->async, t, b);

    ao_spop_obj_end(PO);
}

void ao_spop_obj_try(ao_spop_obj_t * PO)
{
    ao_spop_obj_begin(PO);

    ao_spop_obj_end(PO);
}

// ----------------------------------------------------------------------------

void ao_spush_obj(ao_spush_obj_t * PU, ao_time_t t)
{
    ao_spush_obj_from(PU, t, ao_now());
}

void ao_spush_obj_begin(ao_spush_obj_t * PU)
{
    // Assert.

    ao_assert(PU);

    ao_assert(PU->stream);


    // Variables.

    ao_buffer4obj_t * B;

    ao_list_t * l;

    ao_lock_t L;

    ao_list_node_t * n;

    ao_spop_obj_t * PO;

    bool r;

    ao_stream4obj_t * S;


    // Ready.

    PU->result_override = false;

    S = PU->stream;

    B = &S->buffer;

    ao_async_begin(&PU->async);

    ao_lock(&L);
    {
        r = ao_buffer4obj_is_empty(B);

        if (r)
        {
            // Push and Pop now.

            l = &S->pop;

            n = l->front;

            if (n)
            {
                ao_list_remove_front(l);

                PO = ao_containerof(n, ao_spop_obj_t, node);

                ao_memcpy(PO->ptr, PU->ptr, B->size);

                PO->result = true;

                PU->result = true;

                ao_async_check(&PO->async);

                ao_async_check(&PU->async);
            }

            // Push and pop not possible.

            else
            {
                r = false;
            }
        }

        if (!r)
        {
            // Push later.

            r = ao_buffer4obj_is_full(B);

            if (r)
            {
                PU->result = false;

                ao_list_push_back(&S->push, &PU->node);
            }

            // Push now.

            else
            {
                ao_buffer4obj_push_back(B, PU->ptr);

                PU->result = true;

                ao_async_check(&PU->async);
            }
        }
    }
    ao_unlock(&L);
}

void ao_spush_obj_end(ao_spush_obj_t * PU)
{
    // Assert.

    ao_assert(PU);

    ao_assert(PU->stream);


    // Variables.

    ao_lock_t L;


    // Ready.

    ao_lock(&L);
    {
        if (PU->result) { }

        else
        {
            ao_list_remove(&PU->stream->push, &PU->node);
        }
    }
    ao_unlock(&L);

    ao_async_end(&PU->async);
}

void ao_spush_obj_forever(ao_spush_obj_t * PU)
{
    ao_spush_obj_from(PU, AO_INFINITY, 0);
}

void ao_spush_obj_from(ao_spush_obj_t * PU, ao_time_t t, ao_time_t b)
{
    // Assert.

    ao_assert(PU);


    // Ready.

    ao_spush_obj_begin(PU);

    ao_await_from(&PU->async, t, b);

    ao_spush_obj_end(PU);
}

void ao_spush_obj_override(ao_spush_obj_t * PU)
{
    // Assert.

    ao_assert(PU);

    ao_assert(PU->stream);


    // Variables.

    ao_buffer4obj_t * B;

    ao_list_t * l;

    ao_lock_t L;

    ao_list_node_t * n;

    void * p;

    ao_spop_obj_t * PO;

    bool r1;

    bool r2;

    ao_stream4obj_t * S;


    // Ready.

    S = PU->stream;

    B = &S->buffer;

    ao_lock(&L);
    {
        r1 = ao_buffer4obj_is_empty(B);

        r2 = r1;

        if (r2)
        {
            l = &S->pop;

            n = l->front;

            // Push and pop now.

            if (n)
            {
                ao_list_remove_front(l);

                PO = ao_containerof(n, ao_spop_obj_t, node);

                ao_memcpy(PO->ptr, PU->ptr, B->size);

                PO->result = true;

                PU->result = true;

                PU->result_override = false;

                ao_async_check(&PO->async);
            }

            // Push and pop not possible.

            else
            {
                r2 = false;
            }
        }

        if (!r2)
        {
            r2 = ao_buffer4obj_is_full(B);

            if (r2)
            {
                // Push not possible.

                if (r1)
                {
                    PU->result = false;

                    PU->result_override = false;
                }

                // Push now.

                else
                {
                    p = PU->ptr_override;

                    if (p)
                    {
                        ao_buffer4obj_peek_front(B, p);
                    }

                    ao_buffer4obj_push_back_override(B, PU->ptr);

                    PU->result = true;

                    PU->result_override = true;
                }
            }

            // Push now.

            else
            {
                ao_buffer4obj_push_back(B, PU->ptr);

                PU->result = true;

                PU->result_override = false;
            }
        }
    }
    ao_unlock(&L);
}

void ao_spush_obj_try(ao_spush_obj_t * PU)
{
    ao_spush_obj_begin(PU);

    ao_spush_obj_end(PU);
}

// ----------------------------------------------------------------------------

#endif

#if defined AO_STREAM4PTR

// ----------------------------------------------------------------------------

void ao_spop_ptr(ao_spop_ptr_t * PO, ao_time_t t)
{
    ao_spop_ptr_from(PO, t, ao_now());
}

void ao_spop_ptr_begin(ao_spop_ptr_t * PO)
{
    // Assert.

    ao_assert(PO);

    ao_assert(PO->stream);


    // Variables.

    ao_buffer4ptr_t * B;

    ao_list_t * l;

    ao_lock_t L;

    ao_list_node_t * n;

    void * p;

    ao_spush_ptr_t * PU;

    bool r;

    ao_stream4ptr_t * S;


    // Ready.

    S = PO->stream;

    B = &S->buffer;

    ao_async_begin(&PO->async);

    ao_lock(&L);
    {
        // Buffer is empty.

        r = ao_buffer4ptr_is_empty(B);

        if (r)
        {
            // Push and pop.

            r = ao_buffer4ptr_is_full(B);

            if (r)
            {
                l = &S->push;

                n = l->front;

                // Push and pop now.

                if (n)
                {
                    ao_list_remove_front(l);

                    PU = ao_containerof(n, ao_spush_ptr_t, node);

                    PO->ptr = PU->ptr;

                    PO->result = true;

                    PU->result = true;

                    ao_async_check(&PO->async);

                    ao_async_check(&PU->async);
                }

                // Push and pop not possible.

                else
                {
                    r = false;
                }
            }

            // Pop later.

            if (!r)
            {
                PO->result = false;

                ao_list_push_back(&S->pop, &PO->node);
            }
        }

        // Buffer is not empty.

        else
        {
            // Pop now.

            r = ao_buffer4ptr_is_full(B);

            ao_buffer4ptr_pop_front(B, &p);

            PO->ptr = p;

            PO->result = true;

            ao_async_check(&PO->async);

            // Push now.

            if (r)
            {
                l = &S->push;

                n = l->front;

                if (n)
                {
                    ao_list_remove_front(l);

                    PU = ao_containerof(n, ao_spush_ptr_t, node);

                    ao_buffer4ptr_push_back(B, PU->ptr);

                    PU->result = true;

                    ao_async_check(&PU->async);
                }
            }
        }
    }
    ao_unlock(&L);
}

void ao_spop_ptr_end(ao_spop_ptr_t * PO)
{
    // Assert.

    ao_assert(PO);

    ao_assert(PO->stream);


    // Variables.

    ao_lock_t L;


    // Ready.

    ao_lock(&L);
    {
        if (PO->result) { }

        else
        {
            ao_list_remove(&PO->stream->pop, &PO->node);
        }
    }
    ao_unlock(&L);

    ao_async_end(&PO->async);
}

void ao_spop_ptr_forever(ao_spop_ptr_t * PO)
{
    ao_spop_ptr_from(PO, AO_INFINITY, 0);
}

void ao_spop_ptr_from(ao_spop_ptr_t * PO, ao_time_t t, ao_time_t b)
{
    // Assert.

    ao_assert(PO);


    // Ready.

    ao_spop_ptr_begin(PO);

    ao_await_from(&PO->async, t, b);

    ao_spop_ptr_end(PO);
}

void ao_spop_ptr_try(ao_spop_ptr_t * PO)
{
    ao_spop_ptr_begin(PO);

    ao_spop_ptr_end(PO);
}

// ----------------------------------------------------------------------------

void ao_spush_acq(ao_spush_ptr_t * PU, ao_time_t t)
{
    ao_spush_acq_from(PU, t, ao_now());
}

void ao_spush_acq_begin(ao_spush_ptr_t * PU)
{

#if defined AO_ALLOC

    ao_assert(PU);

    ao_retain(PU->ptr);

#endif

    ao_spush_ptr_begin(PU);
}

void ao_spush_acq_end(ao_spush_ptr_t * PU)
{
    ao_spush_ptr_end(PU);

#if defined AO_ALLOC

    ao_assert(PU);

    if (PU->result) { }

    else
    {
        ao_release(PU->ptr);
    }

#endif

}

void ao_spush_acq_forever(ao_spush_ptr_t * PU)
{
    ao_spush_acq_from(PU, AO_INFINITY, 0);
}

void ao_spush_acq_from(ao_spush_ptr_t * PU, ao_time_t t, ao_time_t b)
{
    // Assert.

    ao_assert(PU);


    // Ready.

    ao_spush_acq_begin(PU);

    ao_await_from(&PU->async, t, b);

    ao_spush_acq_end(PU);
}

void ao_spush_acq_override(ao_spush_ptr_t * PU)
{

#if defined AO_ALLOC

    ao_assert(PU);

    ao_retain(PU->ptr);

#endif

    ao_spush_ptr_override(PU);

#if defined AO_ALLOC

    if (PU->result)
    {
        if (PU->result_override)
        {
            ao_release(PU->ptr_override);

            PU->ptr_override = NULL;
        }

        else { }
    }

    else
    {
        ao_release(PU->ptr);
    }

#endif

}

void ao_spush_acq_try(ao_spush_ptr_t * PU)
{
    ao_spush_acq_begin(PU);

    ao_spush_acq_end(PU);
}

// ----------------------------------------------------------------------------

void ao_spush_ptr(ao_spush_ptr_t * PU, ao_time_t t)
{
    ao_spush_ptr_from(PU, t, ao_now());
}

void ao_spush_ptr_begin(ao_spush_ptr_t * PU)
{
    // Assert.

    ao_assert(PU);

    ao_assert(PU->stream);


    // Variables.

    ao_buffer4ptr_t * B;

    ao_list_t * l;

    ao_lock_t L;

    ao_list_node_t * n;

    ao_spop_ptr_t * PO;

    bool r;

    ao_stream4ptr_t * S;


    // Ready.

    PU->result_override = false;

    S = PU->stream;

    B = &S->buffer;

    ao_async_begin(&PU->async);

    ao_lock(&L);
    {
        r = ao_buffer4ptr_is_empty(B);

        if (r)
        {
            // Push and Pop now.

            l = &S->pop;

            n = l->front;

            if (n)
            {
                ao_list_remove_front(l);

                PO = ao_containerof(n, ao_spop_ptr_t, node);

                PO->ptr = PU->ptr;

                PO->result = true;

                PU->result = true;

                ao_async_check(&PO->async);

                ao_async_check(&PU->async);
            }

            // Push and pop not possible.

            else
            {
                r = false;
            }
        }

        if (!r)
        {
            // Push later.

            r = ao_buffer4ptr_is_full(B);

            if (r)
            {
                PU->result = false;

                ao_list_push_back(&S->push, &PU->node);
            }

            // Push now.

            else
            {
                ao_buffer4ptr_push_back(B, PU->ptr);

                PU->result = true;

                ao_async_check(&PU->async);
            }
        }
    }
    ao_unlock(&L);
}

void ao_spush_ptr_end(ao_spush_ptr_t * PU)
{
    // Assert.

    ao_assert(PU);

    ao_assert(PU->stream);


    // Variables.

    ao_lock_t L;


    // Ready.

    ao_lock(&L);
    {
        if (PU->result) { }

        else
        {
            ao_list_remove(&PU->stream->push, &PU->node);
        }
    }
    ao_unlock(&L);

    ao_async_end(&PU->async);
}

void ao_spush_ptr_forever(ao_spush_ptr_t * PU)
{
    ao_spush_ptr_from(PU, AO_INFINITY, 0);
}

void ao_spush_ptr_from(ao_spush_ptr_t * PU, ao_time_t t, ao_time_t b)
{
    // Assert.

    ao_assert(PU);


    // Ready.

    ao_spush_ptr_begin(PU);

    ao_await_from(&PU->async, t, b);

    ao_spush_ptr_end(PU);
}

void ao_spush_ptr_override(ao_spush_ptr_t * PU)
{
    // Assert.

    ao_assert(PU);

    ao_assert(PU->stream);


    // Variables.

    ao_buffer4ptr_t * B;

    ao_list_t * l;

    ao_lock_t L;

    ao_list_node_t * n;

    void * p;

    ao_spop_ptr_t * PO;

    bool r1;

    bool r2;

    ao_stream4ptr_t * S;


    // Ready.

    S = PU->stream;

    B = &S->buffer;

    ao_lock(&L);
    {
        r1 = ao_buffer4ptr_is_empty(B);

        r2 = r1;

        // Push and pop.

        if (r2)
        {
            // Push and pop now.

            l = &S->pop;

            n = l->front;

            if (n)
            {
                ao_list_remove_front(l);

                PO = ao_containerof(n, ao_spop_ptr_t, node);

                PO->ptr = PU->ptr;

                PO->result = true;

                PU->result = true;

                PU->result_override = false;

                ao_async_check(&PO->async);
            }

            // Push and pop not possible.

            else
            {
                r2 = false;
            }
        }

        if (!r2)
        {
            r2 = ao_buffer4ptr_is_full(B);

            if (r2)
            {
                // Push not possible.

                if (r1)
                {
                    PU->result = false;

                    PU->result_override = false;
                }

                // Push now.

                else
                {
                    ao_buffer4ptr_peek_front(B, p);

                    PU->ptr_override = p;

                    ao_buffer4ptr_push_back_override(B, PU->ptr);

                    PU->result = true;

                    PU->result_override = true;
                }
            }

            else
            {
                // Push now.

                ao_buffer4ptr_push_back(B, PU->ptr);

                PU->result = true;

                PU->result_override = false;
            }
        }
    }
    ao_unlock(&L);
}

void ao_spush_ptr_try(ao_spush_ptr_t * PU)
{
    ao_spush_ptr_begin(PU);

    ao_spush_ptr_end(PU);
}

// ----------------------------------------------------------------------------

#endif

#if defined AO_TASK

// ----------------------------------------------------------------------------

static  void                    ao_task_resume_1(   ao_task_t * t);

// ----------------------------------------------------------------------------

static  void                    ao_task_start_1(    ao_task_t * t);

// ----------------------------------------------------------------------------

static  void                    ao_task_stop_1(     ao_task_t * t);

static  void                    ao_task_stop_2(     ao_task_t * t);

// ----------------------------------------------------------------------------

static  void                    ao_task_suspend_1(  ao_task_t * t);

// ----------------------------------------------------------------------------

static  void                    ao_task_unblock_1(  ao_task_t * t);

// ----------------------------------------------------------------------------

        ao_task_t               ao_task_main;

        ao_task_t * volatile    ao_task_running     [AO_CORE_COUNT];

// ----------------------------------------------------------------------------

void ao_boot_task()
{
    // Assert.

    ao_assert(!ao_booted_task);


    // Variables.

    ao_task_t * t;


    // Ready.

    t = &ao_task_main;

    t->started = 1;

    t->state = AO_TASK_RUNNING;

    ao_task_running[0] = t;

    ao_boot_task_sched();

    ao_boot_task_stack();

    ao_booted_task = true;
}

// ----------------------------------------------------------------------------

void ao_task_entry(ao_task_t const * t)
{
    // Assert.

    ao_assert(t);


    // Variables.

    ao_lock_t l;

    ao_proc_t P;

    void * p;


    // Ready.

    ao_lock(&l);
    {
        P = t->proc;

        p = t->proc_parameter;
    }
    ao_unlock(&l);

    if (P)
    {
        P(p);
    }

    while (1) { }
}

// ----------------------------------------------------------------------------

ao_proc_t ao_task_get_proc(ao_task_t const * t)
{
    // Assert.

    ao_assert(t);


    // Variables.

    ao_task_t const volatile * T = t;

    ao_proc_t x1;
    ao_proc_t x2;


    // Ready.

    do
    {
        x1 = T->proc;
        x2 = T->proc;
    }
    while (x1 != x2);

    return x1;
}

void * ao_task_get_proc_parameter(ao_task_t const * t)
{
    // Assert.

    ao_assert(t);


    // Variables.

    ao_task_t const volatile * T = t;

    void * x1;
    void * x2;


    // Ready.

    do
    {
        x1 = T->proc_parameter;
        x2 = T->proc_parameter;
    }
    while (x1 != x2);

    return x1;
}

// ----------------------------------------------------------------------------

ao_task_state_t ao_task_get_state(ao_task_t const * t)
{
    // Assert.

    ao_assert(t);


    // Variables.

    ao_task_t const volatile * T = t;

    ao_task_state_t x1;
    ao_task_state_t x2;


    // Ready.

    do
    {
        x1 = T->state;
        x2 = T->state;
    }
    while (x1 != x2);

    return x1;
}

ao_task_state_pending_t ao_task_get_state_pending(ao_task_t const * t)
{
    // Assert.

    ao_assert(t);


    // Variables.

    ao_task_t const volatile * T = t;

    ao_task_state_pending_t x1;
    ao_task_state_pending_t x2;


    // Ready.

    do
    {
        x1 = T->state_pending;
        x2 = T->state_pending;
    }
    while (x1 != x2);

    return x1;
}

// ----------------------------------------------------------------------------

bool ao_task_is_active(ao_task_t const * t)
{
    ao_task_state_t x;

    x = ao_task_get_state(t);

    x = x & AO_TASK_ACTIVE;

    return x ? true : false;
}

bool ao_task_is_blocked(ao_task_t const * t)
{
    ao_task_state_t x;

    x = ao_task_get_state(t);

    return x == AO_TASK_BLOCKED ? true : false;
}

bool ao_task_is_blocking(ao_task_t const * t)
{
    ao_task_state_pending_t x;

    x = ao_task_get_state_pending(t);

    return x == AO_TASK_BLOCKING ? true : false;
}

bool ao_task_is_ready(ao_task_t const * t)
{
    ao_task_state_t x;

    x = ao_task_get_state(t);

    return x == AO_TASK_READY ? true : false;
}

bool ao_task_is_running(ao_task_t const * t)
{
    ao_task_state_t x;

    x = ao_task_get_state(t);

    return x == AO_TASK_RUNNING ? true : false;
}

bool ao_task_is_started(ao_task_t const * t)
{
    ao_task_state_t x;

    x = ao_task_get_state(t);

    x = x & AO_TASK_STARTED;

    return x ? true : false;
}

bool ao_task_is_stopped(ao_task_t const * t)
{
    ao_task_state_t x;

    x = ao_task_get_state(t);

    return x == AO_TASK_STOPPED ? true : false;
}

bool ao_task_is_stopping(ao_task_t const * t)
{
    ao_task_state_pending_t x;

    x = ao_task_get_state_pending(t);

    return x == AO_TASK_STOPPING ? true : false;
}

bool ao_task_is_suspendable(ao_task_t const * t)
{
    ao_task_state_t x;

    x = ao_task_get_state(t);

    x = x & AO_TASK_SUSPENDABLE;

    return x ? true : false;
}

bool ao_task_is_suspended(ao_task_t const * t)
{
    ao_task_state_t x;

    x = ao_task_get_state(t);

    return x == AO_TASK_SUSPENDED ? true : false;
}

bool ao_task_is_suspending(ao_task_t const * t)
{
    ao_task_state_pending_t x;

    x = ao_task_get_state_pending(t);

    return x == AO_TASK_SUSPENDING ? true : false;
}

bool ao_task_is_yielding(ao_task_t const * t)
{
    ao_task_state_pending_t x;

    x = ao_task_get_state_pending(t);

    return x == AO_TASK_YIELDING ? true : false;
}

// ----------------------------------------------------------------------------

void ao_task_pend(ao_task_t * t, ao_task_state_pending_t p)
{
    // Notes.

    // Called by ao_block() or

    // Called by ao_task_stop() or

    // Called by ao_task_suspend() or

    // Called by ao_yield().

    // The kernel is locked.

    // The task is running.


    // Assert.

    ao_assert(t);

    ao_assert(t->state == AO_TASK_RUNNING);


    // Ready.

    t->state_pending |= p;

    ao_task_down(t);
}

// ----------------------------------------------------------------------------

void ao_task_resume(ao_task_t * t)
{
    // Assert.

    ao_assert(ao_booted_task);

    ao_assert(t);


    // Variables.

    ao_lock_t l;

    ao_int_t s;


    // Ready.

    ao_lock(&l);
    {

#if AO_TASK_COUNT

        t->count.resume++;

#endif

        s = t->suspended;

        s--;

        t->suspended = s;

        if (s == 0)
        {
            // Task is suspended.

            if (t->state == AO_TASK_SUSPENDED)
            {
                ao_task_resume_1(t);
            }

            // Task is running.

            else if (t->state == AO_TASK_RUNNING)
            {
                // Task is suspending.

                ao_assert(t->state_pending == AO_TASK_SUSPENDING);
            }

            else
            {
                // Task is blocked.

                // Task is stopped.

                ao_assert
                (
                    t->state == AO_TASK_BLOCKED ||
                    t->state == AO_TASK_STOPPED
                );
            }
        }

        else if (s < 0)
        {
            // Task is not suspended.

            ao_assert(t->state != AO_TASK_SUSPENDED);
        }

        else
        {
            // Task is blocked.

            // Task is blocking.

            // Task is stopped.

            // Task is stopping.

            // Task is suspended.

            // Task is suspending.

            ao_assert
            (
                t->state         == AO_TASK_BLOCKED    ||
                t->state         == AO_TASK_STOPPED    ||
                t->state         == AO_TASK_SUSPENDED  ||
                t->state_pending == AO_TASK_BLOCKING   ||
                t->state_pending == AO_TASK_STOPPING   ||
                t->state_pending == AO_TASK_SUSPENDING
            );
        }
    }
    ao_unlock(&l);
}

void ao_task_resume_1(ao_task_t * t)
{
    // Variables.

#if AO_TASK_TIME

    ao_time_t n = ao_now();

#endif


    // Ready.

#if AO_TASK_COUNT

    t->count.activate++;

#endif

#if AO_TASK_TIME

    t->time.point.activation = n;

    t->time.span.inactive += (n - t->time.point.inactivation);

#endif

    t->state = AO_TASK_READY;

    ao_task_add(t);
}

// ----------------------------------------------------------------------------

void ao_task_set_proc(ao_task_t * t, ao_proc_t P, void * p)
{
    ao_assert(t);

    ao_lock_t l;

    ao_lock(&l);
    {
        t->proc = P;

        t->proc_parameter = p;
    }
    ao_unlock(&l);
}

// ----------------------------------------------------------------------------

void ao_task_start(ao_task_t * t)
{
    // Assert.

    ao_assert(ao_booted_task);

    ao_assert(t);


    // Variables.

    ao_lock_t l;

    ao_int_t s;


    // Ready.

    ao_lock(&l);
    {

#if AO_TASK_COUNT

        t->count.start++;

#endif

        s = t->started;

        if (s == 0)
        {
            // Task is stopped.

            if (t->state == AO_TASK_STOPPED)
            {
                ao_task_start_1(t);
            }

            // Task is stopping.

            else
            {
                ao_assert(t->state_pending == AO_TASK_STOPPING);
            }
        }

        else if (s < 0)
        {
            // Task is stopped.

            // Task is stopping.

            ao_assert
            (
                t->state         == AO_TASK_STOPPED  ||
                t->state_pending == AO_TASK_STOPPING
            );
        }

        else
        {
            // Task is started.

            ao_assert(t->state & AO_TASK_STARTED);
        }

        s++;

        t->started = s;
    }
    ao_unlock(&l);
}

void ao_task_start_1(ao_task_t * t)
{
    // Variables.

#if AO_TASK_TIME

    ao_time_t n = ao_now();

#endif


    // Ready.

    ao_task_start_stack(t);

    ao_task_start_context(t);

    ao_task_start_sched(t);

#if AO_TASK_TIME

    t->time.point.start = n;

    t->time.point.switch_out = n;

#endif

    // Task is suspended.

    if (t->suspended > 0)
    {
        t->state = AO_TASK_SUSPENDED;

#if AO_TASK_TIME

        t->time.point.inactivation = n;

#endif

    }

    // Task is ready.

    else
    {
        t->state = AO_TASK_READY;

#if AO_TASK_COUNT

        t->count.activate++;

#endif

#if AO_TASK_TIME

        t->time.point.activation = n;

#endif

        ao_task_add(t);
    }
}

// ----------------------------------------------------------------------------

void ao_task_stop(ao_task_t * t)
{
    // Assert.

    ao_assert(ao_booted_task);

    ao_assert(t);


    // Variables.

    ao_lock_t l;

    ao_int_t s;


    // Ready.

    ao_lock(&l);
    {

#if AO_TASK_COUNT

        t->count.stop++;

#endif

        s = t->started;

        s--;

        t->started = s;

        if (s == 0)
        {
            // Task is running.

            if (t->state == AO_TASK_RUNNING)
            {
                ao_task_pend(t, AO_TASK_STOPPING);
            }

            // Task is not running.

            else
            {
                ao_task_stop_1(t);
            }
        }

        else if (s < 0)
        {
            // Task is stopped.

            // Task is stopping.

            ao_assert
            (
                t->state         == AO_TASK_STOPPED  ||
                t->state_pending == AO_TASK_STOPPING
            );
        }

        else
        {
            // Task is started.

            ao_assert(t->state & AO_TASK_STARTED);
        }
    }
    ao_unlock(&l);
}

void ao_task_stop_1(ao_task_t * t)
{
    // Variables.

#if AO_TASK_TIME

    ao_time_t n = ao_now();

#endif


    // Ready.

#if AO_TASK_TIME || AO_TASK_COUNT

    // Task is active.

    if (t->state == AO_TASK_READY)
    {

#if AO_TASK_COUNT

        t->count.inactivate++;

#endif

#if AO_TASK_TIME

        t->time.point.inactivation = n;

        t->time.span.active += (n - t->time.point.activation);

#endif

    }

#endif

#if AO_TASK_TIME

    // Task is inactive.

    else
    {
        t->time.span.inactive += (n - t->time.point.inactivation);
    }

    t->time.span.down += (n - t->time.point.switch_out);

    t->time.point.stop = n;

#endif

    ao_task_stop_2(t);
}

void ao_task_stop_2(ao_task_t * t)
{
    // Variables.

    ao_block_t * b;


    // Ready.

    // Task is blocked.

    b = t->block;

    if (b)
    {
        ao_alarm_stop_locked(&b->alarm);

        t->block = NULL;
    }

    // Task is ready.

    if (t->state == AO_TASK_READY)
    {
        ao_task_remove(t);
    }

    t->state = AO_TASK_STOPPED;

    ao_task_stop_sched(t);

    ao_task_stop_context(t);

    ao_task_stop_stack(t);
}

// ----------------------------------------------------------------------------

void ao_task_suspend(ao_task_t * t)
{
    // Assert.

    ao_assert(ao_booted_task);

    ao_assert(t);


    // Variables.

    ao_lock_t l;

    ao_int_t s;


    // Ready.

    ao_lock(&l);
    {

#if AO_TASK_COUNT

        t->count.suspend++;

#endif

        s = t->suspended;

        if (s == 0)
        {
            // Task is running.

            if (t->state == AO_TASK_RUNNING)
            {
                ao_task_pend(t, AO_TASK_SUSPENDING);
            }

            // Task is ready.

            else if (t->state == AO_TASK_READY)
            {
                ao_task_suspend_1(t);
            }

            else
            {
                // Task is blocked.

                // Task is stopped.

                ao_assert
                (
                    t->state == AO_TASK_BLOCKED ||
                    t->state == AO_TASK_STOPPED
                );
            }
        }

        else if (s < 0)
        {
            // Task is not suspended.

            ao_assert(t->state != AO_TASK_SUSPENDED);
        }

        else
        {
            // Task is blocked.

            // Task is blocking.

            // Task is stopped.

            // Task is stopping.

            // Task is suspended.

            // Task is suspending.

            ao_assert
            (
                t->state         == AO_TASK_BLOCKED    ||
                t->state         == AO_TASK_STOPPED    ||
                t->state         == AO_TASK_SUSPENDED  ||
                t->state_pending == AO_TASK_BLOCKING   ||
                t->state_pending == AO_TASK_STOPPING   ||
                t->state_pending == AO_TASK_SUSPENDING
            );
        }

        s++;

        t->suspended = s;
    }
    ao_unlock(&l);
}

void ao_task_suspend_1(ao_task_t * t)
{
    // Variables.

#if AO_TASK_TIME

    ao_time_t n = ao_now();

#endif


    // Ready.

    ao_task_remove(t);

#if AO_TASK_COUNT

    t->count.inactivate++;

#endif

#if AO_TASK_TIME

    t->time.point.inactivation = n;

    t->time.span.active += (n - t->time.point.activation);

#endif

    t->state = AO_TASK_SUSPENDED;
}

// ----------------------------------------------------------------------------

void ao_task_switch_in(ao_task_t * t)
{
    // Notes.

    // This function is called by the scheduler function ao_task_switch().

    // The kernel is locked.


    // Assert.

    ao_assert(t);

    ao_assert(t->state == AO_TASK_READY);


    // Variables.

#if AO_TASK_TIME

    ao_time_t n = ao_now();

#endif


    // Ready.

#if AO_TASK_COUNT

    t->count.switch_in++;

#endif

#if AO_TASK_TIME

    t->time.point.switch_in = n;

    t->time.span.down += (n - t->time.point.switch_out);

#endif

    t->state = AO_TASK_RUNNING;
}

bool ao_task_switch_out(ao_task_t * t)
{
    // Notes.

    // This function is called by the scheduler function ao_task_switch().

    // The kernel is locked.


    // Assert.

    ao_assert(t);

    ao_assert(t->state == AO_TASK_RUNNING);


    // Variables.

#if AO_TASK_TIME

    ao_time_t n = ao_now();

#endif

    ao_task_state_t s;

    ao_task_state_pending_t p;


    // Ready.

    s = AO_TASK_READY;

    p = t->state_pending;

    // Task is stopping.

    if (p & AO_TASK_STOPPING)
    {
        // Task has not been started over.

        if (t->started <= 0)
        {
            ao_task_stop_2(t);

            s = AO_TASK_STOPPED;

            p = 0;
        }
    }

    // Task is blocking.

    if (p & AO_TASK_BLOCKING)
    {
        // Task has not been unblocked.

        if (t->block)
        {
            s = AO_TASK_BLOCKED;

            p = 0;
        }
    }

    // Task is suspending.

    if (p & AO_TASK_SUSPENDING)
    {
        // Task has not been resumed.

        if (t->suspended > 0)
        {
            s = AO_TASK_SUSPENDED;
        }
    }

    t->state = s;

    t->state_pending = 0;

#if AO_TASK_COUNT

    t->count.switch_out++;

#endif

#if AO_TASK_TIME

    t->time.point.switch_out = n;

    t->time.span.up += (n - t->time.point.switch_in);

#endif

    // Task is active.

    if (s == AO_TASK_READY)
    {
        return true;
    }

    // Task is inactive.

    else
    {

#if AO_TASK_COUNT

        t->count.inactivate++;

#endif

#if AO_TASK_TIME

        t->time.point.inactivation = n;

        t->time.span.active += (n - t->time.point.activation);

        // Task is stopped.

        if (s == AO_TASK_STOPPED)
        {
            t->time.point.stop = n;
        }

#endif

        return false;
    }
}

// ----------------------------------------------------------------------------

void ao_task_unblock(ao_task_t * t)
{
    // Notes.

    // The kernel is locked.


    // Assert.

    ao_assert(ao_booted_task);

    ao_assert(t);


    // Ready.

#if AO_TASK_COUNT

    t->count.unblock++;

#endif

    if (t->block)
    {
        ao_task_unblock_1(t);
    }
}

void ao_task_unblock_1(ao_task_t * t)
{
    // Variables.

    ao_block_t * b;

#if AO_TASK_TIME

    ao_time_t n = ao_now();

#endif


    // Ready.

    b = t->block;

    if (b->timeout != AO_INFINITY)
    {
        ao_alarm_stop_locked(&b->alarm);
    }

    t->block = NULL;

    // Task is blocked.

    if (t->state == AO_TASK_BLOCKED)
    {
        // Task has been suspended.

        if (t->suspended > 0)
        {
            t->state = AO_TASK_SUSPENDED;
        }

        // Task has not been suspended.

        else
        {

#if AO_TASK_COUNT

            t->count.activate++;

#endif

#if AO_TASK_TIME

            t->time.point.activation = n;

            t->time.span.inactive += (n - t->time.point.inactivation);

#endif

            t->state = AO_TASK_READY;

            ao_task_add(t);
        }
    }

    // Task is not blocked.

    else
    {
        // Task is running and blocking.

        ao_assert
        (
            t->state         == AO_TASK_RUNNING  &&
            t->state_pending == AO_TASK_BLOCKING
        );
    }
}

// ----------------------------------------------------------------------------

void ao_task_wake(ao_task_t * t)
{
    // Notes.

    // The kernel is not locked.

    ao_lock_t l;

    ao_lock(&l);
    {
        ao_task_unblock(t);
    }
    ao_unlock(&l);
}

// ----------------------------------------------------------------------------

#endif

#if defined AO_TASK && AO_TASK_COUNT

// ----------------------------------------------------------------------------

ao_uint_t ao_task_get_count_activate(ao_task_t const * t)
{
    // Assert.

    ao_assert(t);


    // Variables.

    ao_task_t const volatile * T = t;

    ao_uint_t x1;
    ao_uint_t x2;


    // Ready.

    do
    {
        x1 = T->count.activate;
        x2 = T->count.activate;
    }
    while (x1 != x2);

    return x1;
}

ao_uint_t ao_task_get_count_block(ao_task_t const * t)
{
    // Assert.

    ao_assert(t);


    // Variables.

    ao_task_t const volatile * T = t;

    ao_uint_t x1;
    ao_uint_t x2;


    // Ready.

    do
    {
        x1 = T->count.block;
        x2 = T->count.block;
    }
    while (x1 != x2);

    return x1;
}

ao_uint_t ao_task_get_count_inactivate(ao_task_t const * t)
{
    // Assert.

    ao_assert(t);


    // Variables.

    ao_task_t const volatile * T = t;

    ao_uint_t x1;
    ao_uint_t x2;


    // Ready.

    do
    {
        x1 = T->count.inactivate;
        x2 = T->count.inactivate;
    }
    while (x1 != x2);

    return x1;
}

ao_uint_t ao_task_get_count_resume(ao_task_t const * t)
{
    // Assert.

    ao_assert(t);


    // Variables.

    ao_task_t const volatile * T = t;

    ao_uint_t x1;
    ao_uint_t x2;


    // Ready.

    do
    {
        x1 = T->count.resume;
        x2 = T->count.resume;
    }
    while (x1 != x2);

    return x1;
}

ao_uint_t ao_task_get_count_start(ao_task_t const * t)
{
    // Assert.

    ao_assert(t);


    // Variables.

    ao_task_t const volatile * T = t;

    ao_uint_t x1;
    ao_uint_t x2;


    // Ready.

    do
    {
        x1 = T->count.start;
        x2 = T->count.start;
    }
    while (x1 != x2);

    return x1;
}

ao_uint_t ao_task_get_count_stop(ao_task_t const * t)
{
    // Assert.

    ao_assert(t);


    // Variables.

    ao_task_t const volatile * T = t;

    ao_uint_t x1;
    ao_uint_t x2;


    // Ready.

    do
    {
        x1 = T->count.stop;
        x2 = T->count.stop;
    }
    while (x1 != x2);

    return x1;
}

ao_uint_t ao_task_get_count_suspend(ao_task_t const * t)
{
    // Assert.

    ao_assert(t);


    // Variables.

    ao_task_t const volatile * T = t;

    ao_uint_t x1;
    ao_uint_t x2;


    // Ready.

    do
    {
        x1 = T->count.suspend;
        x2 = T->count.suspend;
    }
    while (x1 != x2);

    return x1;
}

ao_uint_t ao_task_get_count_switch_in(ao_task_t const * t)
{
    // Assert.

    ao_assert(t);


    // Variables.

    ao_task_t const volatile * T = t;

    ao_uint_t x1;
    ao_uint_t x2;


    // Ready.

    do
    {
        x1 = T->count.switch_in;
        x2 = T->count.switch_in;
    }
    while (x1 != x2);

    return x1;
}

ao_uint_t ao_task_get_count_switch_out(ao_task_t const * t)
{
    // Assert.

    ao_assert(t);


    // Variables.

    ao_task_t const volatile * T = t;

    ao_uint_t x1;
    ao_uint_t x2;


    // Ready.

    do
    {
        x1 = T->count.switch_out;
        x2 = T->count.switch_out;
    }
    while (x1 != x2);

    return x1;
}

ao_uint_t ao_task_get_count_unblock(ao_task_t const * t)
{
    // Assert.

    ao_assert(t);


    // Variables.

    ao_task_t const volatile * T = t;

    ao_uint_t x1;
    ao_uint_t x2;


    // Ready.

    do
    {
        x1 = T->count.unblock;
        x2 = T->count.unblock;
    }
    while (x1 != x2);

    return x1;
}

// ----------------------------------------------------------------------------

void ao_task_set_count_activate(ao_task_t * t, ao_uint_t x)
{
    ao_assert(t);

    ao_lock_t l;

    ao_lock(&l);
    {
        t->count.activate = x;
    }
    ao_unlock(&l);
}

void ao_task_set_count_block(ao_task_t * t, ao_uint_t x)
{
    ao_assert(t);

    ao_lock_t l;

    ao_lock(&l);
    {
        t->count.block = x;
    }
    ao_unlock(&l);
}

void ao_task_set_count_inactivate(ao_task_t * t, ao_uint_t x)
{
    ao_assert(t);

    ao_lock_t l;

    ao_lock(&l);
    {
        t->count.inactivate = x;
    }
    ao_unlock(&l);
}

void ao_task_set_count_resume(ao_task_t * t, ao_uint_t x)
{
    ao_assert(t);

    ao_lock_t l;

    ao_lock(&l);
    {
        t->count.resume = x;
    }
    ao_unlock(&l);
}

void ao_task_set_count_start(ao_task_t * t, ao_uint_t x)
{
    ao_assert(t);

    ao_lock_t l;

    ao_lock(&l);
    {
        t->count.start = x;
    }
    ao_unlock(&l);
}

void ao_task_set_count_stop(ao_task_t * t, ao_uint_t x)
{
    ao_assert(t);

    ao_lock_t l;

    ao_lock(&l);
    {
        t->count.stop = x;
    }
    ao_unlock(&l);
}

void ao_task_set_count_suspend(ao_task_t * t, ao_uint_t x)
{
    ao_assert(t);

    ao_lock_t l;

    ao_lock(&l);
    {
        t->count.suspend = x;
    }
    ao_unlock(&l);
}

void ao_task_set_count_switch_in(ao_task_t * t, ao_uint_t x)
{
    ao_assert(t);

    ao_lock_t l;

    ao_lock(&l);
    {
        t->count.switch_in = x;
    }
    ao_unlock(&l);
}

void ao_task_set_count_switch_out(ao_task_t * t, ao_uint_t x)
{
    ao_assert(t);

    ao_lock_t l;

    ao_lock(&l);
    {
        t->count.switch_out = x;
    }
    ao_unlock(&l);
}

void ao_task_set_count_unblock(ao_task_t * t, ao_uint_t x)
{
    ao_assert(t);

    ao_lock_t l;

    ao_lock(&l);
    {
        t->count.unblock = x;
    }
    ao_unlock(&l);
}

// ----------------------------------------------------------------------------

#endif

#if defined AO_TASK && AO_TASK_ID

// ----------------------------------------------------------------------------

ao_uint_t ao_task_get_id(ao_task_t const * t)
{
    // Assert.

    ao_assert(t);


    // Variables.

    ao_task_t const volatile * T = t;

    ao_uint_t x1;
    ao_uint_t x2;


    // Ready.

    do
    {
        x1 = T->id;
        x2 = T->id;
    }
    while (x1 != x2);

    return x1;
}

void ao_task_set_id(ao_task_t * t, ao_uint_t x)
{
    ao_assert(t);

    ao_lock_t l;

    ao_lock(&l);
    {
        t->id = x;
    }
    ao_unlock(&l);
}

// ----------------------------------------------------------------------------

#endif

#if defined AO_TASK && AO_TASK_NAME

// ----------------------------------------------------------------------------

char const * ao_task_get_name(ao_task_t const * t)
{
    // Assert.

    ao_assert(t);


    // Variables.

    ao_task_t const volatile * T = t;

    char const * x1;
    char const * x2;


    // Ready.

    do
    {
        x1 = T->name;
        x2 = T->name;
    }
    while (x1 != x2);

    return x1;
}

void ao_task_set_name(ao_task_t * t, char const * x)
{
    ao_assert(t);

    ao_lock_t l;

    ao_lock(&l);
    {
        t->name = x;
    }
    ao_unlock(&l);
}

// ----------------------------------------------------------------------------

#endif

#if defined AO_TASK && AO_TASK_TIME

// ----------------------------------------------------------------------------

ao_time_t ao_task_get_time_point_activation(ao_task_t const * t)
{
    // Assert.

    ao_assert(t);


    // Variables.

    ao_task_t const volatile * T = t;

    ao_time_t x1;
    ao_time_t x2;


    // Ready.

    do
    {
        x1 = T->time.point.activation;
        x2 = T->time.point.activation;
    }
    while (x1 != x2);

    return x1;
}

ao_time_t ao_task_get_time_point_inactivation(ao_task_t const * t)
{
    // Assert.

    ao_assert(t);


    // Variables.

    ao_task_t const volatile * T = t;

    ao_time_t x1;
    ao_time_t x2;


    // Ready.

    do
    {
        x1 = T->time.point.inactivation;
        x2 = T->time.point.inactivation;
    }
    while (x1 != x2);

    return x1;
}

ao_time_t ao_task_get_time_point_start(ao_task_t const * t)
{
    // Assert.

    ao_assert(t);


    // Variables.

    ao_task_t const volatile * T = t;

    ao_time_t x1;
    ao_time_t x2;


    // Ready.

    do
    {
        x1 = T->time.point.start;
        x2 = T->time.point.start;
    }
    while (x1 != x2);

    return x1;
}

ao_time_t ao_task_get_time_point_stop(ao_task_t const * t)
{
    // Assert.

    ao_assert(t);


    // Variables.

    ao_task_t const volatile * T = t;

    ao_time_t x1;
    ao_time_t x2;


    // Ready.

    do
    {
        x1 = T->time.point.stop;
        x2 = T->time.point.stop;
    }
    while (x1 != x2);

    return x1;
}

ao_time_t ao_task_get_time_point_switch_in(ao_task_t const * t)
{
    // Assert.

    ao_assert(t);


    // Variables.

    ao_task_t const volatile * T = t;

    ao_time_t x1;
    ao_time_t x2;


    // Ready.

    do
    {
        x1 = T->time.point.switch_in;
        x2 = T->time.point.switch_in;
    }
    while (x1 != x2);

    return x1;
}

ao_time_t ao_task_get_time_point_switch_out(ao_task_t const * t)
{
    // Assert.

    ao_assert(t);


    // Variables.

    ao_task_t const volatile * T = t;

    ao_time_t x1;
    ao_time_t x2;


    // Ready.

    do
    {
        x1 = T->time.point.switch_out;
        x2 = T->time.point.switch_out;
    }
    while (x1 != x2);

    return x1;
}

// ----------------------------------------------------------------------------

ao_time_t ao_task_get_time_span_active(ao_task_t const * t)
{
    // Assert.

    ao_assert(t);


    // Variables.

    ao_task_t const volatile * T = t;

    ao_time_t x1;
    ao_time_t x2;


    // Ready.

    do
    {
        x1 = T->time.span.active;
        x2 = T->time.span.active;
    }
    while (x1 != x2);

    return x1;
}

ao_time_t ao_task_get_time_span_down(ao_task_t const * t)
{
    // Assert.

    ao_assert(t);


    // Variables.

    ao_task_t const volatile * T = t;

    ao_time_t x1;
    ao_time_t x2;


    // Ready.

    do
    {
        x1 = T->time.span.down;
        x2 = T->time.span.down;
    }
    while (x1 != x2);

    return x1;
}

ao_time_t ao_task_get_time_span_inactive(ao_task_t const * t)
{
    // Assert.

    ao_assert(t);


    // Variables.

    ao_task_t const volatile * T = t;

    ao_time_t x1;
    ao_time_t x2;


    // Ready.

    do
    {
        x1 = T->time.span.inactive;
        x2 = T->time.span.inactive;
    }
    while (x1 != x2);

    return x1;
}

ao_time_t ao_task_get_time_span_up(ao_task_t const * t)
{
    // Assert.

    ao_assert(t);


    // Variables.

    ao_task_t const volatile * T = t;

    ao_time_t x1;
    ao_time_t x2;


    // Ready.

    do
    {
        x1 = T->time.span.up;
        x2 = T->time.span.up;
    }
    while (x1 != x2);

    return x1;
}

// ----------------------------------------------------------------------------

void ao_task_set_time_span_active(ao_task_t * t, ao_time_t x)
{
    ao_assert(t);

    ao_lock_t l;

    ao_lock(&l);
    {
        t->time.span.active = x;
    }
    ao_unlock(&l);
}

void ao_task_set_time_span_down(ao_task_t * t, ao_time_t x)
{
    ao_assert(t);

    ao_lock_t l;

    ao_lock(&l);
    {
        t->time.span.down = x;
    }
    ao_unlock(&l);
}

void ao_task_set_time_span_inactive(ao_task_t * t, ao_time_t x)
{
    ao_assert(t);

    ao_lock_t l;

    ao_lock(&l);
    {
        t->time.span.inactive = x;
    }
    ao_unlock(&l);
}

void ao_task_set_time_span_up(ao_task_t * t, ao_time_t x)
{
    ao_assert(t);

    ao_lock_t l;

    ao_lock(&l);
    {
        t->time.span.up = x;
    }
    ao_unlock(&l);
}

// ----------------------------------------------------------------------------

#endif

#if defined AO_TASK_SCHED_0

// ----------------------------------------------------------------------------

void ao_boot_task_sched() { }

// ----------------------------------------------------------------------------

void ao_task_add(ao_task_t * t)
{
    (void) t;
}

// ----------------------------------------------------------------------------

void ao_task_ceiling_begin(ao_task_ceiling_t * c, ao_task_slave_t * s)
{
    (void) c;

    (void) s;
}

void ao_task_ceiling_end(ao_task_ceiling_t * c)
{
    (void) c;
}

// ----------------------------------------------------------------------------

void ao_task_down(ao_task_t * t)
{
    (void) t;
}

// ----------------------------------------------------------------------------

void ao_task_inheritance_begin(ao_task_master_t * m, ao_task_slave_t * s)
{
    (void) m;

    (void) s;
}

void ao_task_inheritance_end(ao_task_master_t * m)
{
    (void) m;
}

// ----------------------------------------------------------------------------

void ao_task_master_begin(ao_task_master_t * m, ao_task_t * t)
{
    (void) m;

    (void) t;
}

void ao_task_master_end(ao_task_master_t * m)
{
    (void) m;
}

// ----------------------------------------------------------------------------

void ao_task_remove(ao_task_t * t)
{
    (void) t;
}

// ----------------------------------------------------------------------------

void ao_task_slave_begin(ao_task_slave_t * s, ao_task_t * t)
{
    (void) s;

    (void) t;
}

void ao_task_slave_end(ao_task_slave_t * s)
{
    (void) s;
}

// ----------------------------------------------------------------------------

void ao_task_start_sched(ao_task_t * t)
{
    (void) t;
}

void ao_task_stop_sched(ao_task_t * t)
{
    (void) t;
}

// ----------------------------------------------------------------------------

void ao_task_switch() { }

// ----------------------------------------------------------------------------

#endif

#if defined AO_TASK_SCHED_1

// ----------------------------------------------------------------------------

static  void        ao_task_sched_alarm_callback(   void * x);

static  void        ao_task_sched_alarm_start();

static  void        ao_task_sched_alarm_stop();

// ----------------------------------------------------------------------------

static  bool        ao_task_sched_queue_is_empty();

static  ao_task_t * ao_task_sched_queue_peek();

static  void        ao_task_sched_queue_pop();

static  void        ao_task_sched_queue_push(       ao_task_t * t);

static  void        ao_task_sched_queue_remove(     ao_task_t * t);

// ----------------------------------------------------------------------------

static  ao_alarm_t  ao_task_sched_alarm =
{
        .callback   = ao_task_sched_alarm_callback
};

static  ao_time_t   ao_task_sched_alarm_beginning;

static  bool        ao_task_sched_alarm_running;

// ----------------------------------------------------------------------------

static  ao_list_t   ao_task_sched_queue;

// ----------------------------------------------------------------------------

void ao_boot_task_sched()
{
    ao_task_switch_enable(0);
}

// ----------------------------------------------------------------------------

void ao_task_add(ao_task_t * t)
{
    ao_assert(t != ao_task_running[0]);

    ao_task_sched_queue_push(t);

    ao_task_sched_alarm_start();
}

// ----------------------------------------------------------------------------

void ao_task_ceiling_begin(ao_task_ceiling_t * c, ao_task_slave_t * s)
{
    (void) c;

    (void) s;
}

void ao_task_ceiling_end(ao_task_ceiling_t * c)
{
    (void) c;
}

// ----------------------------------------------------------------------------

void ao_task_down(ao_task_t * t)
{
    (void) t;

    ao_task_switch_request(0);
}

// ----------------------------------------------------------------------------

void ao_task_inheritance_begin(ao_task_master_t * m, ao_task_slave_t * s)
{
    (void) m;

    (void) s;
}

void ao_task_inheritance_end(ao_task_master_t * m)
{
    (void) m;
}

// ----------------------------------------------------------------------------

void ao_task_master_begin(ao_task_master_t * m, ao_task_t * t)
{
    (void) m;

    (void) t;
}

void ao_task_master_end(ao_task_master_t * m)
{
    (void) m;
}

// ----------------------------------------------------------------------------

void ao_task_remove(ao_task_t * t)
{
    ao_assert(t != ao_task_running[0]);

    ao_task_sched_queue_remove(t);

    if (ao_task_sched_queue_is_empty())
    {
        ao_task_sched_alarm_stop();
    }
}

// ----------------------------------------------------------------------------

void ao_task_sched_alarm_callback(void * x)
{
    // Notes.

    // This is an alarm callback.

    // The kernel is not locked.


    // Variables.

    ao_time_t b;

    ao_lock_t l;


    // Variables.

    (void) x;


    // Ready.

    ao_lock(&l);
    {
        if (ao_task_sched_alarm_running)
        {
            b = ao_task_sched_alarm_beginning;

            b = b + AO_TASK_QUANTUM;

            ao_task_sched_alarm_beginning = b;

            ao_alarm_start_from_locked(&ao_task_sched_alarm, AO_TASK_QUANTUM, b);
        }
    }
    ao_unlock(&l);

    ao_task_switch_request(0);
}

void ao_task_sched_alarm_start()
{
    // Variables.

    ao_time_t b;


    // Ready.

    if (ao_task_sched_alarm_running) { }

    else
    {
        b = ao_now();

        ao_task_sched_alarm_beginning = b;

        ao_task_sched_alarm_running = true;

        ao_alarm_start_from_locked(&ao_task_sched_alarm, AO_TASK_QUANTUM, b);
    }
}

void ao_task_sched_alarm_stop()
{
    ao_alarm_stop_locked(&ao_task_sched_alarm);

    ao_task_sched_alarm_running = false;
}

// ----------------------------------------------------------------------------

bool ao_task_sched_queue_is_empty()
{
    return ao_list_is_empty(&ao_task_sched_queue);
}

ao_task_t * ao_task_sched_queue_peek()
{
    ao_list_node_t * n = ao_task_sched_queue.front;

    if (n)
    {
        return ao_containerof(n, ao_task_t, sched.node);
    }

    else
    {
        return NULL;
    }
}

void ao_task_sched_queue_pop()
{
    ao_list_remove_front(&ao_task_sched_queue);
}

void ao_task_sched_queue_push(ao_task_t * t)
{
    ao_list_push_back(&ao_task_sched_queue, &t->sched.node);
}

void ao_task_sched_queue_remove(ao_task_t * t)
{
    ao_list_remove(&ao_task_sched_queue, &t->sched.node);
}

// ----------------------------------------------------------------------------

void ao_task_slave_begin(ao_task_slave_t * s, ao_task_t * t)
{
    (void) s;

    (void) t;
}

void ao_task_slave_end(ao_task_slave_t * s)
{
    (void) s;
}

// ----------------------------------------------------------------------------

void ao_task_start_sched(ao_task_t * t)
{
    (void) t;
}

void ao_task_stop_sched(ao_task_t * t)
{
    (void) t;
}

// ----------------------------------------------------------------------------

void ao_task_switch()
{
    // Variables.

    ao_lock_t l;

    bool r;

    ao_task_t * t;


    // Ready.

    ao_lock(&l);
    {
        // Task switch interrupt.

        ao_task_switch_reply(0);


        // Task switch out.

        t = ao_task_running[0];

        r = ao_task_switch_out(t);


        // Task is ready.

        if (r)
        {
            if (ao_task_sched_queue_is_empty()) { }

            else
            {
                ao_task_sched_queue_push(t);

                t = ao_task_sched_queue_peek();

                ao_task_sched_queue_pop();

                ao_task_sched_alarm_start();
            }
        }

        // Task is not ready.

        else
        {
            // Queue is empty.

            // This really should not have happened!

            if (ao_task_sched_queue_is_empty())
            {
                ao_assert(false);

                t = NULL;

                ao_task_sched_alarm_stop();
            }

            // Queue is not empty.

            else
            {
                t = ao_task_sched_queue_peek();

                ao_task_sched_queue_pop();

                if (ao_task_sched_queue_is_empty())
                {
                    ao_task_sched_alarm_stop();
                }

                else
                {
                    ao_task_sched_alarm_start();
                }
            }
        }


        // Task switch in.

        ao_task_switch_in(t);

        ao_task_running[0] = t;
    }
    ao_unlock(&l);
}

// ----------------------------------------------------------------------------

#endif

#if defined AO_TASK_SCHED_2

// ----------------------------------------------------------------------------

#if     AO_TASK_PRIO_MIN != 0

#error  Invalid configuration.

#endif

#if     AO_TASK_PRIO_MAX >= AO_UINT_BITS

#error  Invalid configuration.

#endif

// ----------------------------------------------------------------------------

static  bool        ao_task_ceiling_less(           ao_rb_node_t * n1, ao_rb_node_t * n2, void * parameter);

// ----------------------------------------------------------------------------

static  bool        ao_task_master_less(            ao_rb_node_t * n1, ao_rb_node_t * n2, void * parameter);

static  void        ao_task_master_update(          ao_task_t * t);

// ----------------------------------------------------------------------------

static  ao_uint_t   ao_task_prio_keep(              ao_task_t * t);

static  void        ao_task_prio_update_1(          ao_task_t * t, ao_uint_t p_new);

static  void        ao_task_prio_update_2(          ao_task_t * t);

static  void        ao_task_prio_update_3(          ao_task_t * t, ao_uint_t p_new);

// ----------------------------------------------------------------------------

static  void        ao_task_sched_alarm_callback(   void * x);

static  void        ao_task_sched_alarm_start();

static  void        ao_task_sched_alarm_stop();

// ----------------------------------------------------------------------------

static  bool        ao_task_sched_queue_is_empty();

static  ao_task_t * ao_task_sched_queue_peek();

static  ao_uint_t   ao_task_sched_queue_peek_prio();

static  void        ao_task_sched_queue_pop();

static  void        ao_task_sched_queue_push(       ao_task_t * t);

static  void        ao_task_sched_queue_remove(     ao_task_t * t);

// ----------------------------------------------------------------------------

static  bool        ao_task_slave_less(             ao_rb_node_t * n1, ao_rb_node_t * n2, void * parameter);

static  ao_uint_t   ao_task_slave_prio_keep(        ao_task_slave_t * s);

static  void        ao_task_slave_update(           ao_task_slave_t * s);

// ----------------------------------------------------------------------------

static  ao_alarm_t  ao_task_sched_alarm =
{
        .callback   = ao_task_sched_alarm_callback
};

static  ao_time_t   ao_task_sched_alarm_beginning;

static  bool        ao_task_sched_alarm_running;

// ----------------------------------------------------------------------------

static  ao_list_t   ao_task_sched_queue_list        [AO_TASK_PRIO_MAX + 1];

static  ao_uint_t   ao_task_sched_queue_prio;

static  ao_uint_t   ao_task_sched_queue_prio_mask;

// ----------------------------------------------------------------------------

void ao_boot_task_sched()
{
    ao_task_switch_enable(0);
}

// ----------------------------------------------------------------------------

void ao_task_add(ao_task_t * t2)
{
    // Variables.

    ao_uint_t p1;

    ao_uint_t p2;

    ao_task_t * t1;


    // Ready.

    t1 = ao_task_running[0];

    ao_assert(t1 != t2);

    ao_task_sched_queue_push(t2);

    p1 = t1->sched.prio;

    p2 = t2->sched.prio;

    if (p2 > p1)
    {
        ao_task_switch_request(0);
    }

    else if (p2 == p1)
    {
        ao_task_sched_alarm_start();
    }
}

// ----------------------------------------------------------------------------

void ao_task_down(ao_task_t * t)
{
    (void) t;

    ao_task_switch_request(0);
}

// ----------------------------------------------------------------------------

ao_uint_t ao_task_get_prio(ao_task_t const * t)
{
    // Assert.

    ao_assert(t);


    // Variables.

    ao_task_t const volatile * T = t;

    ao_uint_t x1;

    ao_uint_t x2;


    // Ready.

    do
    {
        x1 = T->sched.prio;
        x2 = T->sched.prio;
    }
    while (x1 != x2);

    return x1;
}

// ----------------------------------------------------------------------------

void ao_task_prio_update_3(ao_task_t * t2, ao_uint_t p2)
{
    // Variables.

    ao_uint_t p1;

    ao_uint_t p3;

    ao_task_t * t1;


    // Ready.

    if (t2->sched.prio != p2)
    {
        t1 = ao_task_running[0];

        // Task is active.

        if (t2->state & AO_TASK_ACTIVE)
        {
            // Task is running.

            if (t2 == t1)
            {
                t2->sched.prio = p2;
            }

            // Task is ready.

            else
            {
                ao_task_sched_queue_remove(t2);

                t2->sched.prio = p2;

                ao_task_sched_queue_push(t2);
            }
        }

        // Task is not active.

        else
        {
            t2->sched.prio = p2;
        }

#if AO_TASK_INHERITANCE

        ao_task_master_update(t2);

#endif

        // Queue is empty.

        if (ao_task_sched_queue_is_empty()) { }

        // Queue is not empty.

        else
        {
            p1 = t1->sched.prio;

            p3 = ao_task_sched_queue_peek_prio();

            if (p3 > p1)
            {
                ao_task_switch_request(0);
            }

            else
            {
                if (p3 == p1)
                {
                    ao_task_sched_alarm_start();
                }

                else
                {
                    ao_task_sched_alarm_stop();
                }
            }
        }
    }
}

// ----------------------------------------------------------------------------

void ao_task_remove(ao_task_t * t2)
{
    // Variables.

    ao_uint_t p1;

    ao_uint_t p2;

    ao_uint_t p3;

    ao_task_t * t1;


    // Ready.

    ao_task_sched_queue_remove(t2);


    // Running task.

    t1 = ao_task_running[0];

    ao_assert(t1 != t2);


    // Running task's priority is equal.

    p1 = t1->sched.prio;

    p2 = t2->sched.prio;

    if (p1 == p2)
    {
        if (ao_task_sched_queue_is_empty())
        {
            ao_task_sched_alarm_stop();
        }

        else
        {
            // Running task's priority is greater.

            p3 = ao_task_sched_queue_peek_prio();

            if (p1 > p3)
            {
                ao_task_sched_alarm_stop();
            }

            // Running task's priority is less.

            else if (p1 < p3)
            {
                ao_assert(false);
            }
        }
    }

    // Running task's priority is less.

    else if (p1 < p2)
    {
        ao_assert(false);
    }
}

// ----------------------------------------------------------------------------

void ao_task_sched_alarm_callback(void * x)
{
    // Notes.

    // This is an alarm callback.

    // The kernel is not locked.


    // Variables.

    ao_time_t b;

    ao_lock_t l;


    // Variables.

    (void) x;


    // Ready.

    ao_lock(&l);
    {
        if (ao_task_sched_alarm_running)
        {
            b = ao_task_sched_alarm_beginning;

            b = b + AO_TASK_QUANTUM;

            ao_task_sched_alarm_beginning = b;

            ao_alarm_start_from_locked(&ao_task_sched_alarm, AO_TASK_QUANTUM, b);
        }
    }
    ao_unlock(&l);

    ao_task_switch_request(0);
}

void ao_task_sched_alarm_start()
{
    // Variables.

    ao_time_t b;


    // Ready.

    if (ao_task_sched_alarm_running) { }

    else
    {
        b = ao_now();

        ao_task_sched_alarm_beginning = b;

        ao_task_sched_alarm_running = true;

        ao_alarm_start_from_locked(&ao_task_sched_alarm, AO_TASK_QUANTUM, b);
    }
}

void ao_task_sched_alarm_stop()
{
    ao_alarm_stop_locked(&ao_task_sched_alarm);

    ao_task_sched_alarm_running = false;
}

// ----------------------------------------------------------------------------

bool ao_task_sched_queue_is_empty()
{
    return ao_task_sched_queue_prio_mask == 0 ? true : false;
}

ao_task_t * ao_task_sched_queue_peek()
{
    // Variables.

    ao_list_node_t * n;

    ao_uint_t p;


    // Ready.

    p = ao_task_sched_queue_prio;

    n = ao_task_sched_queue_list[p].front;

    return ao_containerof(n, ao_task_t, sched.node);
}

ao_uint_t ao_task_sched_queue_peek_prio()
{
    return ao_task_sched_queue_prio;
}

void ao_task_sched_queue_pop()
{
    // Variables.

    ao_list_t * l;

    ao_uint_t m;

    ao_uint_t p;


    // Ready.

    p = ao_task_sched_queue_prio;

    l = ao_task_sched_queue_list + (ptrdiff_t) p;

    ao_list_remove_front(l);

    if (ao_list_is_empty(l))
    {
        m = ao_task_sched_queue_prio_mask;

        m = m & ~(1 << p);

        ao_task_sched_queue_prio_mask = m;

        if (m)
        {
            ao_task_sched_queue_prio = ao_fls(m);
        }
    }
}

void ao_task_sched_queue_push(ao_task_t * t)
{
    // Variables.

    ao_list_t * l;

    ao_uint_t m;

    ao_uint_t p;


    // Ready.

    p = t->sched.prio;

    l = ao_task_sched_queue_list + (ptrdiff_t) p;

    if (ao_list_is_empty(l))
    {
        m = ao_task_sched_queue_prio_mask;

        m = m | (1 << p);

        ao_task_sched_queue_prio_mask = m;

        ao_task_sched_queue_prio = ao_fls(m);
    }

    ao_list_push_back(l, &t->sched.node);
}

void ao_task_sched_queue_remove(ao_task_t * t)
{
    // Variables.

    ao_list_t * l;

    ao_uint_t m;

    ao_uint_t p;


    // Ready.

    p = t->sched.prio;

    l = ao_task_sched_queue_list + (ptrdiff_t) p;

    ao_list_remove(l, &t->sched.node);

    if (ao_list_is_empty(l))
    {
        m = ao_task_sched_queue_prio_mask;

        m = m & ~(1 << p);

        ao_task_sched_queue_prio_mask = m;

        if (m)
        {
            ao_task_sched_queue_prio = ao_fls(m);
        }
    }
}

// ----------------------------------------------------------------------------

void ao_task_set_prio(ao_task_t * t, ao_uint_t p)
{
    // Assert.

    ao_assert(t);

    ao_assert(p <= AO_TASK_PRIO_MAX);


    // Variables.

    ao_lock_t l;


    // Ready.

    ao_lock(&l);
    {

#if AO_TASK_SUBMISSION

        ao_task_prio_update_1(t, p);

#else

        ao_task_prio_update_3(t, p);

#endif

    }
    ao_unlock(&l);
}

// ----------------------------------------------------------------------------

void ao_task_start_sched(ao_task_t * t)
{
    (void) t;
}

void ao_task_stop_sched(ao_task_t * t)
{
    (void) t;
}

// ----------------------------------------------------------------------------

void ao_task_switch()
{
    // Variables.

    ao_lock_t l;

    ao_uint_t p1;

    ao_uint_t p2;

    ao_uint_t p3;

    bool r;

    ao_task_t * t1;

    ao_task_t * t2;


    // Ready.

    ao_lock(&l);
    {
        // Task switch interrupt.

        ao_task_switch_reply(0);


        // Task switch out.

        t1 = ao_task_running[0];

        r = ao_task_switch_out(t1);


        // Task is ready.

        if (r)
        {
            // Queue is empty.

            if (ao_task_sched_queue_is_empty())
            {
                t2 = t1;

                ao_task_sched_alarm_stop();
            }

            // Queue is not empty.

            else
            {
                t2 = ao_task_sched_queue_peek();

                p1 = t1->sched.prio;

                p2 = t2->sched.prio;

                if (p1 > p2)
                {
                    t2 = t1;

                    ao_task_sched_alarm_stop();
                }

                else
                {
                    ao_task_sched_queue_push(t1);

                    ao_task_sched_queue_pop();

                    if (p1 == p2)
                    {
                        ao_task_sched_alarm_start();
                    }

                    else
                    {
                        p3 = ao_task_sched_queue_peek_prio();

                        ao_assert(p2 >= p3);

                        if (p2 > p3)
                        {
                            ao_task_sched_alarm_stop();
                        }

                        else
                        {
                            ao_task_sched_alarm_start();
                        }
                    }
                }
            }
        }

        // Task is not ready.

        else
        {
            // Queue is empty.

            // This really should not have happened!

            if (ao_task_sched_queue_is_empty())
            {
                ao_assert(false);

                t2 = NULL;

                ao_task_sched_alarm_stop();
            }

            // Queue is not empty.

            else
            {
                t2 = ao_task_sched_queue_peek();

                ao_task_sched_queue_pop();


                // Queue is empty.

                if (ao_task_sched_queue_is_empty())
                {
                    ao_task_sched_alarm_stop();
                }

                // Queue is not empty.

                else
                {
                    p2 = t2->sched.prio;

                    p3 = ao_task_sched_queue_peek_prio();

                    ao_assert(p2 >= p3);

                    if (p2 > p3)
                    {
                        ao_task_sched_alarm_stop();
                    }

                    else
                    {
                        ao_task_sched_alarm_start();
                    }
                }
            }
        }


        // Task switch in.

        ao_task_switch_in(t2);

        ao_task_running[0] = t2;
    }
    ao_unlock(&l);
}

// ----------------------------------------------------------------------------

#endif

#if defined AO_TASK_SCHED_2 && AO_TASK_CEILING

// ----------------------------------------------------------------------------

void ao_task_ceiling_begin(ao_task_ceiling_t * c, ao_task_slave_t * s)
{
    // Assert.

    ao_assert(c);

    ao_assert(s);

    ao_assert
    (
        c->slave == NULL ||
        c->slave == s
    );


    // Ready.

    if (c->slave) { }

    else
    {
        c->slave = s;

        s->ceilings.less = ao_task_ceiling_less;

        s->ceilings.less_parameter = NULL;

        ao_rb_insert
        (
            &s->ceilings,
            &c->slave_ceilings_node
        );

        ao_task_slave_update(s);
    }
}

void ao_task_ceiling_end(ao_task_ceiling_t * c)
{
    // Assert.

    ao_assert(c);


    // Variables.

    ao_task_slave_t * s;


    // Ready.

    s = c->slave;

    if (s)
    {
        c->slave = NULL;

        ao_rb_remove
        (
            &s->ceilings,
            &c->slave_ceilings_node
        );

        ao_task_slave_update(s);
    }

    else { }
}

ao_uint_t ao_task_ceiling_get_prio(ao_task_ceiling_t const * c)
{
    // Assert.

    ao_assert(c);


    // Variables.

    ao_task_ceiling_t const volatile * C = c;

    ao_uint_t x1;

    ao_uint_t x2;


    // Ready.

    do
    {
        x1 = C->prio;
        x2 = C->prio;
    }
    while (x1 != x2);

    return x1;
}

bool ao_task_ceiling_less(ao_rb_node_t * n1, ao_rb_node_t * n2, void * parameter)
{
    (void) parameter;

    ao_task_ceiling_t * c1 = ao_containerof(n1, ao_task_ceiling_t, slave_ceilings_node);

    ao_task_ceiling_t * c2 = ao_containerof(n2, ao_task_ceiling_t, slave_ceilings_node);

    return c1->prio > c2->prio ? true : false;
}

void ao_task_ceiling_set_prio(ao_task_ceiling_t * c, ao_uint_t p)
{
    // Assert.

    ao_assert(c);

    ao_assert(p <= AO_TASK_PRIO_MAX);


    // Variables.

    ao_lock_t l;

    ao_task_slave_t * s;


    // Ready.

    ao_lock(&l);
    {
        if (p != c->prio)
        {
            c->prio = p;

            s = c->slave;

            if (s)
            {
                ao_assert(s->ceilings.less == ao_task_ceiling_less);

                ao_assert(s->ceilings.less_parameter == NULL);

                ao_rb_remove
                (
                    &s->ceilings,
                    &c->slave_ceilings_node
                );

                ao_rb_insert
                (
                    &s->ceilings,
                    &c->slave_ceilings_node
                );

                ao_task_slave_update(s);
            }
        }
    }
    ao_unlock(&l);
}

// ----------------------------------------------------------------------------

#endif

#if defined AO_TASK_SCHED_2 && AO_TASK_INHERITANCE

// ----------------------------------------------------------------------------

void ao_task_inheritance_begin(ao_task_master_t * m, ao_task_slave_t * s)
{
    // Assert.

    ao_assert(m);

    ao_assert(s);

    ao_assert
    (
        m->slave == NULL ||
        m->slave == s
    );


    // Ready.

    if (m->slave) { }

    else
    {
        m->slave = s;

        s->masters.less = ao_task_master_less;

        s->masters.less_parameter = NULL;

        ao_rb_insert
        (
            &s->masters,
            &m->slave_masters_node
        );

        ao_task_slave_update(s);
    }
}

void ao_task_inheritance_end(ao_task_master_t * m)
{
    // Assert.

    ao_assert(m);


    // Variables.

    ao_task_slave_t * s;


    // Ready.

    s = m->slave;

    if (s)
    {
        m->slave = NULL;

        ao_rb_remove
        (
            &s->masters,
            &m->slave_masters_node
        );

        ao_task_slave_update(s);
    }

    else { }
}

// ----------------------------------------------------------------------------

void ao_task_master_begin(ao_task_master_t * m, ao_task_t * t)
{
    // Assert.

    ao_assert(m);

    ao_assert(!m->task);

    ao_assert(t);


    // Variables.

    ao_task_slave_t * s;


    // Ready.

    ao_list_push_back
    (
        &t->sched.masters,
        &m->task_masters_node
    );

    m->task = t;

    m->prio = t->sched.prio;

    s = m->slave;

    if (s)
    {
        ao_assert(s->masters.less == ao_task_master_less);

        ao_assert(s->masters.less_parameter == NULL);

        ao_rb_remove
        (
            &s->masters,
            &m->slave_masters_node
        );

        ao_rb_insert
        (
            &s->masters,
            &m->slave_masters_node
        );

        ao_task_slave_update(s);
    }

    else { }
}

void ao_task_master_end(ao_task_master_t * m)
{
    // Assert.

    ao_assert(m);

    ao_assert(m->task);


    // Variables.

    ao_task_slave_t * s;

    ao_task_t * t;


    // Ready.

    t = m->task;

    ao_list_remove
    (
        &t->sched.masters,
        &m->task_masters_node
    );

    m->prio = 0;

    m->task = NULL;

    s = m->slave;

    if (s)
    {
        ao_assert(s->masters.less == ao_task_master_less);

        ao_assert(s->masters.less_parameter == NULL);

        ao_rb_remove
        (
            &s->masters,
            &m->slave_masters_node
        );

        ao_rb_insert
        (
            &s->masters,
            &m->slave_masters_node
        );

        ao_task_slave_update(s);
    }

    else { }
}

bool ao_task_master_less(ao_rb_node_t * n1, ao_rb_node_t * n2, void * parameter)
{
    (void) parameter;

    ao_task_master_t * m1 = ao_containerof(n1, ao_task_master_t, slave_masters_node);

    ao_task_master_t * m2 = ao_containerof(n2, ao_task_master_t, slave_masters_node);

    return m1->prio > m2->prio ? true : false;
}

void ao_task_master_update(ao_task_t * t)
{
    // Variables.

    ao_list_t * l;

    ao_task_master_t * m;

    ao_list_node_t * n;

    ao_task_slave_t * s;


    // Ready.

    l = &t->sched.masters;

    n = l->front;

    while (n)
    {
        m = ao_containerof(n, ao_task_master_t, task_masters_node);

        ao_assert(m->task == t);

        m->prio = t->sched.prio;

        s = m->slave;

        if (s)
        {
            ao_assert(s->masters.less == ao_task_master_less);

            ao_assert(s->masters.less_parameter == NULL);

            ao_rb_remove
            (
                &s->masters,
                &m->slave_masters_node
            );

            ao_rb_insert
            (
                &s->masters,
                &m->slave_masters_node
            );

            ao_task_slave_update(s);
        }

        else { }

        n = n->next;
    }
}

// ----------------------------------------------------------------------------

#endif

#if defined AO_TASK_SCHED_2 && AO_TASK_SUBMISSION

// ----------------------------------------------------------------------------

ao_uint_t ao_task_prio_keep(ao_task_t * t)
{
    // Variables.

    ao_rb_node_t * n;

    ao_uint_t p;

    ao_task_slave_t * s;


    // Ready.

    if (ao_rb_is_empty(&t->sched.slaves))
    {
        p = 0;
    }

    else
    {
        n = ao_rb_min(&t->sched.slaves);

        s = ao_containerof(n, ao_task_slave_t, task_slaves_node);

        p = s->prio_keep;
    }

    return p;
}

void ao_task_prio_update_1(ao_task_t * t, ao_uint_t p_new)
{
    // Variables.

    ao_uint_t p_keep;


    // Ready.

    t->sched.prio_backup = p_new;

    p_keep = ao_task_prio_keep(t);

    p_new = ao_max
    (
        p_new,
        p_keep
    );

    ao_task_prio_update_3(t, p_new);
}

void ao_task_prio_update_2(ao_task_t * t)
{
    // Variables.

    ao_uint_t p_backup;

    ao_uint_t p_keep;

    ao_uint_t p_new;


    // Ready.

    p_backup = t->sched.prio_backup;

    p_keep = ao_task_prio_keep(t);

    p_new = ao_max
    (
        p_backup,
        p_keep
    );

    ao_task_prio_update_3(t, p_new);
}

// ----------------------------------------------------------------------------

void ao_task_slave_begin(ao_task_slave_t * s, ao_task_t * t)
{
    // Assert.

    ao_assert(s);

    ao_assert(t);


    // Ready.

    s->task = t;

    t->sched.slaves.less = ao_task_slave_less;

    t->sched.slaves.less_parameter = NULL;

    ao_rb_insert
    (
        &t->sched.slaves,
        &s->task_slaves_node
    );

    ao_task_prio_update_2(t);
}

void ao_task_slave_end(ao_task_slave_t * s)
{
    // Assert.

    ao_assert(s);

    ao_assert(s->task);


    // Variables.

    ao_task_t * t;


    // Ready.

    t = s->task;

    ao_rb_remove
    (
        &t->sched.slaves,
        &s->task_slaves_node
    );

    s->task = NULL;

    ao_task_prio_update_2(t);
}

bool ao_task_slave_less(ao_rb_node_t * n1, ao_rb_node_t * n2, void * parameter)
{
    (void) parameter;

    ao_task_slave_t * s1 = ao_containerof(n1, ao_task_slave_t, task_slaves_node);

    ao_task_slave_t * s2 = ao_containerof(n2, ao_task_slave_t, task_slaves_node);

    return s1->prio_keep > s2->prio_keep ? true : false;
}

ao_uint_t ao_task_slave_prio_keep(ao_task_slave_t * s)
{
    // Variables.

#if AO_TASK_CEILING

    ao_task_ceiling_t * c;

#endif

#if AO_TASK_INHERITANCE

    ao_task_master_t * m;

#endif

#if AO_TASK_SUBMISSION

    ao_rb_node_t * n;

#endif

    ao_uint_t p_ceiling;

    ao_uint_t p_master;


    // Ready.

#if AO_TASK_CEILING

    if (ao_rb_is_empty(&s->ceilings))
    {

#endif

        p_ceiling = 0;

#if AO_TASK_CEILING

    }

    else
    {
        n = ao_rb_min(&s->ceilings);

        c = ao_containerof(n, ao_task_ceiling_t, slave_ceilings_node);

        p_ceiling = c->prio;
    }

#endif

#if AO_TASK_INHERITANCE

    if (ao_rb_is_empty(&s->masters))
    {

#endif

        p_master = 0;

#if AO_TASK_INHERITANCE

    }

    else
    {
        n = ao_rb_min(&s->masters);

        m = ao_containerof(n, ao_task_master_t, slave_masters_node);

        p_master = m->prio;
    }

#endif

    return ao_max
    (
        p_ceiling,
        p_master
    );
}

void ao_task_slave_update(ao_task_slave_t * s)
{
    // Variables.

    ao_task_t * t;


    // Ready.

    s->prio_keep = ao_task_slave_prio_keep(s);

    t = s->task;

    if (t)
    {
        ao_assert(t->sched.slaves.less == ao_task_slave_less);

        ao_assert(t->sched.slaves.less_parameter == NULL);

        ao_rb_remove
        (
            &t->sched.slaves,
            &s->task_slaves_node
        );

        ao_rb_insert
        (
            &t->sched.slaves,
            &s->task_slaves_node
        );

        ao_task_prio_update_2(t);
    }

    else { }
}

// ----------------------------------------------------------------------------

#endif

#if defined AO_TASK_STACK_0

// ----------------------------------------------------------------------------

void ao_boot_task_stack() { }

// ----------------------------------------------------------------------------

void * ao_task_get_stack_beginning(ao_task_t const * t)
{
    (void) t;

    return NULL;
}

void * ao_task_get_stack_beginning_locked(ao_task_t const * t)
{
    (void) t;

    return NULL;
}

// ----------------------------------------------------------------------------

size_t ao_task_get_stack_size(ao_task_t const * t)
{
    (void) t;

    return 0;
}

size_t ao_task_get_stack_size_locked(ao_task_t const * t)
{
    (void) t;

    return 0;
}

// ----------------------------------------------------------------------------

void ao_task_start_stack(ao_task_t * t)
{
    (void) t;
}

// ----------------------------------------------------------------------------

void ao_task_stop_stack(ao_task_t * t)
{
    (void) t;
}

// ----------------------------------------------------------------------------

#endif

#if defined AO_TASK_STACK_1

// ----------------------------------------------------------------------------

void ao_boot_task_stack() { }

// ----------------------------------------------------------------------------

void * ao_task_get_stack_beginning(ao_task_t const * t)
{
    // Assert.

    ao_assert(t);


    // Variables.

    ao_task_t const volatile * T = t;

    void * x1;
    void * x2;


    // Ready.

    do
    {
        x1 = T->stack.beginning;
        x2 = T->stack.beginning;
    }
    while (x1 != x2);

    return x1;
}

void * ao_task_get_stack_beginning_locked(ao_task_t const * t)
{
    ao_assert(t);

    return t->stack.beginning;
}

// ----------------------------------------------------------------------------

size_t ao_task_get_stack_size(ao_task_t const * t)
{
    // Assert.

    ao_assert(t);


    // Variables.

    ao_task_t const volatile * T = t;

    size_t x1;
    size_t x2;


    // Ready.

    do
    {
        x1 = T->stack.size;
        x2 = T->stack.size;
    }
    while (x1 != x2);

    return x1;
}

size_t ao_task_get_stack_size_locked(ao_task_t const * t)
{
    ao_assert(t);

    return t->stack.size;
}

// ----------------------------------------------------------------------------

void ao_task_set_stack(ao_task_t * t, void * b, size_t s)
{
    ao_assert(t);

    ao_lock_t l;

    ao_lock(&l);
    {
        if (t->state == AO_TASK_STOPPED)
        {
            t->stack.beginning = b;

            t->stack.size = s;
        }

        else
        {
            ao_assert(false);
        }
    }
    ao_unlock(&l);
}

// ----------------------------------------------------------------------------

void ao_task_start_stack(ao_task_t * t)
{
    // Notes.

    // The kernel is locked.


    // Assert.

    ao_assert(t);

    ao_assert(t->stack.beginning);


    // Ready.

#if AO_TASK_STACK_HIGH_WATER_MARK

    ao_stack_fill
    (
        t->stack.beginning,
        t->stack.size
    );

    t->stack.high_water_mark = 0;

#endif

}

// ----------------------------------------------------------------------------

void ao_task_stop_stack(ao_task_t * t)
{
    // Notes.

    // The kernel is locked.


    // Assert.

    ao_assert(t);


    // Ready.

#if AO_TASK_STACK_HIGH_WATER_MARK

    void * b = t->stack.beginning;

    if (b)
    {
        t->stack.high_water_mark = ao_stack_get_high_water_mark
        (
            b,
            t->stack.size
        );
    }

#endif

}

// ----------------------------------------------------------------------------

#endif

#if defined AO_TASK_STACK_1 && AO_TASK_STACK_HIGH_WATER_MARK

// ----------------------------------------------------------------------------

size_t ao_task_get_stack_high_water_mark(ao_task_t const * t)
{
    // Assert.

    ao_assert(t);


    // Variables.

    ao_task_t const volatile * T = t;

    size_t x1;
    size_t x2;


    // Ready.

    do
    {
        x1 = T->stack.high_water_mark;
        x2 = T->stack.high_water_mark;
    }
    while (x1 != x2);

    return x1;
}

size_t ao_task_get_stack_high_water_mark_locked(ao_task_t const * t)
{
    ao_assert(t);

    return t->stack.high_water_mark;
}

// ----------------------------------------------------------------------------

void ao_task_stack_high_water_mark(ao_task_t * t)
{
    // Assert.

    ao_assert(t);


    // Variables.

    void * b;

    size_t h;

    ao_lock_t l;

    size_t s;


    // Ready.

    ao_lock(&l);
    {
        b = t->stack.beginning;

        if (b)
        {
            s = t->stack.size;

            h = ao_stack_get_high_water_mark(b, s);
        }

        else
        {
            h = 0;
        }

        t->stack.high_water_mark = h;
    }
    ao_unlock(&l);
}

// ----------------------------------------------------------------------------

#endif

#if defined AO_TASK_STACK_2

// ----------------------------------------------------------------------------

void ao_boot_task_stack() { }

// ----------------------------------------------------------------------------

void * ao_task_get_stack_beginning(ao_task_t const * t)
{
    // Assert.

    ao_assert(t);


    // Variables.

    ao_task_t const volatile * T = t;

    void * x1;
    void * x2;


    // Ready.

    do
    {
        x1 = T->stack.beginning;
        x2 = T->stack.beginning;
    }
    while (x1 != x2);

    return x1;
}

void * ao_task_get_stack_beginning_locked(ao_task_t const * t)
{
    ao_assert(t);

    return t->stack.beginning;
}

// ----------------------------------------------------------------------------

size_t ao_task_get_stack_size(ao_task_t const * t)
{
    // Assert.

    ao_assert(t);


    // Variables.

    ao_task_t const volatile * T = t;

    size_t x1;
    size_t x2;


    // Ready.

    do
    {
        x1 = T->stack.size;
        x2 = T->stack.size;
    }
    while (x1 != x2);

    return x1;
}

size_t ao_task_get_stack_size_locked(ao_task_t const * t)
{
    ao_assert(t);

    return t->stack.size;
}

// ----------------------------------------------------------------------------

void ao_task_set_stack_size(ao_task_t * t, size_t x)
{
    ao_assert(t);

    ao_lock_t l;

    ao_lock(&l);
    {
        if (t->state == AO_TASK_STOPPED)
        {
            t->stack.size = x;
        }

        else
        {
            ao_assert(false);
        }
    }
    ao_unlock(&l);
}

// ----------------------------------------------------------------------------

void ao_task_start_stack(ao_task_t * t)
{
    // Notes.

    // The kernel is locked.


    // Assert.

    ao_assert(t);

    ao_assert(!t->stack.beginning);


    // Variables.

    void * b;

    size_t s;


    // Ready.

    s = t->stack.size;

    if (s == 0)
    {
        s = AO_TASK_STACK_SIZE_DEFAULT;

        t->stack.size = AO_TASK_STACK_SIZE_DEFAULT;
    }

    b = ao_acquire_1(s);

    ao_assert(b);

    t->stack.beginning = b;

#if AO_TASK_STACK_HIGH_WATER_MARK

    ao_stack_fill(b, s);

    t->stack.high_water_mark = 0;

#endif

}

// ----------------------------------------------------------------------------

void ao_task_stop_stack(ao_task_t * t)
{
    // Notes.

    // The kernel is locked.


    // Assert.

    ao_assert(t);


    // Variables.

    void * b;


    // Ready.

    b = t->stack.beginning;

    if (b)
    {

#if AO_TASK_STACK_HIGH_WATER_MARK

        t->stack.high_water_mark = ao_stack_get_high_water_mark(b, t->stack.size);

#endif

        ao_release_1(b);

        t->stack.beginning = NULL;
    }
}

// ----------------------------------------------------------------------------

#endif

#if defined AO_TASK_STACK_2 && AO_TASK_STACK_HIGH_WATER_MARK

// ----------------------------------------------------------------------------

size_t ao_task_get_stack_high_water_mark(ao_task_t const * t)
{
    // Assert.

    ao_assert(t);


    // Variables.

    ao_task_t const volatile * T = t;

    size_t x1;
    size_t x2;


    // Ready.

    do
    {
        x1 = T->stack.high_water_mark;
        x2 = T->stack.high_water_mark;
    }
    while (x1 != x2);

    return x1;
}

size_t ao_task_get_stack_high_water_mark_locked(ao_task_t const * t)
{
    ao_assert(t);

    return t->stack.high_water_mark;
}

// ----------------------------------------------------------------------------

void ao_task_stack_high_water_mark(ao_task_t * t)
{
    // Assert.

    ao_assert(t);


    // Variables.

    void * b;

    size_t h;

    ao_lock_t l;

    size_t s;


    // Ready.

    ao_lock(&l);
    {
        b = t->stack.beginning;

        if (b)
        {
            s = t->stack.size;

            h = ao_stack_get_high_water_mark(b, s);
        }

        else
        {
            h = 0;
        }

        t->stack.high_water_mark = h;
    }
    ao_unlock(&l);
}

// ----------------------------------------------------------------------------

#endif

#if defined AO_THRESHOLD

// ----------------------------------------------------------------------------

static void ao_threshold_update_1(ao_threshold_t * T, ao_uint_t v);

static void ao_threshold_update_2(ao_threshold_t * T, ao_uint_t v);

// ----------------------------------------------------------------------------

void ao_threshold_add(ao_threshold_t * T, ao_uint_t v)
{
    // Assert.

    ao_assert(T);


    // Variables.

    ao_lock_t L;


    // Ready.

    if (v != 0)
    {
        ao_lock(&L);
        {
            ao_threshold_update_2(T, T->value + v);
        }
        ao_unlock(&L);
    }
}

void ao_threshold_adjust(ao_threshold_t * T, ao_threshold_adjust_t a, void * p)
{
    // Assert.

    ao_assert(T);

    ao_assert(a);


    // Variables.

    ao_lock_t L;

    ao_uint_t v;


    // Ready.

    ao_lock(&L);
    {
        v = a(T->value, p);

        ao_threshold_update_1(T, v);
    }
    ao_unlock(&L);
}

void ao_threshold_decrement(ao_threshold_t * T)
{
    // Assert.

    ao_assert(T);


    // Variables.

    ao_lock_t L;


    // Ready.

    ao_lock(&L);
    {
        ao_threshold_update_2(T, T->value - 1);
    }
    ao_unlock(&L);
}

void ao_threshold_divide(ao_threshold_t * T, ao_uint_t v)
{
    // Assert.

    ao_assert(T);

    ao_assert(v != 0);


    // Variables.

    ao_lock_t L;


    // Ready.

    if (v != 1)
    {
        ao_lock(&L);
        {
            ao_threshold_update_1(T, T->value / v);
        }
        ao_unlock(&L);
    }
}

void ao_threshold_increment(ao_threshold_t * T)
{
    // Assert.

    ao_assert(T);


    // Variables.

    ao_lock_t L;


    // Ready.

    ao_lock(&L);
    {
        ao_threshold_update_2(T, T->value + 1);
    }
    ao_unlock(&L);
}

void ao_threshold_modulo(ao_threshold_t * T, ao_uint_t v)
{
    // Assert.

    ao_assert(T);

    ao_assert(v != 0);


    // Variables.

    ao_lock_t L;


    // Ready.

    ao_lock(&L);
    {
        ao_threshold_update_1(T, T->value % v);
    }
    ao_unlock(&L);
}

void ao_threshold_multiply(ao_threshold_t * T, ao_uint_t v)
{
    // Assert.

    ao_assert(T);


    // Variables.

    ao_lock_t L;


    // Ready.

    if (v != 1)
    {
        ao_lock(&L);
        {
            ao_threshold_update_1(T, T->value * v);
        }
        ao_unlock(&L);
    }
}

void ao_threshold_set(ao_threshold_t * T, ao_uint_t v)
{
    // Assert.

    ao_assert(T);


    // Variables.

    ao_lock_t L;


    // Ready.

    ao_lock(&L);
    {
        ao_threshold_update_1(T, v);
    }
    ao_unlock(&L);
}

void ao_threshold_subtract(ao_threshold_t * T, ao_uint_t v)
{
    // Assert.

    ao_assert(T);


    // Variables.

    ao_lock_t L;


    // Ready.

    if (v != 0)
    {
        ao_lock(&L);
        {
            ao_threshold_update_2(T, T->value - v);
        }
        ao_unlock(&L);
    }
}

void ao_threshold_subtract_from(ao_threshold_t * T, ao_uint_t v)
{
    // Assert.

    ao_assert(T);


    // Variables.

    ao_lock_t L;


    // Ready.

    ao_lock(&L);
    {
        ao_threshold_update_1(T, v - T->value);
    }
    ao_unlock(&L);
}

void ao_threshold_update_1(ao_threshold_t * T, ao_uint_t v)
{
    // Notes.

    // The kernel is locked.


    // Ready.

    if (v != T->value)
    {
        ao_threshold_update_2(T, v);
    }
}

void ao_threshold_update_2(ao_threshold_t * T, ao_uint_t v)
{
    // Notes.

    // The kernel is locked.


    // Assert.

    ao_assert(T->match);


    // Variables.

    ao_list_node_t * n;

    ao_threshold_wait_t * W;


    // Ready.

    if (T->match(v, T->match_parameter))
    {
        n = T->list.front;

        if (n)
        {
            do
            {
                W = ao_containerof(n, ao_threshold_wait_t, node);

                W->result = true;

                ao_async_check(&W->async);

                n = n->next;
            }
            while (n);

            ao_list_remove_all(&T->list);
        }

        if (T->adjust)
        {
            v = T->adjust(v, T->adjust_parameter);
        }
    }

    T->value = v;
}

// ----------------------------------------------------------------------------

bool ao_threshold_wait(ao_threshold_t * T, ao_time_t t)
{
    return ao_threshold_wait_from(T, t, ao_now());
}

void ao_threshold_wait_begin(ao_threshold_wait_t * W)
{
    // Assert.

    ao_assert(W);

    ao_assert(W->threshold);

    ao_assert(W->threshold->match);


    // Variables.

    ao_lock_t L;

    ao_threshold_t * T;


    // Ready.

    T = W->threshold;

    ao_async_begin(&W->async);

    ao_lock(&L);
    {
        // Threshold value is a match.

        if (T->match(T->value, T->match_parameter))
        {
            if (T->adjust)
            {
                T->value = T->adjust(T->value, T->adjust_parameter);
            }

            W->result = true;

            ao_async_check(&W->async);
        }

        // Threshold value is not a match.

        else
        {
            W->result = false;

            ao_list_push_back(&T->list, &W->node);
        }
    }
    ao_unlock(&L);
}

void ao_threshold_wait_end(ao_threshold_wait_t * W)
{
    // Assert.

    ao_assert(W);

    ao_assert(W->threshold);


    // Variables.

    ao_lock_t L;


    // Ready.

    ao_lock(&L);
    {
        if (W->result) { }

        else
        {
            ao_list_remove(&W->threshold->list, &W->node);
        }
    }
    ao_unlock(&L);

    ao_async_end(&W->async);
}

bool ao_threshold_wait_forever(ao_threshold_t * T)
{
    return ao_threshold_wait_from(T, AO_INFINITY, 0);
}

bool ao_threshold_wait_from(ao_threshold_t * T, ao_time_t t, ao_time_t b)
{
    // Variables.

    ao_threshold_wait_t W;


    // Ready.

    ao_clear(&W, ao_threshold_wait_t);

    W.threshold = T;


    ao_threshold_wait_begin(&W);

    ao_await_from(&W.async, t, b);

    ao_threshold_wait_end(&W);


    return W.result;
}

bool ao_threshold_wait_try(ao_threshold_t * T)
{
    // Variables.

    ao_threshold_wait_t W;


    // Ready.

    ao_clear(&W, ao_threshold_wait_t);

    W.threshold = T;


    ao_threshold_wait_begin(&W);

    ao_threshold_wait_end(&W);


    return W.result;
}

// ----------------------------------------------------------------------------

#endif

#if defined AO_TIMER

// ----------------------------------------------------------------------------

static void ao_timer(void * x);

// ----------------------------------------------------------------------------

void ao_timer(void * x)
{
    // Notes.

    // This is an alarm callback.

    // The kernel is not locked.


    // Assert.

    ao_assert(x);


    // Variables.

    ao_time_t    b;

    ao_proc_t    c;

    void *       cp;

    ao_lock_t    l;

    ao_time_t    p;

    ao_timer_t * t = x;


    // Ready.

    // Callback.

    ao_lock(&l);
    {
        c = t->callback;

        cp = t->callback_parameter;
    }
    ao_unlock(&l);

    if (c)
    {
        c(cp);
    }


    // Start over.

    ao_lock(&l);
    {
        p = t->period;

        if (p > 0)
        {
            b = t->end;

            t->end = b + p;

            ao_alarm_start_from_locked(&t->alarm, p, b);
        }
    }
    ao_unlock(&l);
}

void ao_timer_start(ao_timer_t * t, ao_time_t d, ao_time_t p)
{
    ao_timer_start_from(t, d, p, ao_now());
}

void ao_timer_start_from(ao_timer_t * t, ao_time_t d, ao_time_t p, ao_time_t b)
{
    // Assert.

    ao_assert(t);


    // Variables.

    ao_alarm_t * a = &t->alarm;

    ao_lock_t l;


    // Ready.

    ao_lock(&l)
    {
        // Stop.

        ao_alarm_stop_locked(a);


        // Start.

        t->period = p;

        t->end = b + d;

        a->callback = ao_timer;

        a->callback_parameter = t;

        ao_alarm_start_from_locked(a, d, b);
    }
    ao_unlock(&l);
}

void ao_timer_stop(ao_timer_t * t)
{
    // Assert.

    ao_assert(t);


    // Variables.

    ao_lock_t l;


    // Ready.

    ao_lock(&l)
    {
        ao_alarm_stop_locked(&t->alarm);

        t->period = 0;
    }
    ao_unlock(&l);
}

// ----------------------------------------------------------------------------

#endif

#if defined AO_WR

// ----------------------------------------------------------------------------

bool ao_wr_lock_read(ao_wr_t * W, ao_time_t t)
{
    return ao_wr_lock_read_from(W, t, ao_now());
}

void ao_wr_lock_read_begin(ao_wr_lock_t * L)
{
    // Assert.

    ao_assert(L);

    ao_assert(L->wr);


    // Variables.

    bool b1;

    bool b2;

    ao_lock_t l;

    ao_wr_t * W;


    // Ready.

    W = L->wr;

    ao_async_begin(&L->async);

    ao_lock(&l);
    {
        // Writing in progress.

        // Writing in standby.

        b1 = W->w_active;

        b2 = !ao_list_is_empty(&W->w_waiting);

        if (b1 || b2)
        {
            ao_list_push_back(&W->r_waiting, &L->node);

            L->result = false;
        }

        // No writing.

        else
        {
            W->r_active++;

            L->result = true;

            ao_async_check(&L->async);
        }
    }
    ao_unlock(&l);
}

void ao_wr_lock_read_end(ao_wr_lock_t * L)
{
    // Assert.

    ao_assert(L);

    ao_assert(L->wr);


    // Variables.

    ao_lock_t l;


    // Ready.

    ao_lock(&l);
    {
        if (L->result) { }

        else
        {
            ao_list_remove(&L->wr->r_waiting, &L->node);
        }
    }
    ao_unlock(&l);

    ao_async_end(&L->async);
}

bool ao_wr_lock_read_forever(ao_wr_t * W)
{
    return ao_wr_lock_read_from(W, AO_INFINITY, 0);
}

bool ao_wr_lock_read_from(ao_wr_t * W, ao_time_t t, ao_time_t b)
{
    // Variables.

    ao_wr_lock_t L;


    // Ready.

    ao_clear(&L, ao_wr_lock_t);

    L.wr = W;


    // Ready.

    ao_wr_lock_read_begin(&L);

    ao_await_from(&L.async, t, b);

    ao_wr_lock_read_end(&L);


    // Ready.

    return L.result;
}

bool ao_wr_lock_read_try(ao_wr_t * W)
{
    // Variables.

    ao_wr_lock_t L;


    // Ready.

    ao_clear(&L, ao_wr_lock_t);

    L.wr = W;


    // Ready.

    ao_wr_lock_read_begin(&L);

    ao_wr_lock_read_end(&L);


    // Ready.

    return L.result;
}

// ----------------------------------------------------------------------------

bool ao_wr_lock_write(ao_wr_t * W, ao_time_t t)
{
    return ao_wr_lock_write_from(W, t, ao_now());
}

void ao_wr_lock_write_begin(ao_wr_lock_t * L)
{
    // Assert.

    ao_assert(L);

    ao_assert(L->wr);


    // Variables.

    bool b1;

    bool b2;

    ao_lock_t l;

    ao_wr_t * W;


    // Ready.

    W = L->wr;

    ao_async_begin(&L->async);

    ao_lock(&l);
    {
        // Reading in progress.

        // Writing in progress.

        b1 = W->r_active > 0 ? true : false;

        b2 = W->w_active;

        if (b1 || b2)
        {
            ao_list_push_back(&W->w_waiting, &L->node);

            L->result = false;
        }

        // No reading.

        // No writing.

        else
        {
            ao_assert(ao_list_is_empty(&W->w_waiting));

            W->w_active = true;

            L->result = true;

            ao_async_check(&L->async);
        }
    }
    ao_unlock(&l);
}

void ao_wr_lock_write_end(ao_wr_lock_t * L)
{
    // Assert.

    ao_assert(L);

    ao_assert(L->wr);


    // Variables.

    ao_lock_t l;


    // Ready.

    ao_lock(&l);
    {
        if (L->result) { }

        else
        {
            ao_list_remove(&L->wr->w_waiting, &L->node);
        }
    }
    ao_unlock(&l);

    ao_async_end(&L->async);
}

bool ao_wr_lock_write_forever(ao_wr_t * W)
{
    return ao_wr_lock_write_from(W, AO_INFINITY, 0);
}

bool ao_wr_lock_write_from(ao_wr_t * W, ao_time_t t, ao_time_t b)
{
    // Variables.

    ao_wr_lock_t L;


    // Ready.

    ao_clear(&L, ao_wr_lock_t);

    L.wr = W;


    // Ready.

    ao_wr_lock_write_begin(&L);

    ao_await_from(&L.async, t, b);

    ao_wr_lock_write_end(&L);


    // Ready.

    return L.result;
}

bool ao_wr_lock_write_try(ao_wr_t * W)
{
    // Variables.

    ao_wr_lock_t L;


    // Ready.

    ao_clear(&L, ao_wr_lock_t);

    L.wr = W;


    // Ready.

    ao_wr_lock_write_begin(&L);

    ao_wr_lock_write_end(&L);


    // Ready.

    return L.result;
}

// ----------------------------------------------------------------------------

void ao_wr_unlock_read(ao_wr_t * W)
{
    // Assert.

    ao_assert(W);

    ao_assert(W->r_active > 0)

    ao_assert(W->w_active == false);


    // Variables.

    ao_lock_t l;

    ao_wr_lock_t * L;

    ao_list_node_t * n;

    ao_uint_t r;


    // Ready.

    ao_lock(&l);
    {
        r = W->r_active;

        r--;

        // Reading in progress.

        if (r) { }

        // No more reading.

        else
        {
            // Writing in standby.

            n = W->w_waiting.front;

            if (n)
            {
                ao_list_remove_front(&W->w_waiting);

                W->w_active = true;

                L = ao_containerof(n, ao_wr_lock_t, node);

                L->result = true;

                ao_async_check(&L->async);
            }

            // No more writing.

            else { }
        }

        W->r_active = r;
    }
    ao_unlock(&l);
}

// ----------------------------------------------------------------------------

void ao_wr_unlock_write(ao_wr_t * W)
{
    // Assert.

    ao_assert(W);

    ao_assert(W->r_active == 0);

    ao_assert(W->w_active == true);


    // Variables.

    ao_lock_t l;

    ao_wr_lock_t * L;

    ao_list_node_t * n;

    ao_uint_t r;


    // Ready.

    ao_lock(&l);
    {
        // Writing in standby.

        n = W->w_waiting.front;

        if (n)
        {
            ao_list_remove_front(&W->w_waiting);

            L = ao_containerof(n, ao_wr_lock_t, node);

            L->result = true;

            ao_async_check(&L->async);
        }

        // No more writing.

        else
        {
            W->w_active = false;

            // Reading in standby.

            n = W->r_waiting.front;

            if (n)
            {
                r = 0;

                do
                {
                    r++;

                    L = ao_containerof(n, ao_wr_lock_t, node);

                    n = n->next;

                    L->result = true;

                    ao_async_check(&L->async);
                }
                while (n);

                W->r_active = r;

                ao_list_remove_all(&W->r_waiting);
            }

            // No more reading.

            else { }
        }
    }
    ao_unlock(&l);
}

// ----------------------------------------------------------------------------

#endif

#if defined AO_XCH

// ----------------------------------------------------------------------------

void ao_xch_client(ao_xch_client_t * C, ao_time_t t)
{
    ao_xch_client_from(C, t, ao_now());
}

void ao_xch_client_begin(ao_xch_client_t * C)
{
    // Assert.

    ao_assert(C);

    ao_assert(C->server == NULL);

    ao_assert(C->xch);


    // Variables.

    ao_lock_t L;

    ao_list_node_t * n;

    ao_xch_server_t * S;

#if AO_TASK_INHERITANCE

    ao_task_t * T;

#endif

    ao_xch_t * X;


    // Ready.

    X = C->xch;

    ao_async_begin(&C->async);

    ao_lock(&L);
    {

#if AO_TASK_INHERITANCE

        T = ao_self_locked();

        C->task = T;

#endif

        C->result = false;


        // Servers are available.

        n = X->servers.front;

        if (n)
        {
            S = ao_containerof(n, ao_xch_server_t, node);

            ao_list_remove(&X->servers, n);

#if AO_TASK_INHERITANCE

            ao_task_slave_begin(&S->slave, S->task);

            ao_task_master_begin(&C->master, T);

            ao_task_inheritance_begin(&C->master, &S->slave);

#endif

            S->result = true;

            S->client = C;

            ao_async_check(&S->async);

            C->server = S;
        }

        // Servers are not available.

        else
        {
            ao_list_push_back(&X->clients, &C->node);
        }
    }
    ao_unlock(&L);
}

void ao_xch_client_end(ao_xch_client_t * C)
{
    // Assert.

    ao_assert(C);

    ao_assert(C->xch);


    // Variables.

    ao_lock_t L;

    ao_xch_server_t * S;


    // Ready.

    ao_lock(&L);
    {
        if (C->result) { }

        else
        {
            S = C->server;

            if (S)
            {

#if AO_TASK_INHERITANCE

                ao_task_inheritance_end(&C->master);

                ao_task_master_end(&C->master);

                ao_task_slave_end(&S->slave);

#endif

                S->client = NULL;

                C->server = NULL;
            }

            else
            {
                ao_list_remove(&C->xch->clients, &C->node);
            }
        }
    }
    ao_unlock(&L);

    ao_async_end(&C->async);
}

void ao_xch_client_forever(ao_xch_client_t * C)
{
    ao_xch_client_from(C, AO_INFINITY, 0);
}

void ao_xch_client_from(ao_xch_client_t * C, ao_time_t t, ao_time_t b)
{
    ao_assert(C);

    ao_xch_client_begin(C);

    ao_await_from(&C->async, t, b);

    ao_xch_client_end(C);
}

// ----------------------------------------------------------------------------

void ao_xch_server(ao_xch_server_t * S, ao_time_t t)
{
    ao_xch_server_from(S, t, ao_now());
}

void ao_xch_server_begin(ao_xch_server_t * S)
{
    // Assert.

    ao_assert(S);

    ao_assert(S->client == NULL);

    ao_assert(S->xch);


    // Variables.

    ao_xch_client_t * C;

    ao_lock_t L;

    ao_list_node_t * n;

    bool r;

#if AO_TASK_INHERITANCE

    ao_task_t * T;

#endif

    ao_xch_t * X;


    // Ready.

    X = S->xch;

    ao_async_begin(&S->async);

    ao_lock(&L);
    {

#if AO_TASK_INHERITANCE

        T = ao_self_locked();

        S->task = T;

#endif

        // Clients are available.

        n = X->clients.front;

        if (n)
        {
            C = ao_containerof(n, ao_xch_client_t, node);

            ao_list_remove(&X->clients, n);

#if AO_TASK_INHERITANCE

            ao_task_slave_begin(&S->slave, T);

            ao_task_master_begin(&C->master, C->task);

            ao_task_inheritance_begin(&C->master, &S->slave);

#endif

            S->client = C;

            S->result = true;

            ao_async_check(&S->async);

            C->server = S;
        }

        // Clients are not available.

        else
        {
            S->result = false;

            ao_list_push_back(&X->servers, &S->node);
        }
    }
    ao_unlock(&L);
}

void ao_xch_server_end(ao_xch_server_t * S)
{
    // Assert.

    ao_assert(S);

    ao_assert(S->xch);


    // Variables.

    ao_lock_t L;


    // Ready.

    ao_lock(&L);
    {
        if (S->result) { }

        else
        {
            ao_list_remove(&S->xch->servers, &S->node);
        }
    }
    ao_unlock(&L);

    ao_async_end(&S->async);
}

void ao_xch_server_forever(ao_xch_server_t * S)
{
    ao_xch_server_from(S, AO_INFINITY, 0);
}

void ao_xch_server_from(ao_xch_server_t * S, ao_time_t t, ao_time_t b)
{
    ao_assert(S);

    ao_xch_server_begin(S);

    ao_await_from(&S->async, t, b);

    ao_xch_server_end(S);
}

void ao_xch_server_reply(ao_xch_server_t * S)
{
    // Assert.

    ao_assert(S);


    // Variables.

    ao_xch_client_t * C = S->client;

    ao_lock_t L;


    // Ready.

    ao_lock(&L);
    {
        if (C)
        {
            S->client = NULL;

            S->result = true;

#if AO_TASK_INHERITANCE

            ao_task_inheritance_end(&C->master);

            ao_task_master_end(&C->master);

            ao_task_slave_end(&S->slave);

#endif

            C->result = true;

            C->server = NULL;

            ao_async_check(&C->async);
        }

        else
        {
            S->result = false;
        }
    }
    ao_unlock(&L);
}

void ao_xch_server_try(ao_xch_server_t * S)
{
    ao_xch_server_begin(S);

    ao_xch_server_end(S);
}

// ----------------------------------------------------------------------------

#endif

#if defined AO_YIELD

// ----------------------------------------------------------------------------

void ao_yield()
{
    ao_task_t * t = ao_self();

    ao_lock_t l;

    ao_lock(&l);
    {
        ao_task_pend(t, AO_TASK_YIELDING);
    }
    ao_unlock(&l);

    while (ao_task_is_yielding(t)) { }
}

void ao_yield_to(ao_task_t * t)
{
    // Assert.

    ao_assert(t);


    // Variables.

    ao_block_t b;

    ao_lock_t l;

    ao_task_t * s;


    // Ready.

    s = ao_self();

    if (t != s)
    {
        ao_clear(&b, ao_block_t);

        b.beginning = 0;

        b.timeout = AO_INFINITY;

        ao_lock(&l);
        {
            ao_task_unblock(t);

            ao_block(&b);
        }
        ao_unlock(&l);

        while (ao_task_is_blocking(s)) { }
    }
}

// ----------------------------------------------------------------------------

#endif

// ----------------------------------------------------------------------------
