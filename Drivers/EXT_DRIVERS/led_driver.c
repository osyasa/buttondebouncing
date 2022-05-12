#include "stm32l152xc.h"

void init_led_green(void){
	RCC->AHBENR |= (1 << 1);

	GPIOB->MODER |= (1 << 14);
	GPIOB->MODER &= ~(1 << 15);

	GPIOB->OTYPER &= ~(1 << 7);

	GPIOB->OSPEEDR &= ~(1 << 14);
	GPIOB->OSPEEDR &= ~(1 << 15);

	GPIOB->PUPDR &= ~(1 << 14);
	GPIOB->PUPDR &= ~(1 << 15);
}

void init_led_blue(void){
	RCC->AHBENR |= (1 << 1);

	GPIOB->MODER |= (1 << 12);
	GPIOB->MODER &= ~(1 << 13);

	GPIOB->OTYPER &= ~(1 << 6);

	GPIOB->OSPEEDR &= ~(1 << 12);
	GPIOB->OSPEEDR &= ~(1 << 13);

	GPIOB->PUPDR &= ~(1 << 12);
	GPIOB->PUPDR &= ~(1 << 13);
}

void led_green_write(int status){
	if(status==1){
		GPIOB->ODR |= (1 << 7);
	}
	else if(status==0){
		GPIOB->ODR &= ~(1 << 7);
	}
	else{
		asm("NOP");
	}
}

void led_blue_write(int status){
	if(status==1){
		GPIOB->ODR |= (1 << 6);
	}
	else if(status==0){
		GPIOB->ODR &= ~(1 << 6);
	}
	else{
		asm("NOP");
	}
}
