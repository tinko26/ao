---
api: true
author: "Stefan Wagner"
date: 2022-08-29
description: "The /src/ao/ao_rand.h file of the ao real-time operating system."
draft: true
permalink: /src/ao/ao_rand.h/
subtitle: ""
title: "ao_rand.h"
toc: true
---

# Include

```c
#include <stdbool.h>
#include <stdint.h>
```

# Typedefs

```c
typedef bool (* ao_randb_t) ();
```

```c
typedef double (* ao_randd_t) ();
```

```c
typedef float (* ao_randf_t) ();
```

```c
typedef int8_t (* ao_randi8_t) ();
```

```c
typedef int16_t (* ao_randi16_t) ();
```

```c
typedef int32_t (* ao_randi32_t) ();
```

```c
typedef int64_t (* ao_randi64_t) ();
```

```c
typedef long double (* ao_randl_t) ();
```

```c
typedef uint8_t (* ao_randu8_t) ();
```

```c
typedef uint16_t (* ao_randu16_t) ();
```

```c
typedef uint32_t (* ao_randu32_t) ();
```

```c
typedef uint64_t (* ao_randu64_t) ();
```

