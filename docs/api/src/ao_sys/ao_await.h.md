---
author: "Stefan Wagner"
date: 2022-08-31
draft: true
permalink: /api/src/ao_sys/ao_await.h/
toc: true
---

# Include

```c
#include <ao_async.h>
#include <ao_time.h>
```

# Functions

```c
void ao_await(     ao_async_t * x, ao_time_t timeout);
void ao_await_from(ao_async_t * x, ao_time_t timeout, ao_time_t beginning);
```

```c
void ao_await_forever(ao_async_t * x);
```

```c
void ao_await_all(     ao_async_all_t * x, ao_time_t timeout);
void ao_await_all_from(ao_async_all_t * x, ao_time_t timeout, ao_time_t beginning);
```

```c
void ao_await_all_forever(ao_async_all_t * x);
```

```c
void ao_await_any(     ao_async_any_t * x, ao_time_t timeout);
void ao_await_any_from(ao_async_any_t * x, ao_time_t timeout, ao_time_t beginning);
```

```c
void ao_await_any_forever(ao_async_any_t * x);
```
