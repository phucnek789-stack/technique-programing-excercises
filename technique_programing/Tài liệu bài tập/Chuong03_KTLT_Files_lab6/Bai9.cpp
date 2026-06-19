#include <iostream>
#include <fstream>
#include <string>
using namespace std;

ifstream fin;
ofstream fout;

void NhapChuoi(string& s1, string& s2) {
	cout << "Nhap chuoi s1: ";
	getline(cin, s1);
	cout << "Nhap chuoi s2: ";
	getline(cin, s2);
}

void GhiFile(string s1, string s2) {
	fout.open("BT9.txt");
	if (!fout.is_open()) {
		cout << "Khong the mo file de ghi!\n";
		return;
	}
	fout << s1;
	fout << endl;
	fout << s2;
	fout.close();
}

void DocFile(string& s1, string& s2) {
	fin.open("BT9.txt");
	if (!fin.is_open()) {
		cout << "Khong the mo file de doc!\n";
		return;
	}
	getline(fin, s1);
	getline(fin, s2);
	fin.close();
}

void SoSanh2Chuoi(string s1, string s2) {
	cout << "\nKet qua so sanh: ";
	if (s1.length() < s2.length()) cout << "Chuoi s1 ngan hon chuoi s2!\n";
	else if (s1.length() > s2.length()) cout << "Chuoi s1 dai hon chuoi s2!\n";
	else cout << "Hai chuoi bang nhau!\n";
}

string Noi2Chuoi(string s1, string s2) {
	return s1 + " " + s2;
}

int DemNguyenAm(string s) {
	int dem = 0;
	for (char c : s) {
		char down = tolower(c);
		if (down == 'u' || down == 'e' || down == 'o' || down == 'a' || down == 'i')
			dem++;
	}
	return dem;
}

int DemTuTrongFile() {
	fin.open("BT9.txt");
	if (!fin.is_open()) {
		cout << "Khong the mo file de doc!\n";
		return 0;
	}
	string tu;
	int dem = 0;
	while (fin >> tu) {
		dem++;
	}
	fin.close();
	return dem;
}

int main() {
	string s1, s2;

	NhapChuoi(s1, s2);
	GhiFile(s1, s2);
	s1 = s2 = "";
	DocFile(s1, s2);
	SoSanh2Chuoi(s1, s2);
	cout << "Chuoi sau khi da noi la: " << Noi2Chuoi(s1, s2) << endl;
	cout << "So nguyen am trong chuoi s1 la: " << DemNguyenAm(s1) << endl;
	cout << "So tu co trong file la: " << DemTuTrongFile() << endl;
	return 0;
}