#include "HW_Robo1.h"
#include "Forms_01.h"
#include "HW_Internal_STM32F429.h"
//#define asdwe = 0x01//������� ��������� ������
//--------------------------
	typedef struct{
		uint8_t E_ID;
		uint8_t Tobj1_Min; // ����������� ����������� - ���������� �������
		uint8_t Tobj1_Max; // ������������ ���������� - ���������� �������
		uint8_t Tobj1_Min_Stat; // 0 - �� ���������, 1 - ���������; � �����������, ��� ������, ���������
		uint8_t Tobj1_Max_Stat; // 0 - �� ���������, 1 - ���������; � �����������, ��� ������, ���������
		uint8_t Tobj1_Max_ch;// ������ ��������� � �������� ����
		
	}E_T_sensor_data;
//--------------------------
	typedef struct{
		uint8_t E_ID;
		uint8_t E_Door1;// 0 - �� ���������, 1 - ���������; � �����������, ��� ������, ���������
		uint8_t E_Door2;// 0 - �� ���������, 1 - ���������; � �����������, ��� ������, ���������
		uint8_t E_Door3;// 0 - �� ���������, 1 - ���������; � �����������, ��� ������, ���������
	}E_Mech_sensor_data;
//--------------------------
	typedef struct{
		uint8_t E_ID;
		uint8_t E_tim1;// 0 - �� ���������, 1 - ���������; ����� ��� ������ ��������
		uint8_t E_tim2;// 0 - �� ���������, 1 - ���������; ����� ��� ���������� ��������
		uint8_t E_tim3;// 0 - �� ���������, 1 - ���������; ����� ��� ...
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