#include <iostream>
using namespace std;

void selectionsort(int arr[],int n){
    for(int i=0;i<n;i++){
        int minIndex=i;
        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[minIndex])
            minIndex=j;
        }
        swap(arr[minIndex],arr[i]);
    }
}

int main(){
    int arr[5]={2,5,9,1,4};

    selectionsort(arr,5);

    cout<<"Sorted arr:"<<endl;
    for(int i = 0; i < 5; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}