#include <iostream>
#include <ctime>
#include<iomanip>
using namespace std;

const int MAX = 100;

int a[MAX][MAX];

void input(int a[][MAX], int& r, int& c) {
	int x, y;
	cout << "Nhap khoang gia tri cho mang [x, y]: ";
	cin >> x >> y;

	cout << "Nhap so hang: "; cin >> r;
	cout << "Nhap so cot: "; cin >> c;

	for (int i = 0;i < r;i++) 
		for (int j = 0;j < c;j++) 
			a[i][j] = rand() % (y - x + 1) + x;
}

void output(int a[][MAX], int r, int c) {
	cout << "\nMang ngau nhien dang luu tru:\n";
	for (int i = 0;i < r;i++) {
		for (int j = 0;j < c;j++)
			cout << a[i][j] << "\t";
		cout << endl;
	}
}

void findMax(int a[][MAX], int r, int c) {
	int max = a[0][0];
	int maxR = 0;
	int maxC = 0;
	for (int i = 0;i < r;i++) 
		for (int j = 0;j < c;j++) 
			if (a[i][j] > max) {
				max = a[i][j];
				maxR = i;
				maxC = j;
			}
	cout << "\nMax = " << max << endl;
	cout << "Vi tri: a[" << maxR << "][" << maxC << "]\n";
}

void averageCollum(int a[][MAX], int r, int c) {
	cout << "\nTrung binh cong cua tung cot:\n";
	for (int j = 0;j < c;j++) {
		double tong = 0.0;
		for (int i = 0;i < r;i++)
			tong += a[i][j];
		cout << "- Cot " << j << ": " << fixed << setprecision(2) << tong / r << endl;
	}
}

int main() {
	srand(time(0));
	int r, c;

	input(a, r, c);
	output(a, r, c);

	findMax(a, r, c);
	
	averageCollum(a, r, c);

	system("pause");
	return 0;
}