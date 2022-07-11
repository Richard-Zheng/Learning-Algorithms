#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n,m,k;
    cin>>n>>m>>k;
    string a[2];
    cin>>a[0]>>a[1];
    sort(a[0].begin(), a[0].end());
    sort(a[1].begin(), a[1].end());
    int idx[2] = {0};
    int lastadd = -1;
    int addcnt = 0;
    vector<char> ans;
    while (idx[0]<n&&idx[1]<m) {
        int smaller;
        if (a[0][idx[0]] < a[1][idx[1]]) {
            smaller = 0;
        } else if (a[0][idx[0]] == a[1][idx[1]]) {
            if (n < m) {
                smaller = 0;
            } else{
                smaller = 1;
            }
        } else {
            smaller = 1;
        }
        if (lastadd == -1) {
            ans.push_back(a[smaller][idx[smaller]]);
            idx[smaller]++;
            lastadd=smaller;
            addcnt=1;
        } else {
            if (addcnt == k) {
                lastadd = !lastadd;
                ans.push_back(a[lastadd][idx[lastadd]]);
                idx[lastadd]++;
                addcnt = 1;
            } else if (lastadd == smaller) {
                ans.push_back(a[smaller][idx[smaller]]);
                idx[smaller]++;
                lastadd=smaller;
                addcnt++;
            } else {
                ans.push_back(a[smaller][idx[smaller]]);
                idx[smaller]++;
                lastadd=smaller;
                addcnt=1;
            }
        }
    }
    for (auto& x : ans) {
        cout<<x;
    }
    cout<<endl;
}
int main(){
    int t;
    cin>>t;
    while(t--){solve();}
}