/**
  ******************************************************************************
  * @file    bsp_motor.c
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
#include "bsp_motor.h" 


/**
  * @brief  BSP_MotorInit
  * @param  
  * @retval ��ʼ��ȫ��GPIO���Խ�ʡ����
  */
void BSP_MotorInit( void )
{
  
}

/**
  * @brief  BSP_MotorOn
  * @param  
  * @retval 
  */
void BSP_MotorOn( void )
{
  //open motor
  
}

/**
  * @brief  BSP_MotorOff
  * @param  
  * @retval ��ʼ��ȫ��GPIO���Խ�ʡ����
  */
void BSP_MotorOff( void )
{
  
}

/**
  * @brief  BSP_MotorDelayMs
  * @param  
  * @retval ��ʱnMs��������ʱʱ��Ҫ������Ƶ����
  */
void BSP_MotorDelayMs( uint16_t usTimesNms )
{
  uint16_t i=0;
	while( usTimesNms--)
	{
		i = 1600;
		while(i--);
	}
}
