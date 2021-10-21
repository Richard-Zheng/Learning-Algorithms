#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
char s[1001];
char as[1001];
void solve(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>s[i];
        as[i]=s[i];
    }
    sort(as, as+n);
    int ans=0;
    for (int i =0; i<n;i++){
        if(s[i]!=as[i]){
            ans++;
        }
    }
    cout<<ans<<'\n';
}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}