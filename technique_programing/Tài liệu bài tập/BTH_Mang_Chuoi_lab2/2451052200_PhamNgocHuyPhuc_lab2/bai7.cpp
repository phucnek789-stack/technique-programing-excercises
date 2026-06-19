#include <iostream>
#include <string>
#include <fstream>
using namespace std;

ifstream inTinh;
ofstream outTinh;

int main() {
	int a, b, c;
	cout << "Nhap 3 so nguyen: ";
	cin >> a >> b >> c;

	outTinh.open("BT7.txt", ios::out);
	if (outTinh.is_open()) {
		outTinh << a << "#" << b << "#" << c;
		outTinh.close();
	}
	else
		cout << "Khong mo duoc file de ghi du lieu!\n";
	
	int x, y, z;
	inTinh.open("BT7.txt", ios::in);
	if (inTinh.is_open()) {
		inTinh >> x;
		inTinh.ignore();
		inTinh >> y;
		inTinh.ignore();
		inTinh >> z;
		cout << "Trung binh cong: " << (double)(x + y + z) / 3 << endl;
		inTinh.close();
	}
	else
		cout << "Mo file doc that bai!\n";

	system("pause");
	return 0;
}