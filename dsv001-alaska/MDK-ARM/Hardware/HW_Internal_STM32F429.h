#include "stm32f4xx_hal.h"
//#include "stm32f4xx_rcc.h"
//#include "stm32f4xx_gpio.h"
//#include "stm32f4xx_tim.h"
//#include <misc.h>
//#include "stm32f4xx_hal.h"
typedef struct { //
	uint8_t Tim06_ch; //���� ������������
	//uint16_t Tim06_Counter_N; // ����������� �������� ��������
	//uint16_t Tim06_PRSCL; // ����������� �������� ������������	
}Tim06_HWISTM32429; // ��� ��������� �����
typedef struct { //
	uint8_t Tim09_ch; //���� ������������
	//uint16_t Tim09_Counter_N; // ����������� �������� ��������
	//uint16_t Tim09_PRSCL; // ����������� �������� ������������	
}Tim09_HWISTM32429; //��� ������ ������

typedef struct { //��� ��� ������ �������
	Tim06_HWISTM32429 tim06_HWISTM32429;
	Tim09_HWISTM32429 tim09_HWISTM32429;
	//T_sensor_data t_sensor_data;
}Data_Status_HWISTM32429;
//=================================================================
void HW_Internal_STM32F429_Init();
//=================================================================
uint8_t Get_Tim06_ch();
//-=-=-=-=-=-

//=================================================================
uint8_t Get_Tim09_ch();
//-=-=-=-=-=-
//void Get_Tims_data(Data_status *tims_data_000); // ���������� �� ���������
//================
//=================================================================
//=================================================================
