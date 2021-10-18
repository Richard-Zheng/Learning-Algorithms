#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;
const int MAXN = 101;
const int MAXSUM = 20000;
int a[MAXN];
int n;

bool is_prime[MAXSUM];
int prime[MAXSUM];
void pre(int m) {
    memset(is_prime, 1, sizeof(is_prime));
    int cnt = 0;
    for (int i = 2; i <= m; i++) {
        if (is_prime[i]) {
            prime[++cnt] = i;
        }
        for (int j = 1; j <= cnt && i * prime[j] <= m; j++) {
            is_prime[i * prime[j]] = 0;
            if (i % prime[j] == 0) {
                break;
            }
        }
    }
}
void solve() {
    cin >> n;
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        sum += a[i];
    }
    if (is_prime[sum]) {
        for (int i = 1; i <= n; i++) {
            if (!is_prime[sum - a[i]]) {
                cout << n - 1 << '\n';
                for (int j = 1; j <= n; j++) {
                    if (j == i) {
                        continue;
                    }
                    cout << j << ' ';
                }
                cout << '\n';
                break;
            }
        }
    } else {
        cout << n << '\n';
        for (int i = 1; i <= n; i++) {
            cout << i << ' ';
        }
        cout << '\n';
    }
}
int main() {
    pre(MAXSUM);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}