#include <iostream>
#include <fstream>
#include <string>
using namespace std;

ifstream fin;
ofstream fout;

int main() {
	fin.open("BT4.txt");
	fout.open("BT6.txt");

	if (!fin.is_open()) {
		cout << "Mo file BT4.txt de doc that bai!\n";
		return 1;
	}
	if (!fout.is_open()) {
		cout << "Mo file BT6.txt de ghi that bai!\n";
		return 1;
	}
	char c;
	while (fin >> c) {
		char up = toupper(c);

		if (up == 'A' || up == 'E' || up == 'I' || up == 'O' || up == 'U')
			fout << up << " ";
	}
	cout << "Da loc nguyen am tu BT4.txt sang BT6.txt thanh cong!\n";

	fin.close();
	fout.close();
	return 0;
}