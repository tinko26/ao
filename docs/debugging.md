---
author: "Stefan Wagner"
date: 2022-08-13
description: "Debugging in the ao real-time operating system."
draft: false
permalink: /debugging/
subtitle: ""
title: "Debugging"
---

The following modules support the debugging of an application. Especially, runtime assertions are extensively used throughout the framework.

| Module | |
|--------|-|
| [`ao_assert.h`](modules/assert.md) | Defines a single macro function, that executes a runtime assertion. |
| [`ao_break.h`](modules/break.md) | Defines a single function, that executes a breakpoint. |
| [`ao_debug.h`](modules/debug.md) | Defines a single macro constant, that indicates, whether an application is running in debug mode. |
