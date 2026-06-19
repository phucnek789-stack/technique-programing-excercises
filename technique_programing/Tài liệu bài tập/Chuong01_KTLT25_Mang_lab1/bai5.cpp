#include <iostream>
using namespace std;

const int MAX = 10;

int a[MAX][MAX];

int main() {
	int n;
	cout << "Nhap cap cho ma tran (nxn): ";
	cin >> n;

	for (int i = 0;i < n;i++) {
		cout << "Nhap " << n << " phan tu cho dong thu " << i + 1 << ": ";
		for (int j = 0;j < n;j++)
			cin >> a[i][j];
	}
	
	cout << "Ma tran vuong cap " << n << ":\n";
	for (int i = 0;i < n;i++) {
		for (int j = 0;j < n;j++)
			cout << a[i][j] << "\t";
		cout << endl;
	}

	//Tinh tong duong cheo chinh
	int tongCC = 0;
	for (int i = 0;i < n;i++) 
		for (int j = 0;j < n;j++)
			if (i == j)
				tongCC += a[i][j];
	cout << "Tong cac gia tri tren duong cheo chinh la: " << tongCC << endl;

	//Tinh tong duong cheo phu (pp quay ma tran 90 do theo chieu kim dong ho)
	int tongCP = 0;
	for (int i = 0;i < n;i++)
		for (int j = 0;j < n;j++)
			if (i + j == n - 1)
				tongCP += a[i][j];
	cout << "Tong cac gia tri tren duong cheo phu la: " << tongCP << endl;

	return 0;
}