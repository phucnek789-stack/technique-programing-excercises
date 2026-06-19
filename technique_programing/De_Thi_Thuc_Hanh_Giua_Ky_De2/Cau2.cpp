#include <iostream>
#include <fstream>
#include <string>
using namespace std;

ifstream fin;
ofstream fout;

struct Xe {
	int ID = 0;
	string tenXe, hangXe;
	double giaBan = 0.0;
};

void docFile(Xe* x, int& n) {
	fin.open("DanhSachXe.txt");

	string line;
	getline(fin, line);

	if (fin.is_open()) {
		n = 0;
		while (n<20 && fin >> x[n].ID) {
			fin.ignore(1);
			getline(fin, x[n].tenXe, ',');
			getline(fin, x[n].hangXe, ',');
			fin >> x[n].giaBan;
			fin.ignore(1);
			n++;
		}
		fin.close();
		cout << "Mo file DanhSachXe de doc thanh cong!\n";
	}
	else {
		cout << "Mo file DanhSachXe de doc that bai!\n";
		return;
	}
}

void ghiFile(Xe* x, int n) {
	fout.open("BackUpXe1.txt");

	if (fout.is_open()) {
		for (int i = 0;i < n;i++) {
			fout << x[i].ID << ","
				<< x[i].tenXe << ","
				<< x[i].hangXe << ","
				<< x[i].giaBan << endl;
		}
		fout.close();
		cout << "Mo file BackUpXe1 de ghi thanh cong!\n";
	}
	else {
		cout << "Mo file BackUpXe1 de ghi that bai!\n";
		return;
	}
}

void nhapXeMoi(Xe& x) {
	cout << "==============================\n";
	cout << "Nhap xe moi can them vao file:\n";
	cout << "Nhap ID xe: "; cin >> x.ID;
	cin.ignore();
	cout << "Nhap ten xe: "; getline(cin, x.tenXe);
	cout << "Nhap hang xe: "; getline(cin, x.hangXe);
	cout << "Nhap gia xe: "; cin >> x.giaBan;
	cin.ignore();
}

void themXeMoi(Xe* x, int& n) {
	if (n < 30) {
		nhapXeMoi(x[n]);
		n++;
		ghiFile(x, n);
		cout << "Them xe thanh cong!\n";
	}
	else
		cout << "Danh sach xe da day!\n";
}


void sortTangDanTheoTen(Xe* x, int n) {
	for (int i = 0;i < n - 1;i++)
		for (int j = i + 1;j < n;j++)
			if (x[i].tenXe > x[j].tenXe)
				swap(x[i], x[j]);
}

void xuatXe(Xe x) {
	cout << "ID: " << x.ID << endl;
	cout << "Ten xe: " << x.tenXe << endl;
	cout << "Hang xe: " << x.hangXe << endl;
	cout << "Gia xe: " << x.giaBan << endl;
}

void XuatDSXe(Xe* x, int n) {
	for (int i = 0;i < n;i++) {
		cout << "\n==========XE THU " << i + 1 << "==========\n";
		xuatXe(x[i]);
	}
}

void timXeTrongKhoangGia(Xe* x, int n) {
	int min, max;
	cout << "\nNhap khoang gia de in danh sach xe (vd: 300, 500): ";
	cin >> min >> max;

	for (int i = 0;i < n;i++) {
		if (x[i].giaBan >= min && x[i].giaBan <= max) {
			cout << x[i].ID << " - "
				<< x[i].tenXe << " - "
				<< x[i].hangXe << " - "
				<< x[i].giaBan << endl;
		}
	}
}

void tongGT20LoaiXe(Xe* x, int n) {
	double tong = 0;
	for (int i = 0;i < n;i++) {
		tong += x[i].giaBan;
	}
	cout << tong << endl;;
}

int main() {
	Xe* x = new Xe[30];
	int n = 0;

	docFile(x, n);
	cout << endl;

	themXeMoi(x, n);
	cout << endl;

	cout << "Danh sach sau khi sap xep tang dan theo thu tu alphabet: ";
	sortTangDanTheoTen(x, n);
	XuatDSXe(x, n);

	timXeTrongKhoangGia(x, n);

	cout << "\nTong gia tri cua tat ca 20 loai xe trong danh sach la: ";
	tongGT20LoaiXe(x, n);

	delete[] x;
	x = 0;
	system("pause");
	return 0;
}