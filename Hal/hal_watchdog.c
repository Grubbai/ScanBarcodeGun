/**
  ******************************************************************************
  * @file    hal_watchdog.c
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
#include "hal_watchdog.h" 


/**
  * @brief  HAL_WatchdogInitTo1S
  * @param  
  * @retval 初始化为1s定时开门狗
  */
void HAL_WatchdogInitTo1S( void )
{
  BSP_WatchdogInit(4,625);
  BSP_WatchdogEnable();
}

/**
  * @brief  HAL_WatchdogFeed
  * @param  
  * @retval 喂狗
  */
void HAL_WatchdogFeed( void )
{
  BSP_WatchdogFeed();
}
/**
  * @brief  HAL_WatchdogResetSystem
  * @param  
  * @retval 利用开门狗重启系统
  */
void HAL_WatchdogResetSystem( void )
{
  BSP_WatchdogInit(4,63);
  BSP_WatchdogEnable();
}




