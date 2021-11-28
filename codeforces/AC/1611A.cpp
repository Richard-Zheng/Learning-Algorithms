#include<iostream>
#include<string>
using namespace std;
void solve(){
    string n;
    cin>>n;
    if((n[n.size()-1]-'0')%2==0){
        cout<<"0\n";
        return;
    }
    if((n[0]-'0')%2==0){
        cout<<"1\n";
        return;
    }
    for(int i=1;i<n.size()-1;i++){
        if((n[i]-'0')%2==0){
            cout<<"2\n";
            return;
        }
    }
    cout<<"-1\n";
    return;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}