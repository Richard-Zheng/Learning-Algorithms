#include <algorithm>
#include <iostream>
using namespace std;
typedef long long ll;
int main() {
    int t;
    cin >> t;
    while (t--) {
        ll x, n;
        cin >> x >> n;
        ll che;
        if (x & 1) {
            che = -1;
        } else {
            che = 1;
        }
        if (!(n & 1)) {
            if (abs(n) % 4 == 0) {
                cout << x << endl;
            } else {
                cout << x + (che * 1ll) << endl;
            }
        } else {
            if (abs(n) % 4 == 1) {
                cout << x - (che * n) << endl;
            } else {
                if (x & 1 == 1) {
                    cout << x - 1ll - n << endl;
                } else {
                    cout << x + 1ll + n << endl;
                }
            }
        }
    }
}