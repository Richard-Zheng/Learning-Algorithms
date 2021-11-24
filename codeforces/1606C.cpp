#include <cstring>
#include <iostream>
using namespace std;
const int MAXN = 11;
typedef long long ll;
ll a[MAXN];
int time[MAXN];
ll qpow(ll base, ll exp) {
    ll res = 1;
    while (exp) {
        if (exp & 1) {
            res *= base;
        }
        base *= base;
        exp >>= 1;
    }
    return res;
}
void solve() {
    memset(time, 0, sizeof(time));
    ll n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    ll ans = 0;
    ll left = k+1;
    for(int i=0;i<n-1;i++){
        int t=min(left, qpow(10, a[i+1]-a[i])-1);
        cout<<t<<endl;
        left-=t;
        ans+=t*qpow(10, a[i]);
    }
    ans+=left;
    cout << ans << endl;
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}