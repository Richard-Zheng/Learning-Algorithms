#include <iostream>
using namespace std;

const int step[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

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

    int ans = 0;
    for (int i = 1; i <= r; ++i) {
        for (int j = 1; j <= c; ++j) {
            dp[i][j] = max(dp[i][j], 1);

            for (int dir = 0; dir < 4; ++dir) {
                int nexti = i + step[dir][0];
                int nextj = j + step[dir][1];
                
                if (nexti == 0 || nextj == 0) {
                    continue;
                } else if (heightAtPoint[nexti][nextj] < heightAtPoint[i][j]) {
                    dp[nexti][nextj] = max(dp[nexti][nextj], dp[i][j] + 1);
                    ans = max(ans, dp[nexti][nextj]);
                } else if (heightAtPoint[nexti][nextj] > heightAtPoint[i][j]) {
                    dp[i][j] = max(dp[i][j], dp[nexti][nextj] + 1);
                    ans = max(ans, dp[i][j]);
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}