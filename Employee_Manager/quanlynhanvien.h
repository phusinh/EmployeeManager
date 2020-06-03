#ifndef QUANLYNHANVIEN_H
#define QUANLYNHANVIEN_H
#pragma once
#include"nhanvien.h"
#include<vector>
using namespace std;
class quanlynhanvien
{
private:
 nhanvien **x;
 int n;
public:
 quanlynhanvien(void);
 ~quanlynhanvien(void);
 void nhap();
 void xuat();
 void timnv(string a);
 void xuatfile();
};
#endif // QUANLYNHANVIEN_H
