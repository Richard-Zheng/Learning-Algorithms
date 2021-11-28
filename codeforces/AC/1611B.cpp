#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve() {
    ll a, b;
    cin >> a >> b;
    if (a > b) {
        swap(a, b);
    }
    ll t = min(a, (b - a) / 2);
    a -= t;
    b -= t * 3;
    ll t2 = min(a / 2, b / 2);
    cout << t + t2 << endl;
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}