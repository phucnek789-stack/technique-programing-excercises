#include <iostream>
using namespace std;

int soDaoNguoc(int n, int kq = 0) {
	if (n == 0) return kq;
	return soDaoNguoc(n / 10, kq * 10 + n % 10);
}

int main() {
	int n;
	do {
		cout << "Nhap so nguyen n: ";
		cin >> n;
		if (n < 0)
			cout << "Moi nhap so nguyen duong!\n";
	} while (n < 0);

	cout << "So sau khi dao nguoc la: " << soDaoNguoc(n) << endl;
	return 0;
}