#include <LPC17xx.h>
#include "timer.h"

void timer_init(void)
{
	LPC_TIM0->CTCR = 0x0;
	LPC_TIM0->PR = PRESCALE; //Increment TC at every 299 + 1 clock cycles
	//300 clock cycles @3Mhz = 0.1 mS

	LPC_TIM0->TCR = 0x02; //Reset Timer
}

void delay(unsigned long int count) //Using Timer0
{
	LPC_TIM0->TCR = 0x02; //Reset Timer

	LPC_TIM0->TCR = 0x01; //Enable timer

	while(LPC_TIM0->TC < count); //wait until timer counter reaches the desired delay

	LPC_TIM0->TCR = 0x00; //Disable timer
}
