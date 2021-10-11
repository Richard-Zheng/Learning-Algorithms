#include <algorithm>
#include <iostream>
using namespace std;
typedef long long ll;
const int MAXNM = 1e4;
ll f[MAXNM][MAXNM] = {0};
int n, m, c;
ll get_sum(ll x, ll y) {
    ll x2 = x + c - 1;
    ll y2 = y + c - 1;
    return f[x2][y2] - f[x2][y - 1] - f[x - 1][y2] + f[x - 1][y - 1];
}
int main() {
    cin >> n >> m >> c;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            //cin >> v[i][j];
        }
    }
    ll tmp_val;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> tmp_val;
            f[i][j] = f[i][j - 1] + f[i - 1][j] - f[i - 1][j - 1] + tmp_val;
        }
    }

    ll ans = 0;
    int ansi, ansj;
    for (int i = 1; i <= n - c + 1; i++) {
        for (int j = 1; j <= m - c + 1; j++) {
            ll sum = get_sum(i, j);
            if (sum > ans) {
                ans = sum;
                ansi = i;
                ansj = j;
            }
        }
    }
    cout << ansi << ' ' << ansj << endl;
    return 0;
}