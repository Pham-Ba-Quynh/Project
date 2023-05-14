#include "Car.h"
void Car::get_inputCode(int arr[]) {
	for (int i = 0; i < 8; i++) {
		arr[i] = g_inputCode[i];
	}
}
void Car::get_personalNumber(int arr[]) {
	for (int i = 0; i < 8; i++) {
		arr[i] = g_arrPersonalIdentification[i];
	}
}
void Car::get_changeSpeed(int arr[]) {
	for (int i = 0; i < 3; i++) {
		arr[i] = g_changeSpeed[i];
	}
}

//Select_InputCode
void Car::sort_inputCode() {
	string arr;
	cout << "NHAP MA SO CA NHAN, MANG 08 SO" << endl;
	for (int i = 0; i < 8; i++) {
		cout << "SO THU " << i + 1 << ": ";
		do
		{
			getline(cin, arr);
			if (!checkInteger(arr) || arr.size() == 0) {
				cout << "Nhap sai vui long nhap lai so thu " << i + 1 << " : ";
			}
		} while (!checkInteger(arr) || arr.size() == 0);
		g_inputCode[i] = stoi(arr);
	};
	system("cls");
}
void Car::swap_inputCode() {
	int i, j;
	bool haveSwap = false;
	for (i = 0; i < 7; i++) {
		// i phần tử cuối cùng đã được sắp xếp
		haveSwap = false;
		for (j = 0; j < 7 - i; j++) {
			if (g_inputCode[j] > g_inputCode[j + 1]) {
				swap(g_inputCode[j], g_inputCode[j + 1]);
				haveSwap = true; // Kiểm tra lần lặp này có swap không
			}
		}
		// Nếu không có swap nào được thực hiện => mảng đã sắp xếp. Không cần lặp thêm
		if (!haveSwap) {
			break;
		}
	}
}

//Buble_ArrayPersonal
void Car::sort_personalIdentification() {
	string arr;
	cout << "MA SO CA NHAN: " << endl;
	for (int i = 0; i < 8; i++) {
		cout << "SO THU " << i + 1 << ": ";
		do
		{
			getline(cin, arr);
			if (checkInteger(arr) == false || arr.size() == 0) {
				cout << "MA SO CA NHAN GOM 8 SO NGUYEN." << endl << "VUI LONG CAI DAT LAI SO THU " << i + 1 << " : ";
			}
		} while (checkInteger(arr) == false || arr.size() == 0);
		g_arrPersonalIdentification[i] = stoi(arr);
	};
	system("cls");
}
void Car::swap_personalIdentification()
{
	int i, j;
	// Di chuyển ranh giới của mảng đã sắp xếp và chưa sắp xếp
	for (i = 0; i < 8; i++)
	{
		// Tìm phần tử nhỏ nhất trong mảng chưa sắp xếp
		for (j = i + 1; j < 8; j++)
			if (g_arrPersonalIdentification[j] < g_arrPersonalIdentification[i])
				// Đổi chỗ phần tử nhỏ nhất với phần tử đầu tiên
				swap(g_arrPersonalIdentification[j], g_arrPersonalIdentification[i]);
	}
}
void Car::printArr(int arr[], int n) {
	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
}

//Compairing
bool Car::cmp_arr() {
	for (int i = 0; i < 8; i++) {
		if (g_inputCode[i] != g_arrPersonalIdentification[i]) {
			return false;
		}
	}
	return true;
}
void Car::displayComparisonArr() {
	cout << "MANG NHAP VAO TRUOC KHI XAP XEP: ";
	printArr(g_inputCode, 8);

	cout << endl << "---> MANG NHAP VAO SAU KHI SAP XEP: ";
	swap_inputCode();
	printArr(g_inputCode, 8);

	cout << endl << "MA SO CA NHAN TRUOC KHI SAP XEP: ";
	printArr(g_arrPersonalIdentification, 8);

	cout << endl << "---> MA SO CA NHAN SAU KHI SAP XEP: ";
	swap_personalIdentification();
	printArr(g_arrPersonalIdentification, 8);
	cout << endl;
}

// Setting speed range
void Car::speedRange() {
	string arr;
	cout << "CAI DAT VAN TOC CANH BAO KHOANG CACH AN TOAN VOI 3 MUC TOC DO" << endl;

	for (int i = 0; i < 3; i++) {
		cout << "VAN TOC MUC " << i + 1 << ": ";
		do
		{
			getline(cin, arr);
			if (!checkInteger(arr) || arr.size() == 0) {
				cout << "Cai dat sai vui long nhap lai " << endl;
			}
		} while (!checkInteger(arr) || arr.size() == 0);
		g_changeSpeed[i] = stoi(arr);
	};
	swap_speedRange();
	system("cls");
}
void Car::swap_speedRange() {
	int i, j, min_idx;
	// Di chuyển ranh giới của mảng đã sắp xếp và chưa sắp xếp
	for (i = 0; i < 3; i++)
	{
		// Tìm phần tử nhỏ nhất trong mảng chưa sắp xếp
		int min_idx = i;
		for (j = i + 1; j < 3; j++)
			if (g_changeSpeed[j] < g_changeSpeed[min_idx])
				min_idx = j;

		// Đổi chỗ phần tử nhỏ nhất với phần tử đầu tiên
		swap(g_changeSpeed[min_idx], g_changeSpeed[i]);
	}
}
bool Car::checkInteger(string str) {
	for (int i = 0; i < str.size(); i++) {
		if (isdigit(str.at(i)) == false) {
			return false;
		}
	}
	return true;
}

void Car::GhiFile(string tenfile, Save_File & save_file) {
	ofstream outfile;
	outfile.open(tenfile, ios::out);
	if (outfile.fail()) {
		cout << "Khong the mo file!";
		return;
	}
	//for (int i = 0; i < n; i++) {
		outfile.write(reinterpret_cast<const char*>(&save_file), sizeof(save_file));
	//}
	outfile.close();
}

void Car::DocFile(string tenFile, Save_File& save_file) {
	ifstream inFile;
	inFile.open(tenFile, ios::in);
	if (inFile.fail()) {
		cout << "DU LIEU KHONG CO SAN. ";
		so = false;
		return;
	}
	while (!inFile.eof()) {
		inFile.read(reinterpret_cast<char*>(&save_file), sizeof(save_file));
	}
	inFile.close();
}

void Car::FileMSCN(Save_File& save_file) {
	DocFile("ASM04.txt", save_file);

	if (!so) {
		cout << "NGUOI DUNG CAI DAT DAT MA SO CA NHAN:" << endl;
		sort_personalIdentification();
		save_file.setMSCN(g_arrPersonalIdentification);
		GhiFile("ASM04.txt", save_file);
		so = true;
	}
	else {
		save_file.getMSCN(g_arrPersonalIdentification);
		ThayDoiMSCN(save_file);
	}
}

void Car::ThayDoiMSCN(Save_File& save_file) {
	string choice = "";
	int select = 0;
	bool valid = true;
	do {
		cout << "MA SO CA NHAN DA CO SAN. BAN CO MUON THAY DOI KHONG ?" << endl;
		cout << "1. CO" << endl;
		cout << "2. KHONG" << endl;
		cout << "Lua chon 1 hoac 2: ";
		getline(cin, choice);

		if (checkInteger(choice) == false || choice.size() != 1) {
			cout << "Chon sai! Yeu cau chon lai." << endl;
			valid = false;
		}
		else {
			select = stoi(choice);
			if (select < 1 || select > 2) {
				cout << "Chon sai! Yeu cau chon lai." << endl;
				valid = false;
			}
			else {
				valid = true;
			}
		}
	} while (valid == false);
	system("cls");

	switch (select) {
	case(YES):
		sort_personalIdentification();
		save_file.setMSCN(g_arrPersonalIdentification);
		GhiFile("ASM04.txt", save_file);
		break;

	case(NO):
		break;

	}
}

void Car::FileVanToc(Save_File& save_file) {
	DocFile("ASM04.txt",save_file);

	if (!so) {
		cout << "NGUOI DUNG CAI DAT DAT MUC VAN TOC AN TOAN:" << endl;
		speedRange();
		save_file.setRANGED(g_changeSpeed);
		GhiFile("ASM04.txt", save_file);
	}
	else {
		save_file.get_RANGED(g_changeSpeed);
		ThayDoiVT(save_file);
	}
}

void Car::ThayDoiVT(Save_File& save_file) {
	string choice = "";
	int select = 0;
	bool valid = true;
	do {
		cout << "MUC VAN TOC CANH BAO AN TOAN DA CO SAN. BAN CO MUON THAY DOI KHONG ?" << endl;
		cout << "1. CO" << endl;
		cout << "2. KHONG" << endl;
		cout << "Lua chon 1 hoac 2: ";
		getline(cin, choice);

		if (checkInteger(choice) == false || choice.size() != 1) {
			cout << "Chon sai! Yeu cau chon lai." << endl;
			valid = false;
		}
		else {
			select = stoi(choice);
			if (select < 1 || select > 2) {
				cout << "Chon sai! Yeu cau chon lai." << endl;
				valid = false;
			}
			else {
				valid = true;
			}
		}
	} while (valid == false);
	system("cls");

	switch (select) {
	case(YES):
		speedRange();
		save_file.setRANGED(g_changeSpeed);
		GhiFile("ASM04.txt", save_file);
		break;
	case(NO):
		break;
	}
}