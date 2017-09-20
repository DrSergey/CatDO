#include "stm32f429i_discovery_lcd.h"
#include "stdlib.h"
#include "stdio.h"

//#include "HW_Robo1.h"
//void form_001(uint8_t asd333);// всегда на весь экран
typedef struct{
	char * text00;
	uint16_t text00_X;
	uint16_t text00_Y;
}Text00;
typedef struct{
	char * text01;	
	uint16_t text01_X;
	uint16_t text01_Y;
}Text01;

typedef struct{	
	uint8_t alert_act; // Определяет вид по состоянию, ошибки или нормально.
	Text00 frame_text00;
	Text01 frame_text01;
}DSV_Form_01_Data;

//DSV_Form_01_Data dsv_form_01_data;
	void DSV_Draw_wind();
	void DSV_Draw_wind_init();

	void Form01_Set_Mode(uint8_t alert_act);

//
	void Form01_SetText00(char *form01_text00);
	void Form01_SetText01(char *form01_text01);
	//void Form01_SetText00(char *form01_text00);

//	void DSV_Draw_wind_UpData();