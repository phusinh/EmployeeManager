#pragma once
#include <string>

using namespace std;
class Employee
{
    private:
        string id;
        string name;
        string birthday;
        string adress;
        string team;
        string date;
        string status;
    public:
        Employee();
        Employee(string id, string name, string birthday, string adress, string team,string date,string status);

        void setId(string id);
        void setName(string name);
        void setBirthday(string birthday);
        void setAdress(string adress);
        void setTeam(string team);
        void setDate(string date);
        void setStatus(string status);

        string getId();
        string getName();
        string getBirthday();
        string getAdress();
        string getTeam();
        string getDate();
        string getStatus();
};

