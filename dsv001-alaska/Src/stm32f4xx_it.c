/**
  ******************************************************************************
  * @file    stm32f4xx_it.c
  * @brief   Interrupt Service Routines.
  ******************************************************************************
  *
  * COPYRIGHT(c) 2016 STMicroelectronics
  *
  * Redistribution and use in source and binary forms, with or without modification,
  * are permitted provided that the following conditions are met:
  *   1. Redistributions of source code must retain the above copyright notice,
  *      this list of conditions and the following disclaimer.
  *   2. Redistributions in binary form must reproduce the above copyright notice,
  *      this list of conditions and the following disclaimer in the documentation
  *      and/or other materials provided with the distribution.
  *   3. Neither the name of STMicroelectronics nor the names of its contributors
  *      may be used to endorse or promote products derived from this software
  *      without specific prior written permission.
  *
  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
  * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
  * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
  * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
  * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
  * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
  * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
  *
  ******************************************************************************
  */
/* Includes ------------------------------------------------------------------*/
//#include "HW_Internal_STM32F429.h"
//#include "stm32f429i_discovery_lcd.h"
#include "stm32f4xx_hal.h"
#include "stm32f4xx.h"
#include "stm32f4xx_it.h"


/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/* External variables --------------------------------------------------------*/
extern Data_Status_HWISTM32429 data_status_whistm32429;
extern TIM_HandleTypeDef htim6;
extern TIM_HandleTypeDef htim9;
extern DMA2D_HandleTypeDef hdma2d;
extern LTDC_HandleTypeDef hltdc;
extern uint32_t ActiveLayer;

static uint8_t Request_Ch_Layer = 0;
//GPIO_PinState asd3376;

/******************************************************************************/
/*            Cortex-M4 Processor Interruption and Exception Handlers         */ 
/******************************************************************************/

/**
* @brief This function handles System service call via SWI instruction.
*/
void SVC_Handler(void)
{
  /* USER CODE BEGIN SVCall_IRQn 0 */

  /* USER CODE END SVCall_IRQn 0 */
  /* USER CODE BEGIN SVCall_IRQn 1 */

  /* USER CODE END SVCall_IRQn 1 */
}

/**
* @brief This function handles Pendable request for system service.
*/
void PendSV_Handler(void)
{
  /* USER CODE BEGIN PendSV_IRQn 0 */

  /* USER CODE END PendSV_IRQn 0 */
  /* USER CODE BEGIN PendSV_IRQn 1 */

  /* USER CODE END PendSV_IRQn 1 */
}

/**
* @brief This function handles System tick timer.
*/
void SysTick_Handler(void)
{
  /* USER CODE BEGIN SysTick_IRQn 0 */

  /* USER CODE END SysTick_IRQn 0 */
  HAL_IncTick();
  HAL_SYSTICK_IRQHandler();
  /* USER CODE BEGIN SysTick_IRQn 1 */

  /* USER CODE END SysTick_IRQn 1 */
}

/******************************************************************************/
/* STM32F4xx Peripheral Interrupt Handlers                                    */
/* Add here the Interrupt Handlers for the used peripherals.                  */
/* For the available peripheral interrupt handler names,                      */
/* please refer to the startup file (startup_stm32f4xx.s).                    */
/******************************************************************************/

/**
* @brief This function handles TIM1 break interrupt and TIM9 global interrupt.
*/
void TIM1_BRK_TIM9_IRQHandler(void)
{
  /* USER CODE BEGIN TIM1_BRK_TIM9_IRQn 0 */
  //HAL_GPIO_TogglePin(GPIOG, LD3_Pin);
		  if(__HAL_TIM_GET_FLAG(&htim9, TIM_FLAG_UPDATE) != RESET)
  {
    if(__HAL_TIM_GET_IT_SOURCE(&htim9, TIM_IT_UPDATE) !=RESET)
    {
			data_status_whistm32429.tim09_HWISTM32429.Tim09_ch = 1;
			//изменить на внутреннюю переменную, добавить в коллектор событий загрузку из местной переменной
			//HAL_GPIO_TogglePin(GPIOG, LD4_Pin);
    }
  }
	//HAL_GPIO_WritePin(GPIOG, LD4_Pin,1);
  /* USER CODE END TIM1_BRK_TIM9_IRQn 0 */
  HAL_TIM_IRQHandler(&htim9);
  /* USER CODE BEGIN TIM1_BRK_TIM9_IRQn 1 */

  /* USER CODE END TIM1_BRK_TIM9_IRQn 1 */
}

/**
* @brief This function handles TIM6 global interrupt, DAC1 and DAC2 underrun error interrupts.
*/
void TIM6_DAC_IRQHandler(void)
{
  /* USER CODE BEGIN TIM6_DAC_IRQn 0 */
	//delay(1000);
	//HAL_GPIO_WritePin(GPIOG, LD3_Pin,1);
	/*
	typedef enum
{
  GPIO_PIN_RESET = 0,
  GPIO_PIN_SET
}GPIO_PinState;
	*/
	//asd3376
	  if(__HAL_TIM_GET_FLAG(&htim6, TIM_FLAG_UPDATE) != RESET)
  {
    if(__HAL_TIM_GET_IT_SOURCE(&htim6, TIM_IT_UPDATE) !=RESET)
    {
			data_status_whistm32429.tim06_HWISTM32429.Tim06_ch = 1;
			//изменить на внутреннюю переменную, добавить в коллектор событий загрузку из местной переменной			
			//HAL_GPIO_TogglePin(GPIOG, LD3_Pin);
    };
  };
	
	/*
	  // TIM Update event 
  if(__HAL_TIM_GET_FLAG(htim, TIM_FLAG_UPDATE) != RESET)
  {
    if(__HAL_TIM_GET_IT_SOURCE(htim, TIM_IT_UPDATE) !=RESET)
    {
      __HAL_TIM_CLEAR_IT(htim, TIM_IT_UPDATE);
      HAL_TIM_PeriodElapsedCallback(htim);
    }
  }
	*/
  //HAL_GPIO_TogglePin(GPIOG, LD4_Pin);

	//HAL_GPIO_WritePin(GPIOG, LD3_Pin,1);
  /* USER CODE END TIM6_DAC_IRQn 0 */
  HAL_TIM_IRQHandler(&htim6);
  /* USER CODE BEGIN TIM6_DAC_IRQn 1 */

  /* USER CODE END TIM6_DAC_IRQn 1 */
}
//=====================--------------------===============
/**
* @brief This function handles DMA2D global interrupt.
*/
void DMA2D_IRQHandler(void)
{
  /* USER CODE BEGIN DMA2D_IRQn 0 */
	//HAL_GPIO_TogglePin(GPIOG, LD3_Pin);
	HAL_GPIO_WritePin(GPIOG, LD3_Pin, GPIO_PIN_SET);
  /* USER CODE END DMA2D_IRQn 0 */
  HAL_DMA2D_IRQHandler(&hdma2d);
  /* USER CODE BEGIN DMA2D_IRQn 1 */

  /* USER CODE END DMA2D_IRQn 1 */
};
//==================--------------------------=============
/**
* @brief This function handles LTDC global interrupt.
*/
void LTDC_IRQHandler(void)
{
	//HAL_Delay(1);
	HAL_GPIO_TogglePin(GPIOG, LD3_Pin);
	
	  /* Line Interrupt management ************************************************/
  if(__HAL_LTDC_GET_FLAG(&hltdc, LTDC_FLAG_LI) != RESET)
  {
		//HAL_GPIO_WritePin(GPIOG, LD3_Pin, 1);
    if(__HAL_LTDC_GET_IT_SOURCE(&hltdc, LTDC_IT_LI) != RESET)
    {
			__HAL_LTDC_CLEAR_FLAG(&hltdc, LTDC_FLAG_LI);
				if (Request_Ch_Layer)
				{
					Request_Ch_Layer = 0;
					
				};
			
		}
	}
	
	  /* Register reload Interrupt management ***************************************/
  if(__HAL_LTDC_GET_FLAG(&hltdc, LTDC_FLAG_RR) != RESET)
  {
		//HAL_GPIO_WritePin(GPIOG, LD3_Pin, 1);
    if(__HAL_LTDC_GET_IT_SOURCE(&hltdc, LTDC_IT_RR) != RESET)
    {
			__HAL_LTDC_CLEAR_FLAG(&hltdc, LTDC_FLAG_RR);
			ActiveLayer = 0; //ошибка !!!!!???????
			/*if(ActiveLayer)
			{
				ActiveLayer = 0;
			}else
			{
				ActiveLayer = 1;
			}*/
		}
	}
  /* USER CODE BEGIN LTDC_IRQn 0 */
  /* USER CODE END LTDC_IRQn 0 */
	//HAL_GPIO_WritePin(GPIOG, LD3_Pin, 0);

  HAL_LTDC_IRQHandler(&hltdc);
  /* USER CODE BEGIN LTDC_IRQn 1 */

  /* USER CODE END LTDC_IRQn 1 */
}

/**
* @brief This function handles LTDC global error interrupt.
*/
void LTDC_ER_IRQHandler(void)
{
	//HAL_GPIO_WritePin(GPIOG, LD3_Pin, 1);
  /* USER CODE BEGIN LTDC_ER_IRQn 0 */
	//HAL_GPIO_TogglePin(GPIOG, LD3_Pin);
	//HAL_GPIO_WritePin(GPIOG, LD3_Pin, 1);
  //__HAL_LTDC_ENABLE
  /* USER CODE END LTDC_ER_IRQn 0 */
	__HAL_LTDC_CLEAR_FLAG(&hltdc, LTDC_FLAG_FU);
	__HAL_LTDC_CLEAR_FLAG(&hltdc, LTDC_FLAG_TE);
  HAL_LTDC_IRQHandler(&hltdc);
  /* USER CODE BEGIN LTDC_ER_IRQn 1 */

  /* USER CODE END LTDC_ER_IRQn 1 */
}

/**
* @brief This function handles DMA2D global interrupt.
*/
