#include <iostream>
#include <string>
using namespace std;

int main() {
	string s;
	cout << "Nhap chuoi can dao nguoc: ";
	getline(cin, s);

	reverse(s.begin(), s.end());
	cout << s << endl;

	return 0;
}