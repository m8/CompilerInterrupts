/* For Trigger */
#include <stdio.h>
#include <stdint.h>
#include <sched.h>
#include <perfmon/pfmlib.h>
#include <perfmon/perf_event.h>
#include "ci_lib.h"

/* For PAPI */
#include <papi.h>
#include <pthread.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <papi.h>
#include <math.h>

#ifdef CI
/* For Shenango */
#include <base/log.h>
#endif

/* For Trigger */
#define BUFFER_SIZE 5000000
extern __thread uint64_t last_tsc;
extern __thread uint64_t last_ret_ic;
extern __thread double last_avg_ic;
extern __thread double last_avg_ret_ic;
extern __thread double last_avg_tsc;
extern __thread char first_tsc;
extern uint64_t total_hashes;
//extern uint64_t total_hashes2;
extern struct timeval g_tv_start;

void compiler_interrupt_handler(long ic);
void print_timing_stats(void);
void init_stats();
void init_stats_others();

/* For PAPI */
#define NUM_HWEVENTS 2
#define TOT_INST_IDX 0
#define TOT_CYC_IDX 1
#define MAX_COUNT 128 // Change this according to the needs of the benchmark. It represents max number of threads created

extern __thread int events[NUM_HWEVENTS];
extern int event_set[MAX_COUNT];
extern __thread int counter_id;
extern int counter_id_alloc;

typedef void (*ic_overflow_handler_t)(int, void *, long_long, void *);
int __get_id_and_increment();
int instruction_counter_init();
int __reset();
int instruction_counter_register_thread();
int instruction_counter_start();
int instruction_counter_stop();
int instruction_counter_set_handler(ic_overflow_handler_t handler);
void papi_interrupt_handler(int i, void *v1, long_long ll, void *v2);
