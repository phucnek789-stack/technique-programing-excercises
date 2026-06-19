#include <iostream>
using namespace std;

char* timKiem(char* s1, char* s2)
{
    int len1 = strlen(s1);
    int len2 = strlen(s2);
    if (len2 == 0 || len1 < len2)
        return NULL;

    for (int i = 0; i <= len1 - len2; i++)
    {
        bool match = true;
        for (int j = 0; j < len2; j++)
            if (s1[i + j] != s2[j])
            {
                match = false;
                break;
            }
        if (match == true)
            return s1 + i;

    }
    return NULL;
}

void dichQuaPhai(char* s, int start, int shift_amount) {
    int len = strlen(s);    

    for (int i = len; i >= start; i--) {
        s[i + shift_amount] = s[i];
    }
}

void dichQuaTrai(char* s, int start, int shift_amount) {
    int len = strlen(s);

    for (int i = start; i <= len; i++) {
        s[i] = s[i + shift_amount];
    }
}

void thayThe(char* s1, char* s2, char* s3) {
    char* vt = timKiem(s1, s2);
    if (!vt) return; 

    int len1 = strlen(s1), len2 = strlen(s2), len3 = strlen(s3);    
    int index = vt - s1; // Vi tri can thay the

    if (len3 > len2) {
        dichQuaPhai(s1, index + len2, len3 - len2); // Dich sang phai neu s3 dai hon s2
    }
    else if (len3 < len2) {
        dichQuaTrai(s1, index + len3, len2 - len3); // Dich sang trai neu s3 ngan hon s2
    }
    
    // Thay the cuoi s3 vao s1 theo vi tri
    for (int i = 0; i < len3; i++) {
        s1[index + i] = s3[i];
    }
}

int main() {
    char* s1 = new char[100];
    char* s2 = new char[100];
    char* s3 = new char[100];
    cout << "Nhap chuoi 1: ";
    cin.getline(s1, 100);
    cout << "Nhap chuoi 2: ";
    cin.getline(s2, 100);
    cout << "Nhap chuoi 3: ";
    cin.getline(s3, 100);
    char* kq = timKiem(s1, s2);
    cout << "Tim thay s2 trong s1 o vi tri: " << &kq << endl;
    thayThe(s1, s2, s3);
    cout << s1 << endl;

    delete[] s1;
    delete[] s2;
    delete[] s3;
    system("pause");
    return 0;
}