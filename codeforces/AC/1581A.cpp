#include <algorithm>
#include <iostream>
typedef long long ll;
using namespace std;
const ll MOD = (1e9) + 7;
int main() {
    int t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        ll ans = 1;
        for (ll i = 3; i <= 2 * n; ++i) {
            ans = (ans * i) % MOD;
        }
        cout << ans << endl;
    }

    return 0;
}