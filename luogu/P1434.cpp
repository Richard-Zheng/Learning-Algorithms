#include <iostream>
using namespace std;
int main() {
    int r, c;
    int heightAtPoint[101][101];
    int dp[101][101]; // dp[i][j] is the length of longest access to (i, j)
    memset(heightAtPoint, 0, sizeof(heightAtPoint));
    memset(dp, 0, sizeof(dp));
    cin >> r >> c;
    for (int i = 1; i <= r; ++i) {
        for (int j = 1; j <= c; ++j) {
            cin >> heightAtPoint[i][j];
        }
    }

    for (int i = 1; i <= r; ++i) {
        for (int j = 1; j <= c; ++j) {
            if (i == 1) { // solution: longest increasing subsequence
                if (heightAtPoint[i][j] < heightAtPoint[i][j - 1]) {
                    dp[i][j] = dp[i][j - 1] + 1;
                } else {
                    dp[i][j] = 1;
                }
            } else {
                if (heightAtPoint[i][j] < heightAtPoint[i][j - 1]) {
                    dp[i][j] = max(dp[i][j], dp[i][j - 1] + 1);
                }
                if (heightAtPoint[i][j] < heightAtPoint[i - 1][j]) {
                    dp[i][j] = max(dp[i][j], dp[i - 1][j] + 1);
                }
            }
        }
    }

    int ans = 0;
    for (int i = 1; i <= r; ++i) {
        for (int j = 1; j <= c; ++j) {
            ans = max(ans, dp[i][j]);
        }
    }

    cout << ans << endl;
    return 0;
}