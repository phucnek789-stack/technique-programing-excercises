#include <iostream>
#include <string>
using namespace std;

struct NhanVien {
	string maNV;
	string hoTen;
	int namVaoLam;
	int namSinh;
};

void nhapThongTin(NhanVien& nv) {
	cout << "Nhap ma nhan vien: ";
	getline(cin, nv.maNV);
	cout << "Nhap ho ten: ";
	getline(cin, nv.hoTen);
	cout << "Nam lam: ";
	cin >> nv.namVaoLam;
	cout << "Nam sinh: ";
	cin >> nv.namSinh;
	cin.ignore();
}

void xuatThongTin(NhanVien nv) {
	cout << "Thong tin cua nhan vien: "
		<< "\nMa nhan vien: " << nv.maNV
		<< "\nHo va ten: " << nv.hoTen
		<< "\nNam vao lam: " << nv.namVaoLam 
		<< "\nNam sinh cua nhan vien: " << nv.namSinh
		<< endl;
}

int tinhTuoi(NhanVien nv, int namHienTai) {
	return namHienTai - nv.namSinh;
}

int tinhThamNien(NhanVien nv, int namHienTai) {
	return namHienTai - nv.namVaoLam;
}

int main() {
	NhanVien nv;
	nhapThongTin(nv);
	xuatThongTin(nv);

	int namHienTai;
	cout << "Nhap nam hien tai: ";
	cin >> namHienTai;

	cout << "Tuoi cua nhan vien: " << tinhTuoi(nv, namHienTai) << endl;
	cout << "Tham nien cua nhan vien: " << tinhThamNien(nv, namHienTai) << endl;
	
	return 0;
}