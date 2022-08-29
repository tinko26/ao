---
author: "Stefan Wagner"
date: 2022-08-29
description: "The ao_sys/ao_alloc.h module of the ao real-time operating system."
draft: true
permalink: /ao_sys/ao_alloc.h/ 
subtitle: "<code>ao_sys</code>"
title: "<code>ao_alloc.h</code>"
toc: true
---

typedef struct  ao_acquired_t   ao_acquired_t;

typedef struct  ao_released_t   ao_released_t;

typedef struct  ao_retained_t   ao_retained_t;

#ifndef AO_ALLOC

#define AO_ALLOC                (2)

#endif

#if     AO_ALLOC ==             (0)

#elif   AO_ALLOC ==             (1)

#elif   AO_ALLOC ==             (2)

#endif

#ifndef AO_ACQUIRED

#define AO_ACQUIRED             (false)

#endif

#ifndef AO_RELEASED

#define AO_RELEASED             (false)

#endif

#ifndef AO_RETAINED

#define AO_RETAINED             (false)

#endif

#ifndef AO_ACQUIRED_T

#define AO_ACQUIRED_T

struct  ao_acquired_t
{
        void *                  ptr;

        bool                    result;

        size_t                  size_body;

        size_t                  size_body_requested;

        size_t                  size_head;
};

#endif

#ifndef AO_RELEASED_T

#define AO_RELEASED_T

struct  ao_released_t
{
        void *                  ptr;

        size_t                  ref;

        bool                    result;

        size_t                  size_body;

        size_t                  size_head;
};

#endif

#ifndef AO_RETAINED_T

#define AO_RETAINED_T

struct  ao_retained_t
{
        void *                  ptr;

        size_t                  ref;

        bool                    result;

        size_t                  size_body;

        size_t                  size_head;
};

#endif

void *  ao_acquire(             size_t size);

bool    ao_release(             void * ptr);

bool    ao_retain(              void * ptr);

void    ao_acquired(            ao_acquired_t const * info);

void    ao_released(            ao_released_t const * info);

void    ao_retained(            ao_retained_t const * info);

#ifndef ao_new

#define ao_new(type)            ao_acquire(sizeof(type))

#endif

#ifndef ao_delete

#define ao_delete(ptr)          ao_release(ptr)

#endif

