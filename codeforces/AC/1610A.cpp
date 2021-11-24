#include<iostream>
using namespace std;
int main(){
    int t;
    cin>>t;
    int n,m;
    while(t--){
        cin>>n>>m;
        if(n==1&&m==1){
            cout<<"0\n";
            continue;
        }
        if(n==1||m==1){
            cout<<"1\n";
            continue;
        }
        cout<<"2\n";
    }
}