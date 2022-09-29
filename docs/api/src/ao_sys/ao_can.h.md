---
author: "Stefan Wagner"
date: 2022-09-23
draft: true
external:
- https://en.wikipedia.org/wiki/CAN_bus : "CAN"
permalink: /api/src/ao_sys/ao_can.h/
toc: true
---

# Include

| `stdint.h` |

# Types

## `ao_can_t`

```c
typedef struct ao_can_t ao_can_t;
```

Represents a CAN message.

# Structs

## `ao_can_t`

```c
struct  ao_can_t
{
    uint64_t         data;
    union
    {
        struct
        {
            uint32_t eid : 18;
            uint32_t sid : 11;
            uint32_t     : 3;
        };
        struct
        {
            uint32_t xid : 29;
            uint32_t ide : 1;
            uint32_t rtr : 1;
            uint32_t     : 1;
        };
    };
    struct
    {
        uint8_t      dlc : 4;
        uint8_t          : 4;
    };
};
```

| `data` | Each data message carries up to 8 bytes of data or payload. This member is irrelevant for remote messages, since these do not carry data. |
| `dlc` | The data length code indicates the number of data bytes in data messages. It is irrelevant in remote messages. |
| `eid` | The extension identifier specifies the 18 least significant bits of the identifier of an extended message. It is irrelevant for standard messages. |
| `ide` | The identifier extension specifies whether the message is a standard message (0) or an extended messages (1). |
| `rtr` | The remote transmission request specifies whether the message is a data message (0) or a remote messages (1). |
| `sid` | The standard identifier is the identifier of a standard message. In case of an extended message, this member specifies the 11 most significant bits of its identifier. |
| `xid` | The entire 29-bit identifier, which is relevant only for extended messages. |
