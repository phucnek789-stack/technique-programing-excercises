#include <iostream>
#include <string>
using namespace std;

string daoNguocMang(string &s) {
	for (int i =0; i < s.length() / 2; i++) {
		char tam = s[i];
		s[i] = s[s.length() - i - 1];
		s[s.length() - i - 1] = tam;
	}
	return s;
}

int main() {
	string s;
	cout << "Nhap chuoi bat ki: ";
	getline(cin, s);

	string kq = daoNguocMang(s);
	cout << "Mang sau khi dao nguoc la: " << kq << endl;

	system("pause");
	return 0;
}