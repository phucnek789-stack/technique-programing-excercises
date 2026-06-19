#include <iostream>
#include <fstream>
#include <string>
using namespace std;

ifstream fin;
ofstream fout;

struct LinhKien {
	string tenLK, hangSX;
	int soLuong = 0;
	long donGia = 0;
};

void docFile(LinhKien* lk, int& n) {
	fin.open("KhoHang.txt");
	if (fin.is_open()) {
		string line;
		getline(fin, line);

		while (n < 20 && getline(fin, lk[n].tenLK, ',')) {
			getline(fin, lk[n].hangSX, ',');
			fin >> lk[n].soLuong;
			fin.ignore();
			fin >> lk[n].donGia;
			fin.ignore();
			n++;
		}
		fin.close();
		cout << "Mo file KhoHang de doc thanh cong!\n";
	}
	else
		cout << "Mo file KhoHang de doc that bai!\n";
}

void xuatLK(LinhKien lk) {
	cout << "Ten linh kien: " << lk.tenLK << endl;
	cout << "Hang san xuat: " << lk.hangSX << endl;
	cout << "So luong: " << lk.soLuong << endl;
	cout << "Don gia: " << lk.donGia << endl;
}

void xuatDS(LinhKien* lk, int n) {
	for (int i = 0;i < n;i++) {
		cout << "\n -----LINH KIEN THU " << i + 1 << "----- \n";
		xuatLK(lk[i]);
	}
}

void timTheoTen(LinhKien* lk, int n) {
	string ten;
	cout << "Nhap ten linh kien can tim: ";
	getline(cin, ten);

	bool found = false;
	for (int i = 0;i < n;i++) {
		if (lk[i].tenLK.find(ten) != string::npos) {
			cout << "\n -----THONG TIN LINH KIEN----- \n";
			xuatLK(lk[i]);
			found = true;
		}
	}
	if (!found)
		cout << "Khong tim thay linh kien nao co ten " << ten << endl;
}

void tongGTHangHoa(LinhKien* lk, int n) {
	long tong = 0;
	for (int i = 0;i < n;i++) {
		long giaTri = lk[i].soLuong * lk[i].donGia;
		tong += giaTri;
	}
	cout << "\n=============================================\n";
	cout << "Tong gia tri hang hoa trong kho la: " << tong;
	cout << "\n=============================================\n";
}

void lietKeSamSung(LinhKien* lk, int n) {
	bool found = false;
	for (int i = 0;i < n;i++) {
		if (lk[i].hangSX == "Samsung") {
			cout << "-----------------------------\n";
			xuatLK(lk[i]);
			found = true;
		}
	}
	if (!found)
		cout << "Khong ton tai hang Samsung trong danh sach!\n";
}

void ghiFile(LinhKien* lk, int n) {
	fout.open("CanNhap.txt");
	if (fout.is_open()) {
		for (int i = 0;i < n;i++) {
			if (lk[i].soLuong < 5) {
				fout << lk[i].tenLK << ","
					<< lk[i].hangSX << ","
					<< lk[i].soLuong << ","
					<< lk[i].donGia << endl;
			}
		}
		fout.close();
		cout << "Mo file CanNhap de ghi thanh cong!\n";
	}
	else
		cout << "Mo file CanNhap de ghi that bai!\n";
}

int main() {
	LinhKien* lk = new LinhKien[20];
	int n = 0;
	int choice;

	docFile(lk, n);

	do {
		cout << "\n==========MENU LINH KIEN==========\n";
		cout << "1. Xuat danh sach linh kien hien co\n";
		cout << "2. Tim kiem linh kien theo ten\n";
		cout << "3. Tinh tong gia tri hang hoa trong kho (soLuong*donGia)\n";
		cout << "4. Liet ke linh kien cua hang 'SamSung'\n";
		cout << "0. Thoat\n";
		cout << "Nhap tao tac: ";
		cin >> choice;
		cin.ignore();

		switch (choice)
		{
		case 1:
			xuatDS(lk, n);
			break;
		case 2:
			timTheoTen(lk, n);
			break;
		case 3:
			tongGTHangHoa(lk, n);
			break;
		case 4:
			cout << "\n -----CAC SAN PHAM THUOC HANG SAMSUNG----- \n";
			lietKeSamSung(lk, n);
			break;
		case 0:	
			cout << endl;
			ghiFile(lk, n);
			cout << "Thoat chuong trinh thanh cong!\n";
			break;
		default:
			cout << "Thao tac khong hop le!\n";
			break;
		}
	} while (choice != 0);

	delete[] lk;
	lk = NULL;

	system("pause");
	return 0;
}