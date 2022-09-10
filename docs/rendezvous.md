---
author: "Stefan Wagner"
date: 2022-09-10
draft: true
permalink: /rendezvous/
seealso:
- /api/src/ao_sys/ao_rendezvous.h/
toc: true
---

# Example

...

Set up the exchange function. Assume tasks are exchanging doubles.

```c
void exchange(void * pin, void * pout, void * parameter)
{
    double * din = pin;
    double * dout = pout;

    *dout = *din;
}
```

Set up the waiting.

```c
double din;
double dout = 3.14159;
ao_rendezvous_t * r
ao_rendezvous_wait_t * w;
```

```c
w->exchange = exchange;
w->ptr_in = &din;
w->ptr_out = &dout;
w->rendezvous = r;
```

```c
ao_rendezvous(w, AO_MILLISECONDS(500));

if (w->result)
{
    // A rendezvous has happened.

    if (din > dout)
    {
        // Other task has sent a greater value.
    }
}
```

...
