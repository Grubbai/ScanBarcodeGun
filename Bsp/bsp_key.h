/**
  ******************************************************************************
  * @file    bsp_key.h
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
#ifndef __BSP_KEY_H
#define __BSP_KEY_H

#include "stm32f10x.h"

#define KEY_SCAN_PIN                			GPIO_Pin_0
#define KEY_SCAN_GPIO_PORT          			GPIOA
#define KEY_SCAN_GPIO_CLK           			RCC_APB2Periph_GPIOA
#define KEY_SCAN_EXTI_LINE          			EXTI_Line0
#define KEY_SCAN_EXTI_PORT_SOURCE   			GPIO_PortSourceGPIOA
#define KEY_SCAN_EXTI_PIN_SOURCE    			GPIO_PinSource0
#define KEY_SCAN_EXTI_IRQn          			EXTI0_IRQn    

void BSP_KeyInit( void );
uint32_t BSP_ReadKeyState( void );

#endif
