#include <iostream>
using namespace std;
const int MAXN = 5010;
int sm[MAXN][MAXN];
int n, m;
int main() {
    cin >> n >> m;
    int x, y, v;
    for (int i = 1; i <= n; i++) {
        cin >> x >> y >> v;
        sm[x + 1][y + 1] = v;
    }
    for (int i = 1; i < MAXN; i++) {
        for (int j = 1; j < MAXN; j++) {
            sm[i][j] += sm[i][j - 1];
        }
    }
    for (int i = 1; i < MAXN; i++) {
        for (int j = 1; j < MAXN; j++) {
            sm[i][j] += sm[i - 1][j];
        }
    }

    int ans = 0;
    for (int i = m; i < MAXN; i++) {
        for (int j = m; j < MAXN; j++) {
            ans = max(ans, sm[i][j] - sm[i - m][j] - sm[i][j - m] + sm[i - m][j - m]);
        }
    }
    cout << ans << endl;
}