#include "stm32f10x.h"
#include "timer.h"
#include "led.h"
#include "pwm.h"
#include "base_deal.h"
#include "switch.h"
#include "delay.h"
#include "usart.h"	


/************************************************
STM32F103C8T6小绿板
************************************************/

 
// u16 pwm_tem=500;
 int main(void)
 {	
	delay_init();
	delay_ms(200);
//	//AFIO->MAPR|=AFIO_MAPR_SWJ_CFG_JTAGDISABLE;	//	禁用JTAG，只启用SWD方式调试,貌似这条语句没有起到该有的作用
	uart_init(14400);
	LED_Init();
	Switch_Init();
  //TIM3_PWM_Init(ESC_CYCLE-1,720-1);	//ESC_CYCLE=2000,20ms	//与引脚冲突，故屏蔽
	TIM1_Int_Init(200-1,720-1);	//	72MHZ频率，分频720，100khz计数频率，计数100次为1ms,计数200次为2ms
//  Switch_Init();
  while(1)
	{
//GPIO_PinRemapConfig(GPIO_Remap_SWJ_JTAGDisable,ENABLE);//调用GPIO重映射函数		
//		PWM_PB4_Set(pwm_tem);
//		PWM_PB5_Set(pwm_tem);

		if(PA15==1)
		{
			LED=1;
		}
		else
		{
			LED=0;
		}
	}
 }
