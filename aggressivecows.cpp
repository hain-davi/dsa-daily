#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;

bool isPossible(vector<int> & stalls, int k, int mid){
    int cowCount=1;
    int lastpos=stalls[0];
    for(int i=0;i<stalls.size();i++){
        if(stalls[i]-lastpos>=mid){
            cowCount++;
            if(cowCount==k){
                return true;
            }
            lastpos=stalls[i];
        }
    }
    return false;
}

int aggressiveCows(vector<int> &stalls,int k){
    sort(stalls.begin(),stalls.end());
    int s=0;
    int n=stalls.size();
    int e=stalls[n-1]-stalls[0];
    int ans=-1;
    int mid=s+(e-s)/2;

    while(s<=e){
        if(isPossible(stalls,k,mid)){
            ans=mid;
            s=mid+1;
        }
        else{
            e=mid-1;
        }
        mid=s+(e-s)/2;
    }
    return ans;
}

int main(){
    vector <int> stalls={4,2,7,1,8};
    int k=5;

    cout<<"count"<<aggressiveCows(stalls,k)<<endl;
}