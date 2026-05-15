#include <iostream>
using namespace std;

int findduplicate(int arr[],int size){
    int ans=0;
    //XOR all array elements
    for(int i=0;i<size;i++){
        ans=ans^arr[i];
    }

    //XOR numbers from 1 to size-1
    for(int i=1;i<size;i++){
        ans=ans^i;
    }

    return ans;
}
int main(){
    int arr[6]={2,3,1,4,2,5};

    int duplicate=findduplicate(arr,6);

    cout<<"The duplicate element is:"<<duplicaten n  <<endl;

    return 0;
}