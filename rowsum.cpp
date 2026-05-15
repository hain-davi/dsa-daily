#include <iostream>
using namespace std;

bool isPresent(int arr[][3],int target,int row,int col ){
    for(int row=0;row<3;row++){
        for(int col=0;col<3;col++){
            if(arr[row][col]==target){
                return 1;
            }
        }
    }
    return 0;
}

void printSum (int arr[][3],int row,int col ){
    cout<<"Printing sum ->"<<endl;
    for(int row=0;row<3;row++){    // for col replace col->row and row->col
        int sum=0;
        for(int col=0;col<3;col++){
            sum+=arr[row][col];
        }
        cout<<sum<<" ";
    }
    cout<<endl;
}

int main(){
    int arr[3][3];

    cout<<"Enter the elements of the array:"<<endl;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            cin>>arr[i][j];
        }
    }

    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }

    cout<<"Enter the target element:"<<endl;
    int target;
    cin>>target;

    if(isPresent(arr,target,3,4)){
        cout<<"found"<<endl;
    }
    else{
        cout<<"not found"<<endl;
    }

    printSum(arr,3,3);
}