#include <iostream>
using namespace std;

int main(){
    int num=1;
    int ch='1';
    switch(num){
        case 1:cout<<"First"<<endl;
        break;
        case 2:cout<<"Second"<<endl;
        break;
        default:cout<<"It is default case"<<endl;
    }
    cout<<endl;
    switch(ch){
        case 1:cout<<"Number"<<endl;
        break;
        case '1':cout<<"Character"<<endl;
        break;
        default:cout<<"It is default case"<<endl;
    }
    cout<<endl;
    switch(ch){
        case 1:cout<<"Number"<<endl;
               cout<<"First"<<endl;
               break;
        case '1':switch(num){
                    case 1:cout<<"Value of num is:"<<num<<endl;
                    break;
                }
                break;
        default:cout<<"It is default case"<<endl;
    }
    cout<<endl;
}