#include <iostream>
#include <set>
using namespace std;
const int MAXN = 2 * 1e5;
int a[MAXN];
void solve() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int tar[2];
    for (int i = 0; i < n / 2; i++) {
        if (a[i] != a[n - 1 - i]) {
            tar[0] = a[i];
            tar[1] = a[n - 1 - i];
            break;
        }
    }
    bool bigflag = false;
    for (int k = 0; k < 2; k++) {
        int l = 0;
        int r = n - 1;
        bool flag = true;
        while (l < r) {
            if (a[l] == tar[k]) {
                l++;
                continue;
            }
            if (a[r] == tar[k]) {
                r--;
                continue;
            }
            if (a[l] == a[r]) {
                l++;
                r--;
            } else {
                flag = false;
                break;
            }
        }
        if (flag) {
            bigflag = true;
            break;
        }
    }
    if (bigflag) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}