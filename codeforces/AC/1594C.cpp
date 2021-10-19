#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
const int MAXN = 3e5;
void solve() {
    int n;
    char c;
    cin >> n >> c;
    string s;
    cin >> s;
    for (int i = 0; i < n; i++) {
        if (s[i] != c) {
            break;
        }
        if (i == n - 1) {
            cout << "0\n";
            return;
        }
    }
    for (int i = 2; i <= n; i++) {
        int j = i;
        bool ok = true;
        while (j <= n) {
            if (s[j - 1] != c) {
                ok = false;
            }
            j += i;
        }
        if (ok) {
            cout << "1\n"
                 << i << '\n';
            return;
        }
    }
    cout << "2\n"
         << n << ' ' << n - 1 << '\n';
    return;
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}