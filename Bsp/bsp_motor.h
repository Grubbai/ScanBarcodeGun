/**
  ******************************************************************************
  * @file    bsp_motor.h
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
#ifndef __BSP_MOTOR_H
#define __BSP_MOTOR_H
#include "stm32f10x.h"

void BSP_MotorInit( void );
void BSP_MotorOn( void );
void BSP_MotorOff( void );
void BSP_MotorDelayMs( uint16_t usTimesNms );

#endif
