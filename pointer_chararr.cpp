#include <iostream>
using namespace std;

int main(){
    int arr[5]={1,2,3,4,5};
    char ch[6]="abcde";

    cout<<arr<<endl;  //returns address
    cout<<ch<<endl;   //returns "abcde" itself

    char *c=&ch[0];
    cout<<c<<endl;  //returns entire string

    char temp = 'z';
    char *p = &temp;
    cout<<p<<endl;
}