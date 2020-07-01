#include <iostream>
#include <set>
#include <cstring>
using namespace std;
int n, m;
int ans = 0;
set<int> hate[101];
bool choosen[101];
bool ans_choosen[101];

void dfs(int num, int count, bool disable[101]) {
    choosen[num] = true;

    set<int>::iterator iter = hate[num].begin();
    for (set<int>::iterator it = hate[num].begin(); it != hate[num].end(); it++) {
        disable[*it] = true;
    }

    bool flag = true; // is reached the bottom
    for (int i = 1; i <= n; ++i) {
        if (!disable[i] && !choosen[i]) {
            flag = false;
            dfs(i, count + 1, disable);
        }
    }
    if (flag) {
        if (count > ans) {
            ans = count;
            memcpy(ans_choosen, choosen, sizeof(choosen));
        }
    }

    choosen[num] = false;
    return;
}

int main() {
    cin >> n >> m;

    for (int i = 1; i <= m; ++i) {
        int x, y;
        cin >> x >> y;
        hate[x].insert(y);
        hate[y].insert(x);
    }

    bool disable[101];
    memset(disable, 0, sizeof(disable));
    for (int i = 1; i <= n; ++i) {
        dfs(i, 1, disable);
    }

    cout << ans << endl;
    for (int i = 1; i <= n; ++i) {
        cout << ans_choosen[i] << " ";
    }
    return 0;
}