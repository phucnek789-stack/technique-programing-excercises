#include <iostream>
using namespace std;

int main() {
	int a[4][3];
	int i, j;
	i = 0;
	while (i < 4) {
		j = 0;
		cout << "Nhap " << 3 << " phan tu cho dong thu " << i + 1 << ": ";
		while (j<3)
		{
			cin >> a[i][j];
			j++;
		}
		i++;
	}

	i = 0;
	while (i < 4) {
		j = 0;
		while (j < 3)
		{
			cout << a[i][j] << "\t";
			j++;
		}
		cout << endl;
		i++;
	}
	return 0;
}