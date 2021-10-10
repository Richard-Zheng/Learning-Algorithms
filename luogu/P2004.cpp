#include <iostream>
#include <algorithm>
using namespace std;
const int MAXNM = 1e3;
int v[MAXNM][MAXNM] = {0};
int f[MAXNM][MAXNM] = {0};
int n, m, c;
int get_sum(int x, int y) {
    int x2 = x + c - 1;
    int y2 = y + c - 1;
    return f[x2, y2] - f[x2, y - 1] - f[x - 1][y2] + f[x - 1][y - 1];
}
int main() {
    cin >> n >> m >> c;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            //cin >> v[i][j];
        }
    }
    int tmp_val;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> tmp_val;
            f[i][j] = f[i][j-1] + f[i-1][j]-f[i-1][j-1]+tmp_val;
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {

        }
    }
    return 0;
}