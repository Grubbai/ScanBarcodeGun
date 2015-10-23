/**
  ******************************************************************************
  * @file    bsp_key.c
  * @author  Grub'bai
  * @version V0.0.1
  * @date    24-8-2015
  * @brief   
  ******************************************************************************
  * @attention
  *
  *
  ******************************************************************************
  */
#include "bsp_key.h" 


/**
  * @brief  BSP_KeyInit
  * @param  
  * @retval ��ʼ���ⲿ����
  */
void BSP_KeyInit( void )
{
  GPIO_InitTypeDef GPIO_InitStructure;
	EXTI_InitTypeDef EXTI_InitStructure;
  
  /* Enable the GPIO Clock */
	RCC_APB2PeriphClockCmd( KEY_SCAN_GPIO_CLK | RCC_APB2Periph_AFIO, ENABLE);	
  
  /* Configure Key pin as input */
	//GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING; 
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;	
	GPIO_InitStructure.GPIO_Pin = KEY_SCAN_PIN;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		 //IO���ٶ�Ϊ50MHz
	GPIO_Init(KEY_SCAN_GPIO_PORT, &GPIO_InitStructure);
  
  /* Connect Key EXTI Line to Key GPIO Pin */
	GPIO_EXTILineConfig(KEY_SCAN_EXTI_PORT_SOURCE,KEY_SCAN_EXTI_PIN_SOURCE);

		/* Configure Key EXTI line */
	EXTI_InitStructure.EXTI_Line = KEY_SCAN_EXTI_LINE;
	EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;
	EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling;           //�½��ش���,����ʱ����
//EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Rising_Falling;    //Ϊ�˼���ǰ��»���̧��
	EXTI_InitStructure.EXTI_LineCmd = ENABLE;
	EXTI_Init(&EXTI_InitStructure);
}

/**
  * @brief  BSP_ReadKeyState
  * @param  
  * @retval ��ʼ���ⲿ����
  */
uint32_t BSP_ReadKeyState( void )
{
  return GPIO_ReadInputDataBit(KEY_SCAN_GPIO_PORT, KEY_SCAN_PIN);
}
