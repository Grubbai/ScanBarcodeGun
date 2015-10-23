/**
  ******************************************************************************
  * @file    hal_PromptInfo.c
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
#include "hal_PromptInfo.h" 



/**
  * @brief  HAL_LedInit
  * @param  
  * @retval ��ʼ��LED��GPIO�˿�
  */
void HAL_LedInit( void )
{
  BSP_LedInit();
}

/**
  * @brief  hal beeper initialize
  * @param  
  * @retval None
  */
void HAL_BeeperInit(void)
{
	BSP_BeeperInit();
}


// motor---------------------------------------------------------------------------
/**
  * @brief  HAL_MotorInit
  * @param  
  * @retval motor init
  */
void HAL_MotorInit( void )
{
  BSP_MotorInit();
}

/**
  * @brief  HAL_MotorOnContinueNms
  * @param  
  * @retval motor init
  */
void HAL_MotorOnContinueNms( uint16_t usTimesNms )
{
  BSP_MotorOn();
  BSP_MotorDelayMs(usTimesNms);
  BSP_MotorOff();
}

/**
  * @brief  HAL_StartUpHighPowerPrompt
  * @param  
  * @retval ��������������ʾ
  */
void HAL_StartUpHighPowerPrompt( void )
{
  BSP_BeeperSoundFrequency(3200,50,600);	//3.2kHZ
  BSP_BeeperSoundFrequency(2800,50,600);	//2.8kHZ
  BSP_BeeperSoundFrequency(2400,50,600);	//2.4kHZ
  BSP_BeeperSoundFrequency(2000,50,600);	//2.0kHZ
}

/**
  * @brief  HAL_StartUpLowPowerPrompt
  * @param  
  * @retval �����͵�����ʾ
  */
void HAL_StartUpLowPowerPrompt( void )
{
  BSP_BeeperSoundFrequency(1400,50,800);
  BSP_BeeperSoundFrequency(1000,30,800);
  BSP_BeeperSoundFrequency(900,20,800);
  BSP_BeeperSoundFrequency(800,10,800);
}

/**
  * @brief  HAL_StartUpErrorPrompt
  * @param  
  * @retval ����������ʾ
  */
void HAL_StartUpErrorPrompt( void )
{
  
}

/**
  * @brief  HAL_PairSuccessPrompt
  * @param  
  * @retval ��Գɹ���ʾ
  */
void HAL_PairSuccessPrompt( void )
{
  BSP_BeeperSoundFrequency(1400,50,700);	//1.4K
  BSP_BeeperSoundFrequency(2000,50,700);	//2K
  BSP_BeeperSoundFrequency(2400,50,700);	//2.4K
  BSP_BeeperSoundFrequency(2700,50,700);	//2.7K	
}

/**
  * @brief  HAL_PairFailPrompt
  * @param  
  * @retval ��������ʾ
  */
void HAL_PairFailPrompt( void )
{
  BSP_BeeperSoundFrequency(2700,50,700);	//2.7K
  BSP_BeeperSoundFrequency(2400,50,700);	//2.4K
  BSP_BeeperSoundFrequency(2000,50,700);	//2K
  BSP_BeeperSoundFrequency(1400,50,700);	//1.4K
}

/**
  * @brief  HAL_LoseNetworkPrompt
  * @param  
  * @retval �������������ʾ
  */
void HAL_LoseNetworkPrompt( void )
{
  
}

/**
  * @brief  HAL_ReadBarcodeSuccessPrompt
  * @param  
  * @retval �������������ʾ
  */
void HAL_ReadBarcodeSuccessPrompt( T_HAL_PROMPT_INFO t_hal_prompt_info )
{
  uint8_t i;
  uint16_t tempFrequency = 0;
  uint16_t tempDuty = 0;
  for( i = 0; i < t_hal_prompt_info.ucBeeperNum; i++)
  {
    //LED��
    if( t_hal_prompt_info.ucLedState == ON )
    {
      BSP_LedGreenOn();
    }
    
    //��������״̬
    if( t_hal_prompt_info.ucBeeperState == ON )
    {
      
      switch (t_hal_prompt_info.ucBeeperFrequency)
      {
        case 1:
          //1600HZ
          tempFrequency = 1600;
          break;
        case 3:
          //4200HZ
          tempFrequency = 4200;
          break;
        case 2:
        default:  
          //3200HZ 
          tempFrequency = 3200;        
          break;        
      }
      //�ı�ռ�ձȣ��ı�������С
      switch (t_hal_prompt_info.ucBeeperLevel)
      {
        case 1:
          //high
          tempDuty = 80;
          break;
        case 3:
          //low
          tempDuty = 30;
          break;
        case 2:
        default:  
          //middle 
          tempDuty = 50;        
          break;        
      }
      BSP_BeeperSoundFrequency(tempFrequency,tempDuty,700);      
    }
    
    //MOTOR��
    if( t_hal_prompt_info.ucMotorState == ON )
    {
       HAL_MotorOnContinueNms( t_hal_prompt_info.ucMotorLastTime);
    }
   
    //�ر�LED 
    BSP_LedGreenOff();  
  }
}

/**
  * @brief  HAL_ReadBarcodeSuccessPrompt
  * @param  
  * @retval �������������ʾ
  */
void HAL_ReadBarcodeFailPrompt( T_HAL_PROMPT_INFO t_hal_prompt_info )
{
  uint8_t i;
  uint16_t tempFrequency = 0;
  uint16_t tempDuty = 0;
  for( i = 0; i < t_hal_prompt_info.ucBeeperNum; i++)
  {
    //LED��
    if( t_hal_prompt_info.ucLedState == ON )
    {
      BSP_LedRedOn();
    }
    
    //��������״̬
    if( t_hal_prompt_info.ucBeeperState == ON )
    {
     
      switch (t_hal_prompt_info.ucBeeperFrequency)
      {
        case 1:
          //1600HZ
          tempFrequency = 1600;
          break;
        case 3:
          //4200HZ
          tempFrequency = 4200;
          break;
        case 2:
        default:  
          //3200HZ 
          tempFrequency = 3200;        
          break;        
      }
      //�ı�ռ�ձȣ��ı�������С
      switch (t_hal_prompt_info.ucBeeperLevel)
      {
        case 1:
          //high
          tempDuty = 80;
          break;
        case 3:
          //low
          tempDuty = 30;
          break;
        case 2:
        default:  
          //middle 
          tempDuty = 50;        
          break;        
      }
      BSP_BeeperSoundFrequency(tempFrequency,tempDuty,700);      
    }
    
    //MOTOR��
    if( t_hal_prompt_info.ucMotorState == ON )
    {
       HAL_MotorOnContinueNms( t_hal_prompt_info.ucMotorLastTime);
    }
    
    //�ر�LED  
    BSP_LedRedOff();  
  }
}


