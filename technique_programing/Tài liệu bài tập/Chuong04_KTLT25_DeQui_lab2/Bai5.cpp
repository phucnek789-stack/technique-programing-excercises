#include <iostream>
using namespace std;

//Cach 1
/* int demChuSo(long n) {
	if (n < 10) return 1;
	int dem = 0;
	int temp = n % 10;
	dem++;
	int soConLai = n / 10;
	return dem + demChuSo(soConLai);
}
*/

//Cach 2:
int demChuSo(long long n) {
	if (n < 10) return 1;
	return 1 + demChuSo(n/10);
}

int main() {
	long long n;
	do {
		cout << "Nhap so nguyen n: ";
		cin >> n;
		if (n < 0)
			cout << "Moi nhap so nguyen duong!\n";
	} while (n < 0);

	cout << "Co " << demChuSo(n) << " so trong so nguyen " << n << endl;
	return 0;
}