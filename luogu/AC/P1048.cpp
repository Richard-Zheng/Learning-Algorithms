#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int total_time, amount;
    cin >> total_time >> amount;
    int time[101] = {0};
    int price[101] = {0};
    for (int i = 1; i <= amount; i++) {
        cin >> time[i] >> price[i];
    }

    int dp[1001] = {0};
    for (int i = 1; i <= amount; i++) {
        for (int j = total_time; j >= time[i]; j--) {
            dp[j] = max(dp[j], dp[j - time[i]] + price[i]);
        }
    }
    cout << dp[total_time] << endl;
    return 0;
}