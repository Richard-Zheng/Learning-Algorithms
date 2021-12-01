#include <algorithm>
#include <iostream>
using namespace std;
const int MAXN = 101;
int a[MAXN];
void solve() {
    int n, l, r, k;
    cin >> n >> l >> r >> k;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a, a + n);
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] < l || a[i] > r) {
            continue;
        }
        if (k >= a[i]) {
            k -= a[i];
            ans++;
        }
    }
    cout << ans << endl;
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}