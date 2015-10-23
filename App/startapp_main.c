/**
  ******************************************************************************
  * @file    start_main.c
  * @author  Grub'bai
  * @version V0.0.1
  * @date    14-10-2015
  * @brief   startapp init
  ******************************************************************************
  * @attention
  *
  *
  ******************************************************************************
  */
  
/*
*********************************************************************************************************
*                                             INCLUDE FILES
*********************************************************************************************************
*/
#include "stm32f10x.h"

#include  "FreeRTOS.h"
#include  "task.h"

#include  "app_config.h"

#include  "hal_init.h"
//#include  "queue.h"
//#include  "croutine.h"

/*
*********************************************************************************************************
*                                            LOCAL DEFINES
*********************************************************************************************************
*/

/*
*********************************************************************************************************
*                                             FUNCTION
*********************************************************************************************************
*/
static void APP_StartTask (void);
static void APP_SetupHardware (void);
static void APP_Init1(void);
static void APP_Init2(void);
  
extern void APP_ConfigDataTask( void *pvParameters );
extern void APP_FactoryTestTask( void *pvParameters );
extern void APP_KeyTask( void *pvParameters );
extern void APP_PairTask( void *pvParameters );
extern void APP_ScannerTask( void *pvParameters );
extern void APP_ZigbeeTask( void *pvParameters );

/*
*********************************************************************************************************
*                                       EXTERN VER
*********************************************************************************************************
*/



/**
  * @brief  main
  * @param  
  * @retval 
  */
int main(void)
{
  // hardware init.
  APP_SetupHardware();
  
  // create task.
  APP_StartTask();
  
  //Start the scheduler.
	vTaskStartScheduler();
}

/**
  * @brief  APP_SetupHardware
  * @param  
  * @retval 
  */
static void APP_SetupHardware( void )
{
  // 0. init system clock, configuration NVIC, init all gpio to reduce power consumption
  APP_Init1();
  // 1. wait for power suply to be stable
  // 2. first stage initialize
  // 3. pre-charging
  // 4. Bootup Check
  // 5. WFI
  // 6. second stage initialize
  // 7. Working
}

/**
  * @brief  APP_SetupHardware
  * @param  
  * @retval 
  */
static void APP_Init1(void)
{
  // 0. init system clock
  HAL_SystemClockInit();
  // 1. configuration NVIC
  HAL_ConfigurationNVIC();
  // 2. init all gpio to reduce power consumption
  HAL_InitGpioInit();
#ifdef DEBUG_LOG
  
#endif
  // 3. 
}

/**
  * @brief  APP_SetupHardware
  * @param  
  * @retval 
  */
static void APP_Init2(void)
{
  
}
/**
  * @brief  APP_StartTask
  * @param  
  * @retval 
  */
static void APP_StartTask (void)
{
		  
  /* Create task1. */
  xTaskCreate(    APP_KeyTask,          /* Pointer to the function that implements the task.              */
                  "key task1",          /* Text name for the task.  This is to facilitate debugging only. */
                  500,                  /* Stack depth in words.                                          */
                  NULL,                 /* We are not using the task parameter.                           */
                  KEY_TASK_PRO,         /* This task will run at priority 1.                              */
                  NULL );               /* We are not using the task handle.                              */
  
  /* Create task2. */
  xTaskCreate( APP_ConfigDataTask, "config data task2", CFGDATA_TASK_STK_SIZE, NULL, CFGDATA_TASK_PRO, NULL );
  
  /* Create task3. */
  xTaskCreate( APP_FactoryTestTask, "factory test task3", FACTORYTEST_TASK_STK_SIZE, NULL, FACTORYTEST_TASK_PRO, NULL );
  
  /* Create task4. */
  xTaskCreate( APP_PairTask, "pair task4", PAIR_TASK_STK_SIZE, NULL, PAIR_TASK_PRO, NULL );
  
  /* Create task5. */
  xTaskCreate( APP_ScannerTask, "scanner task5", SCANNER_TASK_STK_SIZE, NULL, SCANNER_TASK_PRO, NULL );
  
  /* Create task6. */
  xTaskCreate( APP_ZigbeeTask, "zigbee task6", ZIGBEE_TASK_STK_SIZE, NULL, ZIGBEE_TASK_PRO, NULL );
}

/*********************************************END OF FILE**********************/

