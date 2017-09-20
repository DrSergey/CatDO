#include "Forms_01.h"
//#include "stm32f429i_discovery_lcd.h"


int8_t asdn88;
///


char * Form01_STR_out;
DSV_Form_01_Data dsv_form_01_data; // сгруппированные данные формы
//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
void DSV_Draw_wind_init()
{
		Form01_STR_out = ( char * )calloc( 30,sizeof( char ));
//
		dsv_form_01_data.frame_text00.text00 = ( char * )calloc( 10,sizeof( char ));// текстовое поле.
		dsv_form_01_data.frame_text00.text00_X = 10;
		dsv_form_01_data.frame_text00.text00_Y = 100;
//		
		dsv_form_01_data.frame_text01.text01 = ( char * )calloc( 10,sizeof( char ));// текстовое поле.
		dsv_form_01_data.frame_text01.text01_X = 150;
		dsv_form_01_data.frame_text01.text01_Y = 100;
//
		dsv_form_01_data.alert_act = 0;
	
	//---
	asdn88 = 0;
	
};

//======================================================================
void Form01_SetText00(char *form01_text00)
		{
			strncpy(dsv_form_01_data.frame_text00.text00,form01_text00,10);
			//dsv_form_01_data.text00 = form01_text00;
		};
//======================================================================
void Form01_SetText01(char *form01_text01)
		{
			strncpy(dsv_form_01_data.frame_text01.text01,form01_text01,10);
			//dsv_form_01_data.text00 = form01_text00;
		};
//======================================================================
void Form01_Set_Mode(uint8_t alert_act)
{
	dsv_form_01_data.alert_act = alert_act;
};
//======================================================================
	void DSV_Draw_wind()
	{
		switch (asdn88)
{
    case 0: 
						
						
						
						BSP_LCD_SelectLayer(LCD_FOREGROUND_LAYER);
						BSP_LCD_SetLayerVisible(LCD_FOREGROUND_LAYER, DISABLE);
		
		
						BSP_LCD_SelectLayer(LCD_BACKGROUND_LAYER);
						BSP_LCD_SetLayerVisible(LCD_BACKGROUND_LAYER, ENABLE);
						//BSP_LCD_SetLayerAddress(LCD_BACKGROUND_LAYER, LCD_FRAME_BUFFER);
						//BSP_LCD_SetLayerAddress(LCD_FOREGROUND_LAYER, LCD_FRAME_BUFFER2);
						
						/*BSP_LCD_SetTransparency(LCD_BACKGROUND_LAYER, 0);
						BSP_LCD_SetTransparency(LCD_FOREGROUND_LAYER, 255);*/
						asdn88 = 1;
						HAL_GPIO_TogglePin(GPIOG, LD4_Pin);
						break;
		case 1:	
						BSP_LCD_SelectLayer(LCD_FOREGROUND_LAYER);
						BSP_LCD_SetLayerVisible(LCD_FOREGROUND_LAYER, ENABLE);
		
		
						BSP_LCD_SelectLayer(LCD_BACKGROUND_LAYER);
						BSP_LCD_SetLayerVisible(LCD_BACKGROUND_LAYER, DISABLE);
						//BSP_LCD_SetLayerAddress(LCD_BACKGROUND_LAYER, LCD_FRAME_BUFFER2);
						//BSP_LCD_SetLayerAddress(LCD_FOREGROUND_LAYER, LCD_FRAME_BUFFER);
							/*BSP_LCD_SetTransparency(LCD_BACKGROUND_LAYER, 255);
							BSP_LCD_SetTransparency(LCD_FOREGROUND_LAYER, 0);*/

						asdn88 = 0;
						HAL_GPIO_TogglePin(GPIOG, LD4_Pin);
						break;
    default:		
						break;
}
		

		/*BSP_LCD_SetFont(&Font20);		
		if (dsv_form_01_data.alert_act == 0){
			BSP_LCD_SetTextColor(LCD_COLOR_GREEN);
		}else {
			BSP_LCD_SetTextColor(LCD_COLOR_RED);
		};
		BSP_LCD_DrawRect(0,0,BSP_LCD_GetXSize()-1,BSP_LCD_GetYSize()-1);
		BSP_LCD_SetTextColor(LCD_COLOR_GRAY);
		BSP_LCD_FillRect(1,1,BSP_LCD_GetXSize()-2,BSP_LCD_GetYSize()-2);		
		BSP_LCD_DisplayStringAt(0,0,"Gener",CENTER_MODE);
		BSP_LCD_SetFont(&Font16);
		BSP_LCD_DisplayStringAt(dsv_form_01_data.frame_text00.text00_X,dsv_form_01_data.frame_text00.text00_Y,dsv_form_01_data.frame_text00.text00,LEFT_MODE);
		BSP_LCD_DisplayStringAt(dsv_form_01_data.frame_text01.text01_X,dsv_form_01_data.frame_text01.text01_Y,dsv_form_01_data.frame_text01.text01,LEFT_MODE);
		*/
	};