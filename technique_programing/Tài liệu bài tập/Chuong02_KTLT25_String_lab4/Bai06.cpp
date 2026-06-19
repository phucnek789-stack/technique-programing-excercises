#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

bool kiemTraNamNhuan(int nam)
{
	return (nam % 400 == 0 || (nam % 4 == 0 && nam % 100 != 0));
}

bool kiemTraNgay(int ngay, int thang, int nam)
{
	if (nam < 1 || thang < 1 || thang > 12 || ngay < 1)
		return false;

	int ngayTrongThang[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	
	if (kiemTraNamNhuan(nam))
		ngayTrongThang[2] = 29;

	return ngay <= ngayTrongThang[thang];
}

int tinhNgay(int ngay, int thang, int nam)
{
	if (kiemTraNgay(ngay, thang, nam))
	{

		int ngayTrongThang[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

		if (kiemTraNamNhuan(nam))
			ngayTrongThang[2] = 29;

		int soNgay = 0;
		for (int i = 1; i < thang; i++)
			soNgay += ngayTrongThang[i];

		soNgay += ngay;
		return soNgay;
	}
	else
		return -1;
}

void cach1()
{
	int tmp[3] = { 0 };
	int i = 0;
	char* s = new char[10];
	cout << "Nhap ngay thang nam (DD-MM-YYYY): ";
	cin.getline(s, 10);
	char* token = strtok(s, "-");
	while (token != NULL)
	{
		tmp[i++] = atoi(token);
		token = strtok(NULL, "-");
	}

	cout << "So ngay: " << tinhNgay(tmp[0], tmp[1], tmp[2]) << endl;

	delete[] s;
	delete token;
}

void cach2()
{
	char* ngay = new char[3];
	char* thang = new char[3];
	char* nam = new char[5];
	cout << "Nhap ngay thang nam (DD-MM-YYYY): ";
	cin.getline(ngay, 3, '-');
	cin.getline(thang, 3, '-');
	cin.getline(nam, 5);
	int d = atoi(ngay);
	int m = atoi(thang);
	int y = atoi(nam);
	cout << "So ngay: " << tinhNgay(d, m, y) << endl;
	delete[] ngay;
	delete[] thang;
	delete[] nam;
}

int main()
{
	cout << "Cach 1:\n";
	cach1();
	cout << "Cach 2:\n";
	cach2();
	return 0;
}