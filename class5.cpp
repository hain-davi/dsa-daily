#include <iostream>
#include <string>
using namespace std;

class Person{
protected:
    string name;
    int age;
public:
    void getpersondetails(){
        cout<<"Enter name:";
        getline(cin,name);
        cout<<"Enter age:";
        cin>>age;
        cin.ignore();
    }
    void showpersondetails(){
        cout<<"Name:"<<name<<endl;
        cout<<"Age:"<<age<<endl;
    }
};

class Employee:virtual public Person{
protected:
    int empId;
    double salary;
    string department;
public:
    void getemployeedetails(){
        cout<<"Enter Employee ID:";
        cin>>empId;
        cout<<"Enter salary:";
        cin>>salary;
        cin.ignore();
        cout<<"Enter department:";
        getline(cin,department);
    }
    void showemployeedetails(){
        cout<<"Employee ID:"<<empId<<endl;
        cout<<"Department:"<<department<<endl;
        cout<<"Salary:"<<salary<<endl;

    }
};

class Manager:virtual public Employee{
protected:
    double bonus;
public:
    void getmanagerdetails(){
        cout<<"Enter bonus:";
        cin>>bonus;
        cin.ignore();
    }
    double totalsalary(){
        return salary+bonus;
    }
    void showmanagerdetails(){
        cout<<"Department:"<<department<<endl;
        cout<<"Total salary:"<<totalsalary()<<endl;
    }
};
class Engineer:virtual public Employee{
protected:
    string project;
public:
    void getengineerdetails(){
        cout<<"Enter project:";
        getline(cin,project);
    }
    void showengineerdetails(){
        cout<<"Project:"<<project<<endl;
    }
};

class Teamleader:public Manager,public Engineer{
public:
    void showteamleaddetails(){
        cout<<"\n Team Lead details:"<<endl;
        cout<<"Name:"<<name<<endl;
        cout<<"Department:"<<department<<endl;
        cout<<"Project:"<<project<<endl;
        cout<<"Total salary:"<<totalsalary<<endl;
    }
};

int main(){
    Teamleader Tl;
    Tl.getpersondetails();
    Tl.getemployeedetails();
    Tl.getmanagerdetails();
    Tl.getengineerdetails();
    Tl.showteamleaddetails();
}
