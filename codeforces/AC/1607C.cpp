#include <algorithm>
#include <iostream>
#include <limits>
using namespace std;
const int MAXN = 2e5;
int a[MAXN];
int sum[MAXN];
void solve() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a, a + n);
    sum[0] = a[0];
    for (int i = 1; i < n; i++) {
        sum[i] = sum[i - 1] + (a[i] - sum[i - 1]);
    }

    int ans = numeric_limits<int>::min();
    for (int i = 0; i < n; i++) {
        ans = max(ans, a[i] - sum[i - 1]);
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