#include "stm32f10x.h"  // Device header
#include "Delay.h"
#include "OLED.h"
#include "PWM.h"
#include "Key.h"
uint16_t a;
int main(void)
{
	OLED_Init();
	OLED_ShowString(1,1,"CRR: ");
	
	Key_Init();
	Pwm_Init();
//	LED_Init();
//	LED2_OFF();

	while(1)
	{
		a=Key_get();
		while(a<25)
		{	
			Key_Move1();
			a=Key_get();
			OLED_ShowNum(1,5,a,3);
		}
		
		while(a>5)
		{
			
			a=Key_get();
			Key_Move2();
			OLED_ShowNum(1,5,a,3);
		}
	}
}
