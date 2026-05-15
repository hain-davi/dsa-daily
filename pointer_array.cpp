#include <iostream>
using namespace std;

int main(){

    int arr[10]={23,122,41,67};
    cout<<"Size of : "<<sizeof(arr)<<endl;
    cout<<"Size of 1st : "<<sizeof(*arr)<<endl;
    cout<<"Size of 2nd : "<<sizeof(&arr)<<endl;
    int *ptr=&arr[0];
    cout<<"Size of : "<<sizeof(ptr)<<endl;
    cout<<"Size of : "<<sizeof(*ptr)<<endl;
    cout<<"Size of : "<<sizeof(&ptr)<<endl;

    cout<<"address of the first block of array is "<<arr<<endl;  //address of 0th index
    cout<<arr[0]<<endl;  //value at the 0th index 
    cout<<"address of the first block of array is "<<&arr[0]<<endl; //adress of 0th index
    cout<<"Value at 1st index "<<*arr<<endl;
    cout<<"Value at 2nd index "<<*arr+1<<endl;
    cout<<"Value at 3rd index "<<*(arr+1)<<endl;
    cout<<"Value at 4th index "<<(*arr)+1<<endl;
    cout<<"Value at 5th index "<<arr[2]<<endl;
    cout<<"Value at 6th index "<<*(arr+2)<<endl;

    // int i=3;
    // cout<<i[arr]<<endl;

    // int temp[10]={1,2};
    // cout<<sizeof(temp)<<endl;
    // cout<<"1st "<<sizeof(*temp)<<endl; 
    // cout<<"2nd "<<sizeof(&temp)<<endl; 

    int a[20]={1,2,3,4};
    // a=a+1;  error as array is already defined in the symbol table
    cout<<"-> "<<&a[0]<<endl;
    cout<<&a<<endl;
    cout<<a<<endl;

    int *p=&a[0];
    p=p+1; // no error as it will point to the next location
    cout<<p<<endl;
    cout<<*p<<endl;
    cout<<"-> "<<&p<<endl;
    

}