#include <iostream>
using namespace std;

void print(int *p){
    cout<<*p<<endl; // p will give adress while *p will give value at the address
}
void update(int *p){
    // p=p+1; //gives the address
    // cout<<"inside"<<p<<endl;
    *p=*p+1; //updates the value 
}

int getSum(int arr[],int n){ // *arr comes not the actual arr[]
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=arr[i];
    }
    return sum;
}

int main(){
    int value = 5;
    int *p = &value;
    // print(p);
    cout<<"Before"<<p<<endl; // *p gives the value before update
    update(p);
    cout<<"After"<<p<<endl;  // *p gives the value after update

    int arr[5]={1,2,3,4,5};
    cout<<"Sum is "<<getSum(arr,5)<<endl;
}