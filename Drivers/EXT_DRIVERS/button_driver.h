#ifndef __BUTTON_DRIVER_H
#define __BUTTON_DRIVER_H

/*
 * Initializes onboard button in PA0 without interrupt
 */
void init_button(void);

/*
 * Initializes external button connected to PA1, in pull down mode, without interrupt
 */
void init_button2(void);

/*
 * Returns initial status of PA0 button, 1->Pressed 0->Not Pressed
 */
int button_status(void);

/*
 * Returns initial status of PA1 button, 1->Pressed 0->Not Pressed
 */
int button2_status(void);

/*
 * Initializes PA0 button with interrupt
 */
void init_button_interrupt(void);

/*
 * Initializes PA1 button with interrupt
 */
void init_button2_interrupt(void);


#endif
