/**
  ******************************************************************************
  * @file    BSP_Beeper.c
  * @author  Grub'bai
  * @version V0.0.1
  * @date    24-8-2015
  * @brief   ������Ӳ������㣬�ṩ�ϲ������API
  ******************************************************************************
  * @attention
  *
  *
  ******************************************************************************
  */
#include "bsp_beeper.h" 

//static functions declaration
static void BSP_BeeperTimerPWMInit(void);
static void BSP_BeeperDelayMs(uint16_t usTimesNms);
static void BSP_BeeperGPIOInit(E_BSP_BEEPER_GPIO_MODE eBspBeeperGPIOMode);


  
/**
  * @brief   beeper initalize
  * @param  
  * @retval None
  */
void BSP_BeeperInit(void)
{
	//add init code	
	#if (BSP_BEEPER_TYPE_NOPOWER == 1)	
	BSP_BeeperGPIOInit(E_BSP_BEEPER_GPIO_AF_PP);
	BSP_BeeperTimerPWMInit();	
	#else	
	BSP_BeeperGPIOInit(E_BSP_BEEPER_GPIO_OUT_PP);	
	#endif
}

/**
  * @brief  beeper GPIO initalize,when shutdown beeper ,select E_BSP_BEEPER_GPIO_OUT_PP mode
  * @param  eBspBeeperGPIOMode->
	*		E_BSP_BEEPER_GPIO_AF_PP		// �����������
			E_BSP_BEEPER_GPIO_OUT_PP	//�������	
  * @retval None
  */
static void BSP_BeeperGPIOInit(E_BSP_BEEPER_GPIO_MODE eBspBeeperGPIOMode)
{
	GPIO_InitTypeDef GPIO_InitStructure;

	/* GPIOB clock enable */
	RCC_APB2PeriphClockCmd(BEEPER_GPIO_CLK, ENABLE); 

	/* ���ú������õ���PB0���� */
	GPIO_InitStructure.GPIO_Pin =  BEEPER_GPIO_PIN ;
	
	if (eBspBeeperGPIOMode == E_BSP_BEEPER_GPIO_AF_PP)
	{
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;		    
	}else
	{
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;		
	}
	
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;

	GPIO_Init(BEEPER_GPIO_PORT, &GPIO_InitStructure);
}

#if (BSP_BEEPER_TYPE_NOPOWER == 1)
/**
  * @brief  nopower beeper pwm configuration
  * @param  
  * @retval None
  */
static void BSP_BeeperTimerPWMInit(void)
{
	/*
	 * TIMxCLK/CK_PSC --> TIMxCNT --> TIMx_ARR --> �ж� & TIMxCNT ���¼���
	 *                    TIMx_CCR(��ƽ�����仯)
	 *
	 * �ź�����=(TIMx_ARR +1 ) * ʱ������
	 *((1+TIM_Prescaler)/72M)*(1+TIM_Period)=((1+7199)/72M)*(1+9999)=1
	 * 
	 */

	/*    _______    ______     _____      ____       ___        __         _
	 * |_|       |__|      |___|     |____|    |_____|   |______|  |_______| |________|
	 */
	TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
	TIM_OCInitTypeDef  TIM_OCInitStructure;																				
	
	/* ����TIM3CLK ʱ��Ϊ72MHZ */
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE); 					//ʹ��TIM3ʱ��

	/* ������ʱ������ */		 
	TIM_TimeBaseStructure.TIM_Period = 255;       								//����ʱ����0������255����Ϊ266�Σ�Ϊһ����ʱ����
	TIM_TimeBaseStructure.TIM_Prescaler = 0;	    								//����Ԥ��Ƶ��
	TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1 ;			//����ʱ�ӷ�Ƶϵ��������Ƶ(�����ò���)
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;  	//���ϼ���ģʽ
	TIM_TimeBaseInit(TIM3, &TIM_TimeBaseStructure);

	/* PWMģʽ���� */
	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;	    				//����ΪPWMģʽ1
	
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;	//ʹ�����
	TIM_OCInitStructure.TIM_Pulse = 0;														//���ó�ʼPWM������Ϊ0	
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High ;  	//����ʱ������ֵС��CCR1_ValʱΪ�͵�ƽ

	
	//TIM_OC1Init(TIM3, &TIM_OCInitStructure);								//enable channel1
	//TIM_OC2Init(TIM3, &TIM_OCInitStructure);								//enable channel1
	//TIM_OC3Init(TIM3, &TIM_OCInitStructure);	 							
	TIM_OC4Init(TIM3, &TIM_OCInitStructure);

	//TIM_OC1PreloadConfig(TIM3, TIM_OCPreload_Enable);						//ʹ��Ԥװ��	
	//TIM_OC2PreloadConfig(TIM3, TIM_OCPreload_Enable);						//ʹ��Ԥװ��
	//TIM_OC3PreloadConfig(TIM3, TIM_OCPreload_Enable);						//ʹ��Ԥװ��
	TIM_OC4PreloadConfig(TIM3, TIM_OCPreload_Enable);	
	
	TIM_ARRPreloadConfig(TIM3, ENABLE);			 											//ʹ��TIM3���ؼĴ���ARR

	/* TIM3 enable counter */
	TIM_Cmd(TIM3, DISABLE);                   										//ʹ�ܶ�ʱ��3	
	
	TIM_ITConfig(TIM3,TIM_IT_Update, ENABLE);											//ʹ��update�ж�
}

/**
	* @brief  
	* 		�ı�ռ�ձȿ��Ըı�������С���ı�PWMƵ�ʿ��Ըı�����
	* 		TIMxCLK/CK_PSC --> TIMxCNT --> TIMx_ARR --> TIMxCNT ���¼���->TIMx_CCR(��ƽ�����仯)
	* 		����=(TIMx_ARR +1 ) * ʱ������
	* 		ռ�ձ�=TIMx_CCR/(TIMx_ARR +1)
	* @param 	beeperFrequency->����Ƶ��.����2000HZ,72MHZƵ���£����72Khz
	*			duty->ռ�ձ�0-100 
	*			timesNms->����ʱ��
	* @retval None
	*/
void BSP_BeeperSoundFrequency(uint16_t usBeeperFrequency,uint8_t ucDuty,uint16_t usTimesNms)
{
	
	uint32_t ulTemp;
	BSP_BeeperGPIOInit(E_BSP_BEEPER_GPIO_AF_PP);
	TIM_Cmd(TIM3, ENABLE); 
	TIM_ARRPreloadConfig(TIM3, ENABLE);
	
	ulTemp = 72000000 / usBeeperFrequency - 1;
	TIM3->ARR = ulTemp;
	TIM3->CCR4 = ulTemp * ucDuty / 100;
 
	
	BSP_BeeperDelayMs(usTimesNms);	
	TIM_Cmd(TIM3, DISABLE); 
	TIM_ARRPreloadConfig(TIM3, DISABLE);
	BSP_BeeperGPIOInit(E_BSP_BEEPER_GPIO_OUT_PP);
}


#endif

/**
  * @brief  �ж�����Դ������������Դ������
  * @param  
  * @retval 1-->��Դ��0--->��Դ
  */
uint8_t BSP_BeeperTypeIsNopower(void)
{
	#if BSP_BEEPER_TYPE_HAVE_POWER
		return 0;
	#else
		return 1;
	#endif	
}

/**
  * @brief  havepower beeper sound open
  * @param  timesNms->dealay times
  * @retval None
  */
void BSP_BeeperSoundOn(uint16_t usTimesNms)
{
	#if BSP_BEEPER_TYPE_HAVE_POWER
	GPIO_SetBits(BEEPER_GPIO_PORT,BEEPER_GPIO_PIN);
	BSP_BeeperDelayMs(usTimesNms);
	#endif	
}

/**
  * @brief  havepower beeper sound close
  * @param  
  * @retval None
  */
void BSP_BeeperSoundOff(uint16_t usTimesNms)
{
	#if BSP_BEEPER_TYPE_HAVE_POWER
	GPIO_ResetBits(BEEPER_GPIO_PORT,BEEPER_GPIO_PIN);
	#endif	
	BSP_BeeperDelayMs(usTimesNms);
}

/**
  * @brief  beeper delay  ms times
  * @param  
  * @retval None
  */
static void BSP_BeeperDelayMs(uint16_t usTimesNms)
{
  BSP_DelayMs(usTimesNms);
}
