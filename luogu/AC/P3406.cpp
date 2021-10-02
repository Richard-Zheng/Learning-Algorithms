#include <iostream>
#include <cstring>
#include <algorithm>
typedef long long ll;
using namespace std;
const int MAXM = 10e5;
int main() {
    int n, m;
    cin >> n >> m;

    int p[100001];
    memset(p, 0, sizeof(p));

    int tmp[2];
    cin >> tmp[0];
    int l, r;
    for (int i = 1; i < m; i++) {
        cin >> tmp[i & 1];
        l = min(tmp[!(i & 1)], tmp[i & 1]);
        r = max(tmp[!(i & 1)], tmp[i & 1]);
        p[l]++;
        p[r]--;
    }

    ll ans = 0;
    ll temp = 0;
    ll a, b, c;
    for (int i = 1; i <= n - 1; i++) {
        cin >> a >> b >> c;
        temp += p[i];
        ans += min(a * temp, c + (b * temp));
        //cout << temp << " ";
    }
    cout << ans << endl;
    return 0;
}