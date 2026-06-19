#include <iostream>
using namespace std;

char a[13][6];

void taoSoDo() {
	for (int i = 0;i < 13;i++)
		for (int j = 0;j < 6;j++)
			a[i][j] = '*';
}

void inSoDo() {
	cout << "\n\t-----SO DO CHO NGOI-----\n";

	cout << "\t";
	for (int j = 0;j < 6;j++)
		cout << (char)('A' + j) << "\t";
	cout << endl;

	for (int i = 0;i < 13;i++) {
		cout << "Hang " << i + 1;
		if (i < 9) cout << " ";
		cout << "\t";

		for (int j = 0;j < 6;j++) 
			cout << a[i][j] << "\t";
		cout << endl;
	}
	cout << "\t(*: Cho trong | X: Da co nguoi dat)\n";
}

int chuyenDoiCot(char ghe) {
	ghe = toupper(ghe);
	if (ghe >= 'A' && ghe <= 'F')
		return ghe - 'A';
	else
		return -1;
}

void datVe() {
	int loaiVe;
	cout << "\n-----CHON LOAI VE-----\n";
	cout << "1. Thuong gia (hang 1-2)\n";
	cout << "2. Pho thong (hang 3-7)\n";
	cout << "3. Tiet kiem (8-13)\n";
	cout << "Moi chon loai ve: ";
	cin >> loaiVe;

	if (loaiVe < 1 || loaiVe>3) {
		cout << "Loai ve khong hop le!\n";
		return;
	}

	int hang;
	char ghe;

	cout << "Nhap vi tri muon ngoi (vi du: 5 A): ";
	cin >> hang >> ghe;

	int hang_index = hang - 1;
	int cot_index = chuyenDoiCot(ghe);

	if (hang_index < 0 || hang_index >= 13 || cot_index == -1) {
		cout << "Loi: vi tri khong ton tai!\n";
		return;
	}

	bool dungHang = false;
	if (loaiVe == 1 && (hang_index >= 0 && hang_index <= 1)) dungHang = true;
	else if (loaiVe == 2 && (hang_index >= 2 && hang_index <= 6)) dungHang = true;
	else if (loaiVe == 3 && (hang_index >= 7 && hang_index <= 12)) dungHang = true;

	if (!dungHang) {
		cout << "Loi: hang " << hang << " khong thuoc loai ve ban chon!\n";
		return;
	}

	if (a[hang_index][cot_index] == 'X') {
		cout << "Rat tiec ghe " << hang << (char)toupper(ghe) << " da co nguoi dat!\n";
	}
	else {
		a[hang_index][cot_index] = 'X';
		cout << "Da dat ghe " << hang << (char)toupper(ghe) << " thanh cong!\n";
	}
}

int main() {
	taoSoDo();

	int chon;
	do {
		cout << "=====CHUONG TRINH DAT VE MAY BAY=====\n";
		cout << "1. Hien thi so do cho ngoi.\n";
		cout << "2. Dat ve.\n";
		cout << "0. Thoat chuong trinh.\n";
		cout << "Moi chon thao tac: ";
		cin >> chon;

		switch (chon)
		{
		case 1:
			inSoDo();
			break;
		case 2:
			datVe();
			inSoDo();
			break;
		case 0:
			cout << "Thoat chuong trinh thanh cong! cam on ban da su dung dich vu!\n";
			break;
		default:
			cout << "Thao tac khong hop le! Moi chon lai!\n";
			break;
		}
	} while (chon != 0);
	return 0;
}