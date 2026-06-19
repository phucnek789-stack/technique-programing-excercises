#include <iostream>
using namespace std;

int Fibonacci(int n) {
	if (n == 0) return 0;
	if (n == 1) return 1;
	return Fibonacci(n - 1) + Fibonacci(n - 2);
}

int main() {
	int n;
	do {
		cout << "Nhap so nguyen n: ";
		cin >> n;
		if (n < 0)
			cout << "Moi nhap so nguyen duong!\n";
	} while (n < 0);

	cout << "Fibonacci: " << Fibonacci(n) << endl;
	return 0;
}