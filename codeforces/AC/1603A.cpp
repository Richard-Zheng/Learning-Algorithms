#include <iostream>
using namespace std;
typedef long long ll;
const int MAXN = (1e5) + 1;
const ll MOD = 1e10;
ll a[MAXN];
ll gcd(ll a, ll b) {
    int tmp;
    while (b != 0) {
        tmp = a;
        a = b;
        b = tmp % b;
    }
    return a;
}
ll lcm(ll a, ll b) {
    return a / gcd(a, b) * b;
}
int main() {
    int t;
    cin >> t;
    int n;
    while (t--) {
        cin >> n;
        long long tmp = 1;
        bool flag = true;
        for (ll i = 1; i <= n; i++) {
            cin >> a[i];
            if (flag && tmp <= MOD) {
                tmp = lcm(tmp, i + 1);
                if (a[i] % tmp == 0) {
                    flag = false;
                }
            }
        }
        if (flag) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
}