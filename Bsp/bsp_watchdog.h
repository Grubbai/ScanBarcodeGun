/**
  ******************************************************************************
  * @file    bsp_watchdog.h
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
#ifndef __BSP_WATCHDOG_H
#define __BSP_WATCHDOG_H
#include "stm32f10x.h"



void BSP_WatchdogInit( uint8_t prer, uint16_t rlr );
void BSP_WatchdogEnable( void );
void BSP_WatchdogFeed( void );

#endif
