#include <iostream>
#include <string>
using namespace std;

string layHo(string s) {
	int dau = s.find(' ');
	return s.substr(0, dau);
}

string layTen(string s) {
	int cuoi = s.rfind(' ');
	return s.substr(cuoi + 1);
}

string layChuLot(string s) {
	int dau = s.find(' ');
	int cuoi = s.rfind(' ');
	return s.substr(dau + 1, cuoi - dau - 1);
}

int main() {
	string s;
	cout << "Nhap chuoi: ";
	getline(cin, s);

	string ho = layHo(s);
	string ten = layTen(s);
	string lot = layChuLot(s);

	cout << ho << endl;
	cout << lot << endl;
	cout << ten << endl;
	return 0;
}