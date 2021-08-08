#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int n, m;
int matrix[16][15];
bool is_ok_horizontally(int j) {
    return ((j & (j << 1)) | (j & (j >> 1))) == 0;
}

bool is_ok_vertically(int j, int k) {
    return (j & k) == 0;
}

int count(int i, int j) { // 注意i从1开始
    int sum = 0;
    for (int k = 0; k < m; k++) {
        if (j & 1) {
            sum += matrix[i][k];
        }
        j >>= 1;
    }
    return sum;
}

int main() {
    memset(matrix, 0, sizeof(matrix));
    cin >> n >> m;

    for (int i = 1; i <= n; i++) { // 行从 1 开始，列从 0 开始，dp的时候第一行就不用特别处理
        for (int j = 0; j < m; j++) {
            cin >> matrix[i][j];
        }
    }

    int dp[15][1 << 15];
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= n; i++) { // 枚举行数
        for (int j = 0; j < (1 << m); j++) { // 当前行的选择情况
            if (is_ok_horizontally(j)) {
                for (int k = 0; k < (1 << m); k++) { // 枚举上一行的选择情况，找到最优的
                    if (is_ok_vertically(j, k)) {
                        dp[i][j] = max(dp[i][j], dp[i - 1][k] + count(i, j));
                    }
                }
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < (1 << m); i++) {
        ans = max(ans, dp[n][i]);
    }
    cout << ans << endl;
    cout << count(1, 1);
}