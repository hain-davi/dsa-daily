#include <iostream>
#include <deque>
using namespace std;

int main(){
    deque<int> d;
    d.push_back(1);
    d.push_back(2);
    
    for(int i:d){
        cout<<i<<" ";
    }
    // d.pop_back();  //d.pop_front();

    cout<<"first index"<<d.at(1)<<endl;
    cout<<"front"<<d.front()<<endl;
    cout<<"last"<<d.back()<<endl;
    cout<<"Empty or not:"<<d.empty()<<endl;

    cout<<"before"<<d.size()<<endl;
    d.erase(d.begin(),d.begin()+1);
    cout<<"after"<<d.size()<<endl;
    
}