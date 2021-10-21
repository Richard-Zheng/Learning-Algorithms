#include <algorithm>
#include <iostream>
using namespace std;
const int MAXN = 1e3;
int n, d;
int matrix[MAXN][MAXN][2];
int ans[MAXN][MAXN];
void solve() {
    cin >> n >> d;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> matrix[i][j][0];
        }
    }
    d /= 90;
    d %= 4;
    for (int c = 1; c <= d; c++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                matrix[j][n - i + 1][c & 1] = matrix[i][j][!(c & 1)];
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << matrix[i][j][d & 1];
            if (j != n) {
                cout << ' ';
            }
        }
        cout << '\n';
    }
    cout << '\n';
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}