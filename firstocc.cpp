#include <iostream>
using namespace std;

int firstoccurance(int arr[],int size,int key){
    int start=0;
    int end=size-1;
    int ans=-1;
    int mid=start+(end-start)/2;
    while(start<=end){
        if(arr[mid]==key){
            ans=mid;
            end=mid-1;
        }
        else if(key>arr[mid]){ //go to right side
            start=mid+1;
        }
        else if(key<arr[mid]){  
            end=mid-1;
        }
        mid=start+(end-start)/2;
    }
    return ans;
}

int lastoccurance(int arr[],int size,int key){
    int start=0;
    int end=size-1;
    int ans=-1;
    int mid=start+(end-start)/2;
    while(start<=end){
        if(arr[mid]==key){
            ans=mid;
            start=mid+1;
        }
        else if(key>arr[mid]){ //go to right side
            start=mid+1;
        }
        else if(key<arr[mid]){  
            end=mid-1;
        }
        mid=start+(end-start)/2;
    }
    return ans;
}

int main(){
    int even[10]={1,2,3,3,3,3,3,3,3,5};

    cout<<"First occurance of 3 is at index:"<<firstoccurance(even,10,3)<<endl;
    cout<<"Last occurance of 3 is at index:"<<lastoccurance(even,10,3)<<endl;

}