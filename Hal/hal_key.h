/**
  ******************************************************************************
  * @file    hal_key.h
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
#ifndef __HAL_KEY_H
#define __HAL_KEY_H

#include "bsp_key.h"

void HAL_KeyInit( void );
void HAL_KeyISR( void );

#endif
