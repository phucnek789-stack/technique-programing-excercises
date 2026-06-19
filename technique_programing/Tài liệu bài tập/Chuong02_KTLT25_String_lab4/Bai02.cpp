#include <iostream>
#include <string>
using namespace std;

int main() {
	string s;
	cout << "Nhap s (ho, ten): ";
	getline(cin, s);

	int pos = s.find(',', 0);

	string ho = s.substr(0, pos);
	string ten = s.substr(pos + 2);

	string kq = ho + " " + ten;
	cout << kq << endl;
	return 0;
}