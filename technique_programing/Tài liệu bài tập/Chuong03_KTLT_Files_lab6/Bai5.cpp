#include <iostream>
#include <fstream>
#include <string>
using namespace std;

ifstream fin;

int main() {
	fin.open("BT4.txt");
	if (fin.is_open()) {
		int count = 0;
		char c;
		while (fin.get(c)) 
			count++;
		cout << "Tong so ky tu dang co trong file BT4.txt la: " << count << endl;
		fin.close();
	}
	else
	{
		cout << "Khong the mo file BT4.txt de doc!\n";
		return 1;
	}
	return 0;
}