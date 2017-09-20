#include "HW_Internal_STM32F429.h"

//===================================================

Data_Status_HWISTM32429 data_status_whistm32429;

TIM_HandleTypeDef htim6;
TIM_HandleTypeDef htim9;

void Error_Handler_01(void);
static void MX_TIM6_Init(void);
static void MX_TIM9_Init(void);

//===================================================
void HW_Internal_STM32F429_Init()
{
//----=================    Tim01
	//T = 0.001 sec
	data_status_whistm32429.tim06_HWISTM32429.Tim06_ch = 0; //флаг срабатывания
	//data_status_whistm32429.tim06_HWISTM32429.Tim06_Counter_N = 1000; // загружаемое значение счетчика
	//data_status_whistm32429.tim06_HWISTM32429.Tim06_PRSCL = 168; //значение предделителя
	//

//----=================    Tim02
	//T = 0.02 sec
	data_status_whistm32429.tim09_HWISTM32429.Tim09_ch = 0; //флаг срабатывания
	//data_status_whistm32429.tim09_HWISTM32429.Tim09_Counter_N = 20000; // загружаемое значение счетчика
	//data_status_whistm32429.tim09_HWISTM32429.Tim09_PRSCL = 168; //значение предделителя
	
	//-0-0-0--0-0-0-0-0-0-0-0-0-0-0-0
	MX_TIM6_Init();
    MX_TIM9_Init();
	
	HAL_TIM_Base_Start_IT(&htim6);
	HAL_TIM_Base_Start_IT(&htim9);

};
//=================    Tim01     ==================================
uint8_t Get_Tim06_ch()
	{
		uint8_t D_TMP = data_status_whistm32429.tim06_HWISTM32429.Tim06_ch;
		data_status_whistm32429.tim06_HWISTM32429.Tim06_ch = 0;
		return D_TMP;
	};
//-=-=-=-=-=-

	
//=================    Tim02     ==================================
uint8_t Get_Tim09_ch()
	{
		uint8_t D_TMP = data_status_whistm32429.tim09_HWISTM32429.Tim09_ch;
		data_status_whistm32429.tim09_HWISTM32429.Tim09_ch = 0;
		return D_TMP;
	};
//-=-=-=-=-=-
//===================================================
/*https://www.drive2.ru/b/2236498/
	http://catethysis.ru/stm32-from_zero_to_rtos-2_timers/
	*/
//===================================================
	/* TIM6 init function */
static void MX_TIM6_Init(void)// 45MHz
{

  TIM_MasterConfigTypeDef sMasterConfig;

  htim6.Instance = TIM6;
  htim6.Init.Prescaler = 45000 - 1;
  htim6.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim6.Init.Period = 50 - 1;
  if (HAL_TIM_Base_Init(&htim6) != HAL_OK)
  {
//	HAL_GPIO_TogglePin(GPIOG, LD3_Pin | LD4_Pin);
    Error_Handler_01();
  }

  sMasterConfig.MasterOutputTrigger = TIM_TRGO_UPDATE;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim6, &sMasterConfig) != HAL_OK)
  {
    Error_Handler_01();
  }

	//HAL_NVIC_EnableIRQ(TIM6_DAC_IRQn);

};

/* TIM9 init function */
static void MX_TIM9_Init(void) // 90MHz обновление данных 
{

  TIM_ClockConfigTypeDef sClockSourceConfig;
  TIM_OC_InitTypeDef sConfigOC;

  htim9.Instance = TIM9;
  htim9.Init.Prescaler = 45000 - 1;
  htim9.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim9.Init.Period = 200 - 1;
  htim9.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  if (HAL_TIM_Base_Init(&htim9) != HAL_OK)
  {
    Error_Handler_01();
  }

  sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
  if (HAL_TIM_ConfigClockSource(&htim9, &sClockSourceConfig) != HAL_OK)
  {
    Error_Handler_01();
  }

  if (HAL_TIM_OC_Init(&htim9) != HAL_OK)
  {
    Error_Handler_01();
  }

  sConfigOC.OCMode = TIM_OCMODE_TIMING;
  sConfigOC.Pulse = 0;
  sConfigOC.OCPolarity = TIM_OCPOLARITY_HIGH;
  sConfigOC.OCFastMode = TIM_OCFAST_DISABLE;
  if (HAL_TIM_OC_ConfigChannel(&htim9, &sConfigOC, TIM_CHANNEL_1) != HAL_OK)
  {
    Error_Handler_01();
  }

  if (HAL_TIM_OC_ConfigChannel(&htim9, &sConfigOC, TIM_CHANNEL_2) != HAL_OK)
  {
    Error_Handler_01();
  }
	//HAL_NVIC_EnableIRQ(TIM1_BRK_TIM9_IRQn);
	//HAL_NVIC_EnableIRQ(TIM1_UP_TIM10_IRQn);
	//HAL_GPIO_TogglePin(GPIOG, LD3_Pin);
};

//===================================================
void Error_Handler_01(void)
{
  /* USER CODE BEGIN Error_Handler */
  /* User can add his own implementation to report the HAL error return state */
		//HAL_GPIO_TogglePin(GPIOG, LD4_Pin);
  while(1) 
  {
  }
  /* USER CODE END Error_Handler */ 
}

#ifdef USE_FULL_ASSERT

/**
   * @brief Reports the name of the source file and the source line number
   * where the assert_param error has occurred.
   * @param file: pointer to the source file name
   * @param line: assert_param error line source number
   * @retval None
   */
void assert_failed(uint8_t* file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
    ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */

}

#endif
//===================================================
//===================================================
