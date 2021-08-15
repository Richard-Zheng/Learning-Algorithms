#include <iostream>
#include <algorithm>
#include <map>
using namespace std;
long long tax[101];

int main() {
    int n; // 征服的城市个数
    int m; // 对城市税金的修改次数和对税金的询问次数之和
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> tax[i];
    }

    int op = 0;
    int l, r;
    for (int i = 1; i <= m; i++) {
        cin >> op >> l >> r;
        if (op == 1) {
            for (int j = l; j <= r; j++) {
                tax[j] = tax[j]*251%996*404*123;
            }
        } else if (op == 2) {
            map<long long, int> emerge;
            int ans = 0;
            for (int j = l; j <= r; j++) {
                if (emerge.count(tax[j])) {
                    emerge[tax[j]]++;
                } else {
                    emerge[tax[j]] = 1;
                }
                ans = max(ans, emerge[tax[j]]);
            }
            cout << ans << endl;
        }
    }
    return 0;
}