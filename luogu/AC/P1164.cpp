#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int total_money;
    int number; // 菜品种类数
    cin >> number >> total_money;
    int price[101];
    for (int i = 1; i <= number; i++) {
        cin >> price[i];
    }

    int dp[10001] = {0}; // 给定钱的点菜方案数
    dp[0] = 1;
    for (int i = 1; i <= number; i++) {
        for (int j = total_money; j >= price[i]; j--) {
            dp[j] = dp[j] + dp[j - price[i]];
        }
    }

    cout << dp[total_money] << endl;
}