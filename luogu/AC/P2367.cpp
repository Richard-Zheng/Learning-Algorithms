#include <iostream>
#include <algorithm>
#include <limits>
using namespace std;
const int MAXN = 10e6;
int main() {
    int n, p;
    cin >> n >> p;
    int diff[MAXN] = {0};
    int tmp[2] = {0};
    for (int i = 1; i <= n; i++) {
        cin >> tmp[i & 1];
        diff[i] = tmp[i & 1] - tmp[!(i & 1)];
    }
    int x, y, z;
    for (int i = 1; i <= p; i++) {
        cin >> x >> y >> z;
        diff[x] += z;
        diff[y + 1] -= z;
    }
    
    int ans = numeric_limits<int>::max();
    int temp = 0;
    for (int i = 1; i <= n; i++) {
        temp += diff[i];
        if (temp < ans) {
            ans = temp;
        }
    }
    cout << ans << endl;
    return 0;
}