---
author: "Stefan Wagner"
date: 2022-09-10
draft: true
external:
- https://en.wikipedia.org/wiki/Monitor_(synchronization) : "Monitor"
- https://en.wikipedia.org/wiki/Producer-consumer_problem : "Producer-consumer problem"
permalink: /monitors/
seealso:
- /api/src/ao_sys/ao_monitor.h/
toc: true
---

# Example

```c
ao_mutex_t * mutex;
```

```c
ao_monitor_t not_empty = { .mutex = mutex };
ao_monitor_t not_full  = { .mutex = mutex };
```

```c
int volatile count;
```

```c
bool is_empty() { return count == 0; }
bool is_full()  { return count == 10; }
```

```c
ao_task_t * consumer;
ao_task_t * producer;
```

```c
void consumer_proc(void * x)
{
    while (1)
    {
        ao_monitor_enter_forever(&not_empty);
        {
            while (is_empty())
            {
                ao_monitor_wait_forever(&not_empty);
            }

            count--;

            ao_monitor_notify(&not_full);
        }
        ao_monitor_exit(&not_empty);
    }
}
```

```c
void producer_proc(void * x)
{
    while (1)
    {
        ao_monitor_enter_forever(&not_full);
        {
            while (is_full())
            {
                ao_monitor_wait_forever(&not_full);
            }

            count++;

            ao_monitor_notify(&not_empty);
        }
        ao_monitor_exit(&not_full);
    }
}
```