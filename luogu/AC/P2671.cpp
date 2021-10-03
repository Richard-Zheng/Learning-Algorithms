// 思想：分组、数学推导找重复计算的部分
#include <iostream>
#include <algorithm>
using namespace std;
const int MAXNM = 100001;
int main() {
    int n, m, ans;
    cin >> n >> m;
    int num[MAXNM];
    for (int i = 1; i <= n; i++) {
        cin >> num[i];
    }
    int color[MAXNM];

    int count[MAXNM][2];
    int ysum[MAXNM][2];
    for (int i = 1; i <= n; i++) {
        cin >> color[i];
        count[color[i]][i & 1]++; // 奇偶分组 i & 1 相当于 i % 2
        ysum[color[i]][i & 1] = (ysum[color[i]][i & 1] + num[i]) % 10007;
    }
    ans = 0;
    for (int i = 1; i <= n; i++) {
        ans = (ans + i * ((count[color[i]][i & 1] - 2) * num[i] % 10007 + ysum[color[i]][i & 1])) % 10007;
    }
    cout << ans << endl;
    return 0;
}