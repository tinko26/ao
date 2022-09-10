---
author: "Stefan Wagner"
date: 2022-09-05
draft: true
external:
- https://microchip.com/DS61130 : "PIC32 Family Reference Manual, Section 10, Power-Saving Modes"
permalink: /api/src/ao_sys_xc32_pic32/ao_sys_power.h/
toc: true
---

# Functions

## `ao_sys_idle`

```c
void ao_sys_idle();
```

Enters idle mode.

## `ao_sys_sleep`

```c
void ao_sys_sleep();
```

Enters sleep mode.

## `ao_sys_wait`

```c
void ao_sys_wait();
```

Executes a `WAIT` instruction. Eventually, this function enters idle or sleep mode. 

## `ao_sys_wait_idle`

```c
void ao_sys_wait_idle();
```

Sets up to enter idle mode upon the execution of a `WAIT` instruction.

## `ao_sys_wait_sleep`

```c
void ao_sys_wait_sleep();
```

Sets up to enter sleep mode upon the execution of a `WAIT` instruction.
