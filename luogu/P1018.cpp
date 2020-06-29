#include <iostream>
#include <cstring>
#include <string>
using namespace std;
int n, k;
string in;
int dp[1000][1000];
int main() {
    memset(dp, -1, sizeof(dp));
    cin >> n >> k;
    cin >> in;
    
    for (int i = 1; i <= n; ++i) { // length
        for (int j = 0; j <= i - 1; ++j) { // number of multiplication
            if (j == 0) {
                dp[i][j] = stoi(in.substr(0, i));
                continue;
            } else if (i == j + 1) {
                dp[i][j] = 1;
                for (int p = 0; p < i; ++p) {
                    dp[i][j] *= stoi(in.substr(p, 1));
                }
                //cout << "i " << i << " j " << j << " " << dp[i][j] << endl;
                continue;
            }
            int ans = 0;
            //cout << "length: " << i << " mul: " << j << endl;
            for (int k = j; k < i; ++k) {
                //cout << "cal- ("<< stoi(in.substr(0, k)) << ") " << dp[k][j - 1] << " * " << stoi(in.substr(k, i - k)) << endl;
                ans = max(ans, dp[k][j - 1] * stoi(in.substr(k, i - k)));
            }
            dp[i][j] = ans;
        }
    }
    cout << dp[n][k] << endl;
    return 0;
}