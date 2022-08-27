---
author: "Stefan Wagner"
date: 2022-08-16
description: "The ao_self.h module of the ao real-time operating system."
draft: true
permalink: /modules/self/
title: "<code>ao_self.h"
---

# Overview

This module provides functions for a task to stop or suspend itself, respectively.

```c
ao_stop();
```

```c
ao_suspend();
```

Additionally, a task can get a pointer to its own task control block.

```c
ao_task_t * me = ao_self();
```
