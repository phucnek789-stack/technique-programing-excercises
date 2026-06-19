#include <iostream>
using namespace std;

const int MAX = 10;
int a[MAX][MAX];

//Ham nhap mang
void nhapMang(int &r, int &c) {
	do {
		cout << "Nhap so hang: "; cin >> r;
		cout << "Nhap so cot: "; cin >> c;
		if (r<1 || r>MAX || c<1 || c>MAX)
			cout << "Thao tac sai! Moi nhap lai!\n";
	} while (r<1 || r>MAX || c<1 || c>MAX);
	
	for (int i = 0;i < r;i++) {
		cout << "Nhap " << c << " phan tu cho dong thu " << i + 1 << ": ";
		for (int j = 0;j < c;j++)
			cin >> a[i][j];
	}
}
//Ham xuat mang
void xuatMang(int r, int c) {
	cout << "Xuat mang dang luu tru la:\n";
	for (int i = 0;i < r;i++) {
		for (int j = 0;j < c;j++)
			cout << a[i][j] << "\t";
		cout << endl;
	}
}

//Ham tinh trung binh cong
double tinhTBC(int r, int c) {
	double tong = 0;
	for (int i = 0;i < r;i++) {
		for (int j = 0;j < c;j++)
			tong += a[i][j];
	}
	return tong/(r*c);
}

//Ham kiem tra su ton tai cua gia tri x
bool kiemTra(int &x, int r, int c) {
	for (int i = 0;i < r;i++)
		for (int j = 0;j < c;j++)
			if (a[i][j] == x)
				return true;
	return false;
}

//Ham hoan doi vi tri gia tri x va y
void hoanDoi(int x, int y, int r, int c) {
	int d1 = 0, c1 = 0, d2 = 0, c2 = 0;
	for (int i = 0;i < r;i++)
		for (int j = 0;j < c;j++) {
			if (a[i][j] == x) {
				d1 = i;
				c1 = j;
			}
			if (a[i][j] == y) {
				d2 = i;
				c2 = j;
			}
		}
	swap(a[d1][c1], a[d2][c2]);
	cout << "Da hoan doi gia tri " << x << " va gia tri " << y << " thanh cong.\n";
}

//Ham tinh tich tai 1 cot duoc chi dinh
double tich1Cot(int &k, int r, int c) {
	cout << "Nhap vi tri cot can tinh tich (tu 1 den " << r << "): "; cin >> k;
	double tich = 1;
	if (k >= 1 && k <= c) {
		for (int i = 0;i < r;i++)
			tich *= a[i][k - 1];
		cout << "Tich cua cot thu " << k << " la: " << tich << endl;
	}
	else
		cout << "Thao tac khong hop le!\n";
	return tich;
}

int main() {
	//cau a
	int r, c;
	nhapMang(r, c);
	xuatMang(r, c);

	//cau b
	double kq = tinhTBC(r, c);
	cout << "Trung binh cong cua cac phan tu trong mang la: " << kq << endl;
	
	//cau c
	int x;
	cout << "Nhap gia tri can kiem tra: ";
	cin >> x;
	if (kiemTra(x, r, c) == true)
		cout << "Gia tri " << x << " co ton tai trong mang!\n";
	else
		cout << "Gia tri " << x << " khong ton tai trong mang!\n";
	
	//cau d
	int y;
	cout << "Nhap vao 2 gia tri x va y: ";
	cin >> x >> y;
	if (kiemTra(x, r, c) == true && kiemTra(y, r, c) == true) {
		hoanDoi(x, y, r, c);
		xuatMang(r, c);
	}
	else
		cout << "Error: 1 trong 2 gia tri khong ton tai.\n";

	//cau e
	int k;
	tich1Cot(k, r, c);

	return 0;
}