#include "stm32f10x.h"                  // Device header
#include <stdlib.h>


int niz[10]={0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xf8,0x80,0x90};

int ispisi (int n)
{
	GPIOA->BSRR=niz[n];
}

void dilej()
{	
	
for(int i=0; i<25000; i++)
{
}

};
void delay(){
for(int i=0;i<1000000;i++)
{
}

};

 
void reset()
{
	for(int i=16;i<25;i++)
	{
		GPIOA->BSRR=(1<<i);
	}
}
	

int main()
{

RCC->APB2ENR |=RCC_APB2ENR_IOPAEN;
GPIOA->CRL |=GPIO_CRL_MODE;
GPIOA->CRL &=~GPIO_CRL_CNF;

for(int i=0;i<10;i++)
		{
		
		ispisi(i);
			delay();
			reset();
		}
		
	while(1)
	{
	
			ispisi(rand() % 10 + 1);
			delay();
			reset();

	}
}


	

