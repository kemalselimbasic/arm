#include "stm32f10x.h"                  // Device header

void dilej()
{	
for(int i=0; i<=1000; i++);
}
			int raw;
float v,temp;
int main()
{
/*
 RCC->APB2ENR |=RCC_APB2ENR_IOPAEN;
RCC->APB2ENR |=RCC_APB2ENR_IOPBEN;

GPIOA->CRL |=GPIO_CRL_MODE;
GPIOA->CRL &=~GPIO_CRL_CNF;

GPIOB->CRL |=GPIO_CRL_MODE;
GPIOB->CRL &=~GPIO_CRL_CNF;
*/
	

	
	RCC->APB2ENR |=RCC_APB2ENR_AFIOEN;
	RCC->APB2ENR |=RCC_APB2ENR_IOPAEN;
	RCC->APB2ENR |=RCC_APB2ENR_ADC1EN;
		ADC1->SMPR2 |=ADC_SMPR2_SMP0;

	RCC->CFGR  |=RCC_CFGR_ADCPRE_DIV6;
	
	ADC1->SQR3 |=(0<<0);
	ADC1->CR2 |=ADC_CR2_CONT;
	ADC1->CR2 |=ADC_CR2_ADON;
	for(int i=0;i<10;i++){}
		
	ADC1->CR2 |=ADC_CR2_ADON;
			for(int i=0;i<10;i++){}

ADC1->CR2 |=ADC_CR2_CAL;
				
		while(ADC1->CR2 & ADC_CR2_CAL){;}
dilej();

	while(1)
{
	
	if(ADC1->SR		& ADC_SR_EOC){
		raw=ADC1->DR;
		v=raw*3.3/4096;
	temp=v*100;
	}

//ADC1->SR |=ADC_SR_EOC;
	
}

}
