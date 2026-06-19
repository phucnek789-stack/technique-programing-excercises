#include <iostream>
using namespace std;

int Tong(int n) {
	if (n == 1) return 1;
	return n + Tong(n - 1);
}

int TongBP(int n) {
	if (n == 1) return 1;
	return n * n + TongBP(n - 1);
}

double TongPS(int n) {
	if (n == 1) return 1;
	return (1.0 / n) + TongPS(n - 2);
}

int GiaiThua(int n) {
	if (n == 0 || n == 1) return 1;
	return n * GiaiThua(n - 1);
}
int TongGiaiThua(int n) {
	if (n == 1) return 1;
	return GiaiThua(n) + TongGiaiThua(n - 1);
}

int main() {
	int n;
	do {
		cout << "Nhap so nguyen bat ki: ";
		cin >> n;
		if (n < 0)
			cout << "Moi nhap so nguyen duong!\n";
	} while (n < 0);

	cout << "Tong cac so nguyen tu 1 den " << n << " = " << Tong(n) << endl;
	cout << "Tong cac so nguyen binh phuong tu 1 den " << n << " = " << TongBP(n) << endl;
	if (n % 2 != 0)
		cout << "Tong cac phan so le 1/" << n << " = " << TongPS(n) << endl;
	else
		cout << "Khong dung yeu cau! Phai nhap cac phan so le!\n";
	cout << "Tong cac so nguyen tu 1! den " << n << "! = " << TongGiaiThua(n) << endl;

	return 0;
}