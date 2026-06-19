#include <iostream>
#include <string>
using namespace std;

void chuanHoa(string& s) {
	if (s.length() > 0) {
		s[0] = toupper(s[0]);
	}
	for (int i = 1;i < s.length();i++) {
		if (s[i - 1] == ' ')
			s[i] = toupper(s[i]);
	}
}

int main() {
	string s1, s2;
	cout << "Nhap chuoi 1: ";
	getline(cin, s1);
	cout << "Nhap chuoi 2: ";
	getline(cin, s2);

	if (s1.length() < s2.length())
		cout << "Chuoi 1 ngan hon chuoi 2!\n";
	else if (s1.length() > s2.length())
		cout << "Chuoi 1 dai hon chuoi 2!\n";
	else
		cout << "Hai chuoi bang nhau!\n";

	chuanHoa(s1);
	cout << "chuoi 1 sau khi chuan hoa la: " << s1 << endl;
	chuanHoa(s2);
	cout << "chuoi 2 sau khi chuan hoa la: " << s2 << endl;

	string s = s1 + " " + s2;
	cout << s;
	return 0;
}