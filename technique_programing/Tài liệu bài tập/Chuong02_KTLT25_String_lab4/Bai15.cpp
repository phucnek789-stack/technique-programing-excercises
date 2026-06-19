#include <iostream>
#include <string>
using namespace std;

int main() {
	string s1, s2;

	cout << "Nhap chuoi cha: ";
	getline(cin, s1);

	cout << "Nhap chuoi con: ";
	getline(cin, s2);

	int pos;
	do {
		cout << "Nhap vi tri can chen: ";
		cin >> pos;
		if (pos<0 || pos>s1.length()) {
			cout << "vi tri chen khong hop le!\n";
			cout << "Moi nhap lai.\n	";
		}
	} while (pos<0 || pos>s1.length());
	
	s1.insert(pos, " " + s2);
	cout << "Chuoi sau khi da duoc chen la: " << s1 << endl;
	return 0;
}