
#include "EventHandler_s_Robo1.h"

typedef struct {
   uint32_t quot;
   uint8_t rem;
}divmod10_t;
//---------------------------------------------------------------------------------------
inline static divmod10_t divmodu10(uint32_t n) //деление на 10 ,быстрое
{
    divmod10_t res;
// 
    res.quot = n >> 1;
    res.quot += res.quot >> 1;
    res.quot += res.quot >> 4;
    res.quot += res.quot >> 8;
    res.quot += res.quot >> 16;
    uint32_t qq = res.quot;
// 
    res.quot >>= 3;
// 
    res.rem = (uint8_t)(n - ((res.quot << 1) + (qq & ~7ul)));
// 
    if(res.rem > 9)
    {
        res.rem -= 10;
        res.quot++;
    }
    return res;
}
char * utoa_fast_div(uint32_t value,char *buffer)
{
    buffer = buffer + 11;
    *--buffer = 0;
	do
    {
        divmod10_t res = divmodu10(value);
        *--buffer = res.rem + '0';
        value = res.quot;
    }
    while (value != 0);
    return buffer;
}
//=-=-=-=
int main(void)
{	
	//H_init_R();
	HW_Internal_STM32F429_Init();
	Event_init();
	DSV_Draw_wind_init();

	

		
	
	while (1)
  {			
		Eevent_Collector();
		EventHandler();

		//HAL_Delay(1);
  }

}
