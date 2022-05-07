#include <bits/stdc++.h>
using namespace std;
const int MAXN = 4e4;
const int MOD = 1e9 + 7;
int dp[MAXN + 1];
int qpow(int base, int exp) {
    int result = 1;
    int tmp = 1;
    while (exp) {
        if (exp & 1) {
            result *= base;
        }
        exp >>= 1;
        base = base * base;
    }
    return result;
}
bool check(int x) {
    int digits = 0;
    while (x / qpow(10, digits)) {
        digits++;
    }
    for (int i = 0; i < digits / 2; i++) {
        if ((x / qpow(10, i)) % 10 != (x / qpow(10, digits - i - 1)) % 10) {
            return false;
        }
    }
    return true;
}
int main() {
    for (int i = 1; i <= MAXN; i++) {
        if (check(i)) {
            dp[i] += 1;
            for (int j = 0; j + i <= MAXN; j++) {
                dp[j + i] += dp[j];
                dp[j + i] %= MOD;
            }
        }
    }
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        cout << dp[n] << endl;
    }
}