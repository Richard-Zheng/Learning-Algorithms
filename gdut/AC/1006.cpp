#include <algorithm>
#include <cstring>
#include <iostream>
#include <map>
using namespace std;
void solve() {
    int n, k;
    cin >> n >> k;
    for (int i = n; i >= 1; i--) {
        int pos = (k - 1) % i;
        for (int j = i + 1; j <= n; j++) {
            pos = (pos + k) % j;
        }
        cout << pos;
        if (i != 1) {
            cout << ' ';
        }
    }
    cout << '\n';
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}