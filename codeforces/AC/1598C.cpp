#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
typedef long long ll;
const int MAXN = 2 * 1e5;
ll f[MAXN] = {0};
int main() {
    int t;
    cin >> t;

    int n;
    while (t--) {
        cin >> n;

        double sum = 0;
        //int tmp;
        map<ll, ll> a;
        for (ll i = 0; i < n; i++) {
            cin >> f[i];
            if (a.count(f[i])) {
                a[f[i]]++;
            } else {
                a[f[i]] = 1;
            }
            sum += f[i];
        }
        double avg = sum / n;
        int tar = avg * 2;

        if ((avg * 2) - tar != 0) {
            cout << '0' << endl;
            continue;
        }

        ll ans = 0;
        for (ll i = 0; i < n; i++) {
            if (tar - f[i] == f[i]) {
                ans += (a[f[i]] - 1);
            } else {
                ans += a[tar - f[i]];
            }
        }
        cout << ans / 2 << endl;
    }
    return 0;
}