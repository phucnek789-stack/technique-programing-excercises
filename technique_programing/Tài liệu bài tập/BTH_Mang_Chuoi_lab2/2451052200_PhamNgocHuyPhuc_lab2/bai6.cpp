#include <iostream>
#include <string>
using namespace std;

void Palindrome(string s) {
	for (int i = 0; i < s.length(); i++)
		s[i] = tolower(s[i]);
	int i = 0;
	int j = s.length() - 1;
	while (i < j) {
		if (s[i] == ' ') {
			i++;
			continue;
		}
		if (s[j] == ' ') {
			j--;
			continue;
		}
		if (s[i] != s[j]) {
			cout << "Khong phai la chuoi palindrome!\n";
			return;
		}
		i++;
		j--;
	}
	cout << "La chuoi palindrome!\n";
}

int main() {
	string s;
	cout << "Nhap chuoi bat ki: ";
	getline(cin, s);

	Palindrome(s);

	system("pause");
	return 0;
}