#include <iostream>
using namespace std;
const int MAXN = 101;
const int MAXM = 4501;
int graph[MAXN][MAXN];

int main() {
    int n, m;
    cin >> n >> m;

    int w, l;
    for (int i = 1; i <= m; i++) {
        cin >> w >> l;
        graph[w][l] = true;
    }

    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                graph[i][j] = graph[i][j] || (graph[i][k] && graph[k][j]);
            }
        }
    }

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        int tmp = 1;
        for (int j = 1; j <= n; j++) {
            if (j == i) {
                continue;
            }
            tmp &= graph[i][j] | graph[j][i];
        }
        ans += tmp;
    }

    cout << ans << endl;
}