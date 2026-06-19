#include <iostream>
using namespace std;

int UCLN(int a, int b) {
	if (b == 0) return a;
	else {
		int d = a % b;
		d = b;
		b = a;
	}
	return UCLN(b, a % b);
}

int main() {
	int a, b;
	cout << "Nhap 2 so nguyen a, b: ";
	cin >> a >> b;

	cout << "Uoc chung lon nhat cua hai so nguyen " << a << " va " << b << " la: " << UCLN(a, b);

	return 0;
}