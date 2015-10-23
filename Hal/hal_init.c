/**
  ******************************************************************************
  * @file    bsp_init.c
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
#include "hal_init.h" 


/**
  * @brief  HAL_InitGpioInit
  * @param  
  * @retval 
  */
void HAL_InitGpioInit(void)
{
  BSP_InitGpioInit();   
}

/**
  * @brief  HAL_SystemClockInit
  * @param  
  * @retval 
  */
void HAL_SystemClockInit(void)
{
  BSP_SystemClockInit();
}

/**
  * @brief  HAL_ConfigurationNVIC
  * @param  
  * @retval 
  */
void HAL_ConfigurationNVIC(void)
{ 
  BSP_ConfigurationNVIC();
}

/**
  * @brief  HAL_ConfigurationNVIC
  * @param  
  * @retval 
  */




