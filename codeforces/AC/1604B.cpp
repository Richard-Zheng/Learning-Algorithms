#include<iostream>
using namespace std;
const int MAXN = 1e5;
int a[MAXN];
void solve(){
    int n;
    cin>>n;
    for (int i=0;i<n;i++){
        cin>>a[i];
    }
    if(n%2==0){
        cout<<"YES"<<endl;
        return;
    }
    for (int i = 1;i<n;i++){
        if(a[i-1]>=a[i]){
            cout<<"YES"<<endl;
            return;
        }
    }
    cout<<"NO"<<endl;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}