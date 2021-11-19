#include <algorithm>
#include <iostream>
using namespace std;
const int MAXAB = 101;
int a[MAXAB];
int b[MAXAB];
void solve() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    sort(a, a + n);
    sort(b, b + n);
    for (int i = 0; i < n; i++) {
        if (a[i] - b[i] < -1 || a[i] - b[i] > 0) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
    return;
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}