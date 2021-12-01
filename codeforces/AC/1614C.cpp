#include <cstring>
#include <iostream>
using namespace std;
typedef long long ll;
const int MAXA = (1e6) + 1;
const int MAXN = (2e5) + 1;
bool is_prime[MAXA];
int prime[MAXA];
int cnt;
int sieve(int n) {
    cnt = 0;
    memset(is_prime, 1, sizeof(is_prime));
    is_prime[1] = 0;
    for (int i = 2; i < n; i++) {
        if (is_prime[i]) {
            prime[++cnt] = i;
        }
        for (int j = 1; j <= cnt && i * prime[j] < n; j++) {
            is_prime[i * prime[j]] = false;
            if (i % prime[j] == 0) {
                break;
            }
        }
    }
    return cnt;
}
int a[MAXN];
int pre[MAXN] = {0};
int suf[MAXN] = {0};
void solve() {
    int n, e;
    cin >> n >> e;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    memset(pre, 0, sizeof(pre));
    memset(suf, 0, sizeof(suf));
    for (int i = 1; i <= n; i++) {
        if (a[i] == 1) {
            if (i <= e) {
                pre[i] = 1;
            } else {
                pre[i] = pre[i - e] + 1;
            }
        }
    }
    for (int i = n; i >= 1; i--) {
        if (a[i] == 1) {
            if (i + e > n) {
                suf[i] = 1;
            } else {
                suf[i] = suf[i + e] + 1;
            }
        }
    }
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        if (is_prime[a[i]]) {
            ll sufi = 0, prei = 0;
            if (i > e) {
                prei= pre[i - e];
            }
            if (i + e <= n) {
                sufi= suf[i + e];
            }
            ans += (sufi + prei + sufi * prei);

        }
    }
    cout << ans << endl;
}
int main() {
    sieve(MAXA);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}