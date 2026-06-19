#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <ctime>
#include <iomanip>
using namespace std;

const int MAX = 100;

void input(int a[][MAX], int& r, int& c) {
	cout << "Nhap so hang: "; cin >> r;
	cout << "Nhap so cot: "; cin >> c;
	if (r<0 || r>MAX || c < 0 || c > MAX) {
		cout << "Thao tac khong hop le! Vui long nhap lai!\n";
		return;
	}
	for (int i = 0;i < r;i++) {
		cout << "Nhap " << c << " phan tu cho dong thu " << i + 1 << ": ";
		for (int j = 0;j < c;j++)
			cin >> a[i][j];
	}
}

void output(int a[][MAX], int r, int c) {
	for (int i = 0;i < r;i++) {
		for (int j = 0;j < c;j++)
			cout<< a[i][j]<<" ";
		cout << endl;
	}
}

void initRand(int a[][MAX], int& r, int& c) {
	int x, y;
	cout << "\nNhap khoang gia tri ngau nhien [x, y]: ";
	cin >> x >> y;

	for (int i = 0;i < r;i++)
		for (int j = 0;j < c;j++)
			a[i][j] = rand() % (y - x + 1) + x;
}

void tichTungCot(int a[][MAX], int r, int c) {
	for (int j = 0;j < c;j++) {
		int tich = 1;
		for (int i = 0;i < r;i++) 
			tich *= a[i][j];
		cout << "- Cot thu " << j + 1 << " co tich: " << tich << endl;
	}
}

void TBCTungHang(int a[][MAX], int r, int c) {
	for (int i = 0;i < r;i++) {
		int tong = 0;
		for (int j = 0;j < c;j++)
			tong += a[i][j];
		cout << "- TBC hang thu " << i + 1 << ": " <<(double) tong / c << endl;
	}
}

void timMaxTungHang(int a[][MAX], int r, int c) {
	for (int i = 0;i < r;i++) {
		int maxR = a[i][0];
		for (int j = 1;j < c;j++)
			if (a[i][j] > maxR) {
				maxR = a[i][j];
			}
		cout << "Gia tri lon nhat cua hang " << i + 1 << " la: " << maxR << endl;
	}
		
}

void timX(int a[][MAX], int r, int c) {
	int x;
	cout << "\nNhap gia tri can tim: ";
	cin >> x;
	bool found = false;
	for (int i = 0;i < r;i++) 
		for (int j = 0;j < c;j++)
			if (a[i][j] == x) {
				cout << "Da tim thay gia tri " << x << endl;
				found = true;
				break;
			}
	if (!found) cout << "Gia tri " << x << " khong ton tai trong mang!\n";
}

void tangDanTheoHang(int a[][MAX], int c) {
	int iChoose;
	cout << "\nNhap hang can sap xep: ";
	cin >> iChoose;
	 
	for (int j = 0;j < c - 1;j++) 
		for (int k = j + 1;k < c;k++) 
			if (a[iChoose][j] > a[iChoose][k]) {
				int temp = a[iChoose][j];
				a[iChoose][j] = a[iChoose][k];
				a[iChoose][k] = temp;
			}
	cout << "Da sap xep xong hang " << iChoose;
}

int main() {
	srand(time(0));
	int a[MAX][MAX];
	int r, c;

	input(a, r, c);
	cout << "\nMang dang luu tru la:\n";
	output(a, r, c);

	initRand(a, r, c);
	cout << "Mang ngau nhien:\n";
	output(a, r, c);

	cout << "\nTich cua tung cot:\n";
	tichTungCot(a, r, c);

	cout << "\nTrung binh cong cua tung hang:\n";
	TBCTungHang(a, r, c);

	cout << "\nTim max cua tung hang:\n";
	timMaxTungHang(a, r, c);

	timX(a, r, c);

	tangDanTheoHang(a, c);
	cout << "\nMang sau khi da sap xep theo hang:\n";
	output(a, r, c);

	system("pause");
	return 0;
}