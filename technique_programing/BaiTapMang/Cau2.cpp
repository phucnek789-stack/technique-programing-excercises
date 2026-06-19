#include <iostream>
#include <string>
using namespace std;

const int SO_MON = 5;
const int MAX_SV = 50;

string hoTen[MAX_SV] = {
	"Nguyen Van A", "Tran Thi B", "Le Tien C", "Ly Minh D",
	"Nguyen Thi E","Cao Van F", "Bui Thi G", "Tran Minh H"
};

double bangDiem[MAX_SV][SO_MON] = {
    {9.0, 7.5, 8.3, 7.8, 10.0},
    {7.0, 5.5, 6.0, 6.3, 8.0},
    {8.5, 8.0, 8.0, 9.0, 9.5},
    {6.0, 4.5, 5.0, 5.3, 7.0},
    {7.8, 7.0, 8.0, 6.8, 8.8},
    {10.0, 9.0, 8.5, 10.0, 10.0},
    {5.0, 6.0, 4.5, 4.3, 6.5},
    {7.0, 7.8, 7.5, 6.5, 8.3}
};

void diemMAXTungMon(int n) {
    for (int j = 0;j < SO_MON;j++) {
        double max = bangDiem[0][j];
        int posMax = 0;
        for (int i = 1;i < n;i++) 
            if (bangDiem[i][j] > max) {
                max = bangDiem[i][j];
                posMax = i;
            }
                
        cout << "- Mon thu " << j + 1 << " so diem max = " << max << ", ";
        cout << "Sinh vien: " << hoTen[posMax] << endl;
    }
}

void SinhVienDTBCaoNhat(int n) {
    double dtbMax = -1;
    int posMax = 0;

    for (int i = 0;i < n;i++) {
        double tong = 0;
        for (int j = 0;j < SO_MON;j++)
            tong += bangDiem[i][j];
        double dtb = tong / SO_MON;
        if (dtb > dtbMax) {
            dtbMax = dtb;
            posMax = i;
        }
    }
    cout << "\nSinh vien co diem tung binh cao nhat la: " << hoTen[posMax] << ", DTB = " << dtbMax << endl;
}

void timKiemSV(int n) {
    string ten;
    cout << "\nNhap ho ten sinh can tim: ";
    getline(cin, ten);

    bool found = false;
    for (int i = 0;i < n;i++) {
        if (hoTen[i] == ten) {
            cout << "Bang diem cua sinh vien " << ten << ": ";
            for (int j = 0;j < SO_MON;j++) 
                cout << bangDiem[i][j]<<" | ";
            cout << endl;
            found = true;
            break;
        }
    }
    if (!found) cout << "Khong tim thay ten sinh vien!\n";

}

void themSVMoi(int& n) {
    if (n >= MAX_SV) {
        cout << "Si so lop da day!\n";
        return;
    }

    cout << "Nhap ho ten sinh vien moi: ";
    getline(cin, hoTen[n]);

    for (int j = 0;j < SO_MON;j++) {
        cout << "Nhap diem cho mon hoc thu "<<j+1<<": ";
        cin >> bangDiem[n][j];
    }
    cin.ignore();
    n++;
    cout << "Da them sinh vien thanh cong!\n";
}

int main() {
    int n = 8;

    cout << "So diem cao nhat cua tung mon va ho ten sinh vien dat duoc:\n";
    diemMAXTungMon(n);

    SinhVienDTBCaoNhat(n);

    timKiemSV(n);

    themSVMoi(n);

	system("pause");
	return 0;
}