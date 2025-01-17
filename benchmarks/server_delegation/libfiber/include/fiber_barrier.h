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

#ifndef _FIBER_BARRIER_H_
#define _FIBER_BARRIER_H_

/*
    Author: Brian Watling
    Email: brianwatling@hotmail.com
    Website: https://github.com/brianwatling
*/

#include "mpsc_fifo.h"

typedef struct fiber_barrier {
    uint32_t count;
    volatile uint64_t counter;
    mpsc_fifo_t waiters;
} fiber_barrier_t;

#define FIBER_BARRIER_SERIAL_FIBER (1)

#ifdef __cplusplus
extern "C" {
#endif

extern int fiber_barrier_init(fiber_barrier_t* barrier, int* pthread_dummy, uint32_t count);

extern void fiber_barrier_destroy(fiber_barrier_t* barrier);

extern int fiber_barrier_wait(fiber_barrier_t* barrier);

#ifdef __cplusplus
}
#endif

#endif
