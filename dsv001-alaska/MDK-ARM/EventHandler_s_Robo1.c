#include "EventHandler_s_Robo1.h"

//>>>>>>>>>>>
Event_Stat_Data event_stat_data;
Data_status D_s;		

char *STR_out;//буфер для перевода чисел в строку
uint8_t n_count1;

	
void Event_init()
	{				
		Get_Data_Status(&D_s);
		D_s.t_sensor_data.Tobj1.Filter_coeff = 0.04;
	  D_s.t_sensor_data.Tobj1.Integr_Val = 0;
		
		event_stat_data.e_t_sensor_data.Tobj1_Max = 30;
		event_stat_data.e_t_sensor_data.Tobj1_Max_Stat = 0;
		event_stat_data.e_t_sensor_data.E_ID = 0;
		event_stat_data.e_t_sensor_data.Tobj1_Max_ch = 1;
		
		/*event_stat_data.e_tims_data.E_ID = 1;
		event_stat_data.e_tims_data.E_tim1 = 0;
		event_stat_data.e_tims_data.E_tim2 = 0;
		event_stat_data.e_tims_data.E_tim3 = 0;*/
		
		STR_out = ( char * )calloc( 30,sizeof( char ) );//выделяем память		
		
	};
//>>>>>>>>>>>
void Eevent_Collector() // извлечение/заполнение всех  необходимых данных
	{
		event_stat_data.e_tims_data.E_tim1 = Get_Tim09_ch();
		event_stat_data.e_tims_data.E_tim2 = Get_Tim06_ch();
		
		/*if (Get_Tim09_ch())
		{
			event_stat_data.e_tims_data.E_tim1
			Get_Data_Status(&D_s);			
		};*/
		//Get_Tim09_ch()
		
		//>>>
		if((D_s.t_sensor_data.Tobj1.Integr_Val > event_stat_data.e_t_sensor_data.Tobj1_Max)&&(1)) // проверка на выход за пределы граници
		{
			if (event_stat_data.e_t_sensor_data.Tobj1_Max_Stat == 0)
				{
					event_stat_data.e_t_sensor_data.Tobj1_Max_ch = 1; //флаг - то, что изменился с прошлого раза
			  };
				
			event_stat_data.e_t_sensor_data.Tobj1_Max_Stat = 1;// флаг - вышел из диапазона			
		};
		//>>>
		if((D_s.t_sensor_data.Tobj1.Integr_Val < event_stat_data.e_t_sensor_data.Tobj1_Max)&&(1))
		{
			if (event_stat_data.e_t_sensor_data.Tobj1_Max_Stat == 1)
				{
					event_stat_data.e_t_sensor_data.Tobj1_Max_ch = 1;
			  };
			event_stat_data.e_t_sensor_data.Tobj1_Max_Stat = 0;			
		};
		//---===---
		/*if (event_stat_data.e_tims_data.E_tim1 == 1)
		{
			
		};*/
		//event_stat_data.e_tims_data.E_tim1 = D_s.tims_data.tim1_ticks;
		//event_stat_data.e_tims_data.E_tim2 = D_s.tims_data.tim2_ticks;

		//---===---
		//---===---
		//---===---
		//---===---
		//---===---
	};
//>>>>>>>>>>>
void EventHandler()//обработчик событий
	{
//--------------------------------------------------------------
		//event_stat_data.e_t_sensor_data.Tobj1_Max_ch
		if (event_stat_data.e_t_sensor_data.Tobj1_Max_ch == 1)
			{
				event_stat_data.e_t_sensor_data.Tobj1_Max_ch = 0;
				if (event_stat_data.e_t_sensor_data.Tobj1_Max_Stat == 1)
					{
					//event_stat_data.e_t_sensor_data.Tobj1_Max_Stat = 0;			
					
//						BSP_LCD_SetFont(&Font20);


 					  //HAL_GPIO_TogglePin(GPIOG, LD3_Pin | LD4_Pin);
						Form01_Set_Mode(1);	

						//					
						//DSV_Draw_wind();
//						BSP_LCD_SetFont(&Font16);

		//			n_count1 = 1;
						/*BSP_LCD_SetTextColor(LCD_COLOR_RED);
						BSP_LCD_FillRect(70,120,100,100);
						BSP_LCD_SetTextColor(LCD_COLOR_BLACK);*/
					}
				else
					{
//						BSP_LCD_SetFont(&Font20);



						//HAL_GPIO_TogglePin(GPIOG, LD3_Pin | LD4_Pin);
						Form01_Set_Mode(0);	
						
						//DSV_Draw_wind();

					};
			};
//>>>>>>>>>
				if (		event_stat_data.e_tims_data.E_tim2)
				{
					sprintf(STR_out,"%4.1F", D_s.t_sensor_data.Ta);
					Form01_SetText00(STR_out);
					
					sprintf(STR_out,"%4.1F", D_s.t_sensor_data.Tobj1.Integr_Val);
					Form01_SetText01(STR_out);
					DSV_Draw_wind();
				};
//>>>>>>>>>
				if(event_stat_data.e_tims_data.E_tim1)
				{
					Get_Data_Status(&D_s);
				};

			
			
			
			/*if (event_stat_data.e_tims_data.E_tim2 == 1)
			{
				HAL_GPIO_TogglePin(GPIOG, LD3_Pin | LD4_Pin);
			};*/
		//sprintf(STR_out,"%4.1F", D_s.t_sensor_data.Ta);
		//BSP_LCD_DisplayStringAtLine(4,STR_out);	

		//sprintf(STR_out,"%4.1F", D_s.t_sensor_data.Tobj1.Val_Sens_SRC);
		//BSP_LCD_DisplayStringAtLine(5,STR_out);	

		//sprintf(STR_out,"%4.1F", D_s.t_sensor_data.Tobj1.Integr_Val);
		//BSP_LCD_DisplayStringAtLine(6,STR_out);
		
//======		

//======		
};
