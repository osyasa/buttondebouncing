#include "stm32l152xc.h"
#include "counter.h"
#include "button_driver.h"

void init_button(void){
	RCC->AHBENR |= (1 << 0);

	GPIOA->MODER &= ~(1 << 0);
	GPIOA->MODER &= ~(1 << 1);

	GPIOA->PUPDR &= ~(1 << 0);
	GPIOA->PUPDR |= (1 << 1);
}

void init_button2(void){
	RCC->AHBENR |= (1 << 0);

	GPIOA->MODER &= ~(1 << 2);
	GPIOA->MODER &= ~(1 << 3);

	GPIOA->PUPDR &= ~(1 << 2);
	GPIOA->PUPDR |= (1 << 3);
}

int button_status(void){
	if(GPIOA->IDR & (1 << 0)){
		return 1;
	}
	else if(GPIOA->IDR | ~(1 << 0)){
		return 0;
	}
	else{
		asm("NOP");
	}
}

int button2_status(void){
	if(GPIOA->IDR & (1 << 1)){
		return 1;
	}
	else if(GPIOA->IDR | ~(1 << 1)){
		return 0;
	}
	else{
		asm("NOP");
	}
}

void init_button_interrupt(void){
	init_button();

	RCC->APB2ENR |= (1 << 0);

	SYSCFG->EXTICR[1] &= ~(1 << 0);
	SYSCFG->EXTICR[1] &= ~(1 << 1);
	SYSCFG->EXTICR[1] &= ~(1 << 2);
	SYSCFG->EXTICR[1] &= ~(1 << 3);

	EXTI->IMR |= (1 << 0);

	EXTI->RTSR |= (1 << 0);

	NVIC_SetPriority(EXTI0_IRQn, 1);
	NVIC_EnableIRQ(EXTI0_IRQn);
}

void init_button2_interrupt(void){
	init_button2();

	RCC->APB2ENR |= (1 << 0);

	SYSCFG->EXTICR[1] &= ~(1 << 4);
	SYSCFG->EXTICR[1] &= ~(1 << 5);
	SYSCFG->EXTICR[1] &= ~(1 << 6);
	SYSCFG->EXTICR[1] &= ~(1 << 7);

	EXTI->IMR |= (1 << 1);

	EXTI->RTSR |= (1 << 1);

	NVIC_SetPriority(EXTI1_IRQn, 1);
	NVIC_EnableIRQ(EXTI1_IRQn);
}

void EXTI0_IRQHandler(void){
	EXTI->PR |= EXTI_PR_PIF0;

	TIM6->CNT = 0;
	TIM6->CR1 |= (1 << 0);

}

void EXTI1_IRQHandler(void){
	EXTI->PR |= EXTI_PR_PIF1;

	TIM6->CNT = 0;
	TIM6->CR1 |= (1 << 0);

}
