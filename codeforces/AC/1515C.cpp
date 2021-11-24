#include <algorithm>
#include <iostream>
#include <map>
#include <set>
using namespace std;
const int MAXNM = (1e5) + 1;
int h[MAXNM];
int ans[MAXNM];
void solve() {
    int n, m, x;
    cin >> n >> m >> x;
    set<pair<int, int>> s;  // {height, index}
    for (int i = 1; i <= m; i++) {
        s.insert({0, i});
    }
    for (int i = 1; i <= n; i++) {
        cin >> h[i];
    }
    cout << "YES\n";
    for (int i = 1; i <= n; i++) {
        s.insert({s.begin()->first + h[i], s.begin()->second});
        cout << s.begin()->second << ' ';
        s.erase(s.begin());
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