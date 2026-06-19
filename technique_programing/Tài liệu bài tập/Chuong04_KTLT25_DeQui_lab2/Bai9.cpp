#include <iostream>
using namespace std;

//1101 = 1 x 2^3 + 1 x 2^2 + 0 x 2^1 + 1 x 2^0 = 13
int BinToDec(int n, int bac = 0) {
	if (n == 0) return 0;
	int soCuoi = n % 10;
	return (soCuoi * pow(2, bac)) + BinToDec(n / 10, bac + 1);
}

int main() {
	int n;
	cout << "Nhap so nhi phan: ";
	cin >> n;

	cout << "So nhi phan " << n << " doi sang so thap phan la: "<< BinToDec(n);
	return 0;
}