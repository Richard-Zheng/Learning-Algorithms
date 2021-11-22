#include <cmath>
#include <iostream>
using namespace std;
double x, y;
bool check(int i, int j) {
    return (i + j == (x + y) / 2) && (fabs(i - x) + fabs(j - y) == (x + y) / 2);
}
void solve() {
    cin >> x >> y;
    for (int i = 0; i <= x; i++) {
        for (int j = 0; j <= y; j++) {
            if (check(i, j)) {
                cout << i << ' ' << j << endl;
                return;
            }
        }
    }
    cout << "-1 -1\n";
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}