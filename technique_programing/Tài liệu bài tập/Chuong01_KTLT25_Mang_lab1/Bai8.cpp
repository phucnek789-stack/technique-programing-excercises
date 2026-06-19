#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

const int MAX = 10;
int a[MAX][MAX];
int b[MAX][MAX];
int tong[MAX][MAX];
int tich[MAX][MAX];

//Tao ma tran A
void taoMTNgauNhienA(int &n) {
	for (int i = 0;i < n;i++)
		for (int j = 0;j < n;j++)
			a[i][j] = rand() % 10 + 1;
	cout << "Tao ma tran ngau nhien A thanh cong!\n";
}
void xuatMTA(int n) {
	cout << "Xuat ma tran A:\n";
	for (int i = 0;i < n;i++) {
		for (int j = 0;j < n;j++)
			cout << a[i][j] << "\t";
		cout << endl;
	}		
}

// Tao ma tran B
void taoMTNgauNhienB(int& n) {
	for (int i = 0;i < n;i++)
		for (int j = 0;j < n;j++)
			b[i][j] = rand() % 10 + 1;
	cout << "Tao ma tran ngau nhien B thanh cong!\n";
}
void xuatMTB(int n) {
	cout << "Xuat ma tran B:\n";
	for (int i = 0;i < n;i++) {
		for (int j = 0;j < n;j++)
			cout << b[i][j] << "\t";
		cout << endl;
	}
}

void tinhTong(int n) {
	cout << "Tong cua 2 ma tran vuong cap " << n << " la:\n";
	for (int i = 0;i < n;i++) {
		for (int j = 0;j < n;j++) {
			tong[i][j] = a[i][j] + b[i][j];
			cout << tong[i][j] << "\t";
		}
		cout << endl;
	}
}

void tinhTich(int n) {
	cout << "Tich cua 2 ma tran vuong cap "<<n<<"la:\n";
	for (int i = 0;i < n;i++) {
		for (int j = 0;j < n;j++) {
			tich[i][j] = 0;
			for (int k = 0;k < n;k++)
				tich[i][j] += a[i][k] * b[k][j];
			cout << tich[i][j] << "\t";
		}
		cout << endl;
	}
}

int main() {
	int n;
	cout << "Nhap cap cho ma tran (nxn): ";
	cin >> n;

	taoMTNgauNhienA(n);
	xuatMTA(n);

	taoMTNgauNhienB(n);
	xuatMTB(n);

	tinhTong(n);

	tinhTich(n);

	return 0;
}