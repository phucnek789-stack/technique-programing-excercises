#include <iostream>
using namespace std;

const int MAX = 10;
int a[MAX][MAX];

void nhapMT(int& n) {
	int dem = 1;
	for (int j = 0;j < n;j++) {
		if (j % 2 == 0) {
			for (int i = 0;i < n;i++) {
				a[i][j] = dem;
				dem++;
			}
		}
		else
			for (int i = n - 1;i >= 0;i--) {
				a[i][j] = dem;
				dem++;
			}
	}
}

void xuatMT(int n) {
	cout << "Ma tran dang luu tru la:\n";
	for (int i = 0;i < n;i++) {
		for (int j = 0;j < n;j++)
			cout << a[i][j] << "\t";
		cout << endl;
	}
}

int main() {
	int n;
	do {
		cout << "Nhap cap cua ma tran: ";
		cin >> n;
		if (n<2 || n>MAX)
			cout << "Khong thoa man yeu cau! Moi nhap lai!\n";
	} while (n<2 || n>MAX);
	nhapMT(n);
	xuatMT(n);

	return 0;
}