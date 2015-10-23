/**
  ******************************************************************************
  * @file    bsp_watchdog.c
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
#include "bsp_watchdog.h" 


/**
  * @brief  BSP_WatchInit
  * @param  prer:分频因子：0--7 分频因子=4*2^prer,最大256
            rlr:重装寄存器值
            时间计算：Tout=((4*2^prer)*rlr) /40 (ms)                 
  * @retval 初始化开门狗
  */
void BSP_WatchdogInit( uint8_t prer, uint16_t rlr )
{
  IWDG_WriteAccessCmd( IWDG_WriteAccess_Enable );
  IWDG_SetPrescaler( prer );
  IWDG_SetReload( rlr );
  IWDG_ReloadCounter();
}


/**
  * @brief  BSP_WatchInit
  * @param  
  * @retval 开门狗开启
  */
void BSP_WatchdogEnable( void )
{
  IWDG_Enable();
}

/**
  * @brief  BSP_WatchdogFeed
  * @param  
  * @retval 喂狗
  */
void BSP_WatchdogFeed( void )
{
  IWDG_ReloadCounter();
}

