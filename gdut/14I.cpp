#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
#include <limits>
using namespace std;
const int MAXN = 12;
double p[MAXN][2];
double dist[MAXN][MAXN];
int n, va, vb;
double dp[1 << MAXN][MAXN][2];
int main() {
    cin >> n >> va >> vb;
    for (int i = 0; i < n; i++) {
        cin >> p[i][0] >> p[i][1];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            dist[i][j] = sqrt(pow(p[i][0] - p[j][0], 2.0) + pow(p[i][1] - p[j][1], 2.0));
        }
    }
    for(int s=0;s<(1<<n);s++){
        for(int i=0;i<n;i++){
            dp[s][i][0]=numeric_limits<double>::max();
            dp[s][i][1]=numeric_limits<double>::max();
        }
    }
    dp[1][0][0] = 0;
    dp[1][0][1] = 0;
    double time;
    for (int s = 0; s < (1 << n); s++) {             // 枚举当前已经过的城市的状态
        for (int i = 0; i < n; i++) {                // 枚举当前在城市i
            if (s & (1 << i)) {                      // 必须已经过城市i
                for (int j = 0; j < n; j++) {        // 枚举上一个城市j
                    if (j != i && (s & (i << j))) {  // 必须已经过城市j
                        if (s & (1 << (n - 1))) {    // 已经过终点
                            time = dist[j][i] / vb;
                            if (max(dp[s][i][0], dp[s][i][1]) > max(dp[s ^ 1 << i][j][0], dp[s ^ 1 << i][j][1] + time)) {
                                dp[s][i][0] = dp[s ^ 1 << i][j][0];
                                dp[s][i][1] = dp[s ^ 1 << i][j][1] + time;
                            }
                        } else {
                            time = dist[j][i] / va;
                            dp[s][i][0] = min(dp[s][i][0], dp[s ^ 1 << i][j][0] + time);
                            dp[s][i][1] = 0;
                        }
                    }
                }
            }
        }
    }
    /*
    for (int k = 0; k < 2; k++) {
        for (int s = 0; s < (1 << n); s++) {       // 枚举当前已经过的城市的状态
            for (int i = 0; i < n; i++) {            // 枚举当前在城市i
                if (s & (1 << i)) {                      // 必须已经过城市i
                    for (int j = 0; j < n; j++) {    // 枚举上一个城市j
                        if (j != i && (s & (i << j))) {  // 必须已经过城市j
                            if (k == 0) {                // 第二个人
                                time = dist[j][i] / va;
                            } else { // 第一个人
                                time = dist[j][i] / vb;
                            }
                            cout<<time<<endl;
                                dp[s][i][k] = min(dp[s][i][0], dp[s ^ (1 << i)][j][0] + time);
                        }
                    }
                }
            }
        }
    }*/
    double ans = numeric_limits<double>::max();
    for(int s=0;s<(1<<(n-1));s++){
        int s2 = s ^ ((1<<n)-1);
        s |= (1<<(n-1));
        ans = min(ans, max(dp[s][n-1][0], dp[s2][n-1][1]));
    }
    cout << ans << endl;
}