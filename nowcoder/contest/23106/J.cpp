#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;
const int MAXAB = (1e4) + 1;
int va[MAXAB];
int vb[MAXAB];
int a, b, n;
void solve() {
    memset(va, 0, sizeof(va));
    memset(vb, 0, sizeof(vb));
    cin >> a >> b >> n;
    for (int i = 1; i <= a; i++) {
        cin >> va[i];
    }
    for (int i = 1; i <= b; i++) {
        cin >> vb[i];
    }
    if (a < (n - (n / 2))) {
        cout << "-1\n";
        return;
    }
    sort(va + 1, va + 1 + a, greater<int>());
    sort(vb + 1, vb + 1 + b, greater<int>());
    int var = n;
    int vbr = 0;
    for (int i = 1; i <= n / 2; i++) {
        if (vb[i] > va[var]) {
            vbr = i;
            var--;
        } else {
            break;
        }
    }
    if (var > a) {
        cout << "-1\n";
        return;
    }
    int ans = 0;
    for (int i = 1; i <= var; i++) {
        ans += va[i];
    }
    for (int i = 1; i <= vbr; i++) {
        ans += vb[i];
    }
    cout << ans << '\n';
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}