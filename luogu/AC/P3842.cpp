#include <iostream>
using namespace std;
const int MAXN = (2e4) + 1;
int l[MAXN];
int r[MAXN];
int min_path(int x, bool toleft) {
    if (x == 0) {
        return 0;
    } else {
        return min(min_path(x - 1, r[x]) + abs(l[x] - y) + r[x] - l[x] + 1, min_path(x - 1, l[x]) + abs(r[x] - y) + r[x] - l[x] + 1);
    }
}
int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> l[i] >> r[i];
    }
    cout << min_path(n, n) << endl;
}