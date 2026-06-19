#include <iostream>
#include <string>
using namespace std;

int main() {
	string s;
	cout << "Nhap vao chuoi ky tu: ";
	getline(cin, s);

	string w;
	cout << "Nhap vao tu can tim trong chuoi tren: ";
	cin >> w;

	int dem = 0;
	int pos = 0;
	while ((pos = s.find(w, pos)) != string::npos) {
		dem++;
		pos += w.length();
	}
	cout << "So lan xuat hien cua " << w << " la: " << dem << endl;

	return 0;
}