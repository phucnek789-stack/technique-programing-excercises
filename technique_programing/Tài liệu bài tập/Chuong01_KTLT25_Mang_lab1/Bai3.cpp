#include <iostream>
using namespace std;

const int MAXR = 10, MAXC = 15;

//================ NHAP MA TRAN ================
void nhapMaTran(int a[][MAXC], int& r, int& c) {
	do {
		cout << "Nhap so hang: ";
		cin >> r;
		cout << "Nhap so cot: ";
		cin >> c;
		if (r < 1 || r > MAXR || c < 1 || c > MAXC)
			cout << "Thao tac sai! Moi nhap lai!\n";
	} while (r < 1 || r > MAXR || c < 1 || c > MAXC);

	for (int i = 0; i < r; i++) {
		cout << "Nhap " << c << " phan tu cho dong thu " << i + 1 << ": ";
		for (int j = 0; j < c; j++)
			cin >> a[i][j];
	}
}

//================ XUAT MA TRAN ================
void xuatMaTran(int a[][MAXC], int r, int c) {
	cout << "Xuat mang dang luu tru la:\n";
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++)
			cout << a[i][j] << "\t";
		cout << endl;
	}
}

//================ TINH TONG ================
int tinhTong(int a[][MAXC], int r, int c) {
	int tong = 0;
	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++)
			tong += a[i][j];
	return tong;
}

//================ TIM MIN ================
void timMin(int a[][MAXC], int r, int c, int& min, int& hangMin, int& cotMin) {
	min = a[0][0];
	hangMin = 0;
	cotMin = 0;

	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++)
			if (min > a[i][j]) {
				min = a[i][j];
				hangMin = i;
				cotMin = j;
			}
}

//================ TIM MAX ================
void timMax(int a[][MAXC], int r, int c, int& max, int& hangMax, int& cotMax) {
	max = a[0][0];
	hangMax = 0;
	cotMax = 0;

	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++)
			if (max < a[i][j]) {
				max = a[i][j];
				hangMax = i;
				cotMax = j;
			}
}

//================ MAIN ================
int main() {
	int a[MAXR][MAXC];
	int r, c;

	nhapMaTran(a, r, c);
	xuatMaTran(a, r, c);

	cout << "Tong cua mang la: " << tinhTong(a, r, c) << endl;

	int min, hangMin, cotMin;
	timMin(a, r, c, min, hangMin, cotMin);
	cout << "Gia tri nho nhat la: " << min
		<< " nam o hang " << hangMin
		<< " cot " << cotMin << endl;

	int max, hangMax, cotMax;
	timMax(a, r, c, max, hangMax, cotMax);
	cout << "Gia tri lon nhat la: " << max
		<< " nam o hang " << hangMax
		<< " cot " << cotMax << endl;

	return 0;
}