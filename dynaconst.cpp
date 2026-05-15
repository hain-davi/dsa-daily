#include <iostream>
#include <string>
using namespace std;

class Studentbuspass{
private:
    string studentname;
    int nummonths;
    string *months;

public:
    Studentbuspass(string name,int n){
        studentname=name;
        nummonths=n;
        months=new string[nummonths];

        cout<<"Enter the "<<nummonths<<"nonths:"<<endl;
        for(int i=0;i<nummonths;i++){
            cout<<"Months"<<i+1<<":";
            getline(cin,months[i]);
        }
    }

    void display(){
        cout<<"Bus pass for"<<studentname<<endl;
        cout<<"Valid for"<<nummonths<<endl;
        for(int i=0;i<nummonths;i++){
            cout<<months[i];
            if(i!=nummonths-1){
                cout<<",";
            }
            cout<<endl;
        }
    }
    ~Studentbuspass(){
        delete[] months;
        cout<<"Memory freed for "<<studentname<<"'s bus pass.";
    }
};

int main(){
    int n;
    string name;

    cout<<"Enter student name:";
    getline(cin,name);
    cout<<"Enter the number of months:";
    cin>>n;
    cin.ignore();

    Studentbuspass Pass(name,n);
    Pass.display();
}