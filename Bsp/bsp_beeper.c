/**
  ******************************************************************************
  * @file    BSP_Beeper.c
  * @author  Grub'bai
  * @version V0.0.1
  * @date    24-8-2015
  * @brief   蜂鸣器硬件抽象层，提供上层蜂鸣器API
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
	*		E_BSP_BEEPER_GPIO_AF_PP		// 复用推挽输出
			E_BSP_BEEPER_GPIO_OUT_PP	//推挽输出	
  * @retval None
  */
static void BSP_BeeperGPIOInit(E_BSP_BEEPER_GPIO_MODE eBspBeeperGPIOMode)
{
	GPIO_InitTypeDef GPIO_InitStructure;

	/* GPIOB clock enable */
	RCC_APB2PeriphClockCmd(BEEPER_GPIO_CLK, ENABLE); 

	/* 配置呼吸灯用到的PB0引脚 */
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
	 * TIMxCLK/CK_PSC --> TIMxCNT --> TIMx_ARR --> 中断 & TIMxCNT 重新计数
	 *                    TIMx_CCR(电平发生变化)
	 *
	 * 信号周期=(TIMx_ARR +1 ) * 时钟周期
	 *((1+TIM_Prescaler)/72M)*(1+TIM_Period)=((1+7199)/72M)*(1+9999)=1
	 * 
	 */

	/*    _______    ______     _____      ____       ___        __         _
	 * |_|       |__|      |___|     |____|    |_____|   |______|  |_______| |________|
	 */
	TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
	TIM_OCInitTypeDef  TIM_OCInitStructure;																				
	
	/* 设置TIM3CLK 时钟为72MHZ */
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE); 					//使能TIM3时钟

	/* 基本定时器配置 */		 
	TIM_TimeBaseStructure.TIM_Period = 255;       								//当定时器从0计数到255，即为266次，为一个定时周期
	TIM_TimeBaseStructure.TIM_Prescaler = 0;	    								//设置预分频：
	TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1 ;			//设置时钟分频系数：不分频(这里用不到)
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;  	//向上计数模式
	TIM_TimeBaseInit(TIM3, &TIM_TimeBaseStructure);

	/* PWM模式配置 */
	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;	    				//配置为PWM模式1
	
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;	//使能输出
	TIM_OCInitStructure.TIM_Pulse = 0;														//设置初始PWM脉冲宽度为0	
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High ;  	//当定时器计数值小于CCR1_Val时为低电平

	
	//TIM_OC1Init(TIM3, &TIM_OCInitStructure);								//enable channel1
	//TIM_OC2Init(TIM3, &TIM_OCInitStructure);								//enable channel1
	//TIM_OC3Init(TIM3, &TIM_OCInitStructure);	 							
	TIM_OC4Init(TIM3, &TIM_OCInitStructure);

	//TIM_OC1PreloadConfig(TIM3, TIM_OCPreload_Enable);						//使能预装载	
	//TIM_OC2PreloadConfig(TIM3, TIM_OCPreload_Enable);						//使能预装载
	//TIM_OC3PreloadConfig(TIM3, TIM_OCPreload_Enable);						//使能预装载
	TIM_OC4PreloadConfig(TIM3, TIM_OCPreload_Enable);	
	
	TIM_ARRPreloadConfig(TIM3, ENABLE);			 											//使能TIM3重载寄存器ARR

	/* TIM3 enable counter */
	TIM_Cmd(TIM3, DISABLE);                   										//使能定时器3	
	
	TIM_ITConfig(TIM3,TIM_IT_Update, ENABLE);											//使能update中断
}

/**
	* @brief  
	* 		改变占空比可以改变声音大小，改变PWM频率可以改变音调
	* 		TIMxCLK/CK_PSC --> TIMxCNT --> TIMx_ARR --> TIMxCNT 重新计数->TIMx_CCR(电平发生变化)
	* 		周期=(TIMx_ARR +1 ) * 时钟周期
	* 		占空比=TIMx_CCR/(TIMx_ARR +1)
	* @param 	beeperFrequency->声音频率.例如2000HZ,72MHZ频率下，最大72Khz
	*			duty->占空比0-100 
	*			timesNms->持续时间
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
  * @brief  判断是无源蜂鸣器还是有源蜂鸣器
  * @param  
  * @retval 1-->有源，0--->无源
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
