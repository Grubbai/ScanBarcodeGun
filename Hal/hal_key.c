/**
  ******************************************************************************
  * @file    hal_key.c
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
#include "hal_key.h" 


/**
  * @brief  Bsp_InitGpioInit
  * @param  
  * @retval ��ʼ��ȫ��GPIO���Խ�ʡ����
  */
void HAL_KeyInit( void )
{
  BSP_KeyInit();
}

/**
  * @brief  HAL_KeyISR
  * @param  
  * @retval ��ʼ��ȫ��GPIO���Խ�ʡ����
  */
void HAL_KeyISR( void )
{
  //1������Ƿ�������״̬���������ѡ� 2�����ʹ����ź���
}

