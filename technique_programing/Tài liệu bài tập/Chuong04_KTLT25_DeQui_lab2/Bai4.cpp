#include <iostream>
using namespace std;

double soMu(int x, int n) {
	if (n == 0) return 1;
	if (n < 0) return 1.0 / soMu(x, -n);
	return x * soMu(x, n - 1);
}

int main() {
	int x;
	cout << "Nhap co so x: ";
	cin >> x;

	int n;
	cout << "Nhap so mu n: ";
	cin >> n;

	cout << "x^n = " << soMu(x, n) << endl;

	return 0;
}