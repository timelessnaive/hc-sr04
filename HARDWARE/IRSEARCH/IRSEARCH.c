#include "IRSEARCH.h"
#include "delay.h"
#include "stm32f10x.h"                  // Device header

void IRSearchInit(void)
{
	GPIO_InitTypeDef  GPIO_InitStructure;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA|RCC_APB2Periph_GPIOB , ENABLE);
	
  GPIO_InitStructure.GPIO_Pin = SEARCH_R_PIN;//配置使能GPIO管脚
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;//配置GPIO模式,输入上拉
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;//配置GPIO端口速度
	GPIO_Init(SEARCH_R_GPIO , &GPIO_InitStructure); 
	/*
	GPIO_InitStructure.GPIO_Pin = SEARCH_L_PIN;//配置使能GPIO管脚
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;//配置GPIO模式,输入上拉
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;//配置GPIO端口速度
	GPIO_Init(SEARCH_L_GPIO , &GPIO_InitStructure); 
	*/
}

void SearchRun(void)
{
	/*if(SEARCH_L_IO == WHITE_AREA && SEARCH_R_IO == WHITE_AREA) 
		;
	else if (SEARCH_L_IO == BLACK_AREA && SEARCH_R_IO == WHITE_AREA)
		ctrl_comm = COMM_RIGHT;*/
	if (SEARCH_R_IO == BLACK_AREA) printf("black\r\n");
	else printf("white\r\n");
	
}
/*
//------------------------------------------------------
float ki=1,kp=0.5;
float Position_PID(int now,int aim)
{
	static float bias,last_bias,pwm;
	bias=aim-now;
	pwm+=kp*(bias-last_bias)+ki*bias;
	last_bias=bias;
	return pwm;
}
//--------------------------------------------------------
*/
/*
void SearchRun(void)
{
	
		ctrl_comm = COMM_UP;
	
	
	if(ctrl_comm_last != ctrl_comm)
	{
			ctrl_comm_last = ctrl_comm;
		 	switch(ctrl_comm)
				{
					case COMM_UP:    ZYSTM32_run(50,10);break;
					case COMM_DOWN:  ZYSTM32_back(50,20);break;
					case COMM_LEFT:  ZYSTM32_Left(50,20);break;
					case COMM_RIGHT: ZYSTM32_Right(50,20);break;
					case COMM_STOP:  ZYSTM32_brake(20);break;
					default : break;
				}
	}
}
*/

