#include <iostream>
#include <string>
#include <fstream>
using namespace std;

ifstream fin;
ofstream fout;

int main() {
	char s[21];
	char* p = s;
	cout << "Nhap chuoi (max = 20 ky tu): ";
	cin.getline(s, 21);

	fout.open("BT4.txt", ios::out);
	if (fout.is_open()) {
		while (*p != '\0') {
			fout << (char)toupper(*p) << endl;
			p++;
		}
		fout.close();
	}
	else {
		cout << "Mo file BT4.txt de ghi that bai!\n";
		return 1;
	}

	fin.open("BT4.txt", ios::in);
	if (fin.is_open()) {
		char c;
		while (fin >> c)
			cout << endl;
		fin.close();
	}
	else {
		cout << "Khong the mo file BT4.txt de doc!\n";
		return 1;
	}

	return 0;
}