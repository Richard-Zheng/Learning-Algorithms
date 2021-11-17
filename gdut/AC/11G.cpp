#include <iostream>
using namespace std;
const int MOD = (1e9) + 7;
typedef long long ll;
ll qpow(ll base, ll exp, ll mod) {
    int result = 1;
    while (exp>0) {
        if (exp & 1) {
            result = (result*base) % mod;
        }
        exp = exp>>1;
        base = (base * base) % mod;
    }
    return result;
}
void solve() {
    int n, x;
    cin >> n >> x;
    if ((x == 1) && (n == 1)) {
        cout << 0 << endl;
        return;
    } else {
        cout << (qpow(2, x - 1, MOD) - 1 + qpow(2, n - x, MOD) - 1) % MOD << endl;
    }
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}