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
#include  "bsp_init.h"


#define		BSP_BEEPER_TYPE_NOPOWER		1
//#define		BSP_BEEPER_TYPE_HAVE_POWER	1

typedef enum 
{
	E_BSP_BEEPER_GPIO_AF_PP,
	E_BSP_BEEPER_GPIO_OUT_PP
}E_BSP_BEEPER_GPIO_MODE;


#define BEEPER_GPIO_PORT	GPIOB
#define	BEEPER_GPIO_PIN		GPIO_Pin_1
#define	BEEPER_GPIO_CLK		RCC_APB2Periph_GPIOB

void BSP_BeeperInit(void);
void BSP_BeeperSoundFrequency(uint16_t usBeeperFrequency,uint8_t ucDuty,uint16_t usTimesNms);
uint8_t BSP_BeeperTypeIsNopower(void);
void BSP_BeeperSoundOn(uint16_t usTimesNms);
void BSP_BeeperSoundOff(uint16_t usTimesNms);

#endif
