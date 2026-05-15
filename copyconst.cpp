#include <iostream>
#include <string>
using namespace std;

class Bus{
private:
    int busno;
    string drivername;
    string route;

public:
    Bus(int b,string n,string r){
        busno=b;
        drivername=n;
        route=r;
    }

    Bus(const Bus & b){
        busno=b.busno;
        drivername=b.drivername;
        route=b.route;
    }

    void display(){
        cout<<"Bus no.:"<<busno<<endl;
        cout<<"Driver name:"<<drivername<<endl;
        cout<<"Route:"<<route<<endl;
    }
};

int main(){
    Bus bus1(1,"Surya","Vakeel bridge to railway station");
    Bus bus2 (bus1);

    bus1.display();
    bus2.display();
}