#include <iostream>
#include <cstring>
#include <set>
#include <vector>
#include <cstdio>
using namespace std;
int n, m;
int map[1001];
int rnk[1001];
int get_root(int x) {
    while (map[x] != x) {
        x = map[x];
    }
    return x;
}
void link(int x, int y) {
    int rx = get_root(x);
    int ry = get_root(y);

    if (rx == ry) {
        return;
    }
    if (rnk[rx] < rnk[ry]) {
        map[ry] = rx;
    } else if (rnk[rx] == rnk[ry]) {
        map[ry] = rx;
        ++rnk[rx];
    } else if (rnk[rx] > rnk[ry]) {
        map[rx] = ry;
    }
    return;
}
int find() {
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        if (map[i] == i) {
            ++ans;
        }
    }
    return ans;
}
int main() {
    //vector<int> ans;
    while (scanf("%d %d", &n, &m) == 2) {

        memset(map, 0, sizeof(map));
        memset(rnk, 1, sizeof(rnk));

        // init map
        for (int i = 1; i <= n; ++i) {
            map[i] = i;
        }

        if (m == 0) {
            scanf("%d", &m);
        }

        for (int i = 1; i <= m; ++i) {
            int x, y;
            scanf("%d %d", &x, &y);
            link(x, y);
        }
        printf("%d\n", find() - 1);
    }
    return 0;
}