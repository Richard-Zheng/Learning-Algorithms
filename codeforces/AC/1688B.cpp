#include <algorithm>
#include <cmath>
#include <iostream>
#include <limits>
using namespace std;
const int MAXN = 2e5 + 1;
int a[MAXN];
void solve() {
    int n;
    cin >> n;
    int hasodd = 0;
    int cnteven = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] & 1) {
            hasodd = 1;
        } else {
            cnteven++;
        }
    }
    if (hasodd) {
        cout << cnteven << endl;
    } else {
        int ans = numeric_limits<int>::max();
        for (int j = 0; j < n; j++) {
            int i;
            for (i = 1; i <= 30; i++) {
                if (a[j] % (1 << i)) {
                    break;
                }
            }
            ans = min(ans, i);
        }
        cout << ans + cnteven - 2 << endl;
    }
    return;
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}