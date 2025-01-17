/*
 * Copyright (c) 2012-2015, Brian Watling and other contributors
 *
 * Permission to use, copy, modify, and/or distribute this software for any
 * purpose with or without fee is hereby granted, provided that the above
 * copyright notice and this permission notice appear in all copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
 * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
 * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
 * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
 * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 */

#ifndef _FIBER_COND_H_
#define _FIBER_COND_H_

#include "fiber_mutex.h"
#include "mpsc_fifo.h"
#include <sys/types.h>
#include <time.h>

/*
    Author: Brian Watling
    Email: brianwatling@hotmail.com
    Website: https://github.com/brianwatling

    Description: A condition variable structure for fibers.
*/

typedef struct fiber_cond
{
    fiber_mutex_t* caller_mutex;
    volatile intptr_t waiter_count;
    mpsc_fifo_t waiters;
    fiber_mutex_t internal_mutex;
} fiber_cond_t;

#ifdef __cplusplus
extern "C" {
#endif

extern int fiber_cond_init(fiber_cond_t* cond, int *pthread_dummy);

extern void fiber_cond_destroy(fiber_cond_t* cond);

extern int fiber_cond_signal(fiber_cond_t* cond);

extern int fiber_cond_broadcast(fiber_cond_t* cond);

extern int fiber_cond_wait(fiber_cond_t* cond, fiber_mutex_t * mutex);

#ifdef __cplusplus
}
#endif

#endif

