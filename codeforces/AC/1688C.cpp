#include <cstring>
#include <iostream>
using namespace std;
const int MAXC = 'z' + 1;
int cnt[MAXC];
void solve() {
    memset(cnt, 0, sizeof(cnt));
    int n;
    cin >> n;
    for (int i = 0; i <= 2 * n; i++) {
        string t;
        cin >> t;
        for (auto& x : t) {
            cnt[x]++;
        }
    }
    for (char i = 'a'; i <= 'z'; i++) {
        if (cnt[i] & 1) {
            cout << i << endl;
            break;
        }
    }
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}