#include "stm32f10x.h"                  // Device header
char data;
int main()
	//4567
{
RCC->APB2ENR |=RCC_APB2ENR_IOPAEN;
RCC->APB2ENR |=RCC_APB2ENR_USART1EN;
	
GPIOA->CRH |=(1<<4);
GPIOA->CRH |=(1<<5);
GPIOA->CRH |=(1<<7);
GPIOA->CRH &=~(1<<6);	
	
GPIOA->CRH |=(1<<10);
GPIOA->CRH &=~(1<<8);	
GPIOA->CRH &=~(1<<9);
GPIOA->CRH &=~(1<<11);		
	
USART1->BRR=72000000/9600;

	
USART1->CR1|=(1<<13);
USART1->CR1|=(1<<2);
USART1->CR1|=(1<<3);

	
while (1)
{

if(USART1->SR & USART_SR_RXNE )
{
	data=USART1->DR; 
	USART1->DR=data; 
}


}


}
