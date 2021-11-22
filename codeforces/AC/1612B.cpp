#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
const int MAXN = 101;
int used[MAXN];
void solve() {
    memset(used, 0, sizeof(used));
    int n, a, b;
    cin >> n >> a >> b;
    int tar = n / 2;
    vector<int> ans;
    ans.push_back(a);
    used[a] = true;
    for (int i = n; i > a; i--) {
        if (ans.size() >= tar || used[i] || i == b) {
            continue;
        }
        used[i] = true;
        ans.push_back(i);
    }
    if (ans.size() < tar) {
        cout << "-1\n";
        return;
    }
    ans.push_back(b);
    used[b] = true;
    for (int i = 1; i < b; i++) {
        if (ans.size() >= n || used[i]) {
            continue;
        }
        used[i] = true;
        ans.push_back(i);
    }
    if (ans.size() < n) {
        cout << "-1\n";
        return;
    }
    for (vector<int>::iterator it = ans.begin(); it != ans.end(); it++) {
        cout << *it << ' ';
    }
    cout << endl;
    return;
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}