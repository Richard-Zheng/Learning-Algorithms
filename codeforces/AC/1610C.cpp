#include <algorithm>
#include <iostream>
#include <map>
using namespace std;
const int MAXN = (2 * 1e5) + 1;
int a[MAXN];
int b[MAXN];
int n;
bool check(int x) {
    int k = 0;
    for (int i = 0; i < n; i++) {
        if (k <= b[i] && x - 1 - k <= a[i]) {
            k++;
        }
    }
    if (k >= x) {
        return true;
    } else {
        return false;
    }
}
void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
    }
    int l = 0;
    int r = n;
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (check(mid)) {
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    cout << r << endl;
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}