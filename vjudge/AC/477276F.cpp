#include <iostream>
#include <vector>
using namespace std;
const int MAXN = 1001;
int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> diff(n + 2, vector<int>(n + 2, 0));
    int p[2][2];
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
            cout << (diff[i][j] += diff[i-1][j] + diff[i][j-1] - diff[i-1][j-1]) << ' ';
        }
        cout << endl;
    }
}