#include <algorithm>
#include <iostream>
#include <map>
using namespace std;
const int MAXN = 1e5;
int n;
map<int, int> a;
void solve() {
    a.clear();
    cin >> n;
    bool can_single = (n % 2 != 0);
    int tmp;
    for (int i = 0; i < n; i++) {
        cin >> tmp;
        if (a.count(tmp)) {
            a[tmp]++;
        } else {
            a[tmp] = 1;
        }
    }
    for (map<int, int>::iterator it = a.begin(); it != a.end(); it++) {
        if (it->second % 2 != 0) {
            if (can_single) {
                can_single = false;
                continue;
            } else {
                cout << "No" << endl;
                return;
            }
        }
    }
    cout << "Yes" << endl;
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}