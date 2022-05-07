#include<bits/stdc++.h>
using namespace std;
const int MAXC = 'z';
int cnt[MAXC];
void solve(){
    memset(cnt, 0, sizeof(cnt));
    string s;
    cin>>s;
    for (int i=0;i<s.length();i++){
        cnt[s[i]]++;
    }
    bool flag = true;
    for (int i=0;i<s.length();i++){
        //cout<<s[i]<<": "<<cnt[s[i]]<<endl;
        if (cnt[s[i]]==1){
            flag = false;
        }
        if (flag) {
            cnt[s[i]]--;
            continue;
        }
        cout<<s[i];
        cnt[s[i]]--;
    }
    cout<<endl;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}