#include <iostream>
#include <ctime>
using namespace std;
const int MAXR = 100, MAXC = 100;

void taoMangNgauNhien(int a[][MAXC], int r, int c) {
	for (int i = 0;i < r;i++)
		for (int j = 0;j < c;j++)
			a[i][j] = rand() % (100 - 1 + 1) + 1; //rand() % (max - min + 1) + min ==> tu min toi max
}

void xuatMang(int a[][MAXC], int r, int c) {
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++)
			cout << a[i][j] << "\t";
		cout << endl;
	}
}

int tinhTong(int a[][MAXC], int r, int c) {
	int tong = 0;
	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++)
			tong += a[i][j];
	return tong;
}

int main() {
	int a[MAXR][MAXC];
	srand(time(0));
	
	
	int r, c;
	cout << "Nhap r: "; cin >> r;
	cout << "Nhap c: "; cin >> c;

	int tong = 0;
	do {
		taoMangNgauNhien(a, r, c);
		tong = tinhTong(a, r, c);
	} while (tong != 200);

	cout << "Mang dang luu tru la:\n";
	xuatMang(a, r, c);

	cout << "Tong mang = " << tinhTong(a, r, c);

	return 0;
}