#include <algorithm>
#include <iostream>
#include <map>
#include <set>
using namespace std;
const int MAXN = 2001;
int ma[MAXN][MAXN];
void solve() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> ma[0][i];
    }
    map<int, int> cnt;
    for (int i = 1; i <= 2000; i++) {
        cnt.clear();
        for (int j = 1; j <= n; j++) {
            if (cnt.count(ma[i - 1][j])) {
                cnt[ma[i - 1][j]]++;
            } else {
                cnt[ma[i - 1][j]] = 1;
            }
        }
        for (int j = 1; j <= n; j++) {
            ma[i][j] = cnt[ma[i - 1][j]];
        }
    }
    int q;
    cin >> q;
    int xi, ki;
    for (int j = 0; j < q; j++) {
        cin >> xi >> ki;
        if (ki > MAXN) {
            ki = 2000;
        }
        cout << ma[ki][xi] << endl;
    }
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}