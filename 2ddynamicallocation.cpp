#include <iostream>
using namespace std;

int main(){
    int n;
    cin>>n;

    int ** arr=new int*[n];
    for(int i=0;i<n;i++){
        arr[i]=new int [n];
    }

    for(int i=0;i<n;i++){
        for(int j=0;i<n;j++){
            cin>>arr[i][j];
        }
    }
    cout<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;i<n;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    
}