#include "HW_Robo1.h"
#include "Forms_01.h"
#include "HW_Internal_STM32F429.h"
//#define asdwe = 0x01//событие изменения данных
//--------------------------
	typedef struct{
		uint8_t E_ID;
		uint8_t Tobj1_Min; // минимальная температура - выставляем событие
		uint8_t Tobj1_Max; // максимальная темперутра - выставляем событие
		uint8_t Tobj1_Min_Stat; // 0 - не сработало, 1 - сработало; в обработчике, при чтении, скидываем
		uint8_t Tobj1_Max_Stat; // 0 - не сработало, 1 - сработало; в обработчике, при чтении, скидываем
		uint8_t Tobj1_Max_ch;// статус изменения с прошлого раза
		
	}E_T_sensor_data;
//--------------------------
	typedef struct{
		uint8_t E_ID;
		uint8_t E_Door1;// 0 - не сработало, 1 - сработало; в обработчике, при чтении, скидываем
		uint8_t E_Door2;// 0 - не сработало, 1 - сработало; в обработчике, при чтении, скидываем
		uint8_t E_Door3;// 0 - не сработало, 1 - сработало; в обработчике, при чтении, скидываем
	}E_Mech_sensor_data;
//--------------------------
	typedef struct{
		uint8_t E_ID;
		uint8_t E_tim1;// 0 - не сработало, 1 - сработало; тимер для опроса датчиков
		uint8_t E_tim2;// 0 - не сработало, 1 - сработало; тимер для обновления картинки
		uint8_t E_tim3;// 0 - не сработало, 1 - сработало; тимер для ...
	}E_Tims_data;	
//--------------------------
	typedef struct{
		E_T_sensor_data e_t_sensor_data;
		E_Mech_sensor_data e_mech_sensor_data;
		E_Tims_data e_tims_data;
	}Event_Stat_Data;
//--------------------------
//--------------------------
//--------------------------
//--------------------------
//--------------------------
//--------------------------
void Event_init();
void GetEvent_Stat_Data();
void Eevent_Collector();
void EventHandler();