#include<iostream>
#include"Car.h"
#include"Save_File.h"
#include"Controller.h"
using namespace std;

int main() {
	Save_File Save;
	Car car;
	Controller controller(car);
	car.sort_inputCode();
	car.FileMSCN(Save);
	car.displayComparisonArr();
	controller.setting_speedrange(Save);

}
