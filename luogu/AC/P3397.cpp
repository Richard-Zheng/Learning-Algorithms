#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;
const int MAXNM = 1e4;
int n, m;
int diff[MAXNM][MAXNM] = {0};
int f[MAXNM][MAXNM] = {0};
int main() {
    cin >> n >> m;

    int x1, y1, x2, y2;
    for (int i = 1; i <= m; i++) {
        cin >> x1 >> y1 >> x2 >> y2;
        diff[x1][y1] += 1;
        diff[x2 + 1][y1] -= 1;
        diff[x1][y2 + 1] -= 1;
        diff[x2 + 1][y2 + 1] += 1;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            f[i][j] = f[i - 1][j] + f[i][j - 1] - f[i - 1][j - 1] + diff[i][j];
            cout << f[i][j] << ' ';
        }
        cout << '\n';
    }
}