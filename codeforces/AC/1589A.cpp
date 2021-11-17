#include <cmath>
#include <iostream>
using namespace std;
typedef unsigned long long ull;
ull qpow(ull a, ull n) {
    ull res = 1;
    ull now = a;
    while (n) {
        if (n & 1) {
            res *= now;
        }
        n >>= 1;
        now *= now;
    }
    return res;
}
int main() {
    int t;
    cin >> t;
    ull u, v;
    while (t--) {
        cin >> u >> v;
        cout << '-' << qpow(u, 2) << ' ' << qpow(v, 2) << '\n';
    }
}