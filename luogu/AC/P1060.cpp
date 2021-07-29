#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n; // 总钱数
    int m; // 希望购买物品的个数
    cin >> n >> m;

    int value[26]; // 物品的价格
    long long price[26]; // 物品的重要度
    for (int i = 1; i <= m; i++) {
        cin >> value[i] >> price[i];
    }

    long long dp[30001];
    for (int i = 1; i <= m; i++) {
        for (int j = n; j >= value[i]; j--) {
            dp[j] = max(dp[j], dp[j - value[i]] + (value[i] * price[i]));
        }
    }
    cout << dp[n] << endl;
}