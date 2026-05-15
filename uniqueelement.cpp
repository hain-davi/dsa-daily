#include <iostream>
using namespace std;

int findunique(int arr[],int size){
    int ans=0;
    for(int i=0;i<size;i++){
        ans=ans^arr[i];
    }
    return ans;
}
int main(){
    int arr[9]={2,2,3,4,3,4,6,7,6};

    int unique=findunique(arr,9);

    cout<<"The unique element is:"<<unique<<endl;
}