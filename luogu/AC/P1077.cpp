#include <algorithm>
#include <iostream>
using namespace std;
const int MAXNM = 101;
const int MOD = 1000007;
int dp[MAXNM][MAXNM] = {0};  // dp[i][j]: 摆j盆花，最后一盆摆第i种的方案数
int a[MAXNM];
int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            for (int k = 0; k <= min(j, a[i]); k++) {
                dp[i][j] += dp[i - 1][j - k];
                dp[i][j] %= MOD;
            }
        }
    }
    cout << dp[n][m] << endl;
}