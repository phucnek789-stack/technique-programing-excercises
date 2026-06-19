#include <iostream>
#include <string>
using namespace std;

int main() {
	string s1, s2, s3;

	cout << "Nhap chuoi s1: ";
	getline(cin, s1);

	cout << "Nhap chuoi s2: ";
	getline(cin, s2);

	int tim = s1.find(s2);
	if (tim != -1) {
		cout << "Da tim thay chuoi 2 tai vi tri " << tim << endl;

		cout << "Nhap chuoi s3: ";
		getline(cin, s3);

		s1.replace(tim, s2.length(), s3);
		cout << "Chuoi khi da duoc sua doi la: " << s1 << endl;
	}	
	else
		cout << "Khong tim thay chuoi 2!\n";

	system("pause");
	return 0;
}