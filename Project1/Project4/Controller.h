#pragma once
#include<iostream>
#include"Car.h"


enum MODE_CAR {
	MODE_P = 1,
	MODE_R,
	MODE_N,
	MODE_D,
	MODE_OFF,
};

enum adjustSpeed
{
	TANG_TOC = 1,
	GIAM_TOC,
	PHANH,
	TRO_VE,
};

class Controller
{
private:
	int g_personalIdentificationNumber;
	short mode;
	short speed = 0;
	bool tranferGear = false;
	short convert_DR;
	int changeSpeed[3];
	Car* car;

public:
	Controller(Car& car_temp)
	{
		car = &car_temp;
	} 
	bool checkInteger(string str);
	void gearScreen();


	void handle_PN(int mod);

	void handle_DR(int mod);

	void speedScreen();

	void acceleration();
	void deceleration();

	void speedWarning(short warning);

	void setting_speedrange(Save_File& save_file);
	~Controller() {}
};

