#include <iostream>
using namespace std;
long long n, k;
void solve() {
    cin >> n >> k;
    long long cur = 1;
    long long ans = 0;
    while (cur < k) {
        ans++;
        cur += cur;
    }
    cout << ans + (n - cur + k - 1) / k << endl;
    // 向上取整除法: x/y = [(x+y-1)/y]
}
signed main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}