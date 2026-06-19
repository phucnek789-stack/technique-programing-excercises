#include <iostream>
using namespace std;

const int MAXR = 5, MAXC = 6;

int a[MAXR][MAXC];

void nhapMang(int& r, int& c) {
	do {
		cout << "Nhap so hang: ";
		cin >> r;
		cout << "Nhap so cot: ";
		cin >> c;
		if (r<1 || r>MAXR || c<1 || c>MAXC)
			cout << "Thao tac sai! Moi nhap lai!\n";
	} while (r<1 || r>MAXR || c<1 || c>MAXC);

	for (int i = 0;i < r;i++) {
		cout << "Nhap " << c << " phan tu cho dong thu " << i + 1 << ": ";
		for (int j = 0;j < c;j++)
			cin >> a[i][j];
	}
}

void xuatMang(int r, int c) {
	cout << "Xuat mang dang luu tru la:\n";
	for (int i = 0;i < r;i++) {
		for (int j = 0;j < c;j++)
			cout << a[i][j] << "\t";
		cout << endl;
	}
}

int tongHang(int r, int c, int k) {
	int tong = 0;
	for (int j = 0; j < c; j++)
		tong += a[k][j];
	return tong;
}

int timX(int r, int c, int x) {
	int dem = 0;
	cout << "Vi tri xuat hien:\n";
	for (int i = 0;i < r;i++)
		for (int j = 0;j < c;j++)
			if (a[i][j] == x) {
				cout << "a[" << i << "]""[" << j << "]\n";
				dem++;
			}
	return dem;
}

int main() {
	int r, c;
	nhapMang(r, c);
	xuatMang(r, c);

	//Tinh tong cac gia tri cung 1 hang
	int k;
	cout << "\nNhap vi tri hang can tinh tong (tu 1 den "<<r<<"): ";
	cin >> k;

	if (k >= 1 && k <= r) {
		cout << "Tong cua hang thu " << k << " la: " << tongHang(r, c, k - 1) << endl;
	}
	else
		cout << "Khong hop le!\n";
	


	//Kiem tra gia tri x co ton tai trong mang
	int x;
	cout << "\nNhap gia tri can xet: ";
	cin >> x;

	int dem = timX(r, c, x);

	cout << endl;
	if (dem>0) {
		cout << "Gia tri " << x << " co ton tai trong mang!" << endl;
		cout << "Xuat hien " << dem << " lan!\n";
	}
	else
		cout << "gia tri " << x << " khong ton tai trong mang!\n";
	return 0;
}