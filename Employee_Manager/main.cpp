#include"quanlynhanvien.h"
#include<fstream>
int main()
{
    string n;
    int ch;
    quanlynhanvien x;
    do{ cout<<"\n\t------------------MENU------------------";
        cout<<"\n\t|1.Add Employee                          |";
        cout<<"\n\t|2.Search Employee                       |";
        cout<<"\n\t|3.Exit                                 |";
        cout<<"\n\t****************************************";
        cout<<"\n\tEnter choice: ";
        cin >> ch;
        cout << endl;

        switch(ch){
            case 1:

            x.nhap();

                break;

                        case 2:
                            cout<<"Enter the employee code :";
                            cin>>n;
                            x.timnv(n);

                                 break;
                            }


    }while(ch!=3);

    return 0;
}
