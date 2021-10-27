#include <algorithm>
#include <iostream>
#include <limits>
using namespace std;
int m[121][121];
int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> m[i][j];
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            m[i][j] += m[i][j - 1];
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            m[i][j] += m[i - 1][j];
        }
    }

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            for (int x = 1; x <= i; x++) {
                for (int y = 1; y <= j; y++) {
                    ans = max(ans, m[i][j] - m[x - 1][j] - m[i][y - 1] + m[x - 1][y - 1]);
                }
            }
        }
    }
    cout << ans << endl;
}