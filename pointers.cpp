#include <iostream>
using namespace std;

int main(){
    int num=5;
    cout<<num<<endl;

    //address of operator - > &
    cout<<"Address of num is"<<&num<<endl;

    int *ptr=&num;
    cout<<"Value is : "<<*ptr<<endl;
    cout<<"Address is : "<<ptr<<endl;

    double d=4.3;
    double *p2=&d;

    cout<<"Value is : "<<*p2<<endl;
    cout<<"Address is : "<<p2<<endl;

    cout<<"Size of integer is : "<<sizeof(num)<<endl;
    cout<<"Size of pointer is : "<<sizeof(ptr)<<endl;
    cout<<"Size of pointer is : "<<sizeof(p2)<<endl;

    //pointer to int is created, and pointing to some garbage address
    //int *p=; //bad practice
    //int *p=0; //null pointer leads to segmentation fault

    //cout<<*p<<endl;

    int i=5;
    int*q=&i;
    cout<<q<<endl;
    cout<<*q<<endl;

    int *p=0;
    p=&i;

    cout<<p<<endl;
    cout<<*p<<endl;

}