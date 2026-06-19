#include <iostream>
#include <fstream>
#include <string>
using namespace std;

ifstream inDoc;

int main() {
	string m;

	inDoc.open("BT1.txt");
	if (inDoc.is_open()) {
		cout << "Thong tin doc duoc tu file m la: " << m << endl;
		while (getline(inDoc, m))
			cout << m << endl;
		inDoc.close();
	}
	else
		cout << "Khong mo duoc file de doc!\n";

	return 0;
}