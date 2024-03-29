#include <iostream>
using namespace std;
int n, l, r, k;
int multiple_count(int a) {
    return (r / a) - ((l - 1) / a);
}
void solve() {
    cin >> n >> l >> r >> k;
    int a[3];
    int ans = 0;
    for (int i = 0; i < k; i++) {
        cin >> a[i];
        ans += multiple_count(a[i]);
    }
    for (int i = 0; i < k; i++) {
        for (int j = i + 1; j < k; j++) {
            ans -= multiple_count(lcm(a[i], a[j]));
        }
    }
    if (k == 3) {
        ans += multiple_count(lcm(a[0], lcm(a[1], a[2])));
    }
    cout << ans << endl;
}
int gcd(int a, int b) {
    int tmp;
    while (b != 0) {
        tmp = a;
        a = b;
        b = tmp % b;
    }
    return a;
}
int lcm(int a, int b) {
    return a * b / gcd(a, b);
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}