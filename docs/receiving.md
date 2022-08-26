---
author: "Stefan Wagner"
date: 2022-08-24
description: "Receiving data in the ao real-time operating system."
draft: false
permalink: /receiving/
subtitle: "Receiving data from an opaque source"
title: "Receiving"
toc: false
---

Some sensors send their data as a continuous stream of bytes, that a microcontroller can receive with a serial port, such as UART. For example, GPS receivers usually send NMEA messages in the form of ASCII text.

In order to process such data in software, one could develop a module that runs a single [task](tasks.md) receiving bytes one by one. In addition to temporarily storing each byte in a buffer, the task could take measures to identify the ending of a message. Once a message has been received completely, it can be processed.

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

In order to not waste time waiting for the next character, the receiving part should be implemented in a blocking fashion. Therefore, the task could utilize a [stream](modules/stream.md), given an object encapsulating the popping of data from a stream.

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

Of course, the `recv` object must be properly initialized by the application before starting the message processing. Out the box, the framework supports [receiving data from a stream](modules/recv-from-stream.md) ...

```c
ao_recv_from_stream(recv, spop);
```

... and [receiving data from a callback](modules/recv-from-callback.md). The latter can be quite useful, for example when implementing a mock for a testing scenario.

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
