#include "stm32f10x.h"
#include "timer.h"
#include "led.h"
#include "pwm.h"
#include "base_deal.h"
#include "switch.h"
#include "delay.h"
#include "usart.h"	


/************************************************
STM32F103C8T6С�̰�
************************************************/

 
// u16 pwm_tem=500;
 int main(void)
 {	
	delay_init();
	delay_ms(200);
//	//AFIO->MAPR|=AFIO_MAPR_SWJ_CFG_JTAGDISABLE;	//	����JTAG��ֻ����SWD��ʽ����,ò���������û���𵽸��е�����
	uart_init(14400);
	LED_Init();
	Switch_Init();
  //TIM3_PWM_Init(ESC_CYCLE-1,720-1);	//ESC_CYCLE=2000,20ms	//�����ų�ͻ��������
	TIM1_Int_Init(200-1,720-1);	//	72MHZƵ�ʣ���Ƶ720��100khz����Ƶ�ʣ�����100��Ϊ1ms,����200��Ϊ2ms
//  Switch_Init();
  while(1)
	{
//GPIO_PinRemapConfig(GPIO_Remap_SWJ_JTAGDisable,ENABLE);//����GPIO��ӳ�亯��		
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
