#ifndef NHANVIEN_H
#define NHANVIEN_H
#pragma once
#include<iostream>
using namespace std;
class nhanvien
{
public:
 string manv;
 char hoten[100];
 int ngay,thang,nam;
 string diachi;
 string bophan;

public:
 nhanvien(void);
 ~nhanvien(void);
 virtual void nhap();
 virtual void xuat();
};
#endif // NHANVIEN_H
