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
#ifndef __HAL_INIT_H
#define __HAL_INIT_H
#include "bsp_init.h"


void HAL_InitGpioInit(void);
void HAL_SystemClockInit(void);
void HAL_ConfigurationNVIC(void);

#endif
