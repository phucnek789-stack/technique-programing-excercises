#include <iostream>
#include <ctime>
#include <iomanip>
using namespace std;

const int MAX = 100;

int a[MAX][MAX];

void input(int& r, int& c) {
	int x, y;
	cout << "Nhap khoang gia tri de tao mang [x, y]: ";
	cin >> x >> y;

	cout << "Nhap so dong: "; cin >> r;
	cout << "Nhap so cot: "; cin >> c;

	for (int i = 0;i < r;i++) 
		for (int j = 0;j < c;j++) 
			a[i][j] = rand() % (y - x + 1) + x;
}

void output(int r, int c) {
	cout << "\nMang ngau nhien vua tao la:\n";
	for (int i = 0;i < r;i++) {
		for (int j = 0;j < c;j++)
			cout << a[i][j] << "\t";
		cout << endl;
	}
}

void tongTungHang(int r, int c) {
	cout << "\nTong cua tung hang:\n";
	for (int i = 0;i < r;i++) {
		int tong = 0;
		for (int j = 0;j < c;j++)
			tong += a[i][j];
		cout << "- Hang " << i << " co S = " << tong << endl;
	}
}

void timMin(int r, int c) {
	int min = a[0][0];
	int minR = 0;
	int minC = 0;

	for (int i = 0;i < r;i++) 
		for (int j = 0;j < c;j++) 
			if (a[i][j] < min) {
				min = a[i][j];
				minR = i;
				minC = j;
			}
	cout << "\nMin = " << min << endl;
	cout << "Vi tri: " << "a[" << minR << "][" << minC << "]\n";
}

int main() {
	srand(time(0));
	int r, c;

	input(r, c);
	output(r, c);

	tongTungHang(r, c);

	timMin(r, c);

	system("pause");
	return 0;
}