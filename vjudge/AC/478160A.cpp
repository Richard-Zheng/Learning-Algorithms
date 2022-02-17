#include <iostream>
using namespace std;
const int MAXN = 4000001;
int n, m;
int disset[MAXN];
int find(int x) {
    return x == disset[x] ? x : disset[x] = find(disset[x]);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        disset[i] = i;
    }

    int op, u, v;
    int ans = 0;
    for (int i = 1; i <= m; i++) {
        cin >> op >> u >> v;
        if (op == 0) {
            disset[find(u)] = find(v);
        } else {
            ans = (ans << 1 | find(u) == find(v)) % 998244353;
        }
    }
    cout << ans << '\n';
}