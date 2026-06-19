#include <iostream>
#include <string>
using namespace std;

int main() {
	string s1, s2, s3;
	
	cout << "Nhap ho: ";
	getline(cin, s1);

	cout << "Nhap chu lot: ";
	getline(cin, s2);

	cout << "Nhap ten: ";
	getline(cin, s3);

	string s = s1 + " " + s2 + " " + s3;
	cout << "Ho va ten day du la: " << s << endl;

	return 0;
}