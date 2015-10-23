/**
  ******************************************************************************
  * @file    BSP_Beeper.h
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
#ifndef __BSP_BEEPER_H
#define __BSP_BEEPER_H
#include "stm32f10x.h"
#include  "bsp_key.h"

void BSP_InitGpioInit( void );
void BSP_SystemClockInit( void );
void BSP_ConfigurationNVIC( void );
void BSP_DelayMs( uint16_t usTimesNms );

#endif
