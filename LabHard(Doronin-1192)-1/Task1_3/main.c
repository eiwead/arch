#include "main.h"
#include "math.h"

int main(void)
{
	uint32_t half_period;
	uint32_t n; 
	uint32_t sw1; uint32_t sw2; uint32_t sw3; uint32_t sw4;
	uint32_t btn = 14;
	sw4=((GPIOB->IDR)&0x1000)>>14; sw3=((GPIOB->IDR)&0x2000)>>14; sw2=((GPIOB->IDR)&0x4000)>>14; sw1=((GPIOB->IDR)&0x8000)>>14;
	RCC->AHBENR|=RCC_AHBENR_GPIOBEN;
	GPIOB->MODER|=GPIO_MODER_MODER0_0 | GPIO_MODER_MODER1_0 | GPIO_MODER_MODER2_0 |
								GPIO_MODER_MODER3_0 | GPIO_MODER_MODER4_0 | GPIO_MODER_MODER5_0 |
								GPIO_MODER_MODER6_0 | GPIO_MODER_MODER7_0 | GPIO_MODER_MODER9_0;
	GPIOB->OSPEEDR|=0X5555; //все порты на скорость в 10 мгц - 0b0101010101010101
	GPIOB->MODER&=~( GPIO_MODER_MODER12 | GPIO_MODER_MODER13 | GPIO_MODER_MODER14 | GPIO_MODER_MODER15);
	GPIOB->ODR|=0x200;
	half_period = 50000;
	while(1)
	{
		uint32_t bit[] = {sw1, 1, sw2, 0, 1, sw3, 0, sw4}
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
			if (dec < b)
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
		for (uint32_t = 7; i >=0; i--)
		{
			j = num[i];
			if (j !=0)
		}
	}
}

void delay(uint32_t count)
{
for (uint32_t i=0;i<count;i++);
}

void output(uint32_t mas[]
 