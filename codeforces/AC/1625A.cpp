#include <cstring>
#include <iostream>
using namespace std;
const int MAXN = 101;
int x[MAXN];
int cnt[MAXN];
void solve() {
    memset(cnt, 0, sizeof(cnt));
    int n, l;
    cin >> n >> l;
    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }
    int res = 0;
    for (int i = 0; i < l; i++) {
        for (int j = 0; j < n; j++) {
            cnt[i] += (x[j] >> i) & 1;
        }
        if (cnt[i] > (n / 2)) {
            res |= (1 << i);
        }
    }
    cout << res << '\n';
    return;
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
