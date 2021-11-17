#include <iostream>
using namespace std;
const int MAXN = 2e5;
const int MAXL = 2e5;
int a[MAXN][MAXL];
int l[MAXN];
bool vis[MAXN];
int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> l[i];
        for (int j = 0; j < l[i]; j++) {
            cin >> a[i][j];
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (l[i] != l[j] || vis[j]) {
                continue;
            }
            for (int k = 0; k < l[i]; k++) {
                if (a[i][k] == a[j][k]) {
                    continue;
                }
            }
            vis[j] = true;
            ans++;
        }
    }
    cout << ans - 1 << endl;
}