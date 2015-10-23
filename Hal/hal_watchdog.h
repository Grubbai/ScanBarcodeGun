/**
  ******************************************************************************
  * @file    hal_watchdog.h
  * @author  Grub'bai
  * @version V0.0.1
  * @date    24-8-2015
  * @brief   beeper driver stm32f10x
  ******************************************************************************
  * @attention
  *
  *
  ******************************************************************************
  */
#ifndef __HAL_WATCHDOG_H
#define __HAL_WATCHDOG_H
#include "bsp_watchdog.h"

void HAL_WatchdogInitTo1S( void );
void HAL_WatchdogFeed( void );
void HAL_WatchdogResetSystem( void );

#endif
