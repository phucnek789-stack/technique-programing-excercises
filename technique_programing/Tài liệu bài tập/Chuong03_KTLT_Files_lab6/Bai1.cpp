#include <iostream>
#include <fstream>
using namespace std;

ofstream outInt;

int main() {
	int a, b;
	cout << "Nhap 2 so nguyen bat ki: ";
	cin >> a >> b;

	outInt.open("BT1.txt");
	if (outInt.is_open()) {
		outInt << a << endl;
		outInt << b << endl;
		outInt << "Tong cua 2 so nguyen " << a << " va " << b << " la: " << a + b << endl;
		outInt.close();
	}
	else
		cout << "Mo file de ghi that bai!\n";

	return 0;
}