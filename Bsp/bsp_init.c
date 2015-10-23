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
  * @retval 初始化全部GPIO，以节省功耗
  */
void BSP_InitGpioInit( void )
{
  
}

/**
  * @brief  BSP_SystemClockInit
  * @param  
  * @retval 系统时钟配置
  */
void BSP_SystemClockInit( void )
{
  //
  SystemInit();
}

/**
  * @brief  BSP_ConfigurationNVIC
  * @param  
  * @retval 配置中断优先级组
  */
void BSP_ConfigurationNVIC( void )
{
  NVIC_InitTypeDef NVIC_InitStructure;
  
  NVIC_PriorityGroupConfig(NVIC_PriorityGroup_0);
  
  //配置UART1优先级
	//配对的响应优先级最高
	NVIC_InitStructure.NVIC_IRQChannel = USART1_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0x00 ;//抢占优先级0
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0x05;		//响应优先级最高 
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;			//IRQ通道使能
	NVIC_Init(&NVIC_InitStructure);	//根据指定的参数初始化VIC寄存器	
	
	//配置UART2优先级
	//ZIGBEE的响应优先级
	NVIC_InitStructure.NVIC_IRQChannel = USART2_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0x00 ;//抢占优先级0
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0x06;		
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;			//IRQ通道使能
	NVIC_Init(&NVIC_InitStructure);	//根据指定的参数初始化VIC寄存器	
	
	//TIMER2定时器优先级
	NVIC_InitStructure.NVIC_IRQChannel = TIM2_IRQn;
  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0x00;
  NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0x07;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&NVIC_InitStructure); 
	
	//配置UART3优先级
	NVIC_InitStructure.NVIC_IRQChannel = USART3_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0x00 ;//抢占优先级0
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0x08;		//子优先级3
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;			//IRQ通道使能
	NVIC_Init(&NVIC_InitStructure);	//根据指定的参数初始化VIC寄存器	
	
	//外部中断按键优先级
	//中断优先级最低
	NVIC_InitStructure.NVIC_IRQChannel = KEY_SCAN_EXTI_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0x00;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0x0F;	//最低
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&NVIC_InitStructure);
}

/**
  * @brief  BSP_DelayMs
  * @param  
  * @retval 延时nMs，具体延时时间要根据主频计算
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
