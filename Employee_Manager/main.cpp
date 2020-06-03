#include <iostream>
#include "nhanvien.h"
using namespace std;

int main() {
    int key;
    char fileName[] = "sinhvien.txt";
    NV arrayNV[MAX];
    int soluongNV = 0;
    int idCount = 0;

    // nhap danh sach nhanvien tu file
    soluongNV = docFile(arrayNV, fileName);
    if(soluongNV > 0){
        cout << "\nDanh sach nhanvien.";
        showStudent(arrayNV, soluongNV);
    }else{
        cout << "\nSanh sach nhanvien trong!";
    }
    while(true) {
        cout << "CHUONG TRINH QUAN LY nhanvien C/C++\n";
        cout << "*************************MENU**************************\n";
        cout << "**  1. Them nhanvien.                               **\n";
        cout << "**  2. Tim kiem nhanvien theo ten.                  **\n";
        cout << "*******************************************************\n";
        cout << "Nhap tuy chon: ";
        cin >> key;
        switch(key){
            case 1:
                cout << "\n1. Them nhanvien.";
                idCount++;
                nhapNV(arrayNV, idCount, soluongNV);
                printf("\nThem nhanvien thanh cong!");
                soluongNV++;
                ghiFile(arrayNV, soluongNV, fileName);
                pressAnyKey();
                break;

            case 2:
                if(soluongNV > 0) {
                    cout << "\n4. Tim kiem nhanvien theo ten.";
                    char strTen[30];
                    cout << "\nNhap ten de tim kiem: "; fflush(stdin); gets(strTen);
                    timKiemTheoTen(arrayNV, strTen, soluongNV);
                }else{
                    cout << "\nSanh sach nhanvien trong!";
                }
                pressAnyKey();
                break;
            case 0:
                cout << "\nBan da chon thoat chuong trinh!";
                getch();
                return 0;
            default:
                cout << "\nKhong co chuc nang nay!";
                cout << "\nHay chon chuc nang trong hop menu.";
                pressAnyKey();
                break;
        }
    }
}
