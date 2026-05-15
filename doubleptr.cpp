#include <iostream>
using namespace std;

void update(int **p2){
    p2=p2+1;
    //anything changes?? -- NO
    // *p2=*p2+1;
    //anything changes?? -- YES
    // **p2=**p2+1;
    //anything changes?? -- YES
}

int main(){
    int i=5;
    int *p=&i;
    int **ptr=&p;
    /*
    cout<<"Everything is okay"<<endl;

    cout<<"Printing p"<<p<<endl;
    // cout<<"address of p"<<&p<<endl;
    cout<<*ptr<<endl;

    cout<<i<<endl;
    cout<<*p<<endl;
    cout<<**ptr<<endl;

    cout<<&i<<endl;
    cout<<p<<endl;
    cout<<*ptr<<endl;

    cout<<&p<<endl;
    cout<<ptr<<endl;
    */

    cout<<endl<<endl;
    cout<<"before "<<i<<endl;
    cout<<"before "<<p<<endl;
    cout<<"before "<<ptr<<endl;
    update(ptr);
    cout<<"after "<<i<<endl;
    cout<<"after "<<p<<endl;
    cout<<"after "<<ptr<<endl;
    cout<<endl<<endl;
}