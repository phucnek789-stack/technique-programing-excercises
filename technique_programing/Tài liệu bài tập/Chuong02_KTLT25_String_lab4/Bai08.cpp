#include <iostream>
#include <string>
using namespace std;

int main() {
	string s;
	cout << "Nhap chuoi: ";
	getline(cin, s);

	int dau = s.find(' ');
	int cuoi = s.rfind(' ');

	string ho = s.substr(0, dau);
	string ten = s.substr(cuoi + 1);
	string lot = s.substr(dau + 1, cuoi - dau - 1);

	cout << ho << endl;
	cout << lot << endl;
	cout << ten << endl;
	return 0;
}