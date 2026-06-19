#include <iostream>
#include <fstream>
#include <string>
using namespace std;

ifstream fin;
ofstream fout;

struct SinhVien {
	string maSV, hoTen;
	int namSinh;
};

void nhapThongTin(SinhVien& sv) {
	cout << "Nhap ma sinh vien: ";
	getline(cin, sv.maSV);
	cout << "Nhap ho ten sinh vien: ";
	getline(cin, sv.hoTen);
	cout << "Nhap nam sinh: ";
	cin >> sv.namSinh;
	cin.ignore();
}

void nhapDS(SinhVien* sv, int n) {
	for (int i = 0;i < n;i++) {
		cout << "======================================\n";
		nhapThongTin(sv[i]);
	}
}

void xuatThongTin(SinhVien sv) {
	cout << "Ma sinh vien: " << sv.maSV << " | "
		 << "Ho ten sinh vien: " << sv.hoTen << " | "
		 << "Nam sinh: " << sv.namSinh << endl;
}

void xuatDS(SinhVien* sv, int n) {
	cout << endl;
	for (int i = 0;i < n;i++) {
		cout << "===============SINH VIEN THU " << i + 1 << "===============\n";
		xuatThongTin(sv[i]);
	}
}

void ghiFile(SinhVien* sv, int n) {
	fout.open("BT10.txt");
	if (!fout.is_open()) {
		cout << "Khong the mo file BT10.txt de ghi!\n";
		return;
	}
	for (int i = 0;i < n;i++) {
		fout << sv[i].maSV
			<< " - " << sv[i].hoTen 
			<< " - " << sv[i].namSinh << endl;
	}
	fout.close();
}

void docFile(SinhVien* sv, int n) {
	fin.open("BT10.txt");
	if (!fin.is_open()) {
		cout << "Khong the mo file BT10.txt de doc!\n";
		return;
	}
	string id;
	cout << "\nNhap ma sinh vien can tim: ";
	getline(cin, id);

	cout << "======================================\n";
	string line;
	bool found = false;
	while (getline(fin, line)) {
		if (line.find(id) == 0) {
			cout << "Thong tin tim thay trong file: " << line << endl;
			found = true;
			break;
		}
	}
	if (!found) cout << "Khong tim thay id cua sinh vien trong file!\n";
	fin.close();
}

int main() {
	SinhVien* sv = new SinhVien[10];
	int n;
	do {
		cout << "Nhap so luong sinh vien: ";
		cin >> n;
		cin.ignore();
		if (n < 0 || n>10) {
			cout << "Thong tin khong hop le, moi nhap lai!\n";
			return 1;
		}
	} while (n < 0 || n>10);
	
	nhapDS(sv, n);
	xuatDS(sv, n);
	ghiFile(sv, n);
	docFile(sv, n);

	delete[] sv;
	sv = 0;
	return 0;
}