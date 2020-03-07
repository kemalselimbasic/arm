#include "stm32f10x.h"  
#include "stdlib.h"
#include "string.h"
#include "stdio.h"
#include "stdarg.h"
int data2;
int sum=0;
// Device header
char data[32];
void send(char *msg, ...) {
	char buffer[100];
	
	va_list args;
	va_start(args, msg);
	vsprintf(buffer, msg, args);
	
	for(int i = 0; i < strlen(buffer); i++) {
		USART2 -> DR = buffer[i];
		
		while(!(USART2 -> SR & USART_SR_TXE)); 
	}
};

int main()
	//4567
{

RCC->APB2ENR |=RCC_APB2ENR_IOPAEN;
RCC->APB2ENR |=RCC_APB2ENR_USART1EN;
RCC->APB1ENR |=RCC_APB1ENR_USART2EN;

GPIOA->CRH |=(1<<4);
GPIOA->CRH |=(1<<5);
GPIOA->CRH |=(1<<7);
GPIOA->CRH &=~(1<<6);	
	
GPIOA->CRH |=(1<<10);
GPIOA->CRH &=~(1<<8);	
GPIOA->CRH &=~(1<<9);
GPIOA->CRH &=~(1<<11);		

GPIOA->CRL |=(1<<11);
GPIOA->CRL |=(1<<9);
GPIOA->CRL |=(1<<8);
GPIOA->CRL &=~(1<<10);	
	
GPIOA->CRL |=(1<<14);
GPIOA->CRL &=~(1<<12);	
GPIOA->CRL &=~(1<<13);
GPIOA->CRL &=~(1<<15);

USART2->BRR=36000000/9600;
USART1->BRR=72000000/9600;

	
USART1->CR1|=(1<<13);
USART1->CR1|=(1<<2);
USART1->CR1|=(1<<3);

USART2->CR1|=(1<<13);
USART2->CR1|=(1<<2);
USART2->CR1|=(1<<3);
int j=0;
	bool a=false;
while (1)
	{


if(USART1->SR & USART_SR_RXNE )
{
	data[j]=USART1->DR; 
while(!(USART1->SR & USART_SR_TC)){};
	j++;
}
 if(j==32)
 {
	 for(int i=0;i<30;i++)
	 {
	 
	 sum=sum+data[i];
	 
	 }
 j=0;
	 a=true;
 }
	



	
if(a)
{if(sum==(data[30]<<8)+data[31]){
	if(data[0]=='B' && data[1]=='M')
	{
	

data2=(data[6]<<8)+data[7];
	send("%i",data2);
	sum=0;}

	}else{
	send("error");
	}
	
	a=false;

}
	
	

	
	
	
	





	

		
	

	}




}



























