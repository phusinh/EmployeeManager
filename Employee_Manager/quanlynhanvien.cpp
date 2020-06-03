#include "quanlynhanvien.h"
#include <fstream>
quanlynhanvien::quanlynhanvien(void)
{
    n=0;
    x=new nhanvien*[1000];
}


quanlynhanvien::~quanlynhanvien(void)
{
    delete []x;
}
void quanlynhanvien::nhap()
{
    int k;

    cout<<"Enter the number of employees:";
    cin>>k;
    for(int i=0;i<k;i++)
    {
        n++;
        x[i]=new nhanvien;
        x[i]->nhap();
    }

}
void quanlynhanvien::xuat()
{
    cout<<"Number of employees = "<<n<<"\n";
    for(int i=0;i<n;i++)
    {
        cout<<endl;
        x[i]->xuat();
        cout<<endl;
    }
}
void quanlynhanvien::timnv(string a)
{

    for(int i=0;i<n;i++)
    {
        if(x[i]->manv==a){
            x[i]->xuat();
        }
        else{
            cout<<"Employee does not exist :"<<a;
        }
    }
}



