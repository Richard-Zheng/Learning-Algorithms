#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int main() { // 贪心解法
    int n, m, k;
    cin >> n >> m >> k;
    int checkdate[2000];
    int cost[2000];
    memset(checkdate, 0, sizeof(checkdate));
    memset(cost, 0, sizeof(cost));
    for (int i = 0; i < n; i++) {
        cin >> checkdate[i];
        cost[i] = (i==0) ? 0 : checkdate[i] - checkdate[i - 1];
    }
    sort(cost, cost + n);
    int ans = k;
    for (int i = 0; i <= n - k; i++) {
        ans += cost[i];
    }
    cout << ans << endl;
    return 0;
}

int main_dp() { // DP 解法
    int n; // 高级祭司的点名次数
    int m; // 原本需要工作的天数
    int k; // 懒惰的祭司的工作次数
    int a[2001];
    cin >> n >> m >> k;
    memset(a, 0, sizeof(a));
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    int dp[2001];
    memset(dp, 0x3f, sizeof(dp));
    for (int j = 1; j <= k; j++) {
        dp[j] = 1;
    }
    for (int i = 2; i <= n; i++) {
        for (int j = k; j >= 1; j--) {
            dp[j] = min(dp[j - 1] + 1, dp[j] + a[i] - a[i - 1]);
        }
    }
    int ans = 0x3f3f3f3f;
    for (int j = 1; j <= k; j++) {
        ans = min(ans, dp[j]);
    }
    cout << ans << endl;
    return 0;
}
