#include <algorithm>
#include <iostream>
#include <set>
#include <vector>
using namespace std;
void solve() {
    int n;
    string s;
    cin >> n >> s;
    if (is_sorted(s.begin(), s.end())) {
        cout << 0 << '\n';
        return;
    }
    string t = s;
    sort(t.begin(), t.end());
    cout << 1 << '\n';
    vector<int> ans;
    for (int i = 0; i < n; i++) {
        if (t[i] != s[i]) {
            ans.push_back(i + 1);
        }
    }
    cout << ans.size() << ' ';
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << ' ';
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