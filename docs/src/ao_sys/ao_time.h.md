---
api: true
author: "Stefan Wagner"
date: 2022-08-29
description: "The /src/ao_sys/ao_time.h file of the ao real-time operating system."
draft: true
permalink: /src/ao_sys/ao_time.h/
subtitle: ""
title: "ao_time.h"
toc: true
---

# Include

```c
#include <ao_count.h>
```

# Typedefs

```c
typedef ao_count_t ao_time_t;
```

# Constants

```c
#define AO_INFINITY (AO_COUNT_MAX)
```

```c
#define AO_TIME_MAX (AO_COUNT_MAX)
```

```c
#define AO_TIME_MIN (AO_COUNT_MIN)
```

# Functions

```c
#define ao_now()
```

```c
#define AO_DAYS(x)
```

```c
#define AO_DAYS_FROM_TIME(x)
```

```c
#define AO_HOURS(x)
```

```c
#define AO_HOURS_FROM_TIME(x)
```

```c
#define AO_MINUTES(x)
```

```c
#define AO_MINUTES_FROM_TIME(x)
```

```c
#define AO_SECONDS(x)
```

```c
#define AO_SECONDS_FROM_TIME(x)
```

```c
#define AO_MILLISECONDS(x)
```

```c
#define AO_MILLISECONDS_FROM_TIME(x)
```

```c
#define AO_MICROSECONDS(x)
```

```c
#define AO_MICROSECONDS_FROM_TIME(x)
```

```c
#define AO_NANOSECONDS(x)
```

```c
#define AO_NANOSECONDS_FROM_TIME(x)
```

