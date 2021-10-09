#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN = 5008;
int main() {
    int n;
    cin >> n;

    int a[MAXN] = {0};
    char s;
    for (int i = 1; i <= n; i++) {
        cin >> s;
        if (s == 'B') {
            a[i] = 0;
        } else if (s == 'F') {
            a[i] = 1;
        }
    }
    int ans = MAXN;
    int ansk;
    for (int k = 1; k <= n; k++) {
        int sum = 0; // 翻转操作次数
        int op = 0; // 标记无法翻转
        int tag = 0; // 当前翻转次数
        int f[MAXN << 1] = {0}; // 标记翻转终点，用于退出翻转
        for (int i = 1; i <= n; i++) {
            if ((a[i] + tag) % 2 == 0) {
                if (i + k - 1 > n) {
                    op = 1;
                    break;
                }
                ++sum;
                ++tag;
                f[i + k - 1] = -1;
            }
            if (f[i] == -1) {
                --tag;
                f[i] = 0;
            }
        }
        if (op) continue;
        if (sum < ans) {
            ans = sum;
            ansk = k;
        }
    }
    cout << ansk << " " << ans << endl;
    return 0;
}