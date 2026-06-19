#include <iostream>
using namespace std;
const int MAX = 10;

void TaoMang(int a[MAX], int n) {
	for (int i = 0;i < n;i++) {
		cout << "Nhap a[" << i << "]: ";
		cin >> a[i];
	}
}

void XuatMang(int a[MAX], int n) {
	cout << "Mang vua tao la:\n";
	for (int i = 0;i < n;i++)
		cout << a[i] << "\t";
	cout << endl;
}

int FindMin(int a[MAX], int n) {
	if (n == 0) return 0;
	if (n == 1) return a[0];
	int min = FindMin(a, n - 1);
	return a[n - 1] < min ? a[n - 1] : min;
}

int main() {
	int a[MAX];
	int n;
	do {
		cout << "Nhap so luong phan tu: ";
		cin >> n;
		if (n < 0)
			cout << "Thao tac khong hop le!\n";
	} while (n < 0);
	TaoMang(a, n);
	XuatMang(a, n);
	
	cout << "Gia tri nho nhat trong mang la: " << FindMin(a, n);
	return 0;
}