#include "timer.h"
#include "sys.h"
#include "led.h"

void Timer_SRD_Init(u16 arr,u16 psc)
{
	TIM_TimeBaseInitTypeDef    TIM_TimeBaseInitSture;
	NVIC_InitTypeDef           NVIC_InitSture;
	
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3,ENABLE);//ʹ��TIM3
	
	//��ʼ����ʱ��
	TIM_TimeBaseInitSture.TIM_CounterMode=TIM_CounterMode_Up;
	TIM_TimeBaseInitSture.TIM_Period=5000;
	TIM_TimeBaseInitSture.TIM_Prescaler=7199;
	TIM_TimeBaseInitSture.TIM_ClockDivision=0;
	TIM_TimeBaseInit(TIM3,&TIM_TimeBaseInitSture);
	
	//��������жϣ�������ʽ�ж�
	TIM_ITConfig(TIM3,TIM_IT_Update,ENABLE);
	TIM_ITConfig(TIM3,TIM_IT_Trigger,ENABLE);
	
	//�ж����ȼ�����
	NVIC_InitSture.NVIC_IRQChannel=TIM3_IRQn;
	NVIC_InitSture.NVIC_IRQChannelCmd=ENABLE;
	NVIC_InitSture.NVIC_IRQChannelPreemptionPriority=0;
	NVIC_InitSture.NVIC_IRQChannelSubPriority=3;
	NVIC_Init(&NVIC_InitSture);
	
	//TIM_Cmd(TIM3,ENABLE);
}

void TIM3_IRQHandler(void)
{
	if(TIM_GetITStatus(TIM3,TIM_IT_Update)!=RESET)
	{
		TIM_ClearITPendingBit(TIM3,TIM_IT_Update);
		
	}
}
















