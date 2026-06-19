#include <iostream>
#include <string>
using namespace std;

pair<int, int> soKyTuVaSoChuoi(string s){
	int demChuSo = 0;
	int demSo = 0;	
	for (int i = 0; i < s.length(); i++) {
		if (isalpha(s[i]) != 0)
			demChuSo++;
		if (isdigit(s[i]) != 0)
			demSo++;
	}
	return{ demChuSo, demSo };
}

int main() {
	string s;
	cout << "Nhap chuoi: ";
	getline(cin, s);

	pair<int, int> kq = soKyTuVaSoChuoi(s);
	cout << "So ky tu la: " << kq.first << endl;
	cout << "So chu so la: " << kq.second << endl;
	system("pause");
	return 0;
}