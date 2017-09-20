#include "stm32f4xx_hal.h"
//Float 
typedef struct {
   float integr_component;
   float filter_coeff;
}F_Data_Struct;


float Get_Filter_Data(float *data_src, uint8_t *Sensor_ID);
void Complementary_Filter_Iter(float *data_src, float *integr_component1, float filter_coeff1);
void Complementary_Filter_Init();