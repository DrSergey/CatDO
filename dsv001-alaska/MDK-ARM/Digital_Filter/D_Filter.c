#include "D_Filter.h"
F_Data_Struct f_data_struct;//
F_Data_Struct f_data_struct1;//
F_Data_Struct Mass_f_data_struct[10];

//-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
float Get_Filter_Data_Sensor_ID(float *data_src, uint8_t *Sensor_ID)
	{
		switch (*Sensor_ID){
			case 0:{};  break;
			case 1:{};  break;
			case 2:{};  break;
			case 3:{};  break;
			case 4:{};  break;
			default:{}; break;
		};
	};
//-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
//-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
void Complementary_Filter_Iter(float *data_src, float *integr_component1,float filter_coeff1)
	{
		*integr_component1 = (1-filter_coeff1) * (*integr_component1) + filter_coeff1 * (*data_src);
		//return f_data_struct.integr_component;
	};
//-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
void Complementary_Filter_Init()
	{
		Mass_f_data_struct[0].filter_coeff = 0.1;
		Mass_f_data_struct[0].integr_component = 0;
		
		Mass_f_data_struct[1].filter_coeff = 0.1;
		Mass_f_data_struct[1].integr_component = 0;

		
		f_data_struct.integr_component = 0;
		f_data_struct.filter_coeff = 0.1;
		
		f_data_struct1.integr_component = 0;
		f_data_struct1.filter_coeff = 0.1;
	};
//-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
//-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
//-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
//-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-