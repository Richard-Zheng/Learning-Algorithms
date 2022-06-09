#include <algorithm>
#include <cstring>
#include <iostream>
#include <string>
using namespace std;
const int MAXNM = 500;
int a[MAXNM][MAXNM];
int dr[MAXNM][MAXNM];
int dl[MAXNM][MAXNM];
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        memset(a, 0, sizeof(a));
        memset(dr, 0, sizeof(dr));
        memset(dl, 0, sizeof(dl));
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                cin >> a[i][j];
                dl[i][j] = a[i][j];
                dr[i][j] = dl[i][j];
            }
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                dr[i][j] += dr[i - 1][j - 1];
                dl[i][j] += dl[i - 1][j + 1];
            }
        }
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                int d = n - i;
                int l = j - 1;
                int r = m - j;
                int ddl = min(d, l);
                int ddr = min(d, r);
                ans = max(ans, dl[i + ddl][j - ddl] + dr[i + ddr][j + ddr] - a[i][j]);
                // cout<<dl[i+ddl][j-ddl]<<endl<<+dr[i+ddr][j+ddr]<<endl<<i+ddl<<' '<<j-ddl<<' '<<i+ddr<<' '<<j+ddr<<endl;
            }
        }
        cout << ans << endl;
    }
}