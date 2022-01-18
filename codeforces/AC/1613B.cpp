#include <algorithm>
#include <iostream>
using namespace std;
const int MAXN = (2e5) + 1;
int a[MAXN];
void solve() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= (n / 2); i++) {
        cout << a[n - i + 1] << ' ' << a[1] << endl;
    }
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}