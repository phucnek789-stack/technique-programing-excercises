#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

ofstream fout;

struct NTN {
	int ngay, thang, nam;
};

struct SanPham {
	string maSP;
	string tenSP;
	double dongia = 0.0;
	int slTonKho = 0;
	NTN ngaySX = { 1,1,2026 };
};

//b. ham nhap thong tin san pham
void nhapSP(SanPham&sp) {
	cout << "Nhap ma sp: ";
	getline(cin, sp.maSP);
	cout << "Nhap ten sp: ";
	getline(cin, sp.tenSP);
	cout << "Nhap don gia sp: ";
	cin >> sp.dongia;
	cout << "Nhap so luong ton kho: ";
	cin >> sp.slTonKho;
	cout << "Nhap ngay, thang, nam san xuat: ";
	cin >> sp.ngaySX.ngay >> sp.ngaySX.thang >> sp.ngaySX.nam;
	cin.ignore();
}
void nhapCH(SanPham* CuaHang, int sl) {
	for (int i = 0; i < sl; i++) {
		cout << "====================\n";
		nhapSP(CuaHang[i]);
	}
}

//c. Ham xuat danh sach thong tin san pham
void xuatSP(SanPham sp) {
	cout << "Ma sp: " << sp.maSP << endl;
	cout << "Ten sp: " << sp.tenSP << endl;
	cout << "Don gia sp: " << sp.dongia << endl;
	cout << "So luong ton kho: " << sp.slTonKho << endl;
	cout << "Ngay san xuat: " << sp.ngaySX.ngay
		<< "/" << sp.ngaySX.thang
		<< "/" << sp.ngaySX.nam << endl;
}
void xuatCH(SanPham* CuaHang, int sl) {
	for (int i = 0; i < sl; i++) {
		cout << "==========SAN PHAM THU "<<i+1<< "==========\n";
		xuatSP(CuaHang[i]);
	}
}

//d. ham tim kiem ten cac san pham chua ky tu can tim
string ghiThuong(string s) {
	string res = "";
	for (size_t i = 0; i < s.length(); i++) 
		res += tolower(s[i]);
	return res;
}
void timKiem(SanPham* CuaHang, int sl) {
	string s;
	cout << "\nNhap ten (ky tu) cua san pham can tim: ";
	getline(cin, s);
	for (int i = 0; i < sl; i++) {
		string temp = ghiThuong(CuaHang[i].tenSP);
		s = ghiThuong(s);
		if (temp.find(s) != string::npos) {
			cout << "====================\n";
			xuatSP(CuaHang[i]);
		}
	}
}

//e. ham xoa san pham theo ma tuong ung
void xoaSP(SanPham* CuaHang, int& sl) {	
	string ma;
	cout << "\nNhap ma sp can xoa: ";
	getline(cin, ma);

	int vt = -1;
	for (int i = 0; i < sl; i++) 
		if (CuaHang[i].maSP == ma) {
			vt = i;
			break;
		}
	if (vt == -1) {
		cout << "Khong tim thay san pham!\n";
		return;
	}
	for (int i = vt; i < sl - 1; i++)
		CuaHang[i] = CuaHang[i + 1];
	sl--;
}

//f. ham sap xep ds san pham tang dan theo gia
void sapXep(SanPham* CuaHang, int sl) {
	for (int i = 0;i < sl - 1;i++)
		for (int j = i + 1;j < sl;j++)
			if (CuaHang[i].dongia > CuaHang[j].dongia)
				swap(CuaHang[i], CuaHang[j]);
	cout << "\nDa sap xep danh sach san pham theo thu tu don gia tang dan!\n";
}

//g. ham ghi toan bo ds san pham ra file DSSP.txt
void ghiFile(SanPham* CuaHang, int sl) {
	fout.open("DSSP.txt", ios::out);
	if (fout.is_open()) {
		for (int i = 0;i < sl;i++) {
			SanPham sp = CuaHang[i];
			fout << "===========================\n";
			fout << "Ma san pham: " << sp.maSP << endl;
			fout << "Ten san pham: " << sp.tenSP << endl;
			fout << "Don gia san pham: " << sp.dongia << endl;
			fout << "So luong san pham ton kho: "<<sp.slTonKho << endl;
			fout << "Ngay, thang, nam san xuat: "
				<< sp.ngaySX.ngay << "/"
				<< sp.ngaySX.thang << "/"
				<< sp.ngaySX.nam << endl;
		}
	}
}

int main() {
	SanPham*CuaHang = new SanPham[60]; //a. tao cua hang gom nhieu sp bang cap phat dong
	int sl;
	do {
		cout << "Nhap so luong sp: ";
		cin >> sl;
		cin.ignore();
		if (sl < 1 || sl>60)
			cout << "Thao tac khong hop le! Moi nhap lai\n";
	} while (sl < 1 || sl>60);

	nhapCH(CuaHang, sl);
	xuatCH(CuaHang, sl);

	timKiem(CuaHang, sl);

	xoaSP(CuaHang, sl);

	sapXep(CuaHang, sl);
	xuatCH(CuaHang, sl);

	ghiFile(CuaHang, sl);

	delete[] CuaHang;
	CuaHang = 0;
	system("pause");
	return 0;
}