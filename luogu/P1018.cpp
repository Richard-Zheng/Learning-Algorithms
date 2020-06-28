#include <iostream>
#include <cstring>
#include <string>
using namespace std;
int n, k;
string in;
int dp[100][100];
int main() {
    memset(dp, -1, sizeof(dp));
    cin >> n >> k;
    cin >> in;
    
    for (int i = 1; i <= n; ++i) { // length
        for (int j = 0; j <= i - 1; ++j) { // number of multiplication
            if (j == 0) {
                dp[i][j] = atoi(in.substr(0, i).c_str());
                continue;
            }
            
        }
    }
    return 0;
}