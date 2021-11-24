#include <algorithm>
#include <iostream>
using namespace std;
const int MAXN = 101;
int w[MAXN];
void solve() {
    int n, x;
    cin >> n >> x;
    int sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> w[i];
        sum += w[i];
    }
    if (sum == x) {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    int totalw = 0;
    for (int i = 0; i < n; i++) {
        totalw += w[i];
        if (totalw == x) {
            cout << w[i + 1] << ' ' << w[i] << ' ';
            i++;
        } else {
            cout << w[i] << ' ';
        }
    }
    cout << '\n';
    return;
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}