#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
using namespace std;

ifstream fin;
ofstream fout;

//a. Xd kieu du lieu hs
struct HocSinh {
	string ten;
	string ngaySinh;
	string que;
	double diemToan = 0.0, diemVan = 0.0, diemAnh = 0.0;
};

//Ham tinh diem trung binh
double tinhDTB(HocSinh hs) {
	return ((hs.diemToan + hs.diemVan) * 2 + hs.diemAnh) / 5;
}

//Ham tinh tuoi
int tinhTuoi(HocSinh hs) {
	if (hs.ngaySinh.empty()) return 0;

	int pos = hs.ngaySinh.rfind("-");
	if (pos == string::npos) return 0;

	string namSinh = hs.ngaySinh.substr(pos + 1);

	int ns = stoi(namSinh);

	time_t hienTai = time(0);
	tm* ntn = localtime(&hienTai);
	int namHienTai = ntn->tm_year + 1900;

	return namHienTai - ns;
}

//Ham xuat 1 hs
void xuatHS(HocSinh hs) {
	cout << "Ho ten hs: " << hs.ten << endl;
	cout << "Ngay sinh hs: " << hs.ngaySinh << endl;
	cout << "Que quan hs: " << hs.que << endl;
	cout << "Diem mon Toan - Van - Anh: " << hs.diemToan
		<< " - " << hs.diemVan
		<< " - " << hs.diemAnh << endl
		<< "Diem trung binh: " << tinhDTB(hs) << endl
		<< "Tuoi cua hoc sinh: " << tinhTuoi(hs) << endl;
}
//Ham xuat ds hs
void xuatDS(HocSinh* hs, int n) {
	for (int i = 0; i < n; i++) {
		cout << "==========HOC SINH THU " << i + 1 << "==========\n";
		xuatHS(hs[i]);
	}
}

//c. Ham doc du lieu tu file
void docFile(HocSinh*hs, int& n) {
	fin.open("HocSinh.txt", ios::in);
	if (fin.is_open()) {
		while (true) {
			HocSinh h;

			if (!getline(fin, h.ten, ';')) break;
			if (!getline(fin, h.ngaySinh, ';')) break;
			if (!getline(fin, h.que, ';')) break;

			fin >> h.diemToan;
			fin.ignore();
			fin >> h.diemVan;
			fin.ignore();
			fin >> h.diemAnh;
			fin.ignore();

			hs[n++] = h;
		}
		fin.close();
	}
	else
		cout << "Khong the mo file de doc!\n";
}

//d. Ham nhap thong tin cho hs moi vao cuoi ds
void nhapHS(HocSinh& hs) {
	cout << "====================\n";
	cout << "Nhap ho ten hs: ";
	getline(cin, hs.ten);
	cout << "Nhap ngay sinh: ";
	getline(cin, hs.ngaySinh);
	cout << "Nhap que quan: ";
	getline(cin, hs.que);
	cout << "Nhap diem mon Toan - Van - Anh: ";
	cin >> hs.diemToan >> hs.diemVan >> hs.diemAnh;
	cin.ignore();
}

//Ham ghi du lieu vao file
void ghiFile(HocSinh* hs, int n) {
	fout.open("HocSinh.txt", ios::out);
	if (fout.is_open()) {
		for (int i = 0;i < n;i++) {
			fout << hs[i].ten << ";"
				<< hs[i].ngaySinh << ";"
				<< hs[i].que << ";"
				<< hs[i].diemToan << ";"
				<< hs[i].diemVan << ";"
				<< hs[i].diemAnh << endl;
		}
		fout.close();
	}
	else
		cout << "Mo file de ghi that bai!\n";
}

//Ham them hs
void themHS(HocSinh* hs, int& n) {
	if (n < 50) {
		HocSinh hsMoi;
		nhapHS(hsMoi);
		hs[n++] = hsMoi;
		ghiFile(hs, n);
	}
	else
		cout << "Lop da day!\n";
}

//e. Ham sap xep DTB tang dan
void sapXep(HocSinh* hs, int n) {
	for (int i = 0;i < n - 1;i++) 
		for (int j = i + 1;j < n;j++) 
			if (tinhDTB(hs[i]) > tinhDTB(hs[j]))
				swap(hs[i], hs[j]);
	ghiFile(hs, n);
}

int main() {
	//cau a: nhapHS, xuatHS, tinhDTB, tinhTuoi

	//b. Tao ds cap phat dong va ds co toi da 50 hs
	HocSinh* hs = new HocSinh[50]; 
	int n = 0;

	//cau c
	docFile(hs, n);
	xuatDS(hs, n);

	//cau d
	themHS(hs, n);
	
	//cau e
	sapXep(hs, n);

	delete[] hs;
	hs = NULL;
	system("pause");
	return 0;
}