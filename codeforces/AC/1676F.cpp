#include<bits/stdc++.h>
using namespace std;
const int MAXN=2e5+1000;
int a[MAXN];
vector<int> aa;
void solve(){
    aa.clear();
    int n,k;
    cin>>n>>k;
    for (int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a, a+n);
    int i = 0;
    while (i<n) {
        int now = i;
        while (a[i]==a[now]&&i<n) {
            i++;
        }
        //cout<<"!"<<i-now<<" "<<a[now]<<endl;
        if (i-now >= k){
            aa.push_back(a[now]);
        }
    }
    int si = aa.size();
    if (si==0){
        cout<<-1<<endl;
        return;
    }
    int l = 0;
    int r = 0;
    int ans = 0;
    int ansl = aa[0];
    int ansr = aa[0];
    while (r+1<si){
        if (aa[r+1]-aa[r] == 1){
            r++;
            if (aa[r]-aa[l] > ans){
                ans = aa[r]-aa[l];
                ansl = aa[l];
                ansr = aa[r];
            }
        }else{
            l = r+1;
            r = r+1;
        }
    }
    cout<<ansl<<' '<<ansr<<endl;
}
int main(){
    int t;
    cin>>t;
    while (t--){
        solve();
    }
}