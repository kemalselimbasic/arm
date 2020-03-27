#include "stm32f10x.h"                  // Device header


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


};
void prvi()
{
	GPIOB->BSRR=(1<<0);
	GPIOB->BSRR=(1<<17);


}

void drugi()
{
	GPIOB->BSRR=(1<<1);
	GPIOB->BSRR=(1<<16);

}

void reset()
{
	for(int i=16;i<25;i++)
	{
		GPIOA->BSRR=(1<<i);
	}
}
	

int main()
{
int cj=0,cd=0;
int niz[10]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f};
RCC->APB2ENR |=RCC_APB2ENR_IOPAEN;
RCC->APB2ENR |=RCC_APB2ENR_IOPBEN;

GPIOA->CRL |=GPIO_CRL_MODE;
GPIOA->CRL &=~GPIO_CRL_CNF;

GPIOB->CRL |=GPIO_CRL_MODE;
GPIOB->CRL &=~GPIO_CRL_CNF;

	while(1)
	{

	for(int i=0;i<100;i++)
	{
		
for(int k=0;k<50;k++)
		{
		prvi();
	reset();

	GPIOA->BSRR=(niz[cd]);
	dilej();
		
	drugi();
	reset();
	
	GPIOA->BSRR=(niz[cj]);
	dilej();

		cj=i%10;
	cd=i/10;	
	
		
		}

	
	}
	
	}
	
}