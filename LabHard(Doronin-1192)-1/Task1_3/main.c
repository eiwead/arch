#include "main.h"
#include "math.h"

int main(void)
{
	RCC->AHBENR|=RCC_AHBENR_GPIOBEN;
	uint32_t half_period; 
	uint32_t sw1; uint32_t sw2; uint32_t sw3; uint32_t sw4;
	uint32_t btn = 14;
	sw4=((GPIOB->IDR)&0x1000)>>14; sw3=((GPIOB->IDR)&0x2000)>>14; sw2=((GPIOB->IDR)&0x4000)>>14; sw1=((GPIOB->IDR)&0x8000)>>14;
	GPIOB->MODER|=GPIO_MODER_MODER0_0 | GPIO_MODER_MODER1_0 | GPIO_MODER_MODER2_0 |
								GPIO_MODER_MODER3_0 | GPIO_MODER_MODER4_0 | GPIO_MODER_MODER5_0 |
								GPIO_MODER_MODER6_0 | GPIO_MODER_MODER7_0 | GPIO_MODER_MODER9_0;
	GPIOB->MODER&=~( GPIO_MODER_MODER12 | GPIO_MODER_MODER13 | GPIO_MODER_MODER14 | GPIO_MODER_MODER15);
	GPIOB->ODR|=0x200;
	half_period = 50000;
	while(1)
	{
		uint32_t bit[] = {sw1, 1, sw2, 0, 1, sw3, 0, sw4};
		uint32_t num[8];
		uint32_t dec = 0; uint32_t div; uint32_t j = 7;
		for (uint32_t i = 0; i < 8; i++)
		{
			dec += (bit[i] * pow(2, j));
			j--;
		}
		for (uint32_t i = 0; i < 9; i++)
		{
			div = dec % btn;
			num[i] = div;
			dec -= div;
			dec = dec / btn;
			if (dec < btn)
			{
				i++;
				num[i] = dec;
				if (dec < btn)
				{
					break;
				}
			}
		}
		j = 0;
		uint32_t o;
		for (uint32_t i = 7; i >= 0; i--)
		{
			o = num[i];
			if (j ==0)
			{
				j = num[i];
				if (j != 0)
				{
					output(o);
					delay(200000);
					GPIOB->BSRR|=0x0;
					delay(50000);
				}
			}
			else
			{
				output(o);
				delay(200000);
				GPIOB->BSRR|=0x0;
				delay(50000);
			}
		}
		//горит тчк
		delay(500000);
	}
}

void delay(uint32_t count)
{
for (uint32_t i=0;i<count;i++);
}

void output(uint32_t count)
{
	if (count == 0)
	{
		//
	}
	if (count == 1)
	{
		//
	}
	if (count == 2)
	{
		//
	}
	if (count == 3)
	{
		//
	}
	if (count == 4)
	{
		//
	}
	if (count == 5)
	{
		//
	}
	if (count == 6)
	{
		//
	}
	if (count == 7)
	{
		//
	}
	if (count == 8)
	{
		//
	}
	if (count == 9)
	{
		//
	}
	if (count == 10)
	{
		//
	}
	if (count == 11)
	{
		//
	}
	if (count == 12)
	{
		//
	}
	if (count == 13)
	{
		//
	}
	if (count == 14)
	{
		//
	}
	if (count == 15)
	{
		//
	}
	if (count == 16)
	{
		//
	}
}
 