#include <iostream>
using namespace std;

int GiaiThua(int n) {
	if (n == 0 || n == 1) return 1;
	return n * GiaiThua(n - 1);
}

int main() {
	int n;
	do {
		cout << "Nhap so nguyen n: ";
		cin >> n;
		if (n < 0)
			cout << "Moi nhap so nguyen duong!\n";
	} while (n < 0);
	
	cout << n << "! = " << GiaiThua(n) << endl;
	return 0;
}