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
  * @retval 初始化全部GPIO，以节省功耗
  */
void HAL_KeyInit( void )
{
  BSP_KeyInit();
}

/**
  * @brief  HAL_KeyISR
  * @param  
  * @retval 初始化全部GPIO，以节省功耗
  */
void HAL_KeyISR( void )
{
  //1、检测是否在休眠状态，重启唤醒。 2、发送触发信号量
}

