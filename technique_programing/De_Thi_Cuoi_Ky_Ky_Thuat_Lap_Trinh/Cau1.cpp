#include <iostream>
using namespace std;

//Tinh tong cac chu so cua 1 so nguyen
int tinhTong(int n) {
	int temp = n % 10;
	if (n < 10) return n;
	return temp + tinhTong(n / 10);
}

int main() {
	int n;
	do {
		cout << "Nhap so nguyen duong bat ki: ";
		cin >> n;
		if (n < 0)
			cout << "Nhap sai, moi nhap lai!\n";
	} while (n < 0);

	cout << "Tong cac chu so cua so nguyen " << n << " la: " << tinhTong(n) << endl;

	system("pause");
	return 0;
}