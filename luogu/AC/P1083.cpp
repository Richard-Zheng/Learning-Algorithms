#include <iostream>
#include <algorithm>
using namespace std;
const int MAXNM = 10e6;
int n, m;
int r[MAXNM], d[MAXNM], s[MAXNM], t[MAXNM];
bool check(int j) {
    // 检查是否能够满足到第 j 个订单的需求
    int diff[MAXNM] = {0};
    for (int i = 1; i <= j; i++) {
        diff[s[i]] += d[i];
        diff[t[i] + 1] -= d[i];
    }
    int req = 0;
    for (int i = 1; i <= n; i++) {
        req += diff[i];
        if (req > r[i]) {
            return false;
        }
    }
    return true;
}
int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> r[i];
    }
    for (int i = 1; i <= m; i++) {
        cin >> d[i] >> s[i] >> t[i];
    }

    // 二分查找 无法满足需求的临界点
    int left = 1;
    int right = m;
    while (left < right) {
        int mid = (left + right) / 2;
        if (check(mid)) { // 可以满足，从 mid + 1 继续找
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    if (left >= m) {
        cout << "0" << endl;
    } else {
        cout << "-1" << endl << left;
    }
    return 0;
}