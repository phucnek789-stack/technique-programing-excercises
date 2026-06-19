#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

char* trim(char* s)
{
	while (isspace(*s)) 
		s++;

	if (*s == '\0')
		return s;

	char* end = s + strlen(s) - 1; // tao con tro cuoi cung
	while (end > s && isspace(*end))
		end--;

	*(end + 1) = '\0'; // gan ky tu \0 vao cuoi chuoi
	return s;
}

int demKhoangTrang(char* s)
{
	int dem = 0;
	for (int i = 0; i < strlen(s); i++)
		if (isspace(s[i]))
			dem++;
	return dem;
}

int demKyTuChuSo(char* s)
{
	int dem = 0;
	for (int i = 0; i < strlen(s); i++)
		if (isalnum(s[i]))
			dem++;
	return dem;
}

int demKyTuThuong(char* s)
{
	int dem = 0;
	for (int i = 0; i < strlen(s); i++)
		if (islower(s[i]))
			dem++;
	return dem;
}

int demKyTuHoa(char* s)
{
	int dem = 0;
	for (int i = 0; i < strlen(s); i++)
		if (isupper(s[i]))
			dem++;
	return dem;
}

void inHoa(char* s)
{
	for (int i = 0; i < strlen(s); i++)
		s[i] = toupper(s[i]);
}

void inThuong(char* s)
{
	for (int i = 0; i < strlen(s); i++)
		s[i] = tolower(s[i]);
}

int demTu(char* s)
{
	int dem = 0;
	for (int i = 0; i < strlen(s); i++)
		if (isalnum(s[i]) && (s[i + 1] == ' '|| s[i + 1] == '\0'))
			dem++;
	return dem;
}

int main()
{
	char* s1 = new char[100];
	char* s2 = new char[100];
	char* s3 = new char[100];
	char* s4 = new char[100];

	cout << "Nhap chuoi: ";
	cin.getline(s1, 100);
	strcpy(s2, s1);
	strcpy(s3, s1);
	strcpy(s4, s1);

	cout << "Chuoi ban dau: " << s1 << endl;	
	cout << "Chuoi sau khi loai bo khoang trang: " << trim(s2) << endl;
	cout << "So khoang trang trong chuoi: " << demKhoangTrang(s1) << endl;
	cout << "So ky tu chu so va chu cai trong chuoi: " << demKyTuChuSo(s1) << endl;
	cout << "So ky tu chu viet thuong trong chuoi: " << demKyTuThuong(s1) << endl;
	cout << "So ky tu chu viet hoa trong chuoi: " << demKyTuHoa(s1) << endl;	
	inHoa(s3);
	cout << "Chuoi viet hoa: " << s3 << endl;
	inThuong(s4);
	cout << "Chuoi viet thuong: " << s4 << endl;
	cout << "So tu trong chuoi: " << demTu(s1) << endl;

	delete[] s1;
	delete[] s2;
	delete[] s3;
	delete[] s4;
	system("pause");
	return 0;
}