#include<iostream>
using namespace std;
const int MAXN = 101;
int a[MAXN];
void solve(){
    int n;
    cin>>n;
    for (int i=1;i<=n;i++){
        cin>>a[i];
    }
    int off = 0;
    for (int i=1;i<=n;i++){
        if(a[i]>(i+off)){
            off+=(a[i]-(i+off));
        }
    }
    cout<<off<<endl;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}