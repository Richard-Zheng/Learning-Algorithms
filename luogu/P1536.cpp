#include <iostream>
#include <cstring>
#include <set>
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
    set<int> roots;
    bool has_find[n + 1];
    for (int i = 1; i <= n; ++i) {
        int x = i;
        if (has_find[x]) {
            continue;
        }
        while (map[x] != x) {
            has_find[x] = true;
            x = map[x];
        }
        roots.insert(x);
    }
    return roots.size();
}
int main() {
    memset(map, 0, sizeof(map));
    memset(rnk, 1, sizeof(rnk));

    cin >> n >> m;

    // init map
    for (int i = 1; i <= n; ++i) {
        map[i] = i;
    }

    for (int i = 1; i <= m; ++i) {
        int x, y;
        cin >> x >> y;
        link(x, y);
    }
    cout << find() << endl;
    return 0;
}