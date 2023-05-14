#include "Controller.h"

bool Controller::checkInteger(string str) {
	for (int i = 0; i < str.size(); i++) {
		if (isdigit(str.at(i)) == false) {
			return false;
		}
	}
	return true;
}
void Controller::gearScreen() {
	string choice = "";
	int select = 0;
	bool valid = true;
	do
	{
		if (!valid) {
			system("cls");
			cout << "Nhap sai! Yeu cau lua chon cac so tu 1 -> 5" << endl;
		}
		cout << "XIN MOI LUA CHON TAY SO: " << endl;
		cout << "1.P" << endl;
		cout << "2.R" << endl;
		cout << "3.N" << endl;
		cout << "4.D" << endl;
		cout << "5. POWVER OFF" << endl;
		cout << ">> ";
		getline(cin, choice);
		system("cls");
		if (checkInteger(choice) == false || choice.size() != 1) {

			cout << "Nhap sai! Yeu cau lua chon cac so tu 1 -> 5" << endl;
		}
		else
		{
			select = stoi(choice);
			if (select < 1 || select > 5) {
				valid = false;
			}
			else {
				valid = true;
			}
		}
	} while (!valid);

	system("cls");

	switch (select)
	{
	case MODE_P:
	case MODE_N:
		mode = select;
		handle_PN(mode);
		break;
	case MODE_D:
	case MODE_R:
		mode = select;
		handle_DR(mode);
		break;
	case MODE_OFF:
		cout << "XE DA DUNG HOAT DONG." << endl;
		cout << "CHAO TAM BIET" << endl;
		break;
	}
}

void Controller::handle_PN(int mod) {
	if (speed != 0) {
		cout << "HAY CHAC CHAN XE CUA BAN DA DUNG VA TOC DO LA 0KM/H" << endl;
	}
	else {
		cout << "DA CHUYEN VE TAY SO " << (mod == MODE_N ? "N" : "P") << endl;
		tranferGear = true;
	}
	gearScreen();
}

void Controller::handle_DR(int mod) {
	if (speed == 0) {
		cout << "DA CHUYEN VE TAY SO " << (mod == MODE_D ? "D" : "R") << endl;
		if (tranferGear == true) {
			speed = 7;
		}
		convert_DR = mod;
		tranferGear = false;
	}
	else {
		if (mod != convert_DR) {
			cout << "MUON CHUYEN VE TAY SO " << (mod == MODE_D ? "D" : "R")
				<< " VUI LONG DUA VAN TOC VE 0 KM / H" << endl;
			mode = convert_DR;
		}
		else {
			cout << "---- TOC DO HIEN TAI: " << speed << "Km/h" << endl;
			speedWarning(convert_DR);
		}
	}
	speedScreen();
}

void Controller::speedScreen() {
	string choice;
	int select;
	bool valid = true;
	do
	{
		cout << "MOI LUA CHON: " << endl;
		cout << "1. TANG TOC " << endl;
		cout << "2. GIAM TOC " << endl;
		cout << "3. PHANH " << endl;
		cout << "4. TRO VE LUA CHON TAY SO " << endl;
		cout << ">> ";
		getline(cin, choice);
		system("cls");
		if (checkInteger(choice) == false || choice.size() != 1) {
			cout << "Nhap Sai! Vui Long Nhap Cac So Tu 1 - > 4" << endl;
		}
		else {
			select = stoi(choice);
			if (select < 1 || select > 4) {
				cout << "Nhap Sai! Vui Long Nhap Cac So Tu 1 - > 4" << endl;
				valid = false;
			}
			else {
				valid = true;
			}
		}

	} while (!valid);
	system("cls");

	switch (select) {
	case TANG_TOC:
		acceleration();
		speedScreen();
		break;

	case GIAM_TOC:
		deceleration();
		speedScreen();
		break;
	case PHANH:
		speed = 0;
		cout << "---- TOC DO HIEN TAI: " << speed << "Km/h" << endl;
		cout << "BAN CO THE CHUYEN TAY SO KHAC." << endl;
		speedScreen();
		break;
	case TRO_VE:
		gearScreen();
		break;
	}

}

void Controller::acceleration() {
	speed += 5;
	cout << "---- TOC DO HIEN TAI: " << speed << "Km/h" << endl;
	speedWarning(mode);
}
void Controller::deceleration() {
	speed -= 5;
	cout << "---- TOC DO HIEN TAI: " << speed << "Km/h" << endl;
	speedWarning(mode);
}

void Controller::speedWarning(short warning) {
	car->get_changeSpeed(changeSpeed);
	if (speed <= min(changeSpeed[0], changeSpeed[2])) {
		cout << "BAN CHU Y GIU KHOANG CACH TOI THIEU LA 20m" << endl;
	}
	else if (speed >= max(changeSpeed[0], changeSpeed[2])) {
		cout << "BAN CHU Y GIU KHOANG CACH TOI THIEU LA 100m" << endl;
	}
	else if (speed >= changeSpeed[1] && speed <= changeSpeed[2]) {
		cout << "BAN CHU Y GIU KHOANG CACH TOI THIEU LA 70m" << endl;
	}
	else {
		cout << "BAN CHU Y GIU KHOANG CACH TOI THIEU LA 55m" << endl;
	};
	if (warning == MODE_D) {
		if (speed > 60) {
			cout << "TOC DO NGUY HIEM, BAN NEN GIAM TOC DO" << endl;
		}
	}
	if (warning == MODE_R) {
		if (speed > 20) {
			cout << "TOC DO NGUY HIEM, BAN NEN GIAM TOC DO" << endl;
		}
	}

}

void Controller::setting_speedrange(Save_File& save_file) {
	if (car->cmp_arr() == false) {
		cout << "BAN DA NHAP SAI. TAM BIET BAN";
	}
	else {
		cout << "BAN DA NHAP DUNG. MOI BAN CAI DAT: " << endl;
		car->FileVanToc(save_file);
		car->GhiFile("ASM04.txt", save_file);
		gearScreen();
	}
}