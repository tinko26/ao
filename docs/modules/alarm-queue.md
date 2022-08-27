---
author: "Stefan Wagner"
date: 2022-08-15
description: "The ao_alarm_queue.h module of the ao real-time operating system."
draft: true
permalink: /modules/alarm-queue/
title: "<code>ao_alarm_queue.h</code>"
---

# Overview

The alarm queue ...

# Configuration

This module defines a single macro constant selecting the implementation of the alarm queue. The default value is `5`, which selects an implementation based on a red-black tree.

```c
#define AO_ALARM_QUEUE
```

The following implementations are available.

| Value | Module                                 | |
|-------|----------------------------------------|-|
| `0`   | [`ao_alarm_queue_0`](alarm-queue-0.md) | Stub |
| `1`   | [`ao_alarm_queue_1`](alarm-queue-1.md) | Sorted list |
| `2`   | [`ao_alarm_queue_2`](alarm-queue-2.md) | Binary heap (array-based) |
| `3`   | [`ao_alarm_queue_3`](alarm-queue-3.md) | Binary heap (pointer-based) |
| `4`   | [`ao_alarm_queue_4`](alarm-queue-4.md) | AVL tree |
| `5`   | [`ao_alarm_queue_5`](alarm-queue-5.md) | Red-black tree |
