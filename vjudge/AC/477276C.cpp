#include <cstring>
#include <iostream>
using namespace std;
const int MAXNM = 11;
int dir[8][2] = {{2, 1}, {-2, 1}, {2, -1}, {-2, -1}, {1, 2}, {-1, 2}, {1, -2}, {-1, -2}};
int ans, cnt;
int vis[MAXNM][MAXNM];
int n, m, x, y;
void dfs(int x, int y) {
    if (x < 0 || x >= n || y < 0 || y >= m || vis[x][y]) {
        return;
    }
    vis[x][y] = true;
    cnt++;
    if (cnt == n * m) {
        ans++;
    }
    for (int i = 0; i < 8; i++) {
        dfs(x + dir[i][0], y + dir[i][1]);
    }
    vis[x][y] = false;
    cnt--;
    return;
}
void solve() {
    ans = 0;
    cnt = 0;
    memset(vis, 0, sizeof(vis));
    cin >> n >> m >> x >> y;
    dfs(x, y);
    cout << ans << endl;
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}