/**
  ******************************************************************************
  * @file    bsp_init.c
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
#include "bsp_init.h" 


/**
  * @brief  Bsp_InitGpioInit
  * @param  
  * @retval ��ʼ��ȫ��GPIO���Խ�ʡ����
  */
void BSP_InitGpioInit( void )
{
  
}

/**
  * @brief  BSP_SystemClockInit
  * @param  
  * @retval ϵͳʱ������
  */
void BSP_SystemClockInit( void )
{
  //
  SystemInit();
}

/**
  * @brief  BSP_ConfigurationNVIC
  * @param  
  * @retval �����ж����ȼ���
  */
void BSP_ConfigurationNVIC( void )
{
  NVIC_InitTypeDef NVIC_InitStructure;
  
  NVIC_PriorityGroupConfig(NVIC_PriorityGroup_0);
  
  //����UART1���ȼ�
	//��Ե���Ӧ���ȼ����
	NVIC_InitStructure.NVIC_IRQChannel = USART1_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0x00 ;//��ռ���ȼ�0
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0x05;		//��Ӧ���ȼ���� 
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;			//IRQͨ��ʹ��
	NVIC_Init(&NVIC_InitStructure);	//����ָ���Ĳ�����ʼ��VIC�Ĵ���	
	
	//����UART2���ȼ�
	//ZIGBEE����Ӧ���ȼ�
	NVIC_InitStructure.NVIC_IRQChannel = USART2_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0x00 ;//��ռ���ȼ�0
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0x06;		
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;			//IRQͨ��ʹ��
	NVIC_Init(&NVIC_InitStructure);	//����ָ���Ĳ�����ʼ��VIC�Ĵ���	
	
	//TIMER2��ʱ�����ȼ�
	NVIC_InitStructure.NVIC_IRQChannel = TIM2_IRQn;
  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0x00;
  NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0x07;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&NVIC_InitStructure); 
	
	//����UART3���ȼ�
	NVIC_InitStructure.NVIC_IRQChannel = USART3_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0x00 ;//��ռ���ȼ�0
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0x08;		//�����ȼ�3
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;			//IRQͨ��ʹ��
	NVIC_Init(&NVIC_InitStructure);	//����ָ���Ĳ�����ʼ��VIC�Ĵ���	
	
	//�ⲿ�жϰ������ȼ�
	//�ж����ȼ����
	NVIC_InitStructure.NVIC_IRQChannel = KEY_SCAN_EXTI_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0x00;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0x0F;	//���
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&NVIC_InitStructure);
}

/**
  * @brief  BSP_DelayMs
  * @param  
  * @retval ��ʱnMs��������ʱʱ��Ҫ������Ƶ����
  */
void BSP_DelayMs( uint16_t usTimesNms )
{
  uint16_t i=0;
	while( usTimesNms--)
	{
		i = 1600;
		while(i--);
	}
}
