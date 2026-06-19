#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

const int SO_MON = 5;
const int MAX_SV = 50;

string hoTen[MAX_SV] = {"Nguyen Van A", "Tran Thi B", "Le Tien C", "Ly Minh D", 
"Nguyen Thi E", "Cao Van F", "Bui Thi G", "Tran Minh H"};

float diem[MAX_SV][SO_MON] = {
    {9.0, 7.5, 8.3, 7.8, 10},
    {7, 5.5, 6, 6.3, 8},
    {8.5, 8, 8, 9, 9.5},
    {6, 4.5, 5, 5.3, 7},
    {7.8, 7, 8, 6.8, 8.8},
    {10, 9, 8.5, 10, 10},
    {5, 6, 4.5, 4.3, 6.5},
    {7, 7.8, 7.5, 6.5, 8.3}
};

//Ham in ra ho va ten sinh vien co diem trung binh cao nhat
void xuatSVCoDTBCaoNhat(int n) {
    float maxDTB = -1;
    int maxVT = 0;

    for (int i = 0;i < n;i++) {
        float tong = 0;
        for (int j = 0;j < SO_MON;j++)
            tong += diem[i][j];
        float dtb = tong / SO_MON;

        if (dtb > maxDTB) {
            maxDTB = dtb;
            maxVT = i;
        }
    }

    cout << "Sinh vien co diem trung binh cao nhat la:\nHo va ten: " << hoTen[maxVT] 
        << "\nDiem trung binh: " << maxDTB << endl;
}

//Ham tim kiem sinh vien bang cach nhap ho ten va sau do in ra cac diem so cua sinh vien do
void timKiemSV(int n) {
    string hoTenCanTim;
    cout << "\nNhap ho ten sinh vien can tim: ";
    getline(cin, hoTenCanTim);

    bool timThay = false;
    for (int i = 0;i < n;i++) 
        if (hoTen[i] == hoTenCanTim) {
            cout << "Diem cua sinh vien " << hoTenCanTim << " la:\n";
            for (int j = 0;j < SO_MON;j++)
                cout << diem[i][j] << "\t";
            cout << endl;
            timThay = true;
            break;
        }
    if (!timThay) cout << "Khong tim thay sinh vien nay!\n";
}

//Ham them sinh vien vao cuoi bang
void themSV(int& n) {
    if (n >= MAX_SV) {
        cout << "Danh sach da day, khong the them duoc nua!\n";
        return;
    }

    cout << "\nNhap ho ten sinh vien can them: ";
    getline(cin, hoTen[n]);

    for (int j = 0;j < SO_MON;j++) {
        cout << "Nhap diem cho mon thu " << j + 1 << ": ";
        cin >> diem[n][j];
    }
    cin.ignore();
    n++;
    cout << "Da them sinh vien thanh cong!\n";
}

int main() {
    int n = 8;
    xuatSVCoDTBCaoNhat(n);
    timKiemSV(n);
    themSV(n);
    return 0;
}