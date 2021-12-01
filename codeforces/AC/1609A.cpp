#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;
typedef long long ll;
const int MAXN = 16;
ll a[MAXN];
void solve() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    ll cnttwo = 0;
    for (int i = 1; i <= n; i++) {
        while (a[i] % 2 == 0) {
            a[i] /= 2;
            cnttwo++;
        }
    }

    sort(a + 1, a + n + 1);
    ll ans = 0;
    for (int i = 1; i < n; i++) {
        ans += a[i];
    }
    ans += (a[n] * pow(2ll, cnttwo));
    cout << ans << endl;
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}