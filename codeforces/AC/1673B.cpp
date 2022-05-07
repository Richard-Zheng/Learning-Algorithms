#include <bits/stdc++.h>
using namespace std;
const int MAXCHAR = 'z' + 10;
int cnt[MAXCHAR];
void solve() {
    memset(cnt, 0, sizeof(cnt));
    string s;
    cin>>s;
    for (int i=0;i<s.size();i++){
        cnt[s[i]]++;
    }
    bool flag = true;
    for (int i='a';i<='z';i++){
        for (int j='a';j<='z';j++){
            if (i==j) {
                continue;
            }
            if (cnt[i] == 0 || cnt[j] == 0){
                continue;
            }
            char lst = 0;
            for (int k=0;k<s.size();k++){
                if (s[k]==i||s[k]==j){
                    if (lst==s[k]){
                        flag=false;
                        break;
                    }
                    lst = s[k];
                }
            }
        }
    }
    if (flag){
        cout<<"YES"<<endl;
    }else{
        cout<<"NO"<<endl;
    }
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}