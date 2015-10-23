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
  * @param  prer:��Ƶ���ӣ�0--7 ��Ƶ����=4*2^prer,���256
            rlr:��װ�Ĵ���ֵ
            ʱ����㣺Tout=((4*2^prer)*rlr) /40 (ms)                 
  * @retval ��ʼ�����Ź�
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
  * @retval ���Ź�����
  */
void BSP_WatchdogEnable( void )
{
  IWDG_Enable();
}

/**
  * @brief  BSP_WatchdogFeed
  * @param  
  * @retval ι��
  */
void BSP_WatchdogFeed( void )
{
  IWDG_ReloadCounter();
}

