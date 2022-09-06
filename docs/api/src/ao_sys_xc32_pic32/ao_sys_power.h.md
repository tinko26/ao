---
api: true
author: "Stefan Wagner"
date: 2022-09-05
description: "The /src/ao_sys_xc32_pic32/ao_sys_power.h file of the ao real-time operating system."
draft: true
permalink: /api/src/ao_sys_xc32_pic32/ao_sys_power.h/
subtitle: "System power-saving modes"
title: "ao_sys_power.h"
toc: true
---

# Functions

Enter idle mode.

```c
void ao_sys_idle();
```

Enter sleep mode.

```c
void ao_sys_sleep();
```

Enter idle or sleep mode. This function executes a `WAIT` instruction.

```c
void ao_sys_wait();
```

Enter idle mode upon a `WAIT`.

```c
void ao_sys_wait_idle();
```

Enter sleep mode upon a `WAIT`.

```c
void ao_sys_wait_sleep();
```

# External Links

| [PIC32 Family Reference Manual, Section 10, Power-Saving Modes](https://microchip.com/DS61130) |
