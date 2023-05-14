#pragma once
#include<iostream>
#include<string>
#include<fstream>
#include"Save_File.h"
using namespace std;
class Car
{
private:
	int g_inputCode[8];
	int g_arrPersonalIdentification[8];
	int g_changeSpeed[3];

	int mscn[8];
	int safe_distance[3];
	bool so = true;
	//Save_File* save_file;
	 
public:
	/*Car(Save_File& savefile_temp) {
		save_file = &savefile_temp;
	}*/
	enum LUA_CHON {
		YES = 1,
		NO = 2,
	};
	//
	

	void get_inputCode(int arr[]);
	void get_personalNumber(int arr[]);
	void get_changeSpeed(int arr[]);
	//
	void sort_inputCode();
	void swap_inputCode();
	//
	void sort_personalIdentification();
	void swap_personalIdentification();
	void printArr(int arr[], int n);
	//
	bool cmp_arr();
	void displayComparisonArr();

	// Setting speed range
	void speedRange();
	void swap_speedRange();
	bool checkInteger(string str);

	///Handle file
	void GhiFile(string tenfile, Save_File& save_file);
	void DocFile(string tenFile, Save_File& save_file);
	void FileMSCN(Save_File& save_file);
	void ThayDoiMSCN(Save_File& save_file);
	void FileVanToc(Save_File& save_file);
	void ThayDoiVT(Save_File& save_file);

	~Car() {}
};

