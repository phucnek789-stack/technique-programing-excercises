#include <iostream>
#include <string>
using namespace std;

bool isNguyenAm(char c) {
	c = tolower(c);
	return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

int main() {
	string s; 
	cout << "Nhap chuoi: "; getline(cin, s);

	for (int i = 0;i < s.length();i++) {
		if (isNguyenAm(s[i])) {
			s.erase(i, 1);
			i--;
		}
	}
	cout << "Chuoi sau khi bi loai bo nguyen am la: " << s << endl;

	return 0;
}