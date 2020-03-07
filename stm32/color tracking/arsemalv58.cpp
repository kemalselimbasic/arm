#include "stm32f10x.h"                  // Device header
#include "stm32f10x.h"  
#include "stdlib.h"
#include "string.h"
#include "stdio.h"
#include "stdarg.h"
#include "stm32f103C8_gpio.h"
int data[2];
int sum=0;
// Device header
//char data[32];
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
RCC->APB2ENR |=RCC_APB2ENR_IOPBEN;
	
RCC->APB2ENR |=RCC_APB2ENR_USART1EN;
RCC->APB1ENR |=RCC_APB1ENR_USART2EN;
GPIO_PinMode(GPIOA,1,OUTPUT);
GPIO_PinMode(GPIOA,2,OUTPUT);
GPIO_PinMode(GPIOA,3,OUTPUT);
GPIO_PinMode(GPIOA,4,OUTPUT);
GPIO_PinMode(GPIOA,5,OUTPUT);
GPIO_PinMode(GPIOA,6,OUTPUT);
GPIO_PinMode(GPIOA,7,OUTPUT);
	
	
	GPIO_PinMode(GPIOB,8,OUTPUT);
	GPIO_PinMode(GPIOB,9,OUTPUT);
	GPIO_PinMode(GPIOB,10,OUTPUT);
	GPIO_PinMode(GPIOB,11,OUTPUT);
	GPIO_PinMode(GPIOB,12,OUTPUT);
	

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


int j=0;
	bool a=false;
while (1)
	{

if(!a){
if(USART1->SR & USART_SR_RXNE )
{
	data[j]=USART1->DR; 
while(!(USART1->SR & USART_SR_TC)){};
	j++;
}
 if(j==2)
 {
	 
 j=0;
	a=true;

 }}
 if(a)
 {
	 a=false;
	 
	 for(int i=0;i<8;i++){

		 
		 if(i==data[0])
		 {
			 for(int g=0;g<8;g++){
			 GPIO_DigitalWrite(GPIOA,g,LOW);
			 
			 }
			 
		 GPIO_DigitalWrite(GPIOA,i,HIGH);
		 
		 
		 
		 }
	 
	 }
		 
		 
		
	 for(int k=12;k>7;k--){
	 if(k-8==data[1]){
		 for(int g=8;g<13;g++){
		 
		 	 		 GPIO_DigitalWrite(GPIOB,g,HIGH);

		 }
		 
	 		 GPIO_DigitalWrite(GPIOB,k,LOW);
	 }
	 
	 
	 }
	 
	 

	 }
 
 
 

 }
	




	



	}










