#ifndef __IRSEARCH_H_
#define __IRSEARCH_H_

#include "stm32f10x.h"

void IRSearchInit(void);
void SearchRun(void);

//ѭ�����Թ�
/* 
��ѭ��	SEARCH_R_PIN	PA7
��ѭ��	SEARCH_L_PIN	PB0
 */

#define SEARCH_R_PIN         GPIO_Pin_7
#define SEARCH_R_GPIO        GPIOA
#define SEARCH_R_IO          GPIO_ReadInputDataBit(SEARCH_R_GPIO, SEARCH_R_PIN)

#define SEARCH_L_PIN         GPIO_Pin_0
#define SEARCH_L_GPIO        GPIOB
#define SEARCH_L_IO          GPIO_ReadInputDataBit(SEARCH_L_GPIO, SEARCH_L_PIN)
#define BLACK_AREA 1
#define WHITE_AREA 0


//ָ���
#define COMM_STOP  'S'//ֹͣ
#define COMM_UP    'U'//ǰ��
#define COMM_DOWN  'D'//����
#define COMM_LEFT  'L'//��ת
#define COMM_RIGHT 'R'//��ת



#endif
