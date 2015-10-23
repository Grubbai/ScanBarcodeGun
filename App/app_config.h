/**
  ******************************************************************************
  * @file    app_config.h
  * @author  Grub'bai
  * @version V0.0.1
  * @date    14-10-2015
  * @brief   app header
  ******************************************************************************
  * @attention
  *
  *
  ******************************************************************************
  */
#ifndef __BSP_BEEPER_H
#define __BSP_BEEPER_H 

#include  "FreeRTOS.h"

// set stack . if usStackDepth = 200(word), then alloc 200*4 (bytes) to stack
#define KEY_TASK_STK_SIZE           ( 800/4 )
#define CFGDATA_TASK_STK_SIZE       ( 1200/4 )
#define FACTORYTEST_TASK_STK_SIZE   ( 800/4 )
#define PAIR_TASK_STK_SIZE          ( 2000/4 )
#define SCANNER_TASK_STK_SIZE       ( 2000/4 )
#define ZIGBEE_TASK_STK_SIZE        ( 2000/4 )

// set task priority .
#define KEY_TASK_PRO              ( tskIDLE_PRIORITY + 1UL)
#define CFGDATA_TASK_PRO          ( tskIDLE_PRIORITY + 2UL)
#define FACTORYTEST_TASK_PRO      ( tskIDLE_PRIORITY + 3UL)
#define PAIR_TASK_PRO             ( tskIDLE_PRIORITY + 4UL)
#define SCANNER_TASK_PRO          ( tskIDLE_PRIORITY + 5UL)
#define ZIGBEE_TASK_PRO           ( tskIDLE_PRIORITY + 6UL)

#endif

/*********************************************END OF FILE**********************/
