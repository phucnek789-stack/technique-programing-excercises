#include <iostream>
using namespace std;

void DecToBin(int n) {
	if (n == 0) return;
	DecToBin(n / 2);
	cout << n % 2;
}

int main() {
	int n;
	cout << "Nhap so thap phan: ";
	cin >> n;

	cout << "So thap phan " << n << " doi sang so nhi phan la: ";
	DecToBin(n);
	return 0;
}