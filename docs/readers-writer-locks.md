---
author: "Stefan Wagner"
date: 2022-09-10
draft: true
permalink: /readers-writer-locks/
seealso:
- /api/src/ao_sys/ao_rw.h/
- /api/src/ao_sys/ao_wr.h/
toc: true
---

# Example (... Preferring Readers)

Let's assume, that there is a global variable ...

```c
double data[16];
```

```c
ao_rw_t lock;
```

Locking to Read.

...

```c
bool can_read = ao_rw_lock_read(&lock, AO_MILLISECONDS(500));

if (can_read)
{
    /* ... */ = data[0];
    /* ... */ = data[1];
    /* ... */ = data[2];

    ao_rw_unlock_read(&lock);
}
```

...

Locking to Write.

...

```c
bool can_write = ao_rw_lock_write(&lock, AO_MILLISECONDS(500));

if (can_write)
{
    data[0] = /* ... */;
    data[1] = /* ... */;
    data[2] = /* ... */;

    ao_rw_unlock_write(&lock);
}
```

...

# Example (... Preferring Writers)

Let's assume, that there is a global variable ...

```c
double data[16];
```

```c
ao_wr_t lock;
```

Locking to Read.

...

```c
bool can_read = ao_wr_lock_read(&lock, AO_MILLISECONDS(500));

if (can_read)
{
    /* ... */ = data[0];
    /* ... */ = data[1];
    /* ... */ = data[2];

    ao_wr_unlock_read(&lock);
}
```

...

Locking to Write.

...

```c
bool can_write = ao_wr_lock_write(&lock, AO_MILLISECONDS(500));

if (can_write)
{
    data[0] = /* ... */;
    data[1] = /* ... */;
    data[2] = /* ... */;

    ao_wr_unlock_write(&lock);
}
```

...
