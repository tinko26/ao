---
api: true
author: "Stefan Wagner"
date: 2022-08-29
description: "The /src/ao_sys/ao_spin.h file of the ao real-time operating system."
draft: true
permalink: /api/src/ao_sys/ao_spin.h/
subtitle: ""
title: "ao_spin.h"
toc: true
---

# Include

```c
#include <ao_time.h>
```

# Functions

```c
void ao_spin( ao_time_t timeout);
```

```c
void ao_spin_from( ao_time_t timeout, ao_time_t beginning);
```

```c
void ao_spin_forever();
```

