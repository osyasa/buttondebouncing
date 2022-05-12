#ifndef __LED_DRIVER_H
#define __LED_DRIVER_H

/*
 * Initializes green led connected to PB7
 */
void init_led_green(void);

/*
 * Initializes blue led connected to PB7
 */
void init_led_blue(void);

/*
 * Outputs green led 1->ON 0->OFF
 */
void led_green_write(int status);

/*
 * Outputs blue led 1->ON 0->OFF
 */
void led_blue_write(int status);


#endif
