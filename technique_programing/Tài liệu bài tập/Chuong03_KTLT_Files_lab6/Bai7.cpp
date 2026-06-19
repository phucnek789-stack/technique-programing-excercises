#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

ofstream fout;

int main() {
	fout.open("BT7.txt");
	if (!fout.is_open()) {
		cout << "Khong the mo file de ghi!\n";
		return 1;
	}

	double luong;
	cout << "Bat dau nhap he so luong (nhap -1 de dung)\n";
	while (true) {	
		cout << "Nhap he so luong cho nhan vien: ";
		cin >> luong;
		if (luong == -1)
			break;

		fout << fixed << setprecision(2) << luong << endl;
	}

	fout.close();
	return 0;
}