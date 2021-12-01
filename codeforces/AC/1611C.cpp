#include <iostream>
using namespace std;
const int MAXN = (2e5) + 1;
int a[MAXN];
void solve() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    if (a[0] == n) {
        cout << a[0] << ' ';
        for (int i = n - 1; i >= 1; i--) {
            cout << a[i] << ' ';
        }
        cout << '\n';
        return;
    } else if (a[n - 1] == n) {
        for (int i = n - 2; i >= 0; i--) {
            cout << a[i] << ' ';
        }
        cout << a[n - 1] << '\n';
        return;
    } else {
        cout << "-1\n";
        return;
    }
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}