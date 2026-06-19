#include <iostream>
#include <iomanip>
using namespace std;

int TinhPascal(int r, int c) {
	if (c == 0 || c == r) return 1;
	return TinhPascal(r - 1, c - 1) + TinhPascal(r - 1, c);
}

void InMotDong(int r, int c) {
	if (r < c) return;
	cout << setw(4) << TinhPascal(r, c);
	InMotDong(r, c + 1);
}

void XuatPascal(int n, int r_now) {
	if (r_now == n) return;
	InMotDong(r_now, 0);
	cout << endl;
	XuatPascal(n, r_now + 1);
}

int main() {
	int h;
	cout << "Nhap chieu cao cua tam giac Pascal: ";
	cin >> h;

	if (h <= 0) {
		cout << "Chieu cao khong hop le!\n";
		return 0;
	}
	else {
		cout << "Tam giac Pascal voi chieu cao " << h << " la:" << endl;
		XuatPascal(h, 0);
	}
	return 0;
}