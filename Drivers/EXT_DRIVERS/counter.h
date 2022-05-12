#ifndef __COUNTER_H
#define __COUNTER_H

#include "stdint.h"

/*
 * By default, initializes Timer6 for 1 second for 32 MHz clock
 */
void init_counter_interrupt(void);

/*
 * Counter can be enabled with this function
 */
void enable_counter(void);

/*
 * Counter can be disabled with this function
 */
void disable_counter(void);

/*
 * This function is used for adjusting debounce time in milliseconds
 */
void debounce_time_in_millis(uint16_t milliSeconds);


#endif
