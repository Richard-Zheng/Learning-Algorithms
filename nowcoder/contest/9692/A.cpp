#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
const int MAXN = 1000000;
int main() {
    int n;
    string s;
    cin >> n >> s;
    int dp[MAXN][3] = {0};
    int bit;
    for (int i = 1; i <= n; i++) {
        int bit = s[i - 1] - '0';
        dp[i][0] = dp[i - 1][0] + bit;
        dp[i][1] = min(dp[i - 1][0] + !bit, dp[i - 1][1] + !bit);
        dp[i][2] = min(dp[i - 1][1] + bit, dp[i - 1][2] + bit);
    }
    cout << min(dp[n][0], min(dp[n][1], dp[n][2])) << endl;
}