#include <iostream>
using namespace std;
typedef long long ll;
int exgcd(ll a, ll b, ll& x, ll& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    } else {
        ll r = exgcd(b, a % b, x, y);
        ll tmp = x;
        x = y;
        y = tmp - a / b * y;
        return r;
    }
}
void solve(ll a, ll b, ll c) {
    ll x, y, d = exgcd(a, b, x, y);
    if (c % d != 0) {
        cout << "Impossible";
    } else {
        cout << ((y * c / d) % (a / d) + a / d) % (a / d);
    }
}
int main() {
    ll x, y, m, n, l;
    cin >> x >> y >> m >> n >> l;
    solve(l, n - m, x - y);
}