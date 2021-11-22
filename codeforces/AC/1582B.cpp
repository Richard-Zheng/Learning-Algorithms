#include <iostream>
using namespace std;
typedef long long ll;
const int MAXN = 61;
int a[MAXN];
ll qpow(ll base, ll exp) {
    ll res = 1;
    while (exp) {
        if (exp & 1) {
            res *= base;
        }
        base *= base;
        exp >>= 1;
    }
    return res;
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        ll cntz = 0;
        ll cnto = 0;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            if (a[i] == 0) {
                cntz++;
            } else if (a[i] == 1) {
                cnto++;
            }
        }
        cout << qpow(2, cntz) * cnto << endl;
    }
}