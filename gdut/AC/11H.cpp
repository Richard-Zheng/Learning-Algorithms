#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
typedef long long ll;
const int MAXN = 1000001;
int n, cntz;
string s;
ll a[MAXN];
ll sum[MAXN];
ll hsum[MAXN];
int main() {
    cin >> n >> s;
    for (int i = 1; i <= n; i++) {
        a[i] = s[i - 1] - '0';
        sum[i] = sum[i - 1] + a[i];
    }
    for (int i = n; i >= 1; i--) {
        hsum[i] = hsum[i + 1] + a[i];
    }
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        if (a[i] == 0) {
            ans += min(sum[i], hsum[i]);
        }
    }
    cout << ans << endl;
}