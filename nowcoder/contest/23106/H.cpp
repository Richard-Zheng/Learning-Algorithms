#include <algorithm>
#include <iostream>
using namespace std;
const int MAXN = (1e6) + 1;
int a[MAXN];
int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i] -= 500;
    }
    sort(a, a + n);
    long long ans = 0;
    int tmp;
    for (int i = 0; i < n; i++) {
        tmp = lower_bound(a, a + n, -a[i]) - a;
        ans += tmp * (-a[i]);
        ans += (n - tmp) * a[i];
        ans += abs(a[i]);
    }
    cout << ans << endl;
}