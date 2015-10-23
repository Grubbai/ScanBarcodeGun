/**
  ******************************************************************************
  * @file    hal_PromptInfo.h
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
#ifndef __HAL_PROMPTINFO_H
#define __HAL_PROMPTINFO_H

#include  "common_def.h"
#include  "bsp_beeper.h"
#include  "bsp_led.h"
#include  "bsp_motor.h"

typedef struct {
  uint8_t ucBeeperState;      //1,On  0,Off
  uint8_t ucBeeperFrequency;  //1,1600HZ  2,3200HZ, 3,4200HZ,  default 2
  uint8_t ucBeeperLevel;      //1,high    2,middle  3,low 
  uint8_t ucBeeperNum;        //声响次数，与LED闪烁次数一致。
  uint8_t ucLedState;
  uint8_t ucMotorState;
  uint8_t ucMotorLastTime;    //振动持续时间
}T_HAL_PROMPT_INFO;

#ifndef ON
#define ON  1
#define OFF 0
#endif


void HAL_StartUpHighPowerPrompt( void );
void HAL_StartUpLowPowerPrompt( void );
void HAL_StartUpErrorPrompt( void );
void HAL_PairSuccessPrompt( void );
void HAL_PairFailPrompt( void );
void HAL_LoseNetworkPrompt( void );
void HAL_ReadBarcodeSuccessPrompt( T_HAL_PROMPT_INFO t_hal_prompt_info );
void HAL_ReadBarcodeFailPrompt( T_HAL_PROMPT_INFO t_hal_prompt_info );


#endif
