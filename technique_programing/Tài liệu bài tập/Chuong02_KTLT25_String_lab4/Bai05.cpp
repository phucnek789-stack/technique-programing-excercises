#include <iostream>
#include <conio.h>
using namespace std;

int main()
{
	int i, dem = 0;
	char* password = new char[11];	
	do
	{
		cout << "Nhap mat khau: ";
		for (i = 0; i < 10; i++)
		{
			char ch = _getch();
			if (ch == '\r' || ch == '\n')
				break;

			*(password + i) = ch;
			cout << "X";
		}
		*(password + i) = '\0';
		if (strcmp(password, "SinhVienCQ") != 0)
		{
			cout << "\nNhap sai! Nhap lai!\n";
			dem++;
		}
		else
			cout << "\nDang nhap thanh cong!\n";
	} while (strcmp(password, "SinhVienCQ") != 0 && dem < 3);
	delete[] password;
	system("pause");
	return 0;
}