#include "stm32l152xc.h"
#include "button_driver.h"
#include "led_driver.h"
#include "counter.h"

void init_counter_interrupt(void){
	RCC->APB1ENR |= (1 << 4);

	TIM6->CR1 |= (1 << 0);

	TIM6->PSC = 31999;

	TIM6->ARR = 999;

	TIM6->DIER |= TIM_DIER_UIE;

	NVIC_EnableIRQ(TIM6_IRQn);
	NVIC_SetPriority(TIM6_IRQn,1);
}

void enable_counter(void){
	TIM6->CR1 |= (1 << 0);
}

void disable_counter(void){
	TIM6->CR1 &= ~(1 << 0);
}

void debounce_time_in_millis(uint16_t milliSeconds){
	TIM6->ARR = milliSeconds - 1;
}

void TIM6_IRQHandler(void){
	TIM6->SR &= ~(1 << 0);

	if(button_status() | button2_status()){
		led_blue_write(1);
	}
	else{
		led_blue_write(0);
	}
}
