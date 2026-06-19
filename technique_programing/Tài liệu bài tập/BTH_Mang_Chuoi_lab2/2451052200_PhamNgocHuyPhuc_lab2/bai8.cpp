#include <iostream>
#include <fstream>
#include <string>
using namespace std;

const int MAX = 10;

string chuanHoa(string s) {
	if (isalpha(s[0]))
		s[0] = toupper(s[0]);
	for (int i = 1; i < s.length(); i++) {
		if (isspace(s[i - 1]) && isalpha(s[i]))
			s[i] = toupper(s[i]);
		else
			s[i] = tolower(s[i]);
	}
	return s;
}

void chuanHoaTenQG(string tenQG[MAX], int hang) {
	for (int i = 0; i < hang; i++)
		tenQG[i] = chuanHoa(tenQG[i]);
}

void xuatDS(string tenQG[MAX], int soHC[MAX][MAX], int hang, int cot) {
	for (int i = 0; i < hang; i++) {
		cout << tenQG[i] << "\t";
		for (int j = 0; j < cot; j++) {
			cout << soHC[i][j] << "\t";
		}
		cout << endl;
	}
	cout << endl;
}

void tongSoHC(int soHC[MAX][MAX], int hang, int& cot) {
	for (int i = 0;i < hang;i++) {
		int tong = 0;
		for (int j = 0;j < cot;j++)
			tong += soHC[i][j];
		soHC[i][3] = tong;
	}
	if (cot < 4)cot++;
}

void HCVangNhieuNhat(string tenQG[MAX], int soHC[MAX][MAX], int hang) {
	int max = soHC[0][0];
	string tenNuoc = tenQG[0];
	for (int i = 0;i < hang;i++) {
		if (soHC[i][0] > max) {
			max = soHC[i][0];
			tenNuoc = tenQG[i];
		}
	}
	cout << "Quoc gia co nhieu huy chuong vang nhat la "
		<< tenNuoc << ": " << max << " huy chuong vang" << endl;
}

void inGiamDanTenQG(string tenQG[MAX], int soHC[MAX][MAX], int hang) {
	for (int i = 0; i < hang - 1; i++)
		for (int j = i + 1; j < hang; j++)
			if (soHC[i][3] < soHC[j][3]) {
				swap(tenQG[i], tenQG[j]);

				for (int k = 0; k < 4; k++) {
					swap(soHC[i][k], soHC[j][k]);
				}
			}

	cout << "\nDanh sach giam dan theo tong huy chuong:\n";
	for (int i = 0; i < hang; i++) {
		cout << tenQG[i] << " - " << soHC[i][3] << endl;
	}
}

int main() {
	string tenQG[MAX] = { "phap", "nhatban", "hoa ki", "duc", "y" };
	int soHC[MAX][MAX] = {
	{16,26,22},
	{20,12,13},
	{40,44,42},
	{12,13,18},
	{12,13,15}
	};
	int hang = 5;
	int cot = 3;

	chuanHoaTenQG(tenQG, hang);

	tongSoHC(soHC, hang, cot);
	xuatDS(tenQG, soHC, hang, cot);

	HCVangNhieuNhat(tenQG, soHC, hang);

	inGiamDanTenQG(tenQG, soHC, hang);
	return 0;
}