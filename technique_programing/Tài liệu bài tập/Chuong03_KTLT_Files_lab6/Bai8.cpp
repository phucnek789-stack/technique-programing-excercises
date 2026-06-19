#include <iostream>
#include <fstream>
#include <string>
using namespace std;

ifstream fin;
ofstream fout;

void GhiFile(int a, int b, int c) {
	fout.open("BT8.txt");
	if (!fout.is_open()) {
		cout << "Khong the mo file de ghi!\n";
		return;
	}
	fout << a << "$" << b << "$" << c;
	fout.close();
}

void DocFile(int a, int b, int c) {
	fin.open("BT8.txt");
	if (!fin.is_open()) {
		cout << "Khong the mo file de doc!\n";
		return;
	}
	fin >> a;
	fin.ignore();
	fin >> b;
	fin.ignore();
	fin >> c;
	fin.close();
}

int main() {
	int a, b, c;
	cout << "Nhap 3 so nguyen: ";
	cin >> a >> b >> c;

	GhiFile(a, b, c);
	DocFile(a, b, c);
	
	return 0;
}