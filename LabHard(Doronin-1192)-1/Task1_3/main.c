#include "main.h"

int main(void)
{
	RCC->AHBENR|=RCC_AHBENR_GPIOBEN;
	uint32_t half_period; 
	uint32_t sw1; uint32_t sw2; uint32_t sw3; uint32_t sw4;
	uint32_t btn = 14;
	sw4=((GPIOB->IDR)&0x1000)>>12; sw3=((GPIOB->IDR)&0x2000)>>13; sw2=((GPIOB->IDR)&0x4000)>>14; sw1=((GPIOB->IDR)&0x8000)>>15;
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
			dec += (bit[i] * power(2, j));
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
		for (uint32_t i = 7; i == 0; i--)
		{
			o = num[i];
			if (j ==0)
			{
				j = num[i];
				if (j != 0)
				{
					output(o);
					delay(200000);
					GPIOB->IDR|=0x0;
					delay(50000);
				}
			}
			else
			{
				output(o);
				delay(200000);
				GPIOB->IDR|=0x0;
				delay(50000);
			}
		}
		GPIOB->BSRR|=0x80;
		//горит тчк
		delay(500000);
		GPIOB->IDR|=0x0;
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
		GPIOB->BSRR=0x3F;
	}
	if (count == 1)
	{
		GPIOB->BSRR=0x6;
	}
	if (count == 2)
	{
		GPIOB->BSRR=0x5B;
	}
	if (count == 3)
	{
		GPIOB->BSRR=0x4F;
	}
	if (count == 4)
	{
		GPIOB->BSRR=0x66;
	}
	if (count == 5)
	{
		GPIOB->BSRR=0x6D;
	}
	if (count == 6)
	{
		GPIOB->BSRR=0x7D;
	}
	if (count == 7)
	{
		GPIOB->BSRR=0x7;
	}
	if (count == 8)
	{
		GPIOB->BSRR=0x7F;
	}
	if (count == 9)
	{
		GPIOB->BSRR=0x6F;
	}
	if (count == 10) //a
	{
		GPIOB->BSRR=0x77;
	}
	if (count == 11) //b
	{
		GPIOB->BSRR=0x7C;
	}
	if (count == 12) //c
	{
		GPIOB->BSRR=0x39;
	}
	if (count == 13) //d
	{
		GPIOB->BSRR=0x5E;
	}
	if (count == 14) //e
	{
		GPIOB->BSRR=0x79;
	}
	if (count == 15) //f
	{
		GPIOB->BSRR=0x71;
	}
}

uint32_t power(uint32_t x, uint32_t n)
 {
    if (n==0)
        return 1;
    else if (n==1)
        return x;
    else if (n % 2 == 0 )
        return power( x * x, n/2);
    else
        return power( x * x, n /2)*x;
 }
 
