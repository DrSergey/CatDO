#include "stm32f4xx_hal.h"
#include "mlx90614BCC.h"
#include "stm32f429i_discovery_lcd.h"
//#include "HW_Internal_STM32F429.h"
//#include "stdlib.h"
//#include "stdio.h"
#include "D_Filter.h"
/* сгруппированные данные: 
   float Val_Sens_SRC - исходные данные полученые от датчиков 
	 float Integr_Val 	- 
   float Filter_coeff - 		

*/
typedef struct { 
   float Val_Sens_SRC; //исходные данные
	 float Integr_Val; 
   float Filter_coeff; //коэффициент фильтра		
}Compl_Data_Filter;
//==================================================------------
typedef struct { //тип для данных датчика температуры
	 uint8_t ID_sensor;
   float Ta; // амбиентная температура from RAM
   Compl_Data_Filter Tobj1; //тепература объекта с датчика 1  from RAM
   float Tobj2; //тепература объекта с датчика 2  from RAM
   float Raw_d_IR_chan_1; // хрен знает что это ????  from RAM
   float Raw_d_IR_chan_2; // хрен знает что это ????  from RAM
   uint16_t DSV_Id_1; // ID number  from EEPROM
   uint16_t DSV_Id_2; // ID number  from EEPROM
   uint16_t DSV_Id_3; // ID number  from EEPROM
	 //float integr_component;
   //float filter_coeff;
}T_sensor_data;
//==================================================------------
typedef struct { //тип для данных датчиков
	uint8_t ID_sensor;
	uint8_t Stat_Hole_1; 
	uint8_t Stat_Hole_2; 
	uint8_t Stat_Dore_1; 
	uint8_t Stat_Dore_2; 
  //float integr_component;
  //float filter_coeff;
}Mech_sensor_data;
//-=-=-=-=-=-=-=-=-=-=-=-=
	typedef struct{
		uint8_t E_ID;
		uint8_t tim1_ticks;// 0 - не сработало, 1 - сработало; тимер для опроса датчиков
		uint8_t tim2_ticks;// 0 - не сработало, 1 - сработало; тимер для обновления картинки
		uint8_t tim3_ticks;// 0 - не сработало, 1 - сработало; тимер для ...
	}Tims_data;	
//--------------------------

typedef struct { //тип для данных датчика
	Mech_sensor_data mech_sensor_data;
	T_sensor_data t_sensor_data;
	//Tims_data tims_data;
}Data_status;

//================
double convert_T_sensor_data(uint8_t *Buffer_i2c);
//================
void DSV_Revers_2_bytes(uint8_t *Buffer_i2c);
//================
void MLX90614_RamRead(uint8_t I2C_DEV_ADRS, uint8_t MEM_ADRS ,uint8_t * Buffer_i2c);
//================
void MLX90614_EEPROMRead(uint8_t I2C_DEV_ADRS, uint8_t MEM_ADRS ,uint8_t * Buffer_i2c);
//================
void MLX90614_EEPROMWrite(uint8_t I2C_DEV_ADRS, uint8_t MEM_ADRS ,uint8_t * Buffer_i2c);
//================
//void Get_T_sensor_data(T_sensor_data *t_sensor_data_000);
void Get_T_sensor_data(Data_status *t_sensor_data_000);
//================
void Get_Mech_sensor_data(Data_status *mech_sensor_data000);
//================
void H_init_R();
//================
void SystemClock_Config(void);
//================

//================
void Get_Data_Status(Data_status *data_status);
//=============================================================
//=============================================================