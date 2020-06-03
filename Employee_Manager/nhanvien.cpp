#include "nhanvien.h"
#include<conio.h>
#include<stdio.h>
#include <iostream>
#include <string.h>
#define MAX 100
using namespace std;

typedef NhaNVien NV;
void nhapThongTinNV(NV &NV, int id) {
    cout << "\n Nhap ten: "; fflush(stdin); gets(NV.ten);
    cout << " Nhap gioi tinh: "; gets(NV.gioiTinh);
    cout << " Nhap tuoi: "; cin >> NV.tuoi;
    cout << " Nhap diem Toan: "; cin >> NV.diemToan;
    cout << " Nhap diem Ly: "; cin >> NV.diemLy;
    cout << " Nhap diem Hoa: "; cin >> NV.diemHoa;
    NV.id = id;
}

void nhapNV(NV a[], int id, int n) {
    printLine(40);
    printf("\n Nhap Nhan vien thu %d:", n + 1);
    nhapThongTinNV(a[n], id);
    printLine(40);
}
int xoaTheoID(NV a[], int id, int n) {
    int found = 0;
    for(int i = 0; i < n; i++) {
        if (a[i].id == id) {
            found = 1;
            printLine(40);
            for (int j = i; j < n; j++) {
                a[j] = a[j+1];
            }
            cout << "\n Da xoa NV co ID = " << id;
            printLine(40);
            break;
        }
    }
    if (found == 0) {
        printf("\n Nhan vien co ID = %d khong ton tai.", id);
        return 0;
    } else {
        return 1;
    }
}

void timKiemTheoTen(NV a[], char ten[], int n) {
    NV arrayFound[MAX];
    char tenNV[30];
    int found = 0;
    for(int i = 0; i < n; i++) {
        strcpy(tenNV, a[i].ten);
        if(strstr(strupr(tenNV), strupr(ten))) {
            arrayFound[found] = a[i];
            found++;
        }
    }
    showStudent(arrayFound, found);
}

void showStudent(NV a[], int n) {
    printLine(100);
    cout <<"\n\STT\tID\tHo va ten\tGioi tinh\tTuoi\tToan\tLy\tHoa\tDiem TB\tHoc luc";
    for(int i = 0; i < n; i++) {
        // in Nhan vien thu i ra man hinh
        printf("\n %d", i + 1);
        printf("\t%d", a[i].id);
        printf("\t%s", a[i].ten);
        printf("\t\t%s", a[i].gioiTinh);
        printf("\t\t%d", a[i].tuoi);
        printf("\t%.2f\t%.2f\t%.2f", a[i].diemToan, a[i].diemLy, a[i].diemHoa);
        printf("\t%.2f", a[i].diemTB);
        printf("\t%s", a[i].hocluc);
    }
    printLine(100);
}
int docFile(NV a[], char fileName[]) {
    FILE * fp;
    int i = 0;
    fp = fopen (fileName, "r");
    while (fscanf(fp, "%5d%30s%5s%5d%10f%10f%10f%10f%10s\n", &a[i].id, &a[i].ten,
            &a[i].gioiTinh, &a[i].tuoi, &a[i].diemToan, &a[i].diemLy, &a[i].diemHoa,
            &a[i].diemTB, &a[i].hocluc) != EOF) {
       i++;
    }
    cout << " So luong Nhan vien co san trong file la: " << i << endl;
    fclose (fp);
    return i;
}

void ghiFile(NV a[], int n, char fileName[]) {
    FILE * fp;
    fp = fopen (fileName,"w");
    for(int i = 0;i < n;i++){
        fprintf(fp, "%5d%30s%5s%5d%10f%10f%10f%10f%10s\n", a[i].id, a[i].ten,a[i].gioiTinh,
            a[i].tuoi, a[i].diemToan, a[i].diemLy, a[i].diemHoa, a[i].diemTB, a[i].hocluc);
    }
    fclose (fp);
}

void printLine(int n) {
    cout << endl;
    for (int i = 0; i < n; i++) {
        cout << "_";
    }
    cout << endl;
}

void pressAnyKey() {
    cout << "\n\nBam phim bat ky de tiep tuc...";
    getch();
    system("cls");
}
