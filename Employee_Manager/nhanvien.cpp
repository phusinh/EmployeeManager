#include "nhanvien.h"
#include <fstream>
nhanvien::nhanvien(void)
{
}
nhanvien::~nhanvien(void)
{
}
void nhanvien::nhap()
{
 cout<<"Name:";fflush(stdin);gets(hoten);
 cout<<"Code:";cin>>manv;
 cout<<"Date(d/m/y):";
 cin>>ngay;cin.ignore();cin>>thang;cin.ignore();cin>>nam;
 cout<<"Adress:";cin>>diachi;

 cout<<"Part";cin>>bophan;
}
void nhanvien::xuat()
{
    ofstream myfile;
    myfile.open ("E:\\C_C++\\PrGiuaki\\out.txt");
    myfile <<"Ma nv:"<<manv<<"_"<<endl<<"Ho ten:"<<hoten<<"_"<<endl<<"ngay sinh: "<<ngay<<"/"<<thang<<"/"<<nam<<"_"<<endl<<"Dia chi:"<<diachi<<"_"<<endl<<"Bo phan :"<<bophan<<endl ;
    myfile.close();
    cout<<"Code:"<<manv<<endl<<"Name:"<<hoten<<endl<<"Date: "<<ngay<<"/"<<thang<<"/"<<nam<<endl<<"Adress:"<<diachi<<endl<<"Part:"<<bophan<<endl;
}
