#include "stm32f103C8_gpio.h"


//-------------------------------------------
//Periherial clock control
//-------------------------------------------
//******************************************
// @fn   	->GPIO_ClockCtrl
//
// @expl	->Enable or Disable peripherial clock
//
//@parma[1]	->base adres of GPIO periperial
//@param[2] ->macro for enabling od disabling
//
//@return	->void
//
//********************************************
void GPIO_ClockCtrl(GPIO_TypeDef *pGPIOx, uint8_t EnOrDi)
{
	if(EnOrDi==ENABLE)
	{
		if(pGPIOx==GPIOA)
		{
			RCC->APB2ENR |=RCC_APB2ENR_IOPAEN; //enable clockA
		}
		else if( pGPIOx==GPIOB)
		{
		
			RCC->APB2ENR |=RCC_APB2ENR_IOPBEN; // enable clockB
		
		}
		else if( pGPIOx==GPIOC)
		{
		
			RCC->APB2ENR |=RCC_APB2ENR_IOPCEN; // enable clockC		
		}

	}
	else
	{
		
		if(pGPIOx==GPIOA)
		{
			RCC->APB2ENR &=~RCC_APB2ENR_IOPAEN; //dinable clockA
			
		}
		else if( pGPIOx==GPIOB)
		{
		
			RCC->APB2ENR &=~RCC_APB2ENR_IOPBEN; // enable clockB
		
		}
		else if( pGPIOx==GPIOC)
		{
		
			RCC->APB2ENR &=~RCC_APB2ENR_IOPCEN; // enable clockC		
		}
	
	
	}
}	

//-------------------------------------------
//init Port mode-> simple just output &&  INPUT || Alternativ function TODO
//-------------------------------------------
//******************************************
// @fn   	->GPIO_InitPinMode
//
// @expl	->GPIO_hendler
//
//@parma[1]	->Port Name
//@parma[2]	->Port Pin number
//@parma[3]	->Port Pin Mode -> output || input
//@parma[4]	->Port Pin nspeed -> SLOW MEDIUM FAST
//
//@return	->void
//
//********************************************
void GPIO_PinMode(GPIO_TypeDef *pGPIOx, uint16_t pinNumber, uint16_t pinMode, uint32_t pinSpeed)
{
//	uint32_t temp=0; //temp register

		if((pinNumber<8)&&(pinMode == OUTPUT))
			{
					
					switch (pinSpeed)
					{
						
						case 3: //FAST 50 MHz
						
							pGPIOx->CRL |= (1<<(pinNumber*4));
							pGPIOx->CRL |= (1<<((pinNumber*4)+1));	
							pGPIOx ->CRL &=~(1<<((pinNumber*4)+2));
							pGPIOx ->CRL &=~(1<<((pinNumber*4)+3));
						
						break;
						
						case 1: //MEDIUM 10 MHz
						
							pGPIOx->CRL |= (1<<(pinNumber*4));
							pGPIOx->CRL &=~ (1<<((pinNumber*4)+1));
							pGPIOx ->CRL &=~(1<<((pinNumber*4)+2));
							pGPIOx ->CRL &=~(1<<((pinNumber*4)+3));
					
						break;
					
					
						case 2: //SLOW 2 mhZ
							pGPIOx->CRL &=~ (1<<(pinNumber*4));
							pGPIOx->CRL |= (1<<((pinNumber*4)+1));
							pGPIOx ->CRL &=~(1<<((pinNumber*4)+2));
							pGPIOx ->CRL &=~(1<<((pinNumber*4)+3));
						break;
						
					
				}
			}
				else if ((pinNumber<8)&&(pinMode == INPUT))
			{
					switch (pinSpeed)
					{
						
						case 3:
						
							pGPIOx->CRL &=~ (1<<(pinNumber*4));
							pGPIOx->CRL &=~ (1<<((pinNumber*4)+1));	
							pGPIOx ->CRL &=~(1<<((pinNumber*4)+2));
							pGPIOx ->CRL |=(1<<((pinNumber*4)+3));
						
						break;
						
						case 1:
						
							pGPIOx->CRL &=~ (1<<(pinNumber*4));
							pGPIOx->CRL &=~ (1<<((pinNumber*4)+1));
							pGPIOx ->CRL &=~(1<<((pinNumber*4)+2));
							pGPIOx ->CRL |=(1<<((pinNumber*4)+3));
					
						break;
					
					
						case 2:
							pGPIOx->CRL &=~ (1<<(pinNumber*4));
							pGPIOx->CRL &=~ (1<<((pinNumber*4)+1));
							pGPIOx ->CRL &=~(1<<((pinNumber*4)+2));
							pGPIOx ->CRL |=(1<<((pinNumber*4)+3));
						break;
						
					
				}
					
				
				}
						
		if((pinNumber>=8)&&(pinMode == OUTPUT))
			{
				switch(pinSpeed)
				{
					case 3:
						
						pGPIOx->CRH |= (1<<(pinNumber%8)*4);
						pGPIOx->CRH |= (1<<(((pinNumber%8)*4)+1));
						pGPIOx ->CRH &=~(1<<(((pinNumber%8)*4)+2));
						pGPIOx ->CRH &=~(1<<(((pinNumber%8)*4)+3));
					
					break;
					
				case 1:
					
						pGPIOx->CRH |= (1<<(pinNumber%8)*4);
						pGPIOx->CRH &=~ (1<<(((pinNumber%8)*4)+1));
						pGPIOx ->CRH &=~(1<<(((pinNumber%8)*4)+2));
						pGPIOx ->CRH &=~(1<<(((pinNumber%8)*4)+3));
				
				break;
				
				case 2:
					
					  pGPIOx->CRH &=~ (1<<(pinNumber%8)*4);
						pGPIOx->CRH |= (1<<(((pinNumber%8)*4)+1));
						pGPIOx ->CRH &=~(1<<(((pinNumber%8)*4)+2));
						pGPIOx ->CRH &=~(1<<(((pinNumber%8)*4)+3));
				
				break;
			}
				
		}			
				else if ((pinNumber>=8)&&(pinMode == INPUT))
			{
					switch (pinSpeed)
					{
						
						case 3:
						
							pGPIOx->CRL &=~ (1<<(pinNumber*4));
							pGPIOx->CRL &=~ (1<<((pinNumber*4)+1));	
							pGPIOx ->CRL &=~(1<<((pinNumber*4)+2));
							pGPIOx ->CRL |=(1<<((pinNumber*4)+3));
						
						break;
						
						case 1:
						
							pGPIOx->CRL &=~ (1<<(pinNumber*4));
							pGPIOx->CRL &=~ (1<<((pinNumber*4)+1));
							pGPIOx ->CRL &=~(1<<((pinNumber*4)+2));
							pGPIOx ->CRL |=(1<<((pinNumber*4)+3));
					
						break;
					
					
						case 2:
							pGPIOx->CRL &=~ (1<<(pinNumber*4));
							pGPIOx->CRL &=~ (1<<((pinNumber*4)+1));
							pGPIOx ->CRL &=~(1<<((pinNumber*4)+2));
							pGPIOx ->CRL |=(1<<((pinNumber*4)+3));
						break;
						
					
				}			
	}
}				

//-------------------------------------------
//Deinit Port mode-> reset port
//-------------------------------------------
//******************************************
// @fn   	->GPIO_Deinit ->reset selected port TO DEFAULT STATE
//
// @expl	->GPIO_hendler
//
//@parma[1]	->Port Name
//
//@return	->void
//
//********************************************

void GPIO_ResetPort(GPIO_TypeDef *pGPIOx)
{
	
	if(pGPIOx==GPIOA) do{RCC->APB2RSTR =RCC_APB2RSTR_IOPARST; RCC->APB2RSTR &=~RCC_APB2RSTR_IOPARST; }while(0);
	if(pGPIOx==GPIOB) do{RCC->APB2RSTR =RCC_APB2RSTR_IOPBRST; RCC->APB2RSTR &=~RCC_APB2RSTR_IOPBRST; }while(0);
	if(pGPIOx==GPIOC) do{RCC->APB2RSTR =RCC_APB2RSTR_IOPCRST; RCC->APB2RSTR &=~RCC_APB2RSTR_IOPCRST; }while(0);
		
}
//-------------------------------------------
//Port - Pin Read Write
//-------------------------------------------

//******************************************
// @fn   	->GPIO_DigitalRead ->read input pin state
//
// @expl	->GPIO_hendler
//
//@parma[1]	->Port Name
//@parma[2]	->Pin Number
//
//@return	->bool
//
//********************************************
bool GPIO_DigitalRead(GPIO_TypeDef *pGPIOx,uint16_t PinNumber)
{

		bool value;
		
		value = (pGPIOx->IDR & (1<<PinNumber));

			
		return value;
}	


//******************************************
// @fn   	->GPIO_PortRead ->read Port state
//
// @expl	->GPIO_hendler
//
//@parma[1]	->Port Name
//
//
//@return	->uint16_t
//
//********************************************

uint16_t GPIO_DigitalReadPort(GPIO_TypeDef *pGPIOx)
{
	uint16_t value;
	
	value = (uint16_t) pGPIOx->IDR;
	
	return value;

}


//******************************************
// @fn   	->GPIO_DigitalWrite->write to pin
//
// @expl	->GPIO_hendler
//
//@parma[1]	->Port Name
//@parma[2]	->Port pin
//@parma[3]	-> Value
//
//@return	->void
//
//********************************************
void GPIO_DigitalWrite(GPIO_TypeDef *pGPIOx,uint16_t PinNumber, bool Value)
{
	
	if (Value == HIGH)
	{
		
		pGPIOx->ODR |=(1<<PinNumber);
	
	}
	else
	{
	
		pGPIOx->ODR &=~(1<<PinNumber);
	
	}

}


//******************************************
// @fn   	->GPIO_DigitalPortWrite->write to port
//
// @expl	->GPIO_hendler
//
//@parma[1]	->Port Name
//@parma[2]	-> Value
//
//@return	->void
//
//********************************************

void GPIO_DigitalWritePort(GPIO_TypeDef *pGPIOx,uint16_t Value)
{

	pGPIOx->ODR =Value;
	
}
void GPIO_ToggleOutputPin(GPIO_TypeDef *pGPIOx,uint16_t PinNumber)
{

		pGPIOx->ODR ^= (1<<PinNumber);

}
//-------------------------------------------
//IRQ config and ISR handling
//-------------------------------------------
//void GPIO_IRQConfig(void);
//void GPIO_IRQHandling(uint8_t PinNumber);	
