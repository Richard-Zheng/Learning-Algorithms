#include <iostream>
#include <algorithm>
using namespace std;
int main() {
    int n;
    cin >> n;
    int cost[11]; // 法力值消耗
    bool d[11]; // 是为增加攻击的法术牌，否为随从牌
    int w[11]; // 攻击力
    for (int i = 0; i < n; i++) {
        cin >> cost[i] >> d[i] >> w[i];
    }

    int ans = 0;
    for (int i = 0; i < (1 << n); i++) {
        int total_cost = 0;
        int total_w = 0;
        bool suicong = false;
        for (int j = 0; j < n; j++) {
            if (i & (1 << j)) {
                total_cost += cost[j];
                total_w += w[j];
                if (d[j] == false) {
                    suicong = true;
                }
            }
        }
        if (total_cost > 10 || !suicong) continue;
        ans = max(ans, total_w);
    }
    cout << ans << endl;
    return 0;
}