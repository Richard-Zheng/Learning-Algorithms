#include <iostream>
#include <cstring>
using namespace std;
const int dir[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
int r, c; // row 行 column 列
int map[101][101];
int store[101][101];
int memorized_dfs(int x, int y);

int main() {
    memset(map, 0, sizeof(map));
    memset(store, -1, sizeof(store));

    cin >> r >> c;
    int heighest = 0;
    int hpoint[2];
    for (int i = 1; i <= r; ++i) {
        for (int j = 1; j <= c; ++j) {
            cin >> map[i][j];
            if (map[i][j] > heighest) {
                heighest = map[i][j];
                hpoint[0] = i;
                hpoint[1] = j;
            }
        }
    }

    cout << memorized_dfs(hpoint[0], hpoint[1]) + 1 << endl;
}

bool is_in_range(int x, int y) {
    return x > 0 && y > 0 && x <= r && y <= c;
}

int memorized_dfs(int x, int y) {
    if (store[x][y] != -1) {
        return store[x][y];
    }
    int longest_way = 0;
    for (int d = 0; d < 4; ++d) {
        int xx = x + dir[d][0];
        int yy = y + dir[d][1];

        if (is_in_range(xx, yy) && map[xx][yy] < map[x][y]) {
            longest_way = max(longest_way, memorized_dfs(xx, yy) + 1);
        }
    }
    store[x][y] = longest_way;
    return longest_way;
}