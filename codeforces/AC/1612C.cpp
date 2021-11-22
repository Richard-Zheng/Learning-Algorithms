#include <iostream>
using namespace std;
typedef long long ll;
ll k, x;
const ll MAXX = (1e18) + 10;
ll func(ll n) {
    if (n <= k) {
        return ((1 + n) * n) / 2;
    } else {
        return ((1 + k) * k) / 2 + ((3 * k - n - 1) * (n - k)) / 2;
    }
}
void solve() {
    cin >> k >> x;
 
    ll left = 0;
    ll right = 2 * k - 1;
    while (left <= right) {
        int middle = left + ((right - left) >> 1);
        if (func(middle) >= x) {
            right = middle - 1;
        } else {
            left = middle + 1;
        }
    }
    if (left > 2 * k - 1) {
        cout << 2 * k - 1 << endl;
    } else {
        cout << left << endl;
    }
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}