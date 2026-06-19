#include <iostream>
using namespace std;

int tongCacSoChan(int n) {
	int temp = n % 10;
	if (n == 0) return 0;
	if (temp % 2 == 0)
		return temp + tongCacSoChan(n / 10);
	else
		return tongCacSoChan(n / 10);
}

int tongCacSoLe(int n) {
	int temp = n % 10;
	if (n == 0) return 0;
	if (temp % 2 != 0)
		return temp + tongCacSoLe(n / 10);
	else
		return tongCacSoLe(n / 10);
}

int main() {
	int n;
	do {
		cout << "Nhap so nguyen n: ";
		cin >> n;
		if (n < 0)
			cout << "Moi nhap so nguyen duong!\n";
	} while (n < 0);

	cout << "Tong cac so chan trong chu so " << n << " la: " << tongCacSoChan(n) << endl;
	cout << "Tong cac so le trong chu so " << n << " la: " << tongCacSoLe(n) << endl;
	return 0;
}