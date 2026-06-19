#include <iostream>
#include <string>
using namespace std;

int main() {
	string s;
	cout << "Moi nhap chuoi ki tu: ";
	cin >> s;

	//chuyen ve chuoi thuong
	for (int i = 0;i < s.length();i++) {
		s[0] = towlower(s[i]);
	}

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
			cout << "khong phai la chuoi Palindrome!\n";
			return 0;
		}
		i++;
		j--;
	}
	cout << "La chuoi Palindrome!\n";
	return 0;
}