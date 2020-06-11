#include "Employee.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdlib.h>
#include <iomanip>
using std::setw;
Employee::Employee()
{
    id = "";
    name = "";
    birthday = "";
    adress = "";
    team = "";
    date="";
    status="";
}

Employee::Employee(string id, string name, string birthday, string adress, string team,string date,string status)
{
    this->id = id;
    this->name = name;
    this->birthday = birthday;
    this->adress = adress;
    this->team = team;
    this->date=date;
    this->status=status;
}

void Employee::setId(string id)
{
    this->id = id;
}
void Employee::setName(string name)
{
    this->name = name;
}
void Employee::setBirthday(string birthday)
{
    this->birthday = birthday;
}
void Employee::setAdress(string adress)
{
    this->adress = adress;
}
void Employee::setTeam(string team)
{
    this->team = team;
}
void Employee::setDate(string date)
{
    this->date = date;
}
void Employee::setStatus(string status)
{
    this->status = status;
}

string Employee::getId()
{
    return this->id;
}
string Employee::getBirthday()
{
    return this->birthday;
}
string Employee::getAdress()
{
    return this->adress;
}
string Employee::getTeam()
{
    return this->team;
}
string Employee::getName()
{
    return this->name;
}
string Employee::getDate()
{
    return this->date;
}
string Employee::getStatus()
{
    return this->status;
}


Employee searchEmployee(string file, string id)
{
    Employee e;
    string line;
    ifstream fileInput(file, ios::in);
    if (fileInput.is_open())
    {
        while (!fileInput.eof())
        {
            getline(fileInput, line);
            string epl = line;
            istringstream stm(epl);
            string token;
            getline(stm, token, ',');
            if (token == id)
            {
                e.setId(id);
                getline(stm, token, ',');
                e.setName(token);
                getline(stm, token, ',');
                e.setBirthday(token);
                getline(stm, token, ',');
                e.setAdress(token);
                getline(stm, token, ',');
                e.setTeam(token);
                getline(stm, token, ',');
                e.setDate(token);
                getline(stm, token, ',');
                e.setStatus(token);

            }

        }
        fileInput.close();
    }
    return e;
}
int valiDate(string birthday)
{
    stringstream ss(birthday);
    int day, month, year;

    ss >> day >> month >> year;

    if (year >= 1000 && year <= 3000)
    {
        if ((month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) && day > 0 && day <= 31)
            return 1;
        else
            if (month == 4 || month == 6 || month == 9 || month == 11 && day > 0 && day <= 30)
                return 1;
            else
                if (month == 2)
                {
                    if ((year % 400 == 0 || (year % 100 != 0 && year % 4 == 0)) && day > 0 && day <= 29)
                    {
                        if (day > 0 && day <= 28)
                            return 1;
                        else
                            return 0;
                    }

                }
                else
                    return 0;
    }
    else
        return 0;
    return 0;
}

int kiemtraId(string file, string id)
{
    string line;
    ifstream fileInput(file, ios::in);
    if (fileInput.is_open())
    {
        while (!fileInput.eof())
        {
            getline(fileInput, line);
            string epl = line;
            istringstream stm(epl);
            string token;
            getline(stm, token, ',');
            if (token == id)
            {
                return 0;
            }

        }
        fileInput.close();
    }
    return 1;
}

void writeDataToFile(string file)
{
    ofstream myfile(file, ios::app);
    if (myfile.is_open())
    {
        string id;
        string name, birthday, adress, team;

            cout << "Nhap ma nhan vien (VD: 01): ";
            cin >> id;
            while (kiemtraId(file, id) == 0) {
                cout << "Ma nhan vien bi trung, moi ban nhap lai:  \n";
                cout << "Nhap ma nhan vien: ";
                cin >> id;
            }

            cout << "Nhap ten: ";
            cin.ignore();
            getline(cin, name);

            cout << "Nhap ngay thang nam sinh: ";
            getline(cin, birthday);
            while (valiDate(birthday) == 0)
            {
                cout << "Ban chua nhap dung dinh dang ngay thang, VD: 14 5 1999 \n";
                cout << "Nhap ngay thang nam sinh: ";
                getline(cin, birthday);
            }

            cout << "Nhap dia chi: ";
            getline(cin, adress);
            while (adress.empty())
            {
                cout << "Khong duoc bo trong dia chi \n";
                cout << "Moi ban nhap lai dia chi \n";
                getline(cin, adress);
            }

            cout << "Nhap bo phan cong tac: ";
            getline(cin, team);
            while (team.empty())
            {
                cout << "Khong duoc bo trong bo phan cong tac \n";
                cout << "Moi ban nhap lai bo phan cong tac \n";
                cin >> team;
            }
            cout << "-------------------------------------------------" << endl;

            //myfile << id + "," + name + "," + birthday + "," + adress + "," + team << endl;
            myfile << id << "," << name << "," << birthday << "," << adress << "," << team << endl;

        myfile.close();
    }
    else cout << "Khong the mo duoc file" << endl;

}



void print(Employee e)
{
    cout << "Ma NV: " << e.getId() << endl;
    cout << "Ten NV: " << e.getName() << endl;
    cout << "Ngay thang nam sinh: " << e.getBirthday() << endl;
    cout << "Dia chi: " << e.getAdress() << endl;
    cout << "Bo phan cong tac: " << e.getTeam() << endl;
    cout << "Ngay di lam: " << e.getDate() << endl;
    cout << "Trang thai: " << e.getStatus() << endl;


}
void readCSV(){
    Employee e[10000];
    Employee employee;
    ifstream inFile("ImportData.csv");
    string line;
    int linenum = 0;
    while (getline (inFile, line))
    {
        istringstream linestream(line);
        string item;
        //use this to get up to the first comma
        getline(linestream, item, ',');
        employee.setId(item);
        getline(linestream, item, ',');
        employee.setName(item);
        getline(linestream, item, ',');
        employee.setBirthday(item);
        getline(linestream, item, ',');
        employee.setAdress(item);
        getline(linestream, item, ',');
        employee.setTeam(item);

        //convert to a string stream and then put in id.
//        getline(linestream, item, ',');
//        employee.getBirthday() = item;
//        getline(linestream, item, ',');
//        employee.getAdress() = item;
//        getline(linestream, item, ',');
//        employee.getTeam() = item;
        //add the new employee data to the database
        e[linenum] = employee;
        linenum++;
    }
    for (int i=0;i<5001;i++) {
       cout<<"\n"<<e[i].getId()<<setw(30)<<e[i].getName()<<setw(25)<<e[i].getBirthday()<<setw(35)<<e[i].getAdress()<<setw(20)<<e[i].getTeam()<<"\n";
    }
}
void writeDataStatus(string file)
{
    bool check=false;
    ofstream myfile(file, ios::app);
    if (myfile.is_open())
    {
        string id;string date;string status;

            cout << "Nhap ma nhan vien (VD: 01): ";
            cin >> id;
           if (kiemtraId(file, id) == 0) {
//                cout << "Ma nhan vien da ton tai, moi ban nhap lai:  \n";
//                cout << "Nhap ma nhan vien: ";
                cout << "Nhap ngay thang nam sinh: ";
                getline(cin, date);
                while (valiDate(date) == 0)
                {
                    cout << "Ban chua nhap dung dinh dang ngay thang, VD: 14 5 1999 \n";
                    cout << "Nhap ngay thang nam sinh: ";
                    getline(cin, date);
                }

                cout << "Nhap trang thai : ";
                getline(cin, status);
                while (status.empty())
                {

                    cout << "Khong duoc bo trong dia chi \n";
                    cout << "Moi ban nhap lai dia chi \n";
                }
                if(status.compare("DL")!=0||status.compare("DLNN")!=0||status.compare("N")!=0||status.compare("NP")!=0){
                         cout<<"Khong dung dinh dang\n";
                         check=true;

                }
                if(check==true){
                    cout << "Nhap trang thai : \n";
                    getline(cin, status);
                }

                cout << "-------------------------------------------------" << endl;

                //myfile << id + "," + name + "," + birthday + "," + adress + "," + team << endl;
                myfile << id << "," << date << "," << status << endl;

            myfile.close();
            }

     }

//            cout << "Nhap ngay thang nam sinh: ";
//            getline(cin, date);
//            while (valiDate(date) == 0)
//            {
//                cout << "Ban chua nhap dung dinh dang ngay thang, VD: 14 5 1999 \n";
//                cout << "Nhap ngay thang nam sinh: ";
//                getline(cin, date);
//            }

//            cout << "Nhap trang thai : ";
//            getline(cin, status);
//            while (status.empty())
//            {

//                cout << "Khong duoc bo trong dia chi \n";
//                cout << "Moi ban nhap lai dia chi \n";
//            }
//            if(status.compare("DL")!=0||status.compare("DLNN")!=0||status.compare("N")!=0||status.compare("NP")!=0){
//                     cout<<"Khong dung dinh dang\n";
//                     check=true;

//            }
//            if(check==true){
//                cout << "Nhap trang thai : \n";
//                getline(cin, status);
//            }

//            cout << "-------------------------------------------------" << endl;

//            //myfile << id + "," + name + "," + birthday + "," + adress + "," + team << endl;
//            myfile << id << "," << date << "," << status << endl;

//        myfile.close();
//    }
//    else cout << "Khong the mo duoc file" << endl;

}
int main()
{
    string filePath = "test.txt";
    int choice;
    string y;

    do
    {
        cout << "============================================== \n";
        cout << "= 1 - Nhap thong tin nhan vien               = \n";
        cout << "= 2 - Tim thong tin nhan vien                = \n";
        cout << "= 3 - Moi ban in ra danh sach                = \n";
        cout << "= 4 - Nhap thong tin diem danh               = \n";
        cout << "============================================== \n";
        cout << "Chon chuc nang (1-4): ";
        cin >> choice;
        switch (choice)
        {
        case 1:
        {
            cout << "Moi nhap thong tin nhan vien: \n";
            writeDataToFile(filePath);
            system("pause");;
        }
        break;

        case 2:
        {
            string id;
            cout << "Moi nhap ma nhan vien can tim kiem: ";
            cin >> id;
            while (kiemtraId(filePath, id) != 0) {
                cout << "Ma nv ban tim kiem khong ton tai \n" ;
                cout << "Moi ban nhap lai ma nhan vien can tim kiem: ";
                cin >> id;
            }
            cout << "Thong tin cua nhan vien co ma " << id << endl;
            print(searchEmployee(filePath, id));
        }
        break;
        case 3:
        {
            cout << "Moi ban in ra danh sach : \n";
            readCSV();
            system("pause");;
        }
        case 4:
        {
            cout << "Moi nhap thong tin nhan vien: \n";
            writeDataStatus(filePath);
            system("pause");;
        }
        break;

        default:
            cout << "Khong hop le, moi nhan C de tiep tuc" << endl;
            cin >> y;
            break;
    }
    }while (choice == 1 || choice == 2||choice == 3 || choice == 4 || y == "c");

    return 0;
}


