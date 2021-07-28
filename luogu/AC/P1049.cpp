#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int box_volume, amount;
    cin >> box_volume >> amount;
    int volume[31] = {0};
    for (int i = 1; i <= amount; i++) {
        cin >> volume[i];
    }

    bool dp[200000] = {0};
    dp[0] = true;
    for (int i = 1; i <= amount; i++) {
        for (int j = box_volume; j >= volume[i]; j--) {
            if (dp[j - volume[i]]) {
                dp[j] = true;
            }
        }
    }

    int ans = 0;
    while (!dp[box_volume - ans]) {
        ans++;
    }
    cout << ans << endl;
    return 0;
}