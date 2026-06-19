#include <iostream>
#include <fstream>
#include <string>
using namespace std;

ifstream fin;
ofstream fout;

struct Sach
{
	string tenSach, tenTG;
	int soTrang = 0;
	double giaBan = 0;
};

void docFile(Sach* s, int& n) {
	fin.open("Sach.txt");
	if (fin.is_open()) {
		Sach b;
		while (n < 30 && getline(fin, b.tenSach, ',')) {
			getline(fin, b.tenTG, ',');
			fin >> b.soTrang;
			fin.ignore();
			fin >> b.giaBan;
			fin.ignore(100, '\n');
			s[n++] = b;
		}
		fin.close();
	}
	else
		cout << "Mo file de doc that bai!\n";
}

void xuatSach(Sach s) {
	cout << "Ten sach: " << s.tenSach << endl;
	cout << "Ten tac gia: " << s.tenTG << endl;
	cout << "So trang sach: " << s.soTrang << endl;
	cout << "Gia ban: " << s.giaBan << endl;
}

void XuatDS(Sach* s, int n) {
	for (int i = 0;i < n;i++) {
		cout << "==========CUON SACH THU "<<i+1<<"==========\n";
		xuatSach(s[i]);
	}
}

void inSachTheoGia(Sach* s, int n) {
	double x, y;
	cout << "\nMoi nhap khoang gia tu x den y: ";
	cin >> x >> y;
	cout << "\nDanh sach sach co gia tu " << x << " den " << y << ":" << endl;
	for (int i = 0;i < n;i++) 
		if (s[i].giaBan >= x && s[i].giaBan <= y) 
			cout << s[i].tenSach << " - "
				 << s[i].giaBan << endl;
}

void sapXepSoTrang(Sach* s, int n) {
	for (int i = 0;i < n - 1;i++)
		for (int j = i + 1;j < n;j++)
			if (s[i].soTrang < s[j].soTrang)
				swap(s[i], s[j]);
}

void ghiFile(Sach* s, int n) {
	fout.open("Nguyen.txt", ios::out);
	if (fout.is_open()) {
		for (int i = 0;i < n;i++) 
			if (s[i].tenTG.find("Nguyen") != string::npos) 
				fout << s[i].tenSach << ","
					<< s[i].tenTG << ","
					<< s[i].soTrang << ","
					<< s[i].giaBan << endl;
		fout.close();
		cout << "\nGhi file Nguyen.txt thanh cong!\n";
	}
	else
		cout << "\nGhi file Nguyen.txt that bai\n";
}

int main() {
	Sach* s = new Sach[30];
	int n = 0;

	docFile(s, n);
	XuatDS(s, n);

	inSachTheoGia(s, n);

	cout << "\nDanh sach sau khi sap xep sach theo so trang giam dan:\n";
	sapXepSoTrang(s, n);
	XuatDS(s, n);

	ghiFile(s, n);

	delete[] s;
	s = 0;
	system("pause");
	return 0;
}