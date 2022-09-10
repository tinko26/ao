---
author: "Stefan Wagner"
date: 2022-09-10
draft: true
external:
- https://en.wikipedia.org/wiki/Coroutine : "Coroutine"
- https://en.wikipedia.org/wiki/Producer-consumer_problem : "Producer-consumer problem"
permalink: /coroutines/
seealso:
- /api/src/ao_sys/ao_yield.h/
toc: true
---

# Example

```c
ao_task_t * consumer;
ao_task_t * producer;
```

```c
void consumer_proc(void * x)
{
    while (1)
    {
        // Wait for the producer to produce something.
        ao_yield_to(producer);

        // Consume what the producer has produced.
        consume();
    }
}
```

```c
void producer_proc(void * x)
{
    while (1)
    {
        // Produce something.
        produce();

        // Wait for the consumer to consume what has been produced.
        ao_yield_to(consumer);
    }
}
```
