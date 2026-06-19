#include <iostream>
#include <string>
using namespace std;

string inHoa(string s) {
	for (int i = 0; i < s.length(); i++) {
		s[i] = toupper(s[i]);
	}
	return s;
}

string inThuong(string s) {
	for (int i = 0; i < s.length(); i++) {
		s[i] = tolower(s[i]);
	}
	return s;
}

bool laNguyenAm(char c) {
	c = tolower(c);
	return (c == 'a' || c == 'i' || c == 'o' || c == 'u' || c == 'e');
}

string xoaNguyenAm(string s) {
	for (int i = 0; i < s.length(); i++)
		if (laNguyenAm(s[i])) {
			s.erase(i, 1);
			i--;
		}
	return s;
}

int main() {
	string s;
	cout << "Nhap chuoi: ";
	getline(cin, s);

	cout << "Chuoi sau khi da in hoa toan bo: " << inHoa(s) << endl;
	cout << "Chuoi sau khi da in thuong toan bo: " << inThuong(s) << endl;
	cout << "Chuoi sau khi da xoa toan bo nguyen am la: " << xoaNguyenAm(s) << endl;

	system("pause");
	return 0;
}