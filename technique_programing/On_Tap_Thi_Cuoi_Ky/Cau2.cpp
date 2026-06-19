#include <iostream>
#include <string>
using namespace std;

int demDauCau(string& s, int i) {
	if (i >= s.length())
		return 0;

	char c = s[i];
	int count = 0;
	if (c == ',' || c == '.' || c == '?' || c == '!' || c == ';' || c == ':')
		count = 1;

	return count + demDauCau(s, i + 1);
}

void vietHoaDauTu(string& s, int i) {
	if (i >= s.length())
		return;

	if (i == 0 || isspace(s[i - 1]))
		s[i] = toupper(s[i]);

	vietHoaDauTu(s, i + 1);
}

bool checkDoiXung(const string& s, int left, int right) {
	if (left >= right)
		return true;

	if (s[left] != s[right])
		return false;

	return checkDoiXung(s, left + 1, right - 1);
}

int main() {
	string* s = new string;

	cout << "Nhap chuoi s: ";
	getline(cin, *s);

	int soDauCau = demDauCau(*s, 0);
	cout << "\na. So luong dau cau (. , ! ? ; :) trong chuoi la: " << soDauCau << endl;

	vietHoaDauTu(*s, 0);
	cout << "\nb. Chuoi nay sau khi viet hoa chu cai dau moi tu la: " << *s << endl;

	bool laDoiXung = checkDoiXung(*s, 0, s->length() - 1);
	cout << "\nc. Ket qua kiem tra doi xung: ";
	if (laDoiXung)
		cout << "Day la chuoi doi xung (Palindrome)!\n";
	else
		cout<< "Chuoi nay KHONG phai la chuoi doi xung!\n";

	delete s;
	s = nullptr;

	system("pause");
	return 0;
}