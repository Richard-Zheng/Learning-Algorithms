#include <iostream>
#include <vector>
using namespace std;
int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> matrix(n + 1, vector<int>(m + 1, 0));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> matrix[i][j];
            matrix[i][j] += matrix[i][j - 1];
        }
    }
    for (int j = 1; j <= m; j++) {
        for (int i = 1; i <= n; i++) {
            matrix[i][j] += matrix[i - 1][j];
        }
    }
    int q;
    cin >> q;
    int a, b, c, d;
    for (int i = 1; i <= q; i++) {
        cin >> a >> b >> c >> d;
        cout << matrix[c][d] - matrix[a - 1][d] - matrix[c][b - 1] + matrix[a - 1][b - 1] << endl;
    }
}
