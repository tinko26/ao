---
author: "Stefan Wagner"
date: 2022-08-17
description: "The ao_recv.h module of the ao real-time operating system."
draft: false
permalink: /modules/recv/
title: "ao_recv.h"
---

# ao_recv.h

This module provides an abstraction for tasks to receive data from an opaque source either in a blocking or in a non-blocking fashion.

## Example

Some sensors send their data as a continuous stream of bytes, that a microcontroller can receive with a serial port, such as UART. For example, GPS receivers usually send NMEA messages in the form of ASCII text.

In order to process such data in software, one could develop a module that runs a single task receiving bytes one by one. In addition to temporarily storing each byte in a buffer, the task could take measures to identify the ending of a message. Once a message has been received completely, it can be processed.

```c
while (1)
{
    // Receive next character.

    // Append the character to the buffer.

    if (/* character marks end of message */)
    {
        // Process the message.

        // Clear the buffer.
    }
}
```

In order to not waste time waiting for the next character, the receiving part should be implemented in a blocking fashion. Therefore, the task could utilize a [stream](stream.md), given an object encapsulating the popping of data from a stream.

```c
ao_spop_t * spop;
```

```c
char c;

spop->count_min = 1;
spop->count_max = 1;
spop->ptr = &c;

while (1)
{
    ao_spop_forever(spop);

    if (spop->result)
    {
        // Character has been received and stored
        // in variable c.

        // Append c to the buffer.

        if (/* c marks end of message */)
        {
            // Process the message.

            // Clear the buffer.
        }
    }
}
```

Implemented that way, the module is fairly independent of the data source, that is, it can process messages no matter where they originate from. Still, the module depends on data being popped from a stream.

However, independence can be driven even further, given an object encapsulating the receiving of data from an opaque source.

```c
ao_recv_t * recv;
```

```c
char c;

recv->count_min = 1;
recv->count_max = 1;
recv->ptr = &c;

while (1)
{
    ao_recv_forever(recv);

    if (recv->result)
    {
        // Character has been received and stored
        // in variable c.

        // Append c to the buffer.

        if (/* c marks end of message */)
        {
            // Process the message.

            // Clear the buffer.
        }
    }
}
```

Of course, the `recv` object must be properly initialized by the application before starting the message processing. Out the box, the framework supports [receiving data from a stream](recv-from-stream.md) ...

```c
ao_recv_from_stream(recv, spop);
```

... and [receiving data from a callback](recv-from-callback.md). The latter can be quite useful, for example when implementing a mock for a testing scenario.

```c
void callback(ao_recv_t * x)
{
    static char c = 'A';

    *((char *) x->ptr) = c++;
    x->result = true;
}
```

```c
ao_recv_from_callback(recv, callback);
```

## Types

### Receiving

The `ao_recv_t` type represents the receiving of data.

```c
struct ao_recv_t
{
    ao_async_t      async;
    ao_recv_proc_t  begin;
    size_t volatile count;
    size_t          count_max;
    size_t          count_min;
    ao_recv_proc_t  end;
    void *          parameter;
    void *          ptr;
    bool   volatile result;
};
```

It consists of the following members.

| Member | |
|--------|-|
| `async` | The asynchronous event. |
| `begin` | The function beginning the receiving. |
| `count` | The number of received bytes. |
| `count_max` | The maximum number of bytes to receive. |
| `count_min` | The minimum number of bytes to receive. |
| `end` | The function ending the receiving. |
| `parameter` | An additional parameter. |
| `ptr` | The location to store the received data. |
| `result` | Indicates whether at least `count_min` bytes and at most `count_max` bytes have been received. |

### Receiving Procedure

The `ao_recv_proc_t` represents a function beginning or ending a receiving.

```c
typedef void (* ao_recv_proc_t) (ao_recv_t * x);
```

## Functions

Data can be received in a blocking fashion.

```c
ao_recv_t * x;
```

```c
// Receive with timeout.
ao_recv(x, AO_MILLISECONDS(500));

// Receive with timeout and beginning.
ao_recv_from(x, AO_MILLISECONDS(500), ao_now());

// Receive without timeout.
ao_recv_forever(x);
```

Also, data can be received in a non-blocking fashion, which succeeds, only if data is available immediately.

```c
ao_recv_try(x);
```

Finally, the process can be stripped down into the three stages of beginning, awaiting, and ending the receiving of data.

```c
// Begin.
ao_recv_begin(x);

// Await.
ao_await(&x->async, AO_MILLISECONDS(500));

// End.
ao_recv_end(x);
```

## Usage

Prior to calling any of the above functions, the receiving proxy must be initialized properly.

```c
// The buffer to store the received data.
uint8_t data[4];
```

```c
// The minimum number of bytes to receive.
x->count_min = 1;

// The maximum number of bytes to receive.
x->count_max = 4;

// The pointer to the store.
x->ptr = data;
```

Afterwards, it should be verified whether data has actually been received.

```c
if (x->result)
{
    // x->count bytes have been received
    // and stored in the data variable.
}
```
