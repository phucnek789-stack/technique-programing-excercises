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

void docFile(Xe* car, int& n) {
	fin.open("DanhSachXe.txt");
	if (fin.is_open()) {
		string line;
		getline(fin, line); //bo dong dau trong file

		n = 0;
		while (n<20 && fin >> car[n].ID) {
			fin.ignore(1);
			getline(fin, car[n].tenXe, ',');
			getline(fin, car[n].hangXe, ',');
			fin >> car[n].giaBan;
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

void ghiFile(Xe* car, int n) {
	fout.open("BackUpXe.txt");
	if (fout.is_open()) {
		for (int i = 0;i < n;i++) {
			fout << car[i].ID << ", "
				<< car[i].tenXe << ", "
				<< car[i].hangXe << ", "
				<< car[i].giaBan << endl;
		}
		fout.close();
		cout << "Mo file BackUp de ghi thanh cong!\n";
	}
	else {
		cout << "Mo file BackUp de ghi that bai!\n";
		return;
	}
}

void sortGiamDanTheoGia(Xe* car, int n) {
	for (int i = 0;i < n - 1;i++)
		for (int j = i + 1;j < n;j++)
			if (car[i].giaBan < car[j].giaBan)
				swap(car[i], car[j]);
}

void xuatXe(Xe car) {
	cout << "ID xe: " << car.ID << endl;
	cout << "Ten xe: " << car.tenXe << endl;
	cout << "Hang xe: " << car.hangXe << endl;
	cout << "Gia ban: " << car.giaBan << endl;
}

void xuatDSXe(Xe* car, int n) {
	for (int i = 0;i < n;i++) {
		cout << "----------XE THU " << i + 1 << "----------\n";
		xuatXe(car[i]);
	}
}

void timTenXe(Xe* car, int n) {
	string name;
	cout << "\nNhap ten cac xe co chua tu khoa la: ";
	getline(cin, name);

	bool found = false;
	for (int i = 0;i < n;i++) {
		if (car[i].tenXe.find(name) != string::npos) {
			cout << car[i].ID << " - "
				<< car[i].tenXe << " - "
				<< car[i].hangXe << " - "
				<< car[i].giaBan << endl;
			found = true;
		}
	}
	if (!found)
		cout << "Khong tim thay cai ten nao trung khop voi " << name << endl;
}

void SLXeTheoHang(Xe* car, int n) {
	for (int i = 0;i < n;i++) {
		bool daTrung = false;
		for (int j = 0;j < i;j++) 
			if (car[i].hangXe == car[j].hangXe) {
				daTrung = true;
				break;
			}
				
		if (!daTrung) {
			int dem = 0;
			for (int k = i;k < n;k++) 
				if (car[k].hangXe == car[i].hangXe)
					dem++;
			cout << "- Hang " << car[i].hangXe << ": " << dem << " xe.\n";
		}
	}
}

int main() {
	Xe* car = new Xe[20];
	int n = 0;

	docFile(car, n);
	cout << endl;
	ghiFile(car, n);
	cout << endl;

	cout << "Danh sach xe sau khi duoc sap xep giam dan thao gia ban:\n";
	sortGiamDanTheoGia(car, n);
	xuatDSXe(car, n);

	timTenXe(car, n);

	cout << "\nThong ke so luong xe theo tung hang co trong danh sach:\n";
	SLXeTheoHang(car, n);

	delete[] car;
	car = 0;
	system("pause");
	return 0;
}