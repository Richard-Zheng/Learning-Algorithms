#include <algorithm>
#include <iostream>
using namespace std;
const int MAXAB = 1000000000;
typedef long long ll;
void solve() {
    ll n, a, b;
    cin >> n >> a >> b;

    ll ans = 0;
    if (3 * a < 2 * b) {
        // choose 2
        ans = a * ((n + 2 - 1) / 2);
        if (n >= 3) {
            ans = min(ans, a * ((n - 3 + 2 - 1) / 2) + b);
        }
    } else {
        // choose 3;
        ans = b * ((n + 3 - 1) / 3);
        if (n >= 2) {
            ans = min(ans, b * ((n - 2 + 3 - 1) / 3) + a);
        }
        if (n >= 4) {
            ans = min(ans, b * ((n - 4 + 3 - 1) / 3) + 2 * a);
        }
    }
    cout << ans << endl;
    return;
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}