#include<iostream>
using namespace std;
typedef long long ll;
const int MAXN = 200000;
ll a[MAXN];
ll diff[MAXN];
void solve(){
    ll n;
    cin>>n;
    for (int i=1;i<=n;i++){
        cin>>a[i];
        diff[i] = a[i]-a[i-1];
    }
    ll ans = 0;
    for (int i=2;i<=n;i++){
        ans += abs(diff[i]);
        if (diff[i] > 0) {
            diff[i] = 0;
        } else {
            diff[1] += diff[i];
            diff[i] -= diff[i];
        }
    }
    cout<< ans + abs(diff[1]) << endl;
}
int main(){
    int t;
    cin>>t;
    while(t--){solve();}
}