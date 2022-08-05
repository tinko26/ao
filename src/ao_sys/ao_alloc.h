// ----------------------------------------------------------------------------

// MIT License

// Copyright (c) 2022 Stefan Wagner

// Permission is hereby granted, free of charge, to any person obtaining a
// copy of this software and associated documentation files (the "Software"),
// to deal in the Software without restriction, including without limitation
// the rights to use, copy, modify, merge, publish, distribute, sublicense,
// and/or sell copies of the Software, and to permit persons to whom the
// Software is furnished to do so, subject to the following conditions:

// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.

// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
// FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
// DEALINGS IN THE SOFTWARE.

// ----------------------------------------------------------------------------

// Allocator.

// ----------------------------------------------------------------------------

#include <stdbool.h>
#include <stddef.h>

// ----------------------------------------------------------------------------

typedef struct  ao_acquired_t   ao_acquired_t;

typedef struct  ao_released_t   ao_released_t;

typedef struct  ao_retained_t   ao_retained_t;

// ----------------------------------------------------------------------------

#ifndef AO_ALLOC

#define AO_ALLOC                (2)

#endif

// ----------------------------------------------------------------------------

#if     AO_ALLOC ==             (0)

#include <ao_alloc_0.h>

#elif   AO_ALLOC ==             (1)

#include <ao_alloc_1.h>

#elif   AO_ALLOC ==             (2)

#include <ao_alloc_2.h>

#endif

// ----------------------------------------------------------------------------

#ifndef AO_ACQUIRED

#define AO_ACQUIRED             (false)

#endif

#ifndef AO_RELEASED

#define AO_RELEASED             (false)

#endif

#ifndef AO_RETAINED

#define AO_RETAINED             (false)

#endif

// ----------------------------------------------------------------------------

#ifndef AO_ACQUIRED_T

#define AO_ACQUIRED_T

// ----------------------------------------------------------------------------

struct  ao_acquired_t
{
        void *                  ptr;

        bool                    result;

        size_t                  size_body;

        size_t                  size_body_requested;

        size_t                  size_head;
};

// ----------------------------------------------------------------------------

#endif

#ifndef AO_RELEASED_T

#define AO_RELEASED_T

// ----------------------------------------------------------------------------

struct  ao_released_t
{
        void *                  ptr;

        size_t                  ref;

        bool                    result;

        size_t                  size_body;

        size_t                  size_head;
};

// ----------------------------------------------------------------------------

#endif

#ifndef AO_RETAINED_T

#define AO_RETAINED_T

// ----------------------------------------------------------------------------

struct  ao_retained_t
{
        void *                  ptr;

        size_t                  ref;

        bool                    result;

        size_t                  size_body;

        size_t                  size_head;
};

// ----------------------------------------------------------------------------

#endif

// ----------------------------------------------------------------------------

// @brief

// Allocates a block of memory and takes ownership thereof.

// @details

// This function allocates a block of #size bytes of memory.

// On success, this function returns a pointer to the beginning of the
// allocated block of memory.

// The pointer is suitably aligned for any object type with fundamental alignment.

// The content of the allocated block of memory is not initialized,
// remaining with indeterminate values.

// The reference count of the block of memory is initialized with 1. Therefore,
// the calling thread of execution takes ownership of the block of memory.

// On failure, this function returns #NULL.

// The allocation fails, if

// * #size is zero, or

// * there is no block of at least #size bytes of memory available.

// @param [in]  size            The size of the memory block in bytes.

// @return

// On success, a pointer to the beginning of the allocated block of memory.

// Otherwise, #NULL.

void *  ao_acquire(             size_t size);

// ----------------------------------------------------------------------------

// @brief

// Relinquishes ownership of a block of memory.

// @details

// This function decrements the reference count of a block of memory.

// Therefore, the calling thread of execution relinquishes ownership of the
// block of memory.

// If the reference count reaches zero, then this function additionally
// deallocates the block of memory, making it available for further
// allocations.

// The behavior of this function is undefined, if the block of memory has been
// deallocated previously.

// Therefore, ownership of a block of memory should be relinquished only, if it
// has been taken previously by the same thread of execution by calling
// #ao_acquire() or #ao_retain(), respectively.

// If #ptr is #NULL, then this function does nothing.

// @param [in]  ptr             A pointer to the block of memory.

// @return

// #true if the block of memory has been released successfully.

// #false otherwise.

bool    ao_release(             void * ptr);

// ----------------------------------------------------------------------------

// @brief

// Retains ownership of a block of memory.

// @details

// This function increments the reference count of a block of memory.

// Therefore, the calling thread of execution takes ownership of the block of
// memory.

// If #ptr is #NULL, then this function does nothing.

// @param [in]  ptr             A pointer to the block of memory.

// @return

// #true if the block of memory has been retained successfully.

// #false otherwise.

bool    ao_retain(              void * ptr);

// ----------------------------------------------------------------------------

void    ao_acquired(            ao_acquired_t const * info);

void    ao_released(            ao_released_t const * info);

void    ao_retained(            ao_retained_t const * info);

// ----------------------------------------------------------------------------

#ifndef ao_new

#define ao_new(type)            ao_acquire(sizeof(type))

#endif

#ifndef ao_delete

#define ao_delete(ptr)          ao_release(ptr)

#endif

// ----------------------------------------------------------------------------
