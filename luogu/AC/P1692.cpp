#include <iostream>
#include <set>
#include <cstring>
using namespace std;
int n, m;
int ans = 0;
bool hate[101][101];
bool choosen[101];
bool ans_choosen[101];

void dfs(int x, int count) {
    if (x > n) {
        if (count > ans) {
            ans = count;
            memcpy(ans_choosen, choosen, sizeof(choosen));
        }
        return;
    }

    bool can_choose = true;
    for (int i = 1; i <= n; ++i) {
        if (choosen[i] && hate[x][i]) {
            can_choose = false;
            break;
        }
    }

    if (can_choose) {
        choosen[x] = true;
        dfs(x + 1, count + 1); // choose x
        choosen[x] = false;
    }

    dfs(x + 1, count); // not choose x

    return;
}

int main() {
    cin >> n >> m;

    memset(hate, 0, sizeof(hate));
    memset(choosen, 0, sizeof(choosen));
    for (int i = 1; i <= m; ++i) {
        int x, y;
        cin >> x >> y;
        hate[x][y] = true;
        hate[y][x] = true;
    }

    dfs(1, 0);

    cout << ans << endl;
    for (int i = 1; i <= n; ++i) {
        cout << ans_choosen[i] << " ";
    }
    return 0;
}