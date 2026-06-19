#include <iostream>
#include <fstream>
using namespace std;

ifstream inFile;
ofstream outFile;

int main() {
	int a, b, c;
	cout << "Nhap 3 so nguyen bat ki: ";
	cin >> a >> b >> c;

	outFile.open("BT3.txt");

	if (outFile.is_open()) {
		outFile << a << "#" << b << "#" << c << endl;
		outFile.close();
	}
	else
		cout << "Mo file de ghi that bai!\n";

	inFile.open("BT3.txt");
	if (inFile.is_open()) {
		inFile >> a;
		inFile.ignore();
		inFile >> b;
		inFile.ignore();
		inFile >> c;
		inFile.ignore();
		cout << "Gia tri trung binh la: " << (double)(a + b + c) / 3 << endl;
		inFile.close();
	}
	else
		cout << "Mo file de doc that bai!\n";

	return 0;
}