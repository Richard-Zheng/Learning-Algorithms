#include <iostream>
#include <algorithm>
#include <vector>
#define int long long
using namespace std;
const int MAXN = 400;
int n;
int a[MAXN];
int mi[MAXN];
int gcd(int a, int b) {  // a < b
    if (a == 0) return b;
    return gcd(b % a, a);
}
int n_gcd(int a, int b) {
    if (a < b) {
        return gcd(a, b);
    } else {
        return gcd(b, a);
    }
}
int find_gcd(int n) {
    int result = mi[0];
    for (int i = 1; i < n; i++) {
        if (mi[i] <= result) {
            result = gcd(mi[i], result);
        } else {
            result = gcd(result, mi[i]);
        }
        if (result == 1) {
            return 1;
        }
    }
    return result;
}
signed main() {
    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        int mina = 1e6;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            mina = min(a[i], mina);
        }
        int ans = -1;
        for (int i = 0; i < n; i++) {
            if (a[i]-mina==0) {
            }else if (ans == -1) {
                ans = a[i]-mina;
            } else {
                ans = n_gcd(a[i]-mina, ans);
            }
        }
        cout << ans << endl;
    }
}