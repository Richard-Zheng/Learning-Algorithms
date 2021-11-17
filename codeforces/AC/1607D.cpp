#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e5;
int a[MAXN];
void solve() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    string s;
    cin >> s;
    vector<int> inc;
    vector<int> dec;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'R') {
            inc.push_back(a[i]);
        } else {
            dec.push_back(a[i]);
        }
    }
    sort(inc.begin(), inc.end(), greater<int>());
    sort(dec.begin(), dec.end());
    int m = inc.size();
    for (int i = 0; i < m; i++) {
        if (inc[i] > (n - i)) {
            cout << "NO" << endl;
            return;
        }
    }
    m = dec.size();
    for (int i = 0; i < m; i++) {
        if (dec[i] <= i) {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
    return;
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}