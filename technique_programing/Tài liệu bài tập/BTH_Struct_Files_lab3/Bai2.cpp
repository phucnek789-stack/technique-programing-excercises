#include <iostream>
#include <string>
using namespace std;

struct SinhVien {
	string ma;
	string hoTen;
	int namSinh;
	double toan, van, anh;
};

//b. Ham nhap thong tin 1 sinh vien
void nhapSinhVien(SinhVien& sv) {
	cout << "Nhap ma sinh vien: ";
	getline(cin, sv.ma);
	cout << "Nhap ho ten: ";
	getline(cin, sv.hoTen);
	cout << "Nam sinh: ";
	cin >> sv.namSinh;
	cout << "Nhap lan luot ba diem Toan, Van, Anh: ";
	cin >> sv.toan >> sv.van >> sv.anh;
	cin.ignore();
}

//c. Ham nhap thong tin ca lop
void nhapLop(SinhVien lop[], int n) {
	for (int i = 0;i < n;i++)
		nhapSinhVien(lop[i]);
}

//d. Ham tinh diem trung binh
double tinhDTB(SinhVien sv) {
	return ((sv.toan + sv.van) * 2 + sv.anh) / 5;
}

//e. Ham xep loai sinh vien
string ranking(SinhVien sv) {
	if (tinhDTB(sv) >= 8) return "Gioi";
	else if (tinhDTB(sv) >= 6.5) return "Kha";
	else if (tinhDTB(sv) >= 5) return "Trung Binh";
	else if (tinhDTB(sv) >= 0) return "Yeu";
	else return "Diem khong hop le";
}

//f. Ham tao mail cho sinh vien
string taoEmail(SinhVien sv) {
	return sv.ma + sv.hoTen + "@ou.edu.vn";
}

//g. Ham in day du thong tin cua tat ca sinh vien
void xuatSinhVien(SinhVien sv) {
	cout << "-----Thong tin cua sinh vien-----"
		<< "\nMa sinh vien: " << sv.ma
		<< "\nHo va ten sinh vien: " << sv.hoTen
		<< "\nNam sinh cua sinh vien: " << sv.namSinh
		<< "\nDiem Toan: " << sv.toan
		<< "\nDiem Van: " << sv.van
		<< "\nDiem ANh: " << sv.anh
		<< "\nDiem trung binh cua sinh vien: " << tinhDTB(sv)
		<< "\nXep loai sinh vien: " << ranking(sv)
		<< "\nEmail cua sinh vien: " << taoEmail(sv)
		<< endl;
}

void xuatLop(SinhVien lop[], int n) {
	for (int i = 0;i < n;i++)
		xuatSinhVien(lop[i]);
}

void xuatThuTu(SinhVien lop[], int n) {
	int stt;
	cout << "Nhap so thu tu sinh vien: ";
	cin >> stt;
	stt--;
	xuatSinhVien(lop[stt]);
}

//h. Ham main
int main() {
	SinhVien lop[45]; //a. Tao mang co toi da 45 sinh vien trong 1 lop

	int n;
	cout << "Nhap so luong sinh vien: ";
	cin >> n;
	cin.ignore();

	nhapLop(lop, n);
	xuatLop(lop, n);
	xuatThuTu(lop, n);
	return 0;
}