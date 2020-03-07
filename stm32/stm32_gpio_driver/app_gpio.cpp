/**************************************************
*STM32F103C8 -BluePill GPIO driver API example implementation
*Autor: GrunF
*Date:17.11.2019
*Machine:Thinkpad T430
*Revision notes:
*TO DO -> NVIC
****************************************************/
#include "stm32f10x.h"                  // Device header
#include "stm32f103C8_gpio.h"			//GPIO driver

bool test =false;
uint16_t count;
uint16_t val;

int main(void)
	
{
	GPIO_ClockCtrl(GPIOC,ENABLE); //enable clock for GPIOc port
	GPIO_ClockCtrl(GPIOA,ENABLE); //enable clock for GPIOA port

  //GPIO_PinMode(GPIOA,A1,INPUT);  //A1 input
	for(int i =0;i<16;i++)
	{
	
	GPIO_PinMode(GPIOA,i,OUTPUT);
	}
	GPIO_PinMode(GPIOC,C13,OUTPUT); //C13 output
	//stmGPIO_DeInit(GPIOA);

	while(1)
	{
		
		//GPIO_ToggleOutputPin(GPIOC,13);
		//for(int i=0;i<5;i++);
		//GPIO_ToggleOutputPin(GPIOC,13);
		//for(int i=0;i<5;i++);
		
		//test=GPIO_DigitalRead(GPIOA,1); 
		/*GPIO_DigitalWrite(GPIOC,13,!LOW);
		if(test)
		{
			count++;													  // increment variable
			while(test)
			{ test=GPIO_DigitalRead(GPIOA,1);  //read input pin state
				GPIO_DigitalWrite(GPIOC,13,!HIGH);
				if(!test)break; 								 //when user realese button break from while
			}
		}
		*/
	}
}
