#include <iostream>
using namespace std;

const int MAX = 10;
int a[MAX][MAX];

void nhapMT(int& n) {
	int dem = 1;
	int d1 = 0, d2 = n-1; //dong dau, dong cuoi
	int c1 = 0, c2 = n-1; //cot dau, cot cuoi
	while (dem <= n * n) {
		for(int j = c1;j <= c2;j++) {
			a[d1][j] = dem;
			dem++;
		}
		d1++;

		for(int i = d1;i <= d2;i++) {
			a[i][c2] = dem;
			dem++;
		}
		c2--;

		if (d1 <= d2) {
			for (int j = c2;j >= c1;j--) {
				a[d2][j] = dem;
				dem++;
			}
			d2--;
		}
		
		if (c1 <= c2) {
			for (int i = d2;i >= d1;i--) {
				a[i][c1] = dem;
				dem++;
			}
			c1++;
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