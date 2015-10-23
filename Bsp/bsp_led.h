/**
  ******************************************************************************
  * @file    bsp_led.h
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
#ifndef __BSP_LED_H
#define __BSP_LED_H
#include "stm32f10x.h"



void BSP_LedInit( void );
void BSP_LedGreenOff( void );
void BSP_LedGreenOn( void );
void BSP_LedRedOff( void );
void BSP_LedRedOn( void );

#endif
