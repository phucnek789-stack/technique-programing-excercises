#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
using namespace std;

ifstream fin;
ofstream fout;

//cau a
struct HocSinh {
	string hoTen, ngaySinh, queQuan;
	double toan = 0, van = 0, anh = 0;
};

double tinhDTB(HocSinh hs) {
	return ((hs.toan + hs.van) * 2 + hs.anh) / 5;
}

int tinhTuoi(HocSinh hs) {
	int dauGachCuoi = hs.ngaySinh.rfind("-");
	string namSinh = hs.ngaySinh.substr(dauGachCuoi + 1);
	int ns = stoi(namSinh);
	time_t hienTai = time(0);
	tm* ntn = localtime(&hienTai);
	int namHienTai = ntn->tm_year + 1900;
	return namHienTai - ns;
}

void nhapHS(HocSinh& hs) {
	cout << "Nhap ho ten hoc sinh: ";
	getline(cin, hs.hoTen);
	cout << "Nhap ngay sinh (DD-MM-YYYY): ";
	getline(cin, hs.ngaySinh);
	cout << "Nhap que quan: ";
	getline(cin, hs.queQuan);
	cout << "Nhap lan luot ba diem Toan, Van, Anh: ";
	cin >> hs.toan >> hs.van >> hs.anh;
	cin.ignore();
}

void xuatHS(HocSinh hs) {
	cout << "Ho ten hoc sinh: " << hs.hoTen << endl;
	cout << "Ngay sinh: " << hs.ngaySinh << endl;
	cout << "Que quan: " << hs.queQuan << endl;
	cout << "Diem Toan: " << hs.toan << endl;
	cout << "Diem Van: " << hs.van << endl;
	cout << "Diem Anh: " << hs.anh << endl;
	cout << "Diem trung binh: " << tinhDTB(hs) << endl;
	cout << "Tuoi cua hoc sinh: " << tinhTuoi(hs) << endl;
}

void xuatDS(HocSinh* hs, int n) {
	for (int i = 0;i < n;i++) {
		cout << "\n -----HOC SINH THU " << i + 1 << "----- \n";
		xuatHS(hs[i]);
	}
}

//cau c
void docFile(HocSinh* hs, int& n) {
	fin.open("HocSinh.txt");
	if (fin.is_open()) {
		n = 0;
		while (n < 50 && getline(fin, hs[n].hoTen, ';')) {
			fin.ignore();
			getline(fin, hs[n].ngaySinh, ';');
			fin.ignore();
			getline(fin, hs[n].queQuan, ';');
			fin.ignore();
			fin >> hs[n].toan;
			fin.ignore();
			fin >> hs[n].van;
			fin.ignore();
			fin >> hs[n].anh;
			fin.ignore();
			n++;
		}
		fin.close();
		cout << "Mo file HocSinh de doc thanh cong!\n";
	}
	else
		cout << "Mo file HocSinh de doc that bai!\n";
}

//cau d
void ghiFile(HocSinh* hs, int n) {
	fout.open("HocSinh.txt");
	if (fout.is_open()) {
		for (int i = 0;i < n;i++) {
			fout << hs[i].hoTen << "; "
				<< hs[i].ngaySinh << "; "
				<< hs[i].queQuan << "; "
				<< hs[i].toan << "; "
				<< hs[i].van << "; "
				<< hs[i].anh << endl;
		}
		fout.close();
		cout << "Mo file HocSinh de ghi thanh cong!\n";
	}
	else
		cout << "Mo file HocSinh de ghi that bai!\n";
}

void themHSMoi(HocSinh* hs, int& n) {
	if (n < 50) {
		HocSinh st;
		nhapHS(st);
		hs[n] = st;
		n++;
		ghiFile(hs, n);
	}
	else
		cout << "Lop da day!\n";
}

//cau e
void hamXuatHoTran(HocSinh* hs, int n) {
	string s = "Tran";
	bool found = false;

	for (int i = 0;i < n;i++) {
		if (hs[i].hoTen.find(s) == 0) {
			cout << "\n -----DANH SACH HOC SINH MANG HO [" << s << "]----- \n";
			xuatHS(hs[i]);
			found = true;
		}
	}
	if (!found)
		cout << "Khong tim thay hoc sinh mang ho " << s << endl;
}

//cau f
void sortTangDanDTB(HocSinh* hs, int n) {
	for (int i = 0;i < n - 1;i++)
		for (int j = i + 1;j < n;j++)
			if (tinhDTB(hs[i]) > tinhDTB(hs[j]))
				swap(hs[i], hs[j]);
	ghiFile(hs, n);
	cout << "=> Da sap xep danh sach theo DTB tang dan va cap nhat lai file!\n";
}

int main() {
	HocSinh* hs = new HocSinh[50]; //cau b
	int n = 0;
	int choice;

	docFile(hs, n);

	do {
		cout << "\n================ MENU QUAN LY HOC SINH ================\n";
		cout << "1. Xuat toan bo danh sach hoc sinh hien co\n";
		cout << "2. Nhap va them mot hoc sinh moi (Cap nhat file luu tru)\n";
		cout << "3. In ra toan bo hoc sinh mang ho 'Tran'\n";
		cout << "4. Sap xep danh sach hoc sinh tang dan theo DTB (Cap nhat file)\n";
		cout << "5. Nap lai du lieu tu file HocSinh.txt\n";
		cout << "0. Thoat va giai phong bo nho chuong trinh an toan\n";
		cout << "-------------------------------------------------------\n";
		cout << "Moi ban nhap thao tac lua chon (0-5): ";
		cin >> choice;
		cin.ignore();

		switch (choice) {
		case 1:
			cout << "\n=============== DANH SACH LOP HOC ===============\n";
			xuatDS(hs, n);
			break;
		case 2:
			themHSMoi(hs, n);
			break;
		case 3:
			hamXuatHoTran(hs, n);
			break;
		case 4:
			sortTangDanDTB(hs, n);
			break;
		case 5:
			docFile(hs, n);
			break;
		case 0:
			cout << "\nThoat chuong trinh va luu file hoan tat. Tam biet!\n";
			break;
		default:
			cout << "[Canh bao] Thao tac khong hop le! Vui long chon so tu 0 den 5.\n";
			break;
		}
	} while (choice != 0);

	delete[] hs;
	hs = 0;

	system("pause");
	return 0;
}