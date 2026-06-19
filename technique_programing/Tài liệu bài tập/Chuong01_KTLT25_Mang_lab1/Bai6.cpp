#include <iostream>
using namespace std;

const int MAX = 10;

int a[MAX][MAX];
int b[MAX][MAX];
int tong[MAX][MAX];
int tich[MAX][MAX];

int main() {
	int r, c;
	do {
		cout << "Nhap so hang: ";
		cin >> r;
		cout << "Nhap so cot: ";
		cin >> c;
		if (r<1 || r>MAX || c<1 || c>MAX)
			cout << "Thao tac sai! Moi nhap lai!\n";
	} while (r<1 || r>MAX || c<1 || c>MAX);

	//Ma tran A
	for (int i = 0;i < r;i++) {
		cout << "Nhap " << c << " phan tu cho dong thu " << i + 1 << ": ";
		for (int j = 0;j < c;j++)
			cin >> a[i][j];
	}
	cout << "Xuat ma tran A:\n";
	for (int i = 0;i < r;i++) {
		for (int j = 0;j < c;j++)
			cout << a[i][j] << "\t";
		cout << endl;
	}

	//Ma tran B
	for (int i = 0;i < r;i++) {
		cout << "Nhap " << c << " phan tu cho dong thu " << i + 1 << ": ";
		for (int j = 0;j < c;j++)
			cin >> b[i][j];
	}
	cout << "Xuat ma tran B:\n";
	for (int i = 0;i < r;i++) {
		for (int j = 0;j < c;j++)
			cout << b[i][j] << "\t";
		cout << endl;
	}

	//Tong 2 ma tran
	cout << "Tong 2 ma tran A va B la:\n";
	for (int i = 0;i < r;i++) {
		for (int j = 0;j < c;j++) {
			tong[i][j] = a[i][j] + b[i][j];
			cout << tong[i][j]<<"\t";
		}
		cout << endl;
	}
	
	//Tich 2 ma tran
	if (r == c) {
		cout << "Tich 2 ma tran A va B la:\n";
		for (int i = 0;i < r;i++) {
			for (int j = 0;j < c;j++) {
				tich[i][j] = 0;
				for (int k = 0;k < c;k++)
					tich[i][j] += a[i][k] * b[k][j];
				cout << tich[i][j] << "\t";
			}
			cout << endl;
		}
	}
	else
		cout << "Khong the nhan 2 ma tran vi so cot ma tran A khac so hang ma tran B!\n";
	
	return 0;
}