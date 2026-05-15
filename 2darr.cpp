#include <iostream>
using namespace std;

int main(){
    //create 2D array
    int arr[3][4];
    // int arr[3][4]={1,2,4,2,4,2,6,4,8,0,2,3}; -> row wise input taken
    // int arr[3][4]={{1,11,111,1111},{2,22,222,2222},{3,33,333,3333},{4,44,444,4444}};
    //taking input -> row wise input
    for(int i=0;i<3;i++){
        for(int j=0;j<4;j++){
            cin>>arr[i][j];
        }
    }
    //taking input -> column wise input
    for(int i=0;i<3;i++){
        for(int j=0;j<4;j++){
            cin>>arr[i][j];
        }
    }
    //print 
    for(int i=0;i<4;i++){
        for(int j=0;j<3;j++){
            cout<<arr[j][i]<<" ";
        }
        cout<<endl;
    }


}