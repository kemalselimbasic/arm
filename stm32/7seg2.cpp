#include "stm32f10x.h"                  // Device header
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
	pocetak:

RCC->APB2ENR |=RCC_APB2ENR_IOPAEN;
	RCC->APB2ENR |=RCC_APB2ENR_IOPBEN;

GPIOA->CRL |=GPIO_CRL_MODE;
GPIOA->CRL &=~GPIO_CRL_CNF;
GPIOB->CRL |=(1<<7);
	GPIOB->CRL |=(1<<3);
	GPIOB->CRL &=~(1<<0);
	GPIOB->CRL &=~(1<<1);
	
		GPIOB->CRL &=~(1<<2);
		GPIOB->CRL &=~(1<<4);
		GPIOB->CRL &=~(1<<5);
		GPIOB->CRL &=~(1<<6);

/*
int broj1=5,broj2=0,brojac=0;
	reset();
		ispisi(broj1);
		delay();
broj2=rand() % 10+1;	
*/

int broj1=3;
reset();
ispisi(broj1);
int broj2=rand () % 10;
		
	while(1)
	{
	
		if(GPIOB->IDR & (1<<0))
		{	
			delay();
			
			if(broj1>broj2)
			{
			reset();
				
			ispisi(broj2);
			delay();
			delay();
				
			broj1=broj2;
			broj2=rand () % 10;
			}
			
			if(broj1<broj2)
			{	
				reset();
				
				while (1)
				{
				GPIOA->BSRR=0x77;
				}
				
			}
		
		}
	
			else if (GPIOB->IDR & (1<<1))
			{
				
			delay();
				
			if(broj1>broj2)
			{
				
				reset();
				while (1)
				{
				GPIOA->BSRR=0x77;
				}
			}
			
			if(broj1<broj2)
			{	
			
				reset();
			ispisi(broj2);
			delay();
			delay();
			
				broj1=broj2;
				broj2=rand () % 10;
			}
		
		}
			else
		{
			reset();
			ispisi (broj1);
			delay();
		}
			
			
			
		
		/*
		
		if(GPIOB->IDR & (1<<0))//pritisnuto 1
		{
		if(broj2<broj1)
		{
		//nisi pogodio
		broj1=broj2;
			brojac++;

broj2=rand() % 10+1;
			//broj2=7;
		}
		else 
		{
	
			
				GPIOA->BSRR=0x77;
				delay();
				delay();
			delay();
			goto pocetak;
		
			

		}
		
		}

	 if(GPIOB->IDR & (1<<1))//pritisnuo 4
		{
		if(broj1<broj2)
		{
		//pogodio
				
broj2=rand() % 10+1;
			//broj2=7;
brojac++;
		broj1=broj2;

		}
		else
		{
				GPIOA->BSRR=0x77;
			delay();
				delay();
			delay();
goto pocetak;

		}			
		
		
		}
		
		else
		{
		reset();
		ispisi(broj1);
		delay();
		
		}
		
		
		if(brojac==5)
		{
						GPIOA->BSRR=0x3f;
delay();
				delay();
			delay();
			break;
		
		}
				
		*/	
	}
}


	

