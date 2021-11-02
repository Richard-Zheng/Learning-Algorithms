#include <iostream>
#define S(x1, y1, x2, y2) n[x2][y2] - n[x2][y1 - 1] - n[x1 - 1][y2] + n[x1 - 1][y1 - 1]
using namespace std;
const int MAXRC = 501;
int r, c, a, b;
int n[MAXRC][MAXRC];
bool check(int x) {
    int startx = 1;
    int t = 0;  // 切了多少条
    for (int i = 1; i <= r; i++) {
        int k = 0;  // 切了多少块
        int starty = 1;
        for (int j = 1; j <= c; j++) {
            if (S(startx, starty, i, j) >= x) {
                k++;
                starty = j + 1;
            }
        }
        if (k >= b) {
            t++;
            startx = i + 1;
        }
    }
    return t >= a;
}
int main() {
    cin >> r >> c >> a >> b;
    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++) {
            cin >> n[i][j];
        }
    }
    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++) {
            n[i][j] += n[i][j - 1];
        }
    }
    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++) {
            n[i][j] += n[i - 1][j];
        }
    }
    int left = 0;
    int right = n[r][c];
    int ans;
    while (left <= right) {
        int mid = left + ((right - left) >> 1);
        if (check(mid)) {
            left = mid + 1;
            ans = mid;
        } else {
            right = mid - 1;
        }
    }
    cout << ans << endl;
}