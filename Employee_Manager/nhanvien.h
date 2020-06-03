#ifndef A_H
#define A_H
#include<conio.h>
#include<stdio.h>
#include <iostream>
#include <string.h>
#define MAX 100
using namespace std;

struct NhaNVien {
    int id;
    char maNV;
    char ten[30];
    char gioiTinh[5];
    int tuoi;
    int ngay,thang,nam;
    string diachi;
    string bophan;
    float diemToan;
    float diemLy;
    float diemHoa;
    float diemTB = 0;
    char hocluc[10] = "-";
};

typedef NhaNVien NV;

void printLine(int n);
void nhapThongTinNV(NV &NV, int id);
void nhapNV(NV a[], int id, int n);
void timKiemTheoTen(NV a[], char ten[], int n);
void showStudent(NV a[], int n);
int docFile(NV a[], char fileName[]);
void ghiFile(NV a[], int n, char fileName[]);
void pressAnyKey();
#endif // A_H
