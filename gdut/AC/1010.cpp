#include <iostream>
#include <stack>
using namespace std;
const int MAXN = 1e6;
int n;
void solve() {
    cin >> n;
    stack<int> a;
    int tmp;
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        cin >> tmp;
        if (tmp == 0) {
            while (!a.empty()) {
                a.pop();
            }
            continue;
        }
        bool flag = false;
        while (!a.empty() && a.top() > tmp) {
            a.pop();
        }
        if (a.empty() || a.top() != tmp) {
            ans++;
        }
        a.push(tmp);
    }
    cout << ans << endl;
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}